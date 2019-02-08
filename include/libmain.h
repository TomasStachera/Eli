#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include "../commands_main.h"


class GLOB_ELI_CLASS: public INIT_CMD{
   public:
      GLOB_ELI_CLASS(){InitAll();}
      ~GLOB_ELI_CLASS(){CloseAll();}
      int OpenProgram(wxString path);
      int SetSystemVariable(int pos,float variabl);
      int GetSystemVariable(int pos,float &fval);
      int RunProgram(void);
       wxString GetErrorString(void){return error_string;}
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
};


#endif // MAIN_H_INCLUDED
