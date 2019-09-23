# array-lite library

Resemble `std::array` for CUDA kernels.


## Dependencies

* [CMakeshift](https://github.com/mbeutel/CMakeshift)

## Bugs

This code is far away from being an optimal library. Thus
I am happy to read your issues.

### Quick Example

```cpp
__global__ void kernel(nonstd::array<int, 3> arr, int* ptr) {
  ptr[threadIdx.x] = arr[threadIdx.x % 3];
  ...
}
```

## License

### BSD 3-Clause License

Copyright (c) 2019, Christoph Klein  
All rights reserved.

Redistribution and use in source and binary forms, with or without  
modification, are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright  
    notice, this list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright  
    notice, this list of conditions and the following disclaimer in the  
    documentation and/or other materials provided with the distribution.
  * Neither the name of Christoph Klein nor the  
    names of its contributors may be used to endorse or promote products  
    derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND  
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  
DISCLAIMED. IN NO EVENT SHALL CHRISTOPH KLEIN BE LIABLE FOR ANY  
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
