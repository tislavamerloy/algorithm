#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int pow(int degree) {
	if (degree < 0) return -666;
	if (degree == 0) return 1;
	if (degree == 1) return 10;
	return 10 * pow(--degree);
}

struct razvilka {

	struct core {
		string path;
		int path_lenght;

		core() {
			path_lenght = 0;
		}
		core(string path, int path_lenght) {
			this->path = path;
			this->path_lenght = path_lenght;
		}
	};

	struct head {
		vector<core> path_history;

		head() {

		}
	};

	enum class resourse {
		RIGHT,
		LEFT
	};

	int _A;
	int _B;
	int branch_length;
	head left;
	head right;

	razvilka() {
		_A = 0;
		_B = 0;
		branch_length = 0;
	}

	core podbitb(core copirka, string addpath, int addpath_lenght) {
		copirka.path += addpath;
		copirka.path_lenght += addpath_lenght;
		return copirka;
	}

	void makehistorylal_forright(const razvilka& copirka, resourse resoursefrom) {
		if (resoursefrom == resourse::LEFT) {
			for (int i = 0; i < copirka.left.path_history.size(); i++) {
				this->right.path_history.push_back(podbitb(copirka.left.path_history[i], "ad", this->_A + this->branch_length));
				this->right.path_history.push_back(podbitb(copirka.left.path_history[i], "db", copirka.branch_length + this->_B));
			}
		}
		else if (resoursefrom == resourse::RIGHT) {
			for (int i = 0; i < copirka.right.path_history.size(); i++) {
				this->right.path_history.push_back(podbitb(copirka.right.path_history[i], "b", this->_B));
				this->right.path_history.push_back(podbitb(copirka.right.path_history[i], "dad", copirka.branch_length + this->_A + this->branch_length));
			}
		}
		else throw;
	}

	void makehistorylal_forleft(const razvilka& copirka, resourse resoursefrom) {
		if (resoursefrom == resourse::LEFT) {
			for (int i = 0; i < copirka.left.path_history.size(); i++) {
				this->left.path_history.push_back(podbitb(copirka.left.path_history[i], "a", this->_A));
				this->left.path_history.push_back(podbitb(copirka.left.path_history[i], "dbd", copirka.branch_length + this->_B + this->branch_length));
			}
		}
		else if (resoursefrom == resourse::RIGHT) {
			for (int i = 0; i < copirka.right.path_history.size(); i++) {
				this->left.path_history.push_back(podbitb(copirka.right.path_history[i], "bd", this->_B + this->branch_length));
				this->left.path_history.push_back(podbitb(copirka.right.path_history[i], "da", copirka.branch_length + this->_A));
			}
		}
		else throw;
	}

};

void task() {
	int N;
	vector<razvilka> allrazv;
	int iteraq = -1;

	cout << "enter N: ";
	cin >> N;
	cout << endl;
	
	cout << "enter proprities (x for accept): " << endl;
	while (++iteraq != N) {
		string inputdata;
		char buffer = ' ';
		while (buffer != 'x') {
			inputdata.push_back(buffer);
			buffer = cin.get();
		}

		allrazv.push_back(razvilka());
		vector<int> number;
		vector<int> number2;
		vector<int> number3;

		int flag = 0;
		for (int i = 1; i < inputdata.size(); i++) {
			if (inputdata[i] != ' ' && inputdata[i] != ',' && inputdata[i] != '\n') {
				switch (flag) {
				case 0:
					switch (inputdata[i]) {
					case '0':
						number.push_back(0);
						break;
					case '1':
						number.push_back(1);
						break;
					case '2':
						number.push_back(2);
						break;
					case '3':
						number.push_back(3);
						break;
					case '4':
						number.push_back(4);
						break;
					case '5':
						number.push_back(5);
						break;
					case '6':
						number.push_back(6);
						break;
					case '7':
						number.push_back(7);
						break;
					case '8':
						number.push_back(8);
						break;
					case '9':
						number.push_back(9);
						break;
					}
					break;
				case 1:
					switch (inputdata[i]) {
					case '0':
						number2.push_back(0);
						break;
					case '1':
						number2.push_back(1);
						break;
					case '2':
						number2.push_back(2);
						break;
					case '3':
						number2.push_back(3);
						break;
					case '4':
						number2.push_back(4);
						break;
					case '5':
						number2.push_back(5);
						break;
					case '6':
						number2.push_back(6);
						break;
					case '7':
						number2.push_back(7);
						break;
					case '8':
						number2.push_back(8);
						break;
					case '9':
						number2.push_back(9);
						break;
					}
					break;
				case 2:
					switch (inputdata[i]) {
					case '0':
						number3.push_back(0);
						break;
					case '1':
						number3.push_back(1);
						break;
					case '2':
						number3.push_back(2);
						break;
					case '3':
						number3.push_back(3);
						break;
					case '4':
						number3.push_back(4);
						break;
					case '5':
						number3.push_back(5);
						break;
					case '6':
						number3.push_back(6);
						break;
					case '7':
						number3.push_back(7);
						break;
					case '8':
						number3.push_back(8);
						break;
					case '9':
						number3.push_back(9);
						break;
					}
					break;
				}
			}
			else if (inputdata[i - 1] != ' ' && inputdata[i - 1] != ',' && inputdata[i - 1] != '\n') flag++;
		}
		
		flag = 0;
		while (flag != 3) {
			int rezult = 0;
			switch (flag++) {
			case 0:
				for (int i = 0; i < number.size(); i++) {
					rezult += number[i] * (pow((number.size() - 1) - i));
				}
				allrazv[iteraq]._A = rezult;
				break;
			case 1:
				for (int i = 0; i < number2.size(); i++) {
					rezult += number2[i] * (pow((number2.size() - 1) - i));
				}
				allrazv[iteraq]._B = rezult;
				break;
			case 2:
				for (int i = 0; i < number3.size(); i++) {
					rezult += number3[i] * (pow((number3.size() - 1) - i));
				}
				allrazv[iteraq].branch_length = rezult;
				break;
			}
		}
	}
	
	allrazv[0].left.path_history.push_back(razvilka::core("a", allrazv[0]._A));
	allrazv[0].left.path_history.push_back(razvilka::core("bd", allrazv[0]._B + allrazv[0].branch_length));
	allrazv[0].right.path_history.push_back(razvilka::core("b", allrazv[0]._B));
	allrazv[0].right.path_history.push_back(razvilka::core("ad", allrazv[0]._A + allrazv[0].branch_length));

	iteraq = 0;
	while (++iteraq < N) {
		allrazv[iteraq].makehistorylal_forleft(allrazv[iteraq - 1], razvilka::resourse::LEFT);
		allrazv[iteraq].makehistorylal_forleft(allrazv[iteraq - 1], razvilka::resourse::RIGHT);
		allrazv[iteraq].makehistorylal_forright(allrazv[iteraq - 1], razvilka::resourse::LEFT);
		allrazv[iteraq].makehistorylal_forright(allrazv[iteraq - 1], razvilka::resourse::RIGHT);
	}
	
	pair<int, string> leftmost(INT_MAX, " ");
	pair<int, string> rightmost(INT_MAX, " ");
	for (int i = 0; i < allrazv[N - 1].left.path_history.size(); i++) {
		if (allrazv[N - 1].left.path_history[i].path_lenght < leftmost.first) {
			leftmost.first = allrazv[N - 1].left.path_history[i].path_lenght;
			leftmost.second = allrazv[N - 1].left.path_history[i].path;
		}
	}
	for (int i = 0; i < allrazv[N - 1].right.path_history.size(); i++) {
		if (allrazv[N - 1].right.path_history[i].path_lenght < rightmost.first) {
			rightmost.first = allrazv[N - 1].right.path_history[i].path_lenght;
			rightmost.second = allrazv[N - 1].right.path_history[i].path;
		}
	}

	pair<int, string> themosteffectivemethodofsolutionthisproblem;
	if (leftmost.first < rightmost.first) {
		themosteffectivemethodofsolutionthisproblem.first = leftmost.first;
		themosteffectivemethodofsolutionthisproblem.second = leftmost.second;
	} else {
		themosteffectivemethodofsolutionthisproblem.first = rightmost.first;
		themosteffectivemethodofsolutionthisproblem.second = rightmost.second;
	}
	
	cout << endl <<"ANSWER: " << themosteffectivemethodofsolutionthisproblem.second 
		<< '-' << themosteffectivemethodofsolutionthisproblem.first << endl;
}
