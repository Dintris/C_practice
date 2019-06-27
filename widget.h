#ifndef WIDGET_H
#define WIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>
#include <QVector3D>
#include <QVector2D>
#include <QMatrix4x4>
#include <QMouseEvent>

struct VertexData
{
    VertexData() {}
    VertexData(QVector3D p,  QVector2D t,  QVector3D n):
        position(p), texCoord(t), normal(n)
    {
    }

    QVector3D position;
    QVector2D texCoord;
    QVector3D normal;
};


class Widget : public QOpenGLWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    void initShaders();
    void initCube(float width);

private:

    QMatrix4x4 m_projectonMatrix;
    QOpenGLShaderProgram m_program;
    QOpenGLTexture* m_texture;
    QOpenGLBuffer m_arrayBuffer;
    QOpenGLBuffer m_indexBuffer;
    QVector2D m_mousePosition;
    QQuaternion m_rotation;

};

#endif // WIDGET_H
