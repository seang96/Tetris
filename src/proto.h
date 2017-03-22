
/* BlockMaker.c */
void createPiece ( void );
void newGame ( void );
void clearBlocks ( void );
void moveLeft ( void );
void moveRight ( void );
void moveDown ( void );
int isMoveValid ( int direction );
void debug ( void );

/* abmain.c */

/* click.c */
int click ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );

/* clickDown.c */
int clickDown ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );

/* clickLeft.c */
int clickLeft ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );

/* clickRight.c */
int clickRight ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
