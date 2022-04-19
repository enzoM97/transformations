#include "GL/freeglut.h"
#include <iostream>


constexpr int FLOAT_MIN = 0;
constexpr int FLOAT_MAX = 1;

// initialize OpenGL
void init(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void translation(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	// translated triangle
	glPushMatrix();
	glTranslatef(0.2f, 0.2f, 0.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.3f, 0.1f, 0.0f);
	glVertex3f(0.2f, 0.2f, 0.0f);
	glEnd();
	glPopMatrix();

	// original triangle
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.3f, 0.1f, 0.0f);
	glVertex3f(0.2f, 0.2f, 0.0f);
	glEnd();

	glFlush();
}

void escalation(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glScalef(2.0f, 2.0f, 2.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.1f, 0.0f, 0.0f);
	glVertex3f(0.1f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.1f, 0.0f);
	glEnd();

	glFlush();
}

void rotation(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glRotatef(45.0, 0.0, 0.0, 0.1);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.1f, 0.0f, 0.0f);
	glVertex3f(0.1f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.1f, 0.0f);
	glEnd();

	glFlush();
}

void transformTriangle(void)
{
	// original triangle
	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 1.0f, 0.2f);
	glVertex3f(-0.6f, -0.6f, 0.0f);
	glVertex3f(-0.3f, -0.6f, 0.0f);
	glVertex3f(-0.45f, -0.3f, 0.0f);
	glEnd();

	// transformed triangle
	glPushMatrix();
	// translate to origin
	glTranslatef(0.9f, 0.9f, 0.0f);
	glScalef(1.5f, 1.5f, 1.5f);
	glRotatef(45.0, 0.05, 0.05, 0.0);
	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 1.0f, 0.2f);
	glVertex3f(-0.6f, -0.6f, 0.0f);
	glVertex3f(-0.3f, -0.6f, 0.0f);
	glVertex3f(-0.45f, -0.3f, 0.0f);
	glEnd();
	glPopMatrix();

}

void drawCartesianPlane(void)
{
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(1.0);

	float x = -1.0, y = 1.0, z = 0.0;

	glBegin(GL_POINTS);
	for (float i = -1.0; i < 1.0; i += 0.01) {
		glBegin(GL_POINTS);
		glColor3f(x, y, z);
		glVertex2d(x, 0);
		glVertex2d(0, y);
		x += 0.02f;
		y -= 0.02f;
		z += 0.02f;
	}
	glEnd();
	
	transformTriangle();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(512, 512);
	glutInitWindowPosition(400, 150);
	glutCreateWindow("transformations");

	init();
	glutDisplayFunc(drawCartesianPlane);
	glutMainLoop();

	return 0;
}