//�ݨϥ�Big5�s�X�榡�}���ɮסA���קK�����ܦ��ýX
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
    printf("\n�{���]�p�@�~�T\n");
    printf("UE3B52\n");
    printf("411102252\n");
    printf("�H�¦t\n");
    printf("�п�J�|��ƱK�X:");
    int pw = 2025, input,i;       //�K�X�w�]2025
    scanf("%d", &input);
    if (input != pw) {
        printf("�K�X��J���~\n");
        for(i=0;i<2;i++){
            printf("�п�J�|��ƱK�X:\n"); 
            scanf("%d", &input);
        }
        printf("�K�X��J���~�w�F�T��\n");
        system("pause");
        return 1;
    }
    system("cls"); //�M���ù�
    while (getchar() != '\n'); //�M�z�w�İ�
    while(1){
        printf("----------[Booking System]----------\n");
        printf("|  a. Available seats             |\n");
        printf("|  b. Arrange for you             |\n");
        printf("|  c. Choose by yourself          |\n");
        printf("|  d. Exit                        |\n");
        printf("-----------------------------------\n");
        char in;
        printf("�п�Xa/b/c�ﶵ:");
        scanf(" %c",&in);
        system("cls"); //�M���ù�
        int seats[9][9] = {0};     
        int r = 0;
        srand((unsigned)time(NULL)); //�ϥ�#include <time.h>�A�C�����H��
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
            printf("\n�����N���^�D���...");
            getchar(); getchar();   
            system("cls");        
            break;



        }
    }
    system("pause");
    return 0;
}