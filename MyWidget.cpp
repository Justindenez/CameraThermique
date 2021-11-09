#include "MyWidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
	Mouse_X = 80;
	Mouse_Y = 60;
}
MyWidget::~MyWidget()
{
}

void MyWidget::closeEvent(QCloseEvent *ev){
	ev->accept();
	emit close();
	QWidget::closeEvent(ev);

}
void MyWidget::mousePressEvent(QMouseEvent *ev){
    
    
	
	QImage cross;
	cross.load("/home/pi/Documents/CameraThermique/cross.svg");
	QPixmap pixmap = QPixmap::fromImage(cross);
	
	
	
	crossLab->setPixmap(pixmap.scaled(10, 10, Qt::KeepAspectRatio));
	crossLab->setParent(this);
	
	ev->accept();
	int x,y;
	x = ev->x();
	y = ev->y();

	if(x>160 && x<480 && y>120 && y<360){
		Mouse_X = (x-160)/2;
		Mouse_Y = (y-120)/2;
		crossLab->setGeometry(x-5,y-100, 200, 200);
		crossLab->raise();
		emit clic(Mouse_X,Mouse_Y);
	}
	
	QWidget::mousePressEvent(ev);
	
}


