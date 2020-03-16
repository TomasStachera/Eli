/**
Program app1.
Tomas Stachera email:tomas.stachera@gmail.com
This example program show how to use Eli libraries in any C++ project
with EliLib library. It is console application which execute eli program
over library and read results.
On this way can be executed any eli program from external application.
Program reads picture from example directory and read numbers value on it.
Number on picture is read as string variable. String variable must be same as 
a string on the picture.
Run first program number.eli from example directory on Eli GUI application, 
setup path for selected picture and then run this application
**/
#include <iostream>
#include <string>
#include <cstring>
#include <EliLib.h>  // include EliLib header

using namespace std;

int main()
{
    char string_var[101];//Maximal variable strings 100 chars
    char er_string[501];// Maximal error string 500 chars
    //Write path for eli program which will be executed. Change path according your setup
    string eli_path="/home/tomas/programming/Eli/Eli_examples/example/test_programs/multimeter3_p.eli";
    char path[eli_path.size()+1];
    strcpy(path,eli_path.c_str());
    /**
    Function EliOpenProgramCh.
    This function open .eli program according selected path. If openning program is ok function return 0
    if not function has error. This error should be read in function EliGetErrorStringCh  
    **/
    int ret=EliOpenProgramCh(path);
     if(ret!=0)
    {
    EliGetErrorStringCh(500,er_string);
    cout << "Error string:"<<endl;
    cout <<er_string<<endl;
    }

    /**
    Function EliRunProgram executes selected program
    Function return 0 if all is ok. If return is not 0 function has error. This error can be read in function
   EliGetErrorStringCh
    **/
    ret=EliRunProgram();
    if(ret!=0)
    {
    EliGetErrorStringCh(500,er_string);
    cout << "Error string:"<<endl;
    cout <<er_string<<endl;
    }
    
   /**
    Function EliGetStringVariableCh read value of string variable 0 (1.first parameter of function)
    String 0 variable must be set in .eli program as a result string. If another String variable will
    be use as a result change 1.parameter of this function according it.
   **/

    ret=EliGetStringVariableCh(0,100,string_var);
    cout << "Return string variable :"<<endl;
    cout <<string_var<<endl;
    
     string obj_name="dot";
    char obj_namech[eli_path.size()+1];
    strcpy(obj_namech,obj_name.c_str());
    /**  Function from EliLib. Function return number of objects according name***/
     ret=EliGetNumberObjectsNameCh(obj_namech);
    cout << "Number of objects "<<obj_namech<<":"<< ret<<endl;
    
   char param_name[100]={0};
   int *num_ival;
    int *num_dval;
    int ival[10]; // If there are more than 10 objects alocate more
    double dval[10]; // If there are more than 10 objects alocate more
    
   num_ival=new int;
   num_dval=new int;
    
    for(unsigned i=1;i<30;i++) // Get all 29 parameters
    {
    /** Function from EliLib Get name of object parameter****************************/
    ret=EliGetObjectsParametersNameCh(i,99,param_name);
    /**************************************************/
     if(ret!=0)
      {
      cout << "Get  objects parameter name error: Position: "<<i<< " Error code: "<<ret<<endl; 
      break;
       }
    /** Function from EliLib  Get object parameter value****************************/
    ret= EliGetObjectparameterC(obj_namech,10,i,num_ival,ival,num_dval,dval);
       /**************************************************/
     if(ret<0)
      {
      cout << "Get  objects parameter error: Position: "<<i<< " Error code: "<<ret<<endl; 
      break;
       }
     int numi=0;
     int numd=0;
       numi=*num_ival;
       numd=*num_dval;
      cout<<param_name<<": ";
      if(ret==1) // Returned parameter is integer
       {
         for(unsigned j=0;j<numi;j++) cout<<ival[j]<<":"<<endl;
       }
      if(ret==2)  //Returned parameter is double
      {
        for(unsigned j=0;j<numd;j++) cout<<dval[j]<<":"<<endl;
      }
    }
    
    cout<<"Press CTRL+C for terminate program!!!"<<endl;
    delete num_ival;
    delete num_dval;

    return 0;
}
