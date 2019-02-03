#ifndef CONTOURDESCRIPT3_H_INCLUDED
#define CONTOURDESCRIPT3_H_INCLUDED
#include "commands_main.h"

class ContourCalculation
{
  public:
    ContourCalculation(vector<vector<Point> >  contours,ObjectPrograms *obprg,int numbobj,int read_mode_=0);
    ~ContourCalculation();

    int ContourStringToNumber(wxString name);
    wxString ContourNumberToString(int num);
    double ReturnContourParam(vector<Point>  contour,int type,int pos);
    int InserFilterLine(int result,int input_from,int contour_param,int comp_option,double number,int number_from);
    int FilterAplication(void);
    bool WasOpenCvError(void){return IsCvError;} // If OpenCv error was reported function return true, otherwise fasle
    wxString GetStringOpenCvError(void){return openCvError;}
    void ResetActualFilterLIne(void){actual_filter_line=0;}  //Reset actual filter line to 0
    int ReturnActualFilterLine(void){return actual_filter_line;} //return actual filter lines
    int GetFilterLineParam(int line,int &result,int &input_from,int &contour_parameter,int &comparison_option,double &comparison_number,int &number_from);
    bool IsContourActive(int pos);
    int GetObjectCommandLine(int pos,int line,wxString &cmd,wxString &des,wxString &formula);
    void ClearFilter (void);
    int ExportObjectToFile(wxString obj_name,wxString path);
    int ImportObjectFromFile(wxString path,wxString &obj_name,wxString &obj_des,wxString &er_message);

      /*
OBJECT_COMMAND structure
Structure for store  object commands calculation parameters
type of command:    1=CONDITION
                    2=MATH
                    3=AND
                    4=OR
                    5=(
                    6=)
type of parameter:  1=Contour parameter
                    2=System variable
                    3=Temporary array
                    4=Number
operand:            MATH option : 1:  param1 + param2
                    MATH option : 2:  param1  - param2
                    MATH option : 3:  param1  / param2
                    MATH option : 4:  param1 * param2
                    MATH option : 5:  param1 ^ param2
                    MATH option : 6:  sqrt param1
                    MATH option : 7: sin param1
                    MATH option : 8: cos param1
                    MATH option: 9 : tan param1
                    CONDITION option: 1: TRUE if param1 = param2
                    CONDITION option: 2: TRUE if param1 > param2
                    CONDITION option: 3: TRUE if param1 < param2
                    CONDITION option: 4: TRUE if param1 >= param2
                    CONDITION option: 5: TRUE if param1 <= param2
                    CONDITION option: 6: TRUE if param1 != param2

*/
    struct OBJECT_COMMAND{
       int type; //type of command
       wxString description; //command description
       int param1; // type of parameter1
       int i_param1; //integer number of parameter 1
       float f_param1; //float number of parameter 1
       wxString s_param1; // temporary array variable string
       int param2; // type of parameter 2
       int i_param2; // integer number of parameter 2
       float f_param2; // float nmber of parameter 2
       wxString s_param2; //temporary array of variable string
       int operand; // MATH operand or condition operand
       int i_result; // system variable number
       wxString s_result; //temporary array variable string
    };


    int SetObject(wxString name,wxString Description,int line_numb,OBJECT_COMMAND *obj);
    int FindObjectName(wxString name);
    int GetObjectsLines(int pos); //function return number of test rogram lines in object
    int GetTestProgram(wxString &param,wxString &description,int pos,int line);
    int DeleteObject(wxString name);
    int CopyObject(wxString old_name,wxString new_name);
    int UpdateDescription(wxString name,wxString description);
    int GetNumberOfObject(void){return real_object_number;} //Function return number of object (also deleted objects are included)
    int GetObjectNameAndDescription(int pos,wxString &name,wxString &description);

    int FindObjectExecution(float *syst_var);
    int GetNumbFoundObjects(int pos,int *object_contours);
    int GetNumberOfContours(void){return total_contours;}
     int ReadTempVariable(wxString name, float &value);
     int ReturnAllFoundObjectsNum(void){return all_obj_cnt;}
     int ReturnAllFoundObjects(OBJECTFOUND *of,int mode_=0);



  private:



  int InitTempVariable(void);
  int ReturnTempVariablePosition(wxString name);
  int SetTempVariable(wxString name,float value);
  int RunObjectCommand(vector<Point> contour,int object_pos,int contour_pos);
  int RunOneObjectProgLine(vector<Point> contour,int contour_pos,int object_pos,int line);
  int SetError(int xlog,int object_pos,int ret_code,int contour_pos);
  int ObjectRead(int mode=0);
  int AddObjecttestLines(ObjectPrograms *obj_prg,int numb);
  bool IsInsideContour(vector<Point> orig_cont,vector<Point> mirror,int pos_orig,int pos_mirror);
  bool IsOutsideContour(vector<Point> orig_cont,vector<Point> mirror,int pos_orig,int pos_mirror);
   int CheckLine(wxString line_str,int &typex,wxString &decs,int &param1,int &iparam1,float &fparam1,wxString &s_param1,int &param2,int &iparam2,float &fparam2,wxString &s_param2,int &operand,int &iresult,wxString &sresult);

    struct FILTER {
       int result; //Active=1, Non active=0  If operation is true contour is active if result is 1
       int input_from; //All=1 Active=0 , If input_from =1 function check all contours if not only active contours are read
       int contour_parameter; // contour parameter number see function ContourStringToNumber
       int comparison_option; // (=) 1, (>) 2, (<) 3, (=>) 4, (=<) 5, (!=)6
       int variable_from; //-1 -fixed number, 0-99 system variable
       double comparison_number;
    };

/*
PARAMETERS structure stored all contour parameters which was calculated
if some parameters was calcultaed bool walue ..._calculated is true.
Reason of this structure is that each parameter will be calculated only ones.
If some parameter is need more time during conotour calculation is read from this
structure and can not be calculted. It is more faster than contour parameter
calculation.
*/

    struct PARAMETERS {
        Rect rect; // CV bounding rect calculation
        bool rect_calculated; //if CV bounding rect was calculated is true otherwise false
        double perimeter; // contour perimemer
        bool perimeter_calculated; // if perimeter as calcultated is true otherwise false
        double contour_area; //contour area
        bool contour_area_calculated; //if contour area calculated is true otherwise false
        RotatedRect min_area_rec; //Minimal area rec parameter
        bool min_area_rec_calculated; // if min area rec was calculated is true otherwise false
        Point2f enclosing_circle_center; // enclosing circle center
        float enclosing_circle_radius; // enclosing circle radius
        bool enclosing_circle_calculated; //true if enclosing circle was calculated
        RotatedRect fit_elipse; //fit elipse calculation
        bool fit_elipse_calculated; //true if fit_elipse was calculated otherwise false
        Moments momentsx; // moments calculation
        bool moments_calculated; //true if moments was calculated otherwise false
    };

    int max_filter_line; //maximal filters line
    int actual_filter_line; //actual filters line
    wxString openCvError;
    bool IsCvError;
    int maximal_obj_numb;
    int read_mode;

    vector<vector<Point> > contx; // contours sequence
    int total_contours;// numbers of all contours
    bool *contour_active; //array of all contour, position in bool array is contour number, tru means active contour, false means non active

     FILTER *filter;  //pointer for filter structure
     PARAMETERS *param; //pointer for PARAMETERS structure



    struct OBJECTCAL{
        wxString name; //object name
        wxString description; //object description
        OBJECT_COMMAND *command; //Pointer for object array structure
        int number; //number of command in OBJECT_COMMAND array
        int number_of_contour;  // number of found contours with current object name
        int *cont_pos; // array of contour position in CvSeq structure
    };

    /*
    Structure for temporary variable value save
    */
    struct TEMPVAR{
       wxString var_name;
       float var_value;
    };


 OBJECTCAL *object_calculation;
 TEMPVAR *temporary_variable;//
 int real_object_number; //number of objects
 int temporary_variable_numb; //real teporary variable number
 float temp_syst_var[100];

 OBJECTFOUND *obj_fnd;
 int all_obj_cnt; //Number off all found objects

 /* Contour calculation
 */

//Structure use for  test program calculation
struct CONTCALC{
    bool status; // bool status in current condition level
    int operandx; // 0=no operand ,1=AND operand, 2= OR operand
};

CONTCALC contc[11];
int calc_index; //calculation index. Maximal index level is 10
  ObjectPrograms *obj_prog; // Pointer for object program structure
  int num_obj_block; //number of object block in object program structure

public:
  int ReturnTempVarNumber(void){return temporary_variable_numb;}
  wxString ReturnTempVarName(int pos);
  int RunDebugProgram(int cont_numb,int from_line,int to_line,int object_pos);
  int RestartDebugMode(float *syst_var);
  double GetContourParamValue(int cont_numb,int object_pos,int param_numb,int line_numb);
  float ReturnSystemVariable(int pos){
      if((pos>=0)||(pos<=99))return temp_syst_var[pos];
      else return 0;}
  bool ReturnActualConditionStatus(void){return contc[0].status;} // Return total condition status

  int ReturnBracketConditionStatus(void){     // Function return actual bracket status -1 Not bracket used, 0=bracket false, 1=bracket true
     if(calc_index==0) return -1;
     else return (int)contc[calc_index].status;
  }

  int SaveObjectBlock(void);


};


#endif // CONTOURDESCRIPT3_H_INCLUDED
