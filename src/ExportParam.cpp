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
#include <wx/textfile.h>

//(*IdInit(ExportParam)
const long ExportParam::ID_CHECKLISTBOX1 = wxNewId();
const long ExportParam::ID_CHECKBOX1 = wxNewId();
const long ExportParam::ID_BUTTON1 = wxNewId();
const long ExportParam::ID_BUTTON2 = wxNewId();
const long ExportParam::ID_BUTTON3 = wxNewId();
//*)

//(*IdInit(AlasesExp)
const long AlasesExp::ID_BUTTON1 = wxNewId();
const long AlasesExp::ID_BUTTON2 = wxNewId();
const long AlasesExp::ID_CHOICE1 = wxNewId();
const long AlasesExp::ID_CHOICE2 = wxNewId();
const long AlasesExp::ID_TEXTCTRL1 = wxNewId();
const long AlasesExp::ID_BUTTON3 = wxNewId();
const long AlasesExp::ID_TEXTCTRL2 = wxNewId();
const long AlasesExp::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(AlasesExp,wxDialog)
	//(*EventTable(AlasesExp)
	//*)
END_EVENT_TABLE()

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
	alias=new wxButton(this, ID_BUTTON3, _("Alias"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer2->Add(alias, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CancelBut = new wxButton(this, ID_BUTTON2, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(CancelBut, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ExportParam::OnExportClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ExportParam::OnCancelButClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ExportParam::OnAliasButtonClick);
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

void ExportParam::OnAliasButtonClick(wxCommandEvent& event)
{
  vector<wxString> contours_text;
  contours_text.clear();
  wxString cont_info;

    for(unsigned i=0;i<cont_pos2.size();i++)
  {
      cont_info=_("Contour ");
      cont_info << (unsigned int)cont_pos2[i];
      contours_text.push_back(cont_info);
  }

AlasesExp dlg(this,contours_text);
 dlg.ShowModal();
}

AlasesExp::AlasesExp(wxWindow* parent,vector<wxString> contours_inf,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(AlasesExp)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;




	Create(parent, id, _("Contour alias selection"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	SelAliasFile = new wxButton(this, ID_BUTTON1, _("Select alias file"), wxDefaultPosition, wxSize(125,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(SelAliasFile, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ClearAlias = new wxButton(this, ID_BUTTON2, _("Clear Alias file"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(ClearAlias, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Contour"));
	Contour = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	StaticBoxSizer1->Add(Contour, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Alias"));
	Alais = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	StaticBoxSizer2->Add(Alais, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("New Alias"));
	NewAlias = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(149,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer3->Add(NewAlias, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	AddAlias = new wxButton(this, ID_BUTTON3, _("Add"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer4->Add(AddAlias, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer5->Add(TextCtrl1, 3, wxALL|wxEXPAND, 5);
	Exitbutton = new wxButton(this, ID_BUTTON4, _("Exit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer5->Add(Exitbutton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer5, 2, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AlasesExp::OnSelAliasFileClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AlasesExp::OnClearAliasClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AlasesExp::OnAddAliasClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AlasesExp::OnExitbuttonClick);
	//*)
		wxString pok;
	 wxConfig config(wxT("Prog"),wxT("ELI"));
    config.Read(wxT("EXPORT_DATA_ALIAS"),&pok);
    aliases.clear();
    Alais->Append(wxT("New Alias"));

    for(unsigned i=0;i<contours_inf.size();i++)Contour->Append(contours_inf[i]);

    wxTextFile filex(pok);
    if(!filex.Exists())
    {
      wxMessageBox(wxT("Select  alias file at first"),wxT("Error open alias file"),wxICON_ERROR);
    }
    else
    {
        if(!filex.Open(pok))wxMessageBox(wxT("Can not open alias file"),wxT("Error open alias file"),wxICON_ERROR);
       else
       {
        wxString str;
       for ( wxString str = filex.GetFirstLine(); !filex.Eof(); str = filex.GetNextLine() )   if(str.Length()>0) Alais->Append(str); // add all lines
         if(str.Length()>0) Alais->Append(str); //add last line

      }
    }


}

AlasesExp::~AlasesExp()
{
	//(*Destroy(AlasesExp)
	//*)
}


void AlasesExp::OnSelAliasFileClick(wxCommandEvent& event)
{
      wxString caption=wxT("Select alias file");
   wxString wildcard=wxT("TXT files (*.txt)|*.txt");

     wxString pok;
     wxString defaultDir;
    wxConfig config(wxT("Prog"),wxT("ELI"));
    config.Read(wxT("EXPORT_DATA_ALIAS"),&pok);
    if(pok.Len()==0) defaultDir=wxT("/home");
    else defaultDir=pok.BeforeLast('/');

    wxString defaultFilename=pok.AfterLast('/');


    wxFileDialog dialog(this,caption,defaultDir,defaultFilename,wildcard,wxFD_SAVE);
    if(dialog.ShowModal()==wxID_OK)
    {
      wxString path=dialog.GetPath();
      config.Write(wxT("EXPORT_DATA_ALIAS"),path);
     wxTextFile filex(path);
    if(!filex.Exists())
    {
     if(!filex.Create()) wxMessageBox(wxT("Can not create alias file (Check permission of selected folder)"),wxT("Error create alias file"),wxICON_ERROR);
     else filex.Close();
    }

    }
}

void AlasesExp::OnClearAliasClick(wxCommandEvent& event)
{
 		wxString pok;
	 wxConfig config(wxT("Prog"),wxT("ELI"));
    config.Read(wxT("EXPORT_DATA_ALIAS"),&pok);


     wxTextFile filex(pok);
    if(!filex.Exists())
    {
      wxMessageBox(wxT("Alias file not existt"),wxT("Error open alias file"),wxICON_ERROR);
    }

    if(!filex.Open(pok))
    {
        wxMessageBox(wxT("Can not open alias file"),wxT("Error open alias file"),wxICON_ERROR);
        return;
    }
    filex.Clear();
    filex.Write();
    filex.Close();
   Alais->Clear();
}

void AlasesExp::OnAddAliasClick(wxCommandEvent& event)
{
vector<wxString> datasx;
wxString  contourx=Contour->GetStringSelection();
wxString sel_alias=Alais->GetStringSelection();
if(sel_alias==wxT("New Alias"))sel_alias=NewAlias->GetValue();

datasx.clear();
datasx.push_back(contourx);
datasx.push_back(sel_alias);

bool foundx=false;
for(unsigned i=0;i<aliases.size();i++)
{
    if(aliases[i].size()!=2)
    {
        wxMessageBox(_("Error aliases vector dimension"),_("Alias vector dimension error"),wxICON_ERROR);
        return;
    }
 if(!foundx)
 {
     if(aliases[i][0]==contourx)
     {
         foundx=true;
         aliases[i][0]=sel_alias;
     }
 }
}

if(!foundx)
{
    aliases.push_back(datasx); //Add datas to structure
    TextCtrl1->WriteText(contourx);
    TextCtrl1->WriteText(wxT(" :"));
    TextCtrl1->WriteText(sel_alias);
    TextCtrl1->WriteText(wxT("\n"));
}

	wxString pok;
	 wxConfig config(wxT("Prog"),wxT("ELI"));
    config.Read(wxT("EXPORT_DATA_ALIAS"),&pok);

if(Alais->GetStringSelection()==wxT("New Alias")) //Write to file new alias
{
     wxTextFile filex(pok);
    if(!filex.Exists())
    {
      wxMessageBox(wxT("Alias file not existt"),wxT("Error open alias file"),wxICON_ERROR);
    }

    if(!filex.Open(pok))
    {
        wxMessageBox(wxT("Can not open alias file"),wxT("Error open alias file"),wxICON_ERROR);
        return;
    }
  wxString str;
  bool found_in_file=false;
  //Check for duplicate name in the file
       for ( wxString str = filex.GetFirstLine(); !filex.Eof(); str = filex.GetNextLine() )
       {
           if(!found_in_file)
           {
              if(str.Length()>0) if(str==sel_alias)found_in_file=true; // found alias name in the file

           }
       }
         if(str.Length()>0) if(str==sel_alias)found_in_file=true; //found an the file

     if(!found_in_file) //not found alias add it
     {
        filex.AddLine(sel_alias);
        Alais->Append(sel_alias);
     }
    filex.Write();
    filex.Close();
}

}

void AlasesExp::OnExitbuttonClick(wxCommandEvent& event)
{
    EndModal(0);
}
