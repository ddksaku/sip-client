#ifndef __HistoryWidget__
#define __HistoryWidget__

#include <QtGui/QDialog>
#include "ui_HistoryWidget.h"
#include "Call.h"

class QTableWidgetItem;
class QModelIndex;
class HistoryModel;

/**
 * History widget.
 */
class HistoryWidget : public QDialog , public Ui::HistoryWidget {

        Q_OBJECT

    private :
        HistoryModel *historyModel;

    public :
        /** Constructor. */
        HistoryWidget(QWidget *parent = 0);

        /** Destructor. */
        ~HistoryWidget();

        /** Returns history model. */
        HistoryModel* getHistoryModel() const { return (HistoryModel*) tableView->model(); }

    signals :
        void call(const QString &number);
        void historyChanged(const QStringList &list);

    public slots :
        void onCallStateChanged(Call call, int callState);

    private slots :
        void onDoubleClicked(const QModelIndex &index);

};

#endif /* __HistoryWidget__ */
