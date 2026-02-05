#include <bits/stdc++.h>
using namespace std;
void heapifyUp(vector<int>& heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}
void heapifyDown(vector<int>& heap, int i, int size) {
    while (true) {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}
int main() {
    int N, K;
    cout << "Enter number of scores (N): ";
    cin >> N;
    cout << "Enter cut-off rank (K): ";
    cin >> K;
    vector<int> heap;
    cout << "Enter scores one by one:\n";
    for (int i = 0; i < N; i++) {
        int score;
        cin >> score;

        if (heap.size() < K) {
            heap.push_back(score);
            heapifyUp(heap, heap.size() - 1);
        } 
        else if (score > heap[0]) {
            heap[0] = score;
            heapifyDown(heap, 0, K);
        }

        if (heap.size() < K)
            cout << -1 << endl;
        else
            cout << heap[0] << endl;
    }

    return 0;
}