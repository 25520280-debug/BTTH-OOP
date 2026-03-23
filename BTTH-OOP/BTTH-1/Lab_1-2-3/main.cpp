#include "frac.h"

int main()
{
    std::cout << "Bai tap 1:\n";
    frac f;
    Input(f);                                 // Nhập phân số và rút gọn phân số.
    long long a = f.getNmr(), b = f.getDmn(); // Đọc và gán lần lượt tử số và mẫu số cho biến tạm.
    std::cout << '\n';
    Output(a, b); // Xuất phân số đã rút gọn.

    std::cout << "Bai tap 2:\n";
    frac f1, f2;
    std ::cout << "Phan so A: ";
    Input(f1);
    std ::cout << "Phan so B: ";
    Input(f2);          // Nhập hai phân số.
    std::cout << '\n';
    outCalFrac(f1, f2); // Xuất tổng, hiệu, tích, thương của 2 phân số.

    std::cout << "Bai tap 3:\n";
    frac F1, F2;
    std ::cout << "Phan so A: ";
    Input(F1);
    std ::cout << "Phan so B: ";
    Input(F2);       // Nhập hai phân số.
    std::cout << '\n';
    maxFrac(F1, F2); // Xuất phân số lớn nhất.

    return 0;
}
