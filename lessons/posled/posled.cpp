#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
int main()
{
    int x = 1;
    vector<int> posle = {};
    string line;

    if (std::getline(std::cin, line) && !line.empty()) {
        std::stringstream ss(line);
        int number;
        while (ss >> number) {
            posle.push_back(number);
        }
    }
 
    while  (true) {
        if (x == posle[x - 1]) {
            x += 1;
        }
        else {
            cout << x;
            break;
        }
    }
}
