﻿#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>
#include "windows.h"

UINT toInt(SYSTEMTIME);
BOOL exceedsDelay(UINT cur, UINT prev, UINT delay);

#define MILLIS_IN_SECONDS 1000
#define SECONDS_IN_MINUTE 60
#define MINUTES_IN_HOUR 60
#define HOURS_IN_DAY 24
#define MILLIS_IN_DAY (HOURS_IN_DAY * MINUTES_IN_HOUR * SECONDS_IN_MINUTE * MILLIS_IN_SECONDS)

VOID ErrorExit(LPCSTR);

int game() {
    HANDLE hStdin;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // для смены цветов консоли
    const short bufferSize = 128;
    INPUT_RECORD irInBuf[bufferSize];

    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    if (hStdin == INVALID_HANDLE_VALUE) {
        ErrorExit("GetStdHandle");
    }

    int index = 0; // счётких итераций
    int eventsCount = 0; // счётчик обработанных событий
    const int x_coordinate = 11;
    const int y_coordinate = 11;
    int x = 5;
    int y = 10;

    int player_position[3][2]{
        {5, 0},
        {5, 10},
        {0, 5}
    };
    //char position[x_coordinate]{ '*', '*', '*', '*', '*', 'x', '*', '*', '*', '*', '*' };

    const UINT activeDuration = 10 * MILLIS_IN_SECONDS; //длительность работы программы в милисекундах
    const UINT delay = 200;

    SYSTEMTIME tempTime; //системное время
    GetSystemTime(&tempTime); //обновление системного времени в переменной

    UINT time = toInt(tempTime); //текущее время в милисекундах от начала года
    UINT startTime = time; //время запуска программы в милисекундах от начала месяца
    UINT prevTime = time;
    UINT endTime = time + activeDuration; //время в милисекундах от начала года

    //while (time - startTime < activeDuration) {
    while (index < 1000) {//10000000) {
        GetSystemTime(&tempTime);
        time = toInt(tempTime);

        DWORD cNumRead = 0; // счётчик обрабатываемых событий
        BOOL peekSuccessful = PeekConsoleInput(
            hStdin,
            irInBuf,
            bufferSize,
            &cNumRead
        );

        if (!peekSuccessful) {
            ErrorExit("PeekConsoleInput");
        }
        if (!FlushConsoleInputBuffer(hStdin)) {
            ErrorExit("FlushConsoleInputBuffer");
        }

        eventsCount += cNumRead;

        if (cNumRead != 0) { // чтение клавишь 
            for (DWORD i = 0; i < cNumRead; i++) {
                if (irInBuf[i].EventType == KEY_EVENT) {
                    KEY_EVENT_RECORD ker = irInBuf[i].Event.KeyEvent;
                    if (ker.bKeyDown) {
                        if (ker.wVirtualKeyCode == 38 && y > 0) {
                            y--;
                        }
                        else if (ker.wVirtualKeyCode == 40 && y < y_coordinate - 1) {
                            y++;
                        }
                        if (ker.wVirtualKeyCode == 39 && x >= 0 && x < 10) {
                            x++;
                        }
                        else if (ker.wVirtualKeyCode == 37 && x > 0 && x <= 10) {
                            x--;
                        } // при нажатии стрелок происход изменение в координатной оси
                        //printf("key %d pressed\n", ker.wVirtualKeyCode);
                    }
                    else {
                        //printf("key released\n");
                    }
                }
            }
            index++;
        }

        if (!exceedsDelay(time, prevTime, delay)) { // делает задержку последующим действиям программы
            continue;
        }

        HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD cd;
        cd.X = 0;
        cd.Y = 0;
        SetConsoleCursorPosition(hd, cd); // чистка консоли
        prevTime = time;
        //printf("tick\n");
        for (int i = 0; i < y_coordinate; i++) { // отображение сетки
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
            printf("|");
            for (int j = 0; j < x_coordinate; j++) {
                if ((j == player_position[0][1] && i == player_position[0][0]) ||
                    (j == player_position[1][1] && i == player_position[1][0]) ||
                    (j == player_position[2][1] && i == player_position[2][0])) {
                    SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
                    printf(" x ");
                }
                else if (j == x && i == y) {
                    SetConsoleTextAttribute(handle, FOREGROUND_RED);
                    printf(" x ");
                }
                else {
                    printf(" * ");
                }

                SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
                printf("|");
            }
            printf("\n");
        }

        int count = 0;
        while (count < 3) {
            std::random_device random_device; // Источник энтропии.
            std::mt19937 generator(random_device()); // Генератор случайных чисел.
            // (Здесь берется одно инициализирующее значение, можно брать больше)

            std::uniform_int_distribution<> distribution(1, 4); // Равномерное распределение [1, 4]

            int rand_count = distribution(generator); // Случайное число.
            if (player_position[count][0] == 11 && player_position[count][1] == 11) {
                count++;
                continue;
            }
            if (rand_count == 1 && player_position[count][0] > 0 && player_position[count][0] < 11) {
                player_position[count][0]--;
                count++;
            }
            else if (rand_count == 2 && player_position[count][0] < 10) {
                player_position[count][0]++;
                count++;
            }
            else if (rand_count == 3 && player_position[count][1] < 10) {
                player_position[count][1]++;
                count++;
            }
            else if (rand_count == 4 && player_position[count][1] > 0 && player_position[count][1] < 11) {
                player_position[count][1]--;
                count++;
            }
        }
        if (player_position[0][0] == player_position[1][0] && player_position[0][1] == player_position[1][1]) {
            player_position[0][0] = 11;
            player_position[0][1] = 11;
        }
        else if (player_position[1][0] == player_position[2][0] && player_position[1][1] == player_position[2][1]) {
            player_position[1][0] = 11;
            player_position[1][1] = 11;
        }
        else if (player_position[0][0] == player_position[2][0] && player_position[0][1] == player_position[2][1]) {
            player_position[0][0] = 11;
            player_position[0][1] = 11;
        }
        for (int k = 0; k < 3; k++) {
            if (x == player_position[k][1] && y == player_position[k][0])
                return 0;
            /*printf(" %d %d \n",
                player_position[k][0],
                player_position[k][1]
            );*/
        }
    }
    return 0;
}

int main(VOID) {
    char start;
    bool i = 0;
    while (!i) {
        start = '-';
        system("cls");
        std::cout << "Press 'Y' to start and press 'N' to close: ";
        std::cin >> start;
        if (start == 'Y' || start == 'y') {
            game();
        }
        else if (start == 'N' || start == 'n')
            return 0;
        continue;
    }
    return 0;
}

BOOL exceedsDelay(UINT cur, UINT prev, UINT delay) {
    //если предыдущее время значительно больше текущего, значит случился переход через ноль
    if (prev > cur + delay)
        return cur + MILLIS_IN_DAY - prev > delay;
    else
        return cur - prev > delay;
}

UINT toInt(SYSTEMTIME systemTime) {
    UINT hoursInMounth = systemTime.wDay * HOURS_IN_DAY + systemTime.wHour;
    UINT minutesInMorth = hoursInMounth * MINUTES_IN_HOUR + systemTime.wMinute;
    UINT secondsInMounth = minutesInMorth * SECONDS_IN_MINUTE + systemTime.wSecond;
    UINT millisInMounth = secondsInMounth * MILLIS_IN_SECONDS + systemTime.wMilliseconds;
    return millisInMounth;
}

VOID ErrorExit(LPCSTR lpszMessage) {
    fprintf(stderr, "%s\n", lpszMessage);
    ExitProcess(0);
}