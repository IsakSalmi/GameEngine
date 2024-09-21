#include "Utility/Vector2D.h"
namespace Utility {
template <typename T>
Vector2D<T>::Vector2D()= default;

template <typename T>
Vector2D<T>::Vector2D(T x, T y) {
    m_x = x;
    m_y = y;
}

template <typename T>
Vector2D<T>::~Vector2D()=default;

template <typename T>
T Vector2D<T>::getX() {
    return m_x;
}

template <typename T>
T Vector2D<T>::getY() {
    return m_y;
}

template <typename T>
void Vector2D<T>::setX(T x) {
    m_x = x;
}

template <typename T>
void Vector2D<T>::setY(T y) {
    m_y = y;
}
template <typename T>
void Vector2D<T>::set(T x, T y) {
    m_x = x;
    m_y = y;
}

template <typename T>
Vector2D<T>& Vector2D<T>::operator=(const Vector2D& other) {
    m_x = other.m_x;
    m_y = other.m_y;
    return *this;
}

template <typename T>
Vector2D<T>& Vector2D<T>::operator+=(const Vector2D& other) {
    m_x += other.m_x;
    m_y += other.m_y;
    return *this;
}
}