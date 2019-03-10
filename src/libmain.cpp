#include "libmain.h"
GLOB_ELI_CLASS eli_class;

#if defined(__UNIX__)
#  define EXPORTIT

#elif (__WINDOWS__)

#  define EXPORTIT __declspec( dllexport )


BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD  fdwReason,LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:

            /* Init Code here */

            break;
        case DLL_THREAD_ATTACH:
            break;
        case DLL_THREAD_DETACH:

            break;

       case DLL_PROCESS_DETACH:

            /* Cleanup code here */

            break;

    }

    /* The return value is used for successful DLL_PROCESS_ATTACH */

        return TRUE;

}
#endif

extern "C"
{
  EXPORTIT int EliOpenProgram(wxString path)
  {
      int ret=eli_class.OpenProgram(path);

      return ret;
  }
  EXPORTIT int EliOpenProgramCh(char *pathx)
  {
      int ret=eli_class.OpenProgramCh(pathx);

      return ret;
  }

  EXPORTIT int EliSetSystemVariable(int pos,float variabl)
  {
      int ret=eli_class.SetSystemVariable(pos,variabl);

      return ret;
  }

  EXPORTIT int EliGetSystemVariable(int pos,float *fval)
  {
      float fv=0;
      int ret=eli_class.GetSystemVariable(pos,fv);
      fval=&fv;
      return ret;
  }

  EXPORTIT int EliRunProgram(void)
  {
      int ret=eli_class.RunProgram();

      return ret;
  }

  EXPORTIT int EliRunProgramFromLine(int line)
  {
      int ret=eli_class.RunProgramFromLine(line);

      return ret;
  }

  EXPORTIT void EliEndRunFromLine(void)
  {
      eli_class.EndRunFromLine();
  }

  EXPORTIT wxString EliGetErrorString(void)
  {
      wxString retstr=eli_class.GetErrorString();
      return retstr;
  }

  EXPORTIT int EliGetErrorStringCh(int max_len,char *er_str)
  {
      int ret=eli_class.GetErrorStringCh(max_len,er_str);
      return ret;
  }

  EXPORTIT int EliGetStringVariable(int pos,wxString *sval)
  {
      wxString wxval;
      int ret=eli_class.GetStringVariable(pos,wxval);
      *sval=wxval;
      return ret;
  }

  EXPORTIT int EliGetStringVariableCh(int pos,int max_len,char *valx)
  {
      int ret=eli_class.GetStringVariableCh(pos,max_len,valx);
      return ret;
  }

  EXPORTIT int EliGetNumberOfAllObjects(void)
  {
      return eli_class.GetNumberOfAllObjects();
  }

  EXPORTIT int EliGetObjectsParametersName(int pos,wxString *namex)
  {
     wxString wxval;
     int ret=eli_class.GetObjectsParametersName(pos,wxval);
    *namex=wxval;
     return ret;
  }

  EXPORTIT int EliGetObjectsParametersNameCh(int pos,int max_len,char *namex)
  {
      int ret=eli_class.GetObjectsParametersNameCh(pos,max_len,namex);
      return ret;
  }

  EXPORTIT int EliGetNumberObjectsName(wxString namex)
  {
      int ret=eli_class.GetNumberObjectsName(namex);
      return ret;
  }

  EXPORTIT int EliGetNumberObjectsNameCh(char *namex)
  {
      int ret=eli_class.GetNumberObjectsNameCh(namex);
      return ret;
  }

  EXPORTIT int EliGetObjectParameter(wxString namex,int pos,std::vector<int> &ival,std::vector<double> &dval)
  {
      int ret=eli_class.GetObjectParameter(namex,pos,ival,dval);
      return ret;
  }
/**
Function for get object parameters which does not use vector (for C language)
1.parameter: namex: object name
2.parameter:max_len: maximal length size for alocation ival and dval pointer
3.parameter: pos: position in object structure
4.parameter: num_ival: number of integer values in ival
5.parameter: ival: INTEGER value pointer
6.parameter: num_dval: number og double values in dval
7.parameter: dval: DOUBLE value pointer
Function return 0 if not object with same name as 1.parameter as found
         return -1 if 2.parameter is out of range
         return -2 if Size returned vector is more than max_len
        return 1 if type of returned parameters id INTEGER
        return 2 if type of returned parameters ids double

**/
  EXPORTIT int EliGetObjectparameterC(char *namex,int max_len,int pos,int *num_ival,int *ival,int *num_dval,double *dval)
  {
      std::vector<int> ixval;
      std::vector<double> dxval;

      wxString nam = wxString::FromUTF8(namex);

      int ret=eli_class.GetObjectParameter(nam,pos,ixval,dxval);
      if(ret < 0)
      {
        *num_ival=ixval.size();
        *num_dval=dxval.size();
        if(ixval.size()>max_len)return -2; //
        if(dxval.size()>max_len)return -2; //Size returned vector is more than max_len
        for(unsigned i=0;i<ixval.size();i++) ival[i]=ixval[i];
        for(unsigned i=0;i<dxval.size();i++)dval[i]=dxval[i];
      }

      return ret;
  }
}


/*
Function must be called in loading library
*/
void GLOB_ELI_CLASS::InitAll(void)
{
    init_number=18934;
tp_prg=new TestProgram(); // Inicialize test program class
      run_tpg=NULL;
      ob_prg=new ObjectPrograms;
       InitMainCommands();//Call function for inicialize pointer cmd which is filled command classes
       error_string=wxEmptyString;
       for(unsigned i=0;i<100;i++)syst_variables[i]=0;
       for(unsigned i=0;i<10;i++)string_variables[i]=wxEmptyString;
       all_obj.clear();
}

/*
Function must be called in detach of library
*/
void GLOB_ELI_CLASS::CloseAll(void)
{
    if(init_number==18934)
    {
      DeleteMainCommands(); // call function which delete commands pointers from memory (function is placed in commands_main.cpp)
    delete ob_prg;
    delete tp_prg;
    init_number=0;
    }

}

/**
Function opens test program from file in input parameters
1.parameter: Test program file path in wxString
Function return 0 if all is ok
         return -1 if there is initial error (Error will display in error message)
         return -2 if there is run error (Error can be read in function GetErrorString)
**/
int GLOB_ELI_CLASS::OpenProgram(wxString path)
{
    if(init_number!=18934)
    {
        ErrorLog er;
   wxString mystring=_("InitAll function was not called");
   er.SetError(_("InitAll function was not called"),mystring);
   er.DisplayLog(1);
   return -1;
    }

    delete tp_prg;
    tp_prg=new TestProgram();
    int ret_val=tp_prg->OpenProgram(path,ob_prg);

      if(ret_val !=0)
     {
         error_string.Printf(_("Error Open Test program\nError code:%d"),ret_val);
         return -2;
     }
    return 0;
}
/**
Function set system variables with some value
1.parameter: variable position range <0..99>
2.parameter: float variable value
Function return 0 if all is ok
         return -1 if there is initial error (Error will display in error message)
         return -2 if there is run error (Error can be read in function GetErrorString)
**/
int GLOB_ELI_CLASS::SetSystemVariable(int pos,float variabl)
{
      if(init_number!=18934)
    {
        ErrorLog er;
   wxString mystring=_("InitAll function was not called");
   er.SetError(_("InitAll function was not called"),mystring);
   er.DisplayLog(1);
   return -1;
    }

    if((pos<0)||(pos>99))
    {
       error_string.Printf(_("Position of system variable must be from range <0..99>, Set position is:%d"),pos);
         return -2;
    }

   syst_variables[pos]=variabl;

    return 0;
}
/**
Function get actual value of system variables
1.parameter: variable position range <0..99>
2.parameter: reference float variable value
Function return 0 if all is ok
         return -1 if there is initial error (Error will display in error message)
         return -2 if there is run error (Error can be read in function GetErrorString)
**/
int GLOB_ELI_CLASS::GetSystemVariable(int pos,float &fval)
{
     if(init_number!=18934)
    {
        ErrorLog er;
   wxString mystring=_("InitAll function was not called");
   er.SetError(_("InitAll function was not called"),mystring);
   er.DisplayLog(1);
   return -1;
    }

    if((pos<0)||(pos>99))
    {
       error_string.Printf(_("Position of system variable must be from range <0..99>, Set position is:%d"),pos);
         return -2;
    }

   fval=syst_variables[pos];

    return 0;
}
/**
Function run complete test program form start line to the end line  and close test program
Function return 0 if all is ok
         return -1 if there is initial error (Error will display in error message)
         return -2 if there is run error (Error can be read in function GetErrorString)

**/
int GLOB_ELI_CLASS::RunProgram(void)
{


  if(init_number!=18934)
    {
     ErrorLog er;
   wxString mystring=_("InitAll function was not called");
   er.SetError(_("InitAll function was not called"),mystring);
   er.DisplayLog(1);
   return -1;
    }
      if(run_tpg!=NULL) delete run_tpg;
     run_tpg=new RunTestProgram(cmd);

     for(unsigned i=0;i<100;i++)run_tpg->SetSystemVariable(i,syst_variables[i]);  // Set system variables

int ret=run_tpg->RunProgram(tp_prg,cmd,1,ob_prg,0);

if(ret==0) //Run program ok
{
     if((run_tpg->GetResultPicturePosition()>=0)&&(run_tpg->GetResultPicturePosition()<20))
        {
         result_img=run_tpg->GetResultPicture() ;
        }
      for(unsigned i=0;i<100;i++)syst_variables[i]=run_tpg->GetSystemVariable(i);  // Set system variables
      run_tpg->GetAllObjects(all_obj);
      for(unsigned i=0;i<10;i++)string_variables[i]=run_tpg->GetStringVariables(i);

      delete run_tpg;
        run_tpg=NULL;
}
else
{
     wxString cd=_("Fail in line ");
     cd<<run_tpg->GetNumberExecutedLines();
     cd+= _(", error code :");
     cd<<ret;
     error_string=cd;
     delete run_tpg;
       run_tpg=NULL;
     return -2;
}

    return 0;
}
/**
Function run c test program form some speciefied  line to the end line but program
is not closed (function can be call again in cycle). For close program function EndRunFromLine(void)
must be called
1.parameter: line number of line from where test program should be start
Function return 0 if all is ok
         return -1 if there is initial error (Error will display in error message)
         return -2 if there is run error (Error can be read in function GetErrorString)

**/
int GLOB_ELI_CLASS::RunProgramFromLine(int line)
{


  if(init_number!=18934)
    {
     ErrorLog er;
   wxString mystring=_("InitAll function was not called");
   er.SetError(_("InitAll function was not called"),mystring);
   er.DisplayLog(1);
   return -1;
    }

   if(run_tpg==NULL) run_tpg=new RunTestProgram(cmd);



     for(unsigned i=0;i<100;i++)run_tpg->SetSystemVariable(i,syst_variables[i]);  // Set system variables

int ret=run_tpg->RunProgram(tp_prg,cmd,line,ob_prg,0);

if(ret==0) //Run program ok
{
     if((run_tpg->GetResultPicturePosition()>=0)&&(run_tpg->GetResultPicturePosition()<20))
        {
         result_img=run_tpg->GetResultPicture() ;
        }
      for(unsigned i=0;i<100;i++)syst_variables[i]=run_tpg->GetSystemVariable(i);  // Set system variables
      // Get Objects
      run_tpg->GetAllObjects(all_obj);
        for(unsigned i=0;i<10;i++)string_variables[i]=run_tpg->GetStringVariables(i);
}
else
{
     wxString cd=_("Fail in line ");
     cd<<run_tpg->GetNumberExecutedLines();
     cd+= _(", error code :");
     cd<<ret;
     error_string=cd;
     delete run_tpg;
       run_tpg=NULL;
     return -2;
}

    return 0;
}
/**
Function close test program which should be called
in function RunProgramFromLine(int line)
**/
void GLOB_ELI_CLASS::EndRunFromLine(void)
{
    if(run_tpg!=NULL)
    {
      delete run_tpg;
       run_tpg=NULL;
    }
}
/**
Function gets string value of system variable
1.parameter: pos. System variable string position range <0..9>
2.parameter: sval: returned variable string
Function return 0 if all is ok
         return -1 if there is initial error (Error will display in error message)
         return -2 if there is run error (Error can be read in function GetErrorString)
**/
int GLOB_ELI_CLASS::GetStringVariable(int pos,wxString &sval)
{
     if(init_number!=18934)
    {
        ErrorLog er;
   wxString mystring=_("InitAll function was not called");
   er.SetError(_("InitAll function was not called"),mystring);
   er.DisplayLog(1);
   return -1;
    }

    if((pos<0)||(pos>9))
    {
       error_string.Printf(_("Position of system variable must be from range <0..9>, Set position is:%d"),pos);
         return -2;
    }

   sval=string_variables[pos];

    return 0;
}
/**
Function opens test program from file in input parameters.
This function has input parameter in char * format (if user does not use wxWidgets)
1.parameter: Test program file path in char *
Function return 0 if all is ok
         return -1 if there is initial error (Error will display in error message)
         return -2 if there is run error (Error can be read in function GetErrorString)
**/
int GLOB_ELI_CLASS::OpenProgramCh(char *pathx)
{

    wxString wxpathx = wxString::FromUTF8(pathx);
    int ret=OpenProgram(wxpathx);

    return ret;
}

/**
Function gets string value of system variable. Returned string is in char format
for user which does not use wxWidgets
1.parameter: pos. System variable string position range <0..9>
2.parameter: max_len:Maximal expected length of returned string
3.parameter: sval: returned variable string (char*)
Function return 0 if all is ok
         return -1 if there is initial error (Error will display in error message)
         return -2 if there is run error (Error can be read in function GetErrorString)
         return -3 if returned string variable has more characters as number in parameter 2
**/
int GLOB_ELI_CLASS::GetStringVariableCh(int pos,int max_len,char *valx)
{
    wxString wxval;
int ret=GetStringVariable(pos,wxval) ;
if(wxval.Length()>max_len) return -3;
strcpy(valx,wxval.mb_str());

return ret;
}

/**
Function gets error string in case of run error (return -2 in other functions)
Returned string is in char format for user which does not use wxWidgets
1.parameter: max_len Maximal expected length of returned string
2.parameter: er_str: error string in char format
unction return 0 if all is ok
        return -1 if returned string variable has more characters as number in parameter 1
**/
int  GLOB_ELI_CLASS::GetErrorStringCh(int max_len,char *er_str)
{
    if(error_string.Length()>max_len)return -1;
  strcpy(er_str,error_string.mb_str());

  return 0;
}

/**
Function show name of object parameters according position number
1.parameter: pos: position nuber range < 1..29>
2.parameter: namex: name of object parameter
Function return o if all is ok
         return -1 if parameter 1 is not from range <1..29>
**/
int GLOB_ELI_CLASS::GetObjectsParametersName(int pos,wxString &namex)
{
    if((pos<1)||(pos>29))return -1;
    if(pos==1)namex=_("Bounding rectangle X");
    if(pos==2)namex=_("Bounding rectangle Y");
    if(pos==3)namex=_("Bounding rectangle Height");
    if(pos==4)namex=_("Bounding rectangle Width");
    if(pos==5)namex=_("Perimeter");
    if(pos==6)namex=_("Contour area");
    if(pos==7)namex=_("Minimal area rectangle X");
    if(pos==8)namex=_("Minimal area rectangle Y");
    if(pos==9)namex=_("Minimal area rectangle Height");
    if(pos==10)namex=_("Minimal area rectangle Width");
    if(pos==11)namex=_("Minimal area rectangle Angle");
    if(pos==12)namex=_("Minimal enclosing circle center X");
    if(pos==13)namex=_("Minimal enclosing circle center Y");
    if(pos==14)namex=_("Minimal enclosing circle Radius");
    if(pos==15)namex=_("Fit ellipse center X");
    if(pos==16)namex=_("Fit ellipse center Y");
    if(pos==17)namex=_("Fit ellipse Height");
    if(pos==18)namex=_("Fit ellipse Width");
    if(pos==19)namex=_("Fit ellipse Angle");
    if(pos==20)namex=_("Derived 0");
    if(pos==21)namex=_("Derived 1");
    if(pos==22)namex=_("Derived 2");
    if(pos==23)namex=_("Derived 3");
    if(pos==24)namex=_("Derived 4");
    if(pos==25)namex=_("Derived 5");
    if(pos==26)namex=_("Derived 6");
    if(pos==27)namex=_("Derived 7");
    if(pos==28)namex=_("Derived 8");
    if(pos==29)namex=_("Derived 9");

    return 0;
}
/**
Function show name of object parameters according position number in char format
1.parameter: pos: position nuber range < 1..29>
2.parameter:max_len: Maximal expected length of returned string
3.parameter: namex: name of object parameter in char format
Function return 0 if all is ok
         return -1 if parameter 1 is not from range <1..29>
         return -2 if number of characters in returned string is more than 2.parameter
**/
int GLOB_ELI_CLASS::GetObjectsParametersNameCh(int pos,int max_len,char *namex)
{
    wxString nam;

    if(GetObjectsParametersName(pos,nam)!=0) return -1;
       if(nam.Length()>max_len)return -2;
  strcpy(namex,nam.mb_str());


    return 0;
}

/**
Function return number of found objects according name
1.parameter: namex: name of object which number we want to count
Function return number of found objects
**/
int GLOB_ELI_CLASS::GetNumberObjectsName(wxString namex)
{
    int cnt=0;
    for(unsigned i=0;i<all_obj.size();i++)if(namex==all_obj[i].object_name)cnt++;

    return cnt;
}

/**
Function return number of found objects according name in char format
1.parameter: namex: name of object which number we want to count CHAR format
Function return number of found objects
**/
int GLOB_ELI_CLASS::GetNumberObjectsNameCh(char *namex)
{
   wxString nam = wxString::FromUTF8(namex);
   int ret=GetNumberObjectsName(nam);

    return ret;
}

/**
Function Get found object parameters according object name
1.parameter: namex: name of object
2.parameter: pos: object parameter range <1..29>
3.parameter:ival: vector with parameter of all objects in name according parameter 1 in INTEGER
3.parameter:dval: vector with parameter of all objects in name according parameter 1 in DOUBLE

Function return 0 if not object with same name as 1.parameter as found
        return -1 if 2.parameter is out of range
        return 1 if type of returned parameters id INTEGER
        return 2 if type of returned parameters ids double
**/
int GLOB_ELI_CLASS::GetObjectParameter(wxString namex,int pos,std::vector<int> &ival,std::vector<double> &dval)
{
  int ret=0;

  ival.clear();
  dval.clear();

   if((pos<1)||(pos>29))return -1;

  for(unsigned i=0;i<all_obj.size();i++)
  {
    if(namex==all_obj[i].object_name)
    {

    switch (pos)
    {
    case 1:
       ival.push_back(all_obj[i].bounding_rect_x);
        ret=1;
        break;
    case 2:
        ival.push_back(all_obj[i].bounding_rect_y);
        ret=1;
        break;
    case 3:
        ival.push_back(all_obj[i].bounding_rect_height);
        ret=1;
        break;
    case 4:
        ival.push_back(all_obj[i].bounding_rect_width);
        ret=1;
        break;
    case 5:
        dval.push_back(all_obj[i].perimeter);
        ret=2;
        break;
    case 6:
         dval.push_back(all_obj[i].contour_area);
        ret=2;
        break;
    case 7:
        ival.push_back(all_obj[i].min_area_rect_x);
        ret=1;
        break;
    case 8:
        ival.push_back(all_obj[i].min_area_rect_y);
        ret=1;
        break;
    case 9:
        ival.push_back(all_obj[i].min_area_rect_height);
        ret=1;
        break;
    case 10:
        ival.push_back(all_obj[i].min_area_rect_width);
        ret=1;
        break;
    case 11:
        dval.push_back(all_obj[i].min_area_rect_angle);
        ret=2;
        break;
    case 12:
        ival.push_back(all_obj[i].min_enclosing_circle_center_X);
        ret=1;
        break;
     case 13:
        ival.push_back(all_obj[i].min_enclosing_circle_center_Y);
        ret=1;
        break;
    case 14:
        dval.push_back(all_obj[i].min_enclosing_circle_radius);
        ret=2;
        break;
     case 15:
        ival.push_back(all_obj[i].fit_elipse_center_X);
        ret=1;
        break;
     case 16:
        ival.push_back(all_obj[i].fit_elipse_center_Y);
        ret=1;
        break;
      case 17:
        ival.push_back(all_obj[i].fit_elipse_height);
        ret=1;
        break;
       case 18:
        ival.push_back(all_obj[i].fit_elipse_width);
        ret=1;
        break;
      case 19:
       dval.push_back(all_obj[i].fit_elipse_angle);
        ret=2;
       break;
       case 20:
       dval.push_back(all_obj[i].derived[0]);
        ret=2;
       break;
       case 21:
       dval.push_back(all_obj[i].derived[1]);
        ret=2;
       break;
       case 22:
       dval.push_back(all_obj[i].derived[2]);
        ret=2;
       break;
       case 23:
       dval.push_back(all_obj[i].derived[3]);
        ret=2;
       break;
       case 24:
       dval.push_back(all_obj[i].derived[4]);
        ret=2;
       break;
       case 25:
       dval.push_back(all_obj[i].derived[5]);
        ret=2;
       break;
       case 26:
       dval.push_back(all_obj[i].derived[6]);
        ret=2;
       break;
       case 27:
       dval.push_back(all_obj[i].derived[7]);
        ret=2;
       break;
       case 28:
       dval.push_back(all_obj[i].derived[8]);
        ret=2;
       break;
       case 29:
       dval.push_back(all_obj[i].derived[9]);
        ret=2;
       break;
    }


    }
  }

  return ret;
}
