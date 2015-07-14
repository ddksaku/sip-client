/********************************************************************************
** Form generated from reading ui file 'DialerWidget.ui'
**
** Created: Wed Oct 14 23:13:08 2009
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DIALERWIDGET_H
#define UI_DIALERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialerWidget
{
public:
    QGridLayout *gridLayout;
    QPushButton *oneButton;
    QPushButton *twoButton;
    QPushButton *threeButton;
    QPushButton *fourButton;
    QPushButton *fiveButton;
    QPushButton *sixButton;
    QPushButton *sevenButton;
    QPushButton *eightButton;
    QPushButton *nineButton;
    QPushButton *layoutButton;
    QPushButton *zeroButton;
    QPushButton *backspaceButton;

    void setupUi(QWidget *DialerWidget)
    {
        if (DialerWidget->objectName().isEmpty())
            DialerWidget->setObjectName(QString::fromUtf8("DialerWidget"));
        DialerWidget->resize(289, 180);
        gridLayout = new QGridLayout(DialerWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        oneButton = new QPushButton(DialerWidget);
        oneButton->setObjectName(QString::fromUtf8("oneButton"));

        gridLayout->addWidget(oneButton, 0, 0, 1, 1);

        twoButton = new QPushButton(DialerWidget);
        twoButton->setObjectName(QString::fromUtf8("twoButton"));

        gridLayout->addWidget(twoButton, 0, 1, 1, 1);

        threeButton = new QPushButton(DialerWidget);
        threeButton->setObjectName(QString::fromUtf8("threeButton"));

        gridLayout->addWidget(threeButton, 0, 2, 1, 1);

        fourButton = new QPushButton(DialerWidget);
        fourButton->setObjectName(QString::fromUtf8("fourButton"));

        gridLayout->addWidget(fourButton, 1, 0, 1, 1);

        fiveButton = new QPushButton(DialerWidget);
        fiveButton->setObjectName(QString::fromUtf8("fiveButton"));

        gridLayout->addWidget(fiveButton, 1, 1, 1, 1);

        sixButton = new QPushButton(DialerWidget);
        sixButton->setObjectName(QString::fromUtf8("sixButton"));

        gridLayout->addWidget(sixButton, 1, 2, 1, 1);

        sevenButton = new QPushButton(DialerWidget);
        sevenButton->setObjectName(QString::fromUtf8("sevenButton"));

        gridLayout->addWidget(sevenButton, 2, 0, 1, 1);

        eightButton = new QPushButton(DialerWidget);
        eightButton->setObjectName(QString::fromUtf8("eightButton"));

        gridLayout->addWidget(eightButton, 2, 1, 1, 1);

        nineButton = new QPushButton(DialerWidget);
        nineButton->setObjectName(QString::fromUtf8("nineButton"));

        gridLayout->addWidget(nineButton, 2, 2, 1, 1);

        layoutButton = new QPushButton(DialerWidget);
        layoutButton->setObjectName(QString::fromUtf8("layoutButton"));

        gridLayout->addWidget(layoutButton, 3, 0, 1, 1);

        zeroButton = new QPushButton(DialerWidget);
        zeroButton->setObjectName(QString::fromUtf8("zeroButton"));

        gridLayout->addWidget(zeroButton, 3, 1, 1, 1);

        backspaceButton = new QPushButton(DialerWidget);
        backspaceButton->setObjectName(QString::fromUtf8("backspaceButton"));

        gridLayout->addWidget(backspaceButton, 3, 2, 1, 1);

        QWidget::setTabOrder(oneButton, twoButton);
        QWidget::setTabOrder(twoButton, threeButton);
        QWidget::setTabOrder(threeButton, fourButton);
        QWidget::setTabOrder(fourButton, fiveButton);
        QWidget::setTabOrder(fiveButton, sixButton);
        QWidget::setTabOrder(sixButton, sevenButton);
        QWidget::setTabOrder(sevenButton, eightButton);
        QWidget::setTabOrder(eightButton, nineButton);
        QWidget::setTabOrder(nineButton, layoutButton);
        QWidget::setTabOrder(layoutButton, zeroButton);
        QWidget::setTabOrder(zeroButton, backspaceButton);

        retranslateUi(DialerWidget);

        QMetaObject::connectSlotsByName(DialerWidget);
    } // setupUi

    void retranslateUi(QWidget *DialerWidget)
    {
        DialerWidget->setWindowTitle(QString());
        oneButton->setText(QApplication::translate("DialerWidget", "1", 0, QApplication::UnicodeUTF8));
        twoButton->setText(QApplication::translate("DialerWidget", "2", 0, QApplication::UnicodeUTF8));
        threeButton->setText(QApplication::translate("DialerWidget", "3", 0, QApplication::UnicodeUTF8));
        fourButton->setText(QApplication::translate("DialerWidget", "4", 0, QApplication::UnicodeUTF8));
        fiveButton->setText(QApplication::translate("DialerWidget", "5", 0, QApplication::UnicodeUTF8));
        sixButton->setText(QApplication::translate("DialerWidget", "6", 0, QApplication::UnicodeUTF8));
        sevenButton->setText(QApplication::translate("DialerWidget", "7", 0, QApplication::UnicodeUTF8));
        eightButton->setText(QApplication::translate("DialerWidget", "8", 0, QApplication::UnicodeUTF8));
        nineButton->setText(QApplication::translate("DialerWidget", "9", 0, QApplication::UnicodeUTF8));
        layoutButton->setText(QApplication::translate("DialerWidget", "ABC", 0, QApplication::UnicodeUTF8));
        zeroButton->setText(QApplication::translate("DialerWidget", "0", 0, QApplication::UnicodeUTF8));
        backspaceButton->setText(QApplication::translate("DialerWidget", "backspace", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(DialerWidget);
    } // retranslateUi

};

namespace Ui {
    class DialerWidget: public Ui_DialerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALERWIDGET_H
