#include "editPicture.h"

#include <wx/intl.h>
#include <wx/string.h>
#include <wx/msgdlg.h>
#include <wx/dc.h>
#include <wx/dcclient.h>
#include <wx/image.h>


using namespace cv;

//(*IdInit(editPicture)
const long editPicture::ID_PANEL1 = wxNewId();
const long editPicture::ID_STATICTEXT1 = wxNewId();
const long editPicture::ID_STATICTEXT2 = wxNewId();
const long editPicture::ID_BUTTON1 = wxNewId();
const long editPicture::ID_TEXTCTRL1 = wxNewId();
const long editPicture::ID_TEXTCTRL2 = wxNewId();
const long editPicture::ID_TEXTCTRL3 = wxNewId();
const long editPicture::ID_TEXTCTRL4 = wxNewId();
const long editPicture::ID_SLIDER1 = wxNewId();
const long editPicture::ID_SLIDER2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(editPicture,wxDialog)
	//(*EventTable(editPicture)
	//*)
	EVT_MOUSE_EVENTS(editPicture::OnMouseEvent)
	EVT_KEY_DOWN(editPicture::OnLeftClick)
END_EVENT_TABLE()

editPicture::editPicture(wxWindow* parent,int _mode,wxArrayString names,float v1,float v2,float v3,float v4,float v5,float v6,Mat img,Mat img1,Mat img2,CvScalar col,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    mode=_mode;
    wxString n1,n2,n3,n4,n5,n6;
    /*
    n1=name of left top textbox
    n2=name of left bottom textbox
    n3=name of right top textbox
    n4=name of right bottom textbox
    n5=name of top slider
    n6=name of bottom slider
    */

    if(mode==1) // Select ROI area option
    {
     if(names.GetCount()>=1) n1=names[0];
    if(names.GetCount()>=2) n2=names[1];
    if(names.GetCount()>=3) n3=names[2];
    if(names.GetCount()==4) n4=names[3];
    }

   if(mode==2) //convert scale option
   {
    if(names.GetCount()>=1)
    {
        n1=names[0];
        n5=names[0];
    }
    if(names.GetCount()==2)
    {
        n2=names[1];
        n6=names[1];
    }

   }

   if(mode==3) //addweighted option
   {
     if(names.GetCount()>=1)
     {
         n1=names[0];
         n5=names[0];
     }
    if(names.GetCount()>=2)
    {
        n2=names[1];
        n6=names[1];
    }
    if(names.GetCount()>=3) n3=names[2];

   }
   if(mode==4)//threshold
   {
      if(names.GetCount()>=1)
     {
         n1=names[0];
         n5=names[0];
     }
    if(names.GetCount()>=2)
    {
        n2=names[1];
        n6=names[1];
    }
   }
   if(mode==5)//flood fill
   {
       colour=col;
    if(names.GetCount()>=1) n1=names[0];
    if(names.GetCount()>=2) n2=names[1];
    if(names.GetCount()>=3) n3=names[2];
    if(names.GetCount()==4) n4=names[3];
   }
   if(mode==6) //Canny algoritm
   {
     if(names.GetCount()>=1)
     {
         n1=names[0];
         n5=names[0];
     }
    if(names.GetCount()>=2)
    {
        n2=names[1];
        n6=names[1];
    }
    if(names.GetCount()>=3)
    {
        n3=names[2];
    }
   }
   if(mode==7) //Corners function
   {
     if(names.GetCount()>=1) n1=names[0] ;
     if(names.GetCount()>=2)
     {
         if((int)v1>1) n2=names[1];
     }
     if(names.GetCount()>=3)
     {
         if((int)v1==2) n3=names[2];
     }
   }

	//(*Initialize(editPicture)
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer7;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer6;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer5;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(462,672));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(700,500), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer1->Add(Panel1, 2, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer3->Add(StaticText1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer3->Add(StaticText2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer6 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this,n1);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer1->Add(TextCtrl1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, n2);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticBoxSizer2->Add(TextCtrl2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5->Add(BoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, n3);
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	StaticBoxSizer3->Add(TextCtrl3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, n4);
	TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	StaticBoxSizer4->Add(TextCtrl4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5->Add(BoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer5, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this,n5);
	Slider1 = new wxSlider(this, ID_SLIDER1, 0, 0, 100, wxDefaultPosition, wxSize(206,19), 0, wxDefaultValidator, _T("ID_SLIDER1"));
	StaticBoxSizer5->Add(Slider1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, this, n6);
	Slider2 = new wxSlider(this, ID_SLIDER2, 0, 0, 100, wxDefaultPosition, wxSize(204,19), 0, wxDefaultValidator, _T("ID_SLIDER2"));
	StaticBoxSizer6->Add(Slider2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 3, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->SetSizeHints(this);

	Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&editPicture::OnPanel1Paint,0,this);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editPicture::OnButton1Click);
	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&editPicture::OnValueButton);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&editPicture::OnValueButton);
	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&editPicture::OnValueButton);
	Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&editPicture::OnValueButton);
	Connect(ID_SLIDER1,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&editPicture::OnChangeControl);
	Connect(ID_SLIDER1,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&editPicture::OnChangeControl);
	Connect(ID_SLIDER2,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&editPicture::OnChangeControl);
	Connect(ID_SLIDER2,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&editPicture::OnChangeControl);
	//*)



    Panel1->Connect( wxEVT_MOTION, wxMouseEventHandler( editPicture::OnMouseEvent ), NULL, this );
    Panel1->Connect( wxEVT_LEFT_DOWN, wxKeyEventHandler( editPicture::OnLeftClick), NULL, this );

    res_v1=0;
    res_v2=0;
    res_v3=0;
    res_v4=0;
    corner_function_mode=0;
    try
    {

    _img=img.clone();
    _img1=img1.clone();
    _img2=img2.clone();

    x_size=0;
    y_size=0;
    x_ratio=0;
    y_ratio=0;
    first_x=-1;
    first_y=-1;
    isDisplayedImage=false;

      GenerateDisplPicture(img);

    if(mode==1) //select region mode
    {
        Slider1->Enable(false);
        Slider2->Enable(false);
        g_x1=(int)(v1/x_ratio);
        g_y1=(int)(v2/y_ratio);
        g_x2=(int)((v3+v1)/x_ratio);
        g_y2=(int)((v4+v2)/y_ratio);

        wxString pom=_("");
        pom<<(int)v1;
        TextCtrl1->WriteText(pom);
         pom=_("");
        pom<<(int)v2;
        TextCtrl3->WriteText(pom);
         pom=_("");
        pom<<(int)v3;
        TextCtrl2->WriteText(pom);
         pom=_("");
        pom<<(int)v4;
        TextCtrl4->WriteText(pom);
    }

    if(mode==2) //mode convert scale
    {
       TextCtrl3->Enable(false);
       TextCtrl4->Enable(false);
        Slider1->SetRange(v1,v2); //v1= minimal value slider1, v2=maximal value slider1
        Slider2->SetRange(v3,v4); //v3=minimal value slider2, v4=maximal value slider2
        wxString pom;
        pom<<v5;
        TextCtrl1->WriteText(pom);
        pom=_("");
        pom<<v6;
        TextCtrl2->WriteText(pom);
        Slider1->SetValue(v5);
        Slider2->SetValue(v6);
        EditConvertScale(v6,v5);
    }
    if(mode==3)//add weighted option
    {
        if(v1<0)v1=0;
        if(v1>1)v1=1;
        if(v2<0)v2=0;
        if(v2>1)v2=1;
        if(v3<-255)v3=-255;
        if(v3>255)v3=255;
        TextCtrl4->Enable(false);
        Slider1->SetRange(0,100);
        Slider2->SetRange(0,100);
        wxString pom;
        pom<<v1;
        TextCtrl1->WriteText(pom);
        pom=_("");
        pom<<v2;
        TextCtrl2->WriteText(pom);
        pom=_("");
        pom<<v3;
        TextCtrl3->WriteText(pom);
        Slider1->SetValue((int)(v1*100));
        Slider2->SetValue((int)(v2*100));
        int rtx=EditAddWeighted(v1,v2,v3);
        if(rtx<0)
        {
            pom=_("AddWeighted function error\n");
            if(rtx==-1) pom+=_("the first image is not alocated");
            if(rtx==-2) pom+=_("the second image is not alocated");
            if(rtx==-3) pom+=_("bad alpha number");
            if(rtx==-4) pom+=_("bad betta number");
            if(rtx==-5) pom+=_("bad gama number");
            if(rtx==-6) pom+=_("number of channels of both pictures are not same");
            wxMessageBox(pom,_("Error"),wxICON_ERROR);
        }
    }
    if(mode==4)
    {
        if(v1<0)v1=0;
        if(v1>255)v1=255;
        if(v2<0)v2=0;
        if(v2>4)v2=4;
        TextCtrl4->Enable(false);
        TextCtrl3->Enable(false);
        Slider1->SetRange(0,255);
        Slider2->SetRange(0,4);
        Slider1->SetValue((int)v1);
        Slider2->SetValue((int)v2);
        (*TextCtrl1)<<(int)v1;
        (*TextCtrl2)<<(int)v2;
        Threshold((int)v1,(int)v2);
    }
    if(mode==5)
    {
     Slider1->Enable(false);
     Slider2->Enable(false);
      (*TextCtrl1)<<(int)v1;
      (*TextCtrl2)<<(int)v2;
      (*TextCtrl3)<<v3;
      (*TextCtrl4)<<v4;
      pom_flag=(int)v5;
      FloodFill((int)v1,int(v2),colour,v3,v4,pom_flag);
    }
    if(mode==6)
    {
        TextCtrl4->Enable(false);
        if(v1<0)v1=0;
        if(v1>255)v1=255;
        if(v2<0)v2=0;
        if(v2>255)v2=255;
         Slider1->SetRange(0,255);
        Slider2->SetRange(0,255);
        Slider1->SetValue((int)v1);
        Slider2->SetValue((int)v2);
        (*TextCtrl1)<<(int)v1;
        (*TextCtrl2)<<(int)v2;
        (*TextCtrl3)<<(int)v3;
        FCanny((int)v1,(int)v2,(int)v3);
    }
    if(mode==7)
    {
        corner_function_mode=(int)v1;
        TextCtrl4->Enable(false);
        Slider1->Enable(false);
        Slider2->Enable(false);
        (*TextCtrl1)<<(int)v2;
        if(corner_function_mode==1)
        {
            TextCtrl2->Enable(false);
            TextCtrl3->Enable(false);
        }
        if(corner_function_mode==3)
        {
            TextCtrl3->Enable(false);
            (*TextCtrl2)<<(int)v3;
        }
        if(corner_function_mode==2)
        {
            (*TextCtrl2)<<(int)v3;
            (*TextCtrl3)<<v4;
        }
    Corners((int)v1,v2,v3,v4);
    }

    }
    catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    wxMessageBox(pv,_("OpenCv error"),wxICON_ERROR);
    }

}

editPicture::~editPicture()
{

	//(*Destroy(editPicture)
	//*)
}

/*************************************************
Function is called when user move with mouse
***************************************************/
void editPicture::OnMouseEvent(wxMouseEvent &event)
{
wxPoint pt(event.GetPosition());


if(event.Moving())
{
 if((pt.x<=x_size)&&(pt.y<=y_size))
 {
wxString x=_("x: ");
x<<(int)((float)pt.x*x_ratio);
wxString y=_("y: ");
y<<(int)((float)pt.y*y_ratio);
StaticText1->SetLabel(x);
StaticText2->SetLabel(y);
 }

}

if((mode==1)||(mode==5)) // select ROI mode is active
{

if(event.LeftIsDown())
{

     if((pt.x<=x_size)&&(pt.y<=y_size))
     {
    int x1,y1;
    if((first_x==-1)&&(first_y==-1))
    {

      x1=pt.x;
      y1=pt.y;
      first_x=pt.x;
      first_y=pt.y;
    }
    else
    {
        x1=first_x;
        y1=first_y;
    }
    int x2=pt.x;
    int y2=pt.y;


    g_x1=x1;
    g_y1=y1;
    g_x2=x2;
    g_y2=y2;

  Update();
  Refresh();
    wxString pom=_("");
    TextCtrl1->Clear();//x position
    TextCtrl2->Clear(); //width
    TextCtrl3->Clear(); //y position
    TextCtrl4->Clear(); //height
    if(pt.x>first_x)
    {
      pom<<(int)((float)first_x*x_ratio);
      TextCtrl1->WriteText(pom);
      pom=_("");
      pom<<(int)(((float)pt.x-first_x)*x_ratio);
      TextCtrl2->WriteText(pom);
    }
    else
    {
      pom<<(int)((float)pt.x*x_ratio);
      TextCtrl1->WriteText(pom);
      pom=_("");
      pom<<(int)(((float)first_x-pt.x)*x_ratio);
      TextCtrl2->WriteText(pom);
    }
      pom=_("");
     if(pt.y>first_y)
    {
      pom<<(int)((float)first_y*y_ratio);
      TextCtrl3->WriteText(pom);
      pom=_("");
      pom<<(int)(((float)pt.y-first_y)*y_ratio);
      TextCtrl4->WriteText(pom);
    }
    else
    {
      pom<<(int)((float)pt.y*y_ratio);
      TextCtrl3->WriteText(pom);
      pom=_("");
      pom<<(int)(((float)first_y-pt.y)*y_ratio);
      TextCtrl4->WriteText(pom);
    }

}


}
else
{
    first_x=-1;
    first_y=-1;
}
}



}

void editPicture::OnLeftClick(wxKeyEvent &event)
{
double dxx,dxx2;

         if(mode==5)
         {
               wxPoint pt(event.GetPosition());
               if((pt.x<=x_size)&&(pt.y<=y_size))
             {
             TextCtrl3->GetValue().ToCDouble(&dxx);
             TextCtrl4->GetValue().ToCDouble(&dxx2);

           FloodFill((int)((float)pt.x*x_ratio),(int)((float)pt.y*y_ratio),colour,(float)dxx,(float)dxx2,pom_flag);
           TextCtrl1->Clear();
           TextCtrl2->Clear();
            (*TextCtrl1)<<(int)((float)pt.x*x_ratio);
            (*TextCtrl2)<<(int)((float)pt.y*y_ratio);
             }
         }

}

/***********************************************
FUnction read data from all textboxes and
update parameters values
************************************************/
void editPicture::UpdateData(void)
{
double dxx;
TextCtrl1->GetValue().ToCDouble(&dxx);
  res_v1=(float)dxx;
  TextCtrl2->GetValue().ToCDouble(&dxx);
  res_v2=(float)dxx;
  TextCtrl3->GetValue().ToCDouble(&dxx);
  res_v3=(float)dxx;
  TextCtrl4->GetValue().ToCDouble(&dxx);
  res_v4=(float)dxx;
}

/*************************************************
Function is call when user click EXIT button
**************************************************/
void editPicture::OnButton1Click(wxCommandEvent& event)
{

    if(IsModal())
    {
     if(wxMessageBox(_("Do you want save new data?"),_("Question"),wxICON_QUESTION|wxYES_NO)==wxYES)
     {
         UpdateData();
         EndModal(wxID_OK);
     }
     else EndModal(wxID_CANCEL);
    }
    else
    {
      SetReturnCode(wxID_CANCEL);
      this->Show(false);
    }
}

/****************************************************
Function is called when user change slider value
*****************************************************/
void editPicture::OnChangeControl(wxScrollEvent& event)
{

    if(mode==2)// convert scale option
    {
        wxString px=_("");
        int scale=0,shift=0;
       TextCtrl1->Clear();
       TextCtrl2->Clear();
       px<<Slider1->GetValue();
       shift=Slider1->GetValue();
       TextCtrl1->WriteText(px);
       px=_("");
       px<<Slider2->GetValue();
       scale=Slider2->GetValue();
       TextCtrl2->WriteText(px);
        EditConvertScale((float)scale,(float)shift);
    }
    if(mode==3) // add weghted
    {
        wxString px=_("");
        TextCtrl1->Clear();
        TextCtrl2->Clear();
        px<<(float)Slider1->GetValue()/100;
        TextCtrl1->WriteText(px);
        px=_("");
        px<<(float)Slider2->GetValue()/100;
        TextCtrl2->WriteText(px);
        double dxx;
        TextCtrl3->GetValue().ToCDouble(&dxx);
         int rtx=EditAddWeighted((float)((float)Slider1->GetValue()/100),(float)((float)Slider2->GetValue()/100),(float)dxx);
        if(rtx<0)
        {
            wxString pom=_("AddWeighted function error\n");
            if(rtx==-1) pom+=_("the first image is not alocated");
            if(rtx==-2) pom+=_("the second image is not alocated");
            if(rtx==-3) pom+=_("bad alpha number");
            if(rtx==-4) pom+=_("bad betta number");
            if(rtx==-5) pom+=_("bad gama number");
            if(rtx==-6) pom+=_("number of channels of both pictures are not same");
            wxMessageBox(pom,_("Error"),wxICON_ERROR);
        }

    }
    if(mode==4)//THreshold
    {
       TextCtrl1->Clear();
       TextCtrl2->Clear();
       (*TextCtrl1)<<Slider1->GetValue();
       (*TextCtrl2)<<Slider2->GetValue();
        Threshold(Slider1->GetValue(),Slider2->GetValue());
    }
    if(mode==6) //Canny
    {
       TextCtrl1->Clear();
       TextCtrl2->Clear();
       (*TextCtrl1)<<Slider1->GetValue();
       (*TextCtrl2)<<Slider2->GetValue();
      FCanny(Slider1->GetValue(),Slider2->GetValue(),wxAtoi(TextCtrl3->GetValue()));
    }

}

/*************************************************************************
Function draw restangle which display ROI area
*************************************************************************/
void editPicture::DrawRectRegion(int x1,int y1,int x2,int y2)
{
    wxPaintDC dc(Panel1);
    dc.SetPen(wxPen(*wxRED,2,wxSOLID));
    dc.DrawLine(x1,y1,x2,y1);
    dc.DrawLine(x2,y1,x2,y2);
    dc.DrawLine(x2,y2,x1,y2);
    dc.DrawLine(x1,y2,x1,y1);

}

/*******************************************************
Function draw displayed picture on panel
*******************************************************/

void editPicture::DrawBitmatPic(int clear)
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
       if(mode==1) DrawRectRegion(g_x1,g_y1,g_x2,g_y2);

     }
   }
       catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    wxMessageBox(pv,_("OpenCv error"),wxICON_ERROR);
    }
}

/*****************************************************
Function is called when window must be redraw
******************************************************/
void editPicture::OnPanel1Paint(wxPaintEvent& event)
{
 DrawBitmatPic(1);

}

/************************************************************
Function transformed displayed image to dimension according actual
window size.
*************************************************************/
int editPicture::GenerateDisplPicture(Mat img)
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
               cvtColor(img, img_x, CV_GRAY2RGB);

            //displayed_Image=(new_width,new_heigth,img_x.depth(),img_x.channels());
           resize(img_x,displayed_Image,displayed_Image.size(),tot_ratio,tot_ratio,CV_INTER_LINEAR ); // resize final image to new sizes
           }
           else
           {
                    //    displayed_Image=(new_width,new_heigth,img_x.depth(),img_x.channels());
       resize(img,displayed_Image,displayed_Image.size(),tot_ratio,tot_ratio,CV_INTER_LINEAR ); // resize final image to new sizes
           }
           x_size=im_width*tot_ratio;
           y_size=im_height*tot_ratio;
           x_ratio=1/tot_ratio;
           y_ratio=1/tot_ratio;

 cvtColor(displayed_Image,displayed_Image,CV_RGB2BGR);
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

/***************************************************************
Function is called when user press enter in one of the textboxes
***************************************************************/

void editPicture::OnValueButton(wxCommandEvent& event)
{
 double dxx,dxx2;
    if(mode==2)
    {
    double dxx;
    TextCtrl1->GetValue().ToCDouble(&dxx);
      float shift=(float)dxx;
      TextCtrl2->GetValue().ToCDouble(&dxx);
      float scale=(float)dxx;
      int min=Slider1->GetMin();
      int max=Slider1->GetMax();
      if((int)shift>max) Slider1->SetValue(max);
      else if((int)shift<min) Slider1->SetValue(min);
      else Slider1->SetValue((int)shift);
      min=Slider2->GetMin();
      max=Slider2->GetMax();
      if((int)scale>max)Slider2->SetValue(max);
      else if((int)scale<min)Slider2->SetValue(min);
      else Slider2->SetValue((int)scale);
      EditConvertScale(scale,shift);
    }
    if(mode==3)
    {

    TextCtrl1->GetValue().ToCDouble(&dxx);
        float a_par=(float)dxx;
        TextCtrl2->GetValue().ToCDouble(&dxx);
        float b_par=(float)dxx;
        TextCtrl3->GetValue().ToCDouble(&dxx);
        float gama=(float)dxx;
        if((a_par<0)||(a_par>1))
        {
            wxMessageBox(_("A weight must be in range 0-1"),_("Error"),wxICON_ERROR);
            return;
        }
        if((b_par<0)||(b_par>1))
        {
            wxMessageBox(_("B weight must be in range 0-1"),_("Error"),wxICON_ERROR);
            return;
        }
        if((gama<-255)||(gama>255))
        {
            wxMessageBox(_("Gama value must be in range -255 - 255"),_("Error"),wxICON_ERROR);
            return;
        }

        Slider1->SetValue((int)(a_par*100));
        Slider2->SetValue((int)(b_par*100));
        int rtx=EditAddWeighted(a_par,b_par,gama);
        if(rtx<0)
        {
            wxString pom=_("AddWeighted function error\n");
            if(rtx==-1) pom+=_("the first image is not alocated");
            if(rtx==-2) pom+=_("the second image is not alocated");
            if(rtx==-3) pom+=_("bad alpha number");
            if(rtx==-4) pom+=_("bad betta number");
            if(rtx==-5) pom+=_("bad gama number");
            if(rtx==-6) pom+=_("number of channels of both pictures are not same");
            wxMessageBox(pom,_("Error"),wxICON_ERROR);
        }
    }
    if(mode==4)
    {
        int val=wxAtoi(TextCtrl1->GetValue());
        int meth=wxAtoi(TextCtrl2->GetValue());
       if((val<0)||(val>255))
       {
          wxMessageBox(_("Value must be in range 0-255"),_("Error"),wxICON_ERROR);
            return;
       }
       if((meth<0)||(meth>4))
       {
          wxMessageBox(_("Threshold type must be from range 0-4"),_("Error"),wxICON_ERROR);
            return;
       }
       Slider1->SetValue(val);
       Slider2->SetValue(meth);
      Threshold(val,meth);
    }
    if(mode==5)
    {
    TextCtrl3->GetValue().ToCDouble(&dxx);
    TextCtrl4->GetValue().ToCDouble(&dxx2);
        FloodFill(wxAtoi(TextCtrl1->GetValue()),wxAtoi(TextCtrl2->GetValue()),colour,(float)dxx,(float)dxx2,pom_flag);
    }
    if(mode==6)
    {
        int thres1=wxAtoi(TextCtrl1->GetValue());
        int thres2=wxAtoi(TextCtrl2->GetValue());
        int aper=wxAtoi(TextCtrl3->GetValue());
        if((thres1<0)||(thres1>255))
        {
         wxMessageBox(_("Threshold 1 must be in range 0-255"),_("Error"),wxICON_ERROR);
            return;
        }
        if((thres2<0)||(thres2>255))
        {
         wxMessageBox(_("Threshold 2 must be in range 0-255"),_("Error"),wxICON_ERROR);
            return;
        }
        FCanny(thres1,thres2,aper);
        Slider1->SetValue(thres1);
        Slider2->SetValue(thres2);
    }
    if(mode==7)
    {
        float f1=0;
        float f2=0;
        float f3=0;
        TextCtrl1->GetValue().ToCDouble(&dxx);
        f1=(float)dxx;

        if(corner_function_mode==2)
        {
        TextCtrl2->GetValue().ToCDouble(&dxx);
           f2=(float)dxx;
          TextCtrl3->GetValue().ToCDouble(&dxx);
           f3=(float)dxx;
        }
        if(corner_function_mode==3)
        {
        TextCtrl2->GetValue().ToCDouble(&dxx);
          f2=(float)dxx;
        }
        Corners(corner_function_mode,f1,f2,f3);
    }
}

/******************************************************************
Function executed OPenCV function ConvertScale
scale = scale parameter
shift= shift parameter
******************************************************************/
int editPicture::EditConvertScale(float scale,float shift)
{


    try
    {

   _img.convertTo(_img1,-1,(double)scale,(double)shift);
   GenerateDisplPicture(_img1);
   Refresh();
   Update();
    }

    catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    wxMessageBox(pv,_("OpenCv error"),wxICON_ERROR);
    }

return 0;
}


/*****************************************************************
Function cumpute sum of two images
Images are weighted
alpha- weight of first image (range 0-1.0)
beta-weight of the second image(range 0-1.0)
gama= scallar add to each sum(range -255, 255)
*****************************************************************/
int editPicture::EditAddWeighted(float alpha,float beta,float gama)
{

    if((alpha<0)||(alpha>1)) return -3; //bad alpha value
    if((beta<0)||(beta>1)) return -4; // bad beta value
    if((gama<-255)||(gama>255)) return -5; //bad gama value
   if(_img.channels() != _img1.channels()) return -6; //number of channels are not same


    try
    {

      addWeighted(_img,alpha,_img1,beta,gama,_img2);
    GenerateDisplPicture(_img2);
   Refresh();
   Update();
    }
        catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    wxMessageBox(pv,_("OpenCv error"),wxICON_ERROR);
    }
    return 0;
}

/********************************************************
Function create destination image according
threshold value.
********************************************************/
int editPicture::Threshold(int value,int method)
{
 if(value<0)value=0;
    if(value>255)value=255;

  int method_thres=THRESH_BINARY;
    if(method==1)method_thres=THRESH_BINARY_INV;
    if(method==2)method_thres=THRESH_TRUNC;
    if(method==3)method_thres=THRESH_TOZERO;
    if(method==4)method_thres=THRESH_TOZERO_INV;


    try
    {
    //  _img1=_img;
        threshold(_img,_img1,(double)value,255,method_thres);
        GenerateDisplPicture(_img1);
       Refresh();
      Update();
    }
    catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    wxMessageBox(pv,_("OpenCv error"),wxICON_ERROR);
    }
    return 0;
}

int editPicture::FloodFill(int x,int y,CvScalar new_collor,float loDiff,float upDiff,int flags)
{
if((flags!=4)||(flags!=8)) flags=4;
if(x<0)x=0;
if(y<0)y=0;
try
{
 if(x>=_img.cols)x=_img.cols-1;
 if(y>=_img.rows)y=_img.rows-1;
_img1=_img.clone();
floodFill(_img1, Point(x,y), new_collor,0, Scalar(loDiff,loDiff,loDiff), Scalar(upDiff,upDiff,upDiff),flags);
 GenerateDisplPicture(_img1);
 Refresh();
 Update();
}
    catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    wxMessageBox(pv,_("OpenCv error"),wxICON_ERROR);
    }
    return 0;
}

int editPicture::FCanny(int thres1,int thres2,int aperture)
{
   if(thres1<0)thres1=0;
    if(thres1>255)thres1=255;
    if(thres2<0)thres2=0;
    if(thres2>255)thres2=255;
    if((aperture!=3)&&(aperture!=5)&&(aperture!=7))
    {
        wxMessageBox(_("Aperture size must be 3,5,or 7"),_("Aperture error"),wxICON_ERROR);
        return -1;
    }
    try
    {

     if(_img.channels()!=1)
     {
       wxMessageBox(_("Source image must be single channel"),_("OpenCV error"),wxICON_ERROR);
         return -3;
     }

     _img1=_img.clone();
     Canny(_img,_img1,(double)thres1,(double)thres2,aperture);
      GenerateDisplPicture(_img1);
      Refresh();
      Update();
    }
      catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    wxMessageBox(pv,_("OpenCv error"),wxICON_ERROR);
    }
    return 0;
}

/******************************************************************
Functions for detected corners
*******************************************************************/
int editPicture::Corners(int type,float f1,float f2,float f3)
{
   int aperture_size=0;
    int block_size=0;
    try
    {

Mat orig_im=_img.clone();



     if(_img.channels()!=1)
     {
       wxMessageBox(_("Source image must be single channel"),_("OpenCV error"),wxICON_ERROR);
         return -3;
     }
      Mat imgx;
     if(type==1)//Pre corner detect
     {
        aperture_size=(int)f1;
        _img1=_img.clone();

        if((aperture_size<1)||((aperture_size%2)!=1))
        {
          wxMessageBox(_("Aperture size must be odd number higher than 0"),_("OpenCV error"),wxICON_ERROR);
         return -1;
        }
        preCornerDetect(_img1,imgx,aperture_size);


     }
     if((type==2)||(type==3)) //Corner Haris and cvCornerMInEigenVal
     {
        block_size=(int)f1;
        aperture_size=(int)f2;
        if((aperture_size<1)||((aperture_size%2)!=1))
        {
          wxMessageBox(_("Aperture size must be odd number higher than 0"),_("OpenCV error"),wxICON_ERROR);
         return -1;
        }
        if(block_size<1)
        {
            wxMessageBox(_("Block size must be higher than 0"),_("OpenCV error"),wxICON_ERROR);
         return -1;
        }
        _img1=_img.clone();
      if(type==2) cornerHarris(_img1,imgx,block_size,aperture_size,f3);
      if(type==3) cornerMinEigenVal(_img1,imgx,block_size,aperture_size);
     }
     convertScaleAbs(imgx,_img1);
GenerateDisplPicture(_img1);
  _img=orig_im.clone();
      Refresh();
      Update();
    }

    catch( cv::Exception& e )
    {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
    wxMessageBox(pv,_("OpenCv error"),wxICON_ERROR);
    }
    return 0;
}
