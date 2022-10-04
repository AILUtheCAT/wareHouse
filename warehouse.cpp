#include "warehouse.h"
//#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QAbstractItemView>
#include <QPushButton>
#include <QSqlRecord>
#include <QMessageBox>
#include <QLabel>
#include <QtDebug>
#include <QSqlField>

Warehouse::~Warehouse()
{
}
Warehouse::Warehouse(const QString &DataTable, QWidget *parent) :
    QMainWindow(parent)
{
    //貨品系統
    Depot = new QSqlTableModel(this);
    Depot->setTable(DataTable);//商品表
    Depot->select();

    QGroupBox *commodity = createComGroup();//左邊
    QGroupBox *detail = createDetailGroup();//右邊

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(commodity, 0, 0, 2, 1);
    layout->addWidget(detail, 0, 1, 2, 1);
    layout->setColumnMinimumWidth(0, 500);
    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);
    //設定背景圖片
  /*     this->setAutoFillBackground(true); // 這句要加上, 否則可能顯示不出背景圖.
       QPalette palette = this->palette();
       palette.setBrush(QPalette::Window,
               QBrush(QPixmap("../res/cloud.jpg").scaled(// 縮放背景圖.
                   this->size(),
                   Qt::IgnoreAspectRatio,
                   Qt::SmoothTransformation)));             // 使用平滑的縮放方式
       this->setPalette(palette);
                        // 給widget加上背景圖*/
    resize(750, 500);
}
void Warehouse::rfidaddtotable(int id,
                    QString category,
                    QString name ,
                    QString origin ,
                    int count,
                    double price ,
                    QString quality ,
                    QString exp ){//rfid進貨數據到資料庫
    qDebug() << id << category << name << origin << count << price << quality << exp;
    QSqlRecord record;
    QSqlField f1("id", QVariant::Int);
    QSqlField f2("category", QVariant::String);
    QSqlField f3("name", QVariant::String);
    QSqlField f4("origin", QVariant::String);
    QSqlField f5("count", QVariant::Int);
    QSqlField f6("price", QVariant::Double);
    QSqlField f7("quality", QVariant::String);
    QSqlField f8("exp", QVariant::String);

    f1.setValue(QVariant(id));
    f2.setValue(QVariant(category));
    f3.setValue(QVariant(name));
    f4.setValue(QVariant(origin));
    f5.setValue(QVariant(count));
    f6.setValue(QVariant(price));
    f7.setValue(QVariant(quality));
    f8.setValue(QVariant(exp));

    record.append(f1);
    record.append(f2);
    record.append(f3);
    record.append(f4);
    record.append(f5);
    record.append(f6);
    record.append(f7);
    record.append(f8);

    Depot->insertRecord(-1, record);
    Depot->setSort(0, Qt::AscendingOrder);//升序排列
    Depot->select();

}
void Warehouse::rfidaddto(){
    int id=0;
    QString category;
    QString name ;
    QString origin ;
    int count;
    double price ;
    QString quality ;
    QString exp ;
    if(rfidLineEdit->text()=="0439987809"){
        qDebug() << "0439987809!!!";
        id = 13;
        category = "3C周邊";
        name = "鍵盤";
        origin = "台灣";
        count = 10;
        price = 1000;
        quality = "A";
        exp = "3年保固";
        rfidaddtotable(id,category,name ,origin ,count,price ,quality ,exp );
        rfidLineEdit->setText("");
     }
    if(rfidLineEdit->text()=="0793916273"){
        qDebug() << "0793916273!!!";
        id = 14;
        category = "3C周邊";
        name = "滑鼠";
        origin = "美國";
        count = 20;
        price = 600;
        quality = "A";
        exp = "1年保固";
        rfidaddtotable(id,category,name ,origin ,count,price ,quality ,exp );
        rfidLineEdit->setText("");
     }
}
void Warehouse::rfidadd(){
    QDialog *dialog = new QDialog();
    dialog->setWindowTitle(tr("Add"));

    QGroupBox *box = new QGroupBox(this);
    QLabel *idLabel = new QLabel(tr("rfid: "));
    rfidLineEdit = new QLineEdit;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(idLabel, 0, 0, 1, 1);
    layout->addWidget(rfidLineEdit, 0, 1, 1, 1);
    box->setLayout(layout);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(box);
    dialog->setLayout(mainLayout);
    dialog->show();
    connect(rfidLineEdit,SIGNAL(textChanged(QString)),this,SLOT(rfidaddto()));
/*    if(rfidLineEdit->textChanged("0439987809")){
        qDebug() << "ok!!!";
    }*/
}
QGroupBox* Warehouse::createComGroup()//左邊的框
{
    //清單
    Checklist = new QTableView;
    Checklist->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可編輯
    Checklist->setSortingEnabled(true);//開啟會排序
    Checklist->setSelectionBehavior(QAbstractItemView::SelectRows);//選擇設定(一行)
    Checklist->setSelectionMode(QAbstractItemView::SingleSelection);//選擇設定(單擊)
    Checklist->setShowGrid(true);
    Checklist->setAlternatingRowColors(true);
    Checklist->setModel(Depot);

    connect(Checklist, SIGNAL(clicked(QModelIndex)), this, SLOT(ChecklistDetial(QModelIndex)));
    QGroupBox *box = new QGroupBox(tr("資料訊息"));
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(Checklist, 0, 0);
    box->setLayout(layout);
    return box;
}

QGroupBox* Warehouse::createDetailGroup()//右邊的眶
{
    QGroupBox *box = new QGroupBox(tr("詳細資訊"));
    showList = new QListWidget;

    QPushButton *deleteBtn = new QPushButton(tr("銷貨"));
    QPushButton *addBtn = new QPushButton(tr("進貨"));
    QPushButton *searchBtn = new QPushButton(tr("使用名稱搜尋"));
    QPushButton *search1Btn = new QPushButton(tr("使用類別搜尋"));
    QPushButton *returnBtn = new QPushButton(tr("返回搜尋頁面"));
    QPushButton *quitBtn = new QPushButton(tr("離開"));
    //QPushButton *qrBtn = new QPushButton(tr("qrcode進貨"));
    QPushButton *rfidBtn = new QPushButton(tr("rfidBtn進貨"));
    QLabel *name = new QLabel(tr("員工:楊傑宇"));
    QLabel *level = new QLabel(tr("職位:銷售服務課員"));

    name->setFixedHeight(12);
    level->setFixedHeight(12);
    connect(deleteBtn, SIGNAL(clicked(bool)), this, SLOT(removeComFromDepot()));
    connect(addBtn, SIGNAL(clicked(bool)), this, SLOT(addNew()));
    connect(searchBtn, SIGNAL(clicked(bool)), this, SLOT(searchN()));
    connect(search1Btn, SIGNAL(clicked(bool)), this, SLOT(searchC()));
    connect(returnBtn, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(quitBtn, SIGNAL(clicked(bool)), this, SLOT(quit()));
    connect(rfidBtn, SIGNAL(clicked(bool)), this, SLOT(rfidadd()));

    LineEdit1 = new QLineEdit;
    LineEdit2 = new QLineEdit;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(showList, 0, 0, 3, 2);
    layout->addWidget(deleteBtn, 3, 0, 1, 1);
    layout->addWidget(addBtn, 3, 1, 1, 1);
    //layout->addWidget(qrBtn, 4, 0, 1, 2);
    layout->addWidget(LineEdit1, 5, 0, 1, 1);
    layout->addWidget(searchBtn, 5, 1, 1, 1);
    layout->addWidget(LineEdit2, 6, 0, 1, 1);
    layout->addWidget(search1Btn, 6, 1, 1, 1);
    layout->addWidget(returnBtn, 7, 0, 1, 1);
    layout->addWidget(quitBtn, 7, 1, 1, 1);
    layout->addWidget(rfidBtn, 8, 0, 1, 2);
    layout->addWidget(name,9,0,1,2);
    layout->addWidget(level,9,1,1,2);

    box->setLayout(layout);
    return box;
}
void Warehouse::ChecklistDetial(QModelIndex index)//選到一行，會詳細顯示在右邊列表資訊
{
    showList->clear();
    item = new QListWidgetItem(showList); //取出數據並分離
    QSqlRecord record = Depot->record(index.row());
    int comId = record.value("id").toInt();
    QString category = record.value("category").toString();
    QString name = record.value("name").toString();
    QString origin = record.value("origin").toString();
    int count = record.value("count").toInt();
    double price = record.value("price").toDouble();
    QString quality = record.value("quality").toString();
    QString exp = record.value("exp").toString();
    item->setText(tr("ID: %1\nCategory: %2\nName: %3\nOrigin: %4\nCount: %5\nPrice: %6\nQuality: %7\nExp: %8\n").arg(comId).arg(category).arg(name).arg(origin).arg(count).arg(price).arg(quality).arg(exp));
}

void Warehouse::removeComFromDepot()//出貨
{
    QModelIndexList select = Checklist->selectionModel()->selectedRows();

    if (!select.empty())
    {
        QModelIndex idIndex = select.at(0);//得到id
        QString name = idIndex.sibling(idIndex.row(), 2).data().toString();
        QMessageBox::StandardButton button;
        button = QMessageBox::question(this, tr("Delete"), QString(tr("Are you sure to delete '%1' information?").arg(name)), QMessageBox::Yes | QMessageBox::No);
        if (button == QMessageBox::Yes)
        {
            Depot->removeRow(idIndex.row());
            Depot->submitAll();
            Depot->select();
        }
    }
}
void Warehouse::searchN()//名稱搜尋
{
    QString name = LineEdit1->text();
    if (!name.isEmpty())
    {
        Depot->setFilter(QObject::tr("name = '%1'").arg(name));
        Depot->select();
        LineEdit2->clear();
    }
    else
        return;
}
void Warehouse::searchC()//類別搜尋
{
    QString category = LineEdit2->text();
    if (!category.isEmpty())
    {
        Depot->setFilter(QObject::tr("category = '%1'").arg(category));
        Depot->select();
        LineEdit2->clear();
    }
    else
        return;
}

void Warehouse::back()
{
    Depot->setTable("commodity");
    Depot->setSort(0, Qt::AscendingOrder);
    Depot->select();
}

void Warehouse::addNew()//進貨資訊
{
    QDialog *dialog = new QDialog();
    dialog->setWindowTitle(tr("Add"));

    QGroupBox *box = new QGroupBox(this);
    QPushButton *submitBtn = new QPushButton(tr("Submit"));
    QPushButton *cancelBtn = new QPushButton(tr("clear"));


    connect(submitBtn, SIGNAL(clicked(bool)), this, SLOT(addNewToTable()));
    connect(cancelBtn, SIGNAL(clicked(bool)), this, SLOT(cancel()));

    QLabel *idLabel = new QLabel(tr("編號: "));
    QLabel *categoryLabel = new QLabel(tr("種類: "));
    QLabel *nameLabel = new QLabel(tr("名類: "));
    QLabel *originLabel = new QLabel(tr("產地: "));
    QLabel *countLabel = new QLabel(tr("數量: "));
    QLabel *priceLabel = new QLabel(tr("價格: "));
    QLabel *qualityLabel = new QLabel(tr("品質:"));
    QLabel *expLabel = new QLabel(tr("保固:"));

    idLineEdit = new QLineEdit;
    categoryLineEdit = new QLineEdit;
    nameLineEdit = new QLineEdit;
    originLineEdit = new QLineEdit;
    countLineEdit = new QLineEdit;
    priceLineEdit = new QLineEdit;
    qualityLineEdit = new QLineEdit;
    expLineEdit = new QLineEdit;

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(idLabel, 0, 0, 1, 1);
    layout->addWidget(idLineEdit, 0, 1, 1, 1);
    layout->addWidget(categoryLabel, 1, 0, 1, 1);
    layout->addWidget(categoryLineEdit, 1, 1, 1, 1);
    layout->addWidget(nameLabel, 2, 0, 1, 1);
    layout->addWidget(nameLineEdit, 2, 1, 1, 1);
    layout->addWidget(originLabel, 3, 0, 1, 1);
    layout->addWidget(originLineEdit, 3, 1, 1, 1);
    layout->addWidget(countLabel, 4, 0, 1, 1);
    layout->addWidget(countLineEdit, 4, 1, 1, 1);
    layout->addWidget(priceLabel, 5, 0, 1, 1);
    layout->addWidget(priceLineEdit, 5, 1, 1, 1);
    layout->addWidget(qualityLabel, 6, 0, 1, 1);
    layout->addWidget(qualityLineEdit, 6, 1, 1, 1);
    layout->addWidget(expLabel, 7, 0, 1, 1);
    layout->addWidget(expLineEdit, 7, 1, 1, 1);
    layout->addWidget(submitBtn, 8, 0, 1, 1);
    layout->addWidget(cancelBtn, 8, 1, 1, 1);

    box->setLayout(layout);
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(box);
    dialog->setLayout(mainLayout);
    dialog->show();
}
void Warehouse::addNewToTable()//進貨
{
    int id = idLineEdit->text().toInt();
    QString category = categoryLineEdit->text();
    QString name = nameLineEdit->text();
    QString origin = originLineEdit->text();
    int count = countLineEdit->text().toInt();
    double price = priceLineEdit->text().toDouble();
    QString quality = qualityLineEdit->text();
    QString exp = expLineEdit->text();

    qDebug() << id << category << name << origin << count << price << quality << exp;
    QSqlRecord record;
    QSqlField f1("id", QVariant::Int);
    QSqlField f2("category", QVariant::String);
    QSqlField f3("name", QVariant::String);
    QSqlField f4("origin", QVariant::String);
    QSqlField f5("count", QVariant::Int);
    QSqlField f6("price", QVariant::Double);
    QSqlField f7("quality", QVariant::String);
    QSqlField f8("exp", QVariant::String);

    f1.setValue(QVariant(id));
    f2.setValue(QVariant(category));
    f3.setValue(QVariant(name));
    f4.setValue(QVariant(origin));
    f5.setValue(QVariant(count));
    f6.setValue(QVariant(price));
    f7.setValue(QVariant(quality));
    f8.setValue(QVariant(exp));

    record.append(f1);
    record.append(f2);
    record.append(f3);
    record.append(f4);
    record.append(f5);
    record.append(f6);
    record.append(f7);
    record.append(f8);

    Depot->insertRecord(-1, record);
    Depot->setSort(0, Qt::AscendingOrder);//升序排列
    Depot->select();
    clears();
}

void Warehouse::cancel()//離開
{
    clears();
}
void Warehouse::clears()//出貨
{
    idLineEdit->clear();
    categoryLineEdit->clear();
    nameLineEdit->clear();
    originLineEdit->clear();
    countLineEdit->clear();
    priceLineEdit->clear();
    qualityLineEdit->clear();
    expLineEdit->clear();
}

void Warehouse::quit()//離開
{
    this->close();
}

