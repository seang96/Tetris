/* Header Template                                       */

#ifndef _HEADER_INCLUDED
#include "ablibs.h"
#include "abimport.h"

//typedef struct {
//	int x;
//	int y;
//	PtWidget_t *block;
//} pos;

#include "proto.h"
#define GridSize 24
#define BlockSize 4
struct grid {
	PtWidget_t *block;
	int isMoving;
} GRID[GridSize][GridSize];



#define _HEADER_INCLUDED
#endif
