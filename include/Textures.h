#ifndef TEXTURES_H
#define TEXTURES_H
#include <iostream>
#include <windows.h>
#include <Stb_image.h>
#include <fstream>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Textures
{

int image_Wi;
 int image_Hi;
 int bits_per_pexel;
 unsigned char *baseBuffer; //buffe that holds all texture data



    public:
        Textures();
   void draw_base(int x, int y);







 void draw_goku(int x , int y );
           void draw_brick(int x, int y);
           void draw_mario(int x, int y);
           void draw_montain(int x , int y );
            void draw_castle(int x, int y);
                   static void draw_bird(int x, int y);
                      static void draw_owl(int x, int y);
                           void draw_pipe(int x, int y);
       void draw_question(int x, int y);
        virtual ~Textures();


    protected:


};

#endif // TEXTURES_H
