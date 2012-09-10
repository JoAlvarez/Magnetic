#include "vector2d.h"
#include <cmath>

Vector2d::Vector2d()
{
	x = 0;
	y = 0;
}

Vector2d::Vector2d(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Vector2d::getX()
{
	return x;
}

double Vector2d::getY()
{
	return y;
}

void Vector2d::setX(double x)
{
	this->x = x;
}

void Vector2d::setY(double y)
{
	this->y = y;
}

Vector2d Vector2d::operator=(Vector2d b)
{
	this->x = b.x;
	this->y = b.y;
}

Vector2d sub(Vector2d a, Vector2d b)
{
	Vector2d v;
	v.setX(a.getX() - b.getX());
	v.setY(a.getY() - b.getY());
	return v;
}

Vector2d add(Vector2d a, Vector2d b)
{
	Vector2d v;
	v.setX(a.getX() + b.getX());
	v.setY(a.getY() + b.getY());
	return v;
}

Vector2d mult(Vector2d a, double b)
{
	Vector2d v;
	v.setX(a.getX() * b);
	v.setY(a.getY() * b);
	return v;
}

Vector2d normalize(Vector2d a)
{
	Vector2d v;
	double length = sqrt((a.getX() * a.getX()) + (a.getY() * a.getY()));
	v.setX(a.getX() / length);
	v.setY(a.getY() / length);
	return v;
}

double dotProduct(Vector2d a, Vector2d b)
{
	return (a.getX() * b.getX()) + (a.getY() * b.getY());
}

double length(Vector2d a)
{
	return sqrt((a.getX() * a.getX()) + (a.getY() * a.getY()));
}
