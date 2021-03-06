#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int min(int a, int b) {
  return a < b ? a : b;
}

void merge(int *to, int *fromA, int *fromB, int lenA, int lenB) {
  for (int i = 0, j = 0, k = 0; i < lenA + lenB;) {
    if (k >= lenB || (j < lenA && fromA[j] >= fromB[k]))
      to[i++] = fromA[j++];
    if (j >= lenA || (k < lenB && fromB[k] >= fromA[j]))
      to[i++] = fromB[k++];
  }
}

int main(void) {
  int n;
  scanf("%d", &n);

  int *arr = (int*)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  int *tmp = (int*)malloc(sizeof(int) * n);
  for (int i = 1; i < n; i *= 2) {
    for (int j = 0; j < n; j += i * 2) {
      int lenA = min(i, n - j), lenB = min(i, n - j - i);
      merge(&tmp[j], &arr[j], &arr[j + i], lenA, lenB);
    }
    int *t = arr;
    arr = tmp;
    tmp = t;
  }
  free(tmp);
  
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  
  free(arr);

  return 0;
}

