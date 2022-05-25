#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <thread>
#include <mutex>
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

int player_position[10][2]{ 0 };

int x_coordinate = 11;
int y_coordinate = 11;

class X {
    std::recursive_mutex m;
    std::string shared;
public:
    void fun1() {
        std::lock_guard<std::recursive_mutex> lk(m);
        std::random_device random_device; // Источник энтропии.
        std::mt19937 generator(random_device()); // Генератор случайных чисел.
        // (Здесь берется одно инициализирующее значение, можно брать больше)

        std::uniform_int_distribution<> distribution(1, 4); // Равномерное распределение [1, 4]

        int rand_count = distribution(generator); // Случайное число.

        if (rand_count == 1 && player_position[0][0] > 0 && player_position[0][0] < y_coordinate) {
            player_position[0][0]--;
        }
        else if (rand_count == 2 && player_position[0][0] < y_coordinate - 1) {
            player_position[0][0]++;
        }
        else if (rand_count == 3 && player_position[0][1] < x_coordinate - 1) {
            player_position[0][1]++;
        }
        else if (rand_count == 4 && player_position[0][1] > 0 && player_position[0][1] < x_coordinate) {
            player_position[0][1]--;
        }
    }
    void fun2() {
        std::lock_guard<std::recursive_mutex> lk(m);
        std::random_device random_device; // Источник энтропии.
        std::mt19937 generator(random_device()); // Генератор случайных чисел.
        // (Здесь берется одно инициализирующее значение, можно брать больше)

        std::uniform_int_distribution<> distribution(1, 4); // Равномерное распределение [1, 4]

        int rand_count = distribution(generator); // Случайное число.
        if (rand_count == 1 && player_position[1][0] > 0 && player_position[1][0] < y_coordinate) {
            player_position[1][0]--;
        }
        else if (rand_count == 2 && player_position[1][0] < y_coordinate - 1) {
            player_position[1][0]++;
        }
        else if (rand_count == 3 && player_position[1][1] < x_coordinate - 1) {
            player_position[1][1]++;
        }
        else if (rand_count == 4 && player_position[1][1] > 0 && player_position[1][1] < x_coordinate) {
            player_position[1][1]--;
        }
    };
    void fun3() {
        std::lock_guard<std::recursive_mutex> lk(m);
        std::random_device random_device; // Источник энтропии.
        std::mt19937 generator(random_device()); // Генератор случайных чисел.
        // (Здесь берется одно инициализирующее значение, можно брать больше)

        std::uniform_int_distribution<> distribution(1, 4); // Равномерное распределение [1, 4]

        int rand_count = distribution(generator); // Случайное число.
        if (rand_count == 1 && player_position[2][0] > 0 && player_position[2][0] < y_coordinate) {
            player_position[2][0]--;
        }
        else if (rand_count == 2 && player_position[2][0] < y_coordinate - 1) {
            player_position[2][0]++;
        }
        else if (rand_count == 3 && player_position[2][1] < x_coordinate - 1) {
            player_position[2][1]++;
        }
        else if (rand_count == 4 && player_position[2][1] > 0 && player_position[2][1] < y_coordinate) {
            player_position[2][1]--;
        }
    };
    void fun4() {
        std::lock_guard<std::recursive_mutex> lk(m);
        std::random_device random_device; // Источник энтропии.
        std::mt19937 generator(random_device()); // Генератор случайных чисел.
        // (Здесь берется одно инициализирующее значение, можно брать больше)

        std::uniform_int_distribution<> distribution(1, 4); // Равномерное распределение [1, 4]

        int rand_count = distribution(generator); // Случайное число.
        if (rand_count == 1 && player_position[3][0] > 0 && player_position[3][0] < y_coordinate) {
            player_position[3][0]--;
        }
        else if (rand_count == 2 && player_position[3][0] < y_coordinate - 1) {
            player_position[3][0]++;
        }
        else if (rand_count == 3 && player_position[3][1] < x_coordinate - 1) {
            player_position[3][1]++;
        }
        else if (rand_count == 4 && player_position[3][1] > 0 && player_position[3][1] < x_coordinate) {
            player_position[3][1]--;
        }
    };
    void fun5() {
        std::lock_guard<std::recursive_mutex> lk(m);
        std::random_device random_device; // Источник энтропии.
        std::mt19937 generator(random_device()); // Генератор случайных чисел.
        // (Здесь берется одно инициализирующее значение, можно брать больше)

        std::uniform_int_distribution<> distribution(1, 4); // Равномерное распределение [1, 4]

        int rand_count = distribution(generator); // Случайное число.
        if (rand_count == 1 && player_position[4][0] > 0 && player_position[4][0] < y_coordinate) {
            player_position[4][0]--;
        }
        else if (rand_count == 2 && player_position[4][0] < y_coordinate - 1) {
            player_position[4][0]++;
        }
        else if (rand_count == 3 && player_position[4][1] < x_coordinate - 1) {
            player_position[4][1]++;
        }
        else if (rand_count == 4 && player_position[4][1] > 0 && player_position[4][1] < x_coordinate) {
            player_position[4][1]--;
        }
    };
    void fun6() {
        std::lock_guard<std::recursive_mutex> lk(m);
        std::random_device random_device; // Источник энтропии.
        std::mt19937 generator(random_device()); // Генератор случайных чисел.
        // (Здесь берется одно инициализирующее значение, можно брать больше)

        std::uniform_int_distribution<> distribution(1, 4); // Равномерное распределение [1, 4]

        int rand_count = distribution(generator); // Случайное число.
        if (rand_count == 1 && player_position[5][0] > 0 && player_position[5][0] < y_coordinate) {
            player_position[5][0]--;
        }
        else if (rand_count == 2 && player_position[5][0] < y_coordinate - 1) {
            player_position[5][0]++;
        }
        else if (rand_count == 3 && player_position[5][1] < x_coordinate - 1) {
            player_position[5][1]++;
        }
        else if (rand_count == 4 && player_position[5][1] > 0 && player_position[5][1] < x_coordinate) {
            player_position[5][1]--;
        }
    };
    void fun7() {
        std::lock_guard<std::recursive_mutex> lk(m);
        std::random_device random_device; // Источник энтропии.
        std::mt19937 generator(random_device()); // Генератор случайных чисел.
        // (Здесь берется одно инициализирующее значение, можно брать больше)

        std::uniform_int_distribution<> distribution(1, 4); // Равномерное распределение [1, 4]

        int rand_count = distribution(generator); // Случайное число.
        if (rand_count == 1 && player_position[6][0] > 0 && player_position[6][0] < y_coordinate) {
            player_position[6][0]--;
        }
        else if (rand_count == 2 && player_position[6][0] < y_coordinate - 1) {
            player_position[6][0]++;
        }
        else if (rand_count == 3 && player_position[6][1] < x_coordinate - 1) {
            player_position[6][1]++;
        }
        else if (rand_count == 4 && player_position[6][1] > 0 && player_position[6][1] < x_coordinate) {
            player_position[6][1]--;
        }
    };
    void fun8() {
        std::lock_guard<std::recursive_mutex> lk(m);
        std::random_device random_device; // Источник энтропии.
        std::mt19937 generator(random_device()); // Генератор случайных чисел.
        // (Здесь берется одно инициализирующее значение, можно брать больше)

        std::uniform_int_distribution<> distribution(1, 4); // Равномерное распределение [1, 4]

        int rand_count = distribution(generator); // Случайное число.
        if (rand_count == 1 && player_position[7][0] > 0 && player_position[7][0] < y_coordinate) {
            player_position[7][0]--;
        }
        else if (rand_count == 2 && player_position[7][0] < y_coordinate - 1) {
            player_position[7][0]++;
        }
        else if (rand_count == 3 && player_position[7][1] < x_coordinate - 1) {
            player_position[7][1]++;
        }
        else if (rand_count == 4 && player_position[7][1] > 0 && player_position[7][1] < x_coordinate) {
            player_position[7][1]--;
        }
    };
    void fun9() {
        std::lock_guard<std::recursive_mutex> lk(m);
        std::random_device random_device; // Источник энтропии.
        std::mt19937 generator(random_device()); // Генератор случайных чисел.
        // (Здесь берется одно инициализирующее значение, можно брать больше)

        std::uniform_int_distribution<> distribution(1, 4); // Равномерное распределение [1, 4]

        int rand_count = distribution(generator); // Случайное число.
        if (rand_count == 1 && player_position[8][0] > 0 && player_position[8][0] < y_coordinate) {
            player_position[8][0]--;
        }
        else if (rand_count == 2 && player_position[8][0] < y_coordinate - 1) {
            player_position[8][0]++;
        }
        else if (rand_count == 3 && player_position[8][1] < x_coordinate - 1) {
            player_position[8][1]++;
        }
        else if (rand_count == 4 && player_position[8][1] > 0 && player_position[8][1] < x_coordinate) {
            player_position[8][1]--;
        }
    };
    void fun10() {
        std::lock_guard<std::recursive_mutex> lk(m);
        std::random_device random_device; // Источник энтропии.
        std::mt19937 generator(random_device()); // Генератор случайных чисел.
        // (Здесь берется одно инициализирующее значение, можно брать больше)

        std::uniform_int_distribution<> distribution(1, 4); // Равномерное распределение [1, 4]

        int rand_count = distribution(generator); // Случайное число.
        if (rand_count == 1 && player_position[9][0] > 0 && player_position[9][0] < y_coordinate) {
            player_position[9][0]--;
        }
        else if (rand_count == 2 && player_position[9][0] < y_coordinate - 1) {
            player_position[9][0]++;
        }
        else if (rand_count == 3 && player_position[9][1] < x_coordinate - 1) {
            player_position[9][1]++;
        }
        else if (rand_count == 4 && player_position[9][1] > 0 && player_position[9][1] < x_coordinate) {
            player_position[9][1]--;
        }
    };
};

int game(int Number) {
    player_position[0][0] = 5; player_position[0][1] = 0;
    player_position[1][0] = 5; player_position[1][1] = 10;
    player_position[2][0] = 0; player_position[2][1] = 5;

    player_position[3][0] = 0; player_position[3][1] = 0;

    player_position[4][0] = 0; player_position[4][1] = 15;
    player_position[5][0] = 15; player_position[5][1] = 15;
    player_position[6][0] = 15; player_position[6][1] = 0;

    player_position[7][0] = 0; player_position[7][1] = 10;
    player_position[8][0] = 8; player_position[8][1] = 8;
    player_position[9][0] = 10; player_position[9][1] = 0;
    int loss = 0;
    int x, y;
    if (Number < 4) {
        x_coordinate = 11;
        y_coordinate = 11;
        x = 5;
        y = 10;
    }
    else if (Number > 3) {
        x_coordinate = 16;
        y_coordinate = 16;
        x = 8;
        y = 15;
    }
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

    const UINT activeDuration = 10 * MILLIS_IN_SECONDS; //длительность работы программы в милисекундах
    const UINT delay = 200;

    SYSTEMTIME tempTime; //системное время
    GetSystemTime(&tempTime); //обновление системного времени в переменной

    UINT time = toInt(tempTime); //текущее время в милисекундах от начала года
    UINT startTime = time; //время запуска программы в милисекундах от начала месяца
    UINT prevTime = time;
    UINT coordTime = time;
    UINT endTime = time + activeDuration; //время в милисекундах от начала года

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
                        if (ker.wVirtualKeyCode == 38 && y > 0 && y < y_coordinate) {
                            y--;
                        }
                        else if (ker.wVirtualKeyCode == 40 && y < y_coordinate - 1) {
                            y++;
                        }
                        if (ker.wVirtualKeyCode == 39 && x >= 0 && x < x_coordinate - 1) {
                            x++;
                        }
                        else if (ker.wVirtualKeyCode == 37 && x > 0 && x < x_coordinate) {
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

        if (exceedsDelay(time, coordTime, 10000)) { // делает задержку последующим действиям программы
            y_coordinate--;
            x_coordinate--;
            coordTime = time;
            system("cls");
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
                bool check = false;
                for (int K = 0; K < Number; K++) {
                    if (j == player_position[K][1] && i == player_position[K][0]) {
                        SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
                        printf(" x ");
                        check = true;
                    }
                }
                if (j == x && i == y && !check) {
                    SetConsoleTextAttribute(handle, FOREGROUND_RED);
                    printf(" x ");
                }
                else if (!check) {
                    printf(" * ");
                }
                SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
                printf("|");
            }
            printf("\n");
        }

        X x_mutex;
        std::thread t1(&X::fun1, &x_mutex);
        std::thread t2(&X::fun2, &x_mutex);
        std::thread t3(&X::fun3, &x_mutex);
        std::thread t4(&X::fun4, &x_mutex);
        std::thread t5(&X::fun5, &x_mutex);
        std::thread t6(&X::fun6, &x_mutex);
        std::thread t7(&X::fun7, &x_mutex);
        std::thread t8(&X::fun8, &x_mutex);
        std::thread t9(&X::fun9, &x_mutex); 
        std::thread t10(&X::fun10, &x_mutex);
        t1.join(); t2.join(); t3.join();
        t4.join(); t5.join(); t6.join();
        t7.join(); t8.join(); t9.join();
        t10.join();

        for (int i = 0; i < Number; i++) 
            for (int j = 0; j < Number; j++) {
                if (player_position[i][0] == player_position[j][0] && player_position[i][1] == player_position[j][1] && i != j) {
                    player_position[i][0] = y_coordinate;
                    player_position[i][1] = x_coordinate;
                    loss++;
                }
            }
        for (int i = 0; i < Number; i++) {
            if (loss == Number - 1)
                return 0;
            else if (x == player_position[i][1] && y == player_position[i][0])
                return 1;
        }
        if (y >= y_coordinate)
            return 1;
    }
    return 0;
}

int main(VOID) {
    //char start;
    bool i = 0;
    while (!i) {
        char start = '-';
        int G = 10;
        int number = 3;
        std::cout << "Press 'Y' to start and press 'N' to close: ";
        std::cin >> start;
        if (start == 'Y' || start == 'y') {
            std::cout << "Enter the number of players \n (from one to ten): ";
            std::cin >> number;
            if (number < 1)
                continue;
            G = game(number);
        }
        else if (start == 'N' || start == 'n')
            return 0;
        system("cls");
        if (G == 0)
            std::cout << "YOU WON!\n";
        else if (G == 1)
            std::cout << "YOU LOSS...\n";
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