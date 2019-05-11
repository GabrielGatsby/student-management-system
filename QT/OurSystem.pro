#-------------------------------------------------
#
# Project created by QtCreator 2018-04-30T16:01:30
#
#-------------------------------------------------

QT       += core gui

QT+=axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OurSystem
TEMPLATE = app


SOURCES += main.cpp\
    schoolstaff.cpp \
    function.cpp \
    student.cpp \
    course.cpp \
    teachingstaff.cpp \
    teacher.cpp \
    teachingmanager.cpp \
    teacherinterface.cpp \
    testcode.cpp \
    welcome.cpp \
    teachingmanagerinterface.cpp \
    studentfunction.cpp \
    registerstudent.cpp \
    mainwindow.cpp \
    registerteacher.cpp \
    registerteachingmanager.cpp \
    studentquitshcool.cpp

HEADERS  += \
    schoolstaff.h \
    function.h \
    student.h \
    course.h \
    teachingstaff.h \
    teacher.h \
    teachingmanager.h \
    teacherinterface.h \
    myhashmap.h \
    testcode.h \
    welcome.h \
    teachingmanagerinterface.h \
    student.h \
    studentfunction.h \
    registerstudent.h \
    mainwindow.h \
    registerteacher.h \
    registerteachingmanager.h \
    hashtable.h \
    studentquitshcool.h

FORMS    += \
    teacherinterface.ui \
    welcome.ui \
    teachingmanagerinterface.ui \
    studentfunction.ui \
    registerstudent.ui \
    mainwindow.ui \
    registerteacher.ui \
    registerteachingmanager.ui \
    studentquitshcool.ui
RC_ICONS=xuesheng.ico
