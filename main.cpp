#define M 1500
#include<iostream>
#include"quicksort.h"

void print(int array[], int n);
int main()
{
	int a[M] = { 0 };
	for (int i = 0; i < M; i++){
		a[i] = 2*i - M;
	}

	permute(a, M);
	print(a, M);

	quicksort(a, 0,M - 1);
	print(a, M);
	system("pause");
	return 0;
}

void print(int array[], int n){
	for (int i = 0; i < n; i++){
		if (i % 10 == 0) std::cout <<std:: endl;
		std::cout << array[i]<<"   ";
	}
}
