#include "vector.h"

// ---------- Vector2 ----------

Vector2::Vector2() {}

Vector2::Vector2(float x, float y) : vector{x, y} {}

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

float& Vector2::operator[](size_t index) {
    return this->vector[index];
}

const float& Vector2::operator[](size_t index) const {
    return this->vector[index];
}

// ---------- Matrix2x2 ----------

Matrix2x2::Matrix2x2() {};

Matrix2x2::Matrix2x2(float a11, float a12, float a21, float a22) : matrix{a11, a12, a21, a22} {}

Matrix2x2 operator+(const Matrix2x2& a, const Matrix2x2& b) {
    return {
        a.matrix[0] + b.matrix[0],
        a.matrix[1] + b.matrix[1],
        a.matrix[2] + b.matrix[2],
        a.matrix[3] + b.matrix[3]
    };
}

Matrix2x2 operator-(const Matrix2x2& a, const Matrix2x2& b) {
    return {
        a.matrix[0] - b.matrix[0],
        a.matrix[1] - b.matrix[1],
        a.matrix[2] - b.matrix[2],
        a.matrix[3] - b.matrix[3]
    };
}

Matrix2x2 operator*(const Matrix2x2& a, float f) {
    return {
        a.matrix[0] * f,
        a.matrix[1] * f,
        a.matrix[2] * f,
        a.matrix[3] * f
    };
}

Matrix2x2 operator*(float f, const Matrix2x2& a) {
    return {
        a.matrix[0] * f,
        a.matrix[1] * f,
        a.matrix[2] * f,
        a.matrix[3] * f
    };
}

Matrix2x2 operator/(const Matrix2x2& a, float f) {
    return {
        a.matrix[0] / f,
        a.matrix[1] / f,
        a.matrix[2] / f,
        a.matrix[3] / f
    };
}

Matrix2x2& Matrix2x2::operator=(const Matrix2x2& a) {
    if (this != *a) {
        this->matrix[0] = a[0];
        this->matrix[1] = a[1];
        this->matrix[2] = a[2];
        this->matrix[3] = a[3];
    }
    return *this;
}

Matrix2x2& Matrix2x2::operator*=(float f) {
    this->matrix[0] *= f;
    this->matrix[1] *= f;
    this->matrix[2] *= f;
    this->matrix[3] *= f;
    return *this;
}

Matrix2x2 operator*(const Matrix2x2& a, const Matrix2x2& b) {
    return {
        a.matrix[0] * b.matrix[0] + a.matrix[1] + b.matrix[2],
        a.matrix[0] * b.matrix[1] + a.matrix[1] + b.matrix[3],
        a.matrix[2] * b.matrix[0] + a.matrix[3] + b.matrix[2],
        a.matrix[2] * b.matrix[1] + a.matrix[3] + b.matrix[3]
    };
}

Matrix2x2 matmul(const Matrix2x2& a) {
    return {
        a.matrix[0] * b.matrix[0] + a.matrix[1] + b.matrix[2],
        a.matrix[0] * b.matrix[1] + a.matrix[1] + b.matrix[3],
        a.matrix[2] * b.matrix[0] + a.matrix[3] + b.matrix[2],
        a.matrix[2] * b.matrix[1] + a.matrix[3] + b.matrix[3]
    };
}

Vector2 operator*(const Matrix2x2& a, const Vector2& b) {
    return {
        a.matrix[0] * b.vector[0] + a.matrix[1] * b.vector[1],
        a.matrix[2] * b.vector[0] + a.matrix[3] * b.vector[1]
    };
}

Vector2 Matrix2x2::vecmul(const Vector2& b) {
    return {
        this->matrix[0] * b.vector[0] + this->matrix[1] * b.vector[1],
        this->matrix[2] * b.vector[0] + this->matrix[3] * b.vector[1]
    };
}

float& Matrix2x2::operator()(size_t i, size_t j) {
    return this->matrix[j * 2 + i];
}

const float& Matrix2x2::operator()(size_t i, size_t j) const {
    return this->matrix[j * 2 + i];
}

Matrix2x2 get_rotation_matrix(float angle) {
    return {
        std::cosf(angle), -std::sinf(angle), std::cosf(angle), std::sinf(angle) 
    };
}