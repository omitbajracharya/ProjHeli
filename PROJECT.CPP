#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<graphics.h>
#include<string.h>
float goUp = 0;
float helix1 = 60;
float helix2 = 135;
float heliy1 = 105;
float heliy2 = 160;
char changeSwing = 's';
char isGameOver = 'f';
int score=0;
int obsx1[2][3];
int obsx2[2][3];
int obsy1[2][3];
int obsy2[2][3];
void Heli();
void removeHeli();
void checkGameOver();
void getObstaclePosition(int obsNo, int *x10, int *y10, int *x20, int *y20, int *x11, int *y11, int *x21, int *y21);
void obstacle(int color,int topx1, int topy1, int topx2, int topy2, int bottomx1, int bottomy1, int bottomx2, int bottomy2);
void removeObstacle(int topx1, int topy1, int topx2, int topy2, int bottomx1, int bottomy1, int bottomx2, int bottomy2);
void decrementObstaclePosition();
void gameoverDisplay();
void main()
{
  clrscr();
  int gd = DETECT, gm, buttonValue = 100;
  initgraph(&gd, &gm, "../bgi");
  int maxx = getmaxx();
  int maxy = getmaxy();
  int possibleObsSize, y1Size, y2Size, obs1X,i=0;
  // Fill whole background with cyan(3) initially...
  setfillstyle(1, 3);
  floodfill(10, 10, 3);
  Heli();
  int temp;
  int obsColor;
  int obsNo = 0; // 1st obstacle
  getObstaclePosition(obsNo, &obsx1[0][obsNo], &obsy1[0][obsNo], &obsx2[0][obsNo], &obsy2[0][obsNo], &obsx1[1][obsNo], &obsy1[1][obsNo], &obsx2[1][obsNo], &obsy2[1][obsNo]);
  obsColor=8;
  obstacle(obsColor,obsx1[0][obsNo], obsy1[0][obsNo], obsx2[0][obsNo], obsy2[0][obsNo], obsx1[1][obsNo], obsy1[1][obsNo], obsx2[1][obsNo], obsy2[1][obsNo]);

  obsNo = 1; // 2nd obstacle
  getObstaclePosition(obsNo, &obsx1[0][obsNo], &obsy1[0][obsNo], &obsx2[0][obsNo], &obsy2[0][obsNo], &obsx1[1][obsNo], &obsy1[1][obsNo], &obsx2[1][obsNo], &obsy2[1][obsNo]);
    obsColor=7;
  obstacle(obsColor,obsx1[0][obsNo], obsy1[0][obsNo], obsx2[0][obsNo], obsy2[0][obsNo], obsx1[1][obsNo], obsy1[1][obsNo], obsx2[1][obsNo], obsy2[1][obsNo]);

  obsNo = 2; // 3rd obstacle
  getObstaclePosition(obsNo, &obsx1[0][obsNo], &obsy1[0][obsNo], &obsx2[0][obsNo], &obsy2[0][obsNo], &obsx1[1][obsNo], &obsy1[1][obsNo], &obsx2[1][obsNo], &obsy2[1][obsNo]);
  obsColor=6;
  obstacle(obsColor,obsx1[0][obsNo], obsy1[0][obsNo], obsx2[0][obsNo], obsy2[0][obsNo], obsx1[1][obsNo], obsy1[1][obsNo], obsx2[1][obsNo], obsy2[1][obsNo]);
  while (isGameOver == 'f')
  {
  //  if((obsx2[0][1]>obsx2[0][0]) && ((obsx2[0][1]-obsx1[0][0])<150))
  //   {
	// obsx1[0][1]+=300;
	// obsx2[0][1]+=300;
	// obsx1[1][1]+=300;
	// obsx2[1][1]+=300;
  //   }
  //  if((obsx2[0][2]>obsx2[0][1]) && ((obsx2[0][2]-obsx1[0][1])<150))
  //  {
  //     obsx1[0][2]+=300;
  //     obsx2[0][2]+=300;
  //     obsx2[1][2]+=300;
  //     obsx2[1][2]+=300;
  //  }
  //  if((obsx2[0][0]>obsx2[0][2]) && ((obsx2[0][0]-obsx1[0][2])<80))
  //  {
  //     obsx1[0][0]+=300;
  //     obsx2[0][0]+=300;
  //     obsx2[1][0]+=300;
  //     obsx2[1][0]+=300;
  //  }


    // // 2nd obstacle points -upper & lower
    // getObstaclePosition(&obsx1[0][1],&obsy1[0][1],&obsx2[0][1],&obsy2[0][1],&obsx1[1][1],&obsy1[1][1],&obsx2[1][1],&obsy2[1][1])
    // // 3rd obstacle points -upper & lower
    // getObstaclePosition(&obsx1[0][2],&obsy1[0][2],&obsx2[0][2],&obsy2[0][2],&obsx1[1][2],&obsy1[1][2],&obsx2[1][2],&obsy2[1][2])

    // srand(time(0));
    // possibleObsSize=maxy-150;
    // y1Size=rand()%((possibleObsSize-50)-50+1)+50;
    // y2Size=possibleObsSize-y1Size;
    // obs1X=getmaxx()+(rand()%(150-50+1))+50;

    //  obs1X=100;

    // rectangle(obs1X-i,0,obs1X+30-i,y1Size);
    // rectangle(obs1X-i,maxy,obs1X+30-i,maxy-y2Size);
    //  setcolor(3);
    // rectangle(obs1X-i,0,obs1X+30-i,y1Size);
    // rectangle(obs1X-i,maxy,obs1X+30-i,maxy-y2Size);
    delay(80);
    removeHeli();
    obsNo = 0;
    removeObstacle(obsx1[0][obsNo], obsy1[0][obsNo], obsx2[0][obsNo], obsy2[0][obsNo], obsx1[1][obsNo], obsy1[1][obsNo], obsx2[1][obsNo], obsy2[1][obsNo]);
    obsNo = 1;
    removeObstacle(obsx1[0][obsNo], obsy1[0][obsNo], obsx2[0][obsNo], obsy2[0][obsNo], obsx1[1][obsNo], obsy1[1][obsNo], obsx2[1][obsNo], obsy2[1][obsNo]);
    obsNo = 2;
    removeObstacle(obsx1[0][obsNo], obsy1[0][obsNo], obsx2[0][obsNo], obsy2[0][obsNo], obsx1[1][obsNo], obsy1[1][obsNo], obsx2[1][obsNo], obsy2[1][obsNo]);
    decrementObstaclePosition();
    if (kbhit())
    {
      buttonValue = getch();
      if (buttonValue == 27)
      {
	isGameOver = 't';
      }
      else if (buttonValue == 32 || buttonValue == 72)
      {
	    goUp = goUp + 30;
      }
    }
    else
      goUp = goUp-5;

    heliy1 = heliy1 - goUp;
    heliy2 = heliy2 - goUp;
    if(heliy2>=(getmaxy()-5))
    {
      goUp++;
     heliy2=getmaxy();
      heliy1=heliy2-55;
    }
    if(heliy1<=5)
    {
      goUp-=50;
      heliy1=0;
      heliy2=heliy1+55;
    }
    // Fill whole background with cyan(3) initially...
    setcolor(3);
    setfillstyle(1, 3);
    rectangle(0, 0, getmaxx(), getmaxy());
    floodfill(10, 10, 3);
    if (changeSwing == 's')
      changeSwing = 'l';
    else
      changeSwing = 's';
    Heli();
	  if (obsx1[0][0] <= 0)
    {
      obsNo=0;
      getObstaclePosition(0, &obsx1[0][obsNo], &obsy1[0][obsNo], &obsx2[0][obsNo], &obsy2[0][obsNo], &obsx1[1][obsNo], &obsy1[1][obsNo], &obsx2[1][obsNo], &obsy2[1][obsNo]);
      if(obsx1[0][2]>obsx1[0][0])
      {
	   temp=obsx1[0][2];
	   obsx1[0][2]=obsx1[0][0];
	   obsx1[0][0]=temp;
	   temp=obsx2[0][2];
	   obsx2[0][2]=obsx2[0][0];
	   obsx2[0][0]=temp;
	   temp=obsx1[1][2];
	   obsx1[1][2]=obsx1[1][0];
	   obsx1[1][0]=temp;
	   temp=obsx1[1][2];
	   obsx1[1][2]=obsx1[1][0];
	   obsx1[1][0]=temp;
       }
      if((obsx1[0][0]-obsx1[0][2])<200)
      {
	obsx1[0][0]+=200;
	obsx2[0][0]+=200;
	obsx1[1][0]+=200;
	obsx2[1][0]+=200;
      }
    }
    else if (obsx1[0][1] <= 0)
    {
      obsNo=1;
      getObstaclePosition(1, &obsx1[0][obsNo], &obsy1[0][obsNo], &obsx2[0][obsNo], &obsy2[0][obsNo], &obsx1[1][obsNo], &obsy1[1][obsNo], &obsx2[1][obsNo], &obsy2[1][obsNo]);
	    if((obsx1[0][1]-obsx1[0][0])<200)
      {
	obsx1[0][1]+=200;
	obsx2[0][1]+=200;
	obsx1[1][1]+=200;
	obsx2[1][1]+=200;
      }
    }
    else if (obsx1[0][2] <=0 )
    {
      obsNo=2;
      getObstaclePosition(2, &obsx1[0][obsNo], &obsy1[0][obsNo], &obsx2[0][obsNo], &obsy2[0][obsNo], &obsx1[1][obsNo], &obsy1[1][obsNo], &obsx2[1][obsNo], &obsy2[1][obsNo]);
      if((obsx1[0][2]-obsx1[0][1])<200)
      {
	obsx1[0][2]+=200;
	obsx2[0][2]+=200;
	obsx1[1][2]+=200;
	obsx2[1][2]+=200;
      }
    }
    obsNo = 0;
     obsColor=8;
    obstacle(obsColor,obsx1[0][obsNo], obsy1[0][obsNo], obsx2[0][obsNo], obsy2[0][obsNo], obsx1[1][obsNo], obsy1[1][obsNo], obsx2[1][obsNo], obsy2[1][obsNo]);
    obsNo = 1;
    obsColor=7;
    obstacle(obsColor,obsx1[0][obsNo], obsy1[0][obsNo], obsx2[0][obsNo], obsy2[0][obsNo], obsx1[1][obsNo], obsy1[1][obsNo], obsx2[1][obsNo], obsy2[1][obsNo]);
    obsNo = 2;
    obsColor=6;
    obstacle(obsColor,obsx1[0][obsNo], obsy1[0][obsNo], obsx2[0][obsNo], obsy2[0][obsNo], obsx1[1][obsNo], obsy1[1][obsNo], obsx2[1][obsNo], obsy2[1][obsNo]);
    checkGameOver();
    score++;
  }
  gameoverDisplay();
}

void checkGameOver() //Check on three obstacle upper and lower hits or not...
{

 if(heliy1<=0 || heliy2>=getmaxy()-60)
 {
   isGameOver='t';
   return;
 }
  for(int i=0;i<=2;i++)
  {
    for(int j=0;j<=1;j++)
    {
	if(((helix1>=obsx1[j][i] && helix1<=obsx2[j][i])||(helix2>=obsx1[j][i] && helix2<=obsx2[j][i])) && ((heliy1>=obsy1[j][i] && heliy1<=obsy2[j][i]) || (heliy2>=obsy1[j][i] && heliy2<=obsy2[j][i])))
	{
	   isGameOver='t';
	   return;
	 }
     }
  }
}

void decrementObstaclePosition() //Move obastacle to left position
{
  // 1st obstacle
  obsx1[0][0] -= 10;
  obsx2[0][0] -= 10;
  obsx1[1][0] -= 10;
  obsx2[1][0] -= 10;
  // 2nd obstacle
  obsx1[0][1] -= 10;
  obsx2[0][1] -= 10;
  obsx1[1][1] -= 10;
  obsx2[1][1] -= 10;
  // 3rd obstacle
  obsx1[0][2] -= 10;
  obsx2[0][2] -= 10;
  obsx1[1][2] -= 10;
  obsx2[1][2] -= 10;
}

void obstacle(int color,int topx1, int topy1, int topx2, int topy2, int bottomx1, int bottomy1, int bottomx2, int bottomy2)
{
  setcolor(color);
  rectangle(topx1, topy1, topx2, topy2);
  rectangle(bottomx1, bottomy1, bottomx2, bottomy2);
}

void removeObstacle(int topx1, int topy1, int topx2, int topy2, int bottomx1, int bottomy1, int bottomx2, int bottomy2)
{
  setcolor(3);//background color here
  rectangle(topx1, topy1, topx2, topy2);
  rectangle(bottomx1, bottomy1, bottomx2, bottomy2);
}

void getObstaclePosition(int obsNo, int *x10, int *y10, int *x20, int *y20, int *x11, int *y11, int *x21, int *y21)
{
  srand(time(0));
  int possibleObsSize = getmaxy() - 150;
  int y1Size = rand() % ((possibleObsSize - 50) - 50 + 1) + 50; // just a random no between 50 to possibleObsSize
  int y2Size = possibleObsSize - y1Size;
  int obsX = getmaxx() + (rand() % (150 - 50 + 1)) + 50;
  int someDistance;
  if (obsNo == 0)
    someDistance = 300;
  else if (obsNo == 1)
    someDistance = 450;
  else if (obsNo == 2)
    someDistance = 550;

  // upward obstacle
  *x10 = obsX + someDistance;
  *y10 = 0;
  *x20 = obsX + someDistance + 30;
  *y20 = y1Size;
  // downward obstacle
  *x11 = obsX + someDistance;
  *y11 = getmaxy()- y2Size;
  *x21 = obsX + someDistance + 30;
  *y21 = getmaxy(); 

}
void Heli()
{

  //    //bounding box
  //  setcolor(WHITE);
  //  rectangle(60,heliy1+30-goUp,135,heliy1+55-goUp);

  // Helicopter frontpart-red
  setcolor(BLACK);
  setfillstyle(1, RED);
  pieslice(100, heliy1 + 45 - goUp, 0, 90, 35);
  line(100, heliy1 + 10 - goUp, 70, heliy1 + 28 - goUp);
  line(100, heliy1 + 45 - goUp, 70, heliy1 + 28 - goUp);
  floodfill(80, heliy1 + 28 - goUp, BLACK);
  floodfill(105, heliy1 + 40 - goUp, BLACK);

  // Inner pie-slice with white color(15)
  setcolor(BLACK);
  setfillstyle(1, 15);
  pieslice(107, heliy1 + 38 - goUp, 0, 90, 20);
  floodfill(108, heliy1 + 35 - goUp, BLACK);

  // swing
  if (changeSwing == 's')
  {
    pieslice(68, heliy1 + 16 - goUp, 120, 135, 10);
    pieslice(72, heliy1 + 19 - goUp, 345, 360, 8);
  }
  else
  {
    pieslice(72, heliy1 + 16 - goUp, 40, 60, 10);
    pieslice(68, heliy1 + 19 - goUp, 210, 225, 8);
  }
  // swing downpart
  pieslice(70, heliy1 + 20 - goUp, 240, 300, 16);
  // swing circle
  circle(70, heliy1 + 17 - goUp, 3);
  floodfill(71, heliy1 + 15 - goUp, BLACK);

  // Helicoptor top stand
  setcolor(BLACK);
  rectangle(101, heliy1 + 2 - goUp, 103, heliy1 + 10 - goUp);
  rectangle(95, heliy1 + 3 - goUp, 110, heliy1 + 1 - goUp);
  // downpart landing
  pieslice(105, heliy1 + 45 - goUp, 250, 270, 7);
  pieslice(125, heliy1 + 45 - goUp, 300, 320, 7);
  rectangle(95, heliy1 + 54 - goUp, 135, heliy1 + 55 - goUp);
}
void removeHeli()
{
  // bounding box
  setcolor(3);
  setfillstyle(1, 3);
  rectangle(60, heliy1 + 45 - goUp, 135, heliy1 + 55 - goUp);
  pieslice(100, heliy1 + 45 - goUp, 0, 90, 35);
  line(100, heliy1 + 10 - goUp, 70, heliy1 + 28 - goUp);
  line(100, heliy1 + 45 - goUp, 70, heliy1 + 28 - goUp);
  floodfill(80, heliy1 + 28 - goUp, 3);
  floodfill(105, heliy1 + 40 - goUp, 3);
  pieslice(107, heliy1 + 38 - goUp, 0, 90, 20);
  floodfill(108, heliy1 + 35 - goUp, 3);

  // swing
  pieslice(68, heliy1 + 16 - goUp, 120, 135, 10);
  pieslice(72, heliy1 + 16 - goUp, 40, 60, 10);
  pieslice(68, heliy1 + 19 - goUp, 210, 225, 8);
  pieslice(72, heliy1 + 19 - goUp, 345, 360, 8);
  // swing downpart
  pieslice(70, heliy1 + 20 - goUp, 240, 300, 16);
  // swing circle
  circle(70, heliy1 + 17 - goUp, 3);
  floodfill(71, heliy1 + 15 - goUp, 3);

  // Helicoptor top stand
  rectangle(101, heliy1 + 2 - goUp, 103, heliy1 + 10 - goUp);
  rectangle(95, heliy1 + 3 - goUp, 110, heliy1 + 1 - goUp);
  // downpart landing
  pieslice(105, heliy1 + 45 - goUp, 250, 270, 7);
  pieslice(125, heliy1 + 45 - goUp, 300, 320, 7);
  rectangle(95, heliy1 + 54 - goUp, 135, heliy1 + 55 - goUp);
}

void gameoverDisplay()
{
  char str[100];
sprintf(str, "%d", score);
  setfillstyle(1, 3);
  floodfill(10, 10, 3);
  outtextxy(200, 100, "GameOver");
outtextxy(200, 300, strcat("Your Score is: ",str));
getch();
}