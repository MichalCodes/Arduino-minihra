#pragma once 
#include "DekladationGraphics.h"

class Best{
  private:
    char score[20];
    int posun = 0;
    void draw(){
      scr.setFont(u8g_font_unifont);
      scr.drawStr(20, 10 - posun, "Top Scores");
      scr.setFont(u8g_font_6x10);
      
      scr.drawStr(5, 25 - posun, "Dino:");
      byte topDino = EEPROM.read(0);
      sprintf(score, "%d", (int)topDino);
      scr.drawStr(40, 25 - posun, score);
      
      scr.drawStr(5, 40 - posun, "Sqash:");
      byte topSqash = EEPROM.read(4);
      sprintf(score, "%d", (int)topSqash);
      scr.drawStr(43, 40 - posun, score);
      
      scr.drawStr(5, 55 - posun, "Tetris:");
      byte topTetris = EEPROM.read(3);
      sprintf(score, "%d", (int)topTetris);
      scr.drawStr(49, 55 - posun, score);

      scr.drawStr(5, 70 - posun, "2048:");
      byte top2048 = EEPROM.read(2);
      sprintf(score, "%d", (int)top2048);
      scr.drawStr(49, 70 - posun, score);

      scr.drawCircle(120, 6, 5, U8G_DRAW_UPPER_LEFT);
      scr.drawCircle(120, 6, 5, U8G_DRAW_UPPER_RIGHT);
      scr.drawLine(115, 6, 115, 57);
      scr.drawLine(125, 6, 125, 57);
      scr.drawCircle(120, 57, 5, U8G_DRAW_LOWER_LEFT);
      scr.drawCircle(120, 57, 5, U8G_DRAW_LOWER_RIGHT);

      scr.drawDisc(120, 6 + posun, 3, U8G_DRAW_UPPER_LEFT);
      scr.drawDisc(120, 6 + posun, 3, U8G_DRAW_UPPER_RIGHT);
      scr.drawBox(117, 6 + posun, 7, 39);
      scr.drawDisc(120, 45 + posun, 3, U8G_DRAW_LOWER_LEFT);
      scr.drawDisc(120, 45 + posun, 3, U8G_DRAW_LOWER_RIGHT);
    }
  public:
    void mainSc(){
        scr.firstPage();
        do{
          if(digitalRead(ENTER) == 0){
            game = 0;
          }
          if(digitalRead(DOWN) == 0){
            posun = 12;
          }
          if(digitalRead(UP) == 0){
            posun = 0;
          }
          draw();
        }while(scr.nextPage() && game == 5);
    }
};
