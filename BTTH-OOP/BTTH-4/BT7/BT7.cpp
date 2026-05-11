#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stdexcept>

using namespace std;

class CVector {
public:
    vector<double> data;
    int dim;

    CVector() : dim(0) {}
    CVector(int n) : dim(n), data(n, 0.0) {}
    CVector(vector<double> v) : data(v), dim(v.size()) {}

    double& operator[](int i) { return data[i]; }
    const double& operator[](int i) const { return data[i]; }

    void nhap(const string& ten = "v") {
        cout << "Nhap so chieu cua " << ten << ": ";
        cin >> dim;
        data.resize(dim);
        for (int i = 0; i < dim; i++) {
            cout << "  " << ten << "[" << i << "] = ";
            cin >> data[i];
        }
    }

    void xuat(const string& ten = "v") const {
        cout << ten << " = [ ";
        for (int i = 0; i < dim; i++)
            cout << setw(8) << data[i] << (i < dim - 1 ? ", " : " ");
        cout << "]" << endl;
    }
};

class CMatrix {
private:
    vector<vector<double>> data;
    int rows, cols;

public:
    CMatrix() : rows(0), cols(0) {}

    CMatrix(int r, int c) : rows(r), cols(c), data(r, vector<double>(c, 0.0)) {}

    CMatrix(vector<vector<double>> d) : data(d), rows(d.size()), cols(d[0].size()) {}

    int soHang() const { return rows; }
    int soCot() const { return cols; }

    double& operator()(int i, int j) { return data[i][j]; }
    const double& operator()(int i, int j) const { return data[i][j]; }

    void nhap(const string& ten = "A") {
        cout << "Nhap kich thuoc ma tran " << ten << ":" << endl;
        cout << "  So hang: "; cin >> rows;
        cout << "  So cot : "; cin >> cols;
        data.assign(rows, vector<double>(cols, 0.0));
        cout << "Nhap cac phan tu cua " << ten << ":" << endl;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                cout << "  " << ten << "[" << i << "][" << j << "] = ";
                cin >> data[i][j];
            }
    }

    void xuat(const string& ten = "A") const {
        cout << ten << " (" << rows << "x" << cols << "):" << endl;
        for (int i = 0; i < rows; i++) {
            cout << "  | ";
            for (int j = 0; j < cols; j++)
                cout << setw(9) << fixed << setprecision(4) << data[i][j] << " ";
            cout << "|" << endl;
        }
    }

    CMatrix operator+(const CMatrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Kich thuoc khong khop de cong!");
        CMatrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    CMatrix operator-(const CMatrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Kich thuoc khong khop de tru!");
        CMatrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    CMatrix operator*(double scalar) const {
        CMatrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] * scalar;
        return result;
    }

    friend CMatrix operator*(double scalar, const CMatrix& m) {
        return m * scalar;
    }

    CMatrix operator*(const CMatrix& other) const {
        if (cols != other.rows)
            throw invalid_argument("So cot A phai bang so hang B de nhan!");
        CMatrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    CVector operator*(const CVector& v) const {
        if (cols != v.dim)
            throw invalid_argument("So cot A phai bang so chieu v de nhan!");
        CVector result(rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result[i] += data[i][j] * v[j];
        return result;
    }

    CMatrix operator-() const {
        CMatrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = -data[i][j];
        return result;
    }

    bool operator==(const CMatrix& other) const {
        if (rows != other.rows || cols != other.cols) return false;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (fabs(data[i][j] - other.data[i][j]) > 1e-9) return false;
        return true;
    }

    bool operator!=(const CMatrix& other) const { return !(*this == other); }

    CMatrix chuyen_vi() const {
        CMatrix result(cols, rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[j][i] = data[i][j];
        return result;
    }

    bool la_vuong() const { return rows == cols; }

    double vet() const {
        if (!la_vuong()) throw invalid_argument("Vet chi tinh duoc tren ma tran vuong!");
        double s = 0;
        for (int i = 0; i < rows; i++) s += data[i][i];
        return s;
    }

    CMatrix lay_ma_tran_con(int loai_hang, int loai_cot) const {
        CMatrix result(rows - 1, cols - 1);
        int ri = 0;
        for (int i = 0; i < rows; i++) {
            if (i == loai_hang) continue;
            int rj = 0;
            for (int j = 0; j < cols; j++) {
                if (j == loai_cot) continue;
                result.data[ri][rj++] = data[i][j];
            }
            ri++;
        }
        return result;
    }

    double dinh_thuc() const {
        if (!la_vuong()) throw invalid_argument("Dinh thuc chi tinh duoc tren ma tran vuong!");
        if (rows == 1) return data[0][0];
        if (rows == 2) return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        double det = 0;
        for (int j = 0; j < cols; j++) {
            double cofactor = ((j % 2 == 0) ? 1 : -1) * lay_ma_tran_con(0, j).dinh_thuc();
            det += data[0][j] * cofactor;
        }
        return det;
    }

    CMatrix ma_tran_phu_hop() const {
        if (!la_vuong()) throw invalid_argument("Ma tran phu hop chi tinh tren ma tran vuong!");
        CMatrix adj(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                adj.data[j][i] = (((i + j) % 2 == 0) ? 1 : -1) * lay_ma_tran_con(i, j).dinh_thuc();
        return adj;
    }

    CMatrix nghich_dao() const {
        if (!la_vuong()) throw invalid_argument("Ma tran nghich dao chi tinh tren ma tran vuong!");
        double det = dinh_thuc();
        if (fabs(det) < 1e-12) throw invalid_argument("Ma tran suy bien, khong co nghich dao!");
        return ma_tran_phu_hop() * (1.0 / det);
    }

    static CMatrix don_vi(int n) {
        CMatrix I(n, n);
        for (int i = 0; i < n; i++) I.data[i][i] = 1.0;
        return I;
    }

    CMatrix luy_thua(int p) const {
        if (!la_vuong()) throw invalid_argument("Luy thua chi ap dung tren ma tran vuong!");
        if (p < 0) throw invalid_argument("Luy thua phai >= 0!");
        CMatrix result = don_vi(rows);
        CMatrix base = *this;
        for (int i = 0; i < p; i++) result = result * base;
        return result;
    }

    CMatrix giai_phuong_trinh(const CVector& b) const {
        if (!la_vuong()) throw invalid_argument("Ma tran he so phai vuong!");
        if (b.dim != rows) throw invalid_argument("Kich thuoc b khong khop!");
        double det = dinh_thuc();
        if (fabs(det) < 1e-12) throw invalid_argument("He phuong trinh vo nghiem hoac vo so nghiem!");
        CMatrix x(rows, 1);
        for (int j = 0; j < cols; j++) {
            CMatrix Aj = *this;
            for (int i = 0; i < rows; i++) Aj.data[i][j] = b[i];
            x.data[j][0] = Aj.dinh_thuc() / det;
        }
        return x;
    }
};

void in_duong(int n = 50) { for (int i = 0; i < n; i++) cout << "-"; cout << endl; }
void in_title(const string& s) { in_duong(); cout << s << endl; in_duong(); }

int main() {
    cout << "============================================" << endl;
    cout << "          DEMO LOP CMATRIX                  " << endl;
    cout << "============================================" << endl;

    CMatrix A, B;

    cout << "\n[1] NHAP MA TRAN A:" << endl;
    A.nhap("A");

    cout << "\n[2] NHAP MA TRAN B (cung kich thuoc " << A.soHang() << "x" << A.soCot() << "):" << endl;
    B = CMatrix(A.soHang(), A.soCot());
    for (int i = 0; i < B.soHang(); i++)
        for (int j = 0; j < B.soCot(); j++) {
            cout << "  B[" << i << "][" << j << "] = ";
            cin >> B(i, j);
        }

    in_title("KET QUA NHAP:");
    A.xuat("A");
    cout << endl;
    B.xuat("B");

    in_title("PHEP TOAN CO BAN:");
    (A + B).xuat("A + B");
    cout << endl;
    (A - B).xuat("A - B");
    cout << endl;
    (-A).xuat("-A");

    double k;
    cout << "\nNhap he so scalar k: ";
    cin >> k;
    (A * k).xuat("A * k");
    cout << endl;
    (k * A).xuat("k * A");

    in_title("CHUYEN VI:");
    A.chuyen_vi().xuat("A^T");

    in_title("TICH MA TRAN - MA TRAN:");
    try {
        (A * B).xuat("A * B");
    } catch (exception& e) {
        cout << "  [!] " << e.what() << endl;
    }

    in_title("TICH MA TRAN - VECTOR:");
    CVector v;
    v.nhap("v");
    try {
        CVector kq = A * v;
        kq.xuat("A * v");
    } catch (exception& e) {
        cout << "  [!] " << e.what() << endl;
    }

    if (A.la_vuong()) {
        in_title("TINH CHAT MA TRAN VUONG:");
        cout << "Vet (trace) cua A    = " << A.vet() << endl;

        double det = A.dinh_thuc();
        cout << "Dinh thuc cua A      = " << det << endl;

        if (fabs(det) > 1e-12) {
            cout << endl;
            A.nghich_dao().xuat("A^(-1)");
            cout << endl;
            (A * A.nghich_dao()).xuat("A * A^(-1) (kiem tra = I)");
        } else {
            cout << "A la ma tran suy bien, khong co nghich dao." << endl;
        }

        cout << "\nNhap so mu p (luy thua A^p): ";
        int p; cin >> p;
        try {
            A.luy_thua(p).xuat("A^p");
        } catch (exception& e) {
            cout << "  [!] " << e.what() << endl;
        }

        in_title("GIAI HE PHUONG TRINH Ax = b:");
        CVector b(A.soHang());
        for (int i = 0; i < A.soHang(); i++) {
            cout << "  b[" << i << "] = ";
            cin >> b[i];
        }
        try {
            CMatrix x = A.giai_phuong_trinh(b);
            cout << "Nghiem x:" << endl;
            for (int i = 0; i < x.soHang(); i++)
                cout << "  x[" << i << "] = " << x(i, 0) << endl;
            CVector ktra = A * b;
            cout << "\nKiem tra A*x:" << endl;
            (A * b).xuat("A * x");
        } catch (exception& e) {
            cout << "  [!] " << e.what() << endl;
        }
    }

    in_title("TICH HAI MA TRAN KHAC KICH THUOC:");
    cout << "Nhap ma tran C (so hang = so cot cua A = " << A.soCot() << "):" << endl;
    CMatrix C;
    C.nhap("C");
    try {
        (A * C).xuat("A * C");
    } catch (exception& e) {
        cout << "  [!] " << e.what() << endl;
    }

    in_title("SO SANH:");
    cout << "A == B ? " << (A == B ? "Bang nhau" : "Khac nhau") << endl;
    cout << "A != B ? " << (A != B ? "Khac nhau" : "Bang nhau") << endl;

    in_title("MA TRAN DON VI 3x3:");
    CMatrix::don_vi(3).xuat("I3");

    return 0;
}