/***************************************************************
 * Name:      gui_applicationMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Tomas Stachera (tomas.stachera@gmail.com)
 * Created:   2019-09-20
 * Copyright: Tomas Stachera ()
 * License:
This example show how to use Eli library with your own application
with wxWidgtes and OpenCv support
 **************************************************************/

#include "gui_applicationMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(gui_applicationFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/filedlg.h>
#include <wx/config.h>
#include <wx/dc.h>
#include <wx/dcclient.h>
#include "LoopDialog.h"






//(*IdInit(gui_applicationFrame)
const long gui_applicationFrame::ID_TEXTCTRL1 = wxNewId();
const long gui_applicationFrame::ID_BUTTON1 = wxNewId();
const long gui_applicationFrame::ID_BUTTON2 = wxNewId();
const long gui_applicationFrame::ID_BUTTON3 = wxNewId();
const long gui_applicationFrame::ID_BUTTON4 = wxNewId();
const long gui_applicationFrame::ID_CHOICE1 = wxNewId();
const long gui_applicationFrame::ID_TEXTCTRL2 = wxNewId();
const long gui_applicationFrame::ID_STATICTEXT1 = wxNewId();
const long gui_applicationFrame::ID_TEXTCTRL3 = wxNewId();
const long gui_applicationFrame::ID_PANEL1 = wxNewId();
const long gui_applicationFrame::idMenuQuit = wxNewId();
const long gui_applicationFrame::idMenuAbout = wxNewId();
const long gui_applicationFrame::ID_STATUSBAR1 = wxNewId();
const long gui_applicationFrame::ID_TIMER1=wxNewId();
//*)

BEGIN_EVENT_TABLE(gui_applicationFrame,wxFrame)
    //(*EventTable(gui_applicationFrame)
    //*)
END_EVENT_TABLE()

gui_applicationFrame::gui_applicationFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(gui_applicationFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer5;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Select Eli program"));
    PathToProg = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticBoxSizer1->Add(PathToProg, 4, wxALL|wxEXPAND, 5);
    ChangePath = new wxButton(this, ID_BUTTON1, _("Change"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticBoxSizer1->Add(ChangePath, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    RunAll = new wxButton(this, ID_BUTTON2, _("Run program"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer4->Add(RunAll, 1, wxALL|wxEXPAND, 5);
    RunLoop = new wxButton(this, ID_BUTTON3, _("Run loop"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer4->Add(RunLoop, 1, wxALL|wxEXPAND, 5);
    StopLoop = new wxButton(this, ID_BUTTON4, _("Stop loop"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    StopLoop->Disable();
    BoxSizer4->Add(StopLoop, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Select returned parameter"));
    RetParameter = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    StaticBoxSizer2->Add(RetParameter, 1, wxALL|wxEXPAND, 5);
    BoxSizer5->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("ObjectName"));
    ObjectName = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticBoxSizer3->Add(ObjectName, 1, wxALL|wxEXPAND, 5);
    BoxSizer5->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer5, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Variable output"));
    StaticTextOut = new wxStaticText(this, ID_STATICTEXT1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticTextOut->SetForegroundColour(wxColour(236,20,23));
    wxFont StaticTextOutFont(15,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextOut->SetFont(StaticTextOutFont);
    StaticBoxSizer4->Add(StaticTextOut, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Variable output"));
    TextVarOut = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    StaticBoxSizer5->Add(TextVarOut, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(StaticBoxSizer5, 2, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(350,296), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer3->Add(Panel1, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gui_applicationFrame::OnChangePathClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gui_applicationFrame::OnRunAllClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gui_applicationFrame::OnRunLoopClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gui_applicationFrame::OnStopLoopClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&gui_applicationFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&gui_applicationFrame::OnAbout);
    Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&gui_applicationFrame::OnPanelPaint,0,this);
    //*)
    isDisplayedImage=false;
    wxArrayString arstr;
    arstr.Add(_("Object"));
    wxString px;
    for(unsigned i=0;i<10;i++)
    {
    px.Printf(_("String %d"),i);
    arstr.Add(px);
    }
    for(unsigned i=0;i<100;i++)
    {
    px.Printf(_("Variable %d"),i);
    arstr.Add(px);
    }
   RetParameter->Append(arstr);
   Timer1=NULL;
}

gui_applicationFrame::~gui_applicationFrame()
{
    //(*Destroy(gui_applicationFrame)
    //*)
}

void gui_applicationFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void gui_applicationFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxT("Example aplication for show how to use EliLibwx library in wxWidgets programs");
    wxMessageBox(msg, _("Welcome to..."));
}

/**
Function is executed when user click on Change program button
Function select Eli program and use one function from EliLib
**/
void gui_applicationFrame::OnChangePathClick(wxCommandEvent& event)
{
    wxString caption=wxT("Open Test program");
    wxString wildcard=wxT("ELI files (*.eli)|*.eli");
    wxString defaultDir,path,pok;
    wxConfig config(wxT("Prog"),wxT("APP2"));
    config.Read(wxT("def_dir"),&pok);
    if(pok.Len()==0) defaultDir=wxT("/home");
    else defaultDir=pok;
    PathToProg->Clear(); //Clear path window


    wxString defaultFilename=wxEmptyString;

    wxFileDialog dialog(this,caption,defaultDir,defaultFilename,wildcard,wxFD_OPEN);
    if(dialog.ShowModal()==wxID_OK)
    {
     path=dialog.GetPath();
     wxString sv=path.BeforeLast('/');
     config.Write(wxT("def_dir"),sv);
     PathToProg->WriteText(path);
    /** Function from EliLib**/
     int ret=EliOpenProgram(path); // Function from EliLib.h
    /************************************/
    if(ret==0)TextVarOut->WriteText(_("Open test program OK\n"));
    else if(ret==-1)TextVarOut->WriteText(_("Initial error\n"));
    else TextVarOut->WriteText(EliGetErrorString());
    }
}

/**
Function read Ouptput parameters from EliLib
**/
void gui_applicationFrame::DisplayOutputParameters(void)
{
    int ret=0;
    wxString sel_str=RetParameter->GetStringSelection(); // Get output parameter option
try
{
    cv::Mat imgx; 
   /** Function from EliLib***************/
    ret=EliGetResultPicture(imgx);
  /******************************************/
    if(ret==0) GenerateDisplPicture(imgx);

    if(sel_str==_("Object"))//Object parameters
    {
       wxString obj_name=ObjectName->GetValue();
     /** Function from EliLib********************/
    int num_obj=EliGetNumberObjectsName(obj_name); //Function from EliLib
     /******************************************/
       if(num_obj<1)
       {
           TextVarOut->WriteText(_("No objects "));
           TextVarOut->WriteText(obj_name);
           TextVarOut->WriteText(_(" was found"));
       }
       else
       {
           wxString px,py;
           px.Printf(_("Found %d objects:"),num_obj);
           px+=obj_name;
           TextVarOut->WriteText(px);
           TextVarOut->WriteText(_("\n"));
           std::vector<int> ival;
           std::vector<double> dval;
            for(unsigned j=1;j<30;j++)
            {
          /*****Functions from EliLib**************************/
         ret= EliGetObjectParameter(obj_name,j,ival,dval);
          EliGetObjectsParametersName(j,&py); //Get object parameter name
           /****************************************************/
             TextVarOut->WriteText(_("** "));
             TextVarOut->WriteText(py);
              TextVarOut->WriteText(_(" **\n"));
             if(ival.size()>0) // Object value is integer
             {
               for(unsigned i=0;i<ival.size();i++)
               {
                 px.Printf(_("%d object:%d\n"),i+1,ival[i]);
                 TextVarOut->WriteText(px);
               }
             }
             else if(dval.size()>0)// Object value is double
             {
                 for(unsigned i=0;i<dval.size();i++)
                {
                 px.Printf(_("%d object:%f\n"),i+1,dval[i]);
                 TextVarOut->WriteText(px);
                }
             }
            }
       }

    }
    else if(sel_str.BeforeFirst(' ')==_("String")) //Get string value
    {
       int posx=wxAtoi(sel_str.AfterFirst(' '));
       wxString s_var;
     /************Function from EliLib**************************/
     ret=EliGetStringVariable(posx,&s_var); // Function from EliLib.h
     /**********************************************************/
       if(ret==0)
       {
       TextVarOut->WriteText(_("Get string variable OK:\n"));
       TextVarOut->WriteText(s_var);
       StaticTextOut->SetLabel(s_var);
        }
       else if(ret==-1)TextVarOut->WriteText(_("Initial error\n"));
       else TextVarOut->WriteText(EliGetErrorString());
    }
    else if(sel_str.BeforeFirst(' ')==_("Variable")) //Get float variable value
    {
       int posx=wxAtoi(sel_str.AfterFirst(' '));
       float f_var;
       wxString s_var;
    /*********Function from EliLib**********************************/
       ret=EliGetSystemVariable(posx,&f_var); // Function from EliLib.h
     /***************************************************************/
       if(ret==0)
       {
       s_var.Printf(_("%f"),f_var);
       TextVarOut->WriteText(_("Get float variable OK:\n"));
       TextVarOut->WriteText(s_var);
       StaticTextOut->SetLabel(s_var);
       }
       else if(ret==-1)TextVarOut->WriteText(_("Initial error\n"));
       else TextVarOut->WriteText(EliGetErrorString());
    }
}
  catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    TextVarOut->WriteText(_("OpenCV error in function DisplayOutputParameters:\n"));
    TextVarOut->WriteText(pv);
    }
}

/**
Function run program from EliLib 
**/
void gui_applicationFrame::OnRunAllClick(wxCommandEvent& event)
{
    TextVarOut->Clear();
  /** Function from EliLib ***********/
   int ret=EliRunProgram(); // Function from EliLib.h
  /***********************************/
    if(ret==0)TextVarOut->WriteText(_("Run test program OK\n"));
    else if(ret==-1)TextVarOut->WriteText(_("Initial error\n"));
    else TextVarOut->WriteText(EliGetErrorString());

    DisplayOutputParameters();

}
/**
Function executest loop mode. It display windw for select Loop parameters
**/
void gui_applicationFrame::OnRunLoopClick(wxCommandEvent& event)
{
    RunLoop->Enable(false);
    StopLoop->Enable(true);

/**
Display loop dialog
**/
 LoopDialog dlg(this,10);
dlg.ShowModal();
loop_time_ms=dlg.GetLoopTime();
loop_start_line=dlg.GetStartLine();
/********************************/
   TextVarOut->Clear();
   /******** unction from EliLib ***********
     At first must be run function from line 1 and next can be run from
     specified line***********************/
    int ret=EliRunProgramFromLine(1); // Function from EliLib.h
   /******************************************/
    if(ret==0)TextVarOut->WriteText(_("Run test program OK\n"));
    else if(ret==-1)TextVarOut->WriteText(_("Initial error\n"));
    else TextVarOut->WriteText(EliGetErrorString());

    DisplayOutputParameters();

    if(ret!=0)
    {
        EliEndRunFromLine();
        RunLoop->Enable(true);
    StopLoop->Enable(false);
        return;
    }



  if(Timer1!=NULL)
  {
        Timer1->Stop();
       delete Timer1;
      Timer1=NULL;
    }
/** Create timer for loop execution *********/
     Timer1=new wxTimer();

    Timer1->SetOwner(this, ID_TIMER1);
    Timer1->Start(loop_time_ms,false);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&gui_applicationFrame::OnTimer1Trigger);
}

void gui_applicationFrame::OnStopLoopClick(wxCommandEvent& event)
{
  /** Function from EliLib ***********
   It must be called in the end of the loop */
    EliEndRunFromLine();
  /******************************************/
    Timer1->Stop();
    delete Timer1;
      Timer1=NULL;
    RunLoop->Enable(true);
    StopLoop->Enable(false);
}

/*******************************************************************
Function for generate display picture.
This picture is display in picture window
********************************************************************/
int gui_applicationFrame::GenerateDisplPicture(Mat img)
{

try
{
    //if(img==0) return -1; // if image pointer is not set return -1;
    wxSize size=GetSize();//Get window dimension
    int width=size.GetWidth()/2-40; //calculate maximal posible width in display window
    int heigth=size.GetHeight()-20; //calculate maximal posible height in display window
    int im_width=img.cols; //input image width
    int im_height=img.rows; //input image height

    float ratio_w=(float)width/(float)im_width;
  float ratio_h=(float)heigth/(float)im_height;



  int ra1=(int)(ratio_w*(float)im_height);
  float tot_ratio;
     if(ra1>heigth)tot_ratio=ratio_h;
     else tot_ratio=ratio_w;
         Mat img_x;
           if (img.type()==CV_8UC1)
           {
               cvtColor(img, img_x, COLOR_GRAY2RGB);

            //displayed_Image=(new_width,new_heigth,img_x.depth(),img_x.channels());
           resize(img_x,displayed_Image,Size(),tot_ratio,tot_ratio,INTER_LINEAR ); // resize final image to new sizes
           }
           else
           {
                    //    displayed_Image=(new_width,new_heigth,img_x.depth(),img_x.channels());
       resize(img,displayed_Image,Size(),tot_ratio,tot_ratio,INTER_LINEAR ); // resize final image to new sizes
           }
 cvtColor(displayed_Image,displayed_Image,COLOR_RGB2BGR);
isDisplayedImage=true;


}
   catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    TextVarOut->WriteText(_("OpenCV error in function GenerateDisplPicture:\n"));
    TextVarOut->WriteText(pv);
    }

    return 0;
}

/**********************************************************************************
Function DrawBitmapPic is use for draw result picture to result window
Function read result picture displayed_Image  and convert it to wxImage and than use
wxWidgets funtion for draw bitmap to panel
displayed_Image must be 3 channel !!!!!!!!
if displayed_Image does not have 3 channel you need to convert it before call this function
otherwise displayed picture will not display correctlly
**********************************************************************************/

void gui_applicationFrame::DrawBitmatPic(void)
{

    wxPaintDC dc(Panel1);
    wxBitmap bitmap1;
//    if(!loop_running) dc.Clear(); // clear panel area, if run loop is running panel area is not clear

try
{
     if(isDisplayedImage) // if displayed image is alocated read it and draw in result panel
     {

wxImage wx_tmp;



  wx_tmp=wxImage(displayed_Image.cols,displayed_Image.rows,displayed_Image.data,true);

       bitmap1= wxBitmap(wx_tmp);
        dc.DrawBitmap(bitmap1,1,1);


     }
}
   catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
     TextVarOut->WriteText(_("OpenCV error in function Draw bitmap picture:\n"));
    TextVarOut->WriteText(pv);
    }
}

/*********************************************************************
Function is call everytime when system needs draw window. Function call
function DrawBitmapPic and draw bitmap to result panel.
***********************************************************************/
void gui_applicationFrame::OnPanelPaint(wxPaintEvent& event)
{

DrawBitmatPic();

}

/**
Function is executed when timer expire ( reach loop time)
Till timer will stopeed
**/
void gui_applicationFrame::OnTimer1Trigger(wxTimerEvent& event)
{
  /** Function from EliLib **/
   int ret=EliRunProgramFromLine(loop_start_line); // Function from EliLib.h
  /********************************/
    if(ret==0)TextVarOut->WriteText(_("Run test program OK\n"));
    else if(ret==-1)TextVarOut->WriteText(_("Initial error\n"));
    else TextVarOut->WriteText(EliGetErrorString());

     DisplayOutputParameters();
    if(ret!=0)
    {
    /*** Function from EliLib ***********************/
        EliEndRunFromLine();
   /****************************************************/
         Timer1->Stop();
    delete Timer1;
      Timer1=NULL;
    RunLoop->Enable(true);
    StopLoop->Enable(false);
    }
}
