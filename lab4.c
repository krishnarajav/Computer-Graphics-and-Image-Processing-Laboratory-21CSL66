//Develop a program to demonstrate 2D transformation on basic objects

#include <GL/glut.h>
#include <math.h>

// Angle for rotating the object
float angle = 0.0;

// Scaling factor for the object
float scale = 1.0;

// Translation values for the object
float translateX = 0.0;
float translateY = 0.0;

// Current object to transform: 0 for square, 1 for triangle
int currentObject = 0;

// Function to handle rendering the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Apply translation
    glTranslatef(translateX, translateY, 0.0);
    // Apply rotation
    glRotatef(angle, 0.0, 0.0, 1.0);
    // Apply scaling
    glScalef(scale, scale, 1.0);
    glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);
    glEnd();
    glutSwapBuffers();
}

// Function to handle key press events
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            angle += 5.0;
            break;
        case 'd':
            angle -= 5.0;
            break;
        case 'w':
            scale += 0.1;
            break;
        case 's':
            scale -= 0.1;
            break;
        case 'x':
            translateX += 0.1;
            break;
        case 'z':
            translateX -= 0.1;
            break;
        case 'y':
            translateY += 0.1;
            break;
        case 'h':
            translateY -= 0.1;
            break;
        case 'q':
            exit(0);
    }
    glutPostRedisplay();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("2D Transformations on Basic Objects");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
