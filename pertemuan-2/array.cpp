#include <bits/stdc++.h>

using namespace std;

int getMin(int arr[], int n) {
  if (n == 0) {
    return 0;
  }
  int res = arr[0];
  for (int i = 1; i < n; i++) {
    res = min(res, arr[i]);
  }
  return res;
}
int getMax(int arr[], int n) {
  if (n == 0) {
    return 0;
  }
  int res = arr[0];
  for (int i = 1; i < n; i++) {
    res = max(res, arr[i]);
  }
  return res;
}

int main() {
  int arr[] = {12, 3213, 43, 5435, 65, 1, 213};
  int n = sizeof(arr) / sizeof(int);
  cout << "Elemen Minimal: " << getMin(arr, n) << endl;
  cout << "Elemen Maximal: " << getMax(arr, n) << endl;
  return 0;
}
