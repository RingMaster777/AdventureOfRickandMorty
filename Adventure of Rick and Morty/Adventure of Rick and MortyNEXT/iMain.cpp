

#include <iostream>
#include "gamePlay.h"


using namespace std;

#define screenWidth 1200
#define screenHeight 800


int mposx,  mposy;






void iDraw()
{
	
	iClear();

	if(!menuShow){
		intro();

	}

	if(makeMenuShowTrue()){
		Menu();
	}
	
	

	

}

void iMouseMove(int mx, int my)
{
	
}



void iMouse(int button, int state, int mx, int my)
{
	
	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		

		if(newg==1){
			if(mx >= 450 && mx <= 700 && my >= 220 && my <= 250 && !textActivator)
			{
				textActivator = true;
			}
		}

		if(returnToMainMenu){
			if(mx>=424 && mx <=720 && my>=528 && my<= 570)
			{
				//new game
				gameS = 1;
				startGame = true;
				loadGame  = false;
			}
			else if(mx>=424 && mx<=720 && my>=462 && my<=502)
			{
				//load game
				gameS = 2;
			}
			else if(mx>=424 && mx<=720 && my>=393 && my<=436)
			{
				//highscore
				gameS = 3;
			}
			else if(mx>=424 && mx<=720 && my>=325 && my<=369)
			{
				//instructions
				gameS = 4;
			}
			else if(mx>=424 && mx<=720 && my<=300 && my>=261)
			{
				//exit
				gameS = -1;
			}
		
		}

		if(gameS==1 && savegamemenu){

			if(mx>=504 && mx<=590 && my>=342 && my<=382){
				savegame();
				gameS = 0 ;
				
				
			}else if(mx>=477 && mx<=621 && my>=462 && my<=502){
				gameS = 1;

			}
			savegamemenu= false;


		}


	}


	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}


void iPassiveMouseMove(int mx,int my)
{
	

 mposx = mx;
 mposy = my;
 if(mx== 2){}        
 else if(my== 2){}   

}


void iKeyboard(unsigned char key)
{

	
		int i;
	if(textActivator)
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(highscore[state].name, str);
			highscore[state].score = rick.score;
			state++;
			updateleaderboard();
			for(i = 0; i < len; i++)
				str[i] = 0;
			len = 0;

			newg = 2;
			textActivator = false;
			gameS = 0;

		   
		}
		else
		{
			str[len] = key;
			len++;
		}
	}
	
	
	
		
	

	if(key=='m'){
		
		if(music){
			musicStop();
			music = false;
			
		}else{
			music = true;
			musicOn();
		}

		
	
	}


	if(gameS==1 && newg ==0){
		if(key == 'd'){
			changebacground();
		if(rick.jerryIndex >= 3){
			rick.jerryIndex = 0;
			
		}else{
			
			if( rick.jerryCordinateX >= (screenWidth-128)){
				rick.jerryCordinateX  = (screenWidth-128);
			}else{
				rick.jerryCordinateX  += 10;
			}
			rick.jerryIndex++;
			dx = rick.jerryCordinateX;
		}
	}

	else if(key == 'a'){
		if(rick.jerryIndex <= 0){
			rick.jerryIndex = 3;
		}else{
			
			if( rick.jerryCordinateX <= 0){
				rick.jerryCordinateX=0;
			}else{
				rick.jerryCordinateX -= 10;
			}
			rick.jerryIndex--;
			dx=rick.jerryCordinateX;
		}
	}else if(key == ' '){
		if(!jumpUp)
		    jumpUp = true;
	}

	
		if(key == 'f'){
			if(!fire){
				fire = true;
			}else{
				fire = false;
			}
		}





		/* here y g h j i used to move the rick spaceship. i also created a structure in selectionbar for rick spaceship. 
		i initialized those in the boss functions
		*/
		if(key == 'y'){
			
			if(rickspaceship.rickspaceshipY>screenHeight-150){
				rickspaceship.rickspaceshipY =screenHeight-150;
			}else{
				rickspaceship.rickspaceshipY += 10;
			}

		}else if(key == 'h'){

			if(rickspaceship.rickspaceshipY<0){
				rickspaceship.rickspaceshipY =0;
			}else{
				rickspaceship.rickspaceshipY -= 10;
			}
		}else if(key == 'j'){

			if(rickspaceship.rickspaceshipX>450){
				rickspaceship.rickspaceshipX =450;
			}else{
				rickspaceship.rickspaceshipX += 10;
			}
		}else if(key == 'g'){

			if(rickspaceship.rickspaceshipX<0){
				rickspaceship.rickspaceshipX =0;
			}else{
				rickspaceship.rickspaceshipX -= 10;
			}
		}
	
	
	}


}


void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	else if(key == GLUT_KEY_F1)
	{
		if(gameS == 1){
			savegamemenu = true;
		}else{
			gameS = 0;
		}
	}
}
//


void showleaderboard();
int main()
{

	setAll();

	
	
	setFireVariable();
	setEnemyVariable();
	setSpaceVariable();
	//iSetTimer(100,change);
	iSetTimer(0000,changeInterface);
	iSetTimer(100,changeRy);
	

		
	iSetTimer(200,changefire);
	iSetTimer(500,changespace);

	iSetTimer(10,firecollide);//new


	cout<<rick.health<<endl;
	
	leaderboard();
	musicOn();
	iInitialize(screenWidth, screenHeight, "Adventure of Rick and Morty");
	return 0;
}