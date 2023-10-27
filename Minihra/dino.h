#pragma once
#include "DekladationGraphics.h"

class Dino{
  private:
    int a = 0;
    bool jmp = false, kaktus = true, kaktus2 = true;
    int Ydino = 52, cas, poc = 0;
    int Xkaktus = 128, Xkaktus2 = 140;
    char score_cislo[10], score_text[20] = "Score: ";
    int pom, nahodna;
    int pom2, nahodna2;
    void draw(){
          scr.setFont(u8g_font_6x10);
          for (int i = 0; i < 10; i++)
          {
            score_cislo[i] = '\0';
          }
          for (int i = 7; i < 20; i++)
          {
            score_text[i] = '\0';
          }
          sprintf(score_cislo, "%d", cas / 50);
          strcat(score_text, score_cislo);
          scr.drawStr(5, 10, score_text);
          

      scr.drawDisc(30, Ydino, 3, U8G_DRAW_ALL);
      scr.drawLine(0, 55, 128, 55);
      
      if(kaktus){
        scr.drawLine(Xkaktus, 40, Xkaktus, 55);
        scr.drawLine(Xkaktus - 4, 49, Xkaktus, 49);
        scr.drawLine(Xkaktus - 4, 49, Xkaktus - 4, 43);
        scr.drawLine(Xkaktus, 46, Xkaktus + 4, 46);
        scr.drawLine(Xkaktus + 4, 46, Xkaktus + 4, 41);
      }
      if(kaktus2){
        scr.drawLine(Xkaktus2, 40, Xkaktus2, 55);
        scr.drawLine(Xkaktus2 - 4, 49, Xkaktus2, 49);
        scr.drawLine(Xkaktus2 - 4, 49, Xkaktus2 - 4, 43);
        scr.drawLine(Xkaktus2, 46, Xkaktus2 + 4, 46);
        scr.drawLine(Xkaktus2 + 4, 46, Xkaktus2 + 4, 41);
      }
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
      if(cas / 50 > (int) EEPROM.read(0)){
        int a = cas / 50;
        EEPROM.write(0, (byte) a);
      }
      delay(2000);
      Ydino = 52, Xkaktus = 128, Xkaktus2 = 140;
      jmp = false, kaktus = true, kaktus2 = true;
      poc = 0;
    }
  public:
    void dynoMain(){
      scr.firstPage();
      cas++;
      do{
        cas++;
        if(Ydino > 45 && (Xkaktus == 30 || Xkaktus2 == 30)){
          gameOver();
          poc++;
        }
        else{
          if(Xkaktus > 4){
            Xkaktus --;
            kaktus = true;
          }
          else if(Xkaktus == 4){
            kaktus = false;
            pom = Xkaktus + 1;
            nahodna = random(1, 50);     
          }
          else{
            pom ++;
          }
          if(pom == nahodna){
              Xkaktus = 124;
              nahodna = -1;
          }
  
  
          if(Xkaktus2 > 4){
            Xkaktus2 --;
            kaktus2 = true;
          }
          else if(Xkaktus == 4){
            kaktus2 = false;
            pom2 = Xkaktus2 + 1;
            nahodna2 = random(50, 80);     
          }
          else{
              pom2 ++;
            }
            if(pom2 == nahodna2){
                Xkaktus2 = 124;
                nahodna2 = -1;
            }
            if(Xkaktus2 == 4){
              kaktus2 = false;
            }
            
            if(digitalRead(ENTER) == 0){
              jmp = true;
            }
            if(jmp == true){       
              if(a <= 30){
                a++;
                Ydino--;
              }
    
              if(a >= 30 && a < 60){
                a++;
                Ydino++;
              }
              if(a >= 60 && Ydino == 52){
                 a = 0;
                 jmp = false;
              }
            }
        }

        draw();
      }while(scr.nextPage() && game == 1);
    }
};
