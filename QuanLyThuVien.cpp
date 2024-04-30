#include<iostream>
#include "QuanLySachVaTacGia.cpp"
#include "QuanLyThuThu.cpp"
#include "QuanLySinhVienMuonSach.cpp"

class QuanLyThuVien : public QuanLySachVaTacGia, public QuanLySinhVienMuonSach, public QuanLyThuThu{
};
