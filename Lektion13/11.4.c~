#include <stdio.h>
#include <stdlib.h>

#define SENTINEL -1
#define MAX_X     5
#define MAX_Y     5

void copy_grid(int grid[MAX_X][MAX_Y], int copy_of_grid[MAX_X][MAX_Y]);
int blob_count(int copy_of_grid[MAX_X][MAX_Y], int x, int y, int count);

int main(void){
  int grid[5][5] = {
                     {1, 1, 0, 0, 0},
                     {0, 1, 1, 0, 0},
                     {0, 0, 1, 0, 1},
                     {1, 0, 0, 0, 1},
                     {0, 1, 0, 1, 1},
                    },
      copy_of_grid[5][5] = {
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                    },
      x = 0, y = 0,
      scanres = 0;
  
  copy_grid(grid, copy_of_grid);

  do {
    printf("Input two coordinates (x,y): ");
    scanres = scanf(" %d %d", &x, &y);
    if (scanres == 2 && x >= 0 && x <= 4 && y >= 0 && y <= 4) {
      printf("Start Coordinates, (x,y) = (%d,%d)\n"
             "Number of blobs connected = %d\n", x, 
                                                 y, 
                                                 blob_count(copy_of_grid, x, y, 0)
                                                 );
    }
  } while (x != SENTINEL);

  return 0;
}

void copy_grid(int grid[MAX_X][MAX_Y], int copy_of_grid[MAX_X][MAX_Y]){
  int x, y;

  for(x = 0; x < MAX_X; ++x){
    for(y = 0; y < MAX_Y; ++y){
      copy_of_grid[x][y] = grid[x][y];
    }
  }
}

int blob_count(int copy_of_grid[MAX_X][MAX_Y], int x, int y, int count){
  int i, j;

  if (copy_of_grid[x][y] == 1){
    copy_of_grid[x][y] = 0;
    ++count; 
  }

  for(i = x-1; i < x+1; ++i){
    for(j = y-1; j < y+1; ++j){
      if (copy_of_grid[i][j] == 1){
        copy_of_grid[i][j] = 0;
        ++count;
        blob_count(copy_of_grid, i, j, count);
      }     
    }
    
  }
}

