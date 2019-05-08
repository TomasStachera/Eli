#include "commands2.h"
#include<wx/msgdlg.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

/*************************************************************************************
Class for colour conversion. You can conver colour picture to grayscale or grayscale
to colour, or yoy can convert between several colour spaces, see command help.
**************************************************************************************/
 int Conversion_Color::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>2) return -2;
  if((line==0)||(line==1))
  {
        if(line==0) name=wxT("Source picture");
        if(line==1) name=wxT("Destination picture");
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
  if(line==2)
  {
    name=wxT("Conversion code");
    type=2;
    wxArrayString arraystr;
    arraystr.Add(_("RGB2GRAY"));
    arraystr.Add(_("GRAY2RGB"));
    arraystr.Add(_("RGB2XYZ"));
    arraystr.Add(_("XYZ2RGB"));
    arraystr.Add(_("RGB2YCrCb"));
    arraystr.Add(_("YCrCb2RGB"));
    arraystr.Add(_("RGB2HSV"));
    arraystr.Add(_("HSV2RGB"));
     arraystr.Add(_("RGB2HLS"));
     arraystr.Add(_("HLS2RGB"));
     arraystr.Add(_("RGB2Lab"));
     arraystr.Add(_("Lab2RGB"));
     arraystr.Add(_("RGB2Luv"));
     arraystr.Add(_("Luv2RGB"));

     arraystr.Add(_("BGR2GRAY"));
    arraystr.Add(_("GRAY2BGR"));
    arraystr.Add(_("BGR2XYZ"));
    arraystr.Add(_("XYZ2BGR"));
    arraystr.Add(_("BGR2YCrCb"));
    arraystr.Add(_("YCrCb2BGR"));
    arraystr.Add(_("BGR2HSV"));
    arraystr.Add(_("HSV2BGR"));
     arraystr.Add(_("BGR2HLS"));
     arraystr.Add(_("HLS2BGR"));
     arraystr.Add(_("BGR2Lab"));
     arraystr.Add(_("Lab2BGR"));
     arraystr.Add(_("BGR2Luv"));
     arraystr.Add(_("Luv2BGR"));
    aray_str=arraystr;
        type2=0;
  }

  return 0;
}

 int Conversion_Color::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
 //  pd->text1+=_("Execute Conversion_Color\n");
   wxString src_pic,dest_pic,code,pom;
   src_pic=param.BeforeFirst('#');
   pom=param.AfterFirst('#');
   dest_pic=pom.BeforeFirst('#');
   code=pom.AfterFirst('#');
   try
   {
   int i_src=wxAtoi(src_pic.AfterFirst('_'));
   int i_dest=wxAtoi(dest_pic.AfterFirst('_'));
   int i_code=CV_RGB2GRAY;
   if(code==_("RGB2GRAY")) i_code=CV_RGB2GRAY;
   if(code==_("GRAY2RGB")) i_code=CV_GRAY2RGB;
   if(code==_("RGB2XYZ")) i_code=CV_RGB2XYZ;
   if(code==_("XYZ2RGB")) i_code=CV_XYZ2RGB;
   if(code==_("RGB2YCrCb")) i_code=CV_RGB2YCrCb;
   if(code==_("YCrCb2RGB")) i_code=CV_YCrCb2RGB;
   if(code==_("RGB2HSV")) i_code=CV_RGB2HSV;
   if(code==_("HSV2RGB")) i_code=CV_HSV2RGB;
   if(code==_("RGB2HLS")) i_code=CV_RGB2HLS;
   if(code==_("HLS2RGB")) i_code=CV_HLS2RGB;
   if(code==_("RGB2Lab")) i_code=CV_RGB2Lab;
    if(code==_("Lab2RGB")) i_code=CV_Lab2RGB;
    if(code==_("RGB2Luv")) i_code=CV_RGB2Luv;
    if(code==_("Luv2RGB")) i_code=CV_Luv2RGB;

    if(code==_("BGR2GRAY")) i_code=CV_BGR2GRAY;
   if(code==_("GRAY2BGR")) i_code=CV_GRAY2BGR;
   if(code==_("BGR2XYZ")) i_code=CV_BGR2XYZ;
   if(code==_("XYZ2BGR")) i_code=CV_XYZ2BGR;
   if(code==_("BGR2YCrCb")) i_code=CV_BGR2YCrCb;
   if(code==_("YCrCb2BGR")) i_code=CV_YCrCb2BGR;
   if(code==_("BGR2HSV")) i_code=CV_BGR2HSV;
   if(code==_("HSV2BGR")) i_code=CV_HSV2BGR;
   if(code==_("BGR2HLS")) i_code=CV_BGR2HLS;
   if(code==_("HLS2BGR")) i_code=CV_HLS2BGR;
   if(code==_("BGR2Lab")) i_code=CV_BGR2Lab;
    if(code==_("Lab2BGR")) i_code=CV_Lab2BGR;
    if(code==_("BGR2Luv")) i_code=CV_BGR2Luv;
    if(code==_("Luv2BGR")) i_code=CV_Luv2BGR;

    if((i_src<0)||(i_src>19))return -1; //BAd source image index
    if((i_dest<0)||(i_dest>19)) return -2;//BAd destination image index


    cvtColor(pd->imgx[i_src],pd->imgx[i_dest],i_code);
   }
        catch( cv::Exception& e )
   {

       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90;
   }

   return 0;
 }

 /*******************************************************************************************************************/

 /*************************************************************************************
Class for Scale conversion. Command add  or multiply some number to each pixels in image
**************************************************************************************/
 int Conversion_Scale::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>5) return -2;

    if((line==0)||(line==1))
  {
        if(line==0) name=wxT("Source picture");
        if(line==1) name=wxT("Destination picture");
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

        if(line==2)
    {
        name=wxT("Scale from");
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

        name=wxT("Scale number");
        type=4;
        ival=1;

    }

           if(line==4)
    {
        name=wxT("Shift from");
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

        name=wxT("Shift number");
        type=4;
        ival=0;

    }

  return 0;
}

 int Conversion_Scale::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
     /*
       dest_pic=destination picture, picture array index */

    wxString pom;
    double dxx;

   int  src_pic=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));// source picture  array index
   pom=param.AfterFirst('#');
   int dest_pic=wxAtoi(pom.BeforeFirst('#').AfterFirst('_')); //destination picture array index
   pom=pom.AfterFirst('#');
   float scale_number=1;  // scale number
   if(pom.BeforeFirst('#')==_("Number"))
   {
      pom=pom.AfterFirst('#');
      pom.BeforeFirst('#').ToCDouble(&dxx);
       scale_number=  (float)dxx;
   }
   else
   {
       int pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
       if((pos<0)||(pos>99)) return -1; // bad scale number variable index
       scale_number=pd->fval[pos] ;
      pom=pom.AfterFirst('#');
   }
   pom=pom.AfterFirst('#');

   float shift_number=0; // shift number

    if(pom.BeforeFirst('#')==_("Number"))
   {
      pom=pom.AfterFirst('#');
      pom.BeforeFirst('#').ToCDouble(&dxx);
       shift_number= (float)dxx;
   }
   else
   {
        int pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
       if((pos<0)||(pos>99)) return -2; // bad shift number variable index
       shift_number=pd->fval[pos] ;
   }

   if((src_pic<0)||(src_pic>19)) return -3; // bad source picture index
   if((dest_pic<0)||(dest_pic>19)) return -4; //bad sestination picture index


try
{
     #ifndef ELI_SHARED_LIB
    if(edit==1)
    {
        Mat empt1,empt2;

        wxArrayString names;
        names.Add(_("Shift"));
        names.Add(_("Scale"));

        editPicture dlg(0,2,names,-255,255,0,20,shift_number,scale_number,pd->imgx[src_pic],empt1,empt2);
        if(dlg.ShowModal()==wxID_OK)
        {
            shift_number=dlg.GetV1();
            scale_number=dlg.GetV2();
            pd->updated_param.sprintf(_("Picture_%d#Picture%d#Number#%f#Number#%f"),src_pic,dest_pic,scale_number,shift_number);
            pd->update_param=true;
        }

    }
    #endif

  pd->imgx[src_pic].convertTo(pd->imgx[dest_pic],-1,scale_number,shift_number);
}
        catch( cv::Exception& e )
   {

       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }

     return 0;
 }

/*****************************************************************************************
Class for set or reset ROI (Region of interest) in image
******************************************************************************************/
 int Conversion_Roi::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
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


  if((line==1)||(line==3)||(line==5)||(line==7))
  {
        if(line==1)name=wxT("X-coordinate");
        if(line==3)name=wxT("Y-coordinate");
        if(line==5)name=wxT("Width");
        if(line==7)name=wxT("Height");
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

  if((line==2)||(line==4)||(line==6)||(line==8))
  {

      if(line==2) name=wxT("X-cor Number");
      if(line==4) name=wxT("Y-cor Number");
      if(line==6) name=wxT("Width Number");
      if(line==8) name=wxT("Height Number");
        type=4;
        ival=1;

  }

  return 0;
}

 int Conversion_Roi::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
     wxString pom;

     int pic_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_')); // position in picture array
     if((pic_pos<0)||(pic_pos>19)) return -1; //Bad position in picture array
     pom=param.AfterFirst('#');




     int x_cor=0; // x coordinate of the left most rectangle corner
      int y_cor=0; //y-coordinate of the top most or bottom most rectangle corner
      int width=0; // width of roi rectangle
      int height=0; // height of ro rectange

  for(int i=0;i<4;i++)
   {
     if(pom.BeforeFirst('#')==_("Number"))
     {
         pom=pom.AfterFirst('#');
        if(i==0) x_cor=wxAtoi(pom.BeforeFirst('#'));
        if(i==1) y_cor=wxAtoi(pom.BeforeFirst('#'));
        if(i==2) width=wxAtoi(pom.BeforeFirst('#'));
        if(i==3) height=wxAtoi(pom.BeforeFirst('#'));
        pom=pom.AfterFirst('#');
     }
     else
     {
      int pos= wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
      if((pos<0)||(pos>99)) return -2; // bad position in variable array
     if(i==0) x_cor=(int)pd->fval[pos];
     if(i==1) y_cor=(int)pd->fval[pos];
     if(i==2) width=(int)pd->fval[pos];
     if(i==3) height=(int)pd->fval[pos];
      pom=pom.AfterFirst('#');
      pom=pom.AfterFirst('#');
     }
   }

try
{

//if(pd->img[pic_pos]==0) return -11; // image is not alocated



if(x_cor<0) return -3; //x_cor is less than 0
if(x_cor>pd->imgx[pic_pos].cols) return -4; // x-cor is more than picture width
if(y_cor<0) return -5; //y_cor is less than 0
if(y_cor>pd->imgx[pic_pos].rows) return -6; // y-cor is more than picture height
if(width<=0) return -7; // width is less or equal 0
if((width+x_cor)>pd->imgx[pic_pos].cols) return -8;// width is more tah picture width
if(height<=0) return -9; // height is less or equal 0
if((height+y_cor)>pd->imgx[pic_pos].rows) return -10; // height is more  tha picture height


 #ifndef ELI_SHARED_LIB
   if(edit==1)
    {
        Mat empt1,empt2;
          wxArrayString names;
         names.Add(_("x-position"));
         names.Add(_("Width"));
         names.Add(_("y-position"));
         names.Add(_("Height"));

      editPicture dlg(0,1,names,x_cor,y_cor,width,height,0,0,pd->imgx[pic_pos],empt1,empt2);
        if(dlg.ShowModal()==wxID_OK)
        {
            x_cor=(int)dlg.GetV1();
            width=(int)dlg.GetV2();
            y_cor=(int)dlg.GetV3();
            height=(int)dlg.GetV4();

            pd->updated_param.sprintf(_("Picture_%d#Number#%d#Number#%d#Number#%d#Number#%d"),pic_pos,x_cor,y_cor,width,height);
            pd->update_param=true;
        }

    }
    #endif

pd->imgx[pic_pos]=pd->imgx[pic_pos](cvRect(x_cor,y_cor,width,height));



}

    catch( cv::Exception& e )
   {

       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }

     return 0;
 }

/*************************************************************************************
Class for add 2 images. Each pixels in one image is add with each pixels in second image.
Each pixels is before add multiply with weight factor on image.
**************************************************************************************/
 int Conversion_AddWeighted::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>6) return -2;

 if((line==0)||(line==1)||(line==4))
  {
     if(line==0) name=wxT("Destination picture");
     if(line==1) name=wxT("Source picture A");
     if(line==4) name=wxT("Source picture B");
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
    if((line==2)||(line==5))
    {
       if(line==2) name=wxT("Weight of picture A from");
       if(line==5) name=wxT("Weight of picture B from");
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
      if((line==3)||(line==6))
    {

       if(line==3) name=wxT("Weight of picture A number");
       if(line==6) name=wxT("Weight of picture B number");
        type=4;
        ival=1;

    }

  return 0;
}

 int Conversion_AddWeighted::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
    int dest_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_')); // position of destination picture in picture array
    if((dest_pos<0)||(dest_pos>19))return -1; // bad position of destination picture in picture array
    wxString pom=param.AfterFirst('#');
    int sourc_pic_A=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));// position os source picture A in picture array
    if((sourc_pic_A<0)||(sourc_pic_A>19)) return -2; //bad position of source picture A in picture array
    pom=pom.AfterFirst('#');
    float weight_A=-1; // weight of pixels in picture A
     float weight_B=-1; // weight of pixels in picture B
     int sourc_pic_B=-1; //position of source picture B in picture array
     double dxx;
    for(int i=0;i<2;i++)
    {
    if(pom.BeforeFirst('#')==_("Number"))
    {
        pom=pom.AfterFirst('#');
        if(i==0)
        {
        pom.BeforeFirst('#').ToCDouble(&dxx);
        weight_A=(float)dxx;
        }
        else
        {
        pom.BeforeFirst('#').ToCDouble(&dxx);
        weight_B=(float)dxx;
        }
    }
    else
    {
        int v_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
        if((v_pos<0)||(v_pos>99)) return -3; // bad variable position in variable array
        if(i==0)weight_A=pd->fval[v_pos];
        else weight_B=pd->fval[v_pos];
        pom=pom.AfterFirst('#');
    }
    pom=pom.AfterFirst('#');
    if(i==0)
    {
     sourc_pic_B=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));// position os source picture B in picture array
      pom=pom.AfterFirst('#');
    }
    }
    if((sourc_pic_B<0)||(sourc_pic_B>19)) return -4; //bad position of picture B in picture array
    if((weight_A<0)||(weight_A>1)) return -5;// weight of picture A is out of range (must be (0-1))
    if((weight_B<0)||(weight_B>1)) return -6;//weight of picture B is out of range (must be (0-1))

    try
    {
        #ifndef ELI_SHARED_LIB
     if(edit==1)
     {
         Mat empt1;
          wxArrayString names;
          if(pd->imgx[sourc_pic_A].channels()!=pd->imgx[sourc_pic_B].channels())return -7; //Source and destination number of channels is not same
         names.Add(_("A picture weight"));
         names.Add(_("B picture weight"));
         names.Add(_("Gama"));

       editPicture dlg(0,3,names,weight_A,weight_B,0,0,0,0,pd->imgx[sourc_pic_A],pd->imgx[sourc_pic_B],empt1);
        if(dlg.ShowModal()==wxID_OK)
        {
            weight_A=dlg.GetV1();
            weight_B=dlg.GetV2();

            pd->updated_param.sprintf(_("Picture_%d#Picture_%d#Number#%f#Picture_%d#Number#%f"),dest_pos,sourc_pic_A,weight_A,sourc_pic_B,weight_B);
            pd->update_param=true;
        }

    }
    #endif

    addWeighted(pd->imgx[sourc_pic_A],weight_A,pd->imgx[sourc_pic_B],weight_B,0,pd->imgx[dest_pos]);

    }

        catch( cv::Exception& e )
   {

       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }
     return 0;
 }

 /*************************************************************************************
Class for image threshold. Function convert image according threshold value
**************************************************************************************/
  int Conversion_Threshold::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>4) return -2;
   if((line==0)||(line==1))
  {
     if(line==0) name=wxT("Source picture");
     if(line==1) name=wxT("Destination picture");
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
      if(line==2)
    {
    name=wxT("Threshold from");

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

        name=wxT("Threshold number");
        type=4;
        ival=0;

    }

    if(line==4)
    {
        name=wxT("Threshold type");
         type=2;
        wxArrayString arraystr;
        wxString pom;
        arraystr.Add(_("THRESH_BINARY"));
        arraystr.Add(_("THRESH_BINARY_INV"));
        arraystr.Add(_("THRESH_TRUNC"));
        arraystr.Add(_("THRESH_TOZERO"));
        arraystr.Add(_("THRESH_TOZERO_INV"));
        aray_str=arraystr;
        type2=0;
    }
  return 0;
}

 int Conversion_Threshold::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
     int sour_pic_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));//position of source picture in picture array
     wxString pom=param.AfterFirst('#');
     int dest_pic_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));//posution of destination picture in picture array
     pom=pom.AfterFirst('#');
      int threshold_value=-1; // threshold value (must be in range 0-255)
      if(pom.BeforeFirst('#')==wxT("Number"))
      {
          pom=pom.AfterFirst('#');
          threshold_value=wxAtoi(pom.BeforeFirst('#'));
      }
      else
      {
         int variable_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
         if((variable_pos<0)||(variable_pos>99)) return -1; // bad position in variable array in threshold value variable
         threshold_value=(int)pd->fval[variable_pos];
         pom=pom.AfterFirst('#');
      }
      pom=pom.AfterFirst('#');

     int threshold_type=THRESH_BINARY; // threshold type

      if(pom==_("THRESH_BINARY_INV"))threshold_type=THRESH_BINARY_INV;
      if(pom==_("THRESH_TRUNC"))threshold_type=THRESH_TRUNC;
      if(pom==_("THRESH_TOZERO"))threshold_type=THRESH_TOZERO;
      if(pom==_("THRESH_TOZERO_INV"))threshold_type=THRESH_TOZERO_INV;

      if((sour_pic_pos<0)||(sour_pic_pos>19)) return -2; //bad position of source picture in picture array
      if((dest_pic_pos<0)||(dest_pic_pos>19)) return -3; //bad position of destination picture in picture array
      if((threshold_value<0)||(threshold_value>255)) return -4; //bad threshold value (must be in range 0-255)

     try
     {


      if(pd->imgx[sour_pic_pos].channels() !=1) return -7;// bad channel number in source image
      if(pd->imgx[dest_pic_pos].channels() != 1) return -8;// bad channel number in destination image

      #ifndef ELI_SHARED_LIB
      if(edit==1)
      {
          Mat empt1;
          wxArrayString names;
         names.Add(_("Threshold value"));
         names.Add(_("Threshold type"));
         int tp=0;
         if(threshold_type==THRESH_BINARY_INV)tp=1;
         if(threshold_type==THRESH_TRUNC)tp=2;
         if(threshold_type==THRESH_TOZERO)tp=3;
         if(threshold_type==THRESH_TOZERO_INV)tp=4;

     editPicture dlg(0,4,names,threshold_value,tp,0,0,0,0,pd->imgx[sour_pic_pos],empt1,empt1);
        if(dlg.ShowModal()==wxID_OK)
        {
            threshold_value=(int)dlg.GetV1();
            tp=(int)dlg.GetV2();

            if(tp==0)threshold_type=THRESH_BINARY;
            if(tp==1)threshold_type=THRESH_BINARY_INV;
            if(tp==2)threshold_type=THRESH_TRUNC;
            if(tp==3)threshold_type=THRESH_TOZERO;
            if(tp==4)threshold_type=THRESH_TOZERO_INV;

            wxString px=_("THRESH_BINARY");
            if(tp==1)px=_("THRESH_BINARY_INV");
            if(tp==2)px=_("THRESH_TRUNC");
            if(tp==3)px=_("THRESH_TOZERO");
            if(tp==4)px=_("THRESH_TOZERO_INV");


            pd->updated_param.sprintf(_("Picture_%d#Picture_%d#Number#%d#"),sour_pic_pos,dest_pic_pos,threshold_value);
            pd->updated_param+=px;

            pd->update_param=true;
        }

      }
#endif

      threshold(pd->imgx[sour_pic_pos],pd->imgx[dest_pic_pos],(double)threshold_value,255,threshold_type);
    }

    catch( cv::Exception& e )
   {

       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }

     return 0;
 }

/*************************************************************************************
Class for image adaptive threshold. Function convert image according adaptive threshold
mechanizm
**************************************************************************************/
  int Conversion_AdaptThresh::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>7) return -2;
   if((line==0)||(line==1))
  {
     if(line==0) name=wxT("Source picture");
     if(line==1) name=wxT("Destination picture");
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
      if(line==2)
    {
        name=wxT("Adaptive method");
         type=2;
        wxArrayString arraystr;
        wxString pom;
        arraystr.Add(_("ADAPTIVE_THRESH_MEAN_C"));
        arraystr.Add(_("ADAPTIVE_THRESH_GAUSSIAN_C"));
        aray_str=arraystr;
        type2=0;
    }
        if(line==3)
    {

         name=wxT("Treshold type");
         type=2;
        wxArrayString arraystr;
        wxString pom;
        arraystr.Add(_("THRESH_BINARY"));
        arraystr.Add(_("THRESH_BINARY_INV"));
        aray_str=arraystr;
        type2=0;

    }



    if((line==4)||(line==6))
    {
    if(line==4) name=wxT("Block size from");
    if(line==6) name=wxT("C constant from");

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
    if((line==5)||(line==7))
    {

       if(line==5) name=wxT("Block size number");
       if(line==7) name=wxT("C constant number");
        type=4;
        if(line==5)ival=3;
        else ival=0;
    }

  return 0;
}

 int Conversion_AdaptThresh::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
        int sour_pic_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));//position of source picture in picture array
     wxString pom=param.AfterFirst('#');
     int dest_pic_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));//posution of destination picture in picture array
     pom=pom.AfterFirst('#');
     int thresh_method=ADAPTIVE_THRESH_MEAN_C; //threshold method
     if(pom.BeforeFirst('#')==_("ADAPTIVE_THRESH_GAUSSIAN_C")) thresh_method=ADAPTIVE_THRESH_GAUSSIAN_C;
     pom=pom.AfterFirst('#');
     int thresh_type=THRESH_BINARY; //threshold type
     if(pom.BeforeFirst('#')==_("THRESH_BINARY_INV"))thresh_type=THRESH_BINARY_INV;
     pom=pom.AfterFirst('#');

      int block_size=-1; // Block size value
      if(pom.BeforeFirst('#')==wxT("Number"))
      {
          pom=pom.AfterFirst('#');
          block_size=wxAtoi(pom.BeforeFirst('#'));
      }
      else
      {
         int variable_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
         if((variable_pos<0)||(variable_pos>99)) return -1; // bad position in variable array in block size value variable
         block_size=(int)pd->fval[variable_pos];
         pom=pom.AfterFirst('#');
      }
      pom=pom.AfterFirst('#');

      int c_constant=-1; // c_constant value
      if(pom.BeforeFirst('#')==wxT("Number"))
      {
          pom=pom.AfterFirst('#');
         c_constant=wxAtoi(pom.BeforeFirst('#'));
      }
      else
      {
         int variable_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
         if((variable_pos<0)||(variable_pos>99)) return -1; // bad position in variable array in block size value variable
        c_constant=(int)pd->fval[variable_pos];
         pom=pom.AfterFirst('#');
      }

         if((sour_pic_pos<0)||(sour_pic_pos>19)) return -2; //bad position of source picture in picture array
      if((dest_pic_pos<0)||(dest_pic_pos>19)) return -3; //bad position of destination picture in picture array

       try
     {


      if(pd->imgx[sour_pic_pos].channels() !=1) return -6;// bad channel number in source image
      if(pd->imgx[dest_pic_pos].channels() != 1) return -7;// bad channel number in destination image

      adaptiveThreshold(pd->imgx[sour_pic_pos],pd->imgx[dest_pic_pos],255,thresh_method,thresh_type,block_size,c_constant);

     }
         catch( cv::Exception& e )
   {

       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }
     return 0;
 }

int Conversion_FloodFill::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
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

  if(line==1)
  {
        name=wxT("Flood fill colour");
        type=1; //file path string type
        str=wxT("0,0,0");
        type2=3;//open collor dialog will display
  }

    if((line==2)||(line==4)||(line==6)||(line==8))
    {
    if(line==2) name=wxT("X coordinate from");
    if(line==4) name=wxT("Y coordinate from");
    if(line==6) name=wxT("Lo diff from");
    if(line==8) name=wxT("Up diff from");

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
    if((line==3)||(line==5)||(line==7)||(line==9))
    {

       if(line==3) name=wxT("X coordinate number");
       if(line==5) name=wxT("Y coordinate number");
       if(line==7) name=wxT("Lo diff number");
       if(line==9) name=wxT("Up diff number");

        type=4;
        ival=3;
    }
    if(line==10)
    {
       type=2;
       name=wxT("Flags");
        wxArrayString arraystr;
        arraystr.Add(_("4"));
        arraystr.Add(_("8"));
        aray_str=arraystr;
        type2=0;
    }


  return 0;
}

 int Conversion_FloodFill::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
     int sour_pic_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));//position of source picture in picture array
     wxString pom=param.AfterFirst('#');
     wxString colour_code=pom.BeforeFirst('#');
     pom=pom.AfterFirst('#');
      int r_colour=wxAtoi(colour_code.BeforeFirst(','));
   colour_code=colour_code.AfterFirst(',');
   int g_colour=wxAtoi(colour_code.BeforeFirst(','));
   int b_colour=wxAtoi(colour_code.AfterFirst(','));
   int x_pos=0; //x position of seed value
   int y_pos=0; //y position of seed value
   float loDiff=0; // loDiff value
   float upDiff=0; //upDiff value
   double dxx;
  for(int i=0;i<4;i++)
    {
    if(pom.BeforeFirst('#')==_("Number"))
    {
        pom=pom.AfterFirst('#');
        if(i==0)x_pos=wxAtoi(pom.BeforeFirst('#'));
        if(i==1)y_pos=wxAtoi(pom.BeforeFirst('#'));
        if(i==2)
        {
        pom.BeforeFirst('#').ToCDouble(&dxx);
        loDiff=(float)dxx;
        }
        if(i==3)
        {
        pom.BeforeFirst('#').ToCDouble(&dxx);
        upDiff=(float)dxx;
        }
    }
    else
    {
        int v_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
        if((v_pos<0)||(v_pos>99)) return -1; // bad variable position in variable array
        if(i==0)x_pos=(int)pd->fval[v_pos];
        if(i==1)y_pos=(int)pd->fval[v_pos];
        if(i==2)loDiff=pd->fval[v_pos];
        if(i==3)upDiff=pd->fval[v_pos];
        pom=pom.AfterFirst('#');
    }
    pom=pom.AfterFirst('#');
    }
    int flags=wxAtoi(pom);
    if((flags!=4)&&(flags!=8)) return -2; // bad flag number
    if((sour_pic_pos<0)||(sour_pic_pos>19)) return -3; //bad source picture position in picture array
    if((r_colour<0)||(r_colour>255)) return -4; //bad colour code
    if((g_colour<0)||(g_colour>255)) return -4; // bad colour code
    if((b_colour<0)||(b_colour>255)) return -4; //bad colour code
    try
    {
        //if(pd->img[sour_pic_pos]==0) return -9; // source image is not alocated
     if((x_pos<1)||(x_pos>(pd->imgx[sour_pic_pos].cols-1)))  return -5; // bad x_position value
     if((y_pos<1)||(y_pos>(pd->imgx[sour_pic_pos].rows-1))) return -6; // bad y position value
      if(loDiff<0) return -7; // bad loDiff value
      if(upDiff<0) return -8; //bad upDiff value
#ifndef ELI_SHARED_LIB
    if(edit==1)
     {
          wxArrayString names;
         names.Add(_("X-coordinate"));
         names.Add(_("Y-coordinate"));
         names.Add(_("Lo-diff"));
         names.Add(_("Up-diff"));
      Mat empt1,empt2;
        editPicture dlg(0,5,names,x_pos,y_pos,loDiff,upDiff,flags,0,pd->imgx[sour_pic_pos],empt1,empt2,CV_RGB(r_colour,g_colour,b_colour));
        if(dlg.ShowModal()==wxID_OK)
        {
            x_pos=(int)dlg.GetV1();
            y_pos=(int)dlg.GetV2();
            loDiff=dlg.GetV3();
            upDiff=dlg.GetV4();

            pd->updated_param.sprintf(_("Picture_%d#%d,%d,%d#Number#%d#Number#%d#Number#%.2f#Number#%.2f#%d"),sour_pic_pos,r_colour,g_colour,b_colour,x_pos,y_pos,loDiff,upDiff,flags);
            pd->update_param=true;
        }
    }
    #endif

    floodFill(pd->imgx[sour_pic_pos], Point(x_pos,y_pos), CV_RGB(r_colour,g_colour,b_colour),0, Scalar(loDiff,loDiff,loDiff), Scalar(upDiff,upDiff,upDiff),flags);
    }

    catch( cv::Exception& e )
   {

       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }
     return 0;
 }

/*************************************************************************************
Class for aplicate Morfology algoritm for tested image
**************************************************************************************/
 int Conversion_Morfology::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>8) return -2;

    if((line==0)||(line==1))
  {
    if(line==0) name=wxT("Source picture");
    else name=wxT("Destination picture");
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

  if(line==2)
  {
      name=wxT("Morfology type");
      type=2;
      wxArrayString arraystr;
      arraystr.Add(_("Erode"));
      arraystr.Add(_("Dilate"));
      arraystr.Add(_("Open"));
      arraystr.Add(_("Close"));
      arraystr.Add(_("Gradient"));
      arraystr.Add(_("Tophat"));
      arraystr.Add(_("Blackhat"));
      aray_str=arraystr;
        type2=0;
  }
  if(line==3)
  {
      name=wxT("Iterations");

        type=4;
        ival=1;
  }
  if(line==4)
  {
    name=wxT("Element shape");
      type=2;
      wxArrayString arraystr;
      arraystr.Add(_("RECT"));
      arraystr.Add(_("ELLIPSE"));
      arraystr.Add(_("CROSS"));
      aray_str=arraystr;
        type2=0;
  }
    if(line==5)
  {
      name=wxT("Element width");

        type=4;
        ival=3;
  }
      if(line==6)
  {
      name=wxT("Element height");

        type=4;
        ival=3;
  }
  if((line==7)||(line==8))
  {
      if(line==7) name=wxT("Anchor x");
      if(line==8) name=wxT("Anchor y");
     type=4;
     ival=0;
  }

  return 0;
}

 int Conversion_Morfology::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
   int sour_pic_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));//position of source picture in picture array
  wxString pom=param.AfterFirst('#');
  int dest_pic_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_')); //position of destination picture in picture array
  pom=pom.AfterFirst('#');
  int morf_type=0;//morfology type
  if(pom.BeforeFirst('#')==_("Erode"))  morf_type=1;
  if(pom.BeforeFirst('#')==_("Dilate")) morf_type=2;
  if(pom.BeforeFirst('#')==_("Open")) morf_type=3;
  if(pom.BeforeFirst('#')==_("Close")) morf_type=4;
  if(pom.BeforeFirst('#')==_("Gradient")) morf_type=5;
  if(pom.BeforeFirst('#')==_("Tophat")) morf_type=6;
  if(pom.BeforeFirst('#')==_("Blackhat")) morf_type=7;
  pom=pom.AfterFirst('#');
  int iteration=wxAtoi(pom.BeforeFirst('#')); //number of iteration
  pom=pom.AfterFirst('#');
  int el_shape=0; // element shape
  if(pom.BeforeFirst('#')==_("RECT")) el_shape=1;
  if(pom.BeforeFirst('#')==_("ELLIPSE")) el_shape=2;
  if(pom.BeforeFirst('#')==_("CROSS")) el_shape=3;
  pom=pom.AfterFirst('#');
  int el_width=wxAtoi(pom.BeforeFirst('#')); //element width
  pom=pom.AfterFirst('#');
  int el_height=wxAtoi(pom.BeforeFirst('#')); //element height
  pom=pom.AfterFirst('#');
  int anchor_x=wxAtoi(pom.BeforeFirst('#')); // anchor x-position
  int anchor_y=wxAtoi(pom.AfterFirst('#')); // anchor y-postion

 if((sour_pic_pos<0)||(sour_pic_pos>19)) return -1; // bad position of source picture in picture array
 if((dest_pic_pos<0)||(dest_pic_pos>19)) return -2; // bad position of destination picture in picture array
 if((morf_type<1)||(morf_type>7)) return -3; // bad morfology type
 if(iteration<1) return -4; // bad iteration number
 if((el_shape<1)||(el_shape>3)) return -5; // bad element shape
 if(el_width<1) return -6; // bad elementh width
 if(el_height<1) return -7; //bad element height

 try
 {


  int shape =MORPH_RECT;
  if(el_shape==2) shape=MORPH_ELLIPSE;
  if(el_shape==3) shape=MORPH_CROSS;

  Mat element=getStructuringElement(shape,Size(el_width,el_height),Point(anchor_x,anchor_y)); //create structuring element


  if(morf_type==1) erode(pd->imgx[sour_pic_pos],pd->imgx[dest_pic_pos],element,Point(anchor_x,anchor_y),iteration);
  else if(morf_type==2) dilate(pd->imgx[sour_pic_pos],pd->imgx[dest_pic_pos],element,Point(anchor_x,anchor_y),iteration);
  else
  {
    int morf_operation=MORPH_OPEN;
    if(morf_type==4) morf_operation=MORPH_CLOSE ;
    if(morf_type==5) morf_operation=MORPH_GRADIENT;
    if(morf_type==6) morf_operation=MORPH_TOPHAT;
    if(morf_type==7) morf_operation=MORPH_BLACKHAT;


    morphologyEx(pd->imgx[sour_pic_pos],pd->imgx[dest_pic_pos],morf_operation,element,cvPoint(anchor_x,anchor_y),iteration);

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
Class for aplicate Sobel or laplace algoritm for tested image
**************************************************************************************/
 int Conversion_Edge::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>5) return -2;

 if((line==0)||(line==1))
  {
    if(line==0) name=wxT("Source picture");
    else name=wxT("Destination picture");
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

  if(line==2)
  {
   name=wxT("Edge method");
   type=2;
   wxArrayString arraystr;
   arraystr.Add(_("Sobel"));
   arraystr.Add(_("Laplace"));
    aray_str=arraystr;
        type2=0;
  }

  if(line==3)
  {
      name=wxT("Aperture size");
   type=2;
   wxArrayString arraystr;
   arraystr.Add(_("1"));
   arraystr.Add(_("3"));
   arraystr.Add(_("5"));
   arraystr.Add(_("7"));
    aray_str=arraystr;
        type2=1;
  }

 if(line==4)
  {
   name=wxT("Xorder");
     type=4;
     ival=1;
  }

 if(line==5)
  {
   name=wxT("Yorder");
     type=4;
     ival=0;
  }

  return 0;
}

 int Conversion_Edge::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
{
   int sour_pic_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));//position of source picture in picture array
  wxString pom=param.AfterFirst('#');
  int dest_pic_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_')); //position of destination picture in picture array
  pom=pom.AfterFirst('#');
  int type=1; // type of edge function 1=Sobel, 2=edge
  if(pom.BeforeFirst('#')==_("Laplace")) type=2;
  pom=pom.AfterFirst('#');
  int aperture_size=wxAtoi(pom.BeforeFirst('#')); // aperture size
  pom=pom.AfterFirst('#');
  int xorder=wxAtoi(pom.BeforeFirst('#')); //xorder value
  int yorder=wxAtoi(pom.AfterFirst('#')); //yorder value

  if((sour_pic_pos<0)||(sour_pic_pos>19)) return -1; // bad source picture position in picture array
  if((dest_pic_pos<0)||(dest_pic_pos>19)) return -2; //bad destination picture position in picture array
  if((aperture_size != 1)&&(aperture_size != 3)&&(aperture_size != 5)&&(aperture_size != 7)) return -3; // bad aperture size number
  if(xorder<0) return -4; // xorder is less than 0
  if(yorder<0) return -5; // yorder is less than 0

  try
  {


   if(type==1)Sobel(pd->imgx[sour_pic_pos],pd->imgx[dest_pic_pos],pd->imgx[sour_pic_pos].depth(),xorder,yorder,aperture_size);
   else Laplacian(pd->imgx[sour_pic_pos],pd->imgx[dest_pic_pos],pd->imgx[sour_pic_pos].depth(),aperture_size);

  }
      catch( cv::Exception& e )
   {
       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }

     return 0;
}

 /*************************************************************************************
Class for smooth tested image
**************************************************************************************/
 int Conversion_Smooth::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>6) return -2;

   if((line==0)||(line==1))
  {
    if(line==0) name=wxT("Source picture");
    else name=wxT("Destination picture");
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

    if(line==2)
  {
   name=wxT("Smooth type");
   type=2;
   wxArrayString arraystr;
   arraystr.Add(_("BLUR"));
   arraystr.Add(_("GAUSSIAN"));
   arraystr.Add(_("MEDIAN"));
   arraystr.Add(_("BILATERAL"));
    aray_str=arraystr;
        type2=0;
  }

  if(line==3)
  {
    name=wxT("Aperture width");
     type=4;
     ival=3;
  }

    if(line==4)
  {
    name=wxT("Aperture height");
     type=4;
     ival=0;
  }

  if(line==5)
  {
    name=wxT("Standard deviation");
     type=4;
     ival=0;
  }

    if(line==6)
  {
    name=wxT("Param4");
     type=4;
     ival=0;
  }

  return 0;
}

 int Conversion_Smooth::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
{
   int sour_pic_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));//position of source picture in picture array
  wxString pom=param.AfterFirst('#');
  int dest_pic_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_')); //position of destination picture in picture array
  pom=pom.AfterFirst('#');
  int type=1; //type of smoothing
  if(pom.BeforeFirst('#')==_("BLUR")) type=1;
  if(pom.BeforeFirst('#')==_("GAUSSIAN")) type=2;
  if(pom.BeforeFirst('#')==_("MEDIAN")) type=3;
  if(pom.BeforeFirst('#')==_("BILATERAL")) type=4;
  pom=pom.AfterFirst('#');
  int param1=wxAtoi(pom.BeforeFirst('#')); // aperture width
  pom=pom.AfterFirst('#');
  int param2=wxAtoi(pom.BeforeFirst('#')); //aperture height
  pom=pom.AfterFirst('#');
  double param3;
  pom.BeforeFirst('#').ToCDouble(&param3); // standard deviation
  double param4; //param4
  pom.AfterFirst('#').ToDouble(&param4);

  if((sour_pic_pos<0)||(sour_pic_pos>19)) return -1; // bad source picture position in variable array
  if((dest_pic_pos<0)||(dest_pic_pos>19)) return -2; // bad destination picture position in variable array

  if((param1<0)||(((param1%2)==0)&&(param1!=0))) return -3; // aperture width must be positive odd number
  if(param2<0) return -4; //apaerture height must be positive or 0

 try
  {

  if(type==1)blur(pd->imgx[sour_pic_pos],pd->imgx[dest_pic_pos],Size(param1,param2));
  else if(type==2)GaussianBlur(pd->imgx[sour_pic_pos],pd->imgx[dest_pic_pos],Size(param1,param2),param3);
  else if(type==3)medianBlur(pd->imgx[sour_pic_pos],pd->imgx[dest_pic_pos],param1);
  else bilateralFilter(pd->imgx[sour_pic_pos],pd->imgx[dest_pic_pos],0,param3,param4);
  }
    catch( cv::Exception& e )
   {
       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }
    return 0;
}

/*************************************************************************************
Class for equalize histogram on tested image
**************************************************************************************/
 int Conversion_EqualHist::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>1) return -2;

   if((line==0)||(line==1))
  {
    if(line==0) name=wxT("Source picture");
    else name=wxT("Destination picture");
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
  return 0;
}

 int Conversion_EqualHist::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
{
  int sour_pic_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));//position of source picture in picture array
  int dest_pic_pos=wxAtoi(param.AfterFirst('#').AfterFirst('_')); //position of destination picture in picture array

  if((sour_pic_pos<0)||(sour_pic_pos>19)) return -1; //bad position of source image in picture array
  if((dest_pic_pos<0)||(dest_pic_pos>19)) return -2; //bad position of destination image in picture array

  try
  {

  if(pd->imgx[sour_pic_pos].cols != pd->imgx[dest_pic_pos].cols) return -3; // dimension source and destination image are not same
  if(pd->imgx[sour_pic_pos].rows != pd->imgx[dest_pic_pos].rows) return -3; //dimasion source and destination image are not same
 if(pd->imgx[sour_pic_pos].channels()!=1) return -14; //source image maust be single channel
  if(pd->imgx[dest_pic_pos].channels()!=1) return -15; //destination image maust be single channel
   equalizeHist(pd->imgx[sour_pic_pos],pd->imgx[dest_pic_pos]);
  }
      catch( cv::Exception& e )
   {
       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }
    return 0;
}

/*************************************************************************************
Class for resize tested image
**************************************************************************************/
 int Conversion_Resize::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>6) return -2;

   if((line==0)||(line==1))
  {
    if(line==0) name=wxT("Source picture");
    else name=wxT("Destination picture");
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
  if(line==2)
  {
      type=2;
      name=wxT("Interpolation method");
      wxArrayString arraystr;
      arraystr.Add(_("CV_INTER_NN"));
      arraystr.Add(_("CV_INTER_LINEAR"));
       arraystr.Add(_("CV_INTER_AREA"));
      arraystr.Add(_("CV_INTER_CUBIC"));
      aray_str=arraystr;
        type2=0;
  }
  if((line==3)||(line==5))
    {
    if(line==3) name=wxT("X scale from");
    if(line==5) name=wxT("Y scale from");


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
    if((line==4)||(line==6))
    {

       if(line==4) name=wxT("X scale number");
       if(line==6) name=wxT("Y scale number");


        type=4;
        ival=3;
    }
  return 0;
}

 int Conversion_Resize::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
{
   int sour_pic_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));//position of source picture in picture array
  wxString pom=param.AfterFirst('#');
  int dest_pic_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_')); //position of destination picture in picture array
  int method=CV_INTER_NN; //INterpolation method
  pom=pom.AfterFirst('#');
  if(pom.BeforeFirst('#')==_("CV_INTER_LINEAR")) method=CV_INTER_LINEAR;
  if(pom.BeforeFirst('#')==_("CV_INTER_AREA")) method=CV_INTER_AREA;
  if(pom.BeforeFirst('#')==_("CV_INTER_CUBIC")) method=CV_INTER_CUBIC;
  double x_scale=0,y_scale=0;
  pom=pom.AfterFirst('#');
    for(int i=0;i<2;i++)
    {
    if(pom.BeforeFirst('#')==_("Number"))
    {
        pom=pom.AfterFirst('#');
        if(i==0)pom.BeforeFirst('#').ToCDouble(&x_scale);
        if(i==1)pom.BeforeFirst('#').ToCDouble(&y_scale);

    }
    else
    {
        int v_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
        if((v_pos<0)||(v_pos>99)) return -6; // bad variable position in variable array
        if(i==0)x_scale=(double)pd->fval[v_pos];
        if(i==1)y_scale=(double)pd->fval[v_pos];

        pom=pom.AfterFirst('#');
    }
    pom=pom.AfterFirst('#');
    }
    if((sour_pic_pos<0)||(sour_pic_pos>19)) return -1; //bad position of source image in picture array
  if((dest_pic_pos<0)||(dest_pic_pos>19)) return -2; //bad position of destination image in picture array
  if(x_scale<=0)return -3;//x-scale must be more than 0
  if(y_scale<=0) return -4;//y-scale must be more than 0;

  try
  {

   if(pd->imgx[sour_pic_pos].channels()!=pd->imgx[dest_pic_pos].channels()) return -5; //number of channels in source and destination image is not same

   resize(pd->imgx[sour_pic_pos],pd->imgx[dest_pic_pos],Size(0,0),x_scale,y_scale,method);
  }
    catch( cv::Exception& e )
   {
       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }
  return 0;
}

/*************************************************************************************
Class for flip or rotate tested image
**************************************************************************************/


 int Conversion_RotateFlip::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>3) return -2;

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
      name=wxT("Mode");
      type=2;
      wxArrayString arraystr;
      arraystr.Add(_("Rotate"));
      arraystr.Add(_("Flip_x-axis"));
      arraystr.Add(_("Flip_y-axis"));
      arraystr.Add(_("Flip_both_axis"));
       aray_str=arraystr;
        type2=0;
  }

    if(line==2)
    {
        name=wxT("Rotate angle from");
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

        name=wxT("Rotate angle number");
        type=4;
        ival=90;

    }

  return 0;
}

 int Conversion_RotateFlip::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
{
   int sour_pic_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));//position of source picture in picture array
  wxString pom=param.AfterFirst('#');
  int mode=2;// mede of operation 2=rotate
  if(pom.BeforeFirst('#')==_("Flip_x-axis")) mode=0;
  if(pom.BeforeFirst('#')==_("Flip_y-axis")) mode=1;
  if(pom.BeforeFirst('#')==_("Flip_both_axis")) mode=-1;
  pom=pom.AfterFirst('#');
  int angle=0; // angle of rotation
     if(pom.BeforeFirst('#')==_("Number"))
   {
      pom=pom.AfterFirst('#');
       angle= wxAtoi(pom.BeforeFirst('#'));
   }
   else
   {
        int pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
       if((pos<0)||(pos>99)) return -1; // bad angle number variable index
       angle=(int)pd->fval[pos] ;
   }

   if((sour_pic_pos<0)||(sour_pic_pos>19)) return -2; //bad source picture position in picture array

   try
   {

       if(mode==2) pd->imgx[sour_pic_pos]=rotateImage(pd->imgx[sour_pic_pos],angle);
       else flip(pd->imgx[sour_pic_pos],pd->imgx[sour_pic_pos],mode);
   }
       catch( cv::Exception& e )
   {
       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }
  return 0;
}

Mat Conversion_RotateFlip::rotateImage(Mat src, int angleDegrees)
{

    Mat imageRotated = Mat::zeros(src.rows,src.cols,src.type());

    if(angleDegrees!=0){

        Point2f pt(imageRotated.cols/2,imageRotated.rows/2);
        Mat rot_mat=getRotationMatrix2D( pt, angleDegrees, 1 );

        // Do the transformation
       warpAffine( src,imageRotated, rot_mat,Size(src.cols,src.rows) );
    }

    return imageRotated;
}

 int Conversion_Canny::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>6) return -2;


   if((line==0)||(line==1))
  {
    if(line==0) name=wxT("Source picture");
    else name=wxT("Destination picture");
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

    if((line==2)||(line==4))
    {
    if(line==2) name=wxT("Threshold 1 from");
    if(line==4) name=wxT("Threshold 2 from");

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
    if((line==3)||(line==5))
    {

       if(line==3) name=wxT("Threshold 1 number");
       if(line==5) name=wxT("Threshold 2 number");
        type=4;
        if(line==3)ival=90;
        else ival=200;
    }
    if(line==6)
    {
        name=wxT("Aperture size");
        type=2;
        wxArrayString arraystr;
       arraystr.Add(_("3"));
       arraystr.Add(_("5"));
       arraystr.Add(_("7"));
      aray_str=arraystr;
        type2=0;
    }

  return 0;
}

 int Conversion_Canny::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
{
  int sour_pic_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));//position of source picture in picture array
  wxString pom=param.AfterFirst('#');
  int dest_pic_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_')); //position of destination picture in picture array
  pom=pom.AfterFirst('#');

  int thres1=0; // Threshold1 number

    if(pom.BeforeFirst('#')==_("Number"))
   {
      pom=pom.AfterFirst('#');
       thres1= wxAtoi(pom.BeforeFirst('#'));
   }
   else
   {
        int pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
       if((pos<0)||(pos>99)) return -1; // bad threshold 1 number variable index
       thres1=(int)pd->fval[pos] ;
       pom=pom.AfterFirst('#');
   }
   pom=pom.AfterFirst('#');

   int thres2=0; //THreshold 2 number

       if(pom.BeforeFirst('#')==_("Number"))
   {
      pom=pom.AfterFirst('#');
       thres2= wxAtoi(pom.BeforeFirst('#'));
   }
   else
   {
        int pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
       if((pos<0)||(pos>99)) return -2; // bad threshold 2 number variable index
       thres2=(int)pd->fval[pos] ;
       pom=pom.AfterFirst('#');
   }

   int aperture_size=wxAtoi(pom.AfterFirst('#'));

   if((sour_pic_pos<0)||(sour_pic_pos>19)) return -3; // Bad source picture position in picture array
   if((dest_pic_pos<0)||(dest_pic_pos>19)) return -4; //Bad destination picture position in picture array
   if((thres1<0)||(thres1>255)) return -5; // THreshold 1 number must be from range 0-255
   if((thres2<0)||(thres2>255)) return -6; //THreshold 2 number must be from range 0-255
   if((aperture_size != 3)&&(aperture_size != 5)&&(aperture_size != 7)) return -7; // Aperture size must be 3,5 or 7

  try
  {

  if(pd->imgx[sour_pic_pos].cols != pd->imgx[dest_pic_pos].cols) return -8; // dimension source and destination image are not same
  if(pd->imgx[sour_pic_pos].rows != pd->imgx[dest_pic_pos].rows) return -8; //dimension source and destination image are not same
  if(pd->imgx[sour_pic_pos].channels()!= 1) return -9; // channel number of source image must be 1
   if(pd->imgx[dest_pic_pos].channels()!= 1) return -10; // channel number of destination image must be 1
#ifndef ELI_SHARED_LIB
    if(edit==1)
     {
          wxArrayString names;
         names.Add(_("Threshold 1"));
         names.Add(_("Threshold 2"));
         names.Add(_("Aperture size"));
         Mat empt1,empt2;
        editPicture dlg(0,6,names,(float)thres1,(float)thres2,(float)aperture_size,0,0,0,pd->imgx[sour_pic_pos],empt1,empt2);
        if(dlg.ShowModal()==wxID_OK)
        {
            thres1=(int)dlg.GetV1();
            thres2=(int)dlg.GetV2();
            aperture_size=(int)dlg.GetV3();
            pd->updated_param.sprintf(_("Picture_%d#Picture_%d#Number#%d#Number#%d#%d"),sour_pic_pos,dest_pic_pos,thres1,thres2,aperture_size);
            pd->update_param=true;
        }
    }
    #endif

    Canny(pd->imgx[sour_pic_pos],pd->imgx[dest_pic_pos],(double)thres1,(double)thres2,aperture_size);

  }
    catch( cv::Exception& e )
   {
       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }

    return 0;
}

 int Conversion_Corners::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>5) return -2;

   if((line==0)||(line==1))
  {
    if(line==0) name=wxT("Source picture");
    else name=wxT("Destination picture");
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
  if(line==2)
  {
      name=wxT("Type of detector");
      type=2;
      wxArrayString arraystr;
      arraystr.Add(_("CornerHarris"));
      arraystr.Add(_("CornerMinEigenVal"));
      arraystr.Add(_("PreCornerDetect"));
      aray_str=arraystr;
        type2=0;
  }

  if(line==3)
  {
      name=wxT("Aperture size");
        type=4;
        ival=7;
  }
  if(line==4)
  {
      name=wxT("Block size");
      type=4;
      ival=3;
  }
  if(line==5)
  {
      name=wxT("Harris detector");
      type=5;
      fval=0.04;
  }


  return 0;
}

 int Conversion_Corners::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
{
  int sour_pic_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));//position of source picture in picture array
  wxString pom=param.AfterFirst('#');
  int dest_pic_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_')); //position of destination picture in picture array
  pom=pom.AfterFirst('#');

  int type=1; //type of detector, 1=PreCorner detect, 2=CornerHaris, 3=CornerMinEinVal
  if(pom.BeforeFirst('#')==_("CornerHarris")) type=2; //Corner Haris
  if(pom.BeforeFirst('#')==_("CornerMinEigenVal")) type=3;//CornerMinEinVal

  pom=pom.AfterFirst('#');
  int aperture_size=wxAtoi(pom.BeforeFirst('#')); //aperture size
  pom=pom.AfterFirst('#');
  int block_size=wxAtoi(pom.BeforeFirst('#')); //block size

  double haris_det; //haris detector k parameter
  pom.AfterFirst('#').ToCDouble(&haris_det);
  if((sour_pic_pos<0)||(sour_pic_pos>19)) return -1; //bad source picture position on picture array
  if((dest_pic_pos<0)||(dest_pic_pos>19)) return -2; //bad destination picture position on picture array

  if((aperture_size<3)||(aperture_size>31)) return -3; // Aperture size must be odd number, between 3 and 31
  if((aperture_size%2)==0) return -3; //Aperture size must be odd number between 3 and 31

  if(block_size<1) return -4;//block size must be higher than 0

  try
  {



     if(pd->imgx[sour_pic_pos].cols != pd->imgx[dest_pic_pos].cols) return -5; // dimension source and destination image are not same
  if(pd->imgx[sour_pic_pos].rows != pd->imgx[dest_pic_pos].rows) return -5; //dimension source and destination image are not same
  if(pd->imgx[sour_pic_pos].channels()!= 1) return -6; // channel number of source image must be 1
   if(pd->imgx[dest_pic_pos].channels()!= 1) return -7; // channel number of destination image must be 1

   #ifndef ELI_SHARED_LIB
    if(edit==1)
     {
         Mat empt1,empt2,originx;
         originx=pd->imgx[sour_pic_pos].clone();
          wxArrayString names;
          if(type==1)
          {
              names.Add(_("Aperture size"));
              editPicture dlg(0,7,names,1,(float)aperture_size,0,0,0,0,pd->imgx[sour_pic_pos],empt1,empt2);
                if(dlg.ShowModal()==wxID_OK)
             {
            aperture_size=(int)dlg.GetV1();
            pd->updated_param.sprintf(_("Picture_%d#Picture_%d#PreCornerDetect#%d#3#0.04"),sour_pic_pos,dest_pic_pos,aperture_size);
            pd->update_param=true;
            }
          }
          if(type==2)
          {
              names.Add(_("Block size"));
              names.Add(_("Aperture size"));
              names.Add(_("Haris detector"));
             editPicture dlg(0,7,names,2,(float)block_size,aperture_size,haris_det,0,0,pd->imgx[sour_pic_pos],empt1,empt2);
            if(dlg.ShowModal()==wxID_OK)
             {
            block_size=(int)dlg.GetV1();
            aperture_size=(int)dlg.GetV2();
            haris_det=dlg.GetV3();
            pd->updated_param.sprintf(_("Picture_%d#Picture_%d#CornerHarris#%d#%d#%f"),sour_pic_pos,dest_pic_pos,aperture_size,block_size,haris_det);
            pd->update_param=true;
            }
          }
          if(type==3)
          {
              names.Add(_("Block size"));
              names.Add(_("Aperture size"));
          editPicture dlg(0,7,names,3,(float)block_size,aperture_size,0,0,0,pd->imgx[sour_pic_pos],empt1,empt2);
             if(dlg.ShowModal()==wxID_OK)
             {
            block_size=(int)dlg.GetV1();
            aperture_size=(int)dlg.GetV2();
            pd->updated_param.sprintf(_("Picture_%d#Picture_%d#CornerMinEigenVal#%d#%d#%0.04"),sour_pic_pos,dest_pic_pos,aperture_size,block_size);
            pd->update_param=true;
             }
          }
       pd->imgx[sour_pic_pos]=originx.clone();
    }
    #endif
    Mat imgx;

    if(type==1)  preCornerDetect(pd->imgx[sour_pic_pos],imgx,aperture_size);
    if(type==2) cornerHarris(pd->imgx[sour_pic_pos],imgx,block_size,aperture_size,haris_det);
    if(type==3) cornerMinEigenVal(pd->imgx[sour_pic_pos],imgx,block_size,aperture_size);
    convertScaleAbs(imgx,pd->imgx[dest_pic_pos]);

  }
      catch( cv::Exception& e )
   {
       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }
    return 0;
}

/**************************************************************************
Class for invert tested image
***************************************************************************/
 int Conversion_Invert::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>1) return -2;

   if((line==0)||(line==1))
  {
    if(line==0) name=wxT("Source picture");
    else name=wxT("Destination picture");
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

  return 0;
}

 int Conversion_Invert::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
{
  int sour_pic_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));//position of source picture in picture array
  wxString pom=param.AfterFirst('#');
  int dest_pic_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_')); //position of destination picture in picture array
   if((sour_pic_pos<0)||(sour_pic_pos>19)) return -1; //bad source picture position on picture array
  if((dest_pic_pos<0)||(dest_pic_pos>19)) return -2; //bad destination picture position on picture array

 try
 {


      if(pd->imgx[sour_pic_pos].cols != pd->imgx[dest_pic_pos].cols) return -3; // dimension source and destination image are not same
  if(pd->imgx[sour_pic_pos].rows != pd->imgx[dest_pic_pos].rows) return -3; //dimension source and destination image are not same

 bitwise_not(pd->imgx[sour_pic_pos],pd->imgx[dest_pic_pos]); //Function for invert tested image
 }
       catch( cv::Exception& e )
   {
       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90; // OpenCv error
   }
  return 0;
}
