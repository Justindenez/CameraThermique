#ifndef WINDOW_H
#define WINDOW_H

#include <QtCore>
#include <QWidget>
#include <QWindow>
#include <QApplication>
#include <QThread>
#include <QImage>
#include <QMutex>
#include <QMessageBox>
#include <QMenuBar>
#include <QMenu>
#include <QMainWindow>
#include <QScreen>
#include <QColor>
#include <QLabel>
#include <QtDebug>
#include <QString>
#include <QPushButton>
#include <QFileDialog>
#include <QDateTime>
#include <QBoxLayout>
#include <QGroupBox>

#include "LeptonThread.h"
#include "MyLabel.h"
#include "Palettes.h"
#include "MyWidget.h"
#include "menuWidget.h"
#include "cameraworker.h"
#include <raspicam/raspicam.h>

#include <fstream>
#include <iostream>

#include <QDebug>
#include <QWindow>
#include <QMouseEvent>
#include <QApplication>
#include <QGenericMatrix>
#include <QColor>
#include <QSlider>
#include <QPainter>
#include <QPixmap>
#include <QGraphicsItem>
#include <QThread>
#include <QSpinBox>
  
#include "unistd.h"


class Window : public QWindow {
  Q_OBJECT;

  public:
     explicit Window(QWindow *parent);
    ~Window();
    MyWidget *window;
    MyLabel *myLabel;
    LeptonThread *thread;
    int NbrCap;
    
  public slots:
    void grad(MyLabel*, int);
    void main();
    void Capture();
    void Save();
    void Quit();
    void vid(int a);
  signals:
  void stop();

};

#endif
