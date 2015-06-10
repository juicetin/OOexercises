#-------------------------------------------------
#
# Project created by QtCreator 2015-05-14T15:13:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Curser
TEMPLATE = app


SOURCES += main.cpp\
        Dialog.cpp \
    Cursor.cpp \
    StandardCursorState.cpp \
    EraserState.cpp

HEADERS  += Dialog.h \
    Cursor.h \
    CursorState.h \
    StandardCursorState.h \
    EraserState.h \
    Command.h \
    KeyPressCommand.h \
    MouseClickCommand.h \
    MouseScrollCommand.h

FORMS    += Dialog.ui
