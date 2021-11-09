To build
```
qmake && make
```

To clean:
```
make sdkclean && make distclean
```

To run
```
sudo sh -c "echo performance > /sys/devices/system/cpu/cpufreq/policy0/scaling_governor"
./LeptonVideo -tl 3
```


----

In order for the application to run properly, a Lepton camera must be attached in a specific way to the SPI, power, and ground pins of the Raspi's GPIO interface, as well as the I2C SDA/SCL pins:

Lepton's GND pin should be connected to RasPi's ground.

Lepton's CS pin should be connected to RasPi's CE1 pin.

Lepton's MISO pin should be connected to RasPI's MISO pin.

Lepton's CLK pin should be connected to RasPI's SCLK pin.

Lepton's VIN pin should be connected to RasPI's 3v3 pin.

Lepton's SDA pin should be connected to RasPI's SDA pin.

Lepton's SCL pin should be connected to RasPI's SCL pin.
