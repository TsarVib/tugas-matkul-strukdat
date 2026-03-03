#include <iostream>
using namespace std;

int main() {
  int r, c, num = 1, n = 5;
  cout << "Masukkan angka: ";
  cin >> n;
  for (r = 0; r <= n; r++) {
    for (c = 0; c < r; c++) {
      cout << num++ << " ";
    }
    cout << "\n";
  }
  return 0;
}
