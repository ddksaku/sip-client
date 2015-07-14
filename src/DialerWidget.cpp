#include "DialerWidget.h"


DialerWidget::DialerWidget(QWidget *parent) : QDialog(parent), layout(LAYOUT_123)
{
    setupUi(this);

    timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    currentButton = 0;
    currentCharacter = 0;

    buttonsLayout[LAYOUT_123][0] = "0";
    buttonsLayout[LAYOUT_123][1] = "1";
    buttonsLayout[LAYOUT_123][2] = "2";
    buttonsLayout[LAYOUT_123][3] = "3";
    buttonsLayout[LAYOUT_123][4] = "4";
    buttonsLayout[LAYOUT_123][5] = "5";
    buttonsLayout[LAYOUT_123][6] = "6";
    buttonsLayout[LAYOUT_123][7] = "7";
    buttonsLayout[LAYOUT_123][8] = "8";
    buttonsLayout[LAYOUT_123][9] = "9";
    buttonsLayout[LAYOUT_123][10] = "ABC";

    buttonsLayout[LAYOUT_ABC][0] = "space";
    buttonsLayout[LAYOUT_ABC][1] = "*#@";
    buttonsLayout[LAYOUT_ABC][2] = "abc";
    buttonsLayout[LAYOUT_ABC][3] = "def";
    buttonsLayout[LAYOUT_ABC][4] = "ghi";
    buttonsLayout[LAYOUT_ABC][5] = "jkl";
    buttonsLayout[LAYOUT_ABC][6] = "mno";
    buttonsLayout[LAYOUT_ABC][7] = "pqrs";
    buttonsLayout[LAYOUT_ABC][8] = "tuv";
    buttonsLayout[LAYOUT_ABC][9] = "wxyz";
    buttonsLayout[LAYOUT_ABC][10] = "123";
}

void DialerWidget::buttonClicked(int index)
{
    switch (layout) {
        case LAYOUT_123 :
            emit addDigit(QString(buttonsLayout[LAYOUT_123][index][0]));
            break;

        case LAYOUT_ABC :
            if (timer->isActive()) {
                timer->stop();
                if (currentButton == index) {
                    currentCharacter = (currentCharacter + 1) % buttonsLayout[LAYOUT_ABC][currentButton].size();
                    replaceDigit(QString(buttonsLayout[LAYOUT_ABC][currentButton][currentCharacter]));
                }
                else {                    
                    currentButton = index;
                    currentCharacter = 0;
                    emit addDigit(QString(buttonsLayout[LAYOUT_ABC][currentButton][currentCharacter]));
                }
                timer->start();
            }
            else {
                currentButton = index;
                currentCharacter = 0;
                emit addDigit(QString(buttonsLayout[LAYOUT_ABC][currentButton][0]));
                timer->start();
            }
            break;
    }
}

void DialerWidget::onTimeout()
{
    //emit replaceDigit(QString(buttonsLayout[LAYOUT_ABC][currentButton][currentCharacter]));
}

void DialerWidget::on_oneButton_clicked()
{
    buttonClicked(1);
}

void DialerWidget::on_twoButton_clicked()
{
    buttonClicked(2);
}

void DialerWidget::on_threeButton_clicked()
{
    buttonClicked(3);
}

void DialerWidget::on_fourButton_clicked()
{
    buttonClicked(4);
}

void DialerWidget::on_fiveButton_clicked()
{
    buttonClicked(5);
}

void DialerWidget::on_sixButton_clicked()
{
    buttonClicked(6);
}

void DialerWidget::on_sevenButton_clicked()
{
    buttonClicked(7);
}

void DialerWidget::on_eightButton_clicked()
{
    buttonClicked(8);
}

void DialerWidget::on_nineButton_clicked()
{
    buttonClicked(9);
}

void DialerWidget::on_zeroButton_clicked()
{
    buttonClicked(0);
}

void DialerWidget::on_layoutButton_clicked()
{
    switch (layout) {
        case LAYOUT_123 :
            changeLayout(LAYOUT_ABC);
            break;

        case LAYOUT_ABC :
            changeLayout(LAYOUT_123);
            break;
    }

    currentCharacter = 0;
    currentButton = 0;
    if (timer->isActive()) {
        timer->stop();
    }
}

void DialerWidget::on_backspaceButton_clicked()
{
    emit removeDigit();
}

void DialerWidget::changeLayout(Layout layout)
{
    this->layout = layout;
    zeroButton->setText(buttonsLayout[layout][0]);
    oneButton->setText(buttonsLayout[layout][1]);
    twoButton->setText(buttonsLayout[layout][2]);
    threeButton->setText(buttonsLayout[layout][3]);
    fourButton->setText(buttonsLayout[layout][4]);
    fiveButton->setText(buttonsLayout[layout][5]);
    sixButton->setText(buttonsLayout[layout][6]);
    sevenButton->setText(buttonsLayout[layout][7]);
    eightButton->setText(buttonsLayout[layout][8]);
    nineButton->setText(buttonsLayout[layout][9]);

    layoutButton->setText(buttonsLayout[layout][10]);
}
