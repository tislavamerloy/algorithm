void buble_sort(int* mass, int size) {
	bool flag = false;
	while (flag == false) {
		flag = true;
		for (int i = 0; i < size; i++) {
			for (int ii = i; ii < size; ii++) {
				if (mass[i] > mass[ii]) {
					flag = false;
					int temp = mass[ii];
					mass[ii] = mass[i];
					mass[i] = temp;
					i = ii;
				}
			}
		}
	}
}