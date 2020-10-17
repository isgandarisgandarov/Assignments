#include <stdio.h>
#include<stdbool.h>

int solveMaze(char **maze, const int HT, const int WD, int x, int y); // draws a path and marks wrong paths to the exit on the maze string
void printMaze(char **maze, const int HT, const int WD); // prints the maze

int main(){
    char mazeStr[] =
			"  ##############"
		    "#     #     ####"
		    "# ####* ### ####"
		    "#    ###### ####"
		    "#### # #### ####"
		    "#    # #### ####"
		    "#### # #### ####"
		    "####        ####"
		    "################";
    const int HT = 9;
    const int WD = 16;
    char *maze[HT];

    for (int i=0; i<HT ; i++)	// filling the 2D char array
	maze[i]=&mazeStr[i*WD];

    solveMaze(maze, HT, WD, 0, 0);
    printMaze(maze, HT, WD);

    return 0;
}

int solveMaze(char **maze, const int HT, const int WD, int x, int y){
    if(x < 0 || x >= WD || y < 0 || y >= HT) return 0; // checks the borders of the maze
	if(maze[y][x] == '*') return 1; // checks if the goal destination is reached
	if(maze[y][x] == '#' || maze[y][x] == '.') return 0; // checks if the point is blocked or visited before

	maze[y][x] = '.'; // marks visited point

    if(solveMaze(maze, HT, WD, x, y - 1) == 1) return 1; // checks the north direction
    if(solveMaze(maze, HT, WD, x + 1, y) == 1) return 1; // checks the east direction
    if(solveMaze(maze, HT, WD, x, y + 1) == 1) return 1; // checks the south direction
    if(solveMaze(maze, HT, WD, x - 1, y) == 1) return 1; // checks the west direction
	maze[y][x] = ' '; // unmarks visited point if it is not correct
	return 0;
}

void printMaze(char **maze, const int HT, const int WD){
    for (int i=0; i<HT ; i++){
	for(int j=0; j<WD-1; j++)
	  printf("%c",maze[i][j]);
	printf("%c\n",maze[i][WD-1]);
    }
}
