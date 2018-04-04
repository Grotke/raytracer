#pragma once
#include <string>
#include <sstream>
#include <vector>

#include "SceneObjects.hpp"
#include "Camera.h"

class Scene
{
	public:
		Scene(const std::string& fileName);
		~Scene();
		bool readvals(std::stringstream &s, int numvals, float * values);
		void setDefaults();

		const Camera& getCamera() const;
		const std::vector<Shape*>& getSceneObjects() const;
		const std::string& getOutputFileName() const;
		const unsigned int getWidth() const;
		const unsigned int getHeight() const;

	private:
		Camera cam;
		std::vector<Light> lights;
		glm::vec3 attenuation;
		int maxDepth;
		unsigned int width, height;
		std::string outputFileName;
		std::vector<Shape*> objects;
};

