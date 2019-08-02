#include "ExportParam.h"

//(*InternalHeaders(ExportParam)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/filedlg.h>
#include <wx/config.h>
#include <wx/file.h>
#include <wx/textfile.h>
#include <wx/msgdlg.h>
#include <wx/utils.h>
#include <wx/mimetype.h>

//(*IdInit(ExportParam)
const long ExportParam::ID_CHECKLISTBOX1 = wxNewId();
const long ExportParam::ID_CHECKBOX1 = wxNewId();
const long ExportParam::ID_BUTTON1 = wxNewId();
const long ExportParam::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ExportParam,wxDialog)
	//(*EventTable(ExportParam)
	//*)
END_EVENT_TABLE()

ExportParam::ExportParam(wxWindow* parent,vector<int> cont_pos,vector<vector<vector<double> > > datx,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ExportParam)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, _("Export contour parameters to file"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	CheckListBox1 = new wxCheckListBox(this, ID_CHECKLISTBOX1, wxDefaultPosition, wxSize(236,261), 0, 0, 0, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
	CheckListBox1->Append(_("Bounding rectangle"));
	CheckListBox1->Append(_("Area+Perimeter"));
	CheckListBox1->Append(_("Minimal area rectange"));
	CheckListBox1->Append(_("Minimal enclosing circle"));
	CheckListBox1->Append(_("Fit elipse"));
	CheckListBox1->Append(_("Central moments"));
	CheckListBox1->Append(_("Normalized central moments"));
	CheckListBox1->Append(_("Spatial moments"));
	CheckListBox1->Append(_("Hu moments"));
	BoxSizer1->Add(CheckListBox1, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Display file"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(false);
	BoxSizer2->Add(CheckBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Export = new wxButton(this, ID_BUTTON1, _("Export"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Export, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CancelBut = new wxButton(this, ID_BUTTON2, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(CancelBut, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ExportParam::OnExportClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ExportParam::OnCancelButClick);
	//*)
	vector <double> pom1;
	vector <vector<double> > pom2;
	datx2.clear();

	for(unsigned i=0;i<datx.size();i++)
	{
	    pom2.clear();
	    for(unsigned j=0;j<datx[i].size();j++)
        {
            pom1.clear();
            for(unsigned x=0;x<datx[i][j].size();x++)pom1.push_back(datx[i][j][x]);
           pom2.push_back(pom1);
        }
        datx2.push_back(pom2);
	}
	cont_pos2.clear();
	for(unsigned i=0;i<cont_pos.size();i++)cont_pos2.push_back(cont_pos[i]);
}

ExportParam::~ExportParam()
{
	//(*Destroy(ExportParam)
	//*)
}


void ExportParam::OnExportClick(wxCommandEvent& event)
{
   wxString caption=wxT("Save Exported datas");
   wxString wildcard=wxT("All files (*.*)|*.*");

     wxString pok;
     wxString defaultDir;
    wxConfig config(wxT("Prog"),wxT("ELI"));
    config.Read(wxT("EXPORT_DATA"),&pok);
    if(pok.Len()==0) defaultDir=wxT("/home");
    else defaultDir=pok;

    wxString defaultFilename=wxEmptyString;


    wxFileDialog dialog(this,caption,defaultDir,defaultFilename,wildcard,wxFD_SAVE);
    if(dialog.ShowModal()==wxID_OK)
    {
      wxString path=dialog.GetPath();
     wxString sv=path.BeforeLast('/');
      config.Write(wxT("EXPORT_DATA"),sv);
   
     if((path.AfterLast('.').Length()>5)||(path.AfterLast('.').Length()<1))
       {
    wxMessageBox(_("Missing extension of exported file"),_("Export file error"),wxICON_ERROR,this);
     return;
       }
    if(WriteDataToFile(path)==0)
    {
        if(CheckBox1->GetValue())
        {
            wxMimeTypesManager manager;
         wxFileType *filetype=manager.GetFileTypeFromExtension(path.AfterLast('.'));
      wxString command=filetype->GetOpenCommand(path);
        wxExecute(command);

        }
       else wxMessageBox(_("Export file was created"),_("Export file creation"),wxICON_INFORMATION,this);
    }
    }


}

int ExportParam::WriteDataToFile(wxString path)
{
  wxFile file;
  if(!file.Open(path,wxFile::write))
  {
     file.Close();
      wxMessageBox(_("Error Create file"),_("Export param error"),wxICON_ERROR,this);
     return -1; // error save file
  }

  if(datx2.size()!=cont_pos2.size())
  {
     file.Close();
      wxMessageBox(_("Vectors are not same dimension"),_("Export param error"),wxICON_ERROR,this);
     return -1;
  }
  wxString line_info=_(" \t");

     if(CheckListBox1->IsChecked(0)) line_info+=_("Bounding rec X\tBounding rec Y\tBounding rec height\tBounding rec width\t");
     if(CheckListBox1->IsChecked(1)) line_info+=_("Perimeter\tArea\t");
     if(CheckListBox1->IsChecked(2)) line_info+=_("Min area rec X\tMin area rec Y\tMin area rec width\tMin area rec height\tMin area rec Angle\t");
     if(CheckListBox1->IsChecked(3)) line_info+=_("Min circle X\tMin Circle Y\tMin Circle radius\t");
     if(CheckListBox1->IsChecked(4)) line_info+=_("Fit ellipse center X\tFit ellipse center Y\tFit ellipse width\tFit ellipse height\tFit ellipse angle\t");
     if(CheckListBox1->IsChecked(5)) line_info+=_("Central moments(2 0)\tCentral moments(1 1)\tCentral moments(0 2)\tCentral moments(3 0)\tCentral moments(2 1)\tCentral moments(1 2)\tCentral moments(0 3)\t");
     if(CheckListBox1->IsChecked(6)) line_info+=_("Norm Central moments(2 0)\tNorm Central moments(1 1)\tNorm Central moments(0 2)\tNorm Central moments(3 0)\tNorm Central moments(2 1)\tNorm Central moments(1 2)\tNorm Central moments(0 3)\t");
     if(CheckListBox1->IsChecked(7)) line_info+=_("Spatial moments(0 0)\tSpatial moments(1 0)\tSpatial moments(0 1)\tSpatial moments(1 1)\tSpatial moments(2 0)\tSpatial moments(0 2)\tSpatial moments(3 0)\tSpatial moments(2 1)\tSpatial moments(1 2)\tSpatial moments(0 3)\t");
     if(CheckListBox1->IsChecked(8)) line_info+=_("Hu moments 0\tHu moments 1\tHu moments 2\tHu moments 3\tHu moments 4\tHu moments 5\tHu moments 6\t");
  file.Write(line_info);
  file.Write(wxTextFile::GetEOL());//add line end
  for(unsigned i=0;i<cont_pos2.size();i++)
  {
      line_info=_("Contour ");
      line_info << (unsigned int)cont_pos2[i];
      for(unsigned j=0;j<datx2[i].size();j++)
      {
        if(CheckListBox1->IsChecked(j))
        {
            for(unsigned x=0;x<datx2[i][j].size();x++)
            {
                line_info+=_("\t");
                line_info<<datx2[i][j][x];
            }
        }
      }
      file.Write(line_info);
   file.Write(wxTextFile::GetEOL());//add line end
  }

file.Close();

return 0;

}
void ExportParam::OnCancelButClick(wxCommandEvent& event)
{
    EndModal(0);
}
