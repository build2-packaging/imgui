#include <imgui-platform-win32.h>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace imgui_platform_win32
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}
