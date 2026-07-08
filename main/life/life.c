#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	parse_args(int ac, char **av, int *wd, int *ht, int *it)
{
	if (ac != 4)
		return 0;
	*wd = atoi(av[1]); 
	*ht = atoi(av[2]); 
	*it = atoi(av[3]);

	if (*wd < 0 || *ht < 0 || *it < 0)
		return 0;

	return 1;
}

void	init_grid(int wd, int ht, int grid[2][ht + 2][wd + 2])
{
	int x;
	int y;
	int z;

	for(x = 0;x < 2; x++)
		for(y = 0; y < ht + 2; y++)
			for(z = 0; z < wd + 2; z++)
				grid[x][y][z] = 0;
}

void	draw_pen(int wd, int ht, int grid[ht + 2][wd + 2])
{
	int	x = 1, y = 1;
	int pen = 0;
	char c;

	while (read(0, &c, 1) > 0)
	{
		if (c == 'w' && y > 1)
			y--;
		else if (c == 's' && y < ht)
			y++;
		else if (c == 'a' && x > 1)
			x--;
		else if (c == 'd' && x < wd)
			x++;
		else if (c == 'x')
			pen = !pen;
		if (pen)
			grid[y][x] = 1;
	}
}

void	print_grid(int wd, int ht, int grid[ht + 2][wd + 2])
{
	int	x, y;

	for(x = 1; x <= ht; x++)
	{
		for(y = 1; y < wd; y++)
		{
			if (grid[x][y])
				putchar('0');
			else
				putchar(' ');
		}
		putchar('\n');
	}

}



int	parse_arg1(int ac, char **av, int *wd, int *th, int* it)
{
	if (ac != 4)
		return 1;
		
	*wd = atoi(av[1]);
	*th = atoi(av[2]);
	*it = atoi(av[3]);
		
	if (*wd < 0 || *th < 0 || *it < 0)
		return 1;

	return 0;
}
	
void	init_grid1(int	wd, int th, int grid[2][th + 2][wd + 2])
{
		int x, y, z;

		printf("first grid[0]\n"); //
	
		for (x = 0; x < 2; x++){
			for (y = 0; y < th; y++)
			{
				for (z = 0; z < wd; z++){
					grid[x][y][z] = 0;
					printf("%d ", grid[x][y][z]); //
				}
				printf("\n"); //
			}
			if (x < 1) //
				printf("second grid[1]\n"); //
		}
}

void	draw_pen1(int wd, int th, int grid[th + 2][wd + 2])
{
	int x = 1, y = 1;
	int pen = 0;
	char c;

	while (read(0, &c, 1) > 0)
	{
		if (c == 'w' && y > 1)
			y--;
		else if (c == 's' && y < th)
			y++;
		else if (c == 'a' && x > 1)
			x--;
		else if (c == 'd' && x < wd)
			x++;
		else if (c == 'x')
			pen = !pen;

		if (pen)
			grid[y][x] = 1; 
	}
}

int		count_neighbour1(int wd, int th, int curr[th + 2][wd + 2], int a, int b)
{
	(void)wd;
	(void)th;

	int n = 0;
	int dy, dx;

	for (dy = -1; dy <= 1; dy++)
		for (dx = -1; dx <= 1; dx++)
			if (dx != 0 || dy != 0)
				n += curr[a + dy][b + dx];

	return n;
}

void	step1(int wd, int th, int curr[th + 2][wd + 2], int next[th + 2][wd + 2])
{
	int a, b, n;

	for (a = 1; a <= th; a++){
		for (b = 1; b <= wd; b++){
			n = count_neighbour1(wd, th, curr, a, b);
			if (curr[a][b] == 1)
				next[a][b] = (n == 2 || n == 3);
			else
				next[a][b] = (n == 3);
		}
	}
	
}

void	print_grid1(int wd, int th, int grid[th + 2][wd + 2])
{
	int x, y;

	for (x = 1; x <= th; x++){
		for (y = 1; y <= wd; y++){
			if (grid[x][y])
				putchar('0');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}

void dump_grid(const char *label, int wd, int ht, int grid[2][ht + 2][wd + 2])
{
    int layer, y, x;

    printf("\n=== %s ===\n", label);
    for (layer = 0; layer < 2; layer++)
    {
        printf("layer %d\n", layer);
        for (y = 0; y < ht + 2; y++)
        {
            for (x = 0; x < wd + 2; x++)
                printf("%d ", grid[layer][y][x]);
            printf("\n");
        }
    }
}

int	main(int ac, char **av)
{
	int width;
	int heigth;
	int iteration;

	// printf("start_of_programme\n"); //
	if (parse_arg1(ac, av, &width, &heigth, &iteration))
		return 1;

	// printf("Args Checked\n"); //
	// printf("width = [%d] | heigth = [%d] || iteration = [%d]\n", width, heigth, iteration); //

	
	int grid[2][heigth + 2][width + 2];
	init_grid1(width, heigth, grid);

	// printf("grid created &[%p]\n", grid); //
	// dump_grid("after init", width, heigth, grid); //

	
	draw_pen1(width, heigth, grid[0]);



	for (int it = 0; it < iteration; it++)
	{
		int curr = it % 2;
		int next = (it + 1) % 2;

		step1(width, heigth, grid[curr], grid[next]);
	}
	print_grid1(width, heigth, grid[iteration % 2]);

	return 0;
}