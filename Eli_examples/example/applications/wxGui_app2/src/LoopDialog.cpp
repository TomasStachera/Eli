#include "LoopDialog.h"

//(*InternalHeaders(LoopDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/config.h>

//(*IdInit(LoopDialog)
const long LoopDialog::ID_COMBOBOX1 = wxNewId();
const long LoopDialog::ID_TEXTCTRL1 = wxNewId();
const long LoopDialog::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(LoopDialog,wxDialog)
	//(*EventTable(LoopDialog)
	//*)
END_EVENT_TABLE()

LoopDialog::LoopDialog(wxWindow* parent,int num_lines,wxWindowID id)
{
    wxArrayString strings;
     wxString pom,pom2;

    if(num_lines>0)
    {

        wxString str;
       for(int i=1;i<num_lines+1;i++)
       {
           str.Printf(wxT("%d"),i);
           strings.Add(str);
       }


	wxConfig config(wxT("Setup"),wxT("Eli"));
	config.Read(wxT("Loop_Start_line"),&pom);
	  if(wxAtoi(pom)<1)pom=_("1");
	  if(wxAtoi(pom)>num_lines)pom.Printf(wxT("%d"),num_lines);
	  config.Read(wxT("Loop_time"),&pom2);
    }
	//(*Initialize(LoopDialog)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Start line in next loops"));
	StartLine = new wxComboBox(this, ID_COMBOBOX1, pom,wxDefaultPosition,wxDefaultSize,strings,wxCB_DROPDOWN);
	StaticBoxSizer1->Add(StartLine, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Repeat loop time [ms]"));
	Repeattime = new wxTextCtrl(this, ID_TEXTCTRL1, pom2, wxDefaultPosition, wxSize(163,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer2->Add(Repeattime, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer2, 2, wxALL|wxEXPAND, 5);
	OK_button = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxSize(85,31), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer1->Add(OK_button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LoopDialog::OnOK_buttonClick);
	//*)

  _StartLine=0;
   loop_time=0;
}

LoopDialog::~LoopDialog()
{
	//(*Destroy(LoopDialog)
	//*)
}


void LoopDialog::OnOK_buttonClick(wxCommandEvent& event)
{
  if(Validate()&&TransferDataFromWindow())
  {
      if(IsModal())
      {
          EndModal(wxID_OK);
      }
      else
      {
          SetReturnCode(wxID_OK);
          this->Show(false);
      }
  }



}

bool LoopDialog::TransferDataFromWindow()
{

    wxString pom=Repeattime->GetValue();
    wxString pom2=StartLine->GetValue();

    _StartLine=wxAtoi(pom2);
    loop_time=wxAtoi(pom);

   wxConfig config(wxT("Setup"),wxT("Eli"));

   config.Write(wxT("Loop_Start_line"),pom2);
   config.Write(wxT("Loop_time"),pom);

    return true;
}
