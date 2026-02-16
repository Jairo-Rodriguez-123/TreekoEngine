#pragma once
#include "Prerequisites.h"
#include "ECS/Component.h"


class DeviceContext;
class Entity;

/*
  *  @brief Component that manages parent-child relationships in a scene graph.
*/
class
	HierarchyComponent : public Component {
public:
	/*
	  *  @brief Constructs a HierarchyComponent and sets its type.
	*/
	HierarchyComponent() : Component(ComponentType::HIERARCHY) {}
	/*
	  *  @brief Default destructor.
	*/
	~HierarchyComponent() = default;

	/*
	  *  @brief Initializes the component. No-op for HierarchyComponent.
	*/
	void
		init() override {}

	/*
	  *  @brief Updates the component. No-op for HierarchyComponent.
	  *  @param deltaTime Time elapsed since last update.
	*/
	void
		update(float) override {}

	/*
	  *  @brief Renders the component. No-op for HierarchyComponent.
	  *  @param deviceContext The device context used for rendering.
	*/
	void
		render(DeviceContext& deviceContext) override {}

	/*
	  *  @brief Destroys the component, clearing children and parent references.
	*/
	void
		destroy() override {
		m_children.clear();
		m_parent = nullptr;
	}

	// API SceneGraph
	/*
	  *  @brief Sets the parent entity of this component.
	  *  @param parent Pointer to the parent entity.
	*/
	void
		setParent(Entity* parent) {
		m_parent = parent;
	}

	/*
	  *  @brief Checks if this component is the root (has no parent).
	  *  @return True if root, false otherwise.
	*/
	bool
		isRoot() const {
		return m_parent == nullptr;
	}

	/*
	  *  @brief Checks if this component has any children.
	  *  @return True if it has children, false otherwise.
	*/
	bool
		hasChildren() const {
		return !m_children.empty();
	}

	/*
	  *  @brief Adds a child entity to this component.
	  *  @param child Pointer to the child entity.
	*/
	void
		addChild(Entity* child) {
		if (!child) {
			return;
		}

		if (std::find(m_children.begin(), m_children.end(), child) != m_children.end()) {
			return;
		}
		m_children.push_back(child);
	}

	/*
	  *  @brief Removes a child entity from this component.
	  *  @param child Pointer to the child entity.
	*/
	void
		removeChild(Entity* child) {
		if (!child) return;

		m_children.erase(
			std::remove(m_children.begin(), m_children.end(), child),
			m_children.end()
		);
	}

public:
	/*
	  *  @brief Pointer to the parent entity.
	*/
	Entity* m_parent = nullptr;
	/*
	  *  @brief List of pointers to child entities.
	*/
	std::vector<Entity*> m_children;
};