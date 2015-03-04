void permute(int array[], int n){
	for (int i = n; i > 0; i--){
		std::swap(array[n - 1], array[rand() % i]);
	}
}


int partition2(int array[], int lhs, int rhs){
	int pivot = array[lhs];
	int mi = lhs;
	for (int i = lhs+1; i <= rhs; i++){
		if (array[i] < pivot) std::swap(array[++mi], array[i]);
	}
	std::swap(array[lhs], array[mi]);
	return mi;
}

void quicksort(int array[], int lhs, int rhs){
	if (rhs - lhs < 2) return;
	int mi = partition2(array, lhs, rhs);
	quicksort(array, lhs, mi);
	quicksort(array, mi + 1, rhs);
}
