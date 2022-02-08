
# include "iGraphics.h"

bool music = true;

// Game background music part
void musicOn(){
	if(music == true){
	PlaySound("Music\\file_example_WAV_1MG",NULL,SND_LOOP | SND_ASYNC);
	}else if(music == false){
		PlaySound(0,0,0);
	}

}

void musicStop(){
	
	PlaySound(0,0,0);
}

