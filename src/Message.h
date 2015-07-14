#ifndef __Message__
#define	__Message__

#include <QtCore/QStringList>

/**
 * Message for SIP phone message loop.
 */
class Message {

    public :
        /** Message code enumeration. */
        enum Code {
            CALL            = 1,
            HANGUP          = 2,
            ANSWER          = 3,
            DIAL_DTMF       = 4,
            CHANGE_ACCOUNT  = 5,
            CHANGE_NETWORK  = 6,
            ONLINE          = 7,
            OFFLINE         = 8,
            EXIT            = 9
        };

    private :
        Code code;                  /**< Message code. */
        QStringList parameters;    /**< Message parameters. */

    public :
        /** Constructor. */
        Message(Code code, const QStringList &parameters = QStringList())
            : code(code), parameters(parameters)
        {}

        /** Returns code. */
        Code getCode() { return code; }

        /** Returns parameter. */
        QStringList getParameters() { return parameters; }
};

#endif	/* __Message__ */
