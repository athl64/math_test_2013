#include "var4.h"
#include "ui_var4.h"
#include <QDebug>
#include <QFile>
#include <QDateTime>

int mark4 = 0;
int tasks4[7];

var4::var4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::var4)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(show_help()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(check()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(close()));
    //
    connect(ui->pushButton_3,SIGNAL(clicked()),parent,SLOT(show()));
    connect(this,SIGNAL(markIsReady()),parent,SLOT(transmitMark()));

    ui->lcdNumber->setVisible(false);
    ui->label_27->setVisible(false);
    ui->label_28->setVisible(false);
    ui->pushButton_3->setVisible(false);
}

var4::~var4()
{
    delete ui;
}

void var4::show_help()
{
    h = new help(this);
    h->show();
}

void var4::check()
{
    mark4 = 0;
    for(int ii=0;ii<=6;ii++) {
        tasks4[ii]=0;
    }

    if((ui->lineEdit->text()=="1" && ui->lineEdit_2->text()=="-" && ui->lineEdit_3->text()=="1" && ui->lineEdit_4->text()=="3" && ui->lineEdit_6->text()=="-" && ui->lineEdit_7->text()=="1" && ui->lineEdit_5->text()=="4" && ui->radioButton->isChecked()==false) || (ui->lineEdit->text()=="1" && ui->lineEdit_2->text()=="-" && ui->lineEdit_3->text()=="1" && ui->lineEdit_4->text()=="4" && ui->lineEdit_6->text()=="-" && ui->lineEdit_7->text()=="1" && ui->lineEdit_5->text()=="3" && ui->radioButton->isChecked()==false)) {
        mark4++;
        tasks4[0]=1;
    };
    if((ui->lineEdit_8->text()=="0" && ui->lineEdit_11->text()=="-" && ui->lineEdit_12->text()=="2" && ui->lineEdit_9->text()=="3" && ui->lineEdit_10->text()=="-" && ui->lineEdit_14->text()=="2" && ui->lineEdit_13->text()=="3" && ui->radioButton_2->isChecked()==false) || (ui->lineEdit_8->text()=="0" && ui->lineEdit_11->text()=="-" && ui->lineEdit_12->text()=="2" && ui->lineEdit_9->text()=="3" && ui->lineEdit_10->text()=="-" && ui->lineEdit_14->text()=="2" && ui->lineEdit_13->text()=="3" && ui->radioButton_2->isChecked()==false)) {
        mark4++;
        tasks4[1]=1;
    };
    if((ui->lineEdit_15->text()=="-15" && ui->lineEdit_18->text()=="" && ui->lineEdit_19->text()=="" && ui->lineEdit_16->text()=="" && ui->lineEdit_17->text()=="" && ui->lineEdit_21->text()=="" && ui->lineEdit_20->text()=="" && ui->radioButton_3->isChecked()==true) || (ui->lineEdit_15->text()=="-15" && ui->lineEdit_18->text()=="" && ui->lineEdit_19->text()=="" && ui->lineEdit_16->text()=="" && ui->lineEdit_17->text()=="" && ui->lineEdit_21->text()=="" && ui->lineEdit_20->text()=="" && ui->radioButton->isChecked()==true)) {
        mark4++;
        tasks4[2]=1;
    };
    if((ui->lineEdit_22->text()=="16" && ui->lineEdit_25->text()=="1" && ui->lineEdit_26->text()=="" && ui->lineEdit_23->text()=="" && ui->lineEdit_24->text()=="" && ui->lineEdit_28->text()=="5" && ui->lineEdit_27->text()=="9" && ui->radioButton->isChecked()==false) || (ui->lineEdit_22->text()=="16" && ui->lineEdit_25->text()=="" && ui->lineEdit_26->text()=="5" && ui->lineEdit_23->text()=="9" && ui->lineEdit_24->text()=="1" && ui->lineEdit_28->text()=="" && ui->lineEdit_27->text()=="" && ui->radioButton->isChecked()==false)) {
        mark4++;
        tasks4[3]=1;
    };
    //end of 1-st task
    if((ui->lineEdit_29->text()=="81" && ui->lineEdit_30->text()=="-7" && ui->lineEdit_33->text()=="" && ui->lineEdit_35->text()=="" && ui->lineEdit_31->text()=="2" && ui->lineEdit_32->text()=="" && ui->lineEdit_34->text()=="" && ui->radioButton->isChecked()==false) || (ui->lineEdit_29->text()=="81" && ui->lineEdit_30->text()=="2" && ui->lineEdit_33->text()=="" && ui->lineEdit_35->text()=="" && ui->lineEdit_31->text()=="-7" && ui->lineEdit_32->text()=="" && ui->lineEdit_34->text()=="" && ui->radioButton->isChecked()==false)) {
        mark4++;
        tasks4[4]=1;
    };
    if((ui->lineEdit_40->text()=="784" && ui->lineEdit_38->text()=="-16" && ui->lineEdit_42->text()=="" && ui->lineEdit_39->text()=="" && ui->lineEdit_36->text()=="12" && ui->lineEdit_37->text()=="" && ui->lineEdit_41->text()=="" && ui->radioButton->isChecked()==false) || (ui->lineEdit_40->text()=="784" && ui->lineEdit_38->text()=="12" && ui->lineEdit_42->text()=="" && ui->lineEdit_39->text()=="" && ui->lineEdit_36->text()=="-16" && ui->lineEdit_37->text()=="" && ui->lineEdit_41->text()=="" && ui->radioButton->isChecked()==false)) {
        mark4++;
        tasks4[5]=1;
    };
    //end of 2-nd task
    if((ui->lineEdit_43->text()=="15" && ui->lineEdit_44->text()=="" && ui->lineEdit_45->text()=="" && ui->lineEdit_47->text()=="8" && ui->lineEdit_46->text()=="" && ui->lineEdit_48->text()=="") || (ui->lineEdit_43->text()=="8" && ui->lineEdit_44->text()=="" && ui->lineEdit_45->text()=="" && ui->lineEdit_47->text()=="15" && ui->lineEdit_46->text()=="" && ui->lineEdit_48->text()=="")) {
        mark4++;
        tasks4[6]=1;
    };
    //end of 3-d task

    qDebug()<<"mark4 is "<<mark4;
    show_result();
}

void var4::show_result()
{
    ui->pushButton_3->setVisible(true);
    ui->pushButton_2->setVisible(false);
    ui->lcdNumber->setVisible(true);
    ui->label_27->setVisible(true);
    ui->label_28->setVisible(true);
    ui->lcdNumber->display(mark4);

    switch(mark4) {
        case 0: ui->lcdNumber->setPalette(Qt::red); break;
        case 1: ui->lcdNumber->setPalette(Qt::red); break;
        case 2: ui->lcdNumber->setPalette(Qt::red); break;
        case 3: ui->lcdNumber->setPalette(Qt::red); break;
        case 4: ui->lcdNumber->setPalette(Qt::yellow); break;
        case 5: ui->lcdNumber->setPalette(Qt::yellow); break;
        case 6: ui->lcdNumber->setPalette(Qt::green); break;
        case 7: ui->lcdNumber->setPalette(Qt::green); break;
    }

    QList<QLineEdit *> all_line_edits = this->findChildren<QLineEdit *>();
    QLineEdit *temp_l;
    foreach(temp_l,all_line_edits)
    {
        temp_l->setReadOnly(true);
    }

    QList<QRadioButton *> all_radio = this->findChildren<QRadioButton *>();
    QRadioButton *temp_r;
    foreach(temp_r,all_radio)
    {
        temp_r->setDisabled(true);
    }

    if(tasks4[0]==1) {ui->label_2->setStyleSheet("QLabel {color:green;}");} else {ui->label_2->setStyleSheet("QLabel {color:red;}");};
    if(tasks4[1]==1) {ui->label_7->setStyleSheet("QLabel {color:green;}");} else {ui->label_7->setStyleSheet("QLabel {color:red;}");};
    if(tasks4[2]==1) {ui->label_11->setStyleSheet("QLabel {color:green;}");} else {ui->label_11->setStyleSheet("QLabel {color:red;}");};
    if(tasks4[3]==1) {ui->label_15->setStyleSheet("QLabel {color:green;}");} else {ui->label_15->setStyleSheet("QLabel {color:red;}");};
    if(tasks4[4]==1) {ui->label_19->setStyleSheet("QLabel {color:green;}");} else {ui->label_19->setStyleSheet("QLabel {color:red;}");};
    if(tasks4[5]==1) {ui->label_24->setStyleSheet("QLabel {color:green;}");} else {ui->label_24->setStyleSheet("QLabel {color:red;}");};
    if(tasks4[6]==1) {ui->groupBox_3->setStyleSheet("QGroupBox {color:green;}");} else {ui->groupBox_3->setStyleSheet("QGroupBox {color:red;}");};

    QFile file("log.txt");
    QTextStream stream(&file);
    QDateTime now = QDateTime::currentDateTime();
    file.open(QIODevice::Append | QIODevice::Text);

    for(int i=0;i<=6;i++) {
        stream<<i<<" zavdannia = "<<tasks4[i]<<" baliv\n";
    }

    stream<<"baliv nabrano - "<<mark4<<"\n";
    stream<<"end - "<<now.toString()<<"\n--------------------------------------end\n";
    file.close();

    bank.setMark(mark4);
    emit markIsReady();
}
