#ifndef __Call__
#define __Call__

#include <QtCore/QDateTime>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QMetaType>


/**
 * Call information.
 */
class Call {

    public :
        enum CallType {
            TYPE_OUTGOING,
            TYPE_INCOMING,
            TYPE_MISSED,
            TYPE_NONE
        };

    private :
        QString number;
        CallType type;
        QDateTime startDate;
        QDateTime stopDate;

    public :
        /** Constructor. */
        Call()
            : number("unknown"), type(TYPE_NONE)
        {}

        /** Constructor. */
        Call(const QString &number, CallType type, const QDateTime &startDate = QDateTime::currentDateTime())
            : number(number), type(type), startDate(startDate), stopDate(startDate)
        {}

        /** Constructor. */
        Call(const QString &number, CallType type, const QDateTime &startDate, const QDateTime &stopDate)
            : number(number), type(type), startDate(startDate), stopDate(stopDate)
        {}

        /** Returns call type. */
        CallType getCallType() const { return type; }

        /** Returns call start date. */
        QDateTime getStartDate() const { return startDate; }

        /** Returns call stop date. */
        QDateTime getStopDate() const { return stopDate; }

        /** Sets call stop date. */
        void setStopDate(const QDateTime &date) { this->stopDate = date; }

        /** Returns number. */
        QString getNumber() const { return number; }

};

Q_DECLARE_METATYPE(Call)

#endif /* __Call__ */
