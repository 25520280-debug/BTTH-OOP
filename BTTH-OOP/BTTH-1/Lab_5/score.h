#pragma once // Tránh lỗi lặp định nghĩa.

#include <string>   // Khai báo thư viện string để sử dụng chuỗi.

/*
    Tên lớp : hocsinh
    ------------------------------------------------------
    Nội dung :
        - HT (string) : Họ và tên học sinh.
        - dT (float) : Điểm toán.
        - dV (float) : Điểm văn.
    ------------------------------------------------------  
    Tính năng của phương thức :
        - setHS : Thay giá trị cho điểm toán, điểm văn,
        và họ tên.
        - getV, getT : Đọc và trả về giá trị của điểm toán
        và điểm văn.
*/
class hocsinh
{
    private:
        std :: string HT;   // Họ tên học sinh.
        float dT, dV;       // Điểm toán, điểm văn.
    public:
    //  Phương thức cài đặt các giá trị.
        void setHS (std :: string h, float t, float v);
    // Các phương thức đọc giá trị.
        float getT();
        float getV();
};

/*  
    Tên hàm : check
    ------------------------------------------------------
    Input :
        - i (float) : Điểm cần kiểm tra.
    ------------------------------------------------------
    Output :
        true hoặc false.
    ------------------------------------------------------
    Tính năng :
        - Hàm giúp kiểm tra điểm đã được nhập đúng hay
        chưa.
*/
bool check (float i);
/*  
    Tên hàm : Input
    ------------------------------------------------------
    Input :
        - x (hocsinh) : Học sinh cần nhập thông tin.
    ------------------------------------------------------
    Output :
        Không trả về giá trị.
    ------------------------------------------------------
    Tính năng :
        - Thay thông tin được nhập từ bàn phím vào học sinh
        cần nhập.
*/
void Input (hocsinh &x);
/*
    Tên hàm : average
    ------------------------------------------------------
    Input :
        - x (hocsinh) : Học sinh.
    ------------------------------------------------------
    Output :
        - Trung bình cộng điểm toán và điểm văn của học
        sinh.
    ------------------------------------------------------  
    Tính năng :
        - Tính toán trung bình cộng của hai điểm toán và
        điểm văn.
*/
void average (hocsinh x);
