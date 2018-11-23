#ifndef ZORK_C_
#define ZORK_C_

#include "Platform.h"
#if PL_LOCAL_CONFIG_HAS_ZORK_GAME
#include "Zork.h"


TaskHandle_t  zorkHandle;


void zork_exit(){
	vTaskDelete(zorkHandle);
}



void Zork_Task(void *pv){

	zork_config();
	 run_zork_game();
	 for(;;);

}


uint8_t zork_init() {

	if (xTaskCreate(Zork_Task, "Zork", 900/sizeof(StackType_t),NULL, tskIDLE_PRIORITY+2, zorkHandle)!=pdPASS) {
	      for(;;){} /* error case only, stay here! */
	    }
}


uint8_t ZORK_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io) {


    if ((UTIL1_strcmp((char*)cmd, (char*)"Play Zork")==0)) {
	  *handled = TRUE;

	  return zork_init();

    }
    return ERR_OK;
}
#endif

#endif /* SOURCES_INTRO_COMMON_ZORK_H_ */
