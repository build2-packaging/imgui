import pkgs = {imgui-core/ imgui-platform-glfw/ imgui-render-opengl2/ imgui-render-opengl3/}

using cxx

switch $cxx.target.class
{
    case 'windows'
    {
        import pkgs += {imgui-platform-win32/ imgui-render-dx9/ imgui-render-dx10/ imgui-render-dx11/ imgui-render-dx12/}
    }
    case 'linux'
    {
    }
    case 'macos'
    {
        import pkgs += {imgui-platform-osx/ imgui-render-metal/}
    }
}

./: $pkgs