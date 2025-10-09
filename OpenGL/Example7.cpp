#include "Example7.h"
#include <GL/glut.h>
#include <cmath>
#define PI 3.14159265359
#define MAX_SLICES 40
#define MAX_STACKS 40



void Example7::init()
{
    glClearColor(0.1, 0.1, 0.1, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.0, 2.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void Example7::Render()
{
	//DrawCube(1.0);
	//DrawCuad(1.0);
	//DrawSphere(1.0, 20, 20);
	//DrawPyramid(1.0);
}

void Example7::KeyboardFunc(unsigned char key, int X, int Y)
{
}

void Example7::Idle()
{
}

void Example7::DrawCubeIndex(float distance)
{
    GLfloat vertices[][3] = {
     {-distance, -distance, -distance}, // 0
     { distance, -distance, -distance}, // 1
     { distance,  distance, -distance}, // 2
     {-distance,  distance, -distance}, // 3
     {-distance, -distance,  distance}, // 4
     { distance, -distance,  distance}, // 5
     { distance,  distance,  distance}, // 6
     {-distance,  distance,  distance}  // 7
    };

    GLfloat colores[][3] = {
        {1.0, 0.0, 0.0}, // rojo
        {0.0, 1.0, 0.0}, // verde
        {0.0, 0.0, 1.0}, // azul
        {1.0, 1.0, 0.0}, // amarillo
        {1.0, 0.0, 1.0}, // magenta
        {0.0, 1.0, 1.0}, // cian
        {1.0, 1.0, 1.0}, // blanco
        {0.3, 0.3, 0.3}  // gris
    };

    GLubyte indices[] = {
        0,1,2,3,   // cara trasera
        4,5,6,7,   // cara frontal
        0,4,7,3,   // izquierda
        1,5,6,2,   // derecha
        3,2,6,7,   // arriba
        0,1,5,4    // abajo
    };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colores);

    // Dibujar las 6 caras
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indices);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

void Example7::DrawCuadIndex(float distance)
{
    GLfloat vertices[][2] = {
    {-distance, -distance}, // abajo izquierda
    { distance, -distance}, // abajo derecha
    { distance,  distance}, // arriba derecha
    {-distance,  distance}  // arriba izquierda
    };
    GLfloat colores[][3] = {
    {1.0f, 0.0f, 0.0f}, // rojo
    {0.0f, 1.0f, 0.0f}, // verde
    {0.0f, 0.0f, 1.0f}, // azul
    {1.0f, 1.0f, 0.0f}  // amarillo
    };

    GLubyte indices[] = { 0, 1, 2, 3 };
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colores);

    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, indices);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();

}

void Example7::DrawSphereIndex(float radius, int slices, int stacks)
{
    GLfloat vertices[(MAX_SLICES + 1) * (MAX_STACKS + 1) * 3];
    GLfloat colores[(MAX_SLICES + 1) * (MAX_STACKS + 1) * 3];
    GLushort indices[MAX_SLICES * MAX_STACKS * 6];
    int vIndex = 0;
    int cIndex = 0;
    int iIndex = 0;

    for (int i = 0; i <= stacks; i++) {
        float phi = PI * i / stacks;
        float y = cos(phi);
        float r_sin = sin(phi);

        for (int j = 0; j <= slices; j++) {
            float theta = 2 * PI * j / slices;
            float x = r_sin * cos(theta);
            float z = r_sin * sin(theta);

            vertices[vIndex++] = radius * x;
            vertices[vIndex++] = radius * y;
            vertices[vIndex++] = radius * z;

            colores[cIndex++] = (x + 1) / 2;
            colores[cIndex++] = (y + 1) / 2;
            colores[cIndex++] = (z + 1) / 2;
        }
    }


    for (int i = 0; i < stacks; i++) {
        for (int j = 0; j < slices; j++) {
            int first = i * (slices + 1) + j;
            int second = first + slices + 1;

            indices[iIndex++] = first;
            indices[iIndex++] = second;
            indices[iIndex++] = first + 1;

            indices[iIndex++] = second;
            indices[iIndex++] = second + 1;
            indices[iIndex++] = first + 1;
        }
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colores);

    glDrawElements(GL_TRIANGLES, slices * stacks * 6, GL_UNSIGNED_SHORT, indices);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

void Example7::DrawPyramidIndex(float distance)
{
    GLfloat vertices[][3] = {
    { 0.0f,  distance,  0.0f},   
    {-distance, -distance,  distance}, 
    { distance, -distance,  distance}, 
    { distance, -distance, -distance}, 
    {-distance, -distance, -distance}  
    };

    GLfloat colores[][3] = {
        {1.0f, 0.0f, 0.0f}, 
        {0.0f, 1.0f, 0.0f}, 
        {0.0f, 0.0f, 1.0f}, 
        {1.0f, 1.0f, 0.0f}, 
        {1.0f, 0.0f, 1.0f}  
    };


    GLubyte indices[] = {
        0,1,2,   
        0,2,3,   
        0,3,4,   
        0,4,1,   
        1,2,3,4  
    };


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colores);

   
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, indices);

  
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, &indices[12]);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

void Example7::DrawCube(float distance)
{
    GLfloat vertices[][3] = {
        // Frente (Z positivo)
        {-distance, -distance,  distance},
        { distance, -distance,  distance},
        { distance,  distance,  distance},
        {-distance,  distance,  distance},

        // Atrás (Z negativo)
        { distance, -distance, -distance},
        {-distance, -distance, -distance},
        {-distance,  distance, -distance},
        { distance,  distance, -distance},

        // Izquierda (X negativo)
        {-distance, -distance, -distance},
        {-distance, -distance,  distance},
        {-distance,  distance,  distance},
        {-distance,  distance, -distance},

        // Derecha (X positivo)
        { distance, -distance,  distance},
        { distance, -distance, -distance},
        { distance,  distance, -distance},
        { distance,  distance,  distance},

        // Arriba (Y positivo)
        {-distance,  distance,  distance},
        { distance,  distance,  distance},
        { distance,  distance, -distance},
        {-distance,  distance, -distance},

        // Abajo (Y negativo)
        {-distance, -distance, -distance},
        { distance, -distance, -distance},
        { distance, -distance,  distance},
        {-distance, -distance,  distance}
    };

    // -------------------- COLORES --------------------
    GLfloat colores[][3] = {
        // Frente
        {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f},
        // Atrás
        {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f},
        // Izquierda
        {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f},
        // Derecha
        {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f},
        // Arriba
        {1.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f},
        // Abajo
        {0.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}
    };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colores);

    // Dibujar 6 caras (cada una 4 vértices)
    glDrawArrays(GL_QUADS, 0, 24);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

void Example7::DrawCuad(float distance)
{
    GLfloat vertices[][2] = {
    {-distance, -distance}, // abajo izquierda
    { distance, -distance}, // abajo derecha
    { distance,  distance}, // arriba derecha
    {-distance,  distance}  // arriba izquierda
    };

    // -------------------- COLORES --------------------
    GLfloat colores[][3] = {
        {1.0f, 0.0f, 0.0f}, // rojo
        {0.0f, 1.0f, 0.0f}, // verde
        {0.0f, 0.0f, 1.0f}, // azul
        {1.0f, 1.0f, 0.0f}  // amarillo
    };
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colores);

    // Dibujar el cuadrado (4 vértices)
    glDrawArrays(GL_QUADS, 0, 4);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

void Example7::DrawSphere(float radius, int slices, int stacks)
{
    GLfloat vertices[20000][3];
    GLfloat colors[20000][3];
    int vertexCount = 0;
     
    vertexCount = 0;
    for (int i = 0; i <= stacks; i++)
    {
        float lat0 = PI * (-0.5f + (float)(i - 1) / stacks);
        float z0 = sin(lat0);
        float zr0 = cos(lat0);

        float lat1 = PI * (-0.5f + (float)i / stacks);
        float z1 = sin(lat1);
        float zr1 = cos(lat1);

        for (int j = 0; j <= slices; j++)
        {
            float lng = 2 * PI * (float)(j - 1) / slices;
            float x = cos(lng);
            float y = sin(lng);

            // primer triángulo de la franja
            vertices[vertexCount][0] = radius * x * zr0;
            vertices[vertexCount][1] = radius * y * zr0;
            vertices[vertexCount][2] = radius * z0;
            colors[vertexCount][0] = (x + 1) / 2;
            colors[vertexCount][1] = (y + 1) / 2;
            colors[vertexCount][2] = (z0 + 1) / 2;
            vertexCount++;

            vertices[vertexCount][0] = radius * x * zr1;
            vertices[vertexCount][1] = radius * y * zr1;
            vertices[vertexCount][2] = radius * z1;
            colors[vertexCount][0] = (x + 1) / 2;
            colors[vertexCount][1] = (y + 1) / 2;
            colors[vertexCount][2] = (z1 + 1) / 2;
            vertexCount++;
        }
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    // Dibujamos la esfera con triángulos en tiras (por franjas)
    glDrawArrays(GL_TRIANGLE_STRIP, 0, vertexCount);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

void Example7::DrawPyramid(float distance)
{
    GLfloat vertices[][3] = {
        // Cara frontal
        { 0.0f,  distance,  0.0f},   // punta
        {-distance, -distance,  distance}, // izquierda base
        { distance, -distance,  distance}, // derecha base

        // Cara derecha
        { 0.0f,  distance,  0.0f},
        { distance, -distance,  distance},
        { distance, -distance, -distance},

        // Cara trasera
        { 0.0f,  distance,  0.0f},
        { distance, -distance, -distance},
        {-distance, -distance, -distance},

        // Cara izquierda
        { 0.0f,  distance,  0.0f},
        {-distance, -distance, -distance},
        {-distance, -distance,  distance},

        // Base (cuadrado)
        {-distance, -distance,  distance},
        { distance, -distance,  distance},
        { distance, -distance, -distance},
        {-distance, -distance, -distance}
    };

    GLfloat colores[][3] = {
        // Caras
        {1.0f, 0.0f, 0.0f}, {1.0f, 0.5f, 0.0f}, {1.0f, 0.5f, 0.0f}, // frontal
        {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.5f}, {0.0f, 1.0f, 0.5f}, // derecha
        {0.0f, 0.0f, 1.0f}, {0.3f, 0.3f, 1.0f}, {0.3f, 0.3f, 1.0f}, // trasera
        {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.5f}, {1.0f, 1.0f, 0.5f}, // izquierda
        // Base
        {0.5f, 0.0f, 0.5f}, {0.5f, 0.0f, 0.5f}, {0.5f, 0.0f, 0.5f}, {0.5f, 0.0f, 0.5f}
    };

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colores);

    // Dibujar las 4 caras triangulares
    glDrawArrays(GL_TRIANGLES, 0, 12);

    // Dibujar la base (cuadrado)
    glDrawArrays(GL_QUADS, 12, 4);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

void Example7::Ejercicio1()
{
}

void Example7::Ejercicio2()
{
}
