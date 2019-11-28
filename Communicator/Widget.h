#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QBoxLayout>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void SendMessage();
private:
    QTextEdit *Message;
    QTextEdit *Reply;
    QPushButton *Send;
    QHBoxLayout *layoutText;
    QVBoxLayout *layout;

};
#endif // WIDGET_H
