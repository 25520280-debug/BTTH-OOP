#include "score.h"
#include <iostream>

using namespace std;

void hocsinh :: setHS (string h, float t, float v)
    { HT = h, dT = t, dV = v; }

float hocsinh :: getT() { return dT; }
float hocsinh :: getV() { return dV; }

bool check(float i)
    { return (i >= 0 && i <= 10); } // Giới hạn tính hợp lệ của điểm từ 0 đến 10.

void Input (hocsinh &x)
{
    string s;
    cin.ignore(10000, '\n'); // Bỏ qua 10000 kí tự cho đến khi gặp '\n' thì dừng.
    getline (cin, s);   // Nhập tên.
    float t, v;
    while (true)
    {
    /*
        Kiểm tra xem có nhập thành công hay không
        (tức có nhập vào đúng kiểu hay không).
    */
        if (cin >> t >> v)  
        {
        // Kiểm tra tính hợp lệ của điểm toán và điểm văn.
            if (check(t) && check (v)) break;
            else cout << "Loi nhap sai dinh dang diem.\n";
        }
        else    // Nếu nhập không thành công, làm mới lại cin.
        {
            cout << "Loi nhap sai dang ki tu.\n";
            cin.clear();            // Làm mới lại trạng thái của cin.
            cin.ignore(10000,'\n'); // Bỏ qua 10000 kí tự cho đến khi gặp '\n' thì dừng.
        }
    }
    x.setHS(s,t,v); // Sau khi kiểm tra hợp lệ, gán giá trị vào.
}

void average (hocsinh x)
{
    float t = x.getT(), v = x.getV();   // Đọc và gán giá trị vào biến tạm.
    cout << (t+v)/2;    // Xuất điểm trung bình được tính toán.
}
