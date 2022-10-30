#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* 请问您生成一个判断多少以内的质数的时间复杂度为O(1)的程序呢亲~
    只要您的磁盘容得下呢~经验值，填入10w生成的文件约为10MB */
#define HOW_MANY_DO_YOU_WANT 1000

unsigned char is_prime(unsigned long long num);

int main(void)
{
    char *message[2] = {"__________start!__________","__________end!__________"},quitkey;
    printf("\n%s\n",message[0]);

    /* 程序开始________________________________ */

    FILE* outfile = fopen("is_prime.c","w");
        if(!outfile) return -1;
    
    fputs(
        "#include <stdio.h>\n"
        "#include <stdlib.h>\n\n\n"
        "int main(void)\n{\n"
        "    unsigned long long num = 0;\n"
        "    printf(\"input a num:\");\n"
        "    scanf(\"\%llu\",&num);\n"
        "    printf(\"\\n\");\n\n"
        ,outfile
    );

    fputs(
        "    do{\n\n"
        ,outfile
    );

    for(unsigned long long i = 1;i <= HOW_MANY_DO_YOU_WANT;i++)
    {
        fprintf(
            outfile,
            "    if(num == %llu)\n"
            "    {\n"
            ,i
        );

        if(is_prime(i))
        {
            fprintf(
                outfile,
                "        printf(\"%llu is a prime\\n\");\n"
                ,i
            );
        }else
        {
            fprintf(
                outfile,
                "        printf(\"%llu is not a prime\\n\");\n"
                ,i
            );
        }

        fputs(
            "        break;\n"
            ,outfile
        );

        fputs(
            "    }\n\n"
            ,outfile
        );
    }

    fputs(
        "    }while(0);\n\n"
        ,outfile
    );

    fputs("    system(\"pause\");\n\n",outfile);
    fputs("    return 0;\n\n",outfile);

    fputs("}\n\n\n",outfile);

    fclose(outfile);

    /* ________________________________程序结束 */
    printf("\n%s\n",message[1]);
    printf("Press 'q' key to exit.");
    // while('q' != quitkey){scanf("%c",&quitkey);}
    while('q' != getchar());
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


