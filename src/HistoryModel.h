#ifndef __HistoryModel__
#define __HistoryModel__

#include "AbstractModel.h"
#include <QtCore/QModelIndex>
#include <QtCore/QList>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include "Call.h"

class QObject;

/**
 * History model.
 */
class HistoryModel : public AbstractModel {

        Q_OBJECT

    private :
        static const int columns = 3;     /**< Columns count. */
        static const int maxRecords = 10; /**< Maximum number of records. */
        QList<Call> historyList;       /**< List of the history records. */

    public :
        /** Constructor. */
        HistoryModel(QObject *parent = 0);

        /** Destructor. */
        ~HistoryModel();

        /** Returns row count. */
        int rowCount(const QModelIndex &parent = QModelIndex()) const { return historyList.size(); }

        /** Returns columnt count. */
        int columnCount(const QModelIndex &parent = QModelIndex()) const { return columns; }

        /** Returns data at position specified by index. */
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

        /** Returns header data at position specified by section and orientation. */
        QVariant headerData(int section, Qt::Orientation orientation, int role) const;

        /** Adds phone number to history list. */
        void addRecord(const Call &call);

        QStringList getCompleterList();

    private :
        /** Loads history data. */
        void loadData();

        /** Saves history data. */
        void saveData();

};

#endif /* __HistoryModel__ */
