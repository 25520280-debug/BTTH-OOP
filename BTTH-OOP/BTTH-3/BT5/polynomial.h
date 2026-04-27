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
        Tên phương thức : input
        ---------------------------------------
        Input: Nhận từ bàn phím bậc và các hệ số của đa thức.
        ---------------------------------------
        Output: Không có giá trị trả về. Cập nhật degree và coeffs.
        ---------------------------------------
        Hướng giải thuật: Đọc bậc n trước, resize mảng hệ số,
        sau đó duyệt vòng lặp nhập từng hệ số từ bậc cao nhất
        xuống hằng số.
    */
    void input();

    /*
        Tên phương thức : evaluate
        ---------------------------------------
        Input: x - giá trị thực cần tính (double).
        ---------------------------------------
        Output: Trả về giá trị P(x) kiểu double.
        ---------------------------------------
        Hướng giải thuật: Duyệt mảng hệ số, cộng dồn
        coeffs[i] * x^(degree - i) vào kết quả bằng hàm pow().
    */
    double evaluate(double x) const;

    /*
        Tên phương thức : display
        ---------------------------------------
        Input: Không có.
        ---------------------------------------
        Output: In đa thức ra màn hình theo dạng chuẩn
        (ví dụ: 3x^2 + 2x - 1).
        ---------------------------------------
        Hướng giải thuật: Duyệt từng hệ số, bỏ qua hệ số 0,
        xử lý dấu + / - giữa các số hạng, bỏ hệ số 1 trước x,
        in số hạng hằng nếu bậc bằng 0.
    */
    void display() const;

    /*
        Tên phương thức : add
        ---------------------------------------
        Input: other - đa thức thứ hai cần cộng (const Polynomial&).
        ---------------------------------------
        Output: Trả về đa thức mới là tổng của hai đa thức.
        ---------------------------------------
        Hướng giải thuật: Lấy bậc lớn nhất của hai đa thức,
        duyệt từ bậc 0 đến maxDeg, cộng hệ số tương ứng của
        hai đa thức (dùng 0 nếu bậc vượt quá bậc của đa thức đó).
    */
    Polynomial add(const Polynomial& other) const;

    /*
        Tên phương thức : subtract
        ---------------------------------------
        Input: other - đa thức thứ hai cần trừ (const Polynomial&).
        ---------------------------------------
        Output: Trả về đa thức mới là hiệu của hai đa thức.
        ---------------------------------------
        Hướng giải thuật: Tương tự add, nhưng trừ hệ số của
        other thay vì cộng.
    */
    Polynomial subtract(const Polynomial& other) const;
};

/*
    Tên phương thức : askYesNo
    ---------------------------------------
    Input: question - câu hỏi hiển thị cho user (const string&).
    ---------------------------------------
    Output: Trả về true nếu user nhập 'y' hoặc 'Y', false nếu ngược lại.
*/
bool askYesNo(const string& question);
