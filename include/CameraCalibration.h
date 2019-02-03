#ifndef CAMERACALIBRATION_H
#define CAMERACALIBRATION_H

//(*Headers(CameraCalibration)
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include "opencv2/core.hpp"
#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"

#include <cctype>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <time.h>

using namespace cv;
using namespace std;

class CameraCalib{
  public:
  CameraCalib();
  ~CameraCalib(){};

  int SetFileUndistortCalculation(String filename,double focal_length){return ReadStorageParam(filename,focal_length,cameraMatrix,distCoeffs);}
  bool GetUndistortionImage(Mat Image,Mat &ret_image,double &pixels_per_unit);
  void SetCalibration(float _square_size,String file,int _num_frames,int _aspectRatio=1,bool _writeExtrinsic=false,bool _writePoints=false);
  bool FoundCalibratedFrame(Mat &frame,int &num_frames,bool &finishCalibration);
  double GetReprojectionError(void){return avr_ReprojectionError;}
  bool GetCvError(void){return was_error;}
  void ResetCvError(void){was_error=false;}
  wxString GetErrorCVString(void){return cver_string;}

  private:
  int ReadStorageParam(const string filename,double focal_length,Mat &cameraMatrix,Mat &distCoeffs);
 void saveCameraParams( const string& filename,Size imageSize, Size boardSize,float squareSize,
                       float aspectRatio, int flags,const Mat& cameraMatrix, const Mat& distCoeffs,const vector<Mat>& rvecs,
                        const vector<Mat>& tvecs,const vector<float>& reprojErrs,const vector<vector<Point2f> >& imagePoints,
                        double totalAvgErr );
 double computeReprojectionErrors(
        const vector<vector<Point3f> >& objectPoints,
        const vector<vector<Point2f> >& imagePoints,
        const vector<Mat>& rvecs, const vector<Mat>& tvecs,
        const Mat& cameraMatrix, const Mat& distCoeffs,
        vector<float>& perViewErrors );

 void calcChessboardCorners(Size boardSize, float squareSize, vector<Point3f>& corners);
bool runCalibration( vector<vector<Point2f> > imagePoints,
                    Size imageSize, Size boardSize,
                    float squareSize, float aspectRatio,
                    int flags, Mat& cameraMatrix, Mat& distCoeffs,
                    vector<Mat>& rvecs, vector<Mat>& tvecs,
                    vector<float>& reprojErrs,
                    double& totalAvgErr);
  bool runAndSave(const string& outputFilename,
                const vector<vector<Point2f> >& imagePoints,
                Size imageSize, Size boardSize, float squareSize,
                float aspectRatio, int flags, Mat& cameraMatrix,
                Mat& distCoeffs, bool writeExtrinsics, bool writePoints );


  Size boardSize; //Calibration board size (9x6)
  Mat cameraMatrix; //camera matrix used in undistortion calculation
  Mat distCoeffs; //calculated distrortion coeficients
  float square_size; //dimenion of one side of square
  String out_file; //output file path where calibratioon results will be stored
  int num_frames; //number of calibrated frames
  int aspect_ratio;
  bool writeExtrinsic,writePoints;
  int act_frames_num;
  vector<vector<Point2f> > imagePoints;
  double avr_ReprojectionError;
  bool was_error;
  double size_coef;
  wxString cver_string;

};

class CameraCalibration: public wxDialog
{
	public:

		CameraCalibration(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~CameraCalibration();

		//(*Declarations(CameraCalibration)
		wxSpinCtrl* SpinCtrl1;
		wxButton* SetPath;
		wxTextCtrl* AspectRatio;
		wxButton* StartCalibration;
		wxTextCtrl* SquareSize;
		wxTextCtrl* CalibrationFilePath;
		wxChoice* Camera;
		//*)
		wxTextCtrl* time_reload;
		wxTextCtrl* time_betw_calib;

		void Getparameters(wxString &pathx,double &sqr_sz,int &asp_ratx,int &n_frames,int &cam_numb)
		{
		    pathx=path;
		    sqr_sz=square_sz;
		    asp_ratx=asp_rat;
		    n_frames=num_fram;
		    cam_numb=camera_number;
		}

	protected:

		//(*Identifiers(CameraCalibration)
		static const long ID_CHOICE1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_SPINCTRL1;
		static const long ID_BUTTON2;
		//*)
		static const long ID_TEXTCTRL4;
		static const long ID_TEXTCTRL5;

	private:

		//(*Handlers(CameraCalibration)
		void OnSetPathClick(wxCommandEvent& event);
		void OnStartCalibrationClick(wxCommandEvent& event);
		//*)

		wxString path; //Calibration file path
		double square_sz;//square size
		int asp_rat; //aspect ratio
		int num_fram; //number frames
		int camera_number;

		DECLARE_EVENT_TABLE()
};

#endif
