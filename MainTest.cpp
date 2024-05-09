#include<iostream>
#include"QuanLyThuVien.cpp"
using namespace std;

QuanLyThuVien qltv;

bool actionWithLastChoice(){
	cout << "\n\nNhap hanh dong" << endl;
	cout << "1. Quay Ve trang chu" << endl;
	cout << "2. Thoat" << endl;	
	int choice;
	cin >> choice; 
	cin.ignore();
	if(choice == 2){
		return true;
	}
	return false;
}

bool actionWithThuThu(){
	cout << endl;
	cout << "1. Them thu thu" << endl;
	cout << "2. Xoa thu thu" << endl;
	cout << "3. Danh sach thu thu" << endl;
	cout << "4. Quay Lai" << endl;
	cout << "Chon thao tac: "; 
	int choice; cin >> choice; cin.ignore();
	if(choice == 1){
		qltv.themThuThu();
	} else if(choice == 2){
		qltv.xoaThuThu();
	} else if(choice == 3){
		qltv.printListThuThu();
	} else if(choice == 4){
		return false;
	}
	return actionWithLastChoice();
}

bool actionWithSinhVien(){
	cout << endl;
	cout << "1. Them sinh vien" << endl;
	cout << "2. Xoa sinh vien" << endl;
	cout << "3. Danh sach sinh vien" << endl;
	cout << "4. Tra cuu thong tin sinh vien" << endl;
	cout << "5. Quay Lai" << endl;
	cout << "Chon thao tac: "; 
	int choice; cin >> choice; cin.ignore();
	if(choice == 1){
		qltv.themSinhVien();
	} else if(choice == 2){
		qltv.xoaSinhVien();
	} else if(choice == 3){
		qltv.printListSinhVien();
	} else if(choice == 4){
		qltv.thongTinSinhVien();
	} else if(choice == 5){
		return false;
	}
	
	return actionWithLastChoice();
	
}


bool actionWithSach(){
	cout << endl;
	cout << "1. Them sach" << endl;
	cout << "2. Xoa sach" << endl;
	cout << "3. Tim sach" << endl;
	cout << "4. Danh sach the loai sach" << endl;
	cout << "5. Quay Lai" << endl;
	cout << "Chon thao tac: ";
	int choice; cin >> choice; cin.ignore();
	if(choice == 1){
		qltv.themSach();
	} else if(choice == 2){
		qltv.xoaSach();
	} else if(choice == 3){
		qltv.searchBookInfo();
	} else if(choice == 4){
		qltv.printBooksByGenre();
	} else if(choice == 5){
		return false;
	}
	
	return actionWithLastChoice();
}


bool actionWithTacGia(){
	cout << endl;
	cout << "1. Them tac gia" << endl;
	cout << "2. Xoa tac gia" << endl;
	cout << "3. Danh sach tac gia" << endl;
	cout << "4. Quay Lai" << endl;
	cout << "Chon thao tac: ";
	int choice; cin >> choice; cin.ignore();
	if(choice == 1){
		qltv.themTacGia();
	} else if(choice == 2){
		qltv.xoaTacGia();
	} else if(choice == 3){
		qltv.printBooksByAuthorName();
	} else if(choice == 4){
		return false;
	}
	return actionWithLastChoice();
}


bool actionWithTraMuonSach(){
	cout << endl;
	cout << "1. Them phieu muon" << endl;
	cout << "2. Xoa phieu muon" << endl;
	cout << "3. Danh sach phieu muon" << endl;
	cout << "4. Thong tin chi tiet phieu muon" << endl;
	cout << "5. Tra sach" << endl;
	cout << "6. Quay Lai" << endl;
	cout << "Chon thao tac: ";
	int choice; cin >> choice; cin.ignore();
	if(choice == 1){
		qltv.themPhieuMuon();
	} else if(choice == 2){
		qltv.xoaPhieuMuon();
	} else if(choice == 3){
		qltv.printListPhieuMuon();
	} else if(choice == 4){
		qltv.thongTinPhieuMuon();
	} else if(choice == 5){
		qltv.themPhieuTra();
	} else if(choice == 6){
		return false;
	}
	return actionWithLastChoice();
}


bool actionWithCauTruyVan(){
	cout << endl;
    // In ra 8 câu truy vấn
   	cout << "Cau truy van:" << endl;
	cout << "1. Hay lay ra danh sach sach muon cua cac phieu muon co ma thu thu bang tt001?" << endl;
	cout << "2. Hay lay ra nhung sach co the loai la van hoc va duoc them vao tu kho co ma kho la 1?" << endl;
	cout << "3. Hay cho biet 3 cuon sach ma sinh vien muon nhieu nhat trong nam 2024?" << endl;
	cout << "4. Hay cho biet nhung cuon sach co so luong trong thu vien lon hon 15 va lay ra ma tac gia?" << endl;
	cout << "5. Hay cho biet nhung sinh vien muon sach trong nam 2024?" << endl;
	cout << "6. Hay cho biet tong so phieu muon trong nam 2024?" << endl;
	cout << "7. Hay cho biet ma tac gia cua nhung cuon sach co ma the loai la 4?" << endl;
	cout << "8. Quay Lai" << endl;
	cout << "Chon cau truy van: ";
	int choice; cin >> choice; cin.ignore();
	if(choice == 1){
		 qltv.cau1("tt001");
    }else if(choice == 2) {
		qltv.cau2();
	}else if(choice == 3) {
		qltv.cau3();
	}
	else if(choice == 4) {
		qltv.cau4();
	}
	else if(choice == 5) {
        qltv.cau5();
    }else if(choice == 6) {
		qltv.cau6();
	}
	else if(choice == 7) {
		qltv.cau7();
	}
	else if(choice == 8) {
		return false;
	}
	return actionWithLastChoice();
}


void printChoices(){
	cout << endl;
	cout << "1. Thu Thu" << endl;
	cout << "2. Sinh Vien" << endl;
	cout << "3. Sach" << endl;
	cout << "4. Tac Gia" << endl;
	cout << "5. Tra/Muon Sach" << endl;
	cout << "6. Thuc hien cau truy van" << endl;
	cout << "7. Thoat" << endl;
	cout << "Chon doi tuong muon thao tac: ";
}



bool choiceAction(int choice){
    if(choice == 1){
        return actionWithThuThu();
    } else if(choice == 2){
        return actionWithSinhVien();
    } else if(choice == 3){
        return actionWithSach();
    } else if(choice == 4){
        return actionWithTacGia();
    } else if(choice == 5){
        return actionWithTraMuonSach();
    } else if(choice == 6){
        return actionWithCauTruyVan(); 
    } else if(choice == 7){
        return true; 
    }
    return false;
}

int main(){
    bool isEnd = false;
    while(!isEnd){
        printChoices();
        int choice;
        cin >> choice; cin.ignore();
            isEnd = choiceAction(choice);
    }
}

