#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include "sinhvien.cpp"
#include "phieumuon.cpp"

using namespace std;

class QuanLySinhVienMuonSach{
	vector<SinhVien> listSinhVien;
	vector<PhieuMuon> listPhieuMuon;
	
	bool isInListSinhVien(string msv){
		for(SinhVien s: listSinhVien){
			if(s.getMaSinhVien() == msv){
				return true;
			}
		}
		return false;
	}
	bool isInListPhieuMuon(string mpm){
		for(PhieuMuon s: listPhieuMuon){
			if(s.getMaPhieuMuon() == mpm){
				return true;
			}
		}
		return false;
	}
	
	
public:
	QuanLySinhVienMuonSach(){
		//read data
		getSinhVienDataFromFile("inputSinhVien.txt");
		getPhieuMuonDataFromFile("inputPhieuMuon.txt");
	}
	
	~QuanLySinhVienMuonSach(){
		//write data
		writeSinhVienDataToFile("inputSinhVien.txt");
		writePhieuMuonDataToFile("inputPhieuMuon.txt");
	}

	
    vector<PhieuMuon> getListPhieuMuon() {
        return listPhieuMuon;
    }
	
	void getSinhVienDataFromFile(string filePath){
		fstream file;
		file.open(filePath, ios::in);
		if (!file.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		
		string sNumberOfStudent;
		getline(file, sNumberOfStudent);
		int numberOfStudent = stoi(sNumberOfStudent);
		
		for(int i=0; i<numberOfStudent; i++){
			string maSV;
			string lopSV;
			string tenSV;
			getline(file, maSV);
			getline(file, tenSV);
			getline(file, lopSV);
			SinhVien sv(maSV, tenSV, lopSV);
			listSinhVien.push_back(sv);
		}
		
		file.close();
	}

	void writeSinhVienDataToFile(string filePath){
		fstream file;
		file.open(filePath, ios::out);
		if (!file.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		
		file << listSinhVien.size() << endl;
		
		for(SinhVien sv: listSinhVien){
			file << sv.getMaSinhVien() << endl;
			file << sv.getTenSinhVien() << endl;
			file << sv.getTenLop() << endl;
		}
		
		file.close();
	}

	void getPhieuMuonDataFromFile(string filePath){
		fstream file;
		file.open(filePath, ios::in);
		if (!file.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		
		string sNumberOfPhieuMuon;
		getline(file, sNumberOfPhieuMuon);
		int numberOfPhieuMuon = stoi(sNumberOfPhieuMuon);
		
		for(int i = 0; i < numberOfPhieuMuon; i++){
			string maPhieuMuon;
			string maThuThu;
			string maSinhVien;
			string ngayMuon;
			string ngayTra;
			string elemSach;
			getline(file, maPhieuMuon);
			getline(file, maThuThu);
			getline(file, maSinhVien);
			getline(file, ngayMuon);
			getline(file, ngayTra);
			vector<string> listSachMuon;
			while(true){
				file >> elemSach;
				if(elemSach == "end"){
					break;
				}
				listSachMuon.push_back(elemSach);
			}
			PhieuMuon pm(maPhieuMuon, maThuThu, maSinhVien, ngayMuon, ngayTra);
			pm.setDanhSachMuon(listSachMuon);
			listPhieuMuon.push_back(pm);
			file.ignore();
		}
		file.close();
	}

	void writePhieuMuonDataToFile(string filePath){
		fstream file;
		file.open(filePath, ios::out);
		if (!file.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		
		file << listPhieuMuon.size() << endl;
		for(PhieuMuon pm: listPhieuMuon){
			file << pm.getMaPhieuMuon() << endl;
			file << pm.getMaThuThu() << endl;
			file << pm.getMaSinhVien() << endl;
			file << pm.getNgayMuon() << endl;
			file << pm.getNgayTra() << endl;
			for(string ma: pm.getDanhSachSachMuon()){
				file << ma << " ";
			}
			file << "end" << endl;
		}
		
		file.close();
	}

	void themSinhVien(){
		SinhVien sv;
		sv.nhap();
		if(!isInListSinhVien(sv.getMaSinhVien())){
			listSinhVien.push_back(sv);
			cout << "Them sinh vien thanh cong" << endl;
		} else{
			cout << "Ma sinh vien da ton tai" << endl;
		}
	}
	
	void xoaSinhVien(){
		cout << "Nhap ma sinh vien muon xoa: " << endl;
		string maSinhVien;
		getline(cin, maSinhVien);
		if(!isInListSinhVien(maSinhVien)){
			cout << "Khong tim thay sinh vien can xoa" << endl;
		} else{
			for(int i = 0; i < listSinhVien.size(); i++){
				if(listSinhVien.at(i).getMaSinhVien() == maSinhVien){
					listSinhVien.erase(listSinhVien.begin()+i);
					cout << "Xoa sinh vien thanh cong" << endl;
					return;
				}
			}
		}
	}
	
	void printListSinhVien(){
		for(SinhVien s: listSinhVien){
			s.xuat();
		}
	}
	
	void themPhieuMuon(){
		PhieuMuon pm;
		pm.nhap();
		if(!isInListPhieuMuon(pm.getMaPhieuMuon())){
			listPhieuMuon.push_back(pm);
			cout << "Them phieu muon thanh cong" << endl;
		} else{
			cout << "Ma phieu muon da ton tai" << endl;
		}
	}
	
	void xoaPhieuMuon(){
		cout << "Nhap ma phieu muuon muon xoa: " << endl;
		string maPhieuMuon;
		getline(cin, maPhieuMuon);
		if(!isInListPhieuMuon(maPhieuMuon)){
			cout << "Khong tim thay phieu muon can xoa" << endl;
		} else{
			for(int i = 0; i < listSinhVien.size(); i++){
				if(listPhieuMuon.at(i).getMaPhieuMuon() == maPhieuMuon){
					listPhieuMuon.erase(listPhieuMuon.begin()+i);
					cout << "Xoa phieu muon thanh cong" << endl;
					return;
				}
			}
		}
	}
	
	
	void printListPhieuMuon(){
		for(PhieuMuon pm: listPhieuMuon){
			pm.xuat();
		}
	}
	
	void thongTinPhieuMuon(){
		string maPhieuMuon;
		cout << "Nhap ma phieu muon: ";
		getline(cin, maPhieuMuon);
		
		if(!isInListPhieuMuon(maPhieuMuon)){
			cout << "Khong tim thay ma phieu muon" << endl;
			return;
		}
		
		for(auto pm: listPhieuMuon){
			if(pm.getMaPhieuMuon() == maPhieuMuon){
				pm.xuat();
				return;
			}
		}
		
	}
	
	void thongTinSinhVien(){
		string maSinhVien;
		cout << "Nhap ma sinh vien can tim kiem: ";
		getline(cin, maSinhVien);
		
		if(!isInListSinhVien(maSinhVien)){
			return;
		}
		cout << "Thong tin sinh vien: " << endl;
		for(auto sv: listSinhVien){
			if(sv.getMaSinhVien() == maSinhVien){
				sv.xuat();
				break;
			}
		}
		
		cout << "Cac phieu muon cua sinh vien: " << endl;
		int soPhieu = 0;
		for(auto pm: listPhieuMuon){
			if(pm.getMaSinhVien() == maSinhVien){
				pm.xuat();
				soPhieu++;
			}
		}
		if(soPhieu == 0){
			cout << "Sinh vien khong co phieu muon nao" << endl;		
		}
	}
};
