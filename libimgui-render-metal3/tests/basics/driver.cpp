#include <imgui/backends/imgui_impl_metal.h>

// Smoke test: every entry point needs an MTL::Device, which needs a GPU that
// a headless CI runner may not have. So they are only referenced: the test
// runs without arguments so the branch is never taken, but the symbols
// still have to resolve at link time. These are the metal-cpp (C++, not
// Objective-C++) overloads, see IMGUI_IMPL_METAL_CPP in src/buildfile.

int main (int argc, char*[])
{
  if (argc > 1)
  {
    ImGui_ImplMetal_Init (nullptr);
    ImGui_ImplMetal_NewFrame (nullptr);
    ImGui_ImplMetal_Shutdown ();
  }
}
