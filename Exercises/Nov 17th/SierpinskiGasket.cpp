#include <glut.h>
#include <iostream>


void myinit()
{
      glClearColor(1.0, 1.0, 1.0, 1.0); /* white background */
      glColor3f(1.0, 0.0, 0.0); /* draw in red */

      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0.0, 50.0, 0.0, 50.0);
      glMatrixMode(GL_MODELVIEW);
}


void display( void ){
    GLfloat vertices[3][2]={{0.0,0.0},{25.0,50.0},{50.0,0.0}}; /* A triangle */
    int j, k;
    srand(time(NULL));       /* standard random number generator */
    GLfloat p[2] ={7.5,5.0};  /* An arbitrary initial point inside traingle */

    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */
    glBegin(GL_POINTS);
     for( k=0; k<50000; k++) {
         	j = rand()%3; /* pick a vertex at random */
	 	p[0] = (p[0]+vertices[j][0])/2.0; 
		p[1] = (p[1]+vertices[j][1])/2.0;
	 	glVertex2fv(p); 
     }
	glEnd();
	glFlush(); /* clear buffers */
 }


int main(int argc, char** argv){

    glutInit(&argc, argv);

    // CONFIG WINDOW SIZE AND POSITION
    int screenW = glutGet(GLUT_SCREEN_WIDTH);
    int screenH = glutGet(GLUT_SCREEN_HEIGHT);

    int winW = 600;
    int winH = 400;

    int posX = (screenW - winW) / 2;
    int posY = (screenH - winH) / 2;

    //core
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(winW, winH);
    glutInitWindowPosition(posX, posY);
    glutCreateWindow("Sierpinski Gasket");

    myinit();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}