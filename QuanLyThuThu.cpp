#include<iostream>
#include<vector>
#include "thuthu.cpp"

using namespace std;

class QuanLyThuThu{
public:	
	vector<ThuThu> listThuThu;
	
	QuanLyThuThu(){
		getThuThuDataFromFile("inputThuThu.txt");
	}
	
	~QuanLyThuThu(){
		writeThuThuDataToFile("inputThuThu.txt");
	}
	
	
	// check is in list
	
	bool isInListThuThu(string maThuThu){
		for(auto tt: listThuThu){
			if(tt.getMaThuThu() == maThuThu){
				return true;
			}
		}
		return false;
	}
	
	// get
	
	void getThuThuDataFromFile(string filePath){
		fstream file;
		file.open(filePath, ios::in);
		if (!file.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		
		string sNumberOfTT;
		getline(file, sNumberOfTT);
		int numberOfTT = stoi(sNumberOfTT);
		
		for(int i=0; i<numberOfTT; i++){
			string maTT;
			string sdtTT;
			string tenTT;
			getline(file, maTT);
			getline(file, tenTT);
			getline(file, sdtTT);
			ThuThu tt(maTT, tenTT, sdtTT);
			listThuThu.push_back(tt);
		}
		
		file.close();
	}
	
	// write

	void writeThuThuDataToFile(string filePath){
		fstream file;
		file.open(filePath, ios::out);
		if (!file.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		
		file << listThuThu.size() << endl;
		
		for(auto tt: listThuThu){
			file << tt.getMaThuThu() << endl;
			file << tt.getTenThuThu() << endl;
			file << tt.getSoDienThoaiThuThu() << endl;
		}
		
		file.close();
	}


	// them
	
	void themThuThu(){
		ThuThu tt;
		tt.nhap();
		
		if(!isInListThuThu(tt.getMaThuThu())){
			listThuThu.push_back(tt);
			cout << "Them thu thu thanh cong" << endl;
		} else{
			cout << "Ma thu thu da ton tai" << endl;	
		}
	}
	
	//xoa
	
	void xoaThuThu(){
		string maThuThu;
		cout << "Nhap ma thu thu muon xoa: ";
		getline(cin, maThuThu);
		
		if(!isInListThuThu(maThuThu)){
			cout << "Khong tim thay thu thu can xoa" << endl;
			return;
		}
		
		for(int i = 0; i < listThuThu.size(); i++){
			ThuThu tt = listThuThu.at(i);
			if(tt.getMaThuThu() == maThuThu){
				listThuThu.erase(listThuThu.begin()+i);
				cout << "Xoa thu thu thanh cong" << endl;
				return;
			}
		}
	}
	
	// print lists
	
	void printListThuThu(){
		for(ThuThu tt: listThuThu){
			tt.xuat();
		}
	}
	
		
	void printListMaThuThu(){
		for(auto tt: listThuThu){
			cout << tt.getMaThuThu() << " ";
		}
		cout << endl;
	}
	
};
