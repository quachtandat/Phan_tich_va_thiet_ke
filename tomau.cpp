#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Số đỉnh tối đa của đồ thị

// Khai báo kiểu dữ liệu ma trận kề
typedef int Matrix[MAX][MAX];

// Khai báo mảng màu
int color[MAX];

// Hàm nhập đồ thị từ file
int LoadGraph(int *n, Matrix a, char *fname)
{
    FILE *f;
    f = fopen(fname, "r");
    if (!f)
    {
        printf("\nLoi mo file");
        return 0;
    }
    fscanf(f, "%d", n); // Đọc số đỉnh của đồ thị
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *n; j++)
            fscanf(f, "%d", &a[i][j]); // Đọc ma trận kề
    fclose(f);
    return 1;
}

// Hàm đổi chỗ hai số nguyên
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Hàm sắp xếp các đỉnh theo thứ tự giảm dần của bậc
void sort(int n, Matrix a, int *deg, int *id)
{
    // Tính bậc của các đỉnh
    for (int i = 0; i < n; i++)
    {
        deg[i] = 0;
        for (int j = 0; j < n; j++)
            deg[i] += a[i][j];
    }
    // Khởi tạo mảng id là chỉ số của các đỉnh
    for (int i = 0; i < n; i++)
        id[i] = i;
    // Sắp xếp các đỉnh theo bậc giảm dần
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (deg[i] < deg[j])
            {
                swap(&deg[i], &deg[j]);
                swap(&id[i], &id[j]);
            }
}

// Hàm tô màu đồ thị theo thuật toán Welsh-Powell
void colorGraph(int n, Matrix a)
{
    int deg[MAX]; // Mảng lưu bậc của các đỉnh
    int id[MAX];  // Mảng lưu chỉ số của các đỉnh
    int count;    // Biến đếm số màu đã sử dụng

    // Sắp xếp các đỉnh theo bậc giảm dần
    sort(n, a, deg, id);

    // Khởi tạo màu của các đỉnh là 0
    for (int i = 0; i < n; i++)
        color[i] = 0;

    // Bắt đầu tô màu
    count = 0; // Ban đầu chưa sử dụng màu nào
    for (int i = 0; i < n; i++)
    {
        int u = id[i]; // Lấy đỉnh có bậc cao nhất trong các đỉnh chưa được tô màu
        if (color[u] == 0) // Nếu đỉnh u chưa được tô màu
        {
            count++; // Tăng số màu đã sử dụng lên 1
            color[u] = count; // Gán màu cho đỉnh u
            for (int j = i + 1; j < n; j++)
            {
                int v = id[j]; // Lấy đỉnh tiếp theo trong danh sách đã sắp xếp
                if (color[v] == 0 && a[u][v] == 0) // Nếu đỉnh v chưa được tô màu và không kề với đỉnh u
                {
                    int k;
                    for (k = 0; k < n; k++)
                        if (color[k] == count && a[v][k] > 0) // Kiểm tra xem có đỉnh nào đã tô màu count mà kề với đỉnh v hay không
                            break;
                    if (k == n) // Nếu không có đỉnh nào như vậy
                        color[v] = count; // Gán màu cho đỉnh v
                }
            }
        }
    }
}

// Hàm xuất kết quả ra màn hình
void printResult(int n)
{
    int max = 0; // Biến lưu số màu lớn nhất
    // Tìm số màu lớn nhất
    for (int i = 0; i < n; i++)
        if (color[i] > max)
            max = color[i];
    // In ra số màu sử dụng
    printf("\nSo mau su dung la %d\n", max);
    // In ra các đỉnh tương ứng với mỗi màu
    for (int i = 1; i <= max; i++)
    {
        printf("\nMau %d :", i);
        for (int j = 0; j < n; j++)
            if (color[j] == i)
                printf("%8d", j+1);
    }
}

// Hàm chính
int main()
{
    int n; // Số đỉnh của
    Matrix a; // Ma trận kề của đồ thị 
    char fname[50]; // Tên file chứa đồ thị 
    // Nhập tên file 
    printf("\nNhap ten file: "); scanf("%s", fname); 
    // Nạp đồ thị từ file 
    if (LoadGraph(&n, a, fname) == 0) return 0;
     // Tô màu đồ thị
    colorGraph(n, a);
    // Xuất kết quả 
    printResult(n);
    return 0; 
}