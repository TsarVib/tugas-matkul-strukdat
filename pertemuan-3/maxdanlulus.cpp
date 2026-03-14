#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cout << "Ada berapa mahasiswa? ";
  cin >> n;
  int nilai[n];
  int maxNilai = -9999;
  int bestMhs = -9999;

  for (int i = 0; i < n; i++) {
    cout << "Nilai mahasiswa ke-" << i + 1 << ": ";
    cin >> nilai[i];
    if (nilai[i] > maxNilai) {
      maxNilai = nilai[i];
      bestMhs = i + 1;
    }
  }

  cout << "\nStatus Kelulusan Mahasiswa\n";
  for (int i = 0; i < n; i++) {
    cout << "Mahasiswa " << i + 1 << ": ";
    if (nilai[i] < 75) {
      cout << "Tidak ";
    }
    cout << "Lulus\n";
  }

  cout << "Nilai tertinggi adalah mahasiswa ke-" << bestMhs << " dengan nilai "
       << maxNilai << "\n";

  return 0;
}
