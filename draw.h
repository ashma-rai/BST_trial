#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED
//#include "bstClass.h"
//extern bstClass bstobj;
//extern int num;

void drawInsertMenu()
{   glColor3f(0.8,0.7,0.7);
    glBegin(GL_QUADS);
    glVertex3f(-100,-100,0);
    glVertex3f(100,-100,0);
    glVertex3f(100,100,0);
    glVertex3f(-100,100,0);
    glEnd();
}

#endif // DRAW_H_INCLUDED
