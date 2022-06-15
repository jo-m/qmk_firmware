Was set up with

```bash
qmk new-keymap -kb keebio/quefrency/rev1 -km jo-m-rev1
```

Deploy:

```bash
cd qmk_firmware

# prepare
make setup
make git-submodule

# build
qmk compile -kb keebio/quefrency/rev1 -km jo-m-rev1

# flash
qmk flash -kb keebio/quefrency/rev1 -km jo-m-rev1
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
