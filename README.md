Tính năng
1.Sinh khóa RSA:

Nhập hai số nguyên tố p và q

Tự động tính n = p * q và φ(n) = (p-1)*(q-1)

Tự động chọn số mũ công khai e

Tính khóa bí mật d

2.Mã hóa và giải mã:

Mã hóa số nguyên

Mã hóa chuỗi ký tự (chuyển thành mã ASCII)

Giải mã thông điệp đã mã hóa

Yêu cầu hệ thống
Trình biên dịch C++ hỗ trợ C++11 hoặc cao hơn

Hệ điều hành: Windows/Linux/macOS


#Cách biên dịch và chạy
Biên dịch:
bash
g++ RSAFNl.cpp -o RSAFNL

Chạy chương trình:
bash
./RSAFNL

Hướng dẫn sử dụng
Bước 1: Biên dịch chương trình
bash
g++ RSAFNl.cpp -o RSAFNL
Bước 2: Chạy chương trình
bash
./RSAFNL
Bước 3: Thực hiện các thao tác
1.Sinh khóa:

Nhập số nguyên tố p

Nhập số nguyên tố q (khác p)

Chương trình sẽ tự động sinh khóa công khai (e, n) và khóa bí mật (d, n)

2.Chọn loại mã hóa:

*Lựa chọn 1: Mã hóa số nguyên

Nhập số nguyên M (0 ≤ M < n)

Xem kết quả mã hóa và giải mã

*Lựa chọn 2: Mã hóa chuỗi ký tự

Nhập chuỗi cần mã hóa

Xem kết quả mã hóa (dưới dạng mã ASCII) và chuỗi đã giải mã

Lưu ý quan trọng
1.Số nguyên tố:
p và q phải là số nguyên tố
p và q phải khác nhau
Nên chọn p và q đủ lớn để đảm bảo an toàn

2.Thông điệp:
Đối với số nguyên: M phải nhỏ hơn n
Đối với chuỗi: Mỗi ký tự được chuyển thành mã ASCII trước khi mã hóa

3.Giới hạn:
Chương trình này chỉ phục vụ mục đích học tập
Không sử dụng cho mục đích bảo mật thực tế

#Cấu trúc chương trình
Các hàm chính:
power(): Tính lũy thừa modulo (a^b mod m)

isPrime(): Kiểm tra số nguyên tố

extendedGCD(): Thuật toán Euclid mở rộng

modInverse(): Tìm nghịch đảo modulo

generateKeys(): Sinh khóa RSA

encrypt()/decrypt(): Mã hóa/giải mã số nguyên

encryptString()/decryptString(): Mã hóa/giải mã chuỗi

Biến quan trọng:
p, q: Số nguyên tố

n = p * q: Modulus

φ = (p-1)*(q-1): Hàm phi Euler

e: Số mũ công khai

d: Số mũ bí mật

#Ví dụ sử dụng
Ví dụ 1: Mã hóa số nguyên
text
Nhap so nguyen to p: 61
Nhap so nguyen to q (khac 61): 53

n = p * q = 3233
phi(n) = (p-1) * (q-1) = 3120

Khoa cong khai (e, n): (7, 3233)
Khoa bi mat (d, n): (1783, 3233)

Chon loai du lieu: 1
Nhap thong diep M: 65

Thong diep goc: 65
Thong diep da ma hoa: 2790
Thong diep da giai ma: 65
Ví dụ 2: Mã hóa chuỗi
text
Chon loai du lieu: 2
Nhap chuoi can ma hoa: HELLO

Chuoi goc: HELLO
Chuoi da ma hoa: 1394 610 2222 2222 2080
Chuoi da giai ma: HELLO


Hạn chế và cải tiến có thể thực hiện
Hạn chế hiện tại:
Chỉ xử lý ký tự ASCII đơn giản
Không xử lý số nguyên lớn (sử dụng long long)
Không có giao diện đồ họa
Không lưu/đọc khóa từ file

Cải tiến có thể thực hiện:
Sử dụng thư viện xử lý số lớn (GMP)
Thêm chức năng lưu/đọc khóa từ file
Hỗ trợ UTF-8 cho tiếng Việt
Thêm giao diện đồ họa
Triển khai padding scheme (OAEP)


