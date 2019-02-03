#include "LOGMES.h"

LOGMES::LOGMES()
{
    //ctor
    strcpy(filename,"/home/tomas/eli_log.txt");
}

LOGMES::~LOGMES()
{
    //dtor
}

void LOGMES::SetLogMessage(int linenum,std::string filenamex,std::string messx,int var)
{
ofs.open(filename,std::ios_base::app);
ofs<<linenum<<'\t'<<filenamex<<'\t'<<messx<<'\t'<<var<<std::endl;
ofs.close();

}

void LOGMES::SetLogMessage(int linenum,std::string filenamex,std::string messx,float var)
{
ofs.open(filename,std::ios_base::app);
ofs<<linenum<<'\t'<<filenamex<<'\t'<<messx<<'\t'<<var<<std::endl;
ofs.close();

}

void LOGMES::SetLogMessage(int linenum,std::string filenamex,std::string messx,bool var)
{
ofs.open(filename,std::ios_base::app);
ofs<<linenum<<'\t'<<filenamex<<'\t'<<messx<<'\t'<<var<<std::endl;
ofs.close();

}

void LOGMES::SetLogMessage(int linenum,std::string filenamex,std::string messx,wxString var)
{
ofs.open(filename,std::ios_base::app);
ofs<<linenum<<'\t'<<filenamex<<'\t'<<messx<<'\t'<<var.mb_str()<<std::endl;
ofs.close();

}

void LOGMES::SetLogMessage(int linenum,std::string filenamex,std::string messx,wxArrayString var)
{
ofs.open(filename,std::ios_base::app);
ofs<<linenum<<'\t'<<filenamex<<'\t'<<messx<<'\t';
for(unsigned i=0;i<var.GetCount();i++)ofs<<var[i].mb_str()<<'\t';
ofs<<std::endl;

ofs.close();

}
