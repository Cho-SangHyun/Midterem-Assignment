#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class contact_address {                             //연락처 클래스
	map<string, string> address;                        // map 컨테이너를 멤버변수로
public:
	map<string, string>::iterator it;   
	contact_address();                                  // 생성자 함수
	void add_address(string key, string value);         // 연락처 추가
	void delete_address(string key);                    // 연락처 삭제
	void show_address();                                // 연락처 조회
};

contact_address::contact_address() {
	address.insert(make_pair("김민우", "010-1236-9545"));    //기본적으로 가질 3개의 연락처 저장
	address.insert(make_pair("강희건", "010-3618-8756"));
	address.insert(make_pair("장지환", "010-9872-9436"));
	it = address.begin();
}

void contact_address::add_address(string key, string value) {      // 연락처를 추가하는 함수 : map컨테이너에 추가
	if (address.find(key) == address.end()) {
		cout << key << "을(를) 연락처에 등록합니다" << endl;
		address.insert(make_pair(key, value));
	}
	else
		cout << "이미 " << key << "이(가) 연락처에 등록되어 있습니다" << endl;
}

void contact_address::delete_address(string key) {                 // 연락처를 삭제하는 함수 : map컨테이너에서 삭제
	if (address.find(key) == address.end())
		cout << "이미 연락처에 " << key << "가 없습니다" << endl;
	else {
		cout << key << "(" << address[key] << ")" << "을(를) 연락처에서 제거합니다" << endl;
		address.erase(key);
	}
}

void contact_address::show_address() {                             // 연락처를 조회하는 함수 
	it = address.begin();
	cout << "현재 연락처에 " << address.size() << "개의 번호가 있습니다." << endl << endl;
	if (address.size() > 0) {
		cout << "\t<<목록>>" << endl;
		for (int i = 0; i < address.size(); i++) {
			cout << i+1 << ". " << it->first << " ( " << it->second << " )" << endl;
			it++;
		}
	}
}

class GBBuser {
protected:
	string gbb[3];
public:
	GBBuser() {
		gbb[0] = "가위", gbb[1] = "바위", gbb[2] = "보";
	}
	virtual string turn() = 0;
};

class GBBplayer : public GBBuser {
public:
	GBBplayer() : GBBuser() { ; }
	virtual string turn();
};

string GBBplayer::turn() {
	string word;
	while (true) {
		cout << "무엇을 내시겠습니까? : ";
		cin >> word;
		if (word == "가위" || word == "바위" || word == "보")
			break;
		else
			cout << "잘못된 단어입니다. 다시 내도록 하세요." << endl;
	}
	return word;
}

class GBBcom : public GBBuser {
public:
	GBBcom() : GBBuser() { ; }
	virtual string turn();
};

string GBBcom::turn() {
	srand((unsigned)time(0));
	int num = rand() % 3;
	return gbb[num];
}

class UPandDOWN {
	int value;
	int level;
public:
	UPandDOWN(int level);
	void playgame();
};

UPandDOWN::UPandDOWN(int level) {
	this->level = level;
	srand((unsigned)time(0));
	value = rand() % 100;
}

void UPandDOWN::playgame() {
	if (level == 1)
		cout << "EASY 난이도로 게임을 시작합니다. 답은 0과 99사이에 있습니다. " << endl << endl;
	else if (level == 2)
		cout << "NORMAL 난이도로 게임을 시작합니다. 답은 0과 99사이에 있습니다. " << endl << endl;
	else
		cout << "HARD 난이도로 게임을 시작합니다. 답은 0과 99사이에 있습니다. " << endl << endl;

	int number;
	int count = 0;
	while (count < 6 - level) {
		cout << "(" << count + 1 << ") Round" << "\t(" << count+1 << "/" << 6 - level << ")" << endl;
		cout << " >> ";
		cin >> number;
		if (number < 0 || 99 < number) {
			cout << "답은 0과 99사이입니다. 다시 입력하세요." << endl;
			continue;
		}
		if (number == value) {
			cout << "맞추셨습니다!! 축하드립니다!" << endl << endl;
			break;
		}
		if (number > value)
			cout << " >> DOWN" << endl << endl;
		else
			cout << " >> UP" << endl << endl;
		if (count == 6 - level - 1)
			cout << "아쉽습니다. 정답은 " << value << "였습니다." << endl << endl;
		count++;
	}
}

int main() {
	int menu;
	contact_address A;

	while (true) {
		cout << "==========[ M E N U ] ==========" << endl;
		cout << "(1) >> 연락처 관리하기" << endl;
		cout << "(2) >> 게임하기" << endl;
		cout << "\t*(다른 키 : 프로그램을 종료)" << endl;
		cout << "================================" << endl;
		cout << "사용하실 기능을 골라주세요 : ";
		cin >> menu;
		cout << "================================" << endl << endl;

		switch (menu) {
		case 1: {
			int num1, x;
			x = 1;
			while (x) {          
				cout << "==========[ 연 락 처 ] ==========" << endl;
				cout << "(1) >> 연락처 추가하기" << endl;
				cout << "(2) >> 연락처 삭제하기" << endl;
				cout << "(3) >> 연락처 조회하기" << endl;
				cout << "\t*(다른 키 : 메뉴로 돌아가기)" << endl;
				cout << "=================================" << endl;
				cout << "사용하실 기능을 골라주세요 : ";
				cin >> num1;
				cout << "=================================" << endl << endl;

				switch (num1) {          //사용자가 입력한 num값에 따라 아래 switch문 수행
				case 1: {                //단어 추가하기
					string key, value;
					cout << "연락처에 추가할 사람의 이름을 입력해주세요 :";
					cin >> key;
					cout << "그 사람의 번호을 입력해주세요 : ";
					cin >> value;
					A.add_address(key, value);
					cout << endl;
					break;
				}
				case 2: {                //단어 삭제하기
					string key;
					cout << "연락처에서 삭제할 사람의 이름을 입력해주세요 : ";
					cin >> key;
					A.delete_address(key);
					cout << endl;
					break;
				}
				case 3: {               //단어 검색하기
					A.show_address();
					cout << endl;
					break;
				}
				default: {
					cout << "메뉴로 돌아갑니다." << endl;
					x = 0;
					break;
				}
				}
				cout << endl;
			}
			break;
		}
		case 2: {
			int num2, y;
			y = 1;
			while (y) {
				cout << "==========[ G A M E ] ==========" << endl;
				cout << "(1) >> 가위바위보 게임하기" << endl;
				cout << "(2) >> Up & Down 게임하기" << endl;
				cout << "(3) >> 영단어 뜻 맞추기 게임하기" << endl;
				cout << "(4) >> 별먹기 게임하기" << endl;
				cout << "(5) >> 흑과 백(2p) 게임하기" << endl;
				cout << "\t*(다른 키 : 메뉴로 돌아가기)" << endl;
				cout << "=================================" << endl;
				cout << "플레이할 게임을 골라주세요 : ";
				cin >> num2;
				cout << "=================================" << endl << endl;

				switch (num2) {
				case 1: {
					GBBplayer player;
					GBBcom com;
					cout << "===== 가위바위보 게임을 시작합니다. 5라운드까지 진행됩니다. =====" << endl << endl;
					for (int i = 1; i <= 5; i++) {
						cout << "(" << i << ") " << "Round >>" << endl;
						string players = player.turn();
						string coms = com.turn();
						cout << "컴퓨터가 낸 것 : " << coms << endl;
						if (players == coms)
							cout << "무승부입니다." << endl << endl;
						else if (players == "가위") {
							if (coms == "바위")
								cout << "패배했습니다." << endl << endl;
							else
								cout << "승리했습니다." << endl << endl;
						}
						else if (players == "바위") {
							if (coms == "보")
								cout << "패배했습니다." << endl << endl;
							else
								cout << "승리했습니다." << endl << endl;
						}
						else if (players == "보") {
							if (coms == "가위")
								cout << "패배했습니다." << endl << endl;
							else
								cout << "승리했습니다." << endl << endl;
						}
					}
					break;
				}
				case 2: {
					int game_level;
					cout << "===== Up & Down 게임을 시작합니다. =====" << endl << endl;
					cout << "(1) >> ★★☆☆☆ EASY " << endl;
					cout << "(2) >> ★★★☆☆ NORMAL" << endl;
					cout << "(3) >> ★★★★★ HARD" << endl;
					cout << "========================================" << endl;

					while (true) {
						cout << ">> 난이도를 골라주세요 : ";
						cin >> game_level;
						if (0 < game_level && game_level < 4)
							break;
						cout << "\t잘못 입력하셨습니다." << endl <<endl;
					}
					cout << "========================================" << endl << endl;
					UPandDOWN game(game_level);
					game.playgame();
					break;
				}
				case 3: {
					break;
				}
				case 4: {
					break;
				}
				case 5: {
					break;
				}
				default: {
					cout << "메뉴로 돌아갑니다." << endl;
					y = 0;
					break;
				}
				}
				cout << endl;
			}
			break;
		}
		default: {
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		}
		}
	}
}