//
//  Camera.h
//
//	Basic camera class
//

#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "vec\vec.h"
#include "vec\mat.h"

using namespace linalg;

class camera_t
{
	float vfov, aspect;	// aperture attributes
	float zNear, zFar, rotationYaw = 0, rotationPitch = 0;	// clip planes
	vec3f position;
	mat4f rotation = mat4f::rotation(0.0f, 0.0f, 0.0f);
	

public:

	camera_t(
		float vfov,
		float aspect,
		float zNear,
		float zFar):
		vfov(vfov), aspect(aspect), zNear(zNear), zFar(zFar)
	{

	}

	void moveTo(const vec3f& p)
	{
		position = p;
	}

	void move(const vec3f& v)
	{
		position += v;
	}

	mat4f get_WorldToViewMatrix()
	{
		rotation = mat4f::rotation(0.0f, rotationYaw, rotationPitch);
		return rotation * mat4f::translation(-position);
	}

	void rotateYaw(float value)
	{
		rotationYaw += value;
	}

	void rotatePitch(float value)
	{
		rotationPitch += value;
	}


	mat4f get_ProjectionMatrix() const
	{
		return mat4f::projection(vfov, aspect, zNear, zFar);
	}
};

#endif