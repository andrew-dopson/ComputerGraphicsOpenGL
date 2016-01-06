#include <GLUT/GLUT.h>
//starts out cube on a point
double x = 45;
double y = 45;
double z = 0;
void myMenu();
void createMenu();
int left = -2.0;
int right = 2.0;
int top = -2.0;
int bottom = 2.0;
int front = -2.0;
int back = 2.0;
int mode = 1;
int eyeX = 1.0;
int eyeY = 1.0;
int eyeZ = 1.0;
int centerX = 0.0;
int centerY = 0.0;
int centerZ = 0.0;
int upX = 0.0;
int upY = 1.0;
int upZ = 0.0;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    if(mode == 1){
        glLoadIdentity();
        glOrtho(left, right, top, bottom, front, back);
    }
    if(mode == 2){
        glLoadIdentity();
        glFrustum(left, right, top, bottom, front, back);
    }
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    
    glRotatef(x, 1.0, 0.0, 0.0);
    glRotatef(y, 0.0, 1.0, 0.0);
    glRotatef(z, 0.0, 0.0, 1.0);
    
    //right side - red
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glEnd();
    
    //front side - green
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glEnd();
    
    //left side - blue
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glEnd();
    
    /*top side - purple
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glEnd();*/
    
    //bottom side - yellow
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glEnd();
    
    //back side - cyan
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glEnd();
    
    //for pyramid shape on top of cube
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.0, 0.75, 0.0);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3f(0.5, 0.0, 0.0);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.0, 0.75, 0.0);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(0.0, 0.75, 0.0);
    glVertex3f(0.5, 0.5, -0.5);

    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3f(0.5, 0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.0, 0.75, 0.0);
    glEnd();
    
    
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.0, 1.25, 0.0);
    glutWireSphere(0.5, 20, 20);
    
    
    
    
    glFlush();
}

//from lecture slide
void myKey(unsigned char key, int a, int b){
    if(key == 'X' | key == 'x'){
        x = x + 2;
    }
    if(key == 'Y' | key == 'y'){
        y = y + 2;
    }
    if(key == 'Z' | key == 'z'){
        z = z + 2;
    }
    if(key == 'Q' | key == 'q'){
        exit(0);
    }
    if(key == 'M' | key == 'm'){
        createMenu();
    }
    
    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Homework 3b");
    
    
    glutDisplayFunc(display);
    glutKeyboardFunc(myKey);
    glutMainLoop();
        return 0;
}

void createMenu(){
    glutCreateMenu(myMenu);
    glutAddMenuEntry("Ortho View 1", 1);
    glutAddMenuEntry("Ortho View 2", 2);
    glutAddMenuEntry("Ortho View 3", 3);
    glutAddMenuEntry("Non-Ortho View 1", 4);
    glutAddMenuEntry("Non-Ortho View 2", 5);
    glutAddMenuEntry("Exit", 6);
    glutAttachMenu(GLUT_LEFT_BUTTON);
}

void myMenu(int id){
    if (id == 1) {
        mode = 1;
        left = -1.0;
        right = 1.0;
        top = -1.0;
        bottom = 1.0;
        front = -1.0;
        back = 1.0;
    }
    if (id == 2) {
        mode = 1;
        left = -2.0;
        right = 2.0;
        top = -2.0;
        bottom = 2.0;
        front = -2.0;
        back = 2.0;
    }
    if (id == 3) {
        mode = 1;
        left = -3.0;
        right = 3.0;
        top = -3.0;
        bottom = 3.0;
        front = -3.0;
        back = 3.0;
    }
    if (id == 4) {
        mode = 2;
        left = -3.0;
        right = 3.0;
        top = -3.0;
        bottom = 3.0;
        front = -3.0;
        back = 3.0;

    }
    if (id == 5) {
        mode = 2;
        left = -4.0;
        right = 4.0;
        top = -4.0;
        bottom = 4.0;
        front = -4.0;
        back = 4.0;

    }
    if (id == 6) {
        exit(0);
    }
    
    glutPostRedisplay();
}