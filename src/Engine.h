/* Header Template                                       */

#ifndef _HEADER_INCLUDED
#include "ablibs.h"
#include "abimport.h"
#include "proto.h"
#include "structs.h"
#include "stdlib.h"
#include "pthread.h"

//Defining Movement types
#define LEFT 0
#define RIGHT 1
#define DOWN 2

//Defining Block Types
#define I 0
#define J 1
#define L 2
#define O 3
#define S 4
#define T 5
#define Z 6

Block activeBlocks[4];
int lineBlockCount[GridSize];
int type;
int rotation;
int isDebuggingEnabled;
int gamePlaying;
int lost;
int score;
int seconds;

Block createBlock(int x, int y, PgColor_t color);
void moveBlock(Block *block, int difX, int difY);
#define _HEADER_INCLUDED
#endif
