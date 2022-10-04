#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <ui_widget.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    void createDB();//建立数据库
    void submit();//连接槽函数
    ~Dialog();
private slots:
    void authentication();//登入
  //void databaseConnection();
private:
    Ui::Widget *ui;
    QSqlDatabase db;
};

#endif // DIALOG_H
