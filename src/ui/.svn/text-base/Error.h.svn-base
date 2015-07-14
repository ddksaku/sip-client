#ifndef __ui_Error__
#define __ui_Error__

#include <QtCore/QObject>
#include <QtCore/QString>

namespace ui {

/**
 * Error information.
 */
class Error {

        QString message; /** Error message. */

    public :

        /** Constructor. */
        Error(const QString &message = "") : message(message) {}

        /** Returns error message. */
        QString getMessage() { return message; }

        /** Sets error message. */
        void setMessage(const QString &message) { this->message = message; }

};

}

#endif /* __ui_Error__ */
