#pragma once

//  Khai báo lớp ngày trong năm.
class doy
{
    private:
    // Khai báo ngày, tháng, và năm.
        int d, m, y;
    public:
    // Phương thức cài đặt ngày, tháng, và năm.
        void setDOY(int day, int month, int year);
    // Phương thức đọc ngày, tháng, và năm.
        int getDay();
        int getMonth();
        int getYear();
};
// Hàm kiểm tra tính hợp lệ của ngày, tháng, và năm.
bool check (int day, int month, int year);
// Hàm kiểm tra năm nhuận.
bool checkLeap (int year);
// Hàm nhập ngày, tháng, và năm.
void Input (doy &x);
// Hàm trả về đúng định dạng ngày, tháng, và năm.
void Output (doy x);
// Hàm trả về giới hạn số ngày trong tháng.
int limitDayinMonth (int month, int year);
// Hàm tịnh tiến sang ngày kế tiếp.
void addDay(doy &x);
