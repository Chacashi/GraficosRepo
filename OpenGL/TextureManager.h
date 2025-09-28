#pragma once

#include <GL/glew.h>
#include <GL/glut.h>
#include "process_image.h" 


class TextureManager
{
private:
    bool ImageLoad(const char* filename, Image* image);
public:
    TextureManager();
    GLuint LoadGLTextures(const char* filename);
    GLuint LoadBMP(const char* fileName);
    GLuint LoadGLTexture(const char* filename);
};

