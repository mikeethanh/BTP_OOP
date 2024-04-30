#include <bits/stdc++.h>
using namespace std;

class QuanLyCauTruyVan{
private:
    QuanLySinhVienMuonSach qlsvms;
    QuanLySachVaTacGia qlsvtg;

public:
    //1. Hay lay ra danh sach sach muon cua cac phieu muon co ma thu thu bang tt001?
    void cau1(string maThuThu) {
        bool found = false;

        vector<PhieuMuon> listPhieuMuon = qlsvms.getListPhieuMuon();

        cout << "Danh sach sach muon cua cac phieu muon co ma thu thu la " << maThuThu << ":" << endl;
        for (auto pm : listPhieuMuon) {
            if (pm.getMaThuThu() == maThuThu) {
                found = true;
                cout << "Ma phieu muon: " << pm.getMaPhieuMuon() << endl;
                cout << "Danh sach sach muon: ";

                vector<Sach> listSach = qlsvtg.getListSach();

                for (auto maSach : pm.getDanhSachSachMuon()) {
                    for (auto sach : listSach) {
                        if (sach.getMaSach() == maSach) {
                            cout << sach.getTenSach() << ", ";
                        }
                    }
                }
                cout << endl;
            }
        }
        if (!found) {
            cout << "Khong co phieu muon nao tuong ung voi ma thu thu " << maThuThu << endl;
        }
    }

    //2. Hay lay ra nhung sach co the loai la van hoc va duoc them vao tu kho co ma kho la 1?
    void cau2() {
        cout << "Nhung cuon sach co the loai la van hoc va duoc them tu kho co ma kho 1 la :" << endl;

        vector<Sach> listSach = qlsvtg.getListSach();

        for (auto sach : listSach) {
            if (sach.getMaLoaiSach() == "1" && sach.getMaKho() == "1") {
                cout << sach.getTenSach() << endl;
            }
        }
    }

    //3. Hay cho biet 3 cuon sach ma sinh vien muon nhieu nhat trong nam 2024?
    void cau3() {
        cout << "Ba cuon sach sinh vien muon nhieu nhat trong nam 2024 la :" << endl;

        vector<PhieuMuon> listPhieuMuon = qlsvms.getListPhieuMuon();

        unordered_map<string, int> bookCount;

         for (auto pm : listPhieuMuon) {
            int pos = pm.getNgayMuon().find_last_of('/');
            string yearStr = pm.getNgayMuon().substr(pos + 1);
            int year = stoi(yearStr);

            if (year == 2024) {
                for (auto maSach : pm.getDanhSachSachMuon()) {
                    bookCount[maSach]++;
                }
            }
        }

        vector<pair<string, int>> sortedBooks(bookCount.begin(), bookCount.end());

        sort(sortedBooks.begin(), sortedBooks.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
            return a.second > b.second;
        });

        int count = 0;
        for (auto &book : sortedBooks) {
            cout << book.first << ": " << book.second << " lan muon" << endl;
            count++;
            if (count == 3) {
                break;
            }
        }
    }

    //4. Hay cho biet nhung cuon sach co so luong trong thu vien lon hon 15 va lay ra ma tac gia?
    void cau4() {
        cout << "Cac cuon sach co so luong trong thu vien lon hon 15 va ten tac gia cua tung cuon la:" << endl;

        vector<Sach> listSach = qlsvtg.getListSach();

        for (auto &sach : listSach) {
            if (sach.getSoLuong() > 15) {
                cout << sach.getTenSach() << " - Tac gia: " << sach.getMaTacGia() << endl; 
            }
        }
    }

    //5. Hay cho biet nhung sinh vien muon sach trong nam 2024?
    void cau5() {
        cout << "Nhung sinh vien muon sach trong nam 2024 la:" << endl;

        vector<PhieuMuon> listPhieuMuon = qlsvms.getListPhieuMuon();

        for (auto &pm : listPhieuMuon) {
            int pos = pm.getNgayMuon().find_last_of('/');
            string yearStr = pm.getNgayMuon().substr(pos + 1);
            int year = stoi(yearStr);

            if (year == 2024) {
                cout << "Ma sinh vien: " << pm.getMaSinhVien() << endl;
            }
        }
    }

    //6. Hay cho biet tong so phieu muon trong nam 2024?
    void cau6() {
        cout << "Tong so phieu muon trong nam 2024 la: ";

        vector<PhieuMuon> listPhieuMuon = qlsvms.getListPhieuMuon();

        int count = 0;
        for (auto &pm : listPhieuMuon) {
            int pos = pm.getNgayMuon().find_last_of('/');
            string yearStr = pm.getNgayMuon().substr(pos + 1);
            int year = stoi(yearStr);

            if (year == 2024) {
                count++;
            }
        }
        cout << count << endl;
    }

    //7. Hay cho biet ma tac gia cua nhung cuon sach co ma the loai la 4?
    void cau7() {
        cout << "Ma tac gia cua cac cuon sach co ma the loai thu 4 la: " << endl;

        vector<Sach> listSach = qlsvtg.getListSach();

        for (auto &s : listSach) {
            if (s.getMaLoaiSach() == "4") {
                cout << "Ma sach: " << s.getMaSach() << ", Ma tac gia: " << s.getMaTacGia() << endl;
            }
        }
    }
};

// //test
// int main() {
//     QuanLyCauTruyVan quanLy;
//     //quanLy.cau1("tt001");
//     //quanLy.cau2();
//     //quanLy.cau3();
//     //quanLy.cau4();
//     //quanLy.cau5();
//     //quanLy.cau6();
//     //quanLy.cau7();
//     return 0;
// }
