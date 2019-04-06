
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `SCD30` class instance
    auto airSensor = getValue<input_DEV>(ctx);

    emitValue<output_CO2>(ctx,airSensor->getCO2());
    emitValue<output_RH>(ctx,airSensor->getHumidity());
    emitValue<output_TEMP>(ctx,airSensor->getTemperature());
    emitValue<output_DONE>(ctx,1);

}
