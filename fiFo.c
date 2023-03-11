/*
 * fiFo.c
 *
 *  Created on: 6 июл. 2022 г.
 *      Author: adminus
 */


#include "FiFo.h"


unsigned int pullB(Bring *there)
{
	if (there->blength!=defaultlng) return wrongObject;
	if (there->head==there->tail)
	{
		if (there->isoverflow==1) there->isoverflow=0;
		else{
			return nothing;
		}
	}
	volatile uint8_t a=there->tail;
	volatile uint8_t b=there->body[a];
	a++;
	if (a==defaultlng)
	{a=0;}
	there->tail=a;
	there->contain--;
	return b;

}
unsigned int pushB(Bring *there, uint8_t Data)
{
	if (there->blength!=defaultlng) return wrongObject;
	if (there->isoverflow!=0) return overflow;
	volatile uint8_t a=there->head;
	a++;
	if (a==defaultlng) a=0;
	if (a==there->tail) there->isoverflow=1;
	there->body[there->head]=Data;
	there->head=a;
	there->contain++;
	return luckey;
}

unsigned int ringReset(Bring *there)
{
	if (there == NULL)
	{
		return nothing;
	}
	there->blength=defaultlng;
	there->head=0;
	there->tail=0;
	there->contain=0;
	there->isoverflow=0;
	return luckey;
}
