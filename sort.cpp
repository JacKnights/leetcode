#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) { // 最后i个元素已经到位，所以不需要再检查
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true; // 发生了交换
            }
        }
        if (!swapped) break; // 如果没有发生交换，说明数组已经有序
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int cur = arr[i]; // 当前元素
        int idx = i; // 用于存储当前元素的位置
        // 如果当前元素的前一个位置有元素，并且该元素大于当前元素，将前一个元素后移
        while (idx > 0 && arr[idx - 1] > cur) {
            arr[idx] = arr[idx - 1]; // 后移
            idx = idx - 1; // 继续检查前一个元素
        }
        arr[idx] = cur; // 找到合适的位置，插入当前元素
    }
}

// 快速排序的分区函数
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素作为枢轴
    int p = low; // 最后一个小于枢轴的元素的位置
    for (int i = low; i <= high - 1; i++) {
        if (arr[i] < pivot) {
            swap(arr[p], arr[i]); // 交换元素
            p++;
        }
    }
    swap(arr[p], arr[high]); // 将枢轴放到正确的位置
    return p;
}

void doQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = partition(arr, low, high); // 获取枢轴的位置
        doQuickSort(arr, low, mid - 1); // 递归排序枢轴左边的部分
        doQuickSort(arr, mid + 1, high); // 递归排序枢轴右边的部分
    }
}

void quickSort(vector<int>& arr) {
    doQuickSort(arr, 0, arr.size() - 1);
}

// 保持大根堆的性质，n 是边界，i 是当前处理节点
void heapify(vector<int>& arr, int n, int i) {
    int l = 2 * i + 1;
    if (l < n && arr[l] > arr[i]) {
        swap(arr[i], arr[l]);
        heapify(arr, n, l);
    }
    int r = 2 * i + 2;
    if (r < n && arr[r] > arr[i]) {
        swap(arr[i], arr[r]);
        heapify(arr, n, r);
    }
}

// 堆排序函数
void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) { // 将vector转换为大根堆
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 1; i--) { // 从大根堆中提取最大元素并保持大根堆
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    // 使用vector存储数组
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    heapSort(arr);
    cout << "Sorted array: \n";
    for (int i=0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}