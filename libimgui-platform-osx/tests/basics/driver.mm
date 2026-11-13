#include <imgui/backends/imgui_impl_osx.h>

// Smoke test: every entry point needs a live NSView, which needs a window
// server connection that a headless CI environment may not have. So they
// are only referenced: the test runs without arguments so the branch is
// never taken, but the symbols still have to resolve at link time.

int main (int argc, char*[])
{
  if (argc > 1)
  {
    NSView* view (nullptr);
    ImGui_ImplOSX_Init (view);
    ImGui_ImplOSX_NewFrame (view);
    ImGui_ImplOSX_Shutdown ();
  }
}
