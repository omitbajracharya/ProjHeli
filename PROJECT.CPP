#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<graphics.h>
int goUp=50;
int helix1=60;
int helix2=135;
int heliy1=105;
int heliy2=160;
int isGameOver=0;
void designHeli();
void main()
{
  clrscr();
   int gd=DETECT, gm,buttonValue;
  initgraph(&gd, &gm,"../bgi");
    int maxx=getmaxx();
   int maxy=getmaxy();
  int possibleObsSize,y1Size,y2Size,obs1X,i=0;
   while(isGameOver==1)
   {
    designHeli();
   srand(time(0));
   possibleObsSize=maxy-150;
   y1Size=rand()%((possibleObsSize-50)-50+1)+50;
   y2Size=possibleObsSize-y1Size;
   obs1X=getmaxx()+(rand()%(150-50+1))+50;

    obs1X=100;


    setcolor(BLACK);
//  rectangle(obs1X-i,0,obs1X+30-i,y1Size);
 // rectangle(obs1X-i,maxy,obs1X+30-i,maxy-y2Size);
    delay(80);
   //  setcolor(3);
 // rectangle(obs1X-i,0,obs1X+30-i,y1Size);
 // rectangle(obs1X-i,maxy,obs1X+30-i,maxy-y2Size);

  buttonValue=getch();
  if(buttonValue==27)
  isGameOver=1;
 // else if(buttonValue==34  || buttonValue==38)
  // goUp=goUp+50;
 // else
 // goUp--;

 // heliy1=heliy1+goUp;


    }
    getch();
}

void designHeli()
{
  //Fill whole background with cyan(3) initially...
  setfillstyle(1,3);
  floodfill(10,10,3);

     //bounding box
   setcolor(WHITE);
   rectangle(60,heliy1+45-goUp,135,heliy1+55-goUp);

  //Helicopter frontpart-red
  setcolor(BLACK);
  setfillstyle(1,RED);
  pieslice(100,heliy1+45-goUp,0,90,35);
  line(100,heliy1+10-goUp,70,heliy1+28-goUp);
  line(100,heliy1+45-goUp,70,heliy1+28-goUp);
  floodfill(80,heliy1+28-goUp,BLACK);
  floodfill(105,heliy1+40-goUp,BLACK);

  //Inner pie-slice with white color(15)
  setcolor(BLACK);
  setfillstyle(1,15);
  pieslice(107,heliy1+38-goUp,0,90,20);
  floodfill(108,heliy1+35-goUp,BLACK);

 // swing
  pieslice(68,heliy1+16-goUp,120,135,10);
  pieslice(72,heliy1+16-goUp,40,60,10);
  pieslice(68,heliy1+19-goUp,210,225,8);
  pieslice(72,heliy1+19-goUp,345,360,8);
  //swing downpart
  pieslice(70,heliy1+20-goUp,240,300,16);
  //swing circle
  circle(70,heliy1+17-goUp,3);
  floodfill(71,heliy1+15-goUp,BLACK);

  //Helicoptor top stand
    setcolor(BLACK);
  rectangle(101,heliy1+2-goUp,103,heliy1+10-goUp);
  rectangle(95,heliy1+3-goUp,110,heliy1+1-goUp);
  //downpart landing
  pieslice(105,heliy1+45-goUp,250,270,7);
  pieslice(125,heliy1+45-goUp,300,320,7);
  rectangle(95,heliy1+54-goUp,135,heliy1+55-goUp);

}