#include "BSP.h"
TetrisBlock TetrisBlock1;


/**
  * @brief  页面初始化事件
  * @param  无
  * @retval 无
  */
static void Setup()
{
    tft.fillScreen(TFT_WHITE);
    TetrisBlock1.gameInit();
    // delay(300);
    TetrisBlock1.started = true;
    startPlaying();
}
static void Loop()
{
    if(TetrisBlock1.gameover == true) return;
    Point next_pos;
    next_pos.x = TetrisBlock1.pre_pos.x;
    next_pos.y = TetrisBlock1.pre_pos.y;
    int next_rot = TetrisBlock1.pre_rot;
    if ((millis()-TetrisBlock1.TimeElsp)>TetrisBlock1.score2Level()) {
        next_pos.y += 1;
        TetrisBlock1.TimeElsp=millis();
        TetrisBlock1.reviseScreen(next_pos, next_rot);
    }
    playMelody();
    if(TetrisBlock1.gameover == true){
        page.PagePop();
        stopPlaying();
    }
    
}

/**
  * @brief  页面退出事件
  * @param  无
  * @retval 无
  */
static void Exit()
{
    
}

/**
  * @brief  页面事件
  * @param  btn:发出事件的按键
  * @param  event:事件编号
  * @retval 无
  */
static void Event(void* btn, int event)
{  
    if(event == ButtonEvent::EVENT_ButtonPress || event == ButtonEvent::EVENT_ButtonLongPressRepeat)
    {
        if(TetrisBlock1.gameover == true) return;
        Point next_pos;
        next_pos.x = TetrisBlock1.pre_pos.x;
        next_pos.y = TetrisBlock1.pre_pos.y;
        int next_rot = TetrisBlock1.pre_rot;
        /*按下或长按上下键，图标上下选择*/
        if(btn == &btUP)
        {    
            next_rot = (next_rot + TetrisBlock1.pre_block.numRotate - 1)%TetrisBlock1.pre_block.numRotate;      
        }
        if(btn == &btDOWN)
        {
            next_pos.y += 1;
        }
        if(btn == &btLEFT){
            next_pos.x -= 1;
        }
        if(btn == &btRIGHT){
            next_pos.x += 1;
        }
        TetrisBlock1.reviseScreen(next_pos, next_rot);
        if(TetrisBlock1.gameover == true) {
            stopPlaying();
            page.PagePop();
        }
    }
}

/**
  * @brief  页面注册
  * @param  pageID:为此页面分配的ID号
  * @retval 无
  */
void PageRegister_Game(uint8_t pageID)
{
    /*注册至页面调度器*/
    page.PageRegister(pageID, Setup, Loop, Exit, Event);
}
