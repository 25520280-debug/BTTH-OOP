#pragma once // Tránh lỗi lặp định nghĩa.
/*
    Tên lớp : frac
    ------------------------------------------------------
    Nội dung :
        - a (long long) : Tử số.
        - b (long long) : Mẫu số.
    ------------------------------------------------------  
    Tính năng của phương thức :
        - setFrac : Thay giá trị cho phân số.
        - getNmr, getDmn : Đọc và trả về giá trị của tử
        số và mẫu số.
*/
class frac {
private:
    long long a, b;
public:
    void setFrac(long long x, long long y);
    long long getNmr();
    long long getDmn();
};
/*  
    Tên hàm : simplyFrac
    ------------------------------------------------------
    Input :
        - a (long long) : Tử số.
        - b (long long) : Mẫu số.
    ------------------------------------------------------
    Output :
        Không trả về giá trị.
    ------------------------------------------------------
    Tính năng :
        - Hàm thay đổi giá trị của a và b về dạng rút gọn
        của chúng.
        - Hàm rút gọn phân số bằng cách lần lượt chia cả tử
        và mẫu với ước chung lớn nhất của chúng.

*/
void simplyFrac(long long &a, long long &b);
/*
    Tên hàm : Input
    ------------------------------------------------------
    Input :
        - x (frac) : Phân số mới cần nhập giá trị.
    ------------------------------------------------------
    Output :
        - Không trả về giá trị.
    ------------------------------------------------------  
    Tính năng :
        - Thay giá trị được nhập từ bàn phím vào phân số
        cần nhập giá trị.
*/
void Input(frac &x);
/*
    Tên hàm : Output
    ------------------------------------------------------
    Input :
        - a (long long) : Tử số.
        - b (long long) : Mẫu số.
    ------------------------------------------------------
    Output :
        - Phân số có tử số a và mẫu số b dưới dạng a/b.
    ------------------------------------------------------  
    Tính năng :
        - Xuất ra màn hình phân số đúng định dạng toán học.
*/
void Output(long long a, long long b);
/*
    Tên hàm : sumFrac
    ------------------------------------------------------
    Input :
        - i (frac) : Phân số đầu tiên.
        - j (frac) : Phân số thứ hai.
    ------------------------------------------------------
    Output :
        - Tổng của hai phân số i và j dưới dạng a/b.
    ------------------------------------------------------  
    Tính năng :
        - Tính toán tổng của hai phân số i và j bằng cách
        quy đồng.

*/
void sumFrac(frac i, frac j);
/*
    Tên hàm : difFrac
    ------------------------------------------------------
    Input :
        - i (frac) : Phân số đầu tiên.
        - j (frac) : Phân số thứ hai.
    ------------------------------------------------------
    Output :
        - Hiệu của hai phân số i và j dưới dạng a/b.
    ------------------------------------------------------  
    Tính năng :
        - Tính toán hiệu của hai phân số i và j bằng cách
        quy đồng.
*/
void difFrac(frac i, frac j);
/*
    Tên hàm : prodFrac
    ------------------------------------------------------
    Input :
        - i (frac) : Phân số đầu tiên.
        - j (frac) : Phân số thứ hai.
    ------------------------------------------------------
    Output :
        - Tích của hai phân số i và j dưới dạng a/b.
    ------------------------------------------------------  
    Tính năng :
        - Tính toán tích của hai phân số i và j.
*/
void prodFrac(frac i, frac j);
/*
    Tên hàm : quoFrac
    ------------------------------------------------------
    Input :
        - i (frac) : Phân số đầu tiên.
        - j (frac) : Phân số thứ hai.
    ------------------------------------------------------
    Output :
        - Thương của hai phân số i và j dưới dạng a/b.
    ------------------------------------------------------  
    Tính năng :
        - Tính toán thương của hai phân số i và j.

*/
void quoFrac(frac i, frac j);
/*
    Tên hàm : outCalFrac
    ------------------------------------------------------
    Input :
        - i (frac) : Phân số đầu tiên.
        - j (frac) : Phân số thứ hai.
    ------------------------------------------------------
    Output :
        - Tổng, hiệu, tích, thương của hai phân số i và j
        dưới dạng a/b.
    ------------------------------------------------------  
    Tính năng :
        - Xuất ra màn hình tổng, hiệu, tích, thương của hai
        phân số.
*/
void outCalFrac(frac i, frac j);
/*
    Tên hàm : maxFrac
    ------------------------------------------------------
    Input :
        - i (frac) : Phân số đầu tiên.
        - j (frac) : Phân số thứ hai.
    ------------------------------------------------------
    Output :
        - Phân số lớn nhất dưới dạng a/b.
    ------------------------------------------------------  
    Tính năng :
        - Tìm phân số lớn nhất bằng cách quy đồng đưa bài
        toán về dạng so sánh hai số nguyên.
*/
void maxFrac(frac i, frac j);
