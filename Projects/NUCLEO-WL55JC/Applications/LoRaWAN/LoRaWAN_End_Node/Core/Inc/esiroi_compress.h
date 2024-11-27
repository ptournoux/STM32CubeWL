/*
 * esiroi_compress.h
 *
 *  Created on: Nov 26, 2024
 *      Author: esiroi
 */

#ifndef APPLICATION_USER_CORE_ESIROI_COMPRESS_H_
#define APPLICATION_USER_CORE_ESIROI_COMPRESS_H_

#define ESIROI_SAMPLE_BUFFER_MAX_SIZE 1200

int16_t esiroi_compute_average(int16_t * tab, uint16_t nbElem);

void esiroi_collect_temperature(float sample_float, uint32_t esiroi_timestamp);

void esiroi_compress_and_format(uint8_t *app_data_buff, uint8_t *app_data_size);

void esiroi_reset_buff(void);
#endif /* APPLICATION_USER_CORE_ESIROI_COMPRESS_H_ */
