#ifndef LOGIN_HPP
#define LOGIN_HPP

#pragma once

#include <QMainWindow>

namespace Ui {
    class Login;
}

class Login : public QMainWindow {
    Q_OBJECT

    public:
        explicit Login(QWidget *parent = Q_NULLPTR);
        ~Login();
    private:
        Ui::Login* ui;
};

#endif  // LOGIN_HPP
