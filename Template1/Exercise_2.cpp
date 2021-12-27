// Template1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include "include\GL\GL.H"
#include "include\GL\GLU.H"
#include "include\GL\glut.h"
#include "Exercise_2.h"


void init();
void timer(int);
void reshape(int, int);
void display();
void draw();


float angle = 0.0;
float toAdd = 1.0;

int main(int argc, char** argv) { //<- for normal API
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//single buffer and RGBA
	glutInitWindowSize(800, 800);//initial window size
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My window");//create widnow, hello title bar

	init();

	glutDisplayFunc(display);//
	glutTimerFunc(0, timer, 0);
	glutReshapeFunc(reshape);
	glutMainLoop();//enter main loop and process events
}


void init(void) {

	glClearColor(0.0, 0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
}


void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	//translate
	glTranslatef(0.0, 0.0, -10.0);
	//rotate
	glRotatef(angle, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);

	glBegin(GL_QUADS);
	
	draw();

	glEnd();

	glutSwapBuffers();
}


void reshape(int w, int h) {

	glViewport(0, 0, w, h);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();//=1
	gluPerspective(60.0, 1.0, 2.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
}


void timer(int) {
	//calling displaying on screen
	glutPostRedisplay();
	//60 FPS
	glutTimerFunc(1000 / 60, timer, 0);


	angle += toAdd;
	if (angle > 360.0) {
		angle -= 360.0;
	}
}


void draw(void) {
	//front
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	//back
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	//right
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(1.0, 1.0, -1.0);
	//left
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	//top
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);
	//bottom
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);
}