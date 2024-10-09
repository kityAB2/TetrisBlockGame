#include "BSP.h"

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

/*实例化页面调度器*/
PageManager page(PAGE_MAX);

/*页面注册器*/
#define PAGE_REG(name)\
do{\
    extern void PageRegister_##name(uint8_t pageID);\
    PageRegister_##name(PAGE_##name);\
}while(0)


/**
  * @brief  页面初始化
  * @param  无
  * @retval 无
  */
void Pages_Init()
{
    
    PAGE_REG(MainMenu);     //主菜单
    PAGE_REG(Game);         //游戏
    
    page.PagePush(PAGE_MainMenu);//打开表盘
}

/**
  * @brief  显示初始化
  * @param  无
  * @retval 无
  */
void Display_Update()
{
    // lv_task_handler();
    page.Running();
}



