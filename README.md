# CSC418 Assignment 3: Ray Tracer
 In the assignment I implemented the algorithms used to draw scenes with ray tracing. This includes ray casting, ray intersection with primitive and Phong Illumination. Along with the basic features I implemented global illumination, allowing my ray tracer to create shadows and relfections. And, lastly I implemented anti-aliasing.
 
 ## Part 1: Basic Intersection
 
 In the first part of this assignment I had to implement the intersection algorithm with a sphere and a plane. These are the results.
 
![Scene Signature2](https://raw.githubusercontent.com/SanchitL/RayTracer/master/images/sig2.bmp)

## Part 2: Illumination

In this part of the assignment I implemented diffuse shading and Phong shading using the phong illumination model.

- Diffuse
![Diffuse](https://raw.githubusercontent.com/SanchitL/RayTracer/master/images/diffuse2.bmp)
- Phong
![Phong](https://raw.githubusercontent.com/SanchitL/RayTracer/master/images/phong2.bmp)

## Part 3: Gobal Illumination

Implemented a global ilumination model that allows for one degree of reflection and casts shadows onto the scene.
![Global](https://raw.githubusercontent.com/SanchitL/RayTracer/master/images/global-illumination.bmp)

## Part 4: Anti-Aliasing

Implemented multi-sample anti aliasing to smooth out jaggies from the scene.
![MSAA](https://raw.githubusercontent.com/SanchitL/RayTracer/master/images/anti-aliasing.bmp)
