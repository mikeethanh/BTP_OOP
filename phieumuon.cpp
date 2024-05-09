#include <bits/stdc++.h>
#include <vector>
#pragma once
using namespace std;

class PhieuMuon {
    string maPhieuMuon;
    string maThuThu;
    string maSinhVien;
    string ngayMuon;
    vector<string> danhSachSachMuon;
public:
    PhieuMuon(string maPhieuMuon = "", string maThuThu = "", string maSinhVien = "", string ngayMuon = "") {
        this->maPhieuMuon = maPhieuMuon;
        this->maThuThu = maThuThu;
        this->maSinhVien = maSinhVien;
        this->ngayMuon = ngayMuon; 
    }

    string getMaPhieuMuon() { return maPhieuMuon; }
    string getMaThuThu() { return maThuThu; }
    string getMaSinhVien() { return maSinhVien; }
    string getNgayMuon() { return ngayMuon; }
    vector<string> getDanhSachSachMuon() { return danhSachSachMuon; }
    
    void printListMaSachMuon(){
    	for(string maSachMuon: danhSachSachMuon){
    		cout << maSachMuon << " ";
		}
		cout << endl;
	}
	
	bool isInListSachMuon(string maSach){
		for(Sach s: danhSachSachMuon){
			if(s.getMaSach() == maSach){
				return true;
			}
		}
		return false;
	}
    
	int getSoSachmuon(){
		return danhSachSachMuon.size();
	}

    void addSachMuon(string maSach) {
        danhSachSachMuon.push_back(maSach);
    }
    
    void setDanhSachMuon(vector<string> listSachMuon){
    	this->danhSachSachMuon = listSachMuon;
	}

    void nhap() {
        cout << "Nhap ma phieu muon: "; getline(cin, maPhieuMuon);
        cout << "Nhap ma thu thu: "; getline(cin, maThuThu);
        cout << "Nhap ma sinh vien: "; getline(cin, maSinhVien);
        cout << "Nhap ngay muon: "; getline(cin, ngayMuon);
    }

    void xuat() {
        cout << maPhieuMuon << " " << maThuThu << " " << maSinhVien << " " << ngayMuon << " " << endl;
        if(danhSachSachMuon.size() > 0) {
            cout << "Danh sach ma sach dc muon trong phieu co ma " << maPhieuMuon << ":\n";
            for(auto x : danhSachSachMuon) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};

