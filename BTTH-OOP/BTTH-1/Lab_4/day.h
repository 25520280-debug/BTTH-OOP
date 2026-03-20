#pragma once // Tránh lỗi lặp định nghĩa.

/*
    Tên lớp : doy (day of year)
    ------------------------------------------------------
    Nội dung :
        - d (int) : Ngày.
        - m (int) : Tháng.
        - y (int) : Năm.
    ------------------------------------------------------  
    Tính năng của phương thức :
        - setDOY : Thay giá trị cho ngày, tháng, năm.
        - getDay, getMonth, getYear : Đọc và trả về giá 
        trị của ngày, tháng, và năm.
*/
class doy
{
    private:
        int d, m, y;
    public:
        void setDOY(int day, int month, int year);
        int getDay();
        int getMonth();
        int getYear();
};
/*  
    Tên hàm : check
    ------------------------------------------------------
    Input :
        - d (int) : Ngày.
        - m (int) : Tháng.
        - y (int) : Năm.
    ------------------------------------------------------
    Output :
        true hoặc false.
    ------------------------------------------------------
    Tính năng :
        - Hàm giúp kiểm tra ngày, tháng, năm đã được nhập 
        đúng hay chưa.
*/
bool check (int day, int month, int year);
/*  
    Tên hàm : checkLeap
    ------------------------------------------------------
    Input :
        - y (int) : Năm.
    ------------------------------------------------------
    Output :
        true hoặc false.
    ------------------------------------------------------
    Tính năng :
        - Hàm giúp kiểm tra năm đã được nhập có phải năm
        nhuận hay không.
*/
bool checkLeap (int year);
/*  
    Tên hàm : Input
    ------------------------------------------------------
    Input :
        - x (doy) : Ngày trong năm.
    ------------------------------------------------------
    Output :
        Không trả về giá trị.
    ------------------------------------------------------
    Tính năng :
        - Thay giá trị được nhập từ bàn phím vào phân số
        cần nhập giá trị.
*/
void Input (doy &x);
/*
    Tên hàm : Output
    ------------------------------------------------------
    Input :
        - x (doy) : Ngày trong năm.
    ------------------------------------------------------
    Output :
        - Ngày trong năm có định dạng day/month/year.
    ------------------------------------------------------  
    Tính năng :
        - Xuất ra màn hình ngày trong năm đúng định dạng.
*/
void Output (doy x);
/*
    Tên hàm : limitDayinMonth
    ------------------------------------------------------
    Input :
        - m (int) : Tháng.
        - y (int) : Năm.
    ------------------------------------------------------
    Output :
        - Số ngày có trong tháng được nhập.
    ------------------------------------------------------  
    Tính năng :
        - Cho biết tháng đó có bao nhiêu ngày.
*/
int limitDayinMonth (int month, int year);
/*
    Tên hàm : addDay
    ------------------------------------------------------
    Input :
        - x (doy) : Ngày trong năm.
    ------------------------------------------------------
    Output :
        - Không trả về giá trị.
    ------------------------------------------------------  
    Tính năng :
        - Tăng ngày được nhập lên 1 đơn vị ngày.
*/
void addDay(doy &x);
