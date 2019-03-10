/********************************************************************************
** Form generated from reading UI file 'stereoview.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEREOVIEW_H
#define UI_STEREOVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StereoViewClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGroupBox *CameraState;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *RefreshCameraState;
    QPushButton *m_ChangeCamera;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *LeftCameraState;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *RightCameraState;
    QGroupBox *StereoCalibration;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_16;
    QSlider *m_PdSlider;
    QLineEdit *m_Pdedit;
    QPushButton *m_LockedCalibration;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_8;
    QCheckBox *m_useCalibrate;
    QCheckBox *m_useyml;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *m_Calibrationfileroot;
    QPushButton *m_Calibrateroot;
    QCheckBox *m_Manual;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_17;
    QSlider *m_LeftangleSlider;
    QLineEdit *m_Leftangleedit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_18;
    QSlider *m_RightangleSlider;
    QLineEdit *m_Rightangleedit;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_19;
    QSlider *m_MainangleSlider;
    QLineEdit *m_Mainangleedit;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_20;
    QRadioButton *m_remainall;
    QRadioButton *m_remainmax;
    QGroupBox *Camerainitialization;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QLineEdit *m_Width;
    QLabel *label_7;
    QLineEdit *m_Hue;
    QLineEdit *m_Exposure;
    QLabel *label_13;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *m_Height;
    QLineEdit *m_Brightness;
    QLabel *label_5;
    QLineEdit *m_Saturation;
    QLineEdit *m_Contrast;
    QLabel *label_6;
    QLineEdit *m_Fps;
    QLabel *label_15;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *m_GetLeftCameraParameter;
    QPushButton *m_GetRightCameraParameter;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *m_SetLeftCameraParameter;
    QPushButton *m_SetRightCameraParameter;
    QGroupBox *groupBox_3;
    QLabel *m_CudaState;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *m_UseCuda;
    QCheckBox *m_Unfullscreen;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *m_Startbutton;
    QPushButton *m_Resetbutton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StereoViewClass)
    {
        if (StereoViewClass->objectName().isEmpty())
            StereoViewClass->setObjectName(QStringLiteral("StereoViewClass"));
        StereoViewClass->setEnabled(true);
        StereoViewClass->resize(1011, 628);
        centralWidget = new QWidget(StereoViewClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        CameraState = new QGroupBox(centralWidget);
        CameraState->setObjectName(QStringLiteral("CameraState"));
        gridLayout_2 = new QGridLayout(CameraState);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        RefreshCameraState = new QPushButton(CameraState);
        RefreshCameraState->setObjectName(QStringLiteral("RefreshCameraState"));
        RefreshCameraState->setEnabled(true);

        horizontalLayout_5->addWidget(RefreshCameraState);

        m_ChangeCamera = new QPushButton(CameraState);
        m_ChangeCamera->setObjectName(QStringLiteral("m_ChangeCamera"));

        horizontalLayout_5->addWidget(m_ChangeCamera);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(CameraState);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        LeftCameraState = new QLineEdit(CameraState);
        LeftCameraState->setObjectName(QStringLiteral("LeftCameraState"));
        LeftCameraState->setStyleSheet(QStringLiteral("background-color:transparent"));

        horizontalLayout->addWidget(LeftCameraState);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(CameraState);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        RightCameraState = new QLineEdit(CameraState);
        RightCameraState->setObjectName(QStringLiteral("RightCameraState"));
        RightCameraState->setStyleSheet(QStringLiteral("background-color:transparent"));

        horizontalLayout_2->addWidget(RightCameraState);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_3->addWidget(CameraState, 0, 0, 1, 1);

        StereoCalibration = new QGroupBox(centralWidget);
        StereoCalibration->setObjectName(QStringLiteral("StereoCalibration"));
        gridLayout_5 = new QGridLayout(StereoCalibration);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_16 = new QLabel(StereoCalibration);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_6->addWidget(label_16);

        m_PdSlider = new QSlider(StereoCalibration);
        m_PdSlider->setObjectName(QStringLiteral("m_PdSlider"));
        m_PdSlider->setMinimum(-50);
        m_PdSlider->setMaximum(200);
        m_PdSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(m_PdSlider);

        m_Pdedit = new QLineEdit(StereoCalibration);
        m_Pdedit->setObjectName(QStringLiteral("m_Pdedit"));
        m_Pdedit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_6->addWidget(m_Pdedit);


        verticalLayout_4->addLayout(horizontalLayout_6);

        m_LockedCalibration = new QPushButton(StereoCalibration);
        m_LockedCalibration->setObjectName(QStringLiteral("m_LockedCalibration"));

        verticalLayout_4->addWidget(m_LockedCalibration);


        gridLayout_5->addLayout(verticalLayout_4, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        m_useCalibrate = new QCheckBox(StereoCalibration);
        m_useCalibrate->setObjectName(QStringLiteral("m_useCalibrate"));
        m_useCalibrate->setEnabled(true);

        verticalLayout_8->addWidget(m_useCalibrate);

        m_useyml = new QCheckBox(StereoCalibration);
        m_useyml->setObjectName(QStringLiteral("m_useyml"));
        m_useyml->setEnabled(false);

        verticalLayout_8->addWidget(m_useyml);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        m_Calibrationfileroot = new QLineEdit(StereoCalibration);
        m_Calibrationfileroot->setObjectName(QStringLiteral("m_Calibrationfileroot"));
        m_Calibrationfileroot->setEnabled(false);

        horizontalLayout_9->addWidget(m_Calibrationfileroot);

        m_Calibrateroot = new QPushButton(StereoCalibration);
        m_Calibrateroot->setObjectName(QStringLiteral("m_Calibrateroot"));
        m_Calibrateroot->setEnabled(false);

        horizontalLayout_9->addWidget(m_Calibrateroot);


        verticalLayout_8->addLayout(horizontalLayout_9);

        m_Manual = new QCheckBox(StereoCalibration);
        m_Manual->setObjectName(QStringLiteral("m_Manual"));
        m_Manual->setEnabled(false);

        verticalLayout_8->addWidget(m_Manual);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_17 = new QLabel(StereoCalibration);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_10->addWidget(label_17);

        m_LeftangleSlider = new QSlider(StereoCalibration);
        m_LeftangleSlider->setObjectName(QStringLiteral("m_LeftangleSlider"));
        m_LeftangleSlider->setEnabled(false);
        m_LeftangleSlider->setMinimum(-300);
        m_LeftangleSlider->setMaximum(300);
        m_LeftangleSlider->setPageStep(10);
        m_LeftangleSlider->setValue(0);
        m_LeftangleSlider->setSliderPosition(0);
        m_LeftangleSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(m_LeftangleSlider);

        m_Leftangleedit = new QLineEdit(StereoCalibration);
        m_Leftangleedit->setObjectName(QStringLiteral("m_Leftangleedit"));
        m_Leftangleedit->setEnabled(false);
        m_Leftangleedit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_10->addWidget(m_Leftangleedit);


        verticalLayout_6->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_18 = new QLabel(StereoCalibration);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_11->addWidget(label_18);

        m_RightangleSlider = new QSlider(StereoCalibration);
        m_RightangleSlider->setObjectName(QStringLiteral("m_RightangleSlider"));
        m_RightangleSlider->setEnabled(false);
        m_RightangleSlider->setMinimum(-300);
        m_RightangleSlider->setMaximum(300);
        m_RightangleSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(m_RightangleSlider);

        m_Rightangleedit = new QLineEdit(StereoCalibration);
        m_Rightangleedit->setObjectName(QStringLiteral("m_Rightangleedit"));
        m_Rightangleedit->setEnabled(false);
        m_Rightangleedit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_11->addWidget(m_Rightangleedit);


        verticalLayout_6->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_19 = new QLabel(StereoCalibration);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_12->addWidget(label_19);

        m_MainangleSlider = new QSlider(StereoCalibration);
        m_MainangleSlider->setObjectName(QStringLiteral("m_MainangleSlider"));
        m_MainangleSlider->setEnabled(false);
        m_MainangleSlider->setMinimum(-200);
        m_MainangleSlider->setMaximum(200);
        m_MainangleSlider->setSingleStep(1);
        m_MainangleSlider->setValue(0);
        m_MainangleSlider->setSliderPosition(0);
        m_MainangleSlider->setTracking(true);
        m_MainangleSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_12->addWidget(m_MainangleSlider);

        m_Mainangleedit = new QLineEdit(StereoCalibration);
        m_Mainangleedit->setObjectName(QStringLiteral("m_Mainangleedit"));
        m_Mainangleedit->setEnabled(false);
        m_Mainangleedit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_12->addWidget(m_Mainangleedit);


        verticalLayout_6->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_20 = new QLabel(StereoCalibration);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_13->addWidget(label_20);

        m_remainall = new QRadioButton(StereoCalibration);
        m_remainall->setObjectName(QStringLiteral("m_remainall"));
        m_remainall->setEnabled(false);

        horizontalLayout_13->addWidget(m_remainall);

        m_remainmax = new QRadioButton(StereoCalibration);
        m_remainmax->setObjectName(QStringLiteral("m_remainmax"));
        m_remainmax->setEnabled(false);
        m_remainmax->setChecked(true);

        horizontalLayout_13->addWidget(m_remainmax);


        verticalLayout_6->addLayout(horizontalLayout_13);


        verticalLayout_8->addLayout(verticalLayout_6);


        verticalLayout->addLayout(verticalLayout_8);


        gridLayout_5->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(StereoCalibration, 0, 1, 2, 1);

        Camerainitialization = new QGroupBox(centralWidget);
        Camerainitialization->setObjectName(QStringLiteral("Camerainitialization"));
        gridLayout_4 = new QGridLayout(Camerainitialization);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        m_Width = new QLineEdit(Camerainitialization);
        m_Width->setObjectName(QStringLiteral("m_Width"));

        gridLayout->addWidget(m_Width, 0, 1, 1, 1);

        label_7 = new QLabel(Camerainitialization);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        m_Hue = new QLineEdit(Camerainitialization);
        m_Hue->setObjectName(QStringLiteral("m_Hue"));

        gridLayout->addWidget(m_Hue, 2, 3, 1, 2);

        m_Exposure = new QLineEdit(Camerainitialization);
        m_Exposure->setObjectName(QStringLiteral("m_Exposure"));

        gridLayout->addWidget(m_Exposure, 3, 4, 1, 1);

        label_13 = new QLabel(Camerainitialization);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 1, 2, 1, 1);

        label_3 = new QLabel(Camerainitialization);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(Camerainitialization);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        m_Height = new QLineEdit(Camerainitialization);
        m_Height->setObjectName(QStringLiteral("m_Height"));

        gridLayout->addWidget(m_Height, 1, 1, 1, 1);

        m_Brightness = new QLineEdit(Camerainitialization);
        m_Brightness->setObjectName(QStringLiteral("m_Brightness"));

        gridLayout->addWidget(m_Brightness, 3, 1, 1, 1);

        label_5 = new QLabel(Camerainitialization);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        m_Saturation = new QLineEdit(Camerainitialization);
        m_Saturation->setObjectName(QStringLiteral("m_Saturation"));

        gridLayout->addWidget(m_Saturation, 1, 3, 1, 2);

        m_Contrast = new QLineEdit(Camerainitialization);
        m_Contrast->setObjectName(QStringLiteral("m_Contrast"));

        gridLayout->addWidget(m_Contrast, 0, 3, 1, 2);

        label_6 = new QLabel(Camerainitialization);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        m_Fps = new QLineEdit(Camerainitialization);
        m_Fps->setObjectName(QStringLiteral("m_Fps"));

        gridLayout->addWidget(m_Fps, 2, 1, 1, 1);

        label_15 = new QLabel(Camerainitialization);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 3, 2, 1, 2);

        label_14 = new QLabel(Camerainitialization);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 2, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        m_GetLeftCameraParameter = new QPushButton(Camerainitialization);
        m_GetLeftCameraParameter->setObjectName(QStringLiteral("m_GetLeftCameraParameter"));

        horizontalLayout_3->addWidget(m_GetLeftCameraParameter);

        m_GetRightCameraParameter = new QPushButton(Camerainitialization);
        m_GetRightCameraParameter->setObjectName(QStringLiteral("m_GetRightCameraParameter"));

        horizontalLayout_3->addWidget(m_GetRightCameraParameter);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        m_SetLeftCameraParameter = new QPushButton(Camerainitialization);
        m_SetLeftCameraParameter->setObjectName(QStringLiteral("m_SetLeftCameraParameter"));

        horizontalLayout_4->addWidget(m_SetLeftCameraParameter);

        m_SetRightCameraParameter = new QPushButton(Camerainitialization);
        m_SetRightCameraParameter->setObjectName(QStringLiteral("m_SetRightCameraParameter"));

        horizontalLayout_4->addWidget(m_SetRightCameraParameter);


        verticalLayout_3->addLayout(horizontalLayout_4);


        gridLayout_4->addLayout(verticalLayout_3, 1, 0, 1, 1);


        gridLayout_3->addWidget(Camerainitialization, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        m_CudaState = new QLabel(groupBox_3);
        m_CudaState->setObjectName(QStringLiteral("m_CudaState"));
        m_CudaState->setGeometry(QRect(110, 29, 120, 17));
        m_CudaState->setMinimumSize(QSize(120, 0));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(13, 29, 961, 111));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        m_UseCuda = new QCheckBox(layoutWidget);
        m_UseCuda->setObjectName(QStringLiteral("m_UseCuda"));

        horizontalLayout_7->addWidget(m_UseCuda);

        m_Unfullscreen = new QCheckBox(layoutWidget);
        m_Unfullscreen->setObjectName(QStringLiteral("m_Unfullscreen"));

        horizontalLayout_7->addWidget(m_Unfullscreen);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        m_Startbutton = new QPushButton(layoutWidget);
        m_Startbutton->setObjectName(QStringLiteral("m_Startbutton"));

        horizontalLayout_8->addWidget(m_Startbutton);

        m_Resetbutton = new QPushButton(layoutWidget);
        m_Resetbutton->setObjectName(QStringLiteral("m_Resetbutton"));

        horizontalLayout_8->addWidget(m_Resetbutton);


        verticalLayout_5->addLayout(horizontalLayout_8);


        gridLayout_3->addWidget(groupBox_3, 2, 0, 1, 2);

        StereoViewClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(StereoViewClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1011, 26));
        StereoViewClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(StereoViewClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        StereoViewClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(StereoViewClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        StereoViewClass->setStatusBar(statusBar);

        retranslateUi(StereoViewClass);

        QMetaObject::connectSlotsByName(StereoViewClass);
    } // setupUi

    void retranslateUi(QMainWindow *StereoViewClass)
    {
        StereoViewClass->setWindowTitle(QApplication::translate("StereoViewClass", "StereoView", 0));
        CameraState->setTitle(QApplication::translate("StereoViewClass", "\347\233\270\346\234\272\347\212\266\346\200\201", 0));
        RefreshCameraState->setText(QApplication::translate("StereoViewClass", "\346\211\213\345\212\250\345\210\267\346\226\260\347\233\270\346\234\272\347\212\266\346\200\201", 0));
        m_ChangeCamera->setText(QApplication::translate("StereoViewClass", "\345\267\246\345\217\263\347\233\270\346\234\272\344\272\244\346\215\242", 0));
        label->setText(QApplication::translate("StereoViewClass", "\345\267\246\347\233\270\346\234\272", 0));
        label_2->setText(QApplication::translate("StereoViewClass", "\345\217\263\347\233\270\346\234\272", 0));
        StereoCalibration->setTitle(QApplication::translate("StereoViewClass", "\347\233\270\346\234\272\347\237\253\346\255\243", 0));
        label_16->setText(QApplication::translate("StereoViewClass", "\347\236\263\350\267\235\350\260\203\350\212\202", 0));
        m_Pdedit->setText(QApplication::translate("StereoViewClass", "0", 0));
        m_LockedCalibration->setText(QApplication::translate("StereoViewClass", "\345\272\224\347\224\250\347\237\253\346\255\243", 0));
        m_useCalibrate->setText(QApplication::translate("StereoViewClass", "\345\220\257\347\224\250\347\233\270\346\234\272\347\237\253\346\255\243\357\274\210\344\273\205\345\234\250\347\233\270\346\234\272\347\225\270\345\217\230\346\210\226\350\247\222\345\272\246\345\267\256\350\276\203\345\244\247\346\227\266\344\275\277\347\224\250\357\274\211", 0));
        m_useyml->setText(QApplication::translate("StereoViewClass", "\344\275\277\347\224\250\346\240\207\345\256\232\345\217\202\346\225\260\347\237\253\346\255\243", 0));
        m_Calibrateroot->setText(QApplication::translate("StereoViewClass", "...", 0));
        m_Manual->setText(QApplication::translate("StereoViewClass", "\346\211\213\345\212\250\350\260\203\346\225\264", 0));
        label_17->setText(QApplication::translate("StereoViewClass", "\345\267\246\347\233\270\346\234\272\350\247\222\345\272\246", 0));
        m_Leftangleedit->setText(QApplication::translate("StereoViewClass", "0", 0));
        label_18->setText(QApplication::translate("StereoViewClass", "\345\217\263\347\233\270\346\234\272\350\247\222\345\272\246", 0));
        m_Rightangleedit->setText(QApplication::translate("StereoViewClass", "0", 0));
        label_19->setText(QApplication::translate("StereoViewClass", "\345\205\211\350\275\264\350\247\222\345\272\246", 0));
        m_Mainangleedit->setText(QApplication::translate("StereoViewClass", "0", 0));
        label_20->setText(QApplication::translate("StereoViewClass", "\347\224\273\351\235\242\344\277\235\347\225\231", 0));
        m_remainall->setText(QApplication::translate("StereoViewClass", "\345\205\250\347\224\273\351\235\242\344\277\235\347\225\231", 0));
        m_remainmax->setText(QApplication::translate("StereoViewClass", "\346\234\200\345\244\247\347\224\273\351\235\242\344\277\235\347\225\231", 0));
        Camerainitialization->setTitle(QApplication::translate("StereoViewClass", "\345\210\235\345\247\213\345\214\226\345\217\202\346\225\260\357\274\210\345\267\246\345\217\263\347\233\270\346\234\272\344\270\200\350\207\264\357\274\214\351\235\236\347\211\271\346\256\212\347\233\270\346\234\272\344\270\215\345\205\201\350\256\270\346\233\264\346\224\271\347\233\270\346\234\272\345\217\202\346\225\260\357\274\211", 0));
        label_7->setText(QApplication::translate("StereoViewClass", "\345\257\271\346\257\224\345\272\246", 0));
        label_13->setText(QApplication::translate("StereoViewClass", "\351\245\261\345\222\214\345\272\246", 0));
        label_3->setText(QApplication::translate("StereoViewClass", "\345\256\275\345\272\246", 0));
        label_4->setText(QApplication::translate("StereoViewClass", "\351\253\230\345\272\246", 0));
        label_5->setText(QApplication::translate("StereoViewClass", "\345\270\247\346\225\260", 0));
        label_6->setText(QApplication::translate("StereoViewClass", "\344\272\256\345\272\246", 0));
        label_15->setText(QApplication::translate("StereoViewClass", "\346\233\235\345\205\211\345\272\246", 0));
        label_14->setText(QApplication::translate("StereoViewClass", "\350\211\262\350\260\203", 0));
        m_GetLeftCameraParameter->setText(QApplication::translate("StereoViewClass", "\350\216\267\345\217\226\345\267\246\347\233\270\346\234\272\345\217\202\346\225\260", 0));
        m_GetRightCameraParameter->setText(QApplication::translate("StereoViewClass", "\350\216\267\345\217\226\345\217\263\347\233\270\346\234\272\345\217\202\346\225\260", 0));
        m_SetLeftCameraParameter->setText(QApplication::translate("StereoViewClass", "\350\256\276\347\275\256\345\267\246\347\233\270\346\234\272\345\217\202\346\225\260", 0));
        m_SetRightCameraParameter->setText(QApplication::translate("StereoViewClass", "\350\256\276\347\275\256\345\217\263\347\233\270\346\234\272\345\217\202\346\225\260", 0));
        groupBox_3->setTitle(QApplication::translate("StereoViewClass", "\350\247\206\345\261\217\346\216\247\345\210\266", 0));
        m_CudaState->setText(QString());
        m_UseCuda->setText(QApplication::translate("StereoViewClass", "\344\275\277\347\224\250CUDA", 0));
        m_Unfullscreen->setText(QApplication::translate("StereoViewClass", "\345\217\226\346\266\210\345\205\250\345\261\217", 0));
        m_Startbutton->setText(QApplication::translate("StereoViewClass", "Start", 0));
        m_Resetbutton->setText(QApplication::translate("StereoViewClass", "Reset", 0));
    } // retranslateUi

};

namespace Ui {
    class StereoViewClass: public Ui_StereoViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEREOVIEW_H
