# include <iostream>
# include <string>
using namespace std;
int food() {
	::cout << "food";
	return 0;
}
int main() {
	setlocale(LC_ALL, "Russian");
	//::cout << "hello,world";
	//::cout << "\nhello world!";
	//food();
	// 
	//string name = "Лиза";
	//cout << name;

	//int age = 17;
	//cout << age;
	//string name = "Alik";
	//int age = 17;
	//cout << "hello, my name " << name << " \nand I'm " << age;

	//cout << "Your name:\n";
	//string name;
	//cin >> name;
	//cout << "Your age:\n";
	//int age;
	//cin >> age;

	//cout << "Your login:\n";
	//string log;
	//cin >> log;
	//cout << "your pass\n";
	//string pass;
	//cin >> pass;

	//cout << "1+1=" << "1-1=" << "1*1=" << "1%1=" << "1/1=";
	//int num = 10;
	//cout << num * 2;

	//double num = 9.5;
	//cout << num / 2 << "\n";

	//double num = 9.8;
	//int x = int(num);
	//cout << x;

	//int num = 42;
	//string x = to_string(num);
	//cout << x;

	//string s = "45";
	//int num = stoi (s);
	//cout << num + 5;

	//string num;
	//cin >> num;
	//int x = stoi(num);
	//cout << x + 10;
	string num;
	cin >> num;
	int x = stoi(num);
	double x2 = double(x);
	string num2;
	cin >> num2;
	int y = stoi(num2);
	double y2 = double(y);
	cout << double(x + y) << " " << x - y << " " << x * y;
	return 0;

}