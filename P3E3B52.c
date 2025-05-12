// 需使用 Big5 編碼格式開啟檔案，避免中文亂碼
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    printf(
        "                _______\n"
        "                |  |  |   \n"
        "                |  |  |   \n"
        "                |  |  |\n"
        "                |  |  |\n"
        "                |  |  |\n"
        "                |  |  |\n"
        "            [___|__|__|___]\n"
        "                 | | |\n"
        "                 | | | \n"
        "                 | | |\n"
        "                 | | |   \n"
        "                 | | |\n"
        "                 | | |\n"
        "                 | | |\n"
        "                 | | |   \n"
        "                 | | | \n"
        "                 | | |\n"
        "                 \\ | /\n"
        "                  \\|/     \n"
    );
    printf("\n程式設計作業三\nUE3B52\n411102252\n沈威宇\n");

    const int pw = 2025;
    int input, tries = 0;
    while (tries < 3) {
        printf("請輸入四位數密碼：");
        if (scanf("%d", &input) == 1 && input == pw) break;
        tries++;
        printf("密碼錯誤，還有 %d 次機會！\n", 3 - tries);
    }
    if (tries == 3) {
        printf("密碼錯誤已達三次，程式結束！\n");
        return 1;
    }
    while (getchar() != '\n'); 
    int seats[9][9] = {0};
    int reserved = 0;
    srand((unsigned)time(NULL));
    while (reserved < 10) {
        int rr = rand() % 9;
        int cc = rand() % 9;
        if (seats[rr][cc] == 0) {
            seats[rr][cc] = 1;
            reserved++;
        }
    }

    while (1) {
        system("cls");  
        printf("----------[Booking System]----------\n");
        printf("|  a. Available seats             |\n");
        printf("|  b. Arrange for you             |\n");
        printf("|  c. Choose by yourself          |\n");
        printf("|  d. Exit                        |\n");
        printf("-----------------------------------\n");
        printf("請輸入 a/b/c/d 選項：");

        char in;
        scanf(" %c", &in);  // 前空格跳過殘留換行

        if (in == 'a' || in == 'A') {
            //a選項
            printf("\\123456789\n");
            for (int row = 8; row >= 0; row--) {
                printf("%d-", row + 1);
                for (int col = 0; col < 9; col++)
                    putchar(seats[row][col] ? '*' : '-');
                putchar('\n');
            }
            printf("\n按任意鍵返回主選單...");
            getchar(); getchar();
        }
        else if (in == 'b' || in == 'B') {
            //b選項
            int need;
            while (1) {
                printf("請輸入要預訂的座位數 (1~4)：");
                if (scanf("%d", &need) != 1) {
                    while (getchar() != '\n');
                    printf("輸入錯誤！請輸入數字。\n");
                    continue;
                }
                if (need >= 1 && need <= 4) break;
                printf("輸入錯誤！範圍必須在 1～4。\n");
            }
            while (getchar() != '\n');

            int sug[9][9] = {0};
            if (need <= 3) {
                while (1) {
                    int row   = rand() % 9;
                    int start = rand() % (9 - need + 1);
                    int ok = 1;
                    for (int j = 0; j < need; j++)
                        if (seats[row][start + j]) { ok = 0; break; }
                    if (ok) {
                        for (int j = 0; j < need; j++)
                            sug[row][start + j] = 1;
                        break;
                    }
                }
            } else {
                if (rand() % 2 == 0) {
                    while (1) {
                        int row   = rand() % 9;
                        int start = rand() % 6;  
                        int ok = 1;
                        for (int j = 0; j < 4; j++)
                            if (seats[row][start + j]) { ok = 0; break; }
                        if (ok) {
                            for (int j = 0; j < 4; j++)
                                sug[row][start + j] = 1;
                            break;
                        }
                    }
                } else {
                    while (1) {
                        int row   = rand() % 8;
                        int start = rand() % 8; 
                        int ok = 1;
                        for (int j = 0; j < 2; j++)
                            if (seats[row  ][start + j] ||
                                seats[row+1][start + j])
                                { ok = 0; break; }
                        if (ok) {
                            for (int j = 0; j < 2; j++) {
                                sug[row  ][start + j] = 1;
                                sug[row+1][start + j] = 1;
                            }
                            break;
                        }
                    }
                }
            }
            printf("\\123456789\n");
            for (int r = 8; r >= 0; r--) {
                printf("%d-", r + 1);
                for (int c = 0; c < 9; c++) {
                    if      (sug[r][c])   putchar('@');
                    else if (seats[r][c]) putchar('*');
                    else                  putchar('-');
                }
                putchar('\n');
            }
            char y;
            while (1) {
                printf("滿意嗎？(y/n)：");
                scanf(" %c", &y);
                if (y=='y'||y=='Y') {
                    for (int rr = 0; rr < 9; rr++)
                        for (int cc = 0; cc < 9; cc++)
                            if (sug[rr][cc]) seats[rr][cc] = 1;
                    break;
                }
                if (y=='n'||y=='N') break;
                printf("輸入錯誤，請輸入 y 或 n。\n");
            }
            printf("按任意鍵返回主選單...");
            getchar(); getchar();
        }
        else if (in == 'c' || in == 'C') {
            //c選項
            int sug[9][9] = {0};
            while (1) {
                int rs, cs;
                printf("請輸入座位 (格式 row-col，輸入 0-0 結束)：");
                if (scanf("%d-%d", &rs, &cs) != 2) {
                    while (getchar() != '\n');
                    printf("格式錯誤，請重新輸入\n");
                    continue;
                }
                if (rs == 0 && cs == 0) break;
                if (rs < 1 || rs > 9 || cs < 1 || cs > 9) {
                    printf("範圍錯誤，列行必須 1~9\n");
                    continue;
                }
                if (seats[rs-1][cs-1] || sug[rs-1][cs-1]) {
                    printf("該座位已被預訂或已選擇，請重新輸入\n");
                    continue;
                }
                sug[rs-1][cs-1] = 1;
            }
            while (getchar() != '\n');
            printf("\\123456789\n");
            for (int r = 8; r >= 0; r--) {
                printf("%d-", r + 1);
                for (int c = 0; c < 9; c++) {
                    if      (sug[r][c])   putchar('@');
                    else if (seats[r][c]) putchar('*');
                    else                  putchar('-');
                }
                putchar('\n');
            }
            printf("按任意鍵確認並返回主選單...");
            getchar();
            for (int r = 0; r < 9; r++)
                for (int c = 0; c < 9; c++)
                    if (sug[r][c]) seats[r][c] = 1;
        }
    else if (in == 'd' || in == 'D') {
        //d選項
        char y;
        while (1) {
            printf("Continue? (y/n): ");
            scanf(" %c", &y);            
            if (y == 'y' || y == 'Y') {
                break;                    
            } 
            else if (y == 'n' || y == 'N') {
                printf("感謝使用，再見！\n");
                return 0;              
            } 
            else {
                printf("輸入錯誤，請輸入 y 或 n。\n");
            }
        }
    }
        else {
            printf("選項錯誤，按任意鍵重試...");
            getchar(); getchar();
        }
    }

    return 0;
}
//本次作業是目前實作做大型的作業
//使用到很多迴圈與判斷函式
//寫起來困難度比前面兩次的作業還要增加不少
//期間也上網查詢與問過很多次gpt，如何完成儲存上次狀態與避免覆蓋以預定的位置
//雖然這種對初學者來說是大型專案，且很有挑戰性，希望下次不要失敗bug這麼多
