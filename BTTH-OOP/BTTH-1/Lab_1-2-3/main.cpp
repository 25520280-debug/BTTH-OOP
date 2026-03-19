#include "frac.h"

int main()
{   
    // Bài tập 1:
    frac f; Input(f);   // Nhập phân số và rút gọn phân số.
    long long a = f.getNmr(), b = f.getDmn(); // Đọc và gán lần lượt tử số và mẫu số cho biến tạm.
    Output(a,b); // Xuất phân số đã rút gọn.

    // Bài tập 2:
    frac f1, f2; Input(f1), Input(f2); // Nhập hai phân số.
    outCalFrac(f1,f2); // Xuất tổng, hiệu, tích, thương của 2 phân số.

    // Bài tập 3:
    frac F1,F2; Input(F1), Input(F2);
    maxFrac(F1,F2); // Xuất phân số lớn nhất.

    return 0;
}