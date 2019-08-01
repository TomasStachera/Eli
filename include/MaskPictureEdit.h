#ifndef MASKPICTUREEDIT_H
#define MASKPICTUREEDIT_H

//(*Headers(MaskPictureEdit)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/listbox.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/types_c.h>
using namespace cv;
using namespace std;

/*
imgx: background image
type_mask:Mask picture type: 0=binary
                             1=color
type_bac : type of background color:0=white
                                    1=black
                                    2=color
type_mask,col: type of mask:0=white
                        1=black
                        2=color
back_col: string background color(R,G,B)
mask_col: string mask color (R,G,B)
*/
class MaskPictureEdit: public wxDialog
{
	public:

		MaskPictureEdit(wxWindow* parent,Mat imgx,int type_mask,int type_bac,int type_mask_col,wxString back_col,wxString mask_col,wxString commandx=wxEmptyString,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~MaskPictureEdit();
		wxString GetRetCommand(void){return ret_command;}

		//(*Declarations(MaskPictureEdit)
		wxButton* DeleteSel;
		wxButton* NewObj;
		wxButton* SaveExit;
		wxChoice* Choice1;
		wxListBox* ListBox1;
		wxPanel* Panel1;
		wxSlider* Slider1;
		wxStaticText* Coordinates;
		//*)

	protected:

		//(*Identifiers(MaskPictureEdit)
		static const long ID_PANEL1;
		static const long ID_LISTBOX1;
		static const long ID_CHOICE1;
		static const long ID_SLIDER1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(MaskPictureEdit)
		void OnNewObjClick(wxCommandEvent& event);
		void OnDeleteSelClick(wxCommandEvent& event);
		void OnSaveExitClick(wxCommandEvent& event);
		void OnPanel1Paint(wxPaintEvent& event);
		void OnSlider1CmdScroll(wxScrollEvent& event);
		void OnChoice1Select(wxCommandEvent& event);

		//*)
		void OnListboxRDown(wxMouseEvent& event);
		void OnMouseEvent(wxMouseEvent &event);
		void OnLeftClick(wxKeyEvent &event);
		void DrawBitmatPic(int clear=0);
		int GenerateDisplPicture(Mat img);
		void GenerateMask(Mat imgxx);
		void GenerateAddedImg(int val);
		void UpdateListBox(void);
		void CreateNewImage(void);
		void GenerateRetCommand(void);
		void DecodeCommand(wxString cmdx);
		bool is_color_img;

		/**
		data:
		rectangle: 1-corner,2-corner,3-corner 4-corner
		circle:center,radius
		polynom: polynom point 1....polynom point n
		**/

		struct CONT_DAT{
		    int type;  //1=rectangle,2=circle,3=polynom
		    vector<Point> data;
		};

		Mat displayed_Image;
		Mat backgr_image;
		Mat new_image;
		Mat temp_img;
		Mat polymode_picture;
		Mat orig_new_image;
		int x_size,y_size;
		CvScalar colour;
		bool isDisplayedImage;
		float x_ratio,y_ratio; //ration between width(height) of image and panel dimension
		int first_x,first_y; // when drive selected area first position of this area
		int act_x,act_y;
		int rgb_code[3];
		vector<Point> poly_points,rc_points;
		bool poly_mode,poly_active;
		vector <CONT_DAT> cont_data;
        wxString ret_command;

		DECLARE_EVENT_TABLE()
};

class Ofset: public wxDialog
{
	public:

		Ofset(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Ofset();
		int GetXOfset(void){return x_ofset;}
		int GetYOfset(void){return y_ofset;}

		//(*Declarations(Ofset)
		wxButton* Button1;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		//*)

	protected:

		//(*Identifiers(Ofset)
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(Ofset)
		void OnButton1Click(wxCommandEvent& event);
		//*)
		int x_ofset,y_ofset;

		DECLARE_EVENT_TABLE()
};

#endif
