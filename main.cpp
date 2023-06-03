#include<graphics.h>
#include <iostream>
#include <windows.h>
#include <MMsystem.h>
#include <dos.h>
#include <fstream>
#include <limits>


using namespace std;
void disp_page3();
void playhow();
void playgame();
void rules();
void skip();
void endgame();
int z=0;
int w=0;
int n=0;
fstream newfile;

fstream& GotoLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}

void intro_VRlogo()
{
    cleardevice();
    delay(1000);
     readimagefile("logo.jpeg",0,0,700,600);
   PlaySound(TEXT("music1.wav"),NULL,SND_SYNC);
   delay(1000);
   cleardevice();


   readimagefile("images.jpeg",0,0,700,600);
     settextstyle(8,0,6);
    setcolor(YELLOW);
    for(int i=0;i<=getmaxx()-600;i++)
    {
    cleardevice();
    outtextxy(i,100,"A Game by ");
    outtextxy(i,180,"Team 25");
    delay(10);
    }


delay(1000);
}


void page1()
{
    readimagefile("kbclogo2.jpeg",0,0,700,600);
    PlaySound(TEXT("kbcintrosong.wav"),NULL,SND_SYNC);
    settextstyle(9,0,2);
    setcolor(WHITE);
    outtextxy(200,520,"press any key to continue");
    getch();
}



void page2()
{
    delay(2000);
    cleardevice();
    readimagefile("stage.jpeg",0,0,700,600);
    delay(100);
    settextstyle(SMALL_FONT,0,9);
    outtextxy(250,250,"Loading.........");

    setcolor(GREEN);
    for(int i=0;i<699;i++)
    {
        circle(1+i,550,5);
        delay(1);
    }

    settextstyle(9,0,2);
    setcolor(WHITE);
    outtextxy(200,520,"press any key to continue");

    getch();

}

void disp_page3()
{
    cleardevice();

    readimagefile("stage.jpeg",0,0,700,600);
    setfillstyle(SOLID_FILL, BLUE);
    setcolor(WHITE);
    fillellipse(330, 100, 120, 80);
    setfillstyle(SOLID_FILL, BLUE);
    setcolor(WHITE);
    fillellipse(330, 280, 120, 80);
    setfillstyle(SOLID_FILL, BLUE);
    setcolor(WHITE);
    fillellipse(330, 460, 120, 80);
    settextstyle(SMALL_FONT,0,9);

    outtextxy(295,85,"Play");
    outtextxy(240,265,"How to Play");
    outtextxy(285,445,"Rules");

    int maxx, maxy;
    int x, y;

    maxx = getmaxx( );
     maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
   getmouseclick(WM_LBUTTONDOWN, x, y);

    if (x > 205 && y < 175 && x < 450 && y > 20 ){
        setfillstyle(SOLID_FILL, YELLOW);
        setcolor(WHITE);
        fillellipse(330, 100, 120, 80);
        outtextxy(295,85,"Play");
        PlaySound(TEXT("optionselect.wav"),NULL,SND_SYNC);
        cleardevice();
        playgame();
       }

       if (x > 205 && y < 360 && x < 450 && y > 200 ){
        setfillstyle(SOLID_FILL, YELLOW);
        setcolor(WHITE);
        fillellipse(330, 280, 120, 80);
        outtextxy(240,265,"How to Play");
        PlaySound(TEXT("optionselect.wav"),NULL,SND_SYNC);
        cleardevice();
        playhow();
       }

        if (x >205  && y < 540 && x < 455 && y > 382 ){
        setfillstyle(SOLID_FILL, YELLOW);
        setcolor(WHITE);
        fillellipse(330,458, 120, 80);
        outtextxy(285,445,"Rules");
        PlaySound(TEXT("optionselect.wav"),NULL,SND_SYNC);
        delay(300);
        cleardevice();
        rules();
       }
}



void playhow()
{
    cleardevice();
    readimagefile("images.jpeg",0,0,700,600);
    outtextxy(250,30,"How To Play");
    setcolor(LIGHTRED);
    settextstyle(3,0,3);
    outtextxy(20,150,"1.Questions will be displayed on the screen for which 4 options will be provided.");
    outtextxy(20,200,"2.You have to chose the correct option of the four within the time limit.");
    outtextxy(20,250,"3.Upon answering the question correctly, you will be awarded with prize money of ");
    outtextxy(40,270,"the question.");
    outtextxy(20,320,"4.Upon answering the question wrong, you will be  eliminated from the game with ");
    outtextxy(40,340," the prize money of the last question answered correctly");
    outtextxy(20,390,"5.Whenever stuck with a question, You can use the the 3 lifelines for once. ");
    outtextxy(20,450,"A. 50:50 = removes two wrong options");
    outtextxy(20,480,"B. Skip = skips onto next question");

    setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);

    fillellipse(38, 30, 40, 20);
    settextstyle(8,0,2);
    outtextxy(15,20,"Back");

    int maxx, maxy;
    int x, y;

    maxx = getmaxx( );
     maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

       if ( y < 50 && x < 75 ){
        cleardevice();
        disp_page3();
       }
}


void rules()
{
    cleardevice();

    readimagefile("images.jpeg",0,0,700,600);
    outtextxy(250,30,"Rules");

    setcolor(LIGHTRED);
    settextstyle(3,0,3);
    outtextxy(20,150,"1.You are not allowed to use any digital gadget during the gameplay.");
    outtextxy(20,200,"2.If time is up then you are automatically eliminated from the game.");
    outtextxy(20,225,"3.So it would be better to use your time wisely.");
    outtextxy(20,260,"4.If you want to see your level click on the top right button in the game.");
    outtextxy(20,290," the prize money will not be given in cash maybe not even digitally.");
    outtextxy(20,315," So play the game for time pass only :).");

     setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);

    fillellipse(38, 30, 40, 20);
    settextstyle(8,0,2);
    outtextxy(15,20,"Back");

    int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
     maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

       if ( y < 50 && x < 75 ){
        cleardevice();
        disp_page3();
       }


}

class Questions{

    public:
        void question1();
        void question2();
        void question3();
        void question4();
        void question5();
        void question6();
        void question7();
        void question8();
        void question9();
        void question10();
        void question11();
        void question12();
        void question13();
        void question14();
        void question15();
        void question16();

};

void Questions::question1()
{
    cleardevice();
    readimagefile("page4.jpeg",0,0,700,600);

    settextstyle(8,0,2);
    setfillstyle(SOLID_FILL,WHITE);
    bar(190,10,320,35);
    outtextxy(90,25,"You have won ");
    outtextxy(255,28,"0/- ");

    setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);
    fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");

    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");

    newfile.open("kbc.txt",ios::in);
    PlaySound(TEXT("kbcbeforequestion.wav"),NULL,SND_SYNC);
    settextstyle(9,0,2);

GotoLine(newfile,1);
    if (newfile.is_open()){

     string tp;
        getline(newfile,tp);
        settextstyle(9,0,3);
        int n = tp.length();
        char char_array[n + 1];
        strcpy(char_array, tp.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(360,290,char_array);

delay(3000);
settextstyle(9,0,2);

GotoLine(newfile,2);
        string tp1;
        getline(newfile,tp1);

        int n1 = tp1.length();
        char char_array1[n1 + 1];
        strcpy(char_array1, tp1.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(212,427,char_array1);
delay(800);

GotoLine(newfile,3);
        string tp2;
        getline(newfile,tp2);

        int n2 = tp2.length();
        char char_array2[n2 + 1];
        strcpy(char_array2, tp2.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(525,430,char_array2);
delay(800);

GotoLine(newfile,4);
        string tp3;
        getline(newfile,tp3);

        int n3 = tp3.length();
        char char_array3[n3 + 1];
        strcpy(char_array3, tp3.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(200,520,char_array3);
delay(800);

GotoLine(newfile,5);
        string tp4;
        getline(newfile,tp4);

        int n4 = tp4.length();
        char char_array4[n4 + 1];
        strcpy(char_array4, tp4.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(540,520,char_array4);

    int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
    maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

        //options
       if( x > 55 && x < 340 && y >390 && y <450){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(210,427,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(210,427,char_array1);
        PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"You have won 1000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q2;
        q2.question2();
        }

         if ( x > 410 && x < 650 && y >398 && y <455){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,650,450);
        floodfill(421,420,RED);
        outtextxy(525,430,char_array2);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(210,427,char_array1);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 85 && x < 325 && y >495 && y <542){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,520,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,495,325,542);
        floodfill(91,510,RED);
        outtextxy(200,520,char_array3);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(210,427,char_array1);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 410 && x < 648 && y >495 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(530,520,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,520,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(210,427,char_array1);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        //skip option
        if ( x > 497 && x < 580 && y >8 && y <50)
   {    z=1;
       setfillstyle(SOLID_FILL, YELLOW);
        setcolor(WHITE);
       fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
    delay(1000);
    setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(210,430,char_array1);
    PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
    Questions q21;
        q21.question2();

   }
   else if(z!=1)
    z=0;

   //50:50 option
   if(y < 30 && x < 670){
    w=1;
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
    delay(1000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(410,495,648,540);
    floodfill(421,510,BLACK);
    bar(85,495,325,542);
    floodfill(91,510,BLACK);

     int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
    maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

    if( x > 55 && x < 340 && y >390 && y <450){
            w=1;
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(210,427,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(210,427,char_array1);
        PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"You have won 1000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q22;
        q22.question2();
        }

        if ( x > 410 && x < 650 && y >398 && y <455){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,650,450);
        floodfill(421,420,RED);
        outtextxy(525,430,char_array2);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(210,427,char_array1);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");

        endgame();
        }
   }
       else if(w!=1)
        w=0;


}
getch();
}

void Questions::question2()
{
    cleardevice();
    readimagefile("page4.jpeg",0,0,700,600);
  setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);

    settextstyle(8,0,2);
setfillstyle(SOLID_FILL,WHITE);
    bar(190,10,320,35);
     outtextxy(90,25,"You have won ");
     outtextxy(255,28,"1000/-");

if(z<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
     fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
}
if(w<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
}
    PlaySound(TEXT("kbcbeforequestion.wav"),NULL,SND_SYNC);
    settextstyle(9,0,2);

GotoLine(newfile,7);
    if (newfile.is_open()){
        string tp;
        getline(newfile,tp);
        settextstyle(9,0,3);
        int n = tp.length();
        char char_array[n + 1];
        strcpy(char_array, tp.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(370,297,char_array);
        delay(3000);

        settextstyle(9,0,2);
GotoLine(newfile,8);
        string tp1;
        getline(newfile,tp1);
        int n1 = tp1.length();
        char char_array1[n1 + 1];
        strcpy(char_array1, tp1.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(200,430,char_array1);
delay(800);

GotoLine(newfile,9);
        string tp2;
        getline(newfile,tp2);
        int n2 = tp2.length();
        char char_array2[n2 + 1];
        strcpy(char_array2, tp2.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(530,430,char_array2);
delay(800);

GotoLine(newfile,10);
        string tp3;
        getline(newfile,tp3);
        int n3 = tp3.length();
        char char_array3[n3 + 1];
        strcpy(char_array3, tp3.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(200,518,char_array3);
delay(800);

GotoLine(newfile,11);
        string tp4;
        getline(newfile,tp4);
        int n4 = tp4.length();
        char char_array4[n4 + 1];
        strcpy(char_array4, tp4.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(525,518,char_array4);

      int maxx, maxy;
        int x, y;
        maxx = getmaxx( );
         maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

    //options
       if ( x > 55 && x < 340 && y >390 && y <450){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,400,335,450);
        floodfill(96,420,RED);
        outtextxy(200,430,char_array1);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
       bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,650,450);
        floodfill(421,420,RED);
        outtextxy(525,430,char_array2);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,495,325,542);
        floodfill(91,510,RED);
        outtextxy(200,518,char_array3);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
       PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"You have won 2000 rs!");
        delay(1500);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
         Questions q3;
        q3.question3();

        }

        //skip option
        if ( x > 497 && x < 580 && y >8 && y <50 && z<1)
   {
       setfillstyle(SOLID_FILL, YELLOW);
        setcolor(WHITE);
       fillellipse(540,30,40,20);
        settextstyle(8,0,2);
        outtextxy(540,35,"Skip");
        delay(1000);
        setfillstyle(SOLID_FILL,GREEN);
         bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
    PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
    Questions q31;
        q31.question3();

   }
   else if(z!=1)
    z=0;

   //50:50 option
   if(y < 30 && x < 670){
    w=1;
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
    delay(1000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(85,400,335,450);
    floodfill(96,420,BLACK);
    bar(85,495,325,542);
    floodfill(91,510,BLACK);

    int maxx, maxy;
        int x, y;
        maxx = getmaxx( );
         maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

     if ( x > 420 && x < 640 && y >500 && y <535){
            w=1;
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
       PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 2000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
         Questions q32;
        q32.question3();
        }
         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
       bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,650,450);
        floodfill(421,420,RED);
        outtextxy(525,430,char_array2);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }
   }
       else if(w!=1)
        w=0;
}
getch();
}

void Questions::question3()
{
    cleardevice();
    readimagefile("page4.jpeg",0,0,700,600);

    settextstyle(8,0,2);
    setfillstyle(SOLID_FILL,WHITE);
    bar(190,10,320,35);
    outtextxy(90,25,"You have won ");
    outtextxy(255,28,"2000/-");

    if(z<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);
    fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
    }

    if(w<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
}

    PlaySound(TEXT("kbcbeforequestion.wav"),NULL,SND_SYNC);
    settextstyle(9,0,2);

GotoLine(newfile,13);
    if (newfile.is_open()){
    string tp;
    getline(newfile,tp);
    settextstyle(9,0,3);
    int n = tp.length();
    char char_array[n + 1];
    strcpy(char_array, tp.c_str());
    for (int i = 0; i < 1; i++)
    outtextxy(380,290,char_array);
delay(3000);
settextstyle(9,0,2);

GotoLine(newfile,14);
        string tp1;
        getline(newfile,tp1);
        int n1 = tp1.length();
        char char_array1[n1 + 1];
        strcpy(char_array1, tp1.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(200,430,char_array1);
delay(800);
GotoLine(newfile,15);
        string tp2;
        getline(newfile,tp2);
        int n2 = tp2.length();
        char char_array2[n2 + 1];
        strcpy(char_array2, tp2.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(525,430,char_array2);
delay(800);
GotoLine(newfile,15);
        string tp3;
        getline(newfile,tp3);
        int n3 = tp3.length();
        char char_array3[n3 + 1];
        strcpy(char_array3, tp3.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(200,518,char_array3);
delay(800);
GotoLine(newfile,16);
        string tp4;
        getline(newfile,tp4);
        int n4 = tp4.length();
        char char_array4[n4 + 1];
        strcpy(char_array4, tp4.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(525,518,char_array4);

      int maxx, maxy;
        int x, y;
        maxx = getmaxx( );
         maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);
//option1
       if ( x > 55 && x < 340 && y >390 && y <450){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"You have won 5000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q4;
        q4.question4();
        }
//option2
         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,650,450);
        floodfill(421,420,RED);
        outtextxy(525,430,char_array2);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }
//option3
        if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,495,325,542);
        floodfill(91,510,RED);
        outtextxy(200,518,char_array3);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }
//option4
        if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }
//skip option
          if ( x > 497 && x < 580 && y >8 && y <50 && z<1)
   {
       setfillstyle(SOLID_FILL, YELLOW);
       setcolor(WHITE);
       fillellipse(540,30,40,20);
       settextstyle(9,0,2);
       outtextxy(540,35,"Skip");
       delay(1000);
       setfillstyle(SOLID_FILL,GREEN);
       bar(85,400,335,450);
       floodfill(96,420,GREEN);
       outtextxy(200,430,char_array1);
       PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
       Questions q41;
       q41.question4();
   }

    else if(z!=1)
        z=0;

    //50:50 option
   if(y < 30 && x < 670){
    w=1;
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
    delay(1000);
    setfillstyle(SOLID_FILL,BLACK);
   bar(85,495,325,542);
    floodfill(86,510,BLACK);
   bar(410,400,650,450);
    floodfill(411,420,BLACK);

    int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
    maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

     if ( x > 55 && x < 340 && y >390 && y <450){
         w=1;
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"You have won 5000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q42;
        q42.question4();
        }
         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
       bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,650,450);
        floodfill(421,420,RED);
        outtextxy(525,430,char_array2);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }
   }
    else if(w!=1)
        w=0;
}

getch();
}


void Questions::question4()
{
     cleardevice();
    readimagefile("page4.jpeg",0,0,700,600);
  setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);

    settextstyle(8,0,2);
    setfillstyle(SOLID_FILL,WHITE);
    bar(190,10,320,35);
    outtextxy(90,25,"You have won ");
    outtextxy(255,28,"5000/- ");

    if(z<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
     fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
}

    if(w<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
}

    PlaySound(TEXT("kbcbeforequestion.wav"),NULL,SND_SYNC);
    settextstyle(9,0,2);
    GotoLine(newfile,19);
    if (newfile.is_open()){

     string tp;
    getline(newfile,tp);
    settextstyle(9,0,3);
        int n = tp.length();
        char char_array[n + 1];
        strcpy(char_array, tp.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(370,290,char_array);

        delay(3000);

        settextstyle(9,0,2);
        GotoLine(newfile,20);
        string tp1;
     getline(newfile,tp1);

      int n1 = tp1.length();
      char char_array1[n1 + 1];
      strcpy(char_array1, tp1.c_str());
      for (int i = 0; i < 1; i++)
    outtextxy(200,430,char_array1);
    delay(800);

    GotoLine(newfile,21);
    string tp2;
     getline(newfile,tp2);
        int n2 = tp2.length();
        char char_array2[n2 + 1];
        strcpy(char_array2, tp2.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(525,430,char_array2);
delay(800);

        GotoLine(newfile,22);
        string tp3;
        getline(newfile,tp3);
        int n3 = tp3.length();
        char char_array3[n3 + 1];
        strcpy(char_array3, tp3.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(200,518,char_array3);
delay(800);

        GotoLine(newfile,23);
        string tp4;
        getline(newfile,tp4);
        int n4 = tp4.length();
        char char_array4[n4 + 1];
        strcpy(char_array4, tp4.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(525,518,char_array4);

      int maxx, maxy;
        int x, y;
        maxx = getmaxx( );
         maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);
//option1
       if ( x > 55 && x < 340 && y >390 && y <450){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,400,335,450);
        floodfill(96,420,RED);
        outtextxy(200,430,char_array1);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }
//option2
         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"You have won 10000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q5;
        q5.question5();
        }
//option3
        if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,495,325,542);
        floodfill(91,510,RED);
        outtextxy(200,518,char_array3);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }
//option4
        if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }
//skip option
  if ( x > 497 && x < 580 && y >8 && y <50 && z<1)
   {
       z=1;
       setfillstyle(SOLID_FILL, YELLOW);
       setcolor(WHITE);
       fillellipse(540,30,40,20);
       settextstyle(8,0,2);
       outtextxy(540,35,"Skip");
       delay(1000);
       setfillstyle(SOLID_FILL,GREEN);
       bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
       PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
       Questions q51;
       q51.question5();
   }

   else if(z!=1)
    z=0;

   //50:50 option
   if(y < 30 && x < 670){
    w=1;
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
    delay(1000);
    setfillstyle(SOLID_FILL,BLACK);
   bar(85,400,335,450);
    floodfill(86,420,BLACK);
   bar(410,495,648,540);
    floodfill(411,510,BLACK);

    int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
    maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

      if ( x > 420 && x < 640 && y >410 && y <435){
            w=1;
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"You have won 10000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q52;
        q52.question5();
        }
         if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }
   }
   else if(w!=1)
    w=0;
}
getch();
}

void Questions::question5()
{
    cleardevice();
    readimagefile("page4.jpeg",0,0,700,600);
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);

    settextstyle(8,0,2);
    setfillstyle(SOLID_FILL,WHITE);
    bar(190,10,320,35);
    outtextxy(90,25,"You have won ");
    outtextxy(255,28,"10000/- ");

    if(z<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
}

if(w<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
}
    PlaySound(TEXT("kbcbeforequestion.wav"),NULL,SND_SYNC);
    settextstyle(9,0,2);
    GotoLine(newfile,25);
    if (newfile.is_open()){

     string tp;
    getline(newfile,tp);
    settextstyle(9,0,3);
    int n = tp.length();
    char char_array[n + 1];
    strcpy(char_array, tp.c_str());
    for (int i = 0; i < 1; i++)
    outtextxy(365,290,char_array);
        delay(3000);

    settextstyle(9,0,2);
    GotoLine(newfile,26);
    string tp1;
    getline(newfile,tp1);
    int n1 = tp1.length();
    char char_array1[n1 + 1];
    strcpy(char_array1, tp1.c_str());
    for (int i = 0; i < 1; i++)
    outtextxy(200,430,char_array1);
delay(800);

    GotoLine(newfile,27);
    string tp2;
     getline(newfile,tp2);
    int n2 = tp2.length();
    char char_array2[n2 + 1];
    strcpy(char_array2, tp2.c_str());
    for (int i = 0; i < 1; i++)
    outtextxy(525,430,char_array2);
delay(800);

    GotoLine(newfile,28);
    string tp3;
    getline(newfile,tp3);
    int n3 = tp3.length();
    char char_array3[n3 + 1];
    strcpy(char_array3, tp3.c_str());
    for (int i = 0; i < 1; i++)
    outtextxy(200,518,char_array3);
delay(800);

    GotoLine(newfile,29);
    string tp4;
    getline(newfile,tp4);
    int n4 = tp4.length();
    char char_array4[n4 + 1];
    strcpy(char_array4, tp4.c_str());
    for (int i = 0; i < 1; i++)
    outtextxy(525,518,char_array4);

        int maxx, maxy;
        int x, y;
        maxx = getmaxx( );
        maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

       if ( x > 55 && x < 340 && y >390 && y <450){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,400,335,450);
        floodfill(96,420,RED);
        outtextxy(200,430,char_array1);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
         PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"You have won 20000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q6;
        q6.question6();
        }

        if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,495,325,542);
        floodfill(91,510,RED);
        outtextxy(200,518,char_array3);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

//skip option
        if ( x > 497 && x < 580 && y >8 && y <50)
   {    z=1;
       setfillstyle(SOLID_FILL, YELLOW);
        setcolor(WHITE);
       fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
    delay(1000);
    setfillstyle(SOLID_FILL,GREEN);
    bar(410,400,650,450);
    floodfill(421,420,GREEN);
    outtextxy(525,430,char_array2);
    PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
    Questions q61;
        q61.question6();

   }
   else if(z!=1)
    z=0;

   //50:50 option
   if(y < 30 && x < 670){
    w=1;
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
    delay(1000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(410,495,648,540);
    floodfill(421,510,BLACK);
    bar(85,495,325,542);
    floodfill(91,510,BLACK);

     int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
    maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

           if ( x > 55 && x < 340 && y >390 && y <450){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,400,335,450);
        floodfill(96,420,RED);
        outtextxy(200,430,char_array1);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
         PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"You have won 20000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q62;
        q62.question6();
        }
   }
      else if(w!=1)
      w=0;
}

getch();
}


void Questions::question6()
{
     cleardevice();
    readimagefile("page4.jpeg",0,0,700,600);
  setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);

    settextstyle(8,0,2);
setfillstyle(SOLID_FILL,WHITE);
    bar(190,10,320,35);
     outtextxy(90,25,"You have won ");
     outtextxy(255,28,"20000/-");

if(z<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
     fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
}
if(w<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
}

    PlaySound(TEXT("kbcbeforequestion.wav"),NULL,SND_SYNC);
    settextstyle(9,0,2);
    GotoLine(newfile,31);
    if (newfile.is_open()){

     string tp;
    getline(newfile,tp);
    settextstyle(9,0,3);
        int n = tp.length();
        char char_array[n + 1];
        strcpy(char_array, tp.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(360,290,char_array);

        delay(3000);
        settextstyle(9,0,2);

GotoLine(newfile,32);
        string tp1;
        getline(newfile,tp1);
        int n1 = tp1.length();
        char char_array1[n1 + 1];
        strcpy(char_array1, tp1.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(200,430,char_array1);
    delay(800);

GotoLine(newfile,33);
        string tp2;
        getline(newfile,tp2);
        int n2 = tp2.length();
        char char_array2[n2 + 1];
        strcpy(char_array2, tp2.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(525,430,char_array2);
     delay(800);

GotoLine(newfile,34);
        string tp3;
        getline(newfile,tp3);
        int n3 = tp3.length();
        char char_array3[n3 + 1];
        strcpy(char_array3, tp3.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(200,518,char_array3);
         delay(800);

GotoLine(newfile,35);
        string tp4;
        getline(newfile,tp4);
        int n4 = tp4.length();
        char char_array4[n4 + 1];
        strcpy(char_array4, tp4.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(525,518,char_array4);

      int maxx, maxy;
        int x, y;
        maxx = getmaxx( );
         maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

       if ( x > 55 && x < 340 && y >390 && y <450){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"You have won 40000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q7;
        q7.question7();
        }

         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,650,450);
        floodfill(421,420,RED);
        outtextxy(525,430,char_array2);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,495,325,542);
        floodfill(91,510,RED);
        outtextxy(200,518,char_array3);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

//skip option
        if ( x > 497 && x < 580 && y >8 && y <50)
   {    z=1;
    setfillstyle(SOLID_FILL, YELLOW);
    setcolor(WHITE);
    fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
    delay(1000);
    setfillstyle(SOLID_FILL,GREEN);
    bar(85,400,335,450);
    floodfill(96,420,GREEN);
    outtextxy(210,430,char_array1);
    PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
    Questions q71;
    q71.question7();

   }
   else if(z!=1)
    z=0;

   //50:50 option
   if(y < 30 && x < 670){
    w=1;
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
    delay(1000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(410,495,648,540);
    floodfill(421,510,BLACK);
    bar(85,495,325,542);
    floodfill(91,510,BLACK);

     int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
    maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

    if( x > 55 && x < 340 && y >390 && y <450){
        w=1;
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(210,427,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(210,427,char_array1);
        PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"You have won 40000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q72;
        q72.question7();
        }

        if ( x > 410 && x < 650 && y >398 && y <455){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,650,450);
        floodfill(421,420,RED);
        outtextxy(525,430,char_array2);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }
   }
       else if(w!=1)
        w=0;
}

getch();
}


void Questions::question7()
{
     cleardevice();
    readimagefile("page4.jpeg",0,0,700,600);
  setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);

    settextstyle(8,0,2);
setfillstyle(SOLID_FILL,WHITE);
    bar(190,10,320,35);
     outtextxy(90,25,"You have won ");
     outtextxy(255,28,"40000/-");

if(z<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
     fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
}
if(w<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
}
    PlaySound(TEXT("kbcbeforequestion.wav"),NULL,SND_SYNC);
    settextstyle(9,0,2);
    GotoLine(newfile,37);
    if (newfile.is_open()){

     string tp;
    getline(newfile,tp);
    settextstyle(9,0,3);
    int n = tp.length();
    char char_array[n + 1];
    strcpy(char_array, tp.c_str());
    for (int i = 0; i < 1; i++)
    outtextxy(390,290,char_array);

        delay(3000);
        settextstyle(9,0,2);

GotoLine(newfile,38);
        string tp1;
        getline(newfile,tp1);
        int n1 = tp1.length();
        char char_array1[n1 + 1];
        strcpy(char_array1, tp1.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(200,430,char_array1);
    delay(800);


GotoLine(newfile,39);
        string tp2;
        getline(newfile,tp2);
        int n2 = tp2.length();
        char char_array2[n2 + 1];
        strcpy(char_array2, tp2.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(528,430,char_array2);
    delay(800);

GotoLine(newfile,40);
        string tp3;
        getline(newfile,tp3);
        int n3 = tp3.length();
        char char_array3[n3 + 1];
        strcpy(char_array3, tp3.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(200,518,char_array3);
         delay(800);

GotoLine(newfile,41);
        string tp4;
        getline(newfile,tp4);
        int n4 = tp4.length();
        char char_array4[n4 + 1];
        strcpy(char_array4, tp4.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(525,518,char_array4);

      int maxx, maxy;
        int x, y;
        maxx = getmaxx( );
         maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

       if ( x > 55 && x < 340 && y >390 && y <450){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
       bar(85,400,335,450);
        floodfill(96,420,RED);
        outtextxy(200,430,char_array1);
        setfillstyle(SOLID_FILL,GREEN);
         bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
         PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
       PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(330,150,"You have won 80000 rs!");
        delay(1000);
        outtextxy(330,150,"Your next question on your screen..");
        delay(1000);
         Questions q8;
        q8.question8();
        }

        if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,495,325,542);
        floodfill(91,510,RED);
        outtextxy(200,518,char_array3);
        setfillstyle(SOLID_FILL,GREEN);
         bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,150,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
       bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
       bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
         bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,150,"Sorry, You are eliminated :(");
        endgame();
        }
//skip option
        if ( x > 497 && x < 580 && y >8 && y <50)
   {    z=1;
       setfillstyle(SOLID_FILL, YELLOW);
        setcolor(WHITE);
       fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
    delay(1000);
    setfillstyle(SOLID_FILL,GREEN);
       bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
    PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
    Questions q81;
        q81.question8();

   }
   else if(z!=1)
    z=0;

   //50:50 option
   if(y < 30 && x < 670){
    w=1;
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
    delay(1000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(410,495,648,540);
    floodfill(421,510,BLACK);
    bar(85,495,325,542);
    floodfill(91,510,BLACK);

     int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
    maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

    if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(330,150,"You have won 80000 rs!");
        delay(1000);
        outtextxy(330,150,"Your next question on your screen..");
        delay(1000);
        Questions q82;
        q82.question8();
        }

       if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
       bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
       bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
         bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,150,"Sorry, You are eliminated :(");
        endgame();
        }
   }
       else if(w!=1)
    w=0;
}

getch();
}

void Questions::question8()
{
      cleardevice();
    readimagefile("page4.jpeg",0,0,700,600);
  setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);

    settextstyle(8,0,2);
setfillstyle(SOLID_FILL,WHITE);
    bar(190,10,320,35);
     outtextxy(90,25,"You have won ");
     outtextxy(255,28,"80000/-");

if(z<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
     fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
}
if(w<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
}

    PlaySound(TEXT("kbcbeforequestion.wav"),NULL,SND_SYNC);
    settextstyle(9,0,2);

    GotoLine(newfile,43);
    if (newfile.is_open()){
    string tp;
    getline(newfile,tp);
    settextstyle(9,0,3);
    int n = tp.length();
    char char_array[n + 1];
    strcpy(char_array, tp.c_str());
    for (int i = 0; i < 1; i++)
    outtextxy(380,290,char_array);

        delay(3000);
        settextstyle(9,0,2);

GotoLine(newfile,44);
        string tp1;
        getline(newfile,tp1);
        int n1 = tp1.length();
        char char_array1[n1 + 1];
        strcpy(char_array1, tp1.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(200,430,char_array1);
    delay(800);

GotoLine(newfile,45);
        string tp2;
        getline(newfile,tp2);
        int n2 = tp2.length();
        char char_array2[n2 + 1];
        strcpy(char_array2, tp2.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(525,430,char_array2);
    delay(800);

GotoLine(newfile,46);
        string tp3;
        getline(newfile,tp3);
        int n3 = tp3.length();
        char char_array3[n3 + 1];
        strcpy(char_array3, tp3.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(210,518,char_array3);
        delay(800);

GotoLine(newfile,47);
        string tp4;
        getline(newfile,tp4);
        int n4 = tp4.length();
        char char_array4[n4 + 1];
        strcpy(char_array4, tp4.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(525,518,char_array4);


        int maxx, maxy;
        int x, y;
        maxx = getmaxx( );
        maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

       if ( x > 55 && x < 340 && y >390 && y <450){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,400,335,450);
        floodfill(96,420,RED);
        outtextxy(200,430,char_array1);
        setfillstyle(SOLID_FILL,GREEN);
         bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,650,450);
        floodfill(421,420,RED);
        outtextxy(525,430,char_array2);
        setfillstyle(SOLID_FILL,GREEN);
         bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 90 && x < 320 && y >500 && y <540){
            settextstyle(8,0,2);
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
       bar(85,495,325,542);
        floodfill(91,510,RED);
        outtextxy(200,518,char_array3);
        setfillstyle(SOLID_FILL,GREEN);
         bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
       PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 160000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q9;
        q9.question9();
        }

        //skip option
        if ( x > 497 && x < 580 && y >8 && y <50)
   {    z=1;
        setfillstyle(SOLID_FILL, YELLOW);
        setcolor(WHITE);
        fillellipse(540,30,40,20);
        settextstyle(8,0,2);
        outtextxy(540,35,"Skip");
        delay(1000);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
    PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
    Questions q91;
        q91.question9();

   }
   else if(z!=1)
    z=0;

   //50:50 option
   if(y < 30 && x < 670){
    w=1;
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
    delay(1000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(85,400,335,450);
    floodfill(86,420,BLACK);
    bar(85,495,325,542);
    floodfill(86,510,BLACK);

     int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
    maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

    if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,650,450);
        floodfill(421,420,RED);
        outtextxy(525,430,char_array2);
        setfillstyle(SOLID_FILL,GREEN);
         bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }


       if ( x > 420 && x < 640 && y >500 && y <535){
            w=1;
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
       PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 160000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
       Questions q92;
        q92.question9();
        }
   }
       else if(w!=1)
        w=0;

}

getch();
}




void Questions::question9()
{
      cleardevice();
    readimagefile("page4.jpeg",0,0,700,600);
  setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);

    settextstyle(8,0,2);
setfillstyle(SOLID_FILL,WHITE);
    bar(190,10,320,35);
     outtextxy(90,25,"You have won ");
     outtextxy(255,28,"160000/-");

if(z<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
     fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
}
if(w<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
}

    PlaySound(TEXT("kbcbeforequestion.wav"),NULL,SND_SYNC);
    settextstyle(9,0,2);

GotoLine(newfile,49);
    if (newfile.is_open()){
    string tp;
    getline(newfile,tp);
    settextstyle(9,0,2);
    int n = tp.length();
    char char_array[n + 1];
    strcpy(char_array, tp.c_str());
    for (int i = 0; i < 1; i++)
    outtextxy(380,290,char_array);

        delay(3000);
        settextstyle(9,0,2);

GotoLine(newfile,50);
        string tp1;
        getline(newfile,tp1);
        int n1 = tp1.length();
        char char_array1[n1 + 1];
        strcpy(char_array1, tp1.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(200,430,char_array1);
    delay(800);

GotoLine(newfile,51);
        string tp2;
        getline(newfile,tp2);
        int n2 = tp2.length();
        char char_array2[n2 + 1];
        strcpy(char_array2, tp2.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(525,430,char_array2);
    delay(800);

GotoLine(newfile,52);
        string tp3;
        getline(newfile,tp3);
        int n3 = tp3.length();
        char char_array3[n3 + 1];
        strcpy(char_array3, tp3.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(200,518,char_array3);
        delay(800);

GotoLine(newfile,53);
        string tp4;
        getline(newfile,tp4);
        int n4 = tp4.length();
        char char_array4[n4 + 1];
        strcpy(char_array4, tp4.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(525,518,char_array4);
        delay(800);

        int maxx, maxy;
        int x, y;
        maxx = getmaxx( );
        maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

       if ( x > 55 && x < 340 && y >390 && y <450){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,400,335,450);
        floodfill(96,420,RED);
        outtextxy(200,430,char_array1);
        setfillstyle(SOLID_FILL,GREEN);
         bar(85,495,325,542);
        floodfill(91,510,GREEN);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,650,450);
        floodfill(421,420,RED);
        outtextxy(525,430,char_array2);
        setfillstyle(SOLID_FILL,GREEN);
         bar(85,495,325,542);
        floodfill(91,510,GREEN);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,495,325,542);
        floodfill(91,510,GREEN);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 320000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q10;
        q10.question10();
        }

        if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
         bar(85,495,325,542);
        floodfill(91,510,GREEN);
        outtextxy(200,518,char_array3);
       PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        //skip option
        if ( x > 497 && x < 580 && y >8 && y <50)
   {    z=1;
    setfillstyle(SOLID_FILL, YELLOW);
    setcolor(WHITE);
    fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
    delay(1000);
    setfillstyle(SOLID_FILL,GREEN);
    bar(85,495,325,542);
    floodfill(91,510,GREEN);
    outtextxy(200,518,char_array3);
    PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
    Questions q101;
        q101.question10();

   }
   else if(z!=1)
    z=0;

   //50:50 option
   if(y < 30 && x < 670){
    w=1;
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
    delay(1000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(85,400,335,450);
    floodfill(86,420,BLACK);
    bar(410,400,650,450);
    floodfill(411,420,BLACK);

     int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
    maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

    if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,495,325,542);
        floodfill(91,510,GREEN);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 320000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q102;
        q102.question10();
        }

        if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
         bar(85,495,325,542);
        floodfill(91,510,GREEN);
        outtextxy(200,518,char_array3);
       PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }
   }
       else if(w!=1)
        w=0;

}

getch();
}


void Questions::question10()
{
    cleardevice();
    readimagefile("page4.jpeg",0,0,700,600);
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);

   settextstyle(8,0,2);
setfillstyle(SOLID_FILL,WHITE);
    bar(190,10,320,35);
     outtextxy(90,25,"You have won ");
     outtextxy(255,28,"320000/-");

if(z<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
     fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
}
if(w<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
}

    PlaySound(TEXT("kbcbeforequestion.wav"),NULL,SND_SYNC);
    settextstyle(9,0,2);

    GotoLine(newfile,55);
    if (newfile.is_open()){
    string tp;
    getline(newfile,tp);
    settextstyle(9,0,3);
    int n = tp.length();
    char char_array[n + 1];
    strcpy(char_array, tp.c_str());
    for (int i = 0; i < 1; i++)
    outtextxy(380,290,char_array);

        delay(3000);
        settextstyle(9,0,2);

GotoLine(newfile,56);
    string tp1;
    getline(newfile,tp1);
    int n1 = tp1.length();
    char char_array1[n1 + 1];
    strcpy(char_array1, tp1.c_str());
    for (int i = 0; i < 1; i++)
    outtextxy(200,430,char_array1);
    delay(800);

    GotoLine(newfile,57);
    string tp2;
    getline(newfile,tp2);
    int n2 = tp2.length();
    char char_array2[n2 + 1];
    strcpy(char_array2, tp2.c_str());
    for (int i = 0; i < 1; i++)
    outtextxy(525,430,char_array2);
delay(800);

GotoLine(newfile,58);
        string tp3;
        getline(newfile,tp3);
        int n3 = tp3.length();
        char char_array3[n3 + 1];
        strcpy(char_array3, tp3.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(200,518,char_array3);
        delay(800);

GotoLine(newfile,59);
        string tp4;
        getline(newfile,tp4);
        int n4 = tp4.length();
        char char_array4[n4 + 1];
        strcpy(char_array4, tp4.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(540,518,char_array4);

      int maxx, maxy;
      int x, y;
      maxx = getmaxx( );
      maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

       if ( x > 55 && x < 340 && y >390 && y <450){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,400,335,450);
        floodfill(96,420,RED);
        outtextxy(200,430,char_array1);
        setfillstyle(SOLID_FILL,GREEN);
         bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,650,450);
        floodfill(421,420,RED);
        outtextxy(525,430,char_array2);
        setfillstyle(SOLID_FILL,GREEN);
         bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,495,325,542);
        floodfill(91,510,RED);
        outtextxy(200,518,char_array3);
        setfillstyle(SOLID_FILL,GREEN);
         bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
         PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
       bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
      PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 640000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q11;
        q11.question11();
        }

         //skip option
        if ( x > 497 && x < 580 && y >8 && y <50)
   {    z=1;
    setfillstyle(SOLID_FILL, YELLOW);
    setcolor(WHITE);
    fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
    delay(1000);
    setfillstyle(SOLID_FILL,GREEN);
    bar(410,495,648,540);
    floodfill(421,510,GREEN);
    outtextxy(525,518,char_array4);
    PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
    Questions q111;
        q111.question11();

   }
   else if(z!=1)
    z=0;

   //50:50 option
   if(y < 30 && x < 670){
    w=1;
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
    delay(1000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(85,400,335,450);
    floodfill(86,420,BLACK);
    bar(410,400,650,450);
    floodfill(411,420,BLACK);

     int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
    maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

    if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,495,325,542);
        floodfill(91,510,RED);
        outtextxy(200,518,char_array3);
        setfillstyle(SOLID_FILL,GREEN);
         bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
         PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

         if ( x > 420 && x < 640 && y >500 && y <535){
                w=1;
        setfillstyle(SOLID_FILL,YELLOW);
       bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
      PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 640000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q112;
        q112.question11();
        }
   }
       else if(w!=1)
        w=0;


}

getch();
}


void Questions::question11()
{
    cleardevice();
    readimagefile("page4.jpeg",0,0,700,600);
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);

   settextstyle(8,0,2);
   setfillstyle(SOLID_FILL,WHITE);
   bar(190,10,320,35);
   outtextxy(90,25,"You have won ");
   outtextxy(255,28,"640000/-");

if(z<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
     fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
}
if(w<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
}


    PlaySound(TEXT("kbcbeforequestion.wav"),NULL,SND_SYNC);
    settextstyle(9,0,2);

GotoLine(newfile,61);
    if (newfile.is_open()){
    string tp;
    getline(newfile,tp);
    settextstyle(9,0,2);
    int n = tp.length();
    char char_array[n + 1];
    strcpy(char_array, tp.c_str());
    for (int i = 0; i < 1; i++)
    outtextxy(380,290,char_array);

        delay(3000);
        settextstyle(9,0,2);

GotoLine(newfile,62);
        string tp1;
        getline(newfile,tp1);
        int n1 = tp1.length();
        char char_array1[n1 + 1];
        strcpy(char_array1, tp1.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(200,430,char_array1);
    delay(800);

GotoLine(newfile,63);
        string tp2;
        getline(newfile,tp2);
        int n2 = tp2.length();
        char char_array2[n2 + 1];
        strcpy(char_array2, tp2.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(528,430,char_array2);
    delay(800);

GotoLine(newfile,64);
        string tp3;
        getline(newfile,tp3);
        int n3 = tp3.length();
        char char_array3[n3 + 1];
        strcpy(char_array3, tp3.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(200,518,char_array3);
        delay(800);

GotoLine(newfile,65);
        string tp4;
        getline(newfile,tp4);
        int n4 = tp4.length();
        char char_array4[n4 + 1];
        strcpy(char_array4, tp4.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(532,518,char_array4);
        delay(800);

      int maxx, maxy;
      int x, y;
      maxx = getmaxx( );
      maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

       if ( x > 55 && x < 340 && y >390 && y <450){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 1250000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q12;
        q12.question12();
        }

         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,650,450);
        floodfill(421,420,RED);
        outtextxy(525,430,char_array2);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,495,325,542);
        floodfill(91,510,RED);
        outtextxy(200,518,char_array3);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
         PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
       bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
      PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

 //skip option
        if ( x > 497 && x < 580 && y >8 && y <50)
   {    z=1;
    setfillstyle(SOLID_FILL, YELLOW);
    setcolor(WHITE);
    fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
    delay(1000);
    setfillstyle(SOLID_FILL,GREEN);
    bar(85,400,335,450);
    floodfill(86,420,GREEN);
    outtextxy(200,430,char_array1);
    PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
    Questions q121;
    q121.question12();

   }
   else if(z!=1)
    z=0;

   //50:50 option
   if(y < 30 && x < 670){
    w=1;
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
    delay(1000);
    setfillstyle(SOLID_FILL,BLACK);
   bar(85,495,325,542);
    floodfill(421,510,BLACK);
    bar(410,400,650,450);
    floodfill(91,510,BLACK);

     int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
    maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

    if ( x > 55 && x < 340 && y >390 && y <450){
            w=1;
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 1250000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q122;
        q122.question12();
        }

         if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
       bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
      PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }
   }
       else if(w!=1)
        w=0;
}

getch();
}

void Questions::question12()
{
     cleardevice();
    readimagefile("page4.jpeg",0,0,700,600);
  setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);

   settextstyle(8,0,2);
setfillstyle(SOLID_FILL,WHITE);
    bar(190,10,320,35);
     outtextxy(90,25,"You have won ");
     outtextxy(255,28,"1250000/-");

if(z<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
     fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
}
if(w<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
}

    PlaySound(TEXT("kbcbeforequestion.wav"),NULL,SND_SYNC);
    settextstyle(9,0,2);

GotoLine(newfile,67);
        if (newfile.is_open()){
        string tp;
        getline(newfile,tp);
        settextstyle(9,0,3);
        int n = tp.length();
        char char_array[n + 1];
        strcpy(char_array, tp.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(380,290,char_array);

        delay(3000);
        settextstyle(9,0,2);

GotoLine(newfile,68);
        string tp1;
        getline(newfile,tp1);
        int n1 = tp1.length();
        char char_array1[n1 + 1];
        strcpy(char_array1, tp1.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(200,430,char_array1);
        delay(800);

GotoLine(newfile,69);
        string tp2;
        getline(newfile,tp2);
        int n2 = tp2.length();
        char char_array2[n2 + 1];
        strcpy(char_array2, tp2.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(525,430,char_array2);
        delay(800);

GotoLine(newfile,70);
        string tp3;
        getline(newfile,tp3);
        int n3 = tp3.length();
        char char_array3[n3 + 1];
        strcpy(char_array3, tp3.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(200,518,char_array3);
        delay(800);

GotoLine(newfile,71);
        string tp4;
        getline(newfile,tp4);
        int n4 = tp4.length();
        char char_array4[n4 + 1];
        strcpy(char_array4, tp4.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(525,518,char_array4);
         delay(800);

      int maxx, maxy;
      int x, y;
      maxx = getmaxx( );
      maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

       if ( x > 55 && x < 340 && y >390 && y <450){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,400,335,450);
        floodfill(96,420,RED);
        outtextxy(200,430,char_array1);
        setfillstyle(SOLID_FILL,GREEN);
         bar(85,495,325,542);
        floodfill(91,510,GREEN);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,650,450);
        floodfill(421,420,RED);
        outtextxy(525,430,char_array2);
        setfillstyle(SOLID_FILL,GREEN);
         bar(85,495,325,542);
        floodfill(91,510,GREEN);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,495,325,542);
        floodfill(91,510,GREEN);
        outtextxy(200,518,char_array3);
         PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 2500000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q13;
        q13.question13();
        }

        if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
         bar(85,495,325,542);
        floodfill(91,510,GREEN);
        outtextxy(200,518,char_array3);
     PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

            //skip option
    if ( x > 497 && x < 580 && y >8 && y <50)
   {    z=1;
    setfillstyle(SOLID_FILL, YELLOW);
    setcolor(WHITE);
    fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
    delay(1000);
    setfillstyle(SOLID_FILL,GREEN);
    bar(85,495,325,542);
    floodfill(91,510,GREEN);
    outtextxy(200,518,char_array3);
    PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
    Questions q131;
        q131.question13();

   }
   else if(z!=1)
    z=0;

   //50:50 option
   if(y < 30 && x < 670){
    w=1;
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
    delay(1000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(85,400,335,450);
    floodfill(86,420,BLACK);
    bar(410,400,650,450);
    floodfill(411,420,BLACK);

     int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
    maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

      if ( x > 90 && x < 320 && y >500 && y <540){
            w=1;
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,495,325,542);
        floodfill(91,510,GREEN);
        outtextxy(200,518,char_array3);
         PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 2500000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q13;
        q13.question13();
        }

         if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
         bar(85,495,325,542);
        floodfill(91,510,GREEN);
        outtextxy(200,518,char_array3);
     PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }
   }
       else if(w!=1)
        w=0;

}

getch();
}

void Questions::question13()
{
    cleardevice();
    readimagefile("page4.jpeg",0,0,700,600);
  setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);

   settextstyle(8,0,2);
setfillstyle(SOLID_FILL,WHITE);
    bar(190,10,320,35);
     outtextxy(90,25,"You have won ");
     outtextxy(255,28,"2500000/-");

if(z<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
     fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
}
if(w<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
}

    PlaySound(TEXT("kbcbeforequestion.wav"),NULL,SND_SYNC);
    settextstyle(9,0,2);

GotoLine(newfile,73);
        if (newfile.is_open()){
        string tp;
        getline(newfile,tp);
        settextstyle(9,0,3);
        int n = tp.length();
        char char_array[n + 1];
        strcpy(char_array, tp.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(380,290,char_array);


        delay(3000);
        settextstyle(9,0,2);

GotoLine(newfile,74);
        string tp1;
        getline(newfile,tp1);
        int n1 = tp1.length();
        char char_array1[n1 + 1];
        strcpy(char_array1, tp1.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(200,430,char_array1);
    delay(800);

GotoLine(newfile,75);
        string tp2;
        getline(newfile,tp2);
        int n2 = tp2.length();
        char char_array2[n2 + 1];
        strcpy(char_array2, tp2.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(525,430,char_array2);
    delay(800);

GotoLine(newfile,76);
        string tp3;
        getline(newfile,tp3);
        int n3 = tp3.length();
        char char_array3[n3 + 1];
        strcpy(char_array3, tp3.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(200,518,char_array3);
        delay(800);

GotoLine(newfile,77);
        string tp4;
        getline(newfile,tp4);
        int n4 = tp4.length();
        char char_array4[n4 + 1];
        strcpy(char_array4, tp4.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(525,518,char_array4);
        delay(800);

      int maxx, maxy;
        int x, y;
        maxx = getmaxx( );
         maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

       if ( x > 55 && x < 340 && y >390 && y <450){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
       bar(85,400,335,450);
        floodfill(96,420,RED);
        outtextxy(200,430,char_array1);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }


         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
         PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,160,"You have won 5000000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q14;
        q14.question14();
        }

        if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,495,325,542);
        floodfill(91,510,RED);
        outtextxy(200,518,char_array3);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
         PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

//skip option
    if ( x > 497 && x < 580 && y >8 && y <50)
   {    z=1;
    setfillstyle(SOLID_FILL, YELLOW);
    setcolor(WHITE);
    fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
    delay(1000);
    setfillstyle(SOLID_FILL,GREEN);
    bar(410,400,650,450);
    floodfill(421,420,GREEN);
    outtextxy(525,430,char_array2);
    PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
    Questions q141;
        q141.question14();

   }
   else if(z!=1)
    z=0;

   //50:50 option
   if(y < 30 && x < 670){
    w=1;
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
    delay(1000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(85,400,335,450);
    floodfill(86,420,BLACK);
    bar(410,495,648,540);
    floodfill(411,510,BLACK);

     int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
    maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

    if ( x > 420 && x < 640 && y >410 && y <435){
            w=1;
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
         PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 2500000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
       Questions q142;
       q142.question14();
        }

         if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,495,325,542);
        floodfill(91,510,RED);
        outtextxy(200,518,char_array3);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
         PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }
   }
       else if(w!=1)
        w=0;


getch();
}}




void Questions::question14()
{
    cleardevice();
    readimagefile("page4.jpeg",0,0,700,600);
  setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);

     settextstyle(8,0,2);
setfillstyle(SOLID_FILL,WHITE);
    bar(190,10,320,35);
     outtextxy(90,25,"You have won ");
     outtextxy(255,28,"5000000/-");

if(z<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
     fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
}
if(w<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
}

    PlaySound(TEXT("kbcbeforequestion.wav"),NULL,SND_SYNC);
    settextstyle(9,0,2);

GotoLine(newfile,79);
    if (newfile.is_open()){
     string tp;
    getline(newfile,tp);
    settextstyle(9,0,3);
    int n = tp.length();
    char char_array[n + 1];
    strcpy(char_array, tp.c_str());
    for (int i = 0; i < 1; i++)
    outtextxy(380,290,char_array);

        delay(3000);
        settextstyle(9,0,2);

GotoLine(newfile,80);
        string tp1;
        getline(newfile,tp1);
        int n1 = tp1.length();
        char char_array1[n1 + 1];
        strcpy(char_array1, tp1.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(200,430,char_array1);
    delay(800);

GotoLine(newfile,81);
        string tp2;
        getline(newfile,tp2);
        int n2 = tp2.length();
        char char_array2[n2 + 1];
        strcpy(char_array2, tp2.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(525,430,char_array2);
    delay(800);

GotoLine(newfile,82);
        string tp3;
        getline(newfile,tp3);
        int n3 = tp3.length();
        char char_array3[n3 + 1];
        strcpy(char_array3, tp3.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(200,518,char_array3);
        delay(800);

GotoLine(newfile,83);
        string tp4;
        getline(newfile,tp4);
        int n4 = tp4.length();
        char char_array4[n4 + 1];
        strcpy(char_array4, tp4.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(525,518,char_array4);


      int maxx, maxy;
        int x, y;
        maxx = getmaxx( );
         maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

       if ( x > 55 && x < 340 && y >390 && y <450){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,400,335,450);
        floodfill(96,420,RED);
        outtextxy(200,430,char_array1);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 5000000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q15;
        q15.question15();
        }

        if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,495,325,542);
        floodfill(91,510,RED);
        outtextxy(200,518,char_array3);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
         PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
      PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

//skip option
    if ( x > 497 && x < 580 && y >8 && y <50)
   {    z=1;
    setfillstyle(SOLID_FILL, YELLOW);
    setcolor(WHITE);
    fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
    delay(1000);
    setfillstyle(SOLID_FILL,GREEN);
    bar(410,400,650,450);
    floodfill(421,420,GREEN);
    outtextxy(525,430,char_array2);
    PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
    Questions q151;
        q151.question15();

   }
   else if(z!=1)
    z=0;

   //50:50 option
   if(y < 30 && x < 670){
    w=1;
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
    delay(1000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(85,400,335,450);
    floodfill(86,420,BLACK);
    bar(410,495,648,540);
    floodfill(411,510,BLACK);

     int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
    maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

    if ( x > 420 && x < 640 && y >410 && y <435){
            w=1;
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
         PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 2500000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
       Questions q152;
       q152.question15();
        }

         if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,495,325,542);
        floodfill(91,510,RED);
        outtextxy(200,518,char_array3);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,400,650,450);
        floodfill(421,420,GREEN);
        outtextxy(525,430,char_array2);
         PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }
   }
       else if(w!=1)
        w=0;
}

getch();
}


void Questions::question15()
{
    cleardevice();
    readimagefile("page4.jpeg",0,0,700,600);
  setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);

   settextstyle(8,0,2);
setfillstyle(SOLID_FILL,WHITE);
    bar(190,10,320,35);
     outtextxy(90,25,"You have won ");
     outtextxy(255,28,"7500000/-");

if(z<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
     fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
}
if(w<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
}

    PlaySound(TEXT("kbcbeforequestion.wav"),NULL,SND_SYNC);
    settextstyle(9,0,2);

GotoLine(newfile,85);
    if (newfile.is_open());
     string tp;
    getline(newfile,tp);
    settextstyle(9,0,3);
    int n = tp.length();
    char char_array[n + 1];
    strcpy(char_array, tp.c_str());
    for (int i = 0; i < 1; i++)
    outtextxy(380,290,char_array);

        delay(3000);
        settextstyle(9,0,2);

GotoLine(newfile,86);
        string tp1;
        getline(newfile,tp1);
        int n1 = tp1.length();
        char char_array1[n1 + 1];
        strcpy(char_array1, tp1.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(200,430,char_array1);
    delay(800);

GotoLine(newfile,87);
        string tp2;
        getline(newfile,tp2);
        int n2 = tp2.length();
        char char_array2[n2 + 1];
        strcpy(char_array2, tp2.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(525,430,char_array2);
    delay(800);

GotoLine(newfile,88);
        string tp3;
        getline(newfile,tp3);
        int n3 = tp3.length();
        char char_array3[n3 + 1];
        strcpy(char_array3, tp3.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(200,518,char_array3);
        delay(800);

GotoLine(newfile,89);
        string tp4;
        getline(newfile,tp4);
        int n4 = tp4.length();
        char char_array4[n4 + 1];
        strcpy(char_array4, tp4.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(525,518,char_array4);

      int maxx, maxy;
        int x, y;
        maxx = getmaxx( );
         maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

       if ( x > 55 && x < 340 && y >390 && y <450){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 10000000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q16;
        q16.question16();
        }

         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,650,450);
        floodfill(421,420,RED);
        outtextxy(525,430,char_array2);
        setfillstyle(SOLID_FILL,GREEN);
         bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,495,325,542);
        floodfill(91,510,RED);
        outtextxy(200,518,char_array3);
        setfillstyle(SOLID_FILL,GREEN);
         bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
         PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
         bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
     PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }
//skip option
    if ( x > 497 && x < 580 && y >8 && y <50)
   {    z=1;
    setfillstyle(SOLID_FILL, YELLOW);
    setcolor(WHITE);
    fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
    delay(1000);
    setfillstyle(SOLID_FILL,GREEN);
    bar(85,400,335,450);
    floodfill(96,420,GREEN);
    outtextxy(200,430,char_array1);
    PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
    Questions q161;
    q161.question16();

   }
   else if(z!=1)
    z=0;

   //50:50 option
   if(y < 30 && x < 670){
    w=1;
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
    delay(1000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(410,400,650,450);
    floodfill(86,420,BLACK);
   bar(85,495,325,542);
    floodfill(91,510,BLACK);

     int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
    maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

    if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
         bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

       if ( x > 55 && x < 340 && y >390 && y <450){
            w=1;
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,400,335,450);
        floodfill(96,420,GREEN);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 10000000 rs!");
        delay(1000);
        outtextxy(330,160,"Your next question on your screen..");
        delay(1000);
        Questions q16;
        q16.question16();
        }
   }
       else if(w!=1)
        w=0;
getch();
}




void Questions::question16()
{
    cleardevice();
    readimagefile("page4.jpeg",0,0,700,600);
  setfillstyle(SOLID_FILL,LIGHTBLUE);
    setcolor(WHITE);

    settextstyle(8,0,2);
setfillstyle(SOLID_FILL,WHITE);
    bar(190,10,320,35);
     outtextxy(90,25,"You have won ");
     outtextxy(255,28,"10000000/-");

if(z<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
     fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
}
if(w<1){
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
}

    PlaySound(TEXT("kbcbeforequestion.wav"),NULL,SND_SYNC);
    settextstyle(9,0,2);

    GotoLine(newfile,91);
    if (newfile.is_open()){
     string tp;
    getline(newfile,tp);
    settextstyle(9,0,2);
    int n = tp.length();
    char char_array[n + 1];
    strcpy(char_array, tp.c_str());
    for (int i = 0; i < 1; i++)
    outtextxy(380,290,char_array);

     GotoLine(newfile,92);

     string tp5;
    getline(newfile,tp5);
    settextstyle(9,0,3);
    int n5 = tp5.length();
    char char_array5[n5 + 1];
    strcpy(char_array5, tp5.c_str());
    for (int i = 0; i < 1; i++)
    outtextxy(380,320,char_array5);

        delay(3000);
        settextstyle(9,0,2);

GotoLine(newfile,93);
        string tp1;
        getline(newfile,tp1);
        int n1 = tp1.length();
        char char_array1[n1 + 1];
        strcpy(char_array1, tp1.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(200,430,char_array1);
delay(800);

GotoLine(newfile,94);
        string tp2;
        getline(newfile,tp2);
        int n2 = tp2.length();
        char char_array2[n2 + 1];
        strcpy(char_array2, tp2.c_str());
        for (int i = 0; i < 1; i++)
    outtextxy(525,430,char_array2);
    delay(800);

GotoLine(newfile,95);
        string tp3;
        getline(newfile,tp3);
        int n3 = tp3.length();
        char char_array3[n3 + 1];
        strcpy(char_array3, tp3.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(200,518,char_array3);
        delay(800);

GotoLine(newfile,96);
        string tp4;
        getline(newfile,tp4);
        int n4 = tp4.length();
        char char_array4[n4 + 1];
        strcpy(char_array4, tp4.c_str());
        for (int i = 0; i < 1; i++)
        outtextxy(525,518,char_array4);

      int maxx, maxy;
        int x, y;
        maxx = getmaxx( );
         maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

       if ( x > 55 && x < 340 && y >390 && y <450){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,400,335,450);
        floodfill(96,420,YELLOW);
        outtextxy(200,430,char_array1);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(85,400,335,450);
        floodfill(96,420,RED);
        outtextxy(200,430,char_array1);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,495,325,542);
        floodfill(91,510,GREEN);
        outtextxy(200,518,char_array3);
         PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

         if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,650,450);
        floodfill(421,420,RED);
        outtextxy(525,430,char_array2);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,495,325,542);
        floodfill(91,510,GREEN);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

        if ( x > 90 && x < 320 && y >500 && y <540){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(85,495,325,542);
        floodfill(91,510,YELLOW);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,495,325,542);
        floodfill(91,510,GREEN);
        outtextxy(200,518,char_array3);
         PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 500000000 rs!");
        delay(1500);
        outtextxy(330,160,"Well Done");
        delay(1000);
        endgame();
        }

        if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
       bar(410,495,648,540);
        floodfill(421,510,RED);
        outtextxy(525,518,char_array4);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,495,325,542);
        floodfill(91,510,GREEN);
        outtextxy(200,518,char_array3);
      PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

       //skip option
    if ( x > 497 && x < 580 && y >8 && y <50)
   {    z=1;
    setfillstyle(SOLID_FILL, YELLOW);
    setcolor(WHITE);
    fillellipse(540,30,40,20);
    settextstyle(8,0,2);
    outtextxy(540,35,"Skip");
    delay(1000);
    setfillstyle(SOLID_FILL,GREEN);
    bar(85,495,325,542);
    floodfill(91,510,GREEN);
    outtextxy(200,518,char_array3);
   PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
    outtextxy(310,210,"You have won 50000000 rs!");
    delay(1000);
    outtextxy(330,160,"Well Done");
    delay(1000);
    endgame();

   }
   else if(z!=1)
    z=0;

   //50:50 option
   if(y < 30 && x < 670){
    w=1;
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(650,30,40,20);
    settextstyle(8,0,2);
    outtextxy(650,35,"50:50");
    delay(1000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(85,400,335,450);
    floodfill(86,510,BLACK);
   bar(85,495,325,542);
    floodfill(86,510,BLACK);

     int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
    maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
    getmouseclick(WM_LBUTTONDOWN, x, y);

    if ( x > 420 && x < 640 && y >410 && y <435){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,400,650,450);
        floodfill(421,420,YELLOW);
        outtextxy(525,430,char_array2);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,RED);
        bar(410,400,650,450);
        floodfill(421,420,RED);
        outtextxy(525,430,char_array2);
        setfillstyle(SOLID_FILL,GREEN);
        bar(85,495,325,542);
        floodfill(91,510,GREEN);
        outtextxy(200,518,char_array3);
        PlaySound(TEXT("kbcgalatjawab.wav"),NULL,SND_SYNC);
        outtextxy(330,160,"Sorry, You are eliminated :(");
        endgame();
        }

       if ( x > 420 && x < 640 && y >500 && y <535){
        setfillstyle(SOLID_FILL,YELLOW);
        bar(410,495,648,540);
        floodfill(421,510,YELLOW);
        outtextxy(525,518,char_array4);
        PlaySound(TEXT("kbcoptionlocktune.wav"),NULL,SND_SYNC);
        setfillstyle(SOLID_FILL,GREEN);
        bar(410,495,648,540);
        floodfill(421,510,GREEN);
        outtextxy(525,518,char_array4);
     PlaySound(TEXT("kbcaudienceclapping.wav"),NULL,SND_SYNC);
        outtextxy(310,210,"You have won 50000000 rs!");
        delay(1000);
        outtextxy(330,160,"Well Done");
        delay(1000);
        endgame();
        }
   }
       else if(w!=1)
        w=0;
}

getch();

}

void endgame()
{
    cleardevice();
     setcolor(10);
    circle(150,150,20);
    delay(200);
    circle(210,150,20);
    delay(200);
    setcolor(14);
    circle(180,212,50);
    delay(200);
    setcolor(13);
    ellipse(170,212,60,180,20,40);
    delay(200);
    ellipse(190,212,0,120,20,40);
    delay(200);

    setcolor(12);
    ellipse(140,248,60,120,20,40);
    delay(200);
    ellipse(220,248,60,120,20,40);
    delay(200);

    setcolor(15);
    ellipse(172,200,0,360,6,15);
    delay(200);
    ellipse(188,200,0,360,6,15);
    delay(200);
    ellipse(182,220,10,160,12,6);
    delay(200);

    ellipse(182,225,0,360,12,6);
    delay(200);

    setcolor(12);
    ellipse(182,225,195,345,25,30);
    delay(200);
    ellipse(182,225,195,345,25,20);
    delay(200);

    setcolor(4);
    ellipse(172,208,0,360,2,6);
    delay(200);
    ellipse(188,208,0,360,2,6);
    delay(200);

    outtextxy(430,160,"Wanna Play again?");

    setfillstyle(SOLID_FILL, BLUE);
    setcolor(WHITE);
    fillellipse(180, 400, 80, 60);
    outtextxy(180, 400,"YES!");

    setfillstyle(SOLID_FILL, BLUE);
    setcolor(WHITE);
    fillellipse(490, 400, 80, 60);
    outtextxy(490, 400,"No");

    int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
     maxy = getmaxy( );

   while (!ismouseclick(WM_LBUTTONDOWN)){}
   getmouseclick(WM_LBUTTONDOWN, x, y);


    if (x > 100 && y < 450 && x < 260 && y > 340 ){

        setfillstyle(SOLID_FILL, YELLOW);
        setcolor(WHITE);
        fillellipse(180, 400, 80, 60);
        outtextxy(180, 400,"YES!");
       PlaySound(TEXT("optionselect.wav"),NULL,SND_SYNC);

        cleardevice();
         newfile.close();
       playgame();
       }

       if (x > 405 && y < 450 && x < 570 && y > 340 ){

        setfillstyle(SOLID_FILL, YELLOW);
        setcolor(WHITE);
        fillellipse(490, 400, 80, 60);
        outtextxy(490, 400,"No");
        PlaySound(TEXT("optionselect.wav"),NULL,SND_SYNC);

        cleardevice();
         newfile.close();
        closegraph();
       }

}

void playgame()
{
    cleardevice();
    settextjustify( CENTER_TEXT, CENTER_TEXT );
    settextstyle(DEFAULT_FONT,HORIZ_DIR,5);

    outtextxy(getmaxx()/2, getmaxy()/2,"Let's Play!");
    delay(1000);

    Questions q1;
    q1.question1();

getch();

}

int main()
{
    int q;
    cout << "********************Start Game*************************\n";
    cout <<" enter 1 for Yes\n";
    cout <<" enter 0 for Obviously Yes\n";
    cin >> q;


    if(q==1){
        initwindow(700,600,"Rohit");
   intro_VRlogo();
  page1();
  page2();
   disp_page3();
   newfile.close();
   getch();
    }
    if(q==0){
   // initwindow(700,600,"Rohit");
  // intro_VRlogo();
  //page1();
 // page2();
   disp_page3();
   newfile.close();
   getch();
    }
    return 0;
}

