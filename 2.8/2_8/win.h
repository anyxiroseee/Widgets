#ifndef WIN_H
#define WIN_H
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>


class Counter:public QLineEdit
{
     Q_OBJECT

public:
     Counter(const QString & contents, QWidget *parent=0):
     QLineEdit(contents,parent){}

signals:
     void multiplicityFive_signal();

public slots:
     void add_one()
     {
         QString str=text();
         int count=str.toInt();

         if (count!=0 && count%5 ==0)
             emit multiplicityFive_signal();
         count++;
         str.setNum(count);
         setText(str);
     }
};

class Win: public QWidget
{
    Q_OBJECT

protected:
     QTextCodec *codec;
     QLabel *labelByOne,*labelByFive;
     Counter *counterByOne,*counterByFive;
     QPushButton *addOneButton;
     QPushButton *exitButton;

public:
    Win(QWidget *parent = 0);
};
#endif // WIN_H
