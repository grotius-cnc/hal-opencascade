#include "next.h"
#include "iostream"
#include "mainwindow.h"
#include <QApplication>
#include "thread"

//! Make conversion's easy:
#define toRadians M_PI/180.0
#define toDegrees (180.0/M_PI)

Next::Next()
{

}

data Next::init(data d){

    return d;
}

void Next::start(){
    Thread = new std::thread(&Next::gui,this);
    Thread->detach(); // Execute the thread independent from other stuff.
}

void Next::gui(){
        std::cout<<"gui start executed"<<std::endl;
        int argc=0;
        char *argv[]={};
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        a.exec();
}


// "C" code style:
extern "C" void init_opencascade(){
    Next().start();
}

extern "C" void meat(data d){
    // update the global meat bucket.
    //std::cout<<"data recieved value:"<<d.x<<std::endl;
    databucket=d;
}

extern "C" data init_wrapper(data d){
    struct data r;
    r=Next().init(d);
    return r;
}
















