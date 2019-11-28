#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QKeyEvent>
#include <QBoxLayout>
#include <QPushButton>
#include <QListWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void keyPressEvent(QKeyEvent *);

private slots:
    void SendMessage();

private:
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *helpMenu;

    QAction *Option;

    QListWidget *list;

    QTextEdit *Message;
    QTextEdit *Reply;

    QPushButton *Send;

    QVBoxLayout *layoutText;
    QHBoxLayout *layoutMB;
    QHBoxLayout *layout;

};
#endif // WIDGET_H
