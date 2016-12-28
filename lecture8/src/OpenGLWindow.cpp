/*
 * Basic GL Window modified from the example here
 * http://qt-project.org/doc/qt-5.0/qtgui/openglwindow.html
 * adapted to use NGL
 */
#include "OpenGLWindow.h"
#include <QtCore/QCoreApplication>
#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLPaintDevice>
#include <QtGui/QPainter>
#include <QKeyEvent>
#include <QApplication>
#include <iostream>
#ifdef __APPLE__
  #include <glu.h>
#else
  #include <GL/glu.h>
#endif


OpenGLWindow::OpenGLWindow()
{
  setTitle("Qt5 compat profile OpenGL 2.1");
}

OpenGLWindow::~OpenGLWindow()
{
}



void OpenGLWindow::initializeGL()
{

  glClear(GL_COLOR_BUFFER_BIT); //
  glMatrixMode(GL_PROJECTION);
  ;
  int w=this->size().width();
  int h=this->size().height();
  gluPerspective(45,(float)w/h,0.5,100);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(28,28,28,0,0,0,0,1,0);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  glViewport(0,0,width(),height());
  startTimer(40);

}

void OpenGLWindow::drawCube(float _w, float _h, float _d)
{
    float w2 = _w / 2.0f;
    float h2 = _h / 2.0f;
    float d2 = _d / 2.0f;

    glBegin(GL_TRIANGLES);
    //front face
    glColor3f(1,0,0);
    glVertex3d(-w2, h2, d2); //D
    glVertex3d(-w2, -h2, d2); //A
    glVertex3d(w2, -h2, d2); //B

    glVertex3d(-w2, h2, d2); //D
    glVertex3d(w2, h2, d2); //C
    glVertex3d(w2, -h2, d2); //B

    //back face
    glVertex3d(-w2, h2, -d2); //D
    glVertex3d(-w2, -h2, -d2); //E
    glVertex3d(w2, -h2, -d2); //B

    glVertex3d(-w2, h2, -d2); //H
    glVertex3d(w2, h2, -d2); //C
    glVertex3d(w2, -h2, -d2); //B

    //left face
    glColor3f(0,1,0);
    glVertex3d(-w2, h2, d2); //D
    glVertex3d(-w2, -h2, d2); //A
    glVertex3d(-w2, -h2, -d2); //E

    glVertex3d(-w2, h2, -d2); //H
    glVertex3d(-w2, h2, d2); //D
    glVertex3d(-w2, -h2, -d2); //E

    //right face
    glVertex3d(w2, h2, d2); //D
    glVertex3d(w2, -h2, d2); //A
    glVertex3d(w2, -h2, -d2); //E

    glVertex3d(w2, h2, -d2); //H
    glVertex3d(w2, h2, d2); //D
    glVertex3d(w2, -h2, -d2); //E

    //top face
    glColor3f(0,0,1);
    glVertex3d(-w2, h2, d2); //D
    glVertex3d(w2, h2, -d2); //G
    glVertex3d(-w2, h2, -d2); //H

    glVertex3d(-w2, h2, d2); //D
    glVertex3d(w2, h2, d2); //C
    glVertex3d(w2, h2, -d2); //G

    //bottom face
    glVertex3d(-w2, -h2, d2); //D
    glVertex3d(w2, -h2, -d2); //G
    glVertex3d(-w2, -h2, -d2); //H

    glVertex3d(-w2, -h2, d2); //D
    glVertex3d(w2, -h2, d2); //C
    glVertex3d(w2, -h2, -d2); //G
    glEnd();


}

void OpenGLWindow::paintGL()
{
  glViewport(0,0,m_width,m_height);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  for(int i = -15; i < 15; i+=1)
  {
      for(int j = -15; j < 15; j+=1)
      {
          for(int k = -15; k < 15; k+=1)
          {
              glPushMatrix();
//              glRotated(rot*i*2,1,0,0);
//              glRotated(rot*j*2,0,1,0);
//              glRotated(rot*k*2,0,0,1);

                glPushMatrix();
                glTranslatef(i,i,k);
                    drawCube(0.1,0.1,0.1);
                glPopMatrix();
              glPopMatrix();
          }
      }
  }
  //static int rot=0;

 // ++rot;
}

void OpenGLWindow::timerEvent(QTimerEvent *)
{
  rot++;
  update();
}

void OpenGLWindow::keyPressEvent(QKeyEvent *_event)
{
  switch (_event->key())
  {
   case Qt::Key_Escape : QApplication::exit(EXIT_SUCCESS); break;
  }
}


void OpenGLWindow::resizeGL(int _w, int _h)
{

  m_width=_w;
  m_height=_h;

}

