// Transform.cpp: implementation of the Transform class.


#include "Transform.h"

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
  // YOUR CODE FOR HW1 HERE
	float radians = degrees * pi / 180.0f;
    mat3 r1(cos(radians));
    mat3 r2(0, -axis.z, axis.y, axis.z, 0, -axis.x, -axis.y, axis.x, 0);
    mat3 r3(axis.x*axis.x, axis.x*axis.y, axis.x*axis.z,
            axis.x*axis.y, axis.y*axis.y, axis.y*axis.z,
            axis.x*axis.z, axis.z*axis.y, axis.z*axis.z);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            r2[i][j] = r2[i][j]*sin(radians);
            r3[i][j] = r3[i][j]*(1-cos(radians));
        }
    }
    return r1 + r2 + r3;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
	/*	a	b	c
		d	e	f
		g	h	i

		mat3(a,d,g,b,e,h,c,f,i)
	*/
	eye = eye * rotate(degrees, up);
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
	vec3 ortho_axis = glm::cross(eye, up);
	ortho_axis = glm::normalize(ortho_axis);

	eye = eye*rotate(degrees, ortho_axis);
	up = up*rotate(degrees, ortho_axis);
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
	vec3 center = vec3(0);
  // YOUR CODE FOR HW1 HERE
	mat4 look =glm::lookAt(eye,center,up);
  // You will change this return call
  return look;
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
