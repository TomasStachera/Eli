#include "libmain.h"

GLOB_ELI_CLASS eli_class;

extern "C"
{
    // A function adding two integers and returning the result
    int SampleAddInt(int i1, int i2)
    {
        return i1 + i2;
    }

    // A function doing nothing ;)
    void SampleFunction1()
    {
        // insert code here
    }

    // A function always returning zero
    int SampleFunction2()
    {
        // insert code here

        return 0;
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
1.parameter: Test program file path
Function return 0 if all is ok
         return -1 if there is error in function OpenProgram
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
         return -1;
     }
    return 0;
}

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
         return -1;
    }

   syst_variables[pos]=variabl;

    return 0;
}

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
         return -1;
    }

   fval=syst_variables[pos];

    return 0;
}

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
      // Get Objects

      delete run_tpg;
}
else
{
     wxString cd=_("Fail in line ");
     cd<<run_tpg->GetNumberExecutedLines();
     cd+= _(", error code :");
     cd<<ret;
     error_string=cd;
     delete run_tpg;
     return -1;
}

    return 0;
}
