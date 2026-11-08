#include "vector.h"

using namespace CFD;

// ---------- Vector2 ----------

Vector2::Vector2() {}

Vector2::Vector2(float x, float y) : vector{x, y} {}

Vector2::~Vector2() {
    delete[] this->vector;
}

Vector2 operator+(const Vector2& a, const Vector2& b) {
    return {
        a[0] + b[0],
        a[1] + b[1]
    };
}

Vector2 operator-(const Vector2& a, const Vector2& b) {
    return {
        a[0] - b[0],
        a[1] - b[1]
    };
}

float operator*(const Vector2& a, const Vector2& b) {
    return a[0] * b[0] + a[1] * b[1];
}

Vector2 operator*(const Vector2& a, float f) {
    return {
        a[0] * f,
        a[1] * f
    };
}

Vector2 operator*(float f, const Vector2& a) {
    return {
        a[0] * f,
        a[1] * f
    };
}

Vector2 operator/(const Vector2& a, float f) {
    return {
        a[0] / f,
        a[1] / f
    };
}

Vector2& Vector2::operator=(const Vector2& a) {
    if (this != &a) {
        this->vector[0] = a[0];
        this->vector[1] = a[1];
    }
    return *this;
}

Vector2& Vector2::operator*=(float f) {
    this->vector[0] *= f;
    this->vector[1] *= f;
    return *this;
}

Vector2& Vector2::operator+=(const Vector2& a) {
    this->vector[0] += a[0];
    this->vector[1] += a[1];
    return *this;
}  

Vector2& Vector2::operator-=(const Vector2& a) {
    this->vector[0] -= a[0];
    this->vector[1] -= a[1];
    return *this;
}

float& Vector2::operator[](size_t index) {
    return this->vector[index];
}

const float& Vector2::operator[](size_t index) const {
    return this->vector[index];
}

// ---------- Matrix2x2 ----------

Matrix2x2::Matrix2x2() {};

Matrix2x2::Matrix2x2(float a11, float a12, float a21, float a22) : matrix{a11, a12, a21, a22} {}

Matrix2x2::~Matrix2x2() {
    delete[] this->matrix;
};

Matrix2x2 operator+(const Matrix2x2& a, const Matrix2x2& b) {
    return {
        a(0, 0) + b(0, 0),
        a(0, 1) + b(0, 1),
        a(1, 0) + b(1, 0),
        a(1, 1) + b(1, 1)
    };
}

Matrix2x2 operator-(const Matrix2x2& a, const Matrix2x2& b) {
    return {
        a(0, 0) - b(0, 0),
        a(0, 1) - b(0, 1),
        a(1, 0) - b(1, 0),
        a(1, 1) - b(1, 1)
    };
}

Matrix2x2 operator*(const Matrix2x2& a, float f) {
    return {
        a(0, 0) * f,
        a(0, 1) * f,
        a(1, 0) * f,
        a(1, 1) * f
    };
}

Matrix2x2 operator*(float f, const Matrix2x2& a) {
    return {
        a(0, 0) * f,
        a(0, 1) * f,
        a(1, 0) * f,
        a(1, 1) * f
    };
}

Matrix2x2 operator/(const Matrix2x2& a, float f) {
    return {
        a(0, 0) / f,
        a(0, 1) / f,
        a(1, 0) / f,
        a(1, 1) / f
    };
}

Matrix2x2& Matrix2x2::operator=(const Matrix2x2& a) {
    if (this != &a) {
        (*this)(0, 0) = a(0, 0);
        (*this)(0, 1) = a(0, 1);
        (*this)(1, 0) = a(1, 0);
        (*this)(1, 1) = a(1, 1);
    }
    return *this;
}

Matrix2x2& Matrix2x2::operator*=(float f) {
    (*this)(0, 0) *= f;
    (*this)(0, 1) *= f;
    (*this)(1, 0) *= f;
    (*this)(1, 1) *= f;
    return *this;
}

Matrix2x2& Matrix2x2::operator+=(const Matrix2x2& a) {
    (*this)(0, 0) += a(0, 0);
    (*this)(0, 1) += a(0, 1);
    (*this)(1, 0) += a(1, 0);
    (*this)(1, 1) += a(1, 1);
    return *this;
}

Matrix2x2& Matrix2x2::operator-=(const Matrix2x2& a) {
    (*this)(0, 0) -= a(0, 0);
    (*this)(0, 1) -= a(0, 1);
    (*this)(1, 0) -= a(1, 0);
    (*this)(1, 1) -= a(1, 1);
    return *this;
}

Matrix2x2 operator*(const Matrix2x2& a, const Matrix2x2& b) {
    return {
        a(0, 0) * b(0, 0) + a(0, 1) * b(1, 0),
        a(0, 0) * b(0, 1) + a(0, 1) * b(1, 1), 
        a(1, 0) * b(0, 0) + a(1, 1) * b(1, 0), 
        a(1, 0) * b(0, 1) + a(1, 1) * b(1, 1), 
    };
}

Matrix2x2 Matrix2x2::matmul(const Matrix2x2& a) {
    return {
        (*this)(0, 0) * a(0, 0) + (*this)(0, 1) * a(1, 0),
        (*this)(0, 0) * a(0, 1) + (*this)(0, 1) * a(1, 1), 
        (*this)(1, 0) * a(0, 0) + (*this)(1, 1) * a(1, 0), 
        (*this)(1, 0) * a(0, 1) + (*this)(1, 1) * a(1, 1), 
    };
}

Vector2 operator*(const Matrix2x2& a, const Vector2& b) {
    return {
        a(0, 0) * b[0] + a(0, 1) * b[1],
        a(1, 0) * b[0] + a(1, 1) * b[1]
    };
}

Vector2 Matrix2x2::vecmul(const Vector2& b) {
    return {
        (*this)(0, 0) * b[0] + (*this)(0, 1) * b[1],
        (*this)(1, 0) * b[0] + (*this)(1, 1) * b[1]
    };
}

float& Matrix2x2::operator()(size_t i, size_t j) {
    return this->matrix[j * 2 + i];
}

const float& Matrix2x2::operator()(size_t i, size_t j) const {
    return this->matrix[j * 2 + i];
}

Matrix2x2 CFD::get_rotation_matrix(float angle) {
    return {
        std::cosf(angle), -std::sinf(angle), std::cosf(angle), std::sinf(angle) 
    };
}