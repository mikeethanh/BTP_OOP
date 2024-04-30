#include <bits/stdc++.h>
using namespace std;

class Sach {
    string maSach;
    string tenSach;
    string maKho;
    int soLuong;
    int namXuatBan;
    string maLoaiSach;
    string maTacGia;
public:
    Sach(string maSach = "", string tenSach = "", string maKho = "", int soLuong = 0, 
         int namXuatBan = 0, string maLoaiSach = "", string maTacGia = "") {
        this->maSach = maSach;
        this->tenSach = tenSach;
        this->maKho = maKho;
        this->soLuong = soLuong;
        this->namXuatBan = namXuatBan;
        this->maLoaiSach = maLoaiSach;
        this->maTacGia = maTacGia;
    }

	void setSoLuong(int amount){
		this->soLuong += amount;
	}
	
    string getMaSach() { return maSach; }
    string getTenSach() { return tenSach; }
    string getMaKho() { return maKho; }
    int getSoLuong() { return soLuong; }
    int getNamXuatBan() { return namXuatBan; }
    string getMaLoaiSach() { return maLoaiSach; }
    string getMaTacGia() { return maTacGia; }

    void nhap() {
        cout << "Nhap ma sach: "; getline(cin, maSach);
        cout << "Nhap ten sach: "; getline(cin, tenSach);
        cout << "Nhap ma kho: "; getline(cin, maKho);
        cout << "Nhap so luong: "; cin >> soLuong;
        cout << "Nhap nam xuat ban: "; cin >> namXuatBan;
        cin.ignore();
        cout << "Nhap ma loai sach: "; getline(cin, maLoaiSach);
        cout << "Nhap ma tac gia: "; getline(cin, maTacGia);
    }

    void xuat() {
        cout << maSach << " " << tenSach << " " << maKho << " " << soLuong << " " << namXuatBan << " " << maLoaiSach << " " << maTacGia << endl;
    }
};
