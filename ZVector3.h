#pragma once

// ZMatrix Ŭ������ ���� ����(Forward Declaration)
// ZVector3.h�� ZMatrix�� ��ü ���Ǹ� �� �ʿ� ����, �����ͳ� �����θ� ����ϹǷ�
// �̷� Ŭ������ �ִٴ� ��Ǹ� �˷��ָ� �˴ϴ�. (��ȯ ���� ���� �� ������ �ӵ� ���)
class ZMatrix;

class ZVector3
{
public:
    double x, y, z;

public:
    // ������ �� �Ҹ���
    ZVector3();
    ZVector3(double x, double y, double z);
    ZVector3(const ZVector3& rhs);
    ~ZVector3();

    // ��� �Լ�
    double Dot(const ZVector3& rhs) const;
    ZVector3 Cross(const ZVector3& rhs) const;
    ZVector3 Scale(double k) const;
    double Length() const;
    double radBetween(const ZVector3& a, const ZVector3& b) const;
    double degBetween(const ZVector3& a, const ZVector3& b) const;
    ZVector3 Normalize() const;
    ZVector3 Transform(const ZMatrix& matrix) const; // ��� ��ȯ �Լ�

    // ����(static) �Լ�
    static double Dot(const ZVector3& u, const ZVector3& v); // ���� (���� ��� �Լ�)
    static ZVector3 Cross(const ZVector3& u, const ZVector3& v);

    // ������ �����ε�
    ZVector3 operator+(const ZVector3& rhs) const;
    ZVector3 operator-(const ZVector3& rhs) const;
    void operator=(const ZVector3& rhs);
    ZVector3 operator*(const ZVector3& rhs) const; // ���к� ���� (Hadamard Product)
    ZVector3 operator*(double k) const; // ��Į�� ����

    void PrintInfo();
};


