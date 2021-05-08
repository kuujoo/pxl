#pragma once

#include <pxl/types.h>
#include <functional>
#include <pxl/config.h>
#include <pxl/platforms/platform_backend.h>
#include <pxl/graphics/graphics_backend.h>
#include <pxl/input/gamepad_backend.h>
#include <pxl/input/keyboard_backend.h>
#include <pxl/input/mouse_backend.h>
#include <pxl/utils/input_binding.h>

namespace pxl
{
	class Engine
	{
	public:
		static Engine& instance();
		void start(const Config& config);
		GraphicsBackend& graphics();
		PlatformBackend& platform();
		GamepadsBackend& gamepads();
		KeyboardBackend& keyboard();
		MouseBackend& mouse();
		Vec2 drawSize() const;
		Vec2 size() const;
		void end();
	private:
		Engine();
		void inputUpdate();
		PlatformBackend _platform;
		GraphicsBackend _graphics;
		GamepadsBackend _gamepads;
		KeyboardBackend _keyboard;
		MouseBackend _mouse;
	};

	Engine& engine();
	GraphicsBackend& graphics();
	PlatformBackend& platform();
	GamepadsBackend& gamepads();
	KeyboardBackend& keyboard();
	MouseBackend& mouse();
}