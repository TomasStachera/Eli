#include "CameraProperties.h"

//(*InternalHeaders(CameraProperties)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/dirdlg.h>
#include <wx/config.h>
#include <wx/msgdlg.h>

//(*IdInit(CameraProperties)
const long CameraProperties::ID_TEXTCTRL1 = wxNewId();
const long CameraProperties::ID_BUTTON1 = wxNewId();
const long CameraProperties::ID_TEXTCTRL2 = wxNewId();
const long CameraProperties::ID_TEXTCTRL3 = wxNewId();
const long CameraProperties::ID_TEXTCTRL4 = wxNewId();
const long CameraProperties::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CameraProperties,wxDialog)
	//(*EventTable(CameraProperties)
	//*)
END_EVENT_TABLE()

CameraProperties::CameraProperties(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(CameraProperties)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer5;

	Create(parent, id, _("Camera Properties"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Camera snapshots folder"));
	CameraSnapshotFold = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(413,37), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer1->Add(CameraSnapshotFold, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ChangeSnapshotFold = new wxButton(this, ID_BUTTON1, _("Change"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	StaticBoxSizer1->Add(ChangeSnapshotFold, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 2, wxALL|wxEXPAND, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Camera snapshot option"));
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("File_name"));
	SnapshotName = new wxTextCtrl(this, ID_TEXTCTRL2, _("snapshot.jpg"), wxDefaultPosition, wxSize(255,37), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticBoxSizer3->Add(SnapshotName, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(StaticBoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Start Index"));
	StartIndex = new wxTextCtrl(this, ID_TEXTCTRL3, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	StaticBoxSizer4->Add(StartIndex, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(StaticBoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer2, 3, wxALL|wxEXPAND, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("View camera loop time [ms]"));
	ViewCameraLoop = new wxTextCtrl(this, ID_TEXTCTRL4, _("50"), wxDefaultPosition, wxSize(196,37), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	StaticBoxSizer5->Add(ViewCameraLoop, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	UpdateAll = new wxButton(this, ID_BUTTON2, _("Update All"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(UpdateAll, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CameraProperties::OnChangeSnapshotFoldClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CameraProperties::OnUpdateAllClick);
	//*)

	 wxConfig config(wxT("cam_properties"),wxT("ELI"));
	 wxString pom;
	 config.Read(wxT("def_snap_dir"),&pom);
	 CameraSnapshotFold->WriteText(pom);
	 pom=wxEmptyString;
	 config.Read(wxT("snap_file"),&pom);
	 if(pom.Length()>0)
     {
      SnapshotName->Clear();
	 SnapshotName->WriteText(pom);
     }

	 pom=wxEmptyString;
	 config.Read(wxT("StartIndex"),&pom);
	  if(pom.Length()>0)
     {
     StartIndex->Clear();
	 StartIndex->WriteText(pom);
     }
	 pom=wxEmptyString;
	 config.Read(wxT("VievCamLoopTime"),&pom);
	   if(pom.Length()>0)
     {
         ViewCameraLoop->Clear();
	 ViewCameraLoop->WriteText(pom);
     }

}

CameraProperties::~CameraProperties()
{
	//(*Destroy(CameraProperties)
	//*)
}


void CameraProperties::OnChangeSnapshotFoldClick(wxCommandEvent& event)
{
wxString path;

 wxConfig config(wxT("cam_properties"),wxT("ELI"));
    config.Read(wxT("def_snap_dir"),&path);

    wxDirDialog dlg(NULL, _("Choose directory for Snapshot files"), path,wxDD_DEFAULT_STYLE|wxDD_NEW_DIR_BUTTON);
          if(dlg.ShowModal()==wxID_OK)
          {
            path=dlg.GetPath();
            config.Write(wxT("def_snap_dir"),path);
            CameraSnapshotFold->Clear();
            CameraSnapshotFold->WriteText(path);
          }

}

void CameraProperties::OnUpdateAllClick(wxCommandEvent& event)
{
   wxConfig config(wxT("cam_properties"),wxT("ELI"));

  if(wxMessageBox(_("Do you want to save camera properties?"),_("Save Camera properties"),wxYES_NO|wxICON_QUESTION)==wxYES)
  {
   config.Write(wxT("snap_file"),SnapshotName->GetValue());
   config.Write(wxT("StartIndex"),StartIndex->GetValue());
   config.Write(wxT("VievCamLoopTime"),ViewCameraLoop->GetValue());
  }

}
