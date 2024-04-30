#include <bits/stdc++.h>
using namespace std;

class Kho {
    string maKho;
    string tenKho;
public:
    Kho(string maKho = "") {
        this->maKho = maKho;
        setTenKho();
    }

    string getMaKho() { return maKho; }
    string getTenKho() { return tenKho; }

    void setTenKho() {
        if(maKho == "1") {
            tenKho = "A";
        } else if(maKho == "2") {
            tenKho = "B";
        } else if(maKho == "3") {
            tenKho = "C";
        } else if(maKho == "4") {
            tenKho = "D";
        } else {
            tenKho = "";
        }
    }

    void nhap() {
        cout << "Nhap ma kho: "; getline(cin, maKho);
        setTenKho();
    }

    void xuat() {
        cout << maKho << " " << tenKho << endl;
    }
};