#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<mmsystem.h>
#include<string>
#include<sstream>
#pragma comment(lib, "Winmm.lib")
using namespace std;

int screenWidth=1535,screenHeight=860, speed = 3000,number,level_dis = 1 ;
char op,eq[100];
int ans = 0;
ostringstream str1;

void game_start();

void splash_screen()
{

	initwindow(screenWidth, screenHeight, "",-3 , -3);
	rectangle(0, 0, screenWidth, screenHeight);
	floodfill(200,200,WHITE);
    //PlaySound("sound.wav", GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

	setbkcolor(WHITE);
	setcolor(RED);
	settextstyle(BOLD_FONT,HORIZ_DIR,7);

	outtextxy(470,330,"Fastest Finger's");
	outtextxy(655,420,"First");
	delay(2000);
	settextstyle(3,HORIZ_DIR,1);
	int i;
	char b[]="Press Enter key to continue";
    char d[100];
    char c;

    for(i=0;b[i]!='\0';i++)
    {
        d[i]=b[i];
        d[i+1]='\0';
        outtextxy(665,800, d);
        Sleep(50);
    }
    c=(char)getch();
    delay(100);
	cleardevice();
}
void environment1()
{

    cleardevice();
    setcolor(BLACK);
    setbkcolor(BLACK);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(1,1,BLACK);
    char s[10];
    settextstyle(BOLD_FONT , HORIZ_DIR, 9);
    setcolor(WHITE);
    sprintf(s,"Level %d",level_dis);
    outtextxy(560,50,s);
    settextstyle(6 , HORIZ_DIR , 8);
    setfillstyle(SOLID_FILL,WHITE);

    // x and y is a position and
    // radius is for radius of circle
    //circle(x_circle,y_circle,radius);

    // fill the color at location
    // (x, y) with in border color
    //floodfill(x_circle,y_circle,border_color);


    rectangle(600, 330, 720, 475);
    rectangle(610, 340, 710, 465);
    floodfill(601,331,WHITE);
    rectangle(780, 330, 900, 475);
    rectangle(790, 340, 890, 465);
    floodfill(781,331,WHITE);

}
void restart_game()
{
    char eq[100];
    speed = 3000;
    level_dis = 1;
    ans = 0;
    op = ' ';
    game_start();
}
void environment3()
{
   cleardevice();
   char a[100] = " ";
   strcat(a,eq);
   strcat(a," = " );
   char r[20];
   itoa(ans,r,10);
   strcat(a,r);
   settextstyle(BOLD_FONT,HORIZ_DIR,8);
   outtextxy(480,330,"Game End !!!");
   settextstyle(4,HORIZ_DIR,5);
   outtextxy(450,590,a);
   settextstyle(EUROPEAN_FONT,HORIZ_DIR,1);
   outtextxy(565, 800, "Press enter to play again or esc to exit");
   char c;
	int valid=0;
	while(valid==0)
	{
	    c=(char)getch();
        int a=(int)c;
        if(a == 27)
            valid=1;
        else if(a == 13)
            restart_game();
	}
}
int get_operator(int i)
{
    int opn;
    if (i == 1)
    {
        opn = rand() % ((3) - 2 + 1) + 2;
    }
    else if (i > 4)
    {
        opn = rand() % ((3) - 2 + 1) + 2;
    }
    else
        opn = rand() % ((4) - 2 + 1) + 2;
    switch(opn)
    {
        case 2 : op = '+';
                 break;
        case 3 : op = '-';
                 break;
        case 4 : op = '*';
                 break;
    }
    return op;

}
int get_number()
{
    int n;
    if (op == '*')
    {
         n = rand() % ((5) - 2 + 1) + 2;
    }
    else
        n = rand() % ((9) - 1 + 1) + 1;
    return n;
}
int level()
{
    int i,n;
    stringstream c;
    char m[10];
    char p[100] = " ";
    char s[10];
    char q[10];
    ans = 0;
    environment1();
    settextstyle(BOLD_FONT,HORIZ_DIR,5);
    for (int h = 1;h < 5;h++)
        {
            if (h == 4)
            {
                outtextxy(590,220,">>>>>Go!<<<<<");
            }
            else
            {
                sprintf(q,">>>>> %d <<<<<",h);
                outtextxy(590,220,q);
            }
            Sleep(1000);
        }

    for (i = 1;i < 7;i++)
    {
        environment1();
        settextstyle(BOLD_FONT,HORIZ_DIR,8);
        if (i != 0)
        {
            op = get_operator(i);
            sprintf(s,"%c",op);
            outtextxy(630,365,s);
        }
        else
                  outtextxy(630,365,"+");
        n = get_number();
        sprintf(s,"%d",n);
        outtextxy(820,365,s);
        if (i != 0)
        {
            switch(op)
            {
            case '+': ans = ans + n;
                      break;
            case '-': ans = ans - n;
                      break;
            case '*': ans = ans * n;
                      break;
            }

        }
        else
            ans = ans + n;
        strncat(p,&op,1);
        //cout<<m<<"\n";
        //string stri = to_string(n);

        char z[10];
        itoa(n,z,10);

        strcat(p,z);

        strcpy(eq,p);

        //eq=eq+op+m;
        //sprint(eq,"%c",op);
        //sprint(eq,"%d",n)
        settextstyle(8,HORIZ_DIR,6);
        sprintf(s,"Q.no %d",i);
        outtextxy(260,250,s);
        Sleep(speed);
        cleardevice();

    }
    return ans;
}
int input()
{
    char user[10],d[100],y;
    int j = 0;
    int z = 0;
    while(z==0)
        {
            user[j]=(char)getch();
            y=user[j];
            if((int)user[j]=='\b')
            {
                if(j!=0)
                {
                    user[j-1]='\0';
                    //puts(user);
                    sprintf(d,"%s  ",user);
                    outtextxy(960 ,355 ,d );
                    j--;
                }
            }
            else if ((int)user[j]==13)
            {
               z=1;
               user[j]='\0';
            }
            else
            {
                user[j+1]='\0';
                outtextxy(960 , 355, user);
                j++;
            }

        }
     int n = stoi(user);
     return n;
}
void environment2()
{
    settextstyle(6 , HORIZ_DIR,6);
    outtextxy(560,355,"Answer :- ");

}
void game_start()
{
    settextstyle(6,HORIZ_DIR,8);
    environment1();
    int ans = 0 ,user = 0;
    for (level_dis = 1 ; level_dis < 11 ; level_dis ++)
    {
        ans = level();
        environment2();
        user = input();

        if (ans == user)
        {
            settextstyle(6,HORIZ_DIR,4);
            outtextxy( 560,570,"Correct answer !!! :-)");
            speed = speed - 300;
            Sleep(4000);
        }
        else
        {
            settextstyle(6,HORIZ_DIR,4);
            outtextxy(560,570,"Wrong answer !!! :-(");
            Sleep(4000);
            environment3();
            break;
        }
    }
}
int main()
{
    srand(time(NULL));
    splash_screen();
    game_start();

}

