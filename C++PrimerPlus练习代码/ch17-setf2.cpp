#include <iostream>
#include <cmath>
int main(){
    using namespace std;
    //使用左对齐，显示正号，显示分隔符
        //显示末尾的0，精度为3
    cout.setf(ios_base::left,ios_base::adjustfield);
    cout.setf(ios_base::showpoint);
    cout.setf(ios_base::showpos);
    cout.precision(3);
    ios_base::fmtflags old = cout.setf(ios_base::scientific,ios_base::floatfield);
    cout<<"左对齐:\n";
    long n;
    for(n=1;n<=41;n+=10){
        cout.width(4);
        cout<<n<<"|";
        cout.width(12);
        cout<<sqrt(double(n))<<"|\n";
    }
    //更改为内部对齐
    cout.setf(ios_base::internal,ios_base::adjustfield);
    cout.setf(old,ios_base::floatfield);
    cout<<"内部对齐:\n";
    for(n=1;n<=41;n+=10){
        cout.width(4);
        cout<<n<<"|";
        cout.width(12);
        cout<<sqrt(double(n))<<"|\n";
    }
    //更改为右对齐
    cout.setf(ios_base::right,ios_base::adjustfield);
    cout.setf(ios_base::fixed,ios_base::floatfield);
    cout<<"右对齐:\n";
    for(n=1;n<=41;n+=10){
        cout.width(4);
        cout<<n<<"|";
        cout.width(12);
        cout<<sqrt(double(n))<<"|\n";
    }
    return 0;
}