#ifndef ELILIB_H_INCLUDED
#define ELILIB_H_INCLUDED
#if defined(__UNIX__)
#  define EXPORTIT

#elif (__WINDOWS__)

#  define EXPORTIT __declspec( dllexport )
#endif
/**
Header file for library EliLib
Author: Tomas Stachera
mail: tomas.stachera@gmail.com
**/
extern "C"
{
/**
Function:int OpenProgramCh
Function opens test program from file in input parameters. This function must be called before
function RunProgram
This function has input parameter in char * format (if user does not use wxWidgets)
1.parameter: Test program file path in char *
Function return 0 if all is ok
         return -1 if there is initial error (Error will display in error message)
         return -2 if there is run error (Error can be read in function GetErrorString)
**/
EXPORTIT int EliOpenProgramCh(char *pathx);

/**
Function:OpenProgram. Needs use wxWidgets.
Function opens test program from file in input parameters
1.parameter: Test program file path in wxString
Function return 0 if all is ok
         return -1 if there is initial error (Error will display in error message)
         return -2 if there is run error (Error can be read in function GetErrorString)
**/


EXPORTIT int EliOpenProgram(wxString path);


/**
Function: SetSystemVariable
Function set system variables with some value
1.parameter: variable position range <0..99>
2.parameter: float variable value
Function return 0 if all is ok
         return -1 if there is initial error (Error will display in error message)
         return -2 if there is run error (Error can be read in function GetErrorString)
**/
EXPORTIT int EliSetSystemVariable(int pos,float variabl);

/**
Function:GetSystemVariable
Function get actual value of system variables
1.parameter: variable position range <0..99>
2.parameter: reference float variable value
Function return 0 if all is ok
         return -1 if there is initial error (Error will display in error message)
         return -2 if there is run error (Error can be read in function GetErrorString)
**/
EXPORTIT int EliGetSystemVariable(int pos,float *fval);

/**
Function: RunProgram
Function run complete test program form start line to the end line  and close test program
Function OpenProgram or OpenProgramCh must be called before this function
Function return 0 if all is ok
         return -1 if there is initial error (Error will display in error message)
         return -2 if there is run error (Error can be read in function GetErrorString)

**/
EXPORTIT int EliRunProgram(void);

/**
Function: RunProgramFromLine
Function run  test program from some  line to the end line but program
is not closed (function can be call again in cycle). For close program function EndRunFromLine(void)
must be called
1.parameter: line number of line from where test program should be start
Function return 0 if all is ok
         return -1 if there is initial error (Error will display in error message)
         return -2 if there is run error (Error can be read in function GetErrorString)

**/
EXPORTIT int EliRunProgramFromLine(int line);

/**
Function:EndRunFromLine
Function close test program which should be called
in function RunProgramFromLine(int line)
**/
EXPORTIT void EliEndRunFromLine(void);

/**
Function:GetErrorString
Function return ErrorString in case of error in some function
Needs to be compiled with wxWidgets
**/
EXPORTIT wxString EliGetErrorString(void);

/**
Function:GetErrorStringCh
Similar function as GetErrorString, but error string is in char* format
Function gets error string in case of run error (return -2 in other functions)
Returned string is in char format for user which does not use wxWidgets
1.parameter: max_len Maximal expected length of returned string
2.parameter: er_str: error string in char format
unction return 0 if all is ok
        return -1 if returned string variable has more characters as number in parameter 1
**/
EXPORTIT int EliGetErrorStringCh(int max_len,char *er_str);

/**
Function:GetStringVariable
Function gets string value of system variable
1.parameter: pos. System variable string position range <0..9>
2.parameter: sval: returned variable string
Function return 0 if all is ok
         return -1 if there is initial error (Error will display in error message)
         return -2 if there is run error (Error can be read in function GetErrorString)
**/

EXPORTIT int EliGetStringVariable(int pos,wxString *sval);


/**
Function:GetStringVariableCh
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
EXPORTIT int EliGetStringVariableCh(int pos,int max_len,char *valx);

/**
Function:GetNumberOfAllObjects
Function return number of all found objects
**/
EXPORTIT int EliGetNumberOfAllObjects(void);

/**
Function:GetObjectsParametersName . Needs wxWidgets
Function show name of object parameters according position number
1.parameter: pos: position nuber range < 1..29>
2.parameter: namex: name of object parameter
Function return o if all is ok
         return -1 if parameter 1 is not from range <1..29>
**/

EXPORTIT int EliGetObjectsParametersName(int pos,wxString *namex);


/**
Function:GetObjectsParametersNameCh
Function show name of object parameters according position number in char format
1.parameter: pos: position nuber range < 1..29>
2.parameter:max_len: Maximal expected length of returned string
3.parameter: namex: name of object parameter in char format
Function return 0 if all is ok
         return -1 if parameter 1 is not from range <1..29>
         return -2 if number of characters in returned string is more than 2.parameter
**/
EXPORTIT int EliGetObjectsParametersNameCh(int pos,int max_len,char *namex);

/**
Function:GetNumberObjectsName
Function return number of found objects according object name
1.parameter: namex: name of object which number we want to count
Function return number of found objects
**/

EXPORTIT int EliGetNumberObjectsName(wxString namex);


/**
Function:GetNumberObjectsNameChextern "C"
{
Function return number of found objects according name in char format
1.parameter: namex: name of object which number
**/

EXPORTIT int EliGetNumberObjectsNameCh(char *namex);

/**
Function:GetObjectParameter (Only C++ function and wxWidgets)
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

EXPORTIT int EliGetObjectParameter(wxString namex,int pos,std::vector<int> &ival,std::vector<double> &dval);


/**
Function:GetObjectparameterC
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
EXPORTIT int EliGetObjectparameterC(char *namex,int max_len,int pos,int *num_ival,int *ival,int *num_dval,double *dval);


}
#endif // ELILIB_H_INCLUDED
