/*
 * ST7789-parallel.h
 * 
 * Copyright 2018 Hare <Hare@HARE-PC>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#ifndef ST7789_PARALLEL_H
#define ST7789_PARALLEL_H

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

void setparallelOutput(void);
void setparallelInput(void);
void parallelWriteDC0(uint8_t eightbit);
void parallelWriteDC1(uint8_t eightbit);
uint8_t parallelReadDC1(void);
void parallelMultiWriteDC1(uint8_t *p_eightbit, int numItems);
void parallelMultiReadDC1(uint8_t *p_eightbit, int numItems);
void ST7789_Init(void);

#ifdef __cplusplus
}
#endif

#endif //ST7789_PARALLEL_H


