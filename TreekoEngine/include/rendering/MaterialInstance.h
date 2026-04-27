#pragma once
#include "Prerequisites.h"
#include "Rendering/RenderTypes.h"

	class Material;
class DeviceContext;
class Texture;

/*
  *  @brief Represents an instance of a material with its associated textures and parameters.
*/
class
	MaterialInstance {
public:
	
	/*
	  *  @brief Sets the material for this instance.
	*/
	void
		setMaterial(Material* material) { m_material = material; }

	/*
	  *  @brief Sets the albedo texture.
	*/
	void
		setAlbedo(Texture* texture) { m_albedo = texture; }

	/*
	  *  @brief Sets the normal texture.
	*/
	void
		setNormal(Texture* texture) { m_normal = texture; }

	/*
	  *  @brief Sets the metallic texture.
	*/
	void
		setMetallic(Texture* texture) { m_metallic = texture; }

	/*
	  *  @brief Sets the roughness texture.
	*/
	void
		setRoughness(Texture* texture) { m_roughness = texture; }

	/*
	  *  @brief Sets the ambient occlusion (AO) texture.
	*/
	void
		setAO(Texture* texture) { m_ao = texture; }

	/*
	  *  @brief Sets the emissive texture.
	*/
	void
		setEmissive(Texture* texture) { m_emissive = texture; }

	
	/*
	  *  @brief Gets the material associated with this instance.
	*/
	Material*
		getMaterial() const { return m_material; }

	
	/*
	  *  @brief Gets the albedo texture.
	*/
	Texture*
		getAlbedo() const { return m_albedo; }

	/*
	  *  @brief Gets the normal texture.
	*/
	Texture*
		getNormal() const { return m_normal; }

	
	/*
	  *  @brief Gets the metallic texture.
	*/
	Texture*
		getMetallic() const { return m_metallic; }

	
	/*
	  *  @brief Gets the roughness texture.
	*/
	Texture*
		getRoughness() const { return m_roughness; }

	/*
	  *  @brief Gets the ambient occlusion (AO) texture.
	*/
	Texture*
		getAO() const { return m_ao; }

	/*
	  *  @brief Gets the emissive texture.
	*/
	Texture*
		getEmissive() const { return m_emissive; }

	/*
	  *  @brief Gets the material parameters.
	*/
	MaterialParams&
		getParams() { return m_params; }

	/*
	  *  @brief Gets the material parameters (const version).
	*/
	const MaterialParams&
		getParams() const { return m_params; }

	/*
	  *  @brief Binds the textures to the given device context.
	*/
	void
		bindTextures(DeviceContext& deviceContext) const;

private:
	
	/*
	  *  @brief Pointer to the material.
	*/
	Material* m_material = nullptr;

	/*
	  *  @brief Pointer to the albedo texture.
	*/
	Texture* m_albedo = nullptr;

	/*
	  *  @brief Pointer to the normal texture.
	*/
	Texture* m_normal = nullptr;

	/*
	  *  @brief Pointer to the metallic texture.
	*/
	Texture* m_metallic = nullptr;

	/*
	  *  @brief Pointer to the roughness texture.
	*/
	Texture* m_roughness = nullptr;

	/*
	  *  @brief Pointer to the ambient occlusion (AO) texture.
	*/
	Texture* m_ao = nullptr;

	/*
	  *  @brief Pointer to the emissive texture.
	*/
	Texture* m_emissive = nullptr;

	/*
	  *  @brief Material parameters for this instance.
	*/
	MaterialParams m_params;
};
