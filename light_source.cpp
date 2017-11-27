/***********************************************************
     Starter code for Assignment 3

     This code was originally written by Jack Wang for
		    CSC418, SPRING 2005

		implements light_source.h

***********************************************************/

#include <cmath>
#include "light_source.h"

void PointLight::shade( Ray3D& ray ) {
	// TODO: implement this function to fill in values for ray.col 
	// using phong shading.  Make sure your vectors are normalized, and
	// clamp colour values to 1.0.
	//
	// It is assumed at this point that the intersection information in ray 
	// is available.  So be sure that traverseScene() is called on the ray 
	// before this function.  
	if (ray.intersection.none == true) {
		return;
	}
	Colour diffuse;
	double diffuse_r = _col_diffuse[0] * ray.intersection.mat->diffuse[0] * (ray.intersection.normal.dot(ray.intersection.point - _pos));
	double diffuse_g = _col_diffuse[1] * ray.intersection.mat->diffuse[1] * (ray.intersection.normal.dot(ray.intersection.point - _pos));
	double diffuse_b = _col_diffuse[2] * ray.intersection.mat->diffuse[2] * (ray.intersection.normal.dot(ray.intersection.point - _pos));

	diffuse[0] = diffuse_r;
	diffuse[1] = diffuse_g;
	diffuse[2] = diffuse_b;

	ray.col = diffuse;
	ray.col.clamp();
}

