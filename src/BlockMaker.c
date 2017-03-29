#include "Engine.h"

void createBlock(int x, int y, PgColor_t color) {
	PtWidget_t *parent = AbGetABW(ABN_base),
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
	GRID[x][y].isMoving = 1;
}

void newGame(void)
{
	clearBlocks();
	createBlock(11, 0, Pg_BLUE);
	createBlock(12, 0, Pg_BLUE);
	createBlock(12, 1, Pg_BLUE);
	createBlock(13, 1, Pg_BLUE);
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
				PtDestroyWidget(GRID[x][y].block);
			GRID[x][y].block = 0;
			GRID[x][y].isMoving = 0;
		}
	}
}

void moveLeft(void)
{
	pos positions[BlockSize];
	int blockIndex = 0;
	int x;
	for (x = 0; x < GridSize; x++)
	{
		int y;
		for (y= 0; y < GridSize; y++)
		{
			if (GRID[x][y].isMoving)
			{
				pos position;
				position.x = x;
				position.y = y;
				position.block = GRID[x][y].block;

				positions[blockIndex] = position;

				blockIndex++;
				if (blockIndex == BlockSize)
				{
					x = GridSize;
					y = GridSize;
				}
			}
		}
	}
	int isValid = 1;
	for (blockIndex = 0; blockIndex < BlockSize && isValid; blockIndex++)
	{
		if (positions[blockIndex].x == 0)
			isValid = 0;
	}
	if (isValid) {
		for (blockIndex = 0; blockIndex < BlockSize; blockIndex++)
		{


			moveBlock(positions[blockIndex], -1, 0);
		}
	}
}

void moveRight(void)
{

}

void moveDown(void)
{

}

void moveBlock(pos position, int difX, int difY)
{
	PtWidget_t *block = position.block;
	PhPoint_t pos = {(position.x + difX)*20, (position.y + difY)*20};
	PtArg_t args[1];

	PtSetArg(&args[0], Pt_ARG_POS, &pos, 0);
	PtSetResources(block, 1, args);

	GRID[position.x+difX][position.y+difY].block = block;
	GRID[position.x+difX][position.y+difY].isMoving = 1;

	GRID[position.x][position.y].block = 0;
	GRID[position.x][position.y].isMoving = 0;
}

