#include <bits/stdc++.h>
using namespace std;


//g++ RSAFNl.cpp -o RSAFNL
// Hàm tính lũy thừa modulo (a^b mod m)
long long power(long long base, long long expo, long long m) {
    long long res = 1;
    base = base % m;
    while (expo > 0) {
        if (expo & 1)
            res = (res * base) % m;
        base = (base * base) % m;
        expo = expo >> 1;
    }
    return res;
}

// Kiểm tra số nguyên tố.
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Thuật toán Euclid mở rộng để tìm nghịch đảo modulo
long long extendedGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Tìm nghịch đảo modulo của e theo phi
long long modInverse(long long e, long long phi) {
    long long x, y;
    long long gcd = extendedGCD(e, phi, x, y);
    
    if (gcd != 1) {
        return -1; // Không tồn tại nghịch đảo
    }
    
    // Đảm bảo x dương
    return (x % phi + phi) % phi;
}

// Sinh khóa RSA
bool generateKeys(long long &e, long long &d, long long &n) {
    int p, q;
    
    // Nhập p
    while (true) {
        cout << "Nhap so nguyen to p: ";
        cin >> p;
        if (isPrime(p)) {
            break;
        }
        cout << "Loi: " << p << " khong phai so nguyen to! Nhap lai.\n";
    }
    
    // Nhập q
    while (true) {
        cout << "Nhap so nguyen to q (khac " << p << "): ";
        cin >> q;
        if (q == p) {
            cout << "Loi: q phai khac p! Nhap lai.\n";
            continue;
        }
        if (isPrime(q)) {
            break;
        }
        cout << "Loi: " << q << " khong phai so nguyen to! Nhap lai.\n";
    }
    
    n = (long long)p * q;
    long long phi = (long long)(p - 1) * (q - 1);
    
    cout << "\nn = p * q = " << n << endl;
    cout << "phi(n) = (p-1) * (q-1) = " << phi << endl;
    
    // Chọn e sao cho 1 < e < phi và gcd(e, phi) = 1
    // Thường chọn e = 65537 hoặc e nhỏ
    for (e = 3; e < phi; e += 2) {
        if (__gcd(e, phi) == 1)
            break;
    }
    
    // Tính d là nghịch đảo modulo của e theo phi
    d = modInverse(e, phi);
    
    if (d == -1) {
        cout << "Loi: Khong tim duoc khoa bi mat!\n";
        return false;
    }
    
    return true;
}

// Mã hóa thông điệp
long long encrypt(long long m, long long e, long long n) {
    if (m >= n) {
        cout << "Canh bao: Thong diep phai nho hon n = " << n << endl;
        return -1;
    }
    return power(m, e, n);
}

// Giải mã thông điệp
long long decrypt(long long c, long long d, long long n) {
    return power(c, d, n);
}

// Mã hóa chuỗi ký tự
vector<long long> encryptString(string text, long long e, long long n) {
    vector<long long> encrypted;
    for (char ch : text) {
        long long m = (long long)ch;
        encrypted.push_back(encrypt(m, e, n));
    }
    return encrypted;
}

// Giải mã chuỗi ký tự
string decryptString(vector<long long> encrypted, long long d, long long n) {
    string decrypted = "";
    for (long long c : encrypted) {
        long long m = decrypt(c, d, n);
        decrypted += (char)m;
    }
    return decrypted;
}

int main() {
    long long e, d, n;
    
    cout << "========== CHUONG TRINH MA HOA RSA ==========\n\n";
    
    // Sinh khóa
    if (!generateKeys(e, d, n)) {
        return 1;
    }
    
    cout << "\n========== KHOA CONG KHAI VA BI MAT ==========\n";
    cout << "Khoa cong khai (e, n): (" << e << ", " << n << ")\n";
    cout << "Khoa bi mat (d, n): (" << d << ", " << n << ")\n";
    cout << "============================================\n\n";
    
    // Menu lựa chọn
    int choice;
    cout << "Chon loai du lieu muon ma hoa:\n";
    cout << "1. Ma hoa so nguyen\n";
    cout << "2. Ma hoa chuoi ky tu\n";
    cout << "Lua chon cua ban: ";
    cin >> choice;
    cin.ignore(); // Xóa ký tự newline
    
    if (choice == 1) {
        // Mã hóa số nguyên
        long long M;
        cout << "\nNhap thong diep M (0 <= M < " << n << "): ";
        cin >> M;
        
        if (M < 0 || M >= n) {
            cout << "Loi: Thong diep phai nam trong khoang [0, " << n-1 << "]\n";
            return 1;
        }
        
        cout << "\nThong diep goc: " << M << endl;
        
        // Mã hóa
        long long C = encrypt(M, e, n);
        cout << "Thong diep da ma hoa: " << C << endl;
        
        // Giải mã
        long long decrypted = decrypt(C, d, n);
        cout << "Thong diep da giai ma: " << decrypted << endl;
        
        // Kiểm tra
        if (M == decrypted) {
            cout << "\n Ma hoa va giai ma thanh cong!\n";
        } else {
            cout << "\n Loi: Ma hoa hoac giai ma khong chinh xac!\n";
        }
        
    } else if (choice == 2) {
        // Mã hóa chuỗi
        string text;
        cout << "\nNhap chuoi can ma hoa: ";
        getline(cin, text);
        
        cout << "\nChuoi goc: " << text << endl;
        
        // Mã hóa
        vector<long long> encrypted = encryptString(text, e, n);
        cout << "Chuoi da ma hoa (ma ASCII): ";
        for (long long c : encrypted) {
            cout << c << " ";
        }
        cout << endl;
        
        // Giải mã
        string decrypted = decryptString(encrypted, d, n);
        cout << "Chuoi da giai ma: " << decrypted << endl;
        
        // Kiểm tra
        if (text == decrypted) {
            cout << "\n Ma hoa va giai ma thanh cong!\n";
        } else {
            cout << "\n Loi: Ma hoa hoac giai ma khong chinh xac!\n";
        }
        
    } else {
        cout << "Lua chon khong hop le!\n";
    }
    
    return 0;
}