#include "Engine.h"

Block createBlock(int x, int y, PgColor_t color)
{
	PtWidget_t *parent = ABW_base,
		 *block;

	PtArg_t args[3];
	PhPoint_t pos = { x*BlockDimension,y*BlockDimension };
	PhDim_t size = { BlockDimension, BlockDimension };
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

int createI(void)
{
	if (GRID[MiddleBlock-2][0].block != 0 ||
		GRID[MiddleBlock-1][0].block != 0 ||
		GRID[MiddleBlock][0].block != 0 ||
		GRID[MiddleBlock+1][0].block != 0)
		return 0;
	rotation = 0;
	type = I;
	activeBlocks[0] = createBlock(MiddleBlock - 2	, 0, Pg_VGA8);
	activeBlocks[1] = createBlock(MiddleBlock - 1	, 0, Pg_VGA8);
	activeBlocks[2] = createBlock(MiddleBlock	, 0, Pg_VGA8);
	activeBlocks[3] = createBlock(MiddleBlock + 1	, 0, Pg_VGA8);
	return 1;
}

int createJ(void)
{
	if (GRID[MiddleBlock+1][1].block != 0 ||
		GRID[MiddleBlock-1][0].block != 0 ||
		GRID[MiddleBlock][0].block != 0 ||
		GRID[MiddleBlock+1][0].block != 0)
		return 0;
	rotation = 0;
	type = J;
	activeBlocks[0] = createBlock(MiddleBlock + 1	, 1, Pg_VGA9);
	activeBlocks[1] = createBlock(MiddleBlock - 1	, 0, Pg_VGA9);
	activeBlocks[2] = createBlock(MiddleBlock	, 0, Pg_VGA9);
	activeBlocks[3] = createBlock(MiddleBlock + 1	, 0, Pg_VGA9);
	return 1;
}

int createL(void)
{
	if (GRID[MiddleBlock-1][1].block != 0 ||
		GRID[MiddleBlock][0].block != 0 ||
		GRID[MiddleBlock+1][0].block != 0 ||
		GRID[MiddleBlock-1][0].block != 0)
		return 0;
	rotation = 0;
	type = L;
	activeBlocks[0] = createBlock(MiddleBlock - 1	, 1, Pg_VGAA);
	activeBlocks[1] = createBlock(MiddleBlock	, 0, Pg_VGAA);
	activeBlocks[2] = createBlock(MiddleBlock + 1	, 0, Pg_VGAA);
	activeBlocks[3] = createBlock(MiddleBlock - 1	, 0, Pg_VGAA);
	return 1;
}

int createO(void)
{
	if (GRID[MiddleBlock-1][1].block != 0 ||
		GRID[MiddleBlock][1].block != 0 ||
		GRID[MiddleBlock-1][0].block != 0 ||
		GRID[MiddleBlock][0].block != 0)
		return 0;
	rotation = 0;
	type = O;
	activeBlocks[0] = createBlock(MiddleBlock - 1	, 1, Pg_VGAB);
	activeBlocks[1] = createBlock(MiddleBlock	, 1, Pg_VGAB);
	activeBlocks[2] = createBlock(MiddleBlock - 1	, 0, Pg_VGAB);
	activeBlocks[3] = createBlock(MiddleBlock	, 0, Pg_VGAB);
	return 1;
}

int createS(void)
{
	if (GRID[MiddleBlock-1][1].block != 0 ||
		GRID[MiddleBlock][1].block != 0 ||
		GRID[MiddleBlock][0].block != 0 ||
		GRID[MiddleBlock+1][0].block != 0)
		return 0;
	rotation = 0;
	type = S;
	activeBlocks[0] = createBlock(MiddleBlock - 1	, 1, Pg_VGAC);
	activeBlocks[1] = createBlock(MiddleBlock	, 1, Pg_VGAC);
	activeBlocks[2] = createBlock(MiddleBlock	, 0, Pg_VGAC);
	activeBlocks[3] = createBlock(MiddleBlock + 1	, 0, Pg_VGAC);
	return 1;
}

int createT(void)
{
	if (GRID[MiddleBlock][1].block != 0 ||
		GRID[MiddleBlock-1][0].block != 0 ||
		GRID[MiddleBlock][0].block != 0 ||
		GRID[MiddleBlock+1][0].block != 0)
		return 0;
	rotation = 0;
	type = T;
	activeBlocks[0] = createBlock(MiddleBlock	, 1, Pg_VGAD);
	activeBlocks[1] = createBlock(MiddleBlock - 1	, 0, Pg_VGAD);
	activeBlocks[2] = createBlock(MiddleBlock	, 0, Pg_VGAD);
	activeBlocks[3] = createBlock(MiddleBlock + 1	, 0, Pg_VGAD);
	return 1;
}

int createZ(void)
{
	if (GRID[MiddleBlock][1].block != 0 ||
		GRID[MiddleBlock+1][1].block != 0 ||
		GRID[MiddleBlock-1][0].block != 0 ||
		GRID[MiddleBlock][0].block != 0)
		return 0;
	rotation = 0;
	type = Z;
	activeBlocks[0] = createBlock(MiddleBlock	, 1, Pg_VGAE);
	activeBlocks[1] = createBlock(MiddleBlock + 1	, 1, Pg_VGAE);
	activeBlocks[2] = createBlock(MiddleBlock - 1	, 0, Pg_VGAE);
	activeBlocks[3] = createBlock(MiddleBlock	, 0, Pg_VGAE);
	return 1;
}

void createPiece(void)
{
	int type = rand() % 7;
	int result;
	switch (type) {
		case I:
			result = createI();
			break;
		case J:
			result = createJ();
			break;
		case L:
			result = createL();
			break;
		case O:
			result = createO();
			break;
		case S:
			result = createS();
			break;
		case T:
			result = createT();
			break;
		case Z:
			result = createZ();
			break;
	}
	if (!result)
	{
		lost = 1;
	}
}

void newGame(void)
{
	clearBlocks();
	createPiece();
	gamePlaying = 1;
	lost = 0;
	score = 0;
	seconds = 0;
}

void pauseGame(void)
{
	gamePlaying = !gamePlaying;
	char buttonText[7];
	if (gamePlaying)
		sprintf(buttonText, "Pause");
	else
		sprintf(buttonText, "Resume");
	PtArg_t args[1];
	PtSetArg(&args[0], Pt_ARG_TEXT_STRING, buttonText, 0);
	PtSetResources(ABW_pauseButton, 1, args);

}
void clearBlocks(void)
{
	int x;
	for (x = 0; x < GridSize; x++)
	{
		lineBlockCount[x] = 0;
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

void clearLines(void)
{
	int blockIndex;
	for (blockIndex = BlockSize - 1; blockIndex >= 0; blockIndex--)
	{
		int row = activeBlocks[blockIndex].y;
		lineBlockCount[row]++;
		if (lineBlockCount[row] == GridSize)
		{
			int rowIndex;
			for (rowIndex = 0; rowIndex < GridSize; rowIndex++)
			{
				if (GRID[rowIndex][row].block != 0)
				{
					PtDestroyWidget(GRID[rowIndex][row].block);
					GRID[rowIndex][row].block = 0;
				}
			}
			int currRow;
			for (currRow = row - 1; currRow >= 0; currRow--)
			{
				for (rowIndex = 0; rowIndex < GridSize; rowIndex++)
				{
					if (GRID[rowIndex][currRow].block != 0)
					{
						Block b = {
							.x = rowIndex,
							.y = currRow,
							.b = GRID[rowIndex][currRow].block,
						};
						moveBlock(&b, 0, 1);
					}
				}
			}
			int secondBlockIndex;
			for (secondBlockIndex = blockIndex -1; secondBlockIndex >= 0; secondBlockIndex--)
			{
				if (activeBlocks[secondBlockIndex].y < row)
					activeBlocks[secondBlockIndex].y++;
			}
			while (row > 0)
			{
				lineBlockCount[row] = lineBlockCount[row-1];
				row--;
			}
			lineBlockCount[0] = 0;

			incrementScore();
		}
	}
}

void moveLeft(void)
{
	int blockIndex;
	if (gamePlaying && isMoveValid(LEFT))
		for (blockIndex = 0; blockIndex < BlockSize; blockIndex++)
			moveBlock(&activeBlocks[blockIndex], -1, 0);
}

void moveRight(void)
{
	int blockIndex;
	if (gamePlaying && isMoveValid(RIGHT))
		for (blockIndex = 0; blockIndex < BlockSize; blockIndex++)
			moveBlock(&activeBlocks[blockIndex], 1, 0);
}

void moveDown(void)
{
	int blockIndex;
	if (gamePlaying && isMoveValid(DOWN))
		for (blockIndex = 0; blockIndex < BlockSize; blockIndex++)
			moveBlock(&activeBlocks[blockIndex], 0, 1);
	else if (gamePlaying && !lost) {
		clearLines();
		createPiece();
	}
}

int isRotateValid(int x[], int y[])
{
	int xMinBound = -1, yMinBound = -1, xMaxBound = GridSize - 1, yMaxBound = GridSize - 1;
	int b_iter;
	for (b_iter = 0; b_iter < BlockSize; b_iter++)
	{
		if (activeBlocks[b_iter].b == 0) return 0;	//Fail if no active block
		int new_x = activeBlocks[b_iter].x + x[b_iter];
		int new_y = activeBlocks[b_iter].y + y[b_iter];
		if (new_x == xMinBound || new_y == yMinBound ||	//Fail if x is out of bounds
			new_x == xMaxBound || new_y == yMaxBound)	//Fail if y is out of bounds
			return 0;
		else if (GRID[new_x][new_y].block != 0)	//Fail if a inactive block is in the new position
		{
			PtWidget_t *block = GRID[new_x][new_y].block;
			if (activeBlocks[0].b != block && activeBlocks[1].b != block &&
				activeBlocks[2].b != block && activeBlocks[3].b != block)
				return 0;
		}		
	}
	return 1;
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
		int adjacentBlockX, adjacentBlockY;
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
		if(GRID[adjacentBlockX][adjacentBlockY].block != 0)
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
	PhPoint_t pos = {(block->x + difX)*BlockDimension, (block->y + difY)*BlockDimension};
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
		//sprintf(debugDisplay, "13: %ld\n14: %ld\n15: %ld\n16: %ld", lineBlockCount[13], lineBlockCount[14], lineBlockCount[15], lineBlockCount[16]);
		//debug(debugDisplay);
	}
}

void rotateBlock(void)
{
	if (!gamePlaying)
		return;
	int x[BlockSize];
	int y[BlockSize]; 
	int tmp_rotation;
	switch (type) {
		case I:
			if (rotation == 0)
			{
				x[0] = 1; y[0] = 2;
				x[1] = 0; y[1] = 1;
				x[2] = -1; y[2] = 0;
				x[3] = -2; y[3] = -1;
				tmp_rotation = 1;
			} else {
				x[0] = -1; y[0] = -2;
				x[1] = 0; y[1] = -1;
				x[2] = 1; y[2] = 0;
				x[3] = 2; y[3] = 1;
				tmp_rotation = 0;
			}
			break;
		case J:
			if (rotation == 0)
			{
				x[0] = 0; y[0] = 0;
				x[1] = 1; y[1] = 1;
				x[2] = 1; y[2] = 0;
				x[3] = 0; y[3] = -1;
				tmp_rotation = 1;
			}
			else if (rotation == 1)
			{
				x[0] = -2; y[0] = 0;
				x[1] = 0; y[1] = 0;
				x[2] = 0; y[2] = 1;
				x[3] = -2; y[3] = 1;
				tmp_rotation = 2;
			}
			else if (rotation == 2)
			{
				x[0] = 0; y[0] = 1;
				x[1] = -1; y[1] = 0;
				x[2] = -2; y[2] = -1;
				x[3] = 1; y[3] = 0;
				tmp_rotation = 3;
			}
			else if (rotation == 3)
			{
				x[0] = 2; y[0] = 0;
				x[1] = 0; y[1] = 0;
				x[2] = 1; y[2] = 1;
				x[3] = 1; y[3] = 1;
				tmp_rotation = 0;
			}
			break;
		case L:
			if( rotation == 0)
			{
				x[0] = 1; y[0] = 0;
				x[1] = 0; y[1] = 0;
				x[2] = -1; y[2] = -1;
				x[3] = 0; y[3] = -1;
				tmp_rotation = 1;
			}
			else if (rotation == 1)
			{

				x[0] = 1; y[0] = -1;
				x[1] = 0; y[1] = 0;
				x[2] = -1; y[2] = 1;
				x[3] = 2; y[3] = 0;
				tmp_rotation = 2;
			}
			else if (rotation == 2)
			{
				x[0] = -1; y[0] = 1;
				x[1] = 1; y[1] = 1;
				x[2] = 1; y[2] = 0;
				x[3] = -1; y[3] = 0;
				tmp_rotation = 3;
			}
			else if (rotation == 3)
			{
				x[0] = -1; y[0] = 0;
				x[1] = -1; y[1] = -1;
				x[2] = 1; y[2] = 0;
				x[3] = -1; y[3] = 1;
				tmp_rotation = 0;
			}
			break;
		case O:
			return;
		case S:
			if( rotation == 0)
			{
				x[0] = 1; y[0] = 0;
				x[1] = 0; y[1] = -1;
				x[2] = -1; y[2] = 0;
				x[3] = -2; y[3] = -1;
				tmp_rotation = 1;
			}
			else if (rotation == 1)
			{
				x[0] = -1; y[0] = 0;
				x[1] = 0; y[1] = 1;
				x[2] = 1; y[2] = 0;
				x[3] = 2; y[3] = 1;
				tmp_rotation = 0;
			}
			break;
		case T:
			if( rotation == 0)
			{
				x[0] = 0; y[0] = 0;
				x[1] = 0; y[1] = 0;
				x[2] = 0; y[2] = 0;
				x[3] = -1; y[3] = -1;
				tmp_rotation = 1;
			}
			else if( rotation == 1)
			{
				x[0] = 1; y[0] = -1;
				x[1] = 0; y[1] = 0;
				x[2] = 0; y[2] = 0;
				x[3] = 0; y[3] = 0;
				tmp_rotation = 2;
			}
			else if( rotation == 2)
			{
				x[0] = -1; y[0] = 1;
				x[1] = 2; y[1] = 0;
				x[2] = 0; y[2] = 0;
				x[3] = 0; y[3] = 0;
				tmp_rotation = 3;
			}
			else if( rotation == 3)
			{
				x[0] = 0; y[0] = 0;
				x[1] = -2; y[1] = 0;
				x[2] = 0; y[2] = 0;
				x[3] = 1; y[3] = 1;
				tmp_rotation = 0;
			}
			break;
		case Z:
			if( rotation == 0)
			{
				x[0] = 0; y[0] = 1;
				x[1] = -1; y[1] = 0;
				x[2] = 2; y[2] = 1;
				x[3] = 1; y[3] = 0;
				tmp_rotation = 1;		
			}
			else if( rotation == 1)
			{
				x[0] = 0; y[0] = -1;
				x[1] = 1; y[1] = 0;
				x[2] = -2; y[2] = -1;
				x[3] = -1; y[3] = 0;
				tmp_rotation = 0;		
			}
			break;
	}

	if (isRotateValid(x, y))
	{
		moveBlock(&activeBlocks[0], x[0], y[0]);
		moveBlock(&activeBlocks[1], x[1], y[1]);
		moveBlock(&activeBlocks[2], x[2], y[2]);
		moveBlock(&activeBlocks[3], x[3], y[3]);
		rotation = tmp_rotation;
	}
}

void incrementScore(void)
{
	score += 100;
	updateStats();
}

void incrementSeconds(void)
{
	if (!gamePlaying || lost)
		return;
	seconds++;
	updateStats();
}

void updateStats(void)
{
	char *stats = malloc(2*sizeof(int)+15);
	sprintf(stats, "Time: %ld\nScore: %ld", seconds, score);
	PtArg_t args[1];
	PtSetArg(&args[0], Pt_ARG_TEXT_STRING, stats, 0);
	PtSetResources(ABW_scoreLabel, 1, args);
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
	clearBlocks();

	if (argc >= 2 && strcmp(argv[1], "-d") == 0)
		isDebuggingEnabled = 1;
	else
	{
		isDebuggingEnabled = 0;
		PtDestroyWidget(ABW_GridDebug);
	}
}
