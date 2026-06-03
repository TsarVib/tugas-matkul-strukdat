#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1000000;

class Graph {
private:
  int V;                   // Jumlah vertex
  vector<vector<int>> adj; // List Ketetanggaan untuk DFS & BFS
  vector<vector<pair<int, int>>>
      adjWeighted;      // List Ketetanggaan Berbobot untuk Dijkstra
  vector<bool> visited; // Array penanda untuk DFS

public:
  // Constructor
  Graph(int vertices) {
    V = vertices;
    adj.resize(V);
    adjWeighted.resize(V);
    visited.resize(V, false);
  }

  // Fungsi menambahkan edge untuk Graf Tanpa Bobot (Undirected)
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // Fungsi menambahkan edge untuk Graf Berbobot (Undirected) - Digunakan di
  // Dijkstra
  void addWeightedEdge(int u, int v, int w) {
    adjWeighted[u].push_back({v, w});
    adjWeighted[v].push_back({u, w});
  }

  // 1. REPRESENTASI: Menampilkan Adjacency Matrix
  void displayAdjacencyMatrix() {
    cout << "===== 1. ADJACENCY MATRIX =====" << endl;
    // Inisialisasi matriks dinamis V x V dengan nilai 0
    vector<vector<int>> matrix(V, vector<int>(V, 0));

    // Isi matriks berdasarkan adjacency list yang ada
    for (int i = 0; i < V; i++) {
      for (int node : adj[i]) {
        matrix[i][node] = 1;
      }
    }

    // Cetak Matriks
    cout << "  ";
    for (int i = 0; i < V; i++)
      cout << i << " ";
    cout << endl;

    for (int i = 0; i < V; i++) {
      cout << i << " ";
      for (int j = 0; j < V; j++) {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
    cout << "Catatan: Angka 1 berarti ada koneksi antar vertex.\n" << endl;
  }

  // 2. REPRESENTASI: Menampilkan Adjacency List
  void displayAdjacencyList() {
    cout << "===== 2. ADJACENCY LIST =====" << endl;
    for (int i = 0; i < V; i++) {
      cout << i << " -> ";
      for (int node : adj[i]) {
        cout << node << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  // Reset status visited sebelum melakukan DFS baru
  void resetVisited() { fill(visited.begin(), visited.end(), false); }

  // 3. TRAVERSAL: Depth First Search (DFS) secara Rekursif
  void DFS(int v) {
    visited[v] = true;
    cout << v << " ";
    for (int u : adj[v]) {
      if (!visited[u])
        DFS(u); // Memanggil fungsi secara rekursif ke dalam
    }
  }

  // Helper untuk menjalankan DFS dengan teks judul
  void runDFS(int start) {
    cout << "===== 3. TRAVERSAL DFS =====" << endl;
    cout << "Hasil DFS (Mulai dari " << start << "): ";
    resetVisited();
    DFS(start);
    cout << "\n" << endl;
  }

  // 4. TRAVERSAL: Breadth First Search (BFS) menggunakan Queue
  void BFS(int start) {
    cout << "===== 4. TRAVERSAL BFS =====" << endl;
    cout << "Hasil BFS (Mulai dari " << start << "): ";

    vector<bool> bfs_visited(V, false);
    queue<int> q;

    bfs_visited[start] = true;
    q.push(start);

    while (!q.empty()) {
      int v = q.front();
      q.pop();
      cout << v << " ";

      for (int u : adj[v]) {
        if (!bfs_visited[u]) {
          bfs_visited[u] = true;
          q.push(u);
        }
      }
    }
    cout << "\n" << endl;
  }

  // 5. SHORTEST PATH: Algoritma Dijkstra
  void dijkstra(int start) {
    cout << "===== 5. SHORTEST PATH (DIJKSTRA) =====" << endl;
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    dist[start] = 0;
    pq.push({0, start}); // Menyimpan pair {jarak, vertex}

    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();

      for (auto edge : adjWeighted[u]) {
        int v = edge.first;
        int w = edge.second;

        // Relaksasi Edge
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          pq.push({dist[v], v});
        }
      }
    }

    cout << "Jarak Terpendek dari titik awal (" << start << "):" << endl;
    for (int i = 0; i < V; i++) {
      if (dist[i] == INF) {
        cout << "Ke titik " << i << " : Tidak Terjangkau" << endl;
      } else {
        cout << "Ke titik " << i << " : " << dist[i] << endl;
      }
    }
    cout << endl;
  }
};

int main() {
  // Membuat Graf dengan 5 Vertex (0 sampai 4)
  Graph g(5);

  // --- Input untuk Representasi Graf, DFS, dan BFS ---
  // Struktur hubungan: 0-1, 0-2, 1-3, 2-4
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 4);

  // --- Input Khusus Bobot untuk Algoritma Dijkstra ---
  // Struktur hubungan dan bobotnya (u, v, bobot)
  g.addWeightedEdge(0, 1, 4); // Jalur 0 ke 1 berbobot 4
  g.addWeightedEdge(0, 2, 2); // Jalur 0 ke 2 berbobot 2
  g.addWeightedEdge(1, 3, 2); // Jalur 1 ke 3 berbobot 2
  g.addWeightedEdge(2, 4, 4); // Jalur 2 ke 4 berbobot 4
  g.addWeightedEdge(3, 4, 1); // Jalur 3 ke 4 berbobot 1

  // --- Pemanggilan Seluruh Fungsi Graf ---

  // 1 & 2. Menampilkan Representasi Matriks dan List
  g.displayAdjacencyMatrix();
  g.displayAdjacencyList();

  // 3. Menjalankan Traversal DFS
  g.runDFS(0);

  // 4. Menjalankan Traversal BFS
  g.BFS(0);

  // 5. Menjalankan Pencarian Jalur Terpendek Dijkstra
  g.dijkstra(0);

  return 0;
}
