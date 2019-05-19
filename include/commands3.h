#ifndef COMMANDS3_H_INCLUDED
#define COMMANDS3_H_INCLUDED

#include "commands_main.h"
#include "editPicture.h"

    struct OBJECTX2{
         int x;
         int y;
         wxChar chr;
         int bot_y;
     };
/*************************************************************************************
Class for find contours on selected image
**************************************************************************************/

class Contours_Find:public command{
    public:
  Contours_Find(){};
   ~Contours_Find(){};
   virtual int GetCmdNumberLines(void){return 7;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Contours_Find");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/*************************************************************************************
Class for draw contours on selected image
**************************************************************************************/

class Contours_Draw:public command{
    public:
  Contours_Draw(){};
   ~Contours_Draw(){};
   virtual int GetCmdNumberLines(void){return 5;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Contours_Draw");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/*************************************************************************************
Class for find object from contours
**************************************************************************************/

class Object_Find:public command{
    public:
  Object_Find(){};
   ~Object_Find(){};
   virtual int GetCmdNumberLines(void){return 6;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Object_Find");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/************************************************************************************
Class for draw selected object
************************************************************************************/
class Object_Draw:public command{
    public:
  Object_Draw(){};
   ~Object_Draw(){};
   virtual int GetCmdNumberLines(void){return 5;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Object_Draw");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/************************************************************************************
Class for draw selected object
************************************************************************************/
class Object_Labels:public command{
    public:
  Object_Labels(){};
   ~Object_Labels(){};
   virtual int GetCmdNumberLines(void){return 11;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Object_Labels");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/************************************************************************************
Class for count  number of selected object
************************************************************************************/
class Object_Count:public command{
    public:
  Object_Count(){};
   ~Object_Count(){};
   virtual int GetCmdNumberLines(void){return 2;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Object_Count");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/************************************************************************************
Class transfer selected object to character
************************************************************************************/
class Object_ToChar:public command{
    public:
  Object_ToChar(){};
   ~Object_ToChar(){};
   virtual int GetCmdNumberLines(void){return 2;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Object_ToChar");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/************************************************************************************
Class transfer object characters to string
************************************************************************************/
class Object_CharToString:public command{
    public:
  Object_CharToString(){};
   ~Object_CharToString(){};

   virtual int GetCmdNumberLines(void){return 5;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Object_CharToString");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
     int SortObjectFunction(std::vector<OBJECTX2> dat,wxString &out_mes,int direction,int line_width,int space_size);

};

/************************************************************************************
Class transfer selected object to character
************************************************************************************/
class Object_ParamMath:public command{
    public:
  Object_ParamMath(){};
   ~Object_ParamMath(){};
   virtual int GetCmdNumberLines(void){return 6;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Object_ParamMath");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
    private:
        int GetParameter(wxString prameter,vector<double> &ret_param,wxString object_name,PDAT *pd);
};



#endif // COMMANDS3_H_INCLUDED
