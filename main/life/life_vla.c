#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int parse_args(int ac, char **av, int *width, int *height, int *iterations)
{
    if (ac != 4)
        return (1);
    *width = atoi(av[1]);
    *height = atoi(av[2]);
    *iterations = atoi(av[3]);
    if (*width < 0 || *height < 0 || *iterations < 0)
        return (1);
    return (0);
}

void init_grid(int height, int width, int grid[2][height + 2][width + 2])
{
    int b;
    int i;
    int j;

    for (b = 0; b < 2; b++)
        for (i = 0; i < height + 2; i++)
            for (j = 0; j < width + 2; j++)
                grid[b][i][j] = 0;
}

void draw_pen(int height, int width, int grid[height + 2][width + 2])
{
    int  x = 1, y = 1;
    int  pen = 0;
    char c;

    while (read(0, &c, 1) > 0)
    {
        if (c == 'w' && y > 1)
            y--;
        else if (c == 's' && y < height)
            y++;
        else if (c == 'a' && x > 1)
            x--;
        else if (c == 'd' && x < width)
            x++;
        else if (c == 'x')
            pen = !pen;
        if (pen)
            grid[y][x] = 1;
    }
}

int count_neighbors(int height, int width, int grid[height + 2][width + 2], int i, int j)
{
    int n;
    int dy;
    int dx;

    (void)height;
    (void)width;
    n = 0;
    for (dy = -1; dy <= 1; dy++)
        for (dx = -1; dx <= 1; dx++)
            if (dx != 0 || dy != 0)
                n += grid[i + dy][j + dx];
    return (n);
}

void step(int height, int width, int cur[height + 2][width + 2],
          int next[height + 2][width + 2])
{
    int i;
    int j;
    int n;

    for (i = 1; i <= height; i++)
    {
        for (j = 1; j <= width; j++)
        {
            n = count_neighbors(height, width, cur, i, j);
            if (cur[i][j] == 1)
                next[i][j] = (n == 2 || n == 3);
            else
                next[i][j] = (n == 3);
        }
    }
}

void print_grid(int height, int width, int grid[height + 2][width + 2])
{
    int i;
    int j;

    for (i = 1; i <= height; i++)
    {
        for (j = 1; j <= width; j++)
        {
            if (grid[i][j])
                putchar('O');
            else
                putchar(' ');
        }
        putchar('\n');
    }
}

int main(int ac, char **av)
{
    int width;
    int height;
    int iterations;

    if (parse_args(ac, av, &width, &height, &iterations))
        return (1);

    int grid[2][height + 2][width + 2];
    int it;

    init_grid(height, width, grid);
    draw_pen(height, width, grid[0]);

    for (it = 0; it < iterations; it++)
    {
        int cur = it % 2;
        int next = (it + 1) % 2;
        step(height, width, grid[cur], grid[next]);
    }

    print_grid(height, width, grid[iterations % 2]);
    return (0);
}
