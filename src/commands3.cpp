#include "commands3.h"
#include <wx/msgdlg.h>
#include "ContourDescript.h"
#include "ContourDescript3.h"
#include <vector>
#include <algorithm>

using namespace cv;
using namespace std;



/*************************************************************************************
Class for find contours on selected image
**************************************************************************************/
 int Contours_Find::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>8) return -2;

 if(line==0)
  {
     name=wxT("Source picture");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=0;i<20;i++)
        {
           pom=_("Picture_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
  }

    if(line==1)
  {
     name=wxT("Contours");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=0;i<20;i++)
        {
           pom=_("Contour_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
  }

       if(line==2)
    {
        name=wxT("X ofset from");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        arraystr.Add(_("Number"));
        for(int i=0;i<100;i++)
        {
           pom=_("Variable_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
    }

    if(line==3)
    {

        name=wxT("X ofset number");
        type=4;
        ival=0;

    }

       if(line==4)
    {
        name=wxT("Y ofset from");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        arraystr.Add(_("Number"));
        for(int i=0;i<100;i++)
        {
           pom=_("Variable_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
    }

    if(line==5)
    {

        name=wxT("Y ofset number");
        type=4;
        ival=0;

    }

    if(line==6)
    {
       name=wxT("Results to");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        arraystr.Add(_("None"));
        for(int i=0;i<100;i++)
        {
           pom=_("Variable_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
    }

  return 0;
}

 int Contours_Find::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
   int sour_pic_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));//position of source picture in picture array
  wxString pom=param.AfterFirst('#');
  int contour_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_')); //position of contours array
  pom=pom.AfterFirst('#');
  int mode=CV_RETR_CCOMP; //Retrieval mode
 /* if(pom.BeforeFirst('#')==_("CV_RETR_EXTERNAL")) mode=CV_RETR_EXTERNAL;
  if(pom.BeforeFirst('#')==_("CV_RETR_CCOMP")) mode=CV_RETR_CCOMP;
  if(pom.BeforeFirst('#')==_("CV_RETR_TREE")) mode=CV_RETR_TREE;*/
 // pom=pom.AfterFirst('#');
  int method=CV_CHAIN_APPROX_SIMPLE; //Aproximation method
 /* if(pom.BeforeFirst('#')==_("CV_CHAIN_APPROX_NONE")) method=CV_CHAIN_APPROX_NONE;
  if(pom.BeforeFirst('#')==_("CV_CHAIN_APPROX_TC89_L1"))method=CV_CHAIN_APPROX_TC89_L1;
  if(pom.BeforeFirst('#')==_("CV_CHAIN_APPROX_TC89_KCOS"))method=CV_CHAIN_APPROX_TC89_KCOS;*/
 // pom=pom.AfterFirst('#');

    int x_ofset=0; // X offset number

    if(pom.BeforeFirst('#')==_("Number"))
   {
      pom=pom.AfterFirst('#');
       x_ofset= wxAtoi(pom.BeforeFirst('#'));
   }
   else
   {
        int pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
       if((pos<0)||(pos>99)) return -1; // bad x-ofset number variable index
       x_ofset=(int)pd->fval[pos] ;
       pom=pom.AfterFirst('#');
   }
   pom=pom.AfterFirst('#');

   int y_ofset=0; //Y offset number

    if(pom.BeforeFirst('#')==_("Number"))
   {
      pom=pom.AfterFirst('#');
       y_ofset= wxAtoi(pom.BeforeFirst('#'));
   }
   else
   {
        int pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
       if((pos<0)||(pos>99)) return -2; // bad y-offset number variable index
       y_ofset=(int)pd->fval[pos] ;
       pom=pom.AfterFirst('#');
   }


   int result_pos=-1;
   if(pom.AfterFirst('#')!=_("None"))
   {
       result_pos=wxAtoi(pom.AfterFirst('#').AfterFirst('_'));
       if((result_pos<0)||(result_pos>99))return -3; //bad position in result variable index
   }
  if((sour_pic_pos<0)||(sour_pic_pos>19)) return -4;//bad source position index

  if((contour_pos<0)||(contour_pos>19)) return -5; // bad contour position index

   try
   {

     if(pd->imgx[sour_pic_pos].channels()!=1) return -8; // source picture must be single channel
     if(x_ofset>pd->imgx[sour_pic_pos].cols) return -6; //bad x-ofset number
     if(y_ofset>pd->imgx[sour_pic_pos].rows) return -7; //bad y-ofset number

findContours(pd->imgx[sour_pic_pos],pd->contoursx[contour_pos],pd->hierarchy[contour_pos],mode,method,Point(x_ofset,y_ofset));
if(result_pos>=0)pd->fval[result_pos]=(float)pd->contoursx[contour_pos].size();

   }
    catch( cv::Exception& e )
   {
       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }

     return 0;
 }

 /*************************************************************************************
Class for find contours on selected image
**************************************************************************************/
 int Contours_Draw::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>4) return -2;

   if(line==0)
  {
     name=wxT("Source picture");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=0;i<20;i++)
        {
           pom=_("Picture_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
  }
      if(line==1)
  {
     name=wxT("Contours");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=0;i<20;i++)
        {
           pom=_("Contour_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
  }

   if(line==2)
  {
       name=wxT("Contour color");

        type=1; //file path string type
        str=wxT("0,0,0");
        type2=3;//open collor dialog will display
  }

    if(line==3)
  {
      name=wxT("Tickness");
      type=4;
      ival=1;
  }
  if(line==4)
  {
       name=wxT("Line type");
        type=2;
        wxArrayString arraystr;
        arraystr.Add(_("8"));
        arraystr.Add(_("4"));
        arraystr.Add(_("CV_AA"));
        aray_str=arraystr;
        type2=0;
  }

  return 0;
}

 int Contours_Draw::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
     int sour_pic_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));//position of source picture in picture array
      wxString pom=param.AfterFirst('#');
    int cont_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));// position of contour position inb contours array
    pom=pom.AfterFirst('#');
    wxString colour_code=pom.BeforeFirst('#'); //colour code string
    pom=pom.AfterFirst('#');
    int ext_r=0; //external contour red colour
    int ext_g=0; //external contour green colour
    int ext_b=0; //external contour blue color
    ext_r=wxAtoi(colour_code.BeforeFirst(','));
    colour_code=colour_code.AfterFirst(',');
    ext_g=wxAtoi(colour_code.BeforeFirst(','));
    ext_b=wxAtoi(colour_code.AfterFirst(','));
    colour_code=pom.BeforeFirst('#');

    int ticness=wxAtoi(pom.BeforeFirst('#')); //Ticknes of the contours lines
    int line_type=8; //type of the contours segments
    if(pom.AfterFirst('#')==_("4")) line_type=4;
    if(pom.AfterFirst('#')==_("CV_AA"))line_type=CV_AA;

     if((sour_pic_pos<0)||(sour_pic_pos>19)) return -1; // bad position of source picture in picture array
     if((cont_pos<0)||(cont_pos>19)) return -2; // bad position of contour in contours array
     if((ext_r<0)||(ext_r>255)) return -3; //bad  external contour color code
     if((ext_b<0)||(ext_b>255)) return -3; // bad external contour colour code
     if((ext_g<0)||(ext_g>255)) return -3; // bad external contour colour code


     try
     {
      for(unsigned int i=0;i<pd->contoursx[cont_pos].size();i++)
      {
        drawContours(pd->imgx[sour_pic_pos],pd->contoursx[cont_pos],i,Scalar(ext_b,ext_g,ext_r),ticness,line_type,pd->hierarchy[cont_pos]);
      }
     }
    catch( cv::Exception& e )
   {
       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }

     return 0;
 }

 /*************************************************************************************
Class for find object from contours
**************************************************************************************/
 int Object_Find::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>5) return -2;

   if(line==0)
  {
     name=wxT("Source picture");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=0;i<20;i++)
        {
           pom=_("Picture_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
  }
      if(line==1)
  {
     name=wxT("Contours");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=0;i<20;i++)
        {
           pom=_("Contour_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
  }

   if(line==2)
  {
     name=wxT("Object block number");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=1;i<21;i++)
        {
           pom=_("Block_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
  }

  if(line==3)
  {
     name=wxT("Object read mode");
        type=2;
        wxArrayString arraystr;


          arraystr.Add(_("Basic"));
          arraystr.Add(_("All"));

        aray_str=arraystr;
        type2=0;
  }

     if(line==4)
    {
       name=wxT("Results to");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        arraystr.Add(_("None"));
        for(int i=0;i<100;i++)
        {
           pom=_("Variable_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
    }
      if(line==5)
  {
     name=wxT("List of objects");
        type=2;
        wxArrayString arraystr;


          arraystr.Add(_("New"));
          arraystr.Add(_("Append"));

        aray_str=arraystr;
        type2=0;
  }

  return 0;
}

 int Object_Find::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
 int picture_pos= wxAtoi(param.BeforeFirst('#').AfterFirst('_'));//position of source picture in picture array
   wxString pom=param.AfterFirst('#');
 int contour_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));//position of contours in contour array
   pom=pom.AfterFirst('#');
 int object_block= wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));//Block number
   pom=pom.AfterFirst('#');
int mode=0;
    if(pom.BeforeFirst('#')==_("All")) mode=1;
    else mode=0;

      int result_pos=-1;
     pom=pom.AfterFirst('#');
   if(pom.BeforeFirst('#')!=_("None"))
   {
       result_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
       if((result_pos<0)||(result_pos>99))return -3; //bad position in result variable index
   }

   bool clear_obj=false;
   if(pom.AfterFirst('#')==_("New"))clear_obj=true;
   else clear_obj=false;

  if((picture_pos<0)||(picture_pos>19)) return -1; // Bad picture position in picture ARRAY
  if((contour_pos<0)||(contour_pos>19)) return -2; // Bad contour position in contour array
  if((object_block<1)||(object_block>20)) return -4; //Bad object block number it must be from range 1 to 20

  pd->ival[0]=picture_pos;
  pd->ival[1]=contour_pos;

#ifndef ELI_SHARED_LIB
  if(edit==1)
  {

    ContourDescript *cont=new ContourDescript(0,wxID_ANY,wxDefaultPosition,wxDefaultSize,pd,obp,object_block);

    cont->ShowModal();

   delete cont;
  }
#endif
try
{
  ContourCalculation *calc=new ContourCalculation(pd->contoursx[contour_pos],obp,object_block,mode);
  if(calc->WasOpenCvError())
  {
      delete calc;
      throw calc->GetStringOpenCvError();
  }
  if(calc->FilterAplication()!=0)
  {
      delete calc;
      return -5; //Filter aplication error
  }
  if(calc->WasOpenCvError())
  {
      delete calc;
      throw calc->GetStringOpenCvError();
  }
  if(calc->FindObjectExecution(&pd->fval[0])!=0)
  {
     if(calc->WasOpenCvError()) throw calc->GetStringOpenCvError();
     else
     {
         delete calc;
       return -6; //Find object execution error
     }

  }

  int nc=calc->ReturnAllFoundObjectsNum();
  if(result_pos>-1)pd->fval[result_pos]=nc;

  if(nc==0)
  {
      delete calc;
      return 0;
  }

   OBJECTFOUND *obj;

  obj=new OBJECTFOUND[nc];

  int rt=calc->ReturnAllFoundObjects(obj,mode);
  for(int i=0;i<nc;i++) obj[i].char_activated=false;

  if(rt==-1) return -7; //No object found in the function
  if(rt==-2)return -8 ; //if OBJECTFOUND structure was not allocated
  if(rt==-3) return -9; // input OBJECTFOUND structure was not allocated

  if(clear_obj)pd->obj.clear();
  for(int i=0;i<nc;i++) pd->obj.push_back(obj[i]);

  delete[] obj;

  delete calc;
 }

catch(wxString mesx)
{
    wxString mes=_("Contour calculation error \nLine:");
  mes<<line;
  mes+=_("Description:");
  mes+=mesx;
  return -90;
}

     return 0;
 }

  /**
 Class for draw object labels on selected picture
 **/
  int Object_Labels::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
  {
  if(line<0)return -1;
  if(line>10) return -2;

if(line==0)
  {
     name=wxT("Source picture");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=0;i<20;i++)
        {
           pom=_("Picture_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
  }
if(line==1) //
{
    name=wxT("Object name");
    type=1;
    str=wxT(" ");
    type2=0;
}
if(line==2)
{
        name=wxT("Position");
        type=2;
        wxArrayString arraystr;
        arraystr.Add(_("Top"));
        arraystr.Add(_("Bottom"));
        arraystr.Add(_("Left"));
        arraystr.Add(_("Right"));

        aray_str=arraystr;
        type2=0;
}
if(line==3)
{
     name=wxT("Dimension from object");
      type=4;
      ival=1;
}

if(line==4)
{
        name=wxT("Parameter");
        type=2;
        wxArrayString arraystr;
        arraystr.Add(_("Rect X"));
        arraystr.Add(_("Rect Y"));
        arraystr.Add(_("Rect height"));
        arraystr.Add(_("Rect width"));
        arraystr.Add(_("Perimeter"));
        arraystr.Add(_("Area"));
        arraystr.Add(_("Min Rect X"));
        arraystr.Add(_("MIn Rect Y"));
        arraystr.Add(_("Min Rect height"));
        arraystr.Add(_("Min Rect width"));
        arraystr.Add(_("Min rect angle"));
        arraystr.Add(_("Circle X"));
        arraystr.Add(_("Circle Y"));
        arraystr.Add(_("Circle radius"));
        arraystr.Add(_("Fit_ellipse_center_X"));
        arraystr.Add(_("Fit_ellipse_center_Y"));
        arraystr.Add(_("Fit_ellipse_Height"));
        arraystr.Add(_("Fit_ellipse_Width"));
        arraystr.Add(_("Fit_ellipse_Angle"));
        arraystr.Add(_("Derived_0"));
        arraystr.Add(_("Derived_1"));
        arraystr.Add(_("Derived_2"));
        arraystr.Add(_("Derived_3"));
        arraystr.Add(_("Derived_4"));
        arraystr.Add(_("Derived_5"));
        arraystr.Add(_("Derived_6"));
        arraystr.Add(_("Derived_7"));
        arraystr.Add(_("Derived_8"));
        arraystr.Add(_("Derived_9"));

        aray_str=arraystr;
        type2=0;
}
if(line==5)
  {
       name=wxT("Label color");

        type=1; //file path string type
        str=wxT("0,0,0");
        type2=3;//open collor dialog will display
  }

  if(line==6)
{
        name=wxT("Unit");
        type=2;
        wxArrayString arraystr;
        arraystr.Add(_("pixels"));
        arraystr.Add(_("mm"));

        aray_str=arraystr;
        type2=0;
}
    if(line==7)
  {
      name=wxT("Tickness");
      type=4;
      ival=1;
  }

    if(line==8)
  {
      name=wxT("Scale");
      type=5;
      fval=1.0;
  }
   if(line==9)
   {
        name=wxT("Font");
        type=2;
        wxArrayString arraystr;
        arraystr.Add(_("FONT_HERSHEY_SIMPLEX"));
        arraystr.Add(_("FONT_HERSHEY_PLAIN"));
        arraystr.Add(_("FONT_HERSHEY_DUPLEX"));
        arraystr.Add(_("FONT_HERSHEY_COMPLEX"));
        arraystr.Add(_("FONT_HERSHEY_TRIPLEX"));
        arraystr.Add(_("FONT_HERSHEY_COMPLEX_SMALL"));
        arraystr.Add(_("FONT_HERSHEY_SCRIPT_SIMPLEX"));
        arraystr.Add(_("FONT_HERSHEY_SCRIPT_COMPLEX"));
        arraystr.Add(_("FONT_ITALIC"));
        aray_str=arraystr;
        type2=0;
   }
      if(line==10)
    {
         name=wxT("Get undistortion chan");
         type=2;
        wxArrayString arraystr;
        wxString pom;
        arraystr.Add(_("None"));
        for(int i=0;i<20;i++)
        {
             pom=_("Chan_");
          pom<<i;
          arraystr.Add(pom);
        }

        aray_str=arraystr;
        type2=0;
    }
      return 0;
}

  int Object_Labels::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
  {
       int picture_pos= wxAtoi(param.BeforeFirst('#').AfterFirst('_'));//position of source picture in picture array
   wxString pom=param.AfterFirst('#');
wxString object_name=pom.BeforeFirst('#');
pom=pom.AfterFirst('#');
wxString position=pom.BeforeFirst('#');
pom=pom.AfterFirst('#');
int dim_from_object=wxAtoi(pom.BeforeFirst('#'));
pom=pom.AfterFirst('#');
wxString parameterx=pom.BeforeFirst('#');
pom=pom.AfterFirst('#');
wxString lab_col=pom.BeforeFirst('#');
pom=pom.AfterFirst('#');
wxString unitx=pom.BeforeFirst('#');
pom=pom.AfterFirst('#');
int thick=wxAtoi(pom.BeforeFirst('#'));
pom=pom.AfterFirst('#');
double scalex=wxAtof(pom.BeforeFirst('#'));
pom=pom.AfterFirst('#');
wxString font_string=pom.BeforeFirst('#');
int uch=-1;
       if(pom.AfterFirst('#')==_("None"))uch=-1;
   else  uch=wxAtoi(param.AfterFirst('#').AfterFirst('_'));

   int ext_r=0; //external contour red colour
    int ext_g=0; //external contour green colour
    int ext_b=0; //external contour blue color
    ext_r=wxAtoi(lab_col.BeforeFirst(','));
    lab_col=lab_col.AfterFirst(',');
    ext_g=wxAtoi(lab_col.BeforeFirst(','));
    ext_b=wxAtoi(lab_col.AfterFirst(','));

   if((picture_pos<0)||(picture_pos>19)) return -1; // bad position of source picture in picture array
     if((ext_r<0)||(ext_r>255)) return -2; //bad  external contour color code
     if((ext_b<0)||(ext_b>255)) return -2; // bad external contour colour code
     if((ext_g<0)||(ext_g>255)) return -2; // bad external contour colour code

      if(unitx!=_("pixels")) //Displayed value will be in milimeters
      {
         if(uch==-1) return -3; //No undistortion channel was selected

         if((uch<0)||(uch>19))return -4; //BAd undistortion channel (Channel must be from range <0..19>
         if(pd->pix_per_mm[uch]<0.00001) return -5; //Pixels per milimeter is close to 0
      }

     int par_type=0;

      if(parameterx==_("Rect X"))par_type=1; //Rectifier x point
      if(parameterx==_("Rect Y"))par_type=2;
      if(parameterx==_("Rect height"))par_type=3;
      if(parameterx==_("Rect width"))par_type=4;
      if(parameterx==_("Perimeter"))par_type=5;
      if(parameterx==_("Area"))par_type=6;
      if(parameterx==_("Min Rect X"))par_type=7;
      if(parameterx==_("MIn Rect Y"))par_type=8;
      if(parameterx==_("Min Rect height"))par_type=9;
      if(parameterx==_("Min Rect width"))par_type=10;
      if(parameterx==_("Min rect angle"))par_type=11;
      if(parameterx==_("Circle X"))par_type=12;
      if(parameterx==_("Circle Y"))par_type=13;
      if(parameterx==_("Circle radius"))par_type=14;
      if(parameterx==_("Fit_ellipse_center_X"))par_type=15;
      if(parameterx==_("Fit_ellipse_center_Y"))par_type=16;
      if(parameterx==_("Fit_ellipse_Height"))par_type=17;
      if(parameterx==_("Fit_ellipse_Width"))par_type=18;
      if(parameterx==_("Fit_ellipse_Angle"))par_type=19;
      if(parameterx==_("Derived_0"))par_type=20;
      if(parameterx==_("Derived_1"))par_type=21;
      if(parameterx==_("Derived_2"))par_type=22;
      if(parameterx==_("Derived_3"))par_type=23;
      if(parameterx==_("Derived_4"))par_type=24;
      if(parameterx==_("Derived_5"))par_type=25;
      if(parameterx==_("Derived_6"))par_type=26;
      if(parameterx==_("Derived_7"))par_type=27;
      if(parameterx==_("Derived_8"))par_type=28;
      if(parameterx==_("Derived_9"))par_type=29;

      if(pd->imgx[picture_pos].channels()<3)cvtColor(pd->imgx[picture_pos],pd->imgx[picture_pos],CV_GRAY2RGB);

      wxString labl_text=wxEmptyString;
      int ft=0;
      if(font_string==_("FONT_HERSHEY_SIMPLEX"))ft=CV_FONT_HERSHEY_SIMPLEX;
      if(font_string==_("FONT_HERSHEY_PLAIN"))ft=CV_FONT_HERSHEY_PLAIN;
      if(font_string==_("FONT_HERSHEY_DUPLEX"))ft=CV_FONT_HERSHEY_DUPLEX;
      if(font_string==_("FONT_HERSHEY_COMPLEX"))ft=CV_FONT_HERSHEY_COMPLEX;
      if(font_string==_("FONT_HERSHEY_TRIPLEX"))ft=CV_FONT_HERSHEY_TRIPLEX;
      if(font_string==_("FONT_HERSHEY_COMPLEX_SMALL"))ft=CV_FONT_HERSHEY_COMPLEX_SMALL;
      if(font_string==_("FONT_HERSHEY_SCRIPT_SIMPLEX"))ft=CV_FONT_HERSHEY_SCRIPT_SIMPLEX;
      if(font_string==_("FONT_HERSHEY_SCRIPT_COMPLEX"))ft=CV_FONT_HERSHEY_SCRIPT_COMPLEX;
      if(font_string==_("FONT_ITALIC"))ft=CV_FONT_ITALIC;

  try
    {
     if(pd->obj.size()==0)return 0;
     else
     {

         for(unsigned int i=0;i<pd->obj.size();i++)
          {
           if(object_name==pd->obj[i].object_name)
           {
               switch(par_type)
               {
                   case 1: //Rectifier X
                    if(unitx==_("pixels")) labl_text.Printf(_("%d"),pd->obj[i].bounding_rect_x);
                    else labl_text.Printf(_("%.2f"),(float)pd->obj[i].bounding_rect_x/pd->pix_per_mm[uch]);

                   break;
                   case 2: //Rectifier Y
                    if(unitx==_("pixels")) labl_text.Printf(_("%d"),pd->obj[i].bounding_rect_y);
                    else labl_text.Printf(_("%.2f"),(float)pd->obj[i].bounding_rect_y/pd->pix_per_mm[uch]);
                   break;
                   case 3://Rectifier height
                    if(unitx==_("pixels")) labl_text.Printf(_("%d"),pd->obj[i].bounding_rect_height);
                    else labl_text.Printf(_("%.2f"),(float)pd->obj[i].bounding_rect_height/pd->pix_per_mm[uch]);
                   break;
                   case 4://Rectifier width
                    if(unitx==_("pixels")) labl_text.Printf(_("%d"),pd->obj[i].bounding_rect_width);
                    else labl_text.Printf(_("%.2f"),(float)pd->obj[i].bounding_rect_width/pd->pix_per_mm[uch]);
                   break;
                   case 5: //Perimeter
                    if(unitx==_("pixels")) labl_text.Printf(_("%.2f"),pd->obj[i].perimeter);
                    else labl_text.Printf(_("%.2f"),pd->obj[i].perimeter/pd->pix_per_mm[uch]);
                   break;
                   case 6: //Area
                   if(unitx==_("pixels")) labl_text.Printf(_("%.2f"),pd->obj[i].contour_area);
                   else labl_text.Printf(_("%.2f"),pd->obj[i].contour_area/pd->pix_per_mm[uch]);
                   break;
                   case 7://Minimal rectifier X
                     if(unitx==_("pixels")) labl_text.Printf(_("%d"),pd->obj[i].min_area_rect_x);
                     else labl_text.Printf(_("%.2f"),(float)pd->obj[i].min_area_rect_x/pd->pix_per_mm[uch]);
                   break;
                   case 8://Minimal rectifier Y
                    if(unitx==_("pixels")) labl_text.Printf(_("%d"),pd->obj[i].min_area_rect_y);
                    else labl_text.Printf(_("%.2f"),(float)pd->obj[i].min_area_rect_y/pd->pix_per_mm[uch]);
                   break;
                   case 9://Minimal rectifier height
                    if(unitx==_("pixels")) labl_text.Printf(_("%d"),pd->obj[i].min_area_rect_height);
                    else labl_text.Printf(_("%.2f"),(float)pd->obj[i].min_area_rect_height/pd->pix_per_mm[uch]);
                   break;
                   case 10://Minimal rectifier width
                    if(unitx==_("pixels")) labl_text.Printf(_("%d"),pd->obj[i].min_area_rect_width);
                    else labl_text.Printf(_("%.2f"),(float)pd->obj[i].min_area_rect_width/pd->pix_per_mm[uch]);
                   break;
                   case 11: //Minimal rectifier angle
                     labl_text.Printf(_("%.2f"),pd->obj[i].min_area_rect_angle);
                   break;
                   case 12://Circle X
                    if(unitx==_("pixels")) labl_text.Printf(_("%d"),pd->obj[i].min_enclosing_circle_center_X);
                    else labl_text.Printf(_("%.2f"),(float)pd->obj[i].min_enclosing_circle_center_X/pd->pix_per_mm[uch]);
                   break;
                   case 13://Circle Y
                    if(unitx==_("pixels")) labl_text.Printf(_("%d"),pd->obj[i].min_enclosing_circle_center_Y);
                    else labl_text.Printf(_("%.2f"),(float)pd->obj[i].min_enclosing_circle_center_Y/pd->pix_per_mm[uch]);
                   break;
                   case 14://Circle radius
                    if(unitx==_("pixels")) labl_text.Printf(_("%.2f"),pd->obj[i].min_enclosing_circle_radius);
                    else labl_text.Printf(_("%.2f"),pd->obj[i].min_enclosing_circle_radius/pd->pix_per_mm[uch]);
                   break;
                    case 15://Fit elipse center X
                    if(unitx==_("pixels")) labl_text.Printf(_("%d"),pd->obj[i].fit_elipse_center_X);
                    else labl_text.Printf(_("%.2f"),pd->obj[i].fit_elipse_center_X/pd->pix_per_mm[uch]);
                   break;
                   case 16://Fit elipse center Y
                    if(unitx==_("pixels")) labl_text.Printf(_("%d"),pd->obj[i].fit_elipse_center_Y);
                    else labl_text.Printf(_("%.2f"),pd->obj[i].fit_elipse_center_Y/pd->pix_per_mm[uch]);
                   break;
                   case 17://Fit_ellipse_Height
                    if(unitx==_("pixels")) labl_text.Printf(_("%d"),pd->obj[i].fit_elipse_height);
                    else labl_text.Printf(_("%.2f"),pd->obj[i].fit_elipse_height/pd->pix_per_mm[uch]);
                   break;
                    case 18://Fit_ellipse_width
                    if(unitx==_("pixels")) labl_text.Printf(_("%d"),pd->obj[i].fit_elipse_width);
                    else labl_text.Printf(_("%.2f"),pd->obj[i].fit_elipse_width/pd->pix_per_mm[uch]);
                   break;
                   case 19://Fit_ellipse_angle
                    if(unitx==_("pixels")) labl_text.Printf(_("%.2f"),pd->obj[i].fit_elipse_angle);
                    else labl_text.Printf(_("%.2f"),pd->obj[i].fit_elipse_angle/pd->pix_per_mm[uch]);
                   break;
                   case 20://Derived 0
                    if(unitx==_("pixels")) labl_text.Printf(_("%.2f"),pd->obj[i].derived[0]);
                    else labl_text.Printf(_("%.2f"),pd->obj[i].derived[0]/pd->pix_per_mm[uch]);
                   break;
                   case 21://Derived 1
                    if(unitx==_("pixels")) labl_text.Printf(_("%.2f"),pd->obj[i].derived[1]);
                    else labl_text.Printf(_("%.2f"),pd->obj[i].derived[1]/pd->pix_per_mm[uch]);
                   break;
                   case 22://Derived 2
                    if(unitx==_("pixels")) labl_text.Printf(_("%.2f"),pd->obj[i].derived[2]);
                    else labl_text.Printf(_("%.2f"),pd->obj[i].derived[2]/pd->pix_per_mm[uch]);
                   break;
                   case 23://Derived 3
                    if(unitx==_("pixels")) labl_text.Printf(_("%.2f"),pd->obj[i].derived[3]);
                    else labl_text.Printf(_("%.2f"),pd->obj[i].derived[3]/pd->pix_per_mm[uch]);
                   break;
                   case 24://Derived 4
                    if(unitx==_("pixels")) labl_text.Printf(_("%.2f"),pd->obj[i].derived[4]);
                    else labl_text.Printf(_("%.2f"),pd->obj[i].derived[4]/pd->pix_per_mm[uch]);
                   break;
                   case 25://Derived 5
                    if(unitx==_("pixels")) labl_text.Printf(_("%.2f"),pd->obj[i].derived[5]);
                    else labl_text.Printf(_("%.2f"),pd->obj[i].derived[5]/pd->pix_per_mm[uch]);
                   break;
                   case 26://Derived 6
                    if(unitx==_("pixels")) labl_text.Printf(_("%.2f"),pd->obj[i].derived[6]);
                    else labl_text.Printf(_("%.2f"),pd->obj[i].derived[6]/pd->pix_per_mm[uch]);
                   break;
                   case 27://Derived 7
                    if(unitx==_("pixels")) labl_text.Printf(_("%.2f"),pd->obj[i].derived[7]);
                    else labl_text.Printf(_("%.2f"),pd->obj[i].derived[7]/pd->pix_per_mm[uch]);
                   break;
                   case 28://Derived 8
                    if(unitx==_("pixels")) labl_text.Printf(_("%.2f"),pd->obj[i].derived[8]);
                    else labl_text.Printf(_("%.2f"),pd->obj[i].derived[8]/pd->pix_per_mm[uch]);
                   break;
                   case 29://Derived 9
                    if(unitx==_("pixels")) labl_text.Printf(_("%.2f"),pd->obj[i].derived[9]);
                    else labl_text.Printf(_("%.2f"),pd->obj[i].derived[9]/pd->pix_per_mm[uch]);
                   break;
               }

        String pxx;
        pxx=labl_text.mb_str();
        CvPoint p1;
        if(position==_("Top"))
        {
          p1.x=pd->obj[i].bounding_rect_x;
        p1.y=pd->obj[i].bounding_rect_y-dim_from_object;
        if(p1.y<1)p1.y=1;
        }
        else if(position==_("Bottom"))
        {
         p1.x=pd->obj[i].bounding_rect_x;
         p1.y=pd->obj[i].bounding_rect_y+pd->obj[i].bounding_rect_height+dim_from_object;
        }
        else if(position==_("Left"))
        {
           p1.x=pd->obj[i].bounding_rect_x-dim_from_object;
           if(p1.x<1)p1.x=1;
          p1.y=pd->obj[i].bounding_rect_y+(pd->obj[i].bounding_rect_height/2);
        }
        else
        {
           p1.x=pd->obj[i].bounding_rect_x+pd->obj[i].bounding_rect_width+dim_from_object;
          p1.y=pd->obj[i].bounding_rect_y+(pd->obj[i].bounding_rect_height/2);
        }

        putText(pd->imgx[picture_pos],pxx,p1,ft,scalex,Scalar(ext_b,ext_g,ext_r),thick);
           }
         }
      }

     }

         catch( cv::Exception& e )
   {
       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }


      return 0;
  }

  /*************************************************************************************
Class for draw objects on selected picture
**************************************************************************************/
 int Object_Draw::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>4) return -2;

if(line==0)
  {
     name=wxT("Source picture");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=0;i<20;i++)
        {
           pom=_("Picture_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
  }
  if(line==1) //
{
    name=wxT("Object name");
    type=1;
    str=wxT(" ");
    type2=0;
}
if(line==2)
  {
     name=wxT("Object draw mode");
        type=2;
        wxArrayString arraystr;


          arraystr.Add(_("Rectangle"));
          arraystr.Add(_("Circle"));

        aray_str=arraystr;
        type2=0;
  }
if(line==3)
  {
       name=wxT("Object color");

        type=1; //file path string type
        str=wxT("0,0,0");
        type2=3;//open collor dialog will display
  }

if(line==4)
  {
      name=wxT("Line Tickness");
      type=4;
      ival=1;
  }

  return 0;
}
  int Object_Draw::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
   int sour_pic_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));//position of source picture in picture array
      wxString pom=param.AfterFirst('#');
   wxString object_name= pom.BeforeFirst('#');// object name
    pom=pom.AfterFirst('#');
    int draw_mode=0;//rectange
    if(pom.BeforeFirst('#')==_("Rectangle"))draw_mode=0;
    else draw_mode=1;
    pom=pom.AfterFirst('#');
    wxString colour_code=pom.BeforeFirst('#'); //colour code string

    int ext_r=0; //external contour red colour
    int ext_g=0; //external contour green colour
    int ext_b=0; //external contour blue color
    ext_r=wxAtoi(colour_code.BeforeFirst(','));
    colour_code=colour_code.AfterFirst(',');
    ext_g=wxAtoi(colour_code.BeforeFirst(','));
    ext_b=wxAtoi(colour_code.AfterFirst(','));
    colour_code=pom.BeforeFirst('#');

    int ticness=wxAtoi(pom.AfterFirst('#')); //Ticknes of the contours lines


     if((sour_pic_pos<0)||(sour_pic_pos>19)) return -1; // bad position of source picture in picture array
     if((ext_r<0)||(ext_r>255)) return -3; //bad  external contour color code
     if((ext_b<0)||(ext_b>255)) return -3; // bad external contour colour code
     if((ext_g<0)||(ext_g>255)) return -3; // bad external contour colour code

try
    {
     if(pd->obj.size()==0)return 0;
     else
     {

           for(unsigned int i=0;i<pd->obj.size();i++)
          {
           if(object_name==pd->obj[i].object_name)
           {

               //draw object
               if(draw_mode==0)//draw rectangle
               {
              Rect rc;
              rc.x=pd->obj[i].bounding_rect_x;
              rc.y=pd->obj[i].bounding_rect_y;
              rc.height=pd->obj[i].bounding_rect_height;
              rc.width=pd->obj[i].bounding_rect_width;
              rectangle(pd->imgx[sour_pic_pos],rc,Scalar(ext_b,ext_g,ext_r),ticness);
               }
               else //draw circle
               {
               Point pt;
               pt.x=pd->obj[i].bounding_rect_x+pd->obj[i].bounding_rect_width/2;
               pt.y=pd->obj[i].bounding_rect_y+pd->obj[i].bounding_rect_height/2;
               int radius;
               pd->obj[i].bounding_rect_width > pd->obj[i].bounding_rect_height ? radius=pd->obj[i].bounding_rect_width/2 : radius=pd->obj[i].bounding_rect_height/2;
                circle(pd->imgx[sour_pic_pos],pt,radius,Scalar(ext_b,ext_g,ext_r),ticness);
               }
           }
         }
         }

     }

         catch( cv::Exception& e )
   {
       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }

     return 0;
 }

/*************************************************************************************
Class for count number of selected objects
**************************************************************************************/
 int Object_Count::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1; //Bad line number
  if(line>1) return -2; //Bad line number

if(line==0) //
{
    name=wxT("Object name");
    type=1;
    str=wxT(" ");
    type2=0;
}

    if(line==1)
    {
       name=wxT("Results to");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=0;i<100;i++)
        {
           pom=_("Variable_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
    }

  return 0;
}

  int Object_Count::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
     wxString object_name=param.BeforeFirst('#');
      int result_pos=wxAtoi(param.AfterFirst('#').AfterFirst('_'));
       if((result_pos<0)||(result_pos>99))return -1; //bad position in result variable index
       int countx=0;

        for(unsigned int i=0;i<pd->obj.size();i++)
          {
           if(object_name==pd->obj[i].object_name)countx++;
          }

      pd->fval[result_pos]=(float)countx;

     return 0;
 }

 /*************************************************************************************
Class for transfer objects to character
**************************************************************************************/
 int Object_ToChar::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1; //Bad line number
  if(line>1) return -2; //Bad line number

if(line==0) //
{
    name=wxT("Object name");
    type=1;
    str=wxT(" ");
    type2=0;
}

if(line==1) //
{
    name=wxT("Character");
    type=1;
    str=wxT(" ");
    type2=0;
}

return 0;
}

 int Object_ToChar::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
     wxString object_name=param.BeforeFirst('#');
     wxString paramx=param.AfterFirst('#');
     wxChar letx;
     bool found=false;

    for(unsigned int i=0;i<paramx.Length();i++)
    {
        if(!found)
        {
            if(paramx[i]!=' ')
             {
           letx=paramx[i];
           found=true;
             }
        }

    }

    if(!found)return -1; // No characters in parameters

    for(unsigned int i=0;i<pd->obj.size();i++)
    {
        if(pd->obj[i].object_name==object_name)
        {
            pd->obj[i].char_activated=true;
            pd->obj[i].chr=letx;
        }
    }


     return 0;
 }

  /*************************************************************************************
Class for transfer objects to character
**************************************************************************************/
 int Object_CharToString::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1; //Bad line number
  if(line>4) return -2; //Bad line number

  if(line==0)
  {
     name=wxT("String direction");
        type=2;
        wxArrayString arraystr;


          arraystr.Add(_("Left -> Right"));
          arraystr.Add(_("Right -> Left"));
          arraystr.Add(_("Top -> Bottom"));
          arraystr.Add(_("Bottom -> Top"));

        aray_str=arraystr;
        type2=0;
  }
  if(line==1)
  {
      name=wxT("Line width");
      type=4;
      ival=10;
  }

  if(line==2)
  {
      name=wxT("Space size");
      type=4;
      ival=0;
  }

  if(line==3) //
{
    name=wxT("Space object");
    type=1;
    str=wxT(" ");
    type2=0;
}

  if(line==4)
  {
               name=wxT("Result to");
        type=2;
        wxArrayString arraystr;
        wxString pom;

        for(int i=0;i<10;i++)
        {
           pom=_("String_");
          pom<<i;
          arraystr.Add(pom);
        }

        for(int i=0;i<100;i++)
        {
           pom=_("Variable_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
  }

  return 0;
}

bool compareByX(const OBJECTX2 &x1,const OBJECTX2 &x2)
{
    return x1.x < x2.x;
}

bool compareByX2(const OBJECTX2 &x1,const OBJECTX2 &x2)
{
    return x1.x > x2.x;
}

bool compareByY(const OBJECTX2 &y1,const OBJECTX2 &y2)
{
    return y1.y < y2.y;
}

bool compareByY2(const OBJECTX2 &y1,const OBJECTX2 &y2)
{
    return y1.y > y2.y;
}

int Object_CharToString::SortObjectFunction(std::vector<OBJECTX2> obxx,wxString &out_mes,int direction,int line_width,int space_size)
{
     std::vector<OBJECTX2> obxx2,obxx3;

     obxx2.clear();
     obxx3.clear();

     OBJECTX2 o2;

   if((direction<1)||(direction>4))return -1;



     if(direction<3)std::sort(obxx.begin(),obxx.end(),compareByY);
     else std::sort(obxx.begin(),obxx.end(),compareByX);


     for(unsigned int i=0;i<obxx.size();i++)
     {
         obxx2.push_back(obxx[i]);
         if(direction<3)
         {
              if(i<(obxx.size()-1))
           {
              if((obxx[i].y+line_width)<(obxx[i+1].y))
             {
            if(direction==1) std::sort(obxx2.begin(),obxx2.end(),compareByX);
            if(direction==2) std::sort(obxx2.begin(),obxx2.end(),compareByX2);

            for(unsigned int j=0;j<obxx2.size();j++)obxx3.push_back(obxx2[j]);
            o2.x=0;
            o2.y=0;
            o2.chr='\n';
            obxx3.push_back(o2);
            obxx2.clear();
            }
           }
           else
           {
            if(direction==1) std::sort(obxx2.begin(),obxx2.end(),compareByX);
            if(direction==2) std::sort(obxx2.begin(),obxx2.end(),compareByX2);

            for(unsigned int j=0;j<obxx2.size();j++)obxx3.push_back(obxx2[j]);
            obxx3.push_back(o2);
           }
         }
         else
         {
                 if(i<(obxx.size()-1))
           {
              if((obxx[i].x+line_width)<(obxx[i+1].x))
             {

            if(direction==3) std::sort(obxx2.begin(),obxx2.end(),compareByY);
            if(direction==4) std::sort(obxx2.begin(),obxx2.end(),compareByY2);
            for(unsigned int j=0;j<obxx2.size();j++)obxx3.push_back(obxx2[j]);
            o2.x=0;
            o2.y=0;
            o2.chr='\n';
            obxx3.push_back(o2);
            obxx2.clear();
            }
           }
           else
           {

            if(direction==3) std::sort(obxx2.begin(),obxx2.end(),compareByY);
            if(direction==4) std::sort(obxx2.begin(),obxx2.end(),compareByY2);
            for(unsigned int j=0;j<obxx2.size();j++)obxx3.push_back(obxx2[j]);
            obxx3.push_back(o2);
           }
         }



     }



     out_mes=wxEmptyString;
     bool space_find=false;
for(unsigned int i=0;i<obxx3.size();i++)
{
    if(space_size>0)
    {
        if(i<(obxx3.size()-1))
        {
        if((obxx3[i].chr!='\n')&&(obxx3[i+1].chr!='\n'))
        {
            if(direction<3)
            {
               if(abs(obxx3[i+1].x-obxx3[i].x)>space_size)space_find=true;
            }
            else
            {
               if(abs(obxx3[i+1].y-obxx3[i].y)>space_size)
               space_find=true;
            }

        }
       }
    }

    out_mes<<obxx3[i].chr;
    if(space_find)out_mes+=_(" ");
    space_find=false;
}
    return 0;
}

int Object_CharToString::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
   wxString string_dire=param.BeforeFirst('#');
     wxString pom=param.AfterFirst('#');
     int line_width=wxAtoi(pom.BeforeFirst('#'));
     pom=pom.AfterFirst('#');
     int space_size=wxAtoi(pom.BeforeFirst('#'));
     pom=pom.AfterFirst('#');
     wxString space_object=pom.BeforeFirst('#');
     bool is_string=true;

     if(pom.AfterFirst('#').BeforeFirst('_')==_("String"))is_string=true;
     else is_string=false;

     int ar_pos=wxAtoi(pom.AfterFirst('#').AfterFirst('_'));
     if(line_width<0) return -1; //Line width is negative
     if(space_size<0) return -2; // Space size is negative
     if(is_string)
     {
         if((ar_pos<0)||(ar_pos>10)) return -3; //Bad array position in string array
     }
     else
     {
         if((ar_pos<0)||(ar_pos>99)) return -4; //Bad position in floating array
     }

     int string_direction=0;
     if(string_dire==_("Left -> Right"))string_direction=1;
     else if(string_dire==_("Right -> Left"))string_direction=2;
     else if(string_dire==_("Top -> Bottom"))string_direction=3;
     else string_direction=4;

     vector<OBJECTX2> obxx;

     obxx.clear();


     OBJECTX2 o2;

     for(unsigned int i=0;i<pd->obj.size();i++)
     {
         if(pd->obj[i].char_activated)
         {
             o2.x=pd->obj[i].bounding_rect_x;
             o2.y=pd->obj[i].bounding_rect_y;
             o2.chr=pd->obj[i].chr;

             obxx.push_back(o2);
         }
     }

     if(space_object!=_(" "))
     {
         for(unsigned int i=0;i<pd->obj.size();i++)
       {
         if(pd->obj[i].object_name==space_object)
         {
             o2.x=pd->obj[i].bounding_rect_x;
             o2.y=pd->obj[i].bounding_rect_y;
             o2.chr=' ';

             obxx.push_back(o2);
         }
       }
     }

wxString out_mes=wxEmptyString;

if(SortObjectFunction(obxx,out_mes,string_direction,line_width,space_size)!=0) return -5; //Error in function  SortObjectFunction

if(is_string)pd->str_values[ar_pos]=out_mes;
else pd->fval[ar_pos]=wxAtof(out_mes);


     return 0;
 }

  /**
 Class for Object parameters mathematic
 **/
int Object_ParamMath::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>5) return -2;

if(line==0) //
{
    name=wxT("Object name");
    type=1;
    str=wxT(" ");
    type2=0;
}

if((line==1)||(line==3))
{
        if(line==1)name=wxT("Parameter A");
        else name=wxT("Parameter B");
        type=2;
        wxArrayString arraystr;
        if(line==3)arraystr.Add(_("Costant number"));
        arraystr.Add(_("Rect X"));
        arraystr.Add(_("Rect Y"));
        arraystr.Add(_("Rect height"));
        arraystr.Add(_("Rect width"));
        arraystr.Add(_("Perimeter"));
        arraystr.Add(_("Area"));
        arraystr.Add(_("Min Rect X"));
        arraystr.Add(_("MIn Rect Y"));
        arraystr.Add(_("Min Rect height"));
        arraystr.Add(_("Min Rect width"));
        arraystr.Add(_("Min rect angle"));
        arraystr.Add(_("Circle X"));
        arraystr.Add(_("Circle Y"));
        arraystr.Add(_("Circle radius"));
        arraystr.Add(_("Fit_ellipse_center_X"));
        arraystr.Add(_("Fit_ellipse_center_Y"));
        arraystr.Add(_("Fit_ellipse_Height"));
        arraystr.Add(_("Fit_ellipse_Width"));
        arraystr.Add(_("Fit_ellipse_Angle"));
        arraystr.Add(_("Derived_0"));
        arraystr.Add(_("Derived_1"));
        arraystr.Add(_("Derived_2"));
        arraystr.Add(_("Derived_3"));
        arraystr.Add(_("Derived_4"));
        arraystr.Add(_("Derived_5"));
        arraystr.Add(_("Derived_6"));
        arraystr.Add(_("Derived_7"));
        arraystr.Add(_("Derived_8"));
        arraystr.Add(_("Derived_9"));
        aray_str=arraystr;
        type2=0;
}

  if(line==2) // combobox with all operators
    {
      name=wxT("Operator");
        type=2;
        wxArrayString arraystr;
        arraystr.Add(wxT("+"));
        arraystr.Add(wxT("-"));
        arraystr.Add(wxT("*"));
        arraystr.Add(wxT("/"));
        arraystr.Add(wxT("cos(A)"));
        arraystr.Add(wxT("sin(A)"));
        arraystr.Add(wxT("tan(A)"));
        arraystr.Add(wxT("acos(A)"));
        arraystr.Add(wxT("asin(A)"));
        arraystr.Add(wxT("atan(A)"));
        arraystr.Add(wxT("atan2(A,B)"));
        arraystr.Add(wxT("cosh(A)"));
        arraystr.Add(wxT("sinh(A)"));
        arraystr.Add(wxT("tanh(A)"));
        arraystr.Add(wxT("exp(A)"));
        arraystr.Add(wxT("ln(A)"));
        arraystr.Add(wxT("log10(A)"));
        arraystr.Add(wxT("A^B"));
        arraystr.Add(wxT("sqrt(A)"));
        arraystr.Add(wxT("fabs(A)"));
        arraystr.Add(wxT("fmod(A,B)"));
        aray_str=arraystr;
        type2=0;
    }

    if(line==4) // text box for set fixted number
    {
        name=_("Parameter B constant number");
        type=5;
        fval=0.0;
    }

     if(line==5)// Combo box for derived variables
    {
        name=wxT("Result to");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=0;i<10;i++)
        {
           pom=_("Derived_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
    }

  return 0;
}
/**
Function gets objects parameter value and return it
1.parameter: name of parameter
2.parameter: Object name
3.parameter: pointer for PDAT structure
4.parameter: true if there is error on this function, false if not

**/
int Object_ParamMath::GetParameter(wxString parameterx,vector<double> &ret_param,wxString object_name,PDAT *pd)
{
    double ret_par=0;
    int par_type=-1;
    bool er=true;

     if(parameterx==_("Rect X"))par_type=1; //Rectifier x point
      if(parameterx==_("Rect Y"))par_type=2;
      if(parameterx==_("Rect height"))par_type=3;
      if(parameterx==_("Rect width"))par_type=4;
      if(parameterx==_("Perimeter"))par_type=5;
      if(parameterx==_("Area"))par_type=6;
      if(parameterx==_("Min Rect X"))par_type=7;
      if(parameterx==_("MIn Rect Y"))par_type=8;
      if(parameterx==_("Min Rect height"))par_type=9;
      if(parameterx==_("Min Rect width"))par_type=10;
      if(parameterx==_("Min rect angle"))par_type=11;
      if(parameterx==_("Circle X"))par_type=12;
      if(parameterx==_("Circle Y"))par_type=13;
      if(parameterx==_("Circle radius"))par_type=14;
      if(parameterx==_("Fit_ellipse_center_X"))par_type=15;
      if(parameterx==_("Fit_ellipse_center_Y"))par_type=16;
      if(parameterx==_("Fit_ellipse_Height"))par_type=17;
      if(parameterx==_("Fit_ellipse_Width"))par_type=18;
      if(parameterx==_("Fit_ellipse_Angle"))par_type=19;
      if(parameterx==_("Derived_0"))par_type=20;
      if(parameterx==_("Derived_1"))par_type=21;
      if(parameterx==_("Derived_2"))par_type=22;
      if(parameterx==_("Derived_3"))par_type=23;
      if(parameterx==_("Derived_4"))par_type=24;
      if(parameterx==_("Derived_5"))par_type=25;
      if(parameterx==_("Derived_6"))par_type=26;
      if(parameterx==_("Derived_7"))par_type=27;
      if(parameterx==_("Derived_8"))par_type=28;
      if(parameterx==_("Derived_9"))par_type=29;

      ret_param.clear();



     if(pd->obj.size()==0)return 0;
     else
     {

         for(unsigned int i=0;i<pd->obj.size();i++)
          {
           if(object_name==pd->obj[i].object_name)
           {
               er=false;
               if(par_type==1) ret_par=(double)pd->obj[i].bounding_rect_x;
               else if(par_type==2)ret_par=(double)pd->obj[i].bounding_rect_y;
               else if(par_type==3)ret_par=(double)pd->obj[i].bounding_rect_height;
               else if(par_type==4)ret_par=(double)pd->obj[i].bounding_rect_width;
               else if(par_type==5)ret_par=pd->obj[i].perimeter;
               else if(par_type==6)ret_par=pd->obj[i].contour_area;
               else if(par_type==7)ret_par=(double)pd->obj[i].min_area_rect_x;
               else if(par_type==8)ret_par=(double)pd->obj[i].min_area_rect_y;
               else if(par_type==9)ret_par=(double)pd->obj[i].min_area_rect_height;
               else if(par_type==10)ret_par=(double)pd->obj[i].min_area_rect_width;
               else if(par_type==11)ret_par=pd->obj[i].min_area_rect_angle;
               else if(par_type==12)ret_par=(double)pd->obj[i].min_enclosing_circle_center_X;
                else if(par_type==13)ret_par=(double)pd->obj[i].min_enclosing_circle_center_Y;
                else if(par_type==14)ret_par=pd->obj[i].min_enclosing_circle_radius;
                else if(par_type==15)ret_par=(double)pd->obj[i].fit_elipse_center_X;
                else if(par_type==16)ret_par=(double)pd->obj[i].fit_elipse_center_Y;
                else if(par_type==17)ret_par=(double)pd->obj[i].fit_elipse_height;
                else if(par_type==18)ret_par=(double)pd->obj[i].fit_elipse_width;
                else if(par_type==19)ret_par=pd->obj[i].fit_elipse_angle;
                else if(par_type==20)ret_par=pd->obj[i].derived[0];
                else if(par_type==21)ret_par=pd->obj[i].derived[1];
                else if(par_type==22)ret_par=pd->obj[i].derived[2];
                else if(par_type==23)ret_par=pd->obj[i].derived[3];
                else if(par_type==24)ret_par=pd->obj[i].derived[4];
                else if(par_type==25)ret_par=pd->obj[i].derived[5];
                else if(par_type==26)ret_par=pd->obj[i].derived[6];
                else if(par_type==27)ret_par=pd->obj[i].derived[7];
                else if(par_type==28)ret_par=pd->obj[i].derived[8];
                else if(par_type==29)ret_par=pd->obj[i].derived[9];
                else er=true;
                ret_param.push_back(ret_par);
           }
          }
     }

if(er)return -1;
else return 0;

}

int Object_ParamMath::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
{
 wxString object_name=param.BeforeFirst('#'); // Get object name
     wxString pom=param.AfterFirst('#');
     wxString parameterA=pom.BeforeFirst('#'); //Name of parameter A
    pom=pom.AfterFirst('#');
    wxString operatorx=pom.BeforeFirst('#');  //operator name
    pom=pom.AfterFirst('#');
    wxString parameterB=pom.BeforeFirst('#');  //Name of parameter B
    pom=pom.AfterFirst('#');
    double B_constant=wxAtof(pom.BeforeFirst('#'));
    wxString result_var=pom.AfterFirst('#');

    vector<double> varA,varB,resultx;
    resultx.clear();

    int oper=-1;

     if(GetParameter(parameterA,varA,object_name,pd)!=0) return -1; //error get parameterA

    if(parameterB==_("Costant number"))
    {
        for(unsigned i=0;i<varA.size();i++)varB.push_back(B_constant);

    }
    else
    {
     if(GetParameter(parameterB,varB,object_name,pd)!=0) return -2; //Error get parameter B

    }
     /* Finding operator */
     if(operatorx==wxT("+"))oper=1;
     if(operatorx==wxT("-"))oper=2;
     if(operatorx==wxT("*"))oper=3;
     if(operatorx==wxT("/"))oper=4;
     if(operatorx==wxT("cos(A)"))oper=5;
     if(operatorx==wxT("sin(A)"))oper=6;
     if(operatorx==wxT("tan(A)"))oper=7;
     if(operatorx==wxT("acos(A)"))oper=8;
     if(operatorx==wxT("asin(A)"))oper=9;
     if(operatorx==wxT("atan(A)"))oper=10;
     if(operatorx==wxT("atan2(A,B)"))oper=11;
     if(operatorx==wxT("cosh(A)"))oper=12;
     if(operatorx==wxT("sinh(A)"))oper=13;
     if(operatorx==wxT("tanh(A)"))oper=14;
     if(operatorx==wxT("exp(A)"))oper=15;
     if(operatorx==wxT("ln(A)"))oper=16;
     if(operatorx==wxT("log10(A)"))oper=17;
     if(operatorx==wxT("A^B"))oper=18;
     if(operatorx==wxT("sqrt(A)"))oper=19;
     if(operatorx==wxT("fabs(A)"))oper=20;
     if(operatorx==wxT("fmod(A,B)"))oper=21;
     if((oper<1)||(oper>21)) return -3; //Bad operator

     if(varA.size()!=varB.size()) return -4; // VarA size is not same as varB size


    for(unsigned i=0;i<varA.size();i++)
    {

      switch (oper)
     {
         case 1:
           resultx.push_back(varA[i]+varB[i]);
          break;
         case 2:
           resultx.push_back(varA[i]-varB[i]);
          break;
         case 3:
            resultx.push_back(varA[i]*varB[i]);
           break;
         case 4:
            if(varB[i]==0) varB[i]=0.000001;
            resultx.push_back(varA[i]/varB[i]);
           break;
         case 5:
            resultx.push_back(cos(varA[i]));
           break;
         case 6:
           resultx.push_back(sin(varA[i]));
           break;
         case 7:
           resultx.push_back(tan(varA[i]));
          break;
         case 8:
         if(varA[i]<-1) varA[i]=-1;
         if(varA[i]>1)varA[i]=1;
           resultx.push_back(acos(varA[i]));
          break;
         case 9:
             if(varA[i]<-1)varA[i]=-1;
             if(varA[i]>1)varA[i]=1;
            resultx.push_back(asin(varA[i]));
           break;
         case 10:
            resultx.push_back(atan(varA[i]));
           break;
         case 11:
           resultx.push_back(atan2(varA[i],varB[i]));
           break;
         case 12:
           resultx.push_back(cosh(varA[i]));
           break;
         case 13:
           resultx.push_back(sinh(varA[i]));
          break;
         case 14:
         resultx.push_back(tanh(varA[i]));
          break;
         case 15:
           resultx.push_back(exp(varA[i]));
           break;
         case 16:
         if(varA[i]<=0)varA[i]=0.0001;
            resultx.push_back(log(varA[i]));
           break;
         case 17:
         if(varA[i]<=0)varA[i]=0.0001;
            resultx.push_back(log10(varA[i]));
           break;
         case 18:
           resultx.push_back(pow(varA[i],varB[i]));
           break;
         case 19:
           if(varA[i]<0)varA[i]=0;
           resultx.push_back(sqrt(varA[i]));
          break;
         case 20:
           resultx.push_back(fabs(varA[i]));
          break;
         case 21:
            resultx.push_back(fmod(varA[i],varB[i]));
           break;
          default:
            break;
     }

    }


     int posxx=wxAtoi(result_var.AfterFirst('_'));
     if((posxx<0)||(posxx>9))return -5; //Bad result variable
     unsigned xxx=0;
      for(unsigned int i=0;i<pd->obj.size();i++)
          {
           if(object_name==pd->obj[i].object_name)
           {
               if(xxx==resultx.size())return -6; // Bad vector size
             pd->obj[i].derived[posxx]=resultx[i];
             xxx++;
           }
          }

 return 0;
}

