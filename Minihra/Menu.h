#pragma once
#include "DekladationGraphics.h"
#include "dino.h"

typedef struct{
  int x = 5;
  int y = 25;
} FramePos;
FramePos fpos;

class Menu{
  public:
    void ShowMenu(){
      scr.setFont(u8g_font_unifont);
      scr.drawStr(45, 10, "Menu");
      scr.setFont(u8g_font_6x10);
      scr.drawFrame(fpos.x, fpos.y, 40, 16);
      scr.drawStr(8, 35, "Dyno");
      scr.drawStr(8, 55, "2048");
      scr.drawStr(72, 35, "Tetris");
      scr.drawStr(72, 55, "Sqash");
    }
    
    void Click(){
      if(digitalRead(UP) == 0 && digitalRead(DOWN) == 0){
        game = 5;
      }
      if(digitalRead(R) == 0){
        fpos.x = 70;
      }
      if(digitalRead(L) == 0){
        fpos.x = 5;
      }
      if(digitalRead(UP) == 0){
        fpos.y = 25;
      }
      if(digitalRead(DOWN) == 0){
        fpos.y = 45;
      }
      if(digitalRead(ENTER) == 0 && fpos.x == 5 && fpos.y == 25){
        game = 1;
      }
      if(digitalRead(ENTER) == 0 && fpos.x == 5 && fpos.y == 45){
        game = 2;
      }
      if(digitalRead(ENTER) == 0 && fpos.x == 70 && fpos.y == 25){
        game = 3;
      }
      if(digitalRead(ENTER) == 0 && fpos.x == 70 && fpos.y == 45){
        game = 4;
      }
   }
};
