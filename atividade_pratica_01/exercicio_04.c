/*
Crie uma animação de um relógio analógico com as marcações
de tempo e os 3 ponteiros (horas, minutos, segundos)
*/
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

int init();
void display();

void DrawCircle(GLfloat x, GLfloat y, GLfloat radius);

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(200, 0); // posição da janela
    glutInitWindowSize(400, 300);   // largura e altura da janela
    glutCreateWindow("Quadrado");   // cria a janela

    init();                   // executa função de inicialização
    glutDisplayFunc(display); // função "display" como a função de
                              // callback de exibição
    glutMainLoop();           // mostre tudo e espere
    DrawCircle(3,3,3);
    return 0;
}

void DrawCircle(GLfloat x, GLfloat y, GLfloat radius){
    int i;
    int lineAmount = 100; //# of triangles used to draw circle
    
    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.14;
    
    glBegin(GL_LINE_LOOP);
        for(i = 0; i <= lineAmount;i++) { 
            glVertex2f(
                x + (radius * cos(i *  twicePi / lineAmount)), 
                y + (radius* sin(i * twicePi / lineAmount))
            );
        }
    glEnd();
}
