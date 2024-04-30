#include<iostream>
#include<vector>
#include<fstream>
#include <string>  
#include "sach.cpp"
#include "tacgia.cpp"
#include "loaisach.cpp"
#include "kho.cpp"


using namespace std;

class QuanLySachVaTacGia{
	vector<Sach> listSach;
	vector<LoaiSach> listLoaiSach;
	vector<TacGia> listTacGia;
	vector<Kho> listKho;
	
	bool isInListTacGia(string maTacGia){
		for(TacGia tg: listTacGia){
			if(tg.getMaTacGia() == maTacGia) {
				return true;
			}
		}
		return false;
	}
	
	bool isInListKho(string maKho){
		for(Kho k: listKho){
			if(k.getMaKho() == maKho) {
				return true;
			}
		}
		return false;
	}
	
	bool isInListSach(string maSach){
		for(Sach s: listSach){
			if(s.getMaSach() == maSach){
				return true;
			}
		}
		return false;
	}
	
	bool isInListLoaiSach(string maLoaiSach){
		for(LoaiSach ls: listLoaiSach){
			if(ls.getMaLoaiSach() == maLoaiSach){
				return true;
			}
		}
		return false;
	}
	
	
public:
    vector<Sach> getListSach() {
        return listSach;
    }
	vector<LoaiSach> getListLoaiSach(){
        return listLoaiSach;
    }

	void getBooksDataFromFile(string filePath){
		fstream file;
		file.open(filePath, ios::in);
		
		if (!file.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		
		string strNumberOfBooks;
		getline(file, strNumberOfBooks);
		int numberOfBooks = stoi(strNumberOfBooks);
		for(int i = 0; i < numberOfBooks; i++){
			string maSach;
			getline(file, maSach);
			string tenSach;
			getline(file, tenSach);
			string maKho;
			getline(file, maKho);
			string soLuong;
			getline(file, soLuong);
			string namXuatBan;
			getline(file, namXuatBan);
			string maLoaiSach;
			getline(file, maLoaiSach);
			string maTacGia;
			getline(file, maTacGia);
			Sach s(maSach, tenSach, maKho, stoi(soLuong), stoi(namXuatBan), maLoaiSach, maTacGia);
			themSach(s);
		}
		
		file.close();
	}

	void getAuthorDataFromFile(string filePath){
		fstream file;
		file.open(filePath, ios::in);
		
		if (!file.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		
		string strNumberOfAuthors;
		getline(file, strNumberOfAuthors);
		int numberOfAuthors = stoi(strNumberOfAuthors);
		
		for(int i = 0; i < numberOfAuthors; i++){
			string maTacGia;
			string tenTacGia;
			string sdtTacGia;
			getline(file, maTacGia);
			getline(file, tenTacGia);
			getline(file, sdtTacGia);
			TacGia tg(maTacGia, tenTacGia, sdtTacGia);
			themTacGia(tg);
		}
		file.close();
	}

	
	void writeBooksDataToFile(string filePath){
		fstream file;
		file.open(filePath, ios::out);
		if (!file.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		file << listSach.size() << endl;
		for(int i = 0; i < listSach.size(); i++){
			Sach s = listSach.at(i);
			file << s.getMaSach() << endl;
			file << s.getTenSach() << endl;
			file << s.getMaKho() << endl;
			file << s.getSoLuong() << endl;
			file << s.getNamXuatBan() << endl;
			file << s.getMaLoaiSach() << endl;
			file << s.getMaTacGia() << endl;
		}
		file.close();
	}

	void writeAuthorsDataToFile(string filePath){
		fstream file;
		file.open(filePath, ios::out);
		if (!file.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		file << listTacGia.size() << endl;
		for(TacGia tg: listTacGia){
			file << tg.getMaTacGia() << endl;
			file << tg.getTenTacGia() << endl;
			file << tg.getSoDienThoaiTacGia() << endl;
		}
		file.close();
	}

	QuanLySachVaTacGia(){
		getAuthorDataFromFile("inputTacGia.txt");
		getBooksDataFromFile("inputSach.txt");
	}

	~QuanLySachVaTacGia(){
		writeBooksDataToFile("inputSach.txt");
		writeAuthorsDataToFile("inputTacGia.txt");
	}

	void xoaTacGia(){
		cout << "Nhap ma tac gia can xoa: " << endl;
		string maTacGiaIn;
		getline(cin, maTacGiaIn);
		if(!isInListTacGia(maTacGiaIn)){
			cout << "Khong tim thay tac gia can xoa /n";
		} else{
			for(int i = 0; i < listTacGia.size(); i++){
				if(maTacGiaIn == listTacGia.at(i).getMaTacGia()){
					listTacGia.erase(listTacGia.begin()+i);
					break;
				}
			}
			cout << "Xoa tac gia thanh cong" << endl;
		}	
	}
	

	
	void themTacGia(){
		TacGia tg;
		tg.nhap();
		if(!isInListTacGia(tg.getMaTacGia())){
			listTacGia.push_back(tg);
			cout << "Tac gia da them thanh cong" << endl; 
		} else{
			cout << "Tac gia da ton tai trong danh sach" << endl;
		}
	}
	
	void themTacGia(TacGia tg){
		if(!isInListTacGia(tg.getMaTacGia())){
			listTacGia.push_back(tg);
		}
	}
	
	
	void printListTacGia(){
		int i = 1;
		for(TacGia tg: listTacGia){
			cout << i << ". ";
			tg.xuat();
			i++;
		}
	}
	
	void printBooksByAuthorName(){
		cout << "Danh sach cac tac gia va tac pham: " << endl;
		for(TacGia tg: listTacGia){
			cout << "Tac gia: " << tg.getTenTacGia() << endl;
			cout << "Cac dau sach: " << endl;
			for(Sach s: listSach){
				if(s.getMaTacGia() == tg.getMaTacGia()){
					cout << s.getTenSach() << " | "; 
				}
			}
			cout << endl;
		}
	}
	
	void updateKhoValue(){
		listKho.clear();
		for(Sach s: listSach){
			if(!isInListKho(s.getMaKho())){
				Kho k(s.getMaKho());
				listKho.push_back(k);
			}
		}
	}
	
	void updateLoaiSach(){
		listLoaiSach.clear();
		for(Sach s: listSach){
			if(!isInListLoaiSach(s.getMaLoaiSach())){
				LoaiSach ls(s.getMaLoaiSach());
				listLoaiSach.push_back(ls);
			}
		}
	}
	
	string getTenKhoHienCo(string maKho){
		for(Kho k: listKho){
			if(k.getMaKho() == maKho){
				return k.getTenKho();
			}
		}
		return "";
	}
	
	void searchBookInfo(){
		string maSach;
		cout << "Nhap ma sach can tim: " << endl;
		getline(cin, maSach);
		
		if(!isInListSach(maSach)){
			cout << "Khong tim thay sach" << endl;
			return;
		}
		
		for(Sach s: listSach){
			if(s.getMaSach()==maSach){
				cout << "Ten sach: " << s.getTenSach() << ", so luong: " << s.getSoLuong() << ", kho: " << getTenKhoHienCo(s.getMaKho()) << endl;
			}
		}
	}
	
	void printListSach(){
		for(auto x: listSach){
			x.xuat();
		}
	}
	
	
	void printListLoaiSach(){
		for(auto x: listLoaiSach){
			x.xuat();
		}
	}


	
	void printBooksByGenre(){
		cout << "Danh sach cac the loai va tac pham: " << endl;
		for(LoaiSach ls: listLoaiSach){
			cout << "The loai: " << ls.getTenLoaiSach() << endl;
			cout << "Cac dau sach: " << endl;
			for(Sach s: listSach){
				if(s.getMaLoaiSach() == ls.getMaLoaiSach()){
					cout << s.getTenSach() << " | "; 
				}
			}
			cout << endl;
		}
	}
		
	void xoaSach(){
		cout << "Nhap ma sach can xoa: " << endl;
		string maSach;
		getline(cin, maSach);
		if(!isInListSach(maSach)){
			cout << "Khong tim sach can xoa /n";
		} else{
			for(int i = 0; i < listSach.size(); i++){
				if(maSach == listSach.at(i).getMaSach()){
					listSach.erase(listSach.begin()+i);
					i = 0;
				}
			}
			cout << "Xoa sach thanh cong" << endl;
			updateKhoValue();
			updateLoaiSach();
		}
	}
	
	void themLoaiSach(string maLoaiSach){
		LoaiSach ls(maLoaiSach);
		listLoaiSach.push_back(ls);
	}
	
	void themKho(string maKho){
		Kho k(maKho);
		listKho.push_back(k);
	}
	
	void themSach(){
		Sach s;
		s.nhap();
		
		if(!isInListTacGia(s.getMaTacGia())){
			cout << "Tac gia chua co trong du lieu, vui long nhap ten tac gia: ";
			string tenTacGia;
			getline(cin, tenTacGia);
			TacGia tg(s.getMaTacGia(), tenTacGia);
			listTacGia.push_back(tg);
		}
		
		if(!isInListLoaiSach(s.getMaLoaiSach())){
			themLoaiSach(s.getMaLoaiSach());
		}
		
		if(!isInListKho(s.getMaKho())){
			themKho(s.getMaKho());
		}
		
		if(isInListSach(s.getMaSach()) and isInListKho(s.getMaKho())){
			for(int i = 0; i < listSach.size(); i++){		
				if(listSach.at(i).getMaSach() == s.getMaSach()){
					listSach.at(i).setSoLuong(s.getSoLuong());
					return;
				}	
			}
		} else{
			listSach.push_back(s);
		}	
	}
	
	void themSach(Sach s){
		if(!isInListLoaiSach(s.getMaLoaiSach())){
			themLoaiSach(s.getMaLoaiSach());
		}
		
		if(!isInListKho(s.getMaKho())){
			themKho(s.getMaKho());
		}
		
		
		if(isInListSach(s.getMaSach()) and isInListKho(s.getMaKho())){
			for(int i = 0; i < listSach.size(); i++){		
				if(listSach.at(i).getMaSach() == s.getMaSach()){
					listSach.at(i).setSoLuong(s.getSoLuong());
					return;
				}	
			}
		} else{
			listSach.push_back(s);
		}
	}
};
