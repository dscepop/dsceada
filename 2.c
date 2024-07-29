#include<stdio.h>

#include<conio.h>

void merge(int[], int, int, int);
void mergesort(int[], int, int);
void merge(int a[25], int low, int mid, int high) {
  int b[25], h, i, j, k;
  h = low;
  i = low;
  j = mid + 1;
  while ((h <= mid) && (j <= high)) {
    if (a[h] < a[j]) {
      b[i] = a[h];
      h++;
    } else {
      b[i] = a[j];
      j++;
    }
    i++;
  }
  if (h > mid) {
    for (k = j; k <= high; k++) {
      b[i] = a[k];
      i++;
    }
  } else {
    for (k = h; k <= mid; k++) {
      b[i] = a[k];
      i++;
    }
  }
  for (k = low; k <= high; k++) {
    a[k] = b[k];
  }
}
void mergesort(int a[25], int low, int high) {
  int mid;
  if (low < high) {
    mid = (low + high) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    merge(a, low, mid, high);
  }
}
void main() {
  int a[25], i, n;
  printf("\n Enter the size of the elements to be sorted:");
  scanf("%d", & n);
  printf("\n Enter the elements to sort:");
  for (i = 0; i < n; i++)
    scanf("%d", & a[i]);
  printf("\n The Elements before sorting are:");
  for (i = 0; i < n; i++)
    printf("%d\t", a[i]);
  mergesort(a, 0, n - 1);
  printf("\n The elements after sorting are:");
  for (i = 0; i < n; i++)
    printf("%d\t", a[i]);
  getch();
}