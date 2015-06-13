#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "Quadrocopter.h"
#include "Road.h"
#include <ctype.h>

#define CAM_SHIFT 0.5

float x_axis = 0, y_axis = 0, z_axis = 0, cam_x_axis = 0, cam_y_axis = 0, cam_z_axis = 0;
int control1 = 1, control2 = 1;
Quadrocopter *b = new Quadrocopter();
Road *r = new Road();

void init(void)
{
	glClearColor(0.0, 1, 1, 0.3);
	glShadeModel(GL_FLAT);
	glCullFace(GL_FRONT);
}

void display(void)
{
	GLUquadric *quad = gluNewQuadric();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	gluLookAt(x_axis, y_axis, z_axis, cam_x_axis, cam_y_axis, cam_z_axis, 0.0, 1.0, 1.0);
	glScalef(1, 1, 1);

	glColor3f(0, 0, 0);

	if (control1 == 0){
		r->draw_road();
		b->draw_Quadrocopter();
	}

	else if (control2 == 0){
		for (float i = 1; i < 9; i++){
			Quadrocopter *quadrocopter = new Quadrocopter();
			glPushMatrix();
			glScalef((float)(0.3 + i / 10), (float)(0.3 + i / 10), (float)(0.3 + i / 10));
			glRotatef(45 * i, 0, 1, 0);
			glTranslatef(25, 0, 0);
			quadrocopter->draw_Quadrocopter();
			glPopMatrix();
		}
	}
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 200.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	key = tolower(key);
	switch (key)
	{
	case 'a'://bir adet Quadrocopter cizdirme
		b->reset();
		control1 = 0;
		control2 = 1;
		z_axis = 40;
		x_axis = 0;
		y_axis = 0;
		cam_x_axis = 0;
		glutPostRedisplay();
		break;
	case 's'://birden fazla Quadrocopter cizdirme
		control1 = 1;
		control2 = 0;
		z_axis = 65;
		y_axis = 20;
		x_axis = 0;
		cam_x_axis = 0;
		glutPostRedisplay();
		break;

	case 'r'://reset
		control1 = 1;
		control2 = 1;
		cam_x_axis = 0;
		b->reset();
		glutPostRedisplay();
		break;

	case 'j':
		x_axis -= CAM_SHIFT;
		glutPostRedisplay();
		break;

	case 'k':
		x_axis += CAM_SHIFT;
		glutPostRedisplay();
		break;

	case 'n':
		y_axis -= CAM_SHIFT;
		glutPostRedisplay();
		break;

	case 'm':
		y_axis += CAM_SHIFT;
		glutPostRedisplay();
		break;

	case 'y':
		z_axis -= CAM_SHIFT;
		glutPostRedisplay();
		break;

	case 'u':
		z_axis += CAM_SHIFT;
		glutPostRedisplay();
		break;

	case 't':
		x_axis = 0;
		y_axis = 0;
		z_axis = 0;
		glutPostRedisplay();
		break;


	}
}

void arrow_keys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		b->geriHareketEt();
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		b->ileriHareketEt();
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:
		b->yukarýHareketEt();
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		b->assagýHareketEt();
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(arrow_keys);
	glutMainLoop();
	return 0;
}