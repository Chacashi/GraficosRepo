#pragma once

#include <string>
#include "Transform.h"

#include "TextureManager.h"

using namespace std;
class Figura
{
public:
	Transform transform;
	
    GLuint textureID;

    void SetTexture(GLuint tex) {
        textureID = tex;
    }
    void CargarTextura(const char* fileName, TextureManager* texManager) {
        textureID = texManager->LoadBMP(fileName);
    }

    void AplicarTextura() {
        if (textureID != 0) {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, textureID);
        }
    }

    void DesactivarTextura() {
        glDisable(GL_TEXTURE_2D);
    }

    virtual void Dibujar() = 0;

};

