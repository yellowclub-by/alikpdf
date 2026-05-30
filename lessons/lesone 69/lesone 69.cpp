
#include <iostream>

using namespace std;

//void countOut(int count) {
//	if (count == 0) {
//		return;
//	}
//	cout << "push" << count << endl;
//	countOut(count - 1);
//	cout << "pop" << count << endl;
//}
//void cum(int x) {
//	if (x == 0) return;
//	cout << x << " ";
//	cum(x - 1);
//	cout << x << " ";
//}
//int fuck(int x) {
//	if (x == 0 || x == 1) {
//		return 1;
//	}
//	return x * fuck(x - 1);
//
//}
int cum(int x) {
	if (x == 0) {
		return x;
	}
	x += cum(x - 1);
}

int main()
{
	//рекурсия функия вызывает сому себя но она должна знать когда ей нужно остановится 
	// состоит из двух чистей базавый случий когда мы останавиливаемся и рекурсивный шаг когда вызов себя с боле простой задачий 
	// нет базавового случия = ошибка бесконечная 
	//cout << fuck(5) << endl; 
	cout << cum(6);

	return 0;
}
