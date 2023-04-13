#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// ���峣��
#define WIDTH 60 // ��Ϸ������
#define HEIGHT 20 // ��Ϸ����߶�
#define INIT_LENGTH 5 // �ߵĳ�ʼ����
#define SPEED 100 // ÿһ֡��ʱ���������룩

// ����ö������
enum Direction { UP, RIGHT, DOWN, LEFT };

// ����ṹ��
struct Point {
    int x;
    int y;
};

// ����ȫ�ֱ���
int score = 0; // �÷�
int length = INIT_LENGTH; // �ߵĳ���
enum Direction direction = RIGHT; // �ߵķ���
struct Point snake[WIDTH * HEIGHT]; // �ߵ�����
struct Point food; // ʳ���λ��

// ��ʼ���ߺ�ʳ��
void init() {
    // ��ʼ���ߵ�����
    for (int i = 0; i < length; i++) {
        snake[i].x = i + 1;
        snake[i].y = 1;
    }
    // ��ʼ��ʳ���λ��
    food.x = rand() % WIDTH + 1;
    food.y = rand() % HEIGHT + 1;
}

// ������Ϸ����
void draw() {
    system("cls"); // ����
    // �����ϱ߽�
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");
    // �����м䲿��
    for (int i = 1; i <= HEIGHT; i++) {
        printf("#"); // ������߽�
        for (int j = 1; j <= WIDTH; j++) {
            if (i == snake[0].y && j == snake[0].x) { // ������ͷ
                printf("@");
            }
            else if (i == food.y && j == food.x) { // ����ʳ��
                printf("*");
            }
            else {
                int flag = 0;
                for (int k = 1; k < length; k++) {
                    if (i == snake[k].y && j == snake[k].x) { // ��������
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
        printf("#"); // �����ұ߽�
        printf("\n");
    }
    // �����±߽�
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");
    // ���Ƶ÷�
    printf("Score: %d\n", score);
}

// �ƶ���
void move() {
    // ��¼��β��λ��
    struct Point tail = snake[length - 1];
    // �ƶ��ߵ�����
    for (int i = length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }
    // ���ݷ����ƶ���ͷ
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
    // �����ͷײǽ�ˣ���Ϸ����
    if (snake[0].x == 0 || snake[0].x == WIDTH + 1 || snake[0].y == 0 || snake[0].y == HEIGHT + 1) {
        printf("Game over!\n");
        exit(0);
    }
    // �����ͷײ���Լ��ˣ���Ϸ����
    for (int i = 1; i < length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            printf("Game over!\n");
            exit(0);
        }
    }
    // �����ͷ�Ե���ʳ��÷ּ�һ
    if (snake[0].x == food.x && snake[0].y == food.y) {
        score++;
        length++;
        // ����β������һ������
        snake[length - 1] = tail;
        // ��������ʳ��λ��
        food.x = rand() % WIDTH + 1;
        food.y = rand() % HEIGHT + 1;
    }
}

// �����û�����
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

// ������
int main() {
    // ���ع��
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &CursorInfo);
    // ��ʼ����Ϸ
    init();
    // ��ʼ��Ϸѭ��
    while (1) {
        draw();
        move();
        input();
        Sleep(SPEED);
    }
    return 0;
}