#include <bits/stdc++.h>
using namespace std;

struct Mahasiswa {
  string nrp, nama, jurusan, hobi[3];
};

int main() {
  Mahasiswa mhs[3];

  // Meminta data mahasiswa dari User;
  cout << "============ Input Data Mahasiswa ============" << endl;
  for (int i = 0; i < 3; i++) {
    cout << "\nMahasiswa Ke-" << i + 1 << endl;

    cout << "NRP: ";
    getline(cin, mhs[i].nrp);

    cout << "Nama: ";
    getline(cin, mhs[i].nama);

    cout << "Jurusan: ";
    getline(cin, mhs[i].jurusan);

    for (int j = 0; j < 3; j++) {
      cout << "Hobi ke-" << j + 1 << ": ";
      getline(cin, mhs[i].hobi[j]);
      // berhenti kalau user memasukkan "udah"
      if (mhs[i].hobi[j].compare("udah") == 0)
        break;
    }
  }
  cout << endl;

  // Display data-data mahasiswa
  cout << "============ Display Data Mahasiswa ============" << endl;
  for (int i = 0; i < 3; i++) {
    cout << "\nMahasiswa Ke-" << i + 1 << endl;
    cout << "NRP: " << mhs[i].nrp << endl;
    cout << "Nama: " << mhs[i].nama << endl;
    cout << "Jurusan: " << mhs[i].jurusan << endl;
    cout << "Hobi: ";
    for (int j = 0; j < 3; j++) {
      // berhenti kalau hobi mahasiswa adalah "udah"
      if (mhs[i].hobi[j].compare("udah") == 0)
        break;
      cout << mhs[i].hobi[j] << ", ";
    }
    cout << endl;
  }

  return 0;
}
