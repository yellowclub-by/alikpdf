#include <iostream>
#include <random>
#include <thread> 
#include <chrono> 
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	while (true) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distrib(1, 100);
		int x;
		int y = distrib(gen);
		int c;
		int v;
		cout << "угадай число от 1 до 100" << endl << "у тебя 7 попыток" << endl;
		for (int i = 1; i <= 7; i++) {
			cin >> x;
			if (x == y) {
				cout << "[режим сорказма]позравляю, ты выйграл!"<<endl;
				break;
				c = 1;
			}
			else {
				cout << "неа" <<endl;
				c = 0;
			}
		}
		if (c == 0) {
			cout << "запуск програмы удаления system32"<<endl;
			this_thread::sleep_for(std::chrono::seconds(4));
			for (int z = 0; z <= 100; z++) {
				this_thread::sleep_for(std::chrono::nanoseconds(100000));
				cout << z << "%" << endl;
			}
			cout << "system32 успешна удалена >:3" << endl << "хочешь поробывать еще раз?" << endl << "1 - да" << endl << "0 - нет" << endl;
			cin >> y;
			if (y == 1) {
				cout << "усли выйграешь я востановлю system32" << endl;
				continue;
			}
			else {
				cout << "ладно" ;
				this_thread::sleep_for(std::chrono::seconds(2));
				system("shutdown /s /t 0");
				return 0;
			}
		}
	}
}

