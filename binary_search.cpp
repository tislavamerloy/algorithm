int binary_search(int* mass, int size, int target) {
	int  low = 0;
	int high = size;
	int  mid = 0;
	while (low < high - 1) {
		mid = (high + low) / 2;
		if (mass[mid] > target) {
			high = mid;
		} else {
			low = mid;
		}
	}

	if (low >= 0 && mass[low] == target) return low;
	else return -1;
}
