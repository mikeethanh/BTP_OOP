#include <bits/stdc++.h>
#include "kho.cpp"
#include "loaisach.cpp"
#include "phieumuon.cpp"
#include "sach.cpp"
#include "sinhvien.cpp"
#include "tacgia.cpp"
#include "thuthu.cpp"
using namespace std;

vector<Sach> timSachMuonCuaSinhVien(vector<PhieuMuon> phieumuonList, string maSinhVien, vector<Sach> sachList) {
    vector<Sach> sachMuon;
    for (PhieuMuon phieuMuon : phieumuonList) {
        if (phieuMuon.getMaSinhVien() == maSinhVien) {
            vector<string> danhSachSachMuon = phieuMuon.getDanhSachSachMuon();
            for (string maSach : danhSachSachMuon) {
                for (Sach sach : sachList) {
                    if (sach.getMaSach() == maSach) {
                        sachMuon.push_back(sach);
                    }
                }
            }
        }
    }
    return sachMuon;
}

int main() {
    ThuThu thuthu;
    cout << "Nhap thong tin thu thu:\n";
    thuthu.nhap();
    cout << "Thong tin cua thu thu:\n";
    thuthu.xuat();
    
    cout << "Nhap so luong sach trong thu vien: ";
    int k; cin >> k;
    vector<Sach> sachList(k);
    cin.ignore();
    for(int i = 0; i < k; i++) {
        cout << "Nhap thong tin sach thu " << i + 1 << ":\n";
        sachList[i].nhap();
    }

    cout << "Thong tin cua cac sach trong danh sach:\n";
    for(int i = 0; i < k; i++) {
        sachList[i].xuat();
    }

    cout << "------------------------------------------------------------\n";
    cout << "Nhap so luong sinh vien: ";
    int n; cin >> n;
    vector<SinhVien> sinhvienList(n);
    cin.ignore();
    for(int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        sinhvienList[i].nhap();
    }

    cout << "Thong tin cua cac sinh vien trong danh sach:\n";
    for(int i = 0; i < n; i++) {
        sinhvienList[i].xuat();
    }

    cout << "------------------------------------------------------------\n";
    cout << "Nhap so luong phieu muon: ";
    int m; cin >> m;
    vector<PhieuMuon> phieumuonList(m);
    cin.ignore();
    for(int i = 0; i < m; i++) {
        cout << "Nhap thong tin phieu muon thu " << i + 1 << ":\n";
        phieumuonList[i].nhap();
        cout << "Nhap so luong sach muon: ";
        int p; cin >> p;
        vector<Sach> sachList1(p);
        cin.ignore();
        for(int i = 0; i < p; i++) {
            cout << "Nhap thong tin sach thu " << i + 1 << ":\n";
            sachList1[i].nhap();
            phieumuonList[i].addSachMuon(sachList1[i].getMaSach());
        }
    }

    cout << "Thong tin cua cac phieu muon trong danh sach:\n";
    for(int i = 0; i < m; i++) {
        phieumuonList[i].xuat();
    }

    cout << "------------------------------------------------------------\n";
    string maSinhVien;
    cout << "Nhap ma sinh vien: ";
    cin >> maSinhVien;
    vector<Sach> sachMuon = timSachMuonCuaSinhVien(phieumuonList, maSinhVien, sachList);
    
    cout << "Cac sach duoc muon boi sinh vien " << maSinhVien << ":\n";
    for (Sach sach : sachMuon) {
        sach.xuat();
    }
}