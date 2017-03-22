#include "Engine.h"

Block createBlock(int x, int y, PgColor_t color)
{
	PtWidget_t *parent = ABW_base,
		 *block;

	PtArg_t args[3];
	PhPoint_t pos = { x*20,y*20 };
	PhDim_t size = { 20, 20 };
	PtSetArg(&args[0], Pt_ARG_POS, &pos, 0);
	PtSetArg(&args[1], Pt_ARG_DIM, &size, 0);
	PtSetArg(&args[2], Pt_ARG_FILL_COLOR, color, 0);

	block = PtCreateWidget(PtContainer, parent, 3, &args);
	PtRealizeWidget(block);

	GRID[x][y].block = block;

	Block b = {
		.x = x,
		.y = y,
		.b = block,
	};
	return b;
}

void createPiece(void)
{
	activeBlocks[0] = createBlock(11, 0, Pg_BLUE);
	activeBlocks[1] = createBlock(12, 0, Pg_BLUE);
	activeBlocks[2] = createBlock(12, 1, Pg_BLUE);
	activeBlocks[3] = createBlock(13, 1, Pg_BLUE);
}

void newGame(void)
{
	clearBlocks();
	createPiece();
}

void clearBlocks(void)
{
	int x;
	for (x = 0; x < GridSize; x++)
	{
		int y;
		for (y = 0; y < GridSize; y++)
		{
			if (GRID[x][y].block != 0)
			{
				PtDestroyWidget(GRID[x][y].block);
				GRID[x][y].block = 0;
			}
		}
	}
	for (x = 0; x < BlockSize; x++)
	{
		if (activeBlocks[x].b != 0)
		{
			PtDestroyWidget(activeBlocks[x].b);
			activeBlocks[x].b = 0;
		}
	}
}

void moveLeft(void)
{
	int blockIndex;
	if (isMoveValid(LEFT))
		for (blockIndex = 0; blockIndex < BlockSize; blockIndex++)
			moveBlock(&activeBlocks[blockIndex], -1, 0);
}

void moveRight(void)
{
	int blockIndex;
	if (isMoveValid(RIGHT))
		for (blockIndex = 0; blockIndex < BlockSize; blockIndex++)
			moveBlock(&activeBlocks[blockIndex], 1, 0);
}

void moveDown(void)
{
	int blockIndex;
	if (isMoveValid(DOWN))
		for (blockIndex = 0; blockIndex < BlockSize; blockIndex++)
			moveBlock(&activeBlocks[blockIndex], 0, 1);
}

int isMoveValid(int direction) {
	int xBound = -1, yBound = -1, blockIndex;
	switch (direction)
	{
		case LEFT:
			xBound = 0;
			break;
		case RIGHT:
			xBound = 23;
			break;
		case DOWN:
			yBound = 23;
			break;
	}
	for (blockIndex = 0; blockIndex < BlockSize; blockIndex++)
	{
		if (xBound != -1 && activeBlocks[blockIndex].x == xBound ||
			yBound != -1 && activeBlocks[blockIndex].y == yBound)
			return 0;
	}
	return 1;
}
void moveBlock(Block *block, int difX, int difY)
{
	PhPoint_t pos = {(block->x + difX)*20, (block->y + difY)*20};
	PtArg_t args[1];

	PtSetArg(&args[0], Pt_ARG_POS, &pos, 0);
	PtSetResources(block->b, 1, args);

	GRID[block->x+difX][block->y+difY].block = block->b;
	GRID[block->x][block->y].block = 0;

	block->x += difX;
	block->y += difY;
	
	if (isDebuggingEnabled)
		debug();
}

void debug(void)
{
	char debugDisplay[100];
	sprintf(debugDisplay, "0: .x: %ld .y: %ld\n1: .x: %ld .y: %ld\n2: .x: %ld .y: %ld\n3: .x: %ld .y: %ld\n", activeBlocks[0].x, activeBlocks[0].y,activeBlocks[1].x, activeBlocks[1].y, activeBlocks[2].x, activeBlocks[2].y, activeBlocks[3].x, activeBlocks[3].y);
	PtArg_t args[1];
	PtSetArg(&args[0], Pt_ARG_TEXT_STRING, debugDisplay, 0);
	PtSetResources(ABW_testLabel, 1, args);
}
