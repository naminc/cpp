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


}
int main(){
	int A[MAX], n;
	do {
		cout << "Nhap N: ";
		cin >> n;
	} while (n <= 0);
	srand(time(NULL));
	NhapMangTuDong(A, n);
	/*NhapMang(A, n);*/
	XuatMang(A, n);
	cout << endl;

	system("pause");
}


