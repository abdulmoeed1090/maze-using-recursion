#include <iostream>
#include <string>
using namespace std;

// gloabally created rows and columns
const int ROWS = 5;
const int COLS = 7;

// Function to handle movement
void move(string maze[], char direction, int &playerX, int &playerY)
{
    // newdirection updates if move is valid
    int newdirX = playerX;
    int newdirY = playerY;

    if (direction == 'w') // Move up
        newdirX--;
    else if (direction == 's') // Move down
        newdirX++;
    else if (direction == 'a') // Move left
        newdirY--;
    else if (direction == 'd') // Move right
        newdirY++;

    // Check if the new position is within bounds and not a wall
    if (newdirX >= 0 && newdirX < ROWS && newdirY >= 0 && newdirY < COLS && maze[newdirX][newdirY] != '#')
    {
        // Clear previous position
        maze[playerX][playerY] = ' ';


        // Update player position
        playerX = newdirX;
        playerY = newdirY;


        // move p to this position
        maze[playerX][playerY] = 'P';

        // Check if the player reached the exit
        if (maze[playerX][playerY] == maze[1][5])
        {
            cout << "YOU WON!!!\n";
            return;
        }
    }
    else
    {
        cout << "Wall Spotted !!!\n";
    }

    // Display the maze after the move
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }
    cout << "     \n";
    cout << "Enter the direction (w,a,s,d): ";
    cin >> direction;
    move(maze, direction, playerX, playerY);
}

int main()
{
    // input variable
    char direction;
    // default position of player(p)
    int playerX = 1;
    int playerY = 1;
    // hardcoded a maze
    string maze[ROWS] = {
        "#######",
        "#P# #E#",
        "# # # #",
        "#     #",
        "#######"};

    // Print the maze initially
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }

    cout << "Enter the direction (w,a,s,d): ";
    cin >> direction;

    // Move the player based on input
    move(maze, direction, playerX, playerY);

    return 0;
}
