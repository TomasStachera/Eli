/***************************************************************
 * Name:      eliApp.h
 * Purpose:   Defines Application Class
 * Author:    Tomas Stachera (tomas.stachera@gmail.com)
 * Created:   2011-09-27
 * Copyright: Tomas Stachera ()
 * License:
 **************************************************************/

#ifndef ELIAPP_H
#define ELIAPP_H

#include <wx/app.h>

class eliApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // ELIAPP_H
