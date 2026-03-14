#include <bits/stdc++.h>
using namespace std;

int main() {
  int arr[] = {2, 4, 6, 8};
  for (int i = 0; i < 8; i++) {
    cout << arr[i] << endl;
    cout << "id: " << &arr[i] << endl;
  }
  return 0;
}
