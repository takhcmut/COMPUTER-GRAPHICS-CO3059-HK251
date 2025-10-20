#include <windows.h>
#include <glut.h>

#define	WINDOW_LEFT		-10
#define	WINDOW_RIGHT		 10
#define	WINDOW_BOTTOM		-10
#define	WINDOW_TOP		 10

void myInit(){
	glClearColor(1.0,1.0,1.0,0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(WINDOW_LEFT, WINDOW_RIGHT, WINDOW_BOTTOM, WINDOW_TOP);
}
void drawGrid(){
	glColor3f(0.6f, 0.6f, 0.6f);
	glLineWidth(1.0);

	glBegin(GL_LINES);
		for(int i = WINDOW_LEFT; i<=WINDOW_RIGHT; i++){
			glVertex2i(i, WINDOW_BOTTOM);
			glVertex2i(i, WINDOW_TOP);
		}
		for(int i = WINDOW_BOTTOM; i<WINDOW_TOP; i++){
			//!Hinh1 ve truc ngang
			glVertex2i(WINDOW_LEFT, i);
        	glVertex2i(WINDOW_RIGHT, i);
		}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(5.0);

	glBegin(GL_LINES);
		glVertex2i(WINDOW_LEFT, 0);
		glVertex2i(WINDOW_RIGHT, 0);
		glVertex2i(0, WINDOW_BOTTOM);
		glVertex2i(0, WINDOW_TOP);
	glEnd();
}
void drawHouse(){
	glLineWidth(3.0);
	//! Hinh 1 ve ngoi nha
	glBegin(GL_LINE_LOOP);
		glVertex2i(0, 0);
		glVertex2i(4, 0);
		glVertex2i(4, 2);
		glVertex2i(2, 4);
		glVertex2i(0, 2);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex2f(1.5f, 3.5f);
		glVertex2f(1.5f, 4.0f);
		glVertex2f(0.5f, 4.0f);
		glVertex2f(0.5f, 2.5f);
	glEnd();
}
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();

	//!Hinh 1
	glColor3f(1.0f, 0.0f, 0.0f);
	drawHouse();

	//! Hinh 2
	glPushMatrix(); //saves the current state of transformation
	glTranslatef(4.0f, 3.0f, 0.0f); //translates the object
	glColor3f(0.0f, 0.0f, 1.0f);
	drawHouse();
	glPopMatrix(); //restores the last saved state of transformation

	//! Hinh 3
	glPushMatrix();
	glTranslatef(2.0f, -3.0f, 0.0f);
	glScalef(1.0f,1.5f,0.0f);
	glColor3f(1.0f, 0.0f, 1.0f);  // Purple
	drawHouse();
	glPopMatrix();

	//!Hinh 4
	glPushMatrix();
	glTranslatef(0.0f,2.0f,0.0f);
	glRotatef(90,0,0,1);
	glColor3f(0.0f,1,1);
	drawHouse();
	glPopMatrix();

	//!Hinh 5
	glPushMatrix();
	glTranslatef(0.0f,0.0f,0.0f);
	glScalef(1.5f,1.5f,0.0f);
	glRotatef(180,0,0,1);
	glColor3f(0,0,0);
	drawHouse();
	glPopMatrix();

	glFlush();
}

int main(int argc, char** argv[]) {
	glutInit(&argc, (char**)argv); //initialize the tool 
	
	glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB); //set the display mode
	glutInitWindowSize(650, 650); //set window size
	glutInitWindowPosition(0, 0); // set window position on screen
	glutCreateWindow("LAB-Transformation");//open the screen window

	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}