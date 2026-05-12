#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

class CDate {
    int day, month, year;

    /*
        Ten phuong thuc : isLeapYear
        ------------------------------------------------------------
        Input: y - nam can kiem tra.
        ------------------------------------------------------------
        Output: true neu la nam nhuan, false neu khong phai.
        ------------------------------------------------------------
        Huong giai thuat:
        - Nam nhuan khi chia het cho 4 va khong chia het cho 100,
          hoac chia het cho 400.
    */
    bool isLeapYear(int y) const;

    /*
        Ten phuong thuc : daysInMonth
        ------------------------------------------------------------
        Input: m - thang, y - nam.
        ------------------------------------------------------------
        Output: So ngay trong thang m cua nam y.
        ------------------------------------------------------------
        Huong giai thuat:
        - Dung mang so ngay mac dinh cho 12 thang.
        - Neu la thang 2 va la nam nhuan, tra ve 29.
        - Nguoc lai tra ve gia tri trong mang.
    */
    int daysInMonth(int m, int y) const;

    /*
        Ten phuong thuc : leapsBefore
        ------------------------------------------------------------
        Input: y - nam.
        ------------------------------------------------------------
        Output: Tong so nam nhuan truoc nam y (khong tinh nam y).
        ------------------------------------------------------------
        Huong giai thuat:
        - Ap dung cong thuc lich Gregorian: (y-1)/4 - (y-1)/100 + (y-1)/400.
    */
    long long leapsBefore(int y) const;

    /*
        Ten phuong thuc : toDays
        ------------------------------------------------------------
        Input: Khong (su dung trang thai hien tai cua doi tuong).
        ------------------------------------------------------------
        Output: Tong so ngay tinh tu 01/01/0001 den ngay hien tai.
        ------------------------------------------------------------
        Huong giai thuat:
        - Tinh so ngay cua cac nam truoc nam hien tai bang cong thuc O(1):
          (year-1)*365 + leapsBefore(year).
        - Cong don so ngay cua cac thang truoc thang hien tai.
        - Cong them so ngay hien tai.
    */
    long long toDays() const;

    /*
        Ten phuong thuc : fromDays
        ------------------------------------------------------------
        Input: total - tong so ngay tinh tu 01/01/0001.
        ------------------------------------------------------------
        Output: Cap nhat day, month, year tuong ung.
        ------------------------------------------------------------
        Huong giai thuat:
        - Phan tach theo chu ky 400 nam (146097 ngay), 100 nam (36524),
          4 nam (1461), va nam le de tinh year.
        - Xu ly truong hop bien chu ky (y100==4, y1==4) de tranh sai so.
        - Tru dan so ngay tung thang de tim month va day.
    */
    void fromDays(long long total);

public:
    /*
        Ten phuong thuc : CDate (constructor)
        ------------------------------------------------------------
        Input: d - ngay, m - thang, y - nam (mac dinh 01/01/1900).
        ------------------------------------------------------------
        Output: Doi tuong CDate voi gia tri duoc gan truc tiep.
    */
    CDate(int d = 1, int m = 1, int y = 1900);

    /*
        Ten phuong thuc : isValid
        ------------------------------------------------------------
        Input: Khong (su dung trang thai hien tai cua doi tuong).
        ------------------------------------------------------------
        Output: true neu ngay hop le, false neu khong hop le.
        ------------------------------------------------------------
        Huong giai thuat:
        - Kiem tra year >= 1, month trong [1,12], day trong [1, daysInMonth].
    */
    bool isValid() const;

    /*
        Ten phuong thuc : operator+ (cong so ngay)
        ------------------------------------------------------------
        Input: n - so ngay can cong them (co the am).
        ------------------------------------------------------------
        Output: Doi tuong CDate moi bang ngay hien tai cong n ngay.
        ------------------------------------------------------------
        Huong giai thuat:
        - Chuyen doi tuong hien tai sang so ngay (toDays).
        - Cong n vao ket qua.
        - Chuyen nguoc lai thanh CDate (fromDays).
    */
    CDate operator+(int n) const;

    /*
        Ten phuong thuc : operator- (tru so ngay)
        ------------------------------------------------------------
        Input: n - so ngay can tru (co the am).
        ------------------------------------------------------------
        Output: Doi tuong CDate moi bang ngay hien tai tru n ngay.
        ------------------------------------------------------------
        Huong giai thuat:
        - Chuyen doi tuong hien tai sang so ngay (toDays).
        - Tru n khoi ket qua.
        - Chuyen nguoc lai thanh CDate (fromDays).
    */
    CDate operator-(int n) const;

    /*
        Ten phuong thuc : operator- (khoang cach hai ngay)
        ------------------------------------------------------------
        Input: other - doi tuong CDate can tinh khoang cach.
        ------------------------------------------------------------
        Output: So ngay chech lech giua hai doi tuong (co dau).
        ------------------------------------------------------------
        Huong giai thuat:
        - Lay toDays() cua doi tuong hien tai tru toDays() cua other.
    */
    long long operator-(const CDate& other) const;

    /*
        Ten phuong thuc : operator++ (tien to)
        ------------------------------------------------------------
        Input: Khong.
        ------------------------------------------------------------
        Output: Tham chieu den doi tuong sau khi da tang them 1 ngay.
        ------------------------------------------------------------
        Huong giai thuat:
        - Tang doi tuong hien tai len 1 ngay qua fromDays(toDays()+1).
        - Tra ve tham chieu chinh no.
    */
    CDate& operator++();

    /*
        Ten phuong thuc : operator++ (hau to)
        ------------------------------------------------------------
        Input: int (tham so gia de phan biet voi tien to).
        ------------------------------------------------------------
        Output: Doi tuong CDate luu gia tri truoc khi tang.
        ------------------------------------------------------------
        Huong giai thuat:
        - Luu lai gia tri hien tai.
        - Tang doi tuong hien tai len 1 ngay.
        - Tra ve gia tri da luu.
    */
    CDate operator++(int);

    /*
        Ten phuong thuc : operator-- (tien to)
        ------------------------------------------------------------
        Input: Khong.
        ------------------------------------------------------------
        Output: Tham chieu den doi tuong sau khi da giam bot 1 ngay.
        ------------------------------------------------------------
        Huong giai thuat:
        - Giam doi tuong hien tai xuong 1 ngay qua fromDays(toDays()-1).
        - Tra ve tham chieu chinh no.
    */
    CDate& operator--();

    /*
        Ten phuong thuc : operator-- (hau to)
        ------------------------------------------------------------
        Input: int (tham so gia de phan biet voi tien to).
        ------------------------------------------------------------
        Output: Doi tuong CDate luu gia tri truoc khi giam.
        ------------------------------------------------------------
        Huong giai thuat:
        - Luu lai gia tri hien tai.
        - Giam doi tuong hien tai xuong 1 ngay.
        - Tra ve gia tri da luu.
    */
    CDate operator--(int);

    /*
        Ten phuong thuc : operator<, operator>, operator==
        ------------------------------------------------------------
        Input: o - doi tuong CDate can so sanh.
        ------------------------------------------------------------
        Output: Ket qua so sanh (true/false).
    */
    bool operator<(const CDate& o) const;
    bool operator>(const CDate& o) const;
    bool operator==(const CDate& o) const;

    /*
        Ten phuong thuc : operator<<
        ------------------------------------------------------------
        Input: os - luong xuat, d - doi tuong CDate can xuat.
        ------------------------------------------------------------
        Output: Luong xuat voi ngay duoc in theo dinh dang dd/mm/yyyy.
    */
    friend ostream& operator<<(ostream& os, const CDate& d);

    /*
        Ten phuong thuc : operator>>
        ------------------------------------------------------------
        Input: is - luong nhap, d - doi tuong CDate se nhan gia tri.
        ------------------------------------------------------------
        Output: Luong nhap; d duoc gan gia tri neu hop le,
                failbit duoc set neu sai dinh dang hoac ngay khong ton tai.
    */
    friend istream& operator>>(istream& is, CDate& d);
};