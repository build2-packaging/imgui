import pkgs = {imgui/ imgui-platform-glfw/ imgui-render-opengl2/ imgui-render-opengl3/ imgui-render-vulkan/ imgui-examples/}

using cxx

switch $cxx.target.class
{
    case 'windows'
    {
        import pkgs += {imgui-platform-win32/ imgui-render-dx9/ imgui-render-dx10/ imgui-render-dx11/ imgui-render-dx12/}
    }
    case 'macos'
    {
        import pkgs += {imgui-platform-osx/ imgui-render-metal/}
    }
}

./: $pkgs