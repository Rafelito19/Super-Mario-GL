#include <iostream>
#include <windows.h>
#include <Stb_image.h>
#include <fstream>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <Textures.h>
#include "Mario.h"
#include <chrono>
using namespace std;
int image_W;
int image_H;
int bits_per;
Mario mario;
    unsigned char *base_buffer;












    // textures.cpp : Defines the entry point for the console application.
//



using namespace std;
using namespace std::chrono;






GLubyte BRYGmap[128][128][4]; // blye  red yellow green

void mkIMG(void){

	for (int h = 0; h < 128; h++)
	for (int w = 0; w < 128; w++){
		BRYGmap[h][w][0] = w * 4;
		BRYGmap[h][w][1] = h * 4;
		BRYGmap[h][w][2] = 128;
		BRYGmap[h][w][3] = 128;  // this means semi transparent for some reason

	}

}

GLubyte image[32][64][3];
int load_BMP_FILE(char *path){

	FILE *filep = fopen("bmps//baseWall.bmp","r");
	if (filep == 0)
		return -1;
	int offset;
	fseek(filep, 10, SEEK_SET);
	fread(&offset, 4, 1, filep);
	for (int h = 0; h < 64; h++)
	for (int w = 0; w < 32; w++){

		fseek(filep, offset++, SEEK_SET);
		fread(image[w][h], 1, 1, filep);
		fseek(filep, offset++, SEEK_SET);
		fread(image[w][h]+1, 1, 1, filep);
		fseek(filep, offset++, SEEK_SET);
		fread(image[w][h] + 2, 1, 1, filep);

	}
	fclose(filep);
	return 0;// for sucessfullmaping


}


GLuint LoadTexture(const char * filename)
{

	GLuint texture;

	int width, height;

	unsigned char * data;

	FILE * file;

	file = fopen(filename, "rb");

	if (file == NULL) {
		cout << "couldnt load file" << endl;
		return 0;

	}
	width = 64;
	height =32;
	data = (unsigned char *)malloc(width * height *3);
	//int size = fseek(file,);
	fread(data, width * height * 3, 1, file);
	fclose(file);

	for (int i = 0; i < width * height; ++i)
	{
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];

		data[index] = R;
		data[index + 2] = B;

	}


	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);


	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
	free(data);

	return texture;
}




/*void drawsquere(int x, int y){

	//TEXTURE STUFF

	GLuint Texture;
	glGenTextures(1, &Texture);
	glBindTexture(GL_TEXTURE_2D, Texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	mkIMG(); //loads an image to arrayGL_UNSIGNED_BYTE
	int bits_per;
	//unsigned char *buffer;
	//buffer = stbi_load("bmps//baseWall.bmp", &image_W, &image_H, &bits_per, 3);
	// buffer = stbi_load("", &image_W, &image_H, &bits_per, 3);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_W, image_H, 0, GL_RGB, GL_UNSIGNED_BYTE,base_buffer);




	// Draw the squere now
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(x, y + 128, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(x, y + 128 + 64, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(x + 64, y + 128 + 64, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(x + 64, y + 128, 0.0);
	glEnd();







}
*/
int j=100;
Textures tex;





 high_resolution_clock::time_point t1 = high_resolution_clock::now();

void draw4(){

	glClear(GL_COLOR_BUFFER_BIT);

glColor3f(0.0,0.7,0);







for (int i = 0 ; i <2000; i+=64){
tex.draw_base(i,0);

}

tex.draw_montain(0,0);
tex.draw_brick(300,00);
tex.draw_brick(500,0);
tex.draw_pipe(800,0);
//tex.draw_goku(50,100);
tex.draw_mario(mario.x,mario.y);
	glFlush();


  high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << duration<<endl;


}



void drawPoints();




using namespace std;



void MyKeyboardFunc(unsigned char Key, int x, int y)
{
switch(Key)
{

case 'd': mario.x+=10;  glutPostRedisplay(); break;
case 'a': mario.x-=10;  glutPostRedisplay(); break;
case 'w': mario.y+=10;  glutPostRedisplay(); break;


};


}















int main(int argc, char **argv)
{
	int control;


	cout << "1) to draw figure 1  " << "  2) to draw figure 2  " << "  3) to draw figure 3  " << "  4) to draw figure 4  " << endl;
	cout << "Please enter a your choice:  ";


	//Initialize GLUT
	glutInit(&argc, argv);
	//double buffering used to avoid flickering problem in animation
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// window size
	glutInitWindowSize(1344, 768);
	// create the window
	glutCreateWindow("Computer Graphics project 1 ");



	//glOrtho(0, 1360, 0, 760.00,1.0,1.0);
//gluOrtho2D(0.0,1360,0.0,760);
 glOrtho(0.0,1360.0,0.0,760.0,-10.0,10.0);
	glClearColor(0.48, 0.47, 1.0, 1.0);


	glutDisplayFunc(draw4);  // pass a pointer to the drawing function


	//let's mess with textures
	glEnable(GL_TEXTURE_2D);
    int de=3;
base_buffer=stbi_load("bmps//baseWall.bmp", &image_W, &image_H, &bits_per, de);
    cout <<image_H<<image_W<< endl;

glutKeyboardFunc(MyKeyboardFunc);


	/*	GLuint
			texture2;
			texture2 = LoadTexture("bmps//newbase.bmp");

			glBindTexture(GL_TEXTURE_2D, texture2);

			*/





	glutMainLoop();
	return 0;
}















    /*

int main()
{

FILE *f;
//stbi_load_from_file(f,&image_W,&image_H,&bits_per,3);

    int de=3;

 stbi_load("bmps//baseWall.bmp", &image_W, &image_H, &bits_per, de);
    cout <<image_H<<image_W<< endl;






    return 0;
}
*/
