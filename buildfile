import pkgs = libimgui/
import pkgs_docking = libimgui-docking/

libimgui = [dir_path] $pkgs
libimgui_docking = [dir_path] $pkgs_docking

import pkgs += libimgui-platform-glfw/ libimgui-render-opengl2/ libimgui-render-opengl3/ libimgui-render-vulkan/ libimgui-examples/
import pkgs_docking += libimgui-platform-glfw-docking/ libimgui-render-opengl2-docking/ libimgui-render-opengl3-docking/ libimgui-render-vulkan-docking/ libimgui-examples-docking/

switch $($libimgui/ cxx.target.class)
{
    case 'windows'
    {
        import pkgs += {libimgui-platform-win32/ libimgui-render-dx9/ libimgui-render-dx10/ libimgui-render-dx11/ libimgui-render-dx12/}
    }
    case 'macos'
    {
        import pkgs += {libimgui-platform-osx/ libimgui-render-metal/}
    }
}

switch $($libimgui_docking/ cxx.target.class)
{
    case 'windows'
    {
        import pkgs_docking += {libimgui-platform-win32-docking/ libimgui-render-dx9-docking/ libimgui-render-dx10-docking/ libimgui-render-dx11-docking/ libimgui-render-dx12-docking/}
    }
    case 'macos'
    {
        import pkgs_docking += {libimgui-platform-osx-docking/ libimgui-render-metal-docking/}
    }
}

./: $pkgs $pkgs_docking
