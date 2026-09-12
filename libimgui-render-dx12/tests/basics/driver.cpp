// Smoke test: every entry point needs a D3D12 device, so they are only
// referenced: the test runs without arguments so the branch is never taken,
// but the symbols still have to resolve at link time. CreateDeviceObjects()
// is referenced to pull in CreateDXGIFactory1 (dxgi) and D3DCompile
// (d3dcompiler).

#include <imgui/backends/imgui_impl_dx12.h>

int main (int argc, char*[])
{
  if (argc > 1)
  {
    ImGui_ImplDX12_InitInfo* info (nullptr);
    ImGui_ImplDX12_Init (info);
    ImGui_ImplDX12_CreateDeviceObjects ();
    ImGui_ImplDX12_NewFrame ();
    ImGui_ImplDX12_InvalidateDeviceObjects ();
    ImGui_ImplDX12_Shutdown ();
  }
}
