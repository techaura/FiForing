/*
 * FiFo.h
 *
 *  Created on: 6 июл. 2022 г.
 *      Author: Steppefort
 * @file     FiFo.h
 * @brief   This file contains all the function prototypes for
 *          the  FiFo.c file
   ******************************************************************************
  * @attention
  *
  * Copyright (c) 07.2022 Steppefort.
  * All rights reserved.
  *
  * This software is private.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */


#ifndef FIFO_H_
#define FIFO_H_
#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include "main.h"
/*BFIFO - buffer with 1B size of data*/
#define defaultlng 128
#define overflow 0x0100
#define nothing 0x0200
#define wrongObject 0x0300
#define luckey 0x0000


typedef struct BFIFO{
uint32_t blength;
uint32_t head;
uint32_t tail;
uint32_t contain;
uint32_t isoverflow;
uint8_t body[defaultlng];

}Bring;

unsigned int pullB(Bring *there);
unsigned int pushB(Bring *there, uint8_t Data);
unsigned int ringReset(Bring *there);


#ifdef __cplusplus
}
#endif
#endif /* FIFO_H_ */
