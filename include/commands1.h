#ifndef COMMANDS1_H_INCLUDED
#define COMMANDS1_H_INCLUDED

#include "commands_main.h"

/************************************************************************************
Class System_Macro
This class is use for execute macro commands. Macro is .eli program which is executed
inside next .eli program. Macro can use all commands , only macro command inside macro
file is prohibeted.
************************************************************************************/
class System_Macro:public command{
    public:
   System_Macro(){};
   ~System_Macro(){};
  virtual int GetCmdNumberLines(void){return 1;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
   virtual wxString ReturnClassname(void){return wxT("System_Macro");}
   virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
   virtual int Inicialize(void){return 0;}
};

/************************************************************************************
Class System_Jump
THis class is use for jump to some command line (before or after executed line)
according some condition.
*************************************************************************************/
class System_Jump:public command{
  public:
   System_Jump();
   ~System_Jump(){};
   virtual int GetCmdNumberLines(void){return 13;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
   virtual wxString ReturnClassname(void){return wxT("System_Jump");}
   virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
   virtual int Inicialize(void);
  private:
   int active_jumps[30],numb_jumps[30];
};
/*************************************************************************************
Class System_Math
This class is use for matematical operation between variables or between variable
and number in the test program.
**************************************************************************************/
class System_Math:public command{
  public:
   System_Math(){};
   ~System_Math(){};
   virtual int GetCmdNumberLines(void){return 5;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
   virtual wxString ReturnClassname(void){return wxT("System_Math");}
   virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/**********************************************************************************
Class System_Results
THis class is use for display results in results window.User can choose which variable
will be display in result window and which picture will be display in result picture
window.
***********************************************************************************/
class System_Results:public command{
  public:
   System_Results(){};
   ~System_Results(){};
   virtual int GetCmdNumberLines(void){return 5;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
   virtual wxString ReturnClassname(void){return wxT("System_Results");}
   virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/**********************************************************************************
Class System_Wait
THis class is use for delay int test program in specified time
***********************************************************************************/
class System_Wait:public command{
  public:
   System_Wait(){};
   ~System_Wait(){};
   virtual int GetCmdNumberLines(void){return 2;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
   virtual wxString ReturnClassname(void){return wxT("System_Wait");}
   virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/*******************************************************************************
Class Source_OpenFile
This class is use for load picture from file and store it in one images in test program.
*******************************************************************************/
class Source_OpenFile:public command{
    public:
   Source_OpenFile(){};
   ~Source_OpenFile(){};
  virtual int GetCmdNumberLines(void){return 3;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
   virtual wxString ReturnClassname(void){return wxT("Source_OpenFile");}
  virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
   virtual int Inicialize(void){return 0;}
};

/******************************************************************************
Class for read capture from camera.
Function open selected camera and read capture
*******************************************************************************/
class Source_ReadCamera:public command{
    public:
   Source_ReadCamera(){};
   ~Source_ReadCamera(){};
   virtual int GetCmdNumberLines(void){return 5;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Source_ReadCamera");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/******************************************************************************
Class for read capture from video.
Function open selected video file and read capture
*******************************************************************************/
class Source_ReadVideo:public command{
    public:
   Source_ReadVideo(){};
   ~Source_ReadVideo(){};
   virtual int GetCmdNumberLines(void){return 4;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Source_ReadVideo");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
     virtual int Inicialize(void){return 0;}
};

/******************************************************************************
Class for query frame from video stream capture.
*******************************************************************************/
class Source_QueryFrame:public command{
    public:
   Source_QueryFrame(){};
   ~Source_QueryFrame(){};
   virtual int GetCmdNumberLines(void){return 3;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Source_QueryFrame");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
     virtual int Inicialize(void){return 0;}
};

/******************************************************************************
Class for Set or Get capture property.
*******************************************************************************/
class Source_CaptureProperty:public command{
    public:
   Source_CaptureProperty(){};
   ~Source_CaptureProperty(){};
   virtual int GetCmdNumberLines(void){return 5;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Source_CaptureProperty");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
     virtual int Inicialize(void){return 0;}
};
/*************************************************************************
Class for create new image
**************************************************************************/
class Source_CloneImage:public command{
    public:
   Source_CloneImage(){};
   ~Source_CloneImage(){};
   virtual int GetCmdNumberLines(void){return 2;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Source_CloneImage");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
     virtual int Inicialize(void){return 0;}
};

/*************************************************************************
Class for store image to picture file
*************************************************************************/
class Source_SaveImage:public command{
    public:
   Source_SaveImage(){};
   ~Source_SaveImage(){};
   virtual int GetCmdNumberLines(void){return 2;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Source_SaveImage");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
     virtual int Inicialize(void){return 0;}
};

/*******************************************************************************
Class for create video file
********************************************************************************/
class Source_CreateVideoFile:public command{
    public:
     Source_CreateVideoFile(){};
     ~Source_CreateVideoFile(){};
      virtual int GetCmdNumberLines(void){return 10;}
     virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
     virtual wxString ReturnClassname(void){return wxT("Source_CreateVideoFile");}
     virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
     virtual int Inicialize(void){return 0;}
};

/**********************************************************************************
Class for write frame to video file
***********************************************************************************/
class Source_WriteVideoFrame:public command{
    public:
     Source_WriteVideoFrame(){};
     ~Source_WriteVideoFrame(){};
      virtual int GetCmdNumberLines(void){return 2;}
     virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
     virtual wxString ReturnClassname(void){return wxT("Source_WriteVideoFrame");}
     virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
     virtual int Inicialize(void){return 0;}
};

/**********************************************************************************
Class for release video writer
**********************************************************************************/
class Source_GetPictureParam:public command{
    public:
     Source_GetPictureParam(){};
     ~Source_GetPictureParam(){};
      virtual int GetCmdNumberLines(void){return 3;}
     virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
     virtual wxString ReturnClassname(void){return wxT("Source_GetPictureParam");}
     virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
     virtual int Inicialize(void){return 0;}
};



#endif // COMMANDS1_H_INCLUDED
