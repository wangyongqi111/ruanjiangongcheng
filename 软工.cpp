#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, max_num, operator_num, has_bracket, has_decimal, output_type;
    printf("请输入题目数量：");
    scanf("%d", &num);
    printf("请输入最大数：");
    scanf("%d", &max_num);
    printf("请选择运算符：\n1. 加\n2. 减\n3. 乘\n4. 除\n");
    scanf("%d", &operator_num);
    printf("是否有括号？（1为是，0为否）");
    scanf("%d", &has_bracket);
    printf("是否有小数？（1为是，0为否）");
    scanf("%d", &has_decimal);
    printf("请选择输出方式：\n1. 输出到文件\n2. 打印机\n");
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
            printf("文件打开失败！\n");
            return 0;
        }
        fprintf(fp, "题目数量：%d\n最大数：%d\n运算符：%d\n是否有括号：%d\n是否有小数：%d\n", num, max_num, operator_num, has_bracket, has_decimal);
        fclose(fp);
        printf("已将题目输出到exercise.txt文件中！\n");
    } else {
        printf("请连接打印机打印题目！\n");
    }

    return 0;
}
