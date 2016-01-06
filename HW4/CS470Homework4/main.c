//
//  main.c
//  CS470Homework4
//
//  Created by Andrew Dopson on 11/7/13.
//  Copyright (c) 2013 Andrew Dopson. All rights reserved.
//

#include<GLUT/GLUT.h>.
int left = -20.0;
int right = 20.0;
int top = -20.0;
int bottom = 20.0;
int front = -20.0;
int back = 20.0;
int doorAngle = 0;

void myMenu();
void createMenu();
void createDoor();
void createHouse();
void createWindow();
void createTree();
void myKey(unsigned char key);


void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(left, right, top, bottom, front, back);
    
    GLfloat ambientColor[] = {0.5f, 0.5f, 0.5f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
    GLfloat pos[] = {-40.0, 100.0, 30.0};
    GLfloat am[] = {0.0, 0.3, 0.3, 0.4};
    
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, am);
    
    glRotatef(225, 0.0, 1.0, 0.0);
    glRotatef(15, 1.0, 0.0, 0.0);
    
    
    GLfloat groundmat[] = {0.0, 1.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, groundmat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, groundmat);

    //grass
    glBegin(GL_POLYGON);
    glVertex3f(-30.0, 0.0, 30.0);
     glVertex3f(-30.0, 0.0, -30.0);
    glVertex3f(30.0, 0.0, -30.0);
    glVertex3f(30.0, 0.0, 30.0);
    glEnd();
    
    createDoor();
    createHouse();
    createWindow();
    createTree();
    glFlush();
}

int main(int argc, char* argv[]){
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Homework 4 House");
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHT0);
    glutDisplayFunc(display);
    glutKeyboardFunc(myKey);
    glutMainLoop();
    return 0;
    
    
}
void myKey(unsigned char key){
    if(key == 'Q' | key == 'q'){
        exit(0);
    }
    if(key == 'M' | key == 'm'){
        createMenu();
    }
    
    glutPostRedisplay();
}

void createMenu(){
    glutCreateMenu(myMenu);
    glutAddMenuEntry("Ortho View 1", 1);
    glutAddMenuEntry("Ortho View 2", 2);
    glutAddMenuEntry("Ortho View 3", 3);
    glutAddMenuEntry("Non-Ortho View 1", 4);
    glutAddMenuEntry("Non-Ortho View 2", 5);
    glutAddMenuEntry("Open Door", 6);
    glutAddMenuEntry("Open Window", 7);
    glutAddMenuEntry("Exit", 8);
    glutAttachMenu(GLUT_LEFT_BUTTON);
    
}

void myMenu(int id){
    if (id == 1) {
        left = -20.0;
        right = 20.0;
        top = -20.0;
        bottom = 20.0;
        front = -20.0;
        back = 20.0;
    }
    if (id == 2) {
        left = -15.0;
        right = 15.0;
        top = -15.0;
        bottom = 15.0;
        front = -15.0;
        back = 15.0;
    }
    if (id == 3) {
        left = -20.0;
        right = 20.0;
        top = -20.0;
        bottom = 20.0;
        front = -20.0;
        back = 20.0;
    }
    if (id == 4) {
        left = 20.0;
        right = -20.0;
        top = 20.0;
        bottom = -20.0;
        front = 20.0;
        back = -20.0;
    }
    if (id == 5) {
        left = 15.0;
        right = -15.0;
        top = 15.0;
        bottom = -15.0;
        front = 15.0;
        back = -15.0;
    }
    if (id == 6) {
        if (doorAngle == 0) {
            doorAngle = 85;
        }else {
            doorAngle = 0;
        }
    }
    if (id == 7) {
        
    }
    if (id == 8) {
        exit(0);
    }
    
    glutPostRedisplay();
    
}

void createDoor(){
    glPushMatrix();
    glRotatef(doorAngle, 0.0, 1.0, 0.0);
    
    GLfloat doormat[] = {1.0, 1.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, doormat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, doormat);
    
    //left
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, 0.0, 0.0);
    glVertex3f(-2.0, 1.0, 0.0);
    glVertex3f(-2.0, 1.0, -0.05);
    glVertex3f(-2.0, 0.0, -0.05);
    glEnd();
    
    //right
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, -0.05);
    glVertex3f(0.0, 1.0, -0.05);
    glVertex3f(0.0, 1.0, 0.0);
    glEnd();
    
    
    //back
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, 0.0, -0.05);
    glVertex3f(-2.0, 1.0, -0.05);
    glVertex3f(0.0, 1.0, -0.05);
    glVertex3f(0.0, 1.0, -0.05);
    glEnd();
    
    //top
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(-2.0, 1.0, 0.0);
    glVertex3f(-2.0, 1.0, -0.05);
    glVertex3f(0.0, 1.0, -0.05);
    glEnd();
    
    //bottom
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(-2.0, 0.0, 0.0);
    glVertex3f(-2.0, 0.0, -0.05);
    glVertex3f(0.0, 0.0, -0.05);
    glEnd();
    
    //front
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(-2.0, 0.0, 0.0);
    glVertex3f(-2.0, 0.0, 0.0);
    glVertex3f(0.0, 2.0, 0.0);
    glVertex3f(-2.0, 2.0, 0.0);
        glEnd();
    glPopMatrix();
}

void createHouse(){
    GLfloat outsidemat[] = {0.59, 0.41, 0.31, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, outsidemat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, outsidemat);
    
    //left
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-5.0, 0.0, 0.0);
    glVertex3f(-5.0, 0.0, -10.0);
    glVertex3f(-5.0, 10.0, -10.0);
    glVertex3f(-5.0, 10.0, 0.0);
    glEnd();
    
    //right
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(5.0, 0.0, 0.0);
    glVertex3f(5.0, 10.0, 0.0);
    glVertex3f(5.0, 10.0, -10.0);
    glVertex3f(5.0, 0.0, -10.0);
    glEnd();
    
    //back
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(5.0, 0.0, -10.0);
    glVertex3f(5.0, 10.0, -10.0);
    glVertex3f(-5.0, 10.0, -10.0);
    glVertex3f(-5.0, 0.0, -10.0);
    glEnd();
    
    //front
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-5.0, 0.0, 0.0);
    glVertex3f(-2.0, 0.0, 0.0);
    glVertex3f(-2.0, 10.0, 0.0);
    glVertex3f(-5.0, 10.0, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(5.0, 0.0, 0.0);
    glVertex3f(5.0, 10.0, 0.0);
    glVertex3f(0.0, 10.0, 0.0);
    glEnd();
    
    GLfloat roofmat[] = {0.0, 0.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, roofmat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, roofmat);
    
    //front roof
    glBegin(GL_POLYGON);
    
    glVertex3f(5.0, 10.0, 0.0);
    glVertex3f(-5.0, 10.0, 0.0);
    glVertex3f(0.0, 14.0, 0.0);
    glEnd();
    
    //back roof
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 14.0, -10.0);
    glVertex3f(-5.0, 10.0, -10.0);
    glVertex3f(5.0, 10.0, -10.0);
    glEnd();
    
    //left roof
    glBegin(GL_POLYGON);
    glVertex3f(-5.0, 10.0, 0.0);
    glVertex3f(-5.0, 10.0, -10.0);
    glVertex3f(0.0, 14.0, -10.0);
    glVertex3f(0.0, 14.0, 0.0);
    glEnd();
    
    //right roof
    glBegin(GL_POLYGON);
    glVertex3f(5.0, 10.0, 0.0);
    glVertex3f(0.0, 14.0, 0.0);
    glVertex3f(0.0, 14.0, -10.0);
    glVertex3f(5.0, 10.0, -10.0);
    glEnd();
}
void createTree(){
    glPushMatrix();
    glRotatef(270.0, 1.0, 0.0, 0.0);
    glTranslatef(-20.0, 0.0, 0.0);
    GLfloat trunkmat[] = {0.52, 0.37, 0.26, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, trunkmat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, trunkmat);
    GLUquadricObj *obj = gluNewQuadric();
    gluCylinder(obj, 2.5, 1.5, 10.0, 100, 100);
    
    GLfloat treemat[] = {0.41, 0.56, 0.13, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, treemat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, treemat);
    
    glTranslatef(0.0, 0.0, 14.0);
    glutSolidSphere(5.0, 150, 150);
    
    glPopMatrix();
}