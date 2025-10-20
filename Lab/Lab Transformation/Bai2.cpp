#include <windows.h>
#include <math.h>
#include <glut.h>

const int screenWidth = 700;
const int screenHeight = 700;

void init(){// giữ nguyên
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.2, 1.2, -1.2, 1.2, 0.1, 100);
}
void setLight(){// giữ nguyên
	GLfloat	lightIntensity[]={0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat light_position[]={10, 10, 20.0f, 0.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
}
void setMaterial(){ // giữ nguyên
	GLfloat	mat_ambient[]={0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat	mat_diffuse[]={1.0f, 0.0f, 0.0f, 1.0f};
	GLfloat	mat_specular[]={1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat mat_shininess[] = {50.0f};

	glMaterialfv(GL_FRONT,GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE, mat_diffuse);
}
void setCamera(){// giữ nguyên
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(10, 6, 10, 0.0, 0.5, 0.0, 0.0, 1.0, 0.0);
}
void drawAxis(){// giữ nguyên
	float	xmax = 1.5, ymax = 1.5, zmax = 1.5;
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
		glVertex3f(-xmax, 0, 0);
		glVertex3f(xmax, 0, 0);
		glVertex3f(0, -ymax, 0);
		glVertex3f(0, ymax, 0);
		glVertex3f(0, 0, -zmax);
		glVertex3f(0, 0, zmax);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	void * font = GLUT_BITMAP_TIMES_ROMAN_24;

	glRasterPos3f(1.5, 0, 0);
	glutBitmapCharacter(font, 'X');

	glRasterPos3f(0, 1.5, 0);
	glutBitmapCharacter(font, 'Y');

	glRasterPos3f(0, 0, 1.5);
	glutBitmapCharacter(font, 'Z');
}

void BoxDraw(){
    
}
void display(){// SỬA
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	setCamera();
	drawAxis();
	setLight();

	setMaterial();
    // //!1
    // glPushMatrix();
    // glTranslatef(1,0,0);
    // glutSolidTeapot(0.25);
    // glPopMatrix();

    // //!2
    // //Box
    // glPushMatrix();
    // glScalef(0.5, 1.0, 0.9);     
    // glTranslatef(0.5,0.5,0.5);
    // glutWireCube(1.0);           
    // glPopMatrix();

    // //Teapot
    // glPushMatrix();
    // glTranslatef(0.5,1,0.9);
    // glutSolidTeapot(0.25);
    // glPopMatrix();

    // //!3
    // glPushMatrix();
    // glTranslatef(0,0,1);
    // glutSolidTeapot(0.25);
    // glPopMatrix();

    // //!4
    // glPushMatrix();
    // glRotatef(60,0,1,0);
    // glTranslatef(0,1,0);
    // glutSolidTeapot(0.125);
    // glPopMatrix();

    // //!5
    // glPushMatrix();
    // glTranslatef(0,0,1);
    // glRotatef(270,0,1,0);
    // glutSolidTeapot(0.25);
    // glPopMatrix();

    // glPushMatrix();
    // glTranslatef(0,0,-1);
    // glRotatef(90,0,1,0);
    // glutSolidTeapot(0.25);
    // glPopMatrix();

    // glPushMatrix();
    // glTranslatef(1,0,0);
    // glutSolidTeapot(0.25);
    // glPopMatrix();

    // glPushMatrix();
    // glTranslatef(-1,0,0);
    // glRotatef(180,0,1,0);
    // glutSolidTeapot(0.25);
    // glPopMatrix();

    // //!6
    // glPushMatrix();
    // float scale = 1.0f;
    // float y = 0.0f;

    // for (int i = 0; i < 5; i++) {
    //     glPushMatrix();
    //         glTranslatef(0.0f, y, 0.0f);    
    //         glScalef(scale, scale, scale);   
    //         glutSolidTeapot(0.25);
    //     glPopMatrix();

    //     y += 0.3f;        
    //     scale *= 0.8f;  
    // }
    // glPopMatrix();

    //!7
    // glPushMatrix();
    // for (int axis = 0; axis <2; axis ++)
    // {
    //     int j=5;
    //     for (int i=0;i<5;i++)
    //     {   
    //         for (int k=0;k<j;k++){
    //             glutSolidCube(0.15f);
    //             glTranslatef(0.225f,0,0);
    //     }
    //         if (axis ==0) glTranslatef(-0.225f*j,0,0.225f);
    //         else glTranslatef(-0.225f*j,0.225f,0);
    //         j--;
    //     }
    //     glTranslatef(-0.225f*j,0,-5*0.225f);
    // }
    // glPopMatrix();

    //!8
    for (int axis = 0 ; axis <3; axis ++){
        glPushMatrix();
        float scale = 1.0f;
        float d = 0.0f;
        float rotateAngle = 0;
        int i=0;

        for (i; i < 5; i++) {

            glPushMatrix();
                if (axis ==0) {
                    glTranslatef(0.0f, d, 0.0f);
                    glRotatef(rotateAngle,0,1,0);
                }

                else if (axis ==1)  {
                    glTranslatef(d, 0.0f, 0.0f);
                    glRotatef(rotateAngle,1,0,0);

                }
                else {
                    glTranslatef(0.0f, 0.0f, d);
                    glRotatef(rotateAngle,0,0,1);
                }           
                glScalef(scale, scale, scale);
                glutSolidCube(0.2);
            glPopMatrix();

            d += 0.5*(scale*0.2+scale*0.2*0.8);     
            scale *= 0.8f;  
            rotateAngle +=45;
        }
        float goBackDistance;
        for (int j=0;j<i;j++){
            if (j==0 || j==i-1) goBackDistance += pow (0.8,j);
            else goBackDistance += pow(0.8,j) *2;
        }
        if (axis ==0) glTranslatef(0.0f, -0.5*goBackDistance, 0.0f);
        else if (axis ==1)  glTranslatef(-0.5*goBackDistance, 0.0f, 0.0f);
        else glTranslatef(0.0f, 0.0f, -0.5*goBackDistance);

        glPopMatrix();
    }

	glFlush();
}

int main(int argc, char** argv[]){
	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB |GLUT_DEPTH);
	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(0, 0); // set window position on screen
	glutCreateWindow("Lab-Transformation"); // open the screen window

	glutDisplayFunc(display);

	init();
	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
	return 0;
}
