#include "mainview.h"

void MainView::loadTexture(QString const texname, GLuint *textureHandle){
    //QImage imageq(":/textures/cat_diff");
    QImage imageq(texname);
    QVector<quint8> imagev(imageToBytes(imageq));
    glGenTextures(1, textureHandle);
    glBindTexture(GL_TEXTURE_2D, *textureHandle);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, imageq.width(), imageq.height(), 0,
             GL_RGBA, GL_UNSIGNED_BYTE, imagev.data());
}
