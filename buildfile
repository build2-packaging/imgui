import pkgs = {imgui-core/ imgui-platform-glfw/ imgui-render-opengl2/ imgui-render-opengl3/}

switch $cxx.target.class
{
    case 'windows'
    {
        import pkgs += {imgui-platform-win32/ imgui-platform-dx9/ imgui-platform-dx10/ imgui-platform-dx11/ imgui-platform-dx12/}
    }
    case 'linux'
    {
    }
    case 'macos'
    {
        import pkgs += {imgui-platform-osx/ imgui-platform-metal/}
    }
}

./: $pkgs