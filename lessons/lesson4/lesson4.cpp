#include <math.h>
#include <iostream>
using namespace std;
int main(){
	setlocale(LC_ALL, "Russian");
	//int x = 1;
	//if (x == 1) {
	//	cout << x;
	//}
	//else {
	//	cout << "your guy";
	//}

	//int x;
	//cin >> x;
	//if (x >= 12) {
	//	cout << "oke";
	//}
	//else {
	//	cout << "no furry";
	//}

	//bool x;
	//cin >> x;
	//if (x == 1) {
	//	cout << "берем зонт";
	//}
	//else {
	//	cout << "не берем";
	//}
	
	//int x;
	//cin >> x;
	//if (x >= 1) {
	//	if (x <= 7) {
	//		cout << "hi N";
	//	}
	//	else {
	//		cout << "блок ганджубаса";
	//	}
	//}
	//else {
	//	cout << "хомлендер любит молочко";
	//}

	//int age;
	//cin >> age;
	//string p;
	//cin >> p;
	//if (age >= 18) {
	//	cout << "без мамочки справишся";
	//}
	//else {
	//	if (p == "да") {
	//		cout << "красаучык";
	//	}
	//	else {
	//		cout << "ни мамы ни папы";
	//	}
	//}

	//int x;
	//cin >> x;
	//if (x > 1) {
	//	cout << "ту ту турурур туруру ру у меня в кармане беспонтовый пираок";
	//}
	//else if (x < 1) {
	//	cout << "асипинские пирага есть?";
	//}
	//else {
	//	cout << "аааааааааааааааааааааа";
	//}

	double x1;
	double y1;
	double x2;
	double y2;
	double x3;
	double y3;
	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;
	cin >> x3;
	cin >> y3;
	
	double x12y12 = sqrt((x1 - x2) * 2 + (y1 - y2) * 2);
	double x23y23 = sqrt((x2 - x3) * 2 + (y2 - y3) * 2);
	double x31y31 = sqrt((x3 - x1) * 2 + (y3 - y1) * 2);
	cout << x12y12 <<endl << x23y23 << endl << x31y31 << endl;
	cout << sqrt(x12y12 * 2 - (x23y23 / 2) * 2) << endl << sqrt(x23y23 * 2 - (x31y31 / 2) * 2) << endl << sqrt(x31y31 * 2 - (x12y12 / 2) * 2) << endl;


	
}
