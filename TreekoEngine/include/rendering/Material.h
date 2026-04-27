#pragma once
#include "Prerequisites.h"
#include "Rendering/RenderTypes.h"

class ShaderProgram;
class RasterizerState;
class DepthStencilState;
class SamplerState;


class
	Material {
public:

	/*
	  *  @brief Sets the shader program for this material.
	*/
	void
		setShader(ShaderProgram* shader) { m_shader = shader; }

	
	/*
	  *  @brief Sets the rasterizer state for this material.
	*/
	void
		setRasterizerState(RasterizerState* state) { m_rasterizerState = state; }

	
	/*
	  *  @brief Sets the depth stencil state for this material.
	*/
	void
		setDepthStencilState(DepthStencilState* state) { m_depthStencilState = state; }

	
	/*
	  *  @brief Sets the sampler state for this material.
	*/
	void
		setSamplerState(SamplerState* state) { m_samplerState = state; }

	
	/*
	  *  @brief Sets the material domain.
	*/
	void
		setDomain(MaterialDomain domain) { m_domain = domain; }

	
	/*
	  *  @brief Sets the blend mode for this material.
	*/
	void
		setBlendMode(BlendMode blendMode) { m_blendMode = blendMode; }

	
	/*
	  *  @brief Gets the shader program associated with this material.
	*/
	ShaderProgram*
		getShader() const { return m_shader; }

	
	/*
	  *  @brief Gets the rasterizer state associated with this material.
	*/
	RasterizerState*
		getRasterizerState() const { return m_rasterizerState; }

	
	/*
	  *  @brief Gets the depth stencil state associated with this material.
	*/
	DepthStencilState*
		getDepthStencilState() const { return m_depthStencilState; }

	
	/*
	  *  @brief Gets the sampler state associated with this material.
	*/
	SamplerState*
		getSamplerState() const { return m_samplerState; }

	
	/*
	  *  @brief Gets the material domain.
	*/
	MaterialDomain
		getDomain() const { return m_domain; }

	/*
	  *  @brief Gets the blend mode for this material.
	*/
	BlendMode
		getBlendMode() const { return m_blendMode; }

private:
	
	/*
	  *  @brief The shader program used by this material.
	*/
	ShaderProgram* m_shader = nullptr;


	/*
	  *  @brief The rasterizer state used by this material.
	*/
	RasterizerState* m_rasterizerState = nullptr;

	
	/*
	  *  @brief The depth stencil state used by this material.
	*/
	DepthStencilState* m_depthStencilState = nullptr;


	/*
	  *  @brief The sampler state used by this material.
	*/
	SamplerState* m_samplerState = nullptr;


	/*
	  *  @brief The domain of the material (e.g., Opaque, Transparent).
	*/
	MaterialDomain m_domain = MaterialDomain::Opaque;

	/*
	  *  @brief The blend mode of the material.
	*/
	BlendMode m_blendMode = BlendMode::Opaque;
};