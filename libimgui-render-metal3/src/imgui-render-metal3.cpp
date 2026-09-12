#include <imgui-render-metal3.h>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace imgui_render_metal3
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}
