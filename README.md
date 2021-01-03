# grove-multichannelgassensor-esphome
This are files for the Multi Channel Grove Gas Sensor or mics_6814 sensor

### Dependencies:
* Grove - Multichannel Gas Sensor

### Installation

1. In your ESPHome config folder upload the mics-6814.cpp.h file
2. In the configuration file for your sensor add the following entry to the esphome block:

```
  includes:
    - "mics-6814.cpp.h"
  libraries:
    - "Grove - Multichannel Gas Sensor"
```

3. To access the sensor values in your ESPHome Config use the following template in your sensor block

```
- platform: custom
    lambda: |-
      auto my_sensor = new mics_6814();
      App.register_component(my_sensor);
      return {my_sensor->nh3_sensor, my_sensor->co_sensor, my_sensor->no2_sensor, my_sensor->c3h8_sensor, my_sensor->c4h10_sensor, my_sensor->ch4_sensor, my_sensor->h2_sensor, my_sensor->c2h5oh_sensor};
    sensors:
      - name: "NH3 Sensor"
        accuracy_decimals: 2
        unit_of_measurement: 'NH3'
      - name: "CO Sensor"
        accuracy_decimals: 2
        unit_of_measurement: 'ppm'
      - name: "NO2 Sensor"
        accuracy_decimals: 2
        unit_of_measurement: 'µg/m³'
      - name: "C3H8 Sensor"
        accuracy_decimals: 2
        unit_of_measurement: '%'
      - name: "C4H10 Sensor"
        accuracy_decimals: 2
        unit_of_measurement: '%'
      - name: "CH4 Sensor"
        accuracy_decimals: 2
        unit_of_measurement: '%'
      - name: "H2 Sensor"
        accuracy_decimals: 2
        unit_of_measurement: '%'
      - name: "C2H5OH Sensor"
        accuracy_decimals: 2
        unit_of_measurement: '%'
```

If you get an error saying the `Architecture not matched`. In the folder where your binaries are for that sensor in the `src` directory modify `MutichannelGasSensor.h` by commenting that line along with appending `#define _SERIAL Serial` 


