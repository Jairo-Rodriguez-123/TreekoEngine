#pragma once
#include "Prerequisites.h"
#include "Buffer.h"
#include "DepthStencilState.h"
#include "DepthStencilView.h"
#include "RasterizerState.h"
#include "Rendering/RenderScene.h"
#include "Rendering/RenderTypes.h"
#include "ShaderProgram.h"
#include "Texture.h"
#include "EngineUtilities/Utilities/EditorViewportPass.h"

class Device;
class DeviceContext;
class Camera;
class Material;

/*
  *  @brief Forward rendering pipeline class responsible for rendering scenes using forward rendering techniques.
*/
class
	ForwardRenderer {
public:
	
	/*
	  *  @brief Initializes the forward renderer and its resources.
	  *  @param device Reference to the graphics device.
	  *  @return HRESULT indicating success or failure.
	*/
	HRESULT
		init(Device& device);

	/*
	  *  @brief Resizes the renderer's resources to match the new viewport dimensions.
	  *  @param device Reference to the graphics device.
	  *  @param width New width of the viewport.
	  *  @param height New height of the viewport.
	*/
	void
		resize(Device& device, unsigned int width, unsigned int height);

	/*
	  *  @brief Updates per-frame constant buffers and state.
	  *  @param camera Reference to the active camera.
	  *  @param scene Reference to the render scene.
	  *  @param deviceContext Reference to the device context.
	*/
	void
		updatePerFrame(const Camera& camera,
			const RenderScene& scene,
			DeviceContext& deviceContext);

	/*
	  *  @brief Executes the rendering passes for the current frame.
	  *  @param deviceContext Reference to the device context.
	  *  @param camera Reference to the active camera.
	  *  @param scene Reference to the render scene.
	  *  @param viewportPass Reference to the editor viewport pass.
	*/
	void
		render(DeviceContext& deviceContext,
			const Camera& camera,
			RenderScene& scene,
			EditorViewportPass& viewportPass);

	/*
	  *  @brief Releases all resources used by the renderer.
	*/
	void
		destroy();

	/*
	  *  @brief Gets the shader resource view for the shadow map.
	  *  @return Pointer to the shadow map SRV.
	*/
	ID3D11ShaderResourceView*
		getShadowMapSRV() const { return m_shadowDepthSRV.m_textureFromImg; }

	/*
	  *  @brief Gets the shader resource view for the pre-shadow debug pass.
	  *  @return Pointer to the pre-shadow debug SRV.
	*/
	ID3D11ShaderResourceView*
		getPreShadowSRV() const { return m_preShadowDebugPass.getSRV(); }

private:

	/*
	  *  @brief Builds the rendering queues for opaque and transparent objects.
	  *  @param scene Reference to the render scene.
	  *  @param camera Reference to the active camera.
	*/
	void
		buildQueues(RenderScene& scene, const Camera& camera);

	/*
	  *  @brief Renders the pre-shadow debug pass.
	  *  @param deviceContext Reference to the device context.
	  *  @param scene Reference to the render scene.
	*/
	void
		renderPreShadowDebugPass(DeviceContext& deviceContext, RenderScene& scene);

	/*
	  *  @brief Renders the shadow pass for shadow mapping.
	  *  @param deviceContext Reference to the device context.
	*/
	void
		renderShadowPass(DeviceContext& deviceContext);

	/*
	  *  @brief Renders all opaque objects in the scene.
	  *  @param deviceContext Reference to the device context.
	*/
	void
		renderOpaquePass(DeviceContext& deviceContext);

	/*
	  *  @brief Renders all transparent objects in the scene.
	  *  @param deviceContext Reference to the device context.
	*/
	void
		renderTransparentPass(DeviceContext& deviceContext);

	/*
	  *  @brief Renders the skybox for the scene.
	  *  @param deviceContext Reference to the device context.
	  *  @param scene Reference to the render scene.
	*/
	void
		renderSkyboxPass(DeviceContext& deviceContext, RenderScene& scene);

	/*
	  *  @brief Renders a single object for a specific render pass.
	  *  @param deviceContext Reference to the device context.
	  *  @param object Reference to the render object.
	  *  @param passType Type of the render pass.
	*/
	void
		renderObject(DeviceContext& deviceContext,
			const RenderObject& object,
			RenderPassType passType);

	/*
	  *  @brief Renders a single object for the shadow pass.
	  *  @param deviceContext Reference to the device context.
	  *  @param object Reference to the render object.
	*/
	void
		renderShadowObject(DeviceContext& deviceContext, const RenderObject& object);

	/*
	  *  @brief Creates resources required for shadow mapping.
	  *  @param device Reference to the graphics device.
	  *  @return HRESULT indicating success or failure.
	*/
	HRESULT
		createShadowResources(Device& device);

	/*
	  *  @brief Updates the light matrices used for shadow mapping and lighting.
	  *  @param camera Reference to the active camera.
	  *  @param scene Reference to the render scene.
	*/
	void
		updateLightMatrices(const Camera& camera, const RenderScene& scene);

	/*
	  *  @brief Creates blend states for different material blending modes.
	  *  @param device Reference to the graphics device.
	  *  @return HRESULT indicating success or failure.
	*/
	HRESULT
		createBlendStates(Device& device);

	/*
	  *  @brief Resolves the appropriate blend state for a given material.
	  *  @param material Pointer to the material.
	  *  @return Pointer to the resolved blend state.
	*/
	ID3D11BlendState*
		resolveBlendState(const Material* material) const;

private:

	/*
	  *  @brief Constant buffer for per-frame data.
	*/
	Buffer m_perFrameBuffer;
	
	/*
	  *  @brief Constant buffer for per-object data.
	*/
	Buffer m_perObjectBuffer;

	/*
	  *  @brief Constant buffer for per-material data.
	*/
	Buffer m_perMaterialBuffer;

	
	/*
	  *  @brief Depth stencil state for transparent objects.
	*/
	DepthStencilState m_transparentDepthStencil;
	
	/*
	  *  @brief Blend state for alpha blending.
	*/
	ID3D11BlendState* m_alphaBlendState = nullptr;
	
	/*
	  *  @brief Blend state for opaque objects.
	*/
	ID3D11BlendState* m_opaqueBlendState = nullptr;
	
	/*
	  *  @brief Blend state for additive blending.
	*/
	ID3D11BlendState* m_additiveBlendState = nullptr;
	
	/*
	  *  @brief Blend state for premultiplied alpha blending.
	*/
	ID3D11BlendState* m_premultipliedBlendState = nullptr;
	
	/*
	  *  @brief Blend factor used for blending operations.
	*/
	float m_blendFactor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

	
	/*
	  *  @brief Texture used for shadow depth rendering.
	*/
	Texture m_shadowDepthTexture;

	/*
	  *  @brief Shader resource view for the shadow depth texture.
	*/
	Texture m_shadowDepthSRV;

	/*
	  *  @brief Depth stencil view for the shadow map.
	*/
	DepthStencilView m_shadowDSV;
	
	/*
	  *  @brief Shader program used for shadow rendering.
	*/
	ShaderProgram m_shadowShader;

	/*
	  *  @brief Rasterizer state for shadow rendering.
	*/
	RasterizerState m_shadowRasterizer;

	/*
	  *  @brief Size of the shadow map texture.
	*/
	unsigned int m_shadowMapSize = 2048;

	/*
	  *  @brief Editor viewport pass for pre-shadow debugging.
	*/
	EditorViewportPass m_preShadowDebugPass;

	/*
	  *  @brief Flag indicating whether shadows should be applied.
	*/
	bool m_applyShadows = true;


	
	/*
	  *  @brief Per-frame constant buffer data.
	*/
	CBPerFrame m_cbPerFrame{};

	/*
	  *  @brief Per-object constant buffer data.
	*/
	CBPerObject m_cbPerObject{};

	/*
	  *  @brief Per-material constant buffer data.
	*/
	CBPerMaterial m_cbPerMaterial{};

	/*
	  *  @brief Queue of opaque objects to render.
	*/
	std::vector<const RenderObject*> m_opaqueQueue;
	
	/*
	  *  @brief Queue of transparent objects to render.
	*/
	std::vector<const RenderObject*> m_transparentQueue;
};