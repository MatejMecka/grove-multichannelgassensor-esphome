#include <Wire.h>
#include "MutichannelGasSensor.h"

class mics_6814 : public PollingComponent {
    public:

        Sensor *nh3_sensor = new Sensor();
        Sensor *co_sensor = new Sensor();
        Sensor *no2_sensor = new Sensor();
        Sensor *c3h8_sensor = new Sensor();
        Sensor *c4h10_sensor = new Sensor();
        Sensor *ch4_sensor = new Sensor();
        Sensor *h2_sensor = new Sensor();
        Sensor *c2h5oh_sensor = new Sensor();

        mics_6814() : PollingComponent(15000) {}

        void setup() override {
            gas.begin(0x04);
            gas.powerOn();
        }

        void update() override {
            float nh3;
            nh3 = gas.measure_NH3();
            if (nh3 >= 0) nh3_sensor->publish_state(nh3);

            float co;
            co = gas.measure_CO();
            if (co >= 0) co_sensor->publish_state(co);

            float no2;
            no2 = gas.measure_NO2();
            if (no2 >= 0) no2_sensor->publish_state(no2);

            float c3h8;
            c3h8 = gas.measure_C3H8();
            if (c3h8 >= 0) c3h8_sensor->publish_state(c3h8);

            float c4h10;
            c4h10 = gas.measure_C4H10();
            if (c4h10 >= 0) c4h10_sensor->publish_state(c4h10);
        
            float ch4;
            ch4 = gas.measure_CH4();
            if (ch4 >= 0) ch4_sensor->publish_state(ch4);

            float h2;
            h2 = gas.measure_H2();
            if (h2 >= 0) h2_sensor->publish_state(h2);

            float c2h5oh;
            c2h5oh = gas.measure_C2H5OH();
            if (c2h5oh >= 0) c2h5oh_sensor->publish_state(c2h5oh);
        }
};


