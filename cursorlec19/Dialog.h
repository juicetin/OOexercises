#ifndef DIALOG_H
#define DIALOG_H

#include "Cursor.h"
#include "Command.h"
#include "KeyPressCommand.h"
#include "MouseClickCommand.h"
#include "MouseScrollCommand.h"
#include <QDialog>

namespace Ui
{
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
    void keyPressEvent(QKeyEvent* event);
    void wheelEvent(QWheelEvent* event);
    void mousePressEvent(QMouseEvent * event);

private:
    Ui::Dialog *m_ui;
    Cursor *m_cursor;
    Command *m_keyPressCommand;
    Command *m_mouseClick;
    Command *m_mouseScrollCommand;
};

#endif // DIALOG_H
