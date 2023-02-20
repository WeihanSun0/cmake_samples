#include <iostream>
#include "cuda_static_lib.cuh"
#include "cuda_share_lib.cuh"

using namespace std;

// extern "C" void useCUDA();

int main(void)
{
    cout << "---------call static cuda lib------------" << endl;
    useCUDA_static();
    cout << "---------finish static cuda lib------------" << endl;
    cout << "---------call share cuda lib------------" << endl;
    useCUDA_share();
    cout << "---------finish share cuda lib------------" << endl;
    return 0;
}