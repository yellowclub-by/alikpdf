#include <iostream>
#include <thread> 
#include <chrono> 
#include <cstring>
#include <string>
#include <bit>
using namespace std;
void text(string t,int x) {
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i <= t.size(); i++) {
        char d = t[i];
        cout << d;
        this_thread::sleep_for(chrono::milliseconds(x));
    }
}

typedef void (*OpFunc)(unsigned long long& state, unsigned char arg, unsigned char factor);

// 000: Сложение
void op_add(unsigned long long& state, unsigned char arg, unsigned char factor) {
    state += (unsigned long long)arg * (factor ? factor : 1);
}

// 001: Циклический сдвиг вправо
void op_rotate(unsigned long long& state, unsigned char arg, unsigned char factor) {
    int shift = arg % 64;
    state = (state >> shift) | (state << (64 - shift));
}

// 010: XOR инверсия
void op_xor(unsigned long long& state, unsigned char arg, unsigned char factor) {
    state ^= ((unsigned long long)arg * (factor ? factor : 1));
}

// 011: Условный сброс (используем встроенный попкаунт)
void op_reset(unsigned long long& state, unsigned char arg, unsigned char factor) {
    unsigned long long n = state;
    // Магия битовых масок для подсчета единиц
    n = n - ((n >> 1) & 0x5555555555555555ULL);
    n = (n & 0x3333333333333333ULL) + ((n >> 2) & 0x3333333333333333ULL);
    int count = ((((n + (n >> 4)) & 0x0F0F0F0F0F0F0F0FULL) * 0x0101010101010101ULL) >> 56);

    state *= !(count % 2 == 0);
}
// Заглушки для типов 100-111, если они не используются
void op_nop(unsigned long long& state, unsigned char arg, unsigned char factor) {}

// Таблица переходов (Jump Table) — заменяет switch/if
static const OpFunc operations[8] = {
    op_add, op_rotate, op_xor, op_reset,
    op_nop, op_nop, op_nop, op_nop
};

void processSignal(const unsigned int* commands, size_t count, unsigned long long& state) {
    for (size_t i = 0; i < count; ++i) {
        unsigned int cmd = commands[i];

        // Декодирование битов (bit masking)
        unsigned char type = cmd & 0x07;          // Биты 0-2
        unsigned char factor = (cmd >> 3) & 0x1F;   // Биты 3-7
        unsigned char arg = (cmd >> 8) & 0xFF;   // Биты 8-15

        // Вызов функции без ветвления
        operations[type](state, arg, factor);
    }
}

int main()
{
    //system("color 2");
    //setlocale(LC_ALL, "Russian");
    //text("ты умрешь через 10   9   8   7   6   5   4   3   2   1   0",50);
    //cout << endl << "бум" << endl;
    //text("пошутил, я тебе только систем32 снес",80);
 /*   cum(3, 5);*/
  /*  cum3(11, 146);
    cum3(11, 147);*/
    //p("Aaaaaaa",44);
    //p("Aaaaaaaa",45);
    //p("Aaaaaaaaa",46);
    //p("Aaaaaaaaaa",48);
    //ass(5, 5, 5);
    //ass(3, 2, 5);
    //ass(3, 4, 5);
    //ass(3, 5, 5);
    unsigned long long state = 100;
    unsigned int commands[] = { 0x0501, 0x0100 }; // Сдвиг на 5, затем сложение

    processSignal(commands, 2, state);

    std::cout << "Final state: " << state << std::endl;
	return 0;
}
