#include <stdio.h>

#define R 4
#define C 5

int main(void){
	float mat[R][C] = {
			{3, 0, 9, 5, 2},
			{7, 3, 8, 4, 3},
			{1, 6, 5, 8, 1},
			{2, 3, 2, 4, 6}
		};

	float output_mat[R][C], average, total;

	int i, j, x, y, elems, same_element;

	for (i = 0; i < R; ++i){
		for (j = 0; j < C; ++j){
			average = 0.0;
			total = 0.0;
			elems = 0;

			x = i-1;
			while(x <= i+1){
				if(x >= 0 && x < R){
					y = j-1;
					while(y <= j+1){
						if(i == x && j == y){
							same_element = 1;
						}else{
							same_element = 0;
						}

						if(y >= 0 && y < C && same_element == 0){
								total += mat[x][y];
								++elems;
						}
						++y;
					}
				}
				++x;
			}

			average = total/elems;
			printf("%f\n", average);

		}
		printf("\n");
	}
	return 0;
}

/*int valid(int i, int j){

}

float average(float m[R][C], int r, int c){

}*/