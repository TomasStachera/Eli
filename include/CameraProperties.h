#ifndef CAMERAPROPERTIES_H
#define CAMERAPROPERTIES_H

//(*Headers(CameraProperties)
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class CameraProperties: public wxDialog
{
	public:

		CameraProperties(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~CameraProperties();

		//(*Declarations(CameraProperties)
		wxTextCtrl* ViewCameraLoop;
		wxTextCtrl* StartIndex;
		wxButton* UpdateAll;
		wxButton* ChangeSnapshotFold;
		wxTextCtrl* CameraSnapshotFold;
		wxTextCtrl* SnapshotName;
		//*)

	protected:

		//(*Identifiers(CameraProperties)
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(CameraProperties)
		void OnChangeSnapshotFoldClick(wxCommandEvent& event);
		void OnUpdateAllClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
