/* Define header for application - AppBuilder 2.03  */

/* 'base' Window link */
extern const int ABN_base;
#define ABW_base                             AbGetABW( ABN_base )
extern const int ABN_ButtonActions;
#define ABW_ButtonActions                    AbGetABW( ABN_ButtonActions )
extern const int ABN_LeftButton;
#define ABW_LeftButton                       AbGetABW( ABN_LeftButton )

#define AbGetABW( n ) ( AbWidgets[ n ].wgt )

#define AB_OPTIONS "s:x:y:h:w:S:"
