/*
 * example.c
 *
 *  Created on: 18.11.2018
 *      Author: Harebit
 */

#include "example.h"
#include <stdlib.h>
#include "GUI.h"

int i=0;
int xPos, yPos;

const GUI_POINT aPoints[] = {
  { 40, 20},
  {  0, 20},
  { 20,  0}
};

void loop(void){

//***** "Hello" *****************************************

    GUI_SetBkColor(GUI_BLUE);
    GUI_Clear();
    GUI_SetDrawMode(GUI_DM_NORMAL);
    GUI_SetColor(GUI_WHITE);
    GUI_DrawGradientV(20, 20, 300, 220, GUI_RED, GUI_YELLOW);
    xPos = LCD_GetXSize() / 2;
    yPos = LCD_GetYSize() / 3;
    GUI_SetFont(GUI_FONT_COMIC24B_ASCII);
    HAL_Delay(200);
    GUI_DispStringHCenterAt("Hello Harebit!", xPos, yPos);
    GUI_DispStringHCenterAt("STemWin ",130,120);
    GUI_DispString(GUI_GetVersionString());
    HAL_Delay(500);

//***** "Text" ******************************************

    GUI_SetFont(&GUI_Font8x16);
    GUI_SetBkColor(GUI_BLUE);
    GUI_Clear();
    GUI_SetPenSize(10);
    GUI_SetColor(GUI_RED);
    GUI_DrawLine(80, 10, 240, 90);
    GUI_DrawLine(80, 90, 240, 10);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor(GUI_WHITE);
    GUI_SetTextMode(GUI_TM_NORMAL);
    GUI_DispStringHCenterAt("GUI_TM_NORMAL"            , 160, 10);
    GUI_SetTextMode(GUI_TM_REV);
    GUI_DispStringHCenterAt("GUI_TM_REV"               , 160, 26);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispStringHCenterAt("GUI_TM_TRANS"             , 160, 42);
    GUI_SetTextMode(GUI_TM_XOR);
    GUI_DispStringHCenterAt("GUI_TM_XOR"               , 160, 58);
    GUI_SetTextMode(GUI_TM_TRANS | GUI_TM_REV);
    GUI_DispStringHCenterAt("GUI_TM_TRANS | GUI_TM_REV", 160, 74);
    HAL_Delay(500);

//***** "floating point values" *********************************

    float f = 123.45678;
    GUI_Clear();
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor(GUI_WHITE);
    GUI_SetTextMode(GUI_TM_NORMAL);
    GUI_SetFont(&GUI_Font8x16);
    GUI_DispStringAt("GUI_DispFloat:\n", 0, 20);
    GUI_DispFloat(f, 9);
    GUI_GotoX(100);
    GUI_DispFloat(-f, 9);
    GUI_DispStringAt("GUI_DispFloatFix:\n", 0, 60);
    GUI_DispFloatFix(f, 9, 2);
    GUI_GotoX(100);
    GUI_DispFloatFix(-f, 9, 2);
    GUI_DispStringAt("GUI_DispSFloatFix:\n", 0, 100);
    GUI_DispSFloatFix(f, 9, 2);
    GUI_GotoX(100);
    GUI_DispSFloatFix(-f, 9, 2);
    GUI_DispStringAt("GUI_DispFloatMin:\n", 0, 140);
    GUI_DispFloatMin(f, 3);
    GUI_GotoX(100);
    GUI_DispFloatMin(-f, 3);
    GUI_DispStringAt("GUI_DispSFloatMin:\n", 0, 180);
    GUI_DispSFloatMin(f, 3);
    GUI_GotoX(100);
    GUI_DispSFloatMin(-f, 3);
    HAL_Delay(500);

//***** "Shapes" *********************************

    GUI_SetBkColor(GUI_DARKBLUE);
    GUI_Clear();
    GUI_SetColor(GUI_YELLOW);
    GUI_SetPenSize(3);
    GUI_DrawPoint(20, 10);
    GUI_DrawLine(80, 10, 280, 30);
    GUI_DrawRect(20, 30, 40, 50);
    GUI_FillRect(180, 30, 200, 50);
    GUI_DrawRoundedRect(100, 60, 150, 100, 10);
    GUI_FillRoundedRect(250, 60, 300, 100, 10);
    GUI_DrawCircle(30, 120, 20);
    GUI_FillCircle(180, 120, 20);
    GUI_DrawEllipse(80, 180, 50, 30);
    GUI_FillEllipse(240, 180, 50, 30);
    GUI_DispStringHCenterAt("Shapes",130,120);
    HAL_Delay(500);

//***** "Graph" ****************************************

    GUI_SetBkColor(GUI_DARKGREEN);
    GUI_Clear();
    GUI_SetColor(GUI_WHITE);

    I16 aY[200];
    int i;

      for (i = 0; i < GUI_COUNTOF(aY); i++) {
        aY[i] = rand() % 150;
      }
      GUI_DrawGraph(aY, GUI_COUNTOF(aY), 50, 50);
      GUI_DrawHLine(205, 45, 250);
      GUI_DrawVLine(45, 45, 200);
      GUI_DispStringHCenterAt("Graph",250,210);
      HAL_Delay(500);

//***** "Pie" ****************************************

      GUI_SetBkColor(GUI_WHITE);
      GUI_Clear();

      int a0, a1;
      const unsigned aValues[]  = { 100, 135, 190, 240, 340, 360};
      const GUI_COLOR aColors[] = { GUI_BLUE, GUI_GREEN,   GUI_RED,
                                    GUI_CYAN, GUI_MAGENTA, GUI_YELLOW };
      for (i = 0; i < GUI_COUNTOF(aValues); i++) {
        a0 = (i == 0) ? 0 : aValues[i - 1];
        a1 = aValues[i];
        GUI_SetColor(aColors[i]);
        GUI_DrawPie(100, 100, 80, a0, a1, 0);
      }
      GUI_SetColor(GUI_BLACK);
      GUI_DispStringHCenterAt("Pie",240,150);
      HAL_Delay(500);

//***** "Miscellaneous" *********************************

    GUI_SetBkColor(GUI_GREEN);
    GUI_Clear();
    GUI_SetColor(GUI_RED);
    for (i = 10; i < 270; i += 5) {
    	GUI_DrawLine(20+i, 30, 20+i, 60);
    	HAL_Delay(20);
    };
    for (i = 10; i < 50; i += 3) {
      GUI_DrawCircle(80, 160, i);
      HAL_Delay(20);
    };
    GUI_SetColor(0x00FFFF00);
    for (i = 0; i < 4; i += 1) {
    	GUI_SetColor(0x000FFFF0 << i*0x6);
    	GUI_FillCircle(200+(i*15),150+(i*15),30);
    	HAL_Delay(20);
    };
    GUI_POINT aEnlargedPoints[GUI_COUNTOF(aPoints)];

      GUI_SetDrawMode(GUI_DM_XOR);
      GUI_FillPolygon(aPoints, GUI_COUNTOF(aPoints), 140, 110);
      for (i = 1; i < 10; i++) {
        GUI_EnlargePolygon(aEnlargedPoints, aPoints, GUI_COUNTOF(aPoints), i * 5);
        GUI_FillPolygon(aEnlargedPoints, GUI_COUNTOF(aPoints), 140, 110);
      };
      HAL_Delay(500);
}
