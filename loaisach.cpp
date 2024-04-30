#include <bits/stdc++.h>
using namespace std;

class LoaiSach {
    string maLoaiSach;
    string tenLoaiSach;
public:
    LoaiSach(string maLoaiSach = "") {
        this->maLoaiSach = maLoaiSach;
        setTenLoaiSach();
    }

    string getMaLoaiSach() { return maLoaiSach; }
    string getTenLoaiSach() { return tenLoaiSach; }

    void setTenLoaiSach() {
        if (maLoaiSach == "1") {
            tenLoaiSach = "Sach van hoc";
        } else if (maLoaiSach == "2") {
            tenLoaiSach = "Sach khoa hoc tu nhien";
        } else if (maLoaiSach == "3") {
            tenLoaiSach = "Sach giao trinh";
        } else if (maLoaiSach == "4") {
            tenLoaiSach = "Sach ky nang song";
        } else if (maLoaiSach == "5") {
            tenLoaiSach = "Sach tam ly";
        } else if (maLoaiSach == "6") {
            tenLoaiSach = "Sach ky thuat";
        } else if (maLoaiSach == "7") {
            tenLoaiSach = "Sach Ngoai ngu";
        } else {
            tenLoaiSach = "";
        }
    }

    void nhap() {
        cout << "Nhap ma loai sach: "; getline(cin, maLoaiSach);
        setTenLoaiSach();
    }

    void xuat() {
        cout << maLoaiSach << " " << tenLoaiSach << endl;
    }
};