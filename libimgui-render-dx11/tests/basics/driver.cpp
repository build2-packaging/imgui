// Smoke test: every entry point needs a D3D11 device, so they are only
// referenced: the test runs without arguments so the branch is never taken,
// but the symbols still have to resolve at link time. CreateDeviceObjects()
// is referenced to pull in D3DCompile (d3dcompiler).

#include <imgui/backends/imgui_impl_dx11.h>

int main (int argc, char*[])
{
  if (argc > 1)
  {
    ImGui_ImplDX11_Init (nullptr, nullptr);
    ImGui_ImplDX11_CreateDeviceObjects ();
    ImGui_ImplDX11_NewFrame ();
    ImGui_ImplDX11_InvalidateDeviceObjects ();
    ImGui_ImplDX11_Shutdown ();
  }
}
