#pragma once

// Khai báo lớp phân số.
class frac {
private:
    // Khai báo tử số và mẫu số.
    long long a, b;
public:
    // Phương thức cài đặt phân số.
    void setFrac(long long x, long long y);
    // Phương thức đọc giá trị của tử và mẫu của phân số.
    long long getNmr();
    long long getDmn();
};

/*
    Hàm rút gọn phân số bằng cách lần lượt
    chia cả tử và mẫu với ước chung lớn nhất của chúng.
*/
void simplyFrac(long long &a, long long &b);

// Hàm nhập phân số.
void Input(frac &x);

// Hàm xuất và trả về phân số đúng dạng.
void Output(long long a, long long b);

// Hàm tính tổng hai phân số.
void sumFrac(frac i, frac j);

// Hàm tính hiệu hai phân số.
void difFrac(frac i, frac j);

// Hàm tính tích hai phân số.
void prodFrac(frac i, frac j);

// Hàm tính thương hai phân số.
void quoFrac(frac i, frac j);

// Hàm xuất kết quả tổng, hiệu, tích, thương của hai phân số.
void outCalFrac(frac i, frac j);

// Hàm so sánh và trả về phân số lớn nhất.
void maxFrac(frac i, frac j);
