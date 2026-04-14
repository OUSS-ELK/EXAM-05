#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int ac , char **av){
    if(ac == 1)
        return 1;
    int widith = atoi(av[1]);
    int hieght = atoi(av[2]);
    int iterations = atoi(av[3]);
    if(widith <= 0 || hieght <= 0 || iterations < 0)
        return 1;
    int grid[2][hieght +2][widith +2];
    for(int i = 0; i < 2 ;i++)
    {
        for(int h =0 ; h < hieght +2 ;h++)
        {
            for(int w = 0; w <widith +2 ; w++)
            {
                grid[i][h][w] = 0;
            }
        }
    }
    int x = 1 , y = 1 , pen = 0;
    char cmd;
    while (read(0 , &cmd ,1) > 0)
    {
        if(cmd == 'x')
            pen = !pen;
        if(cmd == 'w' && x > 1)
            x--;
        else if(cmd == 'a' && y > 1)
            y--;
        else if (cmd == 's' && x < hieght)
            x++;
        else if(cmd =='d' && y < widith)
            y++;
        if(pen)
            grid[0][x][y] = 1;
    }

    for(int i = 0; i < iterations ; i++)
    {
        for(int h = 1; h < hieght +1 ; h++)
            for(int w = 1 ;  w <widith +1 ;w++)
            {    int nb =0;
                for(int x = -1 ; x <= 1 ; x++){
                    for(int y =-1 ; y <= 1; y++)
                    {
                        if(x != 0 || y != 0)
                            nb+=grid[i %2][h +x][y +w];
                    }
                }
                if(((nb == 2 || nb == 3) && grid[i %2][h][w]) || nb ==3 )
                    grid[(i +1) %2][h][w] = 1;
                else
                    grid[(i +1) %2][h][w] = 0;;

            }
    }
     for(int h = 1; h < hieght +1 ; h++){
            for(int w = 1 ;  w <widith +1 ;w++){
                putchar(grid[iterations %2][h][w] ? 'O' :' ');
            }
        putchar('\n');
     }   
}