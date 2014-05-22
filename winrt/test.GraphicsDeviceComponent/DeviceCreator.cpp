// Copyright (c) Microsoft Corporation.  All rights reserved

#include "pch.h"

namespace GraphicsDeviceComponent
{
    using namespace Microsoft::Graphics::Canvas;

    public ref class DeviceCreator sealed
    {
    public:
        static DirectX11Device^ CreateDevice()
        {
            using namespace Microsoft::WRL;

            ComPtr<ID3D11Device> d3dDevice;

            ThrowIfFailed(D3D11CreateDevice(
                nullptr,            // adapter
                D3D_DRIVER_TYPE_WARP,
                nullptr,            // software
                D3D11_CREATE_DEVICE_DEBUG,
                nullptr,            // feature levels
                0,                  // feature levels count
                D3D11_SDK_VERSION,
                &d3dDevice,
                nullptr,        // feature level
                nullptr));      // immediate context

            ComPtr<IDXGIDevice> dxgiDevice;
            ThrowIfFailed(d3dDevice.As(&dxgiDevice));
            return CreateDirectX11Device(dxgiDevice.Get());
        }
    };
}
