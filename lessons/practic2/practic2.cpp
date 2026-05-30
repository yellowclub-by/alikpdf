#include <iostream>
#include <thread> 
#include <chrono> 
#include <cstring>
#include <string>
using namespace std;
char text(string t) {
    for (int i = 1; i <= t.size(); i++) {
        t.resize(i);
        char d = t[i];
        cout << d;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}
int main()
{
	setlocale(LC_ALL, "Russian");
    system("color 0A");

    // масивы даных
    // масив это набор эл в подряд 
    // int a[5]; // масив длина 5
 /*   int a[5] = { 1,2,3,4,5 }; не так не робит
    int b[5] = a[5];*/
 /*   int a[10];
    cout << a[6];*/
    //int c[5] = { 1,2 };
    //cout << c[3]; выводит 0
    //int b[3] = {};
    //cout << b[2]; выводит 0
    //const int num[4] = { 1,2,3,4 };
    //num[1] = 23;нелзя
    //int a[5] = { 1,2,3,4,5 };
    //for (int i = 0; i <= 5; i++) {
    //    cout << a[i] << " ";
    //}
    //int a[5];
    //for (int i = 0; i <= 4; i++) {
    //    cin >> a[i];
    //}
    //cout << sizeof(a[5]);
    //int a[5];
    //int max = 0;
    //for (int i = 0; i <= 4; i++) {
    //    cin >> a[i];
    //}
    //for (int i = 0; i <= 4; i++) {
    //    if (max < a[i]) {
    //        max = a[i];
    //    }
    //}
    //cout << "\033[2J";
    //cout << "\033[H";
    //cout << max;
    // линейный поиск это когда проверяем число по очереди
    //int x;
    //cin >> x;
    //int a[5] = { 1,2,3,4,5 };
    //bool found = false;
    //for (int i = 0; i < 5; i++) {
    //    if (a[i] == x) {
    //        cout << text("нашол на позиции ") << i << endl;
    //        found = true;
    //        break;
    //    }
    //}
    //if (!found) {
    //    cout << text("не найден") << endl;
    //}
   
    cout << text("А я - рыба, я - рыба, я - рыба! Не плачу, не смеюсь, не говорю: Спасибо! А я - рыба, я - рыба, я - рыба! Не хожу на работу не получаю прибыл");;
    //int n = 5;
    //int a[5] = { 1,5,2,4,3 };
    //for (int i = 0; i, n - 1; i++) {
    //    for (int j = 0; j, n - 1 - i; j++) {
    //        if (a[j] > a[j + 1]) {
    //            int tmp = a[j];
    //            a[j] = a[j + 1];
    //            a[j + 1] = tmp;
    //        }
    //    }
    //}
    return 0;
}
