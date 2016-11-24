#pragma once 

#include <math.h> 

struct vector2
{
	float x, y;

	//! trivial ctor
	vector2()
	{
	
	}

	//! setting ctor
	vector2(const float x0, const float y0) : x(x0), y(y0)
	{

	}

	//! array indexing
	float &operator [](unsigned int i)
	{
		return *(&x + i);
	}

	//! array indexing
	const float &operator [](unsigned int i) const
	{
		return *(&x + i);
	}

	//! function call operator
	void operator ()(const float x0, const float y0)
	{
		x = x0; y = y0;
	}

	//! test for equality
	bool operator == (const vector2 &v)
	{
		return (x == v.x && y == v.y);
	}

	//! test for inequality
	bool operator!=(const vector2 &v)
	{
		return (x != v.x || y != v.y);
	}

	//! set to value
	const vector2 &operator =(const vector2 &v)
	{
		x = v.x; y = v.y;
		return *this;
	}

	//! negation
	const vector2 operator -(void) const
	{
		return vector2(-x, -y);
	}

	//! addition
	const vector2 operator +(const vector2 &v) const
	{
		return vector2(x + v.x, y + v.y);
	}

	//! subtraction
	const vector2 operator -(const vector2 &v) const
	{
		return vector2(x - v.x, y - v.y);
	}

	//! uniform scaling
	const vector2 operator *(const float num) const
	{
		vector2 temp(*this);
		return temp *= num;
	}

	//! uniform scaling
	const vector2 operator /(const float num) const
	{
		vector2 temp(*this);
		return temp /= num;
	}

	//! addition
	const vector2 &operator +=(const vector2 &v)
	{
		x += v.x;	y += v.y;
		return *this;
	}

	//! subtraction
	const vector2 &operator -=(const vector2 &v)
	{
		x -= v.x;	y -= v.y;
		return *this;
	}

	//! uniform scaling
	const vector2 &operator *=(const float num)
	{
		x *= num;	y *= num;
		return *this;
	}

	//! uniform scaling
	const vector2 &operator /=(const float num)
	{
		x /= num;	y /= num;
		return *this;
	}

	//! dot product
	float operator *(const vector2 &v) const
	{
		return x*v.x + y*v.y;
	}
};

// macro to make creating the ctors for derived vectors easier
#define VECTOR2_CTORS( name,  type )    

/* trivial ctor */				
float name()
{

}						
/* down casting ctor */			
float name(const float &v) //: float(v.x, v.y)
{

}	

/* make x,y combination into a vector */					
float name(float x0, float y0)// : vector2<float>(x0, y0) 
{

}

struct vector2i //: public vector2<float>
{
	VECTOR2_CTORS(vector2i, float)
};

struct vector2ui // : public vector2<float>
{
	VECTOR2_CTORS(vector2ui, float)
};

struct vector2f  : public vector2
{
VECTOR2_CTORS(vector2f, float)

	//! gets the length of this vector squared
	float length_squared() const
	{
		return (float)(*this * *this);
	}

	//! gets the length of this vector
	float length() const
	{
		return (float)sqrt(*this * *this);
	}

	//! normalizes this vector
	void normalize()
	{
		*this /= length();
	}

	//! returns the normalized vector
	vector2f normalized() const
	{
		float l = length();
		//return vector2() / l;
	}

	//! reflects this vector about n
	void reflect(const vector2f &n)
	{
		vector2f orig(*this);
		project(n);
		*this == *this * 2 - orig;
	}

	//! projects this vector onto v
	void project(const vector2f &v)
	{
		*this == v * (*this * v) / (v*v);
	}

	//! returns this vector projected onto v
	vector2f projected(const vector2f &v)
	{
		//return v * (*this * v) / (v*v);
	}

	//! computes the angle between 2 arbitrary vectors
	static inline float angle(const vector2f &v1, const vector2f &v2)
	{
		return acosf((v1*v2) / (v1.length()*v2.length()));
	}

	//! computes the angle between 2 normalized arbitrary vectors
	static inline float angle_normalized(const vector2f &v1, const vector2f &v2)
	{
		return acosf(v1*v2);
	}
};