Was set up with

```bash
qmk new-keymap -kb keebio/sinc/rev1 -km jo-m
```

Deploy:

```bash
cd qmk_firmware

# prepare
make setup
make git-submodule

# build
qmk clean -a
qmk compile -kb keebio/sinc/rev1 -km jo-m

# flash
qmk flash -kb keebio/sinc/rev1 -km jo-m
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
