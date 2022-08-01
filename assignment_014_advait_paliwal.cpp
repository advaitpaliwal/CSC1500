#include <iostream>

using namespace std;

void heapify(int heap[], int n, int i) {
  int m = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && heap[l] > heap[m]) {
    m = l;
  }
  if (r < n && heap[r] > heap[m]) {
    m = r;
  }
  if (m != i) {
    swap(heap[i], heap[m]);
    heapify(heap, n, m);
  }
}

void run_sort() {
  int n = 7;
  int heap[n];
  cout << "Input elements:\n";
  for (int i = 0; i < 7; i++) {
    cin >> heap[i];
  }
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(heap, n, i);
  }
  for (int i = n - 1; i > 0; i--) {
    swap(heap[0], heap[i]);
    heapify(heap, i, 0);
  }
  cout << "Heap Sorted:\n";
  for (int i = 0; i < n; ++i)
    cout << heap[i] << " ";
  cout << "\n";
}

int main() {
  for (int i = 0; i < 5; i++) {
    run_sort();
  }
}