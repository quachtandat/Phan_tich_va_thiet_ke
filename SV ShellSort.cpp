#include <stdio.h>
#include<string.h>
#define Max 100
struct TX{
	int ma;
	char thuonghieu[50];
	float gia;
};
void nhap1sv(TX &s)
{
	printf("Nhap vao MSSV: ");
	scanf("%d",&s.ma);
	fflush(stdin);
	printf("Nhap vao ho ten: ");
	gets(s.thuonghieu);
	printf("Nhap vao diem trung binh: ");
	scanf("%f",&s.gia);
}
void shellSort(TX a[], int n) {
  
  int gap = n / 2;
  while (gap > 0) {
    // Do a gapped insertion sort for this gap size
    for (int i = gap; i < n; i++) {
      // Store the current string in a temporary variable
      char *temp = a[i];
      // Shift earlier gap-sorted strings up until the correct location for temp is found
      int j;
      for (j = i; j >= gap && strcmp(a[j - gap], temp) > 0; j -= gap) {
        a[j] = a[j - gap];
      }
      // Put temp in its correct location
      arr[j] = temp;
    }
    // Reduce the gap
    gap /= 2;
  }
}

void Nhapmang(TX a[], int &n){
	do{
		printf("Nhap vao so luong phan tu: ");
		scanf("%d",&n);
	}while(n<1 || n>Max);
	for(int i=0;i<n;i++)
	nhap1sv(a[i]);
		//scanf("%d",&a[i]);
	
}
void ghiFile(TX a[], int n)
{
	FILE* f = fopen("SVShellSort.txt" , "ab");
	fwrite(a, sizeof(TX),n,f);
	fclose(f);
}
void docFile(TX a[], int &n)
{
	n=0;
	FILE* f = fopen("SVShellSort.txt" , "rb");
	while(!feof(f))
	{
		if(fread(&a[n],sizeof(SV),1,f)) n++;
	}
	fclose(f);
}
void Xuatmang(TX a[], int n)
{
	for (int i = 0; i<n; i++)
		printf(" %d\t%s\t%0.1f\n ", a[i].ma,a[i].thuonghieu,a[i].gia);
	
	
}
int main(){
	int n;
	TX a[10001];
	Nhapmang(a, n);
	ghiFile(a, n);
	docFile(a, n);
	shellSort(a, n);
	printf("Mang sau khi da duoc sap xep theo thuat toan ShellSort: \n");
	Xuatmang(a, n);
	return 0;
}

