#include "Road.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

Road::Road(void)
{
}


Road::~Road(void)
{
}

void Road::draw_road()
{
	glColor3f(0.5, 0.5, 0.5);

	glPushMatrix();

	glBegin(GL_QUADS);
	glVertex3f(-400, -5, 20);
	glVertex3f(400, -5, 20);
	glVertex3f(400, -5, -20);
	glVertex3f(-400, -5, -20);
	glEnd();

	glPopMatrix();

	glColor3f(1, 1, 1);
	for (int i = -400; i <= 400; i += 20){
		glPushMatrix();
		glTranslatef(i, 0, 0);
		glBegin(GL_QUADS);
		glVertex3f(-5, -5, 2);
		glVertex3f(5, -5, 2);
		glVertex3f(5, -5, -2);
		glVertex3f(-5, -5, -2);
		glEnd();
		glPopMatrix();
	}

	glColor3f(0, 0, 0);

	glutSwapBuffers();
}
