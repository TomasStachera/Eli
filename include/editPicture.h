#ifndef EDITPICTURE_H
#define EDITPICTURE_H



#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/slider.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/types_c.h>
using namespace cv;



class editPicture: public wxDialog
{
	public:

		editPicture(wxWindow* parent,int _mode,wxArrayString names,float v1,float v2,float v3,float v4,float v5,float v6,Mat img,Mat img1,Mat img2,CvScalar col=CV_RGB(0,0,0),wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~editPicture();

		//(*Declarations(editPicture)
		wxSlider* Slider1;
		wxTextCtrl* TextCtrl4;
		wxSlider* Slider2;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl3;
		//*)

		Mat _img,_img1,_img2;


		float GetV1(void){return res_v1;}
		float GetV2(void){return res_v2;}
		float GetV3(void){return res_v3;}
		float GetV4(void){return res_v4;}
		int EditConvertScale(float scale,float shift);
		int EditAddWeighted(float alpha,float beta,float gama=0);


	protected:

		//(*Identifiers(editPicture)
		static const long ID_PANEL1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTON1;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_SLIDER1;
		static const long ID_SLIDER2;
		//*)

	private:

		//(*Handlers(editPicture)
		void OnButton1Click(wxCommandEvent& event);
		void OnChangeControl(wxScrollEvent& event);
		void OnPanel1Paint(wxPaintEvent& event);
		void OnValueControl(wxCommandEvent& event);
		void OnValueButton(wxCommandEvent& event);
		//*)
         int mode; // mode of displayed function
		void OnMouseEvent(wxMouseEvent &event);
		void OnLeftClick(wxKeyEvent &event);
		void DrawBitmatPic(int clear=0);
		int GenerateDisplPicture(Mat img);
		void DrawRectRegion(int x1,int y1,int x2,int y2);
		void UpdateData(void);
		int Threshold(int value,int method);
		int FloodFill(int x,int y,CvScalar new_collor,float loDiff,float upDiff,int flags);
		int FCanny(int thres1,int thres2,int aperture);
		int Corners(int type,float f1,float f2,float f3);
		float x_ratio,y_ratio; //ration between width(height) of image and panel dimension
		int first_x,first_y; // when drive selected area first position of this area
		int g_x1,g_y1,g_x2,g_y2;
		float res_v1,res_v2,res_v3,res_v4;
		int pom_flag; // flag variable for flood fill
		int corner_function_mode; // type of corner mode

		Mat displayed_Image;
		int x_size,y_size;
		CvScalar colour;
		bool isDisplayedImage;

		DECLARE_EVENT_TABLE()
};

#endif
