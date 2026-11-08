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