
  #define STB_IMAGE_WRITE_IMPLEMENTATION
#include "Textures.h"

#include "../../Downloads/freeglut-MinGW-3.0.0-1.mp/freeglut/lib/stb_image_writer.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;
Textures::Textures()
{
    //ctor
}
void Textures::draw_base(int x , int y ){

baseBuffer=stbi_load("bmps//newbase.bmp", &image_Wi, &image_Hi, &bits_per_pexel, 3);

     GLuint Texture;
	glGenTextures(1, &Texture);
	glBindTexture(GL_TEXTURE_2D, Texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);


	//unsigned char *buffer;
	//buffer = stbi_load("bmps//baseWall.bmp", &image_W, &image_H, &bits_per, 3);
	// buffer = stbi_load("", &image_W, &image_H, &bits_per, 3);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_Wi, image_Hi, 0, GL_RGB, GL_UNSIGNED_BYTE,baseBuffer);




	// Draw the squere now
	// Draw the squere now
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(x, y, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(x, y + 128, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(x + 64, y + 128, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(x + 64, y, 0.0);
	glEnd();;


}




void Textures::draw_mario(int x , int y ){

baseBuffer=stbi_load("bmps//mario.bmp", &image_Wi, &image_Hi, &bits_per_pexel, 3);

     GLuint Texture;
	glGenTextures(1, &Texture);
	glBindTexture(GL_TEXTURE_2D, Texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);


	//unsigned char *buffer;
	//buffer = stbi_load("bmps//baseWall.bmp", &image_W, &image_H, &bits_per, 3);
	// buffer = stbi_load("", &image_W, &image_H, &bits_per, 3);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_Wi, image_Hi, 0, GL_RGB, GL_UNSIGNED_BYTE,baseBuffer);




	// Draw the squere now
	// Draw the squere now
	glBegin(GL_QUADS);
	glTexCoord2f(0.0,1.0);
        glVertex3f(x,y+128,0.0);
        glTexCoord2f(0.0,0.0);
        glVertex3f(x,y+128+64,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(x+64,y+128+64,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(x+64,y+128,0.0);
	glEnd();;


}




// COPY PIXEL DATA FROM BUTTER INTO A SMALLER OBJECT
void separte_sheet(unsigned char * sheet, unsigned char * item ,int szx, int szy){
// TO BE IMPLEMENTED


unsigned char *temp= (unsigned char* )malloc((szy*szx*4)+4);
for (int i =0;i<szy*szx*4; i++ ){



temp[i]=sheet[i];

if ((i+1)%4==0){


if (temp[i-1]==255&&temp[i-2]==255&&temp[i-3]==255){

    // cout<<"Bit0: "<<(int)temp[i-3]<<" Bit1: "<<(int)temp[i-2]<<" bit2:"<<(int)temp[i-1]<<" bit3: "<<(int)temp[i]<<"\t"<< i<<endl;

temp[i-1]=125;

temp[i-2]=125;
temp[i-3]=125;






sheet[i-1]=255; //BLUE

sheet[i-2]=120; //GREEN
sheet[i-3]=122; ////RED


}

}

   // cout<<(int)sheet[i]<<endl;
 }




FILE *fp;
 fp = fopen( "Sprites\\mari2.png" , "wb" );

  if (fp !=0)
    fwrite(temp , 1 , szx*szy*4 , fp );

cout<<"ok"<<endl;

      fclose(fp);
stbi_write_bmp("Sprites\\marioout2.bmp", szx, szy,4,temp  );


}



//sheet = item;









void Textures::draw_goku(int x , int y ){

baseBuffer=stbi_load("Sprites\\mario.png", &image_Wi, &image_Hi, &bits_per_pexel, 4);
cout<<"bits per peixel "<<bits_per_pexel<<endl;
unsigned char * item =(unsigned char*)malloc(image_Wi*image_Hi*4);


//  memcpy( item, baseBuffer , (image_Wi*image_Hi*3) );






separte_sheet(baseBuffer,item,image_Wi, image_Hi);

     GLuint Texture;
	glGenTextures(1, &Texture);
	glBindTexture(GL_TEXTURE_2D, Texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);


	//unsigned char *buffer;
	//buffer = stbi_load("bmps//baseWall.bmp", &image_W, &image_H, &bits_per, 3);
	// buffer = stbi_load("", &image_W, &image_H, &bits_per, 3);
	glTexImage2D(GL_TEXTURE_2D,0, GL_RGBA, image_Wi, image_Hi/5, 0, GL_RGBA, GL_UNSIGNED_BYTE,baseBuffer);




	// Draw the squere now
	// Draw the squere now
	glBegin(GL_QUADS);
	  glTexCoord2f(0.0,1.0);
        glVertex3f(x,y+128,0.0);
        glTexCoord2f(0.0,0.0);
        glVertex3f(x,y+192+428,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(x+828,y+192+428,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(x+828,y+128,0.0);
	glEnd();;













}
void Textures::draw_montain(int x , int y ){

baseBuffer=stbi_load("bmps//hill.bmp", &image_Wi, &image_Hi, &bits_per_pexel, 3);

     GLuint Texture;
	glGenTextures(1, &Texture);
	glBindTexture(GL_TEXTURE_2D, Texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);


	//unsigned char *buffer;
	//buffer = stbi_load("bmps//baseWall.bmp", &image_W, &image_H, &bits_per, 3);
	// buffer = stbi_load("", &image_W, &image_H, &bits_per, 3);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_Wi, image_Hi, 0, GL_RGB, GL_UNSIGNED_BYTE,baseBuffer);




	// Draw the squere now
	// Draw the squere now
	glBegin(GL_QUADS);
	glTexCoord2f(0.0,1.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f(x,y+128,-1.0);
        glTexCoord2f(0.0,0.0);
        glVertex3f(x,y+64+128,-1.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(x+192,y+64+128,-1.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(x+192,y+128,-1.0);
	glEnd();;


}


void Textures::draw_brick(int x , int y ){

baseBuffer=stbi_load("bmps//brick.bmp", &image_Wi, &image_Hi, &bits_per_pexel, 3);

     GLuint Texture;
	glGenTextures(1, &Texture);
	glBindTexture(GL_TEXTURE_2D, Texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);


	//unsigned char *buffer;
	//buffer = stbi_load("bmps//baseWall.bmp", &image_W, &image_H, &bits_per, 3);
	// buffer = stbi_load("", &image_W, &image_H, &bits_per, 3);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_Wi, image_Hi, 0, GL_RGB, GL_UNSIGNED_BYTE,baseBuffer);




	// Draw the squere now
	// Draw the squere now
	glBegin(GL_QUADS);
	  glTexCoord2f(0.0,1.0);
        glVertex3f(x,y+320,0.0);
        glTexCoord2f(0.0,0.0);
        glVertex3f(x,y+64+320,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(x+64,y+64+320,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(x+64,y+320,0.0);
	glEnd();;


}

void Textures::draw_pipe(int x , int y ){

baseBuffer=stbi_load("bmps//pipe.bmp", &image_Wi, &image_Hi, &bits_per_pexel, 3);

     GLuint Texture;
	glGenTextures(1, &Texture);
	glBindTexture(GL_TEXTURE_2D, Texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);


	//unsigned char *buffer;
	//buffer = stbi_load("bmps//baseWall.bmp", &image_W, &image_H, &bits_per, 3);
	// buffer = stbi_load("", &image_W, &image_H, &bits_per, 3);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_Wi, image_Hi, 0, GL_RGB, GL_UNSIGNED_BYTE,baseBuffer);




	// Draw the squere now
	// Draw the squere now
	glBegin(GL_QUADS);
	  glTexCoord2f(0.0,1.0);
        glVertex3f(x,y+128,0.0);
        glTexCoord2f(0.0,0.0);
        glVertex3f(x,y+192+128,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(x+128,y+192+128,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(x+128,y+128,0.0);
	glEnd();;


}









Textures::~Textures()
{
    //dtor
}
