## BMGL
BMGL is a basic home-made modern OpenGL funtion loader with no external dlls or linking required to use it. By the moment It only works on windows, but in the future I'll add linux support. If you find out that there is either a function or a declaration that haven't been added, feel free to give me a shot or make a pull request yourself adding the feature.

### Usage
Really simple, just drag the bmgl.h file into your project, include it and call bmgl_init() before calling any modern OpenGL function:
```
#include "bmgl.h"
...

int main() {
  bmgl_init();
}
```
