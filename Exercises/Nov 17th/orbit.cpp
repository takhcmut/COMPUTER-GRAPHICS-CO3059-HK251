#include <glut.h>
#include <iostream>
#include <math.h>


#define PI 3.14159
float venusR = 2.5;
float earthR = venusR * 149.6/108.2;



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

void drawLine (float x0, float y0, int vertexCount)
// (x cua tam, y cua tam, so ngay quay)
{
    float earthGap = 2 * PI / 365.25636;
    float venusGap = 2* PI / 224.7008;
    float x1,y1,x2,y2;
    float earthAngle = PI /2;
    float venushAngle = PI /2;

    glBegin(GL_LINES); // ko dc xai gl_line
        for (int i=0; i< vertexCount; i++)
        {
            x1 = earthR * cos(earthAngle) + x0;
            y1 = earthR * sin(earthAngle) + y0;
            x2 = venusR * cos(venushAngle) + x0;
            y2 = venusR * sin(venushAngle) + y0;
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            earthAngle -= earthGap;
            venushAngle -= venusGap;
        }

    glEnd();
    glFlush();
}


void myinit()
{
      glClearColor(1.0f, 1.0f, 1.0f, 1.0f); /* white background */
      glColor3f(0.0, 0.0, 0.0); /* draw in yellow */
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(-4.5, 4.5, -4.5, 4.5);
      glMatrixMode(GL_MODELVIEW);
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */
    drawCircle(0,0,venusR,60);
    drawCircle(0,0,earthR,60);
    drawLine(0,0,365*3);
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
    glutCreateWindow("ORBIT");

    myinit();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}