
#include <iostream>
#include <chrono> 
#include <cstring>
#include <string>
#include <random>
#include <bit>
#include <thread> 
using namespace std;

//class Human {
//private:
//	int age;
//
//public:
//	string name;
//
//	void set(int ag) {
//		if (0 < ag || ag <= 5683) {
//			age = ag;
//		}
//		else {
//			cout << "пшол н#%?&" << endl;
//		}
//	}
//
//	int getAge() {
//		return age;
//	}
//};

class Human {
private:
	int halse = 100;
public:
	int vibor;

	void vib(int v) {
		srand(time(0));
		int n = rand() % 1;
		if (v != n) {
			for (int i = 0; i < 100; i++) {
				int x;
				halse -= 1;
				cout << halse << endl;
				this_thread::sleep_for(chrono::milliseconds(500));
				cin >> x;
				if (x == 4) {
					break;
					cout << "я никого не убивал";
				}
				else {
					continue;
				}

			}
		}
		else {
			cout << "твоя взела";
		}
		
	}
};

int main(){
	setlocale(LC_ALL, "Russian");
	// class - совокупность чево либо, шаблон, 

	//class Human {
	//public:int age;
	//	  string name;
	//};
	//Human firstNum;
	//firstNum.age=20;

	//class point {
	//public:int x;
	//	  int y;
	//};

	//point p;
	//p.x = 30;
	//p.y = 10;

	
//	Human t;
//	t.set(5683);
//;	cout << t.getAge() << endl;
	Human a;
	int v;
	cout << "привет, стихи любишь?" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "ладно это не важно, лучше вибери бутыль 0 или 1, одна с ядом другая с водой"<< endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "выбор за тобой" << endl;
	cin >> v;
	a.vib(v);


}
