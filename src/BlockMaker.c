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

	block = PtCreateWidget(PtPane, parent, 3, &args);
	PtRealizeWidget(block);

	GRID[x][y].block = block;

	Block b = {
		.x = x,
		.y = y,
		.b = block,
	};
	return b;
}

void createI(void)
{
	activeBlocks[0] = createBlock(10, 0, Pg_VGA8);
	activeBlocks[1] = createBlock(11, 0, Pg_VGA8);
	activeBlocks[2] = createBlock(12, 0, Pg_VGA8);
	activeBlocks[3] = createBlock(13, 0, Pg_VGA8);
}

void createJ(void)
{
	activeBlocks[0] = createBlock(11, 0, Pg_VGA9);
	activeBlocks[1] = createBlock(12, 0, Pg_VGA9);
	activeBlocks[2] = createBlock(13, 0, Pg_VGA9);
	activeBlocks[3] = createBlock(13, 1, Pg_VGA9);
}

void createL(void)
{
	activeBlocks[0] = createBlock(11, 0, Pg_VGAA);
	activeBlocks[1] = createBlock(12, 0, Pg_VGAA);
	activeBlocks[2] = createBlock(13, 0, Pg_VGAA);
	activeBlocks[3] = createBlock(11, 1, Pg_VGAA);
}

void createO(void)
{
	activeBlocks[0] = createBlock(11, 0, Pg_VGAB);
	activeBlocks[1] = createBlock(11, 1, Pg_VGAB);
	activeBlocks[2] = createBlock(12, 0, Pg_VGAB);
	activeBlocks[3] = createBlock(12, 1, Pg_VGAB);
}

void createS(void)
{
	activeBlocks[0] = createBlock(11, 1, Pg_VGAC);
	activeBlocks[1] = createBlock(12, 0, Pg_VGAC);
	activeBlocks[2] = createBlock(12, 1, Pg_VGAC);
	activeBlocks[3] = createBlock(13, 0, Pg_VGAC);
} 

void createT(void)
{
	activeBlocks[0] = createBlock(11, 0, Pg_VGAD);
	activeBlocks[1] = createBlock(12, 0, Pg_VGAD);
	activeBlocks[2] = createBlock(13, 0, Pg_VGAD);
	activeBlocks[3] = createBlock(12, 1, Pg_VGAD);
}

void createZ(void)
{
	activeBlocks[0] = createBlock(11, 0, Pg_VGAE);
	activeBlocks[1] = createBlock(12, 0, Pg_VGAE);
	activeBlocks[2] = createBlock(12, 1, Pg_VGAE);
	activeBlocks[3] = createBlock(13, 1, Pg_VGAE);
}

void createPiece(void)
{
	int type = rand() % 6;
	switch (type) {
		case 0:
			createI();
			break;
		case 1:
			createJ();
			break;
		case 2:
			createL();
			break;
		case 3:
			createO();
			break;
		case 4:
			createS();
			break;
		case 5:
			createT();
			break;
		case 6:
			createZ();
			break;
	}
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
	else
		createPiece();
}

int isMoveValid(int direction) {
	int xBound = -1, yBound = -1, blockIndex;
	switch (direction)
	{
		case LEFT:
			xBound = 0;
			break;
		case RIGHT:
			xBound = GridSize - 1;
			break;
		case DOWN:
			yBound = GridSize - 1;
			break;
	}
	for (blockIndex = 0; blockIndex < BlockSize; blockIndex++)
	{
		if (activeBlocks[blockIndex].b == 0 || //Fail if no active block
			activeBlocks[blockIndex].y == GridSize - 1 ||	//Fail if at bottom
			xBound != -1 && activeBlocks[blockIndex].x == xBound ||	//Fail if x out of bounds
			yBound != -1 && activeBlocks[blockIndex].y == yBound)	//Fail if y out of bounds
			return 0;

		//Check if colliding with an inactive block
		int adjacentBlockX = -1, adjacentBlockY = -1;
		if (direction == LEFT)
		{
			adjacentBlockX = activeBlocks[blockIndex].x - 1;
			adjacentBlockY = activeBlocks[blockIndex].y;
		} else if (direction == RIGHT)
		{
			adjacentBlockX = activeBlocks[blockIndex].x + 1;
			adjacentBlockY = activeBlocks[blockIndex].y;
		} else
		{
			adjacentBlockX = activeBlocks[blockIndex].x;
			adjacentBlockY = activeBlocks[blockIndex].y + 1;
		}
		if (isDebuggingEnabled && blockIndex == 3)
		{
			char debugDisplay[100];
			sprintf(debugDisplay, "adjacentX: %ld\n adjacentBlockY: %ld\n", adjacentBlockX, adjacentBlockY);
			debug(debugDisplay);
		}
		if (adjacentBlockX > -1 && adjacentBlockY > -1 && 
			GRID[adjacentBlockX][adjacentBlockY].block != 0)
		{
			PtWidget_t *block = GRID[adjacentBlockX][adjacentBlockY].block;
			if (activeBlocks[0].b != block && activeBlocks[1].b != block &&
				activeBlocks[2].b != block && activeBlocks[3].b != block)
				return 0;
		}

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
	{
		char debugDisplay[100];
		sprintf(debugDisplay, "0: .x: %ld .y: %ld\n1: .x: %ld .y: %ld\n2: .x: %ld .y: %ld\n3: .x: %ld .y: %ld\n", activeBlocks[0].x, activeBlocks[0].y,activeBlocks[1].x, activeBlocks[1].y, activeBlocks[2].x, activeBlocks[2].y, activeBlocks[3].x, activeBlocks[3].y);
		//debug(debugDisplay);
	}
}

void debug(char debugDisplay[])
{


	PtArg_t args[1];
	PtSetArg(&args[0], Pt_ARG_TEXT_STRING, debugDisplay, 0);
	PtSetResources(ABW_testLabel, 1, args);
}

void startUp(int argc, char *argv[])
{
	srand(time(NULL));

	if (argc >= 2 && strcmp(argv[1], "-d") == 0)
		isDebuggingEnabled = 1;
	else
	{
		isDebuggingEnabled = 0;
		PtDestroyWidget(ABW_GridDebug);
	}
}
