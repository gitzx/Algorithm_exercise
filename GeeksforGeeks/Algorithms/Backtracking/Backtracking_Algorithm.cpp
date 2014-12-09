/*
Backtracking Programming 
	1) 

Typic topic
	(1)Print all permutations of a given string
	(2)N Queen Problem
	(3)The Knight's tour problem
	(4)Rat in a Maze
	(5)Subset Sum
	


*/


/*======================Print all permutations of a given string======================*/
/*Write a C program to print all permutations of a given string*/

#include <stdio.h>

void swap(char *x, char *y){
	char tmp;
	tmp=*x;
	*x=*y;
	*y=tmp;
}

void permute(char *a, int low, int high)
{
	int i;
	if(low == high)
	{
		printf("%s\n", a);
	}else{
		for(i=low;i<=high;i++){
			swap((a+low), (a+i));
			permute(a, low+1, high);
			swap((a+low),(a+i));
		}
	}
}

int main()
{
   char a[] = "ABC";  
   permute(a, 0, 2);
   getchar();
   return 0;
}


/*======================N Queen Problem======================*/
/*The N Queen is the problem of placing N chess queens on an N×N 
chessboard so that no two queens attack each other. */

#include <stdio.h>
#define N 4

void printSolution(int board[N][N])
{
	for(int i=0;i<N;i++){
		printf("%d ", board[N][N]);
		printf("\n");
	}
}

bool isSafe(int board[N][N], int row, int col)
{
	int i, j;
	//判断该行左边是否安全
	for(i=0; i<col; i++){
		if(board[row][i]){
			return false;
		}
	}
	//判断左边的对角线上是否安全
	for(i=row,j=col; i>=0&&j>=0;i--,j--){
		if(board[i][j]){
			return false;
		}
	}
	//判断左边的斜对角线是否安全
	for(i=row,j=col; i<N&&j>=0; i++,j--){
		if(board[i][j]){
			return false;
		}
	}
	return true;
}

bool solveNQUtil(int board[N][N], int col)
{
	if(col>=N){
		return true;
	}
	for(int i=0;i<N;i++){
		if(isSafe(board, i, col)){
			board[i][col]=1;
			if(solveNQUtil(board, col+1)==true){
				return true;
			}
			board[i][col]=0; //backtrack
		}
	}
	return false;
}

bool solveNQ()
{
    int board[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
 
    if ( solveNQUtil(board, 0) == false )
    {
      printf("Solution does not exist");
      return false;
    }
 
    printSolution(board);
    return true;
}

int main()
{
    solveNQ();
 
    getchar();
    return 0;
}


/*======================The Knight’s tour problem======================*/
/*A knight's tour is a sequence of moves of a knight on a chessboard such 
that the knight visits every square only once.*/

#include <stdio.h>
#define N 8

int isSafe(int x, int y, int sol[N][N])
{
	if( x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1)
	{
		return 1;
	}	
	return 0;
}

void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++){
        	printf(" %2d ", sol[x][y]);
        }          
        printf("\n");
    }
}

bool solveKT(){
	int sol[N][N];
	for(int x=0;x<N;x++){
		for(int y=0;y<N;y++){
			sol[x][y]=1;
		}
	}
	int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    sol[0][0]  = 0;
    if(solveKTUtil(0, 0, 1, sol, xMove, yMove) == false)
    {
        printf("Solution does not exist");
        return false;
    }else{
    	printSolution(sol);
 	}
    return true;
}

int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[N],
                int yMove[N])
{
   int k, next_x, next_y;
   if (movei == N*N){
   		return true;
   	}
   for (k = 0; k < 8; k++)
   {
       next_x = x + xMove[k];
       next_y = y + yMove[k];
       if (isSafe(next_x, next_y, sol))
       {
	        sol[next_x][next_y] = movei;
	        if (solveKTUtil(next_x, next_y, movei+1, sol, xMove, yMove) == true){
	        	return true;
	        }else{
	            sol[next_x][next_y] = -1;   // backtracking   	
	        }
       }
   }
   return false;
}
 
int main()
{
    solveKT();
    getchar();
    return 0;
}

/*
Output:
  0  59  38  33  30  17   8  63
 37  34  31  60   9  62  29  16
 58   1  36  39  32  27  18   7
 35  48  41  26  61  10  15  28
 42  57   2  49  40  23   6  19
 47  50  45  54  25  20  11  14
 56  43  52   3  22  13  24   5
 51  46  55  44  53   4  21  12
 */


 /*======================Rat in a Maze======================*/
 /*A Maze is given as N*N binary matrix of blocks where source 
 block is the upper left most block, A rat starts from source 
 and has to reach destination.*/

#include <stdio.h>
#define N 4 
 
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}
 
bool isSafe(int maze[N][N], int x, int y)
{
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1){
    	return true;
 	}
    return false;
}
 
bool solveMaze(int maze[N][N])
{
    int sol[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    if(solveMazeUtil(maze, 0, 0, sol) == false)
    {
        printf("Solution doesn't exist");
        return false;
    }
    printSolution(sol);
    return true;
}
 
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    if(x == N-1 && y == N-1)
    {
        sol[x][y] = 1;
        return true;
    }
    if(isSafe(maze, x, y) == true)
    {
        sol[x][y] = 1;
        if (solveMazeUtil(maze, x+1, y, sol) == true){
        	return true;
        }  
        if (solveMazeUtil(maze, x, y+1, sol) == true){
        	return true;
        }            
        sol[x][y] = 0;
        return false;
    }   
    return false;
}
 
int main()
{
    int maze[N][N]  =  { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    solveMaze(maze);
    getchar();
    return 0;
}