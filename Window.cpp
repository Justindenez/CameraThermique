#include "Window.h"

Window::Window(QWindow *parent) : QWindow(parent)
{
	window = new MyWidget();
	myLabel = new MyLabel(window);
	thread = new LeptonThread();
	NbrCap=100;
}

Window::~Window()
{
}

QStringList dir; //path to the directory were we save outout



void Window::vid(int a){
	QString name;
	name.append("imgCam_");
	name.append(QString::number(100000+NbrCap-a));
	name.append(".png");

	//Take the screenshoot
	QPixmap *originalPixmap = new QPixmap();
	*originalPixmap = myLabel->grab(QRect(QPoint(0, 30), QSize(320, 240)));
	
	
	//Save the Capture
	QFile file(name);
	file.open(QIODevice::WriteOnly);
	originalPixmap->save(&file,"PNG");
	
	if(a==0){
		QDateTime time = QDateTime::currentDateTime();
		QString com;
		com.append("echo y | ffmpeg -framerate 10 -pattern_type glob -i '*.png' -c:v ffv1 Video_");
		com.append(time.toString("yyyy_MM_dd_hh_mm_ss"));
		com.append(".avi");
		QByteArray ba = com.toLocal8Bit();
		const char *c_str2 = ba.data();
		system(c_str2);
		
		system("rm imgCam_*.png");

	}
}

void Window::Quit(){
		system("shutdown -P now");
	}
	
//Print the temperature's gratient depending off the colormap
void Window::grad(MyLabel* myGrad, int typeColormap){
	
	QImage grad;
	grad = QImage(20,255, QImage::Format_RGB888);
	QRgb value;
	
	int i=0;
	int j;
	switch (typeColormap) {
		case 1:
			while(colormap_rainbow[i]!=-1 && i<=3*255-1){
				value = qRgb(colormap_rainbow[i],colormap_rainbow[i+1],colormap_rainbow[i+2]);
				j=0;
				while(j<20){
					grad.setPixel(j, i/3, value);
					j=j+1;
				}
				i=i+3;
			}
			break;
		case 2:
			while(colormap_grayscale[i]!=-1 && i<=3*255-1){
				value = qRgb(colormap_grayscale[i],colormap_grayscale[i+1],colormap_grayscale[i+2]);
				j=0;
				while(j<20){
					grad.setPixel(j, i/3, value);
					j=j+1;
				}
				i=i+3;
			}
			break;
		default:
			while(colormap_ironblack[i]!=-1 && i<=3*255-1){
				value = qRgb(colormap_ironblack[i],colormap_ironblack[i+1],colormap_ironblack[i+2]);
				j=0;
				while(j<20){
					grad.setPixel(j, i/3, value);
					j=j+1;
				}
				i=i+3;
			}
			break;
		}
		myGrad->setImage(grad);
	}
	
//Take a screenshot and save it
void Window::Capture(){
		
	//Get the time to put it in the file name
	QDateTime time = QDateTime::currentDateTime();
	
	QString name;
	name.append("Capture_");
	name.append(time.toString("yyyy_MM_dd_hh_mm_ss"));
	name.append(".png");

	//Take the screenshoot
	QPixmap *originalPixmap = new QPixmap();
	*originalPixmap = window->grab(QRect(QPoint(0, 30), QSize(640, 450)));
	
	//Save the Capture
	QFile file(name);
	file.open(QIODevice::WriteOnly);
	originalPixmap->save(&file,"PNG");
	
	QString name2;
	name2.append("Lepton_");
	name2.append(time.toString("yyyy_MM_dd_hh_mm_ss"));
	name2.append(".png");
	QPixmap *originalPixmap2 = new QPixmap();
	*originalPixmap2 = myLabel->grab(QRect(QPoint(0, 0), QSize(320, 240)));
	QFile file2(name2);
	file2.open(QIODevice::WriteOnly);
	originalPixmap2->save(&file2,"PNG");
	
	QString name3;
	name3.append("Data_");
	name3.append(time.toString("yyyy_MM_dd_hh_mm_ss"));
	name3.append(".txt");
	QFile file3(name3);
	file3.open(QIODevice::WriteOnly);	
	QTextStream out(&file3);
    out << "Minimal : " << thread->min <<"\nMaximal : "<< thread->max<<"\n";
    int index, index2;
    for ( index=0; index<160;index++){
		for ( index2=0; index2<120;index2++){
			out << thread->myImageRaw(index,index2)<< " ";
		}
		out << "\n";
	}


	//QAviWriter writer("testVid.avi", QSize(800,600),24,"MJPG");
	/*
	writer.open();
	
	writer.addFrame(*originalPixmap);
	*originalPixmap = screen->grabWindow(0);
	usleep(200);
	
	writer.addFrame(*originalPixmap);
	*originalPixmap = screen->grabWindow(0);
	usleep(200);
	
	writer.addFrame(*originalPixmap);
	*originalPixmap = screen->grabWindow(0);
	usleep(200);
	
	writer.addFrame(*originalPixmap);
	*originalPixmap = screen->grabWindow(0);
	usleep(200);
	
	writer.addFrame(*originalPixmap);
	*originalPixmap = screen->grabWindow(0);
	usleep(200);
	
	writer.addFrame(*originalPixmap);
	*originalPixmap = screen->grabWindow(0);
	usleep(200);
	
	writer.close();*/
	
	}

//Chose the output directory 
void Window::Save(){
	
	QFileDialog dialog;
	dialog.setFileMode(QFileDialog::Directory);
	dialog.setFocusPolicy(Qt::NoFocus);

	if (dialog.exec()){
		dir = dialog.selectedFiles();
		
	}
	QDir::setCurrent(dir[0].toLocal8Bit().constData());
}


void Window::main(){
	
	//Lepton parameters
	int typeColormap = 3; // colormap_ironblack
	int typeLepton = 3; // Lepton 3.x
	int spiSpeed = 30; // SPI bus speed 30MHz
	int rangeMin = -1; 
	int rangeMax = -1; 
	int loglevel = 0;
	
	// Initialize the thread and worker for the camera
    QThread *workerThread = new QThread;
    CameraWorker *worker = new CameraWorker;
    
    worker->moveToThread(workerThread);
    workerThread->start();

	//Create the main window
	//MyWidget *window = new MyWidget();
	window->setGeometry(0, 2, 800, 480);

	//Create the camera label
	MyLabel *cam = new MyLabel(window);
	cam->setGeometry(0, 0,640,480);
	cam->show();

	//Connect the label to the camera
	connect(worker, SIGNAL(handleImage(QImage &)), cam, SLOT(setImage(QImage)));

	//Add a menu bar
	QMenuBar *menubar = new QMenuBar(window);
	QMenu *editmenu = new QMenu("Edit",window);
	QMenu *quitmenu = new QMenu("Quit",window);
	menubar->addMenu(editmenu);
	menubar->addMenu(quitmenu);
	menubar->setNativeMenuBar(1);
	menubar->setVisible(1);
	
	QAction *display = editmenu->addAction("Display");
	QAction *output = editmenu->addAction("Output");
	QAction *quit = quitmenu->addAction("Shutdown");
	QObject::connect(quit, SIGNAL(triggered()),this ,SLOT(Quit()));
	
	
	
	
	//create a label for the lepton
	QImage myImage;
	//MyLabel *myLabel = new MyLabel(window);
	myLabel->setGeometry(160, 120, 320, 240);
	myLabel->setPixmap(QPixmap::fromImage(myImage));
	myLabel->raise();
	//myLabel->setGeometry(0,0,0,0);
	
	//create a label for the maximum
	MyLabel *myMax = new MyLabel(window);
	myMax->setGeometry(660,320, 100, 20);
	myMax->setText("test");

	//create a label for the minimum
	MyLabel *myMin = new MyLabel(window);
	myMin->setGeometry(660,40, 100, 20);
	myMin->setText("test");

	//Create a label for the gradient 
	MyLabel *myGrad = new MyLabel(window);
	myGrad->setGeometry(660,60, 20, 255);
	this->grad(myGrad, typeColormap);
	
	//Create the picked temperature layout
	QWidget *temp2 = new QWidget(window);
	temp2->setGeometry(640,352, 200, 75);
	
	MyLabel *temperature = new MyLabel(window);
	temperature->setGeometry(0,0, 0, 0);
	temperature->setText("température______");
	temperature->setAlignment(Qt::AlignHCenter);
	QGroupBox *box3 = new QGroupBox("Picked temperature",temp2);
	QBoxLayout *layout3 = new QBoxLayout(QBoxLayout::TopToBottom,temp2);
	layout3->addWidget(temperature);
	layout3->addStretch(0);
	box3->setLayout(layout3);
	box3->setAlignment(Qt::AlignHCenter);
	
	//Create the capture button
	QPushButton *CaptureButton = new QPushButton("Capture", window);
	CaptureButton->setGeometry(690, 120, 100, 30);
	QObject::connect(CaptureButton, SIGNAL(clicked()), this, SLOT(Capture()));
	
	QPushButton *Vid = new QPushButton("Video", window);
	Vid->setGeometry(690, 170, 100, 30);
	QObject::connect(Vid, &QPushButton::clicked, this, [=]{thread->video=1; thread->num=NbrCap;});


	
	//Create the edit window
	menuWidget *editW = new menuWidget();
	editW->setGeometry(640, 2, 160, 480);
	editW->setFocusPolicy(Qt::ClickFocus );
	editW->setFocus(Qt::MouseFocusReason);
	//create a thread to gather SPI data
	//when the thread emits updateImage, the label should update its image accordingly
	
	thread->setLogLevel(loglevel);
	thread->useColormap(typeColormap);
	thread->useLepton(typeLepton);
	thread->useSpiSpeedMhz(spiSpeed);
	thread->setAutomaticScalingRange();
	thread->setAlpha(255);
	if (0 <= rangeMin) thread->useRangeMinValue(rangeMin);
	if (0 <= rangeMax) thread->useRangeMaxValue(rangeMax);
	
	QObject::connect(thread, SIGNAL(updateImage(QImage)), myLabel, SLOT(setImage(QImage)));
	QObject::connect(thread, SIGNAL(updateTextMax(QString)), myMax, SLOT(setText2(QString)));
	QObject::connect(thread, SIGNAL(updateTextMin(QString)), myMin, SLOT(setText2(QString)));
	QObject::connect(thread, &LeptonThread::updateImageRaw, temperature, [=]{uint16_t data; data = thread->myImageRaw(window->Mouse_X,window->Mouse_Y);temperature->setText(QString::number(data));});


	//Add a action to the display button in the menu bar
	QObject::connect(display, SIGNAL(triggered()),editW ,SLOT(show()));
	
	//Create the tree colormap buttons and layout
	QPushButton *setIron = new QPushButton("ironblack", editW);
	setIron->setGeometry(0, 0, 100, 30);
	setIron->setFocusPolicy(Qt::NoFocus);
	QObject::connect(setIron, &QPushButton::clicked,  thread, [this, myGrad]{usleep(2000); thread->terminate(); thread->useColormap(3); usleep(2000); thread->start();this->grad(myGrad, 3);});

	QPushButton *setGrey = new QPushButton("Greyscale", editW);
	setGrey->setGeometry(0, 30, 100, 30);
	setGrey->setFocusPolicy(Qt::NoFocus);
	QObject::connect(setGrey, &QPushButton::clicked,  thread, [this, myGrad]{usleep(2000); thread->terminate(); thread->useColormap(2); usleep(2000); thread->start();this->grad(myGrad, 2);});

	QPushButton *setBow = new QPushButton("rainbow", editW);
	setBow->setGeometry(0, 60, 100, 30);
	setBow->setFocusPolicy(Qt::NoFocus);
	QObject::connect(setBow, &QPushButton::clicked, thread, [this, myGrad]{usleep(2000); thread->terminate(); thread->useColormap(1); usleep(2000); thread->start();this->grad(myGrad, 1);});
	
	QWidget *colormap = new QWidget(editW);
	colormap->setGeometry(30, 20, 150, 300);
	
	QGroupBox *box = new QGroupBox("Thermal Colormap",colormap);
	QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom,colormap);
	layout->addWidget(setIron);
	layout->addWidget(setGrey);
	layout->addWidget(setBow);
	layout->addStretch(0);
	box->setLayout(layout);
	box->setAlignment(Qt::AlignHCenter);

	//Create the alpha layout
	QWidget *slide = new QWidget(editW);
	slide->setGeometry(30, 180, 150, 300);
	slide->setFocusPolicy(Qt::NoFocus);

	QSlider *alphaSlide = new QSlider(Qt::Horizontal, slide);
	alphaSlide->setMinimum(0);
	alphaSlide->setMaximum(255);
	alphaSlide->setValue(255);
	alphaSlide->setFocusPolicy(Qt::NoFocus);

	QGroupBox *box2 = new QGroupBox("alpha",slide);
	
	QBoxLayout *layout2 = new QBoxLayout(QBoxLayout::TopToBottom,slide);
	layout2->addWidget(alphaSlide);
	layout2->addStretch(0);
	box2->setLayout(layout2);
	box2->setAlignment(Qt::AlignHCenter);
	
	QObject::connect(alphaSlide, SIGNAL(valueChanged(int)), thread, SLOT(setAlpha(int)));

	//create a FFC button
	QPushButton *FFC = new QPushButton("Perform FFC", editW);
	FFC->setGeometry(30, 300, 100, 30);
	QObject::connect(FFC, SIGNAL(clicked()), thread, SLOT(performFFC()));


	//Create the ok button
	QPushButton *confirm = new QPushButton("OK", editW);
	confirm->setGeometry(30, 400, 100, 30);
	QObject::connect(confirm, SIGNAL(clicked()), editW, SLOT(close()));
	
	
	
	
	QWidget *OutputWindow = new QWidget();
	OutputWindow->setGeometry(0, 2, 800, 480);
	OutputWindow->setFocusPolicy(Qt::ClickFocus );
	OutputWindow->setFocus(Qt::MouseFocusReason);
	
	QLabel *Chose = new QLabel("Output directory :", OutputWindow);
	Chose->setGeometry(170,5, 150, 20);
	Chose->setFocusPolicy(Qt::NoFocus);

	QWidget *dirWiget = new QWidget(OutputWindow);
	dirWiget->setGeometry(100, 0, 800, 480);
	dirWiget->setFocusPolicy(Qt::NoFocus);
	
	MyLabel *UserDir = new MyLabel(OutputWindow);
	UserDir->setGeometry(200,50, 800, 30);
	UserDir->setText("NONE");
	UserDir->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
	
	QPushButton *location = new QPushButton("Change directory", OutputWindow);
	location->setGeometry(0, 50, 300, 30);
	location->setFocusPolicy(Qt::NoFocus);

	QObject::connect(location, SIGNAL(clicked()), this, SLOT(Save()));
	QObject::connect(location, &QPushButton::clicked,  UserDir, [UserDir, this]{UserDir->setText(dir[0].toLocal8Bit().constData());UserDir->adjustSize();});

	QGroupBox *box4 = new QGroupBox("Change Output directory",dirWiget);
	
	QBoxLayout *layout4 = new QBoxLayout(QBoxLayout::LeftToRight,dirWiget);
	layout4->addWidget(Chose);
	layout4->addWidget(UserDir);
	layout4->addWidget(location);
	layout4->addStretch(0);
	box4->setLayout(layout4);
	box4->setAlignment(Qt::AlignHCenter);
	box4->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

	dir <<"/home/pi/Documents/CameraThermique/Output";
	QDir::setCurrent(dir[0].toLocal8Bit().constData());
	UserDir->setText(dir[0].toLocal8Bit().constData());
	
	QObject::connect(output, SIGNAL(triggered()),OutputWindow ,SLOT(show()));
	
	
	
	QWidget *FrameWiget = new QWidget(OutputWindow);
	FrameWiget->setGeometry(300, 100, 800, 480);
	FrameWiget->setFocusPolicy(Qt::NoFocus);

	MyLabel *duree = new MyLabel(OutputWindow);
	duree->setGeometry(300, 300, 100, 30);
	duree->setText("Length");
	
	QSpinBox *frame = new QSpinBox(OutputWindow);
	frame->setRange(0, 1200);
	frame->setGeometry(400, 300, 100, 30);
	frame->setValue(10);
	frame->setSuffix(" s");
	
	QGroupBox *box5 = new QGroupBox("Change Video length",FrameWiget);
	
	QBoxLayout *layout5 = new QBoxLayout(QBoxLayout::LeftToRight,FrameWiget);
	layout5->addWidget(duree);
	layout5->addWidget(frame);
	layout5->addStretch(0);
	box5->setLayout(layout5);
	box5->setAlignment(Qt::AlignHCenter);
	box5->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
	
	connect(frame, QOverload<int>::of(&QSpinBox::valueChanged),[=](int i){ NbrCap=i*10; });






	//Create the ok button
	QPushButton *confirmOut = new QPushButton("OK", OutputWindow);
	confirmOut->setGeometry(350, 400, 100, 30);
	QObject::connect(confirmOut, SIGNAL(clicked()), OutputWindow, SLOT(close()));
	QObject::connect(confirmOut, &QPushButton::clicked,  frame, [this, frame]{this->NbrCap=10*frame->value();});
	
	QObject::connect(window, SIGNAL(close()), thread, SLOT(quit()));
	QObject::connect(window, SIGNAL(close()), workerThread, SLOT(quit()));
	QObject::connect(window, SIGNAL(close()), editW, SLOT(close()));
	QObject::connect(window, SIGNAL(close()), this, SLOT(close()));
	
	QObject::connect(thread, SIGNAL(Capture(int)), this, SLOT(vid(int)));

	
	window->show();
	
	thread->start();
	
	worker->doWork();
	
}
