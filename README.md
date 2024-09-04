# C64Matrix
Commodore 64 Version of Matrix Screensaver.

## Building
This uses make and requires both VICE and CC65 to be installed in order to compile.

Build the prg file, which can be loaded into VICE using the smart attach -> autostart feature:
```bash
make c64
```

Compile the prg file to a D64 disk file:
```bash
make c64
make disk
```
