#ifndef CONTOURDESCRIPT_H
#define CONTOURDESCRIPT_H


//(*Headers(ContourDescript)
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/checklst.h>
#include <wx/toolbar.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
#include <wx/choice.h>
//*)
#include <wx/evtloop.h>
#include <wx/stattext.h>

//#include <wx/app.h>
#include "commands_main.h"
#include "ContourDescript3.h"

using namespace std;

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

class ContourDescript: public wxFrame
{
	public:

		ContourDescript(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize,PDAT *pd=NULL,ObjectPrograms *obprg=NULL,int numbobj=0);
		virtual ~ContourDescript();

		//(*Declarations(ContourDescript)
		wxToolBarToolBase* ToolBarItem4;
		wxToolBar* ToolBar1;
		wxToolBarToolBase* ToolBarItem9;
		wxToolBarToolBase* ToolBarItem3;
		wxToolBarToolBase* ToolBarItem12;
		wxToolBarToolBase* ToolBarItem11;
		wxButton* Button1;
		wxToolBarToolBase* ToolBarItem10;
		wxPanel* Panel1;
		wxButton* Button2;
		wxToolBarToolBase* ToolBarItem6;
		wxToolBarToolBase* ToolBarItem13;
		wxToolBarToolBase* ToolBarItem1;
		wxTextCtrl* ContourInfo;
		wxToolBarToolBase* ToolBarItem5;
		wxToolBarToolBase* ToolBarItem8;
		wxToolBarToolBase* ToolBarItem2;
		wxCheckListBox* ContourList;
		wxToolBarToolBase* ToolBarItem7;
		wxTextCtrl* StatTextX;
		//*)
		wxButton* ButtonExp;



       // Function for show this frame as a modal dialog
        int ShowModal()
        {
                Show();

          m_evtLoop = new wxModalEventLoop(this);
                m_evtLoop->Run();
                delete m_evtLoop;
                m_evtLoop = NULL;

                Hide();
                return m_retCode;
        }

        void EndModal(int retCode)
        {
                m_retCode = retCode;
                m_evtLoop->Exit();
        }

	protected:

		//(*Identifiers(ContourDescript)
		static const long ID_PANEL1;
		static const long ID_CHECKLISTBOX1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_TEXTCTRL1;
		static const long idQuit;
		static const long idSave;
		static const long idRead;
		static const long idFilter;
		static const long idRunFilter;
		static const long idFilterClear;
		static const long idObjectMod;
		static const long idRunObject;
		static const long ListObject;
		static const long idVariablesDispl;
		static const long idClearDispObj;
		static const long idSetupObj;
		static const long idHelp;
		static const long ID_TOOLBAR1;
        static const long ID_TEXTCTRL2;
		//*)

		static const long ID_BUTTON3;

         wxModalEventLoop *m_evtLoop;
        int m_retCode;
         ContourCalculation *cont_calc;

	private:

		//(*Handlers(ContourDescript)
		void QuitClick(wxCommandEvent& event);
		void OnPanel1Paint(wxPaintEvent& event);
		void OnToolBarRead(wxCommandEvent& event);
		void Button_SelectAll(wxCommandEvent& event);
		void Button_SelectNone(wxCommandEvent& event);
		void OnListBoxSelect(wxCommandEvent& event);
		void OnToolBarFilterDisplay(wxCommandEvent& event);
		void OnToolBarRunFilter(wxCommandEvent& event);
		void OnObjectModuleClicked(wxCommandEvent& event);
		void OnToolRunObjectModuleClicked(wxCommandEvent& event);
		void OnToolBarItem7Clicked(wxCommandEvent& event);
		void OnToolBarItem8Clicked(wxCommandEvent& event);
		void OnToolBarItem9Clicked(wxCommandEvent& event);
		void OnToolBarSaveClicked(wxCommandEvent& event);
		void OnToolBarClearFIlterClicked(wxCommandEvent& event);
		void OnToolBarItemDisplVariablesClicked(wxCommandEvent& event);
		void OnToolBarItemHelpClicked(wxCommandEvent& event);
		//*)
		void Button_Export(wxCommandEvent& event);
		void OnMouseEvent(wxMouseEvent &event);
		void DrawBitmatPic(void);
		int GenerateDisplPicture(Mat img);
		int ReturnContourRectPos(int x,int y,int *val);
		int MeasureAllValues(void);

		 Mat displayed_Image; //Image is display in result window
		 Mat mainImage;
		 Mat mainImage2; //template image
		 vector<vector<Point> > contx; // contours sequence
		 vector<Vec4i> hierarch;

		 int total_contours;// numbers of all contours
		 float x_ratio,y_ratio; //ration between width(height) of image and panel dimension
		 int x_size,y_size;
		 int contour_list_number; // how many contours are in the contour list box
		 float syst_variable[100];
		 bool isDisplayedImage;

		 OBJECTFOUND *obj_found;
		 int all_found_objects;

     struct CONTOUR_LIST{
         int list_box_pos; //actual list box position
         Rect bounding_rect; //Bounding rect of selected contour
         double perimeter; // Perimeter (lenght) of contour
         double contour_area; // Area of contours
         RotatedRect min_area_rec; //MInimal rectangle  that will bound contour
         Point2f min_enclosing_circle_center; // Minimal contours enclosing circle center
         float min_enclosing_circle_radius; // MInimal contour enclosing circle radius
         RotatedRect fit_elipse; //best fitting elipsoid
         Moments moments; //moments structure
     };

     CONTOUR_LIST *cont_list;


		DECLARE_EVENT_TABLE()
};



#endif
