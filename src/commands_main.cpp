#include "eliMain.h"
#include <wx/utils.h>
#include <wx/log.h>
#include <wx/msgdlg.h>
#include <new>

using namespace std;

#define MAXIMAL_FILTER_LINES 100
#define MAXIMAL_OBJECTS_LINES 1000
#define MAXIMAL_OBJECT_TEST_PROGRAM_LINES  400




/**********************************************************************

All commands class must be inicialize in this function . Commands in one
group must be together step by step. Position of classes in this
function will be same as position in command list box.
**********************************************************************/
void INIT_CMD::InitMainCommands(void)
{
int i=0;
 try
 {
  cmd[i++]=new System_Macro;
  cmd[i++]=new System_Jump;
  cmd[i++]=new System_Math;
  cmd[i++]=new System_Results;
  cmd[i++]=new System_Wait;
  cmd[i++]=new Source_OpenFile;
  cmd[i++]=new Source_ReadCamera;
  cmd[i++]=new Source_ReadVideo;
  cmd[i++]=new Source_QueryFrame;
  cmd[i++]=new Source_CaptureProperty;
  cmd[i++]=new Source_CloneImage;
  cmd[i++]=new Source_SaveImage;
  cmd[i++]=new Source_CreateVideoFile;
  cmd[i++]=new Source_WriteVideoFrame;
  cmd[i++]=new Source_GetPictureParam;
  cmd[i++]=new Conversion_Color;
  cmd[i++]=new Conversion_Scale;
  cmd[i++]=new Conversion_Roi;
  cmd[i++]=new Conversion_AddWeighted;
  cmd[i++]=new Conversion_MaskPicture;
  cmd[i++]=new Conversion_Threshold;
  cmd[i++]=new Conversion_AdaptThresh;
  cmd[i++]=new Conversion_FloodFill;
  cmd[i++]=new Conversion_Morfology;
  cmd[i++]=new Conversion_Edge;
  cmd[i++]=new Conversion_Smooth;
  cmd[i++]=new Conversion_EqualHist;
  cmd[i++]=new Conversion_Resize;
  cmd[i++]=new Conversion_RotateFlip;
  cmd[i++]=new Conversion_Canny;
  cmd[i++]=new Conversion_Corners;
  cmd[i++]=new Conversion_Invert;
  cmd[i++]=new Contours_Find;
  cmd[i++]=new Contours_Draw;
  cmd[i++]=new Object_Find;
  cmd[i++]=new Object_Draw;
  cmd[i++]=new Object_Count;
  cmd[i++]=new Object_ToChar;
  cmd[i++]=new Object_CharToString;
   cmd[i++]=new Object_Labels;
   cmd[i++]=new Object_ParamMath;
 }

catch(bad_alloc &ba)
{
ErrorLog er;
wxString mystring(ba.what(), wxConvUTF8);
er.SetError(_("Bad alloc new exception "),mystring);
er.DisplayLog(1);
}
}

/*************************************************************************
Function from class eliFrame placed in eliMain.h
Function is called when program is close and main window is delete.
Function delete pointers for all commands classes from memory.
**************************************************************************/
void INIT_CMD::DeleteMainCommands(void)
{
for(int i=0;i<NUMBER_COMMANDS_CLASS;i++) delete cmd[i];
}

/************************************************************************/

/************************************************************************
Constructor of class ErrorLog
This class is use for display error messages
************************************************************************/
ErrorLog::ErrorLog(void)
{
type=_("");
mes=_("");
}

/************************************************************************
Function SetError is use for set error messages.
Function has 2 parameters. The first parameter is type of error message
for example "Open Program error". Next parameter is error message
************************************************************************/
void ErrorLog::SetError(wxString type_,wxString mes_)
{
   type=type_;
   mes=mes_;
}

/************************************************************************
Function display error , display error mesage.
It can be 2 types of error messages. The first is DIsplay error message
with function parameter 0 or without parameter (0 is default). The second
option is parameter 1. This parameter display Fatal erro message.
************************************************************************/
void ErrorLog::DisplayLog(int tp)
{
if(tp==0) wxLogError(wxT("%s : %s"),type.c_str(),mes.c_str());
if(tp==1) wxLogFatalError(wxT("%s : %s"),type.c_str(),mes.c_str());
}

/**************************************************************************
 Test program
 **************************************************************************/

/**************************************************************************
Constructor class TestProgram
Constructor inicialize structure PRG which is use for store all test program
lines with command  name and parameters. Maximal number of test program
lines can be 5000.
**************************************************************************/
 TestProgram::TestProgram(void)
 {
try{
   p1=new PRG[5000];

   for(int i=0;i<5000;i++)
   {
       p1[i].line=0;
       p1[i].br=false;
   }
   line_numberx=0;
 line_numberx2=0;
}
catch(bad_alloc &ba)
{
ErrorLog er;
wxString mystring(ba.what(), wxConvUTF8);
er.SetError(_("Bad alloc new exception "),mystring);
er.DisplayLog(1);
}
 }

/***********************************************************************
Destructor for class TestProgram
Destructor delete PRG structure from memory
***********************************************************************/
 TestProgram::~TestProgram(void)
 {
    delete[] p1;
 }

/*********************************************************************
Function SetProgram is use for set one program line with parameters to
PRG structure
Function has 3 input patameters. The first parameter is test program
line number, second is complete command with command name and parameter
The last parameter is selection if is set new program line or is edit
line which was set before. Parameter 0 is use if command is new, non 0
means edit command.
Function return 0 if SetProgram is OK.
Function return -1 if total activated
line in test program is more than 4999 ( which is maximal posible lines
in test program).
Function return -2 in cycle error (selected line is not found in PRG structure)

*********************************************************************/
 int TestProgram::SetProgram(int line,wxString cmd,int nw)
{
    if(line_numberx2>4999) return -1; //too many commands

if(nw==0) // new command
{

  if(line<=line_numberx)
  {
   int i=0;
   while(p1[i].line!=0) // find first non activated line
   {
     if(p1[i].line>=line) p1[i].line++;
     i++;
     if(i==4999) return -2; // Bad cycle error
   }
  }

   p1[line_numberx2].line=line;
   p1[line_numberx2].cmd=cmd.BeforeFirst('#'); // Set command name
   p1[line_numberx2].param=cmd.AfterFirst('#');// Set comand parameters
   line_numberx++;
   line_numberx2++;
}
else
{
   int i=0;
   while(p1[i].line!=line)
   {
     i++;
     if(i==4999) return -2; // Bad cycle error
   }
    p1[i].cmd=cmd.BeforeFirst('#');
   p1[i].param=cmd.AfterFirst('#');
}

 return 0;
}

/***************************************************************
Function return command name according first input parameter which is
test program line. Function has aslo second  parameter which is start
of position in PRG structure.If second parameter is not set parameter is 0
 If test line is not found in PRG structure
function retrun string ERROR
***************************************************************/
wxString TestProgram::GetCmd(int line,int first_i)
{
  int i=first_i;
   if(i>=4999) return _("ERROR");
  while(p1[i].line!=line)
  {
    i++;
    if(i==4999) return _("ERROR");
  }
  return p1[i].cmd.BeforeFirst(' ');
}

/***************************************************************
Function return description of command according first input parameter which is
test program line. Function has aslo second  parameter which is start
of position in PRG structure.If second parameter is not set parameter is 0
 If test line is not found in PRG structure
function retrun string ERROR
***************************************************************/
wxString TestProgram::GetDescription(int line,int first_i)
{
  int i=first_i;
   if(i>=4999) return _("ERROR");
  while(p1[i].line!=line)
  {
    i++;
    if(i==4999) return _("ERROR");
  }


  return p1[i].cmd.AfterFirst(' ');
}

/*******************************************************************
Function return Command parameter according test program line which
is set as first input parameter. Function has aslo second  parameter which
is start of position in PRG structure.If second parameter is not set
,parameter is 0. If test program line is not found in
PRG structure function return string ERROR
******************************************************************/
wxString TestProgram::GetParam(int line,int first_i)
{
  int i=first_i;
   if(i>=4999) return _("ERROR");
  while(p1[i].line!=line)
  {
    i++;
    if(i==4999) return _("ERROR");
  }
  return p1[i].param;
}

/******************************************************************
Function delete test program line from PRG structure. Deleted line
is input parameter of this function.
Function return 0 if delete line is OK
Function return -1 if line is not found in PRG structure
Function return -2 in cycle error
******************************************************************/

int TestProgram::DeleteLine(int line)
{
  int i=0;
  while(p1[i].line !=line) // find line in PRG structure
  {
     i++;
     if(i==4999) return -1; //Cycle error line not found
  }
  int pom=p1[i].line;
  p1[i].line=-1; // set to delete line line number -1, which means deleted line
   i=0;
  while(p1[i].line !=0) //all lines higher than deleted line are decrease
  {
      if(p1[i].line>pom) p1[i].line--;
    i++;
     if(i==4999) return -2; //Cycle error next line
  }
  line_numberx--;// decrease number of active lines
  return 0;
}


/***************************************************************************
Function is use for copy block of commands
Function copy block of commands before selected line. Block of commands
are copied to the next line after selected.
Function has 3 input parameters. The first is selected line after this
block of commands will be copied.The second parameter is line number start
of bloack and last parameter is line number end of block
Function return 0 if function is OK
Function return -2 if any not activate line was found
Function return -3 if there is error during copy some block line
***************************************************************************/
 int TestProgram::CopyBlockProgram(int line,int start,int end)
 {
   int dif=end-start+1;

      int i=0;
   while(p1[i].line!=0)
   {
     if(p1[i].line>line) p1[i].line=p1[i].line+dif;
     i++;
     if(i==4999) return -2; // Bad cycle error
   }

   for(int j=0;j<dif;j++)
   {
       int c=0;
      while(p1[c].line!=(start+j))
    {
     c++;
     if(c==4999) return -3; // cycle error
    }
    p1[line_numberx2].cmd=p1[c].cmd;
    p1[line_numberx2].param=p1[c].param;
    p1[line_numberx2].line=line+j+1;
    line_numberx2++;
   }
   line_numberx=line_numberx+dif;
     return 0;
 }

/****************************************************************
Function save test program from PRG structure test program file
Function has 2 input parameters.
The first is path for save file
The second parameter is test name of test program
Function return 0 if Save program function is OK
Function return -1 if test program path has bad extension (must be .eli)
Function return -2 if there is error durring open file

****************************************************************/

 int TestProgram::SaveProgram(wxString path,ObjectPrograms *op)
{
     wxString chck=path.AfterLast('.');
    if(chck!=_("eli")) return -1; //bad file extension
  file=new wxFile();
  if(!file->Open(path,wxFile::write))
  {
     file->Close();
     delete file;
     return -2; // error save file
  }
  if(tName!=wxEmptyString)
  {
      file->Write(_("/**\n"));
      file->Write(tName);// write test name to the first line of test program file
       file->Write(_("\n**/\n"));
  }
  //file->Write(wxTextFile::GetEOL());//Add line end

  wxString prk;

  for(int i=0;i<line_numberx;i++)
  {
      prk=GetCmd(i+1);
      if(GetDescription(i+1)!=wxEmptyString)
      {
          prk+=_(" ");
          prk+=GetDescription(i+1);
      }
      prk+=_("#");
      prk+=GetParam(i+1);
      file->Write(prk); // Write one command with parameters to one line
     file->Write(wxTextFile::GetEOL());//add line end
  }
  op->WriteObjectToTestProgram(file);

  file->Close();
     delete file;
 return 0;
}

/****************************************************************************
Functio open test program file and set all commands lines to PRG structure.
Function has one input parameter which is path of test program file which we want open.
Function return 0 if OpenProgram function is OK
Function return -1 if open program has bad extension (must be .eli)
Function return -2 if selected file not exist
Function return -3 if there is error open test program file
Function return -4 if there is error set program to PRG strcuture
*****************************************************************************/
int TestProgram::OpenProgram(wxString path,ObjectPrograms *op)
{
  wxString chck=path.AfterLast('.');
    if(chck!=_("eli")) return -1; //bad file extension
  file2=new wxTextFile(path);
  if(!file2->Exists())
  {
      delete file2;
       return -2; //File not exist
  }
  if(!file2->Open(path))
  {
     file2->Close();
     delete file2;
     return -3; // error open file
  }


tName=wxEmptyString;
wxString line_prg; //test program line
int ret_cd=0;
bool found_obj=false;
bool active_coments=false;
int line_cnt=0;

 for(unsigned int i=0;i<file2->GetLineCount();i++)
 {
     if(i==0)line_prg=file2->GetFirstLine();
     else line_prg=file2->GetNextLine();


     if(line_prg==_("/**")) active_coments=true;

   if(!active_coments)
   {
    ret_cd=op->ChectNewObject(line_prg);
     if(ret_cd<0)
     {
         ErrorLog er;
         wxString ercd=_("Error code:");
         ercd<<ret_cd;
         er.SetError(_("Error in function ChectNewObject"),ercd);
         er.DisplayLog();

         file2->Close();
         delete file2;
         return -4; //Error Set program

     }
     else if(ret_cd==1) found_obj=true;

    if(found_obj) // Object was found
    {
       ret_cd= op->DecodeTestProgramLine(line_prg);
       if(ret_cd<0)
       {
            wxMessageBox(line_prg,_(""));//added
          ErrorLog er;
         wxString ercd=_("Error code:");
         ercd<<ret_cd;
         er.SetError(_("Error in function DecodeTestProgramLine"),ercd);
         er.DisplayLog();
         file2->Close();
         delete file2;
         return -4; //Error Set program
       }
    }
     else
     {
         line_cnt++;
       if(SetProgram(line_cnt,line_prg)!=0)
     {
         file2->Close();
         delete file2;
         return -4; //Error Set program
     }

     }
   }//ENd active comants
   else
   {
           if((active_coments)&&(line_prg==_("**/"))) active_coments=false;
           else
           {
               if(line_prg!=_("/**"))
               {
                 tName+=line_prg; //Add comments
                tName+=_("\n");
               }

           }
   }


 }

delete file2;
 return 0;
}

/*******************************************************************
Function is use for Set break to specified line in test program
structure.
Function has 2 input parameters.The first is test program line,
second parameter is optional and it is position in test program
structure from where finding start.
Function return 0 if all is OK, return -1 if position in test program
structure is miore than 4999, return -2 if maximal lines in
test program structure is found
*******************************************************************/
int TestProgram::SetBreak(int line,int first_i)
{
       int i=first_i;
   if(i>=4999) return -1;
  while(p1[i].line!=line)
  {
    i++;
    if(i==4999) return -2;
  }
  p1[i].br=true;
    return 0;
}

/*******************************************************************
Function is use for reset break to specified line in test program
structure.
Function has 2 input parameters.The first is test program line,
second parameter is optional and it is position in test program
structure from where finding start.
Function return 0 if all is OK, return -1 if position in test program
structure is miore than 4999, return -2 if maximal lines in
test program structure is found
*******************************************************************/
int TestProgram::ResetBreak(int line,int first_i)
{
       int i=first_i;
   if(i>=4999) return -1;
  while(p1[i].line!=line)
  {
    i++;
    if(i==4999) return -2;
  }
  p1[i].br=false;
    return 0;
}

/*********************************************************************
Function return true if break is set in specified line and false if break
is not set in specified line. Function has 2 input parameter, the frist is
specified line, second is position in test program structure from where
finding will start.
Function return false if selected line was not found in test program
structure.
*********************************************************************/
bool TestProgram::GetBreak(int line,int first_i)
{
     int i=first_i;
   if(i>=4999) return false;
  while(p1[i].line!=line)
  {
    i++;
    if(i==4999) return false;
  }
  return p1[i].br;
}

/*******************************************************************
Function update command parameters in test program structure
Function return true if selected line was find and retuyrn false
if selected line is not found
********************************************************************/
bool TestProgram::UpdateParam(int line,wxString param)
{
    int i=0;

    while(p1[i].line!=line)
    {
        i++;
        if(i==4999) return false;
    }
    p1[i].param=param;

    return true;
}

/***************************************************************************
Class RunTestProgram
***************************************************************************/

RunTestProgram::RunTestProgram(command **cmd)
{
/*
INicialize structure PDAT for stroring test results
INicialize and sets variable in this structure
*/
//delete pd;
pd=new PDAT;
//pd->text1=_("");
pd->OpenCvErrorMes=_("");

pd->results=_("");
pd->pic_pos=-1;
pd->updated_param=_("");
pd->update_param=false;
for(int i=0;i<100;i++)
{
    pd->fval[i]=0;
}
for(int i=0;i<NUMBER_COMMANDS_CLASS;i++) cmd[i]->Inicialize();   // Run function INicialize for reset variables

for(int i=0;i<10;i++)
{

   pd->str_values[i]=wxEmptyString;
}

pd->obj.clear();
num_exec_lines=0; // Set number executed lines to 0
tp2=NULL; // Set pointer for second test program class to NULL
}



RunTestProgram::~RunTestProgram(void)
{

delete pd;

}

/*****************************************************************************
Function RunProgram is used for execution test program
The first parameter is pointer for TestProgram class of actually used test program.
Second parameter is pinter for commands class fields
3.parameter is number start line from where test program should start.When test program
  is started from begin number is 1. For cycle this line can be different like 1
4.parameter is edit mode. If no edit mode is select mode =0 , if debug mode is used mode=1, mode=2 one step command.

Function return 0 if test program finish without error

Function return -1 if command name not found in TestProgram class
Function return -2 if command param not found in Test Progrma class
Function return -3 if Command not found in command class
Function return -4 if line in testprogram structure was not find in update param in test mode
Function return -10 and less if test program command error was found. Return value depends in command error codes
Function return -21 if jump line is less than 0
Function return -22 if jump loine is more than maximal number lines

Macro return codes:
  Function return -11 if Test program structure for macro command already open
  Function return -12 if Error open macro file
  Function return -13 if command not found in test program classes
  Function return -14 if command param not found in Test Progrma class
  Function return -15 if Command not found in command class

Function return 1 if break was found in executed line

******************************************************************************/
int RunTestProgram::RunProgram(TestProgram *tpg,command **cmd,int start_line,ObjectPrograms *op,int mode)
{
    wxString first_par=_(""); // test program name from test program class
    wxString second_par=_(""); //Parameter from test program class
    int end_find=0;// variable is using for find right command in command class field if is 1 command was found
    int cnt=0;  // variable is using for index in command class field
    int ret_value=0; // variable for return value from test program execution
    if(start_line<1)start_line=0; //start line for start cycle is 0
    else
    {
        if(start_line>tpg->GetLineNumber())start_line=tpg->GetLineNumber()-1; //start line is in the end of program
        else start_line=start_line-1; // start line for cycle for is -1 than test program line
    }


        for(int i=start_line;i<tpg->GetLineNumber();i++)
        {
          first_par=tpg->GetCmd(i+1,i); // Get command name ,finding starts from test program line number
          if(first_par==_("ERROR"))
          {
              first_par=tpg->GetCmd(i+1); // get command name, finding start from 0 index
              if(first_par==_("ERROR")) return -1; //command name not found in TestProgram class
          }
          second_par=tpg->GetParam(i+1,i); // get command parameter. findings starts from test program line number
          if(second_par==_("ERROR"))
          {
           second_par=tpg->GetParam(i+1);// get command parameter, findings startsfrom 0 index
              if(second_par==_("ERROR")) return -2;//command param not found in Test Progrma class
          }
          end_find=0;
          cnt=0;
          while(end_find==0)
          {
           if(cmd[cnt]->ReturnClassname()==first_par)end_find=1; // find index of executed command from command class fields
           else cnt++;
           if(cnt>= NUMBER_COMMANDS_CLASS) return -3; //  Command not found in command class
          }

          if(mode==1) // debug mode
          {
              if((start_line+1)!=(num_exec_lines+1))// break is in same line like before
              {
                if(tpg->GetBreak(num_exec_lines+1) )return 1; // break was found in executed line
              }

          }
          num_exec_lines=i+1; // increament number executed lines
          int editx=0; //variable for one step edit mode
          if(mode==2) editx=1; // one step edit mode is executed
          pd->update_param=false;
          ret_value=cmd[cnt]->RunCommand(second_par,pd,num_exec_lines,editx,op); // executed command
          if((editx==1)&&(pd->update_param))
          {
              if(!tpg->UpdateParam(i+1,pd->updated_param)) return -4; //error find line in update parame in test mode
          }

          //if return value from function RunCommand is more than 1 jump was found in selected line
          if(ret_value>1) // JUmp command
          {
              if(ret_value<5001) // jump before
              {
                  if((num_exec_lines-ret_value)<0) return -21; // jump line is less than 0
                  num_exec_lines=num_exec_lines-ret_value; //set number executed line to jump line before
                  i=i-ret_value; // set test program index to jump line before
              }
              else  //jump after
              {
                  // If return value is more than 5001, means jump after
                  int numb= ret_value-5001;// calculate number lines to jump after
                  if((numb+num_exec_lines)>tpg->GetLineNumber()) return -22; // jump loine is more than maximal number lines
                  num_exec_lines=num_exec_lines+numb-1; //set number executed lines to jump after line
                  i=i+numb-1; // set test program index to jump line after
              }
          }
          // If return value is 1 means command is executed macro
          if(ret_value==1)//Run macro
          {
           if(tp2!=NULL)  return -11; // Test program structure for macro command already open
           tp2=new TestProgram; // alocate class for macro test program
           if(tp2->OpenProgram(second_par,op)!=0)return -12; //Error open macro file

            wxString sec_first_par=_(""); // variable for command name
            wxString sec_second_par=_(""); // variable for command param
            for(int sec_i=0;sec_i<tp2->GetLineNumber();sec_i++) // cycle for macro test program
            {
                sec_first_par=tp2->GetCmd(sec_i+1,sec_i); //get command name
               if(sec_first_par==_("ERROR")) return -13; // command not found in test program classes

               sec_second_par=tp2->GetParam(sec_i+1,sec_i); // get command param
              if(sec_second_par==_("ERROR")) return -14;//command param not found in Test Progrma class

              int sec_end_find=0; // variable use for command find in command class field
              int sec_cnt=0; // variable use for index in command class field
             while(sec_end_find==0)
             {
             if(cmd[sec_cnt]->ReturnClassname()==sec_first_par)sec_end_find=1; // find command in command class field
             else sec_cnt++;
               if(sec_cnt>= NUMBER_COMMANDS_CLASS) return -15; //  Command not found in command class
             }
              int sec_ret_value=cmd[sec_cnt]->RunCommand(sec_second_par,pd,sec_i+1,0,op); //execute command
              if(sec_ret_value==1) return -16;// next macro inside macro
              if(sec_ret_value<0) return -17;// macro command error
                if(sec_ret_value>1) // JUmp command
                  {
                 if(sec_ret_value<5001) // jump before
                 {
                  if((sec_i+1-sec_ret_value)<0) return -21; // jump line is less than 0

                  sec_i=sec_i-sec_ret_value; // update actual test program line acording jump before lines
                 }
                 else  //jump after
                 {
                  int sec_numb= sec_ret_value-5001; // get number jumps after
                  if((sec_numb+sec_i+1)>tpg->GetLineNumber()) return -22; // jump line is more than maximal number lines
                  sec_i=sec_i+sec_numb-1;// update actual test program line according jump after lines
                 }
                }
           }
           delete tp2;
           tp2=NULL;
          }

          if(ret_value<0) return (ret_value-10); // return command error
          if(mode==2) // one step mode
          {
              if(num_exec_lines<tpg->GetLineNumber())return 1; // one step mode always break in next line till end line was found
          }
        }


    return 0;
}

/**
Function gets all actual objects found
1.parameter:obj: vector with all objects found
Function return number of all objects
**/
int RunTestProgram::GetAllObjects(vector<OBJECTFOUND> &obj)
{
  int num=0;

  obj.clear();
  if(pd->obj.size()==0) return 0; //No objects found

  for(unsigned i=0;i<pd->obj.size();i++)obj.push_back(pd->obj[i]);
  num=obj.size();

   return num;
}


 void command::SetOpenCVErrorMess(std::string description,std::string file,std::string function,int line,PDAT *pd)
 {
    std::string str=description;
    wxString pv(str.c_str(),wxConvUTF8);
    str=file;
    wxString pv2(str.c_str(),wxConvUTF8);
    pv+=_("\nFile: ");
     pv+=pv2;
     str=function;
     wxString pv3(str.c_str(),wxConvUTF8);
     pv+=_("\nFunction: ");
     pv+=pv3;
     pv+=_("\nLine number: ");
     pv<<line;

     pd->OpenCvErrorMes=pv;
 }


/***************************************
Object program class
***************************************/
ObjectPrograms::ObjectPrograms()
{
actual_obj_numb=0;
actual_index=0;
for(int i=0;i<20;i++)
{
  conobj[i].IsFilter=false;
  conobj[i].filterLine.Clear();
  conobj[i].numb_filter_lines=0;
  conobj[i].num_obj=0;
  for(int j=0;j<MAXIMAL_OBJECTS_LINES;j++)
  {
      conobj[i].obj[j].numbcmd=0;
  }
}
}

ObjectPrograms::~ObjectPrograms()
{

}

/*
Function inserts new object block into test program
Function check according object block number if this object is new or old
Function return 0 if all is ok
         return -1 if there is more than 20 object blocks
         return -2  if object number is not from range 1-20
         return -3 if maximal object number was reached.
*/
int ObjectPrograms::InsertNewObjectBlock(int numb)
{
    if(actual_obj_numb>20) return -1;  //Maximal objects block number is 20
    if(numb<1) return -2; // Object block number must be from 1 to 20
    if(numb>20) return -2; //Object block number must be from 1 to 20
    if(actual_obj_numb>=0)
    {
        bool old_obj=false;
        for(int i=0;i<20;i++)
        {
            if(conobj[i].numb==numb)
            {
               old_obj=true; // old object
              actual_index=i;
            }
        }
        if(!old_obj) // new object
        {
         if(actual_obj_numb==20)  return -3; // Maximal object blocks number
         actual_obj_numb++;
         actual_index= actual_obj_numb-1;
         conobj[actual_index].numb=numb;
        }

            conobj[actual_index].numb_filter_lines=0;
            conobj[actual_index].num_obj=0;
            conobj[actual_index].filterLine.Clear();

    }

    return 0;
}

/*
Function check one line in test program file for OBJECTBLOCK part
INput parameter is one line in test program
Function return 0 if any OBJECTBLOCK PART was found;
FUnction return 1 if OBJECTBLOCK part was found
Function   return -1 if there is more than 20 object blocks
         return -2  if object number is not from range 1-20
         return -3 if maximal object number was reached.

*/

int ObjectPrograms::ChectNewObject(wxString line)
{
    bool found=false;

    if(line==_("OBJECTBLOCK_1")) found=true;
    if(line==_("OBJECTBLOCK_2")) found=true;
    if(line==_("OBJECTBLOCK_3")) found=true;
    if(line==_("OBJECTBLOCK_4")) found=true;
    if(line==_("OBJECTBLOCK_5")) found=true;
    if(line==_("OBJECTBLOCK_6")) found=true;
    if(line==_("OBJECTBLOCK_7")) found=true;
    if(line==_("OBJECTBLOCK_8")) found=true;
    if(line==_("OBJECTBLOCK_9")) found=true;
    if(line==_("OBJECTBLOCK_10")) found=true;
    if(line==_("OBJECTBLOCK_11")) found=true;
    if(line==_("OBJECTBLOCK_12")) found=true;
    if(line==_("OBJECTBLOCK_13")) found=true;
    if(line==_("OBJECTBLOCK_14")) found=true;
    if(line==_("OBJECTBLOCK_15")) found=true;
    if(line==_("OBJECTBLOCK_16")) found=true;
    if(line==_("OBJECTBLOCK_17")) found=true;
    if(line==_("OBJECTBLOCK_18")) found=true;
    if(line==_("OBJECTBLOCK_19")) found=true;
    if(line==_("OBJECTBLOCK_20")) found=true;

    if(!found)return 0;
    else
    {
        int numb=wxAtoi(line.AfterFirst('_'));
        int ret_code=InsertNewObjectBlock(numb);
        if(ret_code==0)return 1;
        else return ret_code;
    }
}

/*
Function decode line in  test program according input parameter
If line in test program is in OBJECTBLOCK part line is add to the structure.
Function return 0 if all is OK
        return -1 if line is not in OBJECTBLOCK part
        return -2; if maximal number of objects was reached.
        return -3  if maximal filter lines was reached
        return -4; if maximal object test program lines was reached
*/
int ObjectPrograms::DecodeTestProgramLine(wxString line)
{
 int type=0;
 int obj_ind=0;
 wxString px;


  if(line.BeforeFirst('#')==_("FILTER")) type=1; // Filter line
  if(line.BeforeFirst('#')==_("OBJECT")) type=2;  //Object line
  if(line.BeforeFirst('#')==_("TOBJECT")) type=3;  // Object test program line

  if(type==0) return 0; // Any object test program line was found

  switch(type)
  {
      case 1:
        conobj[actual_index].IsFilter=true;
        conobj[actual_index].filterLine.Add(line.AfterFirst('#'));
        conobj[actual_index].numb_filter_lines++;
        if(conobj[actual_index].numb_filter_lines==MAXIMAL_FILTER_LINES+1)
        {
          conobj[actual_index].numb_filter_lines=MAXIMAL_FILTER_LINES;
          return -3; // Maximal filter lines was reached
        }
       break;
      case 2:
      obj_ind=conobj[actual_index].num_obj;
      px=line.AfterFirst('#');
        conobj[actual_index].obj[obj_ind].name=px.BeforeFirst('#');
       conobj[actual_index].obj[obj_ind].description=px.AfterFirst('#');
        conobj[actual_index].obj[obj_ind].numbcmd=0;
        conobj[actual_index].obj[obj_ind].command.Clear();
        conobj[actual_index].num_obj++;
        if(conobj[actual_index].num_obj==MAXIMAL_OBJECTS_LINES+1)
        {
         conobj[actual_index].num_obj=MAXIMAL_OBJECTS_LINES;
         return -2; // Maximal object number was reached
        }
      break;
      case 3:
        obj_ind=conobj[actual_index].num_obj-1;
         conobj[actual_index].obj[obj_ind].command.Add(line.AfterFirst('#'));
         conobj[actual_index].obj[obj_ind].numbcmd++;
         if(conobj[actual_index].obj[obj_ind].numbcmd==MAXIMAL_OBJECT_TEST_PROGRAM_LINES+1)
         {
          conobj[actual_index].obj[obj_ind].numbcmd= MAXIMAL_OBJECT_TEST_PROGRAM_LINES;
          return -4; // maximal object test program lines was reached
         }
      break;
      default:
       break;
  }

    return 0;
}
/*
Function return index according object blocks number.
Function return -1 if any object with selected number was found
*/
 int ObjectPrograms::GetIndexAccordingNumber(int nub)
 {
     int ind=-1;

        for(int i=0;i<20;i++)
        {
            if(conobj[i].numb==nub) ind=i;

        }

     return ind;
 }

/*
Function gets filter line parameters
1.parameter is index in CONTOUROBJECT structure
2.parameter is reference to number of filter line
3.parameter is reference for array of filter lines
Function return false if filter is not active
Function return true and inserts reference for input parameters
*/
 bool ObjectPrograms::ReturnFilterParam(int ind,int &filter_lines,wxArrayString &ar_lines)
 {
     if(ind<0)return false;
     if(ind>19) return false;
     if(conobj[ind].IsFilter==false)return false;
     ar_lines.Clear();
     filter_lines=conobj[ind].numb_filter_lines;
     for(int i=0;i<filter_lines;i++)ar_lines.Add(conobj[ind].filterLine[i]);

     return true;
 }

/*
Function gets object programs parameters with all lines
1.parameter is index in CONTOUROBJECT structure
2.parameter is object index
3.parameter is reference for object name
4.parameter is reference for object description
5.parameter is reference for number of line in object testprogram
6.parameter is reference for array of test program lines
Function return 0 if all is OK
         return -1 if index for CONTOUROBJECT structure is out of range
         return -2  if object index is out of range
         return -3  if no line was found in object structure
*/
 int ObjectPrograms::ReturnObjectProgram(int ind,int obj_ind,wxString &name,wxString &desc,int &numb_lines,wxArrayString &lines)
 {

 if((ind<0)||(ind>19))return -1; // index for CONTOUROBJECT structure is out of range
 if(obj_ind<0) return -2; // object index is out of range
 if(conobj[ind].num_obj<=obj_ind) return -2; // object index is out of range

 int obj_lines=conobj[ind].obj[obj_ind].numbcmd;
 if(obj_lines<=0) return -3; //No lines in object tes program
 numb_lines=obj_lines;

 name=conobj[ind].obj[obj_ind].name;
 desc=conobj[ind].obj[obj_ind].description;
 lines.Clear();
 for(int i=0;i<obj_lines;i++)
 {
  lines.Add(conobj[ind].obj[obj_ind].command[i]);
 }

     return 0;
 }

/*
Function Write Objects from CONTOUROBJECT structure to the test program file in input parameter
Function return 0 if all is ok
         return -1 if No object in CONTOUROBJECTSTRUCTURE
         return -2 if Too many OBJECT blocks
         return -3 if no object was found
         return -4 if no test program lines in object was found
*/
 int ObjectPrograms::WriteObjectToTestProgram(wxFile *file)
 {
if(actual_obj_numb<=0) return -1;  // No object in CONTOUROBJECTSTRUCTURE
if(actual_obj_numb>19) return -2; // Too many OBJECT blocks

wxString oneline;

for(int i=0;i<actual_obj_numb;i++)
{
  oneline=_("");
  oneline=_("OBJECTBLOCK_");
  oneline<<conobj[i].numb;

  file->Write(oneline);
  file->Write(wxTextFile::GetEOL());//Add line end

  if(conobj[i].IsFilter)  //Is filter activated
  {
      for(int j=0;j<conobj[i].numb_filter_lines;j++)
      {
       oneline=_("");
      oneline=_("FILTER#");
      oneline+= conobj[i].filterLine[j];
      file->Write(oneline);
      file->Write(wxTextFile::GetEOL());//Add line end
      }

  }
  if(conobj[i].num_obj<=0) return -3; // No objects
  for(int j=0;j<conobj[i].num_obj;j++)
  {
      if(conobj[i].obj[j].numbcmd<=0) return -4; // No test program lines in the object
      oneline=_("");
      oneline=_("OBJECT#");
      oneline+=conobj[i].obj[j].name;
      oneline+=_("#");
      oneline+=conobj[i].obj[j].description;
        file->Write(oneline);
      file->Write(wxTextFile::GetEOL());//Add line end

      for(int x=0;x<conobj[i].obj[j].numbcmd;x++)
      {
        oneline=_("");
      oneline=_("TOBJECT#");
      oneline+= conobj[i].obj[j].command[x];
      file->Write(oneline);
      file->Write(wxTextFile::GetEOL());//Add line end
      }

  }


}

     return 0;
 }


