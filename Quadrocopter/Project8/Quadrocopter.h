#pragma once
#pragma once

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Quadrocopter
{
public:
	Quadrocopter();
	void draw_Quadrocopter();
	void ileriHareketEt();
	void geriHareketEt();
	void yukarýHareketEt();
	void assagýHareketEt();
	void reset();
	~Quadrocopter(void);

private:
	void Quadrocopter::Pervane(int x, int y, int z, double angle);
	void Quadrocopter::Ücgen(int x, int y, int z);
	void Quadrocopter::PervanelereBagliDemir(GLUquadric *q, int x, int y, int z, int rota);
	void Quadrocopter::ortaSilindir(GLUquadric *q, int x, int y, int z, int rota);
	const double body_radius;
	const int slices;
	double x_axis, y_axis, z_axis, wheel_angle;
	GLUquadric *q;
	//-----------------------------------------------

};

