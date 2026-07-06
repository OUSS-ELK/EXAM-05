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

void	init_grid1(int wd, int ht, int it, int grid[ht + 2][wd + 2]){

	int x, y, z;

	for (x = 0; x < it; x++)
		for (y = 0; y < ht + 2)

}

int parse_arg1(int ac, char **av, int* wd, int* ht, int* it){

	if (ac != 4)
		return 0;

	*wd = av[1];
	*ht = av[2];
	*it = av[3];

	if (wd < 0 || ht < 0 || it < 0)
		return 0;

	return 1;
}

int	main(int ac, char **av)
{
	int		width;
	int		heigth;
	int		iteration;

	
	if (parse_args(ac, av, &width, &heigth, &iteration))
		return 1;
	
	int		grid[2][heigth + 2][width + 2];
	
	init_grid(width, heigth, grid);
	draw_pen(width, heigth, grid[0]);

	for(int it = 0; it < iteration; it++)
	{
		int	curr = it % 2;
		int next = (it + 1) % 2;
		step(heigth, width, grid[curr], grid[next]);
	}
	print_grid(heigth, width, grid[iteration % 2]);
}