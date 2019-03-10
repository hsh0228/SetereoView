#ifndef STEREOVIEW_H
#define STEREOVIEW_H

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

#pragma comment(lib, "Shell32.lib")

#include <QtWidgets/QMainWindow>
#include "ui_stereoview.h"
#include"cv.h";
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream>  
#include <QFileDialog>
#include <cmath>
#include <fstream>
#define PI 3.14159265358979

#include "opencv2/gpu/gpu.hpp"

using namespace std;
using namespace cv;

class StereoView : public QMainWindow
{
	Q_OBJECT

public:
	StereoView(QWidget *parent = 0);
	~StereoView();

	void setLeftAngle(int ang)
	{
		m_leftangle = ang;
	}

	void setRightAngle(int ang)
	{
		m_rightangle = ang;
	}

	void setMainAngle(int ang)
	{
		m_mainangle = ang;
	}

	void setGraphRemain(bool type)
	{
		m_allgraphremain = type;
	}

	void setPDvalue(int PD)
	{
		m_PDvalue = PD;

		m_dstTriL[0].x = -m_PDvalue;
		m_dstTriL[1].x = m_Width - 1 - m_PDvalue;
		m_dstTriL[2].x = -m_PDvalue;
		m_dstTriL[3].x = m_Width - 1 - m_PDvalue;
		m_dstTriR[0].x = m_PDvalue;
		m_dstTriR[1].x = m_Width - 1 + m_PDvalue;
		m_dstTriR[2].x = m_PDvalue;
		m_dstTriR[3].x = m_Width - 1 + m_PDvalue;
	}
	bool isSwapCamera()
	{
		if (swapcamera) return true;
		else return false;
	}

	void useCalibrate(bool state)
	{
		m_useCalibration = state;
		if (!m_useCalibration&&!m_useManual) m_useoperation = false;
	}

	void useManual(bool state)
	{
		m_useManual = state;
		if (!m_useCalibration&&!m_useManual) m_useoperation = false;
	}

	void setCalibrationfilename(char* root)
	{
		m_Calibratefilename = root;
	}
	
	void SetUnfullscreen(bool state)
	{
		m_UNfullscreen = state;
	}

	void useOperation()
	{
		if (!m_useCalibration&&!m_useManual){ m_useoperation = false; return; }

		if (m_useCalibration)
		{
			if (!m_loadfinished) { cout << "load Calibration file error" << endl; return; }
			//m_warpL1 = getPerspectiveTransform(m_srcTriL, m_dstTriL);
			//m_warpR1 = getPerspectiveTransform(m_srcTriR, m_dstTriR);
			cout << "Calibration finished" << endl;  
		}
		else if (m_useManual)
		{
			this->ManualOperation();
		}

		m_useoperation = true;
	}

	//获取标定参数
	bool loadCalibratefile(char* fileroot)
	{
		if (!m_useCalibration) return false;

		Mat CM1 = Mat(3, 3, CV_64FC1);
		Mat CM2 = Mat(3, 3, CV_64FC1);
		Mat D1, D2;
		Mat R, T;
		Mat R1, R2, P1, P2, Q;
		m_loadfinished = false;

		FileStorage fs1(fileroot, FileStorage::READ);

		if (!fs1.isOpened()) { m_useCalibration = false; return false; }

		fs1["intrinsic_matrixL"] >> CM1;
		fs1["intrinsic_matrixR"] >> CM2;
		fs1["distortion_coeffsL"] >> D1;
		fs1["distortion_coeffsR"] >> D2;
		fs1["steroR"] >> R;
		fs1["steroT"] >> T;

		stereoRectify(CM1, D1, CM2, D2, Size(m_Width, m_Height), R, T, R1, R2, P1, P2, Q, 0, 0);


		initUndistortRectifyMap(CM1, D1, R1, P1, Size(m_Width, m_Height), CV_32FC1, map1x, map1y);
		initUndistortRectifyMap(CM2, D2, R2, P2, Size(m_Width, m_Height), CV_32FC1, map2x, map2y);

		fs1.release();

		m_loadfinished = true;
		return true;
	}

protected slots:

	void RefreashCameraState();
	void SwapCamera();
	void GetLeftCameraState();
	void GetRightCameraState();
	void SetLeftCameraState();
	void SetRightCameraState();
	
	void SetOnCalibration();
	void UseCalibration();
	void UseManual();
	void FindCalibrationroot();
	void OnCalibrationeditchange();
	void OnLeftCameraanglechange();
	void OnRightCameraanglechange();
	void OnMainangleChange();
	void OnLeftCameraeditchange();
	void OnRightCameraeditchange();
	void OnMaineditChange();
	void OnManualtypechange(int );
	void Unfullscreen();

	void UseCuda();
	void OnPdsliderchange();
	void OnPdeditchange();
	void StartVideo();
	void ResetVideo();
	void LockCalibration();
private:
	Ui::StereoViewClass ui;
	void initialization();
	void CreateConnections();
	void InputCameraState(int i);
	void PrintCameraState();
	void BaseReset()
	{
		m_srcTriL[0].x = 0;
		m_srcTriL[0].y = 0;
		m_srcTriL[1].x = m_Width - 1;
		m_srcTriL[1].y = 0;
		m_srcTriL[2].x = 0;
		m_srcTriL[2].y = m_Height - 1;
		m_srcTriL[3].x = m_Width - 1;
		m_srcTriL[3].y = m_Height - 1;
		m_dstTriL[0].x = 0;
		m_dstTriL[0].y = 0;
		m_dstTriL[1].x = m_Width - 1;
		m_dstTriL[1].y = 0;
		m_dstTriL[2].x = 0;
		m_dstTriL[2].y = m_Height - 1;
		m_dstTriL[3].x = m_Width - 1;
		m_dstTriL[3].y = m_Height - 1;
		m_srcTriR[0].x = 0;
		m_srcTriR[0].y = 0;
		m_srcTriR[1].x = m_Width - 1;
		m_srcTriR[1].y = 0;
		m_srcTriR[2].x = 0;
		m_srcTriR[2].y = m_Height - 1;
		m_srcTriR[3].x = m_Width - 1;
		m_srcTriR[3].y = m_Height - 1;
		m_dstTriR[0].x = 0;
		m_dstTriR[0].y = 0;
		m_dstTriR[1].x = m_Width - 1;
		m_dstTriR[1].y = 0;
		m_dstTriR[2].x = 0;
		m_dstTriR[2].y = m_Height - 1;
		m_dstTriR[3].x = m_Width - 1;
		m_dstTriR[3].y = m_Height - 1;
	
	}
	void Reset()
	{
		LeftCamera.release();
		RightCamera.release();
		m_Width = 1280; 
		m_Height = 720;
		m_SWidth = 1920;
		m_SHeight = 1080;
		m_brightness = 0;
		m_constrast = 0;
		m_hue = 0;
		m_exposure = 0;
		m_saturation = 0;
		m_leftangle = 0;
		m_rightangle = 0;
		m_mainangle = 0;
		m_PDvalue = 0;
		m_fps = 60;
		m_useCalibration = false;
		m_isplay = false; 
		m_isreset = true;
		m_ispause = false;
		m_useManual = false;
		m_allgraphremain = true;
		m_useoperation = false;
		m_loadfinished = false;
		m_UNfullscreen = false;
		m_Calibratefilename = NULL;

		Mat M1(m_SHeight, m_SWidth, CV_8UC3, cv::Scalar::all(0));
		LeftImg = M1.clone();
		Mat M2(m_SHeight, m_SWidth, CV_8UC3, cv::Scalar::all(0));
		RightImg = M2.clone();
		cv::Rect R(((m_SWidth - m_Width) / 2), ((m_SHeight - m_Height) / 2), m_Width, m_Height);
		ROI = R;
		m_LeftImg.release();
		m_RightImg.release();

		this->BaseReset();
	}

	//建立输出窗口调整输出窗口位置
	void CreateWindows()
	{
		namedWindow("Img", CV_WINDOW_NORMAL);
		moveWindow("Img", 2000, 0);
		setWindowProperty("Img", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
	}

	void DestoryWindows()
	{
		destroyAllWindows();
	}

	//图像处理过程
	bool ModifiedImg()
	{
		if (m_LeftImg.empty() || m_RightImg.empty()) return false;

		if (!m_useoperation) {
			if (m_UNfullscreen)
			{
				m_LeftImg.copyTo(LeftImg(ROI));
				m_RightImg.copyTo(RightImg(ROI));
				hconcat(LeftImg, RightImg, m_OutImg);
				return true;
			}
			else
			{
				hconcat(m_LeftImg, m_RightImg, m_OutImg);
				return true;
			}
		}
		else if (m_useCalibration)
		{
			if (m_usecuda)
			{
				g_LeftImg.upload(m_LeftImg);
				g_RightImg.upload(m_RightImg);
				g_map1x.upload(map1x);
				g_map2x.upload(map2x);
				g_map1y.upload(map1y);
				g_map2y.upload(map2y);
				gpu::remap(g_LeftImg, g_LeftImg, g_map1x, g_map1y, INTER_LINEAR, BORDER_CONSTANT, Scalar());
				gpu::remap(g_RightImg, g_RightImg, g_map2x, g_map2y, INTER_LINEAR, BORDER_CONSTANT, Scalar());
				gpu::warpPerspective(g_LeftImg, g_LeftImg, m_warpL1, m_LeftImg.size());
				gpu::warpPerspective(g_RightImg, g_RightImg, m_warpR1, m_RightImg.size());
				g_LeftImg.download(m_LeftImg);
				g_RightImg.download(m_RightImg);
			}
			else
			{
				remap(m_LeftImg, m_LeftImg, map1x, map1y, INTER_LINEAR, BORDER_CONSTANT, Scalar());
				remap(m_RightImg, m_RightImg, map2x, map2y, INTER_LINEAR, BORDER_CONSTANT, Scalar());
				//warpPerspective(m_LeftImg, m_LeftImg, m_warpL1, m_LeftImg.size());
				//warpPerspective(m_RightImg, m_RightImg, m_warpR1, m_RightImg.size());
			}
		} 
		else if (m_useManual)
		{
			if (m_usecuda)
			{
				g_LeftImg.upload(m_LeftImg);
				g_RightImg.upload(m_RightImg);
				gpu::warpPerspective(g_LeftImg, g_LeftImg, m_warpL, m_LeftImg.size());
				gpu::warpPerspective(g_RightImg, g_RightImg, m_warpR, m_RightImg.size());
				g_LeftImg.download(m_LeftImg);
				g_RightImg.download(m_RightImg);

			}
			else
			{
				warpPerspective(m_LeftImg, m_LeftImg, m_warpL, m_LeftImg.size());
				warpPerspective(m_RightImg, m_RightImg, m_warpR, m_RightImg.size());
			}
		}

		if (m_UNfullscreen)
		{
			m_LeftImg.copyTo(LeftImg(ROI));
			m_RightImg.copyTo(RightImg(ROI));
			hconcat(LeftImg, RightImg, m_OutImg);
			return true;
		}
		else
		{
			hconcat(m_LeftImg, m_RightImg, m_OutImg);
			//medianBlur(m_OutImg, m_OutImg, 7);
		}
		return true;

	}


	//获取形变矩阵参数
	void ManualOperation()
	{ 
		if (!m_useManual) return;
		Point2f srcTri[4], dstTri[4], srcTri2[4], dstTri2[4];
		double TransL, TransR,Trans;

		if (m_Height == 0 || m_Width == 0) return;

		m_warpL.release();
		m_warpR.release();

		double angle = m_leftangle;
		angle = PI*(angle / 180.0);

		if (m_mainangle >= 0)
		{
			double Sangle = sin((m_mainangle / 180.0)*PI);
			double Slength = m_Height*(1 - 1 / (1 + Sangle)) / 2;
			int Sleng = round(Slength);

			srcTri[0].x = 0;
			srcTri[0].y = 0;
			srcTri[1].x = m_Width - 1;
			srcTri[1].y = Sleng;
			srcTri[2].x = 0;
			srcTri[2].y = m_Height - 1;
			srcTri[3].x = m_Width - 1;
			srcTri[3].y = m_Height - 1-Sleng;
			srcTri2[0].x = 0;
			srcTri2[0].y = Sleng;
			srcTri2[1].x = m_Width - 1;
			srcTri2[1].y = 0;
			srcTri2[2].x = 0;
			srcTri2[2].y = m_Height - 1 - Sleng;
			srcTri2[3].x = m_Width - 1;
			srcTri2[3].y = m_Height - 1;

		}
		else
		{
			double Sangle = sin((-m_mainangle / 180.0)*PI);
			double Slength = m_Height*(1 - 1 / (1 + Sangle)) / 2;
			int Sleng = round(Slength);
			srcTri[0].x = 0;
			srcTri[0].y = Sleng;
			srcTri[1].x = m_Width - 1;
			srcTri[1].y = 0;
			srcTri[2].x = 0;
			srcTri[2].y = m_Height - 1-Sleng;
			srcTri[3].x = m_Width - 1;
			srcTri[3].y = m_Height - 1;
			srcTri2[0].x = 0;
			srcTri2[0].y = 0;
			srcTri2[1].x = m_Width - 1;
			srcTri2[1].y = Sleng;
			srcTri2[2].x = 0;
			srcTri2[2].y = m_Height - 1;
			srcTri2[3].x = m_Width - 1;
			srcTri2[3].y = m_Height - 1 - Sleng;
		}

		double H, W;
		
		H = (m_Height / cos(angle)) + abs((m_Width-m_Height*tan(angle))*sin(angle));
		H = H / 2;
		W = H*((double)m_Width /(double)m_Height);

		TransL = H;

		angle = -angle;

		dstTri[0].x = -cos(angle)*W + sin(angle)*H + m_Width / 2;
		dstTri[0].y = -sin(angle)*W - cos(angle)*H + m_Height / 2;
		dstTri[1].x = cos(angle)*W + sin(angle)*H + m_Width / 2;
		dstTri[1].y = sin(angle)*W - cos(angle)*H + m_Height / 2;
		dstTri[3].x = cos(angle)*W - sin(angle)*H + m_Width / 2;
		dstTri[3].y = sin(angle)*W + cos(angle)*H + m_Height / 2;
		dstTri[2].x = -cos(angle)*W - sin(angle)*H + m_Width / 2;
		dstTri[2].y = -sin(angle)*W + cos(angle)*H + m_Height / 2;


		angle = m_rightangle;
		angle = PI*(angle / 180.0);

		H = (m_Height / cos(angle)) + abs((m_Width - m_Height*tan(angle))*sin(angle));
		H = H / 2;
		W = H*((double)m_Width / (double)m_Height);

		TransR = H;

		angle = -angle;

		dstTri2[0].x = -cos(angle)*W + sin(angle)*H + m_Width / 2;
		dstTri2[0].y = -sin(angle)*W - cos(angle)*H + m_Height / 2;
		dstTri2[1].x = cos(angle)*W + sin(angle)*H + m_Width / 2;
		dstTri2[1].y = sin(angle)*W - cos(angle)*H + m_Height / 2;
		dstTri2[3].x = cos(angle)*W - sin(angle)*H + m_Width / 2;
		dstTri2[3].y = sin(angle)*W + cos(angle)*H + m_Height / 2;
		dstTri2[2].x = -cos(angle)*W - sin(angle)*H + m_Width / 2;
		dstTri2[2].y = -sin(angle)*W + cos(angle)*H + m_Height / 2;



		if (TransL > TransR)
		{
			Trans = TransL / TransR;

			dstTri2[0].x = (m_Width / 2.0) - Trans*(m_Width / 2.0 - dstTri2[0].x);
			dstTri2[0].y = (m_Height / 2.0) - Trans*(m_Height / 2.0 - dstTri2[0].y);
			dstTri2[1].x = (m_Width / 2.0) - Trans*(m_Width / 2.0 - dstTri2[1].x);
			dstTri2[1].y = (m_Height / 2.0) - Trans*(m_Height / 2.0 - dstTri2[1].y);
			dstTri2[2].x = (m_Width / 2.0) - Trans*(m_Width / 2.0 - dstTri2[2].x);
			dstTri2[2].y = (m_Height / 2.0) - Trans*(m_Height / 2.0 - dstTri2[2].y);
			dstTri2[3].x = (m_Width / 2.0) - Trans*(m_Width / 2.0 - dstTri2[3].x);
			dstTri2[3].y = (m_Height / 2.0) - Trans*(m_Height / 2.0 - dstTri2[3].y);
		}
		else
		{
			Trans = TransR / TransL;

			dstTri[0].x = (m_Width / 2.0) - Trans*(m_Width / 2.0 - dstTri[0].x);
			dstTri[0].y = (m_Height / 2.0) - Trans*(m_Height / 2.0 - dstTri[0].y);
			dstTri[1].x = (m_Width / 2.0) - Trans*(m_Width / 2.0 - dstTri[1].x);
			dstTri[1].y = (m_Height / 2.0) - Trans*(m_Height / 2.0 - dstTri[1].y);
			dstTri[2].x = (m_Width / 2.0) - Trans*(m_Width / 2.0 - dstTri[2].x);
			dstTri[2].y = (m_Height / 2.0) - Trans*(m_Height / 2.0 - dstTri[2].y);
			dstTri[3].x = (m_Width / 2.0) - Trans*(m_Width / 2.0 - dstTri[3].x);
			dstTri[3].y = (m_Height / 2.0) - Trans*(m_Height / 2.0 - dstTri[3].y);
		}



		dstTri[0].x -= m_PDvalue;
		dstTri[1].x -= m_PDvalue;
		dstTri[2].x -= m_PDvalue;
		dstTri[3].x -= m_PDvalue;
		dstTri2[0].x += m_PDvalue;
		dstTri2[1].x += m_PDvalue;
		dstTri2[2].x += m_PDvalue;
		dstTri2[3].x += m_PDvalue;

		m_warpL = getPerspectiveTransform(srcTri,dstTri);
		m_warpR = getPerspectiveTransform(srcTri2, dstTri2);

	}

	//刷新输出画面
	void RefreashImg()
	{
		while (!m_isreset)
		{
			
			if (m_ispause){
				cvWaitKey(1000 / 60); continue;
			};
			LeftCamera >> m_LeftImg;
			RightCamera >> m_RightImg;

			/*if (!m_LeftImg.empty() && !m_RightImg.empty())
			{
				hconcat(m_LeftImg, m_RightImg, m_OutImg);
				imshow("Img", m_OutImg);
				count++;
			}
			*/

			if (ModifiedImg())
			{
				imshow("Img", m_OutImg);
			}
			else continue;

			cvWaitKey(1);
		}
		return;
	}



	VideoCapture LeftCamera, RightCamera;
	int m_Width, m_Height, m_brightness, m_constrast, m_hue, m_exposure, m_saturation;
	int m_leftangle, m_rightangle, m_mainangle,m_PDvalue,m_SWidth,m_SHeight;
	double m_fps;
	bool swapcamera, m_useCalibration, m_isplay, m_isreset, m_ispause,m_useManual;
	bool m_allgraphremain, m_useoperation, m_usecuda, m_loadfinished, m_UNfullscreen;
	char* m_Calibratefilename;
	Mat map1x, map2x, map1y, map2y;
	Mat m_LeftImg, m_RightImg, m_OutImg;
	Mat m_warpL, m_warpR, m_warpL1,m_warpR1;
	Mat LeftImg, RightImg;
	Rect ROI;
	Point2f m_srcTriL[4], m_dstTriL[4],m_srcTriR[4], m_dstTriR[4];

	gpu::GpuMat g_LeftImg, g_RightImg, g_OutImg;
	gpu::GpuMat g_map1x, g_map2x, g_map1y, g_map2y;
	gpu::GpuMat g_warpL, g_warpR;

};

#endif // STEREOVIEW_H
