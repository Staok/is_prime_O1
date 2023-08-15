#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* 请问您生成一个判断多少以内的质数的时间复杂度为O(1)的程序呢亲~最好是 100 的整数倍
    只要您的磁盘容得下呢~经验值，填入10w生成的文件约为 150KB */
#define HOW_MANY_DO_YOU_WANT 1000
#define ROOL_NUM 100 /* 这里用于指示产生程序中的数组一行多少个数字，一般不用动 */

unsigned char is_prime(unsigned long long num);

int main(void)
{
    char *message[2] = {" start! __________"," __________ end!"},quitkey;
    printf("\n%s\n",message[0]);

    /* 程序开始________________________________ */

    FILE* outfile = fopen("is_prime.c","w");
        if(!outfile) return -1;
    
    fputs(
        "#include <stdio.h>\n"
        "#include <stdlib.h>\n\n",
        outfile
    );

    fprintf(
        outfile,
        "#define MAX_NUM %llu\n\n",
        HOW_MANY_DO_YOU_WANT
    );

    fputs(
        "char is_prime_result[MAX_NUM] = \n"
        "{\n",
        outfile
    );

    unsigned long long roll = HOW_MANY_DO_YOU_WANT / ROOL_NUM;

    for(unsigned long long i = 0; i < roll; i++)
    {
        fputs("    ", outfile);
        for(unsigned long long j = 1; j <= ROOL_NUM; j++)
        {
            fprintf(outfile, "%d, ", is_prime(i * ROOL_NUM + j));
        }
        fputs("\n", outfile);
    }

    fputs(
        "};\n\n",
        outfile
    );

    fputs(
        "int main(void)\n"
        "{\n"
        "    unsigned long long num = 0;\n\n"
        "    printf(\"input a num(<= %llu):\", MAX_NUM);\n\n"
        "    scanf(\"\%llu\",&num);\n\n"
        "    if(num <= 1) num = 1;\n"
        "    if(MAX_NUM <= num) num = MAX_NUM;\n\n"
        "    printf(\"\%llu\", num); is_prime_result[num - 1] ? printf(\" is\") : printf(\" is not\"); printf(\" a prime\\n\");\n\n"
        "    system(\"pause\");\n\n"
        "    return 0;\n"
        "}\n\n\n"
        ,outfile);

    fclose(outfile);

    /* ________________________________程序结束 */
    printf("\n%s\n",message[1]);
    system("pause");
    return 0;
}

/* 判断质数 */
unsigned char is_prime(unsigned long long num)
{
    unsigned long long n;
    
    if(num == 1) return 0;

    n = (unsigned long long)sqrt((double)num);

    for(unsigned long long i = 2;i <= n;i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}


