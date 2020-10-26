#include "namesp.h"
#include <cmath>

using namespace std;

extern const float e = 2.718;
extern int MAX;

static int myvar1 = 0;

polar rect2polar(const rect xypos){
    cout<<"function rect2polar"<<endl; 
    cout<<"外部变量MAX = "<<MAX<<endl;
    cout<<"外部常量e = "<<e<<endl;
    polar ans;
    ans.distance = sqrt(xypos.x*xypos.x + xypos.y*xypos.y);
    ans.angle = atan2(xypos.y,xypos.x);
    return ans;
}
rect polar2rect(const polar dapos){
    cout<<"function polar2rect"<<endl; 
    cout<<"外部变量 MAX = "<<MAX<<endl;
    cout<<"外部常量 e = "<<e<<endl;
    rect ans;
    ans.x = dapos.distance * cos(dapos.angle);
    ans.y = dapos.distance * sin(dapos.angle);
    cout<<myvar1<<endl;
    return ans;
}

void show_rect(rect xypos){
    cout<<"function show_rect"<<endl;
    cout<< "rect coordinate:" ;
    cout<<"x = "<<xypos.x<<", ";
    cout<<"y = "<<xypos.y<<". ";
    cout<<endl;
}
void show_polar(polar dapos){
    cout<<"function show_polar"<<endl;
    cout<< "rect coordinate:" ;
    cout<<"distance = "<<dapos.distance<<", ";
    cout<<"angle(in degree) = "<<dapos.angle*180/pi;
    cout<<endl;
    MAX = MAX +1;
    cout<<"MAX has been added 1, now MAX =  "<<MAX<<endl;
}