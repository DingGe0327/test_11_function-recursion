#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// 定义常量
#define WIDTH 60 // 游戏区域宽度
#define HEIGHT 20 // 游戏区域高度
#define INIT_LENGTH 5 // 蛇的初始长度
#define SPEED 100 // 每一帧的时间间隔（毫秒）

// 定义枚举类型
enum Direction { UP, RIGHT, DOWN, LEFT };

// 定义结构体
struct Point {
    int x;
    int y;
};

// 定义全局变量
int score = 0; // 得分
int length = INIT_LENGTH; // 蛇的长度
enum Direction direction = RIGHT; // 蛇的方向
struct Point snake[WIDTH * HEIGHT]; // 蛇的身体
struct Point food; // 食物的位置

// 初始化蛇和食物
void init() {
    // 初始化蛇的身体
    for (int i = 0; i < length; i++) {
        snake[i].x = i + 1;
        snake[i].y = 1;
    }
    // 初始化食物的位置
    food.x = rand() % WIDTH + 1;
    food.y = rand() % HEIGHT + 1;
}

// 绘制游戏区域
void draw() {
    system("cls"); // 清屏
    // 绘制上边界
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");
    // 绘制中间部分
    for (int i = 1; i <= HEIGHT; i++) {
        printf("#"); // 绘制左边界
        for (int j = 1; j <= WIDTH; j++) {
            if (i == snake[0].y && j == snake[0].x) { // 绘制蛇头
                printf("@");
            }
            else if (i == food.y && j == food.x) { // 绘制食物
                printf("*");
            }
            else {
                int flag = 0;
                for (int k = 1; k < length; k++) {
                    if (i == snake[k].y && j == snake[k].x) { // 绘制蛇身
                        printf("o");
                        flag = 1;
                        break;
                    }
                }
                if (!flag) {
                    printf(" ");
                }
            }
        }
        printf("#"); // 绘制右边界
        printf("\n");
    }
    // 绘制下边界
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");
    // 绘制得分
    printf("Score: %d\n", score);
}

// 移动蛇
void move() {
    // 记录蛇尾的位置
    struct Point tail = snake[length - 1];
    // 移动蛇的身体
    for (int i = length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }
    // 根据方向移动蛇头
    switch (direction) {
    case UP:
        snake[0].y--;
        break;
    case RIGHT:
        snake[0].x++;
        break;
    case DOWN:
        snake[0].y++;
        break;
    case LEFT:
        snake[0].x--;
        break;
    }
    // 如果蛇头撞墙了，游戏结束
    if (snake[0].x == 0 || snake[0].x == WIDTH + 1 || snake[0].y == 0 || snake[0].y == HEIGHT + 1) {
        printf("Game over!\n");
        exit(0);
    }
    // 如果蛇头撞到自己了，游戏结束
    for (int i = 1; i < length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            printf("Game over!\n");
            exit(0);
        }
    }
    // 如果蛇头吃到了食物，得分加一
    if (snake[0].x == food.x && snake[0].y == food.y) {
        score++;
        length++;
        // 在蛇尾处增加一个身体
        snake[length - 1] = tail;
        // 重新生成食物位置
        food.x = rand() % WIDTH + 1;
        food.y = rand() % HEIGHT + 1;
    }
}

// 处理用户输入
void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'w':
        case 'W':
            if (direction != DOWN) {
                direction = UP;
            }
            break;
        case 'd':
        case 'D':
            if (direction != LEFT) {
                direction = RIGHT;
            }
            break;
        case 's':
        case 'S':
            if (direction != UP) {
                direction = DOWN;
            }
            break;
        case 'a':
        case 'A':
            if (direction != RIGHT) {
                direction = LEFT;
            }
            break;
        }
    }
}

// 主函数
int main() {
    // 隐藏光标
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &CursorInfo);
    // 初始化游戏
    init();
    // 开始游戏循环
    while (1) {
        draw();
        move();
        input();
        Sleep(SPEED);
    }
    return 0;
}