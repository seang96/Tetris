/* Define header for application - AppBuilder 2.03  */

/* 'base' Window link */
extern const int ABN_base;
#define ABW_base                             AbGetABW( ABN_base )
extern const int ABN_ButtonActions;
#define ABW_ButtonActions                    AbGetABW( ABN_ButtonActions )
extern const int ABN_GridDebug;
#define ABW_GridDebug                        AbGetABW( ABN_GridDebug )
extern const int ABN_DownButton;
#define ABW_DownButton                       AbGetABW( ABN_DownButton )
extern const int ABN_LeftButton;
#define ABW_LeftButton                       AbGetABW( ABN_LeftButton )
extern const int ABN_RightButton;
#define ABW_RightButton                      AbGetABW( ABN_RightButton )
extern const int ABN_testLabel;
#define ABW_testLabel                        AbGetABW( ABN_testLabel )

#define AbGetABW( n ) ( AbWidgets[ n ].wgt )

#define AB_OPTIONS "s:x:y:h:w:S:"
