#include <imgui/backends/imgui_impl_glfw.h>

// Smoke test: ImGui_ImplGlfw_Sleep() is the only entry point that works
// without a live GLFWwindow, which needs a display that a headless CI
// environment does not have. The rest is only referenced: the test runs
// without arguments so the branch is never taken, but the symbols still
// have to resolve at link time.

int main (int argc, char*[])
{
  ImGui_ImplGlfw_Sleep (0);

  if (argc > 1)
  {
    ImGui_ImplGlfw_InitForOpenGL (nullptr, false);
    ImGui_ImplGlfw_InitForVulkan (nullptr, false);
    ImGui_ImplGlfw_InitForOther (nullptr, false);
    ImGui_ImplGlfw_GetContentScaleForMonitor (nullptr);
    ImGui_ImplGlfw_NewFrame ();
    ImGui_ImplGlfw_Shutdown ();
  }
}
