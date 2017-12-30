/***********************************************************
     Starter code for Assignment 3

     This code was originally written by Jack Wang for
		    CSC418, SPRING 2005

		implements light_source.h

***********************************************************/

#include <cmath>
#include <algorithm>
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

	// for debugging
	int type = 2;

	// signature
	if (type == 0) {
		Colour diffuse;
		diffuse = ray.intersection.mat->diffuse;

		ray.col = diffuse;
	}
	else {
		// Ambient and Diffuse

		Vector3D lightDir = _pos - ray.intersection.point;
		lightDir.normalize();
		
		Vector3D normal = ray.intersection.normal;
		normal.normalize();

		Vector3D viewDir = -ray.dir;
		viewDir.normalize();

		Vector3D reflectionDir = 2 * normal.dot(lightDir)* normal - lightDir;
		reflectionDir.normalize();

		Colour ambient = ray.intersection.mat->ambient * _col_ambient;
		Colour diffuse =
			ray.intersection.mat->diffuse * (std::max(0.0, normal.dot(lightDir)) * _col_diffuse);
		
			// specular
		Colour specular =
			ray.intersection.mat->specular * (std::pow(std::max(0.0, viewDir.dot(reflectionDir)), ray.intersection.mat->specular_exp) * _col_specular);		
		
		if (type == 1) {
			ray.col = ambient + diffuse;
		}
		else {
			ray.col = ambient + diffuse + specular;
		}
	}
	ray.col.clamp();
}

