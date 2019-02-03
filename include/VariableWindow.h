#ifndef VARIABLEWINDOW_H
#define VARIABLEWINDOW_H

//(*Headers(VariableWindow)
#include <wx/sizer.h>
#include <wx/radiobox.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class VariableWindow: public wxDialog
{
	public:

		VariableWindow(wxWindow* parent,wxArrayString objx,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~VariableWindow();
		void GetParameters(int &var_pos,int &string_pos,int &obj_pos,int &obj_status,int &obj_param)
		{
		    var_pos=pos_glob[0];
		    string_pos=pos_glob[1];
		    obj_pos=pos_glob[2];
		    obj_status=pos_glob[3];
		    obj_param=pos_glob[4];
		}

		//(*Declarations(VariableWindow)
		wxButton* Button1;
		wxChoice* ObjectParam;
		wxChoice* SystVar;
		wxChoice* SystStrings;
		wxRadioBox* RadioBox1;
		wxChoice* Objects;
		//*)

	protected:

		//(*Identifiers(VariableWindow)
		static const long ID_CHOICE1;
		static const long ID_CHOICE2;
		static const long ID_CHOICE3;
		static const long ID_CHOICE4;
		static const long ID_RADIOBOX1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(VariableWindow)
		void OnButton1Click(wxCommandEvent& event);
		void OnRadioBox1Select(wxCommandEvent& event);
		//*)

		int pos_glob[5];
		/**0=variable position
		1=string pos,
		2=object pos,
		3=object status(0=number of object 1= object parameter)
        4=object parameter
                                                                  **/

		DECLARE_EVENT_TABLE()
};

#endif
