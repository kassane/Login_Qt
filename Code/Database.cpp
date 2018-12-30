#include "Headers/Database.hpp"
#include <QtSql>
#include <QDebug>

static QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

Database::Database(QWidget* parent) : QWidget(parent)
{
    db.setDatabaseName("./data/pdv.db");
    if(!db.open()) qDebug() << "ERROR: " << db.lastError();
}
Database::~Database()
{
    //
}

Database* Database::setUser(const QString& name)
{
    _name = name;
    return this;
}
Database* Database::setPassw(const QString& password)
{
    _password = password;
    return this;
}
QString Database::User() const
{
    return _name;
}
QString Database::Password() const
{
    return _password;
}

void Database::connect()
{
    QSqlQuery qry;
    qry.prepare("SELECT Usuario, Senha FROM tb_colaboradores");
    //qry.bindValue(2,_name);
    //qry.bindValue(3,_password);
    if(!qry.exec()) qDebug() << "ERROR: " << qry.lastError();
    for(int i = 0; i < qry.next(); i++) {
        if(User() != qry.value(i).toString() || Password() != qry.value(i+1).toString())
            qDebug() << "ERROR: Senha e/ou Usuario errado!";
        else qDebug() << "Logado com Sucesso!";
    }


    /**
        qry.prepare("INSERT INTO tb_colaboradores (ID, Nome, Usuario, Senha) VALUES (?,?,?,?)");
        qry.bindValue(1,"Matheus");
        qry.bindValue(2,"kassane");
        qry.bindValue(3,"abc123");
        if(!qry.exec()) qDebug() << "ERROR: " << qry.lastError();
     */
}
