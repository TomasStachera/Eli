#include "MaskPictureEdit.h"

//(*InternalHeaders(MaskPictureEdit)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <vector>
#include <wx/dc.h>
#include <wx/dcclient.h>
#include <wx/image.h>
#include <wx/msgdlg.h>

using namespace cv;
using namespace std;

//(*IdInit(MaskPictureEdit)
const long MaskPictureEdit::ID_PANEL1 = wxNewId();
const long MaskPictureEdit::ID_LISTBOX1 = wxNewId();
const long MaskPictureEdit::ID_CHOICE1 = wxNewId();
const long MaskPictureEdit::ID_SLIDER1 = wxNewId();
const long MaskPictureEdit::ID_BUTTON1 = wxNewId();
const long MaskPictureEdit::ID_BUTTON2 = wxNewId();
const long MaskPictureEdit::ID_STATICTEXT1 = wxNewId();
const long MaskPictureEdit::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MaskPictureEdit,wxDialog)
	//(*EventTable(MaskPictureEdit)
	//*)
	EVT_MOUSE_EVENTS(MaskPictureEdit::OnMouseEvent)
//	EVT_KEY_DOWN(MaskPictureEdit::OnLeftClick)
END_EVENT_TABLE()

MaskPictureEdit::MaskPictureEdit(wxWindow* parent,Mat img,int type_mask,int type_bac,int type_mask_col,wxString back_col,wxString mask_col,wxString commandx,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(MaskPictureEdit)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer6;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(800,480), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer1->Add(Panel1, 4, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
	BoxSizer3->Add(ListBox1, 3, wxALL|wxEXPAND, 5);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Type"));
	Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice1->SetSelection( Choice1->Append(_("rectangle")) );
	Choice1->Append(_("circle"));
	Choice1->Append(_("polynom"));
	StaticBoxSizer1->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider1 = new wxSlider(this, ID_SLIDER1, 0, 0, 255, wxDefaultPosition, wxSize(110,35), 0, wxDefaultValidator, _T("ID_SLIDER1"));
	StaticBoxSizer1->Add(Slider1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	NewObj = new wxButton(this, ID_BUTTON1, _("New"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer4->Add(NewObj, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	DeleteSel = new wxButton(this, ID_BUTTON2, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer4->Add(DeleteSel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	Coordinates = new wxStaticText(this, ID_STATICTEXT1, _("X:0 Y:0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer6->Add(Coordinates, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5->Add(BoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SaveExit = new wxButton(this, ID_BUTTON3, _("Save/Exit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer5->Add(SaveExit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer5, 1, wxALL|wxEXPAND, 5);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&MaskPictureEdit::OnPanel1Paint,0,this);
	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MaskPictureEdit::OnChoice1Select);
	Connect(ID_SLIDER1,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&MaskPictureEdit::OnSlider1CmdScroll);
	Connect(ID_SLIDER1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&MaskPictureEdit::OnSlider1CmdScroll);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MaskPictureEdit::OnNewObjClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MaskPictureEdit::OnDeleteSelClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MaskPictureEdit::OnSaveExitClick);
	//*)
	Panel1->Connect( wxEVT_MOTION, wxMouseEventHandler( MaskPictureEdit::OnMouseEvent ), NULL, this );
    ListBox1->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MaskPictureEdit::OnListboxRDown), NULL, this);
    act_x=-1;
    act_y=-1;
    first_x=-1;
    first_y=-1;
    poly_mode=false;
    poly_active=false;
    GenerateDisplPicture(img);
    backgr_image=img.clone();
    cont_data.clear();
    for(unsigned i=0;i<3;i++)rgb_code[i]=0;
    const int mtype = img.type();
    int typx;
    if(mtype==CV_8UC1)typx=1;//Gray
    else if(mtype==CV_8UC2)typx=2; //Grayscale +alfa
    else if(mtype==CV_8UC4)typx=4;//Color+ Alfa
    else if(mtype==CV_8UC3)typx=3; //color
    else
    {
        wxMessageBox(_("Unknown type of image\n Supported type is:CV_8UC1,CV_8UC2,CV_8UC3,CV_8UC4"),_("Mask picture edit error"),wxICON_ERROR);
    }
    if((typx==1)||(typx==2))//Grayscale image
    {
        is_color_img=false;
        int col_val;
        if(type_bac==0)col_val=255;
        else col_val=0;
        if(typx==1)
        {
        Mat img_g(img.size(),CV_8UC1,Scalar(col_val));
      new_image=img_g.clone();
        }
        else
        {
        Mat img_g(img.size(),CV_8UC2,Scalar(col_val));
      new_image=img_g.clone();
        }

      if(type_mask_col==0)rgb_code[0]=255;
      else rgb_code[0]=0;
    }
    if((typx==3)||(typx==4))//Color image
    {
        is_color_img=true;
      int rx=0,gx=0,bx=0;
      if(type_bac==0)
      {
          rx=255;
          gx=255;
          bx=255;
      }
      else if(type_bac==1)
      {
          rx=0;
          gx=0;
          bx=0;
      }
      else
      {
          rx=wxAtoi(back_col.BeforeFirst(','));
          back_col=back_col.AfterFirst(',');
          gx=wxAtoi(back_col.BeforeFirst(','));
          bx=wxAtoi(back_col.AfterFirst(','));
      }
       if(typx==3)
       {
           Mat img_g(img.size(),CV_8UC3,Scalar(bx,gx,rx));
           new_image=img_g.clone();
       }
       else
       {
           Mat img_g(img.size(),CV_8UC4,Scalar(bx,gx,rx));
           new_image=img_g.clone();
       }


        if(type_mask_col==0)
           for(unsigned i=0;i<3;i++)rgb_code[i]=255;
        else if(type_mask_col==1)
            for(unsigned i=0;i<3;i++)rgb_code[i]=0;
        else
        {
           rgb_code[2]=wxAtoi(mask_col.BeforeFirst(','));
           mask_col=mask_col.AfterFirst(',');
           rgb_code[1]=wxAtoi(mask_col.BeforeFirst(','));
           rgb_code[1]=wxAtoi(mask_col.AfterFirst(','));
        }
    }


temp_img=new_image.clone();
orig_new_image=new_image.clone();
 DecodeCommand(commandx);
}

MaskPictureEdit::~MaskPictureEdit()
{
	//(*Destroy(MaskPictureEdit)
	//*)
}

/*************************************************
Function is called when user move with mouse
***************************************************/
void MaskPictureEdit::OnMouseEvent(wxMouseEvent &event)
{
wxPoint pt(event.GetPosition());


if(event.Moving())
{
 if((pt.x<=x_size)&&(pt.y<=y_size))
 {
wxString post=_("x: ");
post<<(int)((float)pt.x*x_ratio);
post+=_(" y: ");
post<<(int)((float)pt.y*y_ratio);
Coordinates->SetLabel(post);

 }

}

if(event.RightIsDown())
{
    if(poly_mode)
    {
        temp_img=polymode_picture.clone();
        poly_points.clear();
        new_image=temp_img.clone();
         int val=Slider1->GetValue();
        GenerateAddedImg(val);
    }
}

if(event.LeftIsDown())
{
   if((pt.x<=x_size)&&(pt.y<=y_size))
 {
    if((first_x==-1)&&(first_y==-1))
    {
     if(!poly_mode)temp_img=new_image.clone();
      first_x=(int)((float)pt.x*x_ratio);
      first_y=(int)((float)pt.y*y_ratio);
    }
    else
    {
        act_x=(int)((float)pt.x*x_ratio);
        act_y=(int)((float)pt.y*y_ratio);
    }
    if(poly_mode)temp_img=new_image.clone();
    GenerateMask(temp_img);
    if(poly_mode)poly_active=true;
 }

}
else
{
if(poly_mode)
{
    Point ptsx;
    ptsx.x=act_x;
    ptsx.y=act_y;
  if(poly_active)  poly_points.push_back(ptsx);
  new_image=temp_img.clone();
  poly_active=false;
}
    first_x=-1;
    first_y=-1;
    act_x=-1;
    act_y=-1;


}

}

void MaskPictureEdit::GenerateMask(Mat imgxx)
{
    if((first_x==-1)||(first_y==-1)||(act_x==-1)||(act_y==-1)) return;
 vector<vector<Point> > contours;
vector<Point> pts;
Point ptsx;
int center[2];
int radius;


int typex=Choice1->GetSelection();
rc_points.clear();
switch(typex)
{
case 0: //rectangle
  ptsx.x=first_x;
  ptsx.y=first_y;

  pts.push_back(ptsx);
  rc_points.push_back(ptsx);
  ptsx.x=first_x;
  ptsx.y=act_y;
  pts.push_back(ptsx);
  rc_points.push_back(ptsx);
  ptsx.x=act_x;
  ptsx.y=act_y;
  pts.push_back(ptsx);
  rc_points.push_back(ptsx);
  ptsx.x=act_x;
  ptsx.y=first_y;

  pts.push_back(ptsx);
  rc_points.push_back(ptsx);

  contours.push_back(pts);

  if(is_color_img)drawContours(imgxx,contours,0,Scalar(rgb_code[0],rgb_code[1],rgb_code[2]),-1);
  else drawContours(imgxx,contours,0,Scalar(rgb_code[0]),-1);
    break;

case 1: //circle
     ptsx.x=first_x;
  ptsx.y=first_y;
  rc_points.push_back(ptsx);
  radius=abs(act_x-first_x);


    if(is_color_img)circle( imgxx ,ptsx, radius, Scalar(rgb_code[0],rgb_code[1],rgb_code[2]), -1 );
    else circle( imgxx,ptsx, radius, Scalar(rgb_code[0]), -1);
    ptsx.x=radius;
    ptsx.y=0;
  rc_points.push_back(ptsx);
    break;
case 2: //Polynom
  if(poly_points.size()==0)
  {

      ptsx.x=first_x;
      ptsx.y=first_y;
      poly_points.push_back(ptsx);
  }
  else
  {

      ptsx.x=act_x;
      ptsx.y=act_y;
      if(is_color_img)line(imgxx,poly_points[poly_points.size()-1],ptsx,Scalar(rgb_code[0],rgb_code[1],rgb_code[2]));
      else line(imgxx,poly_points[poly_points.size()-1],ptsx,Scalar(rgb_code[0]));
  }
    break;
}


     int val=Slider1->GetValue();
   GenerateAddedImg(val);
}

/*******************************************************
Function draw displayed picture on panel
*******************************************************/

void MaskPictureEdit::DrawBitmatPic(int clear)
{
    wxPaintDC dc(Panel1);
    wxBitmap bitmap1;
   if(clear==0) dc.Clear(); // clear panel area,
   try
   {

     //if(img==0) return -1; // if image pointer is not set return -1;
     if(isDisplayedImage) // if displayed image is alocated read it and draw in result panel
     {

wxImage wx_tmp;



  wx_tmp=wxImage(displayed_Image.cols,displayed_Image.rows,displayed_Image.data,true);

       bitmap1= wxBitmap(wx_tmp);
        dc.DrawBitmap(bitmap1,1,1);
//       if(mode==1) DrawRectRegion(g_x1,g_y1,g_x2,g_y2);

     }
   }
       catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    wxMessageBox(pv,_("OpenCv error"),wxICON_ERROR);
    }
}

/************************************************************
Function transformed displayed image to dimension according actual
window size.
*************************************************************/
int MaskPictureEdit::GenerateDisplPicture(Mat img)
{

try
{

      wxSize size=GetSize();//Get window dimension
    int width=size.GetWidth(); //calculate maximal posible width in display window
    int heigth=(size.GetHeight()/4)*3; //calculate maximal posible height in display window
    int im_width=img.cols; //input image width
    int im_height=img.rows; //input image height

    float ratio_w=(float)width/(float)im_width;
  float ratio_h=(float)heigth/(float)im_height;

  int ra1=(int)(ratio_w*(float)im_height);
  float tot_ratio;
     if(ra1>heigth)tot_ratio=ratio_h;
     else tot_ratio=ratio_w;
         Mat img_x;


           if (img.type()==CV_8UC1)
           {
               cvtColor(img, img_x, COLOR_GRAY2RGB);

            //displayed_Image=(new_width,new_heigth,img_x.depth(),img_x.channels());
           resize(img_x,displayed_Image,displayed_Image.size(),tot_ratio,tot_ratio,INTER_LINEAR ); // resize final image to new sizes
           }
           else
           {
                    //    displayed_Image=(new_width,new_heigth,img_x.depth(),img_x.channels());
       resize(img,displayed_Image,displayed_Image.size(),tot_ratio,tot_ratio,INTER_LINEAR ); // resize final image to new sizes
           }
           x_size=im_width*tot_ratio;
           y_size=im_height*tot_ratio;
           x_ratio=1/tot_ratio;
           y_ratio=1/tot_ratio;

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




void MaskPictureEdit::OnNewObjClick(wxCommandEvent& event)
{
Point ptsx;
 CONT_DAT cd;

if(poly_mode)
{
 vector<vector<Point> > contours;
 contours.clear();

 contours.push_back(poly_points);


 cd.type=3;
 for(unsigned i=0;i<poly_points.size();i++)cd.data.push_back(poly_points[i]);
 cont_data.push_back(cd);

   if(is_color_img)drawContours(new_image,contours,0,Scalar(rgb_code[0],rgb_code[1],rgb_code[2]),-1);
  else drawContours(new_image,contours,0,Scalar(rgb_code[0]),-1);

   int val=Slider1->GetValue();
   temp_img=new_image.clone();
   GenerateAddedImg(val);
   poly_points.clear();
   polymode_picture=new_image.clone();
}
else
{
    new_image=temp_img.clone();
  int typex=Choice1->GetSelection();
  if(typex==0)//rectangle
  {
      ptsx.x=first_x;
  ptsx.y=first_y;
 for(unsigned i=0;i<rc_points.size();i++)cd.data.push_back(rc_points[i]);

  cd.type=1;
 cont_data.push_back(cd);

  }
  else // circle
  {
    cd.type=2;
for(unsigned i=0;i<rc_points.size();i++)cd.data.push_back(rc_points[i]);
 cont_data.push_back(cd);
  }

}
UpdateListBox();

}

void MaskPictureEdit::OnDeleteSelClick(wxCommandEvent& event)
{
    int itemx=ListBox1->GetSelection();
    if(itemx<0)
    {
        wxMessageBox(_("Select some item for delete"),_("Delete item"),wxICON_WARNING);
        return;
    }
    cont_data.erase(cont_data.begin()+itemx); //Delete selected
    UpdateListBox();
    CreateNewImage();

}

void MaskPictureEdit::OnSaveExitClick(wxCommandEvent& event)
{
    GenerateRetCommand();
    EndModal(0);
}

void MaskPictureEdit::OnPanel1Paint(wxPaintEvent& event)
{
    DrawBitmatPic(1);
}

void MaskPictureEdit::GenerateAddedImg(int val)
{
      int m1=255-val;
    int m2=val;

    double alf1=(double)m1/255.0;
    double alf2=(double)m2/255.0;
    try
    {
    Mat outs;
    addWeighted(backgr_image,alf1,temp_img,alf2,0,outs);

     GenerateDisplPicture(outs);
     Update();
     Refresh();
     }
    catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    wxMessageBox(pv,_("OpenCv error"),wxICON_ERROR);
    }
}

void MaskPictureEdit::OnSlider1CmdScroll(wxScrollEvent& event)
{

    int val=Slider1->GetValue();
   GenerateAddedImg(val);
}

void MaskPictureEdit::OnChoice1Select(wxCommandEvent& event)
{
    int sel=Choice1->GetSelection();
    if(sel==2)
    {
        poly_mode=true;
        poly_points.clear();
        polymode_picture=new_image.clone();
    }
    else poly_mode=false;
}


void MaskPictureEdit::OnListboxRDown(wxMouseEvent& event)
{
    int item = ListBox1->HitTest(event.GetPosition());
  vector<Point> pxdat;
  CONT_DAT cd;

    if ( item != wxNOT_FOUND )
    {

      Ofset dlg(this);
      dlg.ShowModal();
      int x_ofset=dlg.GetXOfset();
      int y_ofset=dlg.GetYOfset();
      int typex=cont_data[item].type;
      pxdat.clear();
      if((cont_data.size()<=item)||(item<0))
      {
          wxMessageBox(_("Data vector size error"),_("Vector size error"),wxICON_ERROR);
          return;
      }
      for(unsigned i=0;i<cont_data[item].data.size();i++)pxdat.push_back(cont_data[item].data[i]);

      if(typex==2)//circle
      {
        pxdat[0].x=pxdat[0].x+x_ofset;
        pxdat[0].y=pxdat[0].y+y_ofset;
      }
      else
      {
          for(unsigned i=0;i<pxdat.size();i++)
          {
              pxdat[i].x=pxdat[i].x+x_ofset;
              pxdat[i].y=pxdat[i].y+y_ofset;
          }
      }
      cd.type=typex;
      for(unsigned i=0;i<pxdat.size();i++)cd.data.push_back(pxdat[i]);
      cont_data.push_back(cd);
      UpdateListBox();
      CreateNewImage();

    }
    else
        wxMessageBox(_("Listbox right clicked but no item clicked upon"));

    event.Skip();
}

void MaskPictureEdit::UpdateListBox(void)
{
    ListBox1->Clear();
    wxString mes;
    wxArrayString ar_str;


    if(cont_data.size()<1) return;

    for(unsigned i=0;i<cont_data.size();i++)
    {
      if(cont_data[i].type==1)mes=_("R:");
      else if(cont_data[i].type==2)mes=_("C:");
      else mes=_("P:");

      for(unsigned j=0;j<cont_data[i].data.size();j++)
      {
          if(j>0)mes+=_(":");
          mes<<cont_data[i].data[j].x;
          mes+=_(" ");
          mes<<cont_data[i].data[j].y;

      }
      ar_str.Add(mes);
    }

    ListBox1->InsertItems(ar_str,0);
    ListBox1->SetSelection(ar_str.GetCount()-1);
}

void MaskPictureEdit::CreateNewImage(void)
{
 new_image=orig_new_image.clone();
  vector<vector<Point> > contours;

 for(unsigned i=0;i<cont_data.size();i++)
 {
       contours.clear();
     switch (cont_data[i].type)
     {
      case 1: //rectangele
        contours.push_back(cont_data[i].data);
        if(is_color_img)drawContours(new_image,contours,0,Scalar(rgb_code[0],rgb_code[1],rgb_code[2]),-1);
        else drawContours(new_image,contours,0,Scalar(rgb_code[0]),-1);
        break;
      case 2://circle
          if(cont_data[i].data.size()!=2)
          {
              wxMessageBox(_("Bad size circle array"),_("Circle draw"),wxICON_ERROR);
              return;
          }
         if(is_color_img)circle( new_image,cont_data[i].data[0], cont_data[i].data[1].x, Scalar(rgb_code[0],rgb_code[1],rgb_code[2]), -1 );
        else circle( new_image,cont_data[i].data[0] ,cont_data[i].data[1].x, Scalar(rgb_code[0]), -1);
        break;
      case 3://polynom
        contours.push_back(cont_data[i].data);
        if(is_color_img)drawContours(new_image,contours,0,Scalar(rgb_code[0],rgb_code[1],rgb_code[2]),-1);
        else drawContours(new_image,contours,0,Scalar(rgb_code[0]),-1);
        break;
     }
 }
 temp_img=new_image.clone();
  int val=Slider1->GetValue();
   GenerateAddedImg(val);
}

void MaskPictureEdit::GenerateRetCommand(void)
{
    ret_command=wxEmptyString;
    wxString pom;
    for(unsigned i=0;i<cont_data.size();i++)
    {
      pom=wxEmptyString;
      if(i>0)ret_command+=_(";");
      if(cont_data[i].type==1)pom=_("R:");
      else if(cont_data[i].type==2)pom=_("C:");
      else pom=_("P:");
      for(unsigned j=0;j<cont_data[i].data.size();j++)
      {
            if(j>0)pom+=_(":");
          pom<<cont_data[i].data[j].x;
          pom+=_(" ");
          pom<<cont_data[i].data[j].y;
      }
      ret_command+=pom;
    }
}

void MaskPictureEdit::DecodeCommand(wxString cmdx)
{
cont_data.clear();
if(cmdx.Length()<5) return; // EMpty command string or not valid command
bool end_loop=false;
bool end_loop2=false;
bool valid_data=false;// TRue if decode data is vai
wxString pom,typex,pom2;
CONT_DAT cd;
Point pt;

while(!end_loop)
{
pom=cmdx.BeforeFirst(';');
if(pom.Length()>5)
{
typex=pom.BeforeFirst(':');
if(typex==_("R"))cd.type=1;
else if(typex==_("C"))cd.type=2;
else if(typex==_("P"))cd.type=3;
else return; //Bad command
pom=pom.AfterFirst(':');
end_loop2=false;
cd.data.clear();
  while(!end_loop2)
  {
     pom2=pom.BeforeFirst(':');
     pt.x=wxAtoi(pom2.BeforeFirst(' ')) ;
     pt.y=wxAtoi(pom2.AfterFirst(' '));
     cd.data.push_back(pt);
     pom=pom.AfterFirst(':');
     if(pom==wxEmptyString)end_loop2=true;
  }

  if(cd.type==1)
  {
     if(cd.data.size()==4)valid_data=true;
     else valid_data=false;
  }
  else if(cd.type==2)
  {
     if(cd.data.size()==2)valid_data=true;
     else valid_data=false;
  }
  else
  {
     if(cd.data.size()>1)valid_data=true;
     else valid_data=false;
  }

  if(valid_data)cont_data.push_back(cd);
}
cmdx=cmdx.AfterFirst(';');
if(cmdx==wxEmptyString)end_loop=true;

}
CreateNewImage();
UpdateListBox();
}

//(*IdInit(Ofset)
const long Ofset::ID_TEXTCTRL1 = wxNewId();
const long Ofset::ID_TEXTCTRL2 = wxNewId();
const long Ofset::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Ofset,wxDialog)
	//(*EventTable(Ofset)
	//*)
END_EVENT_TABLE()

Ofset::Ofset(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Ofset)
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;

	Create(parent, id, _("Copy object"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("X-ofset"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("0"), wxDefaultPosition, wxSize(61,36), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer1->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Y-ofset"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("0"), wxDefaultPosition, wxSize(54,36), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticBoxSizer2->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("Copy"), wxDefaultPosition, wxSize(62,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Ofset::OnButton1Click);
	//*)
}

Ofset::~Ofset()
{
	//(*Destroy(Ofset)
	//*)
}


void Ofset::OnButton1Click(wxCommandEvent& event)
{
    x_ofset=wxAtoi(TextCtrl1->GetValue());
    y_ofset=wxAtoi(TextCtrl2->GetValue());
    EndModal(0);
}
