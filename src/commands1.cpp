#include "commands1.h"
#include<wx/msgdlg.h>

/************************************************************************************
Class System_Macro
This class is use for execute macro commands. Macro is .eli program which is executed
inside next .eli program. Macro can use all commands , only macro command inside macro
file is prohibeted.
************************************************************************************/


/*************************************************************************************************
Function return parameter in command grid lines. This command use only one line for select
macro file
**************************************************************************************************/
int System_Macro::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
if(line<0)return -1;
if(line>1) return -2;
if(line==0)
{
       name=wxT("Select macro file");
        type=1;
        #if defined(__WXMSW__)
        str=wxT("C:\\");
      #elif defined(__UNIX__)
        str=wxT("/home");
       #endif

        type2=1;
}

    return 0;
}

/***********************************************************************************
FUnction for run Macro command. Function just return 1 and program run class according
return value 1 execute macro command.
************************************************************************************/
 int System_Macro::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
    //   pd->text1+=_("Execute System_Macro\n");
     return 1; //Run macro command
 }
/************************************************************************************/

/************************************************************************************
Constructor class System Jump. Set active and number jumps to 0
**************************************************************************************/
System_Jump::System_Jump(void)
{
for(int i=0;i<30;i++)
{
    active_jumps[i]=0;
    numb_jumps[i]=0;
}
}

int System_Jump::Inicialize(void) //Function is call before start test program
{
   for(int i=0;i<30;i++)
{
    active_jumps[i]=0;
    numb_jumps[i]=0;
}

    return 0;
}


/************************************************************************************
Function return parameter in command grid lines. This command use when is selected
System_Jump command
*************************************************************************************/
int System_Jump::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
if(line<0)return -1;
if(line>12) return -2; //Maximal line for command grid is 12
   if(line==0)// combo box for jump direction
    {
        name=wxT("Jump direction");
        type=2;
        wxArrayString arraystr;
        arraystr.Add(wxT("Before"));
        arraystr.Add(wxT("After"));
        aray_str=arraystr;
        type2=0;
    }
    if(line==1) // number box for set number line where command must jump
    {
        name=wxT("Jump line from command");
        type=4;
        ival=0;
    }
    if(line==2)//number box for set maximal jumps
    {
        name=wxT("Maximal jumps");
        type=4;
        ival=1;
    }

    if(line==3) // combobox for select end condition
    {
        name=wxT("Jumps end number");
        type=2;
        wxArrayString arraystr;
        arraystr.Add(wxT("Fixted"));
        arraystr.Add(wxT("End_condition"));
        aray_str=arraystr;
        type2=0;
    }

    if(line==4) // combobox for sets variable which will be in 1. condition
    {
        name=wxT("Condition 1 left");
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

     if(line==5) //combobox for select sign in condition 1
    {
        name=wxT("Condition 1 sign");
        type=2;
        wxArrayString arraystr;
        arraystr.Add(wxT("less"));
        arraystr.Add(wxT("more"));
        arraystr.Add(wxT("equal"));
         arraystr.Add(wxT("NOT equal"));
        aray_str=arraystr;
        type2=0;
    }

      if(line==6)//combobox for select variable for condition 1 right
    {
        name=wxT("Condition 1 right");
        type=2;
        wxArrayString arraystr;
        arraystr.Add(_("Number"));
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

    if(line==7) // number box for set condition 1 number
    {
       name=_("Condition 1 right number");
        type=5;
        fval=0.0;
    }

      if(line==8)//combobox for set if condition i is using and what type
    {
        name=wxT("Condition 2");
        type=2;
        wxArrayString arraystr;
        arraystr.Add(wxT("Not_used"));
        arraystr.Add(wxT("And"));
        arraystr.Add(wxT("Or"));
        aray_str=arraystr;
        type2=0;
    }

      if(line==9) //combobox for selection variable for condition 2 left
    {
        name=wxT("Condition 2 left");
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

     if(line==10) //combobox for set condition 2 sign
    {
        name=wxT("Condition 2 sign");
        type=2;
        wxArrayString arraystr;
        arraystr.Add(wxT("less"));
        arraystr.Add(wxT("more"));
        arraystr.Add(wxT("equal"));
        arraystr.Add(wxT("NOT equal"));
        aray_str=arraystr;
        type2=0;
    }

      if(line==11)// combobox for set condition 2 right variable
    {
        name=wxT("Condition 2 right");
        type=2;
        wxArrayString arraystr;
        arraystr.Add(_("Number"));
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

    if(line==12) //number box for set condition 2 right number
    {
       name=_("Condition 2 right number");
        type=5;
        fval=0.0;
    }

    return 0;
}

/***********************************************************************************
Function for run System_Jump comand.
Function return -2 if maximal number jumps was set . Maximal number active jumps is 30.
         return -3 if jump position field error is found
         return 0 if no jump lines was found or maximal jumps was found
         return >1 and return <5001  jump before (number lines = return value)
         return >5001, jump after (number lines= 5001-return value)
         return -4 variable 1 bad index number
         return -5 variable 2 bad index number
         return -6 variable 3 bad index number
         return -7 variable 4 bad index number
         return -10 jump command error.
************************************************************************************/
 int System_Jump::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
     /*
     direction = derection of jump  Before/ After
     jump_cond= jumps end condition Fixted (number of jumps before is fixted defined in maximal jumps number)/
                End_condition (if direction is Before: if condition 1 (2) is true command jump to next line, if false jumps to line before
                               if direction is After: if condition 1 (2) is true command jumps to line after, if false jumps to next line
     cond1_l = left variable in condition 1 (Variable_0...99)
     cond1_s = condition 1 sign less/more/equal
     cond1_r = right variable or number in condition 1 (Number/Variable_0...99)
     cond2 = if condition 2 is used if yes if logical function with condition 1 is And or Or: Option are Not_used,And,Or
     cond2_l = left variable in condition 2 (Variable_0..99)
     cond2_s = condition 2 sign less/more/equal
     cond2_r = right variable or number in condition 2 (Number/Variable_0.99)
     */
     wxString direction,jumps_cond,cond1_l,cond1_s,cond1_r,cond2,cond2_l,cond2_s,cond2_r;

     /*
     jump_lines = number of line before or after jumps command where program should jump
     max_jumps = number of maximal jumps
     */
     int jump_lines=0,max_jumps=0;
     /*
     cond1_number= right number in condition 1
     cond2_number= left number in condition 2
     */
     float cond1_number=0,cond2_number=0;
     double dxx;
      // pd->text1+=_("Execute System_Jump\n");

       wxString pom=_("");

       direction=param.BeforeFirst('#');
       pom=param.AfterFirst('#');
       jump_lines=wxAtoi(pom.BeforeFirst('#'));
       pom=pom.AfterFirst('#');
       max_jumps=wxAtoi(pom.BeforeFirst('#'));
       pom=pom.AfterFirst('#');
       jumps_cond=pom.BeforeFirst('#');
       pom=pom.AfterFirst('#');
       cond1_l=pom.BeforeFirst('#');
       pom=pom.AfterFirst('#');
       cond1_s=pom.BeforeFirst('#');
       pom=pom.AfterFirst('#');
       cond1_r=pom.BeforeFirst('#');
       pom=pom.AfterFirst('#');
       pom.BeforeFirst('#').ToCDouble(&dxx);
       cond1_number=(float)dxx;
       pom=pom.AfterFirst('#');
       cond2=pom.BeforeFirst('#');
       pom=pom.AfterFirst('#');
       cond2_l=pom.BeforeFirst('#');
       pom=pom.AfterFirst('#');
       cond2_s=pom.BeforeFirst('#');
       pom=pom.AfterFirst('#');
       cond2_r=pom.BeforeFirst('#');
       pom.AfterFirst('#').ToCDouble(&dxx);
       cond2_number=(float)dxx;
         if(jump_lines<0) jump_lines=jump_lines*(-1);
       int pos=-1;
      for(int i=0;i<30;i++) if(active_jumps[i]==line) pos=i; // jumps in line is already active
      if(pos==-1)
      {
          for(int i=0;i<30;i++)
          {
              if((active_jumps[i]==0)&&(pos==-1))
              {
                  pos=i;
                  active_jumps[i]=line;
              }
          }
      }
      if(pos==-1) return -2; //maximal number active jumps can be 30
      if((pos<0)||(pos>30)) return -3; // jumps position field error
      numb_jumps[pos]++;
      if(numb_jumps[pos]==(max_jumps+1))
      {
          numb_jumps[pos]=0;
          active_jumps[pos]=0;
          return 0; //maximal jumps was found
      }

      if(jump_lines==0)return 0; // no jump line

      if(jumps_cond==_("Fixted")) // fixted jump number
      {
        if(direction==_("Before")) return jump_lines+1; // jump before jump comand
        if(direction==_("After")) //jump after jump command
        {
            numb_jumps[pos]=0;
          active_jumps[pos]=0;
            return jump_lines+5001; // jump after jump command
        }
      }
      if(jumps_cond==_("End_condition")) // end condition is used
      {
          bool b_end1=false,b_end2=false,b_end_tot=false;// b_end1 result condition 1, b_end2= result condition 2, b_end_tot=total result condition 1 and condition 2
          int v1=wxAtoi(cond1_l.AfterFirst('_'));
          if(v1<0) return -4; // variable 1 bad index number
          if(v1>99) return -4; //variable 1 bad index number
          float f1=pd->fval[v1];
          float f2=0;
         if(cond1_r==_("Number")) f2=cond1_number; // second variable in condition 2 is fixted number
         else
         {
             int v2=wxAtoi(cond1_r.AfterFirst('_'));
             if(v2<0) return -5; //variable 2 bad index number
             if(v2>99) return -5; //variable 2 bad index number
            f2=pd->fval[v2];
         }
         if(cond1_s==_("less")) // variable 1< variable 2
         {
             if(f1<f2)b_end1=true;
             else b_end1=false;
         }
          if(cond1_s==_("more")) //variable1 > variable 2
         {
             if(f1>f2)b_end1=true;
             else b_end1=false;
         }

          if(cond1_s==_("equal")) // variable 1 == variable 2
         {
             if(f1==f2)b_end1=true;
             else b_end1=false;
         }

           if(cond1_s==_("NOT equal")) // variable 1 == variable 2
         {
             if(f1!=f2)b_end1=true;
             else b_end1=false;
         }

         if(cond2==_("Not_used")) //condition2 is not used
         {
             if(direction==_("Before"))
             {
                 if(b_end1==true)
                 {
                  numb_jumps[pos]=0;
                  active_jumps[pos]=0;
                  return 0;
                 }
                 else return jump_lines+1; // jump before jump comand
             }
           if(direction==_("After"))
           {
            numb_jumps[pos]=0;
            active_jumps[pos]=0;
            if(b_end1==true)return jump_lines+5001; // jump after jump command
            else return 0;
            }
         }
         else // condition 2 is used
         {
            int v3=wxAtoi(cond2_l.AfterFirst('_'));
          if(v3<0) return -6; // variable 3 bad index number
          if(v3>99) return -6; //variable 3 bad index number
          float f3=pd->fval[v3];
          float f4=0;

             if(cond2_r==_("Number")) f4=cond2_number;
            else
            {
             int v4=wxAtoi(cond2_r.AfterFirst('_'));
             if(v4<0) return -7; //variable 4 bad index number
             if(v4>99) return -7; //variable 4 bad index number
            f4=pd->fval[v4];
             }

               if(cond2_s==_("less"))
              {
             if(f3<f4)b_end2=true;
             else b_end2=false;
              }
             if(cond2_s==_("more"))
             {
             if(f3>f4)b_end2=true;
             else b_end2=false;
             }

              if(cond2_s==_("equal"))
             {
             if(f3==f4)b_end2=true;
             else b_end2=false;
             }

               if(cond2_s==_("NOT equal"))
             {
             if(f3!=f4)b_end2=true;
             else b_end2=false;
             }

             if(cond2==_("And"))
             {
                 if((b_end1)&&(b_end2)) b_end_tot=true;
                 else b_end_tot=false;
             }
             if(cond2==_("Or"))
             {
                if((b_end1)||(b_end2)) b_end_tot=true;
                else b_end_tot=false;
             }

             if(direction==_("Before"))
             {
                 if(b_end_tot==true)
                 {
                  numb_jumps[pos]=0;
                  active_jumps[pos]=0;
                  return 0;
                 }
                 else return jump_lines+1; // jump before jump comand
             }
            if(direction==_("After"))
            {
            numb_jumps[pos]=0;
            active_jumps[pos]=0;
            if(b_end_tot==true)return jump_lines+5001; // jump after jump command
            else return 0;
             }

         }
      }

     return -10; //Jump command error
 }
/***************************************************************************************
***************  System math class *****************************************************
****************************************************************************************/



int System_Math::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
    if(line<0)return -1;
    if(line>4) return -2;// Maximal number of lines is 4
    if(line==0) // combobox with all variables
    {
        name=wxT("Variable A");
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
    if(line==1) // combobox with all operators
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
     if(line==2) // combobox for all variables
    {
        name=wxT("Variable B");
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

    if(line==3) // text box for set fixted number
    {
        name=_("Variable B constant number");
        type=5;
        fval=0.0;
    }
    if(line==4)// Combo box for all variables
    {
        name=wxT("Result to");
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

 int System_Math::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
   //  pd->text1+=_("Execute System_Math\n");
     float varA=0, varB=0; // varA= variable A, varB variable B
     double dxx;
     /*
     oper=0 error bad operator
     oper=1 +
     oper=2 -
     oper=3 *
     oper=4 /
     oper=5 cos
     oper=6 sin
     oper=7 tan
     oper=8 acos
     oper=9 asin
     oper=10 atan
     oper=11 atan2
     oper=12 cosh
     oper=13 sinh
     oper=14 tanh
     oper=15 exp
     oper=16 ln
     oper=17 log10
     oper=18 A^B
     oper=19 sqrt A
     oper=20 fabs A
     oper=21 fmod A,B
     if(oper>21) error
     if(oper<1) error
     */
     int oper=0;
     wxString pom,pom2;
     pom=param.BeforeFirst('#');
     pom2=param.AfterFirst('#');
     int posA=wxAtoi(pom.AfterFirst('_'));
     if((posA<0)||(posA>99)) return -1; //Bad variable A
     varA=pd->fval[posA];
     pom=pom2.BeforeFirst('#');
     pom2=pom2.AfterFirst('#');
     /* Finding operator */
     if(pom==wxT("+"))oper=1;
     if(pom==wxT("-"))oper=2;
     if(pom==wxT("*"))oper=3;
     if(pom==wxT("/"))oper=4;
     if(pom==wxT("cos(A)"))oper=5;
     if(pom==wxT("sin(A)"))oper=6;
     if(pom==wxT("tan(A)"))oper=7;
     if(pom==wxT("acos(A)"))oper=8;
     if(pom==wxT("asin(A)"))oper=9;
     if(pom==wxT("atan(A)"))oper=10;
     if(pom==wxT("atan2(A,B)"))oper=11;
     if(pom==wxT("cosh(A)"))oper=12;
     if(pom==wxT("sinh(A)"))oper=13;
     if(pom==wxT("tanh(A)"))oper=14;
     if(pom==wxT("exp(A)"))oper=15;
     if(pom==wxT("ln(A)"))oper=16;
     if(pom==wxT("log10(A)"))oper=17;
     if(pom==wxT("A^B"))oper=18;
     if(pom==wxT("sqrt(A)"))oper=19;
     if(pom==wxT("fabs(A)"))oper=20;
     if(pom==wxT("fmod(A,B)"))oper=21;
     if((oper<1)||(oper>21)) return -2; //Bad operator
     pom=pom2.BeforeFirst('#');
     pom2=pom2.AfterFirst('#');
     if(pom==_("Number"))
     {
     pom2.BeforeFirst('#').ToCDouble(&dxx);
     varB=(float)dxx;
     }
     else
     {
         int posB=wxAtoi(pom.AfterFirst('_'));
         if((posB<0)||(posB>99))return -3; // Bad variable B
         varB=pd->fval[posB];
     }
     int posR=wxAtoi(pom2.AfterFirst('#').AfterFirst('_'));
     if((posR<0)||(posR>99)) return -4; //Bad result variable

     switch (oper)
     {
         case 1:
           pd->fval[posR]=varA+varB;
          break;
         case 2:
           pd->fval[posR]=varA-varB;
          break;
         case 3:
            pd->fval[posR]=varA*varB;
           break;
         case 4:
            if(varB==0) return -5; //devided by zero
            pd->fval[posR]=varA/varB;
           break;
         case 5:
            pd->fval[posR]=cos(varA);
           break;
         case 6:
           pd->fval[posR]=sin(varA);
           break;
         case 7:
           pd->fval[posR]=tan(varA);
          break;
         case 8:
         if((varA<-1)||(varA>1)) return -6; //variable A out of range
           pd->fval[posR]=acos(varA);
          break;
         case 9:
          if((varA<-1)||(varA>1)) return -6; //variable A out of range
            pd->fval[posR]=asin(varA);
           break;
         case 10:
            pd->fval[posR]=atan(varA);
           break;
         case 11:
           pd->fval[posR]=atan2(varA,varB);
           break;
         case 12:
           pd->fval[posR]=cosh(varA);
           break;
         case 13:
           pd->fval[posR]=sinh(varA);
          break;
         case 14:
         pd->fval[posR]=tanh(varA);
          break;
         case 15:
           pd->fval[posR]=exp(varA);
           break;
         case 16:
         if(varA<=0)return -6; //variable A out of range
            pd->fval[posR]=log(varA);
           break;
         case 17:
         if(varA<=0)return -6; //variable A out of range
            pd->fval[posR]=log10(varA);
           break;
         case 18:
           pd->fval[posR]=pow(varA,varB);
           break;
         case 19:
           if(varA<0)return -6; //variable A ou of range
           pd->fval[posR]=sqrt(varA);
          break;
         case 20:
           pd->fval[posR]=fabs(varA);
          break;
         case 21:
            pd->fval[posR]=fmod(varA,varB);
           break;
          default:
            break;
     }


     return 0;
 }

/*************************************************************************************
Class System_Results
************************************************************************************/


int System_Results::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
if(line<0)return -1;
if(line>9) return -2;//maximal number line is 7
if(line==0) //sets combobox for choosing picture which will be display
{
     name=wxT("Displayed picture");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        arraystr.Add(_("None"));
        for(int i=0;i<20;i++)
        {
           pom=_("Picture_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;

}

if((line==1)||(line==3)||(line==5)) // testbox for result name
{
    name=wxT("Result name");
    type=1;
    str=wxT(" ");
    type2=0;
}
if((line==2)||(line==4)) // combobox for choose variable which will be display
{
           name=wxT("Result variable");
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
        for(int i=0;i<10;i++)
        {
           pom=_("String_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
}



if(line==6)
{
        name=wxT("Object Parameter");
        type=2;
        wxArrayString arraystr;
        arraystr.Add(_("None"));
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

if(line==7)
{
    name=wxT("Object name");
    type=1;
    str=wxT(" ");
    type2=0;
}

  if(line==8)
{
        name=wxT("Unit");
        type=2;
        wxArrayString arraystr;
        arraystr.Add(_("pixels"));
        arraystr.Add(_("mm"));

        aray_str=arraystr;
        type2=0;
}

      if(line==9)
    {
         name=wxT("Undistortion chan");
         type=2;
        wxArrayString arraystr;
        wxString pom;
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

bool System_Results::GetObjectVal(PDAT *pd,wxString obj_name,wxString parameterx,bool milim,int uch,vector<float> &fxval)
{
      int par_type=0;
      fxval.clear();

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
  try
  {
   float valxf=0;

        if(pd->obj.size()==0)return false;


         for(unsigned int i=0;i<pd->obj.size();i++)
          {
           if(obj_name==pd->obj[i].object_name)
           {
               switch(par_type)
               {
                   case 1: //Rectifier X
                    if(!milim) valxf=(float)pd->obj[i].bounding_rect_x;
                    else valxf=(float)(pd->obj[i].bounding_rect_x/pd->pix_per_mm[uch]);

                   break;
                   case 2: //Rectifier Y
                    if(!milim) valxf=(float)pd->obj[i].bounding_rect_y;
                    else valxf=(float)(pd->obj[i].bounding_rect_y/pd->pix_per_mm[uch]);
                   break;
                   case 3://Rectifier height
                    if(!milim) valxf=(float)pd->obj[i].bounding_rect_height;
                    else valxf=(float)(pd->obj[i].bounding_rect_height/pd->pix_per_mm[uch]);
                   break;
                   case 4://Rectifier width
                    if(!milim) valxf=(float)pd->obj[i].bounding_rect_width;
                    else valxf=(float)(pd->obj[i].bounding_rect_width/pd->pix_per_mm[uch]);
                   break;
                   case 5: //Perimeter
                    if(!milim) valxf=(float)pd->obj[i].perimeter;
                    else valxf=(float)(pd->obj[i].perimeter/pd->pix_per_mm[uch]);
                   break;
                   case 6: //Area
                   if(!milim) valxf=(float)pd->obj[i].contour_area;
                   else valxf=(float)(pd->obj[i].contour_area/pd->pix_per_mm[uch]);
                   break;
                   case 7://Minimal rectifier X
                     if(!milim) valxf=(float)pd->obj[i].min_area_rect_x;
                     else valxf=(float)(pd->obj[i].min_area_rect_x/pd->pix_per_mm[uch]);
                   break;
                   case 8://Minimal rectifier Y
                    if(!milim) valxf=(float)pd->obj[i].min_area_rect_y;
                    else valxf=(float)(pd->obj[i].min_area_rect_y/pd->pix_per_mm[uch]);
                   break;
                   case 9://Minimal rectifier height
                    if(!milim) valxf=(float)pd->obj[i].min_area_rect_height;
                    else valxf=(float)(pd->obj[i].min_area_rect_height/pd->pix_per_mm[uch]);
                   break;
                   case 10://Minimal rectifier width
                    if(!milim) valxf=(float)pd->obj[i].min_area_rect_width;
                    else valxf=(float)(pd->obj[i].min_area_rect_width/pd->pix_per_mm[uch]);
                   break;
                   case 11: //Minimal rectifier angle
                     valxf=(float)pd->obj[i].min_area_rect_angle;
                   break;
                   case 12://Circle X
                    if(!milim) valxf=(float)pd->obj[i].min_enclosing_circle_center_X;
                    else valxf=(float)(pd->obj[i].min_enclosing_circle_center_X/pd->pix_per_mm[uch]);
                   break;
                   case 13://Circle Y
                   if(!milim) valxf=(float)pd->obj[i].min_enclosing_circle_center_Y;
                    else valxf=(float)(pd->obj[i].min_enclosing_circle_center_Y/pd->pix_per_mm[uch]);
                   break;
                   case 14://Circle radius
                   if(!milim) valxf=(float)pd->obj[i].min_enclosing_circle_radius;
                   else valxf=(float)(pd->obj[i].min_enclosing_circle_radius/pd->pix_per_mm[uch]);
                   break;
                    case 15://Fit elipse center X
                    if(!milim) valxf=(float)pd->obj[i].fit_elipse_center_X;
                    else valxf=(float)(pd->obj[i].fit_elipse_center_X/pd->pix_per_mm[uch]);
                   break;
                   case 16://Fit elipse center Y
                    if(!milim) valxf=(float)pd->obj[i].fit_elipse_center_Y;
                    else valxf=(float)(pd->obj[i].fit_elipse_center_Y/pd->pix_per_mm[uch]);
                   break;
                   case 17://Fit_ellipse_Height
                    if(!milim) valxf=(float)pd->obj[i].fit_elipse_height;
                    else valxf=(float)(pd->obj[i].fit_elipse_height/pd->pix_per_mm[uch]);
                   break;
                    case 18://Fit_ellipse_width
                    if(!milim) valxf=(float)pd->obj[i].fit_elipse_width;
                    else valxf=(float)(pd->obj[i].fit_elipse_width/pd->pix_per_mm[uch]);
                   break;
                   case 19://Fit_ellipse_angle
                    if(!milim) valxf=(float)pd->obj[i].fit_elipse_angle;
                    else valxf=(float)(pd->obj[i].fit_elipse_angle/pd->pix_per_mm[uch]);
                   break;
                   case 20://Derived 0
                    if(!milim) valxf=(float)pd->obj[i].derived[0];
                    else valxf=(float)(pd->obj[i].derived[0]/pd->pix_per_mm[uch]);
                   break;
                   case 21://Derived 1
                    if(!milim) valxf=(float)pd->obj[i].derived[1];
                    else valxf=(float)(pd->obj[i].derived[1]/pd->pix_per_mm[uch]);
                   break;
                   case 22://Derived 2
                    if(!milim) valxf=(float)pd->obj[i].derived[2];
                    else valxf=(float)(pd->obj[i].derived[2]/pd->pix_per_mm[uch]);
                   break;
                   case 23://Derived 3
                    if(!milim) valxf=(float)pd->obj[i].derived[3];
                    else valxf=(float)(pd->obj[i].derived[3]/pd->pix_per_mm[uch]);
                   break;
                   case 24://Derived 4
                    if(!milim) valxf=(float)pd->obj[i].derived[4];
                    else valxf=(float)(pd->obj[i].derived[4]/pd->pix_per_mm[uch]);
                   break;
                   case 25://Derived 5
                    if(!milim) valxf=(float)pd->obj[i].derived[5];
                    else valxf=(float)(pd->obj[i].derived[5]/pd->pix_per_mm[uch]);
                   break;
                   case 26://Derived 6
                    if(!milim) valxf=(float)pd->obj[i].derived[6];
                    else valxf=(float)(pd->obj[i].derived[6]/pd->pix_per_mm[uch]);
                   break;
                   case 27://Derived 7
                    if(!milim) valxf=(float)pd->obj[i].derived[7];
                    else valxf=(float)(pd->obj[i].derived[7]/pd->pix_per_mm[uch]);
                   break;
                   case 28://Derived 8
                   if(!milim) valxf=(float)pd->obj[i].derived[8];
                    else valxf=(float)(pd->obj[i].derived[8]/pd->pix_per_mm[uch]);
                   break;
                   case 29://Derived 9
                    if(!milim) valxf=(float)pd->obj[i].derived[9];
                    else valxf=(float)(pd->obj[i].derived[9]/pd->pix_per_mm[uch]);
                   break;
                   default:
                    return false;
                    break;
               }
               fxval.push_back(valxf);
           }
          }
  }
    catch( cv::Exception& e )
   {
       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return false;
   }
    return true;
}

 int System_Results::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
     //  pd->text1+=_("Execute System_Results\n");
       wxString pom,pom2;
     pom=param.BeforeFirst('#');
     pom2=param.AfterFirst('#');

     if(pom!=_("None"))
     {
      if(pom.BeforeFirst('_')!=_("Picture"))return -1; //Bad picture name
     int pos=wxAtoi(pom.AfterFirst('_'));
     if((pos<0) ||(pos>19)) return -1; // Bad picture name
     pd->pic_pos=pos;
     }
     else pd->pic_pos=-1;
     if(pom2.BeforeFirst('#')!=_(" "))
     {
         pd->results+=pom2.BeforeFirst('#');
         pd->results+=_(" : ");
     }
     pom=pom2.AfterFirst('#');
     if(pom.BeforeFirst('#')!=_("None"))
     {
         if(pom.BeforeFirst('#').BeforeFirst('_')==_("String"))
         {
           int v2=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
          if((v2<0)||(v2>10)) return -2;// Bad variable1 name;
          pd->results+=_("\n");
          pd->results+=pd->str_values[v2];
         }
         else
         {
        if(pom.BeforeFirst('#').BeforeFirst('_')!=_("Variable")) return -2; // Bad variable 1 name
       int v1=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
       if((v1<0)||(v1>99)) return -2;// Bad variable1 name;
       pd->results<<pd->fval[v1];
         }
           pd->results+=_("\n");
     }
     pom2=pom.AfterFirst('#');
      if(pom2.BeforeFirst('#')!=_(" "))
     {
         pd->results+=pom2.BeforeFirst('#');
         pd->results+=_(" : ");
     }
     pom=pom2.AfterFirst('#');
     if(pom.BeforeFirst('#')!=_("None"))
     {
          if(pom.BeforeFirst('#').BeforeFirst('_')==_("String"))
         {
           int v2=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
          if((v2<0)||(v2>10)) return -3;// Bad variable1 name;
           pd->results+=_("\n");
          pd->results+=pd->str_values[v2];
         }
         else
         {
        if(pom.BeforeFirst('#').BeforeFirst('_')!=_("Variable")) return -3; // Bad variable 1 name
       int v2=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
       if((v2<0)||(v2>99)) return -3; //Bad variable 2 name;
       pd->results<<pd->fval[v2];
         }
                pd->results+=_("\n");
     }
     pom2=pom.AfterFirst('#');
     if(pom2.Length()<2)return 0; //Compatibility with versions with no results
     wxString name_of_par;
     if(pom2.BeforeFirst('#')!=_(" "))
     {
         name_of_par=pom2.BeforeFirst('#');

     }
     pom=pom2.AfterFirst('#');
     if(pom.BeforeFirst('#')!=_("None"))
     {
         wxString obj_param=pom.BeforeFirst('#');
         pom=pom.AfterFirst('#');
         wxString obj_name=pom.BeforeFirst('#');
         pom=pom.AfterFirst('#');
         bool milim=false;
         if(pom.BeforeFirst('#')==_("mm"))milim=true;
         else milim=false;
         int unch=wxAtoi(pom.AfterFirst('#').AfterFirst('_'));
         if((unch<0)||(unch>19)) return -4; // Bad undistortion channel
         vector<float> fxval;
         if(!GetObjectVal(pd,obj_name,obj_param,milim,unch,fxval)) return -5; //Error get Object value
         for(unsigned i=0;i<fxval.size();i++)
         {
                pd->results+=name_of_par;
         pd->results+=_(" : ");
         pd->results<<fxval[i];
         pd->results+=_("\n");
         }

     }


     return 0;
 }
/*******************************************************************************/

/*************************************************************************************
Class System_Wait
************************************************************************************/


int System_Wait::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
if(line<0)return -1;
if(line>1) return -2;//maximal number line is 1

    if(line==0) // combobox for all variables
    {
        name=wxT("Delay from");
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

    if(line==1) // text box for set fixted number
    {
        name=_("Delay number[ms]");
        type=5;
        fval=0.0;
    }

return 0;
}

int System_Wait::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
    //  pd->text1+=_("Execute System_Wait\n");
      float delay_numb=0;

      wxString pom=param.BeforeFirst('#');

      if(pom==_("Number"))
      {
      double dxx;
      param.AfterFirst('#').ToCDouble(&dxx);
          delay_numb=(float)dxx;
      }
      else
      {
       int var_pos=wxAtoi(pom.AfterFirst('_'));
       if(var_pos<0) return -1; // Bad variable index
       if(var_pos>99) return -1; // Bad variable index
        delay_numb=pd->fval[var_pos];
      }

     if(delay_numb<0) return -2; // delay niumber is less than 0

     wxMilliSleep((long)delay_numb);


     return 0;
 }

 /********************************************************************************************/


int Source_OpenFile::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
    if(line<0)return -1;
    if(line>4) return -2;
    if(line==0)
    {
    name=wxT("Path to picture file");
        type=1; //file path string type
     #if defined(__WXMSW__)
        str=wxT("C:\\");
      #elif defined(__UNIX__)
        str=wxT("/home");
       #endif
        type2=1;//open file dialog will display
    }
    if(line==1)
    {
        name=wxT("Load file parameter");
        type=2;
        wxArrayString arraystr;
        arraystr.Add(wxT("CV_LOAD_IMAGE_UNCHANGED"));
        arraystr.Add(wxT("CV_LOAD_IMAGE_GRAYSCALE"));
        arraystr.Add(wxT("CV_LOAD_IMAGE_COLOR"));
        arraystr.Add(wxT("CV_LOAD_IMAGE_ANYDEPTH"));
        arraystr.Add(wxT("CV_LOAD_IMAGE_ANYCOLOR"));
        aray_str=arraystr;
    }
    if(line==2)
    {
       name=wxT("Load as picture");
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
       if(line==3)
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
    if(line==4)
    {

        name=_("Size coefficient");
        type=5;
        fval=0.0;

    }


    return 0;
}
/*************************************************************************
Function load picture from file and store it in picture aray
Function for load picture from file use OpenCV function cvLoadImage
**************************************************************************/
 int Source_OpenFile::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
   //  pd->text1+=_("Execute Source_OpenFile\n");
     wxString path,file_param,pom,var_num;
     path=param.BeforeFirst('#');
     pom=param.AfterFirst('#');
     file_param=pom.BeforeFirst('#');
     pom=pom.AfterFirst('#');
     var_num=pom.BeforeFirst('#');
     pom=pom.AfterFirst('#');
    wxString    uchan_str=pom.BeforeFirst('#'); //Undistortion channel string
  float uch_size_coef=wxAtof(pom.AfterFirst('#')); //Size coeficient for specific channel

     int uch=-1; //undistortion channel
   if(uchan_str==_("None"))uch=-1;
   else  uch=wxAtoi(uchan_str.AfterFirst('_'));

      if(!wxFile::Exists(path))return -1; //File not exist
      int i_param=-2;//file parameter init value
      if(file_param==_("CV_LOAD_IMAGE_UNCHANGED"))i_param=-1;
      if(file_param==_("CV_LOAD_IMAGE_GRAYSCALE"))i_param=0;
      if(file_param==_("CV_LOAD_IMAGE_COLOR"))i_param=1;
      if(file_param==_("CV_LOAD_IMAGE_ANYDEPTH"))i_param=2;
      if(file_param==_("CV_LOAD_IMAGE_ANYCOLOR"))i_param=4;
      if(i_param==-2) return -2;//Bad file parameter
      int picture_pos=wxAtoi(var_num.AfterFirst('_'));
      if((picture_pos<0)||(picture_pos>19)) return -3;//Bad picture position number
     try
     {

     pd->imgx[picture_pos]=imread(String(path.mbc_str()),i_param);

         if(uch>-1) //Undistortion channel activated
    {
       if((uch<0)||(uch>19)) return -4; // Bad undistortion channel
        pd->pix_per_mm[uch]=uch_size_coef;
    }

     }
    catch( cv::Exception& e )
   {

       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90;
   }


      return 0;
 }


/******************************************************************************
Class for read capture from camera.
Function open selected camera and read capture
*******************************************************************************/

int Source_ReadCamera::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
         if(line<0)return -1;
    if(line>4) return -2;
    if(line==0)
    {
      name=wxT("Select camera");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=0;i<20;i++)
        {
             pom=_("Video_");
          pom<<i;
          arraystr.Add(pom);
        }

        aray_str=arraystr;
        type2=0;
    }
    if(line==1)
    {
       name=wxT("Select capture");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=0;i<10;i++)
        {
             pom=_("Capture_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
    }
    if(line==2)
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
      if(line==3)
    {
    name=wxT("Calibration file");
        type=1; //file path string type
     #if defined(__WXMSW__)
        str=wxT("C:\\");
      #elif defined(__UNIX__)
        str=wxT("/home");
       #endif
        type2=1;//open file dialog will display
    }

    if(line==4)
    {

        name=_("Size coefficient");
        type=5;
        fval=0.0;

    }


    return 0;
}

 int Source_ReadCamera::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
  // pd->text1+=_("Execute Source_ReadCamera\n");
  // pd->text1+=_("Execute Source_ReadCamera\n");
   int capture_pos=-1;
   int camera=-1;

   wxString pom=param.BeforeFirst('#');

       camera=wxAtoi(pom.AfterLast('_'));

   if(camera<0) return -1; // bad camera index
   if(camera>19)return -1; //bad camera index
    pom=param.AfterFirst('#');
   capture_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));
   pom=pom.AfterFirst('#');


    int uch=-1; //undistortion channel
   if(pom.BeforeFirst('#')==_("None"))uch=-1;
   else  uch=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));
   pom=pom.AfterFirst('#');
   wxString calib_file=pom.BeforeFirst('#');
   double size_coefx;
   pom.AfterFirst('#').ToCDouble(&size_coefx);
   if((capture_pos<0)||(capture_pos>9)) return -2; //bad capture position
   if(uch>19)return -4; // BAd undistortion channel
   if(uch>-1) //read undistortion
   {
          if(pd->cam_calib[uch].SetFileUndistortCalculation(std::string(calib_file.mb_str()),size_coefx)!=0) return -5; //Can not open calibration file

   }
 try
 {

   pd->capture[capture_pos].open(camera);
   if(!pd->capture[capture_pos].isOpened())return -3;
 }
      catch( cv::Exception& e )
   {

       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90;
   }

     return 0;
 }

 /******************************************************************************
Class for read capture from video.
Function open selected video file and read capture
*******************************************************************************/

 int Source_ReadVideo::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
       if(line<0)return -1;
    if(line>5) return -2;

    if(line==0)
    {
        name=wxT("Select source");
        type=2;
        wxArrayString arraystr;
        arraystr.Add(wxT("File"));
        arraystr.Add(wxT("Url"));
           aray_str=arraystr;
        type2=0;
    }
    if(line==1)
    {
        name=wxT("Path to video file");
        type=1; //file path string type
     #if defined(__WXMSW__)
        str=wxT("C:\\");
      #elif defined(__UNIX__)
        str=wxT("/home");
       #endif
        type2=1;//open file dialog will display
    }
    if(line==2)
    {
        name=wxT("Url adress");
        type=1;
        type2=0;
        str=wxT("http://");
    }
    if(line==3)
    {
           name=wxT("Select capture");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=0;i<10;i++)
        {
             pom=_("Capture_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
    }
    if(line==4)
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
    if(line==5)
    {

        name=_("Size coeficient");
        type=5;
        fval=0.0;

    }

    return 0;
}

 int Source_ReadVideo::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
 //  pd->text1+=_("Execute Source_ReadVideo\n");
   wxString v_type=param.BeforeFirst('#'); //source ; video file or url adress
   wxString pom=param.AfterFirst('#');
   wxString path=pom.BeforeFirst('#'); // path to video file
   pom=pom.AfterFirst('#');
   wxString url=pom.BeforeFirst('#'); // url file for IP camera
   pom=pom.AfterFirst('#');
   wxString s_capture=pom.BeforeFirst('#'); //capture field position
   pom=pom.AfterFirst('#');
wxString   uchan_str=pom.BeforeFirst('#'); //Undistortion channel string
 float  uch_size_coef=wxAtof(pom.AfterFirst('#')); //Size coeficient for specific channel

     int uch=-1; //undistortion channel
   if(uchan_str==_("None"))uch=-1;
   else  uch=wxAtoi(uchan_str.AfterFirst('_'));

   int capture_pos=wxAtoi(s_capture.AfterLast('_'));
try
{

    if((capture_pos<0)||(capture_pos>9)) return -1; //bad capture position

    if(v_type==wxT("File")) // video file path
    {
         pd->capture[capture_pos].open(String(path.mbc_str()));
   if(!pd->capture[capture_pos].isOpened())return -2;
    }
    else //url for ip camera
    {
              pd->capture[capture_pos].open(String(url.mbc_str()));
   if(!pd->capture[capture_pos].isOpened())return -2;
    }

    if(uch>-1) //Undistortion channel activated
    {
       if((uch<0)||(uch>19)) return -3; // Bad undistortion channel
        pd->pix_per_mm[uch]=uch_size_coef;
    }

}
     catch( cv::Exception& e )
   {

       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90;
   }

     return 0;
 }


 /******************************************************************************
Class for query frame from video stream capture.
*******************************************************************************/
  int Source_QueryFrame::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
    if(line>2) return -2;

      if(line==0)
    {
           name=wxT("Select capture");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=0;i<10;i++)
        {
             pom=_("Capture_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
    }
       if(line==1)
    {
       name=wxT("Frame as picture");
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

 int Source_QueryFrame::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
    //   pd->text1+=_("Execute Source_QueryFrame\n");
     int cap_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_')); // capture position in capture array
     wxString pom=param.AfterFirst('#');
     int pic_pos=wxAtoi(pom.BeforeFirst('#').AfterFirst('_')); //picture position in picture array
     int uch=-1;
       if(pom.AfterFirst('#')==_("None"))uch=-1;
   else  uch=wxAtoi(param.AfterFirst('#').AfterFirst('_'));

     if((cap_pos<0)||(cap_pos>9)) return -1; // Bad capture position in capture array
     if((pic_pos<0)||(pic_pos>19)) return -2; // Bad picture position in picture array
     if(uch>19)return -4; //Bad undistortion channel

try
{
//pd->imgx[pic_pos] = cv::Mat::zeros( pd->imgx[pic_pos].size(), pd->imgx[pic_pos].type() );
     if(!pd->capture[cap_pos].isOpened()) return -3; //INput capture is not opened
     pd->capture[cap_pos]>>pd->imgx[pic_pos];
      if(uch>-1)
      {
        if(!pd->cam_calib[uch].GetUndistortionImage(pd->imgx[pic_pos],pd->imgx[pic_pos],pd->pix_per_mm[uch]))return -5;
        if(pd->cam_calib[uch].GetCvError())
         {
         return -6; //OpenCv error
         }
      }


}
     catch( cv::Exception& e )
   {

       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90;
   }

     return 0;
 }

/******************************************************************************
Class for Set or Get capture property.
*******************************************************************************/

int Source_CaptureProperty::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
    if(line<0)return -1;
    if(line>4) return -2;

    if(line==0)
    {
          name=wxT("Properties");
        type=2;
        wxArrayString arraystr;
        wxString pom;
         arraystr.Add(_("Set"));
         arraystr.Add(_("Get"));
        aray_str=arraystr;
        type2=0;
    }

     if(line==1)
    {
           name=wxT("Select capture");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=0;i<10;i++)
        {
             pom=_("Capture_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
    }

    if(line==2)
    {
          name=wxT("Property ID");
        type=2;
        wxArrayString arraystr;
        wxString pom;
         arraystr.Add(_("CAP_PROP_POS_MSEC"));
         arraystr.Add(_("CAP_PROP_POS_FRAMES"));
         arraystr.Add(_("CAP_PROP_POS_AVI_RATIO"));
         arraystr.Add(_("CAP_PROP_FRAME_WIDTH"));
         arraystr.Add(_("CAP_PROP_FRAME_HEIGHT"));
         arraystr.Add(_("CAP_PROP_FPS"));
         arraystr.Add(_("CAP_PROP_FOURCC"));
         arraystr.Add(_("CAP_PROP_FRAME_COUNT"));
         arraystr.Add(_("CAP_PROP_FORMAT"));
          arraystr.Add(_("CAP_PROP_MODE"));
          arraystr.Add(_("CAP_PROP_BRIGHTNESS"));
          arraystr.Add(_("CAP_PROP_CONTRAST"));
          arraystr.Add(_("CAP_PROP_SATURATION"));
          arraystr.Add(_("CAP_PROP_HUE"));
          arraystr.Add(_("CAP_PROP_GAIN"));
          arraystr.Add(_("CAP_PROP_EXPOSURE"));
          arraystr.Add(_("CAP_PROP_CONVERT_RGB"));
           arraystr.Add(_("CAP_PROP_RECTIFICATION"));
           arraystr.Add(_("CAP_PROP_ISO_SPEED"));
           arraystr.Add(_("CAP_PROP_BUFFERSIZE"));
        aray_str=arraystr;
        type2=0;
    }

    if(line==3)
    {
          name=wxT("Value From/To");
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
    if(line==4)
    {

        name=_("Value ID number");
        type=5;
        fval=0.0;

    }

return 0;
}

 int Source_CaptureProperty::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
    //   pd->text1+=_("Source_CaptureProperty\n");

      int prop=0; // 0= Set, 1= Get
      int prop_id=-1; //; Property ID
      int capture_index=-1; // INdex of capture array
      int px=-1; // INdex of variable -1= fixted number , 0-100 variable index
      float f_value=0;
      if(param.BeforeFirst('#')==_("Set")) prop=0;
      else prop=1;
      double dxx;

try
{
      wxString pom=param.AfterFirst('#');
     capture_index=wxAtoi( pom.BeforeFirst('#').AfterFirst('_'));
     if((capture_index<0)||(capture_index>9)) return -1; // Bad capture index
     pom=pom.AfterFirst('#');

      if(pom.BeforeFirst('#')==_("CAP_PROP_POS_MSEC")) prop_id=CAP_PROP_POS_MSEC;
      if(pom.BeforeFirst('#')==_("CAP_PROP_POS_FRAMES")) prop_id=CAP_PROP_POS_FRAMES;
      if(pom.BeforeFirst('#')==_("CAP_PROP_POS_AVI_RATIO")) prop_id=CAP_PROP_POS_AVI_RATIO;
      if(pom.BeforeFirst('#')==_("CAP_PROP_FRAME_WIDTH")) prop_id=CAP_PROP_FRAME_WIDTH;
      if(pom.BeforeFirst('#')==_("CAP_PROP_FRAME_HEIGHT")) prop_id=CAP_PROP_FRAME_HEIGHT;
      if(pom.BeforeFirst('#')==_("CAP_PROP_FPS")) prop_id=CAP_PROP_FPS;
      if(pom.BeforeFirst('#')==_("CAP_PROP_FOURCC")) prop_id=CAP_PROP_FOURCC;
       if(pom.BeforeFirst('#')==_("CAP_PROP_FRAME_COUNT")) prop_id=CAP_PROP_FRAME_COUNT;

     if(pom.BeforeFirst('#')==_("CAP_PROP_FORMAT")) prop_id=CAP_PROP_FORMAT;
      if(pom.BeforeFirst('#')==_("CAP_PROP_MODE")) prop_id=CAP_PROP_MODE;
      if(pom.BeforeFirst('#')==_("CAP_PROP_BRIGHTNESS")) prop_id=CAP_PROP_BRIGHTNESS;
      if(pom.BeforeFirst('#')==_("CAP_PROP_CONTRAST")) prop_id=CAP_PROP_CONTRAST;
      if(pom.BeforeFirst('#')==_("CAP_PROP_SATURATION")) prop_id=CAP_PROP_SATURATION;
      if(pom.BeforeFirst('#')==_("CAP_PROP_HUE")) prop_id=CAP_PROP_HUE;
      if(pom.BeforeFirst('#')==_("CAP_PROP_GAIN")) prop_id=CAP_PROP_GAIN;
       if(pom.BeforeFirst('#')==_("CAP_PROP_EXPOSURE")) prop_id=CAP_PROP_EXPOSURE;

       if(pom.BeforeFirst('#')==_("CAP_PROP_CONVERT_RGB")) prop_id=CAP_PROP_CONVERT_RGB;
      if(pom.BeforeFirst('#')==_("CAP_PROP_RECTIFICATION")) prop_id=CAP_PROP_FRAME_WIDTH;
      if(pom.BeforeFirst('#')==_("CAP_PROP_ISO_SPEED")) prop_id=CAP_PROP_ISO_SPEED;
      if(pom.BeforeFirst('#')==_("CAP_PROP_BUFFERSIZE")) prop_id=CAP_PROP_BUFFERSIZE;

      pom=pom.AfterFirst('#');


      if(pom.BeforeFirst('#')==_("Number"))
      {
      pom.AfterFirst('#').ToCDouble(&dxx);
      f_value=(float)dxx;
      }
      else
      {
           px=wxAtoi(pom.BeforeFirst('#').AfterFirst('_'));
          if((px<0)||(px>99)) return -2;// baf float value index

           f_value=pd->fval[px];
      }


            if(!pd->capture[capture_index].isOpened()) return -3; //INput capture is NULL

     if(prop==0) pd->capture[capture_index].set(prop_id, (double)f_value );
     else
      {
          if(px==-1) return -2; //bad float value index
          pd->fval[px]=(float)pd->capture[capture_index].get(prop_id);
      }
}
     catch( cv::Exception& e )
   {

       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90;
   }

     return 0;
 }

/*************************************************************************
Class for create new image
**************************************************************************/
int Source_CloneImage::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>1) return -2;


       if(line==0)
    {
       name=wxT("Destination picture");
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
       name=wxT("Clone Source picture");
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

 int Source_CloneImage::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {


   //Separate all parameters fro input parameter
   wxString dest,sourc;

   dest=param.BeforeFirst('#');
   sourc=param.AfterFirst('#');


   //End separation
try
{
    int idest=wxAtoi(dest.AfterFirst('_'));
     if((idest<0)||(idest>19)) return -1; // Bad destination picture


    int isourc=wxAtoi(sourc.AfterFirst('_'));
    if((isourc<0)||(isourc>19)) return -2; // Bad source image

    if(idest==isourc) return -3;// source and destination image is same
    pd->imgx[idest]=pd->imgx[isourc].clone();// Function for clone image



}
     catch( cv::Exception& e )
   {

       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90;
   }
     return 0;
 }

/*****************************************************************************************************************************/

int Source_SaveImage::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
  if(line<0)return -1;
  if(line>2) return -2;

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
    name=wxT("Path to picture file");
    type=1; //file path string type
     #if defined(__WXMSW__)
        str=wxT("C:\\test.jpg");
      #elif defined(__UNIX__)
        str=wxT("/home/test.jpg");
       #endif
        type2=4;//open file dialog will display
    }

  return 0;
}

 int Source_SaveImage::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
 {
 try
 {
   wxString pic,path;
   pic=param.BeforeFirst('#');
   path=param.AfterFirst('#');
   int pic_pos=wxAtoi(pic.AfterFirst('_'));
   if((pic_pos<0)||(pic_pos>19))return -1; //Bad picture position
   imwrite(String(path.mbc_str()),pd->imgx[pic_pos]);
 }
      catch( cv::Exception& e )
   {

       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90;
   }
   return 0;
 }

 /****************************************************************************************
 Class for create video file
 *****************************************************************************************/
 int Source_CreateVideoFile::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
 {
 if(line<0)return -1;
  if(line>9) return -2;

  if(line==0)
  {
        name=wxT("Select Video writer");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=0;i<10;i++)
        {
           pom=_("VideoWriter_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
  }

    if(line==1)
    {
    name=wxT("Path to video file");
    type=1; //file path string type
     #if defined(__WXMSW__)
        str=wxT("C:\\test.avi");
      #elif defined(__UNIX__)
        str=wxT("/home/test.avi");
       #endif
        type2=4;//save file dialog will display
    }

    if(line==2)
    {
       name=wxT("Codec");
        type=2;
        wxArrayString arraystr;
        wxString pom;

          arraystr.Add(_("MPEG-1"));
           arraystr.Add(_("motion-jpeg"));
           arraystr.Add(_("MPEG-4.2"));
           arraystr.Add(_("MPEG-4.3"));
           arraystr.Add(_("MPEG-4"));
           arraystr.Add(_("H263"));
           arraystr.Add(_("H263I"));
           arraystr.Add(_("FLV1"));
        aray_str=arraystr;
        type2=0;
    }

    if(line==3)
    {
        name=wxT("Framerate from");
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

    if(line==4)
    {

        name=wxT("Framerate number");
        type=4;
        ival=0;

    }

      if(line==5)
    {
        name=wxT("Height from");
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

    if(line==6)
    {

        name=wxT("Height number");
        type=4;
        ival=0;

    }

      if(line==7)
    {
        name=wxT("Width from");
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

    if(line==8)
    {

        name=wxT("Width number");
        type=4;
        ival=0;

    }

       if(line==9)
    {
        name=wxT("Colour");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        arraystr.Add(_("Grayscale"));
        arraystr.Add(_("Colour"));
        aray_str=arraystr;
        type2=1;
    }

     return 0;
 }

  int Source_CreateVideoFile::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
  {
     wxString pom,pom2;

     int videow_pos=-1; // position of video writer structure
     wxString video_file_path; // path for store video file
     int fourcc_=VideoWriter::fourcc('P','I','M','1'); // code of codec
     double fps=0; // framerate of video stream
     int height=0;  // height of video
     int width=0; //width of video
     int is_color=1; // if value is no zero, video is colour, if 0 video is grayscale
     double dxx;

       pom=param.BeforeFirst('#');
     pom2=param.AfterFirst('#');

     videow_pos=wxAtoi(pom.AfterFirst('_'));
     if((videow_pos<0)||(videow_pos>9)) return -1; // bad video writer structure position
     video_file_path=pom2.BeforeFirst('#');
     pom=pom2.AfterFirst('#');

     pom2=pom.BeforeFirst('#');
     pom=pom.AfterFirst('#');


     if(pom2==_("MPEG-1")) fourcc_=VideoWriter::fourcc('P','I','M','1');
     if(pom2==_("motion-jpeg")) fourcc_=VideoWriter::fourcc('M','J','P','G');
     if(pom2==_("MPEG-4.2")) fourcc_=VideoWriter::fourcc('M', 'P', '4', '2');
     if(pom2==_("MPEG-4.3")) fourcc_=VideoWriter::fourcc('D', 'I', 'V', '3');
     if(pom2==_("MPEG-4")) fourcc_=VideoWriter::fourcc('D', 'I', 'V', 'X');
     if(pom2==_("H263")) fourcc_=VideoWriter::fourcc('U', '2', '6', '3');
     if(pom2==_("H263I")) fourcc_=VideoWriter::fourcc('I', '2', '6', '3');
     if(pom2==_("FLV1")) fourcc_=VideoWriter::fourcc('F', 'L', 'V', '1');

     pom2=pom.BeforeFirst('#');
     pom=pom.AfterFirst('#');

     if(pom2==_("Number"))
     {
     pom.BeforeFirst('#').ToCDouble(&dxx);
     fps=(float)dxx;
     }
     else
     {
         int posB=wxAtoi(pom2.AfterFirst('_'));
         if((posB<0)||(posB>99))return -2; // Bad fps variable
         fps=pd->fval[posB];
     }

       if(fps<=0) return -3; // Bad fps value

     pom=pom.AfterFirst('#');

     pom2=pom.BeforeFirst('#');
     pom=pom.AfterFirst('#');


      if(pom2==_("Number"))
      {
      pom.BeforeFirst('#').ToCDouble(&dxx);
      height=(float)dxx;
      }
     else
     {
         int posC=wxAtoi(pom2.AfterFirst('_'));
         if((posC<0)||(posC>99))return -4; //bad height variable
         height=pd->fval[posC];
     }

     if(height<=0) return -5;// Bad height value

     pom=pom.AfterFirst('#');

     pom2=pom.BeforeFirst('#');
     pom=pom.AfterFirst('#');

      if(pom2==_("Number"))
      {
      pom.BeforeFirst('#').ToCDouble(&dxx);
      width=(float)dxx;
      }
     else
     {
         int posD=wxAtoi(pom2.AfterFirst('_'));
         if((posD<0)||(posD>99))return -6; //bad width variable
         width=pd->fval[posD];
     }

     if(width<=0)return -7; // BAd width value

     if(pom.AfterFirst('#')==_("Grayscale"))is_color=0;
     else is_color=1;
try
{

  pd->video_writers[videow_pos].open(String(video_file_path.mbc_str()),fourcc_,fps,Size(width,height),is_color);
  if(!pd->video_writers[videow_pos].isOpened()) return -8; //Can not open video file
}
     catch( cv::Exception& e )
   {

       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90;
   }

      return 0;
  }

  /****************************************************************************************************************************
  Class for write frame to video file
  ****************************************************************************************************************************/
  int Source_WriteVideoFrame::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
  {
     if(line<0) return -1;
     if(line>1) return -2;

 if(line==0)
  {
        name=wxT("Select Video writer");
        type=2;
        wxArrayString arraystr;
        wxString pom;
        for(int i=0;i<10;i++)
        {
           pom=_("VideoWriter_");
          pom<<i;
          arraystr.Add(pom);
        }
        aray_str=arraystr;
        type2=0;
  }

    if(line==1)
    {
       name=wxT("Frame as picture");
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

  int Source_WriteVideoFrame::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
  {
     int writer_pos=-1;
     int picture_pos=-1;

     writer_pos=wxAtoi(param.BeforeFirst('#').AfterFirst('_'));
     picture_pos=wxAtoi(param.AfterFirst('#').AfterFirst('_'));

     if((writer_pos<0)||(writer_pos>9)) return -1; // Bad position in video writer structure
     if((picture_pos<0)||(picture_pos>19)) return -2; // Bad position in picture structure



    try
    {
        if(!pd->video_writers[writer_pos].isOpened()) return -3; //Can not open video file
        pd->video_writers[writer_pos].write(pd->imgx[picture_pos]);
    }
     catch( cv::Exception& e )
   {

       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90;
   }

      return 0;
  }

/**********************************************************************************************
Class for Get picture parameters
**********************************************************************************************/

int Source_GetPictureParam::GetLineParam(int line,wxString &name,int &type,wxArrayString &aray_str,wxString &str,int &ival,float &fval,bool &bval,int &type2)
{
    if(line<0) return -1;
    if(line>2) return -2;

    if(line==0)
  {

       name=wxT("Select picture");
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
        name=wxT("Picture parameter");
        type=2;
        wxArrayString arraystr;
        wxString pom;

          arraystr.Add(_("Width"));
           arraystr.Add(_("Height"));
           arraystr.Add(_("Channels"));
           arraystr.Add(_("Element size"));
           arraystr.Add(_("Number of pixels"));
           arraystr.Add(_("Depth"));
        aray_str=arraystr;
        type2=0;
  }
   if(line==2)
    {
          name=wxT("Value To");
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

int Source_GetPictureParam::RunCommand(wxString param,PDAT *pd,int line,int edit,ObjectPrograms *obp)
{
    wxString pom=param.BeforeFirst('#');
   wxString  pom2=param.AfterFirst('#');

    int pic_pos=wxAtoi(pom.AfterFirst('_'));
     if((pic_pos<0)||(pic_pos>19)) return -1; // bad picture position
     wxString picture_param=pom2.BeforeFirst('#');
     pom=pom2.AfterFirst('#');
     int var_numb=wxAtoi(pom.AfterFirst('_'));
     if((var_numb<0)||(var_numb>99))return -2; //Bad variable position

    try
    {

     if(picture_param==_("Width"))pd->fval[var_numb]=(float)pd->imgx[pic_pos].cols;
     else if(picture_param==_("Height"))pd->fval[var_numb]=(float)pd->imgx[pic_pos].rows;
     else if(picture_param==_("Channels"))pd->fval[var_numb]=(float)pd->imgx[pic_pos].channels();
     else if(picture_param==_("Element size"))pd->fval[var_numb]=(float)pd->imgx[pic_pos].elemSize();
     else if(picture_param==_("Number of pixels"))pd->fval[var_numb]=(float)pd->imgx[pic_pos].total();
    }
         catch( cv::Exception& e )
   {

       SetOpenCVErrorMess(e.err,e.file,e.func,e.line,pd);
       return -90;
   }

return 0;
}

 /*****************************************************************************************************************************/


