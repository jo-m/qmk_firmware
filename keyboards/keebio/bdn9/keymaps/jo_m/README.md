# Was set up with

```bash
qmk new-keymap -kb keebio/bdn9/rev1 -km jo_m
```

# Deployment

```bash
qmk clean -a
qmk compile -kb keebio/bdn9/rev1 -km jo_m
qmk flash -kb keebio/bdn9/rev1 -km jo_m
```

Control RGB from host:

```bash
keyboards/keebio/bdn9/keymaps/jo_m/rgblib.py --mode=STATIC_LIGHT --hsv 0 255 255
keyboards/keebio/bdn9/keymaps/jo_m/rgblib.py --mode=BREATHING_2 --hsv 100 100 100
keyboards/keebio/bdn9/keymaps/jo_m/rgblib.py --mode=TWINKLE_2 --hsv 200 255 255
keyboards/keebio/bdn9/keymaps/jo_m/rgblib.py --off
```
