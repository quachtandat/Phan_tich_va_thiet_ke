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

int SoDuongChay(SV A[], int N){
    int dem =0,i=0;
    while(i<N){
        while(A[i].MSSV <= A[i+1].MSSV && i<N-1){
            i++;
        }
        dem++;
        i++;
    }
    return dem;
}

void Merge( SV A[], SV B[], SV C[], int &m, int &n, int &nA){
    int i=0, j=0;
    while(i<m && j< n){
        if(B[i].MSSV < C[j].MSSV){
            A[nA++]= B[i++];
        }else{
            A[nA++] = C[j++];
        }
    }
    while(i<m){
        A[nA++] = B[i++];
    }
    while(j<n){
        A[nA++] = C[j++];
    }
    m=0;
    n=0;
}

void PhanPhoiVaoMang(SV A[], int N, SV B[], SV C[]){
    int i=0,dem=0, nA=0;
    int m=0, n=0;
    while(i<N){
        int tmp=i;
        while(A[i].MSSV<A[i+1].MSSV&& i< N-1){
            i++;
        }
        if(dem % 2 == 0){
            for( int j = tmp; j<= i; j++){
                B[m++]= A[j];
            }
        }else{
            for(int j= tmp; j<= i; j++){
                C[n++] = A[j];
            }
            Merge(A,B,C,m,n,nA);
        }
        i++;
        dem++;
    }
    if( m!= 0){
        for(int k =0; k<m;k++){
            A[nA++]= B[k];
        }
    }
}

void NaturalMergeSort(SV A[], int N, SV B[], SV C[]){
    while(SoDuongChay(A,N)>=2){
        PhanPhoiVaoMang(A,N,B,C);
    }
}

void InMang(SV A[], int N){
    for(int i =0; i<N; i++){
        printf("%d\t%s\t%f\n",A[i].MSSV,A[i].HoTen,A[i].DTB);
    }
}

int main()
{
    SV A[Max], B[Max], C[Max];
    int m=0, n=0, k=0;
    int N;
    //nhapMang(A,N);
    //ghiFile(A,N);
    docFile(A,N);
    InMang(A,N);
    NaturalMergeSort(A,N,B,C);
    printf("Mang A sau khi duoc sap xep bang giai thuat: \n");
    InMang(A,N);
    return 0;
}
