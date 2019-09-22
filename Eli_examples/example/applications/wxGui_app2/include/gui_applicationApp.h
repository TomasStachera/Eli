/***************************************************************
 * Name:      gui_applicationApp.h
 * Purpose:   Defines Application Class
 * Author:    Tomas Stachera (tomas.stachera@gmail.com)
 * Created:   2019-09-20
 * Copyright: Tomas Stachera ()
 * License:
 **************************************************************/

#ifndef GUI_APPLICATIONAPP_H
#define GUI_APPLICATIONAPP_H

#include <wx/app.h>

class gui_applicationApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // GUI_APPLICATIONAPP_H
