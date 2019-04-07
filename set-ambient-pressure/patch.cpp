
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `SCD30` class instance
    auto airSensor = getValue<input_DEV>(ctx);

    airSensor->setAmbientPressure(input_MBAR);
    emitValue<output_DONE>(ctx,1);

}
