#include <imgui/backends/imgui_impl_win32.h>

// Smoke test: ImGui_ImplWin32_EnableDpiAwareness() works without a window.
// The rest needs one, so it is only referenced: the test runs without
// arguments so the branch is never taken, but the symbols still have to
// resolve at link time.

int main (int argc, char*[])
{
  ImGui_ImplWin32_EnableDpiAwareness ();

  if (argc > 1)
  {
    ImGui_ImplWin32_GetDpiScaleForMonitor (nullptr);
    ImGui_ImplWin32_EnableAlphaCompositing (nullptr);
    ImGui_ImplWin32_Init (nullptr);
    ImGui_ImplWin32_NewFrame ();
    ImGui_ImplWin32_Shutdown ();
  }
}
