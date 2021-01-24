Was set up with

```bash
qmk new-keymap -kb keebio/bdn9/rev1 -km jo-m
```

Deploy:

```bash
cd repo_root_folder
make keebio/bdn9/rev1:jo-m:flash
```

Upgrade from upstream:

```bash
git checkout master
git pull upstream master
git push origin master
git checkout jo-m
git merge master
git push origin jo-m
```

Control RGB from host:

```bash
keyboards/keebio/bdn9/keymaps/jo-m/rgblib.py --mode=STATIC_LIGHT --hsv 0 255 255
keyboards/keebio/bdn9/keymaps/jo-m/rgblib.py --mode=BREATHING_2 --hsv 100 100 100
keyboards/keebio/bdn9/keymaps/jo-m/rgblib.py --mode=TWINKLE_2 --hsv 200 255 255
keyboards/keebio/bdn9/keymaps/jo-m/rgblib.py --off
```
