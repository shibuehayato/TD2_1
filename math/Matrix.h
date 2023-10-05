﻿#define _USE_MATH_DEFIENS
#include "Matrix4x4.h"
#include "Vector3.h"
#include <assert.h>
#include <cmath>

Vector3 Add(Vector3 v1, Vector3 v2);

Vector3 Sub(Vector3 v1, Vector3 v2);

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

Matrix4x4 MakeRotateXMatrix(float radian);

Matrix4x4 MakeRotateYMatrix(float radian);

Matrix4x4 MakeRotateZMatrix(float radian);

Matrix4x4 MakeRotateMatrix(const Vector3& radian);

Matrix4x4 MakeScaleMatrix(const Vector3& scale);

Matrix4x4 MakeRotateXMatrix(float radian);

Matrix4x4 MakeTranslateMatrix(const Vector3& translate);

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate);

Vector3 VectorAdd(const Vector3& translation, const Vector3& move);

// ベクトル変換
Vector3 TransformNormal(const Vector3& v, const Matrix4x4& m);

// 正規化
Vector3 Normalize(const Vector3 v1);

Matrix4x4 Inverse(const Matrix4x4& m1);

Matrix4x4 MakeViewportMatrix(
    float left, float top, float width, float height, float minDepth, float maxDepth);

Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);