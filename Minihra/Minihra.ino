#include "Menu.h"
#include "dino.h"
#include "Game2048.h"
//#include "Tetris.h"
#include "Sqash.h"
#include "Logik2048.h"
#include "DekladationGraphics.h"
#include "BestSc.h"

Menu menu;
Dino dino;
G2048 g2048;
//Tetris tetris;
Sqash sqash;
Best best;

void setup() {
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(R, INPUT_PULLUP);
  pinMode(L, INPUT_PULLUP);
  pinMode(ENTER, INPUT_PULLUP);
  EEPROM.write(2, 0);
  scr.setRot180();
  Nulove_pole();
  herni_pole[nahodna_pozice(4)][nahodna_pozice(4)] = 2;
}


void loop() {
  scr.firstPage();
  do{
    menu.Click();
    if(game == 1){
       dino.dynoMain();
    }
    else if(game == 2){
       g2048.main2048();
    }
    else if(game == 3){
       //tetris.mainTetris();
    }
    else if(game == 4){
        sqash.mainSqash();
    }
    else if(game == 5){
        best.mainSc();
    }
    else{
      menu.ShowMenu();
    }
    delay(100);
  }while(scr.nextPage());
}
