#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "Quadrocopter.h"

Quadrocopter::Quadrocopter() : slices(30), body_radius(0.4)
{
	x_axis = 0;
	y_axis = 0;
	z_axis = 0;
	wheel_angle = 0;
	q = gluNewQuadric();
}


Quadrocopter::~Quadrocopter(void)
{
}

void Quadrocopter::draw_Quadrocopter()
{
	glPushMatrix();
	glTranslatef(x_axis, y_axis, z_axis);//ana matris, hareket icin

	//sýrasýyla parçalar eklenir

	glPushMatrix();//birinci capraz demir
	PervanelereBagliDemir(q, -15, 0, 5, 135);
	glPopMatrix();

	glPushMatrix();//ikinci capraz demir
	PervanelereBagliDemir(q, -15, 0, -15, 45);
	glPopMatrix();

	glPushMatrix();//sol arka cember
	Pervane(-15, 0, -15, wheel_angle);
	glPopMatrix();


	glPushMatrix();//sag arka cember
	Pervane(-15, 0, 5, wheel_angle);
	glPopMatrix();

	glPushMatrix();//sol ön cember
	Pervane(5, 0, -15, wheel_angle);
	glPopMatrix();

	glPushMatrix();//sag ön teker
	Pervane(5, 0, 5, wheel_angle);
	glPopMatrix();


	glPushMatrix();//orta silindir
	ortaSilindir(q, -5, 2, -5, 45);
	glPopMatrix();

	glPushMatrix();  //üst üçgen
	Ücgen(-5, 2, 0);
	glPopMatrix();

	glPopMatrix();
}


void Quadrocopter::Pervane(int x, int y, int z, double angle) // 
{
	glTranslatef(x, y, z);
	glColor3f(0, 0, 0);
	glRotatef(90, 45, 1, 0);
	glutSolidTorus(0.5, 5.0, 10, 50);

	glRotatef(90, 0, 1, 0);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 1; i < 9; i++){
		glPushMatrix();
		glRotatef(angle + i * 45, 1, 0, 0);
		gluCylinder(q, 0.2, 0.2, 4.5, slices, slices);
		glPopMatrix();
	}
	glColor3f(0, 0, 0);
}


void Quadrocopter::PervanelereBagliDemir(GLUquadric *q, int x, int y, int z, int rota) // küçük tekerlere baðlý olan demir
{
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(x, y, z);
	glRotatef(rota, 1, 45, 0);
	gluCylinder(q, body_radius, body_radius, 28, 28, 10);
}
void Quadrocopter::ortaSilindir(GLUquadric *q, int x, int y, int z, int rota) //  Ortada yer alan silindir.
{
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(x, y, z);
	glRotatef(90, 90, 0, 0);

	gluCylinder(q, body_radius * 7, body_radius * 7, 3, slices, 1);


}

void Quadrocopter::Ücgen(int x, int y, int z) // Üste yer alan ve yön belirten üçgen
{
	glTranslatef(x, y, z);
	glRotatef(90, 1, 0, 0);

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);


	glVertex3f(-3, -1, 0);

	glVertex3f(-3.0, -9.0, 0);

	glVertex3f(6, -5, 0);

	glEnd();
}
void Quadrocopter::yukarýHareketEt() // þeklin ileri gitmesin, saðlar
{
	y_axis += 0.5;
	wheel_angle += 10;
	glutPostRedisplay();
}
void Quadrocopter::assagýHareketEt() // þeklin ileri gitmesin, saðlar
{
	y_axis -= 0.5;
	wheel_angle -= 10;
	glutPostRedisplay();
}

void Quadrocopter::ileriHareketEt() // þeklin ileri gitmesin, saðlar
{
	x_axis += 0.5;
	wheel_angle += 10;
	glutPostRedisplay();
}

void Quadrocopter::geriHareketEt()//Þeklin geriye hareket etmesini saðlar
{
	x_axis -= 0.5;
	wheel_angle -= 10;
	glutPostRedisplay();
}

void Quadrocopter::reset()// Durumu en baþa alýr
{
	x_axis = 0;
	wheel_angle = 0;
	glutPostRedisplay();
}
