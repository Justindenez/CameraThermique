#include <QApplication>
#include <QThread>
#include <QMutex>
#include <QMessageBox>
#include <QMenuBar>
#include <QMenu>
#include <QMainWindow>
#include <QtDBus>
#include <QPixmap>

#include <QColor>
#include <QLabel>
#include <QtDebug>
#include <QString>
#include <QPushButton>

#include "LeptonThread.h"
#include "MyLabel.h"
#include "Palettes.h"
#include "Window.h"

#include <fstream>
#include <iostream>

#include "unistd.h"


int main( int argc, char **argv )
{

	//create the app
	QApplication app( argc, argv );
	QWindow *test = new QWindow;
	
	//Create the MainWindow whitch is the core of the app
	Window mainwindow(test);
	mainwindow.setMouseGrabEnabled(true);
	

	
	//Start the MainWindow
	mainwindow.main();
	
	return app.exec();

}
