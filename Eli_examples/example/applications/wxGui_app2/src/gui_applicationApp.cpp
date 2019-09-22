/***************************************************************
 * Name:      gui_applicationApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Tomas Stachera (tomas.stachera@gmail.com)
 * Created:   2019-09-20
 * Copyright: Tomas Stachera ()
 * License:
 **************************************************************/

#include "gui_applicationApp.h"

//(*AppHeaders
#include "gui_applicationMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(gui_applicationApp);

bool gui_applicationApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	gui_applicationFrame* Frame = new gui_applicationFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
