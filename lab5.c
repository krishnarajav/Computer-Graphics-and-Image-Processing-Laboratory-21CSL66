//Develop a program to demonstrate 3D transformation on 3D objects

#include <GL/glut.h>
#include <stdio.h>

float tx = 0.0, ty = 0.0, tz = 0.0;
float sx = 1.0, sy = 1.0, sz = 1.0;
float angleX = 0.0, angleY = 0.0, angleZ = 0.0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glScalef(sx, sy, sz);
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);
    glRotatef(angleZ, 0.0, 0.0, 1.0);
   
    glBegin(GL_QUADS);
    
    // Front face
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f( 0.5, -0.5, 0.5);
    glVertex3f( 0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
   
    // Back face
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f( 0.5, -0.5, -0.5);
    glVertex3f( 0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
   
    // Top face
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f( 0.5, 0.5, -0.5);
    glVertex3f( 0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
   
    // Bottom face
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f( 0.5, -0.5, -0.5);
    glVertex3f( 0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
   
    // Right face
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f( 0.5, -0.5, -0.5);
    glVertex3f( 0.5, 0.5, -0.5);
    glVertex3f( 0.5, 0.5, 0.5);
    glVertex3f( 0.5, -0.5, 0.5);
   
    // Left face
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glEnd();
    
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'a': // Translate Left
            tx -= 0.1;
            break;
        case 'd': // Translate Right
            tx += 0.1;
            break;
        case 'w': // Translate Up
            ty += 0.1;
            break;
        case 's': // Translate Down
            ty -= 0.1;
            break;
        case 'q': // Translate Forward
            tz += 0.1;
            break;
        case 'e': // Translate Backward
            tz -= 0.1;
            break;
        case 'z': // Scale Down
            sx *= 0.9;
            sy *= 0.9;
            sz *= 0.9;
            break;
        case 'x': // Scale Up
            sx *= 1.1;
            sy *= 1.1;
            sz *= 1.1;
            break;
        case 'i': // Rotate around X-axis
            angleX += 5.0;
            break;
        case 'j': // Rotate around Y-axis
            angleY += 5.0;
            break;
        case 'k': // Rotate around Z-axis
            angleZ += 5.0;
            break;
        case 'r': // Reset Transformations
            tx = 0.0;
            ty = 0.0;
            tz = 0.0;
            sx = 1.0;
            sy = 1.0;
            sz = 1.0;
            angleX = 0.0;
            angleY = 0.0;
            angleZ = 0.0;
            break;
        case 27: // Escape key (ASCII value for ESC)
            exit(0);
            break;
    }
   
    glutPostRedisplay();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Transformations");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // Register keyboard callback
    glutMainLoop();
    return 0;
}
