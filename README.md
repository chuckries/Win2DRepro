# Win2DRepro

Repro for a win2d issue. Vector (float2, float3, etc.) values cannot be set on a pixel shader effect using Windows::Foundation::Numerics::float2. 
I am not sure if this is a bug or if I need to set the property in a different way.

Repro Steps:
1. Open Win2DRepro.sln in Visual Studio 2015. 
2. Change configuration to x86 Debug and Start Debugging.
3. Breakpoint will be hit in catch block of CreateResourcesAsync, indicating an error setting the "myFloat2" property of the PixelShaderEffect.
