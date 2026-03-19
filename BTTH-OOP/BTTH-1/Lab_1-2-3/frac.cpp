#include "frac.h"
#include <iostream>
#include <cmath>
#include <numeric>
using namespace std;

void frac :: setFrac (long long x, long long y) { a = x, b = y; }

long long frac :: getNmr() { return a; };
long long frac :: getDmn() { return b; };


void simplyFrac (long long &a, long long &b)
{
    long long g = gcd(abs(a), abs(b));   // Ứoc chung lớn nhất của tử số a và mẫu số b.
    a /= g, b /= g;
}

void Input(frac &x)
{
    long long a, b;
    while (true)
    {   
    /*
        Kiểm tra xem có nhập thành công hay không 
        (tức có nhập vào đúng kiểu hay không).
    */
        if (cin >> a >> b)
        {
            if (b != 0) // Kiểm tra lỗi chia cho 0.
            {
                if (b < 0)  // Nếu mẫu âm, chuyển dấu lên cho tử.
                    { a *= -1, b *= -1; }
                simplyFrac(a,b); // Rút gọn phân số tại đây để tránh tính toán về sau bị tràn số.
                break;
            }
            else cout << "Loi chia cho 0. Hay nhap lai.\n";
        }
        else // Nếu nhập không thành công, làm mới lại cin.
        {
            cout << "Loi nhap ki tu. Hay nhap lai.\n";
            cin.clear();    // Reset lại trạng thái của cin.
            cin.ignore(10000,'\n'); // Bỏ qua 10000 kí tự trong bộ nhớ đệm (buffer) đến khi gặp '/n'.
        }
    }
    x.setFrac(a,b); // Sau khi kiểm tra hợp lệ, gán giá trị vào.
}

void Output (long long a, long long b)
{
    if (a == 0) cout << 0 << '\n';  // Nếu tử số là 0, xuất thẳng 0.
    else if (b == 1) cout << a << '\n'; // Nếu mẫu bằng 1, chỉ xuất tử số.
    else cout << a << '/' << b << '\n'; // Xuất như bình thường.
}

void sumFrac (frac i, frac j)
{
    // Đọc và gán giá trị vào biến tạm.
    long long a = i.getNmr(), b = i.getDmn(); 
    long long c = j.getNmr(), d = j.getDmn();

    long long dnm = b * d;    // Tính toán tử số.
    long long nmr = (a * d) + (c * b);    // Tính toán mẫu số.
    simplyFrac(nmr,dnm);    // Rút gọn phân số.
    Output(nmr,dnm);  // Trả về kết quả.
}

void difFrac (frac i, frac j)
{
    long long a = i.getNmr(), b = i.getDmn();
    long long c = j.getNmr(), d = j.getDmn();
    long long dnm = b * d;
    long long nmr = (a * d) - (c * b);
    simplyFrac(nmr,dnm);
    Output(nmr,dnm);
}

void prodFrac (frac i, frac j)
{
    long long a = i.getNmr(), b = i.getDmn();
    long long c = j.getNmr(), d = j.getDmn();
    long long dnm = b * d;
    long long nmr = a * c;
    simplyFrac(nmr,dnm);
    Output(nmr,dnm);
}

void quoFrac (frac i, frac j)
{
    long long a = i.getNmr(), b = i.getDmn();
    long long c = j.getNmr(), d = j.getDmn();
    if (c == 0)
    {
        cout << "Khong tinh duoc.";
        return;
    }
    long long dnm = b * c;
    long long nmr = a * d;
    simplyFrac(nmr,dnm);
    Output(nmr,dnm);
}

void outCalFrac (frac i, frac j)    
{
    cout << "Tong : ";
    sumFrac(i,j);
    cout << "\nHieu : ";
    difFrac(i,j);
    cout << "\nTich : ";
    prodFrac(i,j);
    cout << "\nThuong : ";
    quoFrac(i,j);
    cout << '\n';
}

void maxFrac (frac i, frac j)
{
    long long a = i.getNmr(), b = i.getDmn();
    long long c = j.getNmr(), d = j.getDmn();

    // Nếu vế trái lớn hơn vế phải thì trả về phân số đầu và ngược lại.
    if (a * d < c * b) Output(c,d); 
    else Output(a,b);
}
