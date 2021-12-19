#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
	public:
		//constructors
		vec3(): e{0,0,0} {}
		vec3(float e0, float e1, float e2): e{e0, e1, e2} {}

		//getters
		float x() const { return this->e[0]; }
		float y() const { return this->e[1]; }
		float z() const { return this->e[2]; }

		//Operator overloading
		vec3 operator-() const { return vec3( -this->e[0], -this->e[1], -this->e[2]); }
		float operator[](int i) const { return this->e[i]; }
		float& operator[](int i) {return this->e[i]; }

		vec3& operator+=(const vec3 &v) {
			this->e[0] += v.e[0];
			this->e[1] += v.e[1];
			this->e[2] += v.e[2];
			return *this;
		}

		vec3& operator*=(const float t) {
			this->e[0] *= t;
			this->e[1] *= t;
			this->e[2] *= t;
			return *this;
		}

		vec3& operator/=(const float t) {
			return *this *= 1/t;
		}

		float length() const {
			return sqrt(length_squared());
		}

		float length_squared() const {
			return this->e[0] * this->e[0] 
				 + this->e[1] * this->e[1] 
				 + this->e[2] * this->e[2];
		}

	public:
		float e[3];
};

// utility functions

inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+ (const vec3 &u, const vec3 &v) {
	return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v .e[2]);
}

inline vec3 operator- (const vec3 &u, const vec3 &v) {
	return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v .e[2]);
}

inline vec3 operator* (const vec3 &u, const vec3 &v) {
	return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v .e[2]);
}

inline vec3 operator* (float t, const vec3 &v) {
	return vec3(t  * v.e[0], t  * v.e[1], t * v .e[2]);
}

inline vec3 operator* (const vec3 &v, float t) {
	return t * v;
}

inline vec3 operator/ (const vec3 &v, float t) {
	return (1/t) * v;
}

inline double dot(const vec3 &u, const vec3 &v) {
	return u.e[0] * v.e[0]
		 + u.e[1] * v.e[1]
		 + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v) { 
	return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1], 
				u.e[2] * v.e[0] - u.e[0] * v.e[2], 
				u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(vec3 v) {
	return v / v.length();
}

// Type aliases for vec3
using point3 = vec3; // 3D poinjt
using color = vec3;  // RGB color
#endif
