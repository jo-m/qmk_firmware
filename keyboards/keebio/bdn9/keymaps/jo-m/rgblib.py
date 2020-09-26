#!/usr/bin/env python3

from enum import Enum
from typing import NamedTuple
import argparse
import struct

PORT = "/dev/ttyACM0"
BAUD = 9600

MAGIC_1 = b"A"
MAGIC_2 = b"B"
MAGIC_3 = b"C"


class RgbMode(Enum):
    STATIC_LIGHT = 1
    BREATHING = 2
    BREATHING_1 = 3
    BREATHING_2 = 4
    BREATHING_3 = 5
    RAINBOW_MOOD = 6
    RAINBOW_MOOD_1 = 7
    RAINBOW_MOOD_2 = 8
    # RAINBOW_SWIRL = 9
    # RAINBOW_SWIRL_1 = 10
    # RAINBOW_SWIRL_2 = 11
    # RAINBOW_SWIRL_3 = 12
    # RAINBOW_SWIRL_4 = 13
    # RAINBOW_SWIRL_5 = 14
    SNAKE = 15
    SNAKE_1 = 16
    SNAKE_2 = 17
    SNAKE_3 = 18
    SNAKE_4 = 19
    SNAKE_5 = 20
    KNIGHT = 21
    KNIGHT_1 = 22
    KNIGHT_2 = 23
    # CHRISTMAS = 24
    STATIC_GRADIENT = 25
    STATIC_GRADIENT_1 = 26
    STATIC_GRADIENT_2 = 27
    STATIC_GRADIENT_3 = 28
    STATIC_GRADIENT_4 = 29
    STATIC_GRADIENT_5 = 30
    STATIC_GRADIENT_6 = 31
    STATIC_GRADIENT_7 = 32
    STATIC_GRADIENT_8 = 33
    STATIC_GRADIENT_9 = 34
    # RGB_TEST = 35
    ALTERNATING = 36
    TWINKLE = 37
    TWINKLE_1 = 38
    TWINKLE_2 = 39
    TWINKLE_3 = 40
    TWINKLE_4 = 41
    TWINKLE_5 = 42


class Packet(NamedTuple):
    enable: bool
    mode: RgbMode
    hue: int
    sat: int
    val: int

    def serialize(self) -> bytes:
        return struct.pack(
            "cc?BBBBc",
            MAGIC_1,
            MAGIC_2,
            self.enable,
            self.mode.value,
            self.hue,
            self.sat,
            self.val,
            MAGIC_3,
        )


def main():
    import serial

    parser = argparse.ArgumentParser(description="Control the BDN9 macropad RGB.")
    parser.add_argument("--off", "-o", action="store_true", help="Turn off LEDs")
    parser.add_argument(
        "--mode",
        "-m",
        type=str,
        choices=[m.name for m in RgbMode],
        default=RgbMode.STATIC_LIGHT.name,
    )
    parser.add_argument(
        "--hsv",
        "-H",
        type=int,
        nargs=3,
        default=[0, 0, 0],
        help="HSV hue saturation value",
    )
    args = parser.parse_args()

    p = Packet(not args.off, RgbMode[args.mode], args.hsv[0], args.hsv[1], args.hsv[2])
    ser = serial.Serial(PORT, baudrate=BAUD, timeout=1)
    ser.write(p.serialize())


if __name__ == "__main__":
    main()
