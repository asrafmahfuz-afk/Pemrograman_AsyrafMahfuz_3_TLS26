#include <iostream>
using namespace std;

int main() {
    const int MAX = 1000;
    char message[MAX + 1];

    cout << "Masukkan pesan huruf kapital tanpa spasi: ";
    cin >> message;

    int length = 0;
    while (message[length] != '\0') {
        length++;
    }

    if (length == 0) {
        cout << "Pesan kosong." << endl;
        return 0;
    }

    char encrypted[MAX + 1];

    // Huruf pertama tidak berubah.
    encrypted[0] = message[0];

    for (int i = 1; i < length; i++) {
        int currentValue = message[i] - 'A' + 1;
        int previousValue = message[i - 1] - 'A' + 1;

        int newValue = currentValue + previousValue;

        while (newValue > 26) {
            newValue = newValue - 26;
        }

        encrypted[i] = char('A' + newValue - 1);
    }

    encrypted[length] = '\0';

    cout << "Pesan tersandi: " << encrypted << endl;

    return 0;
}
