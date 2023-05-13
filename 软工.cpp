#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, max_num, operator_num, has_bracket, has_decimal, output_type;
    printf("��������Ŀ������");
    scanf("%d", &num);
    printf("�������������");
    scanf("%d", &max_num);
    printf("��ѡ���������\n1. ��\n2. ��\n3. ��\n4. ��\n");
    scanf("%d", &operator_num);
    printf("�Ƿ������ţ���1Ϊ�ǣ�0Ϊ��");
    scanf("%d", &has_bracket);
    printf("�Ƿ���С������1Ϊ�ǣ�0Ϊ��");
    scanf("%d", &has_decimal);
    printf("��ѡ�������ʽ��\n1. ������ļ�\n2. ��ӡ��\n");
    scanf("%d", &output_type);

    srand((unsigned)time(NULL));
    int i;
    for (i = 1; i <= num; i++) {
        int a, b, c, d;
        a = rand() % max_num + 1;
        b = rand() % max_num + 1;
        c = rand() % max_num + 1;
        d = rand() % max_num + 1;
        char operator1, operator2;
        switch (operator_num) {
            case 1:
                operator1 = '+';
                operator2 = '+';
                break;
            case 2:
                operator1 = '-';
                operator2 = '-';
                break;
            case 3:
                operator1 = '*';
                operator2 = '*';
                break;
            case 4:
                operator1 = '/';
                operator2 = '/';
                while (c == 0 || d == 0 || a % c != 0 || b % d != 0) {
                    c = rand() % max_num + 1;
                    d = rand() % max_num + 1;
                }
                break;
        }
        int result;
        if (has_bracket) {
            int bracket = rand() % 2;
            if (bracket == 0) {
                result = (a + b) * c + d;
                printf("(%d %c %d) %c %d = %d\n", a, operator1, b, operator2, c, result);
            } else {
                result = a + (b - c) * d;
                printf("%d %c (%d %c %d) = %d\n", a, operator1, b, operator2, c, result);
            }
        } else {
            result = a + b;
            printf("%d %c %d = %d\n", a, operator1, b, result);
        }
        if (has_decimal) {
            float decimal = (float)rand() / RAND_MAX;
            printf("%.2f\n", decimal);
        }
    }

    if (output_type == 1) {
        FILE *fp = fopen("exercise.txt", "w");
        if (fp == NULL) {
            printf("�ļ���ʧ�ܣ�\n");
            return 0;
        }
        fprintf(fp, "��Ŀ������%d\n�������%d\n�������%d\n�Ƿ������ţ�%d\n�Ƿ���С����%d\n", num, max_num, operator_num, has_bracket, has_decimal);
        fclose(fp);
        printf("�ѽ���Ŀ�����exercise.txt�ļ��У�\n");
    } else {
        printf("�����Ӵ�ӡ����ӡ��Ŀ��\n");
    }

    return 0;
}
