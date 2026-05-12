#pragma once

#include <iostream>
using namespace std;

class CTime {
private:
    int gio, phut, giay;
    
    /*
        Ten phuong thuc : chuanHoa
        ------------------------------------------------------------
        Input: Khong co (tac dong truc tiep len doi tuong hien tai).
        ------------------------------------------------------------
        Output: Thoi gian duoc chuan hoa ve dang hop le (0-23 gio, 0-59 phut, 0-59 giay).
        ------------------------------------------------------------
        Huong giai thuat:
        - Xu ly giay: neu >= 60 thi chuyen sang phut, neu < 0 thi tru phut va dieu chinh lai.
        - Xu ly phut: neu >= 60 thi chuyen sang gio, neu < 0 thi tru gio va dieu chinh lai.
        - Xu ly gio: giu trong khoang 0-23 bang phep chia lay du 24.
    */
    void chuanHoa();

public:
    /*
        Ten phuong thuc : CTime (constructor mac dinh)
        ------------------------------------------------------------
        Input: Khong co.
        ------------------------------------------------------------
        Output: Doi tuong CTime voi thoi gian mac dinh la 00:00:00.
    */
    CTime();
    
    /*
        Ten phuong thuc : CTime (constructor co tham so)
        ------------------------------------------------------------
        Input: g (gio), p (phut), s (giay) - cac so nguyen.
        ------------------------------------------------------------
        Output: Doi tuong CTime duoc khoi tao va tu dong chuan hoa.
    */
    CTime(int g, int p, int s);

    /*
        Ten phuong thuc : operator+
        ------------------------------------------------------------
        Input: s - so giay can cong them (so nguyen).
        ------------------------------------------------------------
        Output: Doi tuong CTime moi la ket qua sau khi cong them s giay.
        ------------------------------------------------------------
        Huong giai thuat:
        - Tao doi tuong moi voi so giay hien tai cong them s.
        - Goi chuanHoa de dieu chinh thoi gian ve dang hop le.
    */
    CTime operator+(int s) const;
    
    /*
        Ten phuong thuc : operator-
        ------------------------------------------------------------
        Input: s - so giay can tru di (so nguyen).
        ------------------------------------------------------------
        Output: Doi tuong CTime moi la ket qua sau khi tru di s giay.
        ------------------------------------------------------------
        Huong giai thuat:
        - Tao doi tuong moi voi so giay hien tai tru di s.
        - Goi chuanHoa de dieu chinh thoi gian ve dang hop le.
    */
    CTime operator-(int s) const;

    /*
        Ten phuong thuc : operator++ (tien to)
        ------------------------------------------------------------
        Input: Khong co.
        ------------------------------------------------------------
        Output: Tham chieu den doi tuong hien tai sau khi tang 1 giay.
        ------------------------------------------------------------
        Huong giai thuat:
        - Tang doi tuong hien tai len 1 giay bang cach goi operator+.
        - Tra ve tham chieu den chinh no.
    */
    CTime& operator++();
    
    /*
        Ten phuong thuc : operator++ (hau to)
        ------------------------------------------------------------
        Input: int (tham so gia de phan biet voi tien to).
        ------------------------------------------------------------
        Output: Doi tuong CTime luu gia tri truoc khi tang.
        ------------------------------------------------------------
        Huong giai thuat:
        - Luu lai gia tri hien tai.
        - Tang doi tuong hien tai len 1 giay.
        - Tra ve gia tri da luu.
    */
    CTime operator++(int);
    
    /*
        Ten phuong thuc : operator-- (tien to)
        ------------------------------------------------------------
        Input: Khong co.
        ------------------------------------------------------------
        Output: Tham chieu den doi tuong hien tai sau khi giam 1 giay.
        ------------------------------------------------------------
        Huong giai thuat:
        - Giam doi tuong hien tai xuong 1 giay bang cach goi operator-.
        - Tra ve tham chieu den chinh no.
    */
    CTime& operator--();
    
    /*
        Ten phuong thuc : operator-- (hau to)
        ------------------------------------------------------------
        Input: int (tham so gia de phan biet voi tien to).
        ------------------------------------------------------------
        Output: Doi tuong CTime luu gia tri truoc khi giam.
        ------------------------------------------------------------
        Huong giai thuat:
        - Luu lai gia tri hien tai.
        - Giam doi tuong hien tai xuong 1 giay.
        - Tra ve gia tri da luu.
    */
    CTime operator--(int);

    /*
        Ten phuong thuc : xuat12h
        ------------------------------------------------------------
        Input: Khong co.
        ------------------------------------------------------------
        Output: Hien thi thoi gian theo dinh dang 12 gio voi AM/PM.
    */
    void xuat12h() const;
    
    /*
        Ten phuong thuc : xuat24h
        ------------------------------------------------------------
        Input: Khong co.
        ------------------------------------------------------------
        Output: Hien thi thoi gian theo dinh dang 24 gio.
    */
    void xuat24h() const;

    /*
        Ten phuong thuc : operator<< (friend)
        ------------------------------------------------------------
        Input: os - doi tuong output stream, t - doi tuong CTime can xuat.
        ------------------------------------------------------------
        Output: Tham chieu den output stream sau khi xuat thoi gian.
    */
    friend ostream& operator<<(ostream& os, const CTime& t);
    
    /*
        Ten phuong thuc : operator>> (friend)
        ------------------------------------------------------------
        Input: is - doi tuong input stream, t - doi tuong CTime can nhap.
        ------------------------------------------------------------
        Output: Tham chieu den input stream sau khi nhap thoi gian.
    */
    friend istream& operator>>(istream& is, CTime& t);
};

