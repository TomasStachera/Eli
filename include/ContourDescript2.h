#ifndef CONTOURDESCRIPT2_H
#define CONTOURDESCRIPT2_H

//(*Headers(ContourDescript2)
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/grid.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#include "ContourDescript.h"
#include "ContourDescript3.h"


/*
Class for displaying filter window
Input parameters:
  - parent: parent window
  - id: window id
  - pos: position of window
  - size : size of window
  - syst_variable : system variable array
  - cont_calc: ContourCalculation class
*/
class ContourDescript2: public wxDialog
{
	public:

		ContourDescript2(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize,float *syst_variable=0,ContourCalculation *cont_calc=0);
		virtual ~ContourDescript2();

		//(*Declarations(ContourDescript2)
		wxButton* UpdateModule;
		wxButton* InsertLine;
		//wxCheckBox* CheckBox3;
		//wxCheckBox* CheckBox2;
		wxGrid* Grid1;
		//wxCheckBox* CheckBox1;
		wxButton* DeleteLine;
		//wxCheckBox* CheckBox4;
		//wxCheckBox* CheckBox5;
		//*)

	protected:

		//(*Identifiers(ContourDescript2)
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		/*static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_CHECKBOX3;
		static const long ID_CHECKBOX4;
		static const long ID_CHECKBOX5;*/
		static const long ID_BUTTON4;
		static const long ID_GRID1;
		//*)

	private:

		//(*Handlers(ContourDescript2)
		void OnButtonInsertLine(wxCommandEvent& event);
		void OnDeleteLineClick(wxCommandEvent& event);
		void OnCopyBlockClick(wxCommandEvent& event);
		void OnGrid1CellChange(wxGridEvent& event);
		void OnGrid1CellLeftClick(wxGridEvent& event);
		void OnGrid1CellLeftClick1(wxGridEvent& event);
		void OnUpdateModuleClick(wxCommandEvent& event);
		//*)
		void InserGridLine(void);

		float syst_var[100];
		ContourCalculation *cont_calcx;

		DECLARE_EVENT_TABLE()
};

#endif
