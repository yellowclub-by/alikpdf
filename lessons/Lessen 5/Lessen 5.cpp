
#include <cstring> //чтобы работать с char
#include <string>// чтобы работать со строками
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	// цыкл многограно выполнить блок ганджюаса по условию
	// While for do while
	//while (true){
	//	cout << "aaaa";
	//}

//	int n;
//	int x = 1;
//	int y = 0;
//	cin >> n;
//	while (x <= n){
//		y += x;
//		x += 1;
//	}
//	cout << y << endl;

	//int x= 0;
	//int z;
	//cin >> z;
	//while (z >= 1) {
	//	z /= 10;
	//	x += 1;
	//}
	//cout << x;

	//string x;
	//int i = 0;
	//int z;
	//cin >> x;
	//int x2 = stoi(x);
	//while (x2 >= 1) {
	//	z = (x.substr(0) == x.substr(-1));
	//	x2 /= 10;
	//	if (z == 1){
	//		i + z;
	//		z = 0;
	//	}
	//}
	//if (i == sizeof(x)) {
	//	cout << "число палидром";
	//}
	//else {
	//	cout << "что за , почему он синий?";
	//}

	//for (int i = 1; i < 10; i++) {
	//	cout << i * i << endl;
	//}

	//for (int i = 2; i <+ 20; i++) {
	//	if (i % 2 == 0) {
	//		cout << i;
	//	}
	//}

	//for (int i = 1; i < 10; i++) {
	//	cout << 5 * i;
	//}

	//int x;
	//int y;
	//int z = 0;
	//cin >> x;
	//cin >> y;
	//for (int i = x; i <= y; i++) {
	//	if (i % 2 != 0) {
	//		z += i;
	//	}
	//}
	//cout << z;

	//for (char c : "Hello")
	//{
	//	cout << c << endl;
	//}

	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 10; j++)
	//	{
	//		cout << " + ";
	//	}
	//	cout << "\n";
	//}
	//int n;
	//cin >> n;
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= i; j++) {
	//		cout << " * ";
	//	}
	//	cout << endl;
	//}

	//int n;
	//cin >> n;
	//for (int i = 1; i <= n; i++) {
	//	for (int c = n; c > i; c--) {
	//		cout << " ";
	//	}
	//	for (int j = 1; j <= i; j++) {
	//		cout << " *";
	//	}
	//	cout << endl;
	//}

	//for (int i = 1; i <= 5; i++) {
	//	for (int j = 1; j <= 5; j++) {
	//		cout <<" " <<  i * j;
	//	}
	//	cout << endl;
	//}
	// do while сначала код а потом ток проверка и пока тру то тру тру тру тру тру тру тру тру тру тру тру тру тру тру тру 
	//int i = 10;
	//do
	//{
	//	cout << i << endl;
	//	i--;
	//} while (i > 0);
	//cout << "алах агбар";
	
	//int x;
	//cin >> x;
	//do {
	//	if (x == 0) {
	//		cout << "програма завершон";
	//	}
	//	else { cout << x; }
	//	return 0;
	//} while (x != 0);

	// операторы  continue  и  break 
	// break - выйти из цикла полносьб 
	// continue - перейти к следуйщей интерации, пропустить текушую.
	
//int result = 0;
//for (int i = 1; i < 10; i++) {
//	result += i;
//	cout << result << endl;
//	if (result > 20) {
//		break;
//	}

//int x;
//for (int i = 1; i <= 10; i++) {
//	cin >> x;
//	if (x < 0) {
//		cout << x;
//		break;
//	}
//	if (i == 10) {
//		cout << " халяль";
//	}
//}

//int result = 0;
//for (int i = 1; i < 10; i++) {
//	if (i % 2==0) {
//		continue;
//	}
//	result += i;
//}
//cout << result << endl;

//for (int i = 1; i < 20; i++) {
//	if (i % 2!=0) {
//		continue;
//	}
//	cout << i << endl;
//};
int z;
int x;
int y;
while (true){
	cout << " муну" << endl << " 1+" << endl << " 2-" << endl << " 3/" << endl << "4*" << endl << " 5^" << endl << " 6^1/2" << endl << " 0 - выход" << endl;
	cin >> z;
	if (z == 0) {
		break;
	}
	else if(z == 6) {
		cin >> x;
		cout << sqrt(x) << endl;
	}
	else if (z == 67) {
		cout << "ХАЛЯЛЬ!!!!!!!!!!!!!!!!!!" << endl;
	}
	else {
		cin >> x;
		cin >> y;
		if (z == 1) {
			cout << x + y << endl;
			}
		else if (z == 2) {
			cout << x - y << endl;
		}
		else if (z == 3) {
			cout << x / y << endl;
		}
		else if (z == 4) {
			cout << x * y << endl;
		}
		else if (z == 5) {
			cout << pow(x, y) << endl;
		}
	}
}
}