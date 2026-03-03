#include <bits/stdc++.h>
#include <cctype>
using namespace std;

void vowelOrConsonant(char x) {
  char a = tolower(x);
  if (a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o')
    cout << x << " is a Vowel" << endl;
  else
    cout << x << " is a Consonant" << endl;
}

bool isPrime(int x) {
  if (x <= 1) {
    return false;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

void findPrime(int l, int r) {
  if (l > r) {
    int t = l;
    l = r;
    r = t;
  }
  bool found = false;
  for (int i = l; i <= r; i++) {
    if (isPrime(i)) {
      cout << i << " ";
      found = true;
    }
  }
  cout << endl;

  if (!found) {
    cout << "Tidak ada angka prima yang ditemukan" << endl;
  }
}

int main() {
  char a = 'x', b = 'e';
  vowelOrConsonant(a);
  vowelOrConsonant(b);
  cout << "Masukkan batas pencarian: ";
  int l, r;
  cin >> l >> r;
  findPrime(l, r);

  return 0;
}
