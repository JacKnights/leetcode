#ifndef HELPER_CPP
#define HELPER_CPP

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void printVectorString(vector<string> vec, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("  \"%2s\" ", vec[i].c_str());
    }
    printf("]\n");
}

void printVectorString2D(vector<vector<string>> mat) {
    printf("[\n");
    for (int i = 0; i < mat.size(); i++) {
        printf("  ");
        printVectorString(mat[i], mat[i].size());
    }
    printf("]\n");
}

void printVectorChar(vector<char> vec, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("  '%c' ", vec[i]);
    }
    printf("]\n");
}

void printVectorChar2D(vector<vector<char>> mat) {
    printf("[\n");
    for (int i = 0; i < mat.size(); i++) {
        printf("  ");
        printVectorChar(mat[i], mat[i].size());
    }
    printf("]\n");
}

void printVectorInt(vector<int> vec, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("  %d ", vec[i]);
    }
    printf("]\n");
}

void printVectorInt2D(vector<vector<int>> mat) {
    printf("[\n");
    for (int i = 0; i < mat.size(); i++) {
        printf("  ");
        printVectorInt(mat[i], mat[i].size());
    }
    printf("]\n");
}

void printMapStringInt(map<string, int> m) {
    printf("[");
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        printf("  %s: %d ", iter->first.c_str(), iter->second);
    }
    printf("]\n");
}

void printMapIntInt(map<int, int> m) {
    printf("[");
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        printf("  %d: %d ", iter->first, iter->second);
    }
    printf("]\n");
}

#endif