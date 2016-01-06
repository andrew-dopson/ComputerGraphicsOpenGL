//
//  main.c
//  finalProjectCS470
//
//  Created by Andrew Dopson on 11/27/13.
//  Copyright (c) 2013 Andrew Dopson. All rights reserved.
//

#include <GLUT/GLUT.h>
#include <stdio.h>


void mydisplay();
void createGround();
void createHuman();
void createHouse();
void createTree();
void createFence();
void createSidewalk();
void createDoor();
void createBackground();
void createMailbox();
void mailboxCap();
void createMenu();
void createLeftLeg();
void createRightLeg();
void myMenu();

unsigned char header[54];
unsigned int dataPos;
unsigned int width, height;
unsigned int imageSize;
unsigned char *data;


int door = 1;
int controlPerson = 0;
int orbitMode = 0;
int zoomMode = 0;
int mailbox = 0;
int personFace = 0;

int lookFromPosX = 120.0;
int lookFromPosY = 50.0;
int lookFromPosZ = 150.0;

int lookAtPosX = 0.0;
int lookAtPosY = 0.0;
int lookAtPosZ = 0.0;

int humanPosX = 40.0;
int humanPosZ = 80.0;

int leftLeg = 0;
int rightLeg = 1;
int leftLegAngle = 0;
int rightLegAngle = 0;

void myKey(unsigned char key, int a, int b){
    if (key == 'a' || key == 'A'){
        if (orbitMode == 1){
            if(lookFromPosX >= 0 && lookFromPosZ >= 0){
                lookFromPosX = lookFromPosX - 3;
                lookFromPosZ = lookFromPosZ + 3;
            }
            if(lookFromPosX <= 0 && lookFromPosZ >= 0){
                lookFromPosX = lookFromPosX - 3;
                lookFromPosZ = lookFromPosZ - 3;
            }
            if(lookFromPosX <= 0 && lookFromPosZ <= 0){
                lookFromPosX = lookFromPosX + 3;
                lookFromPosZ = lookFromPosZ - 3;
            }
            if(lookFromPosX >= 0 && lookFromPosZ <= 0){
                lookFromPosX = lookFromPosX + 3;
                lookFromPosZ = lookFromPosZ + 3;
            }
        }
        if (controlPerson == 1){
            if (personFace == 0) {
                personFace = 3;
            }else{
                personFace--;
            }
        }
    }
    if (key == 'd' || key == 'D'){
        if(orbitMode == 1){
            if(lookFromPosX >= 0 && lookFromPosZ >= 0){
                lookFromPosX = lookFromPosX + 3;
                lookFromPosZ = lookFromPosZ - 3;
            }
            if(lookFromPosX <= 0 && lookFromPosZ >= 0){
                lookFromPosX = lookFromPosX + 3;
                lookFromPosZ = lookFromPosZ + 3;
            }
            if(lookFromPosX <= 0 && lookFromPosZ <= 0){
                lookFromPosX = lookFromPosX - 3;
                lookFromPosZ = lookFromPosZ + 3;
            }
            if(lookFromPosX >= 0 && lookFromPosZ <= 0){
                lookFromPosX = lookFromPosX - 3;
                lookFromPosZ = lookFromPosZ - 3;
            }
        }
        if (controlPerson == 1){
            if (personFace == 3) {
                personFace = 0;
            }else{
                personFace++;
            }
        }

    }
    if(key == 'w' || key == 'W'){
        if(orbitMode == 1){
            lookFromPosY = lookFromPosY + 3;
        }
        if (zoomMode == 1){
            if (lookFromPosX > lookAtPosX) {
                lookFromPosX  = lookFromPosX - 3;
            }else{
                lookFromPosX = lookFromPosX + 3;
            }
            
            if (lookFromPosY > lookAtPosY) {
                lookFromPosY = lookFromPosY - 3;
            }else{
                lookFromPosY = lookFromPosY + 3;
            }
            
            if (lookFromPosZ > lookAtPosZ) {
                lookFromPosZ = lookFromPosZ - 3;
            }else{
                lookFromPosZ = lookFromPosZ + 3;
            }
        }
        if (controlPerson == 1) {
            //out of screen
            if (personFace == 0){
                humanPosZ++;
            }
            //left
            if (personFace == 1){
                humanPosX--;
            }
            //into screen
            if (personFace == 2) {
                humanPosZ--;
            }
            //right
            if (personFace == 3) {
                humanPosX++;
            }
            
            //leg movement
            if(rightLeg == 1){
                if(rightLegAngle < 15){
                    rightLegAngle = rightLegAngle + 3;
                }
                else{
                    rightLeg = 0;
                    rightLegAngle = rightLegAngle - 3;
                }
            }
            if(rightLeg == 0){
                if(rightLegAngle > -15){
                    rightLegAngle = rightLegAngle - 3;                }
                else{
                    rightLeg = 1;
                    rightLegAngle = rightLegAngle + 3;
                }
            }
            if(leftLeg == 1){
                if(leftLegAngle < 15){
                    leftLegAngle = leftLegAngle + 3;
                }
                else{
                    leftLeg = 0;
                    leftLegAngle = leftLegAngle - 3;
                }
            }
            if(leftLeg == 0){
                if(leftLegAngle > -15){
                    leftLegAngle = leftLegAngle - 3;
                }
                else{
                    leftLeg = 1;
                    leftLegAngle = leftLegAngle + 3;
                }
            }

        }
    }
    if(key == 's' || key == 'S'){
        if(orbitMode == 1){
            lookFromPosY = lookFromPosY - 3;
        }
        if (zoomMode == 1){
            if (lookFromPosX < lookAtPosX) {
                lookFromPosX  = lookFromPosX - 3;
            }else{
                lookFromPosX = lookFromPosX + 3;
            }
            
            if (lookFromPosY < lookAtPosY) {
                lookFromPosY = lookFromPosY - 3;
            }else{
                lookFromPosY = lookFromPosY + 3;
            }
            
            if (lookFromPosZ < lookAtPosZ) {
                lookFromPosZ = lookFromPosZ - 3;
            }else{
                lookFromPosZ = lookFromPosZ + 3;
            }
        }
        if (controlPerson == 1) {
            //out of screen
            if (personFace == 0){
                humanPosZ--;
            }
            //left
            if (personFace == 1){
                humanPosX++;
            }
            //into screen
            if (personFace == 2) {
                humanPosZ++;
            }
            //right
            if (personFace == 3) {
                humanPosX--;
            }
            
            //leg movement
            if(rightLeg == 0){
                if(rightLegAngle < 15){
                    rightLegAngle = rightLegAngle + 3;
                }
                else{
                    rightLeg = 1;
                    rightLegAngle = rightLegAngle - 3;
                }
            }
            if(rightLeg == 1){
                if(rightLegAngle > -15){
                    rightLegAngle = rightLegAngle - 3;                }
                else{
                    rightLeg = 0;
                    rightLegAngle = rightLegAngle + 3;
                }
            }
            if(leftLeg == 0){
                if(leftLegAngle < 15){
                    leftLegAngle = leftLegAngle + 3;
                }
                else{
                    leftLeg = 1;
                    leftLegAngle = leftLegAngle - 3;
                }
            }
            if(leftLeg == 1){
                if(leftLegAngle > -15){
                    leftLegAngle = leftLegAngle - 3;
                }
                else{
                    leftLeg = 0;
                    leftLegAngle = leftLegAngle + 3;
                }
            }

            
        }

    }
    if(key == 'm' || key == 'M'){
        createMenu();
    }
    if(key == 'o' || key == 'O'){
        orbitMode = 1;
        zoomMode = 0;
        controlPerson = 0;
        lookAtPosX = 0.0;
        lookAtPosZ = 0.0;
        lookAtPosY = 0.0;
    }
    if(key == 'z' || key == 'Z'){
        orbitMode = 0;
        zoomMode = 1;
        controlPerson = 0;
        lookAtPosX = 0.0;
        lookAtPosZ = 0.0;
        lookAtPosY = 0.0;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Final Project");
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    
    glutDisplayFunc(mydisplay);
    glutKeyboardFunc(myKey);
    glutMainLoop();
    return 0;
}

void createMenu(){
    glutCreateMenu(myMenu);
    glutAddMenuEntry("Top View", 1);
    glutAddMenuEntry("Left View", 2);
    glutAddMenuEntry("Right View", 3);
    glutAddMenuEntry("Front View", 4);
    glutAddMenuEntry("Back View", 5);
    glutAddMenuEntry("Original View", 6);
    glutAddMenuEntry("Open/Close Door", 7);
    glutAddMenuEntry("Open/Close Mailbox", 8);
    glutAddMenuEntry("Control Human", 9);
    glutAttachMenu(GLUT_LEFT_BUTTON);
}

void myMenu(int id){
    if (id == 1) {
        lookFromPosX = 10.0;
        lookFromPosY = 200.0;
        lookFromPosZ = 10.0;
        lookAtPosX = 0.0;
        lookAtPosY = 0.0;
        lookAtPosZ = 0.0;
    }
    if (id == 2) {
        lookFromPosX = -140.0;
        lookFromPosY = 10.0;
        lookFromPosZ = 0.0;
        lookAtPosX = 0.0;
        lookAtPosY = 0.0;
        lookAtPosZ = 0.0;
    }
    if (id == 3) {
        lookFromPosX = 140.0;
        lookFromPosY = 10.0;
        lookFromPosZ = 0.0;
        lookAtPosX = 0.0;
        lookAtPosY = 0.0;
        lookAtPosZ = 0.0;
    }
    if (id == 4) {
        lookFromPosX = 0.0;
        lookFromPosY = 10.0;
        lookFromPosZ = 140.0;
        lookAtPosX = 0.0;
        lookAtPosY = 0.0;
        lookAtPosZ = 0.0;
    }
    if (id == 5) {
        lookFromPosX = 0.0;
        lookFromPosY = 10.0;
        lookFromPosZ = -140.0;
        lookAtPosX = 0.0;
        lookAtPosY = 0.0;
        lookAtPosZ = 0.0;
    }
    if (id == 6) {
        lookFromPosX = 120.0;
        lookFromPosY = 50.0;
        lookFromPosZ = 150.0;
        lookAtPosX = 0.0;
        lookAtPosY = 0.0;
        lookAtPosZ = 0.0;
    }
    if (id == 7) {
        if (door == 0) {
            door = 1;
        }else{
            door = 0;
        }
    }
    if (id == 8) {
        if (mailbox == 0){
            mailbox = 1;
        }else{
            mailbox = 0;
        }
    }
    if (id == 9){
        controlPerson = 1;
        lookAtPosX = humanPosX;
        lookAtPosZ = humanPosZ;
        lookAtPosY = 4.0;
        orbitMode = 0;
        zoomMode = 0;
    }
    glutPostRedisplay();
}

void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, 1.0, 10.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    if (controlPerson == 1) {
        lookAtPosX = humanPosX;
        lookAtPosY = 4.0;
        lookAtPosZ = humanPosZ;
    }

    
    
    gluLookAt(lookFromPosX, lookFromPosY, lookFromPosZ, lookAtPosX, lookAtPosY, lookAtPosZ, 0.0, 1.0, 0.0);
    
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    
    GLfloat ambientColor[] = {0.5f, 0.5f, 0.5f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
    
    GLfloat porchLightColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat porchLightPos[] = {53.0f, 7.0f, 23.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, porchLightColor);
    glLightfv(GL_LIGHT0, GL_POSITION, porchLightPos);
    
    
    GLfloat sunLightColor[] = {1.0f, 0.6f, 0.0f, 1.0f};
    GLfloat sunLightPos[] = {-200.0f, 200.0f, -200.0f};
    glLightfv(GL_LIGHT2, GL_DIFFUSE, sunLightColor);
    glLightfv(GL_LIGHT2, GL_POSITION, sunLightPos);
   
    GLfloat flashlightColor[] = {1.0f, 0.0f, 0.0f, 1.0f};
    GLfloat flashlightPos[] = {humanPosX, 3.0, humanPosZ};
    GLfloat flashlightDirectionFront[] = {0.0, -0.1, 1.0};
    GLfloat flashlightDirectionLeft[] = {-1.0, -0.1, 0.0};
    GLfloat flashlightDirectionBack[] = {0.0, -0.1, -1.0};
    GLfloat flashlightDirectionRight[] = {1.0, -0.1, 0.0};
    
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 10.0);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, flashlightColor);
    glLightfv(GL_LIGHT1, GL_POSITION, flashlightPos);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 10.0);
    
    
    if (personFace == 0) {
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, flashlightDirectionFront);
    }else if (personFace == 1){
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, flashlightDirectionLeft);
    }else if (personFace == 2){
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, flashlightDirectionBack);
    }else if (personFace == 3){
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, flashlightDirectionRight);
    }
    
    
    
    
    
    createBackground();
    createGround();
    createSidewalk();
    createFence();
    createTree();
    createHouse();
    createMailbox();
    mailboxCap();
    createHuman();
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glFlush();
}

void createHuman(){
    GLfloat shirtmat[] = {1.0, 0.11, 0.68, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, shirtmat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, shirtmat);
    glTranslatef(humanPosX, 3.75, humanPosZ);
    
    if(personFace == 1){
        glRotatef(270, 0.0, 1.0, 0.0);
    }
    if (personFace == 2) {
        glRotatef(180, 0.0, 1.0, 0.0);
    }
    if (personFace == 3) {
        glRotatef(90, 0.0, 1.0, 0.0);
    }
    
    //front torso
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 2.5, 0.0);
    glVertex3f(-2.0, 2.5, 0.0);
    glVertex3f(-2.0, 0.0, 0.0);
    glEnd();
    
    //left side
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, -0.5);
    glVertex3f(0.0, 2.5, -0.5);
    glVertex3f(0.0, 2.5, 0.0);
    glEnd();
    
    //right side
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, 0.0, 0.0);
    glVertex3f(-2.0, 2.5, 0.0);
    glVertex3f(-2.0, 2.5, -0.5);
    glVertex3f(-2.0, 0.0, -0.5);
    glEnd();

    //front shoulders
    glBegin(GL_POLYGON);
    glVertex3f(-2.75, 2.5, 0.0);
    glVertex3f(0.75, 2.5, 0.0);
    glVertex3f(0.75, 3.0, 0.0);
    glVertex3f(-2.75, 3.0, 0.0);
    glEnd();

    //front right arm
    glBegin(GL_POLYGON);
    glVertex3f(-2.75, 0.25, 0.0);
    glVertex3f(-2.25, 0.25, 0.0);
    glVertex3f(-2.25, 2.5, 0.0);
    glVertex3f(-2.75, 2.5, 0.0);
    glEnd();

    //front left arm
    glBegin(GL_POLYGON);
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.75, 0.25, 0.0);
    glVertex3f(0.75, 2.5, 0.0);
    glVertex3f(0.25, 2.5, 0.0);
    glEnd();
    
    //top shoulders
    glBegin(GL_POLYGON);
    glVertex3f(0.75, 3.0, 0.0);
    glVertex3f(0.75, 3.0, -0.5);
    glVertex3f(-2.75, 3.0, -0.5);
    glVertex3f(-2.75, 3.0, 0.0);
    glEnd();

    //outside left arm
    glBegin(GL_POLYGON);
    glVertex3f(0.75, 0.25, -0.5);
    glVertex3f(0.75, 3.0, -0.5);
    glVertex3f(0.75, 3.0, 0.0);
    glVertex3f(0.75, 0.25, 0.0);
    glEnd();

    //outside right arm
    glBegin(GL_POLYGON);
    glVertex3f(-2.75, 0.25, 0.0);
    glVertex3f(-2.75, 3.0, 0.0);
    glVertex3f(-2.75, 3.0, -0.5);
    glVertex3f(-2.75, 0.25, -0.5);
    glEnd();
    
    //inside left arm
    glBegin(GL_POLYGON);
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.25, 2.5, 0.0);
    glVertex3f(0.25, 2.5, -0.5);
    glVertex3f(0.25, 0.25, -0.5);
    glEnd();
    
    //inside right arm
    glBegin(GL_POLYGON);
    glVertex3f(-2.25, 0.25, -0.5);
    glVertex3f(-2.25, 2.5, -0.5);
    glVertex3f(-2.25, 2.5, 0.0);
    glVertex3f(-2.25, 0.25, 0.0);
    glEnd();

    //left armpit
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 2.5, 0.0);
    glVertex3f(0.0, 2.5, -0.5);
    glVertex3f(0.25, 2.5, -0.5);
    glVertex3f(0.25, 2.5, 0.0);
    glEnd();
    
    //right armpit
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, 2.5, 0.0);
    glVertex3f(-2.25, 2.5, 0.0);
    glVertex3f(-2.25, 2.5, -0.5);
    glVertex3f(-2.0, 2.5, -0.5);
    glEnd();
    
    //back right arm
    glBegin(GL_POLYGON);
    glVertex3f(-2.75, 0.25, -0.5);
    glVertex3f(-2.75, 2.5, -0.5);
    glVertex3f(-2.25, 2.5, -0.5);
    glVertex3f(-2.25, 0.25, -0.5);
    glEnd();

    //back left arm
    glBegin(GL_POLYGON);
    glVertex3f(0.25, 0.25, -0.5);
    glVertex3f(0.25, 2.5, -0.5);
    glVertex3f(0.75, 2.5, -0.5);
    glVertex3f(0.75, 0.25, -0.5);
    glEnd();

    //back shoulders
    glBegin(GL_POLYGON);
    glVertex3f(-2.75, 2.5, -0.5);
    glVertex3f(-2.75, 3.0, -0.5);
    glVertex3f(0.75, 3.0, -0.5);
    glVertex3f(0.75, 2.5, -0.5);
    glEnd();
    
    //back
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, -0.5);
    glVertex3f(-2.0, 0.0, -0.5);
    glVertex3f(-2.0, 2.5, -0.5);
    glVertex3f(0.0, 2.5, -0.5);
    glEnd();

    //neck
    GLfloat skinmat[] = {0.85, 0.57, 0.44, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, skinmat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, skinmat);
    
    //front neck
    glBegin(GL_POLYGON);
    glVertex3f(-0.75, 3.0, -0.1);
    glVertex3f(-0.75, 3.5, -0.1);
    glVertex3f(-1.25, 3.5, -0.1);
    glVertex3f(-1.25, 3.0, -0.1);
    glEnd();
    
    //left side neck
    glBegin(GL_POLYGON);
    glVertex3f(-0.75, 3.0, -0.4);
    glVertex3f(-0.75, 3.5, -0.4);
    glVertex3f(-0.75, 3.5, -0.1);
    glVertex3f(-0.75, 3.0, -0.1);
    glEnd();

    //right side neck
    glBegin(GL_POLYGON);
    glVertex3f(-1.25, 3.0, -0.1);
    glVertex3f(-1.25, 3.5, -0.1);
    glVertex3f(-1.25, 3.5, -0.4);
    glVertex3f(-1.25, 3.0, -0.4);
    glEnd();

    //back side neck
    glBegin(GL_POLYGON);
    glVertex3f(-1.25, 3.0, -0.4);
    glVertex3f(-1.25, 3.5, -0.4);
    glVertex3f(-0.75, 3.5, -0.4);
    glVertex3f(-0.75, 3.0, -0.4);
    glEnd();
    
    //left hand
    glPushMatrix();
    glTranslatef(0.5, 0.1, -0.25);
    glutSolidSphere(0.25, 100, 100);
    glPopMatrix();
    
    //right hand
    glPushMatrix();
    glTranslatef(-2.5, 0.1, -0.25);
    glutSolidSphere(0.25, 100, 100);
    glPopMatrix();
    
    //head
    glPushMatrix();
    glTranslatef(-1.0, 3.9, -0.25);
    glutSolidSphere(0.75, 100, 100);
    glPopMatrix();
    
    GLfloat pantsmat[] = {0.18, 0.18, 0.34, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, pantsmat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, pantsmat);
    
    //front lower body
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(-2.0, 0.0, 0.0);
    glVertex3f(-2.0, -0.75, 0.0);
    glVertex3f(0.0, -0.75, 0.0);
    glEnd();
    
    //right lower body
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, -0.75, 0.0);
    glVertex3f(0.0, -0.75, -0.5);
    glVertex3f(0.0, 0.0, -0.5);
    glEnd();
    
    //left lower body
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, 0.0, 0.0);
    glVertex3f(-2.0, 0.0, -0.5);
    glVertex3f(-2.0, -0.75, -0.5);
    glVertex3f(-2.0, -0.75, 0.0);
    glEnd();
    
    //butt
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, -0.5);
    glVertex3f(0.0, -0.75, -0.5);
    glVertex3f(-2.0, -0.75, -0.5);
    glVertex3f(-2.0, 0.0, -0.5);
    glEnd();
    
    createLeftLeg();
    createRightLeg();
    
    

}

void createLeftLeg(){
    glPushMatrix();
    glTranslatef(-1.0, -0.50, 0.0);
    glRotatef(leftLegAngle, 1.0, 0.0, 0.0);
    
    GLfloat pantsmat1[] = {0.18, 0.18, 0.34, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, pantsmat1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, pantsmat1);
    
    //front leg
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(-1.0, 0.0, 0.0);
    glVertex3f(-1.0, -3.0, 0.0);
    glVertex3f(0.0, -3.0, 0.0);
    glEnd();
    
    //left side leg
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, -3.0, 0.0);
    glVertex3f(0.0, -3.0, -0.5);
    glVertex3f(0.0, 0.0, -0.5);
    glEnd();

    //right side leg
    glBegin(GL_POLYGON);
    glVertex3f(-1.0, 0.0, -0.5);
    glVertex3f(-1.0, -3.0, -0.5);
    glVertex3f(-1.0, -3.0, 0.0);
    glVertex3f(-1.0, 0.0, 0.0);
    glEnd();

    //back side leg
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, -0.5);
    glVertex3f(0.0, -3.0, -0.5);
    glVertex3f(-1.0, -3.0, -0.5);
    glVertex3f(-1.0, 0.0, -0.5);
    glEnd();
    
    
    GLfloat shoemat[] = {0.196, 0.6, 0.8, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, shoemat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, shoemat);

    //shoe front
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -3.0, 1.0);
    glVertex3f(-0.8, -3.0, 1.0);
    glVertex3f(-0.8, -3.25, 1.0);
    glVertex3f(-0.2, -3.25, 1.0);
    glEnd();

    //shoe top
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -3.0, 1.0);
    glVertex3f(-0.2, -3.0, -0.5);
    glVertex3f(-0.8, -3.0, -0.5);
    glVertex3f(-0.8, -3.0, 1.0);
    glEnd();
    
    //shoe left
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -3.0, 1.0);
    glVertex3f(-0.2, -3.25, 1.0);
    glVertex3f(-0.2, -3.25, -0.5);
    glVertex3f(-0.2, -3.0, -0.5);
    glEnd();

    //shoe right
    glBegin(GL_POLYGON);
    glVertex3f(-0.8, -3.0, 1.0);
    glVertex3f(-0.8, -3.0, -0.5);
    glVertex3f(-0.8, -3.25, -0.5);
    glVertex3f(-0.8, -3.25, 1.0);
    glEnd();
    
    //shoe bottom
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -3.25, 1.0);
    glVertex3f(-0.8, -3.25, 1.0);
    glVertex3f(-0.8, -3.25, -0.5);
    glVertex3f(-0.2, -3.25, -0.5);
    glEnd();

    //shoe back
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -3.0, -0.5);
    glVertex3f(-0.2, -3.25, -0.5);
    glVertex3f(-0.8, -3.25, -0.5);
    glVertex3f(-0.8, -3.0, -0.5);
    glEnd();
    
    glPopMatrix();
}

void createRightLeg(){
    glPushMatrix();
    glTranslatef(0.0, -0.50, 0.0);
    glRotatef(rightLegAngle, 1.0, 0.0, 0.0);
    
    GLfloat pantsmat1[] = {0.18, 0.18, 0.34, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, pantsmat1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, pantsmat1);
    
    //front leg
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(-1.0, 0.0, 0.0);
    glVertex3f(-1.0, -3.0, 0.0);
    glVertex3f(0.0, -3.0, 0.0);
    glEnd();
    
    //left side leg
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, -3.0, 0.0);
    glVertex3f(0.0, -3.0, -0.5);
    glVertex3f(0.0, 0.0, -0.5);
    glEnd();
    
    //right side leg
    glBegin(GL_POLYGON);
    glVertex3f(-1.0, 0.0, -0.5);
    glVertex3f(-1.0, -3.0, -0.5);
    glVertex3f(-1.0, -3.0, 0.0);
    glVertex3f(-1.0, 0.0, 0.0);
    glEnd();
    
    //back side leg
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, -0.5);
    glVertex3f(0.0, -3.0, -0.5);
    glVertex3f(-1.0, -3.0, -0.5);
    glVertex3f(-1.0, 0.0, -0.5);
    glEnd();
    
    
    GLfloat shoemat[] = {0.196, 0.6, 0.8, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, shoemat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, shoemat);
    
    //shoe front
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -3.0, 1.0);
    glVertex3f(-0.8, -3.0, 1.0);
    glVertex3f(-0.8, -3.25, 1.0);
    glVertex3f(-0.2, -3.25, 1.0);
    glEnd();
    
    //shoe top
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -3.0, 1.0);
    glVertex3f(-0.2, -3.0, -0.5);
    glVertex3f(-0.8, -3.0, -0.5);
    glVertex3f(-0.8, -3.0, 1.0);
    glEnd();
    
    //shoe left
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -3.0, 1.0);
    glVertex3f(-0.2, -3.25, 1.0);
    glVertex3f(-0.2, -3.25, -0.5);
    glVertex3f(-0.2, -3.0, -0.5);
    glEnd();
    
    //shoe right
    glBegin(GL_POLYGON);
    glVertex3f(-0.8, -3.0, 1.0);
    glVertex3f(-0.8, -3.0, -0.5);
    glVertex3f(-0.8, -3.25, -0.5);
    glVertex3f(-0.8, -3.25, 1.0);
    glEnd();
    
    //shoe bottom
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -3.25, 1.0);
    glVertex3f(-0.8, -3.25, 1.0);
    glVertex3f(-0.8, -3.25, -0.5);
    glVertex3f(-0.2, -3.25, -0.5);
    glEnd();
    
    //shoe back
    glBegin(GL_POLYGON);
    glVertex3f(-0.2, -3.0, -0.5);
    glVertex3f(-0.2, -3.25, -0.5);
    glVertex3f(-0.8, -3.25, -0.5);
    glVertex3f(-0.8, -3.0, -0.5);
    glEnd();
    
    glPopMatrix();
}

void createMailbox(){
    glPushMatrix();
    glTranslatef(38.0, 0.0, 98.0);
    
    GLfloat mailstemmat[] = {0.52, 0.37, 0.26, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, mailstemmat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mailstemmat);
    glBegin(GL_POLYGON);
    
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 5.5, 0.0);
    glVertex3f(-1.0, 5.5, 0.0);
    glVertex3f(-1.0, 0.0, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, -1.0);
    glVertex3f(0.0, 5.5, -1.0);
    glVertex3f(0.0, 5.5, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, -1.0);
    glVertex3f(-1.0, 0.0, -1.0);
    glVertex3f(-1.0, 5.5, -1.0);
    glVertex3f(0.0, 5.5, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-1.0, 0.0, -1.0);
    glVertex3f(-1.0, 0.0, 0.0);
    glVertex3f(-1.0, 5.5, 0.0);
    glVertex3f(-1.0, 5.5, -1.0);
    glEnd();

    //box
    //front
    GLfloat mailmat0[] = {0.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, mailmat0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mailmat0);
    
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, 5.5, 2.0);
    glVertex3f(1.0, 5.5, 2.0);
    glVertex3f(1.0, 7.5, 2.0);
    glVertex3f(-2.0, 7.5, 2.0);
    glEnd();
    
    
    GLfloat mailmat[] = {0.25, 0.25, 0.44, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, mailmat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mailmat);
    
    //right
    glBegin(GL_POLYGON);
    glVertex3f(1.0, 5.5, 2.0);
    glVertex3f(1.0, 5.5, -3.0);
    glVertex3f(1.0, 7.5, -3.0);
    glVertex3f(1.0, 7.5, 2.0);
    glEnd();
    
    //top
    glBegin(GL_POLYGON);
    glVertex3f(1.0, 7.5, 2.0);
    glVertex3f(1.0, 7.5, -3.0);
    glVertex3f(-2.0, 7.5, -3.0);
    glVertex3f(-2.0, 7.5, 2.0);
    glEnd();
    
    //left
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, 5.5, -3.0);
    glVertex3f(-2.0, 5.5, 2.0);
    glVertex3f(-2.0, 7.5, 2.0);
    glVertex3f(-2.0, 7.5, -3.0);
    glEnd();
    
    //back
    glBegin(GL_POLYGON);
    glVertex3f(1.0, 5.5, -3.0);
    glVertex3f(-2.0, 5.5, -3.0);
    glVertex3f(-2.0, 7.5, -3.0);
    glVertex3f(1.0, 7.5, -3.0);
    glEnd();
    
    //bottom
    glBegin(GL_POLYGON);
    glVertex3f(1.0, 5.5, 2.0);
    glVertex3f(-2.0, 5.5, 2.0);
    glVertex3f(-2.0, 5.5, -3.0);
    glVertex3f(1.0, 5.5, -3.0);
    glEnd();
    
    glPopMatrix();
}

void mailboxCap(){
    glPushMatrix();
    glTranslatef(39.0, 5.5, 100.01);

    if(mailbox == 1){
        glRotatef(90, 1.0, 0.0, 0.0);
    }
    GLfloat mailmat[] = {0.25, 0.25, 0.44, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, mailmat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mailmat);
    glBegin(GL_POLYGON);
    
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 2.0, 0.0);
    glVertex3f(-3.0, 2.0, 0.0);
    glVertex3f(-3.0, 0.0, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(-3.0, 0.0, 0.0);
    glVertex3f(-3.0, 2.0, 0.0);
    glVertex3f(0.0, 2.0, 0.0);
    glEnd();
    
    glPopMatrix();

}

void createGround(){
    
    loadBMP_custom("/Users/adopson/Documents/finalProjectCS470/finalProjectCS470/grass.BMP");
    // Create one OpenGL texture
    GLuint grass;
    glGenTextures(1, &grass);
    
    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, grass);
    
    // Give the image to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    
    
    glPushMatrix();
    GLfloat groundmat[] = {0.18f, 0.32f, 0.18f, 1.0f};
    glMaterialfv(GL_FRONT, GL_AMBIENT, groundmat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, groundmat);

    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-100.0, 0.0, 100.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(100.0, 0.0, 100.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(100.0, 0.0, -100.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-100.0, 0.0, -100.0);
    glEnd();
    
    

    
    GLfloat groundmat1[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_AMBIENT, groundmat1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, groundmat1);
    
    glBegin(GL_POLYGON);
    glVertex3f(-100.0, -0.01, 110.0);
    glVertex3f(-100.0, -0.01, -100.0);
    glVertex3f(100.0, -0.01, -100.0);
    glVertex3f(100.0, -0.01, 110.0);
    
    glEnd();

    
    
    glPopMatrix();
}

void createBackground(){
    loadBMP_custom("/Users/adopson/Documents/finalProjectCS470/finalProjectCS470/sky.bmp");
    // Create one OpenGL texture
    GLuint sky;
    glGenTextures(1, &sky);
    
    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, sky);
    
    // Give the image to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    GLfloat skymat[] = {0.196f, 0.3f, 0.8f, 1.0f};
    glMaterialfv(GL_FRONT, GL_AMBIENT, skymat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, skymat);
    
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(300.0, 5.0, -100.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(300.0, 100.0, -100.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-300.0, 100.0, -100.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-300.0, 5.0, -100.0);
    glEnd();
    
    
    loadBMP_custom("/Users/adopson/Documents/finalProjectCS470/finalProjectCS470/road.bmp");
    // Create one OpenGL texture
    GLuint road;
    glGenTextures(1, &road);
    
    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, road);
    
    // Give the image to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    GLfloat roadmat[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_AMBIENT, roadmat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, roadmat);
    
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(100.0, 0.0, 110.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-100.0, 0.0, 110.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-100.0, 0.0, 130.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(100.0, 0.0, 130.0);
    glEnd();
    
    
}

void createSidewalk(){
    loadBMP_custom("/Users/adopson/Documents/finalProjectCS470/finalProjectCS470/sidewalk.bmp");
    // Create one OpenGL texture
    GLuint sidewalk;
    glGenTextures(1, &sidewalk);
    
    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, sidewalk);
    
    // Give the image to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    //sidewalk
    glPushMatrix();
    GLfloat sidewalkmat[] = {0.5, 0.5, 0.5, 1.0f};
    glMaterialfv(GL_FRONT, GL_AMBIENT, sidewalkmat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, sidewalkmat);
    
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(40.0, 0.01, 19.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(40.0, 0.01, 100.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(50.0, 0.01, 100.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(50.0, 0.01, 19.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-100.0, 0.01, 110.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(100.0, 0.01, 110.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(100.0, 0.01, 100.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-100.0, 0.01, 100.0);
    glEnd();
    glPopMatrix();
    
   
}

void createFence(){
    glPushMatrix();
    GLfloat fencemat[] = {0.64, 0.16, 0.16, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, fencemat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, fencemat);
    
    //front left of sidewalk
    glBegin(GL_POLYGON);
    glVertex3f(-100.0, 0.0, 100.0);
    glVertex3f(40.0, 0.0, 100.0);
    glVertex3f(40.0, 5.0, 100.0);
    glVertex3f(-100.0, 5.0, 100.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(-100.0, 5.0, 100.0);
    glVertex3f(40.0, 5.0, 100.0);
    glVertex3f(40.0, 5.0, 99.0);
    glVertex3f(-100.0, 5.0, 99.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(40.0, 0.0, 99.0);
    glVertex3f(-100.0, 0.0, 99.0);
    glVertex3f(-100.0, 5.0, 99.0);
    glVertex3f(40.0, 5.0, 99.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(40.0, 0.0, 100.0);
    glVertex3f(40.0, 0.0, 99.0);
    glVertex3f(40.0, 5.0, 99.0);
    glVertex3f(40.0, 5.0, 100.0);
    glEnd();

    //front right of sidewalk
    glBegin(GL_POLYGON);
    glVertex3f(50.0, 0.0, 100.0);
    glVertex3f(100.0, 0.0, 100.0);
    glVertex3f(100.0, 5.0, 100.0);
    glVertex3f(50.0, 5.0, 100.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(50.0, 0.0, 100.0);
    glVertex3f(50.0, 5.0, 100.0);
    glVertex3f(50.0, 5.0, 99.0);
    glVertex3f(50.0, 0.0, 99.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(50.0, 5.0, 100.0);
    glVertex3f(100.0, 5.0, 100.0);
    glVertex3f(100.0, 5.0, 99.0);
    glVertex3f(50.0, 5.0, 99.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(50.0, 0.0, 99.0);
    glVertex3f(50.0, 5.0, 99.0);
    glVertex3f(100.0, 5.0, 99.0);
    glVertex3f(100.0, 0.0, 99.0);
    glEnd();
    
    //left side
    glBegin(GL_POLYGON);
    glVertex3f(-100.0, 0.0, 100.0);
    glVertex3f(-100.0, 5.0, 100.0);
    glVertex3f(-100.0, 5.0, -100.0);
    glVertex3f(-100.0, 0.0, -100.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(-100.0, 5.0, 100.0);
    glVertex3f(-99.0, 5.0, 100.0);
    glVertex3f(-99.0, 5.0, -100.0);
    glVertex3f(-100.0, 5.0, -100.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(-99.0, 0.0, 100.0);
    glVertex3f(-99.0, 0.0, -100.0);
    glVertex3f(-99.0, 5.0, -100.0);
    glVertex3f(-99.0, 5.0, 100.0);
    glEnd();

    //right side
    glBegin(GL_POLYGON);
    glVertex3f(100.0, 0.0, 100.0);
    glVertex3f(100.0, 0.0, -100.0);
    glVertex3f(100.0, 5.0, -100.0);
    glVertex3f(100.0, 5.0, 100.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(99.0, 0.0, -100.0);
    glVertex3f(99.0, 0.0, 100.0);
    glVertex3f(99.0, 5.0, 100.0);
    glVertex3f(99.0, 5.0, -100.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(99.0, 5.0, 100.0);
    glVertex3f(100.0, 5.0, 100.0);
    glVertex3f(100.0, 5.0, -100.0);
    glVertex3f(99.0, 5.0, -100.0);
    glEnd();
    
    //back side
    glBegin(GL_POLYGON);
    glVertex3f(-100.0, 0.0, -99.0);
    glVertex3f(100.0, 0.0, -99.0);
    glVertex3f(100.0, 5.0, -99.0);
    glVertex3f(-100.0, 5.0, -99.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-100.0, 5.0, -99.0);
    glVertex3f(100.0, 5.0, -99.0);
    glVertex3f(100.0, 5.0, -100.0);
    glVertex3f(-100.0, 5.0, -100.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(100.0, 0.0, -100.0);
    glVertex3f(-100.0, 0.0, -100.0);
    glVertex3f(-100.0, 5.0, -100.0);
    glVertex3f(100.0, 5.0, -100.0);
    glEnd();
    glPopMatrix();
}

void createDoor(){
    glPushMatrix();
    glTranslatef(50.0, 0.0, 20.0);
    if(door == 0){
        glRotatef(300, 0.0, 1.0, 0.0);
    }
    GLfloat doormat[] = {1.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, doormat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, doormat);
    
    //front
    glBegin(GL_POLYGON);
    
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 8.0, 0.0);
    glVertex3f(-10.0, 8.0, 0.0);
    glEnd();
    
    //left
    glBegin(GL_POLYGON);
    
    glVertex3f(-10.0, 0.0, -1.0);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f(-10.0, 8.0, 0.0);
    glVertex3f(-10.0, 8.0, -1.0);
    glEnd();
    
    //right
    glBegin(GL_POLYGON);
    
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, -1.0);
    glVertex3f(0.0, 8.0, -1.0);
    glVertex3f(0.0, 8.0, 0.0);
    glEnd();
    
    //back
    glBegin(GL_POLYGON);
    
    glVertex3f(0.0, 0.0, -1.0);
    glVertex3f(-10.0, 0.0, -1.0);
    glVertex3f(-10.0, 8.0, -1.0);
    glVertex3f(0.0, 8.0, -1.0);
    glEnd();
    
    //top
    glBegin(GL_POLYGON);
    
    glVertex3f(-10.0, 8.0, 0.0);
    glVertex3f(0.0, 8.0, 0.0);
    glVertex3f(0.0, 8.0, -1.0);
    glVertex3f(-10.0, 8.0, -1.0);
    glEnd();
    
    //doorknob
    glPushMatrix();
    glColor3f(0.8, 0.49, 0.19);
    glTranslatef(-9.0, 4.0, 0.5);
    glutSolidSphere(0.5, 100, 100);
    glPopMatrix();
    
    glPopMatrix();
}

void createHouse(){

    //porchlight
    GLfloat porchlightmat[] = {1.0, 1.0, 0.1, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, porchlightmat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, porchlightmat);
    
    glBegin(GL_POLYGON);
    glVertex3f(53.0, 7.0, 22.0);
    glVertex3f(55.0, 7.0, 22.0);
    glVertex3f(55.0, 9.0, 22.0);
    glVertex3f(53.0, 9.0, 22.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(53.0, 7.0, 20.0);
    glVertex3f(53.0, 7.0, 22.0);
    glVertex3f(53.0, 9.0, 22.0);
    glVertex3f(53.0, 9.0, 20.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(55.0, 7.0, 20.0);
    glVertex3f(55.0, 9.0, 20.0);
    glVertex3f(55.0, 9.0, 22.0);
    glVertex3f(55.0, 7.0, 22.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(53.0, 9.0, 20.0);
    glVertex3f(53.0, 9.0, 22.0);
    glVertex3f(55.0, 9.0, 22.0);
    glVertex3f(55.0, 9.0, 20.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(53.0, 7.0, 20.0);
    glVertex3f(55.0, 7.0, 20.0);
    glVertex3f(55.0, 7.0, 22.0);
    glVertex3f(53.0, 7.0, 22.0);
    glEnd();
    
    
    
    
    //ceiling
    glBegin(GL_POLYGON);
    GLfloat ceilingmat[] = {0.5, 1.0, 0.2, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, ceilingmat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, ceilingmat);
    glVertex3f(1.0, 30.0, 19.0);
    glVertex3f(1.0, 30.0, -79.0);
    glVertex3f(89.0, 30.0, -79.0);
    glVertex3f(89.0, 30.0, 19.0);
    glEnd();
    
    //floor
    glBegin(GL_POLYGON);
    GLfloat floormat[] = {0.5, 0.5, 0.5, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, floormat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, floormat);
    glVertex3f(1.0, 0.01, 19.0);
    glVertex3f(89.0, 0.01, 19.0);
    glVertex3f(89.0, 0.01, -79.0);
    glVertex3f(1.0, 0.01, -79.0);
    glEnd();
    
    //inside back
    glBegin(GL_POLYGON);
    GLfloat wallmat[] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, wallmat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, wallmat);
    glVertex3f(0.0, 0.0, -79.0);
    glVertex3f(90.0, 0.0, -79.0);
    glVertex3f(90.0, 30.0, -79.0);
    glVertex3f(0.0, 30.0, -79.0);
    glEnd();
    
    //inside front left
    glBegin(GL_POLYGON);
    
    glVertex3f(40.0, 0.0, 19.0);
    glVertex3f(0.0, 0.0, 19.0);
    glVertex3f(0.0, 30.0, 19.0);
    glVertex3f(40.0, 30.0, 19.0);
    glEnd();
    
    //inside front middle
    glBegin(GL_POLYGON);
    
    glVertex3f(50.0, 8.0, 19.0);
    glVertex3f(40.0, 8.0, 19.0);
    glVertex3f(40.0, 30.0, 19.0);
    glVertex3f(50.0, 30.0, 19.0);
    glEnd();
    
    //inside front right
    glBegin(GL_POLYGON);
    
    glVertex3f(90.0, 0.0, 19.0);
    glVertex3f(50.0, 0.0, 19.0);
    glVertex3f(50.0, 30.0, 19.0);
    glVertex3f(90.0, 30.0, 19.0);
    glEnd();

    //inside left
    glBegin(GL_POLYGON);
    
    glVertex3f(1.0, 0.0, 20.0);
    glVertex3f(1.0, 0.0, -80.0);
    glVertex3f(1.0, 30.0, -80.0);
    glVertex3f(1.0, 30.0, 20.0);
    glEnd();
    
    //inside right
    glBegin(GL_POLYGON);
    
    glVertex3f(89.0, 0.0, 20.0);
    glVertex3f(89.0, 30.0, 20.0);
    glVertex3f(89.0, 30.0, -80.0);
    glVertex3f(89.0, 0.0, -80.0);
    glEnd();

    createDoor();
    
    //front left
    GLfloat outsidemat[] = {0.59, 0.41, 0.31, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, outsidemat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, outsidemat);
    
    glBegin(GL_POLYGON);
    glColor3f(0.59, 0.41, 0.31);
    glVertex3f(0.0, 0.0, 20.0);
    glVertex3f(40.0, 0.0, 20.0);
    glVertex3f(40.0, 30.0, 20.0);
    glVertex3f(0.0, 30.0, 20.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.59, 0.41, 0.31);
    glVertex3f(40.0, 0.0, 20.0);
    glVertex3f(40.0, 0.0, 19.0);
    glVertex3f(40.0, 8.0, 19.0);
    glVertex3f(40.0, 8.0, 20.0);
    glEnd();
    
    //front middle
    glBegin(GL_POLYGON);
    glColor3f(0.59, 0.41, 0.31);
    glVertex3f(40.0, 8.0, 20.0);
    glVertex3f(50.0, 8.0, 20.0);
    glVertex3f(50.0, 30.0, 20.0);
    glVertex3f(40.0, 30.0, 20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.59, 0.41, 0.31);
    glVertex3f(40.0, 8.0, 19.0);
    glVertex3f(50.0, 8.0, 19.0);
    glVertex3f(50.0, 8.0, 20.0);
    glVertex3f(40.0, 8.0, 20.0);
    glEnd();
    
    //front right
    glBegin(GL_POLYGON);
    glColor3f(0.59, 0.41, 0.31);
    glVertex3f(50.0, 0.0, 20.0);
    glVertex3f(90.0, 0.0, 20.0);
    glVertex3f(90.0, 30.0, 20.0);
    glVertex3f(50.0, 30.0, 20.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.59, 0.41, 0.31);
    glVertex3f(50.0, 0.0, 19.0);
    glVertex3f(50.0, 0.0, 20.0);
    glVertex3f(50.0, 8.0, 20.0);
    glVertex3f(50.0, 8.0, 19.0);
    glEnd();
    
    //left wall
    glBegin(GL_POLYGON);
    glColor3f(0.59, 0.41, 0.31);
    glVertex3f(0.0, 0.0, 20.0);
    glVertex3f(0.0, 30.0, 20.0);
    glVertex3f(0.0, 30.0, -80.0);
    glVertex3f(0.0, 0.0, -80.0);
    glEnd();
    
    //back wall
    glBegin(GL_POLYGON);
    glColor3f(0.59, 0.41, 0.31);
    glVertex3f(90.0, 0.0, -80.0);
    glVertex3f(0.0, 0.0, -80.0);
    glVertex3f(0.0, 30.0, -80.0);
    glVertex3f(90.0, 30.0, -80.0);
    glEnd();

    //right wall
    glBegin(GL_POLYGON);
    glColor3f(0.59, 0.41, 0.31);
    glVertex3f(90.0, 0.0, 20.0);
    glVertex3f(90.0, 0.0, -80.0);
    glVertex3f(90.0, 30.0, -80.0);
    glVertex3f(90.0, 30.0, 20.0);
    glEnd();

    //front roof
    GLfloat roofmat[] = {0.2, 0.2, 0.2, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, roofmat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, roofmat);

    glBegin(GL_TRIANGLES);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(0.0, 30.0, 20.0);
    glVertex3f(90.0, 30.0, 20.0);
    glVertex3f(45.0, 40.0, 20.0);
    glEnd();
    
    //back roof
    glBegin(GL_TRIANGLES);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(0.0, 30.0, -80.0);
    glVertex3f(45.0, 40.0, -80.0);
    glVertex3f(90.0, 30.0, -80.0);
    glEnd();

    //left roof
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(0.0, 30.0, 20.0);
    glVertex3f(45.0, 40.0, 20.0);
    glVertex3f(45.0, 40.0, -80.0);
    glVertex3f(0.0, 30.0, -80.0);
    glEnd();
    
    //right roof
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(90.0, 30.0, -80.0);
    glVertex3f(45.0, 40.0, -80.0);
    glVertex3f(45.0, 40.0, 20.0);
    glVertex3f(90.0, 30.0, 20.0);
    glEnd();
}

void createTree(){
    glPushMatrix();
    glRotatef(270.0, 1.0, 0.0, 0.0);
    glTranslatef(-50.0, 0.0, 0.0);
    GLfloat trunkmat[] = {0.52, 0.37, 0.26, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, trunkmat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, trunkmat);
    GLUquadricObj *obj = gluNewQuadric();
    gluCylinder(obj, 5.0, 3.0, 20.0, 100, 100);
    glPopMatrix();
    
    glPushMatrix();
    GLfloat treemat[] = {0.41, 0.56, 0.13, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, treemat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, treemat);

    glTranslatef(-50.0, 34.0, 0.0);
    glutSolidSphere(15.0, 150, 150);
    
    glPopMatrix();
}

int loadBMP_custom(const char * imagepath){
        FILE * file = fopen(imagepath ,"rb");
    if (!file) {
        printf("Image could not be opened\n");
    }
    
    if ( fread(header, 1, 54, file)!=54 ){ // If not 54 bytes read : problem
        printf("Not a correct BMP file\n");
    }
    
    if ( header[0]!='B' || header[1]!='M' ){
        printf("Not a correct BMP file\n");
    }
    
    dataPos    = *(int*)&(header[0x0A]);
    imageSize  = *(int*)&(header[0x22]);
    width      = *(int*)&(header[0x12]);
    height     = *(int*)&(header[0x16]);
    
    if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
    if (dataPos==0)      dataPos=54;
    
    unsigned char data1[imageSize];
    // Create a buffer
    data = data1;
    
    // Read the actual data from the file into the buffer
    
    fread(data,1,imageSize,file);

    return 0;
    
}










