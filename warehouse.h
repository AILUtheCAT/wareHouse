#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <QMainWindow>
#include <QModelIndex>
#include <QGroupBox>
#include <QSqlTableModel>
#include <QTableView>
#include <QListWidget>
#include <QLineEdit>
class Warehouse : public QMainWindow
{
    Q_OBJECT

public:
    Warehouse(const QString &Datatable, QWidget *parent = 0);
    ~Warehouse();
    void rfidaddtotable(int id,
                        QString category,
                        QString name ,
                        QString origin ,
                        int count,
                        double price ,
                        QString quality ,
                        QString exp );//rfid進貨數據到資料庫
private slots://槽函数
    void ChecklistDetial(QModelIndex index);//點選行並輸出資訊到右邊詳細說明
    void removeComFromDepot();//删除
    void searchN();//名稱搜尋
    void searchC();//類別搜尋
    void back();//返回列表
    void addNew();//進貨的對話框
    void addNewToTable();//進貨數據到資料庫
    void rfidadd();//rfid
    void rfidaddto();//rfid進貨數據
    void cancel();//添加对话框中的取消按钮
    void clears();//清空全部行(LineEdit)内容
    void quit();//離開

private:
    QGroupBox *createComGroup();
    QGroupBox *createDetailGroup();
    QSqlTableModel *Depot;
    QTableView *Checklist;
    QListWidget *showList;
    QListWidgetItem *item;

    QLineEdit *LineEdit1;//輸入名稱
    QLineEdit *LineEdit2;//輸入類別
    QLineEdit *idLineEdit;
    QLineEdit *categoryLineEdit;
    QLineEdit *nameLineEdit;
    QLineEdit *originLineEdit;
    QLineEdit *countLineEdit;
    QLineEdit *priceLineEdit;
    QLineEdit *qualityLineEdit;
    QLineEdit *expLineEdit;

    QLineEdit *rfidLineEdit;
};
#endif // WAREHOUSE_H
