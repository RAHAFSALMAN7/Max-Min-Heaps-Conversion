#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void MaxHeapify(vector<int>& heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        MaxHeapify(heap, n, largest);
    }
}

void buildMaxHeap(vector<int>& heap) {
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        MaxHeapify(heap, n, i);
    }
}

void MinHeapify(vector<int>& heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        MinHeapify(heap, n, smallest);
    }
}

void buildMinHeap(vector<int>& heap) {
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        MinHeapify(heap, n, i);
    }
}

void print(const vector<int>& heap) {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    ifstream inputFile("data.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    vector<int> data;
    int val;
    while (inputFile >> val) {
        data.push_back(val);
    }

    cout << "Original data: ";
    print(data);

    // Make a copy of data for building max-heap
    vector<int> maxHeapData = data;

    buildMaxHeap(maxHeapData);
    cout << "Max_Heap: ";
    print(maxHeapData);

    // Make another copy of data for converting to min-heap
    vector<int> minHeapData = data; // Use the same data for min-heap construction

    buildMinHeap(minHeapData);
    cout << "Min_Heap: ";
    print(minHeapData);

    inputFile.close();
    return 0;
}
