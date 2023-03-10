#include <stdio.h>

int power(int base, int exponent)
{
    return (exponent == 0) ? 1 : base * power(base, exponent - 1);
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

int g_atoi(char *str)
{
    int i;
    i = 0;
    int a;
    int compteur = 0;
    int l = gd_len(str) - 1;
    int bo = 0;
    if (str[0] == 45)
    {
        i = 1;
        bo = 1;
    }
    else if (str[0] == 43)
    {
        i = 1;
    }

    while (str[i] != '\0')
    {
        a = (str[i] - 48) * power(10, l - i);

        i++;
        a = (bo == 0) ? a : -a;
        compteur += a;
    }
    printf("%d", compteur);
    return 0;
}

int main(void)
{
    int e = g_atoi("1015");
    printf("\n");
}
