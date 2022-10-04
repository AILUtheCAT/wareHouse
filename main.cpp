#include "warehouse.h"
#include "database.h"
#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   /* Database conDialog;
    if(conDialog.exec() != QDialog::Accepted)
        return -1;*/
    Dialog login;
    if(login.exec() != QDialog::Accepted)
        return -1;

    Warehouse w("commodity");
    QPalette palette;
    palette.setColor(QPalette::Background, Qt::lightGray);
    w.setPalette(palette);
    w.setAutoFillBackground(true);
    w.show();

    return a.exec();
}
