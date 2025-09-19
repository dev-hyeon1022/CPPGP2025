#include "ZVector3.h"
//#include "ZMatrix.h"
#include <cmath> // sqrt, sin, cos �Լ��� ���
#include <iostream>
using namespace std;


// ������ �� �Ҹ���
ZVector3::ZVector3() : x(0.0f), y(0.0f), z(0.0f) { cout << "default Call!" << endl; }

ZVector3::ZVector3(float x, float y, float z) : x(x), y(y), z(z) { cout << "float Call!" << endl; }

ZVector3::ZVector3(const ZVector3& rhs) : x(rhs.x), y(rhs.y), z(rhs.z) { cout << "Copy Call!" << endl; }

ZVector3::~ZVector3() {}

// ��� �Լ�
float ZVector3::Dot(const ZVector3& rhs) const
{
    return (this->x * rhs.x) + (this->y * rhs.y) + (this->z * rhs.z);
}

ZVector3 ZVector3::Scale(float k) const
{
    return ZVector3(this->x * k, this->y * k, this->z * k);
}

float ZVector3::Length() const
{
    return sqrt(Dot(*this));
}

ZVector3 ZVector3::Normalize() const
{
    float len = Length();
    if (len == 0.0f) return ZVector3(0, 0, 0);
    return ZVector3(this->x / len, this->y / len, this->z / len);
}

// ���� �Լ�
ZVector3 ZVector3::Cross(const ZVector3& u, const ZVector3& v)
{
    float x = u.y * v.z - u.z * v.y;
    float y = u.z * v.x - u.x * v.z;
    float z = u.x * v.y - u.y * v.x;
    return ZVector3(x, y, z);
}

// ������ �����ε�
ZVector3 ZVector3::operator+(const ZVector3& rhs) const
{
    return ZVector3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
}

ZVector3 ZVector3::operator-(const ZVector3& rhs) const
{
    return ZVector3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
}

void ZVector3::operator=(const ZVector3& rhs)
{
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
}

// ���к� ����
ZVector3 ZVector3::operator*(const ZVector3& rhs) const
{
    return ZVector3(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z);
}

// ��Į�� ����
ZVector3 ZVector3::operator*(float k) const
{
    return Scale(k);
}

// ��� ��ȯ
//ZVector3 ZVector3::Transform(const ZMatrix& matrix) const
//{
//    // D3D ���� (���� * ���) �̹Ƿ� ������ǥ w=1�� ���
//    float newX = x * matrix.m[0][0] + y * matrix.m[1][0] + z * matrix.m[2][0] + 1.0f * matrix.m[3][0];
//    float newY = x * matrix.m[0][1] + y * matrix.m[1][1] + z * matrix.m[2][1] + 1.0f * matrix.m[3][1];
//    float newZ = x * matrix.m[0][2] + y * matrix.m[1][2] + z * matrix.m[2][2] + 1.0f * matrix.m[3][2];
//    // w'�� ����ȭ�� ���� ��������, ���⼭�� ������ 1�� �����ϰ� ����
//    return ZVector3(newX, newY, newZ);
//}


void ZVector3::PrintInfo()
{
    cout << "X: " << x << ", Y: " << y << ", Z: " << z << endl;
} 
