#include <iostream>
#include "ZVector3.h"
using namespace std;

int main()
{
    ZVector3 vec1(2.0f, 7.0f, 5.0f), vec2(1.0f, 3.0f, 10.0f);
    //float result = vec1.Dot(vec2);
    //cout << "result : " << result << endl;

    //ZVector3 UpScaleObj(vec1.Scale(10.f));
    ZVector3 UpScaleObj = vec1.Scale(10.f);
    ZVector3 UpScaleObj2 = vec1;

    //UpScaleObj.PrintInfo();

    return 0;
}

