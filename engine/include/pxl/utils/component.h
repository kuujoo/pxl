#pragma once
#include <pxl/types.h>

namespace pxl
{
	class Scene;
	class Entity;

	class IUpdateable
	{
	public:
		virtual void update() = 0;
		virtual i16 updateOrder() const { return 0; }
	};
	
	class Batch;
	class IDrawable
	{
	public:
		virtual void draw(Batch &batch) = 0;
		virtual i16 drawOrder() const { return 0; }
	};

	class IDebugDrawable
	{
	public:
		virtual void debugDraw(Batch& batch) = 0;
		virtual i16 drawOrder() const { return 0; }
	};

	class Component
	{
	public:
		Component();
		virtual ~Component() {}
		virtual void awake() {};
		template<class T>
		T* get();
		template<class T>
		const T* get() const;
		u16 typeId() const;
		virtual void destroyed() {}
		Entity* entity() const;
	private:
		u16 _typeId;
		Entity* _entity;

		friend class Scene;

		//
		static u16 s_type_counter;
		template<class T>
		static u16 findTypeId()
		{
			static const u16 type_id = s_type_counter++;
			assert(type_id < s_max_component_types);
			return type_id;
		}
	};

	template<class T>
	T* Component::get()
	{
		assert(_entity);
		return _entity->get<T>();
	}

	template<class T>
	const T* Component::get() const
	{
		assert(_entity);
		return _entity->get<T>();
	}
}