#pragma once

#include <string>   // Khai báo thư viện string để sử dụng chuỗi.

// Khai báo lớp hocsinh.
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

// Hàm kiểm tra tính hợp lệ của điểm.
bool check (int i);
// Hàm nhập giá trị.
void Input (hocsinh &x);
// Hàm tính toán điểm trung bình.
void average (hocsinh x);
