#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "next.h"

double value=0;
data databucket;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    OpencascadeWidget = new Opencascade(this);
    ui->gridLayout_opencascade->addWidget(OpencascadeWidget);

    //This activates a screen update when robot is moving and screen needs to be updated automaticly.
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::Update_Opencascade);
    timer->start(200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Update_Opencascade()
{
    //OpencascadeWidget->Redraw();
    //std::cout<<"mainwindow timer update is active"<<std::endl;
    value+=1;
    if(value==1000){
        value=0;
    }
    ui->label_timer->setText(QString::number(value));

    //double val=Next().mymeat.x;
    double val=databucket.x;
    std::cout<<"meat value from mainwindow:"<<val<<std::endl;
}

void MainWindow::on_pushButton_loadmodel_pressed()
{
    /*
    OpencascadeWidget->Readstepfile("config/robot/kuka_base.step");
    OpencascadeWidget->Readstepfile("config/robot/kuka_joint_1.step");
    OpencascadeWidget->Readstepfile("config/robot/kuka_joint_2.step");
    OpencascadeWidget->Readstepfile("config/robot/kuka_joint_3.step");
    OpencascadeWidget->Readstepfile("config/robot/kuka_joint_4.step");
    OpencascadeWidget->Readstepfile("config/robot/kuka_joint_5.step");
    OpencascadeWidget->Readstepfile("config/robot/kuka_joint_6.step");
    OpencascadeWidget->Readstepfile("config/robot/kuka_tool_cone.step");
    OpencascadeWidget->Readstepfile("config/robot/kuka_track.step");
    */
}
