#pragma once

// ZMatrix Ŭ������ ���� ����(Forward Declaration)
// ZVector3.h�� ZMatrix�� ��ü ���Ǹ� �� �ʿ� ����, �����ͳ� �����θ� ����ϹǷ�
// �̷� Ŭ������ �ִٴ� ��Ǹ� �˷��ָ� �˴ϴ�. (��ȯ ���� ���� �� ������ �ӵ� ���)
//class ZMatrix;

class ZVector3
{
public:
    float x, y, z;

public:
    // ������ �� �Ҹ���
    ZVector3();
    ZVector3(float x, float y, float z);
    ZVector3(const ZVector3& rhs);
    ~ZVector3();

    // ��� �Լ�
    float Dot(const ZVector3& rhs) const;
    ZVector3 Scale(float k) const;
    float Length() const;
    ZVector3 Normalize() const;
    //ZVector3 Transform(const ZMatrix& matrix) const; // ��� ��ȯ �Լ�

    // ����(static) �Լ�
    static ZVector3 Cross(const ZVector3& u, const ZVector3& v);

    // ������ �����ε�
    ZVector3 operator+(const ZVector3& rhs) const;
    ZVector3 operator-(const ZVector3& rhs) const;
    void operator=(const ZVector3& rhs);
    ZVector3 operator*(const ZVector3& rhs) const; // ���к� ���� (Hadamard Product)
    ZVector3 operator*(float k) const; // ��Į�� ����

    void PrintInfo();
};


