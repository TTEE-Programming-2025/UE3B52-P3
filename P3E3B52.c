// �ݨϥ� Big5 �s�X�榡�}���ɮסA�קK����ýX
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
    printf("\n�{���]�p�@�~�T\nUE3B52\n411102252\n�H�¦t\n");

    const int pw = 2025;
    int input, tries = 0;
    while (tries < 3) {
        printf("�п�J�|��ƱK�X�G");
        if (scanf("%d", &input) == 1 && input == pw) break;
        tries++;
        printf("�K�X���~�A�٦� %d �����|�I\n", 3 - tries);
    }
    if (tries == 3) {
        printf("�K�X���~�w�F�T���A�{�������I\n");
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
        printf("�п�J a/b/c/d �ﶵ�G");

        char in;
        scanf(" %c", &in);  // �e�Ů���L�ݯd����

        if (in == 'a' || in == 'A') {
            //a�ﶵ
            printf("\\123456789\n");
            for (int row = 8; row >= 0; row--) {
                printf("%d-", row + 1);
                for (int col = 0; col < 9; col++)
                    putchar(seats[row][col] ? '*' : '-');
                putchar('\n');
            }
            printf("\n�����N���^�D���...");
            getchar(); getchar();
        }
        else if (in == 'b' || in == 'B') {
            //b�ﶵ
            int need;
            while (1) {
                printf("�п�J�n�w�q���y��� (1~4)�G");
                if (scanf("%d", &need) != 1) {
                    while (getchar() != '\n');
                    printf("��J���~�I�п�J�Ʀr�C\n");
                    continue;
                }
                if (need >= 1 && need <= 4) break;
                printf("��J���~�I�d�򥲶��b 1��4�C\n");
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
                printf("���N�ܡH(y/n)�G");
                scanf(" %c", &y);
                if (y=='y'||y=='Y') {
                    for (int rr = 0; rr < 9; rr++)
                        for (int cc = 0; cc < 9; cc++)
                            if (sug[rr][cc]) seats[rr][cc] = 1;
                    break;
                }
                if (y=='n'||y=='N') break;
                printf("��J���~�A�п�J y �� n�C\n");
            }
            printf("�����N���^�D���...");
            getchar(); getchar();
        }
        else if (in == 'c' || in == 'C') {
            //c�ﶵ
            int sug[9][9] = {0};
            while (1) {
                int rs, cs;
                printf("�п�J�y�� (�榡 row-col�A��J 0-0 ����)�G");
                if (scanf("%d-%d", &rs, &cs) != 2) {
                    while (getchar() != '\n');
                    printf("�榡���~�A�Э��s��J\n");
                    continue;
                }
                if (rs == 0 && cs == 0) break;
                if (rs < 1 || rs > 9 || cs < 1 || cs > 9) {
                    printf("�d����~�A�C�楲�� 1~9\n");
                    continue;
                }
                if (seats[rs-1][cs-1] || sug[rs-1][cs-1]) {
                    printf("�Ӯy��w�Q�w�q�Τw��ܡA�Э��s��J\n");
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
            printf("�����N��T�{�ê�^�D���...");
            getchar();
            for (int r = 0; r < 9; r++)
                for (int c = 0; c < 9; c++)
                    if (sug[r][c]) seats[r][c] = 1;
        }
    else if (in == 'd' || in == 'D') {
        //d�ﶵ
        char y;
        while (1) {
            printf("Continue? (y/n): ");
            scanf(" %c", &y);            
            if (y == 'y' || y == 'Y') {
                break;                    
            } 
            else if (y == 'n' || y == 'N') {
                printf("�P�¨ϥΡA�A���I\n");
                return 0;              
            } 
            else {
                printf("��J���~�A�п�J y �� n�C\n");
            }
        }
    }
        else {
            printf("�ﶵ���~�A�����N�䭫��...");
            getchar(); getchar();
        }
    }

    return 0;
}
//�����@�~�O�ثe��@���j�����@�~
//�ϥΨ�ܦh�j��P�P�_�禡
//�g�_�ӧx���פ�e���⦸���@�~�٭n�W�[����
//�����]�W���d�߻P�ݹL�ܦh��gpt�A�p�󧹦��x�s�W�����A�P�קK�л\�H�w�w����m
//���M�o�ع��Ǫ̨ӻ��O�j���M�סA�B�ܦ��D�ԩʡA�Ʊ�U�����n����bug�o��h
