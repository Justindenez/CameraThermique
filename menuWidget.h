#ifndef MENU_WIDGET
#define MENU_WIDGET

#include <QtCore>
#include <QWidget>
#include <QLabel>
#include <fstream>
#include <iostream>
#include <QFocusEvent>


//we extend QLabel to give it an extra slot, setImage
//this is because we can't pass a QPixmap from our thread
//so we have to pass a QImage and turn the QImage into a QPixmap on our end

class menuWidget : public QWidget {
  Q_OBJECT;

  public:
    menuWidget(QWidget *parent =  0);
    ~menuWidget();
    //void mousePressEvent(QMouseEvent *ev);
    void focusOutEvent(QFocusEvent *event);
    //void hideEvent(QHideEvent *event);
  signals:
  //void clic(int Mouse_X, int Mouse_Y);
  
};

#endif
