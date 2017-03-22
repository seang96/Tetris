/* Header Template                                       */

#ifndef _HEADER_INCLUDED
#include "ablibs.h"
#include "abimport.h"
#include "proto.h"
#include "structs.h"

#define LEFT 0
#define RIGHT 1
#define DOWN 2

Block activeBlocks[4];
int isDebuggingEnabled;

Block createBlock(int x, int y, PgColor_t color);
void moveBlock(Block *block, int difX, int difY);
#define _HEADER_INCLUDED
#endif
