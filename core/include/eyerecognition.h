/*************************************************(((
*
*              Fukebane     : eyerecongnition.h
*		Description :  window launcher for the red eye detection tool
*
* 		Copyright (C) Smartpath infosystems india, Bangalore
*		email to us for further information on team@smartpathindia.com
*
*
*
*
*
****************************************************/
#ifndef EYERE_H
#define EYEREC_H

#include <QWidget>
#include <QMap>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QLineEdit;
class QTextEdit;
QT_END_NAMESPACE


class EyeRecognition
{

public:
    EyeRecognition(const char *trainingdir);

public:
	int faceCount(char *imagfile, char *training);
	int detectface(char *imagefile);
	int set_training_path(const char *trainingpath);

private:
	QString strImgName;
	QString  TrainingDirectory;
	QString presentTrainingFile;
	char trainingdata[512];
};

#endif
