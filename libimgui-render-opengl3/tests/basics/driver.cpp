#include <imgui/backends/imgui_impl_opengl3.h>

// In GLES mode (auto-detected on Emscripten) the backend uses the system
// GLES headers instead of upstream's loader (imgui_impl_opengl3_loader.h),
// so there are no imgl3w symbols to resolve.
//
#if !defined(IMGUI_IMPL_OPENGL_ES2) && !defined(IMGUI_IMPL_OPENGL_ES3)
#  define TEST_LOADER
#  include <imgui/backends/imgui_impl_opengl3_loader.h>
#endif

// Smoke test: every entry point needs a current OpenGL context, which needs
// a real window and GPU that a headless CI environment does not have. So
// they are only referenced: the test runs without arguments so the branch
// is never taken, but the symbols still have to resolve at link time. This
// includes the exported loader, where glClear() goes through imgl3wProcs.

int main (int argc, char*[])
{
  if (argc > 1)
  {
    ImGui_ImplOpenGL3_Init ();
    ImGui_ImplOpenGL3_NewFrame ();
    ImGui_ImplOpenGL3_Shutdown ();

#ifdef TEST_LOADER
    imgl3wGetProcAddress ("glClear");
    glClear (GL_COLOR_BUFFER_BIT);
#endif
  }
}
