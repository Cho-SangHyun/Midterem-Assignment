#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Func {      //함수를 스태틱 멤버를 통해 전역함수처럼 만든 부분
public:
	static void random_set(int arr[], int size, int max);
	static void arr_set(int arr[], int size, int wordnumber);
};

void Func::random_set(int arr[], int size, int max) {        //배열의 각 요소들을 랜덤하게 뽑은 수로 설정해주는 함수
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % max;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				i--;
				break;
			}
		}
	}
}

void Func::arr_set(int arr[], int size, int wordnumber) {  //배열의 각 요소 중 사용자가 원하는 값이 없다면, 배열의 각 요소 중 하나를 사용자가 원하는 값으로 바꿔줌.
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == wordnumber) {
			count++;
			break;
		}
		else {
			;
		}
	}
	if (count == 1)
		;
	else {
		int j = rand() % 4;
		arr[j] = wordnumber;
	}
}

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

class GBBuser {        // 가위바위보 게임에 쓰일 추상 클래스
protected:
	string gbb[3];
public:
	GBBuser();         // 생성자
	virtual string turn() = 0;
};

GBBuser::GBBuser() {    // 생성자 함수
	gbb[0] = "가위", gbb[1] = "바위", gbb[2] = "보";
}

class GBBplayer : public GBBuser {  // 파생 클래스 - 플레이어
public:
	GBBplayer() : GBBuser() { ; }
	virtual string turn();
};

string GBBplayer::turn() {      // 무엇을 내는지 정하는 함수
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

class GBBcom : public GBBuser {   // 파생 클래스 - 컴퓨터
public:
	GBBcom() : GBBuser() { ; }
	virtual string turn();
};

string GBBcom::turn() {     // 가위바위보 중 랜덤하게 하나를 낸다.
	int num = rand() % 3;
	return gbb[num];
}

class UPandDOWN {        // Up & Down 게임에 쓰일 클래스
	int value;              // 정답 즉 사용자가 맞춰야 하는 값에 해당하는 멤버변수
	int level;              // 난이도에 해당하는 멤버변수
public:
	UPandDOWN(int level);
	void playgame();
};

UPandDOWN::UPandDOWN(int level) {   // 생성자
	this->level = level;     // 매개변수로 받은 level이 난이도가 된다.
	value = rand() % 100;    // 0부터 99까지의 숫자 중 랜덤해서 가짐
}

void UPandDOWN::playgame() {
	if (level == 1)
		cout << "EASY 난이도로 게임을 시작합니다. 답은 0과 99사이에 있습니다. " << endl << endl;
	else if (level == 2)
		cout << "NORMAL 난이도로 게임을 시작합니다. 답은 0과 99사이에 있습니다. " << endl << endl;
	else
		cout << "HARD 난이도로 게임을 시작합니다. 답은 0과 99사이에 있습니다. " << endl << endl;

	int number;  // 사용자가 입력하는 값이 저장됨
	int count = 0;
	while (count < 6 - level) {    // 즉 level = 1이면 5번, 2이면 4번, 3이면 3번까지 최대로 루프가 돔
		cout << "(" << count + 1 << ") Round" << "\t(" << count+1 << "/" << 6 - level << ")" << endl;
		cout << " >> ";
		cin >> number;
		if (number < 0 || 99 < number) {  // 0부터 99까지의 숫자가 아닌 걸 제시하면 다시 고르게
			cout << " >> 답은 0과 99사이입니다. 다시 입력하세요." << endl << endl;
			continue;
		}
		if (number == value) {           // 숫자를 맞추면 게임 종료
			cout << "맞추셨습니다!! 축하드립니다!" << endl << endl;
			break;
		}
		if (number > value)
			cout << " >> DOWN" << endl << endl;
		else
			cout << " >> UP" << endl << endl;
		if (count == 6 - level - 1)       // 마지막까지 못 맞추면 정답 알려주고 게임 종료
			cout << "아쉽습니다. 정답은 " << value << "였습니다." << endl << endl;
		count++;
	}
}

class guess_word {                          // 영단어 뜻 맞추기 게임에 쓰일 클래스
	map<string, string> Engdic;                      // 키, 값 모두 string값으로 받는 map컨테이너를 멤버 변수로 가짐
public:
	map<string, string>::iterator it;                // map 컨테이너의 iterator를 멤버 변수로 가짐
	guess_word();
	void set_iterator(int n);                        // iterator가 어떤 값을 가리키게 할 건지 설정
	int get_wordcount() { return Engdic.size(); }    // map컨테이너의 사이즈 반환
};

guess_word::guess_word() {         // 생성자 
	Engdic.insert(make_pair("love", "사랑"));    //기본적으로 가질 20개 영단어 저장
	Engdic.insert(make_pair("chair", "의자"));
	Engdic.insert(make_pair("desk", "책상"));
	Engdic.insert(make_pair("window", "창문"));
	Engdic.insert(make_pair("baby", "아기"));
	Engdic.insert(make_pair("food", "음식"));
	Engdic.insert(make_pair("road", "도로"));
	Engdic.insert(make_pair("pig", "돼지"));
	Engdic.insert(make_pair("picture", "사진"));
	Engdic.insert(make_pair("apple", "사과"));
	Engdic.insert(make_pair("grape", "포도"));
	Engdic.insert(make_pair("friend", "친구"));
	Engdic.insert(make_pair("bomb", "폭탄"));
	Engdic.insert(make_pair("building", "건물"));
	Engdic.insert(make_pair("earth", "지구"));
	Engdic.insert(make_pair("straw", "빨대"));
	Engdic.insert(make_pair("tree", "나무"));
	Engdic.insert(make_pair("boy", "남자"));
	Engdic.insert(make_pair("girl", "여자"));
	Engdic.insert(make_pair("glass", "유리"));
	it = Engdic.begin();
}

void guess_word::set_iterator(int n) {                     // iterator가 특정 녀석을 가리키게 설정하기
	it = Engdic.begin();
	if (0 < n && n < Engdic.size()) {
		for (int i = 0; i < n; i++)
			it++;
	}
}

class BlackWhite {              // 흑과 백 게임에 쓰일 클래스
	vector<int> deck;           // 벡터를 활용한 멤버변수
public:
	vector<int>::iterator it;   // iterator도 멤버변수로 갖는다
	BlackWhite();               // 생성자
	void show_rule();           // 게임의 룰을 출력하는 함수
	void show_deck();           // 덱을 출력하는 함수
	int submit_card();          // 숫자를 제시하는 함수
	void describe_number(int num);   // 제시한 숫자의 색깔을 출력하는 함수
};

BlackWhite::BlackWhite() {      // 생성자함수 : deck의 초기화
	deck = { 0,1,2,3,4,5,6,7,8 };
}

void BlackWhite::show_rule() {   // 룰을 출력하는 함수 : 파일 입출력 활용
	string line;
	ifstream fin("Rule.txt", ios::in);
	while (getline(fin, line)) {  // 라인 단위로 읽어서 룰을 출력
		cout << line << endl;
	}
	fin.close();
}

void BlackWhite::show_deck() {        // 보유한 덱을 출력하는 함수
	int black = 0, white = 0;
	for (int i = 0; i < deck.size(); i++) {  // 현재 보유한 숫자들중 홀수는 몇 갠지, 짝수는 몇 갠지 센다.
		if (deck[i] % 2 == 0)         // 짝수 카운트
			black++;
		else                          // 홀수 카운트
			white++;
	}

	cout << "Deck : ";;
	for (int i = 0; i < black; i++)   // 가지고 있는 숫자 중 짝수숫자의 갯수만큼 블랙 출력
		cout << "□";
	for (int i = 0; i < white; i++)   // 가지고 있는 숫자 중 홀수숫자의 갯수만큼 화이트 출력
		cout << "■";
	cout << endl;
}

int BlackWhite::submit_card() {      // 숫자를 제시하는 함수
	int number;
	int a = 1;
	it = deck.begin();               // 멤버변수 it가 deck벡터의 처음녀석을 가리키게 한다.

	while (true) {
		cout << "제시할 숫자를 골라주십시오 : ";
		cin >> number;
		for (int i = 0; i < deck.size(); i++) {
			if (deck[i] == number) {              // 덱에 있는 숫자 중 사용자가 제시한 숫자가 있다면
				for (int j = 0; j < i; j++) {     // it가 그 놈을 가리키게 한다.
					it++;                         
				}
				a = 0;                            //while문을 탈출하기 위한 장치
				break;                            // for문 탈출
			}
		}
		if (a == 0)                               //for문에서 설정한 덕에 while문을 탈출하게 됨
			break;
		cout << "잘못 입력하셨습니다. " << endl;  // 즉 덱에 있는 숫자에 사용자가 제시한 숫자가 없으면 숫자를 다시 고르게 됨
	}

	it = deck.erase(it);                          // 사용자가 제시한 숫자를 deck벡터에서 지움
	return number;                                // 사용자가 제시한 숫자 리턴
}

void BlackWhite::describe_number(int num) {       // 사용자가 제시한 숫자( = num)의 색 출력
	if (num % 2 == 1)                                 // 홀수면 White
		cout << "흰색카드(■)를 냈습니다." << endl;
	else                                              // 짝수면 Black
		cout << "검은카드(□)를 냈습니다." << endl;
}

class stargameObj {            // 별먹기 게임에 쓰일 추상 클래스
protected:
	int distance;             // 한 번 이동할 때 이 값만큼 이동
	int x, y;                 // 위치의 좌표
public:
	stargameObj(int startX, int startY, int distance);   // 생성자 함수
	virtual ~stargameObj() {};                           // 가상 소멸자
	virtual void move() = 0;                             // 이동하기
	virtual string Shape() = 0;                          // 객체의 모양을 나타내는 문자 리턴
	int getX() { return x; }                             // x좌표 리턴
	int getY() { return y; }                             // y좌표 리턴
	bool collision(stargameObj& p);                      // 객체 p와 충돌하면 true리턴
};

stargameObj::stargameObj(int startX, int startY, int distance) { // 초기 위치 및 이동거리 설정
	this->x = startX, this->y = startY;
	this->distance = distance;
}

bool stargameObj::collision(stargameObj& p) {                    // 충돌하면(즉 좌표값들이 같아지면) true 리턴
	if (this->x == p.getX() && this->y == p.getY())
		return true;
	else
		return false;
}

class Human : public stargameObj {             // 파생 클래스 - 휴먼
public:
	Human(int x, int y, int distance) : stargameObj(x, y, distance) {};
	void move();
	string Shape() { return "◎"; }  // 휴먼의 모양으로 쓰임
};

void Human::move() {        // 휴먼 객체의 이동에 쓰이는 함수
	char key;
	while (true) {
		cout << "\n\n >> 왼쪽(a), 위쪽(w), 오른쪽(d), 아래쪽(s)" << endl;
		cout << " >> 이동하실 방향을 골라주세요 : ";
		cin >> key;

		if (key == 'a') {          // 왼쪽로 이동
			if (this->y != 0) {
				this->y -= distance;
				break;
			}
			else
				cout << " >> 왼쪽으론 더 이상 갈 수 없습니다!" << endl;
		}
		else if (key == 'w') {     // 위로 이동
			if (this->x != 0) {
				this->x -= distance;
				break;
			}
			else
				cout << " >> 위쪽으론 더 이상 갈 수 없습니다!" << endl;
		}
		else if (key == 'd') {     // 오른쪽으로 이동
			if (this->y != 19) {
				this->y += distance;
				break;
			}
			else
				cout << " >> 오른쪽으론 더 이상 갈 수 없습니다!" << endl;
		}
		else if (key == 's') {     // 밑으로 이동 
			if (this->x != 9) {
				this->x += distance;
				break;
			}
			else
				cout << " >> 아래쪽으론 더 이상 갈 수 없습니다!" << endl;
		}
		else
			cout << " >> 잘못 입력하셨습니다." << endl;
	}
}

class Monster : public stargameObj {     // 파생 클래스 - 몬스터 
public:
	Monster(int x, int y, int distance) : stargameObj(x, y, distance) {};
	void move();
	string Shape() { return "▣"; }   // 몬스터 객체의 모양으로 쓰임
};

void Monster::move() {     // 몬스터 객체의 이동에 쓰이는 함수
	while (true) {
		int n = rand() % 4;      // 이동할 방향을 랜덤으로 선택
		if (n == 0) {            // 왼쪽으로 이동
			if (this->y > 1) {
				this->y -= distance;
				break;
			}
		}
		else if (n == 1) {       // 위쪽으로 이동
			if (this->x > 1) {
				this->x -= distance;
				break;
			}
		}
		else if (n == 2) {       // 오른쪽으로 이동 
			if (this->y < 18) {
				this->y += distance;
				break;
			}
		}
		else if (n == 3) {       // 아래쪽으로 이동
			if (this->x < 8) {
				this->x += distance;
				break;
			}
		}
	}
}

class Star : public stargameObj {      // 파생 클래스 - 별
public:
	Star(int x, int y, int distance) : stargameObj(x, y, distance) {};
	void move() { ; }
	string Shape() { return "☆"; }
};

int main() {
	srand((unsigned)time(0));
	int menu;                // 이 값에 따라 연락처 기능을 쓸지, 게임 기능을 쓸지를 선택함
	contact_address A;       // 연락처 객체. 

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
		case 1: {   // 연락처 기능 이용
			int num1, x;    // num1 = 연락처내에서도 어떤 기능을 선택할지 고를 때 쓰임, x = 연락처 기능을 종료할 때 쓰임
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

				switch (num1) {          // 사용자가 입력한 num1값에 따라 아래 switch문 수행
				case 1: {                // 연락처 추가하기
					string key, value;
					cout << "연락처에 추가할 사람의 이름을 입력해주세요 :";
					cin >> key;
					cout << "그 사람의 번호을 입력해주세요 : ";
					cin >> value;
					A.add_address(key, value);
					cout << endl;
					break;
				}
				case 2: {                // 연락처 삭제하기
					string key;
					cout << "연락처에서 삭제할 사람의 이름을 입력해주세요 : ";
					cin >> key;
					A.delete_address(key);
					cout << endl;
					break;
				}
				case 3: {               // 연락처 조회하기
					A.show_address();
					cout << endl;
					break;
				}
				default: {               // 메뉴로 돌아가기
					cout << "메뉴로 돌아갑니다." << endl;
					x = 0;
					break;
				}
				}
				cout << endl;
			}
			break;
		}
		case 2: {   // 게임 기능 이용
			int num2, y;     // num2 = 게임기능 내에서도 어떤 게임을 선택할지 고를 때 쓰임, y = 게임 기능을 종료할 때 쓰임
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

				switch (num2) {     // 사용자가 입력한 num2값에 따라 아래 switch문 수행
				case 1: {           // 가위바위보 게임
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
				case 2: {    // Up & Down 게임
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
				case 3: {    // 영단어 뜻 맞추기 게임
					guess_word dic;
					int word[5];
					int option[4];
					int answer;
					map<string, string>::iterator A;  //퀴즈게임에서 정답에 해당하는 놈을 가리킴
					map<string, string>::iterator p[4];  //퀴즈게임에서 각각 4개의 보기에 해당하는 놈을 가리킴

					cout << "===== 영단어 뜻 맞추기 게임을 시작합니다. =====" << endl << endl;
					Func::random_set(word, 5, dic.get_wordcount());  //퀴즈로 낼 5개의 단어를 설정(랜덤으로)
					for (int i = 0; i < 5; i++) {
						dic.set_iterator(word[i]);
						A = dic.it;              //이를 통해 while 이전에 선언된 A가 map컨테이너에서 정답인 값을 가리키게 된다 
						cout << "(" << i + 1 << ") Round >> '" << A->first << "'" << endl;
						Func::random_set(option, 4, dic.get_wordcount());    //보기로 주어질 4개의 단어 설정
						Func::arr_set(option, 4, word[i]);                   //보기에 정답인 단어도 들어가도록 설정
						for (int j = 0; j < 4; j++) {
							dic.set_iterator(option[j]);
							p[j] = dic.it;                  // 이를 통해 while 이전에 선언된 p들이 map컨테이너에서 보기에 해당하는 값들을 가리키게 됨
						}
						cout << "(1) " << p[0]->second << "\t(2) " << p[1]->second << "\t(3) " << p[2]->second << "\t(4) " << p[3]->second << "\n" << endl;
						cout << "정답을 입력하세요. (보기에 없는 숫자를 누르면 오답으로 간주합니다) : ";
						cin >> answer;
						if (answer > 0 && answer < 5) {
							if (p[answer - 1]->second == A->second)
								cout << "정답!" << "\n" << endl;
							else
								cout << "오답!" << "\n" << endl;
						}
						else
							cout << "오답!" << "\n" << endl;
					}
					break;
				}
				case 4: {     // 별먹기 게임
					string board[10][20];                     // 10 X 20 격자판 만들기
					Human player(0, 0, 1);                    // 휴먼 객체 : 시작위치=(0,0), 이동가능거리 = 1
					Monster monster(5, 10, 2);                // 몬스터 객체 : 시작위치=(5,10), 이동가능거리 = 2
					Star star(9, 16, 0);                      // 별 객체 : 시작위치 = (9,16)
					cout << "===== 별먹기 게임을 시작합니다. =====" << endl << endl;

					for (int i = 0; i < 10; i++) {            // 격자판 초기화
						for (int j = 0; j < 20; j++)
							board[i][j] = "□";
					}
					board[star.getX()][star.getY()] = star.Shape();  // 별 객체의 좌표에 해당하는 격자판 위치에 별 위치 표시

					while (true) {
						board[player.getX()][player.getY()] = player.Shape();         // 휴먼 객체의 좌표에 해당하는 격자판 위치에 휴먼객체 표시
						board[monster.getX()][monster.getY()] = monster.Shape();      // 몬스터 객체의 좌표에 해당하는 격자판 위치에 몬스터객체 표시

						for (int i = 0; i < 10; i++) {                                // 격자판 출력. 휴먼, 몬스터, 별도 나옴
							cout << endl;
							for (int j = 0; j < 20; j++)
								cout << board[i][j];
						}

						board[player.getX()][player.getY()] = "□";                   // 휴먼 객체가 이동하기 전의 자리를 빈 격자판으로 만들기
						board[monster.getX()][monster.getY()] = "□";                 // 몬스터 객체가 이동하기 전의 자리를 빈 격자판으로 만들기

						player.move();                                                // 휴먼 객체 이동
						monster.move();                                               // 몬스터 객체 이동

						if (player.collision(monster)) {                              // 휴먼과 몬스터의 충돌 !! 휴먼의 패배로 끝난다
							board[monster.getX()][monster.getY()] = monster.Shape();    
							for (int i = 0; i < 10; i++) {
								cout << endl;
								for (int j = 0; j < 20; j++)
									cout << board[i][j];
							}
							cout << "\n\n몬스터에게 먹혔습니다 !!" << endl;
							cout << "당신의 패배입니다." << endl;
							break;
						}
						else if (player.collision(star)) {                            // 휴먼과 별의 충돌 !! 휴먼의 승리로 끝난다          
							board[player.getX()][player.getY()] = player.Shape();
							board[monster.getX()][monster.getY()] = monster.Shape();
							for (int i = 0; i < 10; i++) {
								cout << endl;
								for (int j = 0; j < 20; j++)
									cout << board[i][j];
							}
							cout << "\n\n별을 먹었습니다 !!" << endl;
							cout << "당신의 승리입니다." << endl;
							break;
						}
						else if (monster.collision(star)) {                           // 몬스터와 별의 충돌 !! 몬스터의 승리로 끝난다
							board[player.getX()][player.getY()] = player.Shape();
							board[monster.getX()][monster.getY()] = monster.Shape();
							for (int i = 0; i < 10; i++) {
								cout << endl;
								for (int j = 0; j < 20; j++)
									cout << board[i][j];
							}
							cout << "\n\n몬스터가 별을 먹었습니다 !!" << endl;
							cout << "당신의 패배입니다." << endl;
							break;
						}
					}
					break;
				}
				case 5: {    // 흑과 백 게임
					cout << "===== 흑과 백 게임을 시작합니다. =====" << endl << endl;
					BlackWhite P1, P2;          // 흑과 백 게임을 진행할 P1,P2객체 생성
					int p1_num, p2_num;
					int round = 1, p1_count = 0, p2_count = 0;  // count변수는 승점을 의미
					P1.show_rule();
					cout << "======================================" << endl << endl;

					while (true) {
						cout << "<< (" << round << ") Round >> " << endl << endl;
						cout << ":: 현재 승점 :: 1P >> " << p1_count << " : 2P >> " << p2_count << endl << endl;
						cout << ":: 현재 플레이어 덱 ::" << endl;
						cout << "1P ";
						P1.show_deck();       // 각 플레이어의 카드 제시 이전 1P의 덱 상황 
						cout << "2P ";
						P2.show_deck();       // 각 플레이어의 카드 제시 이전 2P의 덱 상황 

						if (round % 2 == 1) {  // 홀수 라운드라면 -> 선플레이어 = 1P
							cout << "\n1P >> ";
							p1_num = P1.submit_card();        // 선 플레이어의 카드 제시
							cout << " >> 1P가 ";
							P1.describe_number(p1_num);       // 선 플레이어가 제시한 카드의 색 출력
							cout << "\n:: 현재 플레이어 덱 ::" << endl;
							cout << "1P ";
							P1.show_deck();         // 선 플레이어의 카드 제시 이후 1P의 덱 상황
							cout << "2P ";
							P2.show_deck();         // 선 플레이어의 카드 제시 이후 2P의 덱 상황
							cout << "\n2P >> ";
							p2_num = P2.submit_card();        // 후 플레이어의 카드 제시
							cout << " >> 2P가 ";
							P2.describe_number(p2_num);       // 후 플레이어가 제시한 카드의 색 출력
						}
						else {                 // 짝수 라운드라면 -> 선플레이어 = 2P
							cout << "\n2P >> ";
							p2_num = P2.submit_card();        // 선 플레이어의 카드 제시
							cout << " >> 2P가 ";
							P2.describe_number(p2_num);       // 선 플레이어가 제시한 카드의 색 출력
							cout << "\n:: 현재 플레이어 덱 ::" << endl;
							cout << "1P ";
							P1.show_deck();        // 선 플레이어의 카드 제시 이후 1P의 덱 상황
							cout << "2P ";
							P2.show_deck();        // 선 플레이어의 카드 제시 이후 2P의 덱 상황
							cout << "\n1P >> ";
							p1_num = P1.submit_card();       // 후 플레이어의 카드 제시
							cout << " >> 1P가 ";
							P1.describe_number(p1_num);      // 후 플레이어가 제시한 카드의 색 출력
						}

						if (p1_num == p2_num)     // 1P가 제시한 숫자 = 2P가 제시한 숫자 -> 무승부로 해당 라운드 종료
							cout << "\n비겼습니다." << endl;
						else if (p1_num > p2_num) {   // 1P가 제시한 숫자 > 2P가 제시한 숫자 -> 1P의 승리로 해당 라운드 종료
							cout << "\n1P가 이겼습니다." << endl;
							p1_count++;
						}
						else {                        // 1P가 제시한 숫자 < 2P가 제시한 숫자 -> 2P의 승리로 해당 라운드 종료
							cout << "\n2P가 이겼습니다." << endl;
							p2_count++;
						}
						cout << "======================================" << endl << endl;

						if (p1_count == 5) {          // 1P가 먼저 승점5점 달성 -> 1P의 승리
							cout << "1P가 먼저 승점 5점을 획득하여 1P의 승리로 끝납니다." << endl;
							break;
						}
						if (p2_count == 5) {          // 2P가 먼저 승점5점 달성 -> 2P의 승리
							cout << "2P가 먼저 승점 5점을 획득하여 2P의 승리로 끝납니다." << endl;
							break;
						}
						if (round == 9) {             // 9라운드까지 진행됨 -> 승점이 더 많은 플레이어 승리
							cout << "게임을 종료합니다. ";
							if (p1_count == p2_count)
								cout << "두 플레이어의 승점이 같습니다. 무승부입니다." << endl;
							else if (p1_count > p2_count)
								cout << p1_count << " : " << p2_count << "로 승점이 더 많은 1P의 승리입니다.";
							else
								cout << p1_count << " : " << p2_count << "로 승점이 더 많은 2P의 승리입니다.";
							break;
						}
						round++;
					}
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