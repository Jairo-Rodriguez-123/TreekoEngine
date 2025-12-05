#pragma once
#include "Prerequisites.h"

/*
 *  @brief Enum representing the type of resource.
 */
enum class
ResourceType {
	Unknown,
	Model3D,
	Texture,
	Sound,
	Shader,
	Material
};

/*
 *  @brief Enum representing the state of a resource.
 */
enum class
ResourceState {
	Unloaded,
	Loading,
	Loaded,
	Failed
};

/*
 *  @brief Interface for resources managed by the engine.
 */
class IResource {
public:
	/*
  *  @brief Constructs a resource with a given name.
  *  @param name Name of the resource.
  */
	IResource(const std::string& name)
		: m_name(name)
		, m_filePath("")
		, m_type(ResourceType::Unknown)
		, m_state(ResourceState::Unloaded)
		, m_id(GenerateID())
	{
	}
	/*
  *  @brief Virtual destructor for IResource.
  */
	virtual ~IResource() = default;

	/*
  *  @brief Creates the GPU resource.
  *  @return True if initialization was successful.
  */
	virtual bool init() = 0;
	/*
  *  @brief Loads the resource from disk.
  *  @param filename Path to the file to load.
  *  @return True if loading was successful.
  */
	virtual bool load(const std::string& filename) = 0;
	/*
  *  @brief Releases the memory used by the resource.
  */
	virtual void unload() = 0;
	/*
  *  @brief Returns the size of the resource in bytes (for profiling).
  *  @return Size in bytes.
  */
	virtual size_t getSizeInBytes() const = 0;

	/*
  *  @brief Sets the file path of the resource.
  *  @param path File path.
  */
	void SetPath(const std::string& path) { m_filePath = path; }
	/*
  *  @brief Sets the type of the resource.
  *  @param t Resource type.
  */
	void SetType(ResourceType t) { m_type = t; }
	/*
  *  @brief Sets the state of the resource.
  *  @param s Resource state.
  */
	void SetState(ResourceState s) { m_state = s; }


	/*
  *  @brief Gets the name of the resource.
  *  @return Resource name.
  */
	const std::string& GetName() const { return m_name; }
	/*
  *  @brief Gets the file path of the resource.
  *  @return File path.
  */
	const std::string& GetPath() const { return m_filePath; }
	/*
  *  @brief Gets the type of the resource.
  *  @return Resource type.
  */
	ResourceType GetType() const { return m_type; }
	/*
  *  @brief Gets the state of the resource.
  *  @return Resource state.
  */
	ResourceState GetState() const { return m_state; }
	/*
  *  @brief Gets the unique ID of the resource.
  *  @return Resource ID.
  */
	uint64_t GetID() const { return m_id; }

protected:
	/*
  *  @brief Name of the resource.
  */
	std::string m_name;
	/*
  *  @brief File path of the resource.
  */
	std::string m_filePath;
	/*
  *  @brief Type of the resource.
  */
	ResourceType m_type;
	/*
  *  @brief State of the resource.
  */
	ResourceState m_state;
	/*
  *  @brief Unique identifier for the resource.
  */
	uint64_t m_id;

private:
	/*
  *  @brief Generates a unique ID for each resource.
  *  @return Unique resource ID.
  */
	static uint64_t GenerateID()
	{
		static uint64_t nextID = 1;
		return nextID++;
	}
};