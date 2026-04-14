#ifndef REC_HPP
#define REC_HPP

#include <string>

using string = std::string;

class Rectangle{
    int width, height;

    public:
        // Modifiers
        void set_values(int,int);
        
        // Access
        int area() const;
        string to_string() const;
};

#endif