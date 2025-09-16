#pragma once

// ZMatrix 클래스의 전방 선언(Forward Declaration)
// ZVector3.h는 ZMatrix의 전체 정의를 알 필요 없이, 포인터나 참조로만 사용하므로
// 이런 클래스가 있다는 사실만 알려주면 됩니다. (순환 참조 방지 및 컴파일 속도 향상)
//class ZMatrix;

class ZVector3
{
public:
    float x, y, z;

public:
    // 생성자 및 소멸자
    ZVector3();
    ZVector3(float x, float y, float z);
    ZVector3(const ZVector3& rhs);
    ~ZVector3();

    // 멤버 함수
    float Dot(const ZVector3& rhs) const;
    ZVector3 Scale(float k) const;
    float Length() const;
    ZVector3 Normalize() const;
    //ZVector3 Transform(const ZMatrix& matrix) const; // 행렬 변환 함수

    // 정적(static) 함수
    static ZVector3 Cross(const ZVector3& u, const ZVector3& v);

    // 연산자 오버로딩
    ZVector3 operator+(const ZVector3& rhs) const;
    ZVector3 operator-(const ZVector3& rhs) const;
    void operator=(const ZVector3& rhs);
    ZVector3 operator*(const ZVector3& rhs) const; // 성분별 곱셈 (Hadamard Product)
    ZVector3 operator*(float k) const; // 스칼라 곱셈

    void PrintInfo();
};


