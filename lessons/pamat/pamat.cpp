#include <iostream>
#include <thread> 
#include <chrono> 
#include <cstring>
#include <string>
#include <bit>
#include <vector>


using namespace std;
void text(string t, int x) {
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i <= t.size(); i++) {
        char d = t[i];
        cout << d;
        this_thread::sleep_for(chrono::milliseconds(x));
    }
}
//void foo(int *pa) {
//    (*pa)++;
//}
//void foo1(int* pa, int *px, int *pb) {
//    (*pa)++;
//    (*px) = 69;
//    (*pb) = -42;
//}
//void swap(int* pa, int* pb) {
//    int b = (*pa);
//    (*pa) = (*pb);
//    (*pb) = b;
//}
int main()
{
    system("color a");
    // озу делится на 2 облости на стек и куча 
    // стек облость озу для хронения временый даных
    // куча все програмы которые работают включая операционая система
    // стек это способ организовать даные для удобного использования 
    // стеке мы можем посмотреть и вытенуть верхний элемент и положить новый поверх старого
    // стек это структура даныйх по типу последний пришол первый ушол LIFO (last in first out)
    // стек памяти это облость памяти которая програма исползует для: вызов функции, хронения локальных переменых, хоронения пораметров функции, что возврашяет после выполенения фунции
    // статическая это даные с зарание извесным размером во время работы програмы эти даные не иззменяются освобождается тоже сома
    // динамическя память выделяется во время работы и находится в области памяти 
    // чтобы работать с этой памяти указатели индекса и показывает где лежат даные 
    // здесь прописываем вручную где и как выделется память 
    // указатель цире это переменая которая содежит адрес другой переменый
    //int a = 5;
    //int* px = &a;
    //// тип указателя должен совподать с типом даных на котый он отсылается
    //cout << px << endl;
    //cout << *px << endl; //  разименование 
    //int* px2 = &a;
    //cout << px2 << endl;
    //*px2 = 2;
    //cout << a << endl;
    // двух стороня связб
    //int x = 3;
    //int*p = &x;
    //*p = 10;
    //cout << x << endl;
    //cout << *p << endl;
    //  указатели позволяют соеденять разные части памяти через одну часть помяти
    //int a = 3;
    //int b = 6;
    //int* p = &a;
    //*p = 10;
    //p = &b;
    //*p = 20;
    //cout << a << endl << b;
    /*int a[5] = { 10,3,4,1,3};*/
    //for (int i = 0; i < 5; i++) {
    //    cout << a[i] << " ";
    //}
    //cout << endl;
     // имя мосива это указатель первого элемента вашего мосива;

    /*cout << "____________________________________________________________"<< endl;*/
    //int*pa = a;
    //for (int i = 0; i < 5; i++) {
    //    cout << pa[i] << endl;
    //}
    //cout << a << endl;
    //cout << pa << endl;
    //int a = 0;
    //cout << a << endl;
    //foo(&a);
    //cout << a;
    //int a = 0,x = 1, b =5;
    //foo1(&a, &x, &b);
    //cout << a << " " << x << " " << b;
    //text("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 10);

    //int a = 10;
    //int b = 5;
    //swap(a,b);
    //cout << a << " " << b << endl;
    //text("-------------------------------------", 20);
    //cout << endl;
    //int c[5] = { 1,2,3,4,5 };
    //int* pa = c;
    //cout << *pa;
    //while (true) {
    //    cout << "a";
    //    this_thread::sleep_for(chrono::milliseconds(10));
    //}

  /*  int size = 5;
    int *a = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < size; j++) {
        cout << a[j];
    }*/

    //int size;

    //int newsize = 5;

    //cin >> size;

    //int* a = new int[size];
    //for (int i = 0; i < size; i++) {
    //    cin >> a[i];
    //}

    //int* newa = new int[newsize];
    //for (int i = 0; i < newsize; i++) {
    //    newa[i] = a[i];
    //}

    //delete[]a;

    //for (int i = size; i < newsize; i++) {
    //    cin >> newa[i];
    //}

    //for (int j = 0; j < newsize; j++) {
    //    cout << newa[j] << " ";
    //}
    //delete[]newa;
    

    //int size;

    //int del;

    //cin >> size;

    //int* a = new int[size];
    //for (int i = 0; i < size; i++) {
    //    cin >> a[i];
    //}

    //cin >> del;

    //int newsize = size-1;

    //int* newa = new int[newsize];

    //for (int i = 0; i < newsize; i++) {

    //    if (i <= del-2) {
    //        newa[i] = a[i];
    //    }
    //    else {
    //        newa[i] = a[i+1];
    //    }
    //}

    //delete[]a;

    //for (int i = size; i < newsize; i++) {
    //    cin >> newa[i];
    //}

    //for (int j = 0; j < newsize; j++) {
    //    cout << newa[j] << " ";
    //}
    //delete[]newa;
    
    vector<int> V;
    vector<int> N;
    //V.push_back(10);
    //V.size();
    //V[3];
    //V.pop_back();
    //V.clear();
    //V.push_back(2);
    int z;
    cin >> z;
    for (int i = 0; i < z; i++) {
        int x;
        cin >> x;
        V.push_back(x);
    }
    int num = 0;
    for (int i = 0; i < V.size(); i++) {
        if (V[i] != 0) {
            num = num + 1;
        }
    }
    for (int i = 0; i <= num; i++) {
        if (V[i] != 0) {
            N.push_back(V[i]);
        }
    }
    for (int j = 0; j < N.size(); j++) {
        cout << N[j] << endl;
    }

    return 0;

}

