#include <imgui.h>

#ifdef IMGUI_ENABLE_FREETYPE
#  include <misc/freetype/imgui_freetype.h>
#endif

#undef NDEBUG
#include <cassert>

// Smoke test for the core library. Does not require any platform or
// renderer backend: exercises context creation, a frame, and a widget
// call, then checks that draw data was produced.

int main ()
{
  assert (ImGui::GetVersion () != nullptr);

#ifdef IMGUI_ENABLE_FREETYPE
  assert (ImGuiFreeType::GetFontLoader () != nullptr);
#endif

  ImGuiContext* ctx (ImGui::CreateContext ());
  assert (ctx != nullptr);

  ImGuiIO& io (ImGui::GetIO ());
  io.IniFilename = nullptr; // Don't read/write imgui.ini for this test.
  io.DisplaySize = ImVec2 (1920.0f, 1080.0f);
  io.DeltaTime = 1.0f / 60.0f;

  // Build the default font atlas ourselves since there is no renderer
  // backend to do it for us (that's normally its job).
  //
  unsigned char* pixels;
  int width, height;
  io.Fonts->GetTexDataAsRGBA32 (&pixels, &width, &height);
  assert (pixels != nullptr);

  ImGui::NewFrame ();
  ImGui::Begin ("Test");
  ImGui::Text ("Hello, Dear ImGui!");
  ImGui::End ();
  ImGui::Render ();

  assert (ImGui::GetDrawData () != nullptr);

  ImGui::DestroyContext (ctx);
}
