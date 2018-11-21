/*
 * effect_flanger.h
 *
 *  Created on: Nov 21, 2018
 *      Author: Cleissom
 */

#ifndef EFFECT_FLANGER_H_
#define EFFECT_FLANGER_H_

#include <arm_math.h>
#include "effect_common.h"

/**
 * @brief Instance structure for the Vibrato Effect.
 */
typedef struct {
	float32_t delay;     	/**< max delay of filter in ms. */
	float32_t alpha;		/**< Scaling factor.*/
	float32_t *pState;    	/**< points to the state variable array. The array is of length numTaps+blockSize-1. */
	uint16_t pStateSize;    /**< size of pState. */
	uint16_t head;			/**< position on state buffer. */
	uint16_t cosineIndex;	/**< index number for digital frequency */
	float32_t flangerDigitalFrequency;	/**< Digital frequency of flanger oscilation */
} effect_instance_flanger;



void effect_flanger_init( effect_instance_flanger * S, float32_t delay, float32_t alpha, float32_t frequency, float32_t * pState, uint16_t pStateSize);
void effect_flanger(effect_instance_flanger * S, float32_t * pSrc, float32_t * pDst, uint16_t blockSize);


#endif /* EFFECT_FLANGER_H_ */
