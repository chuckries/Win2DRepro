//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <WindowsNumerics.h>

using namespace Win2DRepro;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

using namespace Microsoft::Graphics::Canvas;
using namespace Microsoft::Graphics::Canvas::Effects;
using namespace Microsoft::Graphics::Canvas::UI;
using namespace Microsoft::Graphics::Canvas::UI::Xaml;

using namespace concurrency;

using namespace Windows;
using namespace Windows::Storage;
using namespace Windows::Storage::Streams;

using namespace Windows::Foundation::Numerics;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
}


void Win2DRepro::MainPage::CanvasControl_CreateResources(Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl^ sender, Microsoft::Graphics::Canvas::UI::CanvasCreateResourcesEventArgs^ args)
{
    args->TrackAsyncAction(CanvasControl_CreateResourcesAsync(sender, args));
}

IAsyncAction^ Win2DRepro::MainPage::CanvasControl_CreateResourcesAsync(CanvasControl^ sender, CanvasCreateResourcesEventArgs^ args)
{
    return create_async([=]()
    {
        auto openFileOp = ApplicationModel::Package::Current->InstalledLocation->GetFileAsync("PixelShader.bin");

        return create_task(openFileOp).then([=](StorageFile^ file)
        {
            return FileIO::ReadBufferAsync(file);
        }).then([=](IBuffer^ buffer)
        {
            DataReader^ reader = DataReader::FromBuffer(buffer);

            auto bytes = ref new Array<byte>(buffer->Length);
            reader->ReadBytes(bytes);

            _effect = ref new PixelShaderEffect(bytes);
            _effect->Properties->Insert("myFloat2", float2(0.5, 0.5));
        }).then([=](task<void> t)
        {
            try
            {
                t.get();
            }
            catch (COMException^ e)
            {
                OutputDebugString(e->Message->Data());
                __debugbreak();
            }
        });
    });
}

void Win2DRepro::MainPage::CanvasControl_Draw(Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs^ args)
{
    args->DrawingSession->DrawImage(_effect);
}
