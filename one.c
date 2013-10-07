#include <stdio.h>

#define R 4
#define C 5

float calculateAverage(float mat[R][C], int i, int j);
int valid(int i, int j);

int main(void){
	float mat[R][C] = {
			{3, 0, 9, 5, 2},
			{7, 3, 8, 4, 3},
			{1, 6, 5, 8, 1},
			{2, 3, 2, 4, 6}
		};

	float output_mat[R][C];

	int i, j;

	for (i = 0; i < R; ++i){
		for (j = 0; j < C; ++j){
			output_mat[i][j] = calculateAverage(mat, i, j);

			//printf("%f\n", average);

		}
		printf("\n");
	}

	for (i = 0; i < R; ++i){
		for (j = 0; j < C; ++j){
			printf("%6.2f\t", output_mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int valid(int i, int j){
	if(i < 0 || i >= R){
		return 0;
	}
	if(j<0 || j >= C){
		return 0;
	}

	return 1;
}

float calculateAverage(float mat[R][C], int i, int j){
	float total = 0.0;
	int elems = 0, same_element, x, y;


	for(x = i-1; x <= i+1; x++){
		if(x >= 0 && x < R){
			for(y = j-1; y <= j+1; y++){
				if(i == x && j == y){
					same_element = 1;
				}else{
					same_element = 0;
				}

				if(y >= 0 && y < C && same_element == 0){
						total += mat[x][y];
						++elems;
				}
			}
		}
	}

	//average = total/elems;
	return total/elems;
}