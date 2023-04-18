#pragma once

#ifndef _Vector2_hpp_
#define _Vector2_hpp_

#include <iostream>

class Vector2
{
public:
	//constructors
	Vector2(int ix, int iy);
	Vector2(int ia);
	Vector2();

	//variables
	int x, y;

	//operators
	Vector2 operator+(const Vector2& right) const;
	Vector2 operator-(const Vector2& right) const;
	Vector2 operator*(const Vector2& right) const;
	Vector2 operator/(const Vector2& right) const;
	Vector2& operator+=(const Vector2& right);
	Vector2& operator-=(const Vector2& right);
	Vector2& operator*=(const Vector2& right);
	Vector2& operator/=(const Vector2& right);

	//functions
	/**
	 * @brief Change the vector length to exactly one
	 */
	void normalize();
	/**
	 * @brief Rotate the vector clockwize in the z direction
	 *
	 * @param rotation Rotation angle in radians.
	 */
	void rotate(int rotation);
	/**
	 * @brief Rotate the vector clockwize in the z direction
	 *
	 * @param rotation Rotation angle in radians.
	 */
	Vector2 rotated(int rotation) const;
	/**
	 * @brief Return a vector that is the normelized vector of this vector
	 * @details [long description]
	 * @return this vector normilized
	 */
	Vector2 normalized() const;
	/**
	 * @brief Calcultes the length of the vector and returns it.
	 * @details [long description]
	 * @return The lenght of this vector
	 */
	int absolute() const;
	/**
	 * @brief Calculate the dot product of two vetors.
	 * @details The dot product is the product of the vector in the
	 * same length.
	 *
	 * @param left Left hand side of the dot operator.
	 * @param right Right hand side of the dot operator.
	 *
	 * @return Vector result of the dot operation.
	 */
	static int dotProduct(const Vector2& left, const Vector2& right);
};


std::ostream& operator<<(std::ostream& os, const Vector2& vector2);
#endif //_Vector2_hpp_