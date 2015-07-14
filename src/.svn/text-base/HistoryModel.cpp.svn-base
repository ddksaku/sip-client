#include "HistoryModel.h"
#include <QtCore/QObject>
#include <QtCore/QSettings>

HistoryModel::HistoryModel(QObject *parent) : AbstractModel(parent)
{
    loadData();
}

HistoryModel::~HistoryModel()
{
    saveData();
}

QVariant HistoryModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    if (index.row() >= historyList.size() || index.column() >= columns) {
        return QVariant();
    }

    switch (role) {
        case Qt::DisplayRole :
            switch (index.column()) {
                case 0 :
                    switch (historyList.at(index.row()).getCallType()) {
                        case Call::TYPE_OUTGOING :
                            return QString("Outgoing");
                        case Call::TYPE_INCOMING :
                            return QString("Incoming");
                        case Call::TYPE_MISSED :
                            return QString("Missed");
                        default :
                            return "";
                    }
                case 1 :
                    return historyList.at(index.row()).getStartDate().toString(Qt::SystemLocaleDate);
                case 2 :
                    return historyList.at(index.row()).getNumber();
                default :
                    return QVariant();
            }
        default :
            return QVariant();
    }
}

QVariant HistoryModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical) {
        return QString("%1").arg(section);
    }

    switch (role) {
        case Qt::DisplayRole :
            switch (section) {
                case 0 :
                    return QString("Type");
                case 1 :
                    return QString("Date");
                case 2 :
                    return QString("Number");
                default :
                    return QVariant();
            }
        default :
            return QVariant();
    }
}

void HistoryModel::loadData()
{
    QSettings settings;
    QString historyString = settings.value("settings/history").toString();
    QStringList stringList = historyString.split(";");
    foreach (QString string, stringList) {
        if (string != "") {
            QStringList parts = string.split(",");
            QDateTime startDate = QDateTime::fromString(parts.at(0), Qt::ISODate);
            QDateTime stopDate = QDateTime::fromString(parts.at(1), Qt::ISODate);
            QString number = parts.at(2);
            Call::CallType type = (Call::CallType) parts.at(3).toInt();
            Call call(number, type, startDate, stopDate);
            historyList << call;
        }
    }
}

void HistoryModel::saveData()
{
    QString historyString;
    foreach (Call call, historyList) {
        historyString += call.getStartDate().toString(Qt::ISODate) + "," + call.getStopDate().toString(Qt::ISODate) + "," + call.getNumber() + "," + QString::number(call.getCallType()) + ";";
    }

    QSettings settings;
    settings.setValue("settings/history", historyString);
}

QStringList HistoryModel::getCompleterList()
{
    QStringList list;
    for (int i = 0; i < rowCount(); i++) {
        QModelIndex modelIndex = index(i, 2, QModelIndex());
        QString string = data(modelIndex, Qt::DisplayRole).toString();
        list << string;
        string.replace(QRegExp("^sip:"), "");
        list << string;
    }
    return list;
}

void HistoryModel::addRecord(const Call &call)
{
    beginInsertRows(QModelIndex(), 0, 0);
        historyList.prepend(call);
    endInsertRows();

    if (historyList.size() > maxRecords) {
        beginRemoveRows(QModelIndex(), maxRecords, historyList.size() - 1);
            while (historyList.size() > maxRecords) {
                historyList.removeLast();
            }
        endRemoveRows();
    }
}
