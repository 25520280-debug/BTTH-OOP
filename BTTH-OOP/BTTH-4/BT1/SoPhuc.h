#pragma once

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

const double EPS = 1e-9;

class SoPhuc {
private:
    double rel;
    double ima;
    bool   hop_le;
    const char* loi;

    /*
        Tên phương thức : xapXi
        ------------------------------------------------------------
        Input: Hai số thực a, b.
        ------------------------------------------------------------
        Output: true nếu |a - b| < EPS, false nếu ngược lại.
        ------------------------------------------------------------
        Hướng giải thuật:
        - Tính |a - b| bằng fabs().
        - Trả về true nếu kết quả nhỏ hơn hằng số EPS (1e-9).
    */
    static bool xapXi(double a, double b);

    /*
        Tên phương thức : SoPhuc (constructor lỗi - private)
        ------------------------------------------------------------
        Input: bool (không dùng), thông điệp lỗi msg.
        ------------------------------------------------------------
        Output: Đối tượng SoPhuc không hợp lệ mang thông báo lỗi.
    */
    SoPhuc(bool, const char* msg);

public:
    /*
        Tên phương thức : SoPhuc (constructor chính)
        ------------------------------------------------------------
        Input: Phần thực a (mặc định 0.0), phần ảo b (mặc định 0.0).
        ------------------------------------------------------------
        Output: Đối tượng số phức hợp lệ a + bi.
    */
    SoPhuc(double a = 0.0, double b = 0.0);

    /*
        Tên phương thức : loi_phep
        ------------------------------------------------------------
        Input: Thông điệp lỗi msg.
        ------------------------------------------------------------
        Output: Đối tượng SoPhuc không hợp lệ chứa thông điệp lỗi.
        ------------------------------------------------------------
        Hướng giải thuật:
        - Gọi constructor private SoPhuc(false, msg).
        - Trả về đối tượng biểu diễn trạng thái lỗi.
    */
    static SoPhuc loi_phep(const char* msg);

    /*
        Tên phương thức : getThuc
        ------------------------------------------------------------
        Input: Đối tượng số phức hiện tại.
        ------------------------------------------------------------
        Output: Giá trị phần thực (rel).
    */
    double getThuc()  const;

    /*
        Tên phương thức : getAo
        ------------------------------------------------------------
        Input: Đối tượng số phức hiện tại.
        ------------------------------------------------------------
        Output: Giá trị phần ảo (ima).
    */
    double getAo()    const;

    /*
        Tên phương thức : laHopLe
        ------------------------------------------------------------
        Input: Đối tượng số phức hiện tại.
        ------------------------------------------------------------
        Output: true nếu số phức hợp lệ, false nếu ở trạng thái lỗi.
    */
    bool   laHopLe()  const;

    /*
        Tên phương thức : laSo0
        ------------------------------------------------------------
        Input: Đối tượng số phức hiện tại.
        ------------------------------------------------------------
        Output: true nếu cả phần thực lẫn phần ảo xấp xỉ 0.
        ------------------------------------------------------------
        Hướng giải thuật:
        - Kiểm tra hop_le == true.
        - Dùng xapXi để kiểm tra rel ≈ 0 và ima ≈ 0.
        - Trả về true khi cả hai điều kiện thỏa mãn.
    */
    bool laSo0()     const;

    /*
        Tên phương thức : laSoThuc
        ------------------------------------------------------------
        Input: Đối tượng số phức hiện tại.
        ------------------------------------------------------------
        Output: true nếu phần ảo xấp xỉ 0 (là số thực).
        ------------------------------------------------------------
        Hướng giải thuật:
        - Kiểm tra hop_le == true.
        - Dùng xapXi để kiểm tra ima ≈ 0.
        - Trả về true khi điều kiện thỏa mãn.
    */
    bool laSoThuc()  const;

    /*
        Tên phương thức : laThuanAo
        ------------------------------------------------------------
        Input: Đối tượng số phức hiện tại.
        ------------------------------------------------------------
        Output: true nếu phần thực ≈ 0 và phần ảo ≠ 0 (thuần ảo).
        ------------------------------------------------------------
        Hướng giải thuật:
        - Kiểm tra hop_le == true.
        - Dùng xapXi để kiểm tra rel ≈ 0.
        - Dùng xapXi để xác nhận ima ≠ 0.
        - Trả về true khi cả hai điều kiện thỏa mãn.
    */
    bool laThuanAo() const;

    /*
        Tên phương thức : modulus
        ------------------------------------------------------------
        Input: Đối tượng số phức hiện tại.
        ------------------------------------------------------------
        Output: Môđun |z| = sqrt(rel² + ima²).
        ------------------------------------------------------------
        Hướng giải thuật:
        - Tính sqrt(rel * rel + ima * ima) bằng hàm sqrt() của <cmath>.
        - Trả về kết quả dạng double.
    */
    double modulus() const;

    /*
        Tên phương thức : lien_hop
        ------------------------------------------------------------
        Input: Đối tượng số phức hiện tại z = a + bi.
        ------------------------------------------------------------
        Output: Số phức liên hợp z̄ = a - bi.
        ------------------------------------------------------------
        Hướng giải thuật:
        - Nếu không hợp lệ, trả về chính đối tượng.
        - Tạo số phức mới với phần thực giữ nguyên (rel) và phần ảo đổi dấu (-ima).
    */
    SoPhuc lien_hop() const;

    // -------------------- Toán tử --------------------

    /*
        Tên phương thức : operator-() (đảo dấu)
        ------------------------------------------------------------
        Input: Đối tượng số phức hiện tại z = a + bi.
        ------------------------------------------------------------
        Output: Số phức -z = -a - bi.
        ------------------------------------------------------------
        Hướng giải thuật:
        - Nếu không hợp lệ, trả về chính đối tượng.
        - Tạo số phức mới với cả phần thực và phần ảo đổi dấu (-rel, -ima).
    */
    SoPhuc operator-() const;

    /*
        Tên phương thức : operator+
        ------------------------------------------------------------
        Input: Hai số phức z1 = a + bi và o = c + di.
        ------------------------------------------------------------
        Output: Tổng z1 + o = (a+c) + (b+d)i.
        ------------------------------------------------------------
        Hướng giải thuật:
        - Nếu một trong hai không hợp lệ, trả về đối tượng lỗi.
        - Cộng phần thực với phần thực: rel + o.rel.
        - Cộng phần ảo với phần ảo: ima + o.ima.
    */
    SoPhuc operator+(const SoPhuc& o) const;

    /*
        Tên phương thức : operator-
        ------------------------------------------------------------
        Input: Hai số phức z1 = a + bi và o = c + di.
        ------------------------------------------------------------
        Output: Hiệu z1 - o = (a-c) + (b-d)i.
        ------------------------------------------------------------
        Hướng giải thuật:
        - Nếu một trong hai không hợp lệ, trả về đối tượng lỗi.
        - Trừ phần thực: rel - o.rel.
        - Trừ phần ảo: ima - o.ima.
    */
    SoPhuc operator-(const SoPhuc& o) const;

    /*
        Tên phương thức : operator*
        ------------------------------------------------------------
        Input: Hai số phức z1 = a + bi và o = c + di.
        ------------------------------------------------------------
        Output: Tích z1 * o = (ac - bd) + (ad + bc)i.
        ------------------------------------------------------------
        Hướng giải thuật:
        - Nếu một trong hai không hợp lệ, trả về đối tượng lỗi.
        - Phần thực: rel*o.rel - ima*o.ima.
        - Phần ảo: rel*o.ima + ima*o.rel.
    */
    SoPhuc operator*(const SoPhuc& o) const;
    /*
        Tên phương thức : operator/
        ------------------------------------------------------------
        Input: Hai số phức z1 = a + bi và o = c + di.
        ------------------------------------------------------------
        Output: Thương z1 / o. Lỗi nếu |o| ≈ 0.
        ------------------------------------------------------------
        Hướng giải thuật:
        - Nếu một trong hai không hợp lệ, trả về đối tượng lỗi.
        - Tính mẫu: mau = c² + d².
        - Nếu mau < EPS: trả về lỗi "Mau = 0".
        - Phần thực: (ac + bd) / mau.
        - Phần ảo: (bc - ad) / mau.
    */
    SoPhuc operator/(const SoPhuc& o) const;

    /*
        Tên phương thức : operator==
        ------------------------------------------------------------
        Input: Hai số phức z1 và o.
        ------------------------------------------------------------
        Output: true nếu cả hai hợp lệ và rel, ima xấp xỉ bằng nhau.
        ------------------------------------------------------------
        Hướng giải thuật:
        - Kiểm tra cả hai hop_le == true.
        - Dùng xapXi để so sánh rel và ima từng cặp.
        - Trả về true khi cả hai điều kiện thỏa mãn.
    */
    bool operator==(const SoPhuc& o) const;
    /*
        Tên phương thức : operator!=
        ------------------------------------------------------------
        Input: Hai số phức z1 và o.
        ------------------------------------------------------------
        Output: true nếu z1 và o không bằng nhau.
        ------------------------------------------------------------
        Hướng giải thuật:
        - Trả về phủ định của (z1 == o) thông qua operator==.
    */
    bool operator!=(const SoPhuc& o) const;

    /*
        Tên phương thức : can_bac_hai
        ------------------------------------------------------------
        Input: Đối tượng số phức hiện tại z = a + bi.
        ------------------------------------------------------------
        Output: Căn bậc hai chính của z (nghiệm có phần thực ≥ 0).
        ------------------------------------------------------------
        Hướng giải thuật:
        - Nếu không hợp lệ hoặc z = 0, xử lý riêng.
        - Tính r = |z| = modulus().
        - x = sqrt((r + rel) / 2).
        - y = sign(ima) * sqrt((r - rel) / 2).
        - Làm tròn x, y về 0 nếu |x| hoặc |y| < EPS.
    */
    SoPhuc can_bac_hai() const;
    /*
        Tên phương thức : luy_thua
        ------------------------------------------------------------
        Input: Đối tượng số phức hiện tại z và số nguyên n.
        ------------------------------------------------------------
        Output: Lũy thừa z^n. Lỗi nếu z = 0 và n ≤ 0.
        ------------------------------------------------------------
        Hướng giải thuật:
        - Nếu z không hợp lệ, trả về lỗi.
        - Nếu z = 0: n ≤ 0 → lỗi; n > 0 → trả về 0.
        - Nếu n = 0: trả về 1 + 0i.
        - Nếu n < 0: tính 1 / z^(-n) bằng đệ quy.
        - Dùng dạng lượng giác: r^n * (cos(n*θ) + i*sin(n*θ)).
    */
    SoPhuc luy_thua(int n) const;
    /*
        Tên phương thức : xuatGiaTri
        ------------------------------------------------------------
        Input: Đối tượng số phức hiện tại.
        ------------------------------------------------------------
        Output: In dạng a + bi, a - bi, bi, a hoặc 0 tùy trường hợp.
    */
    void xuatGiaTri() const;

    /*
        Tên phương thức : xuatModulus
        ------------------------------------------------------------
        Input: Đối tượng số phức hiện tại.
        ------------------------------------------------------------
        Output: In giá trị môđun |z| ra màn hình.
    */
    void xuatModulus() const;

    /*
        Tên phương thức : xuatArgument
        ------------------------------------------------------------
        Input: Đối tượng số phức hiện tại.
        ------------------------------------------------------------
        Output: In argument arg(z) theo radian và độ. Lỗi nếu z = 0.
    */
    void xuatArgument() const;

    /*
        Tên phương thức : xuatLuongGiac
        ------------------------------------------------------------
        Input: Đối tượng số phức hiện tại.
        ------------------------------------------------------------
        Output: In dạng lượng giác r*(cos(θ) + i*sin(θ)).
    */
    void xuatLuongGiac() const;
};

/*
    Tên hàm  : docDouble
    ------------------------------------------------------------
    Input: Tham chiếu đến biến double x cần đọc.
    ------------------------------------------------------------
    Output: true nếu đọc thành công, false nếu sai kiểu dữ liệu.
*/
bool docDouble(double& x);

/*
    Tên hàm  : nhapSoPhuc
    ------------------------------------------------------------
    Input: Tên gợi nhớ của số phức (dùng để hiển thị).
    ------------------------------------------------------------
    Output: Đối tượng SoPhuc được nhập từ bàn phím.
*/
SoPhuc nhapSoPhuc(const char* ten);

/*
    Tên hàm  : nhapSoMu
    ------------------------------------------------------------
    Input: Không có.
    ------------------------------------------------------------
    Output: Số nguyên n được nhập từ bàn phím (số mũ).
*/
int nhapSoMu();

/*
    Tên hàm  : inDuong
    ------------------------------------------------------------
    Input: Số lượng ký tự '-' cần in (mặc định 48).
    ------------------------------------------------------------
    Output: In một dòng kẻ ngang ra màn hình.
*/
void inDuong(int n = 48);

/*
    Tên hàm  : inTitle
    ------------------------------------------------------------
    Input: Chuỗi tiêu đề s.
    ------------------------------------------------------------
    Output: In tiêu đề được bao quanh bởi hai dòng kẻ ngang.
*/
void inTitle(const char* s);

/*
    Tên hàm  : inNhan
    ------------------------------------------------------------
    Input: Chuỗi nhãn nhan.
    ------------------------------------------------------------
    Output: In nhãn căn trái với khoảng cách cố định trước dấu '='.
*/
void inNhan(const char* nhan);

