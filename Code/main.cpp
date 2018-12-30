#include <QApplication>
#include "Headers/Login.hpp"

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    Login w;
    a.setStyle("fusion");
    //w.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint );
    w.setFixedSize(QSize(320, 240));
    //w.setStyleSheet("QWidget{background-color:#1d1d1d;color: #ffffff;}");
    w.show();

    return a.exec();

}