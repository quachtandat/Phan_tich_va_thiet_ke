#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define Max 10

struct SV
{
    int MSSV;
    char HoTen[50];
    float DTB;
};

 void nhap1SV(SV &s){
    printf("Nhap vao MSSV:");
    scanf("%d",&s.MSSV);
    fflush(stdin);
    printf("nhap ho ten:");
    gets(s.HoTen);
    printf("nhap vao DTB: ");
    scanf("%f",&s.DTB);
}

void nhapMang(SV A[], int &N)
{
    do{
        printf("nhap vào so luong phan tu:");
        scanf("%d",&N);
    }while(N<1 || N> Max);
    for (int i=0; i<N;i++){
        nhap1SV(A[i]);
    }
}

void ghiFile(SV A[], int N){
    FILE* f = fopen("SV.txt","ab");
    fwrite(A, sizeof(SV),N,f);

    fclose(f);
}

void docFile(SV A[], int &N){
    N=0;
    FILE* f = fopen("SV.txt","rb");
    while(!feof(f))
    {
        if(fread(&A[N], sizeof(SV), 1,f)) N++;
    }

    fclose(f);
}

void InMang(SV A[], int N){
    for(int i =0; i<N; i++){
        printf("%d\t%s\t%f\n",A[i].MSSV,A[i].HoTen,A[i].DTB);
    }
}

int shellSort(SV A[], int n) 
{ 
    // Start with a big gap, then reduce the gap 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is 
        // gap sorted  
        for (int i = gap; i < n; i += 1) 
        { 
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = A[i].MSSV; 
  
            // shift earlier gap-sorted elements up until the correct  
            // location for a[i] is found 
            int j;             
            for (j = i; j >= gap && A[j - gap].MSSV > temp; j -= gap) 
                A[j].MSSV = A[j - gap].MSSV; 
              
            //  put temp (the original a[i]) in its correct location 
            A[j].MSSV = temp; 
        } 
    } 
    return 0; 
} 
 

int main() {
    int N;
    SV A[Max];
   // nhapMang(A,N);
    //ghiFile(A,N);
    docFile(A,N);
    InMang(A,N);
   shellSort(A,N);
    printf("Mang A sau khi duoc sap xep bang giai thuat: \n");
    InMang(A,N);
    return 0;
}