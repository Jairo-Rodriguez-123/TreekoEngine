#pragma once
#include "Prerequisites.h"

class Entity;
class DeviceContext;

/*
  *  @brief Manages a scene graph of entities, supporting hierarchy, update, and rendering.
*/
class
	SceneGraph {
public:
	/*
	  *  @brief Default constructor for SceneGraph.
	*/
	SceneGraph() = default;
	/*
	  *  @brief Default destructor for SceneGraph.
	*/
	~SceneGraph() = default;

	/*
	  *  @brief Initializes the scene graph.
	*/
	void
		init();

	/*
	  *  @brief Registers an entity in the scene graph.
	  *  @param e Pointer to the entity to add.
	*/
	void
		addEntity(Entity* e);  // registra en el grafo

	/*
	  *  @brief Removes an entity from the scene graph.
	  *  @param e Pointer to the entity to remove.
	*/
	void
		removeEntity(Entity* e);

	/*
	  *  @brief Checks if a given entity is an ancestor of another entity.
	  *  @param possibleAncestor Pointer to the possible ancestor entity.
	  *  @param node Pointer to the node entity.
	  *  @return True if possibleAncestor is an ancestor of node, false otherwise.
	*/
	bool
		isAncestor(Entity* possibleAncestor, Entity* node) const;

	/*
	  *  @brief Attaches a child entity to a parent entity in the scene graph.
	  *  @param child Pointer to the child entity.
	  *  @param parent Pointer to the parent entity.
	  *  @return True if the attachment was successful, false otherwise.
	*/
	bool
		attach(Entity* child, Entity* parent);

	/*
	  *  @brief Detaches a child entity from its parent in the scene graph.
	  *  @param child Pointer to the child entity.
	  *  @return True if the detachment was successful, false otherwise.
	*/
	bool
		detach(Entity* child);

	/*
	  *  @brief Updates all entities in the scene graph.
	  *  @param deltaTime Time elapsed since the last update.
	  *  @param deviceContext Reference to the device context.
	*/
	void
		update(float deltaTime, DeviceContext& deviceContext);

	/*
	  *  @brief Renders all entities in the scene graph.
	  *  @param deviceContext Reference to the device context.
	*/
	void
		render(DeviceContext& deviceContext);

	/*
	  *  @brief Destroys the scene graph and releases resources.
	*/
	void
		destroy();
private:
	/*
	  *  @brief Recursively updates the world transform of an entity and its children.
	  *  @param node Pointer to the current entity node.
	  *  @param parentWorld Parent's world transformation matrix.
	*/
	void
		updateWorldRecursive(Entity* node, const XMMATRIX& parentWorld);

	/*
	  *  @brief Checks if an entity is a root node in the scene graph.
	  *  @param e Pointer to the entity.
	  *  @return True if the entity is a root, false otherwise.
	*/
	bool
		isRoot(Entity* e) const;

	/*
	  *  @brief Checks if an entity is registered in the scene graph.
	  *  @param e Pointer to the entity.
	  *  @return True if the entity is registered, false otherwise.
	*/
	bool
		isRegistered(Entity* e) const;

private:
	//std::vector<EU::TSharedPointer<Entity>> m_entities;
public:
	/*
	  *  @brief List of pointers to all entities registered in the scene graph.
	*/
	std::vector<Entity*> m_entities;
};