/********************************************************************************
** Form generated from reading ui file 'HistoryWidget.ui'
**
** Created: Wed Oct 14 23:13:08 2009
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_HISTORYWIDGET_H
#define UI_HISTORYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;

    void setupUi(QWidget *HistoryWidget)
    {
        if (HistoryWidget->objectName().isEmpty())
            HistoryWidget->setObjectName(QString::fromUtf8("HistoryWidget"));
        HistoryWidget->resize(271, 201);
        verticalLayout = new QVBoxLayout(HistoryWidget);
        verticalLayout->setMargin(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(HistoryWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setShowGrid(false);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);


        retranslateUi(HistoryWidget);

        QMetaObject::connectSlotsByName(HistoryWidget);
    } // setupUi

    void retranslateUi(QWidget *HistoryWidget)
    {
        HistoryWidget->setWindowTitle(QApplication::translate("HistoryWidget", "Form", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(HistoryWidget);
    } // retranslateUi

};

namespace Ui {
    class HistoryWidget: public Ui_HistoryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYWIDGET_H
