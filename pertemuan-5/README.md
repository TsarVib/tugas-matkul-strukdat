# Tipe Data Stack (Pertemuan 5)

Nama: Firsto Al Kautsar Jagad Kurniaji
NRP: 5025251020
Kelas: Struktur Data D

Link Source Code: [Source Code Pertemuan 5](https://github.com/TsarVib/tugas-matkul-strukdat/tree/main/pertemuan-5)

---

Stack adalah struktur data linear yang menyimpan kumpulan elemen, di mana proses penambahan (push) dan penghapusan (pop) hanya dapat dilakukan pada satu sisi yang disebut top (puncak stack).

Stack menggunakan prinsip LIFO (Last In, First Out), yaitu elemen yang terakhir dimasukkan akan menjadi yang pertama dikeluarkan. Analoginya seperti tumpukan piring: piring terakhir yang diletakkan di atas adalah yang pertama diambil.

---

## Implementasi dengan Array

Stack diimplementasikan menggunakan array berukuran tetap. Variabel `top` digunakan untuk melacak indeks elemen paling atas. Nilai awal `top = -1` menandakan stack kosong.

### Constructor

Menginisialisasi stack dengan mengatur nilai `top` ke `-1`, yang berarti stack dalam kondisi kosong dan belum ada elemen yang tersimpan.

### push(int x)

Menambahkan elemen baru ke puncak stack. Sebelum menambahkan, fungsi ini memeriksa apakah stack sudah penuh (`top == MAX - 1`). Jika penuh, mencetak pesan Stack Overflow. Jika belum penuh, nilai `top` dinaikkan satu lalu elemen disimpan di posisi tersebut.

### pop()

Menghapus elemen yang berada di puncak stack. Fungsi ini memeriksa apakah stack kosong (`top == -1`). Jika kosong, mencetak pesan Stack Underflow. Jika tidak kosong, elemen di posisi `top` diambil lalu nilai `top` diturunkan satu.

### peek()

Melihat elemen paling atas stack tanpa menghapusnya. Jika stack kosong, mencetak pesan bahwa stack kosong. Jika tidak, menampilkan nilai elemen di posisi `top`.

### isFull()

Mengecek apakah stack sudah mencapai kapasitas maksimum dengan membandingkan nilai `top` terhadap `MAX - 1`. Digunakan untuk mencegah Stack Overflow sebelum melakukan push.

### isEmpty()

Mengecek apakah stack tidak memiliki elemen dengan memeriksa apakah nilai `top` sama dengan `-1`.

```cpp
#define MAX 5

class Stack {
private:
  int arr[MAX];
  int top;

public:
  Stack() { top = -1; }

  bool isFull() { return (top == MAX - 1); }

  bool isEmpty() { return (top == -1); }

  void push(int x) {
    if (isFull()) {
      cout << "Stack Overflow\n";
    } else {
      arr[++top] = x;
      cout << x << " ditambahkan ke stack\n";
    }
  }

  void pop() {
    if (isEmpty()) {
      cout << "Stack Underflow\n";
    } else {
      cout << arr[top--] << " dihapus dari stack\n";
    }
  }

  void peek() {
    if (isEmpty()) {
      cout << "Stack kosong\n";
    } else {
      cout << "Elemen teratas: " << arr[top] << endl;
    }
  }
};

int main() {
  Stack s;

  s.push(10);
  s.push(20);
  s.push(30);

  s.peek();

  s.pop();
  s.peek();

  return 0;
}
```

Kelemahan implementasi array adalah ukurannya tetap (statis). Jika elemen melebihi kapasitas `MAX`, stack tidak dapat menampung elemen baru meskipun memori sistem masih tersedia.

---

## Implementasi dengan Linked List

Stack direpresentasikan sebagai linked list. Setiap elemen disimpan dalam sebuah node yang memiliki dua bagian: `data` untuk menyimpan nilai, dan `next` sebagai pointer ke node berikutnya. Puncak stack (top) selalu mengacu pada node paling depan (head) dari linked list.

### struct Node

Mendefinisikan struktur node yang menjadi unit dasar penyimpanan data. Setiap node menyimpan satu nilai integer dan pointer ke node berikutnya dalam rantai linked list.

### Constructor

Menginisialisasi stack dengan mengatur pointer `top` ke `NULL`, yang menandakan bahwa stack dalam kondisi kosong dan belum ada node yang dialokasikan.

### push(int x)

Menambahkan elemen baru ke puncak stack. Langkah-langkahnya:
1. Membuat node baru dengan `new Node()`.
2. Menyimpan nilai `x` ke dalam `data` node baru.
3. Mengarahkan pointer `next` node baru ke node `top` yang lama.
4. Memperbarui `top` agar menunjuk ke node baru.

Dengan cara ini, node baru selalu menjadi kepala dari linked list.

### pop()

Menghapus elemen dari puncak stack. Langkah-langkahnya:
1. Memeriksa apakah stack kosong (`top == NULL`). Jika ya, mencetak pesan Stack Underflow.
2. Menyimpan pointer `top` ke variabel sementara `temp`.
3. Memajukan `top` ke node berikutnya (`top->next`).
4. Menghapus node lama yang tersimpan di `temp` dari memori menggunakan `delete`.

### peek()

Melihat nilai elemen paling atas stack tanpa menghapusnya. Jika `top == NULL`, mencetak pesan bahwa stack kosong. Jika tidak, menampilkan nilai `top->data`.

### isEmpty()

Mengecek apakah stack kosong dengan memeriksa apakah pointer `top` bernilai `NULL`. Mengembalikan `true` jika kosong, `false` jika tidak.

```cpp
struct Node {
  int data;
  Node *next;
};

class Stack {
private:
  Node *top;

public:
  Stack() { top = NULL; }

  bool isEmpty() { return (top == NULL); }

  void push(int x) {
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = top;
    top = newNode;

    cout << x << " ditambahkan ke stack\n";
  }

  void pop() {
    if (isEmpty()) {
      cout << "Stack Underflow\n";
      return;
    }

    Node *temp = top;
    cout << temp->data << " dihapus dari stack\n";
    top = top->next;
    delete temp;
  }

  void peek() {
    if (isEmpty()) {
      cout << "Stack kosong\n";
    } else {
      cout << "Elemen teratas: " << top->data << endl;
    }
  }
};

int main() {
  Stack s;

  s.push(10);
  s.push(20);
  s.push(30);

  s.peek();

  s.pop();
  s.peek();

  return 0;
}
```

Keunggulan implementasi linked list adalah ukurannya dinamis sehingga tidak memiliki batas kapasitas tetap. Stack Overflow tidak akan terjadi selama memori sistem masih tersedia. Namun setiap node memerlukan alokasi memori tambahan untuk menyimpan pointer `next`.

---

## Aplikasi Stack

### Memproses Ekspresi Matematika
Salah satu penggunaan stack yang umum adalah konversi notasi ekspresi matematika. Terdapat tiga jenis notasi ekspresi:

- **Infix**: operator berada di antara dua operand. Contoh: `A + B`
- **Postfix (Reverse Polish Notation)**: operator berada setelah operand. Contoh: `A B +`
- **Prefix (Polish Notation)**: operator berada sebelum operand. Contoh: `+ A B`

Komputer lebih mudah memproses notasi postfix atau prefix karena tidak memerlukan tanda kurung dan tidak ambigu terhadap aturan prioritas operator.
Stack berfungsi sebagai penyimpanan sementara untuk operator, memastikan operator dikeluarkan ke output sesuai dengan urutan prioritasnya.

### Pengecekan Tanda Kurung Valid
Aplikasi lain dari stack adalah memeriksa apakah suatu ekspresi memiliki pasangan kurung yang valid. Sebuah ekspresi dianggap valid jika setiap kurung buka memiliki pasangan kurung tutup yang sesuai dan urutan penutupannya benar.
Contoh ekspresi seimbang: {[()]}, (a + b) * (c - d)
Contoh ekspresi tidak seimbang: {[(])}, ((a + b)
