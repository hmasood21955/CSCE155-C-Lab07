#include <stdlib.h>
#include <stdio.h>
#include<math.h>

#include "array_utils.h"

void printArray(const int *arr, int n) {
  if(arr == NULL) {
    printf("[null]\n");
    return;
  }
  printf("[ ");
  for(int i=0; i<n-1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d ]\n", arr[n-1]);
  return;
}

void printTable(int **table, int n, int m) {
  if(table == NULL) {
    printf("[null]\n");
    return;
  }
  for(int i=0; i<n; i++) {
    printArray(table[i], m);
  }
  return;
}

int * generateRandomArray(int size) {
  if(size < 0) {
    return NULL;
  }
  int randomArr[size];
  for(int i=0; i<size; i++) {
    randomArr[i] = rand() % 100;
  }
  return randomArr;
}

int getSum(int *arr, int size) {
  if(arr == NULL) {
    return 0;
  }
  int total = 0;
  for(int i=0; i<size; i++) {
    total += arr[i];
    arr[i] = 0;
  }
  return total;
}

void freeTable(int **table, int n) {
  if(table == NULL) {
    return;
  }
  for(int i=0; i<n; i++) {
    free(table[i]);
  }
  free(table);
}

double getMean(const int *arr, int size) {
  //TODO: implement
  if (size == 0) {
        return 0.0; 
    }
    return (double)getSum(arr, size) / size;
}

int getMin(const int *arr, int size) {
  //TODO: implement
  if (size == 0) {
        return 0; 
    }
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int getIndexOfMin(const int *arr, int size) {
  //TODO: implement
      if (size == 0) {
        return -1; 
    }

    int minIndex = 0; 

    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    return minIndex;
}

int getMax(const int *arr, int size) {
  //TODO: implement
   if (size == 0) {
        return 0; 
    }

    int max = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int getIndexOfMax(const int *arr, int size) {
  //TODO: implement
  if (size == 0) {
        return -1; 
    }

    int maxIndex = 0; 
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    return maxIndex;
}

int * filterThreshold(const int *arr, int size, int threshold, int *resultSize) {
  //TODO: implement
  int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] >= threshold) {
            ++count;
        }
    }
    int *result = (int *)malloc(sizeof(int) * count);
    if (result == NULL) {
        
        *resultSize = 0;
        return NULL;
    }

    
    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] >= threshold) {
            result[index++] = arr[i];
        }
    }

    *resultSize = count;
    return result;
}

int **createMultiplicationTable(int n, int m) {
  //TODO: implement
  int **table = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i) {
        table[i] = (int *)malloc(sizeof(int) * m);
        for (int j = 0; j < m; ++j) {
            table[i][j] = (i + 1) * (j + 1);
        }
    }
    return table;
}
