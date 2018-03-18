#-------------------------------------------------
#
# Project created by QtCreator 2017-01-24T12:26:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenGL_anima
TEMPLATE = app
CONFIG += c++14

SOURCES += main.cpp\
    mainwindow.cpp \
    mainview.cpp \
    user_input.cpp \
    model.cpp \
    genCube.cpp \
    genPyra.cpp \
    genObj.cpp \
    transform.cpp \
    prepset.cpp \
    genObject.cpp \
    utility.cpp \
    createShader.cpp \
    loadtexture.cpp

HEADERS  += mainwindow.h \
    mainview.h \
    model.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
