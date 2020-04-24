# App
A state machine based application concept

## General concepts
* Each source with the exception of App.c represents a state
* Each state has an array of the next possible `Event`s and its current size
* Each state has its array initialized by other states at start of execution time. This is done through the macro `QUEUE`
* For this, each state has a header to provide a function to append an `Event` to its array. These functions are to be called inside `QUEUE` functions
* A transition occurs whenever an `action` from an `Event` happens. A "minor" state (like `Exit` in `Home.c`) can also be used.

**Note**: The `QUEUE` macro uses [GNU function attributes](https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html#Common-Function-Attributes), thus a proper compiler is necessary.

## Example
The state machine with the `Home`, `Gym` and `Work` states is provided here. A `main` function may look like this:

```c++
#include <stdlib.h>
#include "App.h"

int main(void)
{
    EventPtr next;

    App app = createApp(NULL);
    do
        next = getNextEvent(app);
    while (next != NULL);
    deleteApp(app);
    return 0;
}
```