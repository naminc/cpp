// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "stdio.h"
#include "cstdlib"
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
		A[i]= rand() % 1000;
	}

}
void XoaPhanTuViTriK(int A[], int &n, int k) {
	for (int i = k; i < n; i++)
	{
		A[i] = A[i + 1];
	}
	n--;
}
int main(){
	int A[MAX], n;
	int k;
	do {
		cout << "Nhap N: ";
		cin >> n;
	} while (n <= 0);
	srand(time(NULL));
	NhapMangTuDong(A, n);
	XuatMang(A, n);
	cout << endl;
	do {
		cout << "Nhap vi tri K: ";
		cin >> k;
	} while (k < 0 || k >= n);
	/*NhapMang(A, n);*/
	XoaPhanTuViTriK(A, n, k);
	XuatMang(A, n);
	cout << endl;

	system("pause");
}


