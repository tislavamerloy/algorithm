void buble_sort(int* mass, int size) {
	bool flag = false;
	while (flag == false) {
		flag = true;
		for (int i = 1; i < size; i++) {
			if (mass[i - 1] > mass[i]) {
				flag = false;
				int buffer = mass[i - 1];
				mass[i - 1] = mass[i];
				mass[i] = buffer;
			}
		}
	}
}
