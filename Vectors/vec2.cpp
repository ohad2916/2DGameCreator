#include "vec2.h"

Vector2::Vector2(int ix, int iy) : x(ix), y(iy) {}

Vector2::Vector2(int ia) : x(ia), y(ia) {}

Vector2::Vector2() : x(0), y(0) {}


Vector2 Vector2::operator+(const Vector2& right) const
{
	Vector2 temp(*this);
	temp += right;
	return temp;
}

Vector2 Vector2::operator-(const Vector2& right) const
{
	Vector2 temp(*this);
	temp -= right;
	return temp;
}

Vector2 Vector2::operator*(const Vector2& right) const
{
	Vector2 temp(*this);
	temp *= right;
	return temp;
}

Vector2 Vector2::operator/(const Vector2& right) const
{
	Vector2 temp(*this);
	temp /= right;
	return temp;
}

Vector2& Vector2::operator+=(const Vector2& right)
{
	x += right.x;
	y += right.y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& right)
{
	x -= right.x;
	y -= right.y;
	return *this;
}

Vector2& Vector2::operator*=(const Vector2& right)
{
	x *= right.x;
	y *= right.y;
	return *this;
}

Vector2& Vector2::operator/=(const Vector2& right)
{
	if (right.x != 0 && right.y != 0)
	{
		x /= right.x;
		y /= right.y;
	}
	return *this;
}

void Vector2::normalize()
{
	if (x != 0 || y != 0)
	{
		int lenght = sqrt(pow(x, 2) + pow(y, 2));
		x /= lenght;
		y /= lenght;
	}
}

void Vector2::rotate(int rotation)
{
	int x_1 = x;
	x = (x * cos(rotation)) - (y * sin(rotation));
	y = (x_1 * sin(rotation)) + (y * cos(rotation));
}

Vector2 Vector2::rotated(int rotation) const
{
	return Vector2(
		(x * cos(rotation)) - (y * sin(rotation)),
		(x * sin(rotation)) + (y * cos(rotation))
	);
}

Vector2 Vector2::normalized() const
{
	if (x != 0 || y != 0)
	{
		int length = sqrt(pow(x, 2) + pow(y, 2));
		return Vector2(
			x / length,
			y / length);
	}
	else
	{
		return Vector2(0, 0);
	}
}

int Vector2::absolute() const
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

int Vector2::dotProduct(const Vector2& left, const Vector2& right)
{
	return left.x * right.x + left.y * right.y;
}


std::ostream& operator<<(std::ostream& os, const Vector2& vector2)
{
	os << '{' << vector2.x << ',' << vector2.y << '}';
	return os;
}
