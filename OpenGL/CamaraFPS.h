#pragma once
#include "Camara.h"
#include <GL/glut.h>
#include <cmath>
class CamaraFPS :
    public Camara
{
private:
    float x, y, z;    
    float yaw;         
    float velocidad;   
    float giro;        
    float altura;      

public:
    CamaraFPS(float px = 0.0f, float pz = 5.0f, float h = 2.0f)
        : x(px), y(h), z(pz), yaw(0.0f), velocidad(0.2f), giro(2.0f), altura(h) {
    }

    void ApplyView() override {
        float rad = yaw * 3.14159265f / 180.0f;
        float lx = sinf(rad);   
        float lz = -cosf(rad);  

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(x, y, z, x + lx, y, z + lz, 0.0f, 1.0f, 0.0f);
    }

    void Keyboard(unsigned char key) override {
        float rad = yaw * 3.14159265f / 180.0f;

        switch (key) {
        case 'w': 
            x += velocidad * sinf(rad);
            z += -velocidad * cosf(rad);
            break;
        case 's': 
            x -= velocidad * sinf(rad);
            z -= -velocidad * cosf(rad);
            break;
        case 'a': 
            yaw -= giro;
            if (yaw < 0) yaw += 360;
            break;
        case 'd': 
            yaw += giro;
            if (yaw >= 360) yaw -= 360;
            break;
        }
    }
};

