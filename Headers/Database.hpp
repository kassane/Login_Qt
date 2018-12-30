#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <QWidget>
#include <QLineEdit>

class Database : public QWidget
{
    Q_OBJECT
    public:
        explicit Database(QWidget* parent = Q_NULLPTR);
        Database* setUser(const QString& name);
        Database* setPassw(const QString& password);
        //Getters
        QString User() const;
        QString Password() const;
        ~Database();
    private:
        QString  _name, _password;
    public slots:
        void connect();
};
#endif  // DATABASE_HPP