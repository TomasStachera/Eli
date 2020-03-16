/***************************************************************
 * Name:      eliMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Tomas Stachera (tomas.stachera@gmail.com)
 * Created:   2011-09-27
 * Copyright: Tomas Stachera ()
 * License:The 3-Clause BSD License
 **************************************************************/

#include "eliMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(eliFrame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

#include <wx/msgdlg.h>
#include <wx/numdlg.h>
#include <wx/choicdlg.h>
#include <wx/file.h>
#include <wx/textfile.h>
#include <wx/config.h>
#include <wx/filedlg.h>
#include <wx/font.h>
#include <wx/dc.h>
#include <wx/dcclient.h>
#include <wx/textdlg.h>
#include <wx/busyinfo.h>
#include <wx/filefn.h>
#include <wx/filename.h>
#include <wx/stdpaths.h>
#include <wx/utils.h>
#include "CameraProperties.h"
#include "VariableWindow.h"


/* libraries for get cameras information in linux
It must be instaled v4l-utils libraries
*/
#if defined(__UNIX__)
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>
#endif // defined

#include <wx/platinfo.h>
#include <wx/platform.h>
#include <wx/versioninfo.h>

#define ELI_VERSION_NUMBER "1.0"



//using namespace cv;


//(*IdInit(eliFrame)
const long eliFrame::ID_GRID1 = wxNewId();
const long eliFrame::ID_TREECTRL1 = wxNewId();
const long eliFrame::ID_GRID2 = wxNewId();
const long eliFrame::ID_TEXTCTRL2 = wxNewId();
const long eliFrame::ID_PANEL2 = wxNewId();
const long eliFrame::ID_TEXTCTRL1 = wxNewId();
const long eliFrame::ID_PANEL1 = wxNewId();
const long eliFrame::idNewProgram = wxNewId();
const long eliFrame::idOpenProgram = wxNewId();
const long eliFrame::idSaveProgram = wxNewId();
const long eliFrame::idMenuQuit = wxNewId();
const long eliFrame::idAddCmd = wxNewId();
const long eliFrame::idChangeCmd = wxNewId();
const long eliFrame::idCompyCmd = wxNewId();
const long eliFrame::idDeleteCmd = wxNewId();
const long eliFrame::idComentsCmd = wxNewId();
const long eliFrame::idRun = wxNewId();
const long eliFrame::idMenRunLoop = wxNewId();
const long eliFrame::idMenuStopLoop = wxNewId();
const long eliFrame::idSetBreak = wxNewId();
const long eliFrame::idRemoveBreak = wxNewId();
const long eliFrame::idRemoveAll = wxNewId();
const long eliFrame::idDebug = wxNewId();
const long eliFrame::idStep = wxNewId();
const long eliFrame::idContinue = wxNewId();
const long eliFrame::idStopDebug = wxNewId();
const long eliFrame::ID_FIND_CAMERA = wxNewId();
const long eliFrame::ID_VIEW_CAMERA = wxNewId();
const long eliFrame::ID_VIEW_UNDISTR = wxNewId();
const long eliFrame::ID_CAM_SNAPSHOT = wxNewId();
const long eliFrame::ID_STOP_CAMERA = wxNewId();
const long eliFrame::idCalibrateCamera = wxNewId();
const long eliFrame::idCamProperties = wxNewId();
const long eliFrame::idMenuAbout = wxNewId();
const long eliFrame::idCommandHelp = wxNewId();
const long eliFrame::idHelp = wxNewId();
const long eliFrame::ID_STATUSBAR1 = wxNewId();
const long eliFrame::idOpen = wxNewId();
const long eliFrame::idSave = wxNewId();
const long eliFrame::idNew = wxNewId();
const long eliFrame::idToolRunTestPrg = wxNewId();
const long eliFrame::idToSetBreak = wxNewId();
const long eliFrame::idTolRemovBreak = wxNewId();
const long eliFrame::idTolRemoveAllBreak = wxNewId();
const long eliFrame::idToolDebug = wxNewId();
const long eliFrame::idToolStep = wxNewId();
const long eliFrame::idToolContinue = wxNewId();
const long eliFrame::idToolStopDeb = wxNewId();
const long eliFrame::idRunLoop = wxNewId();
const long eliFrame::idStopLoop = wxNewId();
const long eliFrame::ID_TOOLBAR1 = wxNewId();
//*)
const long eliFrame::ID_MENU_VARIABLE=wxNewId();
const long eliFrame::ID_TIMER1=wxNewId();
const long eliFrame::ID_GAUGE1=wxNewId();
const long eliFrame::ID_STAT=wxNewId();
const long eliFrame::ID_TOOLBAR2 = wxNewId();
const long eliFrame::id_toolbar_add = wxNewId();
const long eliFrame::id_toolbar_change = wxNewId();
const long eliFrame::id_toolbar_delete = wxNewId();
const long eliFrame::id_toolbar_copy= wxNewId();
const long eliFrame::id_toolbar_coments= wxNewId();
const long eliFrame::ID_TIMER2=wxNewId();
const long eliFrame::ID_TIMER3=wxNewId();

BEGIN_EVENT_TABLE(eliFrame,wxFrame)
    //(*EventTable(eliFrame)
    //*)
END_EVENT_TABLE()

//(*IdInit(help_info)
const long help_info::ID_STATICTEXT1 = wxNewId();
const long help_info::ID_STATICTEXT2 = wxNewId();
const long help_info::ID_STATICTEXT3 = wxNewId();
const long help_info::ID_STATICTEXT4 = wxNewId();
const long help_info::ID_STATICTEXT5 = wxNewId();
const long help_info::ID_STATICTEXT6 = wxNewId();
const long help_info::ID_TEXTCTRL1 = wxNewId();
const long help_info::ID_BUTTON1 = wxNewId();
const long help_info::ID_BUTTON2 = wxNewId();
const long help_info::ID_HYPERLINKCTRL1 = wxNewId();
const long help_info::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(help_info,wxDialog)
	//(*EventTable(help_info)
	//*)
END_EVENT_TABLE()

eliFrame::eliFrame(wxWindow* parent,wxWindowID id)
{
    cv::setBreakOnError(false);
wxFileName f(wxStandardPaths::Get().GetExecutablePath());
actual_dir=f.GetPath();
#if defined(__UNIX__)
actual_dir=actual_dir.BeforeLast('/');
actual_dir+=wxT("/share/Eli");
#elif defined(__WXMSW__)
actual_dir=actual_dir.BeforeLast('\\');
actual_dir+=wxT("\\share\\Eli");
#endif



    try
    {

    //(*Initialize(eliFrame)
    wxBoxSizer* BoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxMenuItem* MenuItem5;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxMenu* Menu3;
    wxMenuItem* MenuItem1;
    wxBoxSizer* BoxSizer2;
    wxMenuItem* MenuItem13;
    wxMenu* Menu1;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer6;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu2;
    wxStaticBoxSizer* StaticBoxSizer5;
    wxMenuItem* MenuItem9;
    wxMenu* Menu5;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(actual_dir+_("/icons/eli_icon.png"))));
    	//FrameIcon.LoadFile(actual_dir+_("/icons/eli_icon.ico"),wxBITMAP_TYPE_ICO_RESOURCE);
    	SetIcon(FrameIcon);
    }
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Test program"));
    Grid2 = new wxGrid(Panel1, ID_GRID1, wxDefaultPosition, wxDefaultSize,0, _T("ID_GRID1"));
    Grid2->CreateGrid(0,2);
    wxFont Grid2Font(13,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Grid2->SetFont(Grid2Font);
    Grid2->EnableEditing(true);
    Grid2->EnableGridLines(true);
    Grid2->SetDefaultRowSize(25, true);
    Grid2->SetDefaultCellFont( Grid2->GetFont() );
    Grid2->SetDefaultCellTextColour( Grid2->GetForegroundColour() );
    StaticBoxSizer4->Add(Grid2, 1, wxALL|wxEXPAND, 0);
    BoxSizer5->Add(StaticBoxSizer4, 2, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(BoxSizer5, 1, wxALL|wxEXPAND, 0);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Commands"));
    TreeCtrl1 = new wxTreeCtrl(Panel1, ID_TREECTRL1, wxDefaultPosition, wxDefaultSize, wxTR_HIDE_ROOT|wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL1"));
    StaticBoxSizer3->Add(TreeCtrl1, 1, wxALL|wxEXPAND, 5);
    BoxSizer6->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer5 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Selected command"));
    Grid1 = new wxGrid(Panel1, ID_GRID2, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID2"));
    Grid1->CreateGrid(0,2);
    Grid1->EnableEditing(true);
    Grid1->EnableGridLines(true);
    Grid1->SetDefaultCellFont( Grid1->GetFont() );
    Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
    StaticBoxSizer5->Add(Grid1, 2, wxALL|wxEXPAND, 0);
    StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Command description"));
    CommentsCmd = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticBoxSizer6->Add(CommentsCmd, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer5->Add(StaticBoxSizer6, 1, wxALL|wxEXPAND, 5);
    BoxSizer6->Add(StaticBoxSizer5, 2, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(BoxSizer6, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Picture"));
    Panel2 = new wxPanel(Panel1, ID_PANEL2, wxDefaultPosition, wxSize(485,159), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    StaticBoxSizer1->Add(Panel2, 1, wxALL|wxEXPAND, 0);
    BoxSizer4->Add(StaticBoxSizer1, 2, wxALL|wxEXPAND, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Output"));
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticBoxSizer2->Add(TextCtrl1, 1, wxALL|wxEXPAND, 0);
    BoxSizer4->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer4, 1, wxALL|wxEXPAND, 0);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuINewProgram = new wxMenuItem(Menu1, idNewProgram, _("New Program"), _("New program"), wxITEM_NORMAL);
    MenuINewProgram->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/new_button.png"))));
    Menu1->Append(MenuINewProgram);
    MenuOpenProg = new wxMenuItem(Menu1, idOpenProgram, _("Open Program"), _("Open Test program"), wxITEM_NORMAL);
    MenuOpenProg->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/open.png"))));
    Menu1->Append(MenuOpenProg);
    MenuSaveProg = new wxMenuItem(Menu1, idSaveProgram, _("Save Program"), _("Save test program"), wxITEM_NORMAL);
    MenuSaveProg->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/Save2.png"))));
    Menu1->Append(MenuSaveProg);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu5 = new wxMenu();
    MenuItem5 = new wxMenuItem(Menu5, idAddCmd, _("Add command\tF9"), _("Add new command"), wxITEM_NORMAL);
    MenuItem5->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/add_button_s.png"))));
    Menu5->Append(MenuItem5);
    MenuItem6 = new wxMenuItem(Menu5, idChangeCmd, _("Change command\tF10"), _("Change selected command"), wxITEM_NORMAL);
    MenuItem6->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/change_but_s.png"))));
    Menu5->Append(MenuItem6);
    MenuItem7 = new wxMenuItem(Menu5, idCompyCmd, _("Copy commands\tctrl+C"), _("Copy selected commands"), wxITEM_NORMAL);
    MenuItem7->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/copy_button_s.png"))));
    Menu5->Append(MenuItem7);
    MenuItem8 = new wxMenuItem(Menu5, idDeleteCmd, _("Delete command"), _("Delete selected command"), wxITEM_NORMAL);
    MenuItem8->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/delete_but_s.png"))));
    Menu5->Append(MenuItem8);
    MenuItem9 = new wxMenuItem(Menu5, idComentsCmd, _("Edit coments"), _("Edit program comments"), wxITEM_NORMAL);
    MenuItem9->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/coments_s.png"))));
    Menu5->Append(MenuItem9);
    MenuBar1->Append(Menu5, _("Edit"));
    Menu3 = new wxMenu();
    MenuIRun = new wxMenuItem(Menu3, idRun, _("Run"), _("RunTestProgram"), wxITEM_NORMAL);
    MenuIRun->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/run_button.png"))));
    Menu3->Append(MenuIRun);
    Menu3->AppendSeparator();
    MenuItem3 = new wxMenuItem(Menu3, idMenRunLoop, _("Run loop"), _("Run loop"), wxITEM_NORMAL);
    MenuItem3->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/run_loop_button.png"))));
    Menu3->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu3, idMenuStopLoop, _("Stop loop"), _("Stop loop"), wxITEM_NORMAL);
    MenuItem4->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/stop_loop.png"))));
    Menu3->Append(MenuItem4);
    MenuItem4->Enable(false);
    MenuBar1->Append(Menu3, _("Run"));
    Menu4 = new wxMenu();
    MenuISetBreak = new wxMenuItem(Menu4, idSetBreak, _("Set Break\tF3"), _("Set break to selected line"), wxITEM_NORMAL);
    MenuISetBreak->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/set_break_button.png"))));
    Menu4->Append(MenuISetBreak);
    MenuIRemoveBreak = new wxMenuItem(Menu4, idRemoveBreak, _("Remove Break\tF4"), _("Remove break on selected line"), wxITEM_NORMAL);
    MenuIRemoveBreak->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/clear_break_button.png"))));
    Menu4->Append(MenuIRemoveBreak);
    MenuRemoveAllBreak = new wxMenuItem(Menu4, idRemoveAll, _("Remove all break"), _("Remove all break"), wxITEM_NORMAL);
    MenuRemoveAllBreak->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/clearAll_break_button.png"))));
    Menu4->Append(MenuRemoveAllBreak);
    Menu4->AppendSeparator();
    MenuIDebug = new wxMenuItem(Menu4, idDebug, _("Debug\tF5"), _("Run debug mode"), wxITEM_NORMAL);
    MenuIDebug->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/debug_button.png"))));
    Menu4->Append(MenuIDebug);
    MenuIStep = new wxMenuItem(Menu4, idStep, _("Step\tF6"), _("Run one step"), wxITEM_NORMAL);
    MenuIStep->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/step_button.png"))));
    Menu4->Append(MenuIStep);
    MenuIStep->Enable(false);
    MenuContinue = new wxMenuItem(Menu4, idContinue, _("Continue\tF7"), _("Continue to next break"), wxITEM_NORMAL);
    MenuContinue->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/cont_button.png"))));
    Menu4->Append(MenuContinue);
    MenuContinue->Enable(false);
    MenuIStopDebuger = new wxMenuItem(Menu4, idStopDebug, _("Stop debuger"), _("Stop debuger"), wxITEM_NORMAL);
    MenuIStopDebuger->SetBitmap(wxBitmap(wxImage(actual_dir+_("/icons/stop_but.png"))));
    Menu4->Append(MenuIStopDebuger);
     MenuIStopDebuger->Enable(false);
    variable_window=new wxMenuItem(Menu4, ID_MENU_VARIABLE, _("Variable window\tF8"), _("Display variable window"), wxITEM_NORMAL);
    Menu4->Append(variable_window);
    MenuBar1->Append(Menu4, _("Debug"));
    Menu6 = new wxMenu();
    MenuItem10 = new wxMenuItem(Menu6, ID_FIND_CAMERA, _("Find camera"), _("Find all connected camera"), wxITEM_NORMAL);
    Menu6->Append(MenuItem10);
    MenuItem11 = new wxMenuItem(Menu6, ID_VIEW_CAMERA, _("View camera"), _("View selected camera"), wxITEM_NORMAL);
    Menu6->Append(MenuItem11);
    MenuItem14 = new wxMenuItem(Menu6, ID_VIEW_UNDISTR, _("View camera undistor"), _("View camera undistortion"), wxITEM_NORMAL);
    Menu6->Append(MenuItem14);
    MenuItem15 = new wxMenuItem(Menu6, ID_CAM_SNAPSHOT, _("Snapshot\tF2"), _("MAke snapshot from camera"), wxITEM_NORMAL);
    Menu6->Append(MenuItem15);
    MenuItem12 = new wxMenuItem(Menu6, ID_STOP_CAMERA, _("Stop camera"), _("Stop camera running"), wxITEM_NORMAL);
    Menu6->Append(MenuItem12);
    MenuItem12->Enable(false);
    MenuItem13 = new wxMenuItem(Menu6, idCalibrateCamera, _("Calibrate camera"), _("Calibrate camera"), wxITEM_NORMAL);
    Menu6->Append(MenuItem13);
    MenuItem16 = new wxMenuItem(Menu6, idCamProperties, _("Properties"), _("Display properties window"), wxITEM_NORMAL);
    Menu6->Append(MenuItem16);
    MenuBar1->Append(Menu6, _("Cameras"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
     help_menu= new wxMenuItem(Menu2, idHelp, _("Documentation"), _("Show documentation page"), wxITEM_NORMAL);
      Menu2->Append(help_menu);
    CommandHelp = new wxMenuItem(Menu2, idCommandHelp, _("Command help\tF1"), _("Display command help selected command"), wxITEM_NORMAL);
    CommandHelp->SetBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_HELP")),wxART_OTHER));
    Menu2->Append(CommandHelp);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    ToolBar1 = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL|wxTB_NOALIGN|wxNO_BORDER, _T("ID_TOOLBAR1"));
    ToolBarItem1 = ToolBar1->AddTool(idOpen, _("Open"),wxBitmap(wxImage(actual_dir+_("/icons/open.png"))) ,wxBitmap(wxImage(actual_dir+_("/icons/open_dis.png"))) , wxITEM_NORMAL, _("Open test program"), _("Open test program"));
    ToolBarItem2 = ToolBar1->AddTool(idSave, _("Save"),wxBitmap(wxImage(actual_dir+_("/icons/Save2.png"))),wxBitmap(wxImage(actual_dir+_("/icons/Save2_dis.png"))) , wxITEM_NORMAL, _("Save Test program"), _("Save Test program"));
    ToolBarItem3 = ToolBar1->AddTool(idNew, _("New"),wxBitmap(wxImage(actual_dir+_("/icons/new_button.png"))),wxBitmap(wxImage(actual_dir+_("/icons/new_button_dis.png"))) , wxITEM_NORMAL, _("New Test program"), _("Open New test program"));
    ToolBar1->AddSeparator();
    ToolBarItem4 = ToolBar1->AddTool(idToolRunTestPrg, _("Run"),wxBitmap(wxImage(actual_dir+_("/icons/run_button.png"))),wxBitmap(wxImage(actual_dir+_("/icons/run_button_dis.png"))) , wxITEM_NORMAL, _("Run Test program"), _("Run Test program"));
    ToolBar1->AddSeparator();
    ToolBarItem5 = ToolBar1->AddTool(idToSetBreak, _("SetBreak"),wxBitmap(wxImage(actual_dir+_("/icons/set_break_button.png"))),wxBitmap(wxImage(actual_dir+_("/icons/set_break_button_dis.png"))) , wxITEM_NORMAL, _("Set break"), _("Set break"));
    ToolBarItem6 = ToolBar1->AddTool(idTolRemovBreak, _("Clear"),wxBitmap(wxImage(actual_dir+_("/icons/clear_break_button.png"))),wxBitmap(wxImage(actual_dir+_("/icons/clear_break_button_dis.png"))) , wxITEM_NORMAL, _("Remove break"), _("Remove break"));
    ToolBarItem7 = ToolBar1->AddTool(idTolRemoveAllBreak, _("Clear All"),wxBitmap(wxImage(actual_dir+_("/icons/clearAll_break_button.png"))),wxBitmap(wxImage(actual_dir+_("/icons/clearAll_break_button_dis.png"))) , wxITEM_NORMAL, _("Remove all breaks"), _("Remove all breaks"));
    ToolBar1->AddSeparator();
    ToolBarItem8 = ToolBar1->AddTool(idToolDebug, _("Debug"),wxBitmap(wxImage(actual_dir+_("/icons/debug_button.png"))),wxBitmap(wxImage(actual_dir+_("/icons/debug_button_dis.png"))),wxITEM_NORMAL, _("Debug"), _("Debug"));
    ToolBarItem9 = ToolBar1->AddTool(idToolStep, _("Step"),wxBitmap(wxImage(actual_dir+_("/icons/step_button.png"))),wxBitmap(wxImage(actual_dir+_("/icons/step_button_dis.png"))) , wxITEM_NORMAL, _("Run one step"), _("Run one step"));
    ToolBarItem10 = ToolBar1->AddTool(idToolContinue, _("Continue"),wxBitmap(wxImage(actual_dir+_("/icons/cont_button.png"))),wxBitmap(wxImage(actual_dir+_("/icons/cont_button_dis.png"))) , wxITEM_NORMAL, _("Continue"), _("Continue to the next break"));
    ToolBarItem11 = ToolBar1->AddTool(idToolStopDeb, _("Stop"),wxBitmap(wxImage(actual_dir+_("/icons/stop_but.png"))),wxBitmap(wxImage(actual_dir+_("/icons/stop_but_dis.png"))) , wxITEM_NORMAL, _("Stop debuger"), _("Stop debuger"));
    ToolBar1->AddSeparator();
    ToolBar1->AddSeparator();
    ToolBarItem12 = ToolBar1->AddTool(idRunLoop, _("Run loop"), wxBitmap(wxImage(actual_dir+_("/icons/run_loop_button.png"))),wxBitmap(wxImage(actual_dir+_("/icons/run_loop_button_dis.png"))) , wxITEM_NORMAL, _("Run loop"), _("Run loop"));
    ToolBarItem13 = ToolBar1->AddTool(idStopLoop, _("Stop loop"),wxBitmap(wxImage(actual_dir+_("/icons/stop_loop.png"))) ,wxBitmap(wxImage(actual_dir+_("/icons/stop_loop_dis.png"))) , wxITEM_NORMAL, _("Stop loop"), _("Stop loop"));
    ToolBar1->AddSeparator();
    ToolBar1->AddSeparator();
    gaug=new wxGauge(ToolBar1,ID_GAUGE1,10);
  stat=new wxStaticText(ToolBar1,ID_STAT,_("Stand by"),wxDefaultPosition,wxSize(300,13));
    stat->SetForegroundColour(wxColour(0,0,255));
    stat->SetFont(wxFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD));
    ToolBar1->AddControl(gaug);
   ToolBar1->AddSeparator();
     ToolBar1->AddSeparator();
    ToolBar1->AddControl(stat);
     ToolBar1->EnableTool(idToolContinue,false);
  ToolBar1->EnableTool(idToolStopDeb,false);
  ToolBar1->EnableTool(idToolStep,false);
  ToolBar1->EnableTool(idStopLoop,false);
    ToolBar1->Realize();
    SetToolBar(ToolBar1);
     ToolBar2 = new wxToolBar(this, ID_TOOLBAR2, wxDefaultPosition, wxDefaultSize, wxTB_VERTICAL|wxTB_FLAT|wxTB_TEXT);
 ToolBar2->SetMargins(4,4);
 ToolBarAddCmd = ToolBar2->AddTool(id_toolbar_add, _("Add"),wxBitmap(wxImage(actual_dir+_("/icons/add_button.png"))),_("Add command after selected line"));
 ToolBarChangeCmd = ToolBar2->AddTool(id_toolbar_change, _("Change"),wxBitmap(wxImage(actual_dir+_("/icons/change_but.png"))),_("Save actual command chenges"));
 ToolBarDeleteCmd = ToolBar2->AddTool(id_toolbar_delete, _("Delete"),wxBitmap(wxImage(actual_dir+_("/icons/delete_but.png"))),_("Delete selected command line"));
 ToolBarCopyCmd = ToolBar2->AddTool(id_toolbar_copy, _("Copy"),wxBitmap(wxImage(actual_dir+_("/icons/copy_button.png"))),_("Copy commands"));
 ToolBar2->AddSeparator();
 ToolBar2->AddSeparator();
  ToolBarComments = ToolBar2->AddTool(id_toolbar_coments, _(""),wxBitmap(wxImage(actual_dir+_("/icons/coments.png"))),_("Edit comments"));
  ToolBar2->AddSeparator();
  ToolBar2->AddSeparator();
 ToolBar2->Realize();
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_GRID1,wxEVT_GRID_LABEL_LEFT_CLICK,(wxObjectEventFunction)&eliFrame::OnGrid2CellSelect);
    Connect(ID_GRID1,wxEVT_GRID_SELECT_CELL,(wxObjectEventFunction)&eliFrame::OnGrid2CellSelect);
    Grid2->Connect(wxEVT_SIZE,(wxObjectEventFunction)&eliFrame::OnGrid2Resize,0,this);
    Connect(ID_GRID2,wxEVT_GRID_CELL_LEFT_CLICK,(wxObjectEventFunction)&eliFrame::OnGrid1CellLeftClick);
    Grid1->Connect(wxEVT_SIZE,(wxObjectEventFunction)&eliFrame::OnGrid1Resize,0,this);
    Panel2->Connect(wxEVT_PAINT,(wxObjectEventFunction)&eliFrame::OnPanel2Paint,0,this);
    Connect(idNewProgram,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuINewProgramSelected);
    Connect(idOpenProgram,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuOpenProgSelected);
    Connect(idSaveProgram,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuSaveProgSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnQuit);
    Connect(idAddCmd,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnClickAddNewCommand);
    Connect(idChangeCmd,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnClickChangeCommand);
    Connect(idCompyCmd,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnClickCopyCommand);
    Connect(idDeleteCmd,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnClickDeleteCommand);
    Connect(idComentsCmd,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuIEditCometsSelected);
    Connect(idRun,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuIRunSelected);
    Connect(idMenRunLoop,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnRunLoopClicked);
    Connect(idMenuStopLoop,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnStopLoopClicked);
    Connect(idSetBreak,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuISetBreakSelected);
    Connect(idRemoveBreak,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuIRemoveBreakSelected);
    Connect(idRemoveAll,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuRemoveAllBreakSelected);
    Connect(idDebug,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuIDebugSelected);
    Connect(idStep,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuIStepSelected);
    Connect(idContinue,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuContinueSelected);
    Connect(idStopDebug,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuIStopDebugerSelected);
    Connect(ID_MENU_VARIABLE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuVariableSelected);
    Connect(ID_FIND_CAMERA,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuFindCameraSelected);
    Connect(ID_VIEW_CAMERA,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuViewCameraSelected);
    Connect(ID_VIEW_UNDISTR,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuViewCameraUndistor);
    Connect(ID_CAM_SNAPSHOT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuSnapshotCamera);
    Connect(ID_STOP_CAMERA,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuStopCamera);
    Connect(idCalibrateCamera,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuCalibrateCamera);
    Connect(idCamProperties,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuItemProperties);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnAbout);
    Connect(idHelp,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnMenuHelpMenu);
    Connect(idCommandHelp,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&eliFrame::OnCommandHelpSelected);
    Connect(idOpen,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnMenuOpenProgSelected);
    Connect(idSave,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnMenuSaveProgSelected);
    Connect(idNew,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnMenuINewProgramSelected);
    Connect(idToolRunTestPrg,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnMenuIRunSelected);
    Connect(idToSetBreak,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnMenuISetBreakSelected);
    Connect(idTolRemovBreak,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnMenuIRemoveBreakSelected);
    Connect(idTolRemoveAllBreak,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnMenuRemoveAllBreakSelected);
    Connect(idToolDebug,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnMenuIDebugSelected);
    Connect(idToolStep,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnMenuIStepSelected);
    Connect(idToolContinue,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnMenuContinueSelected);
    Connect(idToolStopDeb,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnMenuIStopDebugerSelected);
    Connect(idRunLoop,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnRunLoopClicked);
    Connect(idStopLoop,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnStopLoopClicked);
    Connect(wxEVT_SIZE,(wxObjectEventFunction)&eliFrame::OnPanel1Resize);
    //*)

MenuItem15->Enable(false);




 /*********************************************************
 Setup Grid 2 parameters (Test program grid): Label dimensions,
 Collumn dimensions,Name of each collumn, selection mode (must be
 wxGridSelectRows), selection background collor and disable editting
 *********************************************************/

     Grid2->SetColLabelValue(0,_("Command"));
     Grid2->SetColLabelValue(1,_("Description"));
   Grid2->SetSelectionMode(wxGrid::wxGridSelectRows);
    Grid2->SetSelectionBackground(wxColour(136,131,131));
    Grid2->EnableEditing(false);




/**********************************************************************
Setup parameters for command grid: Dimensions, Label name
**********************************************************************/

     Grid1->SetLabelSize(1,1);
     Grid1->SetColLabelValue(0,_("Name"));
     Grid1->SetColLabelValue(1,_("Parameter"));




    InitMainCommands();//Call function for inicialize pointer cmd which is filled command classes
      Maximize(); // Main window is always maximize
     but_gr=NULL; // Set null pointer for position of line in command grid
       im=new wxImageList(32,32); //INicialize ImageList for commands list box
     InsertCommands(); // Call function for insert commands name to command list box
     ins_line=0; // set test program grid line to 0
      loop_running=false;
     tp_prg=new TestProgram(); // Inicialize test program class
      run_tpg=NULL;
        Timer1=NULL;
        Timer2=NULL;

     isDisplayedImage=false;
        guge_cnt=0;
        init_gauge=0;
        gauge_pom=0;
        old_loop_string=_("");
       ob_prg=new ObjectPrograms;

       cam_calib=NULL;
       undistor_view_flag=false;
    first_time_view=false;
    snapshot_cnt=0;
view_cam_seque=0;



LayoutChildren();
SetResize2();
SetResize1();
p_name=wxEmptyString;


Connect(id_toolbar_add,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnClickAddNewCommand);
Connect(id_toolbar_change,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnClickChangeCommand);
Connect(id_toolbar_delete ,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnClickDeleteCommand);
Connect(id_toolbar_copy ,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnClickCopyCommand);
Connect(id_toolbar_coments ,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&eliFrame::OnMenuIEditCometsSelected);
    }

catch(bad_alloc &ba) // catch exception when is memory allocation error
{
ErrorLog er;
wxString mystring(ba.what(), wxConvUTF8);
er.SetError(_("Bad alloc new exception "),mystring);
er.DisplayLog(1);
}
}

void eliFrame::LayoutChildren()
{
 wxSize size = GetClientSize();

    int offset;

        ToolBar2->SetSize(0, 0, wxDefaultCoord, size.y);

        offset = ToolBar2->GetSize().x;


    Panel1->SetSize(offset, 0, size.x - offset, size.y);
}

eliFrame::~eliFrame()
{
    //(*Destroy(eliFrame)
    //*)
    DeleteMainCommands(); // call function which delete commands pointers from memory (function is placed in commands_main.cpp)
    delete im;
    delete ob_prg;
    delete tp_prg;

}
void eliFrame::SetResize2(void)
{
    wxSize sz=Grid2->GetSize();

  float w_percent=(float)sz.GetWidth()/100;
   float col_field[]={35,56};
   Grid2->SetRowLabelSize((int)(6*w_percent));
   for(int i=0;i<2;i++)Grid2->SetColSize(i,(int)(col_field[i]*w_percent));


}
void eliFrame::SetResize1(void)
{
    wxSize sz=Grid1->GetSize();

  float w_percent=(float)sz.GetWidth()/100;
   float col_field[]={30,63};
   Grid1->SetRowLabelSize((int)(5*w_percent));
   for(int i=0;i<2;i++)Grid1->SetColSize(i,(int)(col_field[i]*w_percent));



}

/********************************************************
Function OnQuit is call when button for close main window
is called
********************************************************/
void eliFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

/*******************************************************
Function is call when button About from Help menu is press
Function display about window with information about program
*******************************************************/
void eliFrame::OnAbout(wxCommandEvent& event)
{
   help_info dlg(this);
   dlg.ShowModal();
}

/**
Function display documentation page
**/
void eliFrame::OnMenuHelpMenu(wxCommandEvent& event)
{
      wxString page_name=actual_dir;
page_name+=wxT("/help/index.htm");
  if(!wxLaunchDefaultBrowser(page_name))
     {
         wxMessageBox(wxT("Error load default we browser"),wxT("Error load default browser"),wxICON_ERROR);
     }
}

/**********************************************************************************
Function ComandParam set parameter to command description panel (Grid1)
1.parameter is name of description line. This name will be display in collumn 0
2.parameter is number of line where parameter will be set in command description
panel.
3.parameter is type of parameter which will be set to collumn 1.
       0 = text string will be placed to collumn 1 Change string can be done by write
           to this collumn
       1 = Path to file will be placed to collumn 1. Double click on collumn open
           file open dialog.
       2 = Path to directory will be placed to collumn 1. Double click on collumn
           open directory selection dialog.
       3 = Collour code will be placed to collumn 1. (Format : R,G,B). Double click on
           collumn wil open dialog for collour selection.
       4 = Path to file will be placed to collumn 1. Double click on collumn open
           file save dialog.
4.parameter is overloaded, in this function its string of character and according parameter
3 it can be text,file or directory path, colour code in format (R,G,B).

Function return 0 if all is OK and return -1 if line number is higher as number of lines
in Grid 1;
***********************************************************************************/
int eliFrame::CommandParam(wxString name,unsigned int line,int type,wxString s_val)
{
if(Grid1->GetNumberRows()<=(int)line) return -1;
Grid1->SetCellValue(line,0,name);
Grid1->SetReadOnly(line,0);
Grid1->SetCellValue(line,1,s_val);
 but_gr[line]=type;
 if(type>0)Grid1->SetReadOnly(line,1);
return 0;
}

/**********************************************************************************
Function ComandParam set parameter to command description panel (Grid1)
1.parameter is name of description line. This name will be display in collumn 0
2.parameter is number of line where parameter will be set in command description
panel.
3.parameter is use for setting which string in array is display as default.
4.parameter is overloaded, in this function its array string. String in position set in
parameter 3 is display in collumn 1. Double click on collumn will display choice dialog
with all strings in array where we can select string which will be placed in collumn 1.

Function return 0 if all is OK, return -1 if line number is higher or equal as number
lines in Grid1. Return -2 if type is higher or equal as number of strings in array.
***********************************************************************************/
int eliFrame::CommandParam(wxString name,unsigned int line,int type, wxArrayString val)
{
    try
    {
if(Grid1->GetNumberRows()<=(int)line) return -1;
Grid1->SetCellValue(line,0,name);
Grid1->SetReadOnly(line,0);
int num=val.GetCount();
wxString *s_val=new wxString[num];
for(int i=0;i<num;i++) s_val[i]=val.Item(i);
Grid1->SetCellEditor(line, 1, new wxGridCellChoiceEditor(num,s_val));
if(type>=num)
{
  delete[] s_val;
  return -2;
}
Grid1->SetCellValue(line,1,s_val[type]);

delete[] s_val;
    }

catch(bad_alloc &ba)
{
ErrorLog er;
wxString mystring(ba.what(), wxConvUTF8);
er.SetError(_("Bad alloc new exception "),mystring);
er.DisplayLog(1);
}
return 0;
}

/**********************************************************************************
Function ComandParam set parameter to command description panel (Grid1)
1.parameter is name of description line. This name will be display in collumn 0
2.parameter is number of line where parameter will be set in command description
panel.
3.parameter is not use in this command use always 0.
4.parameter is overloaded, in this function its bool value (true or false)
Function display in collumn 1 checkbox for set bool value.

Function return 0 if all is OK, return -1 if line number is higher or equal as number
lines in Grid1.
***********************************************************************************/

int eliFrame::CommandParam(wxString name,unsigned int line,int type,bool bval)
{
if(Grid1->GetNumberRows()<=(int)line) return -1;
Grid1->SetCellValue(line,0,name);
Grid1->SetReadOnly(line,0);
Grid1->SetCellRenderer(line, 1, new wxGridCellBoolRenderer);
 Grid1->SetCellEditor(line, 1, new wxGridCellBoolEditor);
 if(bval)Grid1->SetCellValue(line,1,_("1"));
 else Grid1->SetCellValue(line,1,_("0"));

return 0;
}


/**********************************************************************************
Function ComandParam set parameter to command description panel (Grid1)
1.parameter is name of description line. This name will be display in collumn 0
2.parameter is number of line where parameter will be set in command description
panel.
3.parameter is not use in this command use always 0.
4.parameter is overloaded, in this function its integer value. This value can be change
directlly in collumn 1.

Function return 0 if all is OK, return -1 if line number is higher or equal as number
lines in Grid1.
***********************************************************************************/

int eliFrame::CommandParam(wxString name,unsigned int line,int type,int ival)
{
if(Grid1->GetNumberRows()<=(int)line) return -1;
Grid1->SetCellValue(line,0,name);
Grid1->SetReadOnly(line,0);
wxString px=_("");
px<<ival;
Grid1->SetCellValue(line,1,px);
return 0;
}


/**********************************************************************************
Function ComandParam set parameter to command description panel (Grid1)
1.parameter is name of description line. This name will be display in collumn 0
2.parameter is number of line where parameter will be set in command description
panel.
3.parameter is not use in this command use always 0.
4.parameter is overloaded, in this function its float value. This value can be change
directlly in collumn 1.

Function return 0 if all is OK, return -1 if line number is higher or equal as number
lines in Grid1.
***********************************************************************************/

int eliFrame::CommandParam(wxString name,unsigned int line,int type,float fval)
{
if(Grid1->GetNumberRows()<=(int)line) return -1;
Grid1->SetCellValue(line,0,name);
Grid1->SetReadOnly(line,0);
wxString px=_("");
px<<fval;
Grid1->SetCellValue(line,1,px);
return 0;
}


/*********************************************************************
Function is called when user left click on command grid (Grid1)
This function is use for change some parameters  in commands grid
Function check variable in but_gr field parameter. This parameter
has postion in field which means line number for example but_gr[2] means line 2
Variable in each array elements means type of events which should be
display  in specified line. This parameter is set in CommandParam function.
Param 1 - Display Open file dialog
Param 2 - Display Select directory dialog
Param 3 - Display Colour selection dialog window
Param 4 - Display Save file dialog
*********************************************************************/
void eliFrame::OnGrid1CellLeftClick(wxGridEvent& event)
{
       if( but_gr==NULL) // if no param is set in Function CommandParam
  {
      wxMessageBox(_("Error read grid position"),_("Error"),wxICON_ERROR);
      return;
  }
  int y=event.GetRow();
  event.Skip();
  wxString pom=Grid1->GetCellValue(y,1);
   if(but_gr[y]==1) //Display Open file dialog
   {
   wxString caption=wxT("choose file");
   wxString wildcard=wxT("All (*.*)|*.*"); //display all files with all extensions
   wxString default_dir=pom.BeforeLast('\\');
   wxString default_file=pom.AfterLast('\\');
   wxFileDialog dialog(this, caption, default_dir, default_file,wildcard, wxFD_OPEN);
   if (dialog.ShowModal() == wxID_OK)
    {
    wxString path = dialog.GetPath();
    Grid1->SetCellValue(y,1,path); // Set new path to command grid line
   }

   }
    if(but_gr[y]==2) //Display Select directory dialog
    {
        wxString defaultPath=pom;
        wxDirDialog dialog(this,wxT("Select directory"),defaultPath, wxDD_NEW_DIR_BUTTON);
    if (dialog.ShowModal() == wxID_OK)
     {
      wxString path = dialog.GetPath();
      Grid1->SetCellValue(y,1,path); //Set new path to command grid line
      }

    }

    if(but_gr[y]==3) //Display collour dialog window
    {
        wxColourDialog dialog(this);
         if(dialog.ShowModal() == wxID_OK)
         {
          wxColourData dat=dialog.GetColourData();
          wxColour dcolour=dat.GetColour();
          wxString out=_("");
          out<<(int)dcolour.Red();
          out+=_(",");
          out<<(int)dcolour.Green();
          out+=_(",");
          out<<(int)dcolour.Blue();
          Grid1->SetCellValue(y,1,out); // Colour code is display in command grid line in format (R,G,B) R,G,B means unsigned char value of each colour
         }

    }
       if(but_gr[y]==4) //Display Save file dialog window
   {
   wxString caption=wxT("choose file to save");
   wxString wildcard=wxT("All (*.*)|*.*");
   wxString default_dir=pom.BeforeLast('\\');
   wxString default_file=pom.AfterLast('\\');
   wxFileDialog dialog(this, caption, default_dir, default_file,wildcard, wxFD_SAVE);
   if (dialog.ShowModal() == wxID_OK)
    {
    wxString path = dialog.GetPath();
    Grid1->SetCellValue(y,1,path);
   }

   }
}



/************************************************************************
Function InsertCommands, inserts list of commands to  commands tree Ctrl
Function return 0 if there is no error and -1 if no commands group was found
************************************************************************/

int eliFrame::InsertCommands(void)
{

 // im->Add(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_NEW"))),wxART_OTHER); //Get icon for command group
 //   im->Add(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_NEW"))),wxART_OTHER); //Get icon for each command

im->Add(wxBitmap(wxImage(actual_dir+_("/icons/tree1.png")))); //Get icon for command group
im->Add(wxBitmap(wxImage(actual_dir+_("/icons/tree2.png")))); //Get icon for each command

  TreeCtrl1->SetImageList(im);
//  TreeCtrl1->SetButtonsImageList(im);


/* Function inicialize command base structure where all commands in commands list box
are placed. Structure commnd_base has same number of elements as number of commands.
Function set to structure  all command name , position of command and group and command name*/

   for(int i=0;i<NUMBER_COMMANDS_CLASS;i++)
   {
       comnd_base[i].name=cmd[i]->ReturnClassname();
       comnd_base[i].pos=i;
       comnd_base[i].group_name=cmd[i]->ReturnClassname().BeforeFirst('_');
       comnd_base[i].cmd_name=cmd[i]->ReturnClassname().AfterFirst('_');
   }


  int cnt=0;

  wxString base_name;

/*Calculation number of commadns groups*/
  for(int i=0;i<NUMBER_COMMANDS_CLASS;i++)
  {
     if(i==0)
     {
         base_name=comnd_base[i].group_name;
         cnt++;
     }
     else
     {
      if(base_name != comnd_base[i].group_name)
      {
         base_name=comnd_base[i].group_name;
         cnt++;
      }
     }
  }

  if(cnt==0) // No group was found
  {
      ErrorLog er;
   er.SetError(_("Group name error"),_("Can not find any group name"));
   er.DisplayLog();
    return -1;
  }

  try
  {
wxTreeItemId id0=TreeCtrl1->AddRoot(_("Commands")) ;
  wxTreeItemId *idx=new wxTreeItemId[cnt]; //Allocate subtree items


/*  Insert commands to command list box according groups */
  cnt=0;
  for(int i=0;i<NUMBER_COMMANDS_CLASS;i++)
  {
   if(i==0)
   {
     base_name=comnd_base[i].group_name;
     idx[cnt]=TreeCtrl1->AppendItem(id0,base_name,0) ;
      TreeCtrl1->AppendItem(idx[cnt],comnd_base[i].cmd_name,1);
   }
   else
   {
     if(base_name != comnd_base[i].group_name)
     {
         cnt++;
       base_name=comnd_base[i].group_name;
      idx[cnt]=TreeCtrl1->AppendItem(id0,base_name,0) ;
      TreeCtrl1->AppendItem(idx[cnt],comnd_base[i].cmd_name,1);
     }
     else
     {
      TreeCtrl1->AppendItem(idx[cnt],comnd_base[i].cmd_name,1);
     }
   }
  }




  delete[] idx;
}

  catch(bad_alloc &ba)//Catch allocation memory error
   {
ErrorLog er;
wxString mystring(ba.what(), wxConvUTF8);
er.SetError(_("Bad alloc new exception wxTree Ctrl"),mystring);
er.DisplayLog(1);
  }
    return 0;
}



/*********************************************************************
******* Function is activated by clict on button Add *****************
******* Function display command parameters on selected commands******
******* and insert selected function to the next line after cursor ***
*********************************************************************/

void eliFrame::OnClickAddNewCommand(wxCommandEvent& event)
{
       wxTreeItemId id=TreeCtrl1->GetSelection(); // Read command name from command list box
   wxTreeItemId idp=TreeCtrl1->GetItemParent(id); // Get group number of selected command

   wxString cmdstr=TreeCtrl1->GetItemText(idp);
   cmdstr+=_("_");
   cmdstr+=TreeCtrl1->GetItemText(id);

   int cnt=0,end_find=0;

   if(but_gr != NULL) delete[]but_gr;

   ClearAllBreaks();

try
{
   while(end_find==0)
   {
     if(comnd_base[cnt].name == cmdstr)end_find=1; // Find command in structure comnd_base
     else cnt++;

      if(cnt>= NUMBER_COMMANDS_CLASS) throw "Can not find selected command in list of commands";
   }

   wxString name,str;
   wxArrayString araystring;
   int type,ival,type2;
   bool bval;
   float fval;
   int r_val=0;


   Grid1->ClearGrid();
  if(Grid1->GetNumberRows()>0) Grid1->DeleteRows(0,Grid1->GetNumberRows()); // Delete all rows in command grid
   Grid1->InsertRows(0,cmd[cnt]->GetCmdNumberLines()); //Insert lines to command grid

   but_gr=new int[cmd[cnt]->GetCmdNumberLines()];
   for(int i=0;i<cmd[cnt]->GetCmdNumberLines();i++)but_gr[i]=0;

/* Read parameters for commands grid to all lines*/
   for(int i=0;i<cmd[cnt]->GetCmdNumberLines();i++)
   {
     if(cmd[cnt]->GetLineParam(i,name,type,araystring,str,ival,fval,bval,type2)==0)
     {

       if(type==1)r_val=CommandParam(name,i,type2,str);
       if(type==2)r_val=CommandParam(name,i,type2,araystring);
       if(type==3)r_val=CommandParam(name,i,type2,bval);
       if(type==4)r_val=CommandParam(name,i,type2,ival);
       if(type==5)r_val=CommandParam(name,i,type2,fval);


       if((type<1)||(type>5)||(r_val!=0))
       {
        wxString px=_("Error in function GetLineParam, ClassName:");
        px+=cmd[cnt]->ReturnClassname();
        px+=_("\nLine number: ");
        px<<i;
         if((type<1)||(type>5)) px+=_("\nBad type number (type must be in range 1 to 5)");
         if(r_val!=0) // Generate error code
        {
         px+=_("\nError in function CommandParam with type :");
         px<<type;
         px+=_("\nReturn error code :");
         px<<r_val;

        }
        char pk[400]={0};
        strncpy(pk,(const char*)px.mb_str(wxConvUTF8),400);
         throw pk;
       }

     }
     else
     {
        wxString px=_("Error in function GetLineParam, ClassName:");
        px+=cmd[cnt]->ReturnClassname();
        px+=_("\nLine number: ");
        px<<i;
        char pk[300]={0};
        strncpy(pk,(const char*)px.mb_str(wxConvUTF8),300);
         throw pk;
     }
   }
   wxArrayInt ix;
   int y=0;
   ix.Empty();
   ix=Grid2->GetSelectedRows();
   if(ix.GetCount()<1)y=0;
   else y=ix[0]+1;

          ins_line=y;

              wxString paramGrid2=cmd[cnt]->ReturnClassname();
          paramGrid2+=GetCommandParam();

            //Set command to test program class and update test program grid
            CommentsCmd->Clear();
          if(tp_prg->SetProgram(y+1,paramGrid2)==0) UpdateGrid(1);
          else throw "Error Set program";
}

catch(const char *exception)
{
  ErrorLog er;
  wxString erstring(exception,wxConvUTF8);
 er.SetError(_("Error in function OnAddCommandClick"),erstring);
er.DisplayLog();
}
}




/**********************************************************
 Function update test program grid
 Function return always 0

**********************************************************/
int eliFrame::UpdateGrid(int rx)
{
    Grid2->InsertRows(0,rx); // Insert number of lines to test program grid


 for(int i=0;i<tp_prg->GetLineNumber();i++) // Insert all  commands to test program grid according TestProgram class
 {
    Grid2->SetCellValue(i,0,tp_prg->GetCmd(i+1));
    Grid2->SetCellValue(i,1,tp_prg->GetDescription(i+1));

 }

 if(Grid2->GetNumberRows()>0)Grid2->SelectRow(ins_line);

 return 0;
}

/**************************************************************************
Function generated command parameters from command grid
Function check if character # is in some grid line, becouse character #
is use as delimiter between commands parameter.
Function read parameters from each line and insert character # as delimeter
between parameters.
Function return command parameter
**************************************************************************/
wxString eliFrame::GetCommandParam(void)
{
 wxString ret_val=_("");

try
{
for(int i=0;i<Grid1->GetNumberRows();i++)
{
    ret_val+=_("#");
    if(Grid1->GetCellValue(i,1).Find('#')!=-1)
{
         throw "Character # is prohibeted in command parameter";
    }
    if(Grid1->GetCellValue(i,1).Length()==0) ret_val+=_("0");
 else ret_val+=Grid1->GetCellValue(i,1);
}
}
catch(const char *exception)
{
 throw ;
}
return ret_val;
}

/****************************************************************
Function is call when user click on Change button
Function update test program according parameters in
command grid
****************************************************************/


void eliFrame::OnClickChangeCommand(wxCommandEvent& event)
{
        try
    {
      if(Grid1->GetRows()>0) Grid1->SetGridCursor(0,0);
   wxArrayInt ix;
   int y=0;
   ix.Empty();
   ix=Grid2->GetSelectedRows();
   if(ix.GetCount()<1)y=0;
   else y=ix[0]+1;

          ins_line=y;

              wxString paramGrid2=Grid2->GetCellValue(y-1,0);
              wxString description=wxEmptyString;
              description=CommentsCmd->GetValue();
              if(description.Find('#')!=-1) throw "Character # is prohibeted in description";
              if(description.Length()>1)
              {
                 paramGrid2+=_(" ");
                 paramGrid2+=description;
              }
            paramGrid2+=GetCommandParam(); // Get command parameter according command grid

         if(wxMessageBox(_("Do you want change command parameter?"),_("Question"),wxICON_QUESTION | wxYES_NO)==wxYES)
         {
          if(tp_prg->SetProgram(y,paramGrid2,1)!=0)throw "Error Set program"; // Add test program to tp_prg class
          Grid2->SetCellValue(y-1,1,description);
         }

    }

  catch(const char *exception)
{
  ErrorLog er;
  wxString erstring(exception,wxConvUTF8);
 er.SetError(_("Error in function EditCommandClick"),erstring);
er.DisplayLog();
}
}


/*******************************************************************************
Function update command grid according selected command in test Program grid
*******************************************************************************/

void eliFrame::UpdateProgParam(int x)
{
 wxString com_str=tp_prg->GetCmd(x+1); // Get selected program from Test program class
CommentsCmd->Clear();
CommentsCmd->WriteText(tp_prg->GetDescription(x+1));

int cnt=0;
int end_find=0;
try{
    /* Find command in comnd_base structure*/
      while(end_find==0)
   {
     if(comnd_base[cnt].name == com_str)end_find=1;
     else cnt++;

      if(cnt>= NUMBER_COMMANDS_CLASS) throw "Can not find selected command in list of commands";

   }

      wxString name,str;
   wxArrayString araystring;
   int type,ival,type2;
   bool bval;
   float fval;
   int r_val=0;


   Grid1->ClearGrid();
  if(Grid1->GetNumberRows()>0) Grid1->DeleteRows(0,Grid1->GetNumberRows());// Delete all lines in commands grid
   Grid1->InsertRows(0,cmd[cnt]->GetCmdNumberLines());//Insert all rows in command grid according updated command

   but_gr=new int[cmd[cnt]->GetCmdNumberLines()];
   for(int i=0;i<cmd[cnt]->GetCmdNumberLines();i++)but_gr[i]=0;

   for(int i=0;i<cmd[cnt]->GetCmdNumberLines();i++)
   {
     if(cmd[cnt]->GetLineParam(i,name,type,araystring,str,ival,fval,bval,type2)==0)
     {

       if(type==1)r_val=CommandParam(name,i,type2,str);
       if(type==2)r_val=CommandParam(name,i,type2,araystring);
       if(type==3)r_val=CommandParam(name,i,type2,bval);
       if(type==4)r_val=CommandParam(name,i,type2,ival);
       if(type==5)r_val=CommandParam(name,i,type2,fval);


       if((type<1)||(type>5)||(r_val!=0))
       {
        wxString px=_("Error in function GetLineParam, ClassName:");
        px+=cmd[cnt]->ReturnClassname();
        px+=_("\nLine number: ");
        px<<i;
         if((type<1)||(type>5)) px+=_("\nBad type number (type must be in range 1 to 5)");
         if(r_val!=0) //Generated error code
        {
         px+=_("\nErron in function CommandParam with type :");
         px<<type;
         px+=_("\nReturn error code :");
         px<<r_val;

        }
        char pk[400]={0};
        strncpy(pk,(const char*)px.mb_str(wxConvUTF8),400);
         throw pk;
       }

     }
     else
     {
        wxString px=_("Error in function GetLineParam, ClassName:");
        px+=cmd[cnt]->ReturnClassname();
        px+=_("\nLine number: ");
        px<<i;
        char pk[300]={0};
        strncpy(pk,(const char*)px.mb_str(wxConvUTF8),300);
         throw pk;
     }
   }

   wxString paramx=tp_prg->GetParam(x+1);
   wxString pom_paramx;

//Insert commands parameters to command grid
   for(int i=0;i<Grid1->GetNumberRows();i++)
   {
      pom_paramx=paramx.BeforeFirst('#');
      paramx=paramx.AfterFirst('#');
      Grid1->SetCellValue(i,1,pom_paramx);
   }
}

catch(const char *exception)
{
  ErrorLog er;
  wxString erstring(exception,wxConvUTF8);
 er.SetError(_("Error in Selection test program line"),erstring);
er.DisplayLog();
}
}


/********************************************************************
Function is call when some test program line in test program grid is
selected.
Function read selected row and call function UpdateProgParam which
update command grid
********************************************************************/

void eliFrame::OnGrid2CellSelect(wxGridEvent& event)
{
int x=event.GetRow();
event.Skip();
if(x<0) return;
Grid2->SelectRow(x);

UpdateProgParam(x);

}








/****************************************************************
Function is call when user click on copy button
Function display dialogs for selection start and end of block
which should be copy and than copy selected block after selected line
and update  Test program grid
****************************************************************/
void eliFrame::OnClickCopyCommand(wxCommandEvent& event)
{
        if(Grid2->GetRows()==0) return; // no rows in test program grid
       int y=Grid2->GetCursorRow()+1;
   long startt=1;
   long end=1;
   ClearAllBreaks();

   wxNumberEntryDialog dialog (this,wxT("Insert Start of block"),wxT("Start block line"),wxT("Start of block"),1,1,y);
   if(dialog.ShowModal()==wxID_OK) startt=dialog.GetValue();
   else return;

     wxNumberEntryDialog dialog2 (this,wxT("Insert End of block"),wxT("End block line"),wxT("End of block"),startt,startt,y);
   if(dialog2.ShowModal()==wxID_OK) end=dialog2.GetValue();
   else return;

   if(tp_prg->CopyBlockProgram(y,startt,end)==0)
   {
     ins_line=y+(end-startt);
     UpdateGrid(end-startt+1);
   }
   else wxMessageBox(_("Error Copy program"),_("ERROR"),wxICON_ERROR);
}

/*********************************************************************
Function is call when user click on Delete button
Function Delete selected line and after confirmation this
line is delete from class Test Program adn Update Test Program grid.
*********************************************************************/
void eliFrame::OnClickDeleteCommand(wxCommandEvent& event)
{
        int rw_line=0;
     wxArrayInt ix;
   ix.Empty();
   ix=Grid2->GetSelectedRows();  //Read selected line
   if(ix.GetCount()<1)return;
   else rw_line=ix[0]+1;

   ClearAllBreaks();

try
{
    wxString str=_("Do you want delete command ");
    str+=Grid2->GetCellValue(rw_line-1,0);
    /*str+=_("_");
    str+=Grid2->GetCellValue(rw_line-1,1);*/
    str+=_(" in line ");
    str<<rw_line;
    str+=_("?");
    if(wxMessageBox(str,_("Warning"),wxICON_WARNING|wxYES_NO)==wxYES) //COnfirmation of delete
    {
     if(tp_prg->DeleteLine(rw_line)!=0)throw "Error delete command"; //Run delete line function
     Grid1->ClearGrid();
   if(Grid1->GetNumberRows()>0)Grid1->DeleteRows(0,Grid1->GetNumberRows());
   if(Grid2->GetNumberRows()>0)Grid2->DeleteRows();

        ins_line=rw_line-2;
        if((ins_line>-1)&&(Grid2->GetNumberRows()>0))UpdateGrid(0);// Update test program grid
        else
        {
            if(Grid2->GetNumberRows()>0)
            {
                Grid2->SelectRow(0);
                ins_line=0;
            }

        }

    if(ins_line>-1) UpdateProgParam(ins_line);


    }
}
    catch(const char *exception)
{
  ErrorLog er;
  wxString erstring(exception,wxConvUTF8);
 er.SetError(_("Error in Selection test program line"),erstring);
er.DisplayLog();
}
}

/*******************************************************************************
Function is call when user click on Menu Save program
Function display dialog for save file where user can select name of file where test
program will be saved. Than call function Save test program which generated
test program file according test program. Default name of save file
is test program name with extension eli
*******************************************************************************/
void eliFrame::OnMenuSaveProgSelected(wxCommandEvent& event)
{

    wxString caption=wxT("Save Test Program");
    wxString wildcard=wxT("ELI files (*.eli)|*.eli");
     wxString pok;
     wxString defaultDir;
    wxConfig config(wxT("Prog"),wxT("ELI"));
    config.Read(wxT("def_dir"),&pok);
    if(pok.Length()==0) defaultDir=wxT("/home");
    else defaultDir=pok;

    wxString defaultFilename=p_name;
    defaultFilename+=wxT(".eli");

    wxFileDialog dialog(this,caption,defaultDir,defaultFilename,wildcard,wxFD_SAVE);
    if(dialog.ShowModal()==wxID_OK)
    {
      wxString path=dialog.GetPath();
     wxString sv=path.BeforeLast('/');
      config.Write(wxT("def_dir"),sv);
      if(tp_prg->SaveProgram(path,ob_prg)!=0)wxMessageBox(_("Save program error"),_("ERROR"),wxICON_ERROR);
    }
}

/*****************************************************************************
Function is call when user press Menu Open program.
It display dialog for open file, where user can select file with test program.
Visible are only files with extension .eli.
After selection call function OpenProgram from class Test Program and read
test program to this structure. Test program is write to test program grid and
cursor is set to first line.
*****************************************************************************/
void eliFrame::OnMenuOpenProgSelected(wxCommandEvent& event)
{
      wxString caption=wxT("Open Test program");
    wxString wildcard=wxT("ELI files (*.eli)|*.eli");
     wxString pok;
     wxString defaultDir,path;
    wxConfig config(wxT("Prog"),wxT("ELI"));
    config.Read(wxT("def_dir"),&pok);
    if(pok.Length()==0) defaultDir=wxT("/home");
    else defaultDir=pok;


   wxString defaultFilename=wxEmptyString;

    wxFileDialog dialog(this,caption,defaultDir,defaultFilename,wildcard,wxFD_OPEN);
    if(dialog.ShowModal()==wxID_OK)
    {
       path=dialog.GetPath();
     wxString sv=path.BeforeLast('/');
      config.Write(wxT("def_dir"),sv);
      if(tp_prg !=NULL) delete tp_prg;
        ins_line=0;
     tp_prg=new TestProgram();
     int ret_val=tp_prg->OpenProgram(path,ob_prg);
     p_name=path.AfterLast('/').BeforeFirst('.');
     if(ret_val !=0)
     {
         wxString mes=_("Error Open Test program\nError code:");
            mes<<ret_val;
            wxMessageBox(mes,_("Error"),wxICON_ERROR);
              stat->SetLabel(_("Error Load program"));
          stat->SetForegroundColour(wxColour(255,0,0));
     }
     else{
    if(Grid2->GetNumberRows()>0)Grid2->DeleteRows(0,Grid2->GetNumberRows());
  UpdateGrid(tp_prg->GetLineNumber());
 // Grid2->InsertRows(0,5);

    stat->SetLabel(_("Load program"));
     stat->SetForegroundColour(wxColour(0,0,255));
     TextCtrl1->Clear();
     TextCtrl1->WriteText(_("Loaded program:"));
     TextCtrl1->WriteText(path);
     TextCtrl1->WriteText(_("\nDescription:\n"));
     TextCtrl1->WriteText(tp_prg->GetComents());
     TextCtrl1->WriteText(_("\n\n"));
     }
    }
}

/***************************************************************************
Function is call when user press menu New Program.
Function delete test program grid and alloc new TestProgram class
***************************************************************************/

void eliFrame::OnMenuINewProgramSelected(wxCommandEvent& event)
{
     if(tp_prg !=NULL) delete tp_prg;
        ins_line=0;
        if(Grid2->GetNumberRows()>0)Grid2->DeleteRows(0,Grid2->GetNumberRows());
        if(Grid1->GetNumberRows()>0)Grid1->DeleteRows(0,Grid1->GetNumberRows());

     tp_prg=new TestProgram();
delete ob_prg;
ob_prg=new ObjectPrograms;// Always set new object program class
       stat->SetLabel(_("New program"));
     stat->SetForegroundColour(wxColour(0,0,255));

}

/**************************************************************************
Function is call when user press menu Command Help or key F1. Function
display help HTML window with help on command where cursor is selected
htm files must be placed in directory help in working folder. htm file must have
same name as selected command.
**************************************************************************/
void eliFrame::OnCommandHelpSelected(wxCommandEvent& event)
{
        wxBoxSizer *topsizer;
    wxHtmlWindow *html;


        wxArrayInt ix;
   ix.Empty();
   ix=Grid2->GetSelectedRows();
   if(ix.GetCount()<1)return;
   if(ix[0]<0) return;

    int row=ix[0];
    if(row<0) return;
    wxString name=Grid2->GetCellValue(row,0);

    wxString page_name=actual_dir;
page_name+=wxT("/help/");

    page_name+=name;
    page_name+=wxT(".htm");
    wxString help_name=_("Help window for command ");
    help_name+=name;

    wxDialog dlg(this, wxID_ANY, wxString(help_name));

    topsizer = new wxBoxSizer(wxVERTICAL);

    html = new wxHtmlWindow(&dlg, wxID_ANY, wxDefaultPosition, wxSize(580, 560), wxHW_SCROLLBAR_AUTO);
    html -> SetBorders(0);
    html -> LoadPage(page_name);
    html -> SetSize(html -> GetInternalRepresentation() -> GetWidth(),560);

    topsizer -> Add(html, 1, wxALL, 10);



    wxButton *bu1 = new wxButton(&dlg, wxID_OK, _("OK"));
    bu1 -> SetDefault();

    topsizer -> Add(bu1, 0, wxALL | wxALIGN_RIGHT, 15);

    dlg.SetSizer(topsizer);
    topsizer -> Fit(&dlg);

    dlg.ShowModal();
}

void eliFrame::OnMenuIRunSelected(wxCommandEvent& event)
{
    if(run_tpg!=NULL) return;
    if(tp_prg==NULL)return;
    if(tp_prg->GetLineNumber()<1) return;


    TextCtrl1->Clear();
  int64 t1=0,t2=0,tx=0;

    run_tpg=new RunTestProgram(cmd);

try
{
    if(isDisplayedImage)
    {
        isDisplayedImage=false;
        displayed_Image.release();
    }


     stat->SetLabel(_("Running program, please wait..."));
     stat->SetForegroundColour(wxColour(0,255,0));

     wxWindowDisabler disableAll;
      Update();

    t1=cv::getTickCount();
    int ret=run_tpg->RunProgram(tp_prg,cmd,1,ob_prg,0);
   t2=cv::getTickCount();
   UpdateActualVariableStatus();
    if(ret==0)
    {
        tx=t2-t1;
      double tot_time=(double)tx/cv::getTickFrequency();//calculate total time for test program
        wxString tim_string=_("Program time: ");
        tim_string<<tot_time;
        tim_string+=_(" s \n");
        TextCtrl1->WriteText(tim_string);
      // TextCtrl1->WriteText(run_tpg->GetText1());
       TextCtrl1->WriteText(_("\nResults:\n\n"));
       TextCtrl1->WriteText(run_tpg->GetResults());
         stat->SetLabel(_("Program finished"));
     stat->SetForegroundColour(wxColour(0,0,255));

       /****************************************/
        if((run_tpg->GetResultPicturePosition()>=0)&&(run_tpg->GetResultPicturePosition()<20))
        {
         if(GenerateDisplPicture(run_tpg->GetResultPicture())!=0)TextCtrl1->WriteText(_("\nError: Image is not alocate:\n\n"));
          isDisplayedImage=true;
        }
        // DrawBitmatPic();

        Update();
        Refresh();
       /***************************************/

    }
    else
    {
     wxString cd=_("Fail in line ");
     cd<<run_tpg->GetNumberExecutedLines();
     cd+= _(", error code :");
     cd<<ret;
     TextCtrl1->WriteText(cd);
       stat->SetLabel(_("Run  program error"));
     stat->SetForegroundColour(wxColour(255,0,0));
     if(ret==-100)//OpenCV Error
     {
      TextCtrl1->WriteText(_("\nOpen CV error:\n"));
      TextCtrl1->WriteText(run_tpg->ReturnOpenCVErrMess());
     }
    }
}
   catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    ErrorLog er;
    er.SetError(_("OpenCV error in function OnMenuIRunSelected"),pv);
    er.DisplayLog();
    }

     // DrawBitmatPic();
     Update();
        Refresh();

    delete run_tpg;
    run_tpg=NULL;


}

/*****************************************************************************
Function is active when user click on menu Set breakpoint.
Function read selected line and set breakpoint to test program class.
Next add string (b) to first collumn in selected line and change font in
selected line as break
*****************************************************************************/
void eliFrame::OnMenuISetBreakSelected(wxCommandEvent& event)
{
     wxArrayInt ix;
   int y=0;
   ix.Empty();
   ix=Grid2->GetSelectedRows();
   if(ix.GetCount()<1)return;
   else y=ix[0];


try
{


     DrawBreak(y);
    if(tp_prg==NULL) throw "Can not set break";
    if(tp_prg->SetBreak(y+1)<0) throw "Can not set break";
  }

catch(const char *exception)
{
  ErrorLog er;
  wxString erstring(exception,wxConvUTF8);
 er.SetError(_("Error Set break"),erstring);
er.DisplayLog();
}

}

/*******************************************************************
Function is called when user click on menu reset break.
Function read selected line , reset break in test program class
and remove string (b) from selected line and change back font in selected
line.
*******************************************************************/
void eliFrame::OnMenuIRemoveBreakSelected(wxCommandEvent& event)
{
     wxArrayInt ix;
   int y=0;
   ix.Empty();
   ix=Grid2->GetSelectedRows();
   if(ix.GetCount()<1)return;
   else y=ix[0];



 try
  {
    if(tp_prg==NULL) throw "Can not Reset break";
    if(!tp_prg->GetBreak(y+1))return;
    if(tp_prg->ResetBreak(y+1)<0) throw "Can not Reset break";
    ReDrawBreak(y);


  }

catch(const char *exception)
{
  ErrorLog er;
  wxString erstring(exception,wxConvUTF8);
 er.SetError(_("Error Reset break"),erstring);
er.DisplayLog();
}
}

/***************************************************************************
Function is call when user click on menu remove all breaks.
Function check all line in test program structure. If some line has a
break, reset break in test program class
***************************************************************************/

void eliFrame::ClearAllBreaks(void)
{
     try
    {

      if(tp_prg==NULL) throw "Can not reset break";
    for(int i=0;i<tp_prg->GetLineNumber();i++)
    {
      if(tp_prg->GetBreak(i+1))
      {
        if(tp_prg->ResetBreak(i+1)<0)throw "Can not reset break";
        ReDrawBreak(i);
      }
    }

    }
    catch(const char *exception)
{
  ErrorLog er;
  wxString erstring(exception,wxConvUTF8);
 er.SetError(_("Error Reset break"),erstring);
er.DisplayLog();
}
}

void eliFrame::OnMenuRemoveAllBreakSelected(wxCommandEvent& event)
{
ClearAllBreaks();
}

/**********************************************************************
Function is activated when user click on menu Debug or tool bar debug.
Function is stopped and return if :
 - run_tpg class is not NULL. This class is use for run test program
 - tp_prg class is NULL. This class is test program class
 - no line in test program grid.

 Function dissable buttotns for edit test program,open,save, continue
 step and stop debuger button. In the end of this function those buttons
 are enabled (expect step, continue and stop debuger).Function clear
 Grid 1 which is command parameter grid. This grid is not use durring
 program debug.
  Function RunProgram from RunTestProgram class is called. If this
  function return 0 all test program is is done, if return 1 some break
  was fond in test program. Function display break with line number to log
  window and function end.
**********************************************************************/

void eliFrame::OnMenuIDebugSelected(wxCommandEvent& event)
{

    if(run_tpg!=NULL) return;
    if(tp_prg==NULL)return;
    if(tp_prg->GetLineNumber()<1) return;
    Grid1->ClearGrid();
   if(Grid1->GetNumberRows()>0) Grid1->DeleteRows(0,Grid1->GetNumberRows());
     ToolBar1->EnableTool(idToolRunTestPrg,false);
    ToolBar1->EnableTool(idToolDebug,false);
    ToolBar1->EnableTool(idRunLoop,false);
     ToolBar1->Realize();
    MenuIRun->Enable(false);
     MenuIDebug->Enable(false);
    MenuItem3->Enable(false); // Run loop menu button


    TextCtrl1->Clear();
    run_tpg=new RunTestProgram(cmd);
try
{
     if(isDisplayedImage)
    {
        isDisplayedImage=false;
        displayed_Image.release();
    }

     int ret=-1;
       stat->SetLabel(_("Running debug program"));
     stat->SetForegroundColour(wxColour(0,255,0));
      wxWindowDisabler disableAll;
     Update();

     if(tp_prg->GetBreak(1)) ret=1; // if break is selected in first test program line
     else ret=run_tpg->RunProgram(tp_prg,cmd,1,ob_prg,1); // call function from RunTestProgram class and wait for result
   UpdateActualVariableStatus();
    if(ret==0) // no break found in test program,all step was done
    {
         TextCtrl1->WriteText(_("\nResults:\n\n"));
       TextCtrl1->WriteText(run_tpg->GetResults());
     //  TextCtrl1->WriteText(run_tpg->GetText1());
          /****************************************/
        if((run_tpg->GetResultPicturePosition()>=0)&&(run_tpg->GetResultPicturePosition()<20))
        {
         if(GenerateDisplPicture(run_tpg->GetResultPicture())!=0)TextCtrl1->WriteText(_("\nError: Image is not alocate:\n\n"));
        }
            stat->SetLabel(_("Program finished"));
        stat->SetForegroundColour(wxColour(0,0,255));
        Update();
        Refresh();
        // DrawBitmatPic();
       /***************************************/

         delete run_tpg;
    run_tpg=NULL;
     ToolBar1->EnableTool(idToolRunTestPrg,true);
    ToolBar1->EnableTool(idToolDebug,true);
    ToolBar1->EnableTool(idRunLoop,true);
     ToolBar1->Realize();
    MenuIRun->Enable(true);
     MenuIDebug->Enable(true);
    MenuItem3->Enable(true); // Run loop menu button

    }
    else
    {
        if(ret==1) // some break was found
        {
        wxString cd1=_("Break in line: ");
        cd1<<run_tpg->GetNumberExecutedLines()+1; // read test program line when break was found
        cd1+=_("\n");
        TextCtrl1->WriteText(cd1);
          stat->SetLabel(_("Break stop"));
        stat->SetForegroundColour(wxColour(0,0,255));
        Grid2->SelectRow(run_tpg->GetNumberExecutedLines());
        ToolBar1->EnableTool(idToolStep,true);
        ToolBar1->EnableTool(idToolContinue,true);
        ToolBar1->EnableTool(idToolStopDeb,true);
        ToolBar1->Realize();
        MenuIStep->Enable(true);
        MenuContinue->Enable(true);
        MenuIStopDebuger->Enable(true);


         /****************************************/
        if((run_tpg->GetResultPicturePosition()>=0)&&(run_tpg->GetResultPicturePosition()<20))
        {
         if(GenerateDisplPicture(run_tpg->GetResultPicture())!=0)TextCtrl1->WriteText(_("\nError: Image is not alocate:\n\n"));
        }
        // DrawBitmatPic();
        Update();
        Refresh();
       /***************************************/
        }
        else // some error was found during test program execution
        {
     wxString cd=_("Fail in line ");
     cd<<run_tpg->GetNumberExecutedLines();// read number executed lines, this number represented error line
     cd+= _(", error code :");
     cd<<ret;
     TextCtrl1->WriteText(cd);
       stat->SetLabel(_("Error finish program"));
     stat->SetForegroundColour(wxColour(255,0,0));
    if(ret==-100)//OpenCV Error
     {
      TextCtrl1->WriteText(_("\nOpen CV error:\n"));
      TextCtrl1->WriteText(run_tpg->ReturnOpenCVErrMess());
     }
        //DrawBitmatPic();
        Update();
        Refresh();

        delete run_tpg;
    run_tpg=NULL;

           ToolBar1->EnableTool(idToolRunTestPrg,true);
       ToolBar1->EnableTool(idToolDebug,true);
       ToolBar1->EnableTool(idRunLoop,true);
     ToolBar1->Realize();
    MenuIRun->Enable(true);
     MenuIDebug->Enable(true);
    MenuItem3->Enable(true); // Run loop menu button
        }
    }
}
   catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    ErrorLog er;
    er.SetError(_("OpenCV error in function OnMenuIDebugSelected"),pv);
    er.DisplayLog();
    }

}

/****************************************************************
Function is activated when user click on menu or tool bar Step
Function is stopped and return if :
 - run_tpg class is not NULL. This class is use for run test program
 - tp_prg class is NULL. This class is test program class
 - no line in test program grid.

 Function dissable buttons for edit test program,open,save, continue
 step and stop debuger button. In the end of this function those buttons
 are enabled (expect step, continue and stop debuger).Function clear
 Grid 1 which is command parameter grid. This grid is not use durring
 program debug.
 Function RunProgram is called. This function executes 1 test program line
 and go to the next line and wait for other actions. Function RunProgram
 return 0 if last test program line was executed, return -1 if some error
 was found durring test program line execution, return 1 function
 executed 1 line , go to next line and wait for user action.
****************************************************************/

void eliFrame::OnMenuIStepSelected(wxCommandEvent& event)
{
      if(run_tpg==NULL) return;
    if(tp_prg==NULL)return;
    if(tp_prg->GetLineNumber()<1) return;
    Grid1->ClearGrid();
    if(Grid1->GetNumberRows()>0)Grid1->DeleteRows(0,Grid1->GetNumberRows());
       ToolBar1->EnableTool(idToolStep,false);
        ToolBar1->EnableTool(idToolContinue,false);
        ToolBar1->EnableTool(idToolStopDeb,false);
        ToolBar1->EnableTool(idRunLoop,false);
      ToolBar1->Realize();
         MenuIStep->Enable(false);
     MenuContinue->Enable(false);
     MenuIStopDebuger->Enable(false);

try
{
   if(isDisplayedImage)
    {
        isDisplayedImage=false;
        displayed_Image.release();
    }
          stat->SetLabel(_("Step running"));
     stat->SetForegroundColour(wxColour(0,255,0));
      wxWindowDisabler disableAll;
     Update();

      int ret=run_tpg->RunProgram(tp_prg,cmd,run_tpg->GetNumberExecutedLines()+1,ob_prg,2);
      UpdateActualVariableStatus();
    if(ret==0)//no error , last line was executed,
    {
        TextCtrl1->WriteText(_("\nResults:\n\n"));
       TextCtrl1->WriteText(run_tpg->GetResults());
      // TextCtrl1->WriteText(run_tpg->GetText1());
    /****************************************/
        if((run_tpg->GetResultPicturePosition()>=0)&&(run_tpg->GetResultPicturePosition()<20))
        {
         if(GenerateDisplPicture(run_tpg->GetResultPicture())!=0) TextCtrl1->WriteText(_("\nError: Image is not alocate:\n\n"));
        }
           stat->SetLabel(_("Step finish"));
     stat->SetForegroundColour(wxColour(0,0,255));
       /***************************************/
          //DrawBitmatPic();
          Update();
          Refresh();
         delete run_tpg;
    run_tpg=NULL;


      ToolBar1->EnableTool(idToolDebug,true);
      ToolBar1->EnableTool(idToolRunTestPrg,true);
      ToolBar1->EnableTool(idOpen,true);
      ToolBar1->EnableTool(idSave,true);
      ToolBar1->EnableTool(idNew,true);
       ToolBar1->EnableTool(idRunLoop,true);
      ToolBar1->Realize();
      MenuIRun->Enable(true);
      MenuIDebug->Enable(true);
      MenuINewProgram->Enable(true);
      MenuOpenProg->Enable(true);
      MenuSaveProg->Enable(true);
       MenuItem3->Enable(true); // Run loop menu button

/*      MenuItem5->Enable(true);
      EditCommand->Enable(true);
      CopyCommands->Enable(true);
      DeleteCommands->Enable(true);*/
    }
    else
    {
        if(ret==1)// nmo error, one line was executed
        {
        wxString cd1=_("Step in line: ");
        cd1<<run_tpg->GetNumberExecutedLines()+1;
        cd1+=_("\n");
        TextCtrl1->WriteText(cd1);
          stat->SetLabel(_("Step break"));
     stat->SetForegroundColour(wxColour(0,0,255));
        Grid2->SelectRow(run_tpg->GetNumberExecutedLines());
             /****************************************/
        if((run_tpg->GetResultPicturePosition()>=0)&&(run_tpg->GetResultPicturePosition()<20))
        {
         if(GenerateDisplPicture(run_tpg->GetResultPicture())!=0)  TextCtrl1->WriteText(_("\nError: Image is not alocate:\n\n"));
        }
       // DrawBitmatPic();

       Update();
       Refresh();
       /***************************************/

        ToolBar1->EnableTool(idToolStep,true);
        ToolBar1->EnableTool(idToolContinue,true);
        ToolBar1->EnableTool(idToolStopDeb,true);
        ToolBar1->Realize();
        MenuIStep->Enable(true);
        MenuContinue->Enable(true);
        MenuIStopDebuger->Enable(true);
        }
        else// some error was found durring execution
        {
     wxString cd=_("Fail in line ");
     cd<<run_tpg->GetNumberExecutedLines();// get error line
     cd+= _(", error code :");
     cd<<ret;
     TextCtrl1->WriteText(cd);
       stat->SetLabel(_("Error Step finish"));
     stat->SetForegroundColour(wxColour(255,0,0));
    if(ret==-100)//OpenCV Error
     {
      TextCtrl1->WriteText(_("\nOpen CV error: "));
      TextCtrl1->WriteText(run_tpg->ReturnOpenCVErrMess());
     }
       // DrawBitmatPic();
       Update();
       Refresh();

        delete run_tpg;
    run_tpg=NULL;


      ToolBar1->EnableTool(idToolRunTestPrg,true);
      ToolBar1->EnableTool(idToolDebug,true);
      ToolBar1->EnableTool(idOpen,true);
      ToolBar1->EnableTool(idSave,true);
      ToolBar1->EnableTool(idNew,true);
      ToolBar1->EnableTool(idRunLoop,true);
       ToolBar1->Realize();
       MenuIRun->Enable(true);
      MenuIDebug->Enable(true);
      MenuINewProgram->Enable(true);
      MenuOpenProg->Enable(true);
      MenuSaveProg->Enable(true);
       MenuItem3->Enable(true); // Run loop menu button
    /*  AddCommand->Enable(true);
     EditCommand->Enable(true);
     CopyCommands->Enable(true);
     DeleteCommands->Enable(true);*/
        }
    }
}
   catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    ErrorLog er;
    er.SetError(_("OpenCV error in function OnMenuIDebugSelected"),pv);
    er.DisplayLog();
    }
}

/*******************************************************************************
Function is activated when user click on menu or toolbar Continue
Function is stopped and return if :
 - run_tpg class is not NULL. This class is use for run test program
 - tp_prg class is NULL. This class is test program class
 - no line in test program grid.
 Button in menu or toolbar for active this function are enabled only when
 program stop on break.
 Function execute function RunProgram from line when break was set.
 FUnction continue till next break is found. If some break is found test program
 is stop and this function end. Than can be this function execute again. If no break
 is found after start this function, all lines in test program are executed and
 function finish as in Run mode. If some command in test program return error
 this error whith line number is display in log window and function end.
********************************************************************************/
void eliFrame::OnMenuContinueSelected(wxCommandEvent& event)
{
    if(run_tpg==NULL) return;
    if(tp_prg==NULL)return;
    if(tp_prg->GetLineNumber()<1) return;
    Grid1->ClearGrid();
   if(Grid1->GetNumberRows()>0) Grid1->DeleteRows(0,Grid1->GetNumberRows());
       ToolBar1->EnableTool(idToolStep,false);
        ToolBar1->EnableTool(idToolContinue,false);
        ToolBar1->EnableTool(idToolStopDeb,false);
      ToolBar1->Realize();
         MenuIStep->Enable(false);
     MenuContinue->Enable(false);
     MenuIStopDebuger->Enable(false);

try
{
     if(isDisplayedImage)
    {
        isDisplayedImage=false;
        displayed_Image.release();
    }
           stat->SetLabel(_("Continue running"));
     stat->SetForegroundColour(wxColour(0,255,0));
      wxWindowDisabler disableAll;
     Update();
      int ret=run_tpg->RunProgram(tp_prg,cmd,run_tpg->GetNumberExecutedLines()+1,ob_prg,1);
      UpdateActualVariableStatus();
    if(ret==0)
    {
         TextCtrl1->WriteText(_("\nResults:\n\n"));
       TextCtrl1->WriteText(run_tpg->GetResults());
      // TextCtrl1->WriteText(run_tpg->GetText1());

         stat->SetLabel(_("Continue finish"));
     stat->SetForegroundColour(wxColour(0,0,255));
       /****************************************/
        if((run_tpg->GetResultPicturePosition()>=0)&&(run_tpg->GetResultPicturePosition()<20))
        {
         if(GenerateDisplPicture(run_tpg->GetResultPicture())!=0)TextCtrl1->WriteText(_("\nError: Image is not alocate:\n\n"));
        }
        //DrawBitmatPic();
        Update();
        Refresh();
       /***************************************/

         delete run_tpg;
    run_tpg=NULL;

      ToolBar1->EnableTool(idToolDebug,true);
      ToolBar1->EnableTool(idToolRunTestPrg,true);
      ToolBar1->EnableTool(idOpen,true);
      ToolBar1->EnableTool(idSave,true);
      ToolBar1->EnableTool(idNew,true);
      ToolBar1->EnableTool(idRunLoop,true);

      ToolBar1->Realize();
      MenuIRun->Enable(true);
      MenuIDebug->Enable(true);
      MenuINewProgram->Enable(true);
      MenuOpenProg->Enable(true);
      MenuSaveProg->Enable(true);
       MenuItem3->Enable(true); // Run loop menu button

    /*  AddCommand->Enable(true);
      EditCommand->Enable(true);
      CopyCommands->Enable(true);
      DeleteCommands->Enable(true);*/
    }
    else
    {
        if(ret==1)
        {
        wxString cd1=_("Break in line: ");
        cd1<<run_tpg->GetNumberExecutedLines()+1;
        cd1+=_("\n");
        TextCtrl1->WriteText(cd1);
          stat->SetLabel(_("Continue break"));
         stat->SetForegroundColour(wxColour(0,0,255));
        Grid2->SelectRow(run_tpg->GetNumberExecutedLines());
        ToolBar1->EnableTool(idToolStep,true);
        ToolBar1->EnableTool(idToolContinue,true);
        ToolBar1->EnableTool(idToolStopDeb,true);

        ToolBar1->Realize();
        MenuIStep->Enable(true);
        MenuContinue->Enable(true);
        MenuIStopDebuger->Enable(true);


       /****************************************/
        if((run_tpg->GetResultPicturePosition()>=0)&&(run_tpg->GetResultPicturePosition()<20))
        {
         if(GenerateDisplPicture(run_tpg->GetResultPicture())!=0)TextCtrl1->WriteText(_("\nError: Image is not alocate:\n\n"));
        }
          UpdateActualVariableStatus();
         // DrawBitmatPic();
         Update();
         Refresh();
       /***************************************/
        }
        else
        {
     wxString cd=_("Fail in line ");
     cd<<run_tpg->GetNumberExecutedLines();
     cd+= _(", error code :");
     cd<<ret;
     TextCtrl1->WriteText(cd);
       stat->SetLabel(_("Error Continue finish"));
     stat->SetForegroundColour(wxColour(255,0,0));
    if(ret==-100)//OpenCV Error
     {
      TextCtrl1->WriteText(_("\nOpen CV error:<n"));
      TextCtrl1->WriteText(run_tpg->ReturnOpenCVErrMess());
     }
       //DrawBitmatPic();
       Update();
       Refresh();

        delete run_tpg;
    run_tpg=NULL;
      ToolBar1->EnableTool(idToolRunTestPrg,true);
      ToolBar1->EnableTool(idToolDebug,true);
      ToolBar1->EnableTool(idOpen,true);
      ToolBar1->EnableTool(idSave,true);
      ToolBar1->EnableTool(idNew,true);
      ToolBar1->EnableTool(idRunLoop,true);
       ToolBar1->Realize();
       MenuIRun->Enable(true);
      MenuIDebug->Enable(true);
      MenuINewProgram->Enable(true);
      MenuOpenProg->Enable(true);
      MenuSaveProg->Enable(true);
       MenuItem3->Enable(true); // Run loop menu button
  /*    AddCommand->Enable(true);
     EditCommand->Enable(true);
     CopyCommands->Enable(true);
     DeleteCommands->Enable(true);*/
        }
    }
}
   catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    ErrorLog er;
    er.SetError(_("OpenCV error in function OnMenuContinueSelected"),pv);
    er.DisplayLog();
    }
}


/*****************************************************************************
Function is activated when user click in menu or toolbar button Stop debuger.
This option is only activated when program stop on some break or Step command
is used. Function stop test program, delete RunTestProgram class and enable
buttons for basic setup.
******************************************************************************/
void eliFrame::OnMenuIStopDebugerSelected(wxCommandEvent& event)
{
    TextCtrl1->WriteText(_("\nDebuger was stopped"));
    if(run_tpg==NULL)
    {
       TextCtrl1->WriteText(_("\run_tpg structure not alocated when stop debuder !!!"));
       return;
    }
    UpdateActualVariableStatus();
        delete run_tpg;
    run_tpg=NULL;
     ToolBar1->EnableTool(idToolRunTestPrg,true);
     ToolBar1->EnableTool(idToolDebug,true);
     ToolBar1->EnableTool(idToolStep,false);
     ToolBar1->EnableTool(idToolContinue,false);
     ToolBar1->EnableTool(idToolStopDeb,false);
     ToolBar1->EnableTool(idOpen,true);
      ToolBar1->EnableTool(idSave,true);
      ToolBar1->EnableTool(idNew,true);
      ToolBar1->EnableTool(idRunLoop,true);
     ToolBar1->Realize();
     MenuIRun->Enable(true);
     MenuIDebug->Enable(true);
     MenuIStep->Enable(false);
     MenuContinue->Enable(false);
     MenuIStopDebuger->Enable(false);
      MenuItem3->Enable(true); // Run loop menu button
    MenuINewProgram->Enable(true);
      MenuOpenProg->Enable(true);
      MenuSaveProg->Enable(true);
  /*   AddCommand->Enable(true);
     EditCommand->Enable(true);
     CopyCommands->Enable(true);
     DeleteCommands->Enable(true);*/
       stat->SetLabel(_("Stop debugging"));
     stat->SetForegroundColour(wxColour(0,0,255));
}

void eliFrame::OnMenuVariableSelected(wxCommandEvent& event)
{
    wxArrayString obj_list;
    for(unsigned i=0;i<act_variables.all_obj.size();i++)obj_list.Add(act_variables.all_obj[i].object_name);
VariableWindow dlg(this,obj_list);
dlg.ShowModal();
int parm[5];
/**0=variable position
		1=string pos,
		2=object pos,
		3=object status(0=number of object 1= object parameter)
        4=object parameter
**/
dlg.GetParameters(parm[0],parm[1],parm[2],parm[3],parm[4]);
TextCtrl1->WriteText(_("\n***Variable window***\n"));
wxString pom;
if((parm[0]>=0)&&(parm[0]<100))
{
 pom.Printf(_("Variable %d: %f\n"),parm[0],act_variables.fval[parm[0]]);
 TextCtrl1->WriteText(pom);
}

if((parm[1]>=0)&&(parm[1]<10))
{
    pom.Printf(_("String %d:"),parm[1]);
    pom+=act_variables.strings_var[parm[1]];
    TextCtrl1->WriteText(pom);
}

int cnt=0;//Object counter
if(parm[2]>-1) //Some objects was selected
{
      if(parm[2]>=act_variables.all_obj.size())
       {
           TextCtrl1->WriteText(_("Object position error\n**********\n"));
           return;
       }
   if(parm[3]==0) //Get number of objects
   {
       cnt=0;
     for(unsigned i=0;i<act_variables.all_obj.size();i++)
     {
        if(act_variables.all_obj[i].object_name==act_variables.all_obj[parm[2]].object_name)cnt++;
     }
     TextCtrl1->WriteText(_("Number of objects:"));
     TextCtrl1->WriteText(act_variables.all_obj[parm[2]].object_name);
     pom.Printf(_(" is:%d\n"),cnt);
     TextCtrl1->WriteText(pom);
   }
   else // Get object parameters
   {
       TextCtrl1->WriteText(_("Object: "));
       TextCtrl1->WriteText(act_variables.all_obj[parm[2]].object_name);
     switch (parm[4])
     {
     case 0: //Bounding rect X
        pom.Printf(_("\nBounding rectangle X: %d\n"),act_variables.all_obj[parm[2]].bounding_rect_x);
        TextCtrl1->WriteText(pom);
        break;
     case 1://Bounding rect Y
         pom.Printf(_("\nBounding rectangle Y: %d\n"),act_variables.all_obj[parm[2]].bounding_rect_y);
        TextCtrl1->WriteText(pom);
        break;
     case 2: //Bounding rect Height"
         pom.Printf(_("\nBounding rectangle height: %d\n"),act_variables.all_obj[parm[2]].bounding_rect_height);
        TextCtrl1->WriteText(pom);
        break;
     case 3://Bounding rect Width
         pom.Printf(_("\nBounding rectangle width: %d\n"),act_variables.all_obj[parm[2]].bounding_rect_width);
        TextCtrl1->WriteText(pom);
        break;
     case 4: //Perimeter
         pom.Printf(_("\nPerimeter: %f\n"),act_variables.all_obj[parm[2]].perimeter);
        TextCtrl1->WriteText(pom);
        break;
     case 5: //Contour area
        pom.Printf(_("\nContour area: %f\n"),act_variables.all_obj[parm[2]].contour_area);
        TextCtrl1->WriteText(pom);
        break;
     case 6://Minimal area rect X
        pom.Printf(_("\nMinimal area rectangle X: %d\n"),act_variables.all_obj[parm[2]].min_area_rect_x);
        TextCtrl1->WriteText(pom);
        break;
     case 7://Minimal area rect Y"
         pom.Printf(_("\nMinimal area rectangle Y: %d\n"),act_variables.all_obj[parm[2]].min_area_rect_y);
        TextCtrl1->WriteText(pom);
        break;
     case 8: //Minimal area rect Height
         pom.Printf(_("\nMinimal area rectangle height: %d\n"),act_variables.all_obj[parm[2]].min_area_rect_height);
        TextCtrl1->WriteText(pom);
        break;
     case 9://Minimal area rect Width
          pom.Printf(_("\nMinimal area rectangle width: %d\n"),act_variables.all_obj[parm[2]].min_area_rect_width);
        TextCtrl1->WriteText(pom);
        break;
     case 10://Minimal area rect angle
          pom.Printf(_("\nMinimal area rectangle angle: %f\n"),act_variables.all_obj[parm[2]].min_area_rect_angle);
        TextCtrl1->WriteText(pom);
        break;
     case 11://Minimal enclosing circle X
        pom.Printf(_("\nMinimal enclosing circle X: %d\n"),act_variables.all_obj[parm[2]].min_enclosing_circle_center_X);
        TextCtrl1->WriteText(pom);
        break;
     case 12: //Minimal enclosing circle Y"
          pom.Printf(_("\nMinimal enclosing circle Y: %d\n"),act_variables.all_obj[parm[2]].min_enclosing_circle_center_Y);
        TextCtrl1->WriteText(pom);
        break;
     case 13://Minimal enclosing circle radius
            pom.Printf(_("\nMinimal enclosing circle radius: %f\n"),act_variables.all_obj[parm[2]].min_enclosing_circle_radius);
        TextCtrl1->WriteText(pom);
        break;
     case 14://Fit ellipse center X
         pom.Printf(_("\nFit ellipse center X: %d\n"),act_variables.all_obj[parm[2]].fit_elipse_center_X);
        TextCtrl1->WriteText(pom);
        break;
     case 15: //Fit ellipse center Y
         pom.Printf(_("\nFit ellipse center Y: %d\n"),act_variables.all_obj[parm[2]].fit_elipse_center_Y);
        TextCtrl1->WriteText(pom);
        break;
     case 16: //Fit ellipse height
        pom.Printf(_("\nFit ellipse height: %d\n"),act_variables.all_obj[parm[2]].fit_elipse_height);
        TextCtrl1->WriteText(pom);
        break;
     case 17: //Fit ellipse width
         pom.Printf(_("\nFit ellipse width: %d\n"),act_variables.all_obj[parm[2]].fit_elipse_width);
        TextCtrl1->WriteText(pom);
        break;
     case 18://Fit ellipse angle
        pom.Printf(_("\nFit ellipse angle: %f\n"),act_variables.all_obj[parm[2]].fit_elipse_angle);
        TextCtrl1->WriteText(pom);
        break;
     case 19://Derived 0
        pom.Printf(_("\nDerived 0: %f\n"),act_variables.all_obj[parm[2]].derived[0]);
        TextCtrl1->WriteText(pom);
        break;
     case 20://Derived 1
          pom.Printf(_("\nDerived 1: %f\n"),act_variables.all_obj[parm[2]].derived[1]);
        TextCtrl1->WriteText(pom);
        break;
     case 21://Derived 2
       pom.Printf(_("\nDerived 2: %f\n"),act_variables.all_obj[parm[2]].derived[2]);
        TextCtrl1->WriteText(pom);
        break;
     case 22://Derived 3
       pom.Printf(_("\nDerived 3: %f\n"),act_variables.all_obj[parm[2]].derived[3]);
        TextCtrl1->WriteText(pom);
        break;
     case 23://Derived 4
       pom.Printf(_("\nDerived 4: %f\n"),act_variables.all_obj[parm[2]].derived[4]);
        TextCtrl1->WriteText(pom);
        break;
     case 24://Derived 5
        pom.Printf(_("\nDerived 5: %f\n"),act_variables.all_obj[parm[2]].derived[5]);
        TextCtrl1->WriteText(pom);
        break;
     case 25://Derived 6
       pom.Printf(_("\nDerived 6: %f\n"),act_variables.all_obj[parm[2]].derived[6]);
        TextCtrl1->WriteText(pom);
        break;
     case 26://Derived 7
       pom.Printf(_("\nDerived 7: %f\n"),act_variables.all_obj[parm[2]].derived[7]);
        TextCtrl1->WriteText(pom);
        break;
     case 27://Derived 8
         pom.Printf(_("\nDerived 8: %f\n"),act_variables.all_obj[parm[2]].derived[8]);
        TextCtrl1->WriteText(pom);
        break;
     case 28: //Derived 9
       pom.Printf(_("\nDerived 9: %f\n"),act_variables.all_obj[parm[2]].derived[9]);
        TextCtrl1->WriteText(pom);
        break;
     }
   }
}
TextCtrl1->WriteText(_("**********\n"));
}

/*******************************************************************
Function for generate display picture.
This picture is display in picture window
********************************************************************/
int eliFrame::GenerateDisplPicture(Mat img)
{

try
{
    //if(img==0) return -1; // if image pointer is not set return -1;
    wxSize size=GetSize();//Get window dimension
    int width=size.GetWidth()/2-40; //calculate maximal posible width in display window
    int heigth=size.GetHeight()/2; //calculate maximal posible height in display window
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
    if(Timer1 !=NULL)
    {
       Timer1->Stop();
    delete Timer1;
    Timer1=NULL;
     loop_running=false;
    }

   if(Timer2!=NULL) StopViewCameraFunction();

    ErrorLog er;
    er.SetError(_("OpenCV error in function GenerateDisplPicture"),pv);
    er.DisplayLog();
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

void eliFrame::DrawBitmatPic(void)
{

    wxPaintDC dc(Panel2);
    wxBitmap bitmap1;
    if(!loop_running) dc.Clear(); // clear panel area, if run loop is running panel area is not clear

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
    ErrorLog er;
    er.SetError(_("OpenCV error in function DrawBitmatPic"),pv);
    er.DisplayLog();
    }
}

/*********************************************************************
Function is call everytime when system needs draw window. Function call
function DrawBitmapPic and draw bitmap to result panel.
***********************************************************************/
void eliFrame::OnPanel2Paint(wxPaintEvent& event)
{

DrawBitmatPic();

}

/****************************************************
Start loop
Test program will run in loop till user press
stop loop or Test program will report some error
*******************************************************/
void eliFrame::OnRunLoopClicked(wxCommandEvent& event)
{
        ToolBar1->EnableTool(idStopLoop,true);
       ToolBar1->EnableTool(idRunLoop,false);
      ToolBar1->EnableTool(idToolDebug,false);
      ToolBar1->EnableTool(idToolRunTestPrg,false);
      ToolBar1->EnableTool(idToSetBreak,false);
      ToolBar1->EnableTool(idTolRemovBreak,false);
      ToolBar1->EnableTool(idTolRemoveAllBreak,false);
      ToolBar1->EnableTool(idOpen,false);
      ToolBar1->EnableTool(idSave,false);
      ToolBar1->EnableTool(idNew,false);
  ToolBar1->Realize();

    int numb_lines_tot=Grid2->GetRows();
    if(numb_lines_tot==0)return;
LoopDialog dlg(this,numb_lines_tot);
dlg.ShowModal();

    old_loop_string=_("");

    loop_time_ms=dlg.GetLoopTime();
    loop_start_line=dlg.GetStartLine();
    view_cam_seque=0;
    first_time_view=false;


    if(Timer1!=NULL)
    {
        Timer1->Stop();
       delete Timer1;
      Timer1=NULL;
    }
     Timer1=new wxTimer();

    Timer1->SetOwner(this, ID_TIMER1);
    Timer1->Start(loop_time_ms,false);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&eliFrame::OnTimer1Trigger);

    /*********************** Gauge setup ****************************/

    if(loop_time_ms>200)
    {
       guge_cnt=0;
       init_gauge=1;
       gauge_pom=0;
    }
    else
    {
        init_gauge=200/loop_time_ms;
    }

     /////////////////////////////////////////////////////////

/******************** Dissable menu , tool bar and program buttons ****************************/
        MenuIRun->Enable(false);
     MenuIDebug->Enable(false);
    MenuINewProgram->Enable(false);
      MenuOpenProg->Enable(false);
      MenuSaveProg->Enable(false);
      MenuISetBreak->Enable(false);
      MenuIRemoveBreak->Enable(false);
      MenuRemoveAllBreak->Enable(false);
      MenuItem3->Enable(false); // Run loop menu button
      MenuItem4->Enable(true); //Menu stop loop button

/*     AddCommand->Enable(false);
     EditCommand->Enable(false);
     CopyCommands->Enable(false);
     DeleteCommands->Enable(false);*/


    ////////////////////////////////////////////////////////
      stat->SetLabel(_("Loop running"));
     stat->SetForegroundColour(wxColour(0,255,0));

       TextCtrl1->Clear();
    run_tpg=new RunTestProgram(cmd);

try
{
   if(isDisplayedImage)
   {

     displayed_Image.release();
    isDisplayedImage=false;
   }


   int ret=run_tpg->RunProgram(tp_prg,cmd,1,ob_prg); // call function from RunTestProgram class and wait for result
UpdateActualVariableStatus();
   if(ret==0)
   {
        TextCtrl1->WriteText(_("\nResults:\n\n"));
        old_loop_string=run_tpg->GetResults();
       TextCtrl1->WriteText(run_tpg->GetResults());
          if((run_tpg->GetResultPicturePosition()>=0)&&(run_tpg->GetResultPicturePosition()<20))
        {
         if(GenerateDisplPicture(run_tpg->GetResultPicture())!=0)TextCtrl1->WriteText(_("\nError: Image is not alocate:\n\n"));
        }
       // DrawBitmatPic();
       Update();
       Refresh();
       loop_running=true;
    //   run_tpg->ReleaseImages();
       run_tpg->EmptyResultString();

       /***************************************/
    }
    else // some error was found during test program execution
    {
     wxString cd=_("Fail in line ");
     cd<<run_tpg->GetNumberExecutedLines();// read number executed lines, this number represented error line
     cd+= _(", error code :");
     cd<<ret;
     TextCtrl1->WriteText(cd);

       stat->SetLabel(_("Error loop finish"));
     stat->SetForegroundColour(wxColour(255,0,0));

    if(ret==-100)//OpenCV Error
     {
      TextCtrl1->WriteText(_("\nOpen CV error:\n"));
      TextCtrl1->WriteText(run_tpg->ReturnOpenCVErrMess());
     }

        delete run_tpg;
    run_tpg=NULL;

       Timer1->Stop();
    delete Timer1;
    Timer1=NULL;
     loop_running=false;

    /////////////////////////////////////////////////////////

    /****** Enable menu tool bars and buttons *********************/
   MenuIRun->Enable(true);
     MenuIDebug->Enable(true);
    MenuINewProgram->Enable(true);
      MenuOpenProg->Enable(true);
      MenuSaveProg->Enable(true);
      MenuISetBreak->Enable(true);
      MenuIRemoveBreak->Enable(true);
      MenuRemoveAllBreak->Enable(true);
      MenuItem3->Enable(true); // Run loop menu button
      MenuItem4->Enable(false); //Menu stop loop button

/*     AddCommand->Enable(true);
     EditCommand->Enable(true);
     CopyCommands->Enable(true);
     DeleteCommands->Enable(true);*/

  ToolBar1->EnableTool(idStopLoop,false);
  ToolBar1->EnableTool(idRunLoop,true);
   ToolBar1->EnableTool(idToolDebug,true);
      ToolBar1->EnableTool(idToolRunTestPrg,true);
      ToolBar1->EnableTool(idToSetBreak,true);
      ToolBar1->EnableTool(idTolRemovBreak,true);
      ToolBar1->EnableTool(idTolRemoveAllBreak,true);
      ToolBar1->EnableTool(idOpen,true);
      ToolBar1->EnableTool(idSave,true);
      ToolBar1->EnableTool(idNew,true);
  ToolBar1->Realize();
    ////////////////////////////////////////////////////////

    }
}
   catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    ErrorLog er;
    er.SetError(_("OpenCV error in function OnRunLoopClicked"),pv);
    er.DisplayLog();
    }
}

/*************************************************************
Stop loop
Test program in loop is stopped
****************************************************************/
void eliFrame::OnStopLoopClicked(wxCommandEvent& event)
{
    if(Timer1!=NULL)
    {
       Timer1->Stop();
    delete Timer1;
    Timer1=NULL;
    }

     loop_running=false;
     if(run_tpg==NULL)
     {
         TextCtrl1->WriteText(_("Error stop loop ren_tpg is not alocated\n"));
         return;
     }
     UpdateActualVariableStatus();
     delete run_tpg;
     run_tpg=NULL;

    /////////////////////////////////////////////////////////

  /****** Enable menu tool bars and buttons *********************/
   MenuIRun->Enable(true);
     MenuIDebug->Enable(true);
    MenuINewProgram->Enable(true);
      MenuOpenProg->Enable(true);
      MenuSaveProg->Enable(true);
      MenuISetBreak->Enable(true);
      MenuIRemoveBreak->Enable(true);
      MenuRemoveAllBreak->Enable(true);
      MenuItem3->Enable(true); // Run loop menu button
      MenuItem4->Enable(false); //Menu stop loop button

/*     AddCommand->Enable(true);
     EditCommand->Enable(true);
     CopyCommands->Enable(true);
     DeleteCommands->Enable(true);*/
  ToolBar1->EnableTool(idStopLoop,false);
  ToolBar1->EnableTool(idRunLoop,true);
   ToolBar1->EnableTool(idToolDebug,true);
      ToolBar1->EnableTool(idToolRunTestPrg,true);
      ToolBar1->EnableTool(idToSetBreak,true);
      ToolBar1->EnableTool(idTolRemovBreak,true);
      ToolBar1->EnableTool(idTolRemoveAllBreak,true);
      ToolBar1->EnableTool(idOpen,true);
      ToolBar1->EnableTool(idSave,true);
      ToolBar1->EnableTool(idNew,true);
  ToolBar1->Realize();
    ////////////////////////////////////////////////////////
      stat->SetLabel(_("Stop loop"));
     stat->SetForegroundColour(wxColour(0,0,255));
}

/*************************************************************
Timer is activated in Test program loop.
Function call Run test program
****************************************************************/
void eliFrame::OnTimer1Trigger(wxTimerEvent& event)
{

if(run_tpg==NULL)
{
    Timer1->Stop();
    delete Timer1;
    Timer1=NULL;
     loop_running=false;

    /////////////////////////////////////////////////////////

  /****** Enable menu tool bars and buttons *********************/
   MenuIRun->Enable(true);
     MenuIDebug->Enable(true);
    MenuINewProgram->Enable(true);
      MenuOpenProg->Enable(true);
      MenuSaveProg->Enable(true);
      MenuISetBreak->Enable(true);
      MenuIRemoveBreak->Enable(true);
      MenuRemoveAllBreak->Enable(true);
      MenuItem3->Enable(true); // Run loop menu button
      MenuItem4->Enable(false); //Menu stop loop button

/*     AddCommand->Enable(true);
     EditCommand->Enable(true);
     CopyCommands->Enable(true);
     DeleteCommands->Enable(true);*/
  ToolBar1->EnableTool(idStopLoop,false);
  ToolBar1->EnableTool(idRunLoop,true);
   ToolBar1->EnableTool(idToolDebug,true);
      ToolBar1->EnableTool(idToolRunTestPrg,true);
      ToolBar1->EnableTool(idToSetBreak,true);
      ToolBar1->EnableTool(idTolRemovBreak,true);
      ToolBar1->EnableTool(idTolRemoveAllBreak,true);
      ToolBar1->EnableTool(idOpen,true);
      ToolBar1->EnableTool(idSave,true);
      ToolBar1->EnableTool(idNew,true);
  ToolBar1->Realize();
    ////////////////////////////////////////////////////////
    return;
}

int64 t1=0,t2=0,tx;
if(first_time_view)  t1=cv::getTickCount();

try
{
   int ret=run_tpg->RunProgram(tp_prg,cmd,loop_start_line,ob_prg); // call function from RunTestProgram class and wait for result
   UpdateActualVariableStatus();
   if(ret==0)
   {
        if(run_tpg->GetResults()!=_(""))
        {
            if(run_tpg->GetResults()!=old_loop_string)
            {

                TextCtrl1->WriteText(run_tpg->GetResults());
                TextCtrl1->WriteText(_("\n"));
                old_loop_string=run_tpg->GetResults();
                int h;
             TextCtrl1->GetClientSize(0, &h);
             TextCtrl1->ShowPosition(TextCtrl1->XYToPosition(0, TextCtrl1->GetNumberOfLines()+(h/TextCtrl1->GetCharHeight())));
            }
        }
          if((run_tpg->GetResultPicturePosition()>=0)&&(run_tpg->GetResultPicturePosition()<20))
        {
            displayed_Image.release();
            isDisplayedImage=false;
         if(GenerateDisplPicture(run_tpg->GetResultPicture())!=0) TextCtrl1->WriteText(_("\nError: Image is not alocate:\n\n"));
        }
          // DrawBitmatPic();
          Update();
          Refresh();
            run_tpg->EmptyResultString();
            /*********** Setup gauge ************/
            gauge_pom++;
            if(gauge_pom==init_gauge)
            {
                gaug->SetValue(guge_cnt);
                gauge_pom=0;
                guge_cnt++;
                if(guge_cnt==11)guge_cnt=0;
            }

       /***************************************/
    }
    else // some error was found during test program execution
    {
     wxString cd=_("Fail in line ");
     cd<<run_tpg->GetNumberExecutedLines();// read number executed lines, this number represented error line
     cd+= _(", error code :");
     cd<<ret;
     TextCtrl1->WriteText(cd);

       stat->SetLabel(_("Error loop finish"));
     stat->SetForegroundColour(wxColour(255,0,0));

    if(ret==-100)//OpenCV Error
     {
      TextCtrl1->WriteText(_("\nOpen CV error:\n"));
      TextCtrl1->WriteText(run_tpg->ReturnOpenCVErrMess());
     }
        delete run_tpg;
    run_tpg=NULL;

       Timer1->Stop();
       delete Timer1;
      Timer1=NULL;
       loop_running=false;

    /////////////////////////////////////////////////////////
    /****** Enable menu tool bars and buttons *********************/
   MenuIRun->Enable(true);
     MenuIDebug->Enable(true);
    MenuINewProgram->Enable(true);
      MenuOpenProg->Enable(true);
      MenuSaveProg->Enable(true);
      MenuISetBreak->Enable(true);
      MenuIRemoveBreak->Enable(true);
      MenuRemoveAllBreak->Enable(true);
      MenuItem3->Enable(true); // Run loop menu button
      MenuItem4->Enable(false); //Menu stop loop button

/*     AddCommand->Enable(true);
     EditCommand->Enable(true);
     CopyCommands->Enable(true);
     DeleteCommands->Enable(true);*/
  ToolBar1->EnableTool(idStopLoop,false);
  ToolBar1->EnableTool(idRunLoop,true);
   ToolBar1->EnableTool(idToolDebug,true);
      ToolBar1->EnableTool(idToolRunTestPrg,true);
      ToolBar1->EnableTool(idToSetBreak,true);
      ToolBar1->EnableTool(idTolRemovBreak,true);
      ToolBar1->EnableTool(idTolRemoveAllBreak,true);
      ToolBar1->EnableTool(idOpen,true);
      ToolBar1->EnableTool(idSave,true);
      ToolBar1->EnableTool(idNew,true);
  ToolBar1->Realize();
    ////////////////////////////////////////////////////////

    }



if(first_time_view)
{
  t2=getTickCount();

        tx=t2-t1;
      long long tot_time=tx/(long)getTickFrequency();//calculate total time for test program



     wxString pxv;

      if(tot_time/1000>(loop_time_ms-15))
      {
        pxv.Printf(_("Error run loop:Please Change run loop time\nMinimal value for run loop time is:")) ;
        pxv<<((tot_time/1000)+15);
        pxv+=_("ms");
        TextCtrl1->WriteText(pxv);
            if(Timer1!=NULL)
        {
       Timer1->Stop();
       delete Timer1;
      Timer1=NULL;
         }

     loop_running=false;
     delete run_tpg;
     run_tpg=NULL;

      //End stop camera

      wxMessageBox(_("Run loop error"),_("Loop is stopped"),wxICON_ERROR);

       /****** Enable menu tool bars and buttons *********************/
 MenuIRun->Enable(true);
     MenuIDebug->Enable(true);
    MenuINewProgram->Enable(true);
      MenuOpenProg->Enable(true);
      MenuSaveProg->Enable(true);
      MenuISetBreak->Enable(true);
      MenuIRemoveBreak->Enable(true);
      MenuRemoveAllBreak->Enable(true);
      MenuItem3->Enable(true); // Run loop menu button
      MenuItem4->Enable(false); //Menu stop loop button

  ToolBar1->EnableTool(idStopLoop,false);
  ToolBar1->EnableTool(idRunLoop,true);
   ToolBar1->EnableTool(idToolDebug,true);
      ToolBar1->EnableTool(idToolRunTestPrg,true);
      ToolBar1->EnableTool(idToSetBreak,true);
      ToolBar1->EnableTool(idTolRemovBreak,true);
      ToolBar1->EnableTool(idTolRemoveAllBreak,true);
      ToolBar1->EnableTool(idOpen,true);
      ToolBar1->EnableTool(idSave,true);
      ToolBar1->EnableTool(idNew,true);
  ToolBar1->Realize();
    ////////////////////////////////////////////////////////

      }

     pxv=_("\nLoop Function time :");
      pxv<<tot_time;
      pxv+=_(" us");
      if(tot_time > 0)TextCtrl1->WriteText(pxv);
      first_time_view=false;
}
  if(view_cam_seque<5)
{
  view_cam_seque++;
  if(view_cam_seque==4)
  {
     first_time_view=true;
     view_cam_seque=5;
  }
}

}
   catch( cv::Exception& e )
    {
         delete run_tpg;
    run_tpg=NULL;

       Timer1->Stop();
       delete Timer1;
      Timer1=NULL;
       loop_running=false;
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    ErrorLog er;
    er.SetError(_("OpenCV error in function OnTimer1Trigger"),pv);
    er.DisplayLog();
    }
}



void eliFrame::OnPanel1Resize(wxSizeEvent& event)
{
   LayoutChildren();

}

void eliFrame::OnGrid2Resize(wxSizeEvent& event)
{
     SetResize2();
}

void eliFrame::OnGrid1Resize(wxSizeEvent& event)
{
    SetResize1();

}

/*
Set icons to Grid cell set break icon
*/
class myImageStopGridCellRenderer : public wxGridCellStringRenderer
{
public:
   virtual void Draw(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc, const wxRect& rect, int row, int col, bool isSelected)
   {
      wxGridCellStringRenderer::Draw(grid, attr, dc, rect, row, col, isSelected);

      wxImage cellImage;
wxFileName f(wxStandardPaths::Get().GetExecutablePath());
wxString pic=f.GetPath();
#if defined(__UNIX__)
pic=pic.BeforeLast('/');
pic+=wxT("/share/Eli/icons/break.png");
#elif defined(__WXMSW__)
pic=pic.BeforeLast('\\');
pic+=wxT("\\share\\Eli\\icons\\break.png");
#endif


        int xadd= grid.GetColSize(0)-20;

      if (cellImage.LoadFile(pic))
      {
         wxBitmap cellBitmap(cellImage);
         dc.DrawBitmap(cellBitmap, rect.x+xadd, rect.y);
      }

   }
};



/*
Set icons to Grid cell reset break icon
*/
class myImageClearBreakGridCellRenderer : public wxGridCellStringRenderer
{
public:
   virtual void Draw(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc, const wxRect& rect, int row, int col, bool isSelected)
   {
      wxGridCellStringRenderer::Draw(grid, attr, dc, rect, row, col, isSelected);

      wxImage cellImage;
      wxFileName f(wxStandardPaths::Get().GetExecutablePath());
      wxString pic=f.GetPath();
#if defined(__UNIX__)
pic=pic.BeforeLast('/');
pic+=wxT("/share/Eli/icons/empty.png");
#elif defined(__WXMSW__)
pic=pic.BeforeLast('\\');
pic+=wxT("\\share\\Eli\\icons\\empty.png");
#endif




        int xadd= grid.GetColSize(0)-20;

      if (cellImage.LoadFile(pic))
      {
         wxBitmap cellBitmap(cellImage);
         dc.DrawBitmap(cellBitmap, rect.x+xadd, rect.y);
      }

   }
};

void eliFrame::OnMenuIEditCometsSelected(wxCommandEvent& event)
{
wxString entry_dat=tp_prg->GetComents();
    wxTextEntryDialog dlg(this,_("Test program comments"),_("Edit / Insert comments"),entry_dat,wxTE_MULTILINE|wxOK|wxCENTRE);
    dlg.ShowModal();
    tp_prg->SetComments(dlg.GetValue());
}

int eliFrame::DrawBreak(int row)
{
Grid2->SetCellRenderer(row,0,new myImageStopGridCellRenderer);
Update();
Refresh();
    return 0;
}
int eliFrame::ReDrawBreak(int row)
{
Grid2->SetCellRenderer(row,0,new myImageClearBreakGridCellRenderer);
Update();
Refresh();
    return 0;
}

int eliFrame::FindCamera(void)
{
    cameras_info.Clear();
#if defined(__UNIX__)

int fd;
     v4l2_capability video_cap;
   v4l2_format  pix_form;

   /* struct video_window     video_win;
    struct video_picture   video_pic;*/
    bool endx=false;
    char cam_lab[40]={0};
    int xc=0;
    wxString cam_text;
    wxString rec_mes,p2;
    char *rec;

    while(!endx)
    {
         sprintf(cam_lab,"/dev/video%d",xc);
    if((fd = open(cam_lab, O_RDONLY)) != -1)
    {
        cam_text=_("************************\n*****Video_");
        cam_text<<xc;
        cam_text+=_("********\n******************\n");
        xc++;

        if(ioctl(fd, VIDIOC_QUERYCAP, &video_cap) != -1)
        {

     //Card type
      rec=new char[32];
      for(unsigned int i=0;i<sizeof(video_cap.card);i++)rec[i]=(char)video_cap.card[i];

      rec_mes=wxString::FromUTF8(rec);
     delete rec;
       cam_text+=_("Card type: ");
       cam_text+=rec_mes;

       //Bus info
       rec=new char[32];
      for(unsigned int i=0;i<sizeof(video_cap.bus_info);i++)rec[i]=(char)video_cap.bus_info[i];

      rec_mes=wxString::FromUTF8(rec);
     delete rec;
       cam_text+=_("\nBus info: ");
       cam_text+=rec_mes;

       //Driver module
       rec=new char[32];
      for(unsigned int i=0;i<sizeof(video_cap.driver);i++)rec[i]=(char)video_cap.driver[i];

      rec_mes=wxString::FromUTF8(rec);
     delete rec;
       cam_text+=_("\nDriver: ");
       cam_text+=rec_mes;

         rec_mes.Printf(_("\nCapabilities:%X"),video_cap.capabilities);
         cam_text+=rec_mes;
        }
             pix_form.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
          if(ioctl(fd, VIDIOC_G_FMT, &pix_form) != -1)
        {
          p2.Printf(_("\nWidth:%d"),(int)pix_form.fmt.pix.width);
          cam_text+=p2;
          p2.Printf(_("\nHeight:%d"),(int)pix_form.fmt.pix.height);
         cam_text+=p2;
         p2.Printf(_("\nBytes per line:%d\n"),(int)pix_form.fmt.pix.bytesperline);
         cam_text+=p2;
        }



      cameras_info.Add(cam_text);
    }
    else
    {
        endx=true;
    }
    close(fd);
    //Add to structure

    }


#endif // defined


    return 0;
}

void eliFrame::OnMenuFindCameraSelected(wxCommandEvent& event)
{
cameras_info.Clear();
  wxBusyInfo dlg(_("Please wait system find all connected cameras"));
   FindCamera();
   wxString pom=_("Find cameras finished\nFound ");
  pom<<cameras_info.size();
   pom+=_(" cameras\nList of cameras:\n");
   TextCtrl1->WriteText(pom);
   for(unsigned int i=0;i<cameras_info.size();i++)
   {
       TextCtrl1->WriteText(cameras_info[i]);
       TextCtrl1->WriteText(_("\n"));
   }
}

void eliFrame::OnMenuViewCameraSelected(wxCommandEvent& event)
{

ViewCameraFunction(false);

}

 void eliFrame::OnTimer2Trigger(wxTimerEvent& event)
 {
     long long t1=0,t2=0,tx;
       if(first_time_view)  t1=getTickCount();

     Mat imgxx;
    cam_video>>imgxx;
    if(undistor_view_flag)
    {
        double fxv=0;
        if(cam_calib==NULL)
        {
          undistor_view_flag=false;
          TextCtrl1->WriteText(_("Error View undistortion image\nCamera Calibation structure is null\n"));
          return;
        }
         if(!cam_calib->GetUndistortionImage(imgxx,imgxx,fxv))
         {
             delete cam_calib;
             cam_calib=NULL;
             undistor_view_flag=false;
             TextCtrl1->WriteText(_("Error View undistortion image\nError in function GetUndistortionImage\n"));
             return;//Get undistortion flag error
         }
        if(cam_calib->GetCvError())
         {
         delete cam_calib;
             cam_calib=NULL;
             undistor_view_flag=false;
             TextCtrl1->WriteText(_("Error View undistortion image\nOpenCv error in CameraCalibration class\n"));
             return;//OpenCV error
         }
    }
    GenerateDisplPicture(imgxx);
Update();
Refresh();




if(first_time_view)
{
  t2=cv::getTickCount();

        tx=t2-t1;
      double tot_time=(double)tx/cv::getTickFrequency();//calculate total time for test program

      wxConfig config2(wxT("cam_properties"),wxT("ELI"));
     wxString pxx;
    config2.Read(wxT("VievCamLoopTime"),&pxx);
    int loop_timex=wxAtoi(pxx);
    config2.Read(wxT("StartIndex"),&pxx);
    snapshot_cnt=wxAtoi(pxx);

     wxString pxv;

      if(tot_time*1000>(loop_timex-30))
      {
        pxv.Printf(_("Error view camera:Please Change view loop time\nMinimal value for View loop time is:")) ;
        pxv<<((tot_time*1000)+30);
        pxv+=_("ms");
        TextCtrl1->WriteText(pxv);
         //Stop camera
        StopViewCameraFunction();
      //End stop camera

      wxMessageBox(_("View camera error. Camera is stopped"),_("View camera error"),wxICON_ERROR);

      }

     pxv=_("\nFunction time :");
      pxv<<tot_time;
      pxv+=_(" s");
      if(tot_time>0)TextCtrl1->WriteText(pxv);
      first_time_view=false;
}

if(view_cam_seque<5)
{
  view_cam_seque++;
  if(view_cam_seque==4)
  {
     first_time_view=true;
     view_cam_seque=5;
  }
}


 }

void eliFrame::StopViewCameraFunction(void)
{
      cam_video.release();
      Timer2->Stop();
       delete Timer2;
    if(undistor_view_flag)
    {
        delete cam_calib;
             cam_calib=NULL;
             undistor_view_flag=false;
    }
      Timer2=NULL;
      MenuItem12->Enable(false);
      MenuItem10->Enable(true);
     MenuItem11->Enable(true);
     MenuItem15->Enable(false);
    MenuIRun->Enable(true);
     MenuIDebug->Enable(true);
    MenuItem3->Enable(true); // Run loop menu button
        ToolBar1->EnableTool(idRunLoop,true);
   ToolBar1->EnableTool(idToolDebug,true);
      ToolBar1->EnableTool(idToolRunTestPrg,true);
      ToolBar1->Realize();
}

void eliFrame::OnMenuStopCamera(wxCommandEvent& event)
{
StopViewCameraFunction();
}

void eliFrame::OnMenuCalibrateCamera(wxCommandEvent& event)
{
      wxString path;
    double square_size;
    int aspect_ratio,num_frames;
    int cam_numb;
    CameraCalibration dlg(this);
    if(dlg.ShowModal()==1)
    {
        dlg.Getparameters(path,square_size,aspect_ratio,num_frames,cam_numb);

        if(cam_calib!=NULL)delete cam_calib;

        cam_calib=new CameraCalib;
        cam_calib->SetCalibration(square_size,std::string(path.mb_str()),num_frames,aspect_ratio);

      if(calib_timer!=NULL)
      {
        calib_timer->Stop();
       delete calib_timer;
      calib_timer=NULL;
      }
     calib_timer=new wxTimer();

        cam_video.open(cam_numb);
    if(!cam_video.isOpened())
    {
        wxMessageBox(_("Error open selected camera"),_("Open camera error"),wxICON_ERROR);
        return;
    }

    calib_timer->SetOwner(this, ID_TIMER3);
    calib_timer->Start(1000,wxTIMER_ONE_SHOT);
    Connect(ID_TIMER3,wxEVT_TIMER,(wxObjectEventFunction)&eliFrame::OnCalibTimerTrigger);
    TextCtrl1->Clear();
    TextCtrl1->WriteText(_("Start camera calibration\n"));
    }

}

void eliFrame::CheckCalibration(void)
{
Mat imgxx;
cam_video>>imgxx;
int num_frames;
bool finish_calib;
  ErrorLog er;
  wxConfig config(wxT("calib_path"),wxT("ELI"));
	  wxString pom;
    config.Read(wxT("REL_FRAME"),&pom);
  int rel_frame=wxAtoi(pom);
  pom=wxEmptyString;
  config.Read(wxT("CAL_DELAY"),&pom);
  int cal_delay=wxAtoi(pom);

    bool rx=cam_calib->FoundCalibratedFrame(imgxx,num_frames,finish_calib);
    if(num_frames==-1)
    {

      er.SetError(_("CameraCalibration error"),_("Error in function FoundCalibrated frame"));
     er.DisplayLog();
        if(cam_calib->GetCvError())
        {
             er.SetError(_("CameraCalibration error"),cam_calib->GetErrorCVString());
             er.DisplayLog();
        }
        calib_timer->Stop();
       delete calib_timer;
      calib_timer=NULL;
      delete cam_calib;
      cam_calib=NULL;
      return;
    }

    if(cam_calib->GetCvError())
    {
        ErrorLog er;
      er.SetError(_("CameraCalibration error"),cam_calib->GetErrorCVString());
     er.DisplayLog();
         calib_timer->Stop();
       delete calib_timer;
      calib_timer=NULL;
      delete cam_calib;
      cam_calib=NULL;
      return;
    }

    if(finish_calib)
    {
     TextCtrl1->WriteText(_("Camera calibration finish\n"));
     wxString pd;
     pd.Printf(_("Reprojection error:%f"),cam_calib->GetReprojectionError());
     TextCtrl1->WriteText(pd);
     calib_timer->Stop();
       delete calib_timer;
      calib_timer=NULL;
      delete cam_calib;
      cam_calib=NULL;
    }
    else
    {
        if(rx)
        {
            wxString pd;
            pd.Printf(_("Found %d frames\n"),num_frames);
            TextCtrl1->WriteText(pd);
            calib_timer->Start(cal_delay,wxTIMER_ONE_SHOT);
        }
        else calib_timer->Start(rel_frame,wxTIMER_ONE_SHOT);

    }

    GenerateDisplPicture(imgxx);
    Update();
    Refresh();
}

void eliFrame::OnCalibTimerTrigger(wxTimerEvent& event)
{
    if(cam_calib==NULL)
    {
        calib_timer->Stop();
       delete calib_timer;
      calib_timer=NULL;
      wxMessageBox(_("CameraCalibration class was not allocated !!!"),_("Camera Calibration timer error"),wxICON_ERROR);
      return;
    }
CheckCalibration();
}

void eliFrame::ViewCameraFunction(bool undistor)
{
    undistor_view_flag=false;

    view_cam_seque=0;
     wxArrayString cameras_list;
    wxString pom;
    for(unsigned i=0;i<20;i++)
    {
      pom.Printf(_("Video_%d"),i);
      cameras_list.Add(pom);
    }


    wxSingleChoiceDialog dlg(this,_("Please select camera"),_("CameraView"),cameras_list);
    dlg.ShowModal();
    wxString selx=dlg.GetStringSelection();


 cam_video.open(wxAtoi(selx.AfterLast('_')));

    if(!cam_video.isOpened())
    {
        wxMessageBox(_("Error open selected camera"),_("Open camera error"),wxICON_ERROR);
        cam_video.release();
        return;
    }

    if(undistor)
    {

     wxString calib_path;
    wxString caption=wxT("Open calibration file");
    wxString wildcard=wxT("YML files (*.yml)|*.yml");
     wxString pok;
     wxString defaultDir;
    wxConfig config(wxT("calib_path"),wxT("ELI"));
    config.Read(wxT("def_dir"),&pok);
    if(pok.Len()==0) defaultDir=wxT("/home");
    else defaultDir=pok;


   wxString defaultFilename=wxEmptyString;

    wxFileDialog dialog(this,caption,defaultDir,defaultFilename,wildcard,wxFD_OPEN);
    if(dialog.ShowModal()==wxID_OK)
    {
       calib_path=dialog.GetPath();
     wxString sv=calib_path.BeforeLast('/');
      config.Write(wxT("def_dir"),sv);
    }
    else
    {
        cam_video.release();
        return;
    }
         if(cam_calib!=NULL)delete cam_calib;
        cam_calib=new CameraCalib;
        if(cam_calib->SetFileUndistortCalculation(std::string(calib_path.mb_str()),1)!=0)
        {
           wxMessageBox(_("Can not open calibration file"),_("Open calibration file error"),wxICON_ERROR);
           cam_video.release();
        return;
        }
         undistor_view_flag=true;
    }

     if(Timer2!=NULL)
    {
        Timer2->Stop();
       delete Timer2;
      Timer2=NULL;
    }
     Timer2=new wxTimer();
     MenuItem12->Enable(true);
     MenuItem10->Enable(false);
     MenuItem11->Enable(false);
       MenuIRun->Enable(false);
     MenuIDebug->Enable(false);
     MenuItem15->Enable(true);
        MenuItem3->Enable(false); // Run loop menu button
          ToolBar1->EnableTool(idRunLoop,false);
   ToolBar1->EnableTool(idToolDebug,false);
      ToolBar1->EnableTool(idToolRunTestPrg,false);
      ToolBar1->Realize();

    Timer2->SetOwner(this, ID_TIMER2);
    wxConfig config2(wxT("cam_properties"),wxT("ELI"));
    wxString pxx;
    config2.Read(wxT("VievCamLoopTime"),&pxx);
    Timer2->Start(wxAtoi(pxx),false);
    Connect(ID_TIMER2,wxEVT_TIMER,(wxObjectEventFunction)&eliFrame::OnTimer2Trigger);
}

void eliFrame::OnMenuViewCameraUndistor(wxCommandEvent& event)
{
ViewCameraFunction(true);
}

void eliFrame::OnMenuSnapshotCamera(wxCommandEvent& event)
{
    try
    {

     Mat imgxx;
    // if(!cam_video.isOpened())return;
    cam_video>>imgxx;

       if(undistor_view_flag)
    {
        double fxv=0;
        if(cam_calib==NULL)
        {
          undistor_view_flag=false;
          TextCtrl1->WriteText(_("Error View undistortion image\nCamera Calibation structure is null\n"));
          return;
        }
         if(!cam_calib->GetUndistortionImage(imgxx,imgxx,fxv))
         {
             delete cam_calib;
             cam_calib=NULL;
             undistor_view_flag=false;
             TextCtrl1->WriteText(_("Error View undistortion image\nError in function GetUndistortionImage\n"));
             return;//Get undistortion flag error
         }
        if(cam_calib->GetCvError())
         {
         delete cam_calib;
             cam_calib=NULL;
             undistor_view_flag=false;
             TextCtrl1->WriteText(_("Error View undistortion image\nOpenCv error in CameraCalibration class\n"));
             return;//OpenCV error
         }
    }

    wxConfig config2(wxT("cam_properties"),wxT("ELI"));
     wxString snap_directory,snap_filex,extensionx;
    config2.Read(wxT("def_snap_dir"),&snap_directory);
    config2.Read(wxT("snap_file"),&snap_filex);
    extensionx=snap_filex.AfterLast('.'); //Get file extension
    snap_filex=snap_filex.BeforeLast('.');
    snap_filex+=_("_");
    snap_filex<<snapshot_cnt;
    snap_filex+=_(".");
    snap_filex+=extensionx;
    snapshot_cnt++;
    snap_directory+=_("/");
    snap_directory+=snap_filex;
    imwrite(String(snap_directory.mbc_str()),imgxx);
    if(wxFileExists(snap_directory))
    {
        //file was saved
        TextCtrl1->WriteText(_("Snapshot was saved:"));
        TextCtrl1->WriteText(snap_directory);
        TextCtrl1->WriteText(_("\n"));
    }
    else
    {
        //Error save file
        TextCtrl1->WriteText(_("Error save snapshot file:"));
        TextCtrl1->WriteText(snap_directory);
        TextCtrl1->WriteText(_("\n"));
    }
        }
        catch( cv::Exception& e )
    {
    StopViewCameraFunction();
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    ErrorLog er;
    er.SetError(_("OpenCV error in function SnapShot Camera"),pv);
    er.DisplayLog();
    }
}

void eliFrame::OnMenuItemProperties(wxCommandEvent& event)
{
    CameraProperties dlg(this);
    dlg.ShowModal();
}
/**
This function gets actual variable status float+strings +objects
**/
void eliFrame::UpdateActualVariableStatus(void)
{
  if(run_tpg==NULL)return; // null pointer of runprogram class
  act_variables.all_obj.clear(); //clear object vector
  for(unsigned i=0;i<100;i++)act_variables.fval[i]=run_tpg->GetSystemVariable(i);
  for(unsigned i=0;i<10;i++)act_variables.strings_var[i]=run_tpg->GetStringVariables(i);
   run_tpg->GetAllObjects(act_variables.all_obj);


}

/**
Help info class

**/

help_info::help_info(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(help_info)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("ELI version:"), wxDefaultPosition, wxSize(264,46), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	VersionNumb = new wxStaticText(this, ID_STATICTEXT2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont VersionNumbFont(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	VersionNumb->SetFont(VersionNumbFont);
	BoxSizer2->Add(VersionNumb, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Build info"));
	Compiler_type = new wxStaticText(this, ID_STATICTEXT3, _("Compiler"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont Compiler_typeFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	Compiler_type->SetFont(Compiler_typeFont);
	StaticBoxSizer1->Add(Compiler_type, 1, wxALL|wxALIGN_LEFT, 5);
	BuildDate = new wxStaticText(this, ID_STATICTEXT4, _("Build date"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	wxFont BuildDateFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	BuildDate->SetFont(BuildDateFont);
	StaticBoxSizer1->Add(BuildDate, 1, wxALL|wxALIGN_LEFT, 5);
	osSystem = new wxStaticText(this, ID_STATICTEXT5, _("System"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	wxFont osSystemFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	osSystem->SetFont(osSystemFont);
	StaticBoxSizer1->Add(osSystem, 1, wxALL|wxALIGN_LEFT, 5);
	Lib_info = new wxStaticText(this, ID_STATICTEXT6, _("Lib:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	wxFont Lib_infoFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	Lib_info->SetFont(Lib_infoFont);
	StaticBoxSizer1->Add(Lib_info, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer1->Add(StaticBoxSizer1, 2, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	TextInfo = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer3->Add(TextInfo, 2, wxALL|wxEXPAND, 5);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	AutorBut = new wxButton(this, ID_BUTTON1, _("Authors and license"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer4->Add(AutorBut, 1, wxALL|wxEXPAND, 5);
	OpenCvBut = new wxButton(this, ID_BUTTON2, _("OpenCV build info"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer4->Add(OpenCvBut, 1, wxALL|wxEXPAND, 5);
	HyperlinkCtrl1 = new wxHyperlinkCtrl(this, ID_HYPERLINKCTRL1, _("Home page"), _("www.tsproj.com/eli"), wxDefaultPosition, wxDefaultSize, wxHL_CONTEXTMENU|wxHL_ALIGN_CENTRE|wxNO_BORDER, _T("ID_HYPERLINKCTRL1"));
	wxFont HyperlinkCtrl1Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	HyperlinkCtrl1->SetFont(HyperlinkCtrl1Font);
	BoxSizer4->Add(HyperlinkCtrl1, 1, wxALL|wxEXPAND, 5);
	ExitBut = new wxButton(this, ID_BUTTON3, _("Exit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer4->Add(ExitBut, 1, wxALL|wxEXPAND, 5);
	BoxSizer3->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer3, 3, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&help_info::OnAutorButClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&help_info::OnOpenCvButClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&help_info::OnExitButClick);
	//*)

	VersionNumb->SetLabel(wxT(ELI_VERSION_NUMBER));

	wxString pom=wxT("Compiler version: ");
	pom+=wxString::FromUTF8(__VERSION__);
	Compiler_type->SetLabel(pom);

	pom=wxT("Build date: ");
	pom+=wxString::FromUTF8(__DATE__);
	pom+=wxT(" ");
	pom+=wxString::FromUTF8(__TIME__);
	BuildDate->SetLabel(pom);

	wxPlatformInfo infx;
	pom=wxT("OS: ");
	pom+=infx.GetOperatingSystemDescription();
	pom+=_(" Arch:");
	pom+=infx.GetArchName();
	osSystem->SetLabel(pom);

	wxVersionInfo infv;
	pom=wxT("Lib: ");
	infv=wxGetLibraryVersionInfo();
	pom+=infv.GetVersionString();
	pom+=wxT("    OpenCV ");
	pom+=wxString::FromUTF8(CV_VERSION);
	Lib_info->SetLabel(pom);

   TextInfo->Clear();
    wxString autor=wxT("Tomas Stachera");
    wxString email=wxT("tomas.stachera@gmail.com");

wxString  iinfx=wxT("Author: ");
    iinfx+=autor;
    iinfx+=_("\nEmail:");
    iinfx+=email;
    iinfx+=_("\n\nLicense: The 3-Clause BSD License\n");
    iinfx+=_("Copyright (c) 2019,Tomas Stachera\n");
    iinfx+=_("https://opensource.org/licenses/BSD-3-Clause");


    TextInfo->WriteText(iinfx);
}

help_info::~help_info()
{
	//(*Destroy(help_info)
	//*)
}


void help_info::OnAutorButClick(wxCommandEvent& event)
{
    TextInfo->Clear();
    wxString autor=wxT("Tomas Stachera");
    wxString email=wxT("tomas.stachera@gmail.com");

    wxString infx=wxT("Author: ");
    infx+=autor;
    infx+=_("\nEmail:");
    infx+=email;
    infx+=_("\n\nLicense: The 3-Clause BSD License\n");
    infx+=_("Copyright (c) 2019,Tomas Stachera\n");
    infx+=_("https://opensource.org/licenses/BSD-3-Clause");

    TextInfo->WriteText(infx);
}

void help_info::OnOpenCvButClick(wxCommandEvent& event)
{
    TextInfo->Clear();
    String s=cv::getBuildInformation();
    int n = s.length();

    char char_array[n + 1];

    strcpy(char_array, s.c_str());
    wxString info_str(char_array,wxConvUTF8);

    TextInfo->WriteText(info_str);
}

void help_info::OnExitButClick(wxCommandEvent& event)
{
    EndModal(0);
}
