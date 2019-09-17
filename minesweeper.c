#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//By Emily

typedef struct {
	int row;
	int col;
} coordinate ;

void shuffle( int n, coordinate choice[]) {
	coordinate temp;
	int index;
	srand( (unsigned) time(NULL)); // initialize the random number generator
	for (int i=0; i < n*n; ++i){
		index = rand() % (n*n);
		temp = choice[i];
		choice[i] = choice[index];
		choice[index] = temp;
		}
}

void place( int mines, int n, coordinate choice[],  int matrix[][n]) {
	int i;
	for ( i = 0; i < mines; ++i)
		matrix[ choice[i].row][choice[i].col] = -1;

}

int grid ( const int n, const int matrix[][n], const int r, const int c) {
	int i, j, count = 0;
	for (i = -1; i < 2; ++i)
		for (j = -1; j < 2; ++j)
			if ( (i+r) > -1 && (i+r) < n && (j+c) > -1 && (j+c) < n )
				if ( i != 0 || j != 0 )
					if (matrix[i+r][j+c] == -1 )
						count++;
	return count;
}

void countMines( int n, int matrix[][n]) {
	int r, c;
	for (r = 0; r < n; ++r)
		for (c = 0; c < n; ++c )
			if ( matrix[r][c] != -1 )
				matrix[r][c] = grid(n, matrix, r, c);
}

void printMatrix(int nRows, const int matrix[][nRows]) {
	for (int r=0; r < nRows; ++r){
		for (int c=0; c < nRows; ++c )
			initialise (board, matrix);
			printf("%4+d", matrix[r][c]);
		putchar('\n');
		}
}

void initialize( int n, int mines, int matrix[][n] ) {
	int r, c, index;
	coordinate choice[n*n];

	index = 0;
	for (r = 0; r < n; ++r )
		for (c = 0; c < n; ++c ){
			choice[index].row = r;
			choice[index].col = c;
			matrix[r][c] = 0;
			index++;
		}
	shuffle( n, choice);
	place(mines, n, choice, matrix);
	countMines(n, matrix);
}
void cover(char board[n][n], char matrix[n][n]){
  for (int r=0; i< row; r++)
  {
      for (int c=0; j< col; c++)
      {
				matrix[r][c] = board[r][c] = '-';
      }
  }
  return;
}

void markMine(char board[r][c]){
	board[r][c]= '#';
}
void choice(){
	printf("What would you like to mess with(row, coloum)?" );
	scanf("%d %d", &r, %c);
	printf("Would you like to mark this as a mine?(y/n)")
	scanf("%d", &a) //a for answer
	if(a =n ){
		int location = (r,w);
		if (location = 0) {
			printf(matrix[r][c])
			printf(board[r+1][c+1])
			//if neigbor spot is 0 then do process again till there is all neigbors are none 0 numbers
		} else if (location = -1) {
			//show spot as mines
			gameOver = true;
		} else{
			//if number is anything else
			//only reveal that spot
		}
	}else{
		markMine(board[r][c]);
	}

}

void playGame(){
	bool gameOver = false;
	if(gameOver =false) {
		choice();
			printMatrix(n, matrix);

	}else{
		printMatrix(n, matrix);
		print("Game Over a mine has been found")
	}
}

int main() {
	int n, mines;
	printf("Size of square matrix?");
	scanf("%d", &n);
	printf("How many mines should be placed?");
	scanf("%d", &mines);
	int matrix[n][n];
	initialize(n, mines, matrix);
	printMatrix(n, matrix);
	char board[n][n], matrix[n]n]; //matrix is the board with the numbers, board is the board they see
	playGame();
}
