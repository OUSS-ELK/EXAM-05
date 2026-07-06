#pragma once

#include <iostream>

class vect2
{
    private:
        int x,y;
    public:
        vect2() : x(0), y(0) {}
        vect2(int x, int y) : x(x), y(y) {}
        vect2(const vect2& copy) : x(copy.x), y(copy.y){}
        vect2& operator=(const vect2& copy) {
            if (this != &copy)
            {
                x = copy.x;
                y = copy.y;
            }
            return *this;
        }
        ~vect2(){}

        int& operator[](int i){
            if (i == 0)
                return x;
            else
                return y;
        }

        int operator[](int i) const{
            if (i == 0)
                return x;
            else
                return y;
        }

        friend std::ostream&    operator<<(std::ostream& os, const vect2& v){
            os << "{" << v[0] << ", " << v[1] << "}";
            return os;
        }
        
        vect2 operator++(int)
        {
            vect2   tmp = *this;
            x++;
            y++;
            return tmp;

        }
        vect2 operator--(int)
        {
            vect2   tmp = *this;
            x--;
            y--;
        
            return tmp;

        }
        vect2&  operator++()
        {
            x++;
            y++;
            return *this;
        }
        vect2&  operator--()
        {
            x--;
            y--;
            return *this;
        }
        vect2&  operator+=(const vect2& v){
            x += v.x;
            x += v.x;
            return *this;
        }
        vect2&  operator-=(const vect2& v){
            x -= v.x;
            x -= v.x;
            return *this;
        }
        vect2&  operator*=(int s){
            x -= s;
            x -= s;
            return *this;
        }

        vect2   operator+(const vect2& v) const{
            return (vect2(x + v.x, y + v.y));
        }
        vect2   operator-(const vect2& v) const{
            return (vect2(x - v.x, y - v.y));
        }

        vect2   operator*(int i) const{
            return (vect2(x * i, y * i));
        }

        friend vect2 operator*(int s, const vect2& v){
            
            return vect2(v.x * s, v.y * s);
        }

        vect2 operator-() const{
            return(vect2(-x, -y));
        }

};