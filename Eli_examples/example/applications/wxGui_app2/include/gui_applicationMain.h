/***************************************************************
 * Name:      gui_applicationMain.h
 * Purpose:   Defines Application Frame
 * Author:    Tomas Stachera (tomas.stachera@gmail.com)
 * Created:   2019-09-20
 * Copyright: Tomas Stachera ()
 * License:
 **************************************************************/

#ifndef GUI_APPLICATIONMAIN_H
#define GUI_APPLICATIONMAIN_H

//(*Headers(gui_applicationFrame)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class gui_applicationFrame: public wxFrame
{
    public:

        gui_applicationFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~gui_applicationFrame();

    private:

        //(*Handlers(gui_applicationFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnChangePathClick(wxCommandEvent& event);
        void OnRunAllClick(wxCommandEvent& event);
        void OnRunLoopClick(wxCommandEvent& event);
        void OnStopLoopClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(gui_applicationFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_CHOICE1;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL3;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(gui_applicationFrame)
        wxButton* ChangePath;
        wxButton* RunAll;
        wxButton* RunLoop;
        wxButton* StopLoop;
        wxChoice* RetParameter;
        wxPanel* Panel1;
        wxStaticText* StaticTextOut;
        wxStatusBar* StatusBar1;
        wxTextCtrl* ObjectName;
        wxTextCtrl* PathToProg;
        wxTextCtrl* TextVarOut;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GUI_APPLICATIONMAIN_H
