#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Func {      //�Լ��� ����ƽ ����� ���� �����Լ�ó�� ���� �κ�
public:
	static void random_set(int arr[], int size, int max);
	static void arr_set(int arr[], int size, int wordnumber);
};

void Func::random_set(int arr[], int size, int max) {        //�迭�� �� ��ҵ��� �����ϰ� ���� ���� �������ִ� �Լ�
	srand((unsigned)time(0));
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

void Func::arr_set(int arr[], int size, int wordnumber) {  //�迭�� �� ��� �� ����ڰ� ���ϴ� ���� ���ٸ�, �迭�� �� ��� �� �ϳ��� ����ڰ� ���ϴ� ������ �ٲ���.
	int count = 0;
	srand((unsigned)time(0));
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

class contact_address {                             //����ó Ŭ����
	map<string, string> address;                        // map �����̳ʸ� ���������
public:
	map<string, string>::iterator it;   
	contact_address();                                  // ������ �Լ�
	void add_address(string key, string value);         // ����ó �߰�
	void delete_address(string key);                    // ����ó ����
	void show_address();                                // ����ó ��ȸ
};

contact_address::contact_address() {
	address.insert(make_pair("��ο�", "010-1236-9545"));    //�⺻������ ���� 3���� ����ó ����
	address.insert(make_pair("�����", "010-3618-8756"));
	address.insert(make_pair("����ȯ", "010-9872-9436"));
	it = address.begin();
}

void contact_address::add_address(string key, string value) {      // ����ó�� �߰��ϴ� �Լ� : map�����̳ʿ� �߰�
	if (address.find(key) == address.end()) {
		cout << key << "��(��) ����ó�� ����մϴ�" << endl;
		address.insert(make_pair(key, value));
	}
	else
		cout << "�̹� " << key << "��(��) ����ó�� ��ϵǾ� �ֽ��ϴ�" << endl;
}

void contact_address::delete_address(string key) {                 // ����ó�� �����ϴ� �Լ� : map�����̳ʿ��� ����
	if (address.find(key) == address.end())
		cout << "�̹� ����ó�� " << key << "�� �����ϴ�" << endl;
	else {
		cout << key << "(" << address[key] << ")" << "��(��) ����ó���� �����մϴ�" << endl;
		address.erase(key);
	}
}

void contact_address::show_address() {                             // ����ó�� ��ȸ�ϴ� �Լ� 
	it = address.begin();
	cout << "���� ����ó�� " << address.size() << "���� ��ȣ�� �ֽ��ϴ�." << endl << endl;
	if (address.size() > 0) {
		cout << "\t<<���>>" << endl;
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
		gbb[0] = "����", gbb[1] = "����", gbb[2] = "��";
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
		cout << "������ ���ðڽ��ϱ�? : ";
		cin >> word;
		if (word == "����" || word == "����" || word == "��")
			break;
		else
			cout << "�߸��� �ܾ��Դϴ�. �ٽ� ������ �ϼ���." << endl;
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
		cout << "EASY ���̵��� ������ �����մϴ�. ���� 0�� 99���̿� �ֽ��ϴ�. " << endl << endl;
	else if (level == 2)
		cout << "NORMAL ���̵��� ������ �����մϴ�. ���� 0�� 99���̿� �ֽ��ϴ�. " << endl << endl;
	else
		cout << "HARD ���̵��� ������ �����մϴ�. ���� 0�� 99���̿� �ֽ��ϴ�. " << endl << endl;

	int number;
	int count = 0;
	while (count < 6 - level) {
		cout << "(" << count + 1 << ") Round" << "\t(" << count+1 << "/" << 6 - level << ")" << endl;
		cout << " >> ";
		cin >> number;
		if (number < 0 || 99 < number) {
			cout << " >> ���� 0�� 99�����Դϴ�. �ٽ� �Է��ϼ���." << endl << endl;
			continue;
		}
		if (number == value) {
			cout << "���߼̽��ϴ�!! ���ϵ帳�ϴ�!" << endl << endl;
			break;
		}
		if (number > value)
			cout << " >> DOWN" << endl << endl;
		else
			cout << " >> UP" << endl << endl;
		if (count == 6 - level - 1)
			cout << "�ƽ����ϴ�. ������ " << value << "�����ϴ�." << endl << endl;
		count++;
	}
}

class guess_word {
	map<string, string> Engdic;                      // Ű, �� ��� string������ �޴� map�����̳ʸ� ��� ������ ����
public:
	map<string, string>::iterator it;                // map �����̳��� iterator�� ��� ������ ����
	guess_word();
	void set_iterator(int n);                        // iterator�� � ���� ����Ű�� �� ���� ����
	int get_wordcount() { return Engdic.size(); }    // map�����̳��� ������ ��ȯ
};

guess_word::guess_word() {
	Engdic.insert(make_pair("love", "���"));    //�⺻������ ���� 20�� �ܾ� ����
	Engdic.insert(make_pair("chair", "����"));
	Engdic.insert(make_pair("desk", "å��"));
	Engdic.insert(make_pair("window", "â��"));
	Engdic.insert(make_pair("baby", "�Ʊ�"));
	Engdic.insert(make_pair("food", "����"));
	Engdic.insert(make_pair("road", "����"));
	Engdic.insert(make_pair("pig", "����"));
	Engdic.insert(make_pair("picture", "����"));
	Engdic.insert(make_pair("apple", "���"));
	Engdic.insert(make_pair("grape", "����"));
	Engdic.insert(make_pair("friend", "ģ��"));
	Engdic.insert(make_pair("bomb", "��ź"));
	Engdic.insert(make_pair("building", "�ǹ�"));
	Engdic.insert(make_pair("earth", "����"));
	Engdic.insert(make_pair("straw", "����"));
	Engdic.insert(make_pair("tree", "����"));
	Engdic.insert(make_pair("boy", "����"));
	Engdic.insert(make_pair("girl", "����"));
	Engdic.insert(make_pair("glass", "����"));
	it = Engdic.begin();
}

void guess_word::set_iterator(int n) {                     // iterator�� Ư�� �༮�� ����Ű�� �����ϱ�
	it = Engdic.begin();
	if (0 < n && n < Engdic.size()) {
		for (int i = 0; i < n; i++)
			it++;
	}
}

class BlackWhite {
	vector<int> deck;
public:
	vector<int>::iterator it;
	BlackWhite();
	void show_rule();
	void show_deck();
	int submit_card();
	void describe_number(int num);
};

BlackWhite::BlackWhite() {
	deck = { 0,1,2,3,4,5,6,7,8 };
}

void BlackWhite::show_rule() {
	string line;
	ifstream fin("Rule.txt", ios::in);
	while (getline(fin, line)) {
		cout << line << endl;
	}
	fin.close();
}

void BlackWhite::show_deck() {
	int black = 0, white = 0;
	for (int i = 0; i < deck.size(); i++) {
		if (deck[i] % 2 == 0)
			black++;
		else
			white++;
	}

	cout << "Deck : ";;
	for (int i = 0; i < black; i++)
		cout << "��";
	for (int i = 0; i < white; i++)
		cout << "��";
	cout << endl;
}

int BlackWhite::submit_card() {
	int number;
	int a = 1;
	it = deck.begin();

	while (true) {
		cout << "������ ���ڸ� ����ֽʽÿ� : ";
		cin >> number;
		for (int i = 0; i < deck.size(); i++) {
			if (deck[i] == number) {
				for (int j = 0; j < i; j++) {
					it++;
				}
				a = 0;
				break;
			}
		}
		if (a == 0)
			break;
		cout << "�߸� �Է��ϼ̽��ϴ�. " << endl;
	}

	it = deck.erase(it);
	return number;
}

void BlackWhite::describe_number(int num) {
	if (num % 2 == 1)
		cout << "���ī��(��)�� �½��ϴ�." << endl;
	else
		cout << "����ī��(��)�� �½��ϴ�." << endl;
}

int main() {
	int menu;
	contact_address A;

	while (true) {
		cout << "==========[ M E N U ] ==========" << endl;
		cout << "(1) >> ����ó �����ϱ�" << endl;
		cout << "(2) >> �����ϱ�" << endl;
		cout << "\t*(�ٸ� Ű : ���α׷��� ����)" << endl;
		cout << "================================" << endl;
		cout << "����Ͻ� ����� ����ּ��� : ";
		cin >> menu;
		cout << "================================" << endl << endl;

		switch (menu) {
		case 1: {
			int num1, x;
			x = 1;
			while (x) {          
				cout << "==========[ �� �� ó ] ==========" << endl;
				cout << "(1) >> ����ó �߰��ϱ�" << endl;
				cout << "(2) >> ����ó �����ϱ�" << endl;
				cout << "(3) >> ����ó ��ȸ�ϱ�" << endl;
				cout << "\t*(�ٸ� Ű : �޴��� ���ư���)" << endl;
				cout << "=================================" << endl;
				cout << "����Ͻ� ����� ����ּ��� : ";
				cin >> num1;
				cout << "=================================" << endl << endl;

				switch (num1) {          //����ڰ� �Է��� num���� ���� �Ʒ� switch�� ����
				case 1: {                //�ܾ� �߰��ϱ�
					string key, value;
					cout << "����ó�� �߰��� ����� �̸��� �Է����ּ��� :";
					cin >> key;
					cout << "�� ����� ��ȣ�� �Է����ּ��� : ";
					cin >> value;
					A.add_address(key, value);
					cout << endl;
					break;
				}
				case 2: {                //�ܾ� �����ϱ�
					string key;
					cout << "����ó���� ������ ����� �̸��� �Է����ּ��� : ";
					cin >> key;
					A.delete_address(key);
					cout << endl;
					break;
				}
				case 3: {               //�ܾ� �˻��ϱ�
					A.show_address();
					cout << endl;
					break;
				}
				default: {
					cout << "�޴��� ���ư��ϴ�." << endl;
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
				cout << "(1) >> ���������� �����ϱ�" << endl;
				cout << "(2) >> Up & Down �����ϱ�" << endl;
				cout << "(3) >> ���ܾ� �� ���߱� �����ϱ�" << endl;
				cout << "(4) >> ���Ա� �����ϱ�" << endl;
				cout << "(5) >> ��� ��(2p) �����ϱ�" << endl;
				cout << "\t*(�ٸ� Ű : �޴��� ���ư���)" << endl;
				cout << "=================================" << endl;
				cout << "�÷����� ������ ����ּ��� : ";
				cin >> num2;
				cout << "=================================" << endl << endl;

				switch (num2) {
				case 1: {
					GBBplayer player;
					GBBcom com;
					cout << "===== ���������� ������ �����մϴ�. 5������� ����˴ϴ�. =====" << endl << endl;
					for (int i = 1; i <= 5; i++) {
						cout << "(" << i << ") " << "Round >>" << endl;
						string players = player.turn();
						string coms = com.turn();
						cout << "��ǻ�Ͱ� �� �� : " << coms << endl;
						if (players == coms)
							cout << "���º��Դϴ�." << endl << endl;
						else if (players == "����") {
							if (coms == "����")
								cout << "�й��߽��ϴ�." << endl << endl;
							else
								cout << "�¸��߽��ϴ�." << endl << endl;
						}
						else if (players == "����") {
							if (coms == "��")
								cout << "�й��߽��ϴ�." << endl << endl;
							else
								cout << "�¸��߽��ϴ�." << endl << endl;
						}
						else if (players == "��") {
							if (coms == "����")
								cout << "�й��߽��ϴ�." << endl << endl;
							else
								cout << "�¸��߽��ϴ�." << endl << endl;
						}
					}
					break;
				}
				case 2: {
					int game_level;
					cout << "===== Up & Down ������ �����մϴ�. =====" << endl << endl;
					cout << "(1) >> �ڡڡ١١� EASY " << endl;
					cout << "(2) >> �ڡڡڡ١� NORMAL" << endl;
					cout << "(3) >> �ڡڡڡڡ� HARD" << endl;
					cout << "========================================" << endl;

					while (true) {
						cout << ">> ���̵��� ����ּ��� : ";
						cin >> game_level;
						if (0 < game_level && game_level < 4)
							break;
						cout << "\t�߸� �Է��ϼ̽��ϴ�." << endl <<endl;
					}
					cout << "========================================" << endl << endl;
					UPandDOWN game(game_level);
					game.playgame();
					break;
				}
				case 3: {
					guess_word dic;
					int word[5];
					int option[4];
					int answer;
					map<string, string>::iterator A;  //������ӿ��� ���信 �ش��ϴ� ���� ����Ŵ
					map<string, string>::iterator p[4];  //������ӿ��� ���� 4���� ���⿡ �ش��ϴ� ���� ����Ŵ

					cout << "===== ���ܾ� �� ���߱� ������ �����մϴ�. =====" << endl << endl;
					Func::random_set(word, 5, dic.get_wordcount());  //����� �� 5���� �ܾ ����(��������)
					for (int i = 0; i < 5; i++) {
						dic.set_iterator(word[i]);
						A = dic.it;              //�̸� ���� while ������ ����� A�� map�����̳ʿ��� ������ ���� ����Ű�� �ȴ� 
						cout << "(" << i + 1 << ") Round >> '" << A->first << "'" << endl;
						Func::random_set(option, 4, dic.get_wordcount());    //����� �־��� 4���� �ܾ� ����
						Func::arr_set(option, 4, word[i]);                   //���⿡ ������ �ܾ ������ ����
						for (int j = 0; j < 4; j++) {
							dic.set_iterator(option[j]);
							p[j] = dic.it;                  // �̸� ���� while ������ ����� p���� map�����̳ʿ��� ���⿡ �ش��ϴ� ������ ����Ű�� ��
						}
						cout << "(1) " << p[0]->second << "\t(2) " << p[1]->second << "\t(3) " << p[2]->second << "\t(4) " << p[3]->second << "\n" << endl;
						cout << "������ �Է��ϼ���. (���⿡ ���� ���ڸ� ������ �������� �����մϴ�) : ";
						cin >> answer;
						if (answer > 0 && answer < 5) {
							if (p[answer - 1]->second == A->second)
								cout << "����!" << "\n" << endl;
							else
								cout << "����!" << "\n" << endl;
						}
						else
							cout << "����!" << "\n" << endl;
					}
					break;
				}
				case 4: {
					break;
				}
				case 5: {
					cout << "===== ��� �� ������ �����մϴ�. =====" << endl << endl;
					BlackWhite P1, P2;
					int p1_num, p2_num;
					int round = 1, p1_count = 0, p2_count = 0;
					P1.show_rule();
					cout << "======================================" << endl << endl;

					while (true) {
						cout << "<< (" << round << ") Round >> " << endl << endl;
						cout << ":: ���� ���� :: 1P >> " << p1_count << " : 2P >> " << p2_count << endl << endl;
						cout << ":: ���� �÷��̾� �� ::" << endl;
						cout << "1P ";
						P1.show_deck();
						cout << "2P ";
						P2.show_deck();

						if (round % 2 == 1) {
							cout << "\n1P >> ";
							p1_num = P1.submit_card();
							cout << " >> 1P�� ";
							P1.describe_number(p1_num);
							cout << "\n:: ���� �÷��̾� �� ::" << endl;
							cout << "1P ";
							P1.show_deck();
							cout << "2P ";
							P2.show_deck();
							cout << "\n2P >> ";
							p2_num = P2.submit_card();
							cout << " >> 2P�� ";
							P2.describe_number(p2_num);
						}
						else {
							cout << "\n2P >> ";
							p2_num = P2.submit_card();
							cout << " >> 2P�� ";
							P2.describe_number(p2_num);
							cout << "\n:: ���� �÷��̾� �� ::" << endl;
							cout << "1P ";
							P1.show_deck();
							cout << "2P ";
							P2.show_deck();
							cout << "\n1P >> ";
							p1_num = P1.submit_card();
							cout << " >> 1P�� ";
							P1.describe_number(p1_num);
						}

						if (p1_num == p2_num) 
							cout << "\n�����ϴ�." << endl;
						else if (p1_num > p2_num) {
							cout << "\n1P�� �̰���ϴ�." << endl;
							p1_count++;
						}
						else {
							cout << "\n2P�� �̰���ϴ�." << endl;
							p2_count++;
						}
						cout << "======================================" << endl << endl;

						if (p1_count == 5) {
							cout << "1P�� ���� ���� 5���� ȹ���Ͽ� 1P�� �¸��� �����ϴ�." << endl;
							break;
						}
						if (p2_count == 5) {
							cout << "2P�� ���� ���� 5���� ȹ���Ͽ� 2P�� �¸��� �����ϴ�." << endl;
							break;
						}
						if (round == 9) {
							cout << "������ �����մϴ�. ";
							if (p1_count == p2_count)
								cout << "�� �÷��̾��� ������ �����ϴ�. ���º��Դϴ�." << endl;
							else if (p1_count > p2_count)
								cout << p1_count << " : " << p2_count << "�� ������ �� ���� 1P�� �¸��Դϴ�.";
							else
								cout << p1_count << " : " << p2_count << "�� ������ �� ���� 2P�� �¸��Դϴ�.";
							break;
						}
						round++;
					}
					break;
				}
				default: {
					cout << "�޴��� ���ư��ϴ�." << endl;
					y = 0;
					break;
				}
				}
				cout << endl;
			}
			break;
		}
		default: {
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		}
		}
	}
}