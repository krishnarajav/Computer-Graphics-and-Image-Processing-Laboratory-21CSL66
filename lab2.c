//Develop a program to demonstrate basic geometric operations on the 2D object

#include <GL/glut.h>
#include <stdio.h>

float red = 0.0;
float green = 0.0;
float blue = 0.0;

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
	glLoadIdentity(); // Load the identity matrix
	glColor3f(red, green, blue); // Set square color based on variables
	glBegin(GL_QUADS);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, 0.5);
	glEnd();
	glFlush(); // Flush OpenGL buffer
}

void menu(int option) {
	switch (option) {
		case 1: // Change square color to red
			red = 1.0; green = 0.0; blue = 0.0;
			break;
		case 2: // Change square color to green
			red = 0.0; green = 1.0; blue = 0.0;
			break;
		case 3: // Change square color to blue
			red = 0.0; green = 0.0, blue = 1.0;
			break;
		case 4: // Change square color to yellow
			red = 1.0; green = 1.0; blue = 0.0;
			break;
		case 5: // Change square color to magenta
			red = 1.0; green = 0.0; blue = 1.0;
			break;
		case 6: // Change square color to cyan
			red = 0.0; green = 1.0; blue = 1.0;
			break;
		case 7: // Exit program
			exit(0);
			break;
	}
	glutPostRedisplay(); // Mark the current window for redisplay
}

void createMenu() {
	glutCreateMenu(menu);
	glutAddMenuEntry("Color Red", 1);
	glutAddMenuEntry("Color Green", 2);
	glutAddMenuEntry("Color Blue", 3);
	glutAddMenuEntry("Color Yellow", 4);
	glutAddMenuEntry("Color Magenta", 5);
	glutAddMenuEntry("Color Cyan", 6);
	glutAddMenuEntry("Exit", 7);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
	glutInitWindowSize(500, 500); // Set window size
	glutInitWindowPosition(100, 100); // Set window position
	glutCreateWindow("Basic Geometric Operations"); // Create the window with the given title
	init(); // Initialize drawing
	glutDisplayFunc(display); // Register display callback function
	createMenu(); // Create menu
	glutMainLoop(); // Enter the main loop
	return 0;
}
