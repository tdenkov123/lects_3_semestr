#include <iostream>
#include <string>

using namespace std;

int func(string surname, int variants) {
    int a = 0;
    for (int i = 0; i < surname.length(); i++) {
        a += surname[i];
    }
    return a % variants;
}


int main() {
    string surname;
    int variants;
    cout << "Enter the surname: ";
    cin >> surname;
    cout << "Enter the number of variants: ";
    cin >> variants;

    cout << func(surname, variants);
    return 0;
}