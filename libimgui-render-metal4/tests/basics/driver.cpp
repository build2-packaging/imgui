#include <imgui/backends/imgui_impl_metal4.h>

// Smoke test: every entry point needs an MTL::Device and a Metal 4 command
// queue, which needs a GPU that a headless CI runner may not have. So they
// are only referenced: the test runs without arguments so the branch is
// never taken, but the symbols still have to resolve at link time. These
// are the metal-cpp (C++, not Objective-C++) overloads, see
// IMGUI_IMPL_METAL_CPP in src/buildfile.

int main (int argc, char*[])
{
  if (argc > 1)
  {
    ImGui_ImplMetal4_Init (nullptr, nullptr, 1);
    ImGui_ImplMetal4_CreateDeviceObjects (nullptr);
    ImGui_ImplMetal4_NewFrame (nullptr, 0);
    ImGui_ImplMetal4_Shutdown ();
  }
}
