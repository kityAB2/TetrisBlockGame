#include "Music.h"
//这个界面对应的音乐
int melody[] = {
  523, 494, 523, 587, 659, 587, 523, 494, 523, 392, // 第一句旋律
  523, 494, 523, 587, 659, 587, 523, 494, 523, 392, // 第二句旋律
  587, 523, 659, 587, 523, 494, 587, 659, 523, 523, // 第三句旋律
  523, 494, 523, 392, 523, 494, 523, 587, 523       // 第四句旋律
};

int noteDurations[] = {
  4, 4, 4, 4, 2, 4, 4, 4, 4, 2,  // 第一句时值
  4, 4, 4, 4, 2, 4, 4, 4, 4, 2,  // 第二句时值
  4, 4, 4, 4, 4, 4, 4, 4, 2, 2,  // 第三句时值
  4, 4, 4, 4, 4, 4, 4, 4, 2      // 第四句时值
};
int totalNotes = sizeof(melody) / sizeof(melody[0]);
unsigned long lastNoteTime1 = 0; 
int currentNote = 0; // 当前播放的音符索引
bool isPlaying = false; // 播放状态


//音乐相关
void startPlaying() {
    if (!isPlaying) {
        isPlaying = true; // 开启播放
        currentNote = 0; // 重置到第一个音符
        lastNoteTime1 = millis(); // 重置开始时间
        ledcWriteTone(LEDC_CHANNEL, melody[currentNote]); // 播放当前音符
    }
}

// 停止播放音符的函数
void stopPlaying() {
    if (isPlaying) {
        ledcWriteTone(LEDC_CHANNEL, 0); // 停止音符
        isPlaying = false; // 停止播放
        currentNote = 0; // 重置到第一个音符
    }
}
void playMelody() {
    if (!isPlaying) return; // 如果没有正在播放，则直接返回

    // 计算当前音符的持续时间
    int noteDuration = 1000 / noteDurations[currentNote];

    // 检查是否到达播放下一个音符的时间
    if (millis() - lastNoteTime1 >= noteDuration) {
        // 停止当前音符
        ledcWriteTone(LEDC_CHANNEL, 0);

        // 更新上一个音符的播放时间
        lastNoteTime1 += noteDuration;

        // 播放下一个音符
        currentNote++;
        if (currentNote >= totalNotes) {
            currentNote = 0; // 如果到达末尾，则循环到开头
        }

        // 计算下一个音符的持续时间
        noteDuration = 1000 / noteDurations[currentNote];
        ledcWriteTone(LEDC_CHANNEL, melody[currentNote]); // 播放当前音符

        // 更新上一个音符的播放时间
        lastNoteTime1 = millis();
    }
}