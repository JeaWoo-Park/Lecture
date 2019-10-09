#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <iostream>
#include <random>



GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);
void Keyboard(unsigned char key, int x, int y);
void Timer(int value);
bool time = false;

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_int_distribution<> uid(0, 4);
float r = 0.0f, g = 0.0f, b = 1.0f;

void main(int argc, char** argv) {
	//������ �����ϱ�
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(250, 250);
	glutCreateWindow("Example 1");

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Unable to initialize GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
		std::cout << "GLEW Initialized\n";

	glutKeyboardFunc(Keyboard);
	glutDisplayFunc(drawScene);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}

GLvoid drawScene()
{
	glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}
GLvoid Reshape(int w, int h) {
	glViewport(0, 0, w, h);
}

void Keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'r':
	case 'R':		//����
	R:
		r = 1.0f;
		g = 0.0f;
		b = 0.0f;
		break;
	case 'g':
	case 'G':		//�ʷ�
	G:
		r = 0.0f;
		g = 1.0f;
		b = 0.0f;
		break;
	case 'b':
	case 'B':		//�Ķ�
	B:
		r = 0.0f;
		g = 0.0f;
		b = 1.0f;
		break;
	case 'a':
	case 'A':		//����
		switch (uid(dre))
		{
		case 0:
			goto R;
		case 1:
			goto G;
		case 2:
			goto B;
		case 3:
			goto W;
		case 4:
			goto K;
		}
		break;
	case 'w':
	case 'W':		//���
	W:
		r = 1.0f;
		g = 1.0f;
		b = 1.0f;
		break;
	case 'k':
	case 'K':		//������
	K:
		r = 0.0f;
		g = 0.0f;
		b = 0.0f;
		break;
	case 't':
	case 'T':		//Ÿ�̸�
		time = true;
		glutTimerFunc(100, Timer, 1);
		break;
	case 's':
	case 'S':		//Ÿ�̸� ����
		time = false;
		break;
	case 'q':
	case 'Q':		//����
		glutLeaveMainLoop();
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void Timer(int value) {

	switch (uid(dre))
	{
	case 0:
		r = 1.0f;
		g = 0.0f;
		b = 0.0f;
		break;
	case 1:
		r = 0.0f;
		g = 1.0f;
		b = 0.0f;
		break;
	case 2:
		r = 0.0f;
		g = 0.0f;
		b = 1.0f;
		break;
	case 3:
		r = 1.0f;
		g = 1.0f;
		b = 1.0f;
		break;
	case 4:
		r = 0.0f;
		g = 0.0f;
		b = 0.0f;
		break;
	}

	glutPostRedisplay();
	if (time) {
		glutTimerFunc(100, Timer, 1);
	}
}
