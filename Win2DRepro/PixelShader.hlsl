#define D2D_INPUT_COUNT 2
#define D2D_INPUT0_COMPLEX
#define D2D_INPUT1_COMPLEX

#include "d2d1effecthelpers.hlsli"

float2 myFloat2;

D2D_PS_ENTRY(main)
{
    return float4(myFloat2, 1.0, 1.0);
}