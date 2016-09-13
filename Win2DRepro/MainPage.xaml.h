//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace Win2DRepro
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

    private:
        void CanvasControl_CreateResources(Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl^ sender, Microsoft::Graphics::Canvas::UI::CanvasCreateResourcesEventArgs^ args);
        Windows::Foundation::IAsyncAction^ CanvasControl_CreateResourcesAsync(Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl^ sender, Microsoft::Graphics::Canvas::UI::CanvasCreateResourcesEventArgs^ args);
        void CanvasControl_Draw(Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs^ args);

        Microsoft::Graphics::Canvas::Effects::PixelShaderEffect^ _effect;
    };
}
