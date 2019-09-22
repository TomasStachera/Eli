#include "ContourDescript3.h"



/*******************************************************************************************
Contour calculation class
Class is use for exution object found algorithms
Input parameters:
              contours: CvSequence structure with contours
              obprg: Object program structure with test program for contours found algoritm
              numbobj: object block number.It can be number from 1 to 19 describes objects block
*******************************************************************************************/
ContourCalculation::ContourCalculation(vector<vector<Point> > contours,ObjectPrograms *obprg,int numbobj,int read_mode_)
{
max_filter_line=MAXIMAL_FILTER_LINES; //number of filter commands default value is 100

filter=new FILTER[max_filter_line];
actual_filter_line=0;
IsCvError=false;
temporary_variable_numb=0;
temporary_variable=NULL;
obj_fnd=NULL;
all_obj_cnt=0;
read_mode=read_mode_;
 /*Alocate contour calculation structure*/

 obj_prog=obprg;
 num_obj_block=numbobj;

 maximal_obj_numb=MAXIMAL_OBJECTS_LINES;// Maximal object number is 1000
 object_calculation=new OBJECTCAL[maximal_obj_numb];
 real_object_number=0; // set real object number to 0
 for(int i=0;i<maximal_obj_numb;i++)
 {
     object_calculation[i].number=0;
object_calculation[i].number_of_contour=0;
 }

 /*End alocation contour calculation structure*/

try{

        total_contours=1;

     total_contours=contours.size();
	       for(int i=0;i<total_contours;i++)contx.push_back(contours[i]);



     contour_active=new bool[total_contours];
     param=new PARAMETERS[total_contours];
 // reset  object calculation structure
     for(int i=0;i<maximal_obj_numb;i++)
     {
         object_calculation[i].number_of_contour=0;
         object_calculation[i].cont_pos=new int[total_contours];
     }

 // Set all contours as active (Filter command can deactivate it)
     for(int i=0;i<total_contours;i++)
     {
       contour_active[i]=true;
       param[i].contour_area_calculated=false;
       param[i].enclosing_circle_calculated=false;
       param[i].fit_elipse_calculated=false;
       param[i].min_area_rec_calculated=false;
       param[i].moments_calculated=false;
       param[i].perimeter_calculated=false;
       param[i].rect_calculated=false;
     }

     /*
     Read objects to structure
     */

     int filter_lines;
     wxArrayString lines_string;

  // Get filter parameters
     if(obj_prog->ReturnFilterParam(obj_prog->GetIndexAccordingNumber(num_obj_block),filter_lines,lines_string))
     {
         // Found filter lines
         int result,input_from,contour_param,comp_option,number_from;
         double number;
         wxString pom;

         for(int i=0;i<filter_lines;i++)
         {
             result=wxAtoi(lines_string[i].BeforeFirst('#'));
             pom=lines_string[i].AfterFirst('#');
             input_from=wxAtoi(pom.BeforeFirst('#'));
             pom=pom.AfterFirst('#');
             contour_param=wxAtoi(pom.BeforeFirst('#'));
              pom=pom.AfterFirst('#');
              comp_option=wxAtoi(pom.BeforeFirst('#'));
               pom=pom.AfterFirst('#');
               pom.BeforeFirst('#').ToCDouble(&number);
               number_from=wxAtoi(pom.AfterFirst('#'));
             InserFilterLine(result,input_from,contour_param,comp_option,number,number_from);
         }

     }

     int numbo=obj_prog->GetNumberOfObjects(obj_prog->GetIndexAccordingNumber(num_obj_block));

     if(numbo>0)
     {
         // Some objects was found
         wxString namex,descx;
         int numlinex;
         wxArrayString arlinex;
         OBJECT_COMMAND *objx;

         for(int i=0;i<numbo;i++)
         {
         arlinex.Clear();

         int ret=obj_prog->ReturnObjectProgram(obj_prog->GetIndexAccordingNumber(num_obj_block),i,namex,descx,numlinex,arlinex);

          if(ret!=0)
          {
              ErrorLog erl;
              wxString pomx=_("Error in function ReturnObjectProgram\nError code:");
              pomx<<ret;
              erl.SetError(_("ConTourCalculation costructor error"),pomx);
              erl.DisplayLog(0);
          }
          else
          {
              if(numlinex>0)
              {

              objx=new OBJECT_COMMAND[numlinex];


              for(int j=0;j<numlinex;j++)
              {
                wxString px=arlinex[j];
                objx[j].description=px.BeforeFirst('#');
               px=px.AfterFirst('#');

           if(px.BeforeFirst('#')==_("CONDITION"))  objx[j].type=1;
          else if(px.BeforeFirst('#')==_("MATH"))objx[j].type=2;
         else if(px.BeforeFirst('#')==_("AND")) objx[j].type=3;
         else if(px.BeforeFirst('#')==_("OR")) objx[j].type=4;
         else if(px.BeforeFirst('#')==_("LB"))  objx[j].type=5;
         else if(px.BeforeFirst('#')==_("RB")) objx[j].type=6;
         else objx[j].type=0;

         double dxx;

                px=px.AfterFirst('#');
          objx[j].param1=wxAtoi(px.BeforeFirst('#'));
          px=px.AfterFirst('#');
          objx[j].i_param1=wxAtoi(px.BeforeFirst('#'));
          px=px.AfterFirst('#');
          px.BeforeFirst('#').ToCDouble(&dxx);
          objx[j].f_param1=(float)dxx;
          px=px.AfterFirst('#');
          objx[j].s_param1=px.BeforeFirst('#');
          px=px.AfterFirst('#');
          objx[j].param2=wxAtoi(px.BeforeFirst('#'));
          px=px.AfterFirst('#');
          objx[j].i_param2=wxAtoi(px.BeforeFirst('#'));
          px=px.AfterFirst('#');
          px.BeforeFirst('#').ToCDouble(&dxx);
          objx[j].f_param2=(float)dxx;
          px=px.AfterFirst('#');
          objx[j].s_param2=px.BeforeFirst('#');
           px=px.AfterFirst('#');
          objx[j].operand=wxAtoi(px.BeforeFirst('#'));
          px=px.AfterFirst('#');
          objx[j].i_result=wxAtoi(px.BeforeFirst('#'));
           objx[j].s_result=px.AfterFirst('#');


              }
              ret=SetObject(namex,descx,numlinex,objx);
              delete[]objx;
              if(ret!=0)
              {
                 ErrorLog erl;
              wxString pomx=_("Error in function SetObject\nError code:");
              pomx<<ret;
              erl.SetError(_("ConTourCalculation costructor error"),pomx);
              erl.DisplayLog(0);
              }
              }

          }

         }
     }
}
	  catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    openCvError=pv;
    IsCvError=true;
    }
}

ContourCalculation::~ContourCalculation()
{
delete[] filter;
delete[] param;

/* dealocate contour calculation object */
for(int i=0;i<real_object_number;i++)delete[] object_calculation[i].command; // delete object calculation
for(int i=0;i<maximal_obj_numb;i++) delete[] object_calculation[i].cont_pos;
delete[] object_calculation;
if(temporary_variable!=NULL) delete[] temporary_variable;
if(obj_fnd != NULL) delete[] obj_fnd;
}

/*
Function AddObjectLines add all filter lines to the object structure
Input parameters:
             1. obj_prg= Object program structure with test program
             2.numb = Object block number
Function return 0. If any index from number block was found in ObjectPrograms class (New object block)
         return -1. If program has more lines as maximal filter lines
         return 1. All is OK

*/
int ContourCalculation::AddObjecttestLines(ObjectPrograms *obj_prg,int numb)
{
int ind=obj_prg->GetIndexAccordingNumber(numb);
if(ind<0)return 0; // No index found

int filter_lines=0;
wxArrayString lines_string;
lines_string.Clear();
int result,input_from,contour_param,comp_option,number_from;
double number;
wxString par1;

if(obj_prg->ReturnFilterParam(ind,filter_lines,lines_string))  //Filter was found
{
  for(int i=0;i<filter_lines;i++)
  {
      par1=lines_string[i];
      result=wxAtoi(par1.BeforeFirst('#'));
      par1=par1.AfterFirst('#');
      input_from=wxAtoi(par1.BeforeFirst('#'));
      par1=par1.AfterFirst('#');
      contour_param=wxAtoi(par1.BeforeFirst('#'));
      par1=par1.AfterFirst('#');
      comp_option=wxAtoi(par1.BeforeFirst('#'));
      par1=par1.AfterFirst('#');
      par1.BeforeFirst('#').ToCDouble(&number);
      number_from=wxAtoi(par1.AfterFirst('#'));


     if(InserFilterLine(result,input_from,contour_param, comp_option, number, number_from)!=0) return -1; //Maximal line was detected
  }
}


    return 1;
}

/*
Function ContourStringToNumber  return contour parameter number according contour parameter name as input parameter name
   Function return number from 1 to 56 if contour parameter was found
            return -1 if no parameter according name was found
*/
 int ContourCalculation::ContourStringToNumber(wxString name)
 {
    if(name==_("Bounding rec X")) return 1;
    if(name==_("Bounding rec Y")) return 2;
    if(name==_("Bounding rec Height")) return 3;
    if(name==_("Bounding rec Width")) return 4;
    if(name==_("Perimeter")) return 5;
    if(name==_("Contour area")) return 6;
    if(name==_("Minimal area rec X")) return 7;
    if(name==_("Minimal area rec Y")) return 8;
    if(name==_("Minimal area rec Height")) return 9;
    if(name==_("Minimal area rec Width")) return 10;
    if(name==_("Minimal area rec Angle")) return 11;
    if(name==_("Min enclosing circle Center X")) return 12;
    if(name==_("Min enclosing circle Center Y")) return 13;
    if(name==_("Min enclosing circle Radius")) return 14;
    if(name==_("Fit elipse Center X")) return 15;
    if(name==_("Fit elipse Center Y")) return 16;
    if(name==_("Fit elipse Height")) return 17;
    if(name==_("Fit elipse Width")) return 18;
    if(name==_("Fit elipse Angle")) return 19;
    if(name==_("Central moments(2,0)")) return 20;
    if(name==_("Central moments(1,1)")) return 21;
    if(name==_("Central moments(0,2)")) return 22;
    if(name==_("Central moments(3,0)")) return 23;
    if(name==_("Central moments(2,1)")) return 24;
    if(name==_("Central moments(1,2)")) return 25;
    if(name==_("Central moments(0,3)")) return 26;
    if(name==_("Hu moments 0")) return 27;
    if(name==_("Hu moments 1")) return 28;
    if(name==_("Hu moments 2")) return 29;
    if(name==_("Hu moments 3")) return 30;
    if(name==_("Hu moments 4")) return 31;
    if(name==_("Hu moments 5")) return 32;
    if(name==_("Hu moments 6")) return 33;
    if(name==_("Norm Central moments(2,0)")) return 34;
    if(name==_("Norm Central moments(1,1)")) return 35;
    if(name==_("Norm Central moments(0,2)")) return 36;
    if(name==_("Norm Central moments(3,0)")) return 37;
    if(name==_("Norm Central moments(2,1)")) return 38;
    if(name==_("Norm Central moments(1,2)")) return 39;
    if(name==_("Norm Central moments(0,3)")) return 40;
    if(name==_("Spatial moments(0,0)")) return 41;
    if(name==_("Spatial moments(1,0)")) return 42;
    if(name==_("Spatial moments(0,1)")) return 43;
    if(name==_("Spatial moments(2,0)")) return 44;
    if(name==_("Spatial moments(1,1)")) return 45;
    if(name==_("Spatial moments(0,2)")) return 46;
    if(name==_("Spatial moments(3,0)")) return 47;
    if(name==_("Spatial moments(2,1)")) return 48;
    if(name==_("Spatial moments(1,2)")) return 49;
    if(name==_("Spatial moments(0,3)")) return 50;
    if(name==_("Number of inside contours")) return 51;
    if(name==_("Number of outside contours"))return 52;


     return -1;
 }

/*
Function ContourNumberToString  return name of contour parameter according
number as the first parameter number must be from range 1 to 56.
If number is out of this range function returns string "Error"
*/
 wxString ContourCalculation::ContourNumberToString(int num)
 {
    if(num== 1) return _("Bounding rec X");
    if(num== 2) return _("Bounding rec Y");
    if(num== 3) return _("Bounding rec Height");
    if(num== 4) return _("Bounding rec Width");
    if(num== 5) return _("Perimeter");
    if(num== 6) return _("Contour area");
    if(num== 7) return _("Minimal area rec X");
    if(num== 8) return _("Minimal area rec Y");
    if(num== 9) return _("Minimal area rec Height");
    if(num==10) return _("Minimal area rec Width");
    if(num==11) return _("Minimal area rec Angle");
    if(num==12) return _("Min enclosing circle Center X");
    if(num==13) return _("Min enclosing circle Center Y");
    if(num==14) return _("Min enclosing circle Radius");
    if(num==15) return _("Fit elipse Center X");
    if(num==16) return _("Fit elipse Center Y");
    if(num==17) return _("Fit elipse Height");
    if(num==18) return _("Fit elipse Width");
    if(num==19) return _("Fit elipse Angle");
    if(num==20) return _("Central moments(2,0)");
    if(num==21) return _("Central moments(1,1)");
    if(num==22) return _("Central moments(0,2)");
    if(num==23) return _("Central moments(3,0)");
    if(num==24) return _("Central moments(2,1)");
    if(num==25) return _("Central moments(1,2)");
    if(num==26) return _("Central moments(0,3)");
    if(num==27) return _("Hu moments 0");
    if(num==28) return _("Hu moments 1");
    if(num==29) return _("Hu moments 2");
    if(num==30) return _("Hu moments 3");
    if(num==31) return _("Hu moments 4");
    if(num==32) return _("Hu moments 5");
    if(num==33) return _("Hu moments 6");
    if(num==34) return _("Norm Central moments(2,0)");
    if(num==35) return _("Norm Central moments(1,1)");
    if(num==36) return _("Norm Central moments(0,2)");
    if(num==37) return _("Norm Central moments(3,0)");
    if(num==38) return _("Norm Central moments(2,1)");
    if(num==39) return _("Norm Central moments(1,2)");
    if(num==40) return _("Norm Central moments(0,3)");
    if(num==41) return _("Spatial moments(0,0)");
    if(num==42) return _("Spatial moments(1,0)");
    if(num==43) return _("Spatial moments(0,1)");
    if(num==44) return _("Spatial moments(2,0)");
    if(num==45) return _("Spatial moments(1,1)");
    if(num==46) return _("Spatial moments(0,2)");
    if(num==47) return _("Spatial moments(3,0)");
    if(num==48) return _("Spatial moments(2,1)");
    if(num==49) return _("Spatial moments(1,2)");
    if(num==50) return _("Spatial moments(0,3)");
    if(num==51) return _("Number of inside contours");
    if(num==52) return _("Number of outside contours");
     return _("Error");
 }

/**
Function is true if bounding rectangle of mirror contour is inside of nounding rectangle of orig_contours, otherwise function return false
1.parameter: orig_point - vector of origing contrours
2.parameter: mirrot: vector of mirror contours
3.parameter pos_orig. Position of original vector
4.parameter pos_mirror= position of mirror vector of contours

**/
bool ContourCalculation::IsInsideContour(vector<Point> orig_cont,vector<Point> mirror,int pos_orig,int pos_mirror)
{
 double orig_dat[4]; //0=bounding rect x, 1= bounding rect y, 2=bounding rect height,3=bounding rect width

 for(int i=0;i<4;i++)orig_dat[i]=ReturnContourParam(orig_cont,i+1,pos_orig);

 double miror_dat[4];

for(int i=0;i<4;i++)miror_dat[i]=ReturnContourParam(mirror,i+1,pos_mirror);

if((miror_dat[0]>=orig_dat[0])&&((miror_dat[0]+miror_dat[3])<=(orig_dat[0]+orig_dat[3]))&&(miror_dat[1]>=orig_dat[1])&&((miror_dat[1]+miror_dat[2])<=(orig_dat[1]+orig_dat[2])))return true;
else return false;

}

/**
Function is true if bounding rectangle of mirror contour is outside of nounding rectangle of orig_contours, otherwise function return false
1.parameter: orig_point - vector of origing contrours
2.parameter: mirrot: vector of mirror contours
3.parameter pos_orig. Position of original vector
4.parameter pos_mirror= position of mirror vector of contours

**/
bool ContourCalculation::IsOutsideContour(vector<Point> orig_cont,vector<Point> mirror,int pos_orig,int pos_mirror)
{
 double orig_dat[4]; //0=bounding rect x, 1= bounding rect y, 2=bounding rect height,3=bounding rect width

 for(int i=0;i<4;i++)orig_dat[i]=ReturnContourParam(orig_cont,i+1,pos_orig);

 double miror_dat[4];

for(int i=0;i<4;i++)miror_dat[i]=ReturnContourParam(mirror,i+1,pos_mirror);

if((miror_dat[0]<=orig_dat[0])&&((miror_dat[0]+miror_dat[3])>=(orig_dat[0]+orig_dat[3]))&&(miror_dat[1]<=orig_dat[1])&&((miror_dat[1]+miror_dat[2])>=(orig_dat[1]+orig_dat[2])))return true;
else return false;

}

/*****************************************************************************
Function return Contour parameter measured value according contour type.
Input parameters
 1.contour. Contour sequence structure of selected contour
 2.type. Type of measurement: Calculated parameters is same as in function ContourNumberToString
         It means calculated parameter name is read from this function.
 3.pos. is position in PARAMETERS structure

 Function return measured parameter in double format
         return 0 if no contour was selected
         return 0 if parameter type is out of range (1..56)

******************************************************************************/

double ContourCalculation::ReturnContourParam(vector<Point> contour,int type,int pos)
{
   double value=0;


   if((type<1)||(type>52)) return 0; //unknown type

IsCvError=false; //reset Cv error
try
{
   if((type>=1)&&(type<=4)) //Bounding rect
   {
      cv::Rect rect;
      if(!param[pos].rect_calculated)
      {
          rect=boundingRect(contour);
          param[pos].rect=rect;
          param[pos].rect_calculated=true;
      }
      else rect=param[pos].rect;

       if(type==1) value=(double)rect.x;
       if(type==2) value=(double)rect.y;
       if(type==3) value=(double)rect.height;
       if(type==4) value=(double)rect.width;
   }
   if(type==5)
   {
       if(!param[pos].perimeter_calculated)
       {
          value=arcLength(contour,true); //Perimeter
          param[pos].perimeter=value;
          param[pos].perimeter_calculated=true;
       }
       else value=param[pos].perimeter;

   }
   if(type==6)
   {
       if(!param[pos].contour_area_calculated)
       {
          value=contourArea(contour); //contour area
          param[pos].contour_area=value;
          param[pos].contour_area_calculated=true;
       }
       else value=param[pos].contour_area;
   }
   if((type>=7)&&(type<=11)) //Min area rec
   {
       RotatedRect box;
       if(!param[pos].min_area_rec_calculated)
       {
         box=minAreaRect(contour);
         param[pos].min_area_rec=box;
         param[pos].min_area_rec_calculated=true;
       }
       else box=param[pos].min_area_rec;

       if(type==7) value=(double)box.center.x;
       if(type==8) value=(double)box.center.y;
       if(type==9) value=(double)box.size.height;
       if(type==10) value=(double)box.size.width;
       if(type==11) value=(double)box.angle;

   }
   if((type>=12)&&(type<=14)) //MInimal enclosing circle
   {
      Point2f center; //Minimal enclosing circle center
      float radius; //Minimal enclosing circle radius
      if(!param[pos].enclosing_circle_calculated)
      {
         minEnclosingCircle(contour,center,radius);
         param[pos].enclosing_circle_center=center;
         param[pos].enclosing_circle_radius=radius;
         param[pos].enclosing_circle_calculated=true;
      }
      else
      {
          center=param[pos].enclosing_circle_center;
          radius=param[pos].enclosing_circle_radius;
      }

      if(type==12) value=(double)center.x;
      if(type==13) value=(double)center.y;
      if(type==14) value=(double)radius;
   }
   if((type>=15)&&(type<=19)) // Fit elipse
   {
       RotatedRect box;
      if(contour.size()>5) //At leas 5 point must be for fit elipse
      {
        if(!param[pos].fit_elipse_calculated)
       {
         box=fitEllipse(contour);
         param[pos].fit_elipse=box;
         param[pos].fit_elipse_calculated=true;
       }
       else box=param[pos].fit_elipse;
      }


       if(type==15) value=(double)box.center.x;
       if(type==16) value=(double)box.center.y;
       if(type==17) value=(double)box.size.height;
       if(type==18) value=(double)box.size.width;
       if(type==19) value=(double)box.angle;
   }
   if((type>=20)&&(type<=50)) // Moments
   {
       Moments momentsx;

       if(!param[pos].moments_calculated)
       {
        momentsx=moments(contour);
        param[pos].momentsx=momentsx;
        param[pos].moments_calculated=true;
       }
       else momentsx=param[pos].momentsx;
  //central moments
       if(type==20) value=momentsx.mu20;
       if(type==21) value=momentsx.mu11;
       if(type==22) value=momentsx.mu02;
       if(type==23) value=momentsx.mu30;
       if(type==24) value=momentsx.mu21;
       if(type==25) value=momentsx.mu12;
       if(type==26) value=momentsx.mu03;
       if((type>=27)&&(type<=33)) //hu moments
       {
        double hu[7];
        HuMoments(momentsx,hu);
            if(type==27) value=hu[0];
            if(type==28) value=hu[1];
            if(type==29) value=hu[2];
            if(type==30) value=hu[3];
            if(type==31) value=hu[4];
            if(type==32) value=hu[5];
            if(type==33) value=hu[6];
       }
       //Normalized central moments
      if(type==34) value=momentsx.nu20;
      if(type==35) value=momentsx.nu11;
      if(type==36) value=momentsx.nu02;
      if(type==37) value=momentsx.nu30;
      if(type==38) value=momentsx.nu21;
      if(type==39) value=momentsx.nu12;
      if(type==40) value=momentsx.nu03;
       //Spatial moments
      if(type==41) value=momentsx.m00;
      if(type==42) value=momentsx.m10;
      if(type==43) value=momentsx.m01;
      if(type==44) value=momentsx.m20;
      if(type==45) value=momentsx.m11;
      if(type==46) value=momentsx.m02;
      if(type==47) value=momentsx.m30;
      if(type==48) value=momentsx.m21;
      if(type==49) value=momentsx.m12;
      if(type==50) value=momentsx.m03;
   }

   if(type==51)//Get number of inside rectangles
   {
       int counter_rect=0;

           for(int i=0;i<total_contours;i++)
         {
             if(IsContourActive(i))
             {
                if(i!=pos)
                {
                    if(IsInsideContour(contour,contx[i],pos,i))counter_rect++;
                }
             }

         }
         value=(double)counter_rect;
   }

    if(type==52)//Get number of outside rectangles
   {
       int counter_rect=0;

           for(int i=0;i<total_contours;i++)
         {
             if(IsContourActive(i))
             {
                if(i!=pos)
                {
                    if(IsOutsideContour(contour,contx[i],pos,i))counter_rect++;
                }
             }

         }
         value=(double)counter_rect;
   }


}
	  catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    openCvError=pv;
    IsCvError=true;
    }

    return value;
}

/*
Function InsertFileterLine inserts one line in filter structur according input parameters:
Input parameters
    result :Active=1, Non active=0  If operation is true contour is active if result is 1
     input_from:  All=1 Active=0 , If input_from =1 function check all contours if not only active contours are read
     contour_parameter:   contour parameter number see function ContourStringToNumber
    comp_option:  (=) 1, (>) 2, (<) 3, (=>) 4, (=<) 5, (!=)6
     number: fixed number or variable number according last parameter
     number_from; -1 -fixed number, 0-99 system variable

Function return 0 if all is OK
         return -1 if maximal filter lines was reached
*/
int ContourCalculation::InserFilterLine(int result,int input_from,int contour_param,int comp_option,double number,int number_from)
{
    if(actual_filter_line >= max_filter_line) return -1; //maximal line was found
    filter[actual_filter_line].result=result;
    filter[actual_filter_line].input_from=input_from;
    filter[actual_filter_line].contour_parameter=contour_param;
    filter[actual_filter_line].comparison_option=comp_option;
    filter[actual_filter_line].comparison_number=number;
    filter[actual_filter_line].variable_from=number_from;
    actual_filter_line++;


    return 0;
}

/***************************************************
Function aplied Filter aplication algoritm
Function updated contour_active array as a result of filter
operation.
Function return 0=Normal condition
Function return -1 = actual filter line is equal or more than maximal filter line

Filter algoritm:
 - All contour are active in the begin of cycle. If no filter line  is executed all contours are active
 - If you select option Input from =All
           -if line condition is true conour is Active ( Option result Active) or not active (Opton result Not Active)
           -if line condition is false status of contour is not change
 - If you select option Input from= Active
            - if line condition is true contour is Active ( Option result Active) or not active (Opton result Not Active)
            -if line condition is false  contour is Not active (Option result Active) or active (Option result Not active)


*******************************************************/

int ContourCalculation::FilterAplication(void)
{
if(actual_filter_line>=max_filter_line) return -1; // actual filter line is more or equal than maximal filter line
IsCvError=false; //Reset OpenCV errors
double result_val=0; //result value
double bound_x=0,bound_y=0;
double difx=0,dify=0;
double edge_line=0;

try
{
    for(int x=0;x<total_contours;x++) contour_active[x]=true;
    for(int j=0;j<actual_filter_line;j++)
    {

        for(int i=0;i<total_contours;i++)
         {
           //Filter line calculation
            if((filter[j].input_from==1)||((filter[j].input_from!=1)&&(contour_active[i])))
               {
                   if(filter[j].contour_parameter==0)
                   {
                      //edge line option
                      edge_line=filter[j].comparison_number;

                      bound_x=ReturnContourParam(contx[i],1,i);
                      bound_y=ReturnContourParam(contx[i],2,i);
                       for(int c=i;c<total_contours;c++)
                       {
                           if((contour_active[c])&&(c!=i))
                           {
                             difx=ReturnContourParam(contx[c],1,c)-bound_x;
                           dify=ReturnContourParam(contx[c],2,c)-bound_y;


                        if((difx>=0)&&(difx<=edge_line)&&(dify>=0)&&(dify<=edge_line))contour_active[c]=false;

                           }

                       }
                   }
                   else
                   {
                     result_val=ReturnContourParam(contx[i],filter[j].contour_parameter,i);



                   switch (filter[j].comparison_option) //select according comparison option
                    {
                      case 1: //=
                           if(result_val==filter[j].comparison_number)
                           {
                               if(filter[j].result==1) contour_active[i]=true;
                               else contour_active[i]=false;
                           }
                           else
                           {
                              if(filter[j].result==1) contour_active[i]=false;
                               else contour_active[i]=true;
                           }
                        break;
                      case 2: //>
                            if(result_val > filter[j].comparison_number)
                           {
                               if(filter[j].result==1) contour_active[i]=true;
                               else contour_active[i]=false;

                           }
                           else
                           {
                              if(filter[j].result==1) contour_active[i]=false;
                               else contour_active[i]=true;
                           }
                       break;
                      case 3://<
                           if(result_val<filter[j].comparison_number)
                           {
                               if(filter[j].result==1) contour_active[i]=true;
                               else contour_active[i]=false;

                           }
                           else
                           {
                              if(filter[j].result==1) contour_active[i]=false;
                               else contour_active[i]=true;
                           }
                       break;
                      case 4://=>
                           if(result_val>=filter[j].comparison_number)
                           {
                               if(filter[j].result==1) contour_active[i]=true;
                               else contour_active[i]=false;
                           }
                           else
                           {
                              if(filter[j].result==1) contour_active[i]=false;
                               else contour_active[i]=true;
                           }
                       break;
                      case 5://=<
                            if(result_val<=filter[j].comparison_number)
                           {
                               if(filter[j].result==1) contour_active[i]=true;
                               else contour_active[i]=false;
                           }
                           else
                           {
                              if(filter[j].result==1) contour_active[i]=false;
                               else contour_active[i]=true;
                           }
                       break;
                      case 6://!=
                            if(result_val!=filter[j].comparison_number)
                           {
                               if(filter[j].result==1) contour_active[i]=true;
                               else contour_active[i]=false;
                           }
                           else
                           {
                              if(filter[j].result==1) contour_active[i]=false;
                               else contour_active[i]=true;
                           }
                       break;
                    }
                   }


               }

         }


      }
}



    catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    openCvError=pv;
    IsCvError=true;
    }



    return 0;
}

/*
Function gets filter parameters in one filter line.
Input parameters:
    line: filter line number
    result : returned result value in filter line
    input_from:  returned input from value
    contour_parameter: returned value contour parameter
    comparison_option: returned value comparison option
    comparison_number: returned value comparison number
    number_from: returned value number_from
  Function return 0 if all is OK
           return -1  if there is bad filter line number
*/
int ContourCalculation::GetFilterLineParam(int line,int &result,int &input_from,int &contour_parameter,int &comparison_option,double &comparison_number,int &number_from)
{
    if((line<0)||(line>=max_filter_line)) return -1; //Bad line number

    result=filter[line].result;
    input_from=filter[line].input_from;
    contour_parameter=filter[line].contour_parameter;
    comparison_option=filter[line].comparison_option;
    comparison_number=filter[line].comparison_number;
    number_from=filter[line].variable_from;
    return 0;
}

/*******************************************************
Function return bool value if contour is active according
position in contour array
*********************************************************/

bool ContourCalculation::IsContourActive(int pos)
{

    if((pos>=0)&&(pos<total_contours))
    {
        return contour_active[pos];
    }
    else return false;
}

/*
Function add one object in OBJECT_COMMAND structure or update object if already exist
Input parameters:
          name: name of object
          Description: Description of objects
          line_numb: Number of lines in object programs
          obj object command structure
 Function return 0 if all is ok
                retrun -1 if maximal number of objects was reached (999)
                return -2 if no commands are in the object program (line_numb is less than 1)
*/

int ContourCalculation::SetObject(wxString name,wxString Description,int line_numb,OBJECT_COMMAND *obj)
{
   if(real_object_number>999) return -1; //Maximal number of objects is 999
   if(line_numb<1) return -2; //no commands in object

   int pos=FindObjectName(name);
   if(pos<0) // new object
   {
       pos=real_object_number;
       real_object_number++;
   }

   object_calculation[pos].name=name;
   object_calculation[pos].description=Description;
   object_calculation[pos].number=line_numb;
   object_calculation[pos].command=new OBJECT_COMMAND[line_numb];

   for(int i=0;i<line_numb;i++)
   {
       object_calculation[pos].command[i].type=obj[i].type;
       object_calculation[pos].command[i].description=obj[i].description;
        object_calculation[pos].command[i].param1=obj[i].param1;
       object_calculation[pos].command[i].i_param1=obj[i].i_param1;
       object_calculation[pos].command[i].f_param1=obj[i].f_param1;
       object_calculation[pos].command[i].s_param1=obj[i].s_param1;
        object_calculation[pos].command[i].param2=obj[i].param2;
       object_calculation[pos].command[i].i_param2=obj[i].i_param2;
       object_calculation[pos].command[i].f_param2=obj[i].f_param2;
       object_calculation[pos].command[i].s_param2=obj[i].s_param2;
        object_calculation[pos].command[i].operand=obj[i].operand;
       object_calculation[pos].command[i].i_result=obj[i].i_result;
       object_calculation[pos].command[i].s_result=obj[i].s_result;
   }

    return 0;
}


/*
Function found object according name in object calculation structure
Function return -1 if object name was not found .
If object was found function return position of object in object calculation
structure
*/

int ContourCalculation::FindObjectName(wxString name)
{
    bool end=false;
    int pos=0;

    if(real_object_number==0) return -1; //name was not found

    while(!end)
    {
      if(object_calculation[pos].name==name) end=true;
      else
      {
          pos++;
          if(pos==real_object_number)
          {
              end=true;
              return -1; // name was not found
          }
      }
    }

    return pos;
}

/*
Function return number of lines in object according position number
Input parameter: pos: position in object structure
 Function return -1: if there is bad position in structure (position number is more than real object number
          return -2: if there is bad position in structure (position number is less than 0
  Function return number of object lines if all is OK
*/
int ContourCalculation::GetObjectsLines(int pos)
{
    if(pos>=real_object_number) return -1; //Bad position in structure
    if(pos<0) return -2; //Bad position in structure

    return object_calculation[pos].number;
}

/*
Function gets test program parameters and description according position of object and test program line
Input parameters:
    param: reference for test command parameter
    description: reference for command description
    pos: position od object in object structure
    line: object test program line from where parameters will be read
 Function return 0: if all is OK
        return -2: Bad position in object structure (pos number is less than 0)
        return -1:  Bad position in object structure (pos number is more than real object number)
        return -3: Bad line number .Parameter line is more than maximal line number in object program
        return -4: Bad line number. Line number is less than 1. (No test program lines in object program)
        return -5: Bad command type. Command type is out of range less than 1 (range must be 1 to 6)
        return -6: Bad command type. Command type is out of range more than 6 (range must be 1 to 6)

*/
int ContourCalculation::GetTestProgram(wxString &param,wxString &description,int pos,int line)
{
 /*
     Test command parameters:
     type of command#param1#i_param1#f_param1#s_param1#param2#i_param2#f_param2#s_param2#operand#i_result#s_result
     */
     if(pos<0) return -2; //Bad position in structure
     if(pos>=real_object_number) return -1; //Bad position in sructure
     if(line> object_calculation[pos].number) return -3; //bad line number in test program
     if(line<1) return -4; //bad line number in the test program



     if(object_calculation[pos].command[line-1].type<1) return -5; //bad command type
     if(object_calculation[pos].command[line-1].type>6) return -6; //bad command type

     if(object_calculation[pos].command[line-1].type==1) param=_("CONDITION#");
     if(object_calculation[pos].command[line-1].type==2) param=_("MATH#");
     if(object_calculation[pos].command[line-1].type==3) param=_("AND#");
     if(object_calculation[pos].command[line-1].type==4) param=_("OR#");
     if(object_calculation[pos].command[line-1].type==5) param=_("LB#");
     if(object_calculation[pos].command[line-1].type==6) param=_("RB#");
     param << object_calculation[pos].command[line-1].param1;
     param+=_("#");
     param << object_calculation[pos].command[line-1].i_param1;
     param +=_("#");
     param << object_calculation[pos].command[line-1].f_param1;
     param += _("#");
     param += object_calculation[pos].command[line-1].s_param1;
     param += _("#");
     param << object_calculation[pos].command[line-1].param2;
     param += _("#");
     param << object_calculation[pos].command[line-1].i_param2;
     param += _("#");
     param << object_calculation[pos].command[line-1].f_param2;
     param += _("#");
     param += object_calculation[pos].command[line-1].s_param2;
     param += _("#");
     param << object_calculation[pos].command[line-1].operand;
     param += _("#");
     param << object_calculation[pos].command[line-1].i_result;
     param += _("#");
     param += object_calculation[pos].command[line-1].s_result;
     description=object_calculation[pos].command[line-1].description;


    return 0;
}

/*
Function delete object from OBJECTCAL structure.
Funbction set empty string to object name and obejctdescription
Function return 0 if object was deleted
Function return -1 if object was not found
*/
int ContourCalculation::DeleteObject(wxString name)
{
    int pos=FindObjectName(name);

    if(pos<0) return -1; // No object with neme in parameter was found

    object_calculation[pos].name=_("");
    object_calculation[pos].description=_("");
    object_calculation[pos].number=0;

    return 0;
}

/*
Function copy object. As a source object is object with old_name parameter.
New object name is as second parameter.
Function return 0 if copy objects was OK
Function return -1 if is 999 objects in OBJECTCAL structure
Function return -2 if source name was not found in OBJECTCAL structure
Function return -3 if new name is already use as a object name in OBJECTCAL structure
*/

int ContourCalculation::CopyObject(wxString old_name,wxString new_name)
{
      if(real_object_number>999) return -1; //Maximal number of objects is 999


   int old_pos=FindObjectName(old_name);
   if(old_pos<0) return -2; // old name was not found in OBJECTCAL structure
   int new_pos=FindObjectName(new_name);
   if(new_pos>-1) return -3; // new name is already used use another name
   int pos=real_object_number;
   real_object_number++;


   object_calculation[pos].name=new_name;
   object_calculation[pos].description=object_calculation[old_pos].description;
   object_calculation[pos].number=object_calculation[old_pos].number;
   object_calculation[pos].command=new OBJECT_COMMAND[object_calculation[old_pos].number];
   for(int i=0;i<object_calculation[old_pos].number;i++)
   {
       object_calculation[pos].command[i].type=object_calculation[old_pos].command[i].type;
       object_calculation[pos].command[i].description= object_calculation[old_pos].command[i].description;
        object_calculation[pos].command[i].param1=object_calculation[old_pos].command[i].param1;
       object_calculation[pos].command[i].i_param1=object_calculation[old_pos].command[i].i_param1;
       object_calculation[pos].command[i].f_param1=object_calculation[old_pos].command[i].f_param1;
       object_calculation[pos].command[i].s_param1=object_calculation[old_pos].command[i].s_param1;
        object_calculation[pos].command[i].param2=object_calculation[old_pos].command[i].param2;
       object_calculation[pos].command[i].i_param2=object_calculation[old_pos].command[i].i_param2;
       object_calculation[pos].command[i].f_param2=object_calculation[old_pos].command[i].f_param2;
       object_calculation[pos].command[i].s_param2=object_calculation[old_pos].command[i].s_param2;
        object_calculation[pos].command[i].operand=object_calculation[old_pos].command[i].operand;
       object_calculation[pos].command[i].i_result=object_calculation[old_pos].command[i].i_result;
       object_calculation[pos].command[i].s_result=object_calculation[old_pos].command[i].s_result;
   }
    return 0;
}

/*
Function update object description in OBJECTCAL structure. The first parameter is
a object name and second is updated description.
Function return 0 if update description is OK
Function return -1 if object was not found in OBJECTCAL structure
Function return -2 if description string included prohibeted character #
*/

int ContourCalculation::UpdateDescription(wxString name,wxString description)
{
    int pos=FindObjectName(name);
   if(pos<0) return -1; // old name was not found in OBJECTCAL structure

   if(description.Find('#')!=wxNOT_FOUND) return -2; // Cheracter # is prohibited
   object_calculation[pos].description=description;

    return 0;
}

/*
Function get object name and description from OBJECTCAL structure according position in structure as a first parameter
Function return 0 if all is OK
Function return -1 if position is out of range
*/

int ContourCalculation::GetObjectNameAndDescription(int pos,wxString &name,wxString &description)
{
    if(pos>=real_object_number) return -1; // bad position number;
    if(pos<0) return -1;

    name=object_calculation[pos].name;
    description=object_calculation[pos].description;

    return 0;
}

/*
Function init TEMPVAR structure
This structure is use for store temporary variables
Function always return 0;
*/
int ContourCalculation::InitTempVariable(void)
{
    temporary_variable_numb=0;
    wxArrayString pom_variables; // teporary array for store temporary variables

    if(temporary_variable!=NULL) delete[] temporary_variable;

    pom_variables.Clear();
    bool found_name=false; //if seloected variable name was found in pom_variables array function return true othervise false

    for(int i=0;i<real_object_number;i++)
    {
        for(int j=0;j<object_calculation[i].number;j++)
        {

            if(object_calculation[i].command[j].param1==3)
            {

                found_name=false;
                for(unsigned int x=0;x<pom_variables.GetCount();x++)
                {
                   if(pom_variables[x]==object_calculation[i].command[j].s_param1) found_name=true;
                }
                if(!found_name)pom_variables.Add(object_calculation[i].command[j].s_param1);
            }
            if(object_calculation[i].command[j].param2==3)
            {

                found_name=false;
                for(unsigned int x=0;x<pom_variables.GetCount();x++)
                {
                   if(pom_variables[x]==object_calculation[i].command[j].s_param2) found_name=true;
                }
                if(!found_name)pom_variables.Add(object_calculation[i].command[j].s_param2);
            }
             if(object_calculation[i].command[j].i_result<0)
            {

                found_name=false;
                for(unsigned int x=0;x<pom_variables.GetCount();x++)
                {
                   if(pom_variables[x]==object_calculation[i].command[j].s_result) found_name=true;
                }
                if(!found_name)pom_variables.Add(object_calculation[i].command[j].s_result);
            }
        }
    }

  temporary_variable_numb=pom_variables.GetCount();

  if(temporary_variable_numb>0)
  {
     temporary_variable=new TEMPVAR[temporary_variable_numb];
     for(int i=0;i<temporary_variable_numb;i++)
     {
     temporary_variable[i].var_name=pom_variables[i];
     temporary_variable[i].var_value=0;
     }
  }


    return 0;
}

/*
Function return position of temporary variable in TEMPVAR structure.
Function return -1 if variable was not found
*/
int ContourCalculation::ReturnTempVariablePosition(wxString name)
{
    int pos=-1;

    bool end=false;
    int cnt=0;

    while(!end)
    {
      if(temporary_variable[cnt].var_name==name)
      {
          pos=cnt;
          end=true;
      }
      else
      {
          cnt++;
          if(cnt==temporary_variable_numb) end=true;
      }
    }

    return pos;
}

/*
Function set value to teporary variable.
Function return 0 if set was ok and return -1 if temporary variable was not found
in TEMPVAR structure
*/

int ContourCalculation::SetTempVariable(wxString name,float value)
{
    int pos=ReturnTempVariablePosition(name);
    if(pos<0) return -1;

    temporary_variable[pos].var_value=value;

    return 0;
}
/*
Function read value of temporary variiable. Value is set to second parameter as a reference
Function return 0 if read was OK and return -1 if variable was not found in TEMPVAR structure
*/
int ContourCalculation::ReadTempVariable(wxString name, float &value)
{
     int pos=ReturnTempVariablePosition(name);
    if(pos<0) return -1;

    value=temporary_variable[pos].var_value;

    return 0;
}

/*
Function execute Find object algoritm
Function go to each active contour and executes function RunObjectCommand
Input parameters:  syst_var: float array with system variable
Function return 0 if all is OK
         return -1  if there was error in RunObjectCommand function or OpenCv error
         retrun -2 if there was error in function ObjectRead
*/
int ContourCalculation::FindObjectExecution(float *syst_var)
{
  for(int i=0;i<100;i++)  temp_syst_var[i]=syst_var[i]; // Begin of function , read all system variable values
 InitTempVariable();

for(int i=0;i<maximal_obj_numb;i++)object_calculation[i].number_of_contour=0; // Sets number of contour to 0;
IsCvError=false; //Reset OpenCV errors

try
{


        for(int i=0;i<total_contours;i++)
         {
             if(IsContourActive(i))
             {
                 for(int j=0;j<real_object_number;j++)
                 {
                     if(RunObjectCommand(contx[i],i,j)!=0) return -1; // Error in Run object command
                 }
             }


         }


}

    catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    openCvError=pv;
    IsCvError=true;

      ErrorLog er;
wxString type=_("Contour calculation error in Function Find object execution");
   er.SetError(type,GetStringOpenCvError());
   er.DisplayLog();
   return -1;

    }


for(int i=0;i<100;i++) syst_var[i]=temp_syst_var[i]; // End fo function, update system variable values
if(ObjectRead(read_mode)!=0) return -2;

     return 0;
}

/*Function run test program on one contour object
Parameters:
contour = contour vector
contour_pos =position of contours
  object_pos=position  of object in object structure
Function return 0 if all was OK
        return -1 if there was some error. Error can be read in ErrorLog structure

*/
int ContourCalculation::RunObjectCommand(vector<Point> contour,int contour_pos,int object_pos)
{
for(int i=0;i<11;i++)
{
    contc[i].status=false;
    contc[i].operandx=0;
}
calc_index=0;
 int ret_code=0;

try
{


  if(object_pos<0) throw -2; // Bad object position
  if(object_pos>=real_object_number) throw -2; //Bad object position


  for(int i=1;i<object_calculation[object_pos].number+1;i++)
  {
     ret_code=RunOneObjectProgLine(contour,contour_pos,object_pos,i);
     if(ret_code !=0) throw i;
  }
  if(calc_index!=0) throw -3; //Brackets level error


  if(contc[0].status)
  {


      object_calculation[object_pos].cont_pos[object_calculation[object_pos].number_of_contour]=contour_pos; //Set contour position
      object_calculation[object_pos].number_of_contour++;//increase number of found contours as object
  }

}

catch (int xlog)
{
SetError(xlog, object_pos,ret_code,contour_pos);
return -1;
}

    return 0;
}

/*
Function describes error to ErrorLog structure from RunObjectCommand function and FindObjectExecution function
Parameters:  xlog= Error Return code in non OpenCv error
             object_pos= position  of object in object structure
             ret_code=Return code in functions RunOneObjectProgLine
             contour_pos= Contour number
 Function return always 0

*/
int ContourCalculation::SetError(int xlog,int object_pos,int ret_code,int contour_pos)
{
   ErrorLog er;
wxString type=_("Contour calculation error in Function RunObjectCommand");
wxString mes;

   if(xlog==-1) mes=_("Bad contour position. Less than 0 or more than maximal contur number");
   else if(xlog==-2) mes=_(" Bad object position: Less than 0 or more than maximal contour namuber");
   else if(xlog==-3) mes=_("Brackets level error.");
   else
   {
       mes=_(" Object name: ");
       mes+=object_calculation[object_pos].name;
       mes+=_("\nContour number: ");
       mes<<contour_pos;
       mes+=_("\nObject program line: ");
       mes<<xlog;
       mes+=_("\nError desciption:\n");

        switch (ret_code)
        {
            case -1:
             mes+=_(" Bad contour position. Contour number is more than equal as a maximal contour number or contour number is less tahn 0");
             break;
            case -2:
            mes+=_("Bad object position. Object position is more or equal as a maximal object number or object position is less than 0");
             break;
            case -3:
              mes+=_("Bad line number. Line number is more than maximal number of line in test program or line number is less than 1");
             break;
            case -4:
              mes+=_("Open CV error in operand 1 was detected.\n");
              mes+=GetStringOpenCvError();
             break;
            case -5:
               mes+=_("Bad parameter 1 in operand 1. System variable index is out of range");
             break;
            case -6:
               mes+=_("Temporary variable in operand 1 was not found");
             break;
            case -7:
               mes+=_("Open CV error in opernad 2 was detected. ");
               mes+=GetStringOpenCvError();
            break;
            case -8:
                mes+=_("Bad parameter 1 in operand 2. System variable index is out of range");
             break;
            case -9:
                mes+=_("Temporary variable in opernad 2 was not found");
            break;
            case -10:
                mes+=_("Operannd 2 in math command can not be 0 in operator \\ (0 devided)");
            break;
            case -11:
                mes+=_("Result temporary variable was not found");
            break;
            case -12:
                mes+=_("Result system variable number is  more than 99. Out of range");
            break;
            case -13:
                mes+=_("More brackets level than maximal (Maximal level is 10)");
            break;
            case -14:
                mes+=_("More right brackets than left");
            break;
            case -15:
                 mes+=_("Bad type of command (Command type out of range)");
            break;
            case -16:
                 mes+=_("Bad operator in the condition command (Operator out of range)");
            break;
            case -17:
                 mes+=_("Bad operator in the math command ( Operator  out of range)");
            break;
            default:
              mes+=_("Unspecified error");
            break;
        }
   }
   er.SetError(type,mes);
   er.DisplayLog();
    return 0;
}

/*
Function run one test program line. Function executed command in the selected line
Parameters:
 contour = actual contour sequence
contour_pos =position of contuor
 object_pos=position of object in object structure
 line= test program line

 Return function values
  0= No error

 -2 = Bad object position. Object position is more or equal as a maximal object number or object position is less than 0
 -3 = Bad line number. Line number is more than maximal number of line in test program or line number is less than 1
 -4 = Open CV error in operand 1 was detected. Call function GetStringOpenCvError for error explanation
 -5 = Bad parameter 1 in operand 1. System variable index is out of range
 -6 = Temporary variable in operand 1 was not found
 -7 = Open CV error in opernad 2 was detected. Call function GetStringOpenCvError for error explanation
 -8 = Bad parameter 1 in operand 2. System variable index is out of range
 -9 = Temporary variable in opernad 2 was not found
 -10 = Operannd 2 in math command can not be 0 in operator \ (0 devided)
 -11 = Result temporary variable was not found
 -12 = Result system variable number is  more than 99. Out of range
 -13 = More brackets level than maximal (Maximal level is 10)
 -14 = More right brackets than left
 -15 = Bad type of command (Command type out of range)
 -16 = Bad opetor in the condition command (Operator out of range)
 -17 = Bad operatorin the math command ( Operator  out of range)

*/
int ContourCalculation::RunOneObjectProgLine(vector<Point> contour,int contour_pos,int object_pos,int line)
{

  if(object_pos<0) return -2; // Bad object position
  if(object_pos>=real_object_number) return -2; //Bad object position
  if(line<1) return -3; //Bad line nuber;
  if(line>object_calculation[object_pos].number) return -3; //Bad line number
  int px=0;
  IsCvError=false; //Reset OpenCV errors

  int types=object_calculation[object_pos].command[line-1].type;
   float operand1,operand2;

 /**************  Get operand 1 and operand2 values *****************/
  if((types==1)||(types==2))
  {
      switch(object_calculation[object_pos].command[line-1].param1)
         {
           case 1: //contour parameter
             operand1=ReturnContourParam(contour,object_calculation[object_pos].command[line-1].i_param1,contour_pos);
             if(WasOpenCvError()) return -4; // open cv error in operand1
           break;
           case 2: //system variale
             px= object_calculation[object_pos].command[line-1].i_param1;
            if((px<0)||(px>99)) return -5; // Bad parameter 1 in operand 1
            operand1=temp_syst_var[px];
           break;
           case 3: //temporarry array
           if(ReadTempVariable(object_calculation[object_pos].command[line-1].s_param1,operand1)!=0) return -6; //Temporary variable was not found

            break;
           case 4: //number
           operand1=object_calculation[object_pos].command[line-1].f_param1;
            break;
         }

           switch(object_calculation[object_pos].command[line-1].param2)
         {
           case 1: //contour parameter
             operand2=ReturnContourParam(contour,object_calculation[object_pos].command[line-1].i_param2,contour_pos);
             if(WasOpenCvError()) return -7; // open cv error in operand2
           break;
           case 2: //system variale
             px= object_calculation[object_pos].command[line-1].i_param2;
            if((px<0)||(px>99)) return -8; // Bad parameter 1 in operand 2
            operand2=temp_syst_var[px];
           break;
           case 3: //temporarry array
           if(ReadTempVariable(object_calculation[object_pos].command[line-1].s_param2,operand2)!=0) return -9; //Temporary variable was not found

            break;
           case 4: //number
             operand2=object_calculation[object_pos].command[line-1].f_param2;
            break;
         }
  }

  /*******************  End get operand1 and operand 2 values ************************/



switch (types)
{
    case 1:  //Condition command
          bool cond_result;
         switch (object_calculation[object_pos].command[line-1].operand)
         {
             case 1:
               if(operand1==operand2) cond_result=true;
               else cond_result=false;
             break;
             case 2:
               if(operand1 > operand2) cond_result=true;
               else cond_result=false;
             break;
             case 3:
               if(operand1 < operand2) cond_result=true;
               else cond_result=false;
             break;
             case 4:
               if(operand1 >= operand2) cond_result=true;
               else cond_result=false;
             break;
             case 5:
               if(operand1 <= operand2) cond_result=true;
               else cond_result=false;
             break;
             case 6:
               if(operand1!=operand2) cond_result=true;
               else cond_result=false;
             break;
             default:
              return -16; //Bad operand in the condition command
             break;
         }

        if(contc[calc_index].operandx==0) contc[calc_index].status=cond_result; //No operand was activated
        else if(contc[calc_index].operandx==1)contc[calc_index].status= contc[calc_index].status & cond_result; // AND operand
        else contc[calc_index].status= contc[calc_index].status | cond_result; //OR operand

     break;
    case 2: //Math command
      float xresult;

         switch (object_calculation[object_pos].command[line-1].operand) //operand calculation
         {
            case 1:
              xresult=operand1+operand2;
             break;
            case 2:
             xresult=operand1-operand2;
             break;
            case 3:
            if(operand2==0) return -10; // operand 2 can not be 0
             xresult=operand1/operand2;
            break;
            case 4:
             xresult=operand1*operand2;
            break;
            case 5:
             xresult=pow(operand1,operand2);
            break;
            case 6:
             xresult=sqrt(operand1);
            break;
            case 7:
             xresult=sin(operand1);
            break;
            case 8:
             xresult=cos(operand1);
            break;
            case 9:
             xresult=tan(operand1);
            break;
            default:
              return -17; //bad operand
            break;
         }

        if(object_calculation[object_pos].command[line-1].i_result<0) //temporary array
        {
          if(SetTempVariable(object_calculation[object_pos].command[line-1].s_result,xresult)!=0) return -11; //Result temporary variable was not found
        }
        else
        {
            if(object_calculation[object_pos].command[line-1].i_result>99) return -12;// system variable number can not be higher than 99
            temp_syst_var[object_calculation[object_pos].command[line-1].i_result] =xresult;
        }

     break;
    case 3:  //And command
       contc[calc_index].operandx=1;
     break;
    case 4: //Or command
      contc[calc_index].operandx=2;
     break;
    case 5://Left bracket command
       calc_index++;
       if(calc_index>10) return -13; // Maximal brackets level is 10
       contc[calc_index].operandx=0;
       contc[calc_index].status=false;

     break;
    case 6://Right bracket command
       calc_index--;
       if(calc_index<0) return -14; // More right brackets than left

        if(contc[calc_index].operandx==0) contc[calc_index].status=contc[calc_index+1].status; //No operand was activated
        else if(contc[calc_index].operandx==1)contc[calc_index].status= contc[calc_index].status & contc[calc_index+1].status; // AND operand
        else contc[calc_index].status= contc[calc_index].status | contc[calc_index+1].status; //OR operand

     break;
    default:
      return -15; //Bad typeof command
      break;
}


return 0;
}
/*
Function return number of found contours in object according object position (1.argument)
If some objects was found contour number is return in second paramater
*/
int ContourCalculation::GetNumbFoundObjects(int pos,int *object_contours)
{
    int ret_obj=0;

    ret_obj=object_calculation[pos].number_of_contour;

    for(int i=0;i<ret_obj;i++) object_contours[i]=object_calculation[pos].cont_pos[i];



    return ret_obj;
}

/*
Function get object test program parameters
Parameters: pos= Position in object structure
            line= test program line
            cmd= reference for command name
            des= reference for command description
            formula= test program line formula
    Function return 0 if all is OK
             return -1   Bad position in sructure
             return -2 Bad position in sructure
             return -3  bad line number in test program , line>object program line
             return -4 bad line number in test program line<0
             return -5 BAd command type (command type isss than 0
             return -6  Bad command type (command type is more than 6)

*/
int ContourCalculation::GetObjectCommandLine(int pos,int line,wxString &cmd,wxString &des,wxString &formula)
{
      if(pos<0) return -2; //Bad position in structure
     if(pos>=real_object_number) return -1; //Bad position in sructure
     if(line> object_calculation[pos].number) return -3; //bad line number in test program
     if(line<0) return -4; //bad line number in the test program

     if(object_calculation[pos].command[line-1].type<1) return -5; //bad command type
     if(object_calculation[pos].command[line-1].type>6) return -6; //bad command type

     if(object_calculation[pos].command[line-1].type==1) cmd=_("CONDITION");
     if(object_calculation[pos].command[line-1].type==2) cmd=_("MATH");
     if(object_calculation[pos].command[line-1].type==3) cmd=_("AND");
     if(object_calculation[pos].command[line-1].type==4) cmd=_("OR");
     if(object_calculation[pos].command[line-1].type==5) cmd=_("(");
     if(object_calculation[pos].command[line-1].type==6) cmd=_(")");

     des=object_calculation[pos].command[line-1].description;
     formula=_("");

     wxString operand1,operand2 ;

     if((cmd==_("CONDITION"))||(cmd==_("MATH")))
     {
         if(object_calculation[pos].command[line-1].param1==1) operand1=ContourNumberToString(object_calculation[pos].command[line-1].i_param1);
         else if(object_calculation[pos].command[line-1].param1==2)
         {
             operand1=_("Variable_");
             operand1<<object_calculation[pos].command[line-1].i_param1;
         }
         else if(object_calculation[pos].command[line-1].param1==3) operand1=object_calculation[pos].command[line-1].s_param1;
         else if(object_calculation[pos].command[line-1].param1==4)  operand1<<object_calculation[pos].command[line-1].f_param1;
         else operand1=_("");

         if(object_calculation[pos].command[line-1].param2==1) operand2=ContourNumberToString(object_calculation[pos].command[line-1].i_param2);
         else if(object_calculation[pos].command[line-1].param2==2)
         {
             operand2=_("Variable_");
             operand2<<object_calculation[pos].command[line-1].i_param2;
         }
         else if(object_calculation[pos].command[line-1].param2==3) operand2=object_calculation[pos].command[line-1].s_param2;
         else if (object_calculation[pos].command[line-1].param2==4)operand2<<object_calculation[pos].command[line-1].f_param2;
         else operand2=_("");
     }

     if(cmd==_("CONDITION"))
     {
         wxString op;
         if(object_calculation[pos].command[line-1].operand==1) op=_(" = ");
         else if(object_calculation[pos].command[line-1].operand==2) op=_(" > ");
         else if(object_calculation[pos].command[line-1].operand==3) op=_(" < ");
         else if(object_calculation[pos].command[line-1].operand==4) op=_(" >= ");
         else if(object_calculation[pos].command[line-1].operand==5) op=_(" <= ");
         else if(object_calculation[pos].command[line-1].operand==6) op=_(" != ");
         else op=_(" Error ");

         formula=_("IF ");
         formula+=operand1;
         formula+=op;
         formula+=operand2;
     }

     if(cmd==_("MATH"))
     {
         wxString res;

         if(object_calculation[pos].command[line-1].i_result<0)
         {
             //temporary variable
             res=object_calculation[pos].command[line-1].s_result;
         }
         else
         {
             //system variable
             res=_("Variable_");
             res<<object_calculation[pos].command[line-1].i_result;
         }

         formula=res;
         formula+=_(" = ");

         switch (object_calculation[pos].command[line-1].operand)
         {
           case 1: //op1+op2
             formula+=operand1;
             formula+=_(" + ");
             formula+=operand2;
           break;
           case 2: //op1-op2
             formula+=operand1;
             formula+=_(" - ");
             formula+=operand2;
           break;
           case 3: //op1/op2
             formula+=operand1;
             formula+=_(" / ");
             formula+=operand2;
           break;
           case 4:  //op1*op2
            formula+=operand1;
            formula+=_(" * ");
            formula+=operand2;
           break;
           case 5://op1 ^ op2
             formula+=operand1;
             formula+=_(" ^ ");
             formula+=operand2;
           break;
           case 6:
             formula+=_(" Sqrt(");
             formula+=operand1;
             formula+=_(")");
           break;
           case 7:
             formula+=_("Sin(");
             formula+=operand1;
             formula+=_(")");
           break;
           case 8:
              formula+=_("Cos(");
             formula+=operand1;
             formula+=_(")");
           break;
           case 9:
             formula+=_("Tan(");
             formula+=operand1;
             formula+=_(")");
           break;
           default:
           formula=_("Error");
            break;
         }
     }

    return 0;
}

/*
Function return temporary variable name  according input parameter pos.
Input parameter pos: Index in TEMPVAR structure
Function return variable name if all is OK
    or function return string Error if input parameter index is out of range in TEMPVAR structure
*/
wxString ContourCalculation::ReturnTempVarName(int pos)
{
    if(pos<0) return _("Error");
    if(pos>=temporary_variable_numb) return _("Error");
    return temporary_variable[pos].var_name;
}

/*
Function RestartDebugMode initialize OBJECT calculation structure and temporary variable structure
before run debug mode.
Input parameters: syst_var  float array with system variables
Function always return 0
*/
int ContourCalculation::RestartDebugMode(float *syst_var)
{
    for(int i=0;i<100;i++)  temp_syst_var[i]=syst_var[i]; // Begin of function , read all system variable values
 InitTempVariable();

for(int i=0;i<maximal_obj_numb;i++)object_calculation[i].number_of_contour=0; // Sets number of contour to 0;
IsCvError=false; //Reset OpenCV errors

for(int i=0;i<11;i++)
{
    contc[i].status=false;
    contc[i].operandx=0;
}
calc_index=0;

    return 0;
}

/*
Function executes debug program on selected contour
Input parameters:
   cont_numb= contour number
   from_line : start line of debug test program
   to_line: end line of current debug in test program
   object_pos=position of object in object structure
 Function return 0 if all is OK
          return -1 if there is error in function   RunOneObjectProgLine or opencv error
          return -2 if there is bad contour number
*/
int ContourCalculation::RunDebugProgram(int cont_numb,int from_line,int to_line,int object_pos)
{
    if(cont_numb<1) return -2; //bad contour number
    if(cont_numb>total_contours) return -2; // bad contour number
    int ret_code;

try
{


        for(int i=0;i<total_contours;i++)
         {
              if(i==(cont_numb-1))
                 for(int j=(from_line-1);j<(to_line-1);j++)
                 {

                    ret_code= RunOneObjectProgLine(contx[i],cont_numb-1,object_pos,j+1);
                    if(ret_code!=0)
                    {
                        SetError(j+1,object_pos,ret_code,cont_numb);

                        return -1;// error in function RunOneObjectProgLine
                    }
                 }



         }

}

    catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    openCvError=pv;
    IsCvError=true;

      ErrorLog er;
wxString type=_("Contour calculation error in Function Find object execution");
   er.SetError(type,GetStringOpenCvError());
   er.DisplayLog();
   return -1;

    }



    return 0;
}

/*
Function return contour parameter value according input parameters
Input parameters:
       cont_numb= contour number
       object_pos= position of object in OBJECT structure
       param_numb= Contour parameters number
       line_numb= line number in test program
  Function return selected contour parameter or 0 if there is some error

*/
double ContourCalculation::GetContourParamValue(int cont_numb,int object_pos,int param_numb,int line_numb)
{
    double ret_val=0;



    if(object_pos<0)
    {
        SetError(line_numb,object_pos,-1,cont_numb);
        return 0;
    }
    if(object_pos>=real_object_number) //Bad position in sructure
    {
       SetError(line_numb,object_pos,-1,cont_numb);
        return 0;
    }

    if(cont_numb<0)
    {
      SetError(line_numb,object_pos,-2,cont_numb);
        return 0;
    }

    if(cont_numb>=total_contours)
    {
       SetError(line_numb,object_pos,-2,cont_numb);
        return 0;
    }



try
{


        for(int i=0;i<total_contours;i++)
         {
              if(i==(cont_numb))
                 {
                    ret_val=ReturnContourParam(contx[i],param_numb,cont_numb);
                     if(WasOpenCvError())
                     {
                         SetError(line_numb,object_pos,-7,cont_numb+1);

                         return 0;
                     }
                 }


         }

}

    catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    openCvError=pv;
    IsCvError=true;

      ErrorLog er;
wxString type=_("Contour calculation error in Function GetContourParamValue");
   er.SetError(type,GetStringOpenCvError());
   er.DisplayLog();
   return 0;

    }


    return ret_val;
}

/******************************************************************
Function read all objects from Object calculation structure and store it  OBJECT FOUND structure
Function has 1 input parameter mode
                 mode=0 (default) it will be read oject name,bounding rect x,y, height,width, perimeter and contour area
                 mode=1  all in mode 0 +
Function return 0 if all is OK
         return -1 if there is index error
*******************************************************************/

int ContourCalculation::ObjectRead(int mode)
{
   all_obj_cnt=0;
  if(obj_fnd!=NULL) delete[] obj_fnd;

    for(int i=0;i<real_object_number;i++) all_obj_cnt=all_obj_cnt+object_calculation[i].number_of_contour;

    obj_fnd=new OBJECTFOUND[all_obj_cnt];
    int *ps=NULL;
    int x_cnt=0;

    for(int i=0;i<real_object_number;i++)
    {
        if(object_calculation[i].number_of_contour>0)
        {
            ps=new int[object_calculation[i].number_of_contour];
            int c=GetNumbFoundObjects(i,ps);
            for(int j=0;j<c;j++)
            {
                if(x_cnt>=all_obj_cnt) return -1;
                obj_fnd[x_cnt].object_name=object_calculation[i].name;
                obj_fnd[x_cnt].bounding_rect_x=(int)GetContourParamValue(ps[j],i,1,0);
                obj_fnd[x_cnt].bounding_rect_y=(int)GetContourParamValue(ps[j],i,2,0);
                obj_fnd[x_cnt].bounding_rect_height=(int)GetContourParamValue(ps[j],i,3,0);
                obj_fnd[x_cnt].bounding_rect_width=(int)GetContourParamValue(ps[j],i,4,0);
                obj_fnd[x_cnt].perimeter=GetContourParamValue(ps[j],i,5,0);
                obj_fnd[x_cnt].contour_area=GetContourParamValue(ps[j],i,6,0);
                if(mode==1)
                {
                 obj_fnd[x_cnt].min_area_rect_x=(int)GetContourParamValue(ps[j],i,7,0);
                obj_fnd[x_cnt].min_area_rect_y=(int)GetContourParamValue(ps[j],i,8,0);
                obj_fnd[x_cnt].min_area_rect_height=(int)GetContourParamValue(ps[j],i,9,0);
                obj_fnd[x_cnt].min_area_rect_width=(int)GetContourParamValue(ps[j],i,10,0);
                obj_fnd[x_cnt].min_area_rect_angle=GetContourParamValue(ps[j],i,11,0);
                 obj_fnd[x_cnt].min_enclosing_circle_center_X=(int)GetContourParamValue(ps[j],i,12,0);
                obj_fnd[x_cnt].min_enclosing_circle_center_Y=(int)GetContourParamValue(ps[j],i,13,0);
               obj_fnd[x_cnt].min_enclosing_circle_radius=GetContourParamValue(ps[j],i,14,0);
                obj_fnd[x_cnt].fit_elipse_center_X=(int)GetContourParamValue(ps[j],i,15,0);
                obj_fnd[x_cnt].fit_elipse_center_Y=(int)GetContourParamValue(ps[j],i,16,0);
                obj_fnd[x_cnt].fit_elipse_height=(int)GetContourParamValue(ps[j],i,17,0);
                 obj_fnd[x_cnt].fit_elipse_width=(int)GetContourParamValue(ps[j],i,18,0);
                 obj_fnd[x_cnt].fit_elipse_angle=GetContourParamValue(ps[j],i,19,0);
                }

                x_cnt++;
            }
            delete []ps;
        }

    }

    return 0;
}

/*
Function return all found objects. All objects are stored in
pointer of ObJECTFOUND structure as a input parameter
Function return -1 if no objects was found
         return -2 if OBJECTFOUND structure was not allocated
         return -3 if input OBJECTFOUND structure was not allocated
         return 0 if all is OK
*/
int ContourCalculation::ReturnAllFoundObjects(OBJECTFOUND *of,int mode_)
{
  if(all_obj_cnt<1) return -1; //No object found
  if(obj_fnd==NULL) return -2; //No alocation
  if(of==NULL) return -3; //Bad alocation

  for(int i=0;i<all_obj_cnt;i++)
  {
     of[i].object_name=obj_fnd[i].object_name;
     of[i].bounding_rect_height=obj_fnd[i].bounding_rect_height;
     of[i].bounding_rect_width=obj_fnd[i].bounding_rect_width;
     of[i].bounding_rect_x=obj_fnd[i].bounding_rect_x;
     of[i].bounding_rect_y=obj_fnd[i].bounding_rect_y;
     of[i].contour_area=obj_fnd[i].contour_area;
     of[i].perimeter=obj_fnd[i].perimeter;
     if(mode_==1)
     {
          of[i].min_area_rect_x= obj_fnd[i].min_area_rect_x;
                of[i].min_area_rect_y=obj_fnd[i].min_area_rect_y;
                of[i].min_area_rect_height=obj_fnd[i].min_area_rect_height;
                of[i].min_area_rect_width=obj_fnd[i].min_area_rect_width;
                of[i].min_area_rect_angle=obj_fnd[i].min_area_rect_angle;
                 of[i].min_enclosing_circle_center_X=obj_fnd[i].min_enclosing_circle_center_X;
                of[i].min_enclosing_circle_center_Y=obj_fnd[i].min_enclosing_circle_center_Y;
               of[i].min_enclosing_circle_radius=obj_fnd[i].min_enclosing_circle_radius;
                of[i].fit_elipse_center_X=obj_fnd[i].fit_elipse_center_X;
                of[i].fit_elipse_center_Y=obj_fnd[i].fit_elipse_center_Y;
                of[i].fit_elipse_height=obj_fnd[i].fit_elipse_height;
                 of[i].fit_elipse_width=obj_fnd[i].fit_elipse_width;
                 of[i].fit_elipse_angle=obj_fnd[i].fit_elipse_angle;
     }
  }

    return 0;
}

/*
Function executes clear filter algoritm
*/
 void ContourCalculation::ClearFilter (void)
 {
   ResetActualFilterLIne();
   for(int i=0;i<total_contours;i++) contour_active[i]=true;
 }

/*
Function SaveObjectBlock
This function store object commands to ObjectProgram structure
Funtion return 0 if there is no error
Function return -10  if there is Bad filter line number
                -1 if Any object test program line was found
                -3 if Maximal filter lines was reached
                -2 if  Maximal object number was reached
                -4 if maximal object test program lines was reached
                -11 if there is Bad object number
                -21 Bad position in structure
                -22 Bad position in structure
                -31 Bad position in structure
                -32 Bad position in structure
                -33 bad line number in test program
                -34 bad line number in the test program
                -35 bad command type
                -36 bad command type


*/
 int ContourCalculation::SaveObjectBlock(void)
 {
obj_prog->InsertNewObjectBlock(num_obj_block);

int fil=ReturnActualFilterLine();

wxString line_cmd=_("");
int result,input_from,contour_parameter,comparison_option,number_from;
double comparison_number;


if(fil>0)
{
    for(int i=0;i<fil;i++)
    {
      line_cmd=_("FILTER#");
     if(GetFilterLineParam(i,result,input_from,contour_parameter,comparison_option,comparison_number,number_from)!=0) return -10; // Bad filter line number
     line_cmd<<result;
     line_cmd+=_("#");
     line_cmd<<input_from;
      line_cmd+=_("#");
      line_cmd<<contour_parameter;
      line_cmd+=_("#");
      line_cmd<<comparison_option;
      line_cmd+=_("#");
      line_cmd<<comparison_number;
      line_cmd+=_("#");
      line_cmd<<number_from;
      int x=obj_prog->DecodeTestProgramLine(line_cmd);
      if(x!=0) return x;
    }
}

int nu=GetNumberOfObject();// NUmber of found objects
wxString name,desc,paramx;
if(nu>0)
{
    for(int i=0;i<nu;i++)
    {
       if(GetObjectNameAndDescription(i,name,desc)!=0) return -11; //Bad object  number
       if(name.Length()>0)
       {
           line_cmd=_("OBJECT#");
           line_cmd+=name;
           line_cmd+=_("#");
           line_cmd+=desc;
           int x=obj_prog->DecodeTestProgramLine(line_cmd);
           if(x!=0) return x;
        int c=GetObjectsLines(i);
        if(c<0) return (c-20); //Get object line function error
         for(int j=0;j<c;j++)
         {
          int ret= GetTestProgram(paramx,desc,i,j+1);
          if(ret!=0) return (ret-30);
          line_cmd=_("TOBJECT#");
          line_cmd+=desc;
          line_cmd+=_("#");
          line_cmd+=paramx;
          int x=obj_prog->DecodeTestProgramLine(line_cmd);
           if(x!=0) return x;
         }

       }
    }
}


return 0;
 }

 /*
Function export object to file.
1.parameter=obj_name: object name
2.parameter=path: path for file with stored parameters

Function return 0 if export object to file was ok
         return -1 if object was not found
         return -2 if there is error to open or create export file
         return -3 if there is error write file
*/

int ContourCalculation::ExportObjectToFile(wxString obj_name,wxString path)
{

   int pos=FindObjectName(obj_name);
   if(pos<0) return -1; // object was not found

  wxTextFile fileex;

  if(!fileex.Create(path))
  {
      if(!fileex.Open(path)) return -2; //Error open file
  }
 fileex.Clear();


   fileex.AddLine(object_calculation[pos].name);
   if(object_calculation[pos].description.Length()<1)fileex.AddLine(_(" "));
   else fileex.AddLine(object_calculation[pos].description);
 wxString line_par;
   for(int i=0;i<object_calculation[pos].number;i++)
   {
       line_par=wxEmptyString;
       line_par<<object_calculation[pos].command[i].type;
       line_par+=_("#");
       if(object_calculation[pos].command[i].description.Length()<1)line_par+=_(" ");
       else line_par+=object_calculation[pos].command[i].description;
       line_par+=_("#");
        line_par<<object_calculation[pos].command[i].param1;
        line_par+=_("#");
       line_par<<object_calculation[pos].command[i].i_param1;
       line_par+=_("#");
       line_par<<object_calculation[pos].command[i].f_param1;
       line_par+=_("#");
       if(object_calculation[pos].command[i].s_param1.Length()<1)line_par+=_(" ");
       else line_par+=object_calculation[pos].command[i].s_param1;
       line_par+=_("#");
        line_par<<object_calculation[pos].command[i].param2;
        line_par+=_("#");
       line_par<<object_calculation[pos].command[i].i_param2;
       line_par+=_("#");
       line_par<<object_calculation[pos].command[i].f_param2;
       line_par+=_("#");
       if(object_calculation[pos].command[i].s_param2.Length()<1)line_par+=_(" ");
       else line_par+=object_calculation[pos].command[i].s_param2;
       line_par+=_("#");
        line_par<<object_calculation[pos].command[i].operand;
        line_par+=_("#");
       line_par<<object_calculation[pos].command[i].i_result;
       line_par+=_("#");
       if(object_calculation[pos].command[i].s_result.Length()<1)line_par+=_(" ");
       else line_par+=object_calculation[pos].command[i].s_result;
       fileex.AddLine(line_par);
   }

   if(!fileex.Write()) return -3; //Error write file
   fileex.Close();
    return 0;
}
/**
Function decode one line of import file
Function return 0 if all is ok
        return -1 Bad type It must be in range <1..5>
        return -2 Bad param 1  It must be in range <1..4>
        return -3  Bad param 2  It must be in range <1..4>
**/
int ContourCalculation::CheckLine(wxString line_str,int &typex,wxString &decs,int &param1,int &iparam1,float &fparam1,wxString &s_param1,int &param2,int &iparam2,float &fparam2,wxString &s_param2,int &operand,int &iresult,wxString &sresult)
{
double dxx;

 typex=wxAtoi(line_str.BeforeFirst('#'));
 if((typex<1)||(typex>5))return -1; //Bad type
 wxString pom=line_str.AfterFirst('#');
 decs=pom.BeforeFirst('#');
 pom=pom.AfterFirst('#');
 param1=wxAtoi(pom.BeforeFirst('#'));
 if((param1<0)||(param1>4)) return -2; //Bad param 1
 pom=pom.AfterFirst('#');
 iparam1=wxAtoi(pom.BeforeFirst('#'));
 pom=pom.AfterFirst('#');
 pom.BeforeFirst('#').ToCDouble(&dxx);
 fparam1=(float)dxx;
 pom=pom.AfterFirst('#');
 s_param1=pom.BeforeFirst('#');
  pom=pom.AfterFirst('#');
  param2=wxAtoi(pom.BeforeFirst('#'));
   if((param2<0)||(param2>4)) return -3; //Bad param 2
   pom=pom.AfterFirst('#');
  iparam2=wxAtoi(pom.BeforeFirst('#'));
 pom=pom.AfterFirst('#');
 pom.BeforeFirst('#').ToCDouble(&dxx);
 fparam2=(float)dxx;
 pom=pom.AfterFirst('#');
 s_param2=pom.BeforeFirst('#');
  pom=pom.AfterFirst('#');
  operand=wxAtoi(pom.BeforeFirst('#'));
   pom=pom.AfterFirst('#');
   iresult=wxAtoi(pom.BeforeFirst('#'));
   sresult=pom.AfterFirst('#');
    return 0;
}
/*
Function imports object from file
1.parameter: path: file path
2.parameter er_message : Error message
Function return 0 if import was without errors
Function return -1 if is 999 objects in OBJECTCAL structure
Function return -2 if there is error open file
        return -3 if import name is already used
        return -4 if import name contain character #
        return -5 if import object description contain character #
        return -6 if import file has too less lines (import file must have at least 3 characters
        return -7 if there is error decode command line
*/

int ContourCalculation::ImportObjectFromFile(wxString path,wxString &obj_name,wxString &obj_des,wxString &er_message)
{
      if(real_object_number>999)
      {
          er_message=_("Maximal object number was reached");
          return -1; //Maximal number of objects is 999
      }

  wxTextFile fileex;

      if(!fileex.Open(path))
      {
          er_message=_("Error open file:");
          er_message+=path;
          return -2; //Error open file
      }

    int cmd_typex,cmd_operand,cmd_iresult;
    int cmd_param[2],cmd_iparam[2];
    float cmd_fparam[2];
    wxString cmd_sparam[2];
    wxString cmd_des,cmd_sresult,str;

   int pos=0;
   int ret=0;
   int number_lines=fileex.GetLineCount()-2;


   if(number_lines<3)
   {
       er_message.Printf(_("Too less line in file.(It must be at least 3).Actual number:%d"),number_lines);
       return -6; // Too less line. Import must have at least 2 lines
   }


for ( unsigned i=0;i< fileex.GetLineCount();i++)
{
     if(i==0)str=fileex.GetFirstLine();
     else str=fileex.GetNextLine();

    if(i==0)
    {
       int new_pos=FindObjectName(str);
       if(new_pos>-1)
       {
           er_message=_(" Object name is already in program: Name:");
           er_message+=str;
           return -3; // new name is already used use another name
       }
       pos=real_object_number;
       real_object_number++;
       if(str.Find('#')!=wxNOT_FOUND)
       {
           er_message=_("Object name can not contain character #:Object name:");
           er_message+=str;
           return -4; //Name can not contain character #
       }
       object_calculation[pos].name=str;
       obj_name=str;

    }
    else if(i==1)
    {
       if(str.Find('#')!=wxNOT_FOUND)
       {
           object_calculation[pos].name=_("");
          object_calculation[pos].description=_("");
           object_calculation[pos].number=0;

           er_message=_(" Object description can not contain letter #.Object description:");
           er_message+=str;
           return -5; //DEscription can not conitain character #
       }
       object_calculation[pos].description=str;
       obj_des=str;
       object_calculation[pos].number=number_lines;
       object_calculation[pos].command=new OBJECT_COMMAND[number_lines];
    }
    else
    {
       ret=CheckLine(str,cmd_typex,cmd_des,cmd_param[0],cmd_iparam[0],cmd_fparam[0],cmd_sparam[0],cmd_param[1],cmd_iparam[1],cmd_fparam[1],cmd_sparam[1],cmd_operand,cmd_iresult,cmd_sresult);
       if(ret!=0)
       {
           object_calculation[pos].name=_("");
          object_calculation[pos].description=_("");
           object_calculation[pos].number=0;
           er_message.Printf(_("Error import file line:%d. Error code:%d"),i-1,ret);
           return -7; //Error decode line
       }
       else
       {
          object_calculation[pos].command[i-2].type=cmd_typex;
       object_calculation[pos].command[i-2].description= cmd_des;
        object_calculation[pos].command[i-2].param1=cmd_param[0];
       object_calculation[pos].command[i-2].i_param1=cmd_iparam[0];
       object_calculation[pos].command[i-2].f_param1=cmd_fparam[0];
       object_calculation[pos].command[i-2].s_param1=cmd_sparam[0];
        object_calculation[pos].command[i-2].param2=cmd_param[1];
       object_calculation[pos].command[i-2].i_param2=cmd_iparam[1];
       object_calculation[pos].command[i-2].f_param2=cmd_fparam[1];
       object_calculation[pos].command[i-2].s_param2=cmd_sparam[1];
        object_calculation[pos].command[i-2].operand=cmd_operand;
       object_calculation[pos].command[i-2].i_result=cmd_iresult;
       object_calculation[pos].command[i-2].s_result=cmd_sresult;
       }
    }

}



    return 0;
}
