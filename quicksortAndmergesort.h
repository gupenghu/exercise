#define T_max (~(1<<31))
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



void merge(int s[], int p, int t, int q){

	int l = t - p + 1;
	int r = q - t;
	int *a = new int[l + 1];
	int *b = new int[r + 1];
	int *c = s + p;
	for (int i = 0; i < l; i++){
		a[i] = s[p + i];
	}
	for (int i = 0; i < r; i++){
		b[i] = s[t + i + 1];
	}
	a[l] = T_max;
	b[r] = T_max;
	int k = 0, m = 0, n = 0;
	while (k != l + r){
		if (a[m] <= b[n]) { c[k] = a[m]; k++; m++; }
		else{ c[k] = b[n]; k++; n++; }
	}
	delete[] a;
	delete[] b;
}

void mergesort(int s[], int p, int q){
	if (p < q){
		int t = (p + q) / 2;
		mergesort(s, p, t);
		mergesort(s, t + 1, q);
		merge(s, p, t, q);
	}
}
