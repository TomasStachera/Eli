#ifndef COMMANDS_MAIN_H_INCLUDED
#define COMMANDS_MAIN_H_INCLUDED

#include <wx/string.h>
#include <wx/file.h>
#include <wx/textfile.h>
#include <wx/config.h>
#include <wx/filedlg.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/cvdef.h>
#include <opencv2/core/utility.hpp>
#include "CameraCalibration.h"
#include "LOGMES.h"




using namespace cv;
using namespace std;

#define NUMBER_COMMANDS_CLASS 41// define number of all commands class. Number must be same as number of command class
#define MAXIMAL_FILTER_LINES 100
#define MAXIMAL_OBJECTS_LINES 1000
#define MAXIMAL_OBJECT_TEST_PROGRAM_LINES  400



class ObjectPrograms{
 public:
    ObjectPrograms();
    ~ObjectPrograms();

    int InsertNewObjectBlock(int numb);
    int ChectNewObject(wxString line);
    int DecodeTestProgramLine(wxString line);
    int GetActualObjectsNumber(void){return actual_obj_numb;}
    int GetIndexAccordingNumber(int nub);
    bool ReturnFilterParam(int ind,int &filter_lines,wxArrayString &ar_lines);
    int GetNumberOfObjects(int index) // Function return number of objects according index in input parameter
    {
        if((index<0)||(index>19))return -1;
        else return conobj[index].num_obj;
    }
    int ReturnObjectProgram(int ind,int obj_ind,wxString &name,wxString &desc,int &numb_lines,wxArrayString &lines);
    int WriteObjectToTestProgram(wxFile *file);

 private:
    struct OBJECT{
        wxString name; //Object name
        wxString description; //Object description
        int numbcmd;  // number of commands
        wxArrayString command; // Array of commands lines
    };

    struct CONTOUROBJECT{
        int numb; //numberObjectBlocks
        bool IsFilter; // true if filter is activated, false if not
        int numb_filter_lines; // number of filter lines
        wxArrayString filterLine; // Array of filter lines
        int num_obj; //Number of all objects
        OBJECT obj[MAXIMAL_OBJECTS_LINES]; // arrays of pointers for OBJECT structure
    };

CONTOUROBJECT conobj[20];
int actual_obj_numb; // number of actual object
int actual_index; // number of object which is working

};


/************************************************************************
Object structure with basic information about objects
level 0:
-object name
-Object bounding rect x,y, height, width
-perimeter
-cotour area
level 1:
- minimal area rectangle x,y,height,width, angle

level 2:
-minimal enclosing circle center x,y radius
- fit elipse  center x,y, height, width, angle

*************************************************************************/

struct OBJECTFOUND {
    wxString object_name;
    int bounding_rect_x;
    int bounding_rect_y;
    int bounding_rect_height;
    int bounding_rect_width;
    double perimeter;
    double contour_area;
    int min_area_rect_x;
    int min_area_rect_y;
    int min_area_rect_height;
    int min_area_rect_width;
     double min_area_rect_angle;
    int min_enclosing_circle_center_X;
    int min_enclosing_circle_center_Y;
    double min_enclosing_circle_radius;
    int fit_elipse_center_X;
    int fit_elipse_center_Y;
    int fit_elipse_height;
    int fit_elipse_width;
    double fit_elipse_angle;
    bool char_activated;
    double derived[10];
    wxChar chr;
};

/************************************************************************
Structure for storing test program results. Each test program steps can
updated this structure.
************************************************************************/
     struct PDAT{
       float fval[100]; // test program variables
       wxString results; // string for stroring test result. This variable is updated with class System_results
       wxString str_values[10]; // string value array
       int pic_pos; // picture position which will be displayed in result window. THis variable is updated with class System_results
       Mat imgx[20];
       VideoCapture capture[10]; //capture array
       VideoWriter video_writers[10]; // video vrite structure for store video files
       wxString OpenCvErrorMes; // Variable for store OpenCV error Message
      wxString updated_param;// update parameters in edit mode
      bool update_param; //if edit mode change param was selected return true otherwise is false
      vector<vector<Point> > contoursx[20];
      vector<Vec4i> hierarchy[20];
      int ival[20]; // integer values for contours description file
      int numb_objects; // NUmber of found objects
      vector<OBJECTFOUND> obj;  // Object found structure
      CameraCalib cam_calib[20];
      double pix_per_mm[20];
      };

/**************************************************************************
Virtual class commad
Thisclass is use like pointer for all commands classes
FUnction GetCmdNUmberLines  return number of lines in command
parameters grid.
Function GetLineParam return command parammeter in all lines (line by line)
in command grid
Function ReturnClass name return name of class, this name will be use
as command name.
Function Inicialize is call before each start of test program. Function could be
use for inicialization new variables, which should be inicialize before each run test program
**************************************************************************/
class command{
    public:
   command(){};
   virtual ~command(){};
   virtual int GetCmdNumberLines(void)=0;
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)=0;
   virtual wxString ReturnClassname(void)=0;
   virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)=0;
   virtual int Inicialize(void)=0;
     void SetOpenCVErrorMess(std::string description,std::string file,std::string function,int line,PDAT *pd);


};

/*********************************************************************************
Class ErrorLOg is use for display error message or logs
Function SetError set error messages, the first parameter is type of
error message (for example "Test program error" and second parameter is error message
Function DisplayLog display error  log in 2 modes depent of input parameters.
Default parameter is 0 , if funstion is call without parameter or with parameter 0
Error message is diplay like "usually" message box with error icon.
If parameter is 1 error message is display as fatal error.
**********************************************************************************/
class ErrorLog{
    public:
  ErrorLog();
  ~ErrorLog(){};
  void SetError(wxString type_,wxString mes_);
  void DisplayLog(int tp=0);
  private:
  wxString type,mes;
};

/****************************************************************************
Structure CommandBase is use for store commad name and position of this command
in commands list box.
*****************************************************************************/
struct CommandBase{
    wxString name; // Total command name with group and commmand
    wxString group_name; // Group name
    wxString cmd_name; // comand name
    int pos; // position in list box
};


/*****************************************************************************
Class TestProgram is use for complete process with test program.(Open program,
Save program, set program line, delete commands, copy blocks and so on.
Test proram consist of list of commands. Each command is in 1 line in test
program file. Lines start with name of command than delimeter "#" and than
is parameters. Each parameters are separeted by delimeter "#"
******************************************************************************/

class TestProgram{
    public:
 TestProgram();
 ~TestProgram();

  wxString GetCmd(int line,int first_i=0); // Function return command name according test program line as a function parameter
  wxString GetParam(int line,int first_i=0); // Function return command parameters according test profram line as a function parameter
  wxString GetDescription(int line,int first_i=0); //Function return command line description
  wxString GetComents(void){return tName;} // Function return COments
  int GetLineNumber(void){return line_numberx;} // Fnction return number of active lines in test program
  int SetProgram(int line,wxString cmd,int nw=0);
  int DeleteLine(int line);
  int CopyBlockProgram(int line,int start,int end);
   int SaveProgram(wxString path,ObjectPrograms *op);
   int OpenProgram(wxString path,ObjectPrograms *op);
   int SetBreak(int line,int first_i=0);
   int ResetBreak(int line,int first_i=0);
   bool GetBreak(int line,int first_i=0);
  bool UpdateParam(int line,wxString param);
  void SetComments(wxString comments){tName=comments;}

 private:

  int line_numberx; //number of active lines (total inicialize lines - delete lines)
 int line_numberx2; //Number of all inicialize lines
  wxFile *file;
 wxTextFile *file2;
 wxString tName; // Name of test program
          /*structure for storing test program*/
       struct PRG{
        wxString cmd; // store command name
        wxString param; // store command parameters
       int line;// if line>0 - number test program line, if line ==0 - not inicialize, if line == 1- line was deleted
        bool br; //if break is active br is true , if not false
     };

     PRG *p1; // Pointer for structure PRG
};

/****************************************************************************
Class is used for test program execution.
Function RunProgram execute test program in first parameter
Function GetText1 return string with all executed commands
Function GetResults return string with results
Function GetNumberExecuteLines return nunber of actual executed lines in actual test program
****************************************************************************/

class RunTestProgram
{
    public:
      RunTestProgram(command **cmd);
      ~RunTestProgram();
      int RunProgram(TestProgram *tpg,command **cmd,int start_line,ObjectPrograms *op,int mode=0);// Run test program
      void EmptyResultString(void){pd->results=_("");}
      wxString GetStringVariables(int pos)
      {
          if((pos>=0)&&(pos<=9))return pd->str_values[pos];
          else return wxEmptyString;
       }
//      wxString GetText1(void){return pd->text1;} //return string with all executed commands
      wxString GetResults(void){return pd->results;} //return string with results
      int GetNumberExecutedLines(void){return num_exec_lines;}//return nunber of actual executed lines in actual test program
      int GetResultPicturePosition(void){return pd->pic_pos;} // Get osition in img field, -1 means no postion is selected
      Mat GetResultPicture(void){return pd->imgx[pd->pic_pos];}
        wxString ReturnOpenCVErrMess(void){return pd->OpenCvErrorMes;}
        void SetSystemVariable(int pos,float fval){if((pos>=0)&&(pos<=99))pd->fval[pos]=fval;}
        float GetSystemVariable(int pos)
        {
            if((pos>=0)&&(pos<=99))return pd->fval[pos];
            else return -1;
        }
        int GetAllObjects(vector<OBJECTFOUND> &obj);
     private:
      int num_exec_lines; // variable for store number of executed lines in actual test program
      PDAT *pd; // pointed for PDAT structure
      TestProgram *tp2; // pointer for test program class in macro commands


};



class INIT_CMD{
   public:
       INIT_CMD(){};
       ~INIT_CMD(){};
       void InitMainCommands(void);
       void DeleteMainCommands(void);
         command *cmd[NUMBER_COMMANDS_CLASS]; // virtual class where pointer for all commands class is placed

};

#endif // COMMANDS_MAIN_H_INCLUDED
