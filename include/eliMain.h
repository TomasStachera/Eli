/***************************************************************
 * Name:      eliMain.h
 * Purpose:   Defines Application Frame
 * Author:    Tomas Stachera (tomas.stachera@gmail.com)
 * Created:   2011-09-27
 * Copyright: Tomas Stachera ()
 * License:
 **************************************************************/

#ifndef ELIMAIN_H
#define ELIMAIN_H

//(*Headers(eliFrame)
#include <wx/treectrl.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/toolbar.h>
#include <wx/panel.h>
#include <wx/grid.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

#include <new>

#include <wx/filedlg.h>
#include <wx/dirdlg.h>
#include <wx/colordlg.h>
#include <wx/imaglist.h>
#include <wx/timer.h>
#include <wx/gauge.h>
#include <wx/stattext.h>
#include "wx/image.h"
#include "wx/imagpng.h"
#include "wx/wxhtml.h"
#include "wx/statline.h"

#include "commands_main.h"
#include "commands1.h"
#include "commands2.h"
#include "commands3.h"
#include "LoopDialog.h"
#include "CameraCalibration.h"


using namespace std;
using namespace cv;

/*****************************************************************
Class eliFrame

Class for display main window, wiht all buttons, subwindows...
*****************************************************************/

class eliFrame: public wxFrame, INIT_CMD
{
    public:

        eliFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~eliFrame();


   /********************************************************************
   Function CommandParam is use for setup lines in command grid (Grid1)
   Function is overloaded, last parameter is different according parameter
   which should be setup in command grid line
   *********************************************************************/
         int CommandParam(wxString name,unsigned int line,int type,wxString s_val);
        int CommandParam(wxString name,unsigned int line,int type, wxArrayString s_val);
        int CommandParam(wxString name,unsigned int line,int type,bool bval);
        int CommandParam(wxString name,unsigned int line,int type,int ival);
        int CommandParam(wxString name,unsigned int line,int type,float fval);

    protected:
    static const long ID_TIMER1;
    static const long ID_TIMER2;
    static const long ID_TIMER3;

    private:

        //(*Handlers(eliFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTreeCtrl1ItemRightClick(wxTreeEvent& event);
        void OnAddCommandClick(wxCommandEvent& event);
        void OnGrid2CellSelect(wxGridEvent& event);
        void OnEditCommandClick(wxCommandEvent& event);
        void OnGrid1CellLeftClick(wxGridEvent& event);
        void OnDeleteCommandsClick(wxCommandEvent& event);
        void OnCopyCommandsClick(wxCommandEvent& event);
        void OnMenuSaveProgSelected(wxCommandEvent& event);
        void OnMenuOpenProgSelected(wxCommandEvent& event);
        void OnMenuINewProgramSelected(wxCommandEvent& event);
        void OnCommandHelpSelected(wxCommandEvent& event);
        void OnMenuIRunSelected(wxCommandEvent& event);
        void OnMenuISetBreakSelected(wxCommandEvent& event);
        void OnMenuIRemoveBreakSelected(wxCommandEvent& event);
        void OnMenuRemoveAllBreakSelected(wxCommandEvent& event);
        void OnMenuIDebugSelected(wxCommandEvent& event);
        void OnMenuIStepSelected(wxCommandEvent& event);
        void OnMenuContinueSelected(wxCommandEvent& event);
        void OnMenuIStopDebugerSelected(wxCommandEvent& event);
        void OnMenuVariableSelected(wxCommandEvent& event);
        void OnPanel2Paint(wxPaintEvent& event);
        void OnRunLoopClicked(wxCommandEvent& event);
        void OnStopLoopClicked(wxCommandEvent& event);
        void OnClickAddNewCommand(wxCommandEvent& event);
        void OnClickChangeCommand(wxCommandEvent& event);
        void OnClickCopyCommand(wxCommandEvent& event);
        void OnClickDeleteCommand(wxCommandEvent& event);
        void OnPanel1Resize(wxSizeEvent& event);
        void OnGrid2Resize(wxSizeEvent& event);
        void OnGrid1Resize(wxSizeEvent& event);
        void OnMenuIEditCometsSelected(wxCommandEvent& event);
        void OnMenuFindCameraSelected(wxCommandEvent& event);
        void OnMenuViewCameraSelected(wxCommandEvent& event);
        void OnMenuStopCamera(wxCommandEvent& event);
        void OnMenuCalibrateCamera(wxCommandEvent& event);
        void OnMenuViewCameraUndistor(wxCommandEvent& event);
        void OnMenuSnapshotCamera(wxCommandEvent& event);
        void OnMenuItemProperties(wxCommandEvent& event);
        //*)


        int InsertCommands(void); // Function insert commands to commands list window
        void LayoutChildren(void);
        void SetResize2(void);
        void SetResize1(void);

        static const long ID_GAUGE1;
        static const long ID_STAT;
        //(*Identifiers(eliFrame)
        static const long ID_GRID1;
        static const long ID_TREECTRL1;
        static const long ID_GRID2;
        static const long ID_TEXTCTRL2;
        static const long ID_PANEL2;
        static const long ID_TEXTCTRL1;
        static const long ID_PANEL1;
        static const long idNewProgram;
        static const long idOpenProgram;
        static const long idSaveProgram;
        static const long idMenuQuit;
        static const long idAddCmd;
        static const long idChangeCmd;
        static const long idCompyCmd;
        static const long idDeleteCmd;
        static const long idComentsCmd;
        static const long idRun;
        static const long idMenRunLoop;
        static const long idMenuStopLoop;
        static const long idSetBreak;
        static const long idRemoveBreak;
        static const long idRemoveAll;
        static const long idDebug;
        static const long idStep;
        static const long idContinue;
        static const long idStopDebug;
        static const long ID_FIND_CAMERA;
        static const long ID_VIEW_CAMERA;
        static const long ID_VIEW_UNDISTR;
        static const long ID_CAM_SNAPSHOT;
        static const long ID_STOP_CAMERA;
        static const long idCalibrateCamera;
        static const long idCamProperties;
        static const long idMenuAbout;
        static const long idCommandHelp;
        static const long ID_STATUSBAR1;
        static const long idOpen;
        static const long idSave;
        static const long idNew;
        static const long idToolRunTestPrg;
        static const long idToSetBreak;
        static const long idTolRemovBreak;
        static const long idTolRemoveAllBreak;
        static const long idToolDebug;
        static const long idToolStep;
        static const long idToolContinue;
        static const long idToolStopDeb;
        static const long idRunLoop;
        static const long idStopLoop;
        static const long ID_TOOLBAR1;
        //*)
        static const long ID_MENU_VARIABLE;
        static const long ID_TOOLBAR2;
        static const long id_toolbar_add;
        static const long id_toolbar_change;
        static const long id_toolbar_delete;
        static const long id_toolbar_copy;
        static const long id_toolbar_coments;

        //(*Declarations(eliFrame)
        wxToolBarToolBase* ToolBarItem4;
        wxMenuItem* MenuRemoveAllBreak;
        wxMenuItem* MenuIRemoveBreak;
        wxMenuItem* MenuItem8;
        wxToolBar* ToolBar1;
        wxToolBarToolBase* ToolBarItem9;
        wxMenuItem* MenuItem7;
        wxTextCtrl* CommentsCmd;
        wxMenuItem* MenuISetBreak;
        wxToolBarToolBase* ToolBarItem3;
        wxToolBarToolBase* ToolBarItem12;
        wxToolBarToolBase* ToolBarItem11;
        wxMenuItem* MenuIDebug;
        wxToolBarToolBase* ToolBarItem10;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuIRun;
        wxMenuItem* MenuItem14;
        wxMenuItem* MenuItem11;
        wxMenuItem* MenuItem15;
        wxMenuItem* CommandHelp;
        wxPanel* Panel1;
        wxGrid* Grid1;
        wxMenuItem* MenuItem10;
        wxToolBarToolBase* ToolBarItem6;
        wxToolBarToolBase* ToolBarItem13;
        wxMenuItem* MenuItem12;
        wxMenuItem* MenuContinue;
        wxToolBarToolBase* ToolBarItem1;
        wxGrid* Grid2;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuIStep;
        wxStatusBar* StatusBar1;
        wxMenuItem* MenuItem6;
        wxTreeCtrl* TreeCtrl1;
        wxMenuItem* MenuSaveProg;
        wxToolBarToolBase* ToolBarItem5;
        wxTextCtrl* TextCtrl1;
        wxToolBarToolBase* ToolBarItem8;
        wxPanel* Panel2;
        wxMenuItem* MenuINewProgram;
        wxMenuItem* MenuItem16;
        wxMenu* Menu6;
        wxMenuItem* MenuOpenProg;
        wxToolBarToolBase* ToolBarItem2;
        wxMenu* Menu4;
        wxMenuItem* MenuIStopDebuger;
        wxToolBarToolBase* ToolBarItem7;
        //*)
        wxMenuItem *variable_window;
        wxToolBar* ToolBar2;
        wxToolBarToolBase* ToolBarAddCmd;
        wxToolBarToolBase* ToolBarChangeCmd;
        wxToolBarToolBase* ToolBarDeleteCmd;
        wxToolBarToolBase* ToolBarCopyCmd;
         wxToolBarToolBase* ToolBarComments;

        wxGauge *gaug; // gauge for display run loop running
        wxStaticText *stat;
        wxString actual_dir;

          wxTimer* Timer1;
          wxTimer* Timer2;
          int guge_cnt,init_gauge;// gauge cnt is actual value in loop gauge which is increment, init gauge  is value how many times timer must run befor guuge value change
          int gauge_pom; // help value for gauge incrementation.
          wxTimer* calib_timer;

          int loop_time_ms,loop_start_line; // loop time is number in milisecond. Next loop start after this time pased, loop_start_line is start line number from where loops 2 ... started
          wxString old_loop_string; //this string is use fo store old result string durring run loop

         void OnTimer1Trigger(wxTimerEvent& event);
         void OnTimer2Trigger(wxTimerEvent& event);
         void OnCalibTimerTrigger(wxTimerEvent& event);
        int UpdateGrid(int rx);
        void UpdateProgParam(int x);
        wxString GetCommandParam(void);
        int GenerateDisplPicture(Mat img);
        void DrawBitmatPic(void);
        int DrawBreak(int row);
        int ReDrawBreak(int row);
        void ClearAllBreaks(void);
        int FindCamera(void);
        void CheckCalibration(void);
        void ViewCameraFunction(bool undistor=false);
        void StopViewCameraFunction(void);
        void UpdateActualVariableStatus(void);

        bool loop_running; //if loop is running ,variable is true if not false
        Mat displayed_Image; //Image is display in result window
        bool isDisplayedImage;
        bool undistor_view_flag;
        bool first_time_view;
        int snapshot_cnt;//Actual camera view snapshot number
        int view_cam_seque;


        int *but_gr; // Variable is use for set type of parameter in double click.Array number is line number and value means type of parameter in command grid
        wxImageList *im; //Variable is use in command list window for display command with icon in command list window

        int ins_line; //Variable is use for store actually selected line in Test program grid Grid2
        TestProgram *tp_prg; //Pointer for TestProgram array

      CommandBase comnd_base[NUMBER_COMMANDS_CLASS]; //structur where is placed all commands with position in list box
        RunTestProgram *run_tpg;
        ObjectPrograms *ob_prg;
        wxString p_name;
       wxArrayString cameras_info;
        VideoCapture cam_video;
        CameraCalib *cam_calib;

        /**
        Structure ACTUAL_VARIABLES is used for store actual variables value
        and actual object founds in program
        **/
        struct ACTUAL_VARIABLES{
         float fval[100];
         wxString strings_var[10];
         vector<OBJECTFOUND> all_obj;
        };

        ACTUAL_VARIABLES act_variables;

        DECLARE_EVENT_TABLE()
};






#endif // ELIMAIN_H
