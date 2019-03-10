#include "stereoview.h"

StereoView::StereoView(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->CreateConnections();
	this->RefreashCameraState();
	m_usecuda = false;
}

StereoView::~StereoView()
{
	this->Reset();
}

void StereoView::initialization()
{

}

void StereoView::CreateConnections()
{
	connect(ui.RefreshCameraState, SIGNAL(clicked()), this, SLOT(RefreashCameraState()));
	connect(ui.m_ChangeCamera, SIGNAL(clicked()), this, SLOT(SwapCamera()));
	connect(ui.m_GetLeftCameraParameter, SIGNAL(clicked()), this, SLOT(GetLeftCameraState()));
	connect(ui.m_GetRightCameraParameter, SIGNAL(clicked()), this,SLOT(GetRightCameraState()));
	connect(ui.m_SetLeftCameraParameter, SIGNAL(clicked()), this,SLOT(SetLeftCameraState()));
	connect(ui.m_SetRightCameraParameter, SIGNAL(clicked()), this, SLOT(SetRightCameraState()));

	connect(ui.m_useCalibrate, SIGNAL(stateChanged(int)),this,SLOT(SetOnCalibration()));
	connect(ui.m_useyml, SIGNAL(stateChanged(int)), this, SLOT(UseCalibration()));
	connect(ui.m_Manual, SIGNAL(stateChanged(int)), this, SLOT(UseManual()));
	connect(ui.m_LeftangleSlider, SIGNAL(valueChanged(int)), this, SLOT(OnLeftCameraanglechange()));
	connect(ui.m_RightangleSlider, SIGNAL(valueChanged(int)), this, SLOT(OnRightCameraanglechange()));
	connect(ui.m_MainangleSlider, SIGNAL(valueChanged(int)), this, SLOT(OnMainangleChange()));
	connect(ui.m_Leftangleedit, SIGNAL(textChanged(const QString &)),this,SLOT(OnLeftCameraeditchange()));
	connect(ui.m_Rightangleedit, SIGNAL(textChanged(const QString &)), this, SLOT(OnRightCameraeditchange()));
	connect(ui.m_Mainangleedit, SIGNAL(textChanged(const QString &)), this, SLOT(OnMaineditChange()));
	connect(ui.m_PdSlider, SIGNAL(valueChanged(int)), this, SLOT(OnPdsliderchange()));
	connect(ui.m_Pdedit, SIGNAL(textChanged(const QString &)), this, SLOT(OnPdeditchange()));
	connect(ui.m_UseCuda, SIGNAL(clicked()), this, SLOT(UseCuda()));
	connect(ui.m_Unfullscreen, SIGNAL(clicked()), this, SLOT(Unfullscreen()));


	connect(ui.m_Startbutton, SIGNAL(clicked()), this, SLOT(StartVideo()));
	connect(ui.m_Resetbutton, SIGNAL(clicked()), this, SLOT(ResetVideo()));
	connect(ui.m_LockedCalibration, SIGNAL(clicked()), this, SLOT(LockCalibration()));

	connect(ui.m_Calibrateroot, SIGNAL(clicked()), this, SLOT(FindCalibrationroot()));
	connect(ui.m_Calibrationfileroot, SIGNAL(textChanged(const QString &)), this, SLOT(OnCalibrationeditchange()));
}

void StereoView::RefreashCameraState()
{
	this->Reset();
	if (this->isSwapCamera()) {
		RightCamera = VideoCapture(CV_CAP_DSHOW);
		RightCamera.open(1);
		RightCamera.set(CV_CAP_PROP_FOURCC, CV_FOURCC('M', 'J', 'P', 'G'));
		RightCamera.set(CV_CAP_PROP_FRAME_HEIGHT, 720);
		RightCamera.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
		waitKey(400);
		LeftCamera = VideoCapture(CV_CAP_DSHOW);
		LeftCamera.open(0);
		LeftCamera.set(CV_CAP_PROP_FOURCC, CV_FOURCC('M', 'J', 'P', 'G'));
		LeftCamera.set(CV_CAP_PROP_FRAME_HEIGHT, 720);
		LeftCamera.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
		waitKey(400);

	}
	else {
		LeftCamera = VideoCapture(CV_CAP_DSHOW);
		LeftCamera.open(1);
		LeftCamera.set(CV_CAP_PROP_FOURCC, CV_FOURCC('M', 'J', 'P', 'G'));
		LeftCamera.set(CV_CAP_PROP_FRAME_HEIGHT, 720);
		LeftCamera.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
		waitKey(400);

		RightCamera = VideoCapture(CV_CAP_DSHOW);
		RightCamera.open(0);
		RightCamera.set(CV_CAP_PROP_FOURCC, CV_FOURCC('M', 'J', 'P', 'G'));
		RightCamera.set(CV_CAP_PROP_FRAME_HEIGHT, 720);
		RightCamera.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
		waitKey(400);

	}
	if (LeftCamera.isOpened())
	{
		ui.LeftCameraState->setText("LeftCamera is open");
		ui.LeftCameraState->setStyleSheet("color:blackl;background-color:transparent");
	}
	else { 
		ui.LeftCameraState->setText("LeftCamera fail to open"); 
		ui.LeftCameraState->setStyleSheet("color:red;background-color:transparent");
	}

	if (RightCamera.isOpened())
	{
		ui.RightCameraState->setText("RightCamera is open");
		ui.RightCameraState->setStyleSheet("color:black;background-color:transparent");
	}
	else {
		ui.RightCameraState->setText("RightCamera fail to open");
		ui.RightCameraState->setStyleSheet("color:red;background-color:transparent");
	}
}
void StereoView::SwapCamera()
{
	if (this->isSwapCamera()) this->swapcamera = false;
	else this->swapcamera = true;

	this->RefreashCameraState();
}
void StereoView::GetLeftCameraState()
{
	if (!LeftCamera.isOpened()) return;
	this->m_Width = LeftCamera.get(CV_CAP_PROP_FRAME_WIDTH);
	this->m_Height = LeftCamera.get(CV_CAP_PROP_FRAME_HEIGHT);
	this->m_fps = LeftCamera.get(CV_CAP_PROP_FPS);
	this->m_brightness = LeftCamera.get(CV_CAP_PROP_BRIGHTNESS);
	this->m_constrast = LeftCamera.get(CV_CAP_PROP_CONTRAST);
	this->m_hue = LeftCamera.get(CV_CAP_PROP_HUE);
	this->m_saturation = LeftCamera.get(CV_CAP_PROP_SATURATION);
	this->m_exposure = LeftCamera.get(CV_CAP_PROP_EXPOSURE);

	this->PrintCameraState();
}
void StereoView::GetRightCameraState() 
{
	if (!RightCamera.isOpened()) return;
	this->m_Width = RightCamera.get(CV_CAP_PROP_FRAME_WIDTH);
	this->m_Height = RightCamera.get(CV_CAP_PROP_FRAME_HEIGHT);
	this->m_fps = RightCamera.get(CV_CAP_PROP_FPS);
	this->m_brightness = RightCamera.get(CV_CAP_PROP_BRIGHTNESS);
	this->m_constrast = RightCamera.get(CV_CAP_PROP_CONTRAST);
	this->m_hue = RightCamera.get(CV_CAP_PROP_HUE);
	this->m_saturation = RightCamera.get(CV_CAP_PROP_SATURATION);
	this->m_exposure = RightCamera.get(CV_CAP_PROP_EXPOSURE);

	this->PrintCameraState();
}
void StereoView::SetLeftCameraState()
{
	if (!LeftCamera.isOpened()) return;

	this->m_Width = ui.m_Width->text().toInt();
	this->m_Height = ui.m_Height->text().toInt();
	this->m_fps = ui.m_Fps->text().toInt();
	this->m_brightness = ui.m_Brightness->text().toInt();
	this->m_constrast = ui.m_Contrast->text().toInt();
	this->m_hue = ui.m_Hue->text().toInt();
	this->m_saturation = ui.m_Saturation->text().toInt();
	this->m_exposure = ui.m_Exposure->text().toInt();

	this->InputCameraState(0);
}
void StereoView::SetRightCameraState()
{
	if (!RightCamera.isOpened()) return;

	this->m_Width = ui.m_Width->text().toInt();
	this->m_Height = ui.m_Height->text().toInt();
	this->m_fps = ui.m_Fps->text().toInt();
	this->m_brightness = ui.m_Brightness->text().toInt();
	this->m_constrast = ui.m_Contrast->text().toInt();
	this->m_hue = ui.m_Hue->text().toInt();
	this->m_saturation = ui.m_Saturation->text().toInt();
	this->m_exposure = ui.m_Exposure->text().toInt();

	this->InputCameraState(1);
}

void StereoView::SetOnCalibration()
{
	if (ui.m_useCalibrate->isChecked())
	{
		ui.m_useyml->setEnabled(true);
		ui.m_Manual->setEnabled(true);
	}
	else
	{
		ui.m_useyml->setCheckState(Qt::Unchecked);
		ui.m_useyml->setEnabled(false);
		ui.m_Calibrationfileroot->setEnabled(false);
		ui.m_Calibrateroot->setEnabled(false);

		ui.m_Manual->setCheckState(Qt::Unchecked);
		ui.m_Manual->setEnabled(false);
		ui.m_Leftangleedit->setEnabled(false);
		ui.m_LeftangleSlider->setEnabled(false);
		ui.m_Rightangleedit->setEnabled(false);
		ui.m_RightangleSlider->setEnabled(false);
		ui.m_Mainangleedit->setEnabled(false);
		ui.m_MainangleSlider->setEnabled(false);
		ui.m_remainall->setChecked(false);
		ui.m_remainall->setEnabled(false);
		ui.m_remainmax->setChecked(false);
		ui.m_remainmax->setEnabled(false);
	}
}
void StereoView::UseCalibration()
{
	if (ui.m_useyml->isChecked())
	{
		ui.m_Manual->setCheckState(Qt::Unchecked);
		ui.m_Leftangleedit->setEnabled(false);
		ui.m_LeftangleSlider->setEnabled(false);
		ui.m_Rightangleedit->setEnabled(false);
		ui.m_RightangleSlider->setEnabled(false);
		ui.m_Mainangleedit->setEnabled(false);
		ui.m_MainangleSlider->setEnabled(false);
		ui.m_remainall->setChecked(false);
		ui.m_remainall->setEnabled(false);
		ui.m_remainmax->setChecked(false);
		ui.m_remainmax->setEnabled(false);

		ui.m_Calibrationfileroot->setEnabled(true);
		ui.m_Calibrateroot->setEnabled(true);
		ui.m_useCalibrate->setEnabled(true);
		this->useManual(false);
		this->useCalibrate(true);

	}
	else {
		ui.m_Calibrationfileroot->setEnabled(false);
		ui.m_Calibrateroot->setEnabled(false);
		this->useCalibrate(false);
	}
}
void StereoView::UseManual()
{
	if (ui.m_Manual->isChecked())
	{
		ui.m_useyml->setCheckState(Qt::Unchecked);
		ui.m_Calibrationfileroot->setEnabled(false);
		ui.m_Calibrateroot->setEnabled(false);

		ui.m_Leftangleedit->setEnabled(true);
		ui.m_LeftangleSlider->setEnabled(true);
		ui.m_Rightangleedit->setEnabled(true);
		ui.m_RightangleSlider->setEnabled(true);
		ui.m_Mainangleedit->setEnabled(true);
		ui.m_MainangleSlider->setEnabled(true);
		ui.m_remainall->setChecked(true);
		ui.m_remainall->setEnabled(true);
		ui.m_remainmax->setChecked(true);
		ui.m_remainmax->setEnabled(true);
		this->useCalibrate(false);
		this->useManual(true);
	}
	else
	{
		ui.m_Leftangleedit->setEnabled(false);
		ui.m_LeftangleSlider->setEnabled(false);
		ui.m_Rightangleedit->setEnabled(false);
		ui.m_RightangleSlider->setEnabled(false);
		ui.m_Mainangleedit->setEnabled(false);
		ui.m_MainangleSlider->setEnabled(false);
		ui.m_remainall->setChecked(false);
		ui.m_remainall->setEnabled(false);
		ui.m_remainmax->setChecked(false);
		ui.m_remainmax->setEnabled(false);
		this->useManual(false);
	}
}


void StereoView::FindCalibrationroot()
{
	QString fileName = QFileDialog::getOpenFileName(NULL, tr("Open Calibrate File"),
		"D:/",
		tr("YML File (*.yml)"),
		0);

	ui.m_Calibrationfileroot->setText(fileName);
}
void StereoView::OnCalibrationeditchange()
{
	QString Filename;
	QByteArray Fname;
	char* Calibratename;
	Filename = ui.m_Calibrationfileroot->text();
	Fname = Filename.toLatin1();
	Calibratename = Fname.data();
	if (this->loadCalibratefile(Calibratename))
	{
		ui.m_Calibrationfileroot->setStyleSheet("background-color:green");
		this->setCalibrationfilename(Calibratename);
	}
	else{
		ui.m_Calibrationfileroot->setStyleSheet("background-color:red");
	}
	
}
void StereoView::OnLeftCameraanglechange()
{
	int angle;
	angle = ui.m_LeftangleSlider->value();
	angle /= 10;
	ui.m_Leftangleedit->setText(QString::number(angle));
	this->setLeftAngle(angle);
}
void StereoView::OnRightCameraanglechange()
{
	int angle;
	angle = ui.m_RightangleSlider->value();
	angle /= 10;
	ui.m_Rightangleedit->setText(QString::number(angle));
	this->setRightAngle(angle);
}
void StereoView::OnMainangleChange()
{
	int angle;
	angle = ui.m_MainangleSlider->value();
	angle /= 10;
	ui.m_Mainangleedit->setText(QString::number(angle));
	this->setMainAngle(angle);
}
void StereoView::OnLeftCameraeditchange()
{
	QString sangle;
	int angle;
	sangle = ui.m_Leftangleedit->text();
	angle = sangle.toInt();
	ui.m_LeftangleSlider->setValue(angle*10);
	this->setLeftAngle(angle);

}
void StereoView::OnRightCameraeditchange()
{
	QString sangle;
	int angle;
	sangle = ui.m_Rightangleedit->text();
	angle = sangle.toInt();
	ui.m_RightangleSlider->setValue(angle*10);
	this->setRightAngle(angle);
}
void StereoView::OnMaineditChange()
{
	QString sangle;
	int angle;
	sangle = ui.m_Mainangleedit->text();
	angle = sangle.toInt();
	ui.m_MainangleSlider->setValue(angle*10);
	this->setMainAngle(angle);
}
void StereoView::OnManualtypechange(int type)
{
	if (type == 1)
	{
		this->setGraphRemain(true);
		ui.m_remainmax->setChecked(false);
	}
	/*else
	{
		this->setGraphRemain(false);
		ui.m_remainall->setChecked(false);
	}*/
}


void StereoView::Unfullscreen()
{
	if (ui.m_Unfullscreen->isChecked()) this->SetUnfullscreen(true);
	else this->SetUnfullscreen(false);
}

void StereoView::UseCuda()
{

	if (ui.m_UseCuda->isChecked())
	{
		int num = gpu::getCudaEnabledDeviceCount();

		if (num <= 0)
		{
			ui.m_CudaState->setText("Cuda device unavailable");
			ui.m_CudaState->setStyleSheet("background-color:red");
		}
		else
		{
			ui.m_CudaState->setText("Cuda device available");
			ui.m_CudaState->setStyleSheet("background-color:green");
			m_usecuda = true;
		}
	}
	else
	{
		ui.m_CudaState->setText("");
		ui.m_CudaState->setStyleSheet("background-color:transparent");
		m_usecuda = false;
	}

}

void StereoView::LockCalibration()
{
	this->useOperation();
}
void StereoView::OnPdsliderchange()
{
	int PD;
	PD = ui.m_PdSlider->value();
	ui.m_Pdedit->setText(QString::number(PD));
	this->setPDvalue(PD);
}
void StereoView::OnPdeditchange()
{
	int PD;
	PD = ui.m_Pdedit->text().toInt();
	ui.m_PdSlider->setValue(PD);
	this->setPDvalue(PD);
}

void StereoView::StartVideo()
{

	if (this->m_isreset)
	{
		this->m_isreset = false;
		this->m_isplay = true;
		this->m_ispause = false;
		this->CreateWindows();
		ui.m_Startbutton->setText("Pause");
		this->RefreashImg();
	}
	else
		if (this->m_isplay)
		{
			this->m_isreset = false;
			this->m_isplay = false;
			this->m_ispause = true;
			ui.m_Startbutton->setText("Start");
		}
		else if (this->m_ispause)
		{
			this->m_isreset = false;
			this->m_isplay = true;
			this->m_ispause = false;
			ui.m_Startbutton->setText("Pause");
			this->RefreashImg();
		}
}
void StereoView::ResetVideo()
{
	if (!this->m_isreset)
	{
		this->m_isreset = true;
		this->m_isplay = false;
		this->m_ispause = false;
		this->DestoryWindows();
		ui.m_Startbutton->setText("Start");
		this->Reset();
		this->RefreashCameraState();
	}
}

void StereoView::PrintCameraState()
{
	ui.m_Width->setText(QString::number(this->m_Width));
	ui.m_Height->setText(QString::number(this->m_Height));
	ui.m_Brightness->setText(QString::number(this->m_brightness));
	ui.m_Fps->setText(QString::number(this->m_fps));
	ui.m_Contrast->setText(QString::number(this->m_constrast));
	ui.m_Saturation->setText(QString::number(this->m_saturation));
	ui.m_Hue->setText(QString::number(this->m_hue));
	ui.m_Exposure->setText(QString::number(this->m_exposure));
}
//一般摄像机不允许输入设置，所以只一般不调用以下函数
void StereoView::InputCameraState(int i)
{
	if (i == 1)
	{
		RightCamera.set(CV_CAP_PROP_FRAME_WIDTH, m_Width);
		RightCamera.set(CV_CAP_PROP_FRAME_HEIGHT, m_Height);
		RightCamera.set(CV_CAP_PROP_FPS, m_fps);
		RightCamera.set(CV_CAP_PROP_BRIGHTNESS, m_brightness);
		RightCamera.set(CV_CAP_PROP_CONTRAST, m_constrast);
		RightCamera.set(CV_CAP_PROP_HUE, m_hue);
		RightCamera.set(CV_CAP_PROP_SATURATION, m_saturation);
		RightCamera.set(CV_CAP_PROP_EXPOSURE, m_exposure);

	}
	else if (i == 0)
	{
		LeftCamera.set(CV_CAP_PROP_FRAME_WIDTH, m_Width);
		LeftCamera.set(CV_CAP_PROP_FRAME_HEIGHT, m_Height);
		LeftCamera.set(CV_CAP_PROP_FPS, m_fps);
		LeftCamera.set(CV_CAP_PROP_BRIGHTNESS, m_brightness);
		LeftCamera.set(CV_CAP_PROP_CONTRAST, m_constrast);
		LeftCamera.set(CV_CAP_PROP_HUE, m_hue);
		LeftCamera.set(CV_CAP_PROP_SATURATION, m_saturation);
		LeftCamera.set(CV_CAP_PROP_EXPOSURE, m_exposure);
	}
}