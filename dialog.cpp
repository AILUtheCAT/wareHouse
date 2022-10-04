#include "dialog.h"
#include <QDebug>
#include <ui_widget.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <dialog.h>
#include <QSqlQuery>
#include <QMessageBox>
#include <QTextCodec>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::Widget)
{
    //ui = new Ui::Widget();
    ui->setupUi(this);
   /* db = QSqlDatabase::addDatabase("QMYSQL");
    databaseConnection();*/
    connect(ui->submitPushBtn,SIGNAL(clicked()),this, SLOT(authentication()));
}
void Dialog::authentication()
{
    QString username, password, db_user, db_pass;
    username = ui-> user_lineEdit->text().trimmed();
    password = ui->pass_lineEdit->text().trimmed();
    //帳密內涵於程式碼
    if ( username=="1"&& password=="1")
    {
        qDebug() << "You have logged!!!";
        createDB();//建立資料庫
        this->accept();
    }
    else{
        username.clear();
        password.clear();
        QMessageBox::information(this,"Login failed","You gave the wrong username or password!");
        qDebug() << "Login failed!!!";
    }

    //帳密存於資料庫
   /*QString command ="SELECT * FROM account";
    QSqlQuery query(db);
    bool      login;
    if (query.exec(command))
    {
        login =false;
        while (query.next())
        {
            db_user = query.value("username").toString();
            db_pass = query.value("password").toString();
            if(db_user == username && db_pass == password)
            {
                qDebug() << "You got logged in !!!";
                login=true;
                QMessageBox::information(this,"Login Succssfully","You got logged in!");
                this->accept();
                break;
            }

        }
        if (!login)
        {
            QMessageBox::information(this,"Login failed","You gave the wrong username or password!");
            qDebug()<< "You give wrong username or password!";
        }
    }*/


}
/*void Dialog::databaseConnection()
{
    db.setHostName("192.168.0.101");
    db.setPort(3306);
    db.setDatabaseName("contact");
    db.setUserName("testuser");
    db.setPassword("6315576");
    if (db.open())
        qDebug() << "connected!";
    else
        qDebug() << "Failed to connect.";
}*/
Dialog::~Dialog()
{

}
void Dialog::submit()//连接槽函数
{
        createDB();
        accept();
}
//创建数据库文件commodity.db
void Dialog::createDB()
{
    QSqlError err;
    QSqlDatabase db = QSqlDatabase::addDatabase(("QSQLITE"));
    db.setDatabaseName("commodity.db");
    db.open();
    if(!db.open())
    {
        err = db.lastError();
        qDebug() << err.text();
    }
    else
    {
         qDebug()<<QObject::tr("Open database successfully");
    }

    QSqlQuery q;//數據庫操作
    bool success = q.exec("create table commodity(id int primary key, category varchar(40), name varchar(40), origin varchar(40), count int, price double, quality varchar(40), exp varchar(40))");
    if(success)
    {
        qDebug() << QObject::tr("Create commodity table successfully!");
    }
}
