#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // d�ng d? x�a kho?ng tr?ng th?a

using namespace std;

class CauhoiTN {
private:
    string noidung;
    string dapanA;
    string dapanB;
    char dapanDung; // 'A' ho?c 'B'

public:
    // Phuong th?c nh?p c�u h?i t? b�n ph�m
    void nhap() {
        cout << "Nhap noi dung cau hoi: ";
        getline(cin, noidung);
        cout << "Nhap noi dung dap an A: ";
        getline(cin, dapanA);
        cout << "Nhap noi dung dap an B: ";
        getline(cin, dapanB);
        do {
            cout << "Nhap dap an dung (A/B): ";
            cin >> dapanDung;
            dapanDung = toupper(dapanDung); // �?m b?o nh?p ch? hoa
        } while (dapanDung != 'A' && dapanDung != 'B');
        cin.ignore(); // B? qua k� t? newline c�n l?i
    }

    // Phuong th?c d?c d? li?u c�u h?i t? file
    void docfile(ifstream& f) {
        getline(f, noidung);
        getline(f, dapanA);
        getline(f, dapanB);
        f >> dapanDung;
        f.ignore(); // B? qua k� t? newline sau d�p �n d�ng
    }

    // Phuong th?c ghi c�u h?i v�o file
    void ghifile(ofstream& f) {
        f << noidung << endl;
        f << dapanA << endl;
        f << dapanB << endl;
        f << dapanDung << endl;
    }

    // Phuong th?c ki?m tra c�u tr? l?i c?a ngu?i d�ng
    void kiemtra() {
        char traloi;
        cout << "Cau hoi: " << noidung << endl;
        cout << "A: " << dapanA << endl;
        cout << "B: " << dapanB << endl;
        cout << "Nhap dap an cua ban (A/B): ";
        cin >> traloi;
        traloi = toupper(traloi);
        if (traloi == dapanDung) {
            cout << "Ban tra loi dung!" << endl;
        } else {
            cout << "Ban tra loi sai!" << endl;
        }
    }

    // Phuong th?c xu?t c�u h?i ra m�n h�nh
    void xuat() {
        cout << "Cau hoi: " << noidung << endl;
        cout << "A: " << dapanA << endl;
        cout << "B: " << dapanB << endl;
        cout << "Dap an dung: " << dapanDung << endl;
    }

    // H�m friend ki?m tra hai c�u h?i c� gi?ng nhau hay kh�ng
    friend bool giongnhau(CauhoiTN cau1, CauhoiTN cau2) {
        return cau1.noidung == cau2.noidung &&
               cau1.dapanA == cau2.dapanA &&
               cau1.dapanB == cau2.dapanB &&
               cau1.dapanDung == cau2.dapanDung;
    }

    // X�a kho?ng tr?ng th?a trong c�u h?i v� d�p �n
    void xoaKhoangTrongThua() {
        noidung.erase(remove(noidung.begin(), noidung.end(), ' '), noidung.end());
        dapanA.erase(remove(dapanA.begin(), dapanA.end(), ' '), dapanA.end());
        dapanB.erase(remove(dapanB.begin(), dapanB.end(), ' '), dapanB.end());
    }
};

// Menu ch?c nang
void menu() {
    CauhoiTN dsCauhoi[100]; // Danh s�ch c�u h?i
    int soCauhoi = 0;
    int luachon;

    do {
        cout << "\n==== MENU ====\n";
        cout << "1. Nhap cau hoi\n";
        cout << "2. Luu cau hoi vao file\n";
        cout << "3. Doc cau hoi tu file\n";
        cout << "4. Cho thi\n";
        cout << "5. Xoa khoang trang thua\n";
        cout << "6. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luachon;
        cin.ignore();

        switch (luachon) {
            case 1: {
                // Nh?p c�u h?i
                dsCauhoi[soCauhoi].nhap();
                soCauhoi++;
                break;
            }
            case 2: {
                // Luu c�u h?i v�o file
                ofstream fout("dethi.TTN");
                for (int i = 0; i < soCauhoi; i++) {
                    dsCauhoi[i].ghifile(fout);
                }
                fout.close();
                cout << "Da luu cau hoi vao file.\n";
                break;
            }
            case 3: {
                // �?c c�u h?i t? file
                ifstream fin("dethi.TTN");
                soCauhoi = 0;
                while (fin.peek() != EOF) {
                    dsCauhoi[soCauhoi].docfile(fin);
                    soCauhoi++;
                }
                fin.close();
                cout << "Da doc cau hoi tu file.\n";
                break;
            }
            case 4: {
                // Cho thi
                for (int i = 0; i < soCauhoi; i++) {
                    dsCauhoi[i].kiemtra();
                }
                break;
            }
            case 5: {
                // X�a kho?ng tr?ng th?a
                for (int i = 0; i < soCauhoi; i++) {
                    dsCauhoi[i].xoaKhoangTrongThua();
                }
                ofstream fout("dethi.TTN");
                for (int i = 0; i < soCauhoi; i++) {
                    dsCauhoi[i].ghifile(fout);
                }
                fout.close();
                cout << "Da xoa khoang trang thua va luu vao file.\n";
                break;
            }
            case 6:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (luachon != 6);
}

int main() {
    menu();
    return 0;
}

