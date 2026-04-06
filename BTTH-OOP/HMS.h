#pragma once

class ThoiGian {
private:
    int iGio, iPhut, iGiay;

public:
    /*
        Tên phương thức : Nhap
        ------------------------------------------------------------
        Input: Giờ, Phút, Giây từ bàn phím.
        ------------------------------------------------------------
        Output: Gán giá trị hợp lệ cho các thuộc tính.
        ------------------------------------------------------------
        Hướng giải thuật: Sử dụng vòng lặp do-while để kiểm tra 
        tính hợp lệ:
        - iGio: [0, 23]
        - iPhut: [0, 59]
        - iGiay: [0, 59]
        Nếu nhập sai hoặc nhập ký tự không phải số, yêu cầu 
        nhập lại.
    */
    void Nhap();

    /*
        Tên phương thức : Xuat
        ------------------------------------------------------------
        Input: Không có.
        ------------------------------------------------------------
        Output: In ra màn hình định dạng hh:mm:ss.
    */
    void Xuat();

    /*
        Tên phương thức : TinhCongThemMotGiay
        ------------------------------------------------------------
        Input: Đối tượng thời gian hiện tại.
        ------------------------------------------------------------
        Output: Cập nhật giá trị thời gian lên 1 giây tiếp theo.
        ------------------------------------------------------------
        Hướng giải thuật: 
        - Tăng iGiay thêm 1 đơn vị.
        - Nếu iGiay = 60: Đặt iGiay = 0 và tăng iPhut.
        - Nếu iPhut = 60: Đặt iPhut = 0 và tăng iGio.
        - Nếu iGio = 24: Đặt iGio = 0 (Quay lại bắt đầu ngày mới).
    */
    void TinhCongThemMotGiay();
};
