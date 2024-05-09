#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include "sinhvien.cpp"
#include "phieumuon.cpp"
#include "phieutra.cpp"

using namespace std;

class QuanLySinhVienMuonSach{
public:
	vector<SinhVien> listSinhVien;
	vector<PhieuMuon> listPhieuMuon;	
	vector<PhieuTra> listPhieuTra;
	
	QuanLySinhVienMuonSach(){
		//read data
		getSinhVienDataFromFile("inputSinhVien.txt");
		getPhieuMuonDataFromFile("inputPhieuMuon.txt");
        getPhieuTraDataFromFile("inputPhieuTra.txt");
	}
	
	~QuanLySinhVienMuonSach(){
		//write data
		writeSinhVienDataToFile("inputSinhVien.txt");
		writePhieuMuonDataToFile("inputPhieuMuon.txt");
        writePhieuTraDataToFile("inputPhieuTra.txt");
	}
	
	
	//Check is in lists
	bool isInListSinhVien(string msv){
		for(SinhVien s: listSinhVien){
			if(s.getMaSinhVien() == msv){
				return true;
			}
		}
		return false;
	}
	bool isInListPhieuTra2(string mpt){
		for(PhieuTra s: listPhieuTra){
			if(s.getMaPhieuTra() == mpt){
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
	
	//print lists
	void printListSinhVien(){
		for(SinhVien s: listSinhVien){
			s.xuat();
		}
	}
	
	void printListPhieuMuon(){
		for(PhieuMuon pm: listPhieuMuon){
			pm.xuat();
		}
	}
	
	void printListMaSinhVien(){
		for(SinhVien s: listSinhVien){
			cout << s.getMaSinhVien() << " ";
		}
		cout << endl;
	}
	
	void printListMaPhieuMuon(){
		for(PhieuMuon pm: listPhieuMuon){
			cout << pm.getMaPhieuMuon() << " ";
		}
		cout << endl;
	}
	
	void printListPhieuTra(){
		for(PhieuTra pt: listPhieuTra){
			pt.xuat();
		}
	}
	
	
	// get
	vector<PhieuTra> getListPhieuTra() {
        return listPhieuTra;
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
			string elemSach;
			getline(file, maPhieuMuon);
			getline(file, maThuThu);
			getline(file, maSinhVien);
			getline(file, ngayMuon);
			vector<string> listSachMuon;
			while(true){
				file >> elemSach;
				if(elemSach == "end"){
					break;
				}
				listSachMuon.push_back(elemSach);
			}
			PhieuMuon pm(maPhieuMuon, maThuThu, maSinhVien, ngayMuon);
			pm.setDanhSachMuon(listSachMuon);
			listPhieuMuon.push_back(pm);
			file.ignore();
		}
		file.close();
	}
	
	void getPhieuTraDataFromFile(string filePath){
		fstream file;
		file.open(filePath, ios::in);
		if (!file.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		
		string sNumberOfPhieuTra;
		getline(file, sNumberOfPhieuTra);
		int numberOfPhieuTra = stoi(sNumberOfPhieuTra);
		
		for(int i = 0; i < numberOfPhieuTra; i++){
			string maPhieuTra;
			string maThuThu;
			string maSinhVien;
			string ngayTra;
			string elemSach;
			getline(file, maPhieuTra);
			getline(file, maThuThu);
			getline(file, maSinhVien);
			getline(file, ngayTra);
			vector<string> listSachTra;
			while(true){
				file >> elemSach;
				if(elemSach == "end"){
					break;
				}
				listSachTra.push_back(elemSach);
			}
			PhieuTra pt(maPhieuTra, maThuThu, maSinhVien, ngayTra);
			pt.setDanhSachTra(listSachTra);
			listPhieuTra.push_back(pt);
			file.ignore();
		}
		file.close();
	}
	
	PhieuMuon getPhieuMuonByMa(string maPhieuMuon){
		for(PhieuMuon pm: listPhieuMuon){
			if(pm.getMaPhieuMuon() == maPhieuMuon){
				return pm;
			}
		}
	}
	
	
	
	//write
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
			for(string ma: pm.getDanhSachSachMuon()){
				file << ma << " ";
			}
			file << "end" << endl;
		}
		
		file.close();
	}
	
	void writePhieuTraDataToFile(string filePath){
		fstream file;
		file.open(filePath, ios::out);
		if (!file.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		
		file << listPhieuTra.size() << endl;
		for(PhieuTra pt : listPhieuTra){
			file << pt.getMaPhieuTra() << endl;
			file << pt.getMaThuThu() << endl;
			file << pt.getMaSinhVien() << endl;
			file << pt.getNgayTra() << endl;
			for(string ma : pt.getDanhSachSachTra()){
				file << ma << " ";
			}
			file << "end" << endl;
		}
		
		file.close();
	}
	
	//them

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
	
	//xoa
	
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
	
	void xoaPhieuMuon(){
		cout << "Nhap ma phieu muon muon xoa: " << endl;
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
	
	void xoaPhieuTra(){
		cout << "Nhap ma phieu tra muon xoa: " << endl;
		string maPhieuTra;
		getline(cin, maPhieuTra);
		if(!isInListPhieuTra2(maPhieuTra)){
			cout << "Khong tim thay phieu tra can xoa" << endl;
		} else{
			for(int i = 0; i < listSinhVien.size(); i++){
				if(listPhieuTra.at(i).getMaPhieuTra() == maPhieuTra){
                    string maPhieuMuon = "pm" + maPhieuTra.substr(2);
					listPhieuTra.erase(listPhieuTra.begin()+i);
					cout << "Xoa phieu muon thanh cong" << endl;
					return;
				}
			}
		}
	}

	// thong tin
	
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
	
	void thongTinPhieuTra(){
		string maPhieuTra;
		cout << "Nhap ma phieu tra: ";
		getline(cin, maPhieuTra);
		
		if(!isInListPhieuTra2(maPhieuTra)){
			cout << "Khong tim thay ma phieu tra" << endl;
			return;
		}
		
		for(auto pt: listPhieuTra){
			if(pt.getMaPhieuTra() == maPhieuTra){
				pt.xuat();
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
		int soPhieuMuon = 0;
		for(auto pm: listPhieuMuon){
			if(pm.getMaSinhVien() == maSinhVien){
				pm.xuat();
				soPhieuMuon++;
			}
		}
		if(soPhieuMuon == 0){
			cout << "Sinh vien khong co phieu muon nao" << endl;		
		}
		
		cout << "Cac phieu tra cua sinh vien: " << endl;
		int soPhieuTra = 0;
		for(auto pt: listPhieuTra){
			if(pt.getMaSinhVien() == maSinhVien){
				pt.xuat();
				soPhieuTra++;
			}
		}
		
		if(soPhieuTra == 0){
			cout << "Sinh vien khong co phieu tra nao" << endl;		
		}
	}
	
	void thongTinSinhVienTraSach(){
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
		
		cout << "Cac phieu tra cua sinh vien: " << endl;
		int soPhieu = 0;
		for(auto pt: listPhieuTra){
			if(pt.getMaSinhVien() == maSinhVien){
				pt.xuat();
				soPhieu++;
			}
		}
		if(soPhieu == 0){
			cout << "Sinh vien khong co phieu tra nao" << endl;		
		}
	}
};
