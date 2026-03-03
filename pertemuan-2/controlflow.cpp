#include <iostream>

using namespace std;

int main() {
  cout << "Masukkan sebuah angka: ";
  int angka;
  cin >> angka;

  cout << "Angka yang diberikan merupakan angka ";
  if (angka % 2 == 0) {
    cout << "Genap ";
  } else {
    cout << "Ganjil ";
  }

  if (angka < 0) {
    cout << "Negatif";
  } else if (angka > 0) {
    cout << "Positif";
  }

  cout << endl;
  return 0;
}
