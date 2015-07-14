#ifndef __AbstractModel__
#define __AbstractModel__

#include <QtCore/QAbstractTableModel>

/**
 * Abstract model class.
 */
class AbstractModel : public QAbstractTableModel {

    protected :
        virtual void loadData() = 0;
        virtual void saveData() = 0;

    public :
        AbstractModel(QObject *parent)
            : QAbstractTableModel(parent)
        {}
};

#endif /* __AbstractModel__ */
