#pragma once

class PhanSo {
private:
    int iTu, iMau;
    int GCD(int a, int b);

public:
    /*
        Tên phương thức : Nhap
        ---------------------------------------
        Input: Tử số và mẫu số từ bàn phím.
        ---------------------------------------
        Output: Không trả về giá trị nhưng gán 
        giá trị cho iTu và iMau.
        ---------------------------------------
        Hướng giải thuật: Nhập tử số, sau đó nhập 
        mẫu số. Nếu mẫu số = 0, bắt nhập lại.
    */
    void Nhap();

    /*
        Tên phương thức : RutGon
        ---------------------------------------
        Input: Đối tượng phân số hiện tại.
        ---------------------------------------
        Output: Phân số ở dạng tối giản.
        ---------------------------------------
        Hướng giải thuật: Tìm GCD của tử và 
        mẫu, sau đó chia cả hai cho GCD.
    */
    void RutGon();

    /*
        Tên phương thức : Tong, Hieu, Tich, 
        Thuong.
        ---------------------------------------
        Input: Một đối tượng PhanSo khác.
        ---------------------------------------
        Output: Trả về đối tượng PhanSo là kết 
        quả phép tính.
        ---------------------------------------
        Hướng giải thuật: Áp dụng công thức toán 
        học (ví dụ cộng: a/b + c/d = (ad+bc)/bd),
        sau đó gọi hàm RutGon() trước khi trả về.
    */
    PhanSo Tong(PhanSo b);
    PhanSo Hieu(PhanSo b);
    PhanSo Tich(PhanSo b);
    PhanSo Thuong(PhanSo b);

    /*
        Tên phương thức : SoSanh
        ---------------------------------------
        Input: Một đối tượng PhanSo b.
        ---------------------------------------
        Output: Trả về 1 nếu this > b, 
        -1 nếu this < b, 0 nếu bằng nhau.
        ---------------------------------------
        Hướng giải thuật: Tính hiệu (this - b). 
        Dựa vào dấu của tử số kết quả để kết luận.
    */
    int SoSanh(PhanSo b);
    /*
        Tên phương thức : Xuat
        ---------------------------------------
        Input: Không có.
        ---------------------------------------
        Output: In ra màn hình định dạng 
        Ngay/Thang/Nam.
    */
    void Xuat();
};
