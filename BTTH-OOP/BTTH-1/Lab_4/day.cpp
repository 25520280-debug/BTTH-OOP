#include "day.h"
#include <iostream>

using namespace std;

void doy :: setDOY (int day, int month, int year)
    { d = day, m = month, y = year; }

int doy :: getDay() { return d; }
int doy :: getMonth() { return m; }
int doy :: getYear() { return y; }

bool check (int day, int month, int year)
    {
        return (day > 0 && day < 32)  // Để số ngày hợp lệ trong giới hạn từ 1 đến 31.
        && (month > 0 && month < 13) // Để số tháng giới hạn từ 1 đến 12.
        && year > 0;                // Để số năm luôn dương.
    }  

void Input(doy &x)
{
    int day, month, year;

    while (true)
    {
    /*
        Kiểm tra xem có nhập thành công hay không
        (tức có nhập vào đúng kiểu hay không).
    */
        if (cin >> day >> month >> year)    
        {
            if (check(day, month, year)) break;   // Kiểm tra ngày, tháng, và năm.
            else cout << "Loi nhap sai dinh dang ngay.\n";
        }
        else    // Nếu nhập không thành công, làm mới lại cin.
        {
            cout << "Loi nhap sai dang ki tu.\n";
            cin.clear();            // Làm mới lại trạng thái của cin.
            cin.ignore(10000,'\n'); // Bỏ qua 10000 kí tự cho đến khi gặp '\n' thì dừng.
        }
    }
    x.setDOY(day,month,year);   // Sau khi kiểm tra hợp lệ, gán giá trị vào.
}

void Output (doy x)
{
    int day = x.getDay(), month = x.getMonth(), year = x.getYear(); // Đọc và gán giá trị vào biến tạm.

    if (day < 10) cout << 0 << day; // Định dạng ngày.
    else cout << day;

    cout << '/';

    if (month < 10) cout << 0 << month; // Định dạng tháng.
    else cout << month;

    cout << '/' << year;
}

bool checkLeap (int y) { return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0); }   
// Năm nhuận sẽ chia hết cho 400 hoặc chia hết cho 4 nhưng không chia hết cho 100..

int limitDayinMonth (int month, int year)
{
    switch(month)
    {  
        case 2: // Xét riêng trường hợp của tháng 2.
        {
            if (checkLeap(year)) return 29; // Năm nhuận thì tháng 2 có 29 ngày.
            else return 28;                 // Năm không nhuận thì có 28 ngày.
            break;
        }
        case 4:     // Xét trường hợp những tháng có 31 ngày.
        case 6:
        case 9:
        case 11:  return 30;
        default : return 31;    // Nếu không thuộc những trường hợp trên, trả về 30 ngày.
    }
}

void addDay (doy &x)
{
    int day = x.getDay(), month = x.getMonth(), year = x.getYear();
    if (day > 27)   // Xét trường hợp khi số ngày lớn hơn 27.
    {  
        int lim = limitDayinMonth(month, year);

        if (++day > lim)    // Tăng số ngày lên.
        {
            day = 1;
            month++;    // Nếu số ngày sau khi tăng cao hơn giới hạn ngày, tăng tháng.
        }
        if (month > 12) // Nếu số tháng sau khi tăng cao hơn giới hạn tháng, tăng năm.
        {
            month = 1;
            year++;
        }
    }
    else day++; // Nếu số ngày ít hơn, tăng trực tiếp.
    x.setDOY(day,month,year);
}
