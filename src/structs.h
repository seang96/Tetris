/* Header Template                                       */

#ifndef _HEADER_INCLUDED
#define GridSize 17
#define BlockSize 4
#define BlockDimension 16
#define MiddleBlock BlockDimension/2

typedef struct {
	int x;
	int y;
	PtWidget_t *b;
} Block;

struct grid {
	PtWidget_t *block;
} GRID[GridSize][GridSize];
#define _HEADER_INCLUDED
#endif
