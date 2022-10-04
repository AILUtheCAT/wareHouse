#ifndef DATABASE_H
#define DATABASE_H

#include <QDialog>
//#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class Widget;
}

class Database : public QDialog
{
    Q_OBJECT

public:
    explicit Database(QWidget *parent = nullptr);
    ~Database();

    void createDB();

private slots:
    void on_submitPushBtn_clicked();

private:
    Ui::Widget *ui;
};
#endif // DATABASE_H
