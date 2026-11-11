#include <imgui-render-metal4.h>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace imgui_render_metal4
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}
