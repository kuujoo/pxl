#pragma once
#include <cstdint>
#include <functional>
#include <string>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <assert.h>
#include <algorithm>

namespace pxl
{
	using Func = std::function<void()>;
	using string = std::string;

	template<class T>
	using vector = std::vector<T>;

	template<class T>
	using stack = std::stack<T>;

	template<class T>
	using deque = std::deque<T>;

	template<class T, class E>
	using map = std::map<T,E>;

	template<class T>
	using set = std::set<T>;

	template<class T>
	using unordered_set = std::unordered_set<T>;

	using i8 = int8_t;
	using i16 = int16_t;
	using i32 = int32_t;
	using i64 = int64_t;
	using u8 = uint8_t;
	using u16 = uint16_t;
	using u32 = uint32_t;
	using u64 = uint64_t;

	template<class T>
	string to_string(T v)
	{
		return std::to_string(v);
	}

	template<typename ... Args>
	string string_format(const string& format, Args ... args)
	{
		int size_s = std::snprintf(nullptr, 0, format.c_str(), args ...) + 1;
		if (size_s <= 0) {
			assert(0);
			return "";
		}
		auto size = static_cast<size_t>(size_s);
		auto buf = std::make_unique<char[]>(size);
		std::snprintf(buf.get(), size, format.c_str(), args ...);
		return string(buf.get(), buf.get() + size - 1);
	}

	template<class T>
	void remove_all(vector<T>& from, T value)
	{
		from.erase(std::remove(from.begin(), from.end(), value), from.end());
	}

	class Grid
	{
	public:
		Grid(int width, int height, i16 initialValue);
		Grid();
		~Grid();
		void set(int x, int y, i16 value);
		void set(int index, i16 value);
		void set(int fromx, int fromy, const Grid& otherGrid);
		void setAll(i16 value);
		i16 get(int x, int y) const;
		i16 get(int index) const;
		int width() const;
		int height() const;
	private:
		int _width;
		int _height;
		vector<i16> _data;
	};
}