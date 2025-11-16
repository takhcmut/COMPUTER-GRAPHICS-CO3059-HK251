#include <glut.h>
#include <iostream>
#include <math.h>


#define PI 3.14159
#define ARCDIV 19
#define LINEDIVE 16

float R = 2.5;


struct Point2D {
    float x,y;
};



void drawCircle(float x0, float y0, float R, int vertexCount)
// x cua tam, y cua tam, ban kinh R, so dinh
{
    float x,y;
    float gap = 2* PI / vertexCount; //cho nay xai PI ko xai goc theo do
    float angle = 0;

    glBegin(GL_LINE_LOOP);

    for (int i= 0; i < vertexCount; i++){
        x = R * cos(angle) + x0;
        y = R * sin(angle) + y0;
        glVertex2f(x,y);
        angle += gap;
    }
    glEnd();
    glFlush();
}



void myinit()
{
      glClearColor(1.0f, 1.0f, 1.0f, 1.0f); /* white background */
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(-4.5, 4.5, -4.5, 4.5);
      glMatrixMode(GL_MODELVIEW);
}



void display(){
    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */
    //draw circle
    glColor3f(0,1,1);
    drawCircle (0, 0 , R, 100);

    //draw points on circle
    glColor3f(0,0,0);
    glBegin(GL_POINTS);
    for (int i=0;i < ARCDIV *5; i++){
        glVertex2f(R*cos(PI/2 + i*2*PI/ (ARCDIV*5)), R*sin(PI/2 + i*2*PI/ (ARCDIV*5)));
    }
    glEnd();

    
    glFlush();
}


int main(int argc, char** argv){

    glutInit(&argc, argv);

    // CONFIG WINDOW SIZE AND POSITION
    int screenW = glutGet(GLUT_SCREEN_WIDTH);
    int screenH = glutGet(GLUT_SCREEN_HEIGHT);

    int winW = 600;
    int winH = 600;

    int posX = (screenW - winW) / 2;
    int posY = (screenH - winH) / 2;

    //core
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(winW, winH);
    glutInitWindowPosition(posX, posY);
    glutCreateWindow("Amazing Art");

    myinit();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}