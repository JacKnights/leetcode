#include <cstdio>
#include <vector>
#include <ctime>
#include <random>
using namespace std;

using SortingFunc = void(*) (std::vector<int>&);

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

// 保持大根堆的性质, n 是边界, root 是当前需调整位置
void heapify(vector<int>& arr, int n, int root) {
    int larger = root; // 只需选定左右子树中的较大值
    int left = 2 * root + 1;
    if (left < n && arr[left] > arr[larger]) {
        larger = left;
    }
    int right = 2 * root + 2;
    if (right < n && arr[right] > arr[larger]) {
        larger = right;
    }
    if (larger != root) {
        swap(arr[root], arr[larger]);
        heapify(arr, n, larger);
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

// 归并两个已排序的子数组
void merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low;
    int n2 = high + 1 - mid;

    vector<int> L(n1), R(n2); // 创建临时数组并复制数据
    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + j];

    int i = 0, j = 0;
    int k = low;
    while (i < n1 && j < n2) {    // 归并
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {    // 复制L[]的剩余元素
        arr[k++] = L[i++];
    }
    while (j < n2) {    // 复制R[]的剩余元素
        arr[k++] = R[j++];
    }
}

// 归并排序的递归部分
void doMergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high + 1 - low) / 2;
        // 递归地排序两个子数组
        doMergeSort(arr, low, mid - 1);
        doMergeSort(arr, mid, high);
        // 合并两个已排序的子数组
        merge(arr, low, mid, high);
    }
}

void mergeSort(vector<int>& arr) {
    doMergeSort(arr, 0, arr.size() - 1);
}

// i 为起点下标, gap 为跳步
void doGroupInsertionSort(vector<int>& arr, int n, int i, int gap) {
    for (int j = i; j < n; j += gap) {
        int cur = arr[j];
        int idx = j;
        while (idx >= gap && arr[idx - gap] > cur) {
            arr[idx] = arr[idx - gap];
            idx -= gap;
        }
        arr[idx] = cur;
    }
}

void shellSort(vector<int>& arr) {
    int n = arr.size();
    // gap为步长，每次减为原来的一半。
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 共gap个组，对每一组都执行直接插入排序
        for (int i = 0; i < gap; i++)
            doGroupInsertionSort(arr, n, i, gap);
    }
}

vector<int> generate_random_vector(int length) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10000);

    vector<int> vec(length);
    for (int i = 0; i < length; i++) {
        vec[i] = dis(gen);
    }
    return vec;
}

const int BENCH_ROUND = 10;
const int BENCH_SIZE = 10000;

void sortBenchmark(SortingFunc sf) {
    clock_t start = clock();
    for (int i = 0; i < BENCH_ROUND; i++) {
        vector<int> random_arr = generate_random_vector(BENCH_SIZE);
        sf(random_arr);
    }
    clock_t end = clock();
    printf("Execution time: %f seconds\n", (float)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    // 使用vector存储数组
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 28};
    vector<SortingFunc> sfs = {
        bubbleSort,
        selectionSort,
        insertionSort,
        quickSort,
        heapSort,
        mergeSort,
        shellSort
        // 更多排序算法
    };
    int count = sfs.size();
    vector<vector<int>> arrs;
    arr.reserve(count);
    for (int i = 0; i < count; i++) {
        arrs.push_back(arr);
        sfs[i](arrs[i]);
    }

    for (int i = 1; i < count; i++) {
        for (int j = 0; j < arrs[i].size(); j++) {
            if (arrs[0][j] != arrs[i][j]) {
                return 1;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < arrs[0].size(); i++)
        printf("%d ", arrs[0][i]);
    printf("\n");

    printf("bubbleSort - ");
    sortBenchmark(bubbleSort);
    printf("selectionSort - ");
    sortBenchmark(selectionSort);
    printf("insertionSort - ");
    sortBenchmark(insertionSort);
    printf("quickSort - ");
    sortBenchmark(quickSort);
    printf("heapSort - ");
    sortBenchmark(heapSort);
    printf("shellSort - ");
    sortBenchmark(shellSort);
    printf("mergeSort - ");
    sortBenchmark(mergeSort);
    // bubbleSort - Execution time: 5.092793 seconds
    // selectionSort - Execution time: 1.725421 seconds
    // insertionSort - Execution time: 1.180541 seconds
    // quickSort - Execution time: 0.019891 seconds
    // heapSort - Execution time: 0.032506 seconds
    // shellSort - Execution time: 0.026463 seconds
    // mergeSort - Execution time: 0.043394 seconds
    return 0;
}