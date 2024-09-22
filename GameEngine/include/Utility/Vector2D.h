#pragma once

namespace Utility {
template <typename T>
class Vector2D {
public:
    Vector2D() : m_x(T()), m_y(T()) {}
    Vector2D(T x, T y) : m_x(x), m_y(y) {}
    ~Vector2D() = default;

    T getX() const { return m_x; }
    T getY() const { return m_y; }

    void setX(T x) { m_x = x; }
    void setY(T y) { m_y = y; }
    void set(T x, T y) { m_x = x; m_y = y; }

    Vector2D& operator=(const Vector2D& other) {
        if (this != &other) {
            m_x = other.m_x;
            m_y = other.m_y;
        }
        return *this;
    }

    Vector2D& operator+=(const Vector2D& other) {
        m_x += other.m_x;
        m_y += other.m_y;

        return *this;
    }

private:
    T m_x;
    T m_y;
};
}