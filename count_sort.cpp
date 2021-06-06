void count_sort(int* mass, int size) {
	int list[10];
	for (int i = 0; i < 10; i++) {
		list[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		switch (mass[i]) {
		case 0:
			list[0] += 1;
			break;
		case 1:
			list[1] += 1;
			break;
		case 2:
			list[2] += 1;
			break;
		case 3:
			list[3] += 1;
			break;
		case 4:
			list[4] += 1;
			break;
		case 5:
			list[5] += 1;
			break;
		case 6:
			list[6] += 1;
			break;
		case 7:
			list[7] += 1;
			break;
		case 8:
			list[8] += 1;
			break;
		case 9:
			list[9] += 1;
			break;
		}
	}
	int pointer = -1;
	for (int i = 0; i < 10; i++) {
		while(list[i] != 0) {
			mass[++pointer] = i;
			list[i] -= 1;
		}
	}
}
