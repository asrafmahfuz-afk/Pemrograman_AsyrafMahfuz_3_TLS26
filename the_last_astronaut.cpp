#include <iostream>
using namespace std;

int main() {
    int N, K;

    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai awal K: ";
    cin >> K;

    if (N <= 0) {
        cout << "Jumlah astronot harus lebih dari 0." << endl;
        return 0;
    }

    if (K < 2) {
        K = 2;
    }

    // next[i] menyimpan nomor astronot hidup berikutnya.
    int* next = new int[N + 1];

    for (int i = 1; i <= N; i++) {
        if (i == N) {
            next[i] = 1;
        } else {
            next[i] = i + 1;
        }
    }

    int remaining = N;
    int current = 1;
    int previous = N;

    cout << "Urutan eliminasi: ";

    while (remaining > 1) {
        // current dihitung sebagai hitungan pertama.
        for (int count = 1; count < K; count++) {
            previous = current;
            current = next[current];
        }

        int eliminated = current;
        cout << eliminated;

        if (remaining > 2) {
            cout << " ";
        }

        // Hapus astronot yang tereliminasi dari lingkaran.
        next[previous] = next[current];
        current = next[current];
        remaining--;

        // Perbarui K berdasarkan nomor astronot yang dieliminasi.
        if (eliminated % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
            if (K < 2) {
                K = 2;
            }
        }
    }

    cout << endl;
    cout << "Astronot terakhir: " << current << endl;

    delete[] next;
    return 0;
}
