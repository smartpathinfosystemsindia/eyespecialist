/*************************************************(((
*
*              Fukebane     : imgfiledialog.cpp
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
#include <QtGui>
#include "imgfiledialog.h"

#include <QFileDialog>
#include <QMessageBox>

ImgFileDialog::ImgFileDialog(QWidget *parent)
    : QWidget(parent)
{
	printf("Started the dialog\n");
  //  updateInterface(NavigationMode);
}

#ifdef GG
//! [saveToFile() function part1]
void ImgFileDialog::saveToFile()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Address Book"), "",
        tr("Address Book (*.abk);;All Files (*)"));

//! [saveToFile() function part1]
//! [saveToFile() function part2]
    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
        }

        //out << contacts;
    }
	strImageName = fileName;       
}
#endif

void ImgFileDialog::loadFromFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Address Book"), "",
        tr("Address Book (*.abk);;All Files (*)"));
//! [loadFromFile() function part1]

//! [loadFromFile() function part2]
    if (fileName.isEmpty())
        return;
    else {
        
        QFile file(fileName);
        
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
        }
}
      strImgName=fileName;
	
}

void ImgFileDialog::showMessage(const char *str)
{
            QMessageBox::information(this, str,
                "file not specified correctly");

}

