#pragma once
#include "DekladationGraphics.h"
#include "Logik2048.h"


class G2048{
  private:
    void draw(){
      scr.drawFrame(20, 0, 60, 60);
      scr.drawLine(35, 0, 35, 60);
      scr.drawLine(50, 0, 50, 60);
      scr.drawLine(65, 0, 65, 60);
      
      scr.drawLine(20, 15, 80, 15);
      scr.drawLine(20, 30, 80, 30);
      scr.drawLine(20, 45, 80, 45);

      scr.setFont(u8g_font_6x10);
      scr.drawStr(85, 10, "Score:");
      scr.drawStr(85, 20, score_text);

      char txt[4][4][4];
      for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
          if(herni_pole[j][i] < 100 && herni_pole[j][i] > 0){
            sprintf(txt[j][i], "%d", herni_pole[j][i]);
          }
          else if(herni_pole[j][i] == 0){
            txt[i][j][0] = '\0';
          }
          else{
            if(herni_pole[j][i] == 128)txt[i][j][0] = 'A';
            if(herni_pole[j][i] == 256)txt[i][j][0] = 'B';
            if(herni_pole[j][i] == 512)txt[i][j][0] = 'C';
            if(herni_pole[j][i] == 1024)txt[i][j][0] = 'D';
            if(herni_pole[j][i] == 2048)txt[i][j][0] = 'E';
          }
        }
      }
      
      scr.drawStr(85, 50, "Win = E");

      int o = 0;
      scr.drawStr(22, 12, txt[0][0]);
      scr.drawStr(37, 12, txt[0][1]);
      scr.drawStr(52, 12, txt[0][2]);
      scr.drawStr(67, 12, txt[0][3]);

      scr.drawStr(22, 27, txt[1][0]);
      scr.drawStr(37, 27, txt[1][1]);
      scr.drawStr(52, 27, txt[1][2]);
      scr.drawStr(67, 27, txt[1][3]);

      scr.drawStr(22, 42, txt[2][0]);
      scr.drawStr(37, 42, txt[2][1]);
      scr.drawStr(52, 42, txt[2][2]);
      scr.drawStr(67, 42, txt[2][3]);

      scr.drawStr(22, 57, txt[3][0]);
      scr.drawStr(37, 57, txt[3][1]);
      scr.drawStr(52, 57, txt[3][2]);
      scr.drawStr(67, 57, txt[3][3]);

      for (int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
          for(int k = 0; k < 4; k++){
            txt[i][j][k] = '\0';
          }
        }
      }
      
    }

    
    void Gwin(){
      if(score > (int) EEPROM.read(4)){
        EEPROM.write(2, (byte) score);
      }
    }
    void Glose(){
      if(score > (int) EEPROM.read(4)){
        EEPROM.write(2, (byte) score);
      }
    }
  public:
    void main2048(){
        scr.firstPage();
        do{
          if(digitalRead(UP) == 0){
            upArrow_eventReaction();
          }
          if(digitalRead(DOWN) == 0){
            downArrow_eventReaction();
          }
          if(digitalRead(R) == 0){
            rightArrow_eventReaction();
          }
          if(digitalRead(L) == 0){
            leftArrow_eventReaction();
          }
          if(win() == true){
            Gwin();
          }
          if(lose() == true){
            Glose();
          }
          draw();
          delay(100);
        }while(scr.nextPage() && game == 2);
    }
  
};
