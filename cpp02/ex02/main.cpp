#include <iostream>
#include "Fixed.hpp"

static void printCmp(const Fixed& x, const Fixed& y, const char* lx = "x", const char* ly = "y")
{
    std::cout << "=== compare " << lx << " vs " << ly << " ===\n";
    std::cout << lx << " = " << x << ", " << ly << " = " << y << "\n";
    std::cout << lx << " >  " << ly << " ? " << (x >  y) << "\n";
    std::cout << lx << " <  " << ly << " ? " << (x <  y) << "\n";
    std::cout << lx << " >= " << ly << " ? " << (x >= y) << "\n";
    std::cout << lx << " <= " << ly << " ? " << (x <= y) << "\n";
    std::cout << lx << " == " << ly << " ? " << (x == y) << "\n";
    std::cout << lx << " != " << ly << " ? " << (x != y) << "\n";
}

int main()
{
    // 1) 既出サンプル相当
    Fixed a;                                    // 0
    Fixed const b( Fixed(5.05f) * Fixed(2) );   // 10.10

    std::cout << "[basic]\n";
    std::cout << "a      : " << a << "\n";
    std::cout << "++a    : " << ++a << "\n";    // 前置
    std::cout << "a      : " << a << "\n";
    std::cout << "a++    : " << a++ << "\n";    // 後置
    std::cout << "a      : " << a << "\n";
    std::cout << "b      : " << b << "\n";
    std::cout << "max(a,b): " << Fixed::max(a, b) << "\n";

    std::cout << "--------------\n";
    std::cout << "b - a--: " << (b - a--) << "\n";  // 後置 --
    std::cout << "a      : " << a << "\n";
    std::cout << "b/(--a): " << (b / (--a)) << "\n"; // 前置 --
    std::cout << "a      : " << a << "\n";
    if (a == b) std::cout << "a == b : true\n";
    else if (a != b) std::cout << "a != b : true\n";

    // 2) 四則演算まとめテスト
    std::cout << "\n[arithmetic]\n";
    Fixed x(2.5f);
    Fixed y(-3);           // -3.0
    std::cout << "x = " << x << ", y = " << y << "\n";
    std::cout << "x + y = " << (x + y) << "\n";
    std::cout << "x - y = " << (x - y) << "\n";
    std::cout << "x * y = " << (x * y) << "\n";
    std::cout << "x / y = " << (x / y) << "\n";

    // 3) 比較演算子総当たり
    std::cout << "\n[comparisons]\n";
    printCmp(x, y, "x", "y");
    Fixed z(2.5f);
    printCmp(x, z, "x", "z"); // 等価ケース

    // 4) 前置/後置 ++/-- の挙動
    std::cout << "\n[inc/dec]\n";
    Fixed t(1);
    std::cout << "t      : " << t << "\n";
    std::cout << "++t    : " << ++t << "  (t now " << t << ")\n";
    std::cout << "t++    : " << t++ << "  (t now " << t << ")\n";
    std::cout << "--t    : " << --t << "  (t now " << t << ")\n";
    std::cout << "t--    : " << t-- << "  (t now " << t << ")\n";

    // 5) min/max（非const版とconst版の両方を叩く）
    std::cout << "\n[min/max]\n";
    Fixed m1(3.0f), m2(7.0f);
    const Fixed cm1(4.0f), cm2(1.0f);

    std::cout << "non-const  m1=" << m1 << ", m2=" << m2 << "\n";
    std::cout << "min(m1,m2) = " << Fixed::min(m1, m2) << "\n";
    std::cout << "max(m1,m2) = " << Fixed::max(m1, m2) << "\n";

    std::cout << "const      cm1=" << cm1 << ", cm2=" << cm2 << "\n";
    std::cout << "min(cm1,cm2) = " << Fixed::min(cm1, cm2) << "\n";
    std::cout << "max(cm1,cm2) = " << Fixed::max(cm1, cm2) << "\n";
    return 0;
}
