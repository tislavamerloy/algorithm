using namespace std;

class queue {
	class core {
	public:
		core* next;
		int data;
		int level = 1;
		core(int data = int(), core* next = nullptr ) {
			this->data = data;
			this->next = next;
			if (data % 2 == 0) level += 2;
			if (data % 3 == 0) level += 3;
		}
	};
	core* head;
	core* back;
	core* back3;
	core* back4;
	core* back6;
	int size_all;
public:
	queue() {
		 head = nullptr;
		 back = nullptr;
		 back3 = nullptr;
		 back4 = nullptr;
		 back6 = nullptr;
		  
		 size_all = 0;
	}
	queue(int data) {
		int templevel = 1;
		if (data % 2 == 0) templevel += 2;
		if (data % 3 == 0) templevel += 3;
		switch (templevel) {
		case 1:
			head = new core(data);
			back = head;
			back3 = nullptr;
			back4 = nullptr;
			back6 = nullptr;
			break;
		case 3:
			head = new core(data);
			back3 = head;
			back = nullptr;
			back4 = nullptr;
			back6 = nullptr;
			break;
		case 4:
			head = new core(data);
			back4 = head;
			back = nullptr;
			back3 = nullptr;
			back6 = nullptr;
			break;
		case 6:
			head = new core(data);
			back6 = head;
			back = nullptr;
			back3 = nullptr;
			back4 = nullptr;
			break;
		default:
			head = nullptr;
			back = nullptr;
			back3 = nullptr;
			back4 = nullptr;
			back6 = nullptr;
		} 

		size_all = 1;
	}
	int size() {
		return size_all;
	}
	void add(int data) {
		int templevel = 1;
		if (data % 2 == 0) templevel += 2;
		if (data % 3 == 0) templevel += 3;
		switch (templevel) {
		case 1:
			if (back == nullptr) {
				if (back3 == nullptr) {
					if (back4 == nullptr) {
						if (back6 == nullptr) {
							back = (head = new core(data));
						} else {
							back = (back6->next = new core(data));
						}
					} else {
						back = (back4->next = new core(data));
					}
				} else {
					back = (back3->next = new core(data));
				}
			} else {
				back = (back->next = new core(data));
			}
			break;
		case 3:
			if (back3 == nullptr) {
				if (back4 == nullptr) {
					if (back6 == nullptr) {
						back3 = (head = new core(data, head));
					} else {
						back3 = (back6->next = new core(data, back6->next));
					}
				} else {
					back3 = (back4->next = new core(data, back4->next));
				}
			} else {
				back3 = (back3->next = new core(data, back3->next));
			}
			break;
		case 4:
			if (back4 == nullptr) {
				if (back6 == nullptr) {
					back4 = (head = new core(data, head));
				} else {
					back4 = (back6->next = new core(data, back6->next));
				}
			} else {
				back4 = (back4->next = new core(data, back4->next));
			}
			break;
		case 6:
			if (back6 == nullptr) {
				back6 = (head = new core(data, head));
			} else {
				back6 = (back6->next = new core(data, back6->next));
			}
			break;
		default: throw;
		}
		size_all++;
	}
	int take() {
		int answer = head->data;
		core* temp = head->next;
		delete head;
		head = temp;
		size_all--;
		return answer;
	}
};
