#pragma once
//Matrix class from https://scratchapixel.com
template<typename T>
class Matrix44
{
public:
	Matrix44() {}
	inline const T* operator [] (uint8_t i) const { return m[i]; }
	inline T* operator [] (uint8_t i) { return m[i]; }
	inline Matrix44 operator * (const Matrix44& rhs) const
	{
		Matrix44 mult;
		for (uint8_t i = 0; i < 4; ++i) {
			for (uint8_t j = 0; j < 4; ++j) {
				mult[i][j] = m[i][0] * rhs[0][j] +
					m[i][1] * rhs[1][j] +
					m[i][2] * rhs[2][j] +
					m[i][3] * rhs[3][j];
			}
		}

		return mult;
	}
	inline void multVecMatrix(const Vec3<T>& src, Vec3<T>& dst) const
	{
		dst.x = src.x * m[0][0] + src.y * m[1][0] + src.z * m[2][0] + m[3][0];
		dst.y = src.x * m[0][1] + src.y * m[1][1] + src.z * m[2][1] + m[3][1];
		dst.z = src.x * m[0][2] + src.y * m[1][2] + src.z * m[2][2] + m[3][2];
		T w = src.x * m[0][3] + src.y * m[1][3] + src.z * m[2][3] + m[3][3];
		if (w != 1 && w != 0) {
			dst.x = x / w;
			dst.y = y / w;
			dst.z = z / w;
		}
	}
	inline void multDirMatrix(const Vec3<T>& src, Vec3<T>& dst) const
	{
		dst.x = src.x * m[0][0] + src.y * m[1][0] + src.z * m[2][0];
		dst.y = src.x * m[0][1] + src.y * m[1][1] + src.z * m[2][1];
		dst.z = src.x * m[0][2] + src.y * m[1][2] + src.z * m[2][2];
	}
	// initialize the coefficients of the matrix with the coefficients of the identity matrix
	T m[4][4] = { {1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1} };
};

typedef Matrix44<float> Matrix44f;
typedef Matrix44<double> Matrix44d;