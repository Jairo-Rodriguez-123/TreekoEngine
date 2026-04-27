#pragma once
#include "Prerequisites.h"
#include "Rendering/RenderTypes.h"

class Skybox;

/*
  *  @brief Represents a renderable scene containing objects, lights, and a skybox.
*/
class
	RenderScene {
public:	

	/*
	  *  @brief Clears all objects and lights from the scene.
	*/
	void
		clear();

public:

	/*
	  *  @brief List of opaque renderable objects in the scene.
	*/
	std::vector<RenderObject> opaqueObjects;

	/*
	  *  @brief List of transparent renderable objects in the scene.
	*/
	std::vector<RenderObject> transparentObjects;

	/*
	  *  @brief List of directional lights affecting the scene.
	*/
	std::vector<LightData> directionalLights;

	/*
	  *  @brief Pointer to the skybox used in the scene. Can be nullptr if not set.
	*/
	Skybox* skybox = nullptr;
};