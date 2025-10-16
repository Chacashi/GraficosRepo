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

    Ejercicio1();
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
     {-distance, -distance, -distance}, 
     { distance, -distance, -distance}, 
     { distance,  distance, -distance}, 
     {-distance,  distance, -distance}, 
     {-distance, -distance,  distance}, 
     { distance, -distance,  distance}, 
     { distance,  distance,  distance}, 
     {-distance,  distance,  distance}  
    };

    GLfloat colores[][3] = {
        {1.0, 0.0, 0.0}, 
        {0.0, 1.0, 0.0}, 
        {0.0, 0.0, 1.0}, 
        {1.0, 1.0, 0.0}, 
        {1.0, 0.0, 1.0}, 
        {0.0, 1.0, 1.0}, 
        {1.0, 1.0, 1.0}, 
        {0.3, 0.3, 0.3}  
    };

    GLubyte indices[] = {
        0,1,2,3,   
        4,5,6,7,   
        0,4,7,3,   
        1,5,6,2,  
        3,2,6,7,   
        0,1,5,4    
    };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colores);

 
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indices);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

void Example7::DrawCuadIndex(float distance)
{
    GLfloat vertices[][2] = {
    {-distance, -distance}, 
    { distance, -distance}, 
    { distance,  distance}, 
    {-distance,  distance}  
    };
    GLfloat colores[][3] = {
    {1.0f, 0.0f, 0.0f}, 
    {0.0f, 1.0f, 0.0f}, 
    {0.0f, 0.0f, 1.0f}, 
    {1.0f, 1.0f, 0.0f}  
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
     
        {-distance, -distance,  distance},
        { distance, -distance,  distance},
        { distance,  distance,  distance},
        {-distance,  distance,  distance},

     
        { distance, -distance, -distance},
        {-distance, -distance, -distance},
        {-distance,  distance, -distance},
        { distance,  distance, -distance},


        {-distance, -distance, -distance},
        {-distance, -distance,  distance},
        {-distance,  distance,  distance},
        {-distance,  distance, -distance},

      
        { distance, -distance,  distance},
        { distance, -distance, -distance},
        { distance,  distance, -distance},
        { distance,  distance,  distance},

     
        {-distance,  distance,  distance},
        { distance,  distance,  distance},
        { distance,  distance, -distance},
        {-distance,  distance, -distance},

   
        {-distance, -distance, -distance},
        { distance, -distance, -distance},
        { distance, -distance,  distance},
        {-distance, -distance,  distance}
    };


    GLfloat colores[][3] = {
     
        {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f},
   
        {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f},
 
        {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f},
      
        {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f},
 
        {1.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f},
    
        {0.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}
    };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colores);


    glDrawArrays(GL_QUADS, 0, 24);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

void Example7::DrawCuad(float distance)
{
    GLfloat vertices[][2] = {
    {-distance, -distance},
    { distance, -distance}, 
    { distance,  distance}, 
    {-distance,  distance}  
    };


    GLfloat colores[][3] = {
        {1.0f, 0.0f, 0.0f}, 
        {0.0f, 1.0f, 0.0f}, 
        {0.0f, 0.0f, 1.0f}, 
        {1.0f, 1.0f, 0.0f}  
    };
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colores);

   
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

    
    glDrawArrays(GL_TRIANGLE_STRIP, 0, vertexCount);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

void Example7::DrawPyramid(float distance)
{
    GLfloat vertices[][3] = {

        { 0.0f,  distance,  0.0f},   
        {-distance, -distance,  distance}, 
        { distance, -distance,  distance}, 

  
        { 0.0f,  distance,  0.0f},
        { distance, -distance,  distance},
        { distance, -distance, -distance},


        { 0.0f,  distance,  0.0f},
        { distance, -distance, -distance},
        {-distance, -distance, -distance},


        { 0.0f,  distance,  0.0f},
        {-distance, -distance, -distance},
        {-distance, -distance,  distance},


        {-distance, -distance,  distance},
        { distance, -distance,  distance},
        { distance, -distance, -distance},
        {-distance, -distance, -distance}
    };

    GLfloat colores[][3] = {

        {1.0f, 0.0f, 0.0f}, {1.0f, 0.5f, 0.0f}, {1.0f, 0.5f, 0.0f}, 
        {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.5f}, {0.0f, 1.0f, 0.5f}, 
        {0.0f, 0.0f, 1.0f}, {0.3f, 0.3f, 1.0f}, {0.3f, 0.3f, 1.0f}, 
        {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.5f}, {1.0f, 1.0f, 0.5f}, 

        {0.5f, 0.0f, 0.5f}, {0.5f, 0.0f, 0.5f}, {0.5f, 0.0f, 0.5f}, {0.5f, 0.0f, 0.5f}
    };

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colores);


    glDrawArrays(GL_TRIANGLES, 0, 12);


    glDrawArrays(GL_QUADS, 12, 4);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

void Example7::Ejercicio1()
{
    //DrawCube(1.0f);
    //DrawCuad(1.0f);
    //DrawSphere(1.0f, 32, 32);
    //DrawPyramid(1.0f);
    //DrawCubeIndex(1.0f);
    //DrawCuadIndex(1.0f);
    //DrawSphereIndex(1.0f, 32, 32);
    //DrawPyramidIndex(1.0f);
}

void Example7::Ejercicio2()
{
}
