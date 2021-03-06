//initial
#include<iostream>
#include<GL/glut.h>
#include "bstClass.h"
//#include "draw.h"
#include "keyboardEventHandler.h"
#include "drawTree.h"
using namespace std;
bstClass bstobj;
drawTree drawobj;
keyboardEventHandler keyboardobj;
int choice, num,numofelements,menuVal,val;
bool inputKeyboardVal=false;
bool enterNotPressed=true;
int i=0,keyX=-80,keyY=-30;
char keyPressed[5];

void init();
void display();
void reshape(int ,int);

void resetKeyPressed()
{
    while(i>=0)
            {
            keyPressed[i]='\0';
            i--;
            }
            i=0;
}
void updateTree()
{
    if(!enterNotPressed)
    {
        if(val==1)
           {
            bstobj.insertElement(bstobj.tree,num);
            cout<<num<<" INSERTED"<<endl;
            drawobj.newNode();
            }
        if(val==5)
            {bstobj.searchElement(bstobj.tree,num);
            cout<<"SEARCH COMPLETED"<<endl;
            drawobj.searchedNode();
            }
        resetKeyPressed();
        keyboardobj.closeKeyboard();
        cout<<"KEYBOARD CLOSED"<<endl;
    }
    enterNotPressed=true;
    inputKeyboardVal=false;
}

void keyboard(unsigned char key, int x,int y)
{   if(inputKeyboardVal)
    {
        if(key>='0'&&key<='9')
               {/*glColor3f(0,0,0);
                glRasterPos2i(keyX,keyY);
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,key);
                keyX+=18;*/
                keyPressed[i]=key;
                i++;
                glutPostRedisplay();
                //glFlush();
                }

        if(key==8)//backspace delete all
               {//keyboardobj.displayKeyboard();
                resetKeyPressed();
                cout<<"backspace"<<endl;
                glutPostRedisplay();
                //keyX=-80;
                }
        if(key==10 ||key==13)//enter
            {  if(keyPressed[0]!='\0')
                {   num=atoi(keyPressed);
                    cout<<num<<endl;

                    //erase screen
                    keyX=-80;
                    enterNotPressed=false;
                    glutPostRedisplay();
                    cout<<"CALL UPDATE TREE"<<endl;
                    updateTree();
                    cout<<"TREE UPDATED"<<endl;
                }

            }
            glFlush();
    }
}

void goMenu(int menuVal)
{   val=menuVal;
    switch (menuVal)
    {
        case 1:inputKeyboardVal=true;
               keyboardobj.displayKeyboard();
               keyboardobj.displayInsert();

               break;
        case 2:
                bstobj.inorder(bstobj.tree);
                cout<<endl;
                break;
        case 3:
                bstobj.preorder(bstobj.tree);
                cout<<endl;
                break;
        case 4:
                bstobj.postorder(bstobj.tree);
                cout<<endl;
                break;
        case 5:
                inputKeyboardVal=true;
                keyboardobj.displayKeyboard();
                keyboardobj.displaySearch();
                break;
        case 6:
                exit(0);
                break;
    }
    glutPostRedisplay();

}

void menuDetails()
{
    glutCreateMenu(goMenu);

    int subMenuTraversal=glutCreateMenu(goMenu);

    glutAddMenuEntry("INORDER",2);
    glutAddMenuEntry("PREORDER",3);
    glutAddMenuEntry("POSTORDER",4);
    glutCreateMenu(goMenu);
    glutAddSubMenu("TRAVERSAL",subMenuTraversal);
    glutAddMenuEntry("INSERT",1);
    glutAddMenuEntry("SEARCH",5);
    glutAddMenuEntry("EXIT", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
/*void myTimer(int val)
{
    glutDisplayFunc(menuDetails);
    keyboard('*',keyX,keyY);
    glutPostRedisplay();
}*/

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(500,10);
    glutInitWindowSize(600,600);
    glutCreateWindow("bst");


    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    //glutTimerFunc(2000, myTimer,0);
    menuDetails();
    init();

    glutMainLoop();

}
void init()
{
    glClearColor(0.8,0.7,0.9,1);

}

void reshape(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-500,500,-500,500,-10,10);
    glMatrixMode(GL_MODELVIEW);

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    if(inputKeyboardVal)
    {keyboardobj.displayKeyboard();
    keyboardobj.displayInsert();
    }
    if(enterNotPressed)
    {   glColor3f(0,0,0);
        i=0;
        while(keyPressed[i]!='\0')
        {
            glRasterPos2i(keyX,keyY);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,keyPressed[i]);
            keyX+=18;
            i++;
        }

        keyX=-80;

    }

    glFlush();
    //glutKeyboardFunc(keyboard);
}
