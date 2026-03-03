#include <bits/stdc++.h>
using namespace std;

int main() {
  int var = 999;
  int *ptr = &var;
  cout << "Nilai dari var: " << var << endl;
  cout << "Alamat dari var: " << &var << endl;
  cout << "Nilai yang ada di pointer ptr: " << ptr << endl;
  cout << "Nilai yang ditunjuk oleh ptr: " << *ptr << endl;

  return 0;
}
