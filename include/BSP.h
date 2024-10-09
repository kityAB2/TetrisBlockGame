#ifndef __BSP_H
#define __BSP_H

#include "SysConfig.h"
#include "Arduino.h"
#include "TFT_eSPI.h"
#include "TetrisBlock.h"
#include "Music.h"

/*Backlight*/

/*Buttons*/
#include "ButtonEvent.h"
extern ButtonEvent btUP;              //上键
extern ButtonEvent btDOWN;            //下键
extern ButtonEvent btLEFT;            //左键
extern ButtonEvent btRIGHT;           //右键
extern ButtonEvent btA;               //A键
extern ButtonEvent btB;               //B键
extern ButtonEvent btSoundDown;             //A键
extern ButtonEvent btSoundUp;               //B键
void Button_Init();
void Button_Update();

#include "PageManager.h"
extern PageManager page;
extern TFT_eSPI tft;
typedef enum
{
    /*保留*/
    /*保留*/
    PAGE_NONE,
    PAGE_MainMenu,  
    PAGE_Game,
    /*保留*/
    PAGE_MAX
} Page_Type;
void Display_Update();
void Pages_Init();
#endif
