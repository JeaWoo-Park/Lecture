#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <iostream>
#include <random>



GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);
void Mouse(int button, int state, int x, int y);
bool time = false;

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_int_distribution<> uid(0, 1);
float back_r = 0.0f, back_g = 0.0f, back_b = 1.0f;
float rect_r = 0.0f, rect_g = 0.0f, rect_b = 0.0f; 
void main(int argc, char** argv) {
	//윈도우 생성하기
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(300, 300);
	glutCreateWindow("Example 2");

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Unable to initialize GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
		std::cout << "GLEW Initialized\n";

	glutMouseFunc(Mouse);
	glutDisplayFunc(drawScene);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}

GLvoid drawScene()
{
	glClearColor(back_r,back_g, back_b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(rect_r, rect_g, rect_b);
	glRectf(50, -50, -50, 50);
	
	

	glutSwapBuffers();
}
GLvoid Reshape(int w, int h) {
	glViewport(0, 0, w, h);
	if (w <= h)
		glOrtho(-150.0f, 150.0f, -150.0f * h / w, 150.0f * h / w, 1.0f, -1.0f);
	else
		glOrtho(-150.0f * w / h, 150.0f * w / h, -150.0f, 150.0f, 1.0f, -1.0f);

}

void Mouse(int button, int state, int x, int y) {
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
		if (x >= 100 && x <= 200 && y >= 100 && y <= 200) {	//내부
			rect_r = uid(dre);
			rect_g = uid(dre);
			rect_b = uid(dre);
		}
		else {	//외부
			back_r = uid(dre);
			back_g = uid(dre);
			back_b = uid(dre);
		}
	}
}

