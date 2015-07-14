#include "HistoryWidget.h"
#include <QtCore/QSettings>
#include <QtCore/QRegExp>
#include <QtCore/QModelIndex>
#include <QtGui/QHeaderView>
#include "HistoryModel.h"
#include "voip/SIPCall.h"

HistoryWidget::HistoryWidget(QWidget *parent) : QDialog(parent)
{
    setupUi(this);

    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->setModel(new HistoryModel(this));
    tableView->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);

    connect(tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(onDoubleClicked(const QModelIndex &)));
}

HistoryWidget::~HistoryWidget()
{
}

void HistoryWidget::onDoubleClicked(const QModelIndex &index)
{
    const QAbstractItemModel *model = index.model();
    QModelIndex numberIndex = model->index(index.row(), 2, index);
    QString number = numberIndex.data(Qt::DisplayRole).toString();
    number.replace(QRegExp("^sip:"), "");
    emit call(number);
}

void HistoryWidget::onCallStateChanged(Call call, int callState)
{
    switch (callState) {
        case micro::voip::SIPCall::STATE_DISCONNECTED :
            if (call.getCallType() != Call::TYPE_NONE) {
                HistoryModel *model = (HistoryModel *) tableView->model();
                model->addRecord(call);
                emit historyChanged(model->getCompleterList());
            }
            break;
    }
}
