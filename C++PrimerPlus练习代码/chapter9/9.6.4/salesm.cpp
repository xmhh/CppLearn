#include "salesh.h"

int main(){
    using namespace SALES;
    Sales sa,sb;
    double salearr[4] = {440.1,520.2,631.2,1000.1};
    setSales(sa);
    showSales(sa);
    setSales(sb,sa.sales,3);
    showSales(sb);
    return 0;
}