#include "VariableWindow.h"

//(*InternalHeaders(VariableWindow)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(VariableWindow)
const long VariableWindow::ID_CHOICE1 = wxNewId();
const long VariableWindow::ID_CHOICE2 = wxNewId();
const long VariableWindow::ID_CHOICE3 = wxNewId();
const long VariableWindow::ID_CHOICE4 = wxNewId();
const long VariableWindow::ID_RADIOBOX1 = wxNewId();
const long VariableWindow::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(VariableWindow,wxDialog)
	//(*EventTable(VariableWindow)
	//*)
END_EVENT_TABLE()

VariableWindow::VariableWindow(wxWindow* parent,wxArrayString objx,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(VariableWindow)
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, _("Variable window"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("System variable"));
	SystVar = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(286,36), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	StaticBoxSizer1->Add(SystVar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Strings"));
	SystStrings = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	StaticBoxSizer2->Add(SystStrings, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Objects"));
	Objects = new wxChoice(this, ID_CHOICE3, wxDefaultPosition, wxSize(273,36), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	StaticBoxSizer3->Add(Objects, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(StaticBoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Object parameteres"));
	ObjectParam = new wxChoice(this, ID_CHOICE4, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
	ObjectParam->Disable();
	StaticBoxSizer4->Add(ObjectParam, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(StaticBoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	wxString __wxRadioBoxChoices_1[2] =
	{
		_("Number of objects"),
		_("Object parameters")
	};
	RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, _("Object DIsplay"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
	BoxSizer4->Add(RadioBox1, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer4->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&VariableWindow::OnRadioBox1Select);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VariableWindow::OnButton1Click);
	//*)
	wxString pom;
  for(unsigned i=0;i<100;i++)
  {
      pom.Printf(_("Variable %d"),i);
      SystVar->Append(pom);
  }

   for(unsigned i=0;i<10;i++)
  {
      pom.Printf(_("String %d"),i);
      SystStrings->Append(pom);
  }

  for(unsigned i=0;i<objx.GetCount();i++)Objects->Append(objx[i]);

  if(objx.GetCount()>0)
  {
      ObjectParam->Enable(true);
      ObjectParam->Append(_("Bounding rect X"));
      ObjectParam->Append(_("Bounding rect Y"));
      ObjectParam->Append(_("Bounding rect Height"));
      ObjectParam->Append(_("Bounding rect Width"));
      ObjectParam->Append(_("Perimeter"));
      ObjectParam->Append(_("Contour area"));
       ObjectParam->Append(_("Minimal area rect X"));
       ObjectParam->Append(_("Minimal area rect Y"));
       ObjectParam->Append(_("Minimal area rect Height"));
       ObjectParam->Append(_("Minimal area rect Width"));
       ObjectParam->Append(_("Minimal area rect angle"));
       ObjectParam->Append(_("Minimal enclosing circle X"));
       ObjectParam->Append(_("Minimal enclosing circle Y"));
       ObjectParam->Append(_("Minimal enclosing circle radius"));
       ObjectParam->Append(_("Fit ellipse center X"));
       ObjectParam->Append(_("Fit ellipse center Y"));
       ObjectParam->Append(_("Fit ellipse height"));
       ObjectParam->Append(_("Fit ellipse width"));
     ObjectParam->Append(_("Fit ellipse angle"));
      ObjectParam->Append(_("Derived 0"));
       ObjectParam->Append(_("Derived 1"));
      ObjectParam->Append(_("Derived 2"));
       ObjectParam->Append(_("Derived 3"));
        ObjectParam->Append(_("Derived 4"));
         ObjectParam->Append(_("Derived 5"));
          ObjectParam->Append(_("Derived 6"));
           ObjectParam->Append(_("Derived 7"));
            ObjectParam->Append(_("Derived 8"));
             ObjectParam->Append(_("Derived 9"));
             RadioBox1->SetSelection(1);
  }

}

VariableWindow::~VariableWindow()
{
	//(*Destroy(VariableWindow)
	//*)
}


void VariableWindow::OnButton1Click(wxCommandEvent& event)
{
  pos_glob[0]=SystVar->GetSelection();
  pos_glob[1]=SystStrings->GetSelection();
  pos_glob[2]=Objects->GetSelection();
  pos_glob[3]=RadioBox1->GetSelection();
  pos_glob[4]=ObjectParam->GetSelection();
    EndModal(0);
}

void VariableWindow::OnRadioBox1Select(wxCommandEvent& event)
{
    int sel=RadioBox1->GetSelection();
    if(sel==0)ObjectParam->Enable(false);
    else ObjectParam->Enable(true);
}
