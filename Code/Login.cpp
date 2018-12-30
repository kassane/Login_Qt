#include "Headers/Login.hpp"
#include "ui_login.h"
#include "Headers/Database.hpp"

Login::Login(QWidget *parent) : QMainWindow(parent), ui(new Ui::Login)
{
    ui->setupUi(this);
    Database *data = new Database(this);
    
    connect(ui->connect_btn, &QPushButton::clicked, data, &Database::connect);
    connect(ui->user_lEdit, &QLineEdit::textChanged, [this, data]() {
        // Se clicar no botão de limpeza ele altera o valor e o resultado.
        if (!ui->user_lEdit->text().isEmpty()) data->setUser(ui->user_lEdit->text());
  });
    connect(ui->passw_lEdit, &QLineEdit::textChanged, [this, data](){
        if (!ui->passw_lEdit->text().isEmpty()) data->setPassw(ui->passw_lEdit->text());
  });

}
Login::~Login()
{
    delete ui;
}