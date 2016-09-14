/*************************************************(((
*
*              Fukebane     imgfiledialog.h
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
#ifndef IMGFILEDIALIG_H
#define IMGFILEDIALIG_H

#include <QWidget>
#include <QMap>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QLineEdit;
class QTextEdit;
QT_END_NAMESPACE


class ImgFileDialog : public QWidget
{
    Q_OBJECT

public:
    ImgFileDialog(QWidget *parent = 0);

public:
  //  void saveToFile();
    void loadFromFile();
    void showMessage(const char *str);
    QString getImageFileName()
    {
	return strImgName;
    }


private:
	QString strImgName;
};

#endif
