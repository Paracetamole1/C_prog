#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    char buf[90];
    int i;
    i = 0;

    int **board;
    if (argc < 2)
    {
        printf("pas assez d'arguments\n");
        return 0;
    }

    int fd;
    fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int size = read(fd, buf, 89);
    board = (int **)malloc(sizeof(int *) * (9));

    while (i < 9)
    {
        board[i] = (int *)malloc(sizeof(int) * (9));
        i++;
    }
    buf[size] = '\0';
    printf("%s\n", buf);
    close(fd);
    i = 0;
    int j = 0;
    int x = 0;
    int y = 0;

    while (buf[j] != '\0')
    {
        board[x][y] = buf[j] - 48;
        if (buf[j] == '\n')
        {
            y = 0;
            x++;
            j++;
        }
        else
        {
            y++;
            j++;
        }
    }
    x = 0;
    y = 0;
    printf("%c ----------------------------------------- \n", '\n');

    while (y < 9)
    {
        while (x < 9)
        {
            if ((x) % 3 == 0)
            {
                printf(" |  %i ", board[y][x]);
            }
            else
            {
                printf("  %i ", board[y][x]);
            }
            x++;
        }
        y++;
        x = 0;
        if (y % 3 == 0)
        {
            printf("%c ----------------------------------------- \n", '\n');
        }
        else
        {
            printf("%c \n", '\n');
        }
    }

    while (i < 9)
    {
        free(board[i]);
        i++;
    }
    free(board);
}
