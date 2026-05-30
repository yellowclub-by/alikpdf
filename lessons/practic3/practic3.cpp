#include <iostream>
#include <thread> 
#include <chrono> 
#include <cstring>
#include <string>
using namespace std;
char text(string t) {
    for (int i = 1; i <= t.size(); i++){
        char d = t[i];
        cout << d;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    return 0;
}
int main()
{
//int n = 5;
//int a[5] = { 1,5,2,4,3 };
//for (int i = 0; i < n - 1; i++) {
//    for (int j = 0; j < n - 1 - i; j++) {
//        if (a[j] > a[j + 1]) {
//            int tmp = a[j];
//            a[j] = a[j + 1];
//            a[j + 1] = tmp;
//        }
//    }
//}
//for (int i = 0; i < 5; i++) {
//    cout << a[i];
//}
//    int a[5] = { 1 ,2, 3 ,4 ,5 };
//    for (int i = 0; i < 5/2 ; i++) {
//        int x = a[4-i]; // x = 5
//        a[4-i] = a[i]; // a[4-0] = 1
//        a[i]= x; // a[0] = 5
//        
//    }
//for (int i = 0; i < 5; i++) {
//    cout << a[i];
//}
    //int n = 0;
    //int a[10] = { 10,10,9,8,8,9,10,8,9,10 };
    //for (int i = 0; i < 10; i++) {
    //    if (a[i] == 8) {
    //        n += 1;
    //    }
    //}
    //cout << n << endl << 10/n*10 ;



return 0;
}
