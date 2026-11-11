#include "svobject.h"

CFD::ScalableVectorObject::ScalableVectorObject() {}

CFD::ScalableVectorObject::~ScalableVectorObject() {}

void CFD::ScalableVectorObject::set_outer_points(std::vector<CFD::Vector2> outer_points) {
    this->outer_points = outer_points;
}

std::vector<CFD::Vector2> CFD::ScalableVectorObject::get_outer_points() {
    return this->outer_points;
}

void CFD::ScalableVectorObject::mirror_x() {
    for (size_t i = 0; i < this->outer_points.size(); i++) {
        this->outer_points.at(i) = CFD::MirrorXMatrix * this->outer_points.at(i);
    }
}

void CFD::ScalableVectorObject::mirror_y() {
    for (size_t i = 0; i < this->outer_points.size(); i++) {
        this->outer_points.at(i) = CFD::MirrorYMatrix * this->outer_points.at(i);
    }
}

void CFD::ScalableVectorObject::scale(float f) {
    for (size_t i = 0; i < this->outer_points.size(); i++) {
        this->outer_points.at(i) *= f;
    }
}

void CFD::ScalableVectorObject::rotate(float angle) {
    CFD::Matrix2x2 m = CFD::get_rotation_matrix(angle);
    for (size_t i = 0; i < this->outer_points.size(); i++) {
        this->outer_points.at(i) = m * this->outer_points.at(i);
    }
}

void CFD::ScalableVectorObject::add_offset(CFD::Vector2 offset) {
    for (size_t i = 0; i < this->outer_points.size(); i++) {
        this->outer_points.at(i) += offset;
    }
}

CFD::Vector2 CFD::ScalableVectorObject::get_object_center() {
    CFD::Vector2 center;

    for (size_t i = 0; i < this->outer_points.size(); i++) {
        center += this->outer_points.at(i);
    }

    float num = 1.0f * this->outer_points.size();

    return center / num;
};

float CFD::ScalableVectorObject::get_max_height() {
    if (this->outer_points.empty()) {
        return 0.0f;
    }

    float min_y = this->outer_points.at(0)[1];
    float max_y = this->outer_points.at(0)[1];

    for (size_t i = 0; i < this->outer_points.size(); i++) {
        CFD::Vector2 v = this->outer_points.at(i);
        
        if (v[1] > max_y) {
            max_y = v[1];
        } else if (v[1] < min_y) {
            min_y = v[1];
        }
    }

    return max_y - min_y;
}

float CFD::ScalableVectorObject::get_max_width() {
    if (this->outer_points.empty()) {
        return 0.0f;
    }
    
    float min_x = this->outer_points.at(0)[0];
    float max_x = this->outer_points.at(0)[0];

    for (size_t i = 0; i < this->outer_points.size(); i++) {
        CFD::Vector2 v = this->outer_points.at(i);
        
        if (v[1] > max_x) {
            max_x = v[1];
        } else if (v[1] < min_x) {
            min_x = v[1];
        }
    }

    return max_x - min_x;
}

ScalableVectorObject& operator=(const ScalableVectorObject& obj) {
    if (this != &obj) {
        this->outer_points = a.get_outer_points();
    } 
    return *this;
}

ScalableVectorObject generate_sv_object(std::function<float(float, float)> func, int resolution = 100) {
    std::vector<CFD::Vector2> outer_points;
    float angle = 0.0f, radius = 0.0f, step = 0.1f, maxR = 100.0f;
    for (int i = 0; i < resolution; i++) {
        // for each angle increase the radius until the object outline is 'hit'
        
        // current angle
        angle = i * 360.0f/resolution;

        // current radius
        radius = 0.0f;

        // increase radius
        while (func(radius + step, angle) == 0.0f) {
            radius += step;
        }

        // add the polar coordinates of the (radius, angle) pair
        outer_points.push_back(polar_to_cartesian({radius, angle}));
    }   
    return CFD::ScalableVectorObject(outer_points);
}

CFD::Vector2 polar_to_cartesian(CFD::Vector2 polar_vector) {
    CFD::Vector2 cartesian;

    float radius = polar_vector[0], angle = polar_vector[1];

    cartesian[0] = radius * std::cosf(angle);
    cartesian[1] = radius * std::sinf(angle);

    return cartesian;
}

Vector2 cartesian_to_polar(Vector2 cartesian_vector) {
    CFD::Vector2 polar;

    float x = cartesian_vector[0], y = cartesian_vector[1];

    polar[0] = std::sqrtf(std::powf(x, 2) + std::powf(y, 2));
    polar[1] = std::atan(y / x);

    return cartesian;
}