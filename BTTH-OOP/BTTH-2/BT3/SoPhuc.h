#pragma once

class SoPhuc {
private:
    float iThuc;
    float iAo;

public:
    /*
        Tên phương thức : Nhap
        ----------------------------------------------------------
        Input: Hai số thực (phần thực và phần ảo) từ bàn phím.
        ----------------------------------------------------------
        Output: Không trả về giá trị nhưng gán giá trị cho thuộc 
        tính iThuc và iAo.
        ----------------------------------------------------------
        Hướng giải thuật: Sử dụng cin để nhận dữ liệu. Kiểm tra 
        lỗi dòng nhập (cin.fail()) để yêu cầu nhập lại nếu người 
        dùng nhập ký tự không phải số.
    */
    void Nhap();

    /*
        Tên phương thức : Xuat
        ----------------------------------------------------------
        Input: Không có.
        ----------------------------------------------------------
        Output: In số phức ra màn hình định dạng (a + bi) 
        hoặc (a - bi).
        ----------------------------------------------------------
        Hướng giải thuật: Kiểm tra dấu của phần ảo để in dấu '+' 
        hoặc '-' cho phù hợp thẩm mỹ.
    */
    void Xuat();

    /*
        Tên phương thức : Tong / Hieu
        ----------------------------------------------------------
        Input: Một đối tượng SoPhuc b.
        ----------------------------------------------------------
        Output: Đối tượng SoPhuc mới là kết quả phép tính.
        ----------------------------------------------------------
        Hướng giải thuật: 
        - Phần thực mới = Thực 1 +/- Thực 2.
        - Phần ảo mới = Ảo 1 +/- Ảo 2.
    */
    SoPhuc Tong(SoPhuc b);
    SoPhuc Hieu(SoPhuc b);

    /*
        Tên phương thức : Tich
        Input: Đối tượng SoPhuc b (c + di).
        Output: Đối tượng SoPhuc mới (ac - bd) + (ad + bc)i.
        Hướng giải thuật: Áp dụng hằng đẳng thức nhân số phức.
    */
    SoPhuc Tich(SoPhuc b);

    /*
        Tên phương thức : Thuong
        ------------------------------------------------------------------
        Input: Đối tượng SoPhuc b.
        ------------------------------------------------------------------
        Output: Đối tượng SoPhuc mới.
        ------------------------------------------------------------------
        Hướng giải thuật: Nhân cả tử và mẫu với số phức liên hợp của 
        mẫu (c - di).
        Kết quả = [(ac + bd) / (c^2 + d^2)] + [(bc - ad) / (c^2 + d^2)]i.
    */
    SoPhuc Thuong(SoPhuc b);
};
