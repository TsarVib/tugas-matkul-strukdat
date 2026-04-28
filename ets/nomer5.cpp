#include <bits/stdc++.h>
using namespace std;

// Sistem Queue Sirkular,
// jika _rear mencapai 100 tapi masih ada tempat di awal array maka akan
// dipakai
struct Queue {
  char _arr[100];
  int _front = -1, _rear = -1;

  // Memasukkan mahasiswa ke antrian
  void enqueue(char a) {
    if ((_rear + 1) % 100 == _front) {
      cout << "Antrian Penuh!" << endl;
      return;
    }

    if (_rear == -1) {
      _front = 0;
    }
    _rear = (_rear + 1) % 100;
    _arr[_rear] = a;
  }

  // Memanggil mahasiswa keluar dari antrian untuk diproses
  void dequeue() {
    if (_front == -1) {
      cout << "Antrian Kosong!" << endl;
      return;
    }
    if (_front == _rear) {
      _front = _rear = -1;
      return;
    }
    _front = (_front + 1) % 100;
  }

  // Untuk melihat depan dan belakang antrian
  char front() { return _arr[_front]; }
  char rear() { return _arr[_rear]; }

  // Mencetak semua anggota antrian
  void printQueue() {
    if (_front == -1) {
      cout << "Antrian Kosong!" << endl;
      return;
    }
    cout << "Kondisi Antrian: ";
    int i = _front;
    while (true) {
      cout << _arr[i] << " ";
      if (i == _rear)
        break;
      i = (i + 1) % 100;
    }
    cout << endl;
  }
};

int main() {
  Queue q;

  cout << "Mahasiswa A, B, C masuk antrian" << endl;
  q.enqueue('A');
  q.enqueue('B');
  q.enqueue('C');
  q.printQueue();
  cout << endl;

  cout << "Mahasiswa pertama dilayani" << endl;
  q.dequeue();
  q.printQueue();
  cout << endl;

  cout << "Tambah mahasiswa D" << endl;
  q.enqueue('D');
  cout << endl;

  cout << "Tampilkan kondisi antrian" << endl;
  q.printQueue();
}
