// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "cstring"
#define MAX 100

using namespace std;

struct SinhVien
{
	int MSSV;
	char HoTen[50];
	float DTB;
};

void NhapSV(SinhVien& sv) {
	cout << "Nhap MSSV: ";
	cin.ignore();
	cin >> sv.MSSV;
	cout << "Nhap ho ten sinh vien: ";
	cin.ignore();
	cin.getline(sv.HoTen, sizeof(sv.HoTen));
	cout << "Nhap diem trung binh: ";
	cin >> float(sv.DTB);

}
void NhapDSSV(SinhVien sv[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin sinh vien thu " << i;
		cout << endl;
		NhapSV(sv[i]);
	}
}
void XuatSV(SinhVien sv) {
	cout << "Ma so sinh vien: ";
	cout << sv.MSSV;
	cout << endl;
	cout << "Ho ten sinh vien: ";
	cout << sv.HoTen;
	cout << endl;
	cout << "Diem trung binh sinh vien: ";
	cout << float(sv.DTB);
	cout << endl;
}
void XuatDSSV(SinhVien sv[], int n) {
	cout << "Danh sach sinh vien: ";
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << "Sinh vien thu " << i;
		cout << endl;
		XuatSV(sv[i]);
	}
}
void ThemSVDau(SinhVien sv[], int& n) {
		for (int i = n; i > 0; i--) {
			sv[i] = sv[i - 1];
		}
		NhapSV(sv[0]); 
		n++;
}
void ThemSVCuoi(SinhVien sv[], int& n) {
	NhapSV(sv[n]);
	n++;
}

void ThemSV_Giua(SinhVien sv[], int &n, int pos) {

		for (int i = n; i > pos; i--) {
			sv[i] = sv[i - 1];
		}
		NhapSV(sv[pos]);
		n++;
	
}

void XoaSV_Dau(SinhVien sv[], int &n) {
	for (int i = 0; i < n - 1; i++) {
		sv[i] = sv[i + 1];
	}
	n--;
}
void XoaSV_Cuoi(SinhVien sv[], int &n) {
	n--;
}
void XoaSV_Giua(SinhVien sv[], int&n, int pos) {
	for (int i = pos; i < n - 1; i++) {
		sv[i] = sv[i + 1];
	}
	n--;
}
int main() {
	SinhVien sv[MAX];
	int n, pos;
	do {
		cout << "Nhap N: ";
		cin >> n;
	} while (n <= 0);
	NhapDSSV(sv, n);
	cout << endl; 


	/*ThemSVDau(sv, n);*/
	/*ThemSVCuoi(sv, n);*/
	do {
		cout << "Nhap vi tri : ";
		cin >> pos;
	} while (pos < 0 || pos >= n);
	ThemSV_Giua(sv, n, pos);
	/*XoaSV_Dau(sv, n);*/ 
	/*XoaSV_Cuoi(sv, n);*/

	/*do {
		cout << "Nhap vi tri can xoa: ";
	cin >> pos;
	} while (pos < 0 || pos >= n);
	XoaSV_Giua(sv, n, pos);*/
	cout << endl;
	XuatDSSV(sv, n);
	system("pause");
}
	
