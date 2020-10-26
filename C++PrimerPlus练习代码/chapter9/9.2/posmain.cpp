#include "namesp.h"

int MAX = 1024;
extern const float e;

int main(){
    cout<<"in main: MAX = "<<MAX<<endl;
    polar p1;
    rect p2;
    p1.distance = 1;
    p1.angle = 1.57;
    p2.x = 2;
    p2.y = 1;
    show_rect(p2);
    show_polar(p1);
    show_rect(polar2rect(p1));
    show_polar(rect2polar(p2));
    cout<<"after change in main: MAX = "<<MAX<<endl;
}