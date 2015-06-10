#ifndef CURSORSTATE_H
#define CURSORSTATE_H

#include <QDialog>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include <iostream>

class CursorState
{
public:
        CursorState() {}
        virtual ~CursorState() {}

        virtual void processMouseEvent(QMouseEvent *event, QWidget *dialog) = 0;
        virtual void processMouseEvent(QWheelEvent *event, QWidget *dialog) = 0;

        virtual void updateCursorDisplay(QWidget *dialog) = 0;
};

#endif // CURSORSTATE_H
