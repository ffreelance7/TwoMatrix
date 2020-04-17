#include <iostream>
#include <algorithm> 
#include <ctime> 
#include "time.h"
#define MAX 256
#define BLOCKSIZE 32
using namespace std;
int main() {
	unsigned t0, t1;
	long long A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
	
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			A[i][j]=1;
		}
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			B[i][j]=1;
		}
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			C[i][j]=0;
		}
	}
	//multiplicación de matrices pór bloques

	clock_t startTime = clock();
	for (int bi = 0; bi < MAX; bi += BLOCKSIZE) {
		for (int bj = 0; bj < MAX; bj += BLOCKSIZE) {
			for (int bk = 0; bk < MAX; bk += BLOCKSIZE) {
				for (int i = bi; i < min(bi + BLOCKSIZE,MAX); i++) {
					for (int j = bj; j < min(bj + BLOCKSIZE, MAX); j++) {
						for (int k = bk; k < min(bk + BLOCKSIZE, MAX); k++) {
							C[i][j] += A[i][k] * B[k][j];
						}
					}
				}
			}
		}
	}
	clock_t endTime = clock();

	clock_t clockTicksTaken = endTime - startTime;
	double timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;
	cout << "time: " << timeInSeconds << endl;



	
	return 0;
}
