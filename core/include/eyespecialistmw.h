/*************************************************(((
*
*              Fukebane     : eyespecialistmw.h
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
#ifndef EYESPECIALUSTMW_H
#define EYESPECIALUSTMW_H



#include "ui_eyespecialistwindow.h"

class QGraphicsScene;
QT_BEGIN_NAMESPACE
class QTextEdit;
class QTreeWidget;
class QTreeWidgetItem;
QT_END_NAMESPACE

typedef QList<QTreeWidgetItem *> StyleItems;

class EyeSpecialistMW : public QMainWindow, private Ui::EyeSpecialistWindow
{
    Q_OBJECT

public:
    EyeSpecialistMW(QWidget *parent = 0);



public slots:
    void on_clearAction_triggered();
    void on_markAction_triggered();
    void on_CaptureFile();
	void  on_EyeDetect();

private:
	QString upFile;
	QString pFile;
	QGraphicsScene *pscn;
	QGraphicsScene *upscn;
    //QMap<QString, StyleItems> pageMap;
    int markedCount;
	void setupImage(QGraphicsView *v, QGraphicsScene *s, QString & strFile);
};

#endif
