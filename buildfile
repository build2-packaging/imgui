import pkgs = {imgui/ imgui-platform-glfw/ imgui-render-opengl2/ imgui-render-opengl3/}

switch $cxx.target.class
{
    case 'windows'
    {

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