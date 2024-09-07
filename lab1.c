//Develop a program to draw a line using Bresenham’s line drawing technique

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

GLint xStart, yStart, xEnd, yEnd;

void setPixel(int x, int y) {
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void bresenhamLine(int xStart, int yStart, int xEnd, int yEnd) {
    int dx = abs(xEnd - xStart);
    int dy = abs(yEnd - yStart);
    float m = (float)dy / (float)dx;
    if(m < 1.0) {
    	int D = 2 * dy - dx;
	    int x = xStart, y = yStart;
	    for (x = xStart; x <= xEnd; x++) {
	        setPixel(x, y);
	        if (D >= 0) {
	            y++;
	            D = D + (2 * (dy - dx));
	        } 
			else {
	            D = D + 2*dy;
	        }
	    }
	}
	else {
		int D = 2 * dx - dy;
	    int x = xStart, y = yStart;
	    for (y = yStart; y <= yEnd; y++) {
	        setPixel(x, y);
	        if (D >= 0) {
	            x++;
	            D = D + (2 * (dx - dy));
	        } 
			else {
	            D = D + 2*dx;
	        }
	    }
	}   
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    bresenhamLine(xStart, yStart, xEnd, yEnd);
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}

int main(int argc, char **argv) {
    printf("Bresenham's Line Drawing:\n");
    printf("Enter starting vertex (xStart, yStart): ");
    scanf("%d %d", &xStart, &yStart);
    printf("\nEnter ending vertex (xEnd, yEnd): ");
    scanf("%d %d", &xEnd, &yEnd);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
