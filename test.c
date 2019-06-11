#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdarg.h"
/*void my_printf(char *val, ...)
{
    int ch;
    va_list arg;
    va_start(arg, val);
    while (*val != '\0')
    {
        switch (*val)
        {
        case '%': //遇到%执行switch case语句
        {
            if (*(val + 1) == 'c') //输出字符
            {
                ch = va_arg(arg, char);
                putchar(ch);
                val++; //指针变量向下偏移一个单位
            }
            else if (*(val + 1) == 'd')
            {
                ch = va_arg(arg, char); //输出整形
                printd(ch);
                val++;
            }
            else if (*(val + 1) == 's') //输出字符串
            {
                char *p = va_arg(arg, char *);
                while (*p != '\0')
                {
                    putchar(*p);
                    p++;
                }
                val++; //指向头一变量的下一个字符
            }
            else
                putchar('%');
            break;
        }
        default:
        {
            putchar(*val);
            break;
        }
        }
        val++;
    }
    va_end(arg);
}*/

int fun(char *a)
{
	int b = 0;
	b  = sizeof(a);
	return b;
}

void main(void)
{
	int m =0;
	char str[]={1,2};
	m = fun(str);
	printf("the data local:%d\n",m);
}

