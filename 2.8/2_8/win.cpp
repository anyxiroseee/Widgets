#include "win.h"
#include <QTextCodec>
#include <QBoxLayout>

Win::Win(QWidget *parent):QWidget(parent)
{
     codec = QTextCodec::codecForName("UTF-8");
     this->setWindowTitle(codec->toUnicode("Счетчик"));

     labelByOne = new QLabel(codec->toUnicode("Cчет по 1"),this);
     labelByFive = new QLabel(codec->toUnicode("Cчет по 5"),this);

     counterByOne = new Counter("0",this);
     counterByFive = new Counter("0",this);

     addOneButton=new QPushButton("+1",this);
     exitButton=new QPushButton(codec->toUnicode("Выход"),this);

     QHBoxLayout *layout1 = new QHBoxLayout();
     layout1->addWidget(labelByOne);
     layout1->addWidget(labelByFive);

     QHBoxLayout *layout2 = new QHBoxLayout();
     layout2->addWidget(counterByOne);
     layout2->addWidget(counterByFive);

     QHBoxLayout *layout3 = new QHBoxLayout();
     layout3->addWidget(addOneButton);
     layout3->addWidget(exitButton);

     QVBoxLayout *layout4 = new QVBoxLayout(this);
     layout4->addLayout(layout1);
     layout4->addLayout(layout2);
     layout4->addLayout(layout3);

     // связь сигнала нажатия кнопки и слота закрытия окна
     connect(addOneButton,SIGNAL(clicked(bool)),counterByOne,SLOT(add_one()));
     connect(counterByOne,SIGNAL(multiplicityFive_signal()),counterByFive,SLOT(add_one()));
     connect(exitButton,SIGNAL(clicked(bool)),this,SLOT(close()));
}
