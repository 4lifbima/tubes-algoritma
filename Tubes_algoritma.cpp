#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Barang {
    string nama;
    string kode;
};

vector<Barang> daftarBarang;

void inputData() {
    Barang barang;
    cout << "Masukkan nama barang: ";
    cin >> barang.nama;
    cout << "Masukkan kode barang: ";
    cin >> barang.kode;

    daftarBarang.push_back(barang);
    cout << "Data berhasil dimasukkan." << endl;
}

void tampilkanData() {
    if (daftarBarang.empty()) {
        cout << "Data kosong." << endl;
        return;
    }

    cout << "Daftar Barang:" << endl;
    for (const auto& barang : daftarBarang) {
        cout << "Nama: " << barang.nama << "\tKode: " << barang.kode << endl;
    }
}

void cariData() {
    string kodeCari;
    cout << "Masukkan kode barang yang ingin dicari: ";
    cin >> kodeCari;

    auto it = find_if(daftarBarang.begin(), daftarBarang.end(), [kodeCari](const Barang& barang) {
        return barang.kode == kodeCari;
    });

    if (it != daftarBarang.end()) {
        cout << "Data ditemukan - Nama: " << it->nama << "\tKode: " << it->kode << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
}

void urutkanData() {
    if (daftarBarang.empty()) {
        cout << "Data kosong." << endl;
        return;
    }

    sort(daftarBarang.begin(), daftarBarang.end(), [](const Barang& a, const Barang& b) {
        return a.kode < b.kode;
    });

    cout << "Data berhasil diurutkan berdasarkan kode barang." << endl;
}

int main() {
    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Cari Berdasarkn kode\n";
        cout << "4. Urutkan Berdasarkan kode\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputData();
                break;
            case 2:
                tampilkanData();
                break;
            case 3:
                cariData();
                break;
            case 4:
                urutkanData();
                break;
            case 5:
                cout << "Program selesai. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }

    } while (pilihan != 5);

    return 0;
}
