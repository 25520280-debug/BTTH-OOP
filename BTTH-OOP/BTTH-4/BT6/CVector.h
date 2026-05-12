#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
using namespace std;

class CVector {
    vector<double> components;

public:
    /*
        Ten phuong thuc : CVector()
        ------------------------------------------------------------
        Input: Khong co.
        ------------------------------------------------------------
        Output: Doi tuong CVector 1 chieu voi gia tri 0.
    */
    CVector();

    /*
        Ten phuong thuc : CVector(int n)
        ------------------------------------------------------------
        Input: n - so chieu cua vector (n >= 1).
        ------------------------------------------------------------
        Output: Doi tuong CVector n chieu voi tat ca thanh phan bang 0.
    */
    CVector(int n);

    /*
        Ten phuong thuc : CVector(const vector<double>& v)
        ------------------------------------------------------------
        Input: v - vector<double> chua cac thanh phan khoi tao.
        ------------------------------------------------------------
        Output: Doi tuong CVector voi cac thanh phan sao chep tu v.
    */
    CVector(const vector<double>& v);

    /*
        Ten phuong thuc : dim()
        ------------------------------------------------------------
        Input: Khong co.
        ------------------------------------------------------------
        Output: So chieu cua vector (int).
    */
    int dim() const;

    /*
        Ten phuong thuc : operator[](int i)
        ------------------------------------------------------------
        Input: i - chi so thanh phan (0-based).
        ------------------------------------------------------------
        Output: Tham chieu den thanh phan thu i (co the gan lai).
        ------------------------------------------------------------
        Huong giai thuat:
        - Kiem tra i co nam trong doan [0, dim()-1] khong.
        - Neu khong hop le, nem ngoai le out_of_range.
        - Tra ve tham chieu den components[i].
    */
    double& operator[](int i);

    /*
        Ten phuong thuc : operator[](int i) const
        ------------------------------------------------------------
        Input: i - chi so thanh phan (0-based).
        ------------------------------------------------------------
        Output: Tham chieu hang den thanh phan thu i (chi doc).
        ------------------------------------------------------------
        Huong giai thuat:
        - Kiem tra i co nam trong doan [0, dim()-1] khong.
        - Neu khong hop le, nem ngoai le out_of_range.
        - Tra ve tham chieu hang den components[i].
    */
    const double& operator[](int i) const;

    /*
        Ten phuong thuc : input()
        ------------------------------------------------------------
        Input: Nhap tu ban phim so chieu va cac thanh phan.
        ------------------------------------------------------------
        Output: Khong co (cap nhat truc tiep doi tuong hien tai).
    */
    void input();

    /*
        Ten phuong thuc : display()
        ------------------------------------------------------------
        Input: Khong co.
        ------------------------------------------------------------
        Output: In vector ra man hinh theo dang (v1, v2, ..., vn).
    */
    void display() const;

    /*
        Ten phuong thuc : operator+(const CVector& other)
        ------------------------------------------------------------
        Input: other - vector cung chieu de cong.
        ------------------------------------------------------------
        Output: CVector la tong cua hai vector.
        ------------------------------------------------------------
        Huong giai thuat:
        - Kiem tra hai vector co cung chieu khong, neu khac nem invalid_argument.
        - Tao vector ket qua cung chieu.
        - Cong tung cap thanh phan tuong ung.
        - Tra ve vector ket qua.
    */
    CVector operator+(const CVector& other) const;

    /*
        Ten phuong thuc : operator-(const CVector& other)
        ------------------------------------------------------------
        Input: other - vector cung chieu de tru.
        ------------------------------------------------------------
        Output: CVector la hieu cua hai vector.
        ------------------------------------------------------------
        Huong giai thuat:
        - Kiem tra hai vector co cung chieu khong, neu khac nem invalid_argument.
        - Tao vector ket qua cung chieu.
        - Tru tung cap thanh phan tuong ung.
        - Tra ve vector ket qua.
    */
    CVector operator-(const CVector& other) const;

    /*
        Ten phuong thuc : operator*(double scalar)
        ------------------------------------------------------------
        Input: scalar - gia tri vo huong de nhan.
        ------------------------------------------------------------
        Output: CVector la tich cua vector voi scalar.
        ------------------------------------------------------------
        Huong giai thuat:
        - Tao vector ket qua cung chieu.
        - Nhan tung thanh phan voi scalar.
        - Tra ve vector ket qua.
    */
    CVector operator*(double scalar) const;

    /*
        Ten phuong thuc : operator*(double scalar, const CVector& v)  [friend]
        ------------------------------------------------------------
        Input: scalar - gia tri vo huong; v - vector can nhan.
        ------------------------------------------------------------
        Output: CVector la tich cua scalar voi vector (ho tro dang k * v).
        ------------------------------------------------------------
        Huong giai thuat:
        - Goi lai v * scalar da dinh nghia san.
        - Tra ve ket qua.
    */
    friend CVector operator*(double scalar, const CVector& v);

    /*
        Ten phuong thuc : operator-()
        ------------------------------------------------------------
        Input: Khong co.
        ------------------------------------------------------------
        Output: CVector la phu cua vector hien tai (dao dau tung thanh phan).
        ------------------------------------------------------------
        Huong giai thuat:
        - Tao vector ket qua cung chieu.
        - Dao dau tung thanh phan.
        - Tra ve vector ket qua.
    */
    CVector operator-() const;

    /*
        Ten phuong thuc : dot(const CVector& other)
        ------------------------------------------------------------
        Input: other - vector cung chieu de tinh tich vo huong.
        ------------------------------------------------------------
        Output: Gia tri double la tich vo huong cua hai vector.
        ------------------------------------------------------------
        Huong giai thuat:
        - Kiem tra hai vector co cung chieu khong, neu khac nem invalid_argument.
        - Tinh tong tich tung cap thanh phan tuong ung.
        - Tra ve tong.
    */
    double dot(const CVector& other) const;

    /*
        Ten phuong thuc : norm()
        ------------------------------------------------------------
        Input: Khong co.
        ------------------------------------------------------------
        Output: Gia tri double la do dai (chuan Euclidean) cua vector.
        ------------------------------------------------------------
        Huong giai thuat:
        - Tinh tich vo huong cua vector voi chinh no (dot(*this)).
        - Lay can bac hai.
        - Tra ve ket qua.
    */
    double norm() const;

    /*
        Ten phuong thuc : operator==(const CVector& other)
        ------------------------------------------------------------
        Input: other - vector can so sanh.
        ------------------------------------------------------------
        Output: true neu hai vector bang nhau, false neu khac.
        ------------------------------------------------------------
        Huong giai thuat:
        - Kiem tra so chieu, neu khac tra ve false.
        - So sanh tung cap thanh phan voi nguong sai so 1e-9.
        - Neu co cap nao chenh qua nguong, tra ve false.
        - Nguoc lai tra ve true.
    */
    bool operator==(const CVector& other) const;

    /*
        Ten phuong thuc : operator!=(const CVector& other)
        ------------------------------------------------------------
        Input: other - vector can so sanh.
        ------------------------------------------------------------
        Output: true neu hai vector khac nhau, false neu bang nhau.
        ------------------------------------------------------------
        Huong giai thuat:
        - Goi lai operator== va dao nguoc ket qua.
    */
    bool operator!=(const CVector& other) const;

    /*
        Ten phuong thuc : operator<<(ostream& os, const CVector& v)  [friend]
        ------------------------------------------------------------
        Input: os - luong xuat; v - vector can in.
        ------------------------------------------------------------
        Output: Luong ostream& sau khi da ghi vector theo dang (v1, v2, ..., vn).
    */
    friend ostream& operator<<(ostream& os, const CVector& v);

    /*
        Ten phuong thuc : operator>>(istream& is, CVector& v)  [friend]
        ------------------------------------------------------------
        Input: is - luong nhap; v - vector can doc du lieu vao.
        ------------------------------------------------------------
        Output: Luong istream& sau khi da doc so chieu va cac thanh phan.
    */
    friend istream& operator>>(istream& is, CVector& v);
};