#pragma once

#include <core/mat4.h>
#include <cmath>

namespace wee {
    struct vec3;
    struct mat4 {
        union {
            struct {
                float m11, m12, m13, m14;
                float m21, m22, m23, m24;
                float m31, m32, m33, m34;
                float m41, m42, m43, m44;
            };
            float cell[16];
        };

        static mat4 create_scale(float sx, float sy, float sz) {
            mat4 res;
            res.m11 = sx;
            res.m22 = sy;
            res.m33 = sz;
            res.m44 = 1.0f;
            return res;
        }

        static mat4 create_rotation(float rx, float ry, float rz) {
            auto mrx = mat4::create_rotation_x(rx);
            auto mry = mat4::create_rotation_y(ry);
            auto mrz = mat4::create_rotation_z(rz);
            return mat4::mul(mat4::mul(mrx, mry), mrz);
        }
        static mat4 create_rotation_x(float a) {
            mat4 res;
            float ct = std::cos(a);
            float st = std::sin(a);
            res.m22 =  ct;            res.m23 = -st;
            res.m32 =  st;            res.m33 =  ct;
            return res;
        }
        static mat4 create_rotation_y(float a) {
            mat4 res;
            float ct = std::cos(a);
            float st = std::sin(a);
            res.m11 =  ct;            res.m13 = st;
            res.m31 = -st;            res.m33 = ct;
            return res;
        }
        static mat4 create_rotation_z(float a) {
            mat4 res;
            float ct = std::cos(a);
            float st = std::sin(a);
            res.m11 =  ct;            res.m12 = -st;
            res.m21 =  st;            res.m22 =  ct;
            return res;
        }

        static mat4 create_ortho_offcenter(float left, float right, float top, float bottom, float near, float far) {
            mat4 res;
            res.m11 = 2.0f / (right - left);
            res.m22 = 2.0f / (top - bottom);
            res.m33 = 2.0f / (far - near);
            res.m41 = (left + right) / (left - right);
            res.m42 = (bottom + top) / (bottom - top);
            res.m43 = near / (near - far);
            return res;
        }

        static mat4 create_translation(float x, float y, float z) {
            mat4 res;
            res.m41 = x;
            res.m42 = y;
            res.m43 = z;
            return res;
        }

        static mat4 transposed(const mat4& in) {
            mat4 res;
            res.m11 = in.m11;
            res.m12 = in.m21;
            res.m13 = in.m31;
            res.m14 = in.m41;

            res.m21 = in.m12;
            res.m22 = in.m22;
            res.m23 = in.m32;
            res.m24 = in.m42;

            res.m31 = in.m13;
            res.m32 = in.m23;
            res.m33 = in.m33;
            res.m34 = in.m43;

            res.m41 = in.m14;
            res.m42 = in.m24;
            res.m43 = in.m34;
            res.m44 = in.m44;

            return res;
        }

        static mat4 inverted(const mat4&);

        static mat4 create_lookat(const vec3&, const vec3&, const vec3&);

        static mat4 mul(const mat4& a, const mat4& b) {
            mat4 res;
            matmul4(&a.cell[0], &b.cell[0], &res.cell[0]);
            return res;
        }


#ifdef HAVE_SSE
        static inline __m128 lincomb_sse(const __m128 &a, const mat4 &B)
        {
            __m128 result;
            result = _mm_mul_ps(_mm_shuffle_ps(a, a, 0x00), B.row[0]);
            result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(a, a, 0x55), B.row[1]));
            result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(a, a, 0xaa), B.row[2]));
            result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(a, a, 0xff), B.row[3]));
            return result;
        }


        static void matmul4_sse(const mat4& A, const mat4& B, mat4* out) {
            __m128 out0x = lincomb_sse(A.row[0], B);
            __m128 out1x = lincomb_sse(A.row[1], B);
            __m128 out2x = lincomb_sse(A.row[2], B);
            __m128 out3x = lincomb_sse(A.row[3], B);

            out->row[0] = out0x;
            out->row[1] = out1x;
            out->row[2] = out2x;
            out->row[3] = out3x;

        }
#endif
    };
}

