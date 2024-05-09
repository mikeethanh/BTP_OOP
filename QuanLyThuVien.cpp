#include<iostream>
#include <regex>
#include "QuanLySachVaTacGia.cpp"
#include "QuanLyThuThu.cpp"
#include "QuanLySinhVienMuonSach.cpp"
#include "QuanLyCauTruyVan.cpp"


using namespace std;
class QuanLyThuVien : public QuanLySachVaTacGia, public QuanLySinhVienMuonSach, public QuanLyThuThu, public QuanLyCauTruyVan{
public:
	
	// check ngay muon
	bool isValidDate(const string& date) {
 		regex re("(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[012])/[0-9]{4}");
    	return regex_match(date, re);
	}

	void themPhieuMuon(){		
		//tao ma phieu muon
		string maPhieuMuon = "pm";
		if(listPhieuMuon.size() < 9){
			maPhieuMuon += "00";
			maPhieuMuon += to_string(listPhieuMuon.size()+1);
		} else if(listPhieuMuon.size() < 99){
			maPhieuMuon += "0";
			maPhieuMuon += to_string(listPhieuMuon.size()+1);
		} else{
			maPhieuMuon += to_string(listPhieuMuon.size()+1);
		}
		
		
		// nhap ma sinh vien
		string maSinhVien;
		cout << "Nhap ma sinh vien muon sach:" << endl;
		getline(cin, maSinhVien);
		
		while(!isInListSinhVien(maSinhVien)){
			cout << "Ma sinh vien khong ton tai trong he thong!" << endl;
			cout << "Hien dang co cac ma sinh vien sau: " << endl;
			printListMaSinhVien();
			cout << "Nhap lai ma sinh vien muon sach: " << endl;
			getline(cin, maSinhVien);
		}
		
		// nhap ma thu thu
		string maThuThu;
		cout << "Nhap ma thu thu phu trach: " << endl;
		getline(cin, maThuThu);
		
		while(!isInListThuThu(maThuThu)){
			cout << "Ma thu thu khong ton tai trong he thong!" << endl;
			cout << "Hien dang co cac ma thu thu sau: " << endl;
			printListMaThuThu();
			cout << "Nhap lai ma thu thu phu trach: " << endl;
			getline(cin, maThuThu);
		}
		
		
		// nhap ngay muon
		string ngayMuon;
		cout << "Nhap ngay muon sach: " << endl;
		getline(cin, ngayMuon);
		
		while(!isValidDate(ngayMuon)){
			cout << "Dinh dang ngay muon khong dung (dd/mm/yyyy)!!" << endl;
			cout << "Nhap lai ngay muon sach: " << endl;	
			getline(cin, ngayMuon);
		}
		
		PhieuMuon pm(maPhieuMuon, maThuThu, maSinhVien, ngayMuon);
		
		
		// nhap danh sach sach muon
		vector<string> danhSachSachMuon;
		int numberOfBooks;
		cout << "Nhap so luong sach muon: " << endl;
		cin >> numberOfBooks; cin.ignore();
		for(int i = 0; i < numberOfBooks; i++){
			string maSach;
			cout << "Nhap ma sach thu " << i+1 << ": ";
			getline(cin, maSach);
			
			while(!isInListSach(maSach) || getSoLuongSach(maSach)==0){
				cout << "Ma sach khong ton tai hoac khong du so luong sach cho muon!" << endl;
				cout << "Cac ma sach co the muon: " << endl;
				printListMaSach();
				cout << "Nhap lai ma sach thu " << i+1 << ": ";
				getline(cin, maSach);
				
				if(isInListSinhVien(maSach) && getSoLuongSach(maSach)==0){
					cout << "So luong sach khong du xin nhap ma sach khac" << endl;
					continue;
				}
			}
			
			giamSoLuongSach(maSach);
			danhSachSachMuon.push_back(maSach);
		}
		pm.setDanhSachMuon(danhSachSachMuon);
		
		if(!isInListPhieuMuon(pm.getMaPhieuMuon())){
			listPhieuMuon.push_back(pm);
			cout << "Them phieu muon thanh cong" << endl;
		} else{
			cout << "Ma phieu muon da ton tai" << endl;
		}
	}
	
	
	void themPhieuTra(){
		string maPhieuTra = "pt";
		if(listPhieuTra.size() < 9){
			maPhieuTra += "00";
			maPhieuTra += to_string(listPhieuTra.size()+1);
		} else if(listPhieuTra.size() < 99){
			maPhieuTra += "0";
			maPhieuTra += to_string(listPhieuTra.size()+1);
		} else{
			maPhieuTra += to_string(listPhieuTra.size()+1);
		}
		
		// nhap ma thu thu
		string maThuThu;
		cout << "Nhap ma thu thu phu trach: " << endl;
		getline(cin, maThuThu);
		
		while(!isInListThuThu(maThuThu)){
			cout << "Ma thu thu khong ton tai trong he thong!" << endl;
			cout << "Hien dang co cac ma thu thu sau: " << endl;
			printListMaThuThu();
			cout << "Nhap lai ma thu thu phu trach: " << endl;
			getline(cin, maThuThu);
		}
		
		// nhap ma phieu muon
		string maPhieuMuon;
		cout << "Nhap ma phieu muon: " << endl;
		getline(cin, maPhieuMuon);
		
		while(!isInListPhieuMuon(maPhieuMuon)){
			cout << "Ma phieu muon khong ton tai trong he thong!" << endl;
			cout << "Hien dang co cac ma phieu muon sau: " << endl;
			printListMaPhieuMuon();
			cout << "Nhap lai ma phieu muon: " << endl;
			getline(cin, maPhieuMuon);
		}
		PhieuMuon pm = getPhieuMuonByMa(maPhieuMuon);
		
		string ngayTra;
		cout << "Nhap ngay tra sach: " << endl;
		getline(cin, ngayTra);
		
		while(!isValidDate(ngayTra) || ngayTra < pm.getNgayMuon()){
			cout << "Ngay tra som hon ngay muon hoac dinh dang ngay tra khong dung (dd/mm/yyyy)!!" << endl;
			cout << "Nhap lai ngay tra sach: " << endl;	
			getline(cin, ngayTra);
		}
		
		PhieuTra pt(maPhieuTra, maThuThu, pm.getMaSinhVien(), ngayTra);
		
		cout << "So sach tra: ";
		int soSachTra;
		cin >> soSachTra;
		while(soSachTra > pm.getSoSachmuon()){
			cout << "So sach tra vuot qua so sach muon" << endl;
			cout << "Nhap lai so sach tra: " << endl;
			cin >> soSachTra;
		}
		cin.ignore();
		
		vector<string> danhSachSachTra;
		cout << "Cac ma sach phai tra: ";
		pm.printListMaSachMuon();
		string maSachTra;
		for(int i = 0; i < soSachTra; i++){
			cout << "Nhap ma sach tra thu " << i+1 << ": ";
			getline(cin, maSachTra);
			
			while(!pm.isInListSachMuon(maSachTra)){
				cout << "Ma sach muon tra khong hop le" << endl;
				cout << "Cac ma sach da muon: " << endl;
				pm.printListMaSachMuon();
				cout << "Nhap lai ma sach tra thu " << i+1 << ": ";
				getline(cin, maSachTra);
			}
			
			tangSoLuongSach(maSachTra);
			danhSachSachTra.push_back(maSachTra);
		}
		
		pt.setDanhSachTra(danhSachSachTra);
		
		pt.phatNeuThieuSach(pm.getDanhSachSachMuon());
		pt.phatNeuQuaHan(pm);
		
		listPhieuTra.push_back(pt);
	}
};



