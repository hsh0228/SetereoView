#include "stereoview.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	StereoView w;
	w.show();


	return a.exec();
}
