#ifndef TETRISBLOCK_H
#define TETRISBLOCK_H
#define GameAreStartPosX1 25
#define GameAreStartPosY1 60
#define SocoreArePosX1 0
#define SocoreArePosY1 0
#define NextBlockArePosX1 120
#define NextBlockArePosY1 0

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <BSP.h>
// extern TFT_eSPI tft;

struct Point {
    int x;
    int y;
};
struct Block {
    Point square[4][4];
    int numRotate;
    int color;
};
extern uint16_t BlockImage[8][12][12];
extern Block blocks[7];



const int Length = 12;     // the number of pixels for a side of a block
const int Width = 10;     // the number of horizontal blocks
const int Height = 20;    // the number of vertical blocks


class TetrisBlock {
public:
    unsigned int last_score=0xFFFF;
    int last_block_num_rotate=0xFFFF;
    int last_block_color=0xFFFF;
    uint16_t backBuffer[240][120];  //游戏缓冲区
    uint16_t newblock[48][48];      //新色块缓冲区
    int screen[Width][Height] = {0};//显示当前色块区域
    bool started = false;//游戏开始标志位
    bool gameover = false;//游戏结束标志位
    unsigned int score = 0;//分数
    int pre_rot,next_rot;//当前块的旋转方向和下一个块的旋转方向
    Point pre_pos;//表示当前块的位置
    Block pre_block,next_block;//当前块和下一个颜色块
    unsigned long int TimeElsp;//时间
    // 构造函数
    // TetrisBlock();
    TetrisBlock();
    void gameInit();
    void Draw();
    void delectLine();

    void gameOver();
    void reviseScreen(Point next_pos, int next_rot);
    void putStartPos();
    bool getSquares(Block block, Point pos, int rot, Point* squares);
    unsigned long score2Level ();
    void getNextPosRot(Point* pnext_pos, int* pnext_rot, bool received, boolean* Button_A, boolean* Button_LEFT, boolean* Button_RIGHT, boolean* Button_DOWN, boolean* Button_UP);
    ~TetrisBlock();
};



#endif // TETRISBLOCK_H
