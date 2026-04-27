#pragma once
#include <string>
using namespace std;

class ProductionWorker {
private:
    string id;
    string fullName;
    string birthDate;
    int producedUnits;
    double unitPrice;

    /*
        Tên phương thức : isValidDate
        ---------------------------------------
        Input: Chuỗi date định dạng dd/mm/yyyy.
        ---------------------------------------
        Output: Trả về true nếu ngày hợp lệ, false nếu không.
        ---------------------------------------
        Hướng giải thuật: Kiểm tra định dạng dd/mm/yyyy, tách ngày
        tháng năm, kiểm tra tháng 1-12, năm > 0, ngày hợp lệ theo
        từng tháng (có xét năm nhuận cho tháng 2).
    */
    bool isValidDate(const string& date) const;
public:
    /*
        Tên phương thức : ProductionWorker
        ---------------------------------------
        Input: Không có tham số.
        ---------------------------------------
        Output: Khởi tạo object với các giá trị mặc định.
    */
    ProductionWorker();

    /*
        Tên phương thức : getId
        ---------------------------------------
        Input: Không có tham số.
        ---------------------------------------
        Output: Trả về mã nhân viên.
    */
    string getId() const;

    /*
        Tên phương thức : getFullName
        ---------------------------------------
        Input: Không có tham số.
        ---------------------------------------
        Output: Trả về họ tên nhân viên.
    */
    string getFullName() const;

    /*
        Tên phương thức : getBirthDate
        ---------------------------------------
        Input: Không có tham số.
        ---------------------------------------
        Output: Trả về ngày sinh nhân viên.
    */
    string getBirthDate() const;

    /*
        Tên phương thức : getProducedUnits
        ---------------------------------------
        Input: Không có tham số.
        ---------------------------------------
        Output: Trả về số sản phẩm đã gia công.
    */
    int getProducedUnits() const;

    /*
        Tên phương thức : getUnitPrice
        ---------------------------------------
        Input: Không có tham số.
        ---------------------------------------
        Output: Trả về đơn giá một sản phẩm.
    */
    double getUnitPrice() const;

    /*
        Tên phương thức : setId
        ---------------------------------------
        Input: Chuỗi id mới.
        ---------------------------------------
        Output: Không có giá trị trả về. Cập nhật id.
    */
    void setId(string id);

    /*
        Tên phương thức : setFullName
        ---------------------------------------
        Input: Chuỗi fullName mới.
        ---------------------------------------
        Output: Không có giá trị trả về. Cập nhật fullName.
    */
    void setFullName(string fullName);

    /*
        Tên phương thức : setBirthDate
        ---------------------------------------
        Input: Chuỗi birthDate mới.
        ---------------------------------------
        Output: Không có giá trị trả về. Cập nhật birthDate.
    */
    void setBirthDate(string birthDate);

    /*
        Tên phương thức : setProducedUnits
        ---------------------------------------
        Input: Số nguyên producedUnits mới.
        ---------------------------------------
        Output: Không có giá trị trả về. Cập nhật producedUnits.
    */
    void setProducedUnits(int producedUnits);

    /*
        Tên phương thức : setUnitPrice
        ---------------------------------------
        Input: Số thực unitPrice mới.
        ---------------------------------------
        Output: Không có giá trị trả về. Cập nhật unitPrice.
    */
    void setUnitPrice(double unitPrice);

    /*
        Tên phương thức : calcSalary
        ---------------------------------------
        Input: Không có tham số.
        ---------------------------------------
        Output: Trả về lương = producedUnits * unitPrice.
    */
    double calcSalary() const;

    /*
        Tên phương thức : getBirthYear
        ---------------------------------------
        Input: Không có tham số.
        ---------------------------------------
        Output: Trả về năm sinh trích từ chuỗi birthDate.
        ---------------------------------------
        Hướng giải thuật: Tìm vị trí dấu '/' cuối cùng trong
        chuỗi birthDate, lấy phần sau đó và chuyển sang số nguyên.
    */
    int getBirthYear() const;

    /*
        Tên phương thức : input
        ---------------------------------------
        Input: Nhận từ bàn phím id, họ tên, ngày sinh,
        số sản phẩm gia công và đơn giá.
        ---------------------------------------
        Output: Không có giá trị trả về. Cập nhật toàn bộ thuộc tính.
        ---------------------------------------
        Hướng giải thuật: Đọc id trước, dùng cin.ignore() để xử lý
        ký tự xuống dòng còn sót, sau đó dùng getline để nhận họ tên
        có khoảng trắng, tiếp tục đọc các trường còn lại.
    */
    void input();

    /*
        Tên phương thức : display
        ---------------------------------------
        Input: Không có tham số.
        ---------------------------------------
        Output: Không có giá trị trả về. In thông tin nhân viên
        ra màn hình theo định dạng cột cố định.
    */
    void display() const;
};