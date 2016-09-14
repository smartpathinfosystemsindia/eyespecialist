/*************************************************(((
*
*              Fukebane     : eyespecialist.cpp
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
#include "eyespecialistmw.h"
#include "eyerecognition.h"

EyeSpecialistMW::EyeSpecialistMW(QWidget *parent)
   : QMainWindow(parent)
{
    setupUi(this);

    markedCount = 0;

    connect(ExitAppButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(CaptureFileButton, SIGNAL(clicked()), this, SLOT(on_CaptureFile() ) );
    connect(EyeDetectButton, SIGNAL(clicked()), this, SLOT(on_EyeDetect() ) );

 upscn = new QGraphicsScene(UpGraphicsView);
 upscn->setSceneRect( UpGraphicsView->rect() );
 pscn = new QGraphicsScene(ProcessedGraphicsView );
 pscn->setSceneRect( ProcessedGraphicsView->rect() );
}


void EyeSpecialistMW::on_clearAction_triggered()
{
	printf("triggerd");
}


void EyeSpecialistMW::setupImage(QGraphicsView *pview, QGraphicsScene *s, QString & strName)
{
	if(pview == NULL)
	   return;
pview->setScene( s );
   pview->ensureVisible ( s->sceneRect()  );
    pview->fitInView( s->sceneRect(), Qt::KeepAspectRatio);
//pview->setFixedSize( 800, 800 );
QPixmap pix( strName);
s->addPixmap( pix );
pview->show();
}


void EyeSpecialistMW::on_markAction_triggered()
{
	printf("nothing to do ");
}

void EyeSpecialistMW::on_CaptureFile()
{
	ImgFileDialog d;

	 d.loadFromFile();
 	upFile =   d.getImageFileName();
	if(upFile.isEmpty())
	  d.showMessage("File is empty");
	else
	setupImage(UpGraphicsView, upscn, upFile);
printf("triggerd");
}


void EyeSpecialistMW::on_EyeDetect()
{
	int facecount;
	char mymsg[250];
	ImgFileDialog d;
	EyeRecognition eye("data\\haarcascades");
	if(upFile.isEmpty()) {
	  d.showMessage("File is empty");
	  return;
        }
	eye.set_training_path("./data/haarcascades/haarcascade_frontalface_alt.xml");
	printf("imagepath=%s\n",upFile.toStdString().c_str());
	facecount = eye.detectface((char *)upFile.toStdString().c_str());

        memset(mymsg, 0, 250);
	sprintf(mymsg, "found %d faces in image",facecount);
	d.showMessage(mymsg);
}

