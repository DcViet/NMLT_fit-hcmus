
---

### Giải thích thiết kế
1. **Quản lý độc giả**: Giữ nguyên các chức năng từ trước.
2. **Quản lý sách**: Giữ nguyên các chức năng từ trước.
3. **Lập phiếu mượn/trả sách**: Giữ nguyên từ trước, với `createBorrowTicket` và `createReturnTicket`.
4. **Thống kê cơ bản**:
   - `countBooks`: Tổng số quyển sách trong thư viện.
   - `countBooksByGenre`: Số sách theo từng thể loại.
   - `countReaders`: Tổng số độc giả.
   - `countReadersByGender`: Số độc giả nam và nữ.
   - `countBorrowedBooks`: Số sách đang được mượn (chưa trả).
   - `listOverdueReaders`: Liệt kê độc giả trễ hạn dựa trên ngày hiện tại.
5. **Kiểu dữ liệu**: Chỉ sử dụng `string` và `int`, lưu trữ trong mảng 1 chiều.
6. **Tổ chức mã**: Thêm file `Statistics.h/cpp` cho các chức năng thống kê, các hàm có comment chi tiết.
7. **Menu**: Cập nhật để bao gồm các chức năng thống kê.

---

### Biên dịch và chạy
1. Tạo cấu trúc thư mục và sao chép mã vào các tệp.
2. Biên dịch:
   ```bash
   mkdir build
   cd build
   cmake ..
   make