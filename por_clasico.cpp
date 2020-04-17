#include <iostream>
#include <algorithm> 
#include <ctime> 
#include "time.h"
#define MAX 512
#define BLOCKSIZE 16
using namespace std;
int main() {
	unsigned t0, t1;
	long long A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
		
for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			A[i][j]=j;
		}
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			B[i][j]=i;
		}
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			C[i][j] = 0;
		}
	}

	//multiplicación de matrices clásica
	clock_t startTime = clock();
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			C[i][j] = 0;
			for (int k = 0; k < MAX; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	clock_t endTime = clock();

	clock_t clockTicksTaken = endTime - startTime;
	double timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;
	cout << "time: " << timeInSeconds << endl;


}
