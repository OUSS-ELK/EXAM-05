#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main (int ac, char **av)
{
	if (ac != 4)
		return 1;

	int width = atoi(av[1]);
	int heigth = atoi(av[2]);
	int iteration = atoi(av[3]);

	int map[2][heigth + 2][width + 2];
	
	// initialize the maps to 0 including borders
	for (int i = 0; i < 2; i++)
		for(int h = 0; h < heigth + 2; h++)
			for (int w = 0; w < width + 2; w++)
				map[i][h][w] = 0;
	
	// set alive cells in map[0] to 1
	int x = 1, y = 1, pen = 0;
	char c;

	while (read(0, &c, 1) > 0)
	{
		if (c == 'w' && y > 1)
			y--;
		else if (c == 's' && y < heigth)
			y++;
		else if (c == 'a' && x > 1)
			x--;
		else if (c == 'd' && x < width)
			x++;
		else if (c == 'x')
			pen = !pen;
		if (pen)
			map[0][y][x] = 1;
	}

	// simulation of game
	int curr = iteration % 2;
	int next = (iteration + 1) % 2;

	for (int it = 0; it < iteration; it++){
		for (int h = 1; h <= heigth; h++){
			for (int w = 1; w <= width; w++){
				int nb = 0;
				for (int x = -1; x <= 1; x++)
				{
					for (int y = -1; y <= 1; y++){
						if (x != 0 || y != 0)
							nb += map[curr][h + x][w + y];
					}
				}
				
			}
		}
	}
	

	// print map without borders
	for (int y = 1; y <= heigth; y++)
	{
		for (int x = 1; x <= width; x++)
		{
			if (map[iteration % 2][y][x])
				putchar('0');
			else
				putchar(' ');
		}
		putchar('\n');
	}
	
	return 0;
}