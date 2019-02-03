/***************************************************************
 * Name:      eliApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Tomas Stachera (tomas.stachera@gmail.com)
 * Created:   2011-09-27
 * Copyright: Tomas Stachera ()
 * License:
 **************************************************************/

#include "eliApp.h"

//(*AppHeaders
#include "eliMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(eliApp);

bool eliApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	eliFrame* Frame = new eliFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
