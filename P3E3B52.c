//需使用Big5編碼格式開啟檔案，比避免中文變成亂碼
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
    printf("\n程式設計作業三\n");
    printf("UE3B52\n");
    printf("411102252\n");
    printf("沈威宇\n");
    printf("請輸入四位數密碼:");
    int pw = 2025, input,i;       //密碼預設2025
    scanf("%d", &input);
    if (input != pw) {
        printf("密碼輸入錯誤\n");
        for(i=0;i<2;i++){
            printf("請輸入四位數密碼:\n"); 
            scanf("%d", &input);
        }
        printf("密碼輸入錯誤已達三次\n");
        system("pause");
        return 1;
    }
    system("cls"); //清除螢幕
    while (getchar() != '\n'); //清理緩衝區
    while(1){
        printf("----------[Booking System]----------\n");
        printf("|  a. Available seats             |\n");
        printf("|  b. Arrange for you             |\n");
        printf("|  c. Choose by yourself          |\n");
        printf("|  d. Exit                        |\n");
        printf("-----------------------------------\n");
        char in;
        printf("請輸出a/b/c選項:");
        scanf(" %c",&in);
        system("cls"); //清除螢幕
        int seats[9][9] = {0};     
        int r = 0;
        srand((unsigned)time(NULL)); //使用#include <time.h>，每次都隨機
        while (r < 10) {
            int b = rand() % 9;     
            int c = rand() % 9;     
            if (seats[r][c] == 0) {
                seats[r][c] = 1;
                r++;
            }
        }
        switch (in) {
            case 'a': 
                printf("\\123456789\n");
                for (int row = 8; row >= 0; row--) {
                    printf("%d-", row + 1);
                    for (int col = 0; col < 9; col++) {
                        putchar(seats[row][col] ? '*' : '-');
                    }
                    putchar('\n');
                }
            printf("\n按任意鍵返回主選單...");
            getchar(); getchar();   
            system("cls");        
            break;



        }
    }
    system("pause");
    return 0;
}