#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
 
double cleanNum(double x);
 
class vertex {
public:
    double x, y;
 
    vertex();
    vertex(double x, double y);
 
    /*
        Tên phương thức : distance
        ----------------------------------------------------------------------------
        Input: Một đối tượng vertex other (tham chiếu hằng).
        ----------------------------------------------------------------------------
        Output: Trả về khoảng cách Euclidean giữa đỉnh hiện tại và other.
        ----------------------------------------------------------------------------
        Hướng giải thuật:
        -   Tính hiệu tọa độ: dis_X = this->x - other.x, dis_Y = this->y - other.y.
        -   Trả về sqrt(dis_X^2 + dis_Y^2).
    */
    double distance(const vertex& other);
 
    friend istream& operator>>(istream& in, vertex& p);
    friend ostream& operator<<(ostream& out, const vertex& p);
};
 
class transformation {
public:
    /*
        Tên phương thức : apply
        ----------------------------------------------------------------------------
        Input: Một đối tượng vertex v (tham chiếu hằng).
        ----------------------------------------------------------------------------
        Output: Trả về đỉnh mới sau khi áp dụng phép biến đổi.
    */
    virtual vertex apply(const vertex& v) const = 0;
 
    /*
        Tên phương thức : name
        ----------------------------------------------------------------------------
        Output: Trả về tên của phép biến đổi dưới dạng string.
    */
    virtual string name() const = 0;
 
    virtual ~transformation() {}
};
 
class translation : public transformation {
    double u, v;
public:
    translation(double u, double v);
 
    /*
        Tên phương thức : apply
        ----------------------------------------------------------------------------
        Input: Một đối tượng vertex p (tham chiếu hằng).
        ----------------------------------------------------------------------------
        Output: Trả về đỉnh mới sau khi tịnh tiến: (p.x + u, p.y + v).
    */
    vertex apply(const vertex& p) const override;
    string name() const override;
};
 
class rotation : public transformation {
    double deg;
public:
    rotation(const double& degrees);
 
    /*
        Tên phương thức : apply
        ----------------------------------------------------------------------------
        Input: Một đối tượng vertex p (tham chiếu hằng).
        ----------------------------------------------------------------------------
        Output: Trả về đỉnh mới sau khi quay góc deg quanh gốc tọa độ.
        ----------------------------------------------------------------------------
        Hướng giải thuật:
        -   Chuyển độ sang radian: rad = deg * PI / 180.
        -   Áp dụng ma trận quay:
                x' = x*cos(rad) - y*sin(rad)
                y' = x*sin(rad) + y*cos(rad)
    */
    vertex apply(const vertex& p) const override;
    string name() const override;
};
 
class scaling : public transformation {
    double t;
public:
    scaling(double t);
 
    /*
        Tên phương thức : apply
        ----------------------------------------------------------------------------
        Input: Một đối tượng vertex p (tham chiếu hằng).
        ----------------------------------------------------------------------------
        Output: Trả về đỉnh mới sau khi co dãn.
        ----------------------------------------------------------------------------
        Hướng giải thuật:
        -   Nếu t < 0: chia tọa độ cho (-t) → thu nhỏ.
        -   Nếu t >= 0: nhân tọa độ với t → phóng to.
    */
    vertex apply(const vertex& p) const override;
    string name() const override;
};
 
class shape {
protected:
    /*
        Tên phương thức : applyAndPrint
        ----------------------------------------------------------------------------
        Input: Một đối tượng transformation t (tham chiếu hằng).
        ----------------------------------------------------------------------------
        Output: Áp dụng phép biến đổi lên toàn bộ đỉnh của hình,
                tạo hình mới và in thông tin hình đó.
    */
    virtual void applyAndPrint(const transformation& t) const = 0;
 
public:
    virtual void   input()            = 0;
    virtual void   printInfo() const  = 0;
    virtual double area()      const  = 0;
    virtual double per()       const  = 0;
    virtual ~shape() {}
 
    /*
        Tên phương thức : printTransformed
        ----------------------------------------------------------------------------
        Input: Một đối tượng transformation t (tham chiếu hằng).
        ----------------------------------------------------------------------------
        Output: In tên phép biến đổi rồi gọi applyAndPrint(t) — đây là nơi
                đa hình hoạt động: t có thể là translation, rotation, hoặc scaling.
    */
    virtual void printTransformed(const transformation& t) const;
};

class triangle : public shape {
    vertex A, B, C;
    double a, b, c;
    double p;
 
    /*
        Tên phương thức : build
        ----------------------------------------------------------------------------
        Output: Tính lại độ dài 3 cạnh (a, b, c) và nửa chu vi (p)
                từ tọa độ 3 đỉnh hiện tại.
        ----------------------------------------------------------------------------
        Hướng giải thuật:
        -   a = khoảng cách B-C, b = khoảng cách A-C, c = khoảng cách B-A.
        -   p = (a + b + c) / 2.
    */
    void build();
 
    string triType() const;
 
protected:
    void applyAndPrint(const transformation& t) const override;
 
public:
    triangle();
    triangle(vertex A, vertex B, vertex C);
 
    /*
        Tên phương thức : check
        ----------------------------------------------------------------------------
        Output: Trả về true nếu 3 đỉnh tạo thành tam giác hợp lệ.
        ----------------------------------------------------------------------------
        Hướng giải thuật:
        -   Dùng công thức Heron: S = sqrt(p*(p-a)*(p-b)*(p-c)).
        -   Nếu p*(p-a)*(p-b)*(p-c) > 1e-9 thì hợp lệ (S > 0).
    */
    bool check();
 
    /*
        Tên phương thức : input
        ----------------------------------------------------------------------------
        Output: Nhận tọa độ 3 đỉnh từ người dùng, kiểm tra hợp lệ,
                lặp lại nếu không tạo được tam giác.
    */
    void input() override;
 
    double area()      const override;
    double per()       const override;
    void   printInfo() const override;
};

class polygon : public shape {
    vector<vertex> verticles;
 
    /*
        Tên phương thức : collinear
        ----------------------------------------------------------------------------
        Input: Ba đỉnh a, b, c (tham chiếu hằng).
        ----------------------------------------------------------------------------
        Output: Trả về true nếu 3 đỉnh thẳng hàng.
        ----------------------------------------------------------------------------
        Hướng giải thuật:
        -   Tính tích có hướng (cross product):
                cross = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x)
        -   Nếu |cross| < 1e-9 thì 3 điểm thẳng hàng.
    */
    bool collinear(const vertex& a, const vertex& b, const vertex& c);
 
    /*
        Tên phương thức : check
        ----------------------------------------------------------------------------
        Input: Danh sách đỉnh points (vector tham chiếu hằng).
        ----------------------------------------------------------------------------
        Output: Trả về true nếu không có 3 đỉnh liên tiếp nào thẳng hàng.
        ----------------------------------------------------------------------------
        Hướng giải thuật:
        -   Duyệt qua từng bộ 3 đỉnh liên tiếp (i, i+1, i+2), bọc vòng qua % n.
        -   Nếu bất kỳ bộ nào collinear thì trả về false.
    */
    bool check(const vector<vertex>& points);
 
protected:
    void applyAndPrint(const transformation& t) const override;
 
public:
    polygon();
    polygon(const vector<vertex>& points);
 
    /*
        Tên phương thức : input
        ----------------------------------------------------------------------------
        Output: Nhận số đỉnh và tọa độ từng đỉnh từ người dùng,
                kiểm tra hợp lệ, lặp lại nếu có 3 đỉnh liên tiếp thẳng hàng.
    */
    void input() override;
 
    double area()      const override;
    double per()       const override;
    void   printInfo() const override;
};