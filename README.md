# FakeROM

Utility for create an empty ROM with specific size.

## Description

FakeROM create an empty "ROM", which is particularly useful when creating your own cartridge with a real ROM, however it does not have the correct size of the EPROM/EEPROM, so this fake ROM is then used to fill the intended space.

## Getting Started

### Dependencies

* GCC/Clang.
* Make (optional).
* Linux, Mac or Window.

### Build

* If you have make, you can do:

``` bash
$ make fakerom
```

* Or just compile fakerom.c

``` bash
$ cc -O3 fakerom.c -o fakerom
```

### Executing program

* An exeample creating a 16K ROM

``` bash
// linux
$ ./fakerom -r 16
```
* The out put is a file `fake.rom` with size of 16384kb

## Version History

* 1.0
    * Initial Release

## Acknowledgments

Inspiration, code snippets, etc.
* [MSX-Spider-Cart](https://github.com/konkotgit/MSX-Spider-Cart)
* [The MSX Repro carts](https://www.youtube.com/watch?v=pd_EqTok7fc)
