#include <nonstd/array.h>
#include <array>

#include <iostream>
#include <cstdio>

__global__ void kernel(nonstd::array<float, 3> arr) {
	for (auto& e : arr) {
		printf("e = %f\n", e);
	}

	nonstd::array<float, 3> other;
	other = nonstd::array<float, 3>({10, 11, 12});
	printf("other = %f %f %f\n", other[0], other[1], other[2]);
}

int main() {


	nonstd::array<int, 2> defconstr;

	nonstd::array<float, 3> arr = {1, 2, 3};
	nonstd::array<float, 3> abc({8, 9, 10});
	std::array<float, 3> stdarr = {8, 9, 10};
	kernel<<<1,1>>>(arr);
	cudaDeviceSynchronize();

	// compatible with std::array
	arr = stdarr;
}
