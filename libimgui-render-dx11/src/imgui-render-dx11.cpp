#include <imgui-render-dx11.h>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace imgui_render_dx11
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}
