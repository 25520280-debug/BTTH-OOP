#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Polynomial {
private:
    int degree;
    vector<double> coeffs;
public:
    Polynomial();
    Polynomial(int n);

    /*
        Ten phuong thuc : input
        ---------------------------------------
        Input: Nhan tu ban phim bac va cac he so cua da thuc.
        ---------------------------------------
        Output: Khong co gia tri tra ve. Cap nhat degree va coeffs.
        ---------------------------------------
        Huong giai thuat: Doc bac n truoc, resize mang he so,
        sau do duyet vong lap nhap tung he so tu bac cao nhat
        xuong hang so.
    */
    void input();

    /*
        Ten phuong thuc : evaluate
        ---------------------------------------
        Input: x - gia tri thuc can tinh (double).
        ---------------------------------------
        Output: Tra ve gia tri P(x) kieu double.
        ---------------------------------------
        Huong giai thuat: Duyet mang he so, cong don
        coeffs[i] * x^(degree - i) vao ket qua bang ham pow().
    */
    double evaluate(double x) const;

    /*
        Ten phuong thuc : display
        ---------------------------------------
        Input: Khong co.
        ---------------------------------------
        Output: In da thuc ra man hinh theo dang chuan
        (vi du: 3x^2 + 2x - 1).
        ---------------------------------------
        Huong giai thuat: Duyet tung he so, bo qua he so 0,
        xu ly dau + / - giua cac so hang, bo he so 1 truoc x,
        in so hang hang neu bac bang 0.
    */
    void display() const;

    /*
        Ten phuong thuc : add
        ---------------------------------------
        Input: other - da thuc thu hai can cong (const Polynomial&).
        ---------------------------------------
        Output: Tra ve da thuc moi la tong cua hai da thuc.
        ---------------------------------------
        Huong giai thuat: Lay bac lon nhat cua hai da thuc,
        duyet tu bac 0 den maxDeg, cong he so tuong ung cua
        hai da thuc (dung 0 neu bac vuot qua bac cua da thuc do).
    */
    Polynomial add(const Polynomial& other) const;

    /*
        Ten phuong thuc : subtract
        ---------------------------------------
        Input: other - da thuc thu hai can tru (const Polynomial&).
        ---------------------------------------
        Output: Tra ve da thuc moi la hieu cua hai da thuc.
        ---------------------------------------
        Huong giai thuat: Tuong tu add, nhung tru he so cua
        other thay vi cong.
    */
    Polynomial subtract(const Polynomial& other) const;

    /*
        Ten phuong thuc : operator+
        ------------------------------------------------------------
        Input: other - da thuc can cong (const Polynomial&).
        ------------------------------------------------------------
        Output: Da thuc moi la tong cua hai da thuc.
        ------------------------------------------------------------
        Huong giai thuat: Goi ham add() de tai su dung logic san co.
    */
    Polynomial operator+(const Polynomial& other) const;

    /*
        Ten phuong thuc : operator-
        ------------------------------------------------------------
        Input: other - da thuc can tru (const Polynomial&).
        ------------------------------------------------------------
        Output: Da thuc moi la hieu cua hai da thuc.
        ------------------------------------------------------------
        Huong giai thuat: Goi ham subtract() de tai su dung logic san co.
    */
    Polynomial operator-(const Polynomial& other) const;

    /*
        Ten phuong thuc : operator()
        ------------------------------------------------------------
        Input: x - gia tri thuc can tinh (double).
        ------------------------------------------------------------
        Output: Gia tri P(x) kieu double.
        ------------------------------------------------------------
        Huong giai thuat: Goi ham evaluate() de tai su dung logic san co.
    */
    double operator()(double x) const;

    /*
        Ten phuong thuc : operator<<
        ------------------------------------------------------------
        Input: os - luong xuat, p - da thuc can in.
        ------------------------------------------------------------
        Output: Luong xuat voi bieu dien chuan cua da thuc.
    */
    friend ostream& operator<<(ostream& os, const Polynomial& p);

    /*
        Ten phuong thuc : operator>>
        ------------------------------------------------------------
        Input: is - luong nhap, p - da thuc se nhan gia tri.
        ------------------------------------------------------------
        Output: Luong nhap; p duoc gan gia tri hop le hoac set failbit.
    */
    friend istream& operator>>(istream& is, Polynomial& p);
};

/*
    Ten phuong thuc : askYesNo
    ---------------------------------------
    Input: question - cau hoi hien thi cho user (const string&).
    ---------------------------------------
    Output: Tra ve true neu user nhap 'y' hoac 'Y', false neu nguoc lai.
*/
bool askYesNo(const string& question);