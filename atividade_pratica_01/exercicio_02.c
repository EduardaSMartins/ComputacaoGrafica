#include <stdio.h>
#include <GL/glut.h>
#include <stdbool.h>

/*
Modifique a animação anterior (crie um novo arquivo) para que o
quadrado se movimente em um determinado ângulo e "quique" ao
bater em uma das extremidades da tela. Ao bater na tela, o fundo
deve trocar de cor de forma aleatória
*/

int init();
void display();
void movimentaQuadrado();

GLfloat rfx, rfy, sx, sy, angle, tx, ty;
bool increasing;
int tamX = 500, tamY = 300, volta=0, tamQuadrado=30;

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(500, 0); // posição da janela
    glutInitWindowSize(tamX, tamY); // largura e altura da janela
    glutCreateWindow("Quadrado com movimento");   // cria a janela

    init();                   // executa função de inicialização
    glutDisplayFunc(display); // função "display" como a função de
                              // callback de exibição

    glutMainLoop(); // mostre tudo e espere
    return 0;
}

int init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // define a cor de fundo

    glMatrixMode(GL_PROJECTION); // carrega a matriz de projeção
    gluOrtho2D(0, tamX/2, 0, tamY/2);  // define projeção ortogonal 2D que
                                 // mapeia objetos da coordenada do
                                 // mundo para coordenadas da tela
    rfx = 100;
    rfy = 65;
    sx = sy = 1;
    angle = 0;
    increasing = true;
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glLoadIdentity();
    movimentaQuadrado();
    glBegin(GL_QUADS);
    glVertex2f(0, tamQuadrado);
    glVertex2f(tamQuadrado, tamQuadrado);
    glVertex2f(tamQuadrado, 0);
    glVertex2f(0, 0);
    glEnd();

    glPopMatrix();

    glLoadIdentity();
    glTranslatef(rfx, rfy, 0);
    glTranslatef(-rfx, -rfy, 0);

    glutPostRedisplay();
    glutSwapBuffers();
}

void movimentaQuadrado()
{
    if (tx < (tamX/2)-tamQuadrado && volta == 0)
        tx += 1;
    else {
        volta = 1;
        tx -= 1;
        if(tx == 0) volta = 0;
    }
    glTranslatef(tx, ty, 0);
}