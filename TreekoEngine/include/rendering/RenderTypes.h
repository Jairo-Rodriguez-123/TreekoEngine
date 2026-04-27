#pragma once
#include "Prerequisites.h"

/*
  *  @brief Forward declaration of Mesh class.
*/
class Mesh;
/*
  *  @brief Forward declaration of MaterialInstance class.
*/
class MaterialInstance;

/*
  *  @brief Specifies the domain of a material (opaque, masked, transparent).
*/
enum class
	MaterialDomain {
	/*
	  *  @brief Opaque material domain.
	*/
	Opaque = 0,
	/*
	  *  @brief Masked material domain.
	*/
	Masked,
	/*
	  *  @brief Transparent material domain.
	*/
	Transparent
};

/*
  *  @brief Specifies the blend mode for materials.
*/
enum class
	BlendMode {
	/*
	  *  @brief Opaque blend mode.
	*/
	Opaque = 0,             
	/*
	  *  @brief Alpha blend mode.
	*/
	Alpha,                  
	/*
	  *  @brief Additive blend mode.
	*/
	Additive,               
	/*
	  *  @brief Premultiplied alpha blend mode.
	*/
	PremultipliedAlpha      
};

/*
  *  @brief Specifies the type of render pass.
*/
enum class
	RenderPassType {
	/*
	  *  @brief Shadow pass.
	*/
	Shadow = 0,    
	/*
	  *  @brief Opaque pass.
	*/
	Opaque,        
	/*
	  *  @brief Skybox pass.
	*/
	Skybox,        
	/*
	  *  @brief Transparent pass.
	*/
	Transparent,   
	/*
	  *  @brief Editor pass.
	*/
	Editor         
};

/*
  *  @brief Specifies the type of light.
*/
enum class
	LightType {
	/*
	  *  @brief Directional light.
	*/
	Directional = 0, 
	/*
	  *  @brief Point light.
	*/
	Point,           
	/*
	  *  @brief Spot light.
	*/
	Spot             
};

/*
  *  @brief Stores data for a light source.
*/
struct
	LightData {
	/*
	  *  @brief Type of the light.
	*/
	LightType type = LightType::Directional;
	/*
	  *  @brief Color of the light.
	*/
	EU::Vector3 color = EU::Vector3(1.0f, 1.0f, 1.0f);
	/*
	  *  @brief Intensity of the light.
	*/
	float intensity = 1.0f;

	/*
	  *  @brief Direction of the light (for directional and spot lights).
	*/
	EU::Vector3 direction = EU::Vector3(0.0f, -1.0f, 0.0f);
	/*
	  *  @brief Range of the light (for point and spot lights).
	*/
	float range = 0.0f;

	/*
	  *  @brief Position of the light (for point and spot lights).
	*/
	EU::Vector3 position = EU::Vector3(0.0f, 0.0f, 0.0f);
	/*
	  *  @brief Spot angle (for spot lights).
	*/
	float spotAngle = 0.0f;
};

/*
  *  @brief Stores material parameter values.
*/
struct
	MaterialParams {
	/*
	  *  @brief Base color of the material.
	*/
	XMFLOAT4 baseColor = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	/*
	  *  @brief Metallic value of the material.
	*/
	float metallic = 1.0f;
	/*
	  *  @brief Roughness value of the material.
	*/
	float roughness = 1.0f;
	/*
	  *  @brief Ambient occlusion value.
	*/
	float ao = 1.0f;
	/*
	  *  @brief Normal map scale.
	*/
	float normalScale = 1.0f;
	/*
	  *  @brief Emissive strength.
	*/
	float emissiveStrength = 1.0f;
	/*
	  *  @brief Alpha cutoff threshold.
	*/
	float alphaCutoff = 0.5f;
};

/*
  *  @brief Stores per-frame constant buffer data.
*/
struct
	CBPerFrame {
	/*
	  *  @brief View matrix.
	*/
	XMFLOAT4X4 View{};
	/*
	  *  @brief Projection matrix.
	*/
	XMFLOAT4X4 Projection{};
	/*
	  *  @brief Light view-projection matrix.
	*/
	XMFLOAT4X4 LightViewProjection{};

	/*
	  *  @brief Camera position.
	*/
	EU::Vector3 CameraPos{};
	/*
	  *  @brief Padding for alignment.
	*/
	float pad0 = 0.0f; 

	/*
	  *  @brief Light direction.
	*/
	EU::Vector3 LightDir = EU::Vector3(0.0f, -1.0f, 0.0f);
	/*
	  *  @brief Padding for alignment.
	*/
	float pad1 = 0.0f; 

	/*
	  *  @brief Light color.
	*/
	EU::Vector3 LightColor = EU::Vector3(1.0f, 1.0f, 1.0f);
	/*
	  *  @brief Padding for alignment.
	*/
	float pad2 = 0.0f; 
};

/*
  *  @brief Stores per-object constant buffer data.
*/
struct
	CBPerObject {
	/*
	  *  @brief World matrix.
	*/
	XMFLOAT4X4 World{}; 
};

/*
  *  @brief Stores per-material constant buffer data.
*/
struct
	CBPerMaterial {
	/*
	  *  @brief Base color of the material.
	*/
	XMFLOAT4 BaseColor = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f); 

	/*
	  *  @brief Metallic value.
	*/
	float Metallic = 1.0f;
	/*
	  *  @brief Roughness value.
	*/
	float Roughness = 1.0f;
	/*
	  *  @brief Ambient occlusion value.
	*/
	float AO = 1.0f;
	/*
	  *  @brief Normal map scale.
	*/
	float NormalScale = 1.0f;
	/*
	  *  @brief Emissive strength.
	*/
	float EmissiveStrength = 1.0f;
	/*
	  *  @brief Alpha cutoff threshold.
	*/
	float AlphaCutoff = 0.0f;

	/*
	  *  @brief Padding for alignment.
	*/
	float pad0 = 0.0f;
	/*
	  *  @brief Padding for alignment.
	*/
	float pad1 = 0.0f;
	/*
	  *  @brief Padding for alignment.
	*/
	float pad2 = 0.0f;
	/*
	  *  @brief Padding for alignment.
	*/
	float pad3 = 0.0f;
	/*
	  *  @brief Padding for alignment.
	*/
	float pad4 = 0.0f;
	/*
	  *  @brief Padding for alignment.
	*/
	float pad5 = 0.0f;
};

/*
  *  @brief Represents a renderable object in the scene.
*/
struct
	RenderObject {
	/*
	  *  @brief Pointer to the mesh.
	*/
	Mesh* mesh = nullptr;                               
	/*
	  *  @brief Pointer to the primary material instance.
	*/
	MaterialInstance* materialInstance = nullptr;       
	/*
	  *  @brief List of material instances for the mesh.
	*/
	std::vector<MaterialInstance*> materialInstances;   
	/*
	  *  @brief World transformation matrix.
	*/
	XMMATRIX world = XMMatrixIdentity();                
	/*
	  *  @brief Indicates if the object casts shadows.
	*/
	bool castShadow = true;                             
	/*
	  *  @brief Indicates if the object is transparent.
	*/
	bool transparent = false;                           
	/*
	  *  @brief Distance from the camera.
	*/
	float distanceToCamera = 0.0f;                      
};
