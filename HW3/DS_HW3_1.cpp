#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h> 
using namespace std;

void Bubble_Sort(int arr[], int len);
void Insertion_Sort(int arr[], int n);
void Quick_Sort(int arr[], int first_index, int last_index);
void merge(int array[], int const left, int const mid, int const right);
void mergeSort(int array[], int const begin, int const end);

// Bubble_sort
void Bubble_Sort(int arr[], int len){
	int i, j, temp;
	for (i = 0; i < len - 1; ++i)          
		for (j = 0; j < len - 1 - i; ++j) 
			if (arr[j] > arr[j + 1])      
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

// Insertion_Sort
void Insertion_Sort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      int temp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = temp;
      j--;
    }
  }
}

// Quick_Sort
void Quick_Sort(int arr[], int first, int last) {
  int pivot, temp, index_a, index_b;

  if (first < last) {
    pivot = first;
    index_a = first;
    index_b = last;

    while (index_a < index_b) {
      while (arr[index_a] <= arr[pivot] && index_a < last) {
        index_a++;
      }
      while (arr[index_b] > arr[pivot]) {
        index_b--;
      }

      if (index_a < index_b) {
        temp = arr[index_a];
        arr[index_a] = arr[index_b];
        arr[index_b] = temp;
      }
    }

    temp = arr[pivot];
    arr[pivot] = arr[index_b];
    arr[index_b] = temp;

    Quick_Sort(arr, first, index_b - 1);
    Quick_Sort(arr, index_b + 1, last);
  }
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void merge(int array[], int left, int mid, int right)
{
    int const arr1 = mid - left + 1;
    int const arr2 = right - mid;
  
    // Create temp arrays
    int *leftArray = new int[arr1],
         *rightArray = new int[arr2];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < arr1; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < arr2; j++)
        rightArray[j] = array[mid + 1 + j];
  
    int index1 = 0, // Initial index of first sub-array
        index2 = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
  
    // Merge the temp arrays
    while (index1 < arr1 && index2 < arr2) {
        if (leftArray[index1] <= rightArray[index2]) {
            array[indexOfMergedArray] = leftArray[index1];
            index1++;
        }
        else {
            array[indexOfMergedArray] = rightArray[index2];
            index2++;
        }
        indexOfMergedArray++;
    }

    while (index1 < arr1) {
        array[indexOfMergedArray] = leftArray[index1];
        index1++;
        indexOfMergedArray++;
    }

    while (index2 < arr2) {
        array[indexOfMergedArray] = rightArray[index2];
        index2++;
        indexOfMergedArray++;
    }
}

int main(){

  double START,END;
  double t_b1,t_i1,t_q1,t_m1,t_b2,t_i2,t_q2,t_m2,t_b3,t_i3,t_q3,t_m3;

	srand(time(NULL));

	int arr1_1[1000],arr1_2[1000],arr1_3[1000],arr1_4[1000];
	for (int i = 0 ; i < 999 ; i++){
    int rnum = rand();
    arr1_1[i] = rnum;
    arr1_2[i] = rnum;
    arr1_3[i] = rnum;
    arr1_4[i] = rnum;
	}

  int arr2_1[10000],arr2_2[10000],arr2_3[10000],arr2_4[10000];
	for (int i = 0 ; i < 9999 ; i++){
		int rnum = rand();
		arr2_1[i] = rnum;
    arr2_2[i] = rnum;
    arr2_3[i] = rnum;
    arr2_4[i] = rnum;
	}

  int arr3_1[100000],arr3_2[100000],arr3_3[100000],arr3_4[100000];
	for (int i = 0 ; i < 99999 ; i++){
		int rnum = rand();
		arr3_1[i] = rnum;
    arr3_2[i] = rnum;
    arr3_3[i] = rnum;
    arr3_4[i] = rnum;
	}

  // 1000 numbers
  printf("[1000 numbers]\n\n");
  printf("Bubble_Sort:\n");
  START = clock();
  printf("start: %5f ",START);
  Bubble_Sort(arr1_1,1000);
  END = clock();
  printf("end: %5f\n",END);
  t_b1 = (END - START) / CLOCKS_PER_SEC* 1000;
  printf("Bubble_Sort took %f\n\n",t_b1);

  printf("Insertion_Sort:\n");
  START = clock();
  printf("start: %5f ",START);
  Insertion_Sort(arr1_2,1000);
  END = clock();
  printf("end: %5f\n",END);
  t_i1 = (END - START) / CLOCKS_PER_SEC* 1000;
  printf("Insertion_Sort took: %f\n\n",t_i1);

  printf("Quick_Sort:\n");
  START = clock();
  printf("start: %f ",START);
  Quick_Sort(arr1_3,0,999);
  END = clock();
  printf("end: %f\n",END);
  t_q1 = (END - START) / CLOCKS_PER_SEC * 1000;
  printf("Quick_Sort took: %f\n\n",t_q1);

  printf("Merge_Sort:\n");
  START = clock();
  printf("start: %f ",START);
  mergeSort(arr1_1, 0,999);
  END = clock();
  printf("end: %f\n",END);
  t_m1 = (END - START) / CLOCKS_PER_SEC * 1000;
  printf("Merge_Sort took: %f\n\n",t_m1);

  // 10000 numbers
  printf("[10000 numbers]\n\n");
  printf("Bubble_Sort:\n");
  START = clock();
  printf("start: %5f ",START);
  Bubble_Sort(arr2_1,10000);
  END = clock();
  printf("end: %5f\n",END);
  t_b1 = (END - START) / CLOCKS_PER_SEC* 1000;
  printf("Bubble_Sort took %f\n\n",t_b1);

  printf("Insertion_Sort:\n");
  START = clock();
  printf("start: %5f ",START);
  Insertion_Sort(arr2_2,10000);
  END = clock();
  printf("end: %5f\n",END);
  t_i1 = (END - START) / CLOCKS_PER_SEC* 1000;
  printf("Insertion_Sort took: %f\n\n",t_i1);

  printf("Quick_Sort:\n");
  START = clock();
  printf("start: %f ",START);
  Quick_Sort(arr2_3,0,9999);
  END = clock();
  printf("end: %f\n",END);
  t_q1 = (END - START) / CLOCKS_PER_SEC * 1000;
  printf("Quick_Sort took: %f\n\n",t_q1);

  printf("Merge_Sort:\n");
  START = clock();
  printf("start: %f ",START);
  mergeSort(arr2_4, 0,9999);
  END = clock();
  printf("end: %f\n",END);
  t_m1 = (END - START) / CLOCKS_PER_SEC * 1000;
  printf("Merge_Sort took: %f\n\n",t_m1);

  // 100000 numbers
  printf("[100000 numbers]\n\n");
  printf("Bubble_Sort:\n");
  START = clock();
  printf("start: %5f ",START);
  Bubble_Sort(arr3_1,100000);
  END = clock();
  printf("end: %5f\n",END);
  t_b1 = (END - START) / CLOCKS_PER_SEC* 1000;
  printf("Bubble_Sort took %f\n\n",t_b1);

  printf("Insertion_Sort:\n");
  START = clock();
  printf("start: %5f ",START);
  Insertion_Sort(arr3_2,100000);
  END = clock();
  printf("end: %5f\n",END);
  t_i1 = (END - START) / CLOCKS_PER_SEC* 1000;
  printf("Insertion_Sort took: %f\n\n",t_i1);

  printf("Quick_Sort:\n");
  START = clock();
  printf("start: %f ",START);
  Quick_Sort(arr3_3,0,99999);
  END = clock();
  printf("end: %f\n",END);
  t_q1 = (END - START) / CLOCKS_PER_SEC * 1000;
  printf("Quick_Sort took: %f\n\n",t_q1);

  printf("Merge_Sort:\n");
  START = clock();
  printf("start: %f ",START);
  mergeSort(arr3_4, 0,99999);
  END = clock();
  printf("end: %f\n",END);
  t_m1 = (END - START) / CLOCKS_PER_SEC * 1000;
  printf("Merge_Sort took: %f\n\n",t_m1);
}
