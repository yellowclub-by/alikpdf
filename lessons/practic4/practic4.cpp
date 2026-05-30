#include <iostream>
#include <thread> 
#include <chrono> 
#include <cstring>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	//int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		cout << a[i][j];
	//	}
	//}

	//int a[3][4];
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		cin >> a[i][j];
	//	}
	//}
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		cout << a[i][j];
	//	}
	//}
	//int a[3][3] = {1,2,3,4,5,6,7,8,9};
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		a[i][j] = i*j;
	//		cout << i * j;
	//	}
	//	cout << endl;
	//}
	int n;
	int m;
	int a[100][100];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		int cum = 0;
		for (int j = 0; j < m; j++) {
			cum += a[i][j];
		}
		cout << cum << endl;
	}
}
