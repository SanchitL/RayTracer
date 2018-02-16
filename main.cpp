/***********************************************************
Starter code for Assignment 3

This code was originally written by Jack Wang for
CSC418, SPRING 2005

***********************************************************/


#include "raytracer.h"
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
	// Build your scene and setup your camera here, by calling 
	// functions from Raytracer.  The code here sets up an example
	// scene and renders it from two different view points, DO NOT
	// change this if you're just implementing part one of the 
	// assignment.  
	Raytracer raytracer;
	int width = 320;
	int height = 240;
	int aaSamples = 1;

	if (argc >= 3) {
		width = atoi(argv[1]);
		height = atoi(argv[2]);
	}

	if (argc == 4) {
		aaSamples = atoi(argv[3]);
	}

	std::cout << "Rendering with width: " << width << ", height: " << height << " ..." << std::endl;
	if (aaSamples > 1) std::cout << "AA with x: " << aaSamples << std::endl;
	// Camera parameters.
	Point3D eye(0, 0, 1);
	Vector3D view(0, 0, -1);
	Vector3D up(0, 1, 0);
	double fov = 60;

	// Defines a material for shading.
	Material gold(Colour(0.3, 0.3, 0.3), Colour(0.75164, 0.60648, 0.22648),
		Colour(0.628281, 0.555802, 0.366065),
		51.2,
		true);
	Material jade(Colour(0, 0, 0), Colour(0.54, 0.89, 0.63),
		Colour(0.316228, 0.316228, 0.316228),
		12.8,
		true);

	// Defines a point light source.
	raytracer.addLightSource(new PointLight(Point3D(0, 0, 5),
		Colour(0.9, 0.9, 0.9)));

	// Add a unit square into the scene with material mat.
	// SceneDagNode* sphere = raytracer.addObject(new UnitSphere(), &gold);
	// SceneDagNode* plane = raytracer.addObject(new UnitSquare(), &jade);
	SceneDagNode* cylinder = raytracer.addObject(new UnitCylinder(), &jade);


	// Apply some transformations to the unit square.
	double factor1[3] = { 1.0, 2.0, 1.0 };
	double factor2[3] = { 6.0, 6.0, 6.0 };
	// raytracer.translate(sphere, Vector3D(0, 0, -5));
	// raytracer.rotate(sphere, 'x', -45);
	// raytracer.rotate(sphere, 'z', 45);
	// raytracer.scale(sphere, Point3D(0, 0, 0), factor1);

	// raytracer.translate(plane, Vector3D(0, 0, -7));
	// raytracer.rotate(plane, 'z', 45);
	// raytracer.scale(plane, Point3D(0, 0, 0), factor2);

	raytracer.translate(cylinder, Vector3D(0, 0, -5));

	// Render the scene, feel free to make the image smaller for
	// testing purposes.
	std::cout << "Now rendering view1 .... \n" << std::endl;
	raytracer.render(width, height, eye, view, up, fov, aaSamples, "view1.bmp");

	// Render it from a different point of view.
	Point3D eye2(4, 2, 1);
	Vector3D view2(-4, -2, -6);

	std::cout << "Now rendering view2 .... \n" << std::endl;
	raytracer.render(width, height, eye2, view2, up, fov, aaSamples, "view2.bmp");

	return 0;
}