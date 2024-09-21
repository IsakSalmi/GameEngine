#pragma once

namespace Utility {
template <typename T>
class Vector2D {
public:
    Vector2D();
    Vector2D(T x, T y);
    ~Vector2D();
    T getX();
    T getY();

    void setX(T x);
    void setY(T y);
    void set(T x, T y);

    Vector2D& operator=(const Vector2D& other);
    Vector2D& operator+=(const Vector2D& other);
private:
    T m_x;
    T m_y;
};
}
