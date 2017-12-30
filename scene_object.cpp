/***********************************************************
     Starter code for Assignment 3

     This code was originally written by Jack Wang for
		    CSC418, SPRING 2005

		implements scene_object.h

***********************************************************/

#include <cmath>
#include <iostream>
#include "scene_object.h"

bool UnitSquare::intersect( Ray3D& ray, const Matrix4x4& worldToModel,
		const Matrix4x4& modelToWorld ) {
	// TODO: implement intersection code for UnitSquare, which is
	// defined on the xy-plane, with vertices (0.5, 0.5, 0), 
	// (-0.5, 0.5, 0), (-0.5, -0.5, 0), (0.5, -0.5, 0), and normal
	// (0, 0, 1).
	//
	// Your goal here is to fill ray.intersection with correct values
	// should an intersection occur.  This includes intersection.point, 
	// intersection.normal, intersection.none, intersection.t_value.   
	//
	// HINT: Remember to first transform the ray into object space  
	// to simplify the intersection test.

	//Transform the ray
	Vector3D normal = Vector3D(0.0, 0.0, 1.0);
	Point3D modelPoint = worldToModel*ray.origin;
	Vector3D modelDir = worldToModel*ray.dir;

	//t-value using z value of ray
	double t = (0 - modelPoint[2]) / modelDir[2];

	Point3D intersectionPoint = modelPoint + t*modelDir;
	double x = intersectionPoint[0];
	double y = intersectionPoint[1];

	// invalid t value
	if (t <= 0) return false;

	// is the point in the square?
	if (x < 0.5 && x > -0.5 && y < 0.5 && y > -0.5) {
		//is this closer than a previous intersection or does one not exsist
		if (ray.intersection.none || t < ray.intersection.t_value) {
			ray.intersection.point = modelToWorld*intersectionPoint;
			ray.intersection.normal = transNorm(worldToModel, normal);
			ray.intersection.normal.normalize();
			ray.intersection.none = false;
			ray.intersection.t_value = t;
			return true;
		}
	}
	return false;
}

bool UnitSphere::intersect( Ray3D& ray, const Matrix4x4& worldToModel,
		const Matrix4x4& modelToWorld ) {
	// TODO: implement intersection code for UnitSphere, which is centred 
	// on the origin.  
	//
	// Your goal here is to fill ray.intersection with correct values
	// should an intersection occur.  This includes intersection.point, 
	// intersection.normal, intersection.none, intersection.t_value.   
	//
	// HINT: Remember to first transform the ray into object space  
	// to simplify the intersection test.
	Point3D centre = Point3D(0.0, 0.0, 0.0);
	int radius = 1;

	Point3D modelPoint = worldToModel*ray.origin;
	Vector3D modelDir = worldToModel*ray.dir;
	Vector3D diff = modelPoint - centre;

	// At^2 + Bt + C = 0
	double A = modelDir.dot(modelDir);
	double B = diff.dot(modelDir);
	double C = diff.dot(diff) - radius;

	double discriminant = (B*B) - (A*C);

	//no intersection
	if (discriminant < 0) return false;

	// solve for t
	double t_1 = (-B + std::sqrt(discriminant)) / A;
	double t_2 = (-B - std::sqrt(discriminant)) / A;

	double t = 0.0;

	// pick the small positive t
	if (t_1 < t_2) {
		t = t_1;
	}
	else if (t_2 < t_1) {
		t = t_2;
	}
	
	if (t <= 0) return false;

	Point3D intersectionPoint = modelPoint + t*modelDir;
	if (ray.intersection.none || t < ray.intersection.t_value) {
		ray.intersection.point = modelToWorld*intersectionPoint;
		ray.intersection.normal = transNorm(worldToModel, (intersectionPoint - centre));
		ray.intersection.normal.normalize();
		ray.intersection.none = false;
		ray.intersection.t_value = t;
		return true;
	}

	return false;
}

bool UnitCylinder::intersect(Ray3D& ray, const Matrix4x4& wordlToModel,
	const Matrix4x4& modelToWorld) {

	return false;
}

