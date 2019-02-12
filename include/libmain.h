#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include "../include/commands_main.h"


class GLOB_ELI_CLASS: public INIT_CMD{
   public:
      GLOB_ELI_CLASS(){InitAll();}
      ~GLOB_ELI_CLASS(){CloseAll();}

      //Function for open eli program
      int OpenProgram(wxString path);
      int OpenProgramCh(char *pathx);
      //
      //Function for set and Get system variables
      int SetSystemVariable(int pos,float variabl);
      int GetSystemVariable(int pos,float &fval);
      //
      // Function for run test program
      int RunProgram(void);
      int RunProgramFromLine(int line);
      void EndRunFromLine(void);
      //
      // Get error string functions
       wxString GetErrorString(void){return error_string;}
       int GetErrorStringCh(int max_len,char *er_str);
       //
       // Function for gets string variables
       int GetStringVariable(int pos,wxString &sval);
       int GetStringVariableCh(int pos,int max_len,char *valx);
       //
       //Object functions
       int GetNumberOfAllObjects(void){return all_obj.size();}
       int GetObjectsParametersName(int pos,wxString &namex);
       int GetObjectsParametersNameCh(int pos,int max_len,char *namex);
       int GetNumberObjectsName(wxString namex);
       int GetNumberObjectsNameCh(char *namex);
       int GetObjectParameter(wxString namex,int pos,std::vector<int> &ival,std::vector<double> &dval);
   private:
       void InitAll(void);
       void CloseAll(void);
       Mat result_img;

     TestProgram *tp_prg; //Pointer for TestProgram array

        RunTestProgram *run_tpg;
        ObjectPrograms *ob_prg;
         CameraCalib *cam_calib;
         int init_number; //init number 18934 means that InitAll function was called otherwise not
         wxString error_string;
        float syst_variables[100];
        wxString string_variables[10];
        vector<OBJECTFOUND> all_obj;
};


#endif // MAIN_H_INCLUDED
