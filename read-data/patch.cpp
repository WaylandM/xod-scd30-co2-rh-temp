
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `SCD30` class instance
    auto airSensor = getValue<input_DEV>(ctx);

    if (airSensor->dataAvailable())
    {
        emitValue<output_CO2>(ctx,airSensor->getCO2());
        emitValue<output_RH>(ctx,airSensor->getHumidity());
        emitValue<output_TEMP>(ctx,airSensor->getTemperature());
        emitValue<output_OK>(ctx,1);
    } else {
        emitValue<output_NO_DATA>(ctx, 1);
    }

}
