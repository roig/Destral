#pragma once

#include <glm/mat3x3.hpp>
#include <entt/entity/fwd.hpp>
#include <vector>
#include <sokol_gfx.h>

namespace ds {
	struct sprite {
		sg_image img;
	};
}

namespace ds::cp {
	/**
	* @brief Orthographic camera.
	*/
	struct camera {
		/** The viewport is the rectangle into which the contents of the
		* camera will be displayed, expressed as a factor (between 0 and 1)
		* of the size of the screen window to which the camera is applied.
		* By default, a view has a viewport which covers the entire screen:
		* vec4(0.0, 0.0, 1.0, 1.0)
		*
		* |      *(1,1)
		* |
		* |______
		* (0,0)
		*/
		glm::vec4 viewport = glm::vec4(0.f, 0.f, 1.f, 1.f);

		/** @brief color used when the camera clears their viewport */
		glm::vec4 clear_color = glm::vec4{ 0.5f, 0.5f, 0.5f, 1.0f };

		// half vertical size in world units
		float half_vsize = 360.0f;

		// aspect ratio of the camera, used to calculate the width, based on half_vsize
		float aspect = 16.0f / 9.0f;
	};

	struct line_rd {
		// List of Points of the line
		std::vector<glm::vec2> points;

		// Color of the line (green default)
		glm::vec4 color = {0,1,0,1};
	};

	struct rect_rd {
		glm::vec2 size = { 25.0f, 25.0f };
		glm::vec4 color = { 0.f,1.f,0.f,1.f };
		bool filled = true;
	};

	struct sprite_rd {
		// texture to draw
		sg_image texture = sg_image{ 0 };

		// sprite tint (white for texture color)
		glm::vec4 color = { 1,1,1,1 };
	};



}

namespace ds::rd {
	void init();
	void shutdown();
	void draw_all(entt::registry& r);

	sg_image create_image(const char* file_name);
}



//void ds_rd_draw_line(vec2 p0, vec2 position);
//void ds_rd_draw_sprite(SDL_Texture* texture);
//void ds_rd_draw();