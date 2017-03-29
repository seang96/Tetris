typedef struct {
	int x;
	int y;
	PtWidget_t *block;
} pos;

/* BlockMaker.c */
void createBlock ( int x , int y , PgColor_t color );
void newGame ( void );
void clearBlocks ( void );
void moveLeft ( void );
void moveRight ( void );
void moveDown ( void );
void moveBlock ( pos position , int difX , int difY );

/* abmain.c */

/* click.c */
int click ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );

/* clickLeft.c */
int clickLeft ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
