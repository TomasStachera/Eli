//(*InternalHeaders(object)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/msgdlg.h>
#include <wx/choicdlg.h>
#include <wx/textdlg.h>
#include <wx/colordlg.h>
#include <wx/config.h>
#include <wx/colour.h>
#include <wx/numdlg.h>
#include "ContourDescript4.h"


//(*IdInit(object)
const long object::ID_BUTTON1 = wxNewId();
const long object::ID_BUTTON2 = wxNewId();
const long object::ID_BUTTON3 = wxNewId();
const long object::ID_BUTTON4 = wxNewId();
const long object::ID_BUTTON5 = wxNewId();
const long object::ID_BUTTON6 = wxNewId();
const long object::ID_BUTTON7 = wxNewId();
const long object::ID_BUTTON8 = wxNewId();
const long object::ID_GRID1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(object,wxDialog)
	//(*EventTable(object)
	//*)
END_EVENT_TABLE()


//(*IdInit(ObjectDes)
const long ObjectDes::ID_TEXTCTRL1 = wxNewId();
const long ObjectDes::ID_TEXTCTRL2 = wxNewId();
const long ObjectDes::ID_BUTTON1 = wxNewId();
const long ObjectDes::ID_BUTTON2 = wxNewId();
const long ObjectDes::ID_BUTTON3 = wxNewId();
const long ObjectDes::ID_BUTTON4 = wxNewId();
const long ObjectDes::ID_BUTTON5 = wxNewId();
const long ObjectDes::ID_GRID1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ObjectDes,wxDialog)
	//(*EventTable(ObjectDes)
	//*)
END_EVENT_TABLE()

//(*IdInit(MathSubModule)
const long MathSubModule::ID_CHOICE1 = wxNewId();
const long MathSubModule::ID_CHOICE2 = wxNewId();
const long MathSubModule::ID_TEXTCTRL2 = wxNewId();
const long MathSubModule::ID_CHOICE3 = wxNewId();
const long MathSubModule::ID_CHOICE4 = wxNewId();
const long MathSubModule::ID_CHOICE5 = wxNewId();
const long MathSubModule::ID_TEXTCTRL3 = wxNewId();
const long MathSubModule::ID_CHOICE6 = wxNewId();
const long MathSubModule::ID_CHOICE7 = wxNewId();
const long MathSubModule::ID_TEXTCTRL1 = wxNewId();
const long MathSubModule::ID_BUTTON7 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MathSubModule,wxDialog)
	//(*EventTable(MathSubModule)
	//*)
END_EVENT_TABLE()

//(*IdInit(ConditionSubModule)
const long ConditionSubModule::ID_CHOICE1 = wxNewId();
const long ConditionSubModule::ID_CHOICE2 = wxNewId();
const long ConditionSubModule::ID_TEXTCTRL1 = wxNewId();
const long ConditionSubModule::ID_CHOICE3 = wxNewId();
const long ConditionSubModule::ID_CHOICE4 = wxNewId();
const long ConditionSubModule::ID_CHOICE5 = wxNewId();
const long ConditionSubModule::ID_TEXTCTRL2 = wxNewId();
const long ConditionSubModule::ID_BUTTON7 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ConditionSubModule,wxDialog)
	//(*EventTable(ConditionSubModule)
	//*)
END_EVENT_TABLE()

//(*IdInit(ContourDebug)
const long ContourDebug::ID_CHOICE1 = wxNewId();
const long ContourDebug::ID_BUTTON1 = wxNewId();
const long ContourDebug::ID_BUTTON2 = wxNewId();
const long ContourDebug::ID_BUTTON3 = wxNewId();
const long ContourDebug::ID_BUTTON4 = wxNewId();
const long ContourDebug::ID_STATICTEXT1 = wxNewId();
const long ContourDebug::ID_STATICTEXT2 = wxNewId();
const long ContourDebug::ID_RADIOBOX1 = wxNewId();
const long ContourDebug::ID_LISTBOX1 = wxNewId();
const long ContourDebug::ID_TEXTCTRL2 = wxNewId();
const long ContourDebug::ID_STATICTEXT3 = wxNewId();
const long ContourDebug::ID_GRID1 = wxNewId();
const long ContourDebug::ID_TEXTCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ContourDebug,wxDialog)
	//(*EventTable(ContourDebug)
	//*)
END_EVENT_TABLE()

//(*IdInit(ObjectList)
const long ObjectList::ID_LISTBOX1 = wxNewId();
const long ObjectList::ID_STATICTEXT1 = wxNewId();
const long ObjectList::ID_STATICTEXT2 = wxNewId();
const long ObjectList::ID_STATICTEXT3 = wxNewId();
const long ObjectList::ID_STATICTEXT4 = wxNewId();
const long ObjectList::ID_STATICTEXT5 = wxNewId();
const long ObjectList::ID_STATICTEXT6 = wxNewId();
const long ObjectList::ID_BUTTON1 = wxNewId();
const long ObjectList::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ObjectList,wxDialog)
	//(*EventTable(ObjectList)
	//*)
END_EVENT_TABLE()

//(*IdInit(ObjectSetup)
const long ObjectSetup::ID_TEXTCTRL2 = wxNewId();
const long ObjectSetup::ID_TEXTCTRL3 = wxNewId();
const long ObjectSetup::ID_TEXTCTRL4 = wxNewId();
const long ObjectSetup::ID_BUTTON1 = wxNewId();
const long ObjectSetup::ID_TEXTCTRL1 = wxNewId();
const long ObjectSetup::ID_BUTTON2 = wxNewId();
const long ObjectSetup::ID_BUTTON3 = wxNewId();
const long ObjectSetup::ID_TEXTCTRL5 = wxNewId();
const long ObjectSetup::ID_TEXTCTRL6 = wxNewId();
const long ObjectSetup::ID_TEXTCTRL7 = wxNewId();
const long ObjectSetup::ID_BUTTON4 = wxNewId();
const long ObjectSetup::ID_CHOICE1 = wxNewId();
const long ObjectSetup::ID_RADIOBOX1 = wxNewId();
const long ObjectSetup::ID_RADIOBOX2 = wxNewId();
const long ObjectSetup::ID_TEXTCTRL8 = wxNewId();
const long ObjectSetup::ID_CHOICE2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ObjectSetup,wxDialog)
	//(*EventTable(ObjectSetup)
	//*)
END_EVENT_TABLE()

/*********************************************************
Class object  display object module window
Input parameters: parent: parent window
                  cont_calc : ContourCalculation class
                  syst_var: system variable array
                  id: window id
                  pos: window position
                  size: window size
**************************************************************/
object::object(wxWindow* parent,ContourCalculation *cont_calc,float *syst_var,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(object)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, _("Object module"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	New_object = new wxButton(this, ID_BUTTON1, _("New object"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(New_object, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Edit_object = new wxButton(this, ID_BUTTON2, _("Edit object"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Edit_object->Disable();
	BoxSizer2->Add(Edit_object, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ExportObject=new wxButton(this, ID_BUTTON7, _("Export object"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
	ExportObject->Disable();
	BoxSizer2->Add(ExportObject, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ImportObject=new wxButton(this, ID_BUTTON8, _("Import object"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
	BoxSizer2->Add(ImportObject, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	//
	Debug_object = new wxButton(this, ID_BUTTON6, _("Debug object"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Debug_object->Disable();
	BoxSizer2->Add(Debug_object, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	//
	Copy_objects = new wxButton(this, ID_BUTTON3, _("Copy objects"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Copy_objects->Disable();
	BoxSizer2->Add(Copy_objects, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Delete_objects = new wxButton(this, ID_BUTTON4, _("Delete objects"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Delete_objects->Disable();
	BoxSizer2->Add(Delete_objects, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Update_modul = new wxButton(this, ID_BUTTON5, _("Update module"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	BoxSizer2->Add(Update_modul, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxSize(632,242), 0, _T("ID_GRID1"));
	Grid1->CreateGrid(0,2);
	Grid1->EnableEditing(true);
	Grid1->EnableGridLines(true);
	Grid1->SetColLabelValue(0, _("Object name"));
	Grid1->SetColLabelValue(1, _("Comments"));
	Grid1->SetDefaultCellFont( Grid1->GetFont() );
	Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
	BoxSizer1->Add(Grid1, 4, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&object::OnNew_objectClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&object::OnEdit_objectClick);
	//*)
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&object::OnCopy_objectClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&object::OnDelete_objectClick);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&object::OnUpdate_objectClick);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&object::OnDebug_objectClick);
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&object::OnExport_objectClick);
	Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&object::OnImport_objectClick);

    Grid1->SetColSize(0,350);
    Grid1->SetColSize(1,510);
    Grid1->SetLabelSize(0,60);
   	Grid1->SetSelectionMode(wxGrid::wxGridSelectRows);
   	cont_calcx=cont_calc;

   	wxString obj_name,obj_descript;

   	for(int i=0;i<100;i++)system_var[i]=syst_var[i];

   	for(int i=0;i < cont_calcx->GetNumberOfObject();i++)
   	{
   	    if(cont_calcx->GetObjectNameAndDescription(i,obj_name,obj_descript)==0)
   	    {
   	        if(obj_name != _(""))
   	        {
   	            Grid1->InsertRows(i,1);
   	            Grid1->SetCellValue(i,0,obj_name);
   	            Grid1->SetCellValue(i,1,obj_descript);
   	        }
   	    }
   	}

    if(cont_calcx->GetNumberOfObject()>0)
    {
       Edit_object->Enable(true);
        Delete_objects->Enable(true);
        Copy_objects->Enable(true);
        Debug_object->Enable(true);
        ExportObject->Enable(true);
    }
}

object::~object()
{
	//(*Destroy(object)
	//*)
}

/*
Function is called when user click on button Debug
Function displays Debug window
*/
void object::OnDebug_objectClick(wxCommandEvent& event)
{
    if(Grid1->GetCursorRow()<0) return;
    wxString namex=Grid1->GetCellValue(Grid1->GetCursorRow(),0);

ContourDebug dlg(this,cont_calcx,system_var,namex);
dlg.ShowModal();
}

/*
Function is activates when user clicks on button NewObject
Function displays dialog for set name for new object. If name is correct object program window
is displays
*/
void object::OnNew_objectClick(wxCommandEvent& event)
{
  /*  int pos=Grid1->GetCursorRow();
    Grid1->InsertRows(pos+1,1);
    Grid1->SetGridCursor(pos+1,0);
    Grid1->SelectRow(pos+1);
    New_object->Enable(false);
    Edit_object->Enable(true);
    Copy_objects->Enable(true);*/

    wxTextEntryDialog dialog(this,_("Please insert object name minimal 1 character and  maximal 30 characters"),_("Insert object name"),_(""),wxOK|wxCANCEL);

    bool end=false;

    wxString name;
    bool correct_name=false;
    int  pos=0;

    while(!end)
    {
     if(dialog.ShowModal()==wxID_OK)
     {
         name=dialog.GetValue();
         int len=name.Length();
         if((len>0)&&(len<31))
         {

       if(cont_calcx->FindObjectName(name)>=0)
       {
           wxMessageBox(_("Object name is already use please use new name"),_("Object insertion error"),wxICON_ERROR,this);
       }
       else
       {
        if(name.Find('#')!=wxNOT_FOUND) wxMessageBox(_("Object name can not contain character #"),_("Object insertion error"),wxICON_ERROR,this);
        else
        {
           pos=Grid1->GetNumberRows();
          Grid1->InsertRows(pos,1);
          Grid1->SetCellValue(pos,0,name);
           correct_name=true;
          end=true;
        }

       }
         }
         else wxMessageBox(_("Object name must have at least 1 and maximal 30 characters"),_("Object insertion error"),wxICON_ERROR,this);
     }
     else end=true;
    }

 if(correct_name)// new name
 {
     object_prog=new TestProgram;
     wxArrayString start_str;

        ObjectDes obj(this,name,_(""),cont_calcx,object_prog,start_str);
     if(obj.ShowModal()==wxID_OK)AddTestProgramToStruct(name,cont_calcx,object_prog,obj.GetDescriptionArray());
     else  Grid1->DeleteRows(pos,1);
        delete object_prog;
        Edit_object->Enable(true);
        Debug_object->Enable(true);
        Delete_objects->Enable(true);
        Copy_objects->Enable(true);
        ExportObject->Enable(true);
 }

Grid1->Scroll(0,Grid1->GetCursorRow());

}

void object::OnExport_objectClick(wxCommandEvent& event)
{
 if(Grid1->GetCursorRow()<0) return;
    wxString namex=Grid1->GetCellValue(Grid1->GetCursorRow(),0);//Name of object

   wxString caption=wxT("Export object");
    wxString wildcard=wxT("DAT files (*.dat)|*.dat");
     wxString pok;
     wxString defaultDir;
    wxConfig config(wxT("Prog"),wxT("ELI"));
    config.Read(wxT("EXPORT_OBJECT"),&pok);
    if(pok.Len()==0) defaultDir=wxT("/home");
    else defaultDir=pok;

    wxString defaultFilename=namex;
    defaultFilename+=wxT(".dat");

    wxFileDialog dialog(this,caption,defaultDir,defaultFilename,wildcard,wxFD_SAVE);
    if(dialog.ShowModal()==wxID_OK)
    {
      wxString path=dialog.GetPath();
     wxString sv=path.BeforeLast('/');
      config.Write(wxT("EXPORT_OBJECT"),sv);
      int retx=cont_calcx->ExportObjectToFile(namex,path);
      if(retx!=0)
      {
          pok.Printf(_("Export object error: Error code:%d"),retx);
          wxMessageBox(pok,_("ERROR"),wxICON_ERROR,this);
      }
    }
}

void object::OnImport_objectClick(wxCommandEvent& event)
{
   wxString caption=wxT("Export object");
    wxString wildcard=wxT("DAT files (*.dat)|*.dat");
     wxString pok;
     wxString defaultDir;
    wxConfig config(wxT("Prog"),wxT("ELI"));
    int ret=0;
    wxString er_message,obj_name,obj_des;
    config.Read(wxT("EXPORT_OBJECT"),&pok);
    if(pok.Len()==0) defaultDir=wxT("/home");
    else defaultDir=pok;

    wxString defaultFilename=wxEmptyString;
    defaultFilename+=wxT(".dat");

    wxFileDialog dialog(this,caption,defaultDir,defaultFilename,wildcard,wxFD_OPEN);
    if(dialog.ShowModal()==wxID_OK)
    {
      wxString path=dialog.GetPath();
     wxString sv=path.BeforeLast('/');
      config.Write(wxT("EXPORT_OBJECT"),sv);
      ret=cont_calcx->ImportObjectFromFile(path,obj_name,obj_des,er_message);
      if(ret!=0)
      {
         wxMessageBox(er_message,_("Inport object error"),wxICON_ERROR,this) ;
          return;
      }
       int pos=Grid1->GetNumberRows();
          Grid1->InsertRows(pos,1);
          Grid1->SetCellValue(pos,0,obj_name);
          Grid1->SetCellValue(pos,1,obj_des);

       Grid1->Scroll(0,Grid1->GetCursorRow());
       Edit_object->Enable(true);
        Debug_object->Enable(true);
        Delete_objects->Enable(true);
        Copy_objects->Enable(true);
        ExportObject->Enable(true);

    }
}

/*
Function add object structure to test program for each object
Input parameters: name: object name
                  calc:  contour calculation class
                  tpg: Object test program class
                  descript: reference for array of each test program line description
    Function return -1 if object name was not found in object structure
             return -2 if no test program lines is in object structure
             return -11 (Get test program function error) Bad position in the structure, postion is more than real objects number
             return -12 (Get test program function error) Bad position in he structure, position number is less than 0
             return -13 (Get test program function error) Bad line number in the test program,
             return -14 (Get test program function error) Bad line number in the test program (less than 0)
             return -15 (Get test program function error) Bad command type (command type must be from range 1-6
             return -21 (Set program function error) Too many command in the test program ( more than 4999)
             return -22 (Set program function error) Cycle error in function
             return 0 if all is OK

             */
int object::AddStructToProgram(wxString name,ContourCalculation *calc,TestProgram *tpg,wxArrayString &descript)
{
    int pos=calc->FindObjectName(name);


    if(pos<0) return -1; // object name was not found

    int numb_lines=calc->GetObjectsLines(pos);
    if(numb_lines<1) return -2; // no test program lines in object structure


descript.Clear();

    for (int i=0;i<numb_lines;i++)
    {
        wxString param,desc;
        int bck=calc->GetTestProgram(param,desc,pos,i+1);
        if(bck != 0) return (bck-10); // Get test program function error
        bck=tpg->SetProgram(i+1,param);
        if(bck !=0) return (bck-20); // Set test program error
        descript.Add(desc);
    }

    return 0;
}

/*
Class for insert object test program to object structure;
Input parameters:
- name : name ob object
- calc: pointer for contour calculation structure
-tpg : pointer for Test program class
- description: array string with description of all test steps
Function always return 0;
Error message box generated in this function;
     Error code -1 = too many objects in the structure, maximal objects is 999
     Error code -2 = No commands in object test program
*/

int object::AddTestProgramToStruct(wxString name,ContourCalculation *calc,TestProgram *tpg,wxArrayString description)
{
int lines=tpg->GetLineNumber(); // number of lines in object test program structure
ContourCalculation::OBJECT_COMMAND  *objx;
objx=new ContourCalculation::OBJECT_COMMAND[lines];



for(int i=0;i<lines;i++)
{
    objx[i].description=description[i];
    if(tpg->GetCmd(i+1)==_("CONDITION"))  objx[i].type=1;
    else if(tpg->GetCmd(i+1)==_("MATH"))objx[i].type=2;
    else if(tpg->GetCmd(i+1)==_("AND")) objx[i].type=3;
     else if(tpg->GetCmd(i+1)==_("OR")) objx[i].type=4;
     else if(tpg->GetCmd(i+1)==_("LB"))  objx[i].type=5;
     else if(tpg->GetCmd(i+1)==_("RB")) objx[i].type=6;
     else objx[i].type=0;

     if((objx[i].type>2)||(objx[i].type<1))
     {
         objx[i].f_param1=0;
         objx[i].f_param2=0;
         objx[i].i_param1=0;
         objx[i].i_param2=0;
         objx[i].i_result=0;
         objx[i].operand=0;
         objx[i].param1=0;
         objx[i].param2=0;
         objx[i].s_param1=_("");
         objx[i].s_param2=_("");
         objx[i].s_result=_("");
     }
     else
     {
          // Test command parameters:param1#i_param1#f_param1#s_param1#param2#i_param2#f_param2#s_param2#operand#i_result#s_result


        wxString px=tpg->GetParam(i+1);
        objx[i].param1=wxAtoi(px.BeforeFirst('#'));
        px=px.AfterFirst('#');
        objx[i].i_param1=wxAtoi(px.BeforeFirst('#'));
        px=px.AfterFirst('#');
        objx[i].f_param1=wxAtof(px.BeforeFirst('#'));
        px=px.AfterFirst('#');
        objx[i].s_param1=px.BeforeFirst('#');
        px=px.AfterFirst('#');
        objx[i].param2=wxAtoi(px.BeforeFirst('#'));
        px=px.AfterFirst('#');
        objx[i].i_param2=wxAtoi(px.BeforeFirst('#'));
        px=px.AfterFirst('#');
        objx[i].f_param2=wxAtof(px.BeforeFirst('#'));
        px=px.AfterFirst('#');
        objx[i].s_param2=px.BeforeFirst('#');
        px=px.AfterFirst('#');
        objx[i].operand=wxAtoi(px.BeforeFirst('#'));
        px=px.AfterFirst('#');
        objx[i].i_result=wxAtoi(px.BeforeFirst('#'));
        objx[i].s_result=px.AfterFirst('#');
     }
}

int ret=cont_calcx->SetObject(name,_(""),lines,objx);
if(ret != 0)
{
    wxString er_mes=_("Set object to structure error\nError code :");
    er_mes<<ret;
    wxMessageBox(er_mes,_("Set object error"),wxICON_ERROR,this);
}

delete[] objx;

 return 0;
}

/*
Function is called when user click on button Edit Object
*/
void object::OnEdit_objectClick(wxCommandEvent& event)
{
    wxString Object_name=Grid1->GetCellValue(Grid1->GetCursorRow(),0);
    if((Object_name.Length()==0)||(Object_name.Length()>30))wxMessageBox(_("Object name must have at least 1 character and maximal 30 characters"),_("Object name error"),wxICON_ERROR);
    else
    {
        object_prog=new TestProgram;
         wxArrayString descript;
        int ret=AddStructToProgram(Object_name,cont_calcx,object_prog,descript);
        if(ret !=0)
        {
            wxString er_mes=_("Can not read edited object from structure\nError code: ");
            er_mes<<ret;
            wxMessageBox(er_mes,_("Edit object error"),wxICON_ERROR,this);
            delete object_prog;
            object_prog=new TestProgram;
        }

           wxArrayInt pm;
   pm=Grid1->GetSelectedRows();
   if(pm.GetCount()>0)
   {
       Grid1->SetGridCursor(pm[0],0);
   }

        wxString name_obj=Grid1->GetCellValue(Grid1->GetCursorRow(),0);

        ObjectDes obj(this,name_obj,Grid1->GetCellValue(Grid1->GetCursorRow(),1),cont_calcx,object_prog,descript);
    if(obj.ShowModal()==wxID_OK)AddTestProgramToStruct(name_obj,cont_calcx,object_prog,obj.GetDescriptionArray());
        delete object_prog;

        Grid1->Scroll(0,Grid1->GetCursorRow());
    }
}

/*
Function is called when user click on button CopyObjets
*/
void object::OnCopy_objectClick(wxCommandEvent& event)
{
       wxArrayInt pm;
   pm=Grid1->GetSelectedRows();
   if(pm.GetCount()>0)
   {
       Grid1->SetGridCursor(pm[0],0);
   }


     wxString old_name=Grid1->GetCellValue(Grid1->GetCursorRow(),0);
     wxString mes=_("Copy object: ");
     mes+=old_name;
     mes+=_(" ?");

     wxString old_desc=Grid1->GetCellValue(Grid1->GetCursorRow(),1);
    wxTextEntryDialog dialog(this,_("Please insert new object name minimal 1 character and  maximal 30 characters"),mes,_(""),wxOK|wxCANCEL);

    bool end=false;

    wxString name;
    bool correct_name=false;
    int  pos=0;

    while(!end)
    {
     if(dialog.ShowModal()==wxID_OK)
     {
         name=dialog.GetValue();
         int len=name.Length();
         if((len>0)&&(len<31))
         {

       if(cont_calcx->FindObjectName(name)>=0)
       {
           wxMessageBox(_("Object name is already use please use new name"),_("Object insertion error"),wxICON_ERROR,this);
       }
       else
       {
        if(name.Find('#')!=wxNOT_FOUND) wxMessageBox(_("Object name can not contain character #"),_("Object insertion error"),wxICON_ERROR,this);
        else
        {
           correct_name=true;
          end=true;
        }

       }
         }
         else wxMessageBox(_("Object name must have at least 1 and maximal 30 characters"),_("Object insertion error"),wxICON_ERROR,this);
     }
     else end=true;
    }

 if(correct_name)// new name
 {
     if(cont_calcx->CopyObject(old_name,name)==0)
     {
         pos=Grid1->GetNumberRows();
          Grid1->InsertRows(pos,1);
          Grid1->SetCellValue(pos,0,name);
          Grid1->SetCellValue(pos,1,old_desc);
     }
     else
     {
         wxMessageBox(_("Error copy object in OBJECTCAL structure"),_("Copy object error"),wxICON_ERROR,this);
     }
 }

 Grid1->Scroll(0,Grid1->GetCursorRow());
}

/*
Function is called when user click on button Delete Object
*/
void object::OnDelete_objectClick(wxCommandEvent& event)
{
       wxArrayInt pm;
   pm=Grid1->GetSelectedRows();
   if(pm.GetCount()>0)
   {
       Grid1->SetGridCursor(pm[0],0);
   }


  wxString obj=Grid1->GetCellValue(Grid1->GetCursorRow(),0);
  wxString mes=_("Delete object: ");
  mes+=obj;
  mes+=_(" ?");
  if(wxMessageBox(mes,_("Delete object"),wxYES_NO|wxICON_QUESTION,this)==wxYES)
  {
      if(cont_calcx->DeleteObject(obj)==0)
      {
          Grid1->DeleteRows(Grid1->GetCursorRow(),1);
      }
      else wxMessageBox(_("Error delete object from OBJECTCAL structure"),_("Delete object error"),wxICON_ERROR,this);
  }


}

/*
Function is called when user clicks on button UpdateObject
*/
void object::OnUpdate_objectClick(wxCommandEvent& event)
{
wxString er_mes;
for(int i=0;i<Grid1->GetNumberRows();i++)
{
int ret=cont_calcx->UpdateDescription(Grid1->GetCellValue(i,0),Grid1->GetCellValue(i,1));
if(ret==-1)
{
   er_mes=_("Object:");
   er_mes+= Grid1->GetCellValue(i,0);
   er_mes+=_(" not exist in OBJECTCAL structure\n Update module was not finished");
   wxMessageBox(er_mes,_("Update module error"),wxICON_ERROR,this);
   return;
}
if(ret==-2)
{
    er_mes=_("Description string on line: ");
    er_mes<<(i+1);
    er_mes+=_(" include prohibeted character #");
    wxMessageBox(er_mes,_("Update module error"),wxICON_ERROR,this);
    return;
}
}
wxMessageBox(_("Module was updated"),_("Update module"),wxICON_INFORMATION,this);



}

/****************************************************
End class object
****************************************************/
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
ObjectDes::ObjectDes(wxWindow* parent,wxString Object_name,wxString comments,ContourCalculation *cont_calc,TestProgram *obj_tpg,wxArrayString descript,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ObjectDes)
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxCAPTION, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Object name"));
	ObjectName = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer1->Add(ObjectName, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Object description"));
	ObjectDescript = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticBoxSizer2->Add(ObjectDescript, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer2, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer4, 2, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	InsertLine = new wxButton(this, ID_BUTTON1, _("Insert line"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(InsertLine, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	EditLine = new wxButton(this, ID_BUTTON2, _("Edit line"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(EditLine, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CopyLines = new wxButton(this, ID_BUTTON3, _("Copy lines"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer2->Add(CopyLines, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	DeleteLine = new wxButton(this, ID_BUTTON4, _("Delete line"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer2->Add(DeleteLine, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	UpdateModule = new wxButton(this, ID_BUTTON5, _("Update-Exit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	BoxSizer2->Add(UpdateModule, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID1"));
	Grid1->CreateGrid(0,2);
	Grid1->EnableEditing(true);
	Grid1->EnableGridLines(true);
	Grid1->SetDefaultColSize(200, true);
	Grid1->SetColLabelValue(0, _("Command"));
	Grid1->SetColLabelValue(1, _("Description"));
	Grid1->SetDefaultCellFont( Grid1->GetFont() );
	Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
	BoxSizer3->Add(Grid1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 7, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ObjectDes::OnInsertLineClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ObjectDes::OnEditLineClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ObjectDes::OnCopyLinesClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ObjectDes::OnDeleteLineClick);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ObjectDes::OnUpdateModuleClick);
	//*)
	ObjectName->WriteText(Object_name);
	ObjectDescript->WriteText(comments);
	   Grid1->SetColSize(0,150);
    Grid1->SetColSize(1,320);
    Grid1->SetLabelSize(0,60);
   	Grid1->SetSelectionMode(wxGrid::wxGridSelectRows);
   		cont_calcx=cont_calc;
   		obj_tpgx=obj_tpg;
   		wxString px=_("");


   		for(int i=0;i<obj_tpgx->GetLineNumber();i++)
   		{
   		    Grid1->InsertRows(i,1);
   		    px=obj_tpgx->GetCmd(i+1);
   		    if(px==_("LB"))px=_("(");
   		    if(px==_("RB"))px=_(")");
   		    Grid1->SetCellValue(i,0,px);
   		   Grid1->SetCellValue(i,1,descript[i]);
   		}
}

ObjectDes::~ObjectDes()
{
	//(*Destroy(ObjectDes)
	//*)

}

/*
Function check module commands. If all is ok function return true,if there is some error
function return false
*/
bool ObjectDes::CheckModule(void)
{
    struct ErrorStruct
    {
     wxString message;
     int line;
    };

    ErrorStruct er_st;

   int lines=Grid1->GetNumberRows();
   bool condition_flag=false; //false no condition
   for(int i=0;i<lines;i++) // function check if there is some condition command
   {
     if(Grid1->GetCellValue(i,0)== _("CONDITION")) condition_flag=true;
   }
   if(!condition_flag)
   {
       wxMessageBox(_("No condition command in the module"),_("Check module error"),wxICON_ERROR,this);
       return false;
   }

   condition_flag=false;

try
{

   for(int i=0;i<lines;i++) // Check condition algoritm
   {

         if(Grid1->GetCellValue(i,0)== _("CONDITION"))
         {
             if(condition_flag)
             {

               er_st.message=_("No AND or OR command between 2 conditions.");
               er_st.line=i;
               throw er_st;
             }
             else condition_flag=true;
         }
         if((Grid1->GetCellValue(i,0)== _("AND"))||(Grid1->GetCellValue(i,0)== _("OR")))
         {
             if(condition_flag) condition_flag=false;
             else
             {
               er_st.message=_("More than 1 logical operator AND (OR) between 2 conditions.");
               er_st.line=i;
               throw er_st;
             }
         }

   }
   int brackets_numb=0;

   for(int i=0;i<lines;i++)
   {
     if(Grid1->GetCellValue(i,0)== _("(")) brackets_numb++;
     if(Grid1->GetCellValue(i,0)==_(")")) brackets_numb--;

     if(brackets_numb<0)
     {
                er_st.message=_("Missing left bracket.");
               er_st.line=i;
               throw er_st;
     }
     if(brackets_numb>10)
     {
               er_st.message=_("Too many brackets inside Maximal number of brackets inside is 10.");
               er_st.line=i;
               throw er_st;
     }
   }

   if(brackets_numb != 0)
   {
                er_st.message=_("Missing at least one right bracket .");
               er_st.line=lines-1;
               throw er_st;
   }

   wxString description;
   for(int i=0;i<lines;i++)
   {
       description=Grid1->GetCellValue(i,1);
       if(description.Length()>50)
       {
                 er_st.message=_("Description can have maximal 50 characters.");
               er_st.line=i;
               throw er_st;
       }
       if(description.Find('#')!=wxNOT_FOUND)
       {
                er_st.message=_("Description can not contains character #");
               er_st.line=i;
               throw er_st;
       }
   }


}



   catch(ErrorStruct &msg)
   {
      wxString er_msg;
      er_msg=msg.message;
      er_msg+=_("\nError in line: ");
      er_msg<<(msg.line+1);
      wxMessageBox(er_msg,_("Check module error"),wxICON_ERROR,this);
               Grid1->SelectRow(msg.line);
               return false;
   }

   description_array.Clear();

   for(int i=0; i<lines;i++)
   {
     description_array.Add(Grid1->GetCellValue(i,1));
   }

    return true;
}

/*
Click on Insert line button
FUnction insert one line after line with curcor.( If option "()" is selected function inserts 2 lines)
Before Insert line dialog for selection command is display. If user click OK selected commands is
write to the line, if user press Cancel "CONDITION " command  is write to the line.

Maximal line in object test program is 402, if you want change  change number in the first condition, maximal posible
lines is 4998 according test program class !!!
*/
void ObjectDes::OnInsertLineClick(wxCommandEvent& event)
{
    if(obj_tpgx->GetLineNumber()>MAXIMAL_OBJECT_TEST_PROGRAM_LINES)
    {
        wxMessageBox(_("Maximal object program lines is 400 !!!!"),_("Error"),wxICON_ERROR);
        return;
    }
    wxArrayString commands;
    commands.Add(_("CONDITION"));
    commands.Add(_("MATH"));
    commands.Add(_("AND"));
    commands.Add(_("OR"));
    commands.Add(_("()"));

    wxSingleChoiceDialog dialog(this,wxT("Please select command"),wxT("Select command"),commands);
    dialog.SetSelection(0);

     wxString selected_command;
    if(dialog.ShowModal()==wxID_OK) selected_command=dialog.GetStringSelection();
    else selected_command=_("CONDITION");

       wxArrayInt pm;
   pm=Grid1->GetSelectedRows();
   if(pm.GetCount()>0)
   {
       Grid1->SetGridCursor(pm[0],0);
   }


    int pos=Grid1->GetCursorRow();
    Grid1->InsertRows(pos+1,1);
    Grid1->SetGridCursor(pos+1,0);
    Grid1->SelectRow(pos+1);
    Grid1->SetReadOnly(pos+1,0);

     wxString prog_string=selected_command;
     Grid1->Scroll(0,pos);

     /*
     Test command parameters:
     type of command#param1#i_param1#f_param1#s_param1#param2#i_param2#f_param2#s_param2#operand#i_result#s_result
     */

    if(selected_command!=_("()"))
    {
        Grid1->SetCellValue(pos+1,0,selected_command);

        if(selected_command==_("MATH"))prog_string+=_("#1#1#0# #1#1#0# #1#0#");
        else if(selected_command==_("CONDITION")) prog_string+=_("#1#1#0# #1#1#0# #1");
     else prog_string+=_("#1#0#0# #1#0#0# #1#0# ");

      if(obj_tpgx->SetProgram(pos+2,prog_string)!=0) wxMessageBox(_("Error Set test program"),_("Error"),wxICON_ERROR); // Set test program parameter in new line
    }
    else
    {
     Grid1->SetCellValue(pos+1,0,_("("));
     Grid1->InsertRows(pos+2,1);
    Grid1->SetGridCursor(pos+2,0);
    Grid1->SelectRow(pos+2);
    Grid1->SetCellValue(pos+2,0,_(")"));
    Grid1->SetReadOnly(pos+2,0);

    for(int i=2;i<4;i++)
    {
    if(i==2) prog_string=_("LB"); // LB= ( Left bracket
    if(i==3) prog_string=_("RB"); // RB= ) Right bracket
     prog_string+=_("#1#0#0# #1#0#0# #1#0# ");

      if(obj_tpgx->SetProgram(pos+i,prog_string)!=0) wxMessageBox(_("Error Set test program"),_("Error"),wxICON_ERROR); // Set test program parameter in new line
    }
    }

    Grid1->Scroll(0,Grid1->GetCursorRow());
}

/*
Function is call when user click  Edit line  button.
Function is active only if commands CONDITION or MATH is in selected line.
Function display edit command dialog
*/
void ObjectDes::OnEditLineClick(wxCommandEvent& event)
{

       wxArrayInt pm;
   pm=Grid1->GetSelectedRows();
   if(pm.GetCount()>0)
   {
       Grid1->SetGridCursor(pm[0],0);
   }


wxString command=Grid1->GetCellValue(Grid1->GetCursorRow(),0); //Get command name
wxString pxx=obj_tpgx->GetParam(Grid1->GetCursorRow()+1);
if(pxx==_("ERROR"))
{
    wxMessageBox(_("Can not find selected command in tpg structure"),_("Error"),wxICON_ERROR,this);
    pxx=_("");
}
wxString comd=_("");
if(command==_("MATH"))
{
  MathSubModule math(this,cont_calcx,pxx);
  math.ShowModal();
  comd=_("");
  comd+=math.GetCommandParameter();
  if(comd==_("Error"))return;

  if(obj_tpgx->SetProgram(Grid1->GetCursorRow()+1,comd,1)!=0) wxMessageBox(_("Can not update tpg structure"),_("Error"),wxICON_ERROR);



}
else if(command==_("CONDITION"))
{
    ConditionSubModule cond(this,cont_calcx,pxx);
    cond.ShowModal();
    comd=cond.GetCommandParameter();
   if(comd==_("Error"))return;
    if(obj_tpgx->SetProgram(Grid1->GetCursorRow()+1,comd,1)!=0) wxMessageBox(_("Can not update tpg structure"),_("Error"),wxICON_ERROR);


}

}

/*
Function copy lines in the test program class
*/
void ObjectDes::OnCopyLinesClick(wxCommandEvent& event)
{
     if(Grid1->GetRows()==0) return; // no rows in test program grid

        wxArrayInt pm;
   pm=Grid1->GetSelectedRows();
   if(pm.GetCount()>0)
   {
       Grid1->SetGridCursor(pm[0],0);
   }


       int y=Grid1->GetCursorRow()+1;
   long startt=1;
   long end=1;

   wxNumberEntryDialog dialog (this,wxT("Insert Start of block"),wxT("Start block line"),wxT("Start of block"),1,1,y);
   if(dialog.ShowModal()==wxID_OK) startt=dialog.GetValue();
   else return;

     wxNumberEntryDialog dialog2 (this,wxT("Insert End of block"),wxT("End block line"),wxT("End of block"),startt,startt,y);
   if(dialog2.ShowModal()==wxID_OK) end=dialog2.GetValue();
   else return;

   if(obj_tpgx->CopyBlockProgram(y,startt,end)==0)
   {
    Grid1->InsertRows(y,(end-startt+1));
    for(int i=0;i<(end-startt+1);i++)
    {
       Grid1->SetCellValue(y+i,0,Grid1->GetCellValue(startt-1+i,0));
       Grid1->SetCellValue(y+i,1,Grid1->GetCellValue(startt-1+i,1));
    }
   }
   else wxMessageBox(_("Error Copy program"),_("ERROR"),wxICON_ERROR,this);

   Grid1->Scroll(0,Grid1->GetCursorRow());

}

/**
Function is called when user click on Delete button
After confirmation function deletes current line
**/
void ObjectDes::OnDeleteLineClick(wxCommandEvent& event)
{
       wxArrayInt pm;
   pm=Grid1->GetSelectedRows();
   if(pm.GetCount()>0)
   {
       Grid1->SetGridCursor(pm[0],0);
   }

  int pos=Grid1->GetCursorRow();
  if(pos<0) return;

  wxString mes=_("Do you want to delete line ");
  mes<<pos+1;
  mes+=_("?");
  if(wxMessageBox(mes,_("Warning !!!"),wxICON_QUESTION | wxYES_NO,this)==wxYES)
  {
     if(obj_tpgx->DeleteLine(pos+1)!=0) wxMessageBox(_("Can not delete selected line in test program structure"),_("Error"),wxICON_ERROR);
     else Grid1->DeleteRows(pos,1);
  }

}

/**
Function is called when user click on button UpdateModule
**/
void ObjectDes::OnUpdateModuleClick(wxCommandEvent& event)
{

    if(wxMessageBox(_("DO you want to save all changes?"),_("Save changes?"),wxYES_NO | wxICON_QUESTION,this)==wxYES)
    {
        if(CheckModule())EndModal(wxID_OK);
    }
    else EndModal(wxID_CANCEL);
}

/***************************************************************************
End class ObjectDes
*************************************************************************/

/*******************************************************************************************
MathSubModule class

This class is called when user want edit MATH command

Input parameters:
- parent: parent window
- cont_calc: pointer for ContourCalculation structure
- prog_param: command paramters
*******************************************************************************************/
MathSubModule::MathSubModule(wxWindow* parent,ContourCalculation *cont_calc,wxString prog_param,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(MathSubModule)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer7;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer6;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer5;

	Create(parent, wxID_ANY, _("Math submodule"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Parameter 1"));
	Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(128,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice1->SetSelection( Choice1->Append(_("Contour parameter")) );
	Choice1->Append(_("System variable"));
	Choice1->Append(_("Temporary variable"));
	Choice1->Append(_("Number"));
	StaticBoxSizer2->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, this, _("Parameter 1 option"));
	Param1_option_choice = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	StaticBoxSizer3->Add(Param1_option_choice, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Param1_Option_text = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticBoxSizer3->Add(Param1_Option_text, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(StaticBoxSizer3, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer2, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Math operand"));
	Math_operand = new wxChoice(this, ID_CHOICE3, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	Math_operand->SetSelection( Math_operand->Append(_("( + )")) );
	Math_operand->Append(_("( - )"));
	Math_operand->Append(_("( / )"));
	Math_operand->Append(_("( * )"));
	Math_operand->Append(_("Pow"));
	Math_operand->Append(_("Sqrt"));
	Math_operand->Append(_("Sin"));
	Math_operand->Append(_("Cos"));
	Math_operand->Append(_("Tan"));
	StaticBoxSizer4->Add(Math_operand, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer4, 2, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Parameter 2"));
	Choice2 = new wxChoice(this, ID_CHOICE4, wxDefaultPosition, wxSize(128,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
	Choice2->SetSelection( Choice2->Append(_("Contour parameter")) );
	Choice2->Append(_("System variable"));
	Choice2->Append(_("Temporary variable"));
	Choice2->Append(_("Number"));
	StaticBoxSizer5->Add(Choice2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer6 = new wxStaticBoxSizer(wxVERTICAL, this, _("Parameter 1 option"));
	Param2_option_choice = new wxChoice(this, ID_CHOICE5, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
	StaticBoxSizer6->Add(Param2_option_choice, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Param2_Option_text = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	StaticBoxSizer6->Add(Param2_Option_text, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer5->Add(StaticBoxSizer6, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer5, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Result"));
	Result = new wxChoice(this, ID_CHOICE6, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE6"));
	Result->SetSelection( Result->Append(_("Temporary variable")) );
	Result->Append(_("System variable"));
	StaticBoxSizer1->Add(Result, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer7 = new wxStaticBoxSizer(wxVERTICAL, this, _("Result option"));
	Result_option_choice = new wxChoice(this, ID_CHOICE7, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE7"));
	Result_option_choice->Disable();
	StaticBoxSizer7->Add(Result_option_choice, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Result_option_text = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer7->Add(Result_option_text, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(StaticBoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer1, 4, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    CloseObj= new wxButton(this, ID_BUTTON7, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    BoxSizer2->Add(CloseObj, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Result_option_choice->Enable(false);
    Result_option_text->Enable(true);

	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MathSubModule::OnChoice1Select);
	Connect(ID_CHOICE4,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MathSubModule::OnChoice2Select);
	Connect(ID_CHOICE6,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MathSubModule::OnChoice6Select);
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MathSubModule::OnButtonCloseClick);
	//*)
		cont_calcx=cont_calc;

		   /*
     Test command parameters:
     param1#i_param1#f_param1#s_param1#param2#i_param2#f_param2#s_param2#operand#i_result#s_result
     */
     int pos1=wxAtoi(prog_param.BeforeFirst('#')); // param1
     wxString pxc=prog_param.AfterFirst('#'); // rest of string
     int i_param1=wxAtoi(pxc.BeforeFirst('#')); // i_param1
     pxc=pxc.AfterFirst('#');
     float f_param1=wxAtof(pxc.BeforeFirst('#')); // float param1
     pxc=pxc.AfterFirst('#');
     wxString s_param1=pxc.BeforeFirst('#'); // string param1
     pxc=pxc.AfterFirst('#');
     int pos2=wxAtoi(pxc.BeforeFirst('#')); //param2
     pxc=pxc.AfterFirst('#');
     int i_param2=wxAtoi(pxc.BeforeFirst('#')); //integer param2
     pxc=pxc.AfterFirst('#');
     float f_param2=wxAtof(pxc.BeforeFirst('#'));  //float param2
      pxc=pxc.AfterFirst('#');
      wxString s_param2=pxc.BeforeFirst('#'); // string param2
       pxc=pxc.AfterFirst('#');
       int operand=wxAtoi(pxc.BeforeFirst('#')); // math operand
        pxc=pxc.AfterFirst('#');
        int i_result=wxAtoi(pxc.BeforeFirst('#')); // integer result
        wxString s_result=pxc.AfterFirst('#'); // integer string

     wxString pxx=_(""); //variable for set text box

	 if((pos1<1)||(pos1>4)||(pos2<1)||(pos2>4))
	 {
	 FillParameters(_("Contour parameter"));
    FillParameters2(_("Contour parameter"));

	 }
	 else
	 {
	     switch (pos1)
	     {
	         case 1:
	         FillParameters(_("Contour parameter"));
	         Choice1->SetStringSelection(_("Contour parameter"));
	         Param1_option_choice->SetStringSelection(cont_calcx->ContourNumberToString(i_param1));
	         break;
	         case 2:
	         FillParameters(_("System variable"));
	         Choice1->SetStringSelection(_("System variable"));
            pxx=_("Variable_");
	         pxx<<i_param1;
	         Param1_option_choice->SetStringSelection(pxx);
	         break;
	         case 3:
	         FillParameters(_("Temporary variable"));
	         Choice1->SetStringSelection(_("Temporary variable"));
	         Param1_Option_text->SetValue(s_param1);
	         break;
	         case 4:
	         FillParameters(_("Number"));
	         Choice1->SetStringSelection(_("Number"));
	         pxx<<f_param1;
	         Param1_Option_text->SetValue(pxx);
	         break;
	     }

	      switch (pos2)
	     {
	         case 1:
	         FillParameters2(_("Contour parameter"));
	         Choice2->SetStringSelection(_("Contour parameter"));
	         Param2_option_choice->SetStringSelection(cont_calcx->ContourNumberToString(i_param2));
	         break;
	         case 2:
	         FillParameters2(_("System variable"));
	         Choice2->SetStringSelection(_("System variable"));
            pxx=_("Variable_");
	         pxx<<i_param2;
	         Param2_option_choice->SetStringSelection(pxx);
	         break;
	         case 3:
	         FillParameters2(_("Temporary variable"));
	         Choice2->SetStringSelection(_("Temporary variable"));
	         Param2_Option_text->SetValue(s_param2);
	         break;
	         case 4:
	         FillParameters2(_("Number"));
	         Choice2->SetStringSelection(_("Number"));
	         pxx=_("");
	         pxx<<f_param2;
	         Param2_Option_text->SetValue(pxx);
	         break;
	     }
	     Math_operand->SetSelection(operand-1); //set operand
	     if(i_result<0) //temporary variable result
	     {
	         Result->SetSelection(0);
	          Result_option_choice->Enable(false);
              Result_option_text->Enable(true);
              Result_option_text->SetValue(s_result);
	     }
         else  //system variable result
         {
             Result->SetSelection(1);
          wxString pom=_("");
        Result_option_choice->Enable(true);
    Result_option_text->Enable(false);
    Result_option_choice->Clear();
    Result_option_choice->SetSelection(Result_option_choice->Append(_("Variable_0")));
     for(int i=1;i<100;i++)
     {
       pom.Printf(_("Variable_%d"),i);
       Result_option_choice->Append(pom);
     }
       Result_option_choice->SetSelection(i_result);
         }

	 }

}

MathSubModule::~MathSubModule()
{
	//(*Destroy(MathSubModule)
	//*)

}
/*
Function return test program string
*/
wxString MathSubModule::GetCommandParameter(void)
{
       /*
     Test command parameters:
     type of command#param1#i_param1#f_param1#s_param1#param2#i_param2#f_param2#s_param2#operand#i_result#s_result
     */
int pos=Choice1->GetSelection()+1; //param1 type of parameter 1
int i_param1=0;
float f_param1=0;
wxString s_param1=_(" ");
wxString px=_("");

switch (pos)
{
    case 1:
     i_param1=cont_calcx->ContourStringToNumber(Param1_option_choice->GetStringSelection());
    break;
    case 2:
   px=Param1_option_choice->GetStringSelection();
     i_param1=wxAtoi(px.AfterFirst('_'));
    break;
   case 3:
    s_param1=Param1_Option_text->GetValue();
      if(s_param1.Find('#')!=wxNOT_FOUND)
    {
        wxMessageBox(_("Temporary variable can not have  character #, Math is not stored"),_("Error"),wxICON_ERROR);
        return _("Error");
    }
    break;
   case 4:
    f_param1=wxAtof(Param1_Option_text->GetValue());
     break;
}

int pos2=Choice2->GetSelection()+1;
int i_param2=0;
float f_param2=0;
wxString s_param2=_(" ");

switch (pos2)
{
    case 1:
     i_param2=cont_calcx->ContourStringToNumber(Param2_option_choice->GetStringSelection());
    break;
    case 2:
   px=Param2_option_choice->GetStringSelection();
     i_param2=wxAtoi(px.AfterFirst('_'));
    break;
   case 3:
    s_param2=Param2_Option_text->GetValue();
      if(s_param2.Find('#')!=wxNOT_FOUND)
    {
        wxMessageBox(_("Temporary variable can not have  character #, Math is not stored"),_("Error"),wxICON_ERROR);
        return _("Error");
    }
    break;
   case 4:
    f_param2=wxAtof(Param2_Option_text->GetValue());
     break;
}

int operand=Math_operand->GetSelection()+1;

int i_result=-1; // -1 means result is temporary array
wxString s_result=_(" ");

if(Result->GetSelection()==0) s_result=Result_option_text->GetValue(); // temprary array
else
{
    px=Result_option_choice->GetStringSelection();
    i_result=wxAtoi(px.AfterFirst('_'));
}

  if(s_result.Find('#')!=wxNOT_FOUND)
    {
        wxMessageBox(_("Temporary variable can not have  character #, Math is not stored"),_("Error"),wxICON_ERROR);
        return _("Error");
    }
   /*
     Test command parameters:
     type of command#param1#i_param1#f_param1#s_param1#param2#i_param2#f_param2#s_param2#operand#i_result#s_result
     */
wxString ret_val=_("MATH#");
ret_val<<pos;
ret_val+=_("#");
ret_val<<i_param1;
ret_val+=_("#");
ret_val<<f_param1;
ret_val+=_("#");
ret_val+=s_param1;
ret_val+=_("#");
ret_val<<pos2;
ret_val+=_("#");
ret_val<<i_param2;
ret_val+=_("#");
ret_val<<f_param2;
ret_val+=_("#");
ret_val+=s_param2;
ret_val+=_("#");
ret_val<<operand;
ret_val+=_("#");
ret_val<<i_result;
ret_val+=_("#");
ret_val+=s_result;

return ret_val;
}

/***
Function fills parameters to test proghram window according selected parameter
in Choice1 box
**/
void MathSubModule::OnChoice1Select(wxCommandEvent& event)
{
  FillParameters(Choice1->GetStringSelection());

}

void MathSubModule::OnButtonCloseClick(wxCommandEvent& event)
{
 Close();
}

/***
Function fills parameters to test proghram window according selected parameter
in Choice2 box
**/
void MathSubModule::OnChoice2Select(wxCommandEvent& event)
{
  FillParameters2(Choice2->GetStringSelection());

}
/*
Function filled ResultOption choice window with system variables
*/
void MathSubModule::OnChoice6Select(wxCommandEvent& event)
{
if(Result->GetStringSelection()==_("System variable"))
{
    wxString pom=_("");
    Result_option_choice->Enable(true);
    Result_option_text->Enable(false);
    Result_option_choice->Clear();
    Result_option_choice->SetSelection(Result_option_choice->Append(_("Variable_0")));
     for(int i=1;i<100;i++)
     {
       pom.Printf(_("Variable_%d"),i);
       Result_option_choice->Append(pom);
     }

}
else
{
  Result_option_choice->Enable(false);
    Result_option_text->Enable(true);
}

}

/*
Function fill Parameter 1 options
*/
void MathSubModule::FillParameters(wxString param)
{
 if(param==_("Contour parameter"))
 {
     Param1_option_choice->Enable(true);
     Param1_Option_text->Enable(false);
     Param1_option_choice->Clear();
     Param1_option_choice->SetSelection(Param1_option_choice->Append(cont_calcx->ContourNumberToString(1)));
     for(int i=2;i<53;i++) Param1_option_choice->Append(cont_calcx->ContourNumberToString(i));
 }
 else if(param==_("System variable"))
 {
     wxString pom=_("");
      Param1_option_choice->Enable(true);
       Param1_Option_text->Enable(false);
       Param1_option_choice->Clear();
     Param1_option_choice->SetSelection(Param1_option_choice->Append(_("Variable_0")));
     for(int i=1;i<100;i++)
     {
       pom.Printf(_("Variable_%d"),i);
       Param1_option_choice->Append(pom);
     }
 }
 else
 {
     Param1_option_choice->Enable(false);
       Param1_Option_text->Enable(true);
 }
}

/*
Function fill Parameter 2 options
*/
void MathSubModule::FillParameters2(wxString param)
{
 if(param==_("Contour parameter"))
 {
     Param2_option_choice->Enable(true);
     Param2_Option_text->Enable(false);
     Param2_option_choice->Clear();
     Param2_option_choice->SetSelection(Param2_option_choice->Append(cont_calcx->ContourNumberToString(1)));
     for(int i=2;i<53;i++) Param2_option_choice->Append(cont_calcx->ContourNumberToString(i));
 }
 else if(param==_("System variable"))
 {
     wxString pom=_("");
      Param2_option_choice->Enable(true);
       Param2_Option_text->Enable(false);
       Param2_option_choice->Clear();
     Param2_option_choice->SetSelection(Param2_option_choice->Append(_("Variable_0")));
     for(int i=1;i<100;i++)
     {
       pom.Printf(_("Variable_%d"),i);
       Param2_option_choice->Append(pom);
     }
 }
 else
 {
     Param2_option_choice->Enable(false);
       Param2_Option_text->Enable(true);
 }
}
/*******************************************************************************
End class MathSubModule
*******************************************************************************/

/*******************************************************************************************************
ConditionSubModule class

Class is displayed when user click on command CONDITION
Input parameters:
- parent: parent window
- cont_calc: pointer for ContourCalculation class
- prog_param: object program parameters
*******************************************************************************************************/
ConditionSubModule::ConditionSubModule(wxWindow* parent,ContourCalculation *cont_calc,wxString prog_param,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ConditionSubModule)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer5;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Parameter 1"));
	Param1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(164,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Param1->SetSelection( Param1->Append(_("Contour parameter")) );
	Param1->Append(_("System variable"));
	Param1->Append(_("Temporary variable"));
	Param1->Append(_("Number"));
	StaticBoxSizer1->Add(Param1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("Parameter 1 option"));
	Param1_option_choice = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	StaticBoxSizer2->Add(Param1_option_choice, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Param1_op_text = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer2->Add(Param1_op_text, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(StaticBoxSizer2, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 4, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Comparison option"));
	Compar_option = new wxChoice(this, ID_CHOICE3, wxDefaultPosition, wxSize(195,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	Compar_option->SetSelection( Compar_option->Append(_("Parameter 1 = Parameter 2")) );
	Compar_option->Append(_("Parameter 1 > Parameter 2"));
	Compar_option->Append(_("Parameter 1 < Parameter 2"));
	Compar_option->Append(_("Parameter 1 >= Parameter 2"));
	Compar_option->Append(_("Parameter 1 <= Parameter 2"));
	Compar_option->Append(_("Parameter 1 != Parameter 2"));
	StaticBoxSizer3->Add(Compar_option, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer3, 2, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Parameter 2"));
	Parameter2 = new wxChoice(this, ID_CHOICE4, wxDefaultPosition, wxSize(143,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
	Parameter2->SetSelection( Parameter2->Append(_("Contour parameter")) );
	Parameter2->Append(_("System variable"));
	Parameter2->Append(_("Temporary variable"));
	Parameter2->Append(_("Number"));
	StaticBoxSizer4->Add(Parameter2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxVERTICAL, this, _("Parameter 2 option"));
	Param2_option_choice = new wxChoice(this, ID_CHOICE5, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
	StaticBoxSizer5->Add(Param2_option_choice, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Param2_option_text = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticBoxSizer5->Add(Param2_option_text, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4->Add(StaticBoxSizer5, 2 , wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer4, 4, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CloseObj = new wxButton(this, ID_BUTTON7, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
	BoxSizer1->Add(CloseObj, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&ConditionSubModule::OnChoice1Select);
	Connect(ID_CHOICE4,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&ConditionSubModule::OnChoice4Select);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ConditionSubModule::OnButtonCloseClick);
		cont_calcx=cont_calc;

			   /*
     Test command parameters:
     param1#i_param1#f_param1#s_param1#param2#i_param2#f_param2#s_param2#operand#i_result#s_result
     */
     int pos1=wxAtoi(prog_param.BeforeFirst('#')); // param1
     wxString pxc=prog_param.AfterFirst('#'); // rest of string
     int i_param1=wxAtoi(pxc.BeforeFirst('#')); // i_param1
     pxc=pxc.AfterFirst('#');
     float f_param1=wxAtof(pxc.BeforeFirst('#')); // float param1
     pxc=pxc.AfterFirst('#');
     wxString s_param1=pxc.BeforeFirst('#'); // string param1
     pxc=pxc.AfterFirst('#');
     int pos2=wxAtoi(pxc.BeforeFirst('#')); //param2
     pxc=pxc.AfterFirst('#');
     int i_param2=wxAtoi(pxc.BeforeFirst('#')); //integer param2
     pxc=pxc.AfterFirst('#');
     float f_param2=wxAtof(pxc.BeforeFirst('#'));  //float param2
      pxc=pxc.AfterFirst('#');
      wxString s_param2=pxc.BeforeFirst('#'); // string param2

       int operand=wxAtoi(pxc.AfterFirst('#')); // math operand


     wxString pxx=_(""); //variable for set text box

	 if((pos1<1)||(pos1>4)||(pos2<1)||(pos2>4))
	 {
	 FillParameters(_("Contour parameter"));
    FillParameters2(_("Contour parameter"));

	 }
	 else
	 {
	     switch (pos1)
	     {
	         case 1:
	         FillParameters(_("Contour parameter"));
	         Param1->SetStringSelection(_("Contour parameter"));
	         Param1_option_choice->SetStringSelection(cont_calcx->ContourNumberToString(i_param1));
	         break;
	         case 2:
	         FillParameters(_("System variable"));
	         Param1->SetStringSelection(_("System variable"));
            pxx=_("Variable_");
	         pxx<<i_param1;
	         Param1_option_choice->SetStringSelection(pxx);
	         break;
	         case 3:
	         FillParameters(_("Temporary variable"));
	         Param1->SetStringSelection(_("Temporary variable"));
	         Param1_op_text->SetValue(s_param1);

	         break;
	         case 4:
	         FillParameters(_("Number"));
	         Param1->SetStringSelection(_("Number"));
	         pxx<<f_param1;
	         Param1_op_text->SetValue(pxx);
	         break;
	     }

	      switch (pos2)
	     {
	         case 1:
	         FillParameters2(_("Contour parameter"));
	         Parameter2->SetStringSelection(_("Contour parameter"));
	         Param2_option_choice->SetStringSelection(cont_calcx->ContourNumberToString(i_param2));
	         break;
	         case 2:
	         FillParameters2(_("System variable"));
	         Parameter2->SetStringSelection(_("System variable"));
            pxx=_("Variable_");
	         pxx<<i_param2;
	         Param2_option_choice->SetStringSelection(pxx);
	         break;
	         case 3:
	         FillParameters2(_("Temporary variable"));
	         Parameter2->SetStringSelection(_("Temporary variable"));
	         Param2_option_text->SetValue(s_param2);
	         break;
	         case 4:
	         FillParameters2(_("Number"));
	         Parameter2->SetStringSelection(_("Number"));
	         pxx=_("");
	         pxx<<f_param2;
	         Param2_option_text->SetValue(pxx);
	         break;
	     }
	     Compar_option->SetSelection(operand-1); //set operand


	 }
}

ConditionSubModule::~ConditionSubModule()
{
	//(*Destroy(ConditionSubModule)
	//*)
}

void ConditionSubModule::OnButtonCloseClick(wxCommandEvent& event)
{
 Close();
}

void ConditionSubModule::OnChoice1Select(wxCommandEvent& event)
{
  FillParameters(Param1->GetStringSelection());

}

void ConditionSubModule::OnChoice4Select(wxCommandEvent& event)
{
  FillParameters2(Parameter2->GetStringSelection());

}

/*
Function fill Parameter 1 options
*/
void ConditionSubModule::FillParameters(wxString param)
{
 if(param==_("Contour parameter"))
 {
     Param1_option_choice->Enable(true);
     Param1_op_text->Enable(false);
     Param1_option_choice->Clear();
     Param1_option_choice->SetSelection(Param1_option_choice->Append(cont_calcx->ContourNumberToString(1)));
     for(int i=2;i<53;i++) Param1_option_choice->Append(cont_calcx->ContourNumberToString(i));
 }
 else if(param==_("System variable"))
 {
     wxString pom=_("");
      Param1_option_choice->Enable(true);
       Param1_op_text->Enable(false);
       Param1_option_choice->Clear();
     Param1_option_choice->SetSelection(Param1_option_choice->Append(_("Variable_0")));
     for(int i=1;i<100;i++)
     {
       pom.Printf(_("Variable_%d"),i);
       Param1_option_choice->Append(pom);
     }
 }
 else
 {
     Param1_option_choice->Enable(false);
       Param1_op_text->Enable(true);
 }
}

/*
Function fill Parameter 2 options
*/
void ConditionSubModule::FillParameters2(wxString param)
{
 if(param==_("Contour parameter"))
 {
     Param2_option_choice->Enable(true);
     Param2_option_text->Enable(false);
     Param2_option_choice->Clear();
     Param2_option_choice->SetSelection(Param2_option_choice->Append(cont_calcx->ContourNumberToString(1)));
     for(int i=2;i<53;i++) Param2_option_choice->Append(cont_calcx->ContourNumberToString(i));
 }
 else if(param==_("System variable"))
 {
     wxString pom=_("");
      Param2_option_choice->Enable(true);
       Param2_option_text->Enable(false);
       Param2_option_choice->Clear();
     Param2_option_choice->SetSelection(Param2_option_choice->Append(_("Variable_0")));
     for(int i=1;i<100;i++)
     {
       pom.Printf(_("Variable_%d"),i);
       Param2_option_choice->Append(pom);
     }
 }
 else
 {
     Param2_option_choice->Enable(false);
       Param2_option_text->Enable(true);
 }
}

/*
Function return test program string
*/
wxString ConditionSubModule::GetCommandParameter(void)
{
       /*
     Test command parameters:
     type of command#param1#i_param1#f_param1#s_param1#param2#i_param2#f_param2#s_param2#operand#i_result#s_result
     */
int pos=Param1->GetSelection()+1; //param1 type of parameter 1
int i_param1=0;
float f_param1=0;
wxString s_param1=_(" ");
wxString px=_("");

switch (pos)
{
    case 1:
     i_param1=cont_calcx->ContourStringToNumber(Param1_option_choice->GetStringSelection());
    break;
    case 2:
   px=Param1_option_choice->GetStringSelection();
     i_param1=wxAtoi(px.AfterFirst('_'));
    break;
   case 3:
    s_param1=Param1_op_text->GetValue();
    if(s_param1.Find('#')!=wxNOT_FOUND)
    {
        wxMessageBox(_("Temporary variable can not have  character #, Condition is not stored"),_("Error"),wxICON_ERROR);
        return _("Error");
    }
    break;
   case 4:
    f_param1=wxAtof(Param1_op_text->GetValue());
     break;
}

int pos2=Parameter2->GetSelection()+1;
int i_param2=0;
float f_param2=0;
wxString s_param2=_(" ");

switch (pos2)
{
    case 1:
     i_param2=cont_calcx->ContourStringToNumber(Param2_option_choice->GetStringSelection());
    break;
    case 2:
   px=Param2_option_choice->GetStringSelection();
     i_param2=wxAtoi(px.AfterFirst('_'));
    break;
   case 3:
    s_param2=Param2_option_text->GetValue();
      if(s_param2.Find('#')!=wxNOT_FOUND)
    {
        wxMessageBox(_("Temporary variable can not have  character #, Condition is not stored"),_("Error"),wxICON_ERROR,this);
        return _("Error");
    }
    break;
   case 4:
    f_param2=wxAtof(Param2_option_text->GetValue());
     break;
}

int operand=Compar_option->GetSelection()+1;


   /*
     Test command parameters:
     type of command#param1#i_param1#f_param1#s_param1#param2#i_param2#f_param2#s_param2#operand#i_result#s_result
     */
wxString ret_val=_("CONDITION#");
ret_val<<pos;
ret_val+=_("#");
ret_val<<i_param1;
ret_val+=_("#");
ret_val<<f_param1;
ret_val+=_("#");
ret_val+=s_param1;
ret_val+=_("#");
ret_val<<pos2;
ret_val+=_("#");
ret_val<<i_param2;
ret_val+=_("#");
ret_val<<f_param2;
ret_val+=_("#");
ret_val+=s_param2;
ret_val+=_("#");
ret_val<<operand;




return ret_val;
}

/*********************************************************************************************
End Class ConditionSubModule
*********************************************************************************************/

/************************************************************************************************
     Contour debug class
Window displays debug information for selected object. User can debug test program for selected object.

Input parameters:
- parent: parent window
- cont_calc: pointer for ContourCalculation class
- syst_var: array of system variables
- object_name: Name of object which will be edited
************************************************************************************************/

ContourDebug::ContourDebug(wxWindow* parent,ContourCalculation *cont_calc,float *syst_var,wxString object_name,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ContourDebug)
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer7;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer6;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer5;

	wxString mx= _("Contour test program debug window, Object name: ");
	mx<<object_name;

	Create(parent, wxID_ANY,mx , wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	Contour = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(101,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Contour->SetToolTip(_("Select contour"));
	Contour->SetHelpText(_("Select contour"));
	BoxSizer3->Add(Contour, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Start = new wxButton(this, ID_BUTTON1, _("Start/Stop"), wxDefaultPosition, wxSize(86,27), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Start->SetToolTip(_("Start or stop program debug"));
	Start->SetHelpText(_("Start or stop program debug"));
	BoxSizer3->Add(Start, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Break = new wxButton(this, ID_BUTTON2, _("Break"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Break->SetToolTip(_("Set or reset break on selected line"));
	Break->SetHelpText(_("Set or reset break on selected line"));
	BoxSizer3->Add(Break, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Continue = new wxButton(this, ID_BUTTON3, _("Continue"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Continue->Disable();
	Continue->SetToolTip(_("Continue on program after break stop"));
	Continue->SetHelpText(_("Continue on program after break stop"));
	BoxSizer3->Add(Continue, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Step = new wxButton(this, ID_BUTTON4, _("Step"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Step->Disable();
	Step->SetToolTip(_("Run one test program line where cursor is."));
	Step->SetHelpText(_("Run one test program line where cursor is."));
	BoxSizer3->Add(Step, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Total result"));
	TotalResult = new wxStaticText(this, ID_STATICTEXT1, _("False"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	TotalResult->SetForegroundColour(wxColour(238,19,11));
	wxFont TotalResultFont(12,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	TotalResult->SetFont(TotalResultFont);
	StaticBoxSizer5->Add(TotalResult, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Bracket result"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT2, _("Not used"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText1->SetForegroundColour(wxColour(234,9,9));
	wxFont StaticText1Font(12,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticBoxSizer6->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Variable watch"));
	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	wxString __wxRadioBoxChoices_1[3] =
	{
		_("Contour param"),
		_("System variable"),
		_("Temp variable")
	};
	RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, _("Option"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, wxRA_HORIZONTAL, wxDefaultValidator, _T("ID_RADIOBOX1"));
	RadioBox1->SetToolTip(_("Select which type of variable you want to watch"));
	RadioBox1->SetHelpText(_("Select which type of variable you want to watch"));
	BoxSizer6->Add(RadioBox1, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, wxVSCROLL|wxHSCROLL, wxDefaultValidator, _T("ID_LISTBOX1"));
	wxFont ListBox1Font(8,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	ListBox1->SetFont(ListBox1Font);
	ListBox1->SetToolTip(_("Choose variable (Left double click)\nActual value of selected variable will be displayed in Value box."));
	ListBox1->SetHelpText(_("Choose variable (Left double click)\nActual value of selected variable will be displayed in Value box."));
	BoxSizer6->Add(ListBox1, 3, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer5->Add(BoxSizer6, 4, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Value"));
	VariableVal = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticBoxSizer4->Add(VariableVal, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5->Add(StaticBoxSizer4, 3, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3->Add(BoxSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer2->Add(StaticBoxSizer3, 3, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 3, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Status"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT3, _("Not started"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText2->SetForegroundColour(wxColour(4,0,255));
	wxFont StaticText2Font(12,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	StaticBoxSizer7->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Test program"));
	Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxSize(290,32), 0, _T("ID_GRID1"));
	Grid1->CreateGrid(0,2);
	Grid1->EnableEditing(false);
	Grid1->EnableGridLines(true);
	Grid1->SetDefaultColSize(150, true);
	Grid1->SetColLabelValue(0, _("Command"));
	Grid1->SetColLabelValue(1, _("Description"));
	Grid1->SetDefaultCellFont( Grid1->GetFont() );
	Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
	StaticBoxSizer2->Add(Grid1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer2, 3, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Command"));
	CommandWindow = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(586,27), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer1->Add(CommandWindow, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ContourDebug::OnStartClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ContourDebug::OnBreakClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ContourDebug::OnContinueClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ContourDebug::OnStepClick);
	Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&ContourDebug::OnRadioBox1Select);
	Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&ContourDebug::OnListBox1DClick);
	//*)

     Grid1->SetColSize(0,150);
     Grid1->SetColSize(1,390);

     cont=cont_calc;

     int px=cont->FindObjectName(object_name);
     object_pos=px;

     start_flag=false;

     for(int i=0;i<100;i++)system_var[i]=syst_var[i];

     if(px<0) wxMessageBox(_("Object not found."),_("Object found error"),wxICON_ERROR,this);
     else
     {
       for(int i=0;i<cont->GetNumberOfContours();i++)
       {
           wxString nm=_("Contour ");
           nm<<(i+1);
          Contour->Insert(nm,i);
       }

       deb_par=new DebParam[cont->GetObjectsLines(px)];
       wxString _cmd,_des,_formula;

       for(int i=0;i<cont->GetObjectsLines(px);i++)
       {
           cont->GetObjectCommandLine(px,i+1,_cmd,_des,_formula);
           deb_par[i].cmd=_cmd;
           deb_par[i].desc=_des;
           deb_par[i].line_des=_formula;
           deb_par[i]._xbreak=false;
           Grid1->InsertRows(i,1);
           Grid1->SetCellValue(i,0,_cmd);
           Grid1->SetCellValue(i,1,_des);

       }
       Grid1->SelectRow(0);
       wxString pom=_("Line 1 expresion:  ");
       pom+=deb_par[0].line_des;
       CommandWindow->Clear();
       CommandWindow->WriteText(pom);
       Grid1->SetSelectionMode(wxGrid::wxGridSelectRows);

       DisplayVariables(1);

     }


}

ContourDebug::~ContourDebug()
{
	//(*Destroy(ContourDebug)
	//*)
	delete[] deb_par;
}

/*
User click on button SetBreak
*/
void ContourDebug::OnBreakClick(wxCommandEvent& event)
{

    //int pos=Grid1->GetCursorRow();
   //
   wxArrayInt pm;
   pm=Grid1->GetSelectedRows();
   if(pm.GetCount()>0)
   {
       Grid1->SetGridCursor(pm[0],0);
   }
    int pos=Grid1->GetGridCursorRow();


    if(pos<0) return;

    if(deb_par[pos]._xbreak)
    {
        Grid1->SetCellBackgroundColour(pos,0,wxColor(255,255,255));
        Grid1->SetCellBackgroundColour(pos,1,wxColor(255,255,255));
        deb_par[pos]._xbreak=false;
    }
    else
    {
       Grid1->SetCellBackgroundColour(pos,0,wxColor(255,0,0));
       Grid1->SetCellBackgroundColour(pos,1,wxColor(255,0,0));
        deb_par[pos]._xbreak=true;
    }
  Refresh();
  Update();

}

/*
Function is called when user click on "start button"
Debug program will start and it is stoped on break line
*/
void ContourDebug::OnStartClick(wxCommandEvent& event)
{
    if(!start_flag) start_flag=true;
    else
    {
        if(wxMessageBox(_("Stop debuging program?"),_("Program debug"),wxYES_NO,this)==wxYES)
        {
          start_flag=false;
          Contour->Enable(true);
          Continue->Enable(false);
          Step->Enable(false);
          Break->Enable(true);
          StaticText2->SetLabel(_("Degug was stopped"));
        }

       return;
    }


    int cont_pos=Contour->GetSelection()+1;

    if(cont_pos<1)
    {
        wxMessageBox(_("No contour was selected"),_("Contour selection error"),wxICON_ERROR,this);
        start_flag=false;
    }
    else
    {
        Contour->Enable(false);
        Break->Enable(false);
        Continue->Enable(false);
          Step->Enable(false);

        StaticText2->SetLabel(_("Start debuging program"));
        cont->RestartDebugMode(system_var);
        stoped_line=0;
        int to_line=Grid1->GetNumberRows()+1; // no break found
        bool found_break=false;
        for(int i=0;i<Grid1->GetNumberRows();i++)
        {
         if(!found_break)
         {
             if(deb_par[i]._xbreak)
             {
                 to_line=i+1;
                 found_break=true;
             }
         }
        }

        ProgramExecution(cont_pos,1,to_line);
    }
}

/*
Function is called when user click on button Continue
Programs continues till next break
*/
void ContourDebug::OnContinueClick(wxCommandEvent& event)
{
        int cont_pos=Contour->GetSelection()+1;

        StaticText2->SetLabel(_("Continue debuging program"));

        int to_line=Grid1->GetNumberRows()+1; // no break found
        bool found_break=false;
        for(int i=stoped_line;i<Grid1->GetNumberRows();i++)
        {
         if(!found_break)
         {
             if(deb_par[i]._xbreak)
             {
                 to_line=i+1;
                 found_break=true;
             }
         }
        }

        ProgramExecution(cont_pos,stoped_line,to_line);

}

/*
Function is called when user click on button Step
Program executes one step
*/
void ContourDebug::OnStepClick(wxCommandEvent& event)
{
     int cont_pos=Contour->GetSelection()+1;

        StaticText2->SetLabel(_("Run one step on debuging program"));
          ProgramExecution(cont_pos,stoped_line,stoped_line+1);
}

/*
Function is called when user click on Opton radiobox
User can select type of variables which will be displayed in Listbox1 window
*/
void ContourDebug::OnRadioBox1Select(wxCommandEvent& event)
{
    int pos=RadioBox1->GetSelection();
    DisplayVariables(pos+1);
}

/*
Function is called when user click on some variable in ListBox1
Value of selected variable is displayed in VariableValue line
*/
void ContourDebug::OnListBox1DClick(wxCommandEvent& event)
{
    int pos=RadioBox1->GetSelection();
    wxString selection=ListBox1->GetStringSelection();
    int cont_pos=Contour->GetSelection();
    double val=0;
    float t_val=0;
    int line_numb=Grid1->GetCursorRow()+1;
    wxString namex; //Variable name +value

    namex=selection;
         namex+=_(" : ");

         int s_var=0; //system variable position



    switch(pos)
    {
        case 0: //Contour parameters
         val=cont->GetContourParamValue(cont_pos,object_pos,cont->ContourStringToNumber(selection),line_numb);
         namex<<val;


         break;
        case 1: //System variable
         s_var=wxAtoi(selection.AfterFirst('_'));
         if((s_var<0)||(s_var>99)) namex=_("System variable error");
         else
         {
             val=cont->ReturnSystemVariable(s_var);
             namex<<val;
         }
        break;
        case 2: //Temporary variable
         if(cont->ReadTempVariable(selection,t_val)!=0) namex=_("Error read variable");
         else namex<<t_val;
        break;
        default:
         break;
    }
    VariableVal->Clear();
    VariableVal->WriteText(namex);
}

/*
Function is called when user selected some type of variable in listbox Option.
Input parameter: type: type of variables 1:Contour parameters, 2:System variable, 3:Temporary variable

*/
int ContourDebug::DisplayVariables(int type)
{

  wxArrayString arr;
  wxString px;

   arr.Clear();

     switch (type)
     {
         case 1:  //Contour parameters
            for(int i=1;i<53;i++) arr.Add(cont->ContourNumberToString(i));
          break;
         case 2:  //System variable
            for(int i=0;i<100;i++)
            {
              px=_("Variable_");
              px<<i;
              arr.Add(px);
            }
          break;
         case 3: //Temporary variable
          for(int i=0;i<cont->ReturnTempVarNumber();i++)arr.Add(cont->ReturnTempVarName(i));
         break;
     }

     ListBox1->Clear();
     ListBox1->InsertItems(arr,0);

    return 0;
}

/*
Function after each break and it is displayed actual (or bracket) status
*/
void ContourDebug::DisplayConditionStatus(void)
{
 if(cont->ReturnActualConditionStatus())
 {
     TotalResult->SetLabel(_("TRUE"));
     TotalResult->SetForegroundColour(wxColour(4,255,0));
 }
 else
 {
       TotalResult->SetLabel(_("FALSE"));
     TotalResult->SetForegroundColour(wxColour(255,0,0));
 }

 int st=cont->ReturnBracketConditionStatus();
 if(st==-1)
 {
    StaticText1->SetLabel(_("Not used"));
     StaticText1->SetForegroundColour(wxColour(0,0,255));
 }
 else if(st==0)
 {
    StaticText1->SetLabel(_("FALSE"));
     StaticText1->SetForegroundColour(wxColour(255,0,0));
 }
 else
 {
   StaticText1->SetLabel(_("TRUE"));
     StaticText1->SetForegroundColour(wxColour(0,255,0));
 }

}

/*
Function executes debug progma
Input parameters: cont_numb : COntour number
                  from_line : Start line (Program start executes from this line)
                  to_line: End line ( Program stops executes to this line
Function returns: 0 if all is OK
                  -1 if there is error in RunDebugFunction
*/
int ContourDebug::ProgramExecution(int cont_numb,int from_line,int to_line)
{


int ret=cont->RunDebugProgram(cont_numb,from_line,to_line,object_pos);
if(ret<0)
{
    wxMessageBox(_("Error in debug program\n Debug finished"),_("Debug error"),wxICON_ERROR);
    start_flag=false;
    StaticText2->SetLabel(_("Debug error"));
    return -1;
}
else
{
    if(to_line==(Grid1->GetNumberRows()+1))
    {
       StaticText2->SetLabel(_("Debug finished"));
        start_flag=false;
          Contour->Enable(true);
          Continue->Enable(false);
          Step->Enable(false);
          Break->Enable(true);
          DisplayConditionStatus();
    }
    else
    {
       wxString lab=_("Program stoped on line: ");
    lab<<to_line;
     StaticText2->SetLabel(lab);
     Grid1->SelectRow(to_line-1);

   Grid1->Scroll(0,to_line-1);
   stoped_line=to_line;
   Continue->Enable(true);
          Step->Enable(true);
          wxString pom=_("Line ");
          pom<<stoped_line;
          pom+=_(" expresion:  ");
       pom+=deb_par[stoped_line-1].line_des;
       CommandWindow->Clear();
       CommandWindow->WriteText(pom);
       DisplayConditionStatus();
    }

}

    return 0;
}

/*****************************************************
End ContourDebug class
*****************************************************/
/***************************************************
Class ObjectList
Class for display all found objects with its parameters
Input parameters: parent : parent window
                  obj_numb : Number of found objects
                  ob : Pointer for OBJECTFOUND structure
                  id: window id
*****************************************************/

ObjectList::ObjectList(wxWindow* parent,int obj_numb,OBJECTFOUND *ob,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ObjectList)
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer7;
	wxStaticBoxSizer* StaticBoxSizer8;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer6;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer5;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("List of objects"));
	ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(161,173), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
	StaticBoxSizer1->Add(ListBox1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Bounding rect"));
	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("X"));
	Bound_x = new wxStaticText(this, ID_STATICTEXT1, _("00000"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticBoxSizer3->Add(Bound_x, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Y"));
	Bound_y = new wxStaticText(this, ID_STATICTEXT2, _("00000"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticBoxSizer4->Add(Bound_y, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Height"));
	Bound_h = new wxStaticText(this, ID_STATICTEXT3, _("00000"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticBoxSizer5->Add(Bound_h, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6->Add(StaticBoxSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Width"));
	Bound_w = new wxStaticText(this, ID_STATICTEXT4, _("00000"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticBoxSizer6->Add(Bound_w, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6->Add(StaticBoxSizer6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer2, 3, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Perimeter"));
	Perim = new wxStaticText(this, ID_STATICTEXT5, _("0000.00"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticBoxSizer7->Add(Perim, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer8 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Contour area"));
	Cont_a = new wxStaticText(this, ID_STATICTEXT6, _("0000.00"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticBoxSizer8->Add(Cont_a, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 5, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Show_object = new wxButton(this, ID_BUTTON1, _("Show object"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Show_object->Disable();
	BoxSizer3->Add(Show_object, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Exit = new wxButton(this, ID_BUTTON2, _("Exit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Exit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&ObjectList::OnListBox1Select);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ObjectList::OnShow_objectClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ObjectList::OnExitClick);
	//*)

	num_obj=obj_numb;

	if(num_obj<1) wxMessageBox(_("No object found"),_("Object display error"),wxICON_ERROR,this);
	else
	{
	    ob_fnd=new OBJECTFOUND[num_obj];
	    wxArrayString arr;
        arr.Clear();

        for(int i=0;i<num_obj;i++)
        {
            ob_fnd[i].object_name=ob[i].object_name;
            ob_fnd[i].bounding_rect_height=ob[i].bounding_rect_height;
            ob_fnd[i].bounding_rect_width=ob[i].bounding_rect_width;
            ob_fnd[i].bounding_rect_x=ob[i].bounding_rect_x;
            ob_fnd[i].bounding_rect_y=ob[i].bounding_rect_y;
            ob_fnd[i].contour_area=ob[i].contour_area;
            ob_fnd[i].perimeter=ob[i].perimeter;
            arr.Add(ob_fnd[i].object_name);
        }
        ListBox1->Clear();
        ListBox1->InsertItems(arr,0);
        ListBox1->SetSelection(0);
      wxString px=_("");
        px<<ob_fnd[0].bounding_rect_height;
        Bound_h->SetLabel(px);
        px=_("");
        px<<ob_fnd[0].bounding_rect_width;
        Bound_w->SetLabel(px);
        px=_("");
        px<<ob_fnd[0].bounding_rect_x;
        Bound_x->SetLabel(px);
        px=_("");
        px<<ob_fnd[0].bounding_rect_y;
        Bound_y->SetLabel(px);
        px=_("");
        px<<ob_fnd[0].contour_area;
        Cont_a->SetLabel(px);
        px=_("");
        px<<ob_fnd[0].perimeter;
        Perim->SetLabel(px);
        Show_object->Enable(true);

	}


}

ObjectList::~ObjectList()
{
	//(*Destroy(ObjectList)
	//*)
	delete []ob_fnd;
}

/*
Function is called when user click on Show object button
Function close dialog and display selected object
*/
void ObjectList::OnShow_objectClick(wxCommandEvent& event)
{
    int ret=ListBox1->GetCount();
    if(ret>0)EndModal(ListBox1->GetSelection());
    else EndModal(-2);
}

void ObjectList::OnExitClick(wxCommandEvent& event)
{
    EndModal(-1);
}

/*
Function is called when user select som item in list box
*/
void ObjectList::OnListBox1Select(wxCommandEvent& event)
{
    int i=ListBox1->GetSelection();
    if(i<0)
    {
        wxMessageBox(_("Selection less than 0"),_("List box selection error"),wxICON_ERROR,this);
        return;
    }
    if(i>=num_obj)
    {
        wxMessageBox(_("Selection more than maximal object number"),_("List box selection error"),wxICON_ERROR,this);
        return;
    }

  wxString px=_("");
        px<<ob_fnd[i].bounding_rect_height;
        Bound_h->SetLabel(px);
        px=_("");
        px<<ob_fnd[i].bounding_rect_width;
        Bound_w->SetLabel(px);
        px=_("");
        px<<ob_fnd[i].bounding_rect_x;
        Bound_x->SetLabel(px);
        px=_("");
        px<<ob_fnd[i].bounding_rect_y;
        Bound_y->SetLabel(px);
        px=_("");
        px<<ob_fnd[i].contour_area;
        Cont_a->SetLabel(px);
        px=_("");
        px<<ob_fnd[i].perimeter;
        Perim->SetLabel(px);
}
/************************************************************
End ObjectList class
*************************************************************/
/********************************************************
Object Setup class
Class displayed window where user can setup basic parameter on Contour Description window
**********************************************************/

ObjectSetup::ObjectSetup(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ObjectSetup)
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer12;
	wxStaticBoxSizer* StaticBoxSizer14;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer9;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer7;
	wxStaticBoxSizer* StaticBoxSizer13;
	wxStaticBoxSizer* StaticBoxSizer10;
	wxStaticBoxSizer* StaticBoxSizer8;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer6;
	wxStaticBoxSizer* StaticBoxSizer11;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer5;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Object line"));
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Color"));
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("R"));
	Obj_line_col_R = new wxTextCtrl(this, ID_TEXTCTRL2, _("255"), wxDefaultPosition, wxSize(33,27), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticBoxSizer4->Add(Obj_line_col_R, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3->Add(StaticBoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("G"));
	Obj_line_col_G = new wxTextCtrl(this, ID_TEXTCTRL3, _("255"), wxDefaultPosition, wxSize(37,27), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	StaticBoxSizer5->Add(Obj_line_col_G, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3->Add(StaticBoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("B"));
	Obj_line_col_B = new wxTextCtrl(this, ID_TEXTCTRL4, _("255"), wxDefaultPosition, wxSize(35,27), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	StaticBoxSizer7->Add(Obj_line_col_B, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3->Add(StaticBoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Obj_col_change = new wxButton(this, ID_BUTTON1, _("Change"), wxDefaultPosition, wxSize(55,29), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	wxFont Obj_col_changeFont(8,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	Obj_col_change->SetFont(Obj_col_changeFont);
	StaticBoxSizer3->Add(Obj_col_change, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Line thickness"));
	Obj_line_thickness = new wxTextCtrl(this, ID_TEXTCTRL1, _("1"), wxDefaultPosition, wxSize(100,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer6->Add(Obj_line_thickness, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(StaticBoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Update = new wxButton(this, ID_BUTTON2, _("Update"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Update, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Exit = new wxButton(this, ID_BUTTON3, _("Exit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer2->Add(Exit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("Object name"));
	StaticBoxSizer8 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Color"));
	StaticBoxSizer9 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("R"));
	Obj_name_col_R = new wxTextCtrl(this, ID_TEXTCTRL5, _("255"), wxDefaultPosition, wxSize(36,27), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	StaticBoxSizer9->Add(Obj_name_col_R, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer8->Add(StaticBoxSizer9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer10 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("G"));
	Obj_name_col_G = new wxTextCtrl(this, ID_TEXTCTRL6, _("255"), wxDefaultPosition, wxSize(35,27), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	StaticBoxSizer10->Add(Obj_name_col_G, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer8->Add(StaticBoxSizer10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer11 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("B"));
	Obj_name_col_B = new wxTextCtrl(this, ID_TEXTCTRL7, _("255"), wxDefaultPosition, wxSize(39,27), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	StaticBoxSizer11->Add(Obj_name_col_B, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer8->Add(StaticBoxSizer11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Obj_name_change = new wxButton(this, ID_BUTTON4, _("Change"), wxDefaultPosition, wxSize(59,29), 0, wxDefaultValidator, _T("ID_BUTTON4"));
	wxFont Obj_name_changeFont(8,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	Obj_name_change->SetFont(Obj_name_changeFont);
	StaticBoxSizer8->Add(Obj_name_change, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(StaticBoxSizer8, 2, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer12 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Font Hershey"));
	Font_sel = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(103,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Font_sel->SetSelection( Font_sel->Append(_("SIMPLEX")) );
	Font_sel->Append(_("PLAIN "));
	Font_sel->Append(_("DUPLEX"));
	Font_sel->Append(_("COMPLEX\t"));
	Font_sel->Append(_("TRIPLEX"));
	Font_sel->Append(_("COMPLEX_SMALL"));
	Font_sel->Append(_("SCRIPT_SIMPLEX "));
	Font_sel->Append(_("SCRIPT_COMPLEX "));
	StaticBoxSizer12->Add(Font_sel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(StaticBoxSizer12, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	wxString __wxRadioBoxChoices_1[2] =
	{
		_("1"),
		_("0.5")
	};
	H_scale = new wxRadioBox(this, ID_RADIOBOX1, _("H scale"), wxDefaultPosition, wxSize(67,70), 2, __wxRadioBoxChoices_1, 1, wxRA_HORIZONTAL, wxDefaultValidator, _T("ID_RADIOBOX1"));
	H_scale->SetSelection(0);
	BoxSizer3->Add(H_scale, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	wxString __wxRadioBoxChoices_2[2] =
	{
		_("1"),
		_("0.5")
	};
	V_scale = new wxRadioBox(this, ID_RADIOBOX2, _("V scale"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_2, 1, wxRA_HORIZONTAL, wxDefaultValidator, _T("ID_RADIOBOX2"));
	BoxSizer3->Add(V_scale, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer3, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer13 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Line thickness"));
	Obj_name_line_thickness = new wxTextCtrl(this, ID_TEXTCTRL8, _("1"), wxDefaultPosition, wxSize(87,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	StaticBoxSizer13->Add(Obj_name_line_thickness, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer14 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Line type"));
	Linetype = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxSize(125,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	Linetype->SetSelection( Linetype->Append(_("8-connected")) );
	Linetype->Append(_("4-connected"));
	Linetype->Append(_("Antialias"));
	StaticBoxSizer14->Add(Linetype, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(BoxSizer4, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ObjectSetup::OnObj_col_changeClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ObjectSetup::OnUpdateClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ObjectSetup::OnExitClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ObjectSetup::OnObj_name_changeClick);
	//*)

   H_scale->Enable(false);
   Linetype->Enable(false);

	wxConfig cfg_data(_("ELI"));
    wxString r_data;

    cfg_data.Read(_("CONTOURWINDOW_OBJECTLINE_COL"),&r_data);

    wxColour pok(0,0,0);

    if(r_data.Length()>1)
    {
     pok.Set(r_data);
    }



    Obj_line_col_R->Clear();
    Obj_line_col_G->Clear();
    Obj_line_col_B->Clear();

    Obj_name_col_R->Clear();
    Obj_name_col_G->Clear();
    Obj_name_col_B->Clear();


    wxString pm=_("");

    pm<<(int)pok.Red();
    Obj_line_col_R->WriteText(pm);


    pm=_("");
    pm<<(int)pok.Green();
    Obj_line_col_G->WriteText(pm);

    pm=_("");
    pm<<(int)pok.Blue();
    Obj_line_col_B->WriteText(pm);

    r_data=_("");

    cfg_data.Read(_("CONTOURWINDOW_OBJECTNAME_COL"),&r_data);

    if(r_data.Length()>1)
    {
     pok.Set(r_data);
    }

    pm=_("");
    pm<<(int)pok.Red();
    Obj_name_col_R->WriteText(pm);

    pm=_("");
    pm<<(int)pok.Green();
    Obj_name_col_G->WriteText(pm);

    pm=_("");
    pm<<(int)pok.Blue();
    Obj_name_col_B->WriteText(pm);

    r_data=_("");

    Obj_line_thickness->Clear();



    cfg_data.Read(_("CONTOURWINDOW_OBJECTLINE_THICKNESS"),&r_data);
     if(r_data.Length()>0) Obj_line_thickness->WriteText(r_data);

     r_data=_("");

    cfg_data.Read(_("CONTOURWINDOW_OBJECTNAME_FONT"),&r_data);
    if(r_data.Length()>0) Font_sel->SetSelection(wxAtoi(r_data));

    r_data=_("");

    cfg_data.Read(_("CONTOURWINDOW_OBJECTNAME_HSCALE"),&r_data);
    if(r_data.Length()>0) H_scale->SetSelection(wxAtoi(r_data));

    r_data=_("");

    cfg_data.Read(_("CONTOURWINDOW_OBJECTNAME_VSCALE"),&r_data);
     if(r_data.Length()>0) V_scale->SetSelection(wxAtoi(r_data));

     r_data=_("");

    Obj_name_line_thickness->Clear();
    cfg_data.Read(_("CONTOURWINDOW_OBJECTNAME_LINETHIC"),&r_data);
     if(r_data.Length()>0) Obj_name_line_thickness->WriteText(r_data);

     r_data=_("");

    cfg_data.Read(_("CONTOURWINDOW_OBJECTNAME_LINETYPE"),&r_data);
     if(r_data.Length()>0) Linetype->SetSelection(wxAtoi(r_data));
}

ObjectSetup::~ObjectSetup()
{
	//(*Destroy(ObjectSetup)
	//*)
}

/*
Function is called when user clicks on Change object colour button
*/
void ObjectSetup::OnObj_col_changeClick(wxCommandEvent& event)
{
    wxConfig cfg_data(_("ELI"));

    wxString r_data;

    cfg_data.Read(_("CONTOURWINDOW_OBJECTLINE_COL"),&r_data);

    wxColour pok(0,0,0);
    wxColourData data;
    if(r_data.Length()>1)
    {
     pok.Set(r_data);
    }
      data.SetColour(pok);


    wxColourDialog dlg(this,&data);
    dlg.ShowModal();
     data=dlg.GetColourData();
    wxColour clr=data.GetColour();
    wxString str_clr=clr.GetAsString();

    Obj_line_col_R->Clear();
    Obj_line_col_G->Clear();
    Obj_line_col_B->Clear();

    wxString pm=_("");
    pm<<(int)clr.Red();
    Obj_line_col_R->WriteText(pm);

    pm=_("");
    pm<<(int)clr.Green();
    Obj_line_col_G->WriteText(pm);

    pm=_("");
    pm<<(int)clr.Blue();
    Obj_line_col_B->WriteText(pm);


  cfg_data.Write(_("CONTOURWINDOW_OBJECTLINE_COL"),str_clr);

}
/*
Function is called when user clicks on Change object name colour button
*/
void ObjectSetup::OnObj_name_changeClick(wxCommandEvent& event)
{
      wxConfig cfg_data(_("ELI"));

    wxString r_data;

    cfg_data.Read(_("CONTOURWINDOW_OBJECTNAME_COL"),&r_data);

    wxColour pok(0,0,0);
    wxColourData data;
    if(r_data.Length()>1)
    {
     pok.Set(r_data);
    }
      data.SetColour(pok);


    wxColourDialog dlg(this,&data);

    dlg.ShowModal();
     data=dlg.GetColourData();

     wxColour clr(0,0,0);
    clr=data.GetColour();

    wxString str_clr=clr.GetAsString();


    Obj_name_col_R->Clear();
    Obj_name_col_G->Clear();
    Obj_name_col_B->Clear();

    wxString pm=_("");
    pm<<(int)clr.Red();

    Obj_name_col_R->WriteText(pm);

   pm=_("");
    pm<<(int)clr.Green();
    Obj_name_col_G->WriteText(pm);

    pm=_("");
    pm<<(int)clr.Blue();
    Obj_name_col_B->WriteText(pm);


  cfg_data.Write(_("CONTOURWINDOW_OBJECTNAME_COL"),str_clr);
}

/*
Function is called when user clicks on UpdateButton
*/
void ObjectSetup::OnUpdateClick(wxCommandEvent& event)
{
   wxConfig cfg_data(_("ELI"));

   if(wxMessageBox(_("Update all parameters?"),_("Update parameters"),wxICON_QUESTION | wxYES_NO,this)==wxYES)
   {
       wxString pm=_("");
       pm=Obj_line_thickness->GetValue();
        cfg_data.Write(_("CONTOURWINDOW_OBJECTLINE_THICKNESS"),pm);

        pm=_("");
        pm<<Font_sel->GetSelection();
        cfg_data.Write(_("CONTOURWINDOW_OBJECTNAME_FONT"),pm);

        pm=_("");
        pm<<H_scale->GetSelection();
        cfg_data.Write(_("CONTOURWINDOW_OBJECTNAME_HSCALE"),pm);

        pm=_("");
        pm<<V_scale->GetSelection();
        cfg_data.Write(_("CONTOURWINDOW_OBJECTNAME_VSCALE"),pm);

        pm=_("");
        pm=Obj_name_line_thickness->GetValue();
        cfg_data.Write(_("CONTOURWINDOW_OBJECTNAME_LINETHIC"),pm);

        pm=_("");
        pm<<Linetype->GetSelection();
        cfg_data.Write(_("CONTOURWINDOW_OBJECTNAME_LINETYPE"),pm);
   }
}

/*
Function is called when user clicks on Exit button
*/
void ObjectSetup::OnExitClick(wxCommandEvent& event)
{
    EndModal(1);
}

/*************************************************************
End ObjectSetup class
*************************************************************/
