#include <sstream>
#include "rect.hpp"

void Rectangle::set_values(int w, int h){
    width = w;
    height = h;
}

string Rectangle::to_string() const{
    std::ostringstream oss;
    oss << "[W : " << width << ", H: " << height << ", A: " << area() << " ]";
    return oss.str();
}

int Rectangle::area() const{ return width * height; }