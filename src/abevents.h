/* Event header for application - AppBuilder 2.03  */

static const ApEventLink_t AbApplLinks[] = {
	{ 3, 0, 0L, 0L, 0L, &base, NULL, NULL, 0, NULL, 0, 0, 0, 0, },
	{ 0 }
	};

static const ApEventLink_t AbLinks_base[] = {
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "ButtonActions", 2009, click, 0, 0, 0, 0, },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "DownButton", 2009, clickDown, 0, 0, 0, 0, },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "LeftButton", 2009, clickLeft, 0, 0, 0, 0, },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "RightButton", 2009, clickRight, 0, 0, 0, 0, },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "AutoFall", 41002, moveDownTimer, 0, 0, 0, 0, },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "Rotatebutton", 2009, rotatecw, 0, 0, 0, 0, },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "pauseButton", 2009, clickPause, 0, 0, 0, 0, },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "clockTimer", 41002, incrementTime, 0, 0, 0, 0, },
	{ 0 }
	};

const char ApOptions[] = AB_OPTIONS;
