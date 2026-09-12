#include <imgui-platform-glfw.h>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace imgui_platform_glfw
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}
