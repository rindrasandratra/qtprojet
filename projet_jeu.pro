#-------------------------------------------------
#
# Project created by QtCreator 2016-10-15T22:55:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projet_jeu
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cercle.cpp \
    cercle_widget.cpp \
    aiguille.cpp \
    Question.cpp \
    score.cpp \
    Acceuil.cpp

HEADERS  += mainwindow.h \
    cercle.h \
    cercle_widget.h \
    aiguille.h \
    Question.h \
    score.h \
    Acceuil.h
    
RESOURCES += ressource.qrc


CONFIG += mobility
MOBILITY = 

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/ressource
