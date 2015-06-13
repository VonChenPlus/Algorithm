#include<stdio.h>   
#include<string.h>   
char   str[1000001];
int   main()   {
    int   i, j, l;
    do{
        scanf("%s", str);
        if (strcmp(str, ".") == 0)   break;
        l = strlen(str);
        for (i = 1; i <= l; i++)
            if (l%i == 0)   {
                for (j = 0; j < l - i; j++)
                    if (str[j] != str[j + i])   {
                        i += j;
                        goto   next;
                    }
                printf("%d\n", l / i);
                break;
            next:;
            }
    } while (1);
    return   0;
}