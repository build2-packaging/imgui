#include <sstream>
#include <stdexcept>

#include <imgui-platform-win32.h>

#undef NDEBUG
#include <cassert>

int main ()
{
  using namespace std;
  using namespace imgui_platform_win32;

  // Basics.
  //
  {
    ostringstream o;
    say_hello (o, "World");
    assert (o.str () == "Hello, World!\n");
  }

  // Empty name.
  //
  try
  {
    ostringstream o;
    say_hello (o, "");
    assert (false);
  }
  catch (const invalid_argument& e)
  {
    assert (e.what () == string ("empty name"));
  }
}
