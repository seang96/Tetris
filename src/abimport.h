/* Import (extern) header for application - AppBuilder 2.03  */

#include "abdefine.h"

extern ApWindowLink_t base;
extern ApWidget_t AbWidgets[ 7 ];


#ifdef __cplusplus
extern "C" {
#endif
int click( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int clickLeft( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int clickRight( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int clickDown( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
#ifdef __cplusplus
}
#endif
