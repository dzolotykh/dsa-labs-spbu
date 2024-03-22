#ifndef LAB1_REVERSEDCODE_H
#define LAB1_REVERSEDCODE_H

#include <iostream>

template <typename T>
class ReversedCode {
private:
    T container_;

public:
    // NOLINTNEXTLINE(google-explicit-constructor)
    ReversedCode(const T& container);

    ReversedCode(const ReversedCode<T>& other);

    ReversedCode<T>& operator+=(const ReversedCode<T>& other);
    ReversedCode<T>& operator-=(ReversedCode<T> other);
    ReversedCode<T>& operator*=(ReversedCode<T> other);

    friend std::ostream& operator<<(std::ostream& os, const ReversedCode<T>& a);

    operator T();
};

template <typename T>
ReversedCode<T> operator+(ReversedCode<T> lhs,
                          const ReversedCode<T>& rhs) noexcept;

template <typename T>
ReversedCode<T> operator-(ReversedCode<T> lhs,
                          const ReversedCode<T>& rhs) noexcept;

template <typename T>
ReversedCode<T> operator*(ReversedCode<T> lhs,
                          const ReversedCode<T>& rhs) noexcept;
#endif  //LAB1_REVERSEDCODE_H
