# DOAN_NMLT_KHTN
#
LibraryManagement/
├── include/               # Thư mục chứa các file header (.h)
│   ├── core/             # Core components
│   │   ├── Date.h
│   │   ├── Library.h
│   │   └── Constants.h
│   ├── entities/         # Các thực thể
│   │   ├── Book.h
│   │   ├── Reader.h
│   │   └── BorrowTicket.h
│   ├── services/         # Các dịch vụ
│   │   ├── BookService.h
│   │   ├── ReaderService.h
│   │   └── BorrowService.h
│   └── utils/            # Tiện ích
│       ├── InputHelper.h
│       ├── DateUtils.h
│       └── Menu.h
├── src/                  # Thư mục chứa các file nguồn (.cpp)
│   ├── core/
│   │   └── Library.cpp
│   ├── entities/
│   │   ├── Book.cpp
│   │   ├── Reader.cpp
│   │   └── BorrowTicket.cpp
│   ├── services/
│   │   ├── BookService.cpp
│   │   ├── ReaderService.cpp
│   │   └── BorrowService.cpp
│   ├── utils/
│   │   ├── InputHelper.cpp
│   │   ├── DateUtils.cpp
│   │   └── Menu.cpp
│   └── main.cpp         # File main chương trình
├── test/                # Thư mục test
│   ├── unit_tests/      # Unit tests
│   └── integration_tests/ # Integration tests
├── docs/                # Tài liệu dự án
├── CMakeLists.txt       # File cấu hình CMake
└── README.md           # Hướng dẫn dự án

#
Tôi muốn bạn viết một chương trình quản lý thư viện chạy trên nền console bằng ngôn ngữ C++. Chương trình cần quản lý 3 loại thông tin: độc giả, sách và phiếu mượn/trả sách. Dưới đây là yêu cầu chi tiết:

### Yêu cầu thông tin:
1. **Thông tin độc giả**:
   - Mã độc giả (chuỗi)
   - Họ tên (chuỗi)
   - CMND (chuỗi)
   - Ngày tháng năm sinh (ngày, tháng, năm)
   - Giới tính (chuỗi)
   - Email (chuỗi)
   - Địa chỉ (chuỗi)
   - Ngày lập thẻ (ngày, tháng, năm)
   - Ngày hết hạn thẻ (tự động tính: 48 tháng kể từ ngày lập thẻ)

2. **Thông tin sách**:
   - ISBN (chuỗi)
   - Tên sách (chuỗi)
   - Tác giả (chuỗi)
   - Nhà xuất bản (chuỗi)
   - Năm xuất bản (số nguyên)
   - Thể loại (chuỗi)
   - Giá sách (số nguyên)
   - Số quyển sách (số nguyên)

3. **Thông tin phiếu mượn/trả sách**:
   - Mã độc giả (chuỗi)
   - Ngày mượn (ngày, tháng, năm)
   - Ngày trả dự kiến (tự động tính: 7 ngày kể từ ngày mượn)
   - Ngày trả thực tế (ngày, tháng, năm, nhập khi trả sách)
   - Danh sách ISBN của các sách được mượn (danh sách chuỗi)

### Yêu cầu chức năng:
1. **Thêm độc giả**: Nhập thông tin độc giả và tự động tính ngày hết hạn thẻ.
2. **Thêm sách**: Nhập thông tin sách.
3. **Mượn sách**: 
   - Nhập mã độc giả, ngày mượn, danh sách ISBN sách mượn.
   - Giảm số lượng sách trong kho.
   - Tính ngày trả dự kiến.
4. **Trả sách**: 
   - Nhập mã độc giả và ngày trả thực tế.
   - Tăng số lượng sách trong kho.
   - Tính tiền phạt nếu quá hạn: 5.000 đồng/ngày.
   - (Tùy chọn: Nếu sách mất, phạt 200% giá sách, nhưng có thể bỏ qua nếu phức tạp).

### Yêu cầu kỹ thuật:
- Sử dụng `struct` để định nghĩa các kiểu dữ liệu cho độc giả, sách và phiếu mượn.
- Sử dụng `vector` để lưu danh sách độc giả, sách và phiếu mượn.
- Tạo menu chính với các lựa chọn: 
  1. Thêm độc giả
  2. Thêm sách
  3. Mượn sách
  4. Trả sách
  5. Thoát
- Xử lý ngày tháng đơn giản (giả sử mỗi tháng 30 ngày nếu cần).

### Hướng dẫn:
- Viết mã nguồn hoàn chỉnh, bao gồm các thư viện cần thiết (`iostream`, `string`, `vector`, v.v.).
- Tạo các hàm riêng biệt cho từng chức năng (addReader, addBook, borrowBook, returnBook).
- Đảm bảo chương trình có thể chạy lặp lại qua menu cho đến khi người dùng chọn thoát.

Hãy viết chương trình này bằng C++ và cung cấp mã nguồn hoàn chỉnh