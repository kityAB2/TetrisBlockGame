#include "BSP.h"


/*实例化按键对象*/
ButtonEvent btUP;              //上键
ButtonEvent btDOWN;            //下键
ButtonEvent btLEFT;            //左键
ButtonEvent btRIGHT;           //右键
ButtonEvent btA;               //A键
ButtonEvent btB;               //B键
ButtonEvent btSoundDown;             //A键
ButtonEvent btSoundUp;               //B键


/**
  * @brief  按键事件回调处理
  * @param  btn:按键对象地址
  * @param  event:事件类型
  * @retval 无
  */
static void Button_EventHandler(ButtonEvent* btn, int event)
{
    
    /*传递至页面事件*/
    // page.PageEventTransmit(btn, event);
}

/**
  * @brief  电源按键事件回调处理
  * @param  btn:按键对象地址
  * @param  event:事件类型
  * @retval 无
  */
static void ButtonSound_EventHandler(ButtonEvent* btn, int event)
{
    if(btn == &btSoundDown)
    {
        /*长按关机*/
        if(event == ButtonEvent::EVENT_ButtonPress)
        {
            // Power_Shutdown();
        }
    }
}

/**
  * @brief  按键初始化
  * @param  无
  * @retval 无
  */
void Button_Init()
{
    /*上拉输入*/
    pinMode(KEY_UP_Pin, INPUT_PULLUP);
    pinMode(KEY_DOWN_Pin, INPUT_PULLUP);
    pinMode(KEY_LEFT_Pin, INPUT_PULLUP);
    pinMode(KEY_RIGHT_Pin, INPUT_PULLUP);
    pinMode(KEY_A_Pin, INPUT_PULLUP);
    pinMode(KEY_B_Pin, INPUT_PULLUP);
    pinMode(KEY_Sound_Down_Pin, INPUT_PULLUP);
    pinMode(KEY_Sound_Up_Pin, INPUT_PULLUP);
    

    /*关联事件*/
    btUP.EventAttach(Button_EventHandler);
    btDOWN.EventAttach(Button_EventHandler);
    btLEFT.EventAttach(Button_EventHandler);
    btRIGHT.EventAttach(Button_EventHandler);
    btA.EventAttach(Button_EventHandler);
    btB.EventAttach(Button_EventHandler);
    btSoundDown.EventAttach(ButtonSound_EventHandler);
    btSoundUp.EventAttach(ButtonSound_EventHandler);

}

/**
  * @brief  按键监控更新
  * @param  无
  * @retval 无
  */
void Button_Update()
{

    btUP.EventMonitor(!digitalRead(KEY_UP_Pin));
    btDOWN.EventMonitor(!digitalRead(KEY_DOWN_Pin));
    btLEFT.EventMonitor(!digitalRead(KEY_LEFT_Pin));
    btRIGHT.EventMonitor(digitalRead(KEY_RIGHT_Pin));
    btA.EventMonitor(!digitalRead(KEY_A_Pin));
    btB.EventMonitor(!digitalRead(KEY_B_Pin));
    btSoundDown.EventMonitor(!digitalRead(KEY_Sound_Down_Pin));
    btSoundUp.EventMonitor(digitalRead(KEY_Sound_Up_Pin));
}
