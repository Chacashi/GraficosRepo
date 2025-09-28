#include "TextureManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "process_image.h"
#include "BMPTextureLoader.h"
#include <GL/freeglut.h>
#include <GL/glew.h>
#include <GL/glut.h>
static unsigned int getint(FILE* fp)
{
    unsigned int c, c1, c2, c3;
    c = ((unsigned int)getc(fp));  // get 4 bytes
    c1 = ((unsigned int)getc(fp)) << 8;
    c2 = ((unsigned int)getc(fp)) << 16;
    c3 = ((unsigned int)getc(fp)) << 24;

    return c | c1 | c2 | c3;
}

// Ensure that Little Endian shorts are read into memory correctly on Big Endian platforms
static unsigned short getshort(FILE* fp)
{
    unsigned short c, c1, c2, c3;;
    //get 2 bytes
    c = ((unsigned short)getc(fp));
    c1 = ((unsigned short)getc(fp)) << 8;
    c2 = ((unsigned int)getc(fp)) << 16;
    c3 = ((unsigned int)getc(fp)) << 24;
    return c | c1;
}
bool TextureManager::ImageLoad(const char* filename, Image* image)
{
    FILE* file;
    unsigned long size;          // size of the image in bytes.
    size_t i, j, k, linediff;		     // standard counter.
    unsigned short int planes;   // number of planes in image (must be 1)
    unsigned short int bpp;      // number of bits per pixel (must be 24)
    char temp;                   // temporary storage for bgr-rgb conversion.

    // Make sure the file is there.
    if ((file = fopen(filename, "rb")) == NULL) {
        printf("File Not Found : %s\n", filename);
        return false;
    }

    // Seek through the bmp header, up to the width/height:
    fseek(file, 18, SEEK_CUR);

    // Read the width
    image->w = getint(file);
    printf("Width of %s: %lu\n", filename, image->w);

    // Read the height
    image->h = getint(file);
    printf("Height of %s: %lu\n", filename, image->h);


    // Calculate the size (assuming 24 bits or 3 bytes per pixel).
    // BMP lines are padded to the nearest double word boundary.
    // fortunat
    size = 4.0 * ceil(image->w * 24.0 / 32.0) * image->h;
    printf("size: %u\n", filename, size);
    // Read the planes
    planes = getshort(file);

    if (planes != 1) {
        printf("Planes from %s is not 1: %u\n", filename, planes);
        return false;
    }

    // Read the bpp
    bpp = getshort(file);

    if (bpp != 3) {
        printf("Bpp from %s is not 24: %u\n", filename, bpp);
        return 0;
    }

    // Seek past the rest of the bitmap header.
    fseek(file, 3, SEEK_CUR);

    // Allocate space for the img.
    image->img = new GLubyte[size];
    if (image->img == NULL) {
        printf("Error allocating memory for color-corrected image img");
        return false;
    }

    // Read the img
    i = fread(image->img, size, 1, file);
    if (i != 1) {
        printf("Error reading image img from %s.\n", filename);
        return false;
    }

    // Reverse all of the colors (bgr -> rgb)
    // Calculate distance to 4 byte boundary for each line
    // if this distance is not 0, then there will be a color reversal error
    //  unless we correct for the distance on each line.
    linediff = 4.0 * ceil(image->w * 24.0 / 32.0) - image->w * 3.0;
    k = 0;
    for (j = 0; j < image->h; j++) {
        for (i = 0; i < image->w; i++) {
            temp = image->img[k];
            image->img[k] = image->img[k + 2];
            image->img[k + 2] = temp;
            k += 3;
        }
        k += linediff;
    }
    return true;
}


TextureManager::TextureManager()
{
}
GLuint TextureManager::LoadBMP(const char* fileName)
{
    FILE* file;
    unsigned char header[54];
    unsigned int imgPos;
    unsigned int size;
    unsigned int width, height;
    unsigned char* img;


    file = fopen(fileName, "rb");

    if (file == NULL)
    {
        //MessageBox(NULL, L"Error: Invaild file path!", L"Error", MB_OK);
        //printf("FError: Invaild file path!\n", fileName);
        printf("Error allocating space for image");
        return false;
    }

    if (fread(header, 1, 54, file) != 54)
    {
        MessageBox(NULL, L"Error: Invaild file!", L"Error", MB_OK);
        printf("Error nvaild file for image");
        return false;
    }

    if (header[0] != 'B' || header[1] != 'M')
    {
        MessageBox(NULL, L"Error: Invaild file!", L"Error", MB_OK);
        return false;
    }

    imgPos = *(int*)&(header[0x0A]);
    size = *(int*)&(header[0x22]);
    width = *(int*)&(header[0x12]);
    height = *(int*)&(header[0x16]);

    if (size == NULL)
        size = width * height * 3;
    if (imgPos == NULL)
        imgPos = 54;

    img = new unsigned char[size];

    fread(img, 1, size, file);

    fclose(file);


    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img);

    return texture;
}
GLuint TextureManager::LoadGLTextures(const char* filename) {
    // Load Texture
    Image* image1;
    GLuint idtextures;
    // Allocate space for texture
    image1 = new Image();
    if (image1 == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }

    // Load picture from file
    if (!ImageLoad(filename, image1)) {
        exit(1);
    }

    // Create Texture Name and Bind it as current
    glGenTextures(1, &idtextures);
    glBindTexture(GL_TEXTURE_2D, idtextures);   // 2d texture (x and y size)

    // Set Texture Parameters
    //  Scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //  Scale linearly when image smaller than texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    // Load texture into OpenGL RC
    glTexImage2D(GL_TEXTURE_2D,     // 2D texture
        0,                  // level of detail 0 (normal)
        3,	                // 3 color components
        image1->w,      // x size from image
        image1->h,      // y size from image
        0,	                // border 0 (normal)
        GL_RGB,             // rgb color img order
        GL_UNSIGNED_BYTE,   // color component types
        image1->img        // image img itself
    );
    return idtextures;
};
GLuint TextureManager::LoadGLTexture(const char* filename)
{
    GLuint texture = 0;
    unsigned int width = 0, height = 0;
    unsigned char* img;
    FILE* file;

    //CODE SEGMENT 1
     // open texture img
    file = fopen(filename, "r");
    if (file == NULL) return 0;

    // allocate buffer
    img = (unsigned char*)malloc(width * height * 4);

    //read texture img
    fread(img, width * height * 4, 1, file);
    fclose(file);

   


    glGenTextures(1, &texture); // allocate a texture name
    glBindTexture(GL_TEXTURE_2D, texture); // select our current texture
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);  // when texture area is small, bilinear filter the closest mipmap
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // when texture area is large, bilinear filter the first mipmap
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);  // texture should tile
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, img); // build our texture mipmaps
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img);

    free(img);  // free buffer

    return texture;
}