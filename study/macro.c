/**
 * 功能:学习c语言预处理
 * 来源:网络
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIX 6
#define SEVEN 7
#define Cube(x) (x)*(x)*(x)
#define VERSION "tzs"
#define PASTE(n) "最终胜利者是："#n//paste string
#define NUM(a,b,c) a##b##c//paste token
#define STR(a,b,c) a##b##c
#define DEBUG 1

int main()
{
    int i;
    i = SIX + SEVEN;
    printf("i = %d\n",i);
    i = (SIX * SEVEN);
    printf("i = %d\n",i);

    i = Cube(3);
    printf("i = %d\n",i);

    printf("%s\n",VERSION);
    printf("%s\n",PASTE(中文不行吗));
    puts(PASTE(yy/));
    puts(PASTE(xx));

    printf("%d\n",NUM(1,2,3));
    //printf("%s\n",STR(aa,bb,cc));

    #if DEBUG
        printf("Debugging\n");
        printf("Debugging2222\n");
    #endif
        printf("Running\n");
    #if defined DEBUG
        printf("yes\n");
    #endif
    #if !defined JJ
        printf("no JJ\n");
    #endif

}
