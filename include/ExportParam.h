#ifndef EXPORTPARAM_H
#define EXPORTPARAM_H

//(*Headers(ExportParam)
#include <wx/sizer.h>
#include <wx/checklst.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
//*)
#include <vector>
using namespace std;

class AlasesExp: public wxDialog
{
	public:

		AlasesExp(wxWindow* parent,vector<wxString> contours_inf,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~AlasesExp();

		//(*Declarations(AlasesExp)
		wxButton* AddAlias;
		wxButton* ClearAlias;
		wxButton* Exitbutton;
		wxButton* SelAliasFile;
		wxChoice* Alais;
		wxChoice* Contour;
		wxTextCtrl* NewAlias;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(AlasesExp)
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_CHOICE1;
		static const long ID_CHOICE2;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON3;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON4;
		//*)

	private:

		//(*Handlers(AlasesExp)
		void OnSelAliasFileClick(wxCommandEvent& event);
		void OnClearAliasClick(wxCommandEvent& event);
		void OnAddAliasClick(wxCommandEvent& event);
		void OnExitbuttonClick(wxCommandEvent& event);
		//*)

		vector<vector<wxString> >aliases;

		DECLARE_EVENT_TABLE()
};


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
		wxButton* alias;
		//*)

	protected:

		//(*Identifiers(ExportParam)
		static const long ID_CHECKLISTBOX1;
		static const long ID_CHECKBOX1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(ExportParam)
		void OnExportClick(wxCommandEvent& event);
		void OnCancelButClick(wxCommandEvent& event);
		void OnAliasButtonClick(wxCommandEvent& event);
		//*)
		int WriteDataToFile(wxString path);
       vector<vector<vector<double> > > datx2;
       vector<int> cont_pos2;
		DECLARE_EVENT_TABLE()
};

#endif
