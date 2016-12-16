#include<iostream>

using namespace std;

void quickSort(int *A, int left, int right) {
	if (left < right) {
		int pivot = A[left];
		int i = left;
		int j = right;
		while (i < j) {
			do
				i++;
			while (A[i] < pivot);
			while (A[j] > pivot) {
				j--;
			}
			if (i < j) {
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
		int t = A[j];
		A[j] = A[left];
		A[left] = t;
		quickSort(A, left, j - 1);
		quickSort(A, j + 1, right);
	}
}

int main() {
	int A[10] = { 26,5,37,1,61,11,59,15,48,19 };
	quickSort(A, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << A[i] << " ";
	}
	return 0;
}