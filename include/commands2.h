#ifndef COMMANDS2_H_INCLUDED
#define COMMANDS2_H_INCLUDED

#include "commands_main.h"
#include "editPicture.h"

/*************************************************************************************
Class for colour conversion. You can conver colour picture to grayscale or grayscale
to colour, or yoy can convert between several colour spaces, see command help.
**************************************************************************************/

class Conversion_Color:public command{
    public:
   Conversion_Color(){};
   ~Conversion_Color(){};
   virtual int GetCmdNumberLines(void){return 3;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Conversion_Color");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
     virtual int Inicialize(void){return 0;}
};

/*************************************************************************************
Class for Scale conversion. Command add  or multiply some number to each pixels in image
**************************************************************************************/

class Conversion_Scale:public command{
    public:
   Conversion_Scale(){};
   ~Conversion_Scale(){};
   virtual int GetCmdNumberLines(void){return 6;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Conversion_Scale");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
     virtual int Inicialize(void){return 0;}
};

/*****************************************************************************************
Class for set or reset ROI (Region of interest) in image
******************************************************************************************/

class Conversion_Roi:public command{
    public:
   Conversion_Roi(){};
   ~Conversion_Roi(){};
   virtual int GetCmdNumberLines(void){return 9;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Conversion_Roi");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
     virtual int Inicialize(void){return 0;}
};

/*************************************************************************************
Class for add 2 images. Each pixels in one image is add with each pixels in second image.
Each pixels is before add multiply with weight factor on image.
**************************************************************************************/

class Conversion_AddWeighted:public command{
    public:
  Conversion_AddWeighted(){};
   ~Conversion_AddWeighted(){};
   virtual int GetCmdNumberLines(void){return 7;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Conversion_AddWeighted");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
     virtual int Inicialize(void){return 0;}
};

/*************************************************************************************
Class for image threshold. Function convert image according threshold value
**************************************************************************************/

class Conversion_Threshold:public command{
    public:
  Conversion_Threshold(){};
   ~Conversion_Threshold(){};
   virtual int GetCmdNumberLines(void){return 5;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Conversion_Threshold");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
     virtual int Inicialize(void){return 0;}
};

/*************************************************************************************
Class for image adaptive threshold. Function convert image according adaptive threshold
mechanizm
**************************************************************************************/

class Conversion_AdaptThresh:public command{
    public:
  Conversion_AdaptThresh(){};
   ~Conversion_AdaptThresh(){};
   virtual int GetCmdNumberLines(void){return 8;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Conversion_AdaptThresh");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
     virtual int Inicialize(void){return 0;}
};

/*************************************************************************************
Class for aplicate floodFill algoritm for tested image
**************************************************************************************/

class Conversion_FloodFill:public command{
    public:
  Conversion_FloodFill(){};
   ~Conversion_FloodFill(){};
   virtual int GetCmdNumberLines(void){return 11;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Conversion_FloodFill");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/*************************************************************************************
Class for aplicate Morfology algoritm for tested image
**************************************************************************************/

class Conversion_Morfology:public command{
    public:
  Conversion_Morfology(){};
   ~Conversion_Morfology(){};
   virtual int GetCmdNumberLines(void){return 9;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Conversion_Morfology");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/*************************************************************************************
Class for aplicate Laplace or Sobel algoritm for tested image
**************************************************************************************/

class Conversion_Edge:public command{
    public:
  Conversion_Edge(){};
   ~Conversion_Edge(){};
   virtual int GetCmdNumberLines(void){return 6;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Conversion_Edge");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/*************************************************************************************
Class for smooth tested image
**************************************************************************************/

class Conversion_Smooth:public command{
    public:
  Conversion_Smooth(){};
   ~Conversion_Smooth(){};
   virtual int GetCmdNumberLines(void){return 7;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Conversion_Smooth");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/*************************************************************************************
Class for equalize histogram on tested image
**************************************************************************************/

class Conversion_EqualHist:public command{
    public:
  Conversion_EqualHist(){};
   ~Conversion_EqualHist(){};
   virtual int GetCmdNumberLines(void){return 2;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Conversion_EqualHist");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/*************************************************************************************
Class for resize tested image
**************************************************************************************/

class Conversion_Resize:public command{
    public:
  Conversion_Resize(){};
   ~Conversion_Resize(){};
   virtual int GetCmdNumberLines(void){return 7;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Conversion_Resize");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/*************************************************************************************
Class for flip or rotate tested image
**************************************************************************************/

class Conversion_RotateFlip:public command{
    public:
  Conversion_RotateFlip(){};
   ~Conversion_RotateFlip(){};
   virtual int GetCmdNumberLines(void){return 4;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Conversion_RotateFlip");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}

    private:
    Mat rotateImage(const Mat src, int angleDegrees); // function for rotate image, angleDegrees is rotate angle in  degrees
};

/*************************************************************************************
Class for applied canny algoritm on tested image
**************************************************************************************/

class Conversion_Canny:public command{
    public:
  Conversion_Canny(){};
   ~Conversion_Canny(){};
   virtual int GetCmdNumberLines(void){return 7;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Conversion_Canny");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/*************************************************************************************
Class for applied corners algoritm on tested image
**************************************************************************************/

class Conversion_Corners:public command{
    public:
  Conversion_Corners(){};
   ~Conversion_Corners(){};
   virtual int GetCmdNumberLines(void){return 6;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Conversion_Corners");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

/*************************************************************************************
Class for invert tested image
**************************************************************************************/

class Conversion_Invert:public command{
    public:
  Conversion_Invert(){};
   ~Conversion_Invert(){};
   virtual int GetCmdNumberLines(void){return 2;}
   virtual int GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2);
    virtual wxString ReturnClassname(void){return wxT("Conversion_Invert");}
    virtual int RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp);
    virtual int Inicialize(void){return 0;}
};

#endif // COMMANDS2_H_INCLUDED
