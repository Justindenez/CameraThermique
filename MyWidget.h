#ifndef MY_WIDGET
#define MY_WIDGET

#include <QtCore>
#include <QWidget>
#include <QLabel>
#include <fstream>
#include <iostream>
#include <QMouseEvent>
#include <stdlib.h>
#include <cstdlib>
#include "MyLabel.h"

//we extend QLabel to give it an extra slot, setImage
//this is because we can't pass a QPixmap from our thread
//so we have to pass a QImage and turn the QImage into a QPixmap on our end

class MyWidget : public QWidget {
  Q_OBJECT;

  public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();
	void mousePressEvent(QMouseEvent *ev);
	void closeEvent(QCloseEvent *ev);
	int Mouse_X;
	int Mouse_Y;
	MyLabel *crossLab = new MyLabel(this);	

  signals:
  void clic(int Mouse_X, int Mouse_Y);
  void close();
};

#endif
