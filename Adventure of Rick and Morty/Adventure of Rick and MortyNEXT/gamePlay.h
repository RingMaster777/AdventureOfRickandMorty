#include "selectionBar.h"
#include <stdlib.h>

#include <iostream>
using namespace std;

bool bulletCollision = false;
bool collision = false;
bool fire = false;
int changeTime = 0;
void bossMovement();



bool menuShow = false;
bool returnToMainMenu =false;

int newg = 0;///changing interface inside new game interface


int selectMenu = 0;
int killboss = 0;

void gameEnds();
int jump =200;
int jumpUp = false;



int healthX = 150;
int healthY = 30;



bool bc = false;
int finalscore;

bool savegamemenu = false;







/////THONA code start
bool firesheild = true;//new

bool bul=false;
bool gron=true;
bool rec;
bool sheild=false;
bool sheild_deactive= true;
bool bar=false;
bool sheild_op= true;
bool boss_op=true;
bool boss_upore=false;


int level;
int dx=rick.jerryCordinateX;
int dy=rick.jerryCordinateY;


int sheild_score=50;



// Boss code start




int bossdx = 10;
int bossdy = 10;

void bossMovement(){
	if(rick.score >= 400){
	
		iShowBMP2(bossmama.bossCoordinateX,bossmama.bossCoordinateY,"character\\enemy1.bmp",0);

		bossmama.bossCoordinateX -=bossdx;
		bossmama.bossCoordinateY -=bossdy;


	if(bossmama.bossCoordinateX > (screenWidth-100) || bossmama.bossCoordinateX < 0){
		bossdx= -bossdx;
	}

	if(bossmama.bossCoordinateY > (screenHeight-100) || bossmama.bossCoordinateY  < 0){
		bossdy = -bossdy;
	}
	}


}

void bossBulletCollision(){
	if(!gameEnd){
		
			if((bossmama.bossCoordinateX < rickspaceship.spaceShipGunX +25 && bossmama.bossCoordinateX + 120 > rickspaceship.spaceShipGunX) && (bossmama.bossCoordinateY < rickspaceship.spaceShipGunY + 25 && bossmama.bossCoordinateY + 100 > rickspaceship.spaceShipGunY))
			{
				bc = true;
				bossmama.bosshealth-=20;
				rick.score += 10;
			}else{
				bc = false;
			}
		}
	

	
}

void bosskill(){
	if((bossmama.bossCoordinateX < rickspaceship.rickspaceshipX + 100 && bossmama.bossCoordinateX + 120 > rickspaceship.rickspaceshipX) && (bossmama.bossCoordinateY < rickspaceship.rickspaceshipY + 100 && bossmama.bossCoordinateY + 100 > rickspaceship.rickspaceshipY)){
		collision = true;
		if(collision){
			  // if(bul == false){
			rick.health -= 10;
			healthX -= 10;
			if(rick.health < 0){
				rick.health = 0;
				healthX = 0; 
				newg = 1; 
			}
		  }
		// }
	
	}

}


//Boss code end






 // Main character movemnent
void charactermovement(){
	if(rick.rickshow){
	iShowBMP2(rick.jerryCordinateX,rick.jerryCordinateY,jerry[rick.jerryIndex],0);
	}
}



void spaceMovement(){
	for(int i = 0; i < 5; i++){
		if(space[i].spaceShow){
			iShowBMP2(space[i].spaceX,space[i].spaceY,spaceship[space[i].spaceIndex],0);
		}
	}
}


void fireMovement(){
	for(int i = 0; i < 5; i++){
		if(agun[i].fireShow){
			iShowBMP2(agun[i].fireX,agun[i].fireY,bomb[agun[i].fireIndex],0);
		}
	}
}



void setSpaceVariable()
{
	for(int i = 0; i < 5; i++)
	{
		space[i].spaceX = screenWidth + rand()%500;
		space[i].spaceY = 700;
		space[i].spaceIndex = rand()%5;
		space[i].spaceShow = true;
	}
}




void setFireVariable()
{
	for(int i = 0; i < 5; i++)
	{
		
		agun[i].fireX =-10;
		agun[i].fireY = 700+rand()%5;
		agun[i].fireIndex = rand()%5;
		agun[i].fireShow = true;
	}
}



void changespace(){	

	for(int i = 0; i < 5; i++){
		space[i].spaceX -= 30;
		if(space[i].spaceX < 0){
			space[i].spaceX = screenWidth + rand()%900;
		}
		space[i].spaceIndex++;
		if(space[i].spaceIndex >= 3){
			space[i].spaceIndex = 0;
		}
	}

}



void changefire(){	

	for(int i = 0; i < 5; i++){
		agun[i].fireY -= 20;
		agun[i].fireX -=20;
		if(agun[i].fireY <= 0 && space[i].spaceX<750 ){
			agun[i].fireY =700+rand()%3;
			agun[i].fireX =space[i].spaceX +rand()%3;
		}
		agun[i].fireIndex++;
		if(agun[i].fireIndex >= 3){
			agun[i].fireIndex = 0;
		}
	}

	
}



void levels()     //for sheild 
{
 if(rick.score>sheild_score && rick.score<sheild_score+150)
 {
	// sheild_score+=50; 
	 if(sheild_op){
 iShowBMP2(300,0,"option sheild.bmp",0);
	 }
 
 
if((rick.jerryCordinateX + 128>300+34 &&  rick.jerryCordinateX<300+34) && (rick.jerryCordinateY + 128>10 &&  rick.jerryCordinateY<10+44)) //when rick touches the sheild option a sheild bar appears
			{
				
				sheild_op = false;
				sheild= true;
				
			}
for(int i=0;i<5;i++)
{
if((enemy[i].birdX< dx+180 && enemy[i].birdX+150>dx) && (enemy[i].birdY<dy+180 && enemy[i].birdY+123>0))  //when enemy will collide to sheild.
{
	//iFilledRectangle(10,0,100,100);
	gron=false;
	rick.health = rick.health ;
		   healthX = healthX ;
}
if(( dy<agun[i].fireY +31 && dy+180>agun[i].fireY) && ( dx<agun[i].fireX +36 && dx+180>agun[i].fireX ))   //new
    //when enemy will collide to sheild.
{
	iFilledRectangle(10,100,100,100);
	firesheild = false;
	rick.health = rick.health ;
		   healthX = healthX ;

}
		 if(!gron){ 
			 rick.health += rick.health;
		   healthX += healthX;
		 }
		   if(rick.health > 100){
			rick.health = 100;
		    healthX = 139; 
		}
		    if(!firesheild){                                       //new
			 rick.health += rick.health;
		   healthX += healthX;
		 }
		   if(rick.health > 100){
			rick.health = 100;
		    healthX = 139; 
		}
		  
		  bul=false;
}


				
            }	
else if(rick.score>sheild_score+150)
		{
			//sheild_score+=50;
			gron = true;
		bul= false;
				
            }	
 
 else
 {
	 sheild =false;
  }
 }



void bossupor()
{
	if(boss_upore)
	{
		iShowBMP2( rickspaceship.rickspaceshipX,rickspaceship.rickspaceshipY,"bossproper.bmp",0);
	
	}
}


void showshild(){

	if(sheild){
		iShowBMP2( dx,0,"sheild.bmp",0);
		sheild_deactive= false;
	}

}


void bosscoming(){

	if(rick.score>400)

	{
		 if(boss_op){
			iShowBMP2(rickspaceship.rickspaceshipX,rickspaceship.rickspaceshipY,"bossproper.bmp",0);
	 }
	for(int i=0;i<5;i++)
	{
 
		if((rick.jerryCordinateX + 128>rickspaceship.rickspaceshipX &&  rick.jerryCordinateX+128<rickspaceship.rickspaceshipX+140) && (rick.jerryCordinateY + 128>0 &&  rick.jerryCordinateY<0+140))
			//when rick touches the sheild option a sheild bar appears
		{		
				boss_op = false;
				boss_upore= true;
				enemy[i].birdShow = false;
				rick.rickshow=false;
				bul = true;
		}
	}
	}
}


void firecollide()               //new
{
for(int i=0;i<5;i++)
{
   if(( rick.jerryCordinateY<agun[i].fireY +31 && rick.jerryCordinateY+128>agun[i].fireY) && ( rick.jerryCordinateX<agun[i].fireX +36 && rick.jerryCordinateX+128>agun[i].fireX ))
   {
	    iFilledRectangle(300,300,300,300);
	   collision = true;
       agun[i].fireY=1200;
	   agun[i].fireY =700+rand()%3;
	   agun[i].fireX=1200;
	   agun[i].fireX =space[i].spaceX +rand()%3;

	   if(collision){
		   if(bul ==false){
		rick.health -= 10;
		healthX -= 10;

		if(rick.health < 0){
			rick.health = 0;
		    healthX = 0; 
			gameEnd = true;
	   iFilledRectangle(300,300,300,300);
		}
	  }
	   }
   }
 }
}


//// thona code end




// enemy movement 
void enemyMovement(){
	for(int i = 0; i < 5; i++){
		if(enemy[i].birdShow){
			iShowBMP2(enemy[i].birdX,enemy[i].birdY,birds[enemy[i].birdIndex],0);
		}
	}
}




// enemy set variable
void setEnemyVariable()
{
	for(int i = 0; i < 5; i++)
	{
		enemy[i].birdX = screenWidth + rand()%300;
		enemy[i].birdY = 0;
		enemy[i].birdIndex = rand()%10;
		enemy[i].birdShow = true;
	}
}



//Enemy change variable
void change(){	
	for(int i = 0; i < 5; i++){
		enemy[i].birdX -= 10;
		if(enemy[i].birdX < 0){
			enemy[i].birdX = screenWidth + rand()%300;
		}
		enemy[i].birdIndex++;
		if(enemy[i].birdIndex >= 3){
			enemy[i].birdIndex = 0;
		}
	}
}



// Main character's changing cordinate with jump 

void changeRy(){

	if(jumpUp){
		
		rick.jerryCordinateY +=20;
		if(rick.jerryCordinateY >= jump){
			jumpUp = false;
		}
	}else{
		rick.jerryCordinateY -=20;
		if( rick.jerryCordinateY< 0){
			rick.jerryCordinateY=0;
		}

		
	}


}





void enemykill()
{
	for(int i=0;i<5;i++)
	{
	   if((enemy[i].birdX < rick.jerryCordinateX + 100 && enemy[i].birdX + 120 > rick.jerryCordinateX) && (enemy[i].birdY < rick.jerryCordinateY + 100 && enemy[i].birdY + 100 > rick.jerryCordinateY))
	   {
		   collision = true;
		   enemy[i].birdX=1200;
		   enemy[i].birdX=900+rand()%1200;
		   enemy[i].birdY=10;

		   if(collision){
			   if(bul == false){
			rick.health -= 10;
			healthX -= 10;

			if(rick.health < 0){
				rick.health = 0;
				healthX = 0; 
				newg = 1; 
			}
		  }
		 }
	   }
	} 
}



// method for bullet
void gunfire(){
	if(killboss == 0){
	if(fire){
		iShowBMP2(rick.gfX,rick.gfY,"bullets\\gf.bmp",0);
		rick.gfX+=30;
		if(rick.gfX > 1200 ){
			rick.gfX = 80 + rick.jerryCordinateX;
		    rick.gfY = 30 + rick.jerryCordinateY;

		}else if(bc){
			rick.gfX = 80 + rick.jerryCordinateX;
		    rick.gfY = 30 + rick.jerryCordinateY;
		}
		
	}else{
		rick.gfX = 80 + rick.jerryCordinateX;
		rick.gfY= 30 + rick.jerryCordinateY;
		
	}
	}
	if(killboss == 1){
		if(fire){
		iShowBMP2(rickspaceship.spaceShipGunX,rickspaceship.spaceShipGunY,"bullets\\gf.bmp",0);
		rickspaceship.spaceShipGunX+=30;
		if(rickspaceship.spaceShipGunX > 1200 ){
			rickspaceship.spaceShipGunX = 80 + rickspaceship.rickspaceshipX;
		    rickspaceship.spaceShipGunX = 30 + rickspaceship.rickspaceshipY;

		}else if(bc){
			rickspaceship.spaceShipGunX = 80 + rickspaceship.rickspaceshipX;
		    rickspaceship.spaceShipGunY = 30 + rickspaceship.rickspaceshipY;
		}
		
	}else{
		rickspaceship.spaceShipGunX = 80 + rickspaceship.rickspaceshipX;
		rickspaceship.spaceShipGunY= 30 + rickspaceship.rickspaceshipY;
		
	}
	}
	
		
}


//for bullet and enemy collision
void bulletcollision(){
	if(!gameEnd){
		for(int i=0;i<5;i++){
			if((enemy[i].birdX < rick.gfX+25 && enemy[i].birdX + 120 > rick.gfX) && (enemy[i].birdY < rick.gfY + 25 && enemy[i].birdY + 100 > rick.gfY))
			{
				bc = true;
				enemy[i].birdX=1200;
				enemy[i].birdX=900+rand()%1200;
				enemy[i].birdY=10;
				rick.score += 10;
			}else{
				bc = false;
			}
		}
	}

	
}






///game over interface

char fscore[10];
void gameOver(){
	
	iShowBMP(0,0,"bg//GameOver.bmp");
	iSetColor(255, 255, 255);
	iText(450,700,"YOUR SCORE :: ", GLUT_BITMAP_TIMES_ROMAN_24);
	_itoa(rick.score, fscore, 10);
	iText(650, 700, fscore, GLUT_BITMAP_TIMES_ROMAN_24);
	if(newg == 1){
		drawTextBox();
		if(textActivator){
			iSetColor(255, 255, 255);
			iFilledRectangle(450, 220, 250, 30);
			nameInput();
		}	
	}
}


///gameEnds Function 
void gameEnds(){
	

		returnToMainMenu = true;
		newGame = false;
		startGame = false;
		loadGame = false;
		highScore = false;
		instructions = false;
		ex  = false;
		gameS = 0;
		killboss = 0;
		rick.jerryIndex = 0;
        rick.jerryCordinateX = 0;
        rick.jerryCordinateY = 0;
		rick.score = 0;
		rick.health = 100;
		rick.gfX = 80 + rick.jerryCordinateX;
		rick.gfY = 40 + rick.jerryCordinateY;
		
		rickspaceship.rickspaceshipX = 300;
		rickspaceship.rickspaceshipY = 0;
			
}



//// new codes we are trying to implement


///game play functions
void playGame(){
	// for all level
	if(startGame && (killboss == 0)){
		    change();
		    charactermovement();
		    enemyMovement();
		    enemykill();

			//thona function
			spaceMovement();
			fireMovement();
			levels();
			showshild();
			//thona function ends


			bulletcollision();
			gunfire();
			iSetColor(255,0,0);
			iRectangle(1000, 750, 150, 30);
		    iFilledRectangle(999,749,healthX,healthY);
			if(rick.score >= 400)
				killboss = 1;
		
	}else if(startGame && (killboss == 1)){
	       
		    charactermovement();
			bossBulletCollision();
			bosskill();
			firecollide();
			bossupor();
			bosscoming();
			bulletcollision();
			gunfire();
			iSetColor(255,0,0);
			iRectangle(1000, 750, 150, 30);
		    iFilledRectangle(999,749,healthX,healthY);
			bossMovement();
			
	}
}


void Level1(){
	if(!savegamemenu){
		playGame();
	}else{
		iShowBMP2(200,200,"bg\\bg.bmp",0);
	}


}



void scoreboard()
{

		iSetColor(0,0 , 0);
		iText(600, 770, "Score: ", GLUT_BITMAP_TIMES_ROMAN_24);
		char showscore[10];
		_itoa(rick.score, showscore, 10);
		iText(700, 770, showscore, GLUT_BITMAP_TIMES_ROMAN_24);
		
}





//new game function
void NewGame(){

	if(gameS == 1){

		newGame = true;
		returnToMainMenu = false;
		if(newg == 0){
			if(killboss == 0){
				//iShowBMP(0,0,menu[1]);
				for(int i=0; i<10; i++)
				{
					iShowBMP(upperBackground[i].x, upperBackground[i].y , upperBackgroundImage[i]);
					iShowBMP(lowerBackground[i].x, lowerBackground[i].y, lowerBackgroundImage[i]);
				}
				iText(10, 770, " Press F1 button to exit and save the game ", GLUT_BITMAP_TIMES_ROMAN_24);
				Level1();
			
			}

			if(killboss == 1){
				//iShowBMP(0,0,menu[1]);
				for(int i=0; i<10; i++)
				{
					iShowBMP(upperBackground[i].x, upperBackground[i].y , upperBackgroundImage[i]);
					iShowBMP(lowerBackground[i].x, lowerBackground[i].y, lowerBackgroundImage[i]);
				}
				iText(10, 770, " Press F1 button to exit and save the game ", GLUT_BITMAP_TIMES_ROMAN_24);
				Level1();

			}
			
			scoreboard();

			
		}
		
		else if(newg == 1){
				gameOver();
			
		}
		else if(newg == 2){
			gameEnds();
			setEnemyVariable();
			rick.score = 0;
			killboss = 0;
			newg = 0;
		}

		
	
	}

}







//Load Game interface 
void LoadGame(){
	
	if(gameS == 2){
	
		loadgame();
		loadGame = true;
		gameS = 1;
	}

}


//highscore interface 
void HighScore(){
	
	if(gameS == 3){
	highScore = true;
	returnToMainMenu = false;
	iShowBMP(0,0,menu[2]);
	showleaderboard();
	iText(10,10, " Press F1 button to go back ", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}


//instruction interface 
void Instructions(){
	if(gameS == 4){
	iShowBMP(0,0,menu[3]);
	iText(10, 10, " Press F1 button to go back ", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}


//exit interface 
void Exit(){
	if (gameS == -1 && selectMenu == 5){
		exit(0);
	}



}






/// for changing interface
void changeInterface(){
	changeTime = 1;
	menuShow = true;
	
	
}


bool makeMenuShowTrue(){
	if(changeTime==1){
		returnToMainMenu = true;

	}
	return returnToMainMenu;

}


//to show the menu interface
void showMenu(){
	iShowBMP(0,0,menu[0]);
}

//menubar function
void Menu(){
	if(returnToMainMenu){
		showMenu();
	}
		NewGame();
		LoadGame();
		HighScore();
		Instructions();
		Exit();

}




