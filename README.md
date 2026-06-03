# GuineaFowl (Teensy 4.1)

Watchdog system for autonoous drone project validation.

## Prerequisites

- PlatformIO Core CLI 6.x (`pio --version`)
- Teensy 4.1 connected over USB

## Commands

Build:

```sh
pio run -e teensy41
```

Build and upload:

```sh
pio run -e teensy41 -t upload
```

Clean build artifacts:

```sh
pio run -e teensy41 -t clean
```

List available serial devices:

```sh
pio device list
```

Open serial monitor:

```sh
pio device monitor -b 115200
```
