/*
 * Zork.h
 *
 *  Created on: 16.11.2018
 *      Author: Test
 */

#ifndef ZORK_H_
#define ZORK_H_

#include "Platform.h"
#if PL_LOCAL_CONFIG_HAS_ZORK_GAME
#include "Shell.h"
#include "CLS1.h"
#include "Application.h"
#include "funcs.h"
#include "zork_config.h"

#if PL_CONFIG_HAS_RTOS
 #include "FRTOS1.h"
#include "FRTOS1.h"
#endif




/*!
 * \brief Shell parser routine.
 * \param cmd Pointer to command line string.
 * \param handled Pointer to status if command has been handled. Set to TRUE if command was understood.
 * \param io Pointer to stdio handle
 * \return Error code, ERR_OK if everything was ok.
 */
uint8_t ZORK_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io);

TaskHandle_t  zorkHandle;
uint8_t zork_init();
void zork_exit();


#endif

#endif /* SOURCES_INTRO_COMMON_ZORK_H_ */
