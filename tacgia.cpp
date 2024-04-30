#include <bits/stdc++.h>
using namespace std;

class TacGia {
    string maTacGia;
    string tenTacGia;
    string soDienThoaiTacGia;
public:
    TacGia(string maTacGia = "", string tenTacGia = "", string soDienThoaiTacGia = "") {
        this->maTacGia = maTacGia;
        this->tenTacGia = tenTacGia;
        this->soDienThoaiTacGia = soDienThoaiTacGia;
    }

    string getMaTacGia() { return maTacGia; }
    string getTenTacGia() { return tenTacGia; }
    string getSoDienThoaiTacGia() { return soDienThoaiTacGia; }

    bool isValidMaTacGia(const string& maTG) {
        // Mã tác giả hợp lệ nếu không rỗng
        return !maTG.empty();
    }

    bool isValidPhoneNumber(const string& phoneNumber) {
        // Số điện thoại hợp lệ nếu có đúng 10 chữ số và tất cả các ký tự là số
        if (phoneNumber.length() != 10 || phoneNumber.length() != 11)
            return false;
        for (char c : phoneNumber) {
            if (!isdigit(c))
                return false;
        }
        return true;
    }

    void nhap() {
        do {
            cout << "Nhap ma tac gia: "; 
            getline(cin, maTacGia);
            if (!isValidMaTacGia(maTacGia))
                cout << "Ma tac gia khong hop le. Vui long nhap lai.\n";
        } while (!isValidMaTacGia(maTacGia));

        cout << "Nhap ten tac gia: "; getline(cin, tenTacGia);
        do {
            cout << "Nhap so dien thoai tac gia: "; 
            getline(cin, soDienThoaiTacGia);
            if (!isValidPhoneNumber(soDienThoaiTacGia))
                cout << "So dien thoai khong hop le. Vui long nhap lai.\n";
        } while (!isValidPhoneNumber(soDienThoaiTacGia));
    }

    void xuat() {
        cout << maTacGia << " " << tenTacGia << " " << soDienThoaiTacGia << endl;
    }
};