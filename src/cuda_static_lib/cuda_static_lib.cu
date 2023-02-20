#include "cuda_static_lib.cuh"

#define CHECK(res) { if(res != cudaSuccess){printf("Error ：%s:%d , ", __FILE__,__LINE__);   \
                    printf("code : %d , reason : %s \n", res,cudaGetErrorString(res));exit(-1);}}

__global__ void foo()
{int i = blockIdx.x;
    int j = blockIdx.y;
    int m = threadIdx.x;
    int n = threadIdx.y;
    printf("hello CUDA static %d, %d, %d, %d!\n", i, j, m, n);
}

void useCUDA_static()
{
    dim3 gridShape = dim3(10, 10); // blocks / grid
    dim3 blockShape = dim3(4, 4); // threads / block
    foo<<<gridShape, blockShape>>>();
    CHECK(cudaDeviceSynchronize());
}