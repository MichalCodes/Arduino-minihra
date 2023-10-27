#pragma once
#include "DekladationGraphics.h"

class Sqash{
private:
  bool up = true, right = true;
  int palkaY = 18;
  char score_cislo[10], score_text[20] = "Score: ";
  int x = 1;
  int y = 32;
  int score = 0;
  
  void draw(){
    scr.drawLine(0, 0, 0, 64);
    scr.drawLine(100, palkaY, 100, palkaY + 15);
    scr.drawPixel(x, y);
    
          scr.setFont(u8g_font_6x10);
          for (int i = 0; i < 10; i++)
          {
            score_cislo[i] = '\0';
          }
          for (int i = 7; i < 20; i++)
          {
            score_text[i] = '\0';
          }
          sprintf(score_cislo, "%d", score);
          strcat(score_text, score_cislo);
          scr.drawStr(5, 10, score_cislo);
      
  }
  void gameOver(){

    int i;
      game = 0;
      scr.firstPage();
      do{
        i++;
        scr.setFont(u8g_font_unifont);
        scr.drawStr(20, 30, "GAME OVER");
        scr.drawStr(20, 60, score_text);
      }while(scr.nextPage() && i < 10);
      if(score > (int) EEPROM.read(4)){
        EEPROM.write(4, (byte) score);
      }
      delay(2000);
      score = 0, x = 1, y = 32;
  }
public:

  void mainSqash(){
    scr.firstPage();
    do{
      if(digitalRead(UP) == 0 && palkaY > 0){
        palkaY--;
      }
      if(digitalRead(DOWN) == 0 && palkaY + 15 < 64){
        palkaY++;
      }
      if(x == Xmax){
        gameOver();
      }
      if(x == 0){
        right = true;
      }
      if(y == Ymax){
        up = true;
      }
      if(y == 0){
        up = false;
      }
      if(y >= palkaY && y <= palkaY + 15 && x == 100){
        right = false;
        score++;
      }
      if(right){
        x ++;
      }
      if(!right){
        x --;
      }
      if(up){
        y --;
      }
      if(!up){
        y ++;
      }
      draw();
    }while(scr.nextPage() && game == 4);
  }
};
