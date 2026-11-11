#ifndef SVOBJECT_H
#define SVOBJECT_H

#include <vector>
#include <functional>
#include <stdint.h>
#include <cmath>

#include "vector.hpp"

constexpr float PI = 3.14159265f;

namespace CFD {
    /// @brief this class defines the objects which are used to perform CFD on
    class ScalableVectorObject {
        public:
            /// @brief constructor
            ScalableVectorObject();

            /// @brief destructor
            ~ScalableVectorObject();

            /// @brief set the outer points defining the surface of the object
            void set_outer_points(std::vector<Vector2> outer_points);

            /// @brief get the outer points defining the surface of the object
            std::vector<Vector2> get_outer_points();

            /// @brief mirror the object on the x axis
            void mirror_x();

            /// @brief mirror the object on the y axis
            void mirror_y();

            /// @brief scale the object
            void scale(float f);

            /// @brief rotate the object
            void rotate(float angle);

            /// @brief add an offset to the object
            void add_offset(Vector2 offset);

            /// @brief get the geometric center of the object
            Vector2 get_object_center();

            /// @brief get the current maximal vertical distance between the most lower and upper points
            float get_max_height();

            /// @brief get the current maximal horizontal distance between the most left and right points
            float get_max_width();

            /// @brief assignment operator for object copies
            ScalableVectorObject& operator=(const ScalableVectorObject& obj);

        private:
            std::vector<Vector2> outer_points;
    };

    /// @brief generate a ScalableVectorObject using a function defining its surface
    /// @param func the function defining the objects surface (takes polar coordinates and returns 1.0 if the point is within the object, else returns 0.0f)
    /// @param resolution the number of points to be generated on the surface
    ScalableVectorObject generate_sv_object(std::function<float(float, float)> func, int resolution = 100);
    
    inline const ScalableVectorObject CIRCLE = generate_sv_object(
    [](float r, float a)
    { 
    if (r <= 50.0f)
        return 1.0f;
    else 
        return 0.0f; }, 360);

    inline const ScalableVectorObject SQUARE = generate_sv_object(
    [](float r, float a)
    {
        float x = cosf(a * PI / 180.0f);
        float y = sinf(a * PI / 180.0f);
        float rMax = 50.0f / std::max(fabsf(x), fabsf(y));

        if (r < rMax)
            return 1.0f;
        else
            return 0.0f;
    }, 360);

    /// @brief convert a polar vector to a cartesian vector
    /// @param polar_vector Vector2 with radius [0] and angle [1]
    /// @returns cartesian vector
    Vector2 polar_to_cartesian(Vector2 polar_vector);

    /// @brief convert a cartesian vector to a cartesian vector
    /// @param polar_vector Vector2 with x [0] and y [1]
    /// @returns polar vector
    Vector2 cartesian_to_polar(Vector2 cartesian_vector);

}

#endif