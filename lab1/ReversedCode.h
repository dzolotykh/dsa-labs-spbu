#ifndef LAB1_REVERSEDCODE_H
#define LAB1_REVERSEDCODE_H

#include <iostream>

template <typename T>
class ReversedCode {
   private:
    T container_;
    const int num_bits = sizeof(T) * 8;

   public:
    // NOLINTNEXTLINE(google-explicit-constructor)
    ReversedCode(const T& container) : container_(container) {
        if (container_ < 0) {
            container_ = ~abs(container_);
        }
    }

    ReversedCode(const ReversedCode<T>& other) : container_(other.container_) {}

    ReversedCode<T>& operator+=(const ReversedCode<T>& other) noexcept;
    ReversedCode<T>& operator-=(ReversedCode<T> other) noexcept;
    ReversedCode<T>& operator*=(ReversedCode<T> other) noexcept;

    friend std::ostream& operator<<(std::ostream& os,
                                    const ReversedCode<T>& a) {
        os << static_cast<int>(a);
        return os;
    }

    // NOLINTNEXTLINE(google-explicit-constructor)
    operator T() const {
        if (sign(*this)) {
            return -(~container_);
        }
        return container_;
    }

    inline static int sign(ReversedCode a) noexcept {
        return (a.container_ >> (a.num_bits - 1)) & 1;
    }
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

template <typename T>
ReversedCode<T>& ReversedCode<T>::operator+=(
    const ReversedCode<T>& other) noexcept {
    if (sign(container_) == sign(other.container_)) {
        if (sign(container_) == 0) {
            container_ += other.container_;
        } else {
            container_ = ~(~container_ + ~other.container_);
        }
        return *this;
    }

    if (container_ > ~other.container_) {
        container_ += other.container_ + 1;
    } else {
        container_ = ~(~other.container_ + ~container_ + 1);
    }

    if (__builtin_popcount(container_) == num_bits) {
        container_ = ~container_;
    }

    return *this;
}

template <typename T>
ReversedCode<T>& ReversedCode<T>::operator-=(ReversedCode<T> other) noexcept {
    other.container_ = ~other.container_;
    *this += other;
    return *this;
}

template <typename T>
ReversedCode<T>& ReversedCode<T>::operator*=(ReversedCode<T> other) noexcept {
    int sign = ((container_ >> (num_bits - 1)) & 1) ^
               ((other.container_ >> (num_bits - 1)) & 1);
    if ((container_ >> (num_bits - 1)) & 1) {
        container_ = ~container_;
    }
    if ((other.container_ >> (num_bits - 1)) & 1) {
        other.container_ = ~other.container_;
    }
    container_ *= other.container_;
    if (sign) {
        container_ = ~container_;
    }
    return *this;
}

template <typename T>
ReversedCode<T> operator+(ReversedCode<T> lhs,
                          const ReversedCode<T>& rhs) noexcept {
    lhs += rhs;
    return lhs;
}

template <typename T>
ReversedCode<T> operator-(ReversedCode<T> lhs,
                          const ReversedCode<T>& rhs) noexcept {
    lhs -= rhs;
    return lhs;
}

template <typename T>
ReversedCode<T> operator*(ReversedCode<T> lhs,
                          const ReversedCode<T>& rhs) noexcept {
    lhs *= rhs;
    return lhs;
}

#endif  //LAB1_REVERSEDCODE_H