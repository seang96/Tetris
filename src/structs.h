/* Header Template                                       */

#ifndef _HEADER_INCLUDED
#define GridSize 24
#define BlockSize 4
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
