#pragma once
#include "Prerequisites.h"
#include "Buffer.h"
	

struct
	/*
	  *  @brief Represents a submesh containing vertex and index buffers, index count, start index, and material slot.
	*/
	Submesh {
		/*
		  *  @brief Vertex buffer for the submesh.
		*/
		Buffer vertexBuffer;          
		/*
		  *  @brief Index buffer for the submesh.
		*/
		Buffer indexBuffer;           
		/*
		  *  @brief Number of indices in the submesh.
		*/
		unsigned int indexCount = 0;  
		/*
		  *  @brief Starting index in the index buffer.
		*/
		unsigned int startIndex = 0;  
		/*
		  *  @brief Material slot index for the submesh.
		*/
		unsigned int materialSlot = 0;
	};


class
	/*
	  *  @brief Represents a mesh composed of multiple submeshes.
	*/
	Mesh {
public:
	
		/*
		  *  @brief Returns a reference to the vector of submeshes.
		  *  @return Reference to the vector of submeshes.
		*/
		std::vector<Submesh>&
			getSubmeshes() { return m_submeshes; }


		/*
		  *  @brief Returns a const reference to the vector of submeshes.
		  *  @return Const reference to the vector of submeshes.
		*/
		const std::vector<Submesh>&
			getSubmeshes() const { return m_submeshes; }

		/*
		  *  @brief Destroys all submeshes and clears the submesh vector.
		*/
		void
			destroy() {
			for (Submesh& submesh : m_submeshes) {
				submesh.vertexBuffer.destroy();
				submesh.indexBuffer.destroy();
			}

			m_submeshes.clear();
		}

private:

		/*
		  *  @brief Vector containing all submeshes of the mesh.
		*/
		std::vector<Submesh> m_submeshes;
	};