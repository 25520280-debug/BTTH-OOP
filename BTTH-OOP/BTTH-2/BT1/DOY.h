#pragma once
#include <iostream>

class DOY {
private:
    int iNgay, iThang, iNam;

// Giải thuật: Năm nhuận chia hết cho 400 hoặc (chia hết cho 4 và không chia cho 100).
    bool isLeap(int nam);
// Giải thuật: Sử dụng cấu trúc rẽ nhánh để phân loại số ngày theo tháng.
    int dayInMonth(int thang, int nam);

public:
/*
    Tên phương thức : Nhap
    ----------------------------------------------------------------------------
    Input: Nhập từ bàn phím 3 số nguyên dương lần lượt cho iNgay, iThang, iNam.
    ----------------------------------------------------------------------------
    Output: Không trả về giá trị nhưng có tác dụng gán giá trị vào các biến 
    thành viên của đối tượng.
*/
    void Nhap();
/*
    Tên phương thức : Xuat
    ----------------------------------------------------------------------------
    Input: Các biến thành viên iNgay, iThang, iNam của đối tượng hiện tại.
    ----------------------------------------------------------------------------
    Output: Một chuỗi ký tự có định dạng dd/mm/yyyy in ra terminal.
*/
    void Xuat();

/*
    Tên phương thức : NgayThangNamTiepTheo
    ----------------------------------------------------------------------------
    Input: Một đối tượng NgayTrongNam thuộc lớp DOY.
    ----------------------------------------------------------------------------
    Output: Cập nhật giá trị ngày tiếp theo cho đối tượng hiện tại và in ra 
    màn hình.
    ----------------------------------------------------------------------------
    Hướng giải thuật:
    -   Sao chép: Gán giá trị từ NgayTrongNam sang đối tượng hiện tại (this).
    -   Tăng tiến: Tăng iNgay thêm 1 đơn vị.
    -   Kiểm tra tràn ngày: So sánh iNgay với số ngày tối đa của iThang hiện tại.
    -   Nếu iNgay > MaxDays: Đặt iNgay = 1 và tăng iThang++.
    -   Kiểm tra tràn tháng: Nếu iThang > 12: Đặt iThang = 1 và tăng iNam++.
    -   Xử lý năm nhuận: Sử dụng hàm bổ trợ để xác định tháng 2 có 28 hay 29 ngày.
*/
    void NgayThangNamTiepTheo(DOY NgayTrongNam); 
};
