#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>


bool gameover = false;
unsigned int final_Score = -1;
unsigned int score = 0;
unsigned int frame = 0;

time_t t0;
time_t t1;
float t_Rz;
float t_Tt;

FILE* logos;

char Translate_InChar_FromNumber(int number) {
	switch (number) {
	case 0:
		return '0'; break;
	case 1:
		return '1'; break;
	case 2:
		return '2'; break;
	case 3:
		return '3'; break;
	case 4:
		return '4'; break;
	case 5:
		return '5'; break;
	case 6:
		return '6'; break;
	case 7:
		return '7'; break;
	case 8:
		return '8'; break;
	case 9:
		return '9'; break;
	}
	return 'X';
}

int Translate_InNumber_FromChar(char symbol) {
	switch (symbol) {
	case '0':
		return 0; break;
	case '1':
		return 1; break;
	case '2':
		return 2; break;
	case '3':
		return 3; break;
	case '4':
		return 4; break;
	case '5':
		return 5; break;
	case '6':
		return 6; break;
	case '7':
		return 7; break;
	case '8':
		return 8; break;
	case '9':
		return 9; break;
	}
	return -1;
}

char my_Map[10][21] = {
		"####################",
		"#       @     0    #",
		"# #  #      #   #  #",
		"#    #####  #####  #",
		"# #  #   # 1       #",
		"# #  #   # ### #   #",
		"# #    2 #      #  #",
		"# # ### ##   ##    #",
		"#                  #",
		"####################",
};

int my_BitMap[10][21];

void Init_BitMap() {
	for (int i = 0; i < 10; ++i) {
		for (int ii = 0; ii < 21; ++ii) {
			if (my_Map[i][ii] == '#') my_BitMap[i][ii] = 3;
			else if (my_Map[i][ii] == '+') my_BitMap[i][ii] = 2;
			else if (my_Map[i][ii] == 'o') my_BitMap[i][ii] = 1;
			else my_BitMap[i][ii] = 0;
		}
	}
}

int Calculate_Final_Score() {
	int highest = 0;
	for (int i = 0; i < 10; ++i) {
		for (int ii = 0; ii < 21; ++ii) {
			if (highest < Translate_InNumber_FromChar(my_Map[i][ii])) {
				highest = Translate_InNumber_FromChar(my_Map[i][ii]);
			}
		}
	}
	return highest + 1;
}

void Time_Manipul(time_t* first_Time, time_t* second_Time) {
	t_Rz = (float)(*second_Time - *first_Time) / CLOCKS_PER_SEC;
	t_Tt += t_Rz;
	*first_Time = 0;
	*second_Time = 0;
}

void Enter_To_Next(char my_Button) {
	switch (my_Button) {
	case 'e': gameover = true;
	};
}

struct my_Hero {
	int x;
	int y;
}hero;

void Init_StartXY_Hero() {
	for (int i = 0; i < 10; ++i) {
		for (int ii = 0; ii < 21; ++ii) {
			if (my_Map[i][ii] == '@') {
				hero.x = ii;
				hero.y = i;
				my_Map[i][ii] = ' ';
			}
		}
	}

};

void Correct_actualXY(char my_Button) {
	switch (my_Button) {
	case'w':
		if (my_BitMap[hero.y - 1][hero.x] == 3 ||
			my_BitMap[hero.y - 1][hero.x] == 2 ||
			my_BitMap[hero.y - 1][hero.x] == 1){
				--(my_BitMap[hero.y - 1][hero.x]);
				break;
		};
		hero.y -= 1; break;
	case's':
		if (my_BitMap[hero.y + 1][hero.x] == 3 ||
			my_BitMap[hero.y + 1][hero.x] == 2 ||
			my_BitMap[hero.y + 1][hero.x] == 1) {
			--(my_BitMap[hero.y + 1][hero.x]);
			break;
		};
		hero.y += 1; break;
	case'a':
		if (my_BitMap[hero.y][hero.x - 1] == 3 ||
			my_BitMap[hero.y][hero.x - 1] == 2 ||
			my_BitMap[hero.y][hero.x - 1] == 1) {
			--(my_BitMap[hero.y][hero.x - 1]);
			break;
		};
		hero.x -= 1; break;
	case'd':
		if (my_BitMap[hero.y][hero.x + 1] == 3 ||
			my_BitMap[hero.y][hero.x + 1] == 2 ||
			my_BitMap[hero.y][hero.x + 1] == 1) {
			--(my_BitMap[hero.y][hero.x + 1]);
			break;
		};
		hero.x += 1; break;
	case'e':
		gameover = true;
	}
}

void Draw_Game_Screen() {

	system("cls");
	printf("\n FRAME %d | %gs + %g \n", frame++, t_Tt, t_Rz);
	fprintf(logos, "\n FRAME %d | %gs + %g \n", frame, t_Tt, t_Rz);

	for (int i = 0; i < 10; ++i) {
		printf(" ");
		fprintf(logos, " ");
		for (int ii = 0; ii < 21; ++ii) {
			if (i == hero.y && ii == hero.x) {
				printf("@");
				fprintf(logos, "@");
			}
			else if (my_Map[i][ii] == '0' ||
				my_Map[i][ii] == '1' ||
				my_Map[i][ii] == '2' ||
				my_Map[i][ii] == '3' ||
				my_Map[i][ii] == '4' ||
				my_Map[i][ii] == '5' ||
				my_Map[i][ii] == '6' ||
				my_Map[i][ii] == '7' ||
				my_Map[i][ii] == '8' ||
				my_Map[i][ii] == '9') {
				if (my_Map[i][ii] == Translate_InChar_FromNumber(score)) { 
					printf("&");
					fprintf(logos, "&");
				}
				else {
					printf(" ");
					fprintf(logos, " ");
				}
			}
			else if (my_BitMap[i][ii] == 3) {
				printf("#");
				fprintf(logos, "#");
			}
			else if (my_BitMap[i][ii] == 2) {
				printf("+");
				fprintf(logos, "+");
			}
			else if (my_BitMap[i][ii] == 1) { 
				printf("o");
				fprintf(logos, "o");
			}
			else {
				printf(" ");
				fprintf(logos, " ");
			}
		}
		printf("\n");
		fprintf(logos, "\n");
	}
	fprintf(logos, "C$\n");

}

void Animation_IntoReplay() {

	system("cls");

	char my_FinalScreen[12][21] = {
		"####################",
		"##@@@###@@@@##@@@###",
		"##@##@##@#####@##@##",
		"##@@@###@@@@##@@@@##",
		"##@##@##@#####@#####",
		"##@###@#@@@@##@#####",
		"####################",
		"##@#####@@###@###@##",
		"##@####@##@###@@@###",
		"##@####@@@@####@####",
		"##@@@#@###@####@####",
		"####################",
	};
	printf("\n");
	for (int i = 0; i < 12; ++i) {
		printf(" ");
		for (int ii = 0; ii < 21; ++ii) {
			printf("%c", my_FinalScreen[i][ii]);
		}
		printf("\n");
	}
	printf("FRAME: %d | TIME: %g\n", score, t_Tt);

}

void CheckXY_ForEat() {
	if (my_Map[hero.y][hero.x] == Translate_InChar_FromNumber(score)) {
		++score;
	}
}

void Check_Gameover() {
	if (score == final_Score) gameover = true;
}

void Start_Repeat_Mode() {

}

int main() {
	
	final_Score = Calculate_Final_Score();
	Init_BitMap();
	logos = fopen("logos.txt", "w");

	Init_StartXY_Hero();

	while(!gameover) {
		t0 = clock();
		Draw_Game_Screen();

		Correct_actualXY( _getch() );

		CheckXY_ForEat();

		Check_Gameover();
		t1 = clock();
		
		Time_Manipul(&t0, &t1);

	}
	fclose(logos);

	Draw_Game_Screen();
	
	gameover = false;
	while (!_kbhit());
	Enter_To_Next(_getch());
	if (!gameover) {
		
		Animation_IntoReplay();

		while (!_kbhit());
		Enter_To_Next(_getch());
		
		while (!gameover) {
			logos = fopen("logos.txt", "r");
			system("cls");

			char buffer[30];
			memset(buffer, 0, sizeof(buffer));
			
			while (!feof(logos)) {
				fgets(buffer, 30, logos);
				if(buffer[0] != 'C' && buffer[1] != '$') printf("%s", buffer);
				else {
					Sleep(500);
					system("cls");
				}
			}

			Animation_IntoReplay();
			while (!_kbhit());

			if(_kbhit()) Enter_To_Next(_getch());

			fclose(logos);
		}
		
	}

	return 0;
}
