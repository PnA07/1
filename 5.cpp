

#include <glut.h>

float tx = 0.0, ty = 0.0, tz = 0.0; 
float angleX = 0.0, angleY = 0.0, angleZ = 0.0;  
float scale = 1.0;  

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  
    glEnable(GL_DEPTH_TEST);           
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();  

    
    glTranslatef(tx, ty, tz);  
    glRotatef(angleX, 1.0, 0.0, 0.0);  
    glRotatef(angleY, 0.0, 1.0, 0.0);  
    glRotatef(angleZ, 0.0, 0.0, 1.0);  
    glScalef(scale, scale, scale);  

    
    glBegin(GL_QUADS);
    
    glColor3f(0.5, 0.0, 0.0);  

    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);

    
    glColor3f(0.0, 1.0, 0.0); 

    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);

   
    glColor3f(0.0, 0.0, 1.0); 

    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);

    
    glColor3f(1.0, 1.0, 0.0);  

    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);

    
    glColor3f(1.0, 0.0, 1.0);  

    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);

    
    glColor3f(0.0, 1.0, 1.0);  

    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glEnd();

    glutSwapBuffers();  
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'u': ty += 0.1f; break;  
    case 'd': ty -= 0.1f; break;  
    case 'l': tx -= 0.1f; break;  
    case 'r': tx += 0.1f; break;  
    case 'q': tz += 0.3f; break;  
    case 'e': tz -= 0.3f; break;  
    case 'x': angleX += 5.0f; break;  
    case 'X': angleX -= 5.0f; break;  
    case 'y': angleY += 5.0f; break;  
    case 'Y': angleY -= 5.0f; break;  
    case 'z': angleZ += 5.0f; break;  
    case 'Z': angleZ -= 5.0f; break;  
    case 's': scale += 0.1f; break;  
    case 'S': scale -= 0.1f; break;  
    case 27: exit(0);  
    }
    glutPostRedisplay();  
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Transformations in OpenGL");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}