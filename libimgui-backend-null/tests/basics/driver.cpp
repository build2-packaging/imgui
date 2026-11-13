#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_null.h>

#undef NDEBUG
#include <cassert>

// Smoke test: the null backend needs no window or device, so run a few
// headless frames through it. The renderer marks the font atlas texture as
// created, which the next frame requires.

static void
frame ()
{
  ImGui::NewFrame ();
  ImGui::Begin ("Test");
  ImGui::Text ("Hello, Dear ImGui!");
  ImGui::End ();
  ImGui::Render ();

  ImDrawData* dd (ImGui::GetDrawData ());
  assert (dd != nullptr && dd->Textures != nullptr);

  ImGui_ImplNullRender_RenderDrawData (dd);

  for (ImTextureData* t: *dd->Textures)
    assert (t->Status == ImTextureStatus_OK);
}

int main ()
{
  IMGUI_CHECKVERSION ();

  ImGuiContext* ctx (ImGui::CreateContext ());
  assert (ctx != nullptr);

  ImGuiIO& io (ImGui::GetIO ());
  io.IniFilename = nullptr; // Don't read/write imgui.ini for this test.

  // Combined platform and renderer.
  //
  bool r (ImGui_ImplNull_Init ());
  assert (r);
  assert ((io.BackendFlags & ImGuiBackendFlags_RendererHasTextures) != 0);

  for (int i (0); i != 3; ++i)
  {
    ImGui_ImplNull_NewFrame ();
    assert (io.DisplaySize.x == 1920.0f && io.DisplaySize.y == 1080.0f);
    frame ();
  }

  ImGui_ImplNull_Shutdown ();
  assert ((io.BackendFlags & ImGuiBackendFlags_RendererHasTextures) == 0);

  // Separate platform and renderer halves.
  //
  r = ImGui_ImplNullPlatform_Init () && ImGui_ImplNullRender_Init ();
  assert (r);

  ImGui_ImplNullPlatform_NewFrame ();
  ImGui_ImplNullRender_NewFrame ();
  frame ();

  ImGui_ImplNullRender_Shutdown ();
  ImGui_ImplNullPlatform_Shutdown ();

  ImGui::DestroyContext (ctx);
}
