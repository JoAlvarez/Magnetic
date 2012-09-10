#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__

#include "mathfunctions.h"

class Vector2d
{
	private:

		double x, y;

	public:

		Vector2d();
		Vector2d(double x, double y);

		double getX();
		double getY();

		void setX(double x);
		void setY(double y);

		Vector2d operator= (Vector2d b);
};

Vector2d sub(Vector2d a, Vector2d b);
Vector2d add(Vector2d a, Vector2d b);
Vector2d mult(Vector2d a, double b);
Vector2d normalize(Vector2d v);
double dotProduct(Vector2d a, Vector2d b);
double length(Vector2d v);

#endif
