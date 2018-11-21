/*
 * ST7789-parallel
 * 
 * Copyright 2018 Harebit
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
 */
 
#include "stm32f1xx_hal.h"
#include "ST7789-parallel.h"
#include "stm32f1xx_hal_gpio.h"

uint8_t setOutput;


void setparallelOutput(void){

GPIO_InitTypeDef GPIO_InitStruct;

  /*Configure GPIO pins : LCD_D1_Pin */
  GPIO_InitStruct.Pin = LCD_D1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_D7_Pin LCD_D0_Pin LCD_D2_Pin */
  GPIO_InitStruct.Pin = LCD_D7_Pin|LCD_D0_Pin|LCD_D2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  
   /*Configure GPIO pins : LCD_D6_Pin LCD_D3_Pin LCD_D5_Pin LCD_D4_Pin */
  GPIO_InitStruct.Pin = LCD_D6_Pin|LCD_D3_Pin|LCD_D5_Pin|LCD_D4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  setOutput = 1;

}

void setparallelInput(void){

GPIO_InitTypeDef GPIO_InitStruct;

/*Configure GPIO pins : LCD_D1_Pin */
  GPIO_InitStruct.Pin = LCD_D1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_D7_Pin LCD_D0_Pin LCD_D2_Pin */
  GPIO_InitStruct.Pin = LCD_D7_Pin|LCD_D0_Pin|LCD_D2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  
   /*Configure GPIO pins : LCD_D6_Pin LCD_D3_Pin LCD_D5_Pin LCD_D4_Pin */
  GPIO_InitStruct.Pin = LCD_D6_Pin|LCD_D3_Pin|LCD_D5_Pin|LCD_D4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  setOutput = 0;
}

void parallelWriteDC0(uint8_t eightbit){

	if(setOutput){} else {setparallelOutput();}
	//printf ("writedc0: %i ",setOutput);

HAL_GPIO_WritePin(LCD_WR_GPIO_Port, LCD_WR_Pin, GPIO_PIN_SET); // idle = high
HAL_GPIO_WritePin(LCD_RD_GPIO_Port, LCD_RD_Pin, GPIO_PIN_SET); // idle = high
HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET); // low = command

HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, (eightbit & 1) == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, (eightbit & 2) == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, (eightbit & 4) == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, (eightbit & 8) == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, (eightbit & 16) == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, (eightbit & 32) == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, (eightbit & 64) == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (eightbit & 128) == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
    //printf ("eightbit: %X\n",eightbit);
HAL_GPIO_WritePin(LCD_WR_GPIO_Port, LCD_WR_Pin, GPIO_PIN_RESET);
HAL_GPIO_WritePin(LCD_WR_GPIO_Port, LCD_WR_Pin, GPIO_PIN_SET); // raising edge
}

void parallelWriteDC1(uint8_t eightbit){

	if(setOutput){} else {setparallelOutput();}
	//printf ("writedc1: %i ",setOutput);

HAL_GPIO_WritePin(LCD_WR_GPIO_Port, LCD_WR_Pin, GPIO_PIN_SET); // idle = high
HAL_GPIO_WritePin(LCD_RD_GPIO_Port, LCD_RD_Pin, GPIO_PIN_SET); // idle = high
HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET); // high = data

HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, (eightbit & 1) == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, (eightbit & 2) == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, (eightbit & 4) == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, (eightbit & 8) == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, (eightbit & 16) == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, (eightbit & 32) == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, (eightbit & 64) == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (eightbit & 128) == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
     // printf ("eightbit: %X\n",eightbit);
HAL_GPIO_WritePin(LCD_WR_GPIO_Port, LCD_WR_Pin, GPIO_PIN_RESET);
HAL_GPIO_WritePin(LCD_WR_GPIO_Port, LCD_WR_Pin, GPIO_PIN_SET); // raising edge
}

uint8_t parallelReadDC1(void){

uint8_t eightbit = 0x00;

	if(!setOutput){} else {setparallelInput();}

HAL_GPIO_WritePin(LCD_WR_GPIO_Port, LCD_WR_Pin, GPIO_PIN_SET);   // idle = high
HAL_GPIO_WritePin(LCD_RD_GPIO_Port, LCD_RD_Pin, GPIO_PIN_RESET); // low = ready
HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET);   // high = data

eightbit = (HAL_GPIO_ReadPin(LCD_D0_GPIO_Port, LCD_D0_Pin)|
		(HAL_GPIO_ReadPin(LCD_D1_GPIO_Port, LCD_D1_Pin)<<1)|
		(HAL_GPIO_ReadPin(LCD_D2_GPIO_Port, LCD_D2_Pin)<<2)|
		(HAL_GPIO_ReadPin(LCD_D3_GPIO_Port, LCD_D3_Pin)<<3)|
		(HAL_GPIO_ReadPin(LCD_D4_GPIO_Port, LCD_D4_Pin)<<4)|
		(HAL_GPIO_ReadPin(LCD_D5_GPIO_Port, LCD_D5_Pin)<<5)|
		(HAL_GPIO_ReadPin(LCD_D6_GPIO_Port, LCD_D6_Pin)<<6)|
		(HAL_GPIO_ReadPin(LCD_D7_GPIO_Port, LCD_D7_Pin)<<7));

HAL_GPIO_WritePin(LCD_RD_GPIO_Port, LCD_RD_Pin, GPIO_PIN_SET); // raising edge

return eightbit;
}

void parallelMultiWriteDC1(uint8_t *p_eightbit, int numItems) {

	for (int i = 0; i < numItems; i++)
	parallelWriteDC1(p_eightbit[i]);

}

void parallelMultiReadDC1(uint8_t *p_eightbit, int numItems) {

	for (int i = 0; i < numItems; i++)
	p_eightbit[i] = parallelReadDC1();

}

void ST7789_Init(void){

    parallelWriteDC0(0x01);   //Software Reset
    HAL_Delay(200);
     
    parallelWriteDC0(0x28);   // Display off
        
    parallelWriteDC0(0x3A);   // Pixel Format 
    parallelWriteDC1(0x55);   // 565, 16-bit
    
    parallelWriteDC0(0xBB);   // VCOMS
    parallelWriteDC1(0x2B);   //  1,175     

    parallelWriteDC0(0xC3);   // VRHS
    parallelWriteDC1(0x11);   //   4,4V 

    parallelWriteDC0(0xD0);   // PWCTRL
    parallelWriteDC1(0xA4);   // 
    parallelWriteDC1(0xA1);   // VDD=2,3V; AVCL=4,8V; AVDD=6,8V

    parallelWriteDC0(0x11);   // Exit Sleep 
    HAL_Delay(120);

    parallelWriteDC0(0x29);   // Display on 
    
    parallelWriteDC0(0x2c);   // Memory Write
}
