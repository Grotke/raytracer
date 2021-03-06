#pragma once
#include <glm/glm.hpp>
class Transform {
public:
	static glm::mat4 translate(float x, float y, float z) {
		glm::mat4 ret;
		ret = glm::transpose(glm::mat4(1.0f, 0.0f, 0.0f, x,
			0.0f, 1.0f, 0.0f, y,
			0.0f, 0.0f, 1.0f, z,
			0.0f, 0.0f, 0.0f, 1.0f));
		return ret;
	}

	static glm::mat4 scale(float x, float y, float z) {
		return glm::mat4(x, 0.0f, 0.0f, 0.0f, 0.0f, y, 0.0f, 0.0f, 0.0f, 0.0f, z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	}

	static glm::mat4 rotate(float x, float y, float z, float angleInDegrees) {
		glm::mat3 ret;
		float radians = glm::radians(angleInDegrees);
		glm::vec3 unitAxis = glm::normalize(glm::vec3(x, y, z));

		ret = (cos(radians)* glm::transpose(glm::mat3(1.0f))) + ((1.0f - cos(radians))*glm::transpose(glm::mat3(pow(unitAxis.x, 2.0f), unitAxis.x*unitAxis.y, unitAxis.x*unitAxis.z, unitAxis.x*unitAxis.y, pow(unitAxis.y, 2.0f), unitAxis.y*unitAxis.z, unitAxis.x*unitAxis.z, unitAxis.y*unitAxis.z, pow(unitAxis.z, 2.0f)))) + (sin(radians) * glm::transpose(glm::mat3(0.0f, -unitAxis.z, unitAxis.y, unitAxis.z, 0.0f, -unitAxis.x, -unitAxis.y, unitAxis.x, 0.0f)));
		glm::mat4 mat;
		mat[0] = glm::vec4(ret[0], 0.0f);
		mat[1] = glm::vec4(ret[1], 0.0f);
		mat[2] = glm::vec4(ret[2], 0.0f);
		mat[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
		return mat;
	}
};