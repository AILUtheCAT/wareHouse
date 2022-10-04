/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_6;
    QTableWidget *tableWidget;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QFormLayout *formLayout;
    QLabel *user_label;
    QLabel *pass_label;
    QLineEdit *user_lineEdit;
    QLineEdit *pass_lineEdit;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *submitPushBtn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(694, 499);
        Widget->setStyleSheet(QString::fromUtf8("#verticalLayout{border-image: url(:/resorce/res/login_bg.png);}\n"
"#verticalLayout{border-image: url(:/images/login_bg.png);}\n"
""));
        Widget->setInputMethodHints(Qt::ImhNone);
        horizontalLayout_4 = new QHBoxLayout(Widget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("#frame {border-image: url(:/resorce/res/back.png);}\n"
"\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        tableWidget = new QTableWidget(frame);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMaximumSize(QSize(256, 192));
        tableWidget->setStyleSheet(QString::fromUtf8("border-image: url(:/resorce/res/login.png);"));

        verticalLayout->addWidget(tableWidget, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 20, 10, -1);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(0);
        formLayout->setContentsMargins(-1, 10, -1, 10);
        user_label = new QLabel(frame);
        user_label->setObjectName(QString::fromUtf8("user_label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Berlin Sans FB Demi"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(9);
        user_label->setFont(font);
        user_label->setStyleSheet(QString::fromUtf8("color:white;font: 75 16pt \"Berlin Sans FB Demi\";\n"
"\n"
""));

        formLayout->setWidget(0, QFormLayout::LabelRole, user_label);

        pass_label = new QLabel(frame);
        pass_label->setObjectName(QString::fromUtf8("pass_label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Berlin Sans FB Demi"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        pass_label->setFont(font1);
        pass_label->setStyleSheet(QString::fromUtf8("color:white;font: 75 16pt \"Berlin Sans FB Demi\";"));

        formLayout->setWidget(1, QFormLayout::LabelRole, pass_label);

        user_lineEdit = new QLineEdit(frame);
        user_lineEdit->setObjectName(QString::fromUtf8("user_lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, user_lineEdit);

        pass_lineEdit = new QLineEdit(frame);
        pass_lineEdit->setObjectName(QString::fromUtf8("pass_lineEdit"));
        pass_lineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, pass_lineEdit);


        horizontalLayout_2->addLayout(formLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        submitPushBtn = new QPushButton(frame);
        submitPushBtn->setObjectName(QString::fromUtf8("submitPushBtn"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Berlin Sans FB Demi"));
        font2.setPointSize(32);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        submitPushBtn->setFont(font2);
        submitPushBtn->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.495 rgba(0, 255, 255, 255), stop:0.505 rgba(0, 255, 255, 255), stop:1 rgba(0, 0, 0, 255));\n"
"color:white;font: 75 32pt \"Berlin Sans FB Demi\";"));

        horizontalLayout->addWidget(submitPushBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout);


        horizontalLayout_4->addWidget(frame);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        user_label->setText(QApplication::translate("Widget", "Username:", nullptr));
        pass_label->setText(QApplication::translate("Widget", "Password :", nullptr));
        submitPushBtn->setText(QApplication::translate("Widget", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
