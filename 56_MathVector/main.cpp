#include <iostream>
#include <vector>

template <typename T>
class MathVector {
private:
    std::vector<T> data;

public:
    // Храним в `data` нулевой вектор длины `n`
    MathVector(size_t n) {
        data.resize(n);
    }

    template <typename Iter>
    MathVector(Iter first, Iter last) {
        data = std::vector<T>(first, last);
    }

    size_t Dimension() const {
        return data.size();
    }

    T& operator [] (size_t i) {
        return data[i];
    }

    const T& operator [] (size_t i) const {
        return data.at(i);
    }

};

// Output format: (1, 2, 3, 4, 5)
template <typename T>
std::ostream& operator << (std::ostream& out, const MathVector<T>& v) {
    out << '(';
    for (size_t i = 0; i != v.Dimension(); ++i) {
        if (i > 0) {
            out << ", ";
        }
        out << v[i];
    }
    out << ')';
    return out;
}

template <typename T>
MathVector<T>& operator *= (MathVector<T>& v, const T& scalar) {
    for (size_t i = 0; i != v.Dimension(); ++i) {
        v[i] *= scalar;
    }
    return v;
}

template <typename T>
MathVector<T> operator * (const MathVector<T>& v, const T& scalar) {
    auto tmp(v);
    tmp *= scalar;
    return tmp;
}

template <typename T>
MathVector<T> operator * (const T& scalar, const MathVector<T>& v) {
    return v * scalar;
}

template <typename T>
MathVector<T>& operator += (MathVector<T>& v1, const MathVector<T>& v2) {
    for (size_t i = 0; i != v1.Dimension(); ++i) {
        v1[i] += v2[i];
    }
    return v1;
}

template <typename T>
MathVector<T> operator + (const MathVector<T>& v1, const MathVector<T>& v2) {
    auto tmp(v1);
    tmp += v2;
    return tmp;
}



int main()
{
    std::vector<int> vv{1,2,3,4,5};
    MathVector<int> v(vv.begin(), vv.end());

    std::vector<int> uu{5,6,7,8,9};
    MathVector<int> u(uu.begin(), uu.end());

    std::cout << v << std::endl;

    auto v2 = 1*v;
    auto u2 = -1*u;

    std::cout << (3 * u + v * (-2)) << "\n";

    MathVector<int> w(uu.begin(), uu.end());
    ((u += 2 * w) *= 5) += v;
    return 0;
}
