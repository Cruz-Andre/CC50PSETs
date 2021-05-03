/***************************************************************************
 * fifteen.c - Exercício 1
 *
 * Set de Problemas Semana 3
 * Curso CC50 Introdução à Ciência da Computação de Harvard
 *
 * Implements The Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 ****************************************************************************/
 
#define _XOPEN_SOURCE 500

#include <cc50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// constants
#define DIM_MIN 3
#define DIM_MAX 9


// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;


// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);


int
main(int argc, char *argv[])
{
    // greet user with instructions
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: %s d\n", argv[0]);
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %d x %d and %d x %d, inclusive.\n",
         DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // check for win
        if (won())
        {
            printf("Puzzle Solved! ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}


/*
 * Clears screen using ANSI escape sequences.
 */

void
clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}


/*
 * Greets player.
 */

void
greet(void)
{
    clear();
    printf("WELCOME TO THE GAME OF FIFTEEN\n");
    usleep(2000000);
}


/*
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

void
init(void)
{
    // Get total size of board
    int boardsize = d * d;
    // interate over entire board
    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
            // insert into board value of boardsize, then decrement counter
            board[row][col] = boardsize - 1;
            boardsize--;
        }
    }
    // Swap positions 2 and 1 for board with even number of spaces
    if (d == 4 || d == 6 || d == 8)
    {
        int temp = board[d - 1][d - 2];
        board[d - 1][d - 2] = board[d - 1][d - 3];
        board[d - 1][d - 3] = temp;
    }

}

/* 
 * Prints the board in its current state.
 */

void
draw(void)
{
    // Loop through board array
    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
           // Print line instead of zero
           if (board[row][col] == 0)
           {
               printf("|__|");
           }
           else
           {
               printf("|%02d|", board[row][col]);
           }
           printf(" ");
        }
        printf("\n");
    }
}


/* 
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */

bool
move(int tile)
{
    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
           if (board[row][col] == tile)
           {
                // Check nearby spaces
                // moving up (tile is within board, blank tile is above)
                if (row - 1 >= 0 && board[row - 1][col] == 0)
                {
                    board[row - 1][col] = tile;
                    board[row][col] = 0;
                }
                // moving down (tile is within board, blank tile is below)
                else if (row + 1 < d && board[row + 1][col] == 0)
                {
                    board[row + 1][col] = tile;
                    board[row][col] = 0;
                }
                // moving left (tile is within board, blank tile on left)
                else if (col - 1 >= 0 && board[row][col - 1] == 0)
                {
                    board[row][col - 1] = tile;
                    board[row][col] = 0;
                }
                // move right (tile is within board, blank tile on right)
                else if (col + 1 < d && board[row][col + 1] == 0)
                {
                    board[row][col + 1] = tile;
                    board[row][col] = 0;
                }
                // move is illegal
                else
                {
                    return false;
                }
                // return true after a valid/legal move
                return true;
            }
        }    
    }
    // return false if there is no such tile number
    return false;
}


/*
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */

bool
won(void)
{
    // check if every tile were sorted
    int count = 1;
    for (int i = 0; i < d; i++)
    {    
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == count)
            {        
                count ++;
                if (count == d * d)
                return true;
            }
            else
            return false;
        }
    }
    return false;
}
