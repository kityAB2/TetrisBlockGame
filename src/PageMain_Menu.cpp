#include "BSP.h"
/**
  * @brief  页面初始化事件
  * @param  无
  * @retval 无
  */
int playerScore[3] ={3,2,1};
static int selectedItem;
static void Setup()
{
    Serial.println("Starting");
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(35, 250);  // 水平居中 (170-100)/2 = 35, 垂直靠中
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(2);
    tft.println("1Player");

    tft.setCursor(35, 280);  // 显示第二个菜单项
    tft.println("2Player");
    if (selectedItem == 0) {
        tft.drawRect(30, 275, 110, 30, TFT_BLACK);   // 绘制选中框
        tft.drawRect(30, 240, 110, 30, TFT_GREEN);   // 绘制选中框
    } else if (selectedItem == 1) {
        tft.drawRect(30, 275, 110, 30, TFT_GREEN);   // 绘制选中框
        tft.drawRect(30, 240, 110, 30, TFT_BLACK);   // 绘制选中框
    }
    //绘制排行榜
    tft.setCursor(35, 30);
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(2);
    tft.println("Ranking");
    for(int i =0; i< 3;i++){
        tft.print("    ");
        tft.print(i+1);
        tft.print(".");
        char buffer[5]; // 4位数字 + 1位终止符
        sprintf(buffer, "%04d", playerScore[i]); // 使用前导零格式化
        tft.print(buffer);
        tft.println();
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
        /*按下或长按上下键，图标上下选择*/
        if(btn == &btUP)
        {
            selectedItem = selectedItem == 0 ? 1 : 0;
            if (selectedItem == 0) {
                tft.drawRect(30, 275, 110, 30, TFT_BLACK);   // 绘制选中框
                tft.drawRect(30, 240, 110, 30, TFT_GREEN);   // 绘制选中框
            } else if (selectedItem == 1) {
                tft.drawRect(30, 275, 110, 30, TFT_GREEN);   // 绘制选中框
                tft.drawRect(30, 240, 110, 30, TFT_BLACK);   // 绘制选中框
            }
        }
        if(btn == &btDOWN)
        {
            selectedItem = selectedItem == 0 ? 1 : 0;
            if (selectedItem == 0) {
                tft.drawRect(30, 275, 110, 30, TFT_BLACK);   // 绘制选中框
                tft.drawRect(30, 240, 110, 30, TFT_GREEN);   // 绘制选中框
            } else if (selectedItem == 1) {
                tft.drawRect(30, 275, 110, 30, TFT_GREEN);   // 绘制选中框
                tft.drawRect(30, 240, 110, 30, TFT_BLACK);   // 绘制选中框
            }
        }
        if(btn == &btA){
            page.PagePush(PAGE_Game);
        }
    }
}

/**
  * @brief  页面注册
  * @param  pageID:为此页面分配的ID号
  * @retval 无
  */
void PageRegister_MainMenu(uint8_t pageID)
{
    /*注册至页面调度器*/
    page.PageRegister(pageID, Setup, NULL, Exit, Event);
}
