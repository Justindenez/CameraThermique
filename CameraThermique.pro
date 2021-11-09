
TEMPLATE = app
QT += core gui
QT += dbus
QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CameraThermique

RPI_LIBS = ../raspberrypi_libs

LEPTONSDK = leptonSDKEmb32PUB

LIBS += -L/opt/vc/lib -lmmal -lmmal_core -lmmal_util
LIBS += -L/usr/local/lib -I/usr/local/include -lraspicam

PRE_TARGETDEPS += sdk
QMAKE_EXTRA_TARGETS += sdk sdkclean
sdk.commands = make -C $${RPI_LIBS}/$${LEPTONSDK}
sdkclean.commands = make -C $${RPI_LIBS}/$${LEPTONSDK} clean

DEPENDPATH += .

INCLUDEPATH += ../raspberrypi_libs
INCLUDEPATH   += libgwavi/inc
INCLUDEPATH   += libgwavi/src

DESTDIR=.
OBJECTS_DIR=gen_objs
MOC_DIR=gen_mocs

HEADERS += *.h

SOURCES += *.cpp

unix:LIBS += -L$${RPI_LIBS}/$${LEPTONSDK}/Debug -lLEPTON_SDK

unix:QMAKE_CLEAN += -r $(OBJECTS_DIR) $${MOC_DIR}

