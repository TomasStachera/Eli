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
    string eli_path="/home/tomas/programming/Eli/Eli_examples/example/test_programs/numbers.eli";
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
    
    cout<<"Press CTRL+C for terminate program!!!"<<endl;

    return 0;
}
