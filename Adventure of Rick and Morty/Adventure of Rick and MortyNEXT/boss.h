#include "gamePlay.h"


int bossdx = 10;
int bossdy = 10;

void bossMovement(){
	if(rick.score >= 400){
	
		iShowBMP2(bossmama.bossCoordinateX,bossmama.bossCoordinateY,"character\\enemy1.bmp",0);

		bossmama.bossCoordinateX -=bossdx;
		bossmama.bossCoordinateY -=bossdy;


	if(bossmama.bossCoordinateX > (screenWidth-100) || bossmama.bossCoordinateX < 600){
		bossdx= -bossdx;
	}

	if(bossmama.bossCoordinateY > (screenHeight-100) || bossmama.bossCoordinateY  < 600){
		bossdy = -bossdy;
	}
	}


}

void bossBulletCollision(){
	if(!gameEnd){
		
			if((bossmama.bossCoordinateX < rick.gfX+25 && bossmama.bossCoordinateX + 120 > rick.gfX) && (bossmama.bossCoordinateY < rick.gfY + 25 && bossmama.bossCoordinateY + 100 > rick.gfY))
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
	if((bossmama.bossCoordinateX < rick.jerryCordinateX + 100 && bossmama.bossCoordinateX + 120 > rick.jerryCordinateX) && (bossmama.bossCoordinateY < rick.jerryCordinateX + 100 && bossmama.bossCoordinateY + 100 > rick.jerryCordinateY)){
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
