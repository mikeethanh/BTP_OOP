#include <bits/stdc++.h>
using namespace std;

class ThuThu {
    string maThuThu;
    string tenThuThu;
    string soDienThoaiThuThu;
public:
    ThuThu(string maThuThu = "", string tenThuThu = "", string soDienThoaiThuThu = "") {
        this->maThuThu = maThuThu;
        this->tenThuThu = tenThuThu;
        this->soDienThoaiThuThu = soDienThoaiThuThu;
    }

    string getMaThuThu() { return maThuThu; }
    string getTenThuThu() { return tenThuThu; }
    string getSoDienThoaiThuThu() { return soDienThoaiThuThu; }

    bool isValidPhoneNumber(const string& phoneNumber) {
    // Số điện thoại hợp lệ nếu có đúng 10 hoặc 11 chữ số và tất cả các ký tự là số
    if (phoneNumber.length() != 10 && phoneNumber.length() != 11)
        return false;
    for (char c : phoneNumber) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

    bool isValidMaThuThu(const string& maTT) {
        // Mã thủ thư hợp lệ nếu có đúng định dạng ttXXX
        if (maTT.length() != 5 || maTT.substr(0, 2) != "tt")
            return false;
        for (int i = 2; i < 5; ++i) {
            if (!isdigit(maTT[i]))
                return false;
        }
        return true;
    }

    void nhap() {
        do {
            cout << "Nhap ma thu thu (theo dinh dang ttXXX): "; 
            getline(cin, maThuThu);
            if (!isValidMaThuThu(maThuThu))
                cout << "Ma thu thu khong hop le. Vui long nhap lai.\n";
        } while (!isValidMaThuThu(maThuThu));

        cout << "Nhap ten thu thu: "; getline(cin, tenThuThu);
        do {
            cout << "Nhap so dien thoai thu thu: "; 
            getline(cin, soDienThoaiThuThu);
            if (!isValidPhoneNumber(soDienThoaiThuThu))
                cout << "So dien thoai khong hop le. Vui long nhap lai.\n";
        } while (!isValidPhoneNumber(soDienThoaiThuThu));
    }

    void xuat() {
        cout << maThuThu << " " << tenThuThu << " " << soDienThoaiThuThu << endl;
    }
};
