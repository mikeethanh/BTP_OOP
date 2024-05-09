#include <bits/stdc++.h>

#pragma once
using namespace std;

class SinhVien {
    string maSinhVien;
    string tenSinhVien;
    string tenLop;
public:
    SinhVien(string maSinhVien = "", string tenSinhVien = "", string tenLop = "") {
        this->maSinhVien = maSinhVien;
        this->tenSinhVien = tenSinhVien;
        this->tenLop = tenLop;
    }

    string getMaSinhVien() { return maSinhVien; }
    string getTenSinhVien() { return tenSinhVien; }
    string getTenLop() { return tenLop; }

    bool isValidMaSinhVien(const string& maSV) {
        // Mã sinh viên hợp lệ nếu có đúng định dạng svXXX
        if (maSV.length() != 5 || maSV.substr(0, 2) != "sv")
            return false;
        for (int i = 2; i < 5; ++i) {
            if (!isdigit(maSV[i]))
                return false;
        }
        return true;
    }

    void nhap() {
        do {
            cout << "Nhap ma sinh vien (theo dinh dang svXXX): "; 
            getline(cin, maSinhVien);
            if (!isValidMaSinhVien(maSinhVien))
                cout << "Ma sinh vien khong hop le. Vui long nhap lai.\n";
        } while (!isValidMaSinhVien(maSinhVien));

        cout << "Nhap ten sinh vien: "; getline(cin, tenSinhVien);
        cout << "Nhap ten lop: "; getline(cin, tenLop);
    }

    void xuat() {
        cout << maSinhVien << " " << tenSinhVien << " " << tenLop << endl;
    }
};
