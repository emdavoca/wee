#include <core/mat4.hpp>
#include <core/vec3.hpp>
#include <numeric>
#include <limits>
using namespace wee;

mat4 mat4::inverted(const mat4& in) 
{
    mat4 res;
    

	float num23 = (in.m33 * in.m44) - (in.m34 * in.m43);
    float num22 = (in.m32 * in.m44) - (in.m34 * in.m42);
    float num21 = (in.m32 * in.m43) - (in.m33 * in.m42);
    float num20 = (in.m31 * in.m44) - (in.m34 * in.m41);
    float num19 = (in.m31 * in.m43) - (in.m33 * in.m41);
    float num18 = (in.m31 * in.m42) - (in.m32 * in.m41);
    float num39 = ((in.m22 * num23) - (in.m23 * num22)) + (in.m24 * num21);
    float num38 = -(((in.m21 * num23) - (in.m23 * num20)) + (in.m24 * num19));
    float num37 = ((in.m21 * num22) - (in.m22 * num20)) + (in.m24 * num18);
    float num36 = -(((in.m21 * num21) - (in.m22 * num19)) + (in.m23 * num18));
    float num = (float) 1 / ((((in.m11 * num39) + (in.m12 * num38)) + (in.m13 * num37)) + (in.m14 * num36));
    res.m11 = num39 * num;
    res.m21 = num38 * num;
    res.m31 = num37 * num;
    res.m41 = num36 * num;
    res.m12 = -(((in.m12 * num23) - (in.m13 * num22)) + (in.m14 * num21)) * num;
    res.m22 = (((in.m11 * num23) - (in.m13 * num20)) + (in.m14 * num19)) * num;
    res.m32 = -(((in.m11 * num22) - (in.m12 * num20)) + (in.m14 * num18)) * num;
    res.m42 = (((in.m11 * num21) - (in.m12 * num19)) + (in.m13 * num18)) * num;
    float num35 = (in.m23 * in.m44) - (in.m24 * in.m43);
    float num34 = (in.m22 * in.m44) - (in.m24 * in.m42);
    float num33 = (in.m22 * in.m43) - (in.m23 * in.m42);
    float num32 = (in.m21 * in.m44) - (in.m24 * in.m41);
    float num31 = (in.m21 * in.m43) - (in.m23 * in.m41);
    float num30 = (in.m21 * in.m42) - (in.m22 * in.m41);
    res.m13 = (((in.m12 * num35) - (in.m13 * num34)) + (in.m14 * num33)) * num;
    res.m23 = -(((in.m11 * num35) - (in.m13 * num32)) + (in.m14 * num31)) * num;
    res.m33 = (((in.m11 * num34) - (in.m12 * num32)) + (in.m14 * num30)) * num;
    res.m43 = -(((in.m11 * num33) - (in.m12 * num31)) + (in.m13 * num30)) * num;
    float num29 = (in.m23 * in.m34) - (in.m24 * in.m33);
    float num28 = (in.m22 * in.m34) - (in.m24 * in.m32);
    float num27 = (in.m22 * in.m33) - (in.m23 * in.m32);
    float num26 = (in.m21 * in.m34) - (in.m24 * in.m31);
    float num25 = (in.m21 * in.m33) - (in.m23 * in.m31);
    float num24 = (in.m21 * in.m32) - (in.m22 * in.m31);
    res.m14 = -(((in.m12 * num29) - (in.m13 * num28)) + (in.m14 * num27)) * num;
    res.m24 = (((in.m11 * num29) - (in.m13 * num26)) + (in.m14 * num25)) * num;
    res.m34 = -(((in.m11 * num28) - (in.m12 * num26)) + (in.m14 * num24)) * num;
    res.m44 = (((in.m11 * num27) - (in.m12 * num25)) + (in.m13 * num24)) * num;
    return res;
}

mat4 mat4::create_lookat(const vec3& eye, const vec3& at, const vec3& up) {

	vec3 vz = vec3::normalized(eye - at);

    vec3 vx = vec3::cross(up, vz);

    if (vec3::dot(vx, vx) < std::numeric_limits<float>::epsilon())
        vx = vec3::_right;
    else
        vx = vec3::normalized(vx);

    vec3 vy = vec3::normalized(vec3::cross(vz, vx));

    mat4 res;
    res.m11 = vx.x;  res.m12 = vy.x;  res.m13 = vz.x; res.m14 = (float)0.;
    res.m21 = vx.y;  res.m22 = vy.y;  res.m23 = vz.y; res.m24 = (float)0.;
    res.m31 = vx.z;  res.m32 = vy.z;  res.m33 = vz.z; res.m34 = (float)0.;

    res.m41 = vec3::dot(vx, -eye);
    res.m42 = vec3::dot(vy, -eye);
    res.m43 = vec3::dot(vz, -eye);

    res.m44 = (float)1.;
    return res;
}
