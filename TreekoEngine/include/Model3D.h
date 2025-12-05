#pragma once
#include "Prerequisites.h"
#include "IResource.h"
#include "MeshComponent.h"
#include "fbxsdk.h"

/*
  *  @brief Enum representing the type of 3D model (OBJ or FBX).
*/
enum
ModelType {
	OBJ,
	FBX
};

/*
  *  @brief Class representing a 3D model resource, supporting OBJ and FBX formats.
*/
class
Model3D : public IResource {
public:
	/*
   *  @brief Constructs a Model3D resource with a given name and model type.
   *  @param name Name of the model resource.
   *  @param modelType Type of the model (OBJ or FBX).
	*/
	Model3D(const std::string& name, ModelType modelType)
		: IResource(name), m_modelType(modelType), lSdkManager(nullptr), lScene(nullptr) {
		SetType(ResourceType::Model3D);
		load(name);
	}

	/*
   *  @brief Default destructor for Model3D.
	*/
	~Model3D() = default;

	/*
   *  @brief Loads the model resource from the specified path.
   *  @param path Path to the model file.
   *  @return True if loading was successful, false otherwise.
	*/
	bool
		load(const std::string& path) override;

	/*
   *  @brief Initializes the model resource (e.g., GPU resource creation).
   *  @return True if initialization was successful.
	*/
	bool
		init() override;

	/*
   *  @brief Unloads the model resource and releases memory.
	*/
	void
		unload() override;

	/*
   *  @brief Returns the size of the model resource in bytes.
   *  @return Size in bytes.
	*/
	size_t
		getSizeInBytes() const override;

	/*
   *  @brief Gets the list of mesh components associated with this model.
   *  @return Const reference to the vector of MeshComponent.
	*/
	const std::vector<MeshComponent>&
		GetMeshes() const { return m_meshes; }

	/* FBX MODEL LOADER*/

	/*
   *  @brief Initializes the FBX SDK manager.
   *  @return True if initialization was successful.
	*/
	bool
		InitializeFBXManager();

	/*
   *  @brief Loads an FBX model from the specified file path.
   *  @param filePath Path to the FBX file.
   *  @return Vector of MeshComponent loaded from the FBX file.
	*/
	std::vector<MeshComponent>
		LoadFBXModel(const std::string& filePath);

	/*
   *  @brief Processes an FBX node recursively to extract mesh and material data.
   *  @param node Pointer to the FBX node to process.
	*/
	void
		ProcessFBXNode(FbxNode* node);

	/*
   *  @brief Processes an FBX node to extract mesh data.
   *  @param node Pointer to the FBX node containing mesh data.
	*/
	void
		ProcessFBXMesh(FbxNode* node);

	/*
   *  @brief Processes an FBX material to extract texture and material properties.
   *  @param material Pointer to the FBX surface material.
	*/
	void
		ProcessFBXMaterials(FbxSurfaceMaterial* material);

	/*
   *  @brief Gets the list of texture file names used by the model.
   *  @return Vector of texture file names.
	*/
	std::vector<std::string>
		GetTextureFileNames() const { return textureFileNames; }
private:
	/*
   *  @brief Pointer to the FBX SDK manager.
	*/
	FbxManager* lSdkManager;
	/*
   *  @brief Pointer to the FBX scene.
	*/
	FbxScene* lScene;
	/*
   *  @brief List of texture file names used by the model.
	*/
	std::vector<std::string> textureFileNames;
public:
	/*
   *  @brief Type of the model (OBJ or FBX).
	*/
	ModelType m_modelType;
	/*
   *  @brief List of mesh components that make up the model.
	*/
	std::vector<MeshComponent> m_meshes;
};