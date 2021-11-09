#include "menuWidget.h"

menuWidget::menuWidget(QWidget *parent) : QWidget(parent)
{
}
menuWidget::~menuWidget()
{
}


void menuWidget::focusOutEvent(QFocusEvent *event){
	event->accept();
	//std::cout << "test\n";
	this->close();
	QWidget::focusOutEvent(event);

}


//hideEvent(QHideEvent *event)
