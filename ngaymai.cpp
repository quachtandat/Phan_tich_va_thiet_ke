#include <iostream> //cin, cout
using namespace std;
#include<math.h>
#include<stdio.h>

int xacdinhsothang( int &month ,int year, int &tg ){
     switch(month)
    {
        case 4:
        case 6:
        case 9:
        case 11:
            tg = 30;
            break;
        case 2:
            tg = 28 + ((year%4==0 && year%100) || (year%400==0));
            break;
        default:
            tg = 31;
    }

}

void timngaymai(int day ,int month, int year, int tg){
    xacdinhsothang(month,year,tg);
    day = (day%tg)+1;
    if(day==1)
    {
        month = (month%12)+1;
    }

    cout<<"Ngay mai: "<<day<<"/"<<month<<"/"<<year;
}

void nagyhomqua(int day1 ,int month1, int year1){
    if(day1==1)
    {
        switch(month1-1)
        {
            case 4:
            case 6:
            case 9:
            case 11:
                day1=30;
                break;
            case 2:
                day1=28+((year1%4==0 && year1%100) || (year1%400==0));
                break;
            default:
                day1=31;
        }
        if(month1==1)
        {
            month1=12;
            year1--;
        }
        else
        {
            month1--;
        }
    }
    else
    {
        day1--;
    }

    cout<<"\nHom qua: "<<day1<<"/"<<month1<<"/"<<year1;
}

void nhapdulieu(int &day, int &day1 , int &month , int &month1, int &year, int &year1){
    cout<<"Nhap vao ngay: "; cin>>day; day1=day;
    cout<<"Nhap vao thang: "; cin>>month; month1=month;
    cout<<"Nhap vao nam: "; cin>>year; year1=year;
}
int main(){
    int day, month, year,day1, month1, year1 , tg;
    nhapdulieu(day, month, year,day1, month1, year1);
    timngaymai(day , month, year, tg);
    nagyhomqua(day , month, year);
    
}