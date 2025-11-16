#include <glut.h>
#include <iostream>
#include <math.h>


#define PI 3.14159
float R = 2;


struct Point2D {
    float x,y;
};

Point2D points[10];


Point2D TimGiaoDiem(Point2D A, Point2D B, Point2D C, Point2D D) //Dung de tim 5 diem o trong 
{ 
    float A1,B1,A2,B2;

    A1 = (B.y - A.y) / (B.x - A.x); //vector chi phuong
    B1 = A.y - A1*A.x; // phuong trinh duong thang theo dang vector

    A2 = (D.y - C.y) / (D.x - C.x);
    B2 = C.y - A2*C.x;

    Point2D giaoDiem;
    giaoDiem.x = (B2-B1)/ (A1-A2);
    giaoDiem.y = A1*giaoDiem.x +B1;

    return giaoDiem;
  
}

void myinit()
{
      glClearColor(1.0f, 0.0f, 0.0f, 1.0f); /* red background */
      glColor3f(1.0, 1.0, 0.0); /* draw in yellow */

      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(-4.5, 4.5, -3.0, 3.0);
      glMatrixMode(GL_MODELVIEW);
}


void display(){
    // tinh 5 diem tren duong tron
    for (int i=0; i<5; i++){
        points[i].x = R * cos(PI/2 + i*2 * PI/5);
        points[i].y = R * sin (PI/2 + i*2 * PI/5);
    }   
     
    //tinh 5 diem o trong vong tron
    points[5] = TimGiaoDiem(points[0],points[2],points[1],points[4]);
    points[6] = TimGiaoDiem(points[0],points[2],points[1],points[3]);
    points[7] = TimGiaoDiem(points[1],points[3],points[2],points[4]);
    points[8] = TimGiaoDiem(points[0],points[3],points[2],points[4]);
    points[9] = TimGiaoDiem(points[0],points[3],points[1],points[4]);
    
    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */
    // glBegin(GL_LINE_LOOP);  //POLYGON
    //     glVertex2f(points[0].x, points[0].y);
    //     glVertex2f(points[5].x, points[5].y);
    //     glVertex2f(points[1].x, points[1].y);
    //     glVertex2f(points[6].x, points[6].y);
    //     glVertex2f(points[2].x, points[2].y);
    //     glVertex2f(points[7].x, points[7].y);
    //     glVertex2f(points[3].x, points[3].y);
    //     glVertex2f(points[8].x, points[8].y);
    //     glVertex2f(points[4].x, points[4].y);
    //     glVertex2f(points[9].x, points[9].y);
    // glEnd();

    //! DUNG POLYGON CHI DUNG CHO DA GIAC LOI, O DAY LA DA GIAC LOM NEN BI SAI
    // glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    // glBegin(GL_POLYGON);  //POLYGON
    //     glVertex2f(points[0].x, points[0].y);
    //     glVertex2f(points[5].x, points[5].y);
    //     glVertex2f(points[1].x, points[1].y);
    //     glVertex2f(points[6].x, points[6].y);
    //     glVertex2f(points[2].x, points[2].y);
    //     glVertex2f(points[7].x, points[7].y);
    //     glVertex2f(points[3].x, points[3].y);
    //     glVertex2f(points[8].x, points[8].y);
    //     glVertex2f(points[4].x, points[4].y);
    //     glVertex2f(points[9].x, points[9].y);
    // glEnd();

    // !CHIA HINH SAO THANH NHIEU DA GIAC LOM (CACH 1)
    // glBegin(GL_TRIANGLE_FAN);  //POLYGON
    //     glVertex2f(0,0);
    //     glVertex2f(points[0].x, points[0].y);
    //     glVertex2f(points[5].x, points[5].y);
    //     glVertex2f(points[1].x, points[1].y);
    //     glVertex2f(points[6].x, points[6].y);
    //     glVertex2f(points[2].x, points[2].y);
    //     glVertex2f(points[7].x, points[7].y);
    //     glVertex2f(points[3].x, points[3].y);
    //     glVertex2f(points[8].x, points[8].y);
    //     glVertex2f(points[4].x, points[4].y);
    //     glVertex2f(points[9].x, points[9].y);
    //     glVertex2f(points[0].x, points[0].y); // cho nay de p0 1 lan nua de tao thanh hinh tam giac, ko thi se bi sai o khuc cuoi

    // glEnd();

   // ! CHIA HINH SAO THANH NHIEU DA GIAC LOM (CACH 2)
    glBegin(GL_TRIANGLES);  //POLYGON
        glVertex2f(points[0].x, points[0].y);
        glVertex2f(points[5].x, points[5].y);
        glVertex2f(points[9].x, points[9].y);

        glVertex2f(points[1].x, points[1].y);
        glVertex2f(points[5].x, points[5].y);
        glVertex2f(points[6].x, points[6].y);

        glVertex2f(points[6].x, points[6].y);
        glVertex2f(points[2].x, points[2].y);
        glVertex2f(points[7].x, points[7].y);

        glVertex2f(points[7].x, points[7].y);
        glVertex2f(points[3].x, points[3].y);
        glVertex2f(points[8].x, points[8].y);
        
        glVertex2f(points[4].x, points[4].y);
        glVertex2f(points[8].x, points[8].y);
        glVertex2f(points[9].x, points[9].y);

    glEnd();

    glBegin(GL_POLYGON);  //POLYGON
        glVertex2f(points[5].x, points[5].y);
        glVertex2f(points[6].x, points[6].y);
        glVertex2f(points[7].x, points[7].y);
        glVertex2f(points[8].x, points[8].y);
        glVertex2f(points[9].x, points[9].y);
    glEnd();


    glFlush();
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
    glutCreateWindow("VN FLAG");

    myinit();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}