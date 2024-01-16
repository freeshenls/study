#include<stdlib.h>
#include<stdio.h>

void visitIsland(char** grid, int i, int j, int gridSize, int* gridColSize){
        if (i == -1 || j==-1 || i==gridSize || j == *gridColSize)
        {
                return;
        }

        if (grid[i][j] == '1')
        {
                grid[i][j] = '2';
                // 上
                visitIsland(grid, i-1, j, gridSize, gridColSize);
                // 下
                visitIsland(grid, i+1, j, gridSize, gridColSize);
                // 左
                visitIsland(grid, i, j-1, gridSize, gridColSize);
                // 右
                visitIsland(grid, i, j+1, gridSize, gridColSize);
        }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
        int nums = 0;
        int i = 0;
        for (; i < gridSize; ++i)
        {
                int j = 0;
                for (; j < *gridColSize; ++j)
                {
                        if (grid[i][j] == '1')
                        {
                                visitIsland(grid, i, j, gridSize, gridColSize);
                                nums++;
                        }
                        // printf("%c", grid[i][j]);
                }
                // printf("\n");
        }
        return nums;
}

int main(int argc, char const *argv[])
{
        char temp[][5] = { "11110", "11010", "11000", "00000"};
        // char temp[][5] = { "11000", "11000", "00100", "00011"};
        char *grid[4];
        grid[0] = temp[0];
        grid[1] = temp[1];
        grid[2] = temp[2];
        grid[3] = temp[3];

        int* returnSize = (int*)malloc(sizeof(int));
        *returnSize = 5;

        int nums = numIslands(grid, 4, returnSize);
        printf("%d\n", nums);
        free(returnSize);
        return 0;
}
