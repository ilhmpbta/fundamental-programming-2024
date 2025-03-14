#include <stdio.h>
#define nrp5025241152 "Bintang Ilham Pabeta"
#define N 8 // Maze size

// Write a function that accepts an 8 by 8 array of characters that represents a maze.
// Each position can contain either an X or a blank. Starting at position (0,1), list any
// path through the maze to get to location (7,7). Only horizontal and vertical moves
// are allowed. If no path exists, write a message indicating there is no path.
// Moves can be made only to locations that contain a blank. If an X is
// encountered, that path is blocked and another must be chosen. Use recursion

int dx[] = {-1, 1, 0, 0}; int dy[] = {0, 0, -1, 1}; // array to simplify directions (down/up/left/right)

void maze_display(char maze[N][N]); // function to print maze
int path_finder(char maze[N][N], int x, int y, int path[N][N]); // path finding function

int main() {
    char maze[N][N] = {
        {' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X'},
        {'X', ' ', 'X', ' ', ' ', ' ', 'X', ' '},
        {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '},
        {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '},
        {'X', ' ', 'X', ' ', 'X', ' ', ' ', ' '},
        {'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X'},
        {'X', ' ', ' ', ' ', 'X', ' ', ' ', ' '},
        {'X', 'X', 'X', ' ', 'X', 'X', ' ', ' '}
    }; // initial 8x8 maze, if you want to change it via scanf, please uncomment the for loop below

    // Or if you want to create the maze from your own input, we'll replace blank spaces with P first (since we can't input blank spaces in scanf)
    // printf("Input maze terrains (P for path / X for walls)\n");
    // for (int i = 0; i < N; i++){
    //     for (int j = 0; j < N; j++){
    //     scanf(" %c", &maze[i][j]);
    //     if (maze[i][j] == 'P') maze[i][j] = ' '; // to replace with blank space
    //     }
    // }

    printf("Initialized maze:\n"); maze_display(maze);

    int path[N][N] = {0}; // for tracking current position

    // start search from (0,0)
    if (path_finder(maze, 0, 0, path)) {
        printf("\nPath found:\n"); // if maze is solvable
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (path[i][j] == 1) printf(" • "); // for each valid path, print •
                else printf(" ▢ "); // if not valid print =
            } printf("\n");
        }
    } else printf("No path found.\n"); // if it's impossible to reach (7,7) from (0,0)

    return 0;
}

void maze_display(char maze[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c  ", maze[i][j]);
        }
        printf("\n");
    }
}
int path_finder(char maze[N][N], int x, int y, int path[N][N]) {
    if (x == 7 && y == 7) {
        path[x][y] = 1; return 1; // Base case: recursion stops when we reach area (7,7)
    }

    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == ' ' && path[x][y] == 0) {
        path[x][y] = 1; // If the path is valid (not a wall or outside the map), continue
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i]; int newY = y + dy[i]; // test 4 directional movements
            if (path_finder(maze, newX, newY, path)) return 1; // if valid, recurse
        } path[x][y] = 0; // if not valid, set to 0
    }

    return 0; // No path found
}