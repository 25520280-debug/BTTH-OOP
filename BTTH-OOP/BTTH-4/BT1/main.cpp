#include "SoPhuc.h"

int main() {
    SoPhuc z1 = nhapSoPhuc("z1");
    cout << '\n';
    SoPhuc z2 = nhapSoPhuc("z2");
    cout << '\n';
    int n = nhapSoMu();
    cout << '\n';

    inTitle("GIA TRI NHAP:");
    inNhan("z1");              z1.xuatGiaTri();       cout << '\n';
    inNhan("z2");              z2.xuatGiaTri();       cout << '\n';

    inTitle("DANG LUONG GIAC:");
    inNhan("z1");              z1.xuatLuongGiac();    cout << '\n';
    inNhan("z2");              z2.xuatLuongGiac();    cout << '\n';

    inTitle("TINH CHAT:");
    inNhan("|z1|");            z1.xuatModulus();      cout << '\n';
    inNhan("|z2|");            z2.xuatModulus();      cout << '\n';
    inNhan("arg(z1)");         z1.xuatArgument();     cout << '\n';
    inNhan("arg(z2)");         z2.xuatArgument();     cout << '\n';
    inNhan("conj(z1)");        z1.lien_hop().xuatGiaTri();  cout << '\n';
    inNhan("conj(z2)");        z2.lien_hop().xuatGiaTri();  cout << '\n';
    inNhan("-z1");             (-z1).xuatGiaTri();    cout << '\n';
    inNhan("-z2");             (-z2).xuatGiaTri();    cout << '\n';
    inNhan("z1 la so 0?");     cout << (z1.laSo0()     ? "Co" : "Khong") << '\n';
    inNhan("z1 la so thuc?");  cout << (z1.laSoThuc()  ? "Co" : "Khong") << '\n';
    inNhan("z1 la thuan ao?"); cout << (z1.laThuanAo() ? "Co" : "Khong") << '\n';
    inNhan("z2 la so 0?");     cout << (z2.laSo0()     ? "Co" : "Khong") << '\n';
    inNhan("z2 la so thuc?");  cout << (z2.laSoThuc()  ? "Co" : "Khong") << '\n';
    inNhan("z2 la thuan ao?"); cout << (z2.laThuanAo() ? "Co" : "Khong") << '\n';

    inTitle("4 PHEP TOAN:");
    inNhan("z1 + z2");         (z1 + z2).xuatGiaTri(); cout << '\n';
    inNhan("z1 - z2");         (z1 - z2).xuatGiaTri(); cout << '\n';
    inNhan("z1 * z2");         (z1 * z2).xuatGiaTri(); cout << '\n';
    inNhan("z1 / z2");         (z1 / z2).xuatGiaTri(); cout << '\n';
    inNhan("z2 / z1");         (z2 / z1).xuatGiaTri(); cout << '\n';

    inTitle("LUY THUA & CAN BAC HAI:");
    inNhan("sqrt(z1)");        z1.can_bac_hai().xuatGiaTri(); cout << '\n';
    inNhan("sqrt(z2)");        z2.can_bac_hai().xuatGiaTri(); cout << '\n';
    inNhan("z1^n");            z1.luy_thua(n).xuatGiaTri();   cout << '\n';
    inNhan("z2^n");            z2.luy_thua(n).xuatGiaTri();   cout << '\n';

    inTitle("SO SANH:");
    inNhan("z1 == z2");        cout << (z1 == z2 ? "True"  : "False") << '\n';
    inNhan("z1 != z2");        cout << (z1 != z2 ? "True"  : "False") << '\n';

    inTitle("KIEM TRA TINH CHAT:");
    inNhan("z1 * conj(z1)");   (z1 * z1.lien_hop()).xuatGiaTri(); cout << '\n';
    inNhan("|z1|^2");          cout << z1.modulus() * z1.modulus()  << '\n';
    inNhan("z2 * conj(z2)");   (z2 * z2.lien_hop()).xuatGiaTri(); cout << '\n';
    inNhan("|z2|^2");          cout << z2.modulus() * z2.modulus()  << '\n';

    inDuong();
    return 0;
}
