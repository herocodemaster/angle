//
// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// DisplayD3D.h: D3D implementation of egl::Display

#ifndef LIBANGLE_RENDERER_D3D_DISPLAYD3D_H_
#define LIBANGLE_RENDERER_D3D_DISPLAYD3D_H_

#include "libANGLE/renderer/DisplayImpl.h"

namespace rx
{
class RendererD3D;

class DisplayD3D : public DisplayImpl
{
  public:
    DisplayD3D();

    egl::Error initialize(egl::Display *display) override;
    virtual void terminate() override;

    egl::Error createWindowSurface(const egl::Config *configuration, EGLNativeWindowType window, const egl::AttributeMap &attribs, bool allowRenderToBackBuffer,
                                   SurfaceImpl **outSurface) override;
    egl::Error createPbufferSurface(const egl::Config *configuration, const egl::AttributeMap &attribs,
                                    SurfaceImpl **outSurface) override;
    egl::Error createPbufferFromClientBuffer(const egl::Config *configuration, EGLClientBuffer shareHandle,
                                             const egl::AttributeMap &attribs, SurfaceImpl **outSurface) override;

    egl::Error createContext(const egl::Config *config, const gl::Context *shareContext, const egl::AttributeMap &attribs,
                             gl::Context **outContext) override;

    egl::Error makeCurrent(egl::Surface *drawSurface, egl::Surface *readSurface, gl::Context *context) override;

    egl::ConfigSet generateConfigs() const override;

    bool isDeviceLost() const override;
    bool testDeviceLost() override;
    egl::Error restoreLostDevice() override;

    bool isValidNativeWindow(EGLNativeWindowType window) const override;

    std::string getVendorString() const override;

  private:
    DISALLOW_COPY_AND_ASSIGN(DisplayD3D);

    void generateExtensions(egl::DisplayExtensions *outExtensions) const override;
    void generateCaps(egl::Caps *outCaps) const override;

    egl::Display *mDisplay;

    rx::RendererD3D *mRenderer;
};

}

#endif // LIBANGLE_RENDERER_D3D_DISPLAYD3D_H_