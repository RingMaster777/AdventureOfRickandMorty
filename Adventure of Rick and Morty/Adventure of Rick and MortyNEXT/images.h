#include "music.h"
#define screenWidth 1200
#define screenHeight 800


#define upperBackgroundSpeed 120
#define lowerBackgroundSpeed 120


char menu[4][20] = {"bg\\2.bmp","bg\\bg12.bmp","bg\\highscores.bmp","bg\\Instructions.bmp"};
char jerry[4][30] = {"character\\Rick.bmp","character\\Rick2.bmp","character\\Rick3.bmp","character\\Rick4.bmp"};
char birds[3][30] = {"character\\alienf1.bmp","character\\alienf2.bmp","character\\alienf3.bmp"};




char upperBackgroundImage[10][15]={"bgr\\br1.bmp", "bgr\\br2.bmp", "bgr\\br3.bmp", "bgr\\br4.bmp", "bgr\\br5.bmp", "bgr\\br6.bmp", "bgr\\br7.bmp", "bgr\\br8.bmp", "bgr\\br9.bmp", "bgr\\br10.bmp"};
char lowerBackgroundImage[10][15]={"bgr\\br11.bmp", "bgr\\br12.bmp", "bgr\\br13.bmp", "bgr\\br14.bmp", "bgr\\br15.bmp", "bgr\\br16.bmp", "bgr\\br17.bmp", "bgr\\br18.bmp", "bgr\\br19.bmp", "bgr\\br20.bmp"};


struct bckgrnd
{ 
	int x;
	int y;

};
bckgrnd upperBackground[10];
bckgrnd lowerBackground[10];


void setAll()
{ 
	int sum=0;
	for(int i=0; i<10; i++)
	{
		upperBackground[i].y= 120;//wiil not change
		lowerBackground[i].y= 0;//wiil not change
		upperBackground[i].x= sum;
		lowerBackground[i].x= sum;
		sum += 120;
	}
}


void changebacground()
{
 for(int i=0; i<10; i++)
 {
	 upperBackground[i].x -= upperBackgroundSpeed;
	 lowerBackground[i].x -= lowerBackgroundSpeed;
	 if(upperBackground[i].x+10 < 0)
	 {
		 upperBackground[i].x  = screenWidth-120; 
	 }
	 if(lowerBackground[i].x + 12 < 0)
	 {
		 lowerBackground[i].x = screenWidth-120; 
	 }
 }
}







char spaceship[3][30] = {"space\\s1.bmp","space\\s2.bmp","space\\s3.bmp"};
char bomb[3][30] = {"fire\\f1.bmp","fire\\f2.bmp","fire\\f3.bmp"};


//for first interface
void intro()
{
	iShowBMP(0,0,"bg\\bg69.bmp");
	
}



void allImages(){
	intro();
	
}





