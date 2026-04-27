#pragma once
#include <string>
using namespace std;
 
/*
    Tên hàm        : readInt
    ---------------------------------------
    Input: Chuỗi prompt hiển thị cho người dùng.
    ---------------------------------------
    Output: Trả về giá trị nguyên hợp lệ nhập từ bàn phím.
    ---------------------------------------
    Hướng giải thuật: Liên tục yêu cầu nhập cho đến khi
    nhận được số nguyên hợp lệ; xóa trạng thái lỗi của cin
    nếu nhập sai.
*/
int readInt(const string& prompt);
 
/*
    Tên hàm        : readChoice
    ---------------------------------------
    Input: Chuỗi prompt và chuỗi các ký tự hợp lệ.
    ---------------------------------------
    Output: Trả về ký tự (viết thường) mà người dùng chọn.
    ---------------------------------------
    Hướng giải thuật: Liên tục yêu cầu nhập cho đến khi
    ký tự nhập vào nằm trong tập ký tự hợp lệ.
*/
char readChoice(const string& prompt, const string& valid);
 
 
class Array {
private:
    int* data;
    int  n;
 
    /*
        Tên phương thức : isPrime
        ---------------------------------------
        Input: Số nguyên x.
        ---------------------------------------
        Output: Trả về true nếu x là số nguyên tố,
        false nếu ngược lại.
        ---------------------------------------
        Hướng giải thuật: Loại các trường hợp x < 2,
        x chẵn (trừ 2), sau đó kiểm tra chia hết cho
        các số lẻ từ 3 đến sqrt(x).
    */
    bool isPrime(int x) const;
 
    /*
        Tên phương thức : swp
        ---------------------------------------
        Input: Hai tham chiếu số nguyên a và b.
        ---------------------------------------
        Output: Không trả về giá trị; hoán đổi giá trị
        của a và b.
    */
    void swp(int& a, int& b) const;
 
    /*
        Tên phương thức : _merge
        ---------------------------------------
        Input: Thứ tự sắp xếp (asc), chỉ số đầu (lo)
        và chỉ số cuối (hi) của đoạn cần sắp xếp.
        ---------------------------------------
        Output: Không trả về giá trị; sắp xếp đoạn
        data[lo..hi] trực tiếp trên mảng.
        ---------------------------------------
        Hướng giải thuật: Đệ quy chia đôi mảng (merge sort),
        sau đó trộn hai nửa đã sắp theo thứ tự tăng hoặc
        giảm dần tùy tham số asc; dùng mảng tạm để trộn.
    */
    void _merge(bool asc, int lo, int hi);
 
public:
    /*
        Tên phương thức : Array (constructor)
        ---------------------------------------
        Input: Không có.
        ---------------------------------------
        Output: Khởi tạo đối tượng với data = nullptr
        và n = 0.
    */
    Array();
 
    /*
        Tên phương thức : ~Array (destructor)
        ---------------------------------------
        Input: Không có.
        ---------------------------------------
        Output: Giải phóng bộ nhớ động đã cấp cho data.
    */
    ~Array();
 
    /*
        Tên phương thức : input
        ---------------------------------------
        Input: Số lượng phần tử và các giá trị nguyên
        từ bàn phím.
        ---------------------------------------
        Output: Không trả về giá trị; cấp phát và gán
        dữ liệu cho mảng data.
        ---------------------------------------
        Hướng giải thuật: Nhập n (bắt buộc > 0), cấp phát
        mảng động, sau đó nhập từng phần tử.
    */
    void input();
 
    /*
        Tên phương thức : print
        ---------------------------------------
        Input: Không có.
        ---------------------------------------
        Output: In nội dung mảng ra màn hình theo
        định dạng [ a[0], a[1], ... ].
    */
    void print() const;
 
    /*
        Tên phương thức : sortedStatus
        ---------------------------------------
        Input: Không có.
        ---------------------------------------
        Output: Trả về  1 nếu tăng dần,  -1 nếu giảm dần,
        2 nếu tất cả bằng nhau, 0 nếu không có thứ tự.
        ---------------------------------------
        Hướng giải thuật: Duyệt mảng một lượt, theo dõi
        đồng thời hai cờ asc và desc; kết hợp hai cờ để
        trả về trạng thái.
    */
    int sortedStatus() const;
 
    /*
        Tên phương thức : count
        ---------------------------------------
        Input: Giá trị nguyên x cần đếm.
        ---------------------------------------
        Output: Trả về số lần xuất hiện của x trong mảng.
    */
    int count(int x) const;
 
    /*
        Tên phương thức : minOdd
        ---------------------------------------
        Input: Tham chiếu result để lưu kết quả.
        ---------------------------------------
        Output: Trả về true và gán result = giá trị lẻ
        nhỏ nhất nếu tồn tại; trả về false nếu không có
        phần tử lẻ nào.
    */
    bool minOdd(int& result) const;
 
    /*
        Tên phương thức : maxPrime
        ---------------------------------------
        Input: Tham chiếu result để lưu kết quả.
        ---------------------------------------
        Output: Trả về true và gán result = số nguyên tố
        lớn nhất nếu tồn tại; trả về false nếu không có.
    */
    bool maxPrime(int& result) const;
 
    /*
        Tên phương thức : printInfo
        ---------------------------------------
        Input: Không có.
        ---------------------------------------
        Output: In ra màn hình nội dung mảng, trạng thái
        sắp xếp, phần tử lẻ nhỏ nhất và số nguyên tố lớn nhất.
    */
    void printInfo() const;
 
    /*
        Tên phương thức : mergeSort
        ---------------------------------------
        Input: Tham số asc (mặc định true = tăng dần).
        ---------------------------------------
        Output: Không trả về giá trị; sắp xếp toàn bộ
        mảng theo thứ tự được chỉ định.
    */
    void mergeSort(bool asc = true);
};
