#ifndef LOOPDIALOG_H
#define LOOPDIALOG_H

//(*Headers(LoopDialog)
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/combobox.h>
//*)

class LoopDialog: public wxDialog
{
	public:

		LoopDialog(wxWindow* parent,int num_lines,wxWindowID id=wxID_ANY);
		virtual ~LoopDialog();
		int GetStartLine(void){return _StartLine;}
		int GetLoopTime(void){return loop_time;}

		//(*Declarations(LoopDialog)
		wxButton* OK_button;
		wxComboBox* StartLine;
		wxTextCtrl* Repeattime;
		//*)

	protected:

		//(*Identifiers(LoopDialog)
		static const long ID_COMBOBOX1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(LoopDialog)
		void OnOK_buttonClick(wxCommandEvent& event);
		//*)
		bool TransferDataFromWindow(void);

		int _StartLine,loop_time;

		DECLARE_EVENT_TABLE()
};

#endif
