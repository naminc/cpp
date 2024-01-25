
#include "stdafx.h"
#include "iostream"
#include "ctime"

#define MAX 100
using namespace std;

void NhapMang(int A[], int n) {
	for (int i = 0; i < n; i++) {
		do {
			cout << "Nhap phan tu thu " << i << " ";
			cin >> A[i];
			cout << endl;
		} while (A[i] < 0 || A[i] > 999);

	}
}
void XuatMang(int A[], int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i];
		cout << "\t";


	}
}
void NhapMangTuDong(int A[], int n) {
	for (int i = 0; i < n; i++) {
		A[i] = rand() % 1000;
	}

}

void DoiCho(int &x, int &y) {
	int z = x;
	x = y;
	y = z;
}
void InterChangeSort(int A[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (A[i] > A[j])
				DoiCho(A[i], A[j]);
}
void SelectTionSort(int A[], int n) {
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if (A[j] < A[min])
				min = j;
		if (min != i ) {
				DoiCho(A[min], A[i]);
		}
	}
}
void InsertTionSort(int A[], int n) {
	int vitri, x;
	for (int i = 1; i < n; i++){
		x = A[i];
		vitri = i;
		while (vitri > 0 && x < A[vitri - 1]){
			DoiCho(A[vitri], A[vitri - 1]);
			vitri--;
		}
		DoiCho(A[vitri], x);
	}
}
void BubbleSort(int A[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
	if (A[j] < A[j - 1])
		DoiCho(A[j], A[j - 1]);
}
void QuickSort(int A[], int l, int r) {
	int p = A[(l + r) / 2];
	int i = l, j = r;
	while (i < j){
		while (A[i] < p){
			i++;
		}
		while (A[j] > p){
			j--;
		}
		if (i <= j){
			DoiCho(A[i], A[j]);
			i++;
			j--;
		}
	}
	if (i < r){
		QuickSort(A, i, r);
	}
	if (l < j){
		QuickSort(A, l, j);
	}
}


int FindPivot(int A[], int L, int R) {
	int mid = L + (R - L) / 2;

	if (A[L] > A[mid])
		DoiCho(A[L], A[mid]);
	if (A[L] > A[R])
		DoiCho(A[L], A[R]);
	if (A[mid] > A[R])
		DoiCho(A[mid], A[R]);

	return A[mid];
}

int Partition(int A[], int L, int R, int pivot) {
	int i = L;
	int j = R;

	while (true) {
		while (A[i] < pivot)
			i++;
		while (A[j] > pivot)
			j--;

		if (i >= j)
			return j;

		DoiCho(A[i], A[j]);
		i++;
		j--;
	}
}

void Quick_Sort(int A[], int L, int R) {
	if (L < R) {
		int pivot = FindPivot(A, L, R);
		int p = Partition(A, L, R, pivot);

		Quick_Sort(A, L, p);
		Quick_Sort(A, p + 1, R);
	}
}
int main(){
	int A[MAX], n;
	int l = 0, r = n - 1;  
	do {
		cout << "Nhap N: ";
		cin >> n;
	} while (n <= 0);
	srand(time(NULL));
	NhapMangTuDong(A, n);
	// InterChangeSort(A, n);
	// SelectTionSort(A, n);
	// InsertTionSort(A, n);
	// BubbleSort(A, n);
	/*QuickSort(A, l, r);  */
	Quick_Sort(A, l, r);
	XuatMang(A, n);
	cout << endl;
	system("pause");
}
