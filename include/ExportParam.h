#ifndef EXPORTPARAM_H
#define EXPORTPARAM_H

//(*Headers(ExportParam)
#include <wx/sizer.h>
#include <wx/checklst.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#include <vector>
using namespace std;

class ExportParam: public wxDialog
{
	public:

		ExportParam(wxWindow* parent,vector<int> cont_pos,vector<vector<vector<double> > > datx,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ExportParam();

		//(*Declarations(ExportParam)
		wxButton* CancelBut;
		wxCheckListBox* CheckListBox1;
		wxCheckBox* CheckBox1;
		wxButton* Export;
		//*)

	protected:

		//(*Identifiers(ExportParam)
		static const long ID_CHECKLISTBOX1;
		static const long ID_CHECKBOX1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(ExportParam)
		void OnExportClick(wxCommandEvent& event);
		void OnCancelButClick(wxCommandEvent& event);
		//*)
		int WriteDataToFile(wxString path);
       vector<vector<vector<double> > > datx2;
       vector<int> cont_pos2;
		DECLARE_EVENT_TABLE()
};

#endif
