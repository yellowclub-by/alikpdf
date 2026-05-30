#include <iostream>
#include <thread> 
#include <chrono> 
#include <cstring>
#include <string>
#include <bit>
using namespace std;
//void text(string t, int x) {
//    setlocale(LC_ALL, "Russian");
//    for (int i = 0; i <= t.size(); i++) {
//        char d = t[i];
//        cout << d;
//        this_thread::sleep_for(chrono::milliseconds(x));
//    }
//}

//int cum(int x[100],int n) {
//    int cuum = 0;
//    for (int i = 0; i < n; i++) {
//        cuum += x[i];
//    }
//    return cuum;
//}

//int cum2(int x[100],int n) {
//    int cuum = 0;
//    for (int i = 0; i < n; i++) {
//        cuum += x[i];
//    }
//    int cuum2 = cuum / n;
//    cout << cuum << endl << cuum2;
//    return 0;
//}

//void obr(int n) {
//    if (n == 0) {
//        cout << "start";
//        return;
//    }
//    cout << n << endl;
//    this_thread::sleep_for(chrono::milliseconds(500));
//    obr(n - 1);
//}
void ger(int n) {
    int x;
    if (n == 0) {
        cout << "о нет ты выбрался";
        return;
    }
    
    cout << "осталось" << n <<endl;
    cin >> x;
    ger(n - x);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("color a");
    //text("игра началась",100);
    // 
    //int z[100] = { 10,11,22,11,33 };
    //cout << cum(z, 6);

    //int z[5] = { 1,0,1,0,2 };
    //cum2(z, 5);

    //int a[4][4] = { 1,1,1,0, 1,0,1,0, 0,1,0,0, 0,0,0,0 };
    //int z = 0;
    //int y = 0;
    //for (int i = 0; i < 4; i++) {
    //    int x = 0;
    //    for (int j = 0; j < 4; j++) {
    //        x += a[i][j];
    //    }
    //    if (x > y) {
    //        y = x;
    //        z = i;
    //    }
    //}
    //cout << z + 1;

    /*obr(10);*/
    ger(10);
}
