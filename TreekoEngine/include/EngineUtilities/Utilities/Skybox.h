#pragma once
#include "Prerequisites.h"
#include "ShaderProgram.h"
#include "Texture.h"
#include "Buffer.h"
#include "SamplerState.h"
#include "Model3D.h"
#include "RasterizerState.h"
#include "DepthStencilState.h"
#include "EngineUtilities\Utilities\Camera.h"
#include "ECS\Actor.h"
		
class Device;
class DeviceContext;

/*
  *  @brief Represents a skybox for rendering backgrounds in a 3D scene.
*/
class
	Skybox {
public:
	/*
	  *  @brief Default constructor for Skybox.
	*/
	Skybox() = default;
	/*
	  *  @brief Default destructor for Skybox.
	*/
	~Skybox() = default;

	/*
	  *  @brief Initializes the skybox with the given device, context, and cubemap texture.
	  *  @param device Reference to the rendering device.
	  *  @param deviceContext Pointer to the device context.
	  *  @param cubemap Reference to the cubemap texture.
	  *  @return HRESULT indicating success or failure.
	*/
	HRESULT
		init(Device& device, DeviceContext* deviceContext, Texture& cubemap);

	/*
	  *  @brief Updates the skybox state. Currently does nothing.
	*/
	void
		update() {}

	/*
	  *  @brief Renders the skybox using the provided device context and camera.
	  *  @param deviceContext Reference to the device context.
	  *  @param camera Reference to the camera.
	*/
	void
		render(DeviceContext& deviceContext, Camera& camera);

	/*
	  *  @brief Destroys and releases skybox resources. Currently does nothing.
	*/
	void
		destroy() {}

private:
	/*
	  *  @brief Shader program used for rendering the skybox.
	*/
	ShaderProgram m_shaderProgram;
	/*
	  *  @brief Constant buffer for shader parameters.
	*/
	Buffer m_constantBuffer;
	/*
	  *  @brief Sampler state for texture sampling.
	*/
	SamplerState m_samplerState;
	/*
	  *  @brief Rasterizer state for skybox rendering.
	*/
	RasterizerState m_rasterizerState;
	/*
	  *  @brief Depth stencil state for skybox rendering.
	*/
	DepthStencilState m_depthStencilState;
	/*
	  *  @brief Texture representing the skybox cubemap.
	*/
	Texture m_skyboxTexture;
	/*
	  *  @brief Pointer to the 3D cube model used for the skybox.
	*/
	Model3D* m_cubeModel = nullptr;
	/*
	  *  @brief Shared pointer to the Actor representing the skybox.
	*/
	EU::TSharedPointer<Actor> m_skybox;

};
