/*
 * esiroi_compress.c
 *
 *  Created on: Nov 26, 2024
 *      Author: esiroi
 */

#include "esiroi_compress.h"

static void esiroi_collect_temperature(float sample_float, uint32_t esiroi_timestamp){
	// nothing todo... yet
	APP_LOG(TS_OFF, VLEVEL_H, "esiroi_collect_temperature\r\n");
	if(AppNbSampleInBuffer >= ESIROI_SAMPLE_BUFFER_MAX_SIZE){
		// Buffer is full ...
		APP_LOG(TS_ON, VLEVEL_M, "# %d ESIROI_SAMPLE_BUFFER_MAX_SIZE: %d\r\n");
	}
    assert(AppNbSampleInBuffer < ESIROI_SAMPLE_BUFFER_MAX_SIZE);
	int16_t sample_temp = (int16_t)(sensor_data.temperature*1000);
	AppSampleBuffer[AppNbSampleInBuffer++] = sample_temp; // Postfixed incrementation
	// Meaning that the variable is evaluated then incremented
	APP_LOG(TS_ON, VLEVEL_M, "# %d temp: %d\r\n",AppNbSampleInBuffer, AppSampleBuffer[AppNbSampleInBuffer-1]);
	// Is it really useful to stop and start the timer ..
	// even though it is set as periodic ?
	/*UTIL_TIMER_Stop(&PeriodicCollectTimer);
	UTIL_TIMER_SetPeriod(&PeriodicCollectTimer, COLLECT_PERIOD_TIME);
	UTIL_TIMER_Start(&PeriodicCollectTimer);*/
}

static void esiroi_compress_and_format(uint8_t *app_data_buff, uint8_t *app_data_size){
	// LORAWAN_APP_DATA_BUFFER_MAX_SIZE
	// nothing todo... yet
	APP_LOG(TS_OFF, VLEVEL_H, "compress_and_format\r\n");

	int16_t to_send = esiroi_compute_average(AppSampleBuffer, AppNbSampleInBuffer);

}

static int16_t esiroi_compute_average(int16_t * tab, uint16_t nbElem){
	int32_t avg = 0;
	for(int i=0;i<nbElem;i++){
		avg+=tab[i];
	}
	if (nbElem <= 0) return 0;
	else return (int16_t) (avg / (int16_t) nbElem);

}
