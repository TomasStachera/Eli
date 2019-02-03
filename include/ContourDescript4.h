#ifndef CONTOURDESCRIPT4_H_INCLUDED
#define CONTOURDESCRIPT4_H_INCLUDED

//(*Headers(ObjectDes)
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/grid.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/choice.h>
#include <wx/radiobox.h>
//*)
#include <wx/stattext.h>
#include <wx/listbox.h>

#include "ContourDescript3.h"

/*********************************************************
Class object  display object module window
Input parameters: parent: parent window
                  cont_calc : ContourCalculation class
                  syst_var: system variable array
                  id: window id
                  pos: window position
                  size: window size
**************************************************************/
class object: public wxDialog
{
	public:

		object(wxWindow* parent,ContourCalculation *cont_calc,float *syst_var,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~object();

		//(*Declarations(object)
		wxButton* Delete_objects;
		wxButton* Copy_objects;
		wxButton* Update_modul;
		wxGrid* Grid1;
		wxButton* Edit_object;
		wxButton* New_object;
		//*)
		wxButton* Debug_object;
		wxButton* ExportObject;
		wxButton* ImportObject;


	protected:

		//(*Identifiers(object)
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_BUTTON5;
		static const long ID_GRID1;
		//*)
		static const long ID_BUTTON6;
        static const long ID_BUTTON7; //Export object
        static const long ID_BUTTON8;  //Import object

	private:

		//(*Handlers(object)
		void OnNew_objectClick(wxCommandEvent& event);
		void OnEdit_objectClick(wxCommandEvent& event);
		//*)
		void OnCopy_objectClick(wxCommandEvent& event);
		void OnDelete_objectClick(wxCommandEvent& event);
		void OnUpdate_objectClick(wxCommandEvent& event);
		void OnDebug_objectClick(wxCommandEvent& event);
		void OnExport_objectClick(wxCommandEvent& event);
		void OnImport_objectClick(wxCommandEvent& event);

		ContourCalculation *cont_calcx;
		TestProgram *object_prog;

		int AddTestProgramToStruct(wxString name,ContourCalculation *calc,TestProgram *tpg,wxArrayString description);
		int AddStructToProgram(wxString name,ContourCalculation *calc,TestProgram *tpg,wxArrayString &description);

         float system_var[100];

		DECLARE_EVENT_TABLE()
};

/*****************************************************************************
Class ObjectDes
Class for create object description function according object descriptoin test program
Input parameters:
- parent : parent window
- Object_name: Name of object
- coments: Object description
- cont_calc : pointer for Contour calculation structure
- obj_tpg: Test program class for current object
- descript: description on each test program line
******************************************************************************/


class ObjectDes: public wxDialog
{
	public:

		ObjectDes(wxWindow* parent,wxString Object_name,wxString comments,ContourCalculation *cont_calc,TestProgram *obj_tpg,wxArrayString decsript,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ObjectDes();

		//(*Declarations(ObjectDes)
		wxButton* UpdateModule;
		wxTextCtrl* ObjectName;
		wxButton* InsertLine;
		wxGrid* Grid1;
		wxButton* DeleteLine;
		wxButton* EditLine;
		wxButton* CopyLines;
		wxTextCtrl* ObjectDescript;
		//*)
		wxArrayString GetDescriptionArray(void){return description_array;}

	protected:

		//(*Identifiers(ObjectDes)
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_BUTTON5;
		static const long ID_GRID1;
		//*)

	private:

		//(*Handlers(ObjectDes)
		void OnInsertLineClick(wxCommandEvent& event);
		void OnEditLineClick(wxCommandEvent& event);
		void OnCopyLinesClick(wxCommandEvent& event);
		void OnDeleteLineClick(wxCommandEvent& event);
		void OnUpdateModuleClick(wxCommandEvent& event);
		//*)
		ContourCalculation *cont_calcx;
		TestProgram *obj_tpgx;
         bool CheckModule(void);

         wxArrayString description_array;

		DECLARE_EVENT_TABLE()
};

/*******************************************************************************************
MathSubModule class

This class is called when user want edit MATH command

Input parameters:
- parent: parent window
- cont_calc: pointer for ContourCalculation structure
- prog_param: command paramters
*******************************************************************************************/
class MathSubModule: public wxDialog
{
	public:

		MathSubModule(wxWindow* parent,ContourCalculation *cont_calc,wxString prog_param,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~MathSubModule();

		//(*Declarations(MathSubModule)
		wxTextCtrl* Param1_Option_text;
		wxChoice* Math_operand;
		wxTextCtrl* Param2_Option_text;
		wxChoice* Result_option_choice;
		wxChoice* Param1_option_choice;
		wxChoice* Param2_option_choice;
		wxTextCtrl* Result_option_text;
		wxChoice* Result;
		wxChoice* Choice1;
		wxChoice* Choice2;
		//*)
			wxButton* CloseObj;
        wxString GetCommandParameter(void);
	protected:

		//(*Identifiers(MathSubModule)
		static const long ID_CHOICE1;
		static const long ID_CHOICE2;
		static const long ID_TEXTCTRL2;
		static const long ID_CHOICE3;
		static const long ID_CHOICE4;
		static const long ID_CHOICE5;
		static const long ID_TEXTCTRL3;
		static const long ID_CHOICE6;
		static const long ID_CHOICE7;
		static const long ID_TEXTCTRL1;
		//*)
		static const long ID_BUTTON7;

	private:

		//(*Handlers(MathSubModule)
		void OnChoice1Select(wxCommandEvent& event);
		void OnChoice2Select(wxCommandEvent& event);
		void OnChoice6Select(wxCommandEvent& event);
		//*)
		void OnButtonCloseClick(wxCommandEvent& event);
		ContourCalculation *cont_calcx;
		void FillParameters(wxString param);
		void FillParameters2(wxString param);

		DECLARE_EVENT_TABLE()
};
/*******************************************************************************************************
ConditionSubModule class

Class is displayed when user click on command CONDITION
Input parameters:
- parent: parent window
- cont_calc: pointer for ContourCalculation class
- prog_param: object program parameters
*******************************************************************************************************/
class ConditionSubModule: public wxDialog
{
	public:

		ConditionSubModule(wxWindow* parent,ContourCalculation *cont_calc,wxString prog_param,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ConditionSubModule();

		//(*Declarations(ConditionSubModule)
		wxTextCtrl* Param2_option_text;
		wxTextCtrl* Param1_op_text;
		wxChoice* Param1;
		wxChoice* Compar_option;
		wxChoice* Param1_option_choice;
		wxChoice* Param2_option_choice;
		wxChoice* Parameter2;
		//*)
		wxButton* CloseObj;

		wxString GetCommandParameter(void);

	protected:

		//(*Identifiers(ConditionSubModule)
		static const long ID_CHOICE1;
		static const long ID_CHOICE2;
		static const long ID_TEXTCTRL1;
		static const long ID_CHOICE3;
		static const long ID_CHOICE4;
		static const long ID_CHOICE5;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON7;
		//*)

	private:
         void OnChoice1Select(wxCommandEvent& event);
		void OnChoice4Select(wxCommandEvent& event);
		void OnButtonCloseClick(wxCommandEvent& event);
		//(*Handlers(ConditionSubModule)
		void OnCompar_optionSelect(wxCommandEvent& event);
		//*)
		void FillParameters(wxString param);
		void FillParameters2(wxString param);
		ContourCalculation *cont_calcx;

		DECLARE_EVENT_TABLE()
};

/************************************************************************************************
     Contour debug class
Window displays debug information for selected object. User can debug test program for selected object.

Input parameters:
- parent: parent window
- cont_calc: pointer for ContourCalculation class
- syst_var: array of system variables
- object_name: Name of object which will be edited
************************************************************************************************/
class ContourDebug: public wxDialog
{
	public:

		ContourDebug(wxWindow* parent,ContourCalculation *cont_calc,float *syst_var,wxString obj_name,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ContourDebug();

		//(*Declarations(ContourDebug)
		wxButton* Continue;
		wxButton* Break;
		wxStaticText* StaticText2;
		wxChoice* Contour;
		wxStaticText* StaticText1;
		wxGrid* Grid1;
		wxButton* Step;
		wxTextCtrl* VariableVal;
		wxRadioBox* RadioBox1;
		wxButton* Start;
		wxStaticText* TotalResult;
		wxTextCtrl* CommandWindow;
		wxListBox* ListBox1;
		//*)

	protected:

		//(*Identifiers(ContourDebug)
		static const long ID_CHOICE1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_RADIOBOX1;
		static const long ID_LISTBOX1;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_GRID1;
		static const long ID_TEXTCTRL1;
		//*)

	private:

		//(*Handlers(ContourDebug)
		void OnBreakClick(wxCommandEvent& event);
		void OnStartClick(wxCommandEvent& event);
		void OnContinueClick(wxCommandEvent& event);
		void OnStepClick(wxCommandEvent& event);
		void OnRadioBox1Select(wxCommandEvent& event);
		void OnListBox1DClick(wxCommandEvent& event);
		//*)

		ContourCalculation *cont;

		int DisplayVariables(int type);
		int ProgramExecution(int cont_numb,int from_line,int to_line);

		void DisplayConditionStatus(void);

		bool start_flag;
		int stoped_line;
		int object_pos;

		float system_var[100];


 /*
 Structure for all line parameters
 */
		struct DebParam
		{
		  wxString cmd; //command name
		  wxString desc; // command descriptoion
		  wxString line_des;// command formula
		  bool _xbreak; // true if break was active on line
		};

		DebParam *deb_par;

		DECLARE_EVENT_TABLE()
};

/***************************************************
Class ObjectList
Class for display all found objects with its parameters
Input parameters: parent : parent window
                  obj_numb : Number of found objects
                  ob : Pointer for OBJECTFOUND structure
                  id: window id
*****************************************************/
class ObjectList: public wxDialog
{
	public:

		ObjectList(wxWindow* parent,int obj_numb,OBJECTFOUND *ob,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ObjectList();

		//(*Declarations(ObjectList)
		wxButton* Exit;
		wxStaticText* Cont_a;
		wxStaticText* Bound_x;
		wxStaticText* Perim;
		wxButton* Show_object;
		wxStaticText* Bound_h;
		wxStaticText* Bound_y;
		wxStaticText* Bound_w;
		wxListBox* ListBox1;
		//*)

	protected:

		//(*Identifiers(ObjectList)
		static const long ID_LISTBOX1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(ObjectList)
		void OnShow_objectClick(wxCommandEvent& event);
		void OnExitClick(wxCommandEvent& event);
		void OnListBox1Select(wxCommandEvent& event);
		//*)

		int num_obj;
		OBJECTFOUND *ob_fnd;


		DECLARE_EVENT_TABLE()
};
/********************************************************
Object Setup class
Class displayed window where user can setup basic parameter on Contour Description window
**********************************************************/
class ObjectSetup: public wxDialog
{
	public:

		ObjectSetup(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ObjectSetup();

		//(*Declarations(ObjectSetup)
		wxButton* Exit;
		wxChoice* Linetype;
		wxRadioBox* V_scale;
		wxRadioBox* H_scale;
		wxTextCtrl* Obj_line_thickness;
		wxTextCtrl* Obj_name_col_G;
		wxChoice* Font_sel;
		wxButton* Obj_col_change;
		wxTextCtrl* Obj_name_line_thickness;
		wxTextCtrl* Obj_name_col_B;
		wxTextCtrl* Obj_name_col_R;
		wxTextCtrl* Obj_line_col_B;
		wxTextCtrl* Obj_line_col_R;
		wxButton* Update;
		wxTextCtrl* Obj_line_col_G;
		wxButton* Obj_name_change;
		//*)

	protected:

		//(*Identifiers(ObjectSetup)
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_BUTTON1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_TEXTCTRL5;
		static const long ID_TEXTCTRL6;
		static const long ID_TEXTCTRL7;
		static const long ID_BUTTON4;
		static const long ID_CHOICE1;
		static const long ID_RADIOBOX1;
		static const long ID_RADIOBOX2;
		static const long ID_TEXTCTRL8;
		static const long ID_CHOICE2;
		//*)

	private:

		//(*Handlers(ObjectSetup)
		void OnObj_col_changeClick(wxCommandEvent& event);
		void OnObj_name_changeClick(wxCommandEvent& event);
		void OnUpdateClick(wxCommandEvent& event);
		void OnExitClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif // CONTOURDESCRIPT4_H_INCLUDED
