#ifndef LOGMES_H
#define LOGMES_H
#include <fstream>
#include <string>
#include <cstring>
#include <wx/string.h>
#include <wx/arrstr.h>

/**
LOGMES lg;
  lg.SetLogMessage(__LINE__,__FILE__,"parameter",parameterx);
**/
class LOGMES
{
    public:
        LOGMES();
        virtual ~LOGMES();

      void  SetLogMessage(int linenum,std::string filenamex,std::string messx,int var);
      void  SetLogMessage(int linenum,std::string filenamex,std::string messx,float var);
      void SetLogMessage(int linenum,std::string filenamex,std::string messx,bool var);
       void SetLogMessage(int linenum,std::string filenamex,std::string messx,wxString var);
       void SetLogMessage(int linenum,std::string filenamex,std::string messx,wxArrayString var);
    protected:

    private:
      std::ofstream ofs;
      char filename[100];

};

#endif // LOGMES_H
