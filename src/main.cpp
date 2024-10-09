#include <Arduino.h>
#include "MillisTaskManager.h"
#include "BSP.h"
/*任务调度器*/
static MillisTaskManager mtmMain;


void setup() {
    Serial.begin(9600);
    tft.init();
    tft.init();
    tft.setRotation(0);
    tft.setSwapBytes (true);
    tft.fillScreen(TFT_BLACK);
    Button_Init();
    Pages_Init();
    // put your setup code here, to run once:
    mtmMain.Register(Display_Update, 1);                //屏幕刷新
    mtmMain.Register(Button_Update, 10);             //按键检测

}

void loop() {
  // put your main code here, to run repeatedly:
    mtmMain.Running(millis());
    
}

