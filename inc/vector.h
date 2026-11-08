#ifndef VECTOR_H
#define VECTOR_H

#include <stdint.h>
#include <cmath>

namespace CFD {

    /// @brief simple class for two dimensional vectors (floating-point data type)
    class Vector2 {
        public:
            /// @brief constructor
            Vector2();
            Vector2(float x, float y);
            ~Vector2();

            /// @brief addition
            friend Vector2 operator+(const Vector2& a, const Vector2& b);

            /// @brief subtraction
            friend Vector2 operator-(const Vector2& a, const Vector2& b);

            /// @brief dot product
            friend float operator*(const Vector2& a, const Vector2& b);

            /// @brief scalar multiplication
            friend Vector2 operator*(const Vector2& a, float f);
            /// @brief scalar multiplication
            friend Vector2 operator*(float f, const Vector2& a);

            /// @brief scalar division
            friend Vector2 operator/(const Vector2& a, float f);
            
            /// @brief assignment operator
            Vector2& operator=(const Vector2& a);
            /// @brief assignment operator
            Vector2& operator*=(float f);
            /// @brief assignment operator
            Vector2& operator+=(const Vector2& a);
            /// @brief assignment operator
            Vector2& operator-=(const Vector2& a);
            
            /// @brief element manipulation
            float& operator[](size_t index);
            /// @brief element manipulation
            const float& operator[](size_t index) const;

        private:
            float vector[2] {0.0f};
    };

    /// @brief simple class for 2 by 2 matrices
    class Matrix2x2 {
        public:
            /// @brief constructor
            Matrix2x2();
            Matrix2x2(float a11, float a12, float a21, float a22);
            ~Matrix2x2();

            /// @brief addition
            friend Matrix2x2 operator+(const Matrix2x2& a, const Matrix2x2& b);

            /// @brief subtraction
            friend Matrix2x2 operator-(const Matrix2x2& a, const Matrix2x2& b);

            /// @brief scalar multiplication
            friend Matrix2x2 operator*(const Matrix2x2& a, float f);
            /// @brief scalar multiplication
            friend Matrix2x2 operator*(float f, const Matrix2x2& a);

            /// @brief scalar division
            friend Matrix2x2 operator/(const Matrix2x2& a, float f);
            
            /// @brief assignment operator
            Matrix2x2& operator=(const Matrix2x2& a);
            /// @brief assignment operator
            Matrix2x2& operator*=(float f);
            /// @brief assignment operator
            Matrix2x2& operator+=(const Matrix2x2& a);
            /// @brief assignment operator
            Matrix2x2& operator-=(const Matrix2x2& a);
            
            /// @brief matrix multiplication
            friend Matrix2x2 operator*(const Matrix2x2& a, const Matrix2x2& b);
            /// @brief matrix multiplication
            Matrix2x2 matmul(const Matrix2x2& a);

            /// @brief vector multiplication
            friend Vector2 operator*(const Matrix2x2& a, const Vector2& b);
            Vector2 vecmul(const Vector2& b);

            /// @brief element manipulation
            float& operator()(size_t i, size_t j);
            /// @brief element manipulation
            const float& operator()(size_t i, size_t j) const;

        private:
            float matrix[4] = {0.0f};
    };

    /// @brief get the two-dimensional rotation matrix for a given rotation
    /// @param angle the rotation angle
    /// @return the two-dimensional rotation matrix
    Matrix2x2 get_rotation_matrix(float angle);

}

#endif 