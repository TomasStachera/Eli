#include "ContourDescript.h"

//(*InternalHeaders(ContourDescript)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

#include <wx/dc.h>
#include <wx/dcclient.h>
#include <wx/msgdlg.h>
#include <wx/settings.h>
#include <wx/config.h>
#include <wx/filefn.h>
#include <wx/filename.h>
#include <wx/stdpaths.h>
//#include "contourDMain.h"
#include "ContourDescript.h"
#include "ContourDescript2.h"
#include "ContourDescript4.h"
#include "ExportParam.h"



//(*IdInit(ContourDescript)
const long ContourDescript::ID_PANEL1 = wxNewId();
const long ContourDescript::ID_CHECKLISTBOX1 = wxNewId();
const long ContourDescript::ID_BUTTON1 = wxNewId();
const long ContourDescript::ID_BUTTON2 = wxNewId();
const long ContourDescript::ID_TEXTCTRL1 = wxNewId();
const long ContourDescript::ID_TEXTCTRL2 = wxNewId();
const long ContourDescript::idQuit = wxNewId();
const long ContourDescript::idSave = wxNewId();
const long ContourDescript::idRead = wxNewId();
const long ContourDescript::idFilter = wxNewId();
const long ContourDescript::idRunFilter = wxNewId();
const long ContourDescript::idFilterClear = wxNewId();
const long ContourDescript::idObjectMod = wxNewId();
const long ContourDescript::idRunObject = wxNewId();
const long ContourDescript::ListObject = wxNewId();
//const long ContourDescript::idVariablesDispl = wxNewId();
const long ContourDescript::idClearDispObj = wxNewId();
const long ContourDescript::idSetupObj = wxNewId();
const long ContourDescript::idHelp = wxNewId();
const long ContourDescript::ID_TOOLBAR1 = wxNewId();


//*)
const long ContourDescript::ID_BUTTON3 = wxNewId();


BEGIN_EVENT_TABLE(ContourDescript,wxFrame)
	//(*EventTable(ContourDescript)
	//*)
	EVT_MOUSE_EVENTS(ContourDescript::OnMouseEvent)
END_EVENT_TABLE()

/*
Class for displayed panel for editing
Input parameters:
  - parent: parent window
  - id: window id
  - pos: position of window
  - size : size of window
  - pd: PDAT structure
  - obprg : ObjectPrograms structure with opened object programs
  - numbobj : Object block number ( It can be from range 1-20)
*/

ContourDescript::ContourDescript(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size,PDAT *pd,ObjectPrograms *obprg,int numbobj)
{

wxFileName f(wxStandardPaths::Get().GetExecutablePath());
wxString actual_dir=f.GetPath();

//cvSetErrMode(CV_ErrModeParent);

	//(*Initialize(ContourDescript)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	Create(parent, wxID_ANY, _("Contour description aplication"), wxDefaultPosition, wxSize(1200,750), wxSTAY_ON_TOP|wxSYSTEM_MENU|wxFULL_REPAINT_ON_RESIZE, _T("wxID_ANY"));
	SetBackgroundColour(wxColour(0,0,152));
	{
		wxIcon FrameIcon;
		FrameIcon.CopyFromBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_INFORMATION")),wxART_FRAME_ICON));
		SetIcon(FrameIcon);
	}
   BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL|wxFULL_REPAINT_ON_RESIZE, _T("ID_PANEL1"));
	BoxSizer1->Add(Panel1, 5, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	ContourList = new wxCheckListBox(this, ID_CHECKLISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
	BoxSizer3->Add(ContourList, 4, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("All"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer5->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Button2 = new wxButton(this, ID_BUTTON2, _("None"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer5->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	ButtonExp = new wxButton(this, ID_BUTTON3, _("Export"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer5->Add(ButtonExp, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BoxSizer3->Add(BoxSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	ContourInfo = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_AUTO_SCROLL|wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer4->Add(ContourInfo, 4, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	StatTextX = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_NO_VSCROLL|wxTE_MULTILINE|wxFULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer4->Add(StatTextX, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);



	ToolBar1 = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER, _T("ID_TOOLBAR1"));
	ToolBarItem1 = ToolBar1->AddTool(idQuit, _("Quit"), wxBitmap(wxImage(actual_dir+_("/icons/quit.png"))), wxNullBitmap, wxITEM_NORMAL, _("Quit application"), _("Quit application"));
	ToolBarItem2 = ToolBar1->AddTool(idSave, _("Save"),wxBitmap(wxImage(actual_dir+_("/icons/Save.png"))) , wxNullBitmap, wxITEM_NORMAL, _("Save new parameters"), _("Save updated parameters"));
	ToolBarItem3 = ToolBar1->AddTool(idRead, _("Read contours"),wxBitmap(wxImage(actual_dir+_("/icons/show_contours.png"))) , wxNullBitmap, wxITEM_NORMAL, _("Read contours"), _("Read contours"));
	/*ToolBar1->AddSeparator();
	ToolBar1->AddSeparator();
	ToolBar1->AddSeparator();
	ToolBar1->AddSeparator();*/
	ToolBar1->AddSeparator();
	ToolBarItem4 = ToolBar1->AddTool(idFilter, _("Filter window"),wxBitmap(wxImage(actual_dir+_("/icons/display_filter.png")))  , wxNullBitmap, wxITEM_NORMAL, _("Display filter modulle"), _("Display filter modulle"));
	ToolBarItem5 = ToolBar1->AddTool(idRunFilter, _("Run Filter"),wxBitmap(wxImage(actual_dir+_("/icons/run_filter.png"))), wxNullBitmap, wxITEM_NORMAL, _("Run filter module"), _("Run filter module"));
	ToolBarItem6 = ToolBar1->AddTool(idFilterClear, _("Clear filter"),wxBitmap(wxImage(actual_dir+_("/icons/clear_filter.bmp"))) , wxNullBitmap, wxITEM_NORMAL, _("Clear filter"), _("Clear filter"));
	ToolBar1->AddSeparator();
	/*ToolBar1->AddSeparator();
	ToolBar1->AddSeparator();
	ToolBar1->AddSeparator();
	ToolBar1->AddSeparator();*/
	ToolBarItem7 = ToolBar1->AddTool(idObjectMod, _("Object module"),wxBitmap(wxImage(actual_dir+_("/icons/object_module.png")))  , wxNullBitmap, wxITEM_NORMAL, _("Display Obect module window"), _("Display object modulle window"));
	ToolBarItem8 = ToolBar1->AddTool(idRunObject, _("Run Object module"),wxBitmap(wxImage(actual_dir+_("/icons/find_objects.bmp")))  , wxNullBitmap, wxITEM_NORMAL, _("Run object module"), _("Run object module"));
	ToolBarItem9 = ToolBar1->AddTool(ListObject, _("List of object"),wxBitmap(wxImage(actual_dir+_("/icons/object_list.png")))   , wxNullBitmap, wxITEM_CHECK, _("List of all objects"), _("Display list of all objects"));
	//ToolBarItem10 = ToolBar1->AddTool(idVariablesDispl, _("Display variables"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_NORMAL_FILE")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, _("Display variables"), _("Display variables"));
	ToolBarItem11 = ToolBar1->AddTool(idClearDispObj, _("Clear objects"),wxBitmap(wxImage(actual_dir+_("/icons/clear_objects.bmp")))  , wxNullBitmap, wxITEM_NORMAL, _("Clear displayed objets"), _("Clear displayed objects"));
	/*ToolBar1->AddSeparator();
	ToolBar1->AddSeparator();
	ToolBar1->AddSeparator();
	ToolBar1->AddSeparator();*/
	ToolBar1->AddSeparator();
	ToolBarItem12 = ToolBar1->AddTool(idSetupObj, _("Setup"),wxBitmap(wxImage(actual_dir+_("/icons/setup.png")))  , wxNullBitmap, wxITEM_NORMAL, _("Setup displayed window"), _("Setup displayed window"));
	ToolBarItem13 = ToolBar1->AddTool(idHelp, _("Help"),wxBitmap(wxImage(actual_dir+_("/icons/help.bmp"))) , wxNullBitmap, wxITEM_NORMAL, _("DIsplay help window"), _("Display help window"));
	ToolBar1->Realize();
	SetToolBar(ToolBar1);
    // Block for display system variable in the toolbar
isDisplayedImage=false;






	Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ContourDescript::OnPanel1Paint,0,this);
	Connect(ID_CHECKLISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&ContourDescript::OnListBoxSelect);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ContourDescript::Button_SelectAll);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ContourDescript::Button_SelectNone);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ContourDescript::Button_Export);
	Connect(idQuit,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ContourDescript::QuitClick);
	Connect(idSave,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ContourDescript::OnToolBarSaveClicked);
	Connect(idRead,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ContourDescript::OnToolBarRead);
	Connect(idFilter,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ContourDescript::OnToolBarFilterDisplay);
	Connect(idRunFilter,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ContourDescript::OnToolBarRunFilter);
	Connect(idFilterClear,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ContourDescript::OnToolBarClearFIlterClicked);
	Connect(idObjectMod,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ContourDescript::OnObjectModuleClicked);
	Connect(idRunObject,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ContourDescript::OnToolRunObjectModuleClicked);
	Connect(ListObject,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ContourDescript::OnToolBarItem7Clicked);

	Connect(idClearDispObj,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ContourDescript::OnToolBarItem8Clicked);
	Connect(idSetupObj,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ContourDescript::OnToolBarItem9Clicked);
	Connect(idHelp,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&ContourDescript::OnToolBarItemHelpClicked);
	//*)


//Block for enable mouse events

	Panel1->Connect( wxEVT_MOTION, wxMouseEventHandler( ContourDescript::OnMouseEvent ), NULL, this );




// Initialize variables

	all_found_objects=0;
	obj_found=NULL;

	x_ratio=0;
	y_ratio=0;
	x_size=0;
	y_size=0;
	contour_list_number=0;
	cont_list=0;


//Block for set system variable array and display selected immage

	for(int i=0;i<100;i++) syst_variable[i]=pd->fval[i];
	try
	{


	if((pd->ival[0]<0)||(pd->ival[0]>19))wxMessageBox(_("Position in picture array is not from range 0-19"),_("Error"),wxICON_ERROR);
	else
	{


     mainImage=pd->imgx[pd->ival[0]].clone();
    mainImage2=mainImage.clone();
	   // DrawBitmatPic();
	}


//Block for read contour array
	if((pd->ival[1]<0)||(pd->ival[1]>19))
	{
	    wxMessageBox(_("Position in contour array is not from range 0-19"),_("Error"),wxICON_ERROR,this);

	}
	else
	{
   if(pd->contoursx[pd->ival[1]].size()==0)
	  {
	    wxMessageBox(_("No contours was found in selected image"),_("Error"),wxICON_ERROR,this);
        total_contours=0;
	  }
	  else
	  {



	       total_contours=pd->contoursx[pd->ival[1]].size();
	       for(int i=0;i<total_contours;i++)contx.push_back(pd->contoursx[pd->ival[1]][i]);


    wxArrayString contour_array;
     contour_list_number=0;


     cont_list= new CONTOUR_LIST[total_contours];





   for(int i=0;i<total_contours;i++)
     {

         wxString pom=_("Contour ");
         pom<<(i+1);
         contour_array.Add(pom);
         contour_list_number++;

         cont_list[i].list_box_pos=i;

      cont_list[i].bounding_rect=boundingRect(contx[i]);


     }



    ContourList->InsertItems(contour_array,0);


// Measured all contour parameters
  MeasureAllValues();

	  }
	}



//Block for initiate ContourCalculation structure
cont_calc=new  ContourCalculation(contx,obprg,numbobj);

 if(cont_calc->WasOpenCvError()) wxMessageBox(cont_calc->GetStringOpenCvError(),_("OpenCvError"),wxICON_ERROR,this);

   Maximize();

	}



	  catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    wxMessageBox(pv,_("OpenCV error"),wxICON_ERROR,this);

    }
}

ContourDescript::~ContourDescript()
{
	//(*Destroy(ContourDescript)
	//*)
	delete[] cont_list;
	if(obj_found!=NULL) delete[] obj_found;
}


/*
Press Quit button. Close window as modal dialog
*/
void ContourDescript::QuitClick(wxCommandEvent& event)
{
EndModal(0);
}

/*
Function is activated when displayed panel should be repaint
Function convert OpenCv image to wxImage
*/
void ContourDescript::OnPanel1Paint(wxPaintEvent& event)
{

      GenerateDisplPicture(mainImage2);
  DrawBitmatPic();

}

/*
Function paints selected picture to window panel
*/
void ContourDescript::DrawBitmatPic(void)
{

    wxPaintDC dc(Panel1);
    wxBitmap bitmap1;


try
{
     if(isDisplayedImage) // if displayed image is alocated read it and draw in result panel
     {

wxImage wx_tmp;



  wx_tmp=wxImage(displayed_Image.cols,displayed_Image.rows,displayed_Image.data,true);

       bitmap1= wxBitmap(wx_tmp);
        dc.DrawBitmap(bitmap1,1,1);


     }
}


   catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    wxMessageBox(pv,_("OpenCV error"),wxICON_ERROR);

    }
}

/************************************************************
Function transformed displayed image to dimension according actual
window size.
1.input parameter; displayed image
Function return 0: if all is OK
         return -1 if image pointer is not set
*************************************************************/
int ContourDescript::GenerateDisplPicture(Mat img)
{

 try
{
    //if(img==0) return -1; // if image pointer is not set return -1;
   wxSize size=Panel1->GetSize();//Get window dimension
//wxSize  size=GetSize();//Get window dimension
    int width=size.GetWidth(); //calculate maximal posible width in display window
    int heigth=size.GetHeight()-3; //calculate maximal posible height in display window
    int im_width=img.cols; //input image width
    int im_height=img.rows; //input image height

    float ratio_w=(float)width/(float)im_width;
  float ratio_h=(float)heigth/(float)im_height;





  int ra1=(int)(ratio_w*(float)im_height);
  float tot_ratio;

     if(ra1>heigth)tot_ratio=ratio_h;
     else tot_ratio=ratio_w;

     x_ratio=1/tot_ratio;
     y_ratio=1/tot_ratio;


     x_size=width;
     y_size=heigth;




         Mat img_x;
           if (img.type()==CV_8UC1)
           {
               cvtColor(img, img_x, COLOR_GRAY2RGB);

            //displayed_Image=(new_width,new_heigth,img_x.depth(),img_x.channels());
           resize(img_x,displayed_Image,Size(),(double)tot_ratio,(double)tot_ratio,INTER_LINEAR ); // resize final image to new sizes

           }
           else
           {
                    //    displayed_Image=(new_width,new_heigth,img_x.depth(),img_x.channels());
       resize(img,displayed_Image,Size(),tot_ratio,tot_ratio,INTER_LINEAR ); // resize final image to new sizes
           }
 cvtColor(displayed_Image,displayed_Image,COLOR_RGB2BGR);

isDisplayedImage=true;


}
        catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    wxMessageBox(pv,_("OpenCv error"),wxICON_ERROR);
    }

    return 0;
}

/*
Function is activated when user clicks on button Read contours
There are displayed all contours which was selected in list box ContourList
*/
void ContourDescript::OnToolBarRead(wxCommandEvent& event)
{
try
{

 mainImage2=mainImage.clone();
 if(mainImage2.channels()<3)cvtColor(mainImage2,mainImage2,COLOR_GRAY2RGB);


  /* Read setup */
           wxConfig cfg_data(_("ELI"));
           wxString r_data;

            cfg_data.Read(_("CONTOURWINDOW_OBJECTLINE_COL"),&r_data);

          wxColour pok;

          if(r_data.Length()>1) pok.Set(r_data);

          r_data=_("");
         int line_thick=1;
         cfg_data.Read(_("CONTOURWINDOW_OBJECTLINE_THICKNESS"),&r_data);
         if(r_data.Length()>0) line_thick=wxAtoi(r_data);


 for(unsigned int i=0;i<contx.size();i++)
  {
   if(cont_list[i].list_box_pos>=0)// Check if Item is in list check box
   {
     if(ContourList->IsChecked(cont_list[i].list_box_pos)) // Check if contour is checked
        drawContours(mainImage2,contx,i,Scalar(pok.Blue(),pok.Green(),pok.Red()),line_thick);

   }

   }

   Update();
   Refresh();
}



           catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    wxMessageBox(pv,_("OpenCv error"),wxICON_ERROR,this);
    }

}
/*
Function is called when user clicks on button select all contour in list box ContourList
*/
void ContourDescript::Button_SelectAll(wxCommandEvent& event)
{
    for(int i=0;i<contour_list_number;i++) ContourList->Check(i,true);
}
/*
Function is called when user clicks on button Export and function exported all selected contours to file
*/
void ContourDescript::Button_Export(wxCommandEvent& event)
{
    vector<vector<vector<double> > >dvalue;
    /*
    3-dimensional vector of contour paramaeters
    1.dimension: Contour position
    2.dimension: 0=Bounding rect values
                 1=Area+ Perimeter;
                 2=MInimal area rectangle
                 3=MInimal encloasing circle
                 4=Fit elipse
                 5=Central moments
                 6=Normalized central moments
                 7=Spatial moments
                 8=Hu moments
    */
    vector<vector<double> >pom2_dvalue;
    vector<double> pom_dvalue;
    dvalue.clear();
    vector<int>contour_number;
    contour_number.clear();

for(unsigned int i=0;i<contx.size();i++)
  {

   if(cont_list[i].list_box_pos>=0)// Check if Item is in list check box
   {
     if(ContourList->IsChecked(cont_list[i].list_box_pos)) // Check if contour is checked
     {
      pom_dvalue.clear();
      pom2_dvalue.clear();
      contour_number.push_back(i+1);

      //adding bounding rectangle
      pom_dvalue.push_back((double)cont_list[i].bounding_rect.x);
      pom_dvalue.push_back((double)cont_list[i].bounding_rect.y);
      pom_dvalue.push_back((double)cont_list[i].bounding_rect.height);
      pom_dvalue.push_back((double)cont_list[i].bounding_rect.width);
      pom2_dvalue.push_back(pom_dvalue);
      pom_dvalue.clear();
      //adding perimeter+ area
      pom_dvalue.push_back((double)cont_list[i].perimeter);
      pom_dvalue.push_back((double)cont_list[i].contour_area);
      pom2_dvalue.push_back(pom_dvalue);
      pom_dvalue.clear();
      //adding minimal area rectangle
      pom_dvalue.push_back((double)cont_list[i].min_area_rec.center.x);
      pom_dvalue.push_back((double)cont_list[i].min_area_rec.center.y);
      pom_dvalue.push_back((double)cont_list[i].min_area_rec.size.width);
      pom_dvalue.push_back((double)cont_list[i].min_area_rec.size.height);
      pom_dvalue.push_back((double)cont_list[i].min_area_rec.angle);
      pom2_dvalue.push_back(pom_dvalue);
      pom_dvalue.clear();
      //add minimal enclosing circle
      pom_dvalue.push_back((double)cont_list[i].min_enclosing_circle_center.x);
      pom_dvalue.push_back((double)cont_list[i].min_enclosing_circle_center.y);
      pom_dvalue.push_back((double)cont_list[i].min_enclosing_circle_radius);
      pom2_dvalue.push_back(pom_dvalue);
      pom_dvalue.clear();
      //add fit elipse
      pom_dvalue.push_back((double)cont_list[i].fit_elipse.center.x);
      pom_dvalue.push_back((double)cont_list[i].fit_elipse.center.y);
      pom_dvalue.push_back((double)cont_list[i].fit_elipse.size.width);
      pom_dvalue.push_back((double)cont_list[i].fit_elipse.size.height);
      pom_dvalue.push_back((double)cont_list[i].fit_elipse.angle);
      pom2_dvalue.push_back(pom_dvalue);
      pom_dvalue.clear();
      //add central moments
      pom_dvalue.push_back((double)cont_list[i].moments.mu20);
      pom_dvalue.push_back((double)cont_list[i].moments.mu11);
      pom_dvalue.push_back((double)cont_list[i].moments.mu02);
      pom_dvalue.push_back((double)cont_list[i].moments.mu30);
      pom_dvalue.push_back((double)cont_list[i].moments.mu21);
      pom_dvalue.push_back((double)cont_list[i].moments.mu12);
      pom_dvalue.push_back((double)cont_list[i].moments.mu03);
      pom2_dvalue.push_back(pom_dvalue);
      pom_dvalue.clear();
      //add normalized central moments
      pom_dvalue.push_back((double)cont_list[i].moments.nu20);
      pom_dvalue.push_back((double)cont_list[i].moments.nu11);
      pom_dvalue.push_back((double)cont_list[i].moments.nu02);
      pom_dvalue.push_back((double)cont_list[i].moments.nu30);
      pom_dvalue.push_back((double)cont_list[i].moments.nu21);
      pom_dvalue.push_back((double)cont_list[i].moments.nu12);
      pom_dvalue.push_back((double)cont_list[i].moments.nu03);
      pom2_dvalue.push_back(pom_dvalue);
      pom_dvalue.clear();
    //add spatial moments
      pom_dvalue.push_back((double)cont_list[i].moments.m00);
      pom_dvalue.push_back((double)cont_list[i].moments.m10);
      pom_dvalue.push_back((double)cont_list[i].moments.m01);
      pom_dvalue.push_back((double)cont_list[i].moments.m11);
      pom_dvalue.push_back((double)cont_list[i].moments.m20);
      pom_dvalue.push_back((double)cont_list[i].moments.m02);
      pom_dvalue.push_back((double)cont_list[i].moments.m30);
      pom_dvalue.push_back((double)cont_list[i].moments.m21);
      pom_dvalue.push_back((double)cont_list[i].moments.m12);
      pom_dvalue.push_back((double)cont_list[i].moments.m03);
     pom2_dvalue.push_back(pom_dvalue);
      pom_dvalue.clear();
      //add hu moments
       double hu[7];

    HuMoments(cont_list[i].moments,hu);
    pom_dvalue.push_back(hu[0]);
    pom_dvalue.push_back(hu[1]);
    pom_dvalue.push_back(hu[2]);
    pom_dvalue.push_back(hu[3]);
    pom_dvalue.push_back(hu[4]);
    pom_dvalue.push_back(hu[5]);
    pom_dvalue.push_back(hu[6]);
    pom2_dvalue.push_back(pom_dvalue);
    dvalue.push_back(pom2_dvalue);


     }

   }

   }
ExportParam dlg(this,contour_number,dvalue);
dlg.ShowModal();
}

/*
Function is called when user clicks on button select none contour in list box ContourList
*/
void ContourDescript::Button_SelectNone(wxCommandEvent& event)
{
     for(int i=0;i<contour_list_number;i++) ContourList->Check(i,false);
}

/*************************************************
Function is called when user move with mouse
***************************************************/
void ContourDescript::OnMouseEvent(wxMouseEvent &event)
{
wxPoint pt(event.GetPosition());
int *con_num=new int[total_contours];

if(event.Moving())
{

 if((pt.x<=x_size)&&(pt.y<=y_size))
 {
wxString x=_("x: ");
x<<(int)((float)pt.x*x_ratio);
x+=_(" y: ");
x<<(int)((float)pt.y*y_ratio);

int numb=ReturnContourRectPos((int)((float)pt.x*x_ratio),(int)((float)pt.y*y_ratio),con_num);

if(numb>0)
{
    for(int j=0;j<numb;j++)
    {
       wxString pom=_("  Contour ") ;
      pom<< con_num[j] ;
      x+=pom;
    }


}
StatTextX->Clear();
StatTextX->WriteText(x);



 }

}

delete[]con_num;
}

/****************************************************************
Function check if some contours are in the position (x,y), It is check bounding
rect area on each contours
Function return number of found contours ,write contour number to the
pointer val.
*********************************************************************/
int ContourDescript::ReturnContourRectPos(int x,int y,int *val)
{
   int cnt=0;

  for(int i=0;i<total_contours;i++)
  {
    if((x>=cont_list[i].bounding_rect.x)&&(x<=(cont_list[i].bounding_rect.width+cont_list[i].bounding_rect.x)))
    {
        if((y>=cont_list[i].bounding_rect.y)&&(y<=(cont_list[i].bounding_rect.height+cont_list[i].bounding_rect.y)))
        {
            val[cnt]=i+1;
            cnt++;
        }
    }
  }

    return cnt;
}

/*********************************************************
Function measure all values on all contours
***********************************************************/
int ContourDescript::MeasureAllValues(void)
{
    int cont_pos=0; // position of contour for error log
if(cont_list==0) return -1; //contour list structure was not alocated

try
{



     for(int i=0;i<total_contours;i++)
     {
         cont_pos++;
       cont_list[i].perimeter=arcLength(contx[i],true);// Measure contour perimeter
       cont_list[i].contour_area=contourArea(contx[i]); //Measure contour area
       cont_list[i].min_area_rec=minAreaRect(contx[i]); //Measure minimal rect area
     if(contx[i].size()>5)cont_list[i].fit_elipse=fitEllipse(contx[i]); //Measure elipse
      minEnclosingCircle(contx[i],cont_list[i].min_enclosing_circle_center,cont_list[i].min_enclosing_circle_radius);//measure Minimal enclosing circle
        cont_list[i].moments=moments(contx[i]);

     }


}

 	  catch(cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    pv+=_("\nContour number:");
    pv<<cont_pos;
    wxMessageBox(pv,_("OpenCV error "),wxICON_ERROR,this);

    }

    return 0;
}

/*
Function is called when user click on som item in list box with all comtours
All measred contours parameters will be displayed in window Contour info
*/
void ContourDescript::OnListBoxSelect(wxCommandEvent& event)
{
    int pos=event.GetSelection(); //list box index

    int end_loop=0;
    int i=0; // index in list box structure of selected contour
    while(end_loop==0)
    {
     if(cont_list[i].list_box_pos==pos)  end_loop=1;
      else
      {
          i++;
          if(i==total_contours)
          {
              end_loop=1;
              i=-1;
          }
      }
    }

   if(i==-1)
   {
       wxMessageBox(_("Error contour list box selection"),_("Error"),wxICON_ERROR,this);
       return ;
   }

wxString info_message; // message displayed in contour information window

info_message=_("Contour ");
info_message<<(i+1);
info_message+=_("\n\n");
info_message+=_("Bounding rec:\n\tX:\t");
info_message<<cont_list[i].bounding_rect.x;
info_message+=_("\n\tY:\t");
info_message<<cont_list[i].bounding_rect.y;
info_message+=_("\n\tHeight:\t");
info_message<<cont_list[i].bounding_rect.height;
info_message+=_("\n\tWidth:\t");
info_message<<cont_list[i].bounding_rect.width;
info_message+=_("\nPerimeter:\t");
info_message<<cont_list[i].perimeter;
info_message+=_("\nContour area:\t");
info_message<<cont_list[i].contour_area;
info_message+=_("\nMinimal area rec:\n\tCenter:\tX:");
info_message<<(int)cont_list[i].min_area_rec.center.x;
info_message+=_("\n\t\t\tY:");
info_message<<(int)cont_list[i].min_area_rec.center.y;
info_message+=_("\n\tSize: \tWidth:");
info_message<<(int)cont_list[i].min_area_rec.size.width;
info_message+=_("\n\t\t\tHeight:");
info_message<<(int)cont_list[i].min_area_rec.size.height;
info_message+=_("\n\tAngle:");
info_message<<cont_list[i].min_area_rec.angle;
info_message+=_("\nMin enclosing circle:\n");
info_message+=_("\tCenter:\tX:");
info_message<<(int)cont_list[i].min_enclosing_circle_center.x;
info_message+=_("\n\t\t\tY:");
info_message<<(int)cont_list[i].min_enclosing_circle_center.y;
info_message+=_("\n\tRadius:");
info_message<<cont_list[i].min_enclosing_circle_radius;
info_message+=_("\nFit elipse:\n");
info_message+=_("\tCenter:\tX:");
info_message<<(int)cont_list[i].fit_elipse.center.x;
info_message+=_("\n\t\t\tY:");
info_message<<(int)cont_list[i].fit_elipse.center.y;
info_message+=_("\n\tSize: \tWidth:");
info_message<<(int)cont_list[i].fit_elipse.size.width;
info_message+=_("\n\t\t\tHeight:");
info_message<<(int)cont_list[i].fit_elipse.size.height;
info_message+=_("\n\tAngle:");
info_message<<cont_list[i].fit_elipse.angle;

/************************************************************
Central Moments ******************************************************/
info_message+=_("\n\nCentral Moments: (x order,y order)");
info_message+=_("\n\t(2,0):");
info_message<<cont_list[i].moments.mu20;
info_message+=_("\n\t(1,1):");
info_message<<cont_list[i].moments.mu11;
info_message+=_("\n\t(0,2):");
info_message<<cont_list[i].moments.mu02;
info_message+=_("\n\t(3,0):");
info_message<<cont_list[i].moments.mu30;
info_message+=_("\n\t(2,1):");
info_message<<cont_list[i].moments.mu21;
info_message+=_("\n\t(1,2):");
info_message<<cont_list[i].moments.mu12;
info_message+=_("\n\t(0,3):");
info_message<<cont_list[i].moments.mu03;

/************************************************************
Normalized Central Moments ******************************************************/
info_message+=_("\n\nNormalized Central Moments: (x order,y order)");
info_message+=_("\n\t(2,0):");
info_message<<cont_list[i].moments.nu20;
info_message+=_("\n\t(1,1):");
info_message<<cont_list[i].moments.nu11;
info_message+=_("\n\t(0,2):");
info_message<<cont_list[i].moments.nu02;
info_message+=_("\n\t(3,0):");
info_message<<cont_list[i].moments.nu30;
info_message+=_("\n\t(2,1):");
info_message<<cont_list[i].moments.nu21;
info_message+=_("\n\t(1,2):");
info_message<<cont_list[i].moments.nu12;
info_message+=_("\n\t(0,3):");
info_message<<cont_list[i].moments.nu03;


/************************************************************
Spatial Moments ******************************************************/
info_message+=_("\n\nSpatial Moments: (x order,y order)");
info_message+=_("\n\t(0,0):");
info_message<<cont_list[i].moments.m00;
info_message+=_("\n\t(1,0):");
info_message<<cont_list[i].moments.m10;
info_message+=_("\n\t(0,1):");
info_message<<cont_list[i].moments.m01;
info_message+=_("\n\t(1,1):");
info_message<<cont_list[i].moments.m11;
info_message+=_("\n\t(2,0):");
info_message<<cont_list[i].moments.m20;
info_message+=_("\n\t(0,2):");
info_message<<cont_list[i].moments.m02;
info_message+=_("\n\t(3,0):");
info_message<<cont_list[i].moments.m30;
info_message+=_("\n\t(2,1):");
info_message<<cont_list[i].moments.m21;
info_message+=_("\n\t(1,2):");
info_message<<cont_list[i].moments.m12;
info_message+=_("\n\t(0,3):");
info_message<<cont_list[i].moments.m03;

/************************************************************************
Hu moments *************************************************************/

double hu[7];

HuMoments(cont_list[i].moments,hu);
info_message+=_("\n\nHu moments");
info_message+=_("\n\th1:");
info_message<<hu[0];
info_message+=_("\n\th2:");
info_message<<hu[1];
info_message+=_("\n\th3:");
info_message<<hu[2];
info_message+=_("\n\th4:");
info_message<<hu[3];
info_message+=_("\n\th5:");
info_message<<hu[4];
info_message+=_("\n\th6:");
info_message<<hu[5];
info_message+=_("\n\th7:");
info_message<<hu[6];

ContourInfo->Clear();
ContourInfo->WriteText(info_message);

}

/*
Function is called when user click on toolbar display filter. Function displays filter program window
*/
void ContourDescript::OnToolBarFilterDisplay(wxCommandEvent& event)
{
ContourDescript2 dlg(this,wxID_ANY,wxDefaultPosition,wxDefaultSize,syst_variable,cont_calc);
dlg.ShowModal();
}



/*
Function is called when user clicks on toolbar icon RUnFilter.
Function executes Filter algorithm
*/
void ContourDescript::OnToolBarRunFilter(wxCommandEvent& event)
{
    if(cont_calc->FilterAplication()==0)
    {
       if(cont_calc->WasOpenCvError()) wxMessageBox(cont_calc->GetStringOpenCvError(),_("Filter module error"),wxICON_ERROR,this);
       else
       {

           int active_cnt=0;
           wxArrayString contour_array;
           for(int i=0;i<total_contours;i++)
           {

             if(cont_calc->IsContourActive(i))
             {

                 cont_list[i].list_box_pos=active_cnt;
                 active_cnt++;
                   wxString pom=_("Contour ");
                 pom<<(i+1);
                 contour_array.Add(pom);
             }
             else cont_list[i].list_box_pos=-1; //contour is not active
           }
             ContourList->Clear();
             ContourList->InsertItems(contour_array,0);
           wxMessageBox(_("Filter module was executed"),_("Filter module message"),wxICON_INFORMATION,this);
       }
    }
    else wxMessageBox(_("Filter lines number is more than maximal filter lines"),_("Filter modulle error"),wxICON_ERROR,this);
}

/*
Function is called when user click on toolbar button DisplayObjectmodule
Function display object module window
*/
void ContourDescript::OnObjectModuleClicked(wxCommandEvent& event)
{
    object obj(this,cont_calc,syst_variable);
    obj.ShowModal();
}

/*
Function is activated when user click on toolbar icon RunObjectModule
Function executes FinObjectExecution  funtion and display result in to window ContourInfo
*/
void ContourDescript::OnToolRunObjectModuleClicked(wxCommandEvent& event)
{
if(cont_calc->FindObjectExecution(syst_variable)!=0)
{
    wxMessageBox(_("Error in function FindObjectExecution"),_("Error"),wxICON_ERROR,this);
    return;
}

ContourInfo->Clear();


int *cont=new int[total_contours]; // contour number array
int numb_found_cont; // Number of found contours in current object
wxString obj_name,obj_desc,px;


for(int i=0;i<cont_calc->GetNumberOfObject();i++)
{
numb_found_cont=cont_calc->GetNumbFoundObjects(i,cont);
if(numb_found_cont>0)
{
    ContourInfo->WriteText(_("Object: "));
    if(cont_calc->GetObjectNameAndDescription(i,obj_name,obj_desc) !=0) obj_name=_("Not found");
    ContourInfo->WriteText(obj_name);
    for(int j=0;j<numb_found_cont;j++)
    {
     px=_("\nContour ");
     px<<(cont[j]+1);
     ContourInfo->WriteText(px);
    }
    ContourInfo->WriteText(_("\n\n\n"));
}
else ContourInfo->WriteText(_("Any objects was found !\n"));
}

if(obj_found!=NULL)
{
    delete[] obj_found;
    obj_found=NULL;
}
all_found_objects=cont_calc->ReturnAllFoundObjectsNum();



if(all_found_objects > 0)
{
    obj_found=new OBJECTFOUND[all_found_objects];
    cont_calc->ReturnAllFoundObjects(obj_found);
}

delete []cont;
}

/*
Function is displayed whe user click on toolbar button List of object
Function display dialog ObjectList and if user select some object to show, function will
display it.
*/
void ContourDescript::OnToolBarItem7Clicked(wxCommandEvent& event)
{
    if(all_found_objects<1)
    {
        wxMessageBox(_("No object found"),_("Object found error"),wxICON_ERROR,this);
        return;
    }
    if(obj_found ==NULL)
    {
        wxMessageBox(_("Structure object found is not alocated"),_("Object foun error"),wxICON_ERROR,this);
        return;
    }
    ObjectList *dialog;
    dialog=new ObjectList(this,all_found_objects,obj_found);
    int ret_code=dialog->ShowModal();
    delete dialog;

try
{
    if(ret_code>=0)
    {
        /* Read setup */
           wxConfig cfg_data(_("ELI"));
           wxString r_data;

            cfg_data.Read(_("CONTOURWINDOW_OBJECTLINE_COL"),&r_data);

          wxColour pok,pok2;

          if(r_data.Length()>1) pok.Set(r_data);

          r_data=_("");
          cfg_data.Read(_("CONTOURWINDOW_OBJECTNAME_COL"),&r_data);

         if(r_data.Length()>1)  pok2.Set(r_data);

         r_data=_("");
         int line_thick=1;
         cfg_data.Read(_("CONTOURWINDOW_OBJECTLINE_THICKNESS"),&r_data);
         if(r_data.Length()>0) line_thick=wxAtoi(r_data);

         r_data=_("");
         cfg_data.Read(_("CONTOURWINDOW_OBJECTNAME_FONT"),&r_data);
         int ft=FONT_HERSHEY_SIMPLEX;  // Font
         if(r_data.Length()>0)
         {
         if(wxAtoi(r_data)==0) ft=FONT_HERSHEY_SIMPLEX;
         if(wxAtoi(r_data)==1)  ft=FONT_HERSHEY_PLAIN;
         if(wxAtoi(r_data)==2)  ft=FONT_HERSHEY_DUPLEX;
         if(wxAtoi(r_data)==3)  ft=FONT_HERSHEY_COMPLEX;
         if(wxAtoi(r_data)==4)  ft=FONT_HERSHEY_TRIPLEX;
         if(wxAtoi(r_data)==5)  ft=FONT_HERSHEY_COMPLEX_SMALL;
         if(wxAtoi(r_data)==6)  ft=FONT_HERSHEY_SCRIPT_SIMPLEX;
         if(wxAtoi(r_data)==7)  ft=FONT_HERSHEY_SCRIPT_COMPLEX;
         }



         r_data=_("");
         double v_scale=1;
         cfg_data.Read(_("CONTOURWINDOW_OBJECTNAME_VSCALE"),&r_data);
          if(r_data.Length()>0)
         {
         if(wxAtoi(r_data)==0) v_scale=1;
         else v_scale=0.5;
         }


       /* End  */


        //Drav selected objects
        cv::Point p1,p2;
        p1.x=obj_found[ret_code].bounding_rect_x;
        p1.y=obj_found[ret_code].bounding_rect_y;
        p2.x=obj_found[ret_code].bounding_rect_x + obj_found[ret_code].bounding_rect_width;
        p2.y=obj_found[ret_code].bounding_rect_y + obj_found[ret_code].bounding_rect_height;

        if(mainImage2.channels()<3)cvtColor(mainImage2,mainImage2,COLOR_GRAY2RGB);

        rectangle(mainImage2,p1,p2,CV_RGB(pok.Red(),pok.Green(),pok.Blue()),line_thick);

        p1.x=p1.x-2;
        p1.y=p1.y-2;

        String pxx;
        pxx=obj_found[ret_code].object_name.mb_str();

        putText(mainImage2,pxx,p1,ft,v_scale,CV_RGB(pok2.Red(),pok2.Green(),pok2.Blue()));

        GenerateDisplPicture(mainImage2);

      //  DrawBitmatPic();   // maybe used on linux on windows doees not works

           Update();
          Refresh();

    }
}

    catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    wxMessageBox(pv,_("OpenCv error"),wxICON_ERROR);
    }

}

/*
Function is called when user click on toolbar icon Clear displayed objects
Function clear all displayed objects in the panel
*/
void ContourDescript::OnToolBarItem8Clicked(wxCommandEvent& event)
{
    try
    {

    mainImage2=mainImage.clone();
    GenerateDisplPicture(mainImage2);
       // DrawBitmatPic();  // not work on windows maybe it is need in linux
        Update();
        Refresh();

    }

          catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    wxMessageBox(pv,_("OpenCv error"),wxICON_ERROR,this);
    }

}

/*
Function is called when user click on toolbar button Setup
FUnction display Setup window
*/
void ContourDescript::OnToolBarItem9Clicked(wxCommandEvent& event)
{
    ObjectSetup dlg(this);
    dlg.ShowModal();
}

/*
Function is caled when user click on toolbar button Save
Function save actual object block to the structure.
*/
void ContourDescript::OnToolBarSaveClicked(wxCommandEvent& event)
{
   if(wxMessageBox(_("Do you want to save updates?"),_("Save updates"),wxICON_QUESTION|wxYES_NO,this)==wxYES)
   {
    int ret=cont_calc->SaveObjectBlock();
    if(ret!=0)
    {
        wxString log_mes=_("Save object Block error\nCode:");
        log_mes<<ret;
        ErrorLog er;
        er.SetError(_("Save object block function"),log_mes);
        er.DisplayLog(0);
    }
   }


}

/*
Function clear filter module
*/
void ContourDescript::OnToolBarClearFIlterClicked(wxCommandEvent& event)
{
if(wxMessageBox(_("Do you want to clear filter module?"),_("Filter module clear"),wxYES_NO,this)==wxYES)
{
cont_calc->ClearFilter();
int active_cnt=0;
wxArrayString contour_array;
           for(int i=0;i<total_contours;i++)
           {

             if(cont_calc->IsContourActive(i))
             {

                 cont_list[i].list_box_pos=active_cnt;
                 active_cnt++;
                   wxString pom=_("Contour ");
                 pom<<(i+1);
                 contour_array.Add(pom);
             }
             else cont_list[i].list_box_pos=-1; //contour is not active
           }
             ContourList->Clear();
             ContourList->InsertItems(contour_array,0);
}
}


/*
Function display help menu
*/
void ContourDescript::OnToolBarItemHelpClicked(wxCommandEvent& event)
{
}
