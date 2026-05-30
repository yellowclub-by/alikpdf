
#include <iostream>
#include <cstring> //чтобы работать с char
#include <string>// чтобы работать со строками
#include <thread> 
#include <chrono> 
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	bool doorOpened = false;
	bool powerOn = false;
	bool engineStarted = false;
	bool z = true;
	string x;
	this_thread::sleep_for(std::chrono::seconds(2));
	cout << "ты очнулся на повреждённом космическом корабле." << endl << "Чтобы выбраться, тебе нужно выполнить три обязательных действия" << endl << "Открыть дверь" << endl << "Включить энергии" << endl << "Запустить двигатель" << endl << "Но порядок действий важен!" << endl << "Если ты ввидешь неправильный шаг то умрешь" << endl;
	this_thread::sleep_for(std::chrono::seconds(10));
	cout << " " << endl << "Открыть дверь - open" << endl << "Включить энергию - power" << endl << "Запустить двигатель - engine" << endl;
	for (int i = 1; i <= 3; i++) {
		cin >> x;
		this_thread::sleep_for(std::chrono::seconds(1));
		if (i == 1) {
			if (x == "open") {
				cout << "дверь открыта" << endl;
			}
			else {
				cout << "ты умер";
			}
		}
		if (i == 2) {
			if (x == "power") {
				cout << "енергия есть" << endl;
			}
			else {
				cout << "ты умер" << endl;
			}
		}
		if (i == 3) {
			if (x == "engine") {
				cout << "двигатели включены" << "ура ты выжел и прилетел дмой твой штраф за самостоятельную починку и использование сломаной апаратуры компании JC Jenson состовляет" << endl <<"загрузка" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 ливанских фунтов";
			}
			else {
				cout << "ты умер";
			}
		}
	}

}
