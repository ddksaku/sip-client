#ifndef __GLWidget__
#define __GLWidget__

//#include <QGLWidget>
#include <QWidget>

class GLWidget : public /*QGLWidget*/ QWidget {

    private :

    public :
        GLWidget(QWidget *parent = 0);

    private :
        //void paintGL();

};

#endif /* __GLWidget__ */
