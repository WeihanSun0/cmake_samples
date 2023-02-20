#include <cuda_runtime.h>
#include <device_launch_parameters.h>

#include <stdio.h>

__global__ void test(void)
{
    int i = blockIdx.x;
    int j = blockIdx.y;
    int m = threadIdx.x;
    int n = threadIdx.y;
    printf("hello CUDA %d, %d, %d, %d!\n", i, j, m, n);
}

int main()
{
    dim3 gridShape = dim3(10, 10); // blocks / grid
    dim3 blockShape = dim3(4, 4); // threads / block
    test<<<gridShape, blockShape>>>();
    cudaDeviceSynchronize();
    return 0;
}