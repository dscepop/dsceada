#include<stdio.h>

#include<conio.h>

void qsort(int[], int, int);
int partition(int[], int, int);
void qsort(int a[], int first, int last) {
  int j;
  if (first < last) {
    j = partition(a, first, last + 1);
    qsort(a, first, j - 1);
    qsort(a, j + 1, last);
  }
}
int partition(int a[], int first, int last) {
  int v = a[first];
  int i = first;
  int j = last;
  int temp = 0;
  do {
    do {
      i++;
    } while (a[i] < v);
    do {
      j--;
    } while (a[j] > v);
    if (i < j) {
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  } while (i < j);
  a[first] = a[j];
  a[j] = v;
  return j;
}
int main() {
  int a[40], i, n;
  printf("\n Enter the no of elements (size):");
  scanf("%d", & n);
  printf("\n Enter the ELements to sort:");
  for (i = 0; i < n; i++)
    scanf("%d", & a[i]);
  qsort(a, 0, n - 1);
  printf("\n The ELements after sorting are:");
  for (i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
  getch();
  return 0;
}