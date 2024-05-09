#include <bits/stdc++.h>
#include "phieumuon.cpp"
#pragma once
using namespace std;


class PhieuTra {
private:
    string maPhieuTra;
    string maThuThu;
    string maSinhVien;
    string ngayTra; // "DD-MM-YYYY"
    vector<string> danhSachSachTra;
public:
    // Constructor
    PhieuTra(string maPhieuTra, string maThuThu, string maSinhVien, string ngayTra)  {
        this->maPhieuTra = maPhieuTra;
        this->maThuThu = maThuThu;
        this->maSinhVien = maSinhVien;
        this->ngayTra = ngayTra;
    }

    string getMaPhieuTra() { return maPhieuTra; }
    string getMaThuThu() { return maThuThu; }
    string getMaSinhVien() { return maSinhVien; }
    string getNgayTra() { return ngayTra; }
    vector<string> getDanhSachSachTra() { return danhSachSachTra; }
    // Destructor
    ~PhieuTra() {}

    // Method to check if all borrowed books are returned
    bool kiemTraTraDuSach(vector<string> danhSachSachMuon) {
        for (const auto& sach : danhSachSachMuon) {
            bool found = false;
            for (const auto& sachTra : danhSachSachTra) {
                if (sach == sachTra) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Sach " << sach << " chua duoc tra." << endl;
                return false;
            }
        }
        cout << "Tat ca cac sach da duoc tra." << endl;
        return true;
    }

    bool kiemTraQuaHan(PhieuMuon phieuMuon) {
        // Tách ngày mượn sách
        int borrowDay = stoi(phieuMuon.getNgayMuon().substr(0, 2));
        int borrowMonth = stoi(phieuMuon.getNgayMuon().substr(3, 2));
        int borrowYear = stoi(phieuMuon.getNgayMuon().substr(6, 4));

        // Tách ngày trả sách
        int returnDay = stoi(ngayTra.substr(0, 2));
        int returnMonth = stoi(ngayTra.substr(3, 2));
        int returnYear = stoi(ngayTra.substr(6, 4));
        // Tính số ngày từ ngày mượn sách đến ngày trả sách
        int days = (returnYear - borrowYear) * 365 + (returnMonth - borrowMonth) * 30 + (returnDay - borrowDay);

        // Kiểm tra xem có quá 30 ngày hay không
        if (days > 30) {
            cout << "Sach da duoc tra qua han." << endl;
            return true;
        } else {
            cout << "Sach duoc tra dung han." << endl;
            return false;
        }
    }

    void phatNeuThieuSach(vector<string> danhSachSachMuon) {
        if (!kiemTraTraDuSach(danhSachSachMuon)) {
            int soSachMuon = danhSachSachMuon.size();
            int soSachTra = danhSachSachTra.size();
            int soSachThieu = soSachMuon - soSachTra;
            cout << "Ban da tra thieu " << soSachThieu << " cuon sach." << endl;
            
            int phatTien = soSachThieu * 50000; // Giả sử phạt 50000 VND cho mỗi cuốn sách thiếu
            cout << "So tien phat vi tra thieu sach: " << phatTien << " VND." << endl;
        }
    }
    
    void phatNeuQuaHan(PhieuMuon phieuMuon) {
        if (kiemTraQuaHan(phieuMuon)) {
            // Phat tien o day
            int phatTien = 50000; // Giả sử phạt 50000 VND nếu trả sách quá hạn
            cout << "So tien phat vi tra sach qua han: " << phatTien << " VND." << endl;
        }
    }

    void addSachTra(string maSach) {
        danhSachSachTra.push_back(maSach);
    }
    
    void setDanhSachTra(vector<string> listSachTra){
    	this->danhSachSachTra = listSachTra;
	}

    void xuat() {
        cout << maPhieuTra << " " << maThuThu << " " << maSinhVien << " " << ngayTra << " " << endl;
        if(danhSachSachTra.size() > 0) {
            cout << "Danh sach ma sach dc tra trong phieu co ma " << maPhieuTra << ":\n";
            for(auto x : danhSachSachTra) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};
