#-------------------------------------------------
#
# Project created by QtCreator 2019-02-07T15:25:36
#
#-------------------------------------------------

QT       += core gui opengl

LIBS += opengl32.lib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OGL-test
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

DISTFILES +=

RESOURCES += \
    shaders.qrc \
    textures.qrc
