#pragma once
#ifndef NONSTD_ARRAY_LITE
#define NONSTD_ARRAY_LITE

#ifdef __CUDACC__
#define NONSTD_ARRAY_LITE_HOST_DEVICE_FUNCTION __host__ __device__
#else
#define NONSTD_ARRAY_LITE_HOST_DEVICE_FUNCTION
#endif

#include <array>
#include <initializer_list>
#include <stdexcept>

namespace nonstd {

template <typename T, size_t N>
class array {

   public:
	using value_type = T;
	using reference = value_type&;
	using const_reference = const value_type&;
	using pointer = value_type*;
	using const_pointer = const value_type*;
	using size_type = size_t;
	using difference_type = ptrdiff_t;

	NONSTD_ARRAY_LITE_HOST_DEVICE_FUNCTION
	array() {
		for (size_t i = 0; i < N; ++i) {
			values[i] = T();
		}
	};

	array(const std::array<T, N>& other) {
		// Probably the compiler is smart enough to unroll this loop.
		// Alternatively std::index_sequence can be used here.
		for (size_t i = 0; i < N; ++i) {
			values[i] = other[i];
		}
	}

	NONSTD_ARRAY_LITE_HOST_DEVICE_FUNCTION
	constexpr array(std::initializer_list<T>&& l) {
		// TODO: check size of initializer list somehow at compile time.
		// How is std::vector doing this?
		//static_assert(l.size() == N);
		size_t i = 0;
#ifndef __CUDA_ARCH__
		if (l.size() != N) {
			throw std::out_of_range(
			    "size of initializer list unequal to nonstd::array size");
		}
		using std::move;
		for (auto& e : l) {
			values[i] = move(e);
			++i;
		}
#else
		assert(l.size() == N);
		for (auto& e : l) {
			values[i] = e;
			++i;
		}
#endif
	}

	NONSTD_ARRAY_LITE_HOST_DEVICE_FUNCTION
	constexpr pointer begin() noexcept {
		return values;
	}

	NONSTD_ARRAY_LITE_HOST_DEVICE_FUNCTION
	constexpr pointer end() noexcept {
		return values + N;
	}

	NONSTD_ARRAY_LITE_HOST_DEVICE_FUNCTION
	constexpr const_pointer begin() const noexcept {
		return values;
	}

	NONSTD_ARRAY_LITE_HOST_DEVICE_FUNCTION
	constexpr const_pointer end() const noexcept {
		return values + N;
	}

	NONSTD_ARRAY_LITE_HOST_DEVICE_FUNCTION
	constexpr size_t size() const noexcept {
		return N;
	}

	NONSTD_ARRAY_LITE_HOST_DEVICE_FUNCTION
	const T& operator[](size_t i) const noexcept {
		return values[i];
	}

	NONSTD_ARRAY_LITE_HOST_DEVICE_FUNCTION
	T& operator[](size_t i) noexcept {
		return values[i];
	}

   private:
	T values[N];
};

} // namespace nonstd

#endif
