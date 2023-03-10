#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void gd_putchar(char c)
{
    write(1, &c, 1);
}

int gd_len(char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

int gd_putstr(char *str)
{
    int i = gd_len(str);
    write(1, str, i);
    return (i);
}

int main(void)
{
    gd_putstr("Hello\0");
    printf("\n");
}
