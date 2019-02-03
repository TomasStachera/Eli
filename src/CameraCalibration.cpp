#include "CameraCalibration.h"

//(*InternalHeaders(CameraCalibration)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/config.h>
#include <wx/filedlg.h>

//(*IdInit(CameraCalibration)
const long CameraCalibration::ID_CHOICE1 = wxNewId();
const long CameraCalibration::ID_TEXTCTRL1 = wxNewId();
const long CameraCalibration::ID_BUTTON1 = wxNewId();
const long CameraCalibration::ID_TEXTCTRL2 = wxNewId();
const long CameraCalibration::ID_TEXTCTRL3 = wxNewId();
const long CameraCalibration::ID_SPINCTRL1 = wxNewId();
const long CameraCalibration::ID_BUTTON2 = wxNewId();
//*)
const long CameraCalibration::ID_TEXTCTRL4 = wxNewId();
const long CameraCalibration::ID_TEXTCTRL5 = wxNewId();

BEGIN_EVENT_TABLE(CameraCalibration,wxDialog)
	//(*EventTable(CameraCalibration)
	//*)
END_EVENT_TABLE()

CameraCalibration::CameraCalibration(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(CameraCalibration)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer5;
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer6;
	wxStaticBoxSizer* StaticBoxSizer7;

	Create(parent, id, _("Camera calibration"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Select camera"));
	Camera = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Camera->SetSelection( Camera->Append(_("Video 0")) );
	Camera->Append(_("Video 1"));
	Camera->Append(_("Video 2"));
	Camera->Append(_("Video 3"));
	Camera->Append(_("Video 4"));
	Camera->Append(_("Video 5"));
	Camera->Append(_("Video 6"));
	Camera->Append(_("Video 7"));
	Camera->Append(_("Video 8"));
	Camera->Append(_("Video 9"));
	Camera->Append(_("Video 10"));
	Camera->Append(_("Video 11"));
	Camera->Append(_("Video 12"));
	Camera->Append(_("Video 13"));
	Camera->Append(_("Video 14"));
	Camera->Append(_("Video 15"));
	Camera->Append(_("Video 16"));
	Camera->Append(_("Video 17"));
	Camera->Append(_("Video 18"));
	Camera->Append(_("Video 19"));
	StaticBoxSizer1->Add(Camera, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Calibration file"));
	CalibrationFilePath = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer2->Add(CalibrationFilePath, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetPath = new wxButton(this, ID_BUTTON1, _("Set path"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	StaticBoxSizer2->Add(SetPath, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer2, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4=new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Reload frame [ms]"));
	time_reload= new wxTextCtrl(this, ID_TEXTCTRL3, _("50"), wxDefaultPosition, wxSize(59,31), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	StaticBoxSizer6->Add(time_reload,1,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer6,1,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Calibration frame delay[ms]"));
	time_betw_calib=new wxTextCtrl(this, ID_TEXTCTRL4, _("2000"), wxDefaultPosition, wxSize(59,31), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	StaticBoxSizer7->Add(time_betw_calib,1,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer7,1,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Square size"));
	SquareSize = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(70,31), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticBoxSizer3->Add(SquareSize, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(StaticBoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Aspect Ratio"));
	AspectRatio = new wxTextCtrl(this, ID_TEXTCTRL3, _("1"), wxDefaultPosition, wxSize(59,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	StaticBoxSizer4->Add(AspectRatio, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(StaticBoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Number frames"));
	SpinCtrl1 = new wxSpinCtrl(this, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxSize(71,21), 0, 0, 100, 0, _T("ID_SPINCTRL1"));
	SpinCtrl1->SetValue(_T("0"));
	StaticBoxSizer5->Add(SpinCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(StaticBoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StartCalibration = new wxButton(this, ID_BUTTON2, _("Start calibration"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(StartCalibration, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CameraCalibration::OnSetPathClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CameraCalibration::OnStartCalibrationClick);
	//*)

	  wxConfig config(wxT("calib_path"),wxT("ELI"));
	  wxString pom;

	  config.Read(wxT("REL_FRAME"),&pom);
	  if(pom.Length()>1)
      {
          time_reload->Clear();
          time_reload->WriteText(pom);
      }
      pom=wxEmptyString;
      config.Read(wxT("CAL_DELAY"),&pom);
      if(pom.Length()>1)
      {
        time_betw_calib->Clear();
        time_betw_calib->WriteText(pom);
      }

}

CameraCalibration::~CameraCalibration()
{
	//(*Destroy(CameraCalibration)
	//*)
}


void CameraCalibration::OnSetPathClick(wxCommandEvent& event)
{
      wxString caption=wxT("Save calibration file");
    wxString wildcard=wxT("YML files (*.yml)|*.yml");
     wxString pok;
     wxString defaultDir;
    wxConfig config(wxT("calib_path"),wxT("ELI"));
    config.Read(wxT("def_dir"),&pok);
    if(pok.Len()==0) defaultDir=wxT("/home");
    else defaultDir=pok;


   wxString defaultFilename=wxEmptyString;

    wxFileDialog dialog(this,caption,defaultDir,defaultFilename,wildcard,wxFD_SAVE);
    if(dialog.ShowModal()==wxID_OK)
    {
       path=dialog.GetPath();
     wxString sv=path.BeforeLast('/');
      config.Write(wxT("def_dir"),sv);
      CalibrationFilePath->Clear();
      CalibrationFilePath->WriteText(path);
    }
}

void CameraCalibration::OnStartCalibrationClick(wxCommandEvent& event)
{
    	square_sz=wxAtof(SquareSize->GetValue());
	     asp_rat=wxAtoi(AspectRatio->GetValue()); //aspect ratio
		 num_fram=SpinCtrl1->GetValue(); //number frames
		 camera_number=Camera->GetSelection();
		  wxConfig config(wxT("calib_path"),wxT("ELI"));
		  config.Write(wxT("REL_FRAME"),time_reload->GetValue());
		  config.Write(wxT("CAL_DELAY"),time_betw_calib->GetValue());

    EndModal(1);
}

/**

**/

CameraCalib::CameraCalib(void)
{
    boardSize.width=9;
    boardSize.height=6;
    act_frames_num=0;
    avr_ReprojectionError=0;
    was_error=false;
    size_coef=1;
}

/**
Function reads stored parsameters from file
1.parameter: filename: path for file frome where input parameters should be read
2.parameter: cazmeraMatrix: return camera matrix of readed file
3.parameter: distCoeffs: return matrix of distortion coeficients
Function return 0 if all is ok
         return -1 if file can not be opened
         return -2 if there is bad focal length
**/
int CameraCalib::ReadStorageParam(const string filename,double size_coefx,Mat &cameraMatrix,Mat &distCoeffs)
{
try{
   FileStorage fs(filename,FileStorage::READ);
   if(!fs.isOpened()) return -1; //file is not open

   if(size_coef==0) return -2; //Bad focal_length number

   size_coef=size_coefx;

   FileNode fn=fs["camera_matrix"];
   fn>>cameraMatrix;

   FileNode fn2=fs["distortion_coefficients"];
   fn2>>distCoeffs;



}
    catch( cv::Exception& e )
   {
       std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
     cver_string=pv;
     was_error=true;
   }
    return 0;
}
void CameraCalib::saveCameraParams(const string& filename,Size imageSize, Size boardSize,float squareSize,
                                          float aspectRatio, int flags,const Mat& cameraMatrix, const Mat& distCoeffs,
                                          const vector<Mat>& rvecs, const vector<Mat>& tvecs,const vector<float>& reprojErrs,
                                          const vector<vector<Point2f> >& imagePoints,double totalAvgErr )
{
    try
    {

    FileStorage fs( filename, FileStorage::WRITE );

    time_t tt;
    time( &tt );
    struct tm *t2 = localtime( &tt );
    char buf[1024];
    strftime( buf, sizeof(buf)-1, "%c", t2 );

    fs << "calibration_time" << buf;

    if( !rvecs.empty() || !reprojErrs.empty() )
        fs << "nframes" << (int)std::max(rvecs.size(), reprojErrs.size());
    fs << "image_width" << imageSize.width;
    fs << "image_height" << imageSize.height;
    fs << "board_width" << boardSize.width;
    fs << "board_height" << boardSize.height;
    fs << "square_size" << squareSize;

    if( flags & CALIB_FIX_ASPECT_RATIO )
        fs << "aspectRatio" << aspectRatio;

    if( flags != 0 )
    {
        sprintf( buf, "flags: %s%s%s%s",
            flags & CALIB_USE_INTRINSIC_GUESS ? "+use_intrinsic_guess" : "",
            flags & CALIB_FIX_ASPECT_RATIO ? "+fix_aspectRatio" : "",
            flags & CALIB_FIX_PRINCIPAL_POINT ? "+fix_principal_point" : "",
            flags & CALIB_ZERO_TANGENT_DIST ? "+zero_tangent_dist" : "" );
        //cvWriteComment( *fs, buf, 0 );
    }

    fs << "flags" << flags;

    fs << "camera_matrix" << cameraMatrix;
    fs << "distortion_coefficients" << distCoeffs;

    fs << "avg_reprojection_error" << totalAvgErr;
    if( !reprojErrs.empty() )
        fs << "per_view_reprojection_errors" << Mat(reprojErrs);

    if( !rvecs.empty() && !tvecs.empty() )
    {
        CV_Assert(rvecs[0].type() == tvecs[0].type());
        Mat bigmat((int)rvecs.size(), 6, rvecs[0].type());
        for( int i = 0; i < (int)rvecs.size(); i++ )
        {
            Mat r = bigmat(Range(i, i+1), Range(0,3));
            Mat t = bigmat(Range(i, i+1), Range(3,6));

            CV_Assert(rvecs[i].rows == 3 && rvecs[i].cols == 1);
            CV_Assert(tvecs[i].rows == 3 && tvecs[i].cols == 1);
            //*.t() is MatExpr (not Mat) so we can use assignment operator
            r = rvecs[i].t();
            t = tvecs[i].t();
        }
        //cvWriteComment( *fs, "a set of 6-tuples (rotation vector + translation vector) for each view", 0 );
        fs << "extrinsic_parameters" << bigmat;
    }

    if( !imagePoints.empty() )
    {
        Mat imagePtMat((int)imagePoints.size(), (int)imagePoints[0].size(), CV_32FC2);
        for( int i = 0; i < (int)imagePoints.size(); i++ )
        {
            Mat r = imagePtMat.row(i).reshape(2, imagePtMat.cols);
            Mat imgpti(imagePoints[i]);
            imgpti.copyTo(r);
        }
        fs << "image_points" << imagePtMat;
    }

    }

        catch( cv::Exception& e )
   {

     std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
     cver_string=pv;
     was_error=true;
   }

}

 double CameraCalib::computeReprojectionErrors(
        const vector<vector<Point3f> >& objectPoints,
        const vector<vector<Point2f> >& imagePoints,
        const vector<Mat>& rvecs, const vector<Mat>& tvecs,
        const Mat& cameraMatrix, const Mat& distCoeffs,
        vector<float>& perViewErrors )
{
    vector<Point2f> imagePoints2;
    int i, totalPoints = 0;
    double totalErr = 0, err;

   try{

    perViewErrors.resize(objectPoints.size());

    for( i = 0; i < (int)objectPoints.size(); i++ )
    {
        projectPoints(Mat(objectPoints[i]), rvecs[i], tvecs[i],
                      cameraMatrix, distCoeffs, imagePoints2);
        err = norm(Mat(imagePoints[i]), Mat(imagePoints2), NORM_L2);
        int n = (int)objectPoints[i].size();
        perViewErrors[i] = (float)std::sqrt(err*err/n);
        totalErr += err*err;
        totalPoints += n;
    }

      }
    catch( cv::Exception& e )
   {
     std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
     cver_string=pv;
     was_error=true;
   }
    return std::sqrt(totalErr/totalPoints);
}

void CameraCalib::calcChessboardCorners(Size boardSize, float squareSize, vector<Point3f>& corners)
{
    try
    {
     corners.resize(0);

        for( int i = 0; i < boardSize.height; i++ )
            for( int j = 0; j < boardSize.width; j++ )
                corners.push_back(Point3f(float(j*squareSize),
                                          float(i*squareSize), 0));
    }
     catch( cv::Exception& e )
   {
     std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
     cver_string=pv;
     was_error=true;
   }

}

 bool CameraCalib::runCalibration( vector<vector<Point2f> > imagePoints,
                    Size imageSize, Size boardSize,
                    float squareSize, float aspectRatio,
                    int flags, Mat& cameraMatrix, Mat& distCoeffs,
                    vector<Mat>& rvecs, vector<Mat>& tvecs,
                    vector<float>& reprojErrs,
                    double& totalAvgErr)
{
    bool ok=false;
    try
    {

    cameraMatrix = Mat::eye(3, 3, CV_64F);
    if( flags & CALIB_FIX_ASPECT_RATIO )
        cameraMatrix.at<double>(0,0) = aspectRatio;

    distCoeffs = Mat::zeros(8, 1, CV_64F);

    vector<vector<Point3f> > objectPoints(1);
   calcChessboardCorners(boardSize, squareSize, objectPoints[0]);

    objectPoints.resize(imagePoints.size(),objectPoints[0]);

   calibrateCamera(objectPoints, imagePoints, imageSize, cameraMatrix,
                    distCoeffs, rvecs, tvecs, flags|CALIB_FIX_K4|CALIB_FIX_K5);
                    ///*|CALIB_FIX_K3*/|CALIB_FIX_K4|CALIB_FIX_K5);
   // printf("RMS error reported by calibrateCamera: %g\n", rms);

  ok = checkRange(cameraMatrix) && checkRange(distCoeffs);

    totalAvgErr = computeReprojectionErrors(objectPoints, imagePoints,
                rvecs, tvecs, cameraMatrix, distCoeffs, reprojErrs);

    }
         catch( cv::Exception& e )
   {
      std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
     cver_string=pv;
     was_error=true;
     return false;
   }


    return ok;
}

 bool CameraCalib::runAndSave(const string& outputFilename,
                const vector<vector<Point2f> >& imagePoints,
                Size imageSize, Size boardSize, float squareSize,
                float aspectRatio, int flags, Mat& cameraMatrix,
                Mat& distCoeffs, bool writeExtrinsics, bool writePoints )
{
    vector<Mat> rvecs, tvecs;
    vector<float> reprojErrs;
    double totalAvgErr = 0;
    bool ok=false;
try
{

    ok = runCalibration(imagePoints, imageSize, boardSize, squareSize,
                   aspectRatio, flags, cameraMatrix, distCoeffs,
                   rvecs, tvecs, reprojErrs, totalAvgErr);
   avr_ReprojectionError=totalAvgErr;


    if( ok )
        saveCameraParams( outputFilename, imageSize,
                         boardSize, squareSize, aspectRatio,
                         flags, cameraMatrix, distCoeffs,
                         writeExtrinsics ? rvecs : vector<Mat>(),
                         writeExtrinsics ? tvecs : vector<Mat>(),
                         writeExtrinsics ? reprojErrs : vector<float>(),
                         writePoints ? imagePoints : vector<vector<Point2f> >(),
                         totalAvgErr );

}
     catch( cv::Exception& e )
   {
   std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
     cver_string=pv;
     was_error=true;
     return false;
   }

    return ok;
}

/**
Function calculates undistortion Image from image in The first parameter
1.parameter : input image
2.parameter : Undistortion image
3.parameter: pixels_per_unit return actual coeficient pixel per unit

Function return true if all is ok
return false if there is not correct size of cameraMatrix or distCoeffs matrix
 If there is openCv error was_error flag is set to true
**/
bool CameraCalib::GetUndistortionImage(Mat Image,Mat &retImage,double &pixels_per_unit)
{

    try
    {
       retImage=Image.clone();


      if(cameraMatrix.size().width != 3) return false;
      if(cameraMatrix.size().height !=3) return false;
     if(distCoeffs.size().width!=1)return false;
     if(distCoeffs.size().height!=5)return false;

 pixels_per_unit=((cameraMatrix.at<double>(0,0)+cameraMatrix.at<double>(1,1))/2)/size_coef;

  undistort(Image,retImage,cameraMatrix,distCoeffs);
    }


     catch( cv::Exception& e )
   {
    std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
     cver_string=pv;
     was_error=true;

   }

 return true;
}
/**
This function sets calibration parameters . This function must be set before calibration
1.parameter: _square_size : Set dimension of  cheesboard cube size
2.parameter file: path for file where calibration will be stored
3.parameter: num_frames: number of frames needs for calibration
4.parameter: _aspectRatio: Aspect ratio : default=1
5._writeExtrinsic. If it is true Extrinsic parameter will be write to the file: default : false
6._writePoints. If it is true  Points wiil be  write to the file. default:false;
**/
void CameraCalib::SetCalibration(float _square_size,String file,int _num_frames,int _aspectRatio,bool _writeExtrinsic,bool _writePoints)
{
   square_size=_square_size; //dimenion of one side of square
  out_file=file; //output file path where calibratioon results will be stored
  num_frames=_num_frames; //number of calibrated frames
  if(num_frames<1)num_frames=1;
  aspect_ratio=_aspectRatio;
  writeExtrinsic=_writeExtrinsic;
  writePoints=_writePoints;
  act_frames_num=0;
  imagePoints.clear();
}
/**
Function found calibrated cheesboard of selected frame
1.parameter: frame image frame frome camera
2.paramter: num_frames: return number of calibrated frames. If this prameter is -1 there was a error in function
3.parmameter: finishCalibration. Thre if number of founded frames is same as number of maximal frames, otherwise false

Function return true if frame was found
         return false if frame was not found
**/
bool CameraCalib::FoundCalibratedFrame(Mat &frame,int &num_framesx,bool &finishCalibration)
{
  bool found=false;
  finishCalibration=false;
  vector<Point2f> pointbuf;
  Size imageSize=frame.size();
  try
  {
     found = findChessboardCorners( frame, boardSize, pointbuf,CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_FAST_CHECK | CALIB_CB_NORMALIZE_IMAGE);
  if(found)
  {
      imagePoints.push_back(pointbuf);
      drawChessboardCorners( frame, boardSize, Mat(pointbuf), found );
      act_frames_num++;
      num_framesx=act_frames_num;
      if(imagePoints.size()==(unsigned)num_frames)//finish calibration
      {
          if(runAndSave(out_file, imagePoints, imageSize,boardSize, square_size, aspect_ratio,CALIB_FIX_ASPECT_RATIO, cameraMatrix, distCoeffs,writeExtrinsic, writePoints))
          finishCalibration=true;
          else
          {
            finishCalibration=false;
            found=false;
            num_framesx=-1;
          }
      }
  }
  }
    catch( cv::Exception& e )
   {
     std::string str=e.err;
    wxString pv(str.c_str(),wxConvUTF8);
     cver_string=pv;
     was_error=true;
     return false;
   }

  return found;
}
