#include <iostream>

using namespace std;

const float pi = 3.1415926;

struct polar{
    float distance;
    float angle;
};
struct rect{
    float x;
    float y;
};

polar rect2polar(const rect xypos);
rect polar2rect(const polar dapos);
void show_rect(rect xypos);
void show_polar(polar dapos);