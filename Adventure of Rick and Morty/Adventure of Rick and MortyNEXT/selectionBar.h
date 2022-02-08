#include "images.h"
#include<stdio.h>
#include<cstdlib>
#include<cstring>
int enemynumber=0;


int gameS=0;
bool gameEnd =  false;


bool startGame = false;
bool newGame = false;
bool loadGame = false;
bool instructions = false;
bool opt = false;
bool highScore = false;
bool ex = false;

int state;

bool textActivator = false;

char str[100], str2[100];
int len;
int mode;

void showleaderboard();



//draw the box for name input
void drawTextBox()
{
	iSetColor(150, 150, 150);
	iRectangle(450, 220, 250, 30);
	iText(10, 10, "CLICK THE BOX TO ACTIVATE AND ENTER YOUR NAME");
}

//to take player name
void nameInput(){
	
		iSetColor(255, 0, 0);
		iText(550, 230, str);
	   
}




// rick character structure

struct rickStruct{
	int jerryIndex; 
    int jerryCordinateX; 
    int jerryCordinateY; 
	int score; 
	int health; 
	int gfX;
	int gfY;
	bool rickshow;

	rickStruct(){
		jerryIndex = 0;
        jerryCordinateX = 0;
        jerryCordinateY = 0;
		score = 0;
		health = 150;
		gfX = jerryCordinateX + 0;
		gfY = jerryCordinateY+ 0;
		rickshow = true;
	}

}rick;




// enemy character structure

struct habijabi{
	int birdX;
	int birdY;
	int birdIndex;
	bool birdShow;
};
habijabi enemy[5];



// Small spaceship


struct hj{
	int spaceX;
	int spaceY;
	int spaceIndex;
	bool spaceShow;
};
hj space[5];



// small spaceship gun
struct fr{
	int fireX;
	int fireY;
	int fireIndex;
	bool fireShow;
};
 fr agun[5];



 // rick spaceship

 struct rickspaceshipstuff{

	 int rickspaceshipX;
	 int rickspaceshipY;
	 int spaceShipGunX;
	 int spaceShipGunY;

	 rickspaceshipstuff(){
		 rickspaceshipX = 300;
		 rickspaceshipY=0;
		 spaceShipGunX = 0 + rickspaceshipX;
	     spaceShipGunY = 0 + spaceShipGunY;

	 }

 }rickspaceship;




 struct Boss{
	int bossCoordinateX;
	int bossCoordinateY;
	int bosshealth;
	bool bossShow;
	int bossBulletX;
	int bossBulletY;
	Boss(){
		bossCoordinateX = screenWidth-100;
		bossCoordinateY = 500;
		bosshealth = 200;
		bossShow = true;
		bossBulletX = 40 + bossCoordinateX;
		bossBulletY = 40 + bossBulletY;
	
	}
}bossmama;







//codes for highscore interface
struct highScore{

	char name[30];
	int score;
}highscore[1000];


//sorting the leaderbord
void sortleaderboard()
{
	for (int i = 0; i < state - 1; i++){
		for (int j = i + 1; j < state; j++){
			if (highscore[i].score < highscore[j].score){
				int temp;
				temp = highscore[i].score;
				highscore[i].score = highscore[j].score;
				highscore[j].score = temp;
				//
				char temp3[100];
				strcpy(temp3, highscore[i].name);
				strcpy(highscore[i].name, highscore[j].name);
				strcpy(highscore[j].name, temp3);
			}
		}
	}
}

//updating it
void updateleaderboard()
{
	sortleaderboard();
	FILE *fp;
	fp = fopen("score.txt", "a");
	for (int i = 0; i < state; i++){
		fprintf(fp, "%s %d\n", highscore[i].name, highscore[i].score);
		//printf("%s\n",highscore[i].name);
	}
	fclose(fp);
	fp = fopen("state.txt", "w");
	fprintf(fp,"%d", state);
	fclose(fp);
}


//creating two file
void leaderboard()
{
	FILE *fp;
	fp = fopen("state.txt", "r");
	fscanf(fp, "%d", &state);
	fclose(fp);
	fp = fopen("score.txt", "r");
	for (int i = 0; i < state; i++){
		fscanf(fp, "%s   %d", &highscore[i].name, &highscore[i].score);
	}
}


//showing the leaderboard for top 5
void showleaderboard()
{
		int k = 5, x = 82, y = 600;
		if (state < 5) k = state;
		for (int i = 0; i < k; i++, y -= 70){
			char temp4[10], temp5[5];
			_itoa(highscore[i].score, temp4, 10);
			_itoa(i + 1, temp5, 10);
			iSetColor(255, 255, 255);
			iText(250, y, temp5, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(500, y, highscore[i].name, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(730, y, temp4, GLUT_BITMAP_TIMES_ROMAN_24);
		}
}






//codes of load game interface


///save game function
void savegame()
{
	FILE *fp;
	fp = fopen("player.txt", "w");
	fprintf(fp, "%d %d %d %d %d %d %d\n", rick.jerryCordinateX, rick.jerryCordinateY, rick.score, rick.health,rick.jerryIndex,rick.gfX,rick.gfY);
	fclose(fp);

	fp = fopen("enemy.txt", "w");
	for (int i = 0; i < 5; i++){
			fprintf(fp, "%d %d %d\n", enemy[i].birdIndex, enemy[i].birdX, enemy[i].birdY);
	}
	fclose(fp);



	fp = fopen("smallspaceship.txt", "w");
	for (int i = 0; i < 5; i++){
		fprintf(fp, "%d %d %d\n", space[i].spaceX, space[i].spaceY, space[i].spaceIndex);
	}
	fclose(fp);


	fp = fopen("agun.txt", "w");
	for (int i = 0; i < 5; i++){
		fprintf(fp, "%d %d %d\n", agun[i].fireX, agun[i].fireY, agun[i].fireIndex);
	}
	fclose(fp);


	fp = fopen("boss.txt", "w");
	fprintf(fp, "%d %d %d %d %d\n", bossmama.bossCoordinateX, bossmama.bossCoordinateY,bossmama.bosshealth,bossmama.bossBulletX,bossmama.bossBulletY);
	fclose(fp);

	
}



///load game function
void loadgame()
{
	FILE *fp;
	fp = fopen("player.txt", "r");
	fscanf(fp, "%d %d %d %d %d %d %d\n", &rick.jerryCordinateX, &rick.jerryCordinateY, &rick.score, &rick.health,&rick.jerryIndex,&rick.gfX,&rick.gfY);
	fclose(fp);

	fp = fopen("enemy.txt", "r");
	for (int i = 0; i < 5; i++){
			fscanf(fp, "%d %d %d\n", &enemy[i].birdIndex, &enemy[i].birdX, &enemy[i].birdY);
	}
	fclose(fp);

	fp = fopen("smallspaceship.txt", "r");
	for (int i = 0; i < 5; i++){
		fscanf(fp, "%d %d %d\n", &space[i].spaceX, &space[i].spaceY, &space[i].spaceIndex);
	}
	fclose(fp);


	fp = fopen("agun.txt", "r");
	for (int i = 0; i < 5; i++){
		fprintf(fp, "%d %d %d\n", &agun[i].fireX, &agun[i].fireY, &agun[i].fireIndex);
	}
	fclose(fp);



	
	fp = fopen("boss.txt", "r");
	fprintf(fp, "%d %d %d %d %d\n", &bossmama.bossCoordinateX, &bossmama.bossCoordinateY, &bossmama.bosshealth, &bossmama.bossBulletX, &bossmama.bossBulletY);
	fclose(fp);
	
}