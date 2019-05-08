#include "ContourDescript2.h"

//(*InternalHeaders(ContourDescript2)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/msgdlg.h>
//(*IdInit(ContourDescript2)
const long ContourDescript2::ID_BUTTON1 = wxNewId();
const long ContourDescript2::ID_BUTTON2 = wxNewId();
/*const long ContourDescript2::ID_CHECKBOX1 = wxNewId();
const long ContourDescript2::ID_CHECKBOX2 = wxNewId();
const long ContourDescript2::ID_CHECKBOX3 = wxNewId();
const long ContourDescript2::ID_CHECKBOX4 = wxNewId();
const long ContourDescript2::ID_CHECKBOX5 = wxNewId();*/
const long ContourDescript2::ID_BUTTON4 = wxNewId();
const long ContourDescript2::ID_GRID1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ContourDescript2,wxDialog)
	//(*EventTable(ContourDescript2)
	//*)
END_EVENT_TABLE()

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

ContourDescript2::ContourDescript2(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size,float *syst_variable,ContourCalculation *cont_calc)
{
	//(*Initialize(ContourDescript2)
	wxBoxSizer* BoxSizer4;

	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, wxID_ANY, _("Filter module"), wxDefaultPosition, wxDefaultSize,wxDEFAULT_DIALOG_STYLE, _T("Filter module"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	InsertLine = new wxButton(this, ID_BUTTON1, _("Insert line"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(InsertLine, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	DeleteLine = new wxButton(this, ID_BUTTON2, _("Delete line"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(DeleteLine, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("FIlter module"));
	BoxSizer2->Add(StaticBoxSizer1, 3, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	UpdateModule = new wxButton(this, ID_BUTTON4, _("Update module"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer4->Add(UpdateModule, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxSize(935,262), 0, _T("ID_GRID1"));
	Grid1->CreateGrid(0,6);
	Grid1->EnableEditing(true);
	Grid1->EnableGridLines(true);
	Grid1->SetDefaultColSize(140, true);
	Grid1->SetColLabelValue(0, _("Result"));
	Grid1->SetColLabelValue(1, _("Input from"));
	Grid1->SetColLabelValue(2, _("Contour parameter"));
	Grid1->SetColLabelValue(3, _("Comparison \n option"));
	Grid1->SetColLabelValue(4, _("Compare with"));
	Grid1->SetColLabelValue(5, _("Compare number"));
	Grid1->SetDefaultCellFont( Grid1->GetFont() );
	Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
	BoxSizer1->Add(Grid1, 3, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ContourDescript2::OnButtonInsertLine);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ContourDescript2::OnDeleteLineClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ContourDescript2::OnUpdateModuleClick);
	Connect(ID_GRID1,wxEVT_GRID_CELL_CHANGE,(wxObjectEventFunction)&ContourDescript2::OnGrid1CellChange);
	//*)
	Grid1->SetLabelSize(0,40);
	Grid1->SetColSize(0,110);
	Grid1->SetColSize(1,100);
	Grid1->SetColSize(2,280);
     Grid1->SetColSize(3,110);
	Grid1->SetColSize(4,130);

     cont_calcx=cont_calc;

	//Grid1->SetSelectionBackground(wxColour(0,0,255));
	Grid1->SetSelectionMode(wxGrid::wxGridSelectRows);
    for(int i=0;i<100;i++)syst_var[i]=syst_variable[i];
    for(int i=0;i<cont_calcx->ReturnActualFilterLine();i++)InserGridLine();

    int result,input_from,contour_parameter,comparison_option,variable_from;
    double comparison_number;
    for(int i=0;i<cont_calcx->ReturnActualFilterLine();i++)
    {
    if(cont_calcx->GetFilterLineParam(i,result,input_from,contour_parameter,comparison_option,comparison_number,variable_from)==0)
    {
        if(result==1) Grid1->SetCellValue(i,0,_("Active"));
        else Grid1->SetCellValue(i,0,_("Not active"));

        if(input_from==1) Grid1->SetCellValue(i,1,_("All"));
        else Grid1->SetCellValue(i,1,_("Active"));

        if((contour_parameter>=1)&&(contour_parameter<=56))Grid1->SetCellValue(i,2,cont_calcx->ContourNumberToString(contour_parameter));
        else if(contour_parameter==0) Grid1->SetCellValue(i,2,_("Edge line"));

        if(comparison_option==1)Grid1->SetCellValue(i,3,_("="));
        if(comparison_option==2)Grid1->SetCellValue(i,3,_(">"));
        if(comparison_option==3)Grid1->SetCellValue(i,3,_("<"));
        if(comparison_option==4)Grid1->SetCellValue(i,3,_("=>"));
        if(comparison_option==5)Grid1->SetCellValue(i,3,_("=<"));
        if(comparison_option==6)Grid1->SetCellValue(i,3,_("!="));

        wxString px=_("");
        px<<comparison_number;
        Grid1->SetCellValue(i,5,px);

        if(variable_from==-1) Grid1->SetCellValue(i,4,_("Number"));
        else
        {
            px.Printf(_("Variable_%d"),variable_from);
            Grid1->SetCellValue(i,4,px);
        }
    }
    }
}

ContourDescript2::~ContourDescript2()
{
	//(*Destroy(ContourDescript2)
	//*)
}

/*
Function InserGridLine inserts  one line to the filter program window
*/
void ContourDescript2::InserGridLine(void)
{
     wxArrayString val;
    //Fill result column
    int pos=Grid1->GetCursorRow();
    Grid1->InsertRows(pos+1,1);
    for(int i=0;i<5;i++)
    {
      val.Clear();
      switch (i)
      {
          case 0:
             val.Add(_("Active"));
             val.Add(_("Not active"));
            break;
          case 1:
             val.Add(_("All"));
             val.Add(_("Active"));
             break;
          case 2:
               val.Add(_("Edge line"));
              for(int i=1;i<53;i++)val.Add(cont_calcx->ContourNumberToString(i));
            break;
          case 3:
                 val.Add(_("="));
                 val.Add(_(">"));
                 val.Add(_("<"));
                 val.Add(_("=>"));
                 val.Add(_("=<"));
                 val.Add(_("!="));
             break;
          case 4:
                 val.Add(_("Number"));
                 wxString px;
                 for(int j=0;j<100;j++)
                 {
                    px=_("");
                    px.Printf(_("Variable_%d"),j);
                    val.Add(px);
                 }
             break;
      }

int num=val.GetCount();
wxString *s_val=new wxString[num];
for(int x=0;x<num;x++) s_val[x]=val.Item(x);
Grid1->SetCellEditor(pos+1, i, new wxGridCellChoiceEditor(num,s_val));
if(num>0)Grid1->SetCellValue(pos+1,i,s_val[0]);

    }

///////////////////////////////////
}

/*
Function is call when user clicks on button InsertLine
*/
void ContourDescript2::OnButtonInsertLine(wxCommandEvent& event)
{
InserGridLine();

}

/*
Function is call when user clicks on button Delete line
*/
void ContourDescript2::OnDeleteLineClick(wxCommandEvent& event)
{
    Grid1->DeleteRows(Grid1->GetGridCursorRow(),1);

}



/****************************************************************************
Function is executed when is some change in the cells.
If some changes is collumns Compare width, function update  Compare number
column with variable number if option Variable_0 .. Variable_99 was selected
*****************************************************************************/
void ContourDescript2::OnGrid1CellChange(wxGridEvent& event)
{
    int y=Grid1->GetCursorRow();
    int x=Grid1->GetCursorColumn();


if(x==4)
{
  if(Grid1->GetCellValue(y,x)!=_("Number"))
  {
      int ar_pos=wxAtoi(Grid1->GetCellValue(y,x).AfterFirst('_'));
      if((ar_pos>=0)&&(ar_pos<=99))
      {
          wxString px=_("");
          px<<syst_var[ar_pos];
          Grid1->SetCellValue(y,x+1,px);
          Grid1->SetReadOnly(y,x+1,true);
      }
  }
  else  Grid1->SetReadOnly(y,x+1,false);
}

}


/*
Function is called when user click on update module button
Filter program is stored to the ContourCalculation class
*/

void ContourDescript2::OnUpdateModuleClick(wxCommandEvent& event)
{
    if(wxMessageBox(_("Do you want update filter modul?"),_("Question"),wxICON_QUESTION | wxYES_NO ,this) !=wxYES) return;

    int result=0;
    int input_from=0;
    int contour_parameter=1;

    cont_calcx->ResetActualFilterLIne(); //set filter line to 0

    for(int i=0;i<Grid1->GetNumberRows();i++)
    {
        Grid1->SetGridCursor(0,0);
        if(Grid1->GetCellValue(i,0)==_("Active")) result=1;
        else result=0;

        if(Grid1->GetCellValue(i,1)==_("All")) input_from=1;
        else input_from=0;
        if(Grid1->GetCellValue(i,2)==_("Edge line"))contour_parameter=0;
        else contour_parameter=cont_calcx->ContourStringToNumber(Grid1->GetCellValue(i,2));



        int comparison_option=1;
        double fxxval;


        if(Grid1->GetCellValue(i,3)==_("=")) comparison_option=1;
        else if (Grid1->GetCellValue(i,3)==_(">")) comparison_option=2;
        else if (Grid1->GetCellValue(i,3)==_("<")) comparison_option=3;
        else if (Grid1->GetCellValue(i,3)==_("=>")) comparison_option=4;
        else if (Grid1->GetCellValue(i,3)==_("=<")) comparison_option=5;
        else comparison_option=6;
        int var_from=-1;
        if(Grid1->GetCellValue(i,4)!=_("Number")) var_from=wxAtoi(Grid1->GetCellValue(i,4).AfterFirst('_'));
        Grid1->GetCellValue(i,5).ToCDouble(&fxxval);
        cont_calcx->InserFilterLine(result,input_from,contour_parameter,comparison_option,(float)fxxval,var_from);



    }

    wxMessageBox(_("Filter modulle was updated"),_("Information"),wxICON_INFORMATION,this);
}
