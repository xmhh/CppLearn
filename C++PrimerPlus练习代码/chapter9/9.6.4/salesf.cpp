#include "salesh.h"
namespace SALES{
    void setSales(Sales &s, const double ar[],int n){
        double total = 0;
        double max = ar[0];
        double min = ar[0];
        for(int i=0;i<n;i++){
            s.sales[i] = ar[i];
            if (s.sales[i]==-1)
                continue;
            total += ar[i];
            if (ar[i]>=max)  max = ar[i];
            if (ar[i]<=min)  min = ar[i];
        }
        if(n<QUARTERS)
            for(int j=n;j<QUARTERS;j++)
                s.sales[j] = -9e20;
        s.average = total/n;
        s.max = max;
        s.min = min;
        std::cout<<"Sales has been set by the 1st setSales function!\n"<<std::endl;
    };
    void setSales(Sales &s){
        using std::cin;
        using std::cout;
        using std::endl;
        cout<<"Please input the sales of four quarters!\n";
        double total = 0;
        double max = 0;
        double min = 0;
        for(int i=0;i<QUARTERS;i++){
            cout<<"Please enter the "<<i+1<<" quarter sales: ";
            while(!(cin>>s.sales[i])){
                while(cin.get()!='\n')  continue;
                cout<<"Please input the correct sales of a quarter!"<<endl;
            }  
            if (s.sales[i]<0){
                while(cin.get()!='\n') continue;
                cout<<"the "<<i+1<<" quarter sales you input is below zero, \n";
                cout<<"do you want to input it again?(Y/N) ";
                char yn;
                cin.get(yn);
                if (yn == 'Y'||yn =='y')
                    i--;
                    continue;
            }
            total += s.sales[i];
            if (s.sales[i]>max)  
                max = s.sales[i];
            if (min==0)  
                min = s.sales[i];
            else if(s.sales[i]<min)
                min = s.sales[i];
        }
        s.average = total/4;
        s.max = max;
        s.min = min;
        cout<<"Sales has been set by the 2nd setSales function!\n"<<endl;
    };
    void showSales(const Sales &s){
        using std::cout;
        using std::endl;
        for(int i = 0;i<QUARTERS;i++)
            cout<<"The sale of "<<i+1<<" quarters is "<<s.sales[i]<<endl;
        cout<<"The average value of the sales is "<<s.average<<endl;
        cout<<"The maximum value of the sales is "<<s.max<<endl;
        cout<<"The minimum value of the sales is "<<s.min<<endl;
    };
}