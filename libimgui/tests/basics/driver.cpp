#include <imgui/imgui.h>

#ifdef IMGUI_ENABLE_FREETYPE
#  include <imgui/misc/freetype/imgui_freetype.h>
#endif

#undef NDEBUG
#include <cassert>

#ifdef IMGUI_USE_WCHAR32
static_assert (sizeof (ImWchar) == sizeof (ImWchar32), "ImWchar is 32-bit");
#else
static_assert (sizeof (ImWchar) == sizeof (ImWchar16), "ImWchar is 16-bit");
#endif

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

  // There is no renderer backend, so claim texture support the way a modern
  // one does (as upstream's null backend does). The font atlas is then built
  // on demand, without the legacy GetTexDataAsRGBA32() that is unavailable
  // with IMGUI_DISABLE_OBSOLETE_FUNCTIONS.
  //
  io.BackendFlags |= ImGuiBackendFlags_RendererHasTextures;

  ImGui::NewFrame ();
  ImGui::Begin ("Test");
  ImGui::Text ("Hello, Dear ImGui!");
  ImGui::End ();
  ImGui::Render ();

  assert (ImGui::GetDrawData () != nullptr);

  ImGui::DestroyContext (ctx);
}
