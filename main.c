#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
int ind=0;
int flag=0;
int p=3;
char page[10];
int n =10;
char s[20];
int count =0;
int counter = 0;
void dpage(int a)
{
	int x = a;
	int y = 600;
	int incr = 60;
	for(int i=0;i<p;i++)
	{
	    glColor3f(1,1,1);
        glBegin(GL_POLYGON);
            glVertex2i(x,y);
            x+=incr;
            glVertex2i(x,y);
            y-=incr;
            glVertex2i(x,y);
            x-=incr;
            glVertex2i(x,y);
        glEnd();

        glColor3f(0,0,0);
        glRasterPos2f(x+(incr/1.75), y+(incr/1.75)); //define position on the screen
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, page[i]);
        y-=10;
	}


}
void dstring()
{
	int x=60;int y=750;int incr=60;

	for(int i=0;i<n;i++)
	{
        glColor3f(0.9,0.4,0);
        glBegin(GL_POLYGON);
            glVertex2i(x,y);
            y-=incr;
            glVertex2i(x,y);
            x+=incr;
            glVertex2i(x,y);
            y+=incr;
            glVertex2i(x,y);
        glEnd();

        glColor3f(1,1,1);
        glRasterPos2f(x-(incr/1.75), y-(incr/1.75)); //define position on the screen
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);

        x+=40;
	}
}
void ptr(int a,int b)
{
    glColor3f(0,0.7,0);
	glBegin(GL_POLYGON);
		glVertex2i(a-30,b-10);
		glVertex2i(a-10,b-30);
		glVertex2i(a-30,b-50);
	glEnd();
}
void hitmiss()
{
	int x=100;int y= 200;int xincr=100;int yincr =40;int i=0; //hit
	glColor3f(0,0,0.2);
	glBegin(GL_POLYGON);
		glVertex2i(x,y);
		y-=yincr;
		glVertex2i(x,y);
		x+=xincr;
		glVertex2i(x,y);
		y+=yincr;
		glVertex2i(x,y);
		x-=xincr;
	glEnd();
	glColor3f(1,1,1);
	glRasterPos2f(x-(xincr/2), y-(yincr/2)-10); //define position on the screen
    char *string = "Hit: ";
    while(*string){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
      }

    char c[2];
    i = 0;
    sprintf(c, "%d", (n-count));
    glRasterPos2f(x+(xincr/2), y-(yincr/2)-10);
    while(i<2){
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);
    i++;
    }

	y = 140; //miss
	glColor3f(0,0,0.2);
	glBegin(GL_POLYGON);
		glVertex2i(x,y);
		y-=yincr;
		glVertex2i(x,y);
		x+=xincr;
		glVertex2i(x,y);
		y+=yincr;
		glVertex2i(x,y);
		x-=xincr;
	glEnd();
	glColor3f(1,1,1);
	glRasterPos2f(x-(xincr/2), y-(yincr/2)-10); //define position on the screen
    char *string1 = "Miss: ";
    while(*string1){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string1++);
      }
    char c1[2];
    i = 0;
    sprintf(c1, "%d", count);
    glRasterPos2f(x+(xincr/2), y-(yincr/2)-10);
    while(i<2){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c1[i]);
        i++;
    }

}
void head()
{
	int x=250;int y= 900;int xincr=500;int yincr =100; //hit
	glColor3f(0,0,0.2);
	glBegin(GL_POLYGON);
		glVertex2i(x,y);
		y-=yincr;
		glVertex2i(x,y);
		x+=xincr;
		glVertex2i(x,y);
		y+=yincr;
		glVertex2i(x,y);
		x-=xincr;
	glEnd();
	glColor3f (1.0, 0.0, 0.0);
    glRasterPos2f(350, 840); //define position on the screen
    char *string = "First In First Out - CG Project";

    while(*string){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
      }
}
void fifo()
{
    int a=60;int b=670;int incr = 60;
	for(int i=0;i<n;i++)
	{
		flag=0;
		for(int j=0;j<p;j++)
		{
			if(page[j]==s[i])
			{
			    //hit func
				flag=1;
				ptr(a,b);
				dpage(a);
				break;
			}
		}
		if(flag==0)
		{
			//miss func
			page[ind]=s[i];
			ind++;
			if(ind==p)
			{
				ind=0;
			}
			count++;
			b-=70;
            if(b<=600-(p*70))
            {
                    b=600;
            }
			ptr(a,b);
            dpage(a);
		}
		a+=100;
		glColor3f(0,0,0.2);

	}
	hitmiss();
	//miss
	printf("Miss: %d",count);
	printf("Hits: %d",(n-count));
	//hit
}
void display()
{
    if(counter==0)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        //dpage();
        dstring();
        //glColor3f(0,0.7,0);
        //ptr();
        fifo();
        //glColor3f(0,0,0.2);
        //hitmiss();
        head();
        glFlush();
        counter++;
    }
}
void myinit()
{
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0,999,0,999,0,5);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv)
{
	//input
	printf("page frame size(max. 4)");
	scanf("%d",&p);
	printf("string size (max. 9)");
	scanf("%d",&n);
	printf("enter string");
	for(int i = 0;i<p;i++)
	{
		page[i]=' ';
	}
	for(int i = 0;i<n;i++)
	{
		scanf("%s",&s[i]);
	}
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("FIFO");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
