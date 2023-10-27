#pragma once
#include "DekladationGraphics.h"
#define Rect 5

    typedef struct{
      int x;
      int y;
    }Point;

    class Pozice{
      public:
        Point pix;
        int ix;
        int iy;
        bool block = false, down = false;
        Point count(int x, int y){
          Point bod;
          bod.x = 21 + x * 6;
          bod.y = 60 - y * 6;
          return bod;
        }
      public:

        void naplnBlok(int x, int y){
          this-> ix = x;
          this-> iy = y;
          this-> pix = count(x, y);
          this-> block = false;
        }
        void drawRectOnPosition(bool block){
          this-> block = block;
        }
        bool getBlock(){
          return this->block;
        }
        int getX(){
          return this-> pix.x;
        }
        int getY(){
          return this-> pix.y;
        }
        bool getDown(){
          return this->down;
        }

    };

class Tetris{
  private:
  int rot = 0;
  int blok = 0;
    
    class Dilek{
      public:
        Point dilek;
      public:
        void umisniDilek(int x, int y){
          this-> dilek.x = x;
          this-> dilek.y = y;
          if(blok == 1){
            if(rot == 0 || rot == 3){
              if(!pos[dilek.x][dilek.y + 1].getDown()) {
                pos[dilek.x][dilek.y - 2].drawRectOnPosition(false);
              }
              pos[dilek.x][dilek.y - 1].drawRectOnPosition(true);
              pos[dilek.x][dilek.y].drawRectOnPosition(true);
              pos[dilek.x][dilek.y + 1].drawRectOnPosition(true);
            }
            else if(rot == 1 || rot == 2){
              if(!pos[dilek.x][dilek.y].getDown() && !pos[dilek.x + 1][dilek.y].getDown() && !pos[dilek.x + 1][dilek.y].getDown()) {
                pos[dilek.x + 1][dilek.y - 1].drawRectOnPosition(false);
                pos[dilek.x][dilek.y - 1].drawRectOnPosition(false);
                pos[dilek.x - 1][dilek.y - 1].drawRectOnPosition(false);
              }
              pos[dilek.x - 1][dilek.y].drawRectOnPosition(true);
              pos[dilek.x][dilek.y].drawRectOnPosition(true);
              pos[dilek.x + 1][dilek.y].drawRectOnPosition(true);
            }
    
          }
          if(blok == 2){
            
          }
          if(blok == 3){
            
          }
          if(blok == 4){
              if(!pos[dilek.x][dilek.y + 1].getDown()) {
                pos[dilek.x][dilek.y - 2].drawRectOnPosition(false);
              }
              pos[dilek.x + 1][dilek.y].drawRectOnPosition(true);
              pos[dilek.x][dilek.y].drawRectOnPosition(true);
              pos[dilek.x][dilek.y + 1].drawRectOnPosition(true);
              pos[dilek.x + 1][dilek.y + 1].drawRectOnPosition(true);
          }
        }
    };

    Dilek puclik[20];
    void draw(){
      scr.drawFrame(20, -1, 58, 60);
      scr.drawStr(85, 10, "Score:");
      scr.drawStr(85, 20, "0");
      blok = 4;
      puclik[0].umisniDilek(2, 2);
    }
  public:
    void mainTetris(){
          Pozice pos = new Pozice[6][10];
        for(int i = 0; i < 6; i++){
          for(int j = 0; j < 10; j++){
            pos[i][j].naplnBlok(i, j);
          }
        }
        
        scr.firstPage();
        do{
          draw();
          for(int i = 0; i < 10; i++){
            for(int j = 0; j < 6; j++){
              if(pos[i][j].getBlock() == true){
                  scr.drawBox(pos[i][j].getX(), pos[i][j].getY(), Rect, Rect);
              }
            }
          }
        delay(10);
        }while(scr.nextPage() && game == 3);
    }
};
