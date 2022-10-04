#include "database.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QtDebug>
#include <QSqlQuery>
#include <QDialog>

Database::Database(QWidget *parent)
    : QDialog(parent),ui(new Ui::Widget)
{

    ui->setupUi(this);
}

Database::~Database()
{
    delete ui;//建立資料庫後將頁面關閉
}

void Database::on_submitPushBtn_clicked()
{
   /* if(this->ui->user_lineEdit->text().trimmed()== tr("1") && this->ui->pass_lineEdit->text().trimmed()==tr("1"))//判斷帳號密碼是否正確才開資料庫
    {
        createDB();//建立資料庫
        accept();
    }*/
}

void Database::createDB()//建立資料庫的函式
{
    QSqlError err;
    QSqlDatabase DB=QSqlDatabase::addDatabase(("QSQLITE"));//建立一個QSqlite的資料庫
    DB.setDatabaseName("Data.db");//將資料庫取名為Database
    DB.open();
    if(!DB.open())
    {
        err=DB.lastError();
        qDebug()<<err.text();
    }
    else
    {
        qDebug()<<QObject::tr("Open database successfully");
    }

    QSqlQuery q;
    bool success=q.exec("create table Data(編號 int primary key,種類 varchar(40),名稱 varchar(40),產地 varchar(40),數量 int,價格 dpuble,特價 varchar(40),保固 varchar(40))");
    if(success)
    {
        qDebug()<<QObject::tr("Create Database table successfully");
    }
}

