Was set up with

```bash
qmk new-keymap -kb keebio/quefrency/rev3 -km jo-m-rev3
```

Deploy:

```bash
cd qmk_firmware

# prepare
make setup
make git-submodule

# build
qmk clean -a
qmk compile -kb keebio/quefrency/rev3 -km jo-m-rev3

# flash
qmk flash -kb keebio/quefrency/rev3 -km jo-m-rev3
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
