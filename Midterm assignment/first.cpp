#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

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
		cout << key << "(" << address[key] << ")" << "��(��) �������� �����մϴ�" << endl;
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
				cout << "(3) >> ��� ��(2p) �����ϱ�" << endl;
				cout << "\t*(�ٸ� Ű : �޴��� ���ư���)" << endl;
				cout << "=================================" << endl;
				cout << "�÷����� ������ ����ּ��� : ";
				cin >> num2;
				cout << "=================================" << endl << endl;

				switch (num2) {
				case 1: {
					break;
				}
				case 2: {
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