#pragma once

#define UP 5
#define DOWN 6
#define R 7
#define L 8
#define ENTER 9

#define Xmax 128
#define Ymax 64

#include "U8glib.h"
#include "EEPROM.h"
U8GLIB_SSD1306_128X64 scr(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);


int game;
