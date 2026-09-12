#include <imgui-render-vulkan.h>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace imgui_render_vulkan
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}
