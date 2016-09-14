/************************************************(((
*
*              Fukebane     : main.cpp
*		Description :  window launcher for the red eye detection tool
*
* 		Copyright (C) Smartpath infosystems india, Bangalore
		email to us for further information on team@smartpathindia.com
*
*
*
****************************************************/
#include <QApplication>
//#include <QtGui/QApplication>
#include <qgraphicsview.h>
#include <eyespecialistmw.h>

int main(int argc, char *argv[])
{
QApplication a(argc, argv);
#ifdef GG
QGraphicsView* w = new QGraphicsView();
QGraphicsScene *scn = new QGraphicsScene( w );
scn->setSceneRect( w->rect() );
w->setScene( scn );
w->setFixedSize( 800, 800 );
QPixmap pix( argv[1] );
scn->addPixmap( pix );
w->show();
#endif
EyeSpecialistMW mw;
mw.show();
a.connect( &a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
return a.exec();
}
