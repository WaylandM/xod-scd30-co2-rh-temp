// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/sparkfun/SparkFun_SCD30_Arduino_Library"

//Include C++ libraries
{{#global}}
#include <Wire.h>
#include <SparkFun_SCD30_Arduino_Library.h>
{{/global}}

// Reserve memory to store an instance of the class,
// and create the instance later:
struct State {
    uint8_t mem[sizeof(SCD30)];
};

// Define our custom type as a pointer on the class instance.
using Type = SCD30*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // It should be evaluated only once on the first (setup) transaction
    if (!isSettingUp())
        return;

    auto state = getState(ctx);

    // Create a new object in the memory area reserved previously.
    Type airSensor = new (state->mem) SCD30();

    emitValue<output_DEV>(ctx, airSensor);
}
