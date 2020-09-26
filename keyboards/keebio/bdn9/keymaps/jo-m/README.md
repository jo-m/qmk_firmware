Was set up with

```bash
qmk config user.keyboard=keebio/bdn9/rev1
qmk config user.keymap=jo-m
qmk new-keymap
```

Deploy:

```bash
cd repo_root_folder
qmk compile -kb keebio/bdn9 -km jo-m && \
make keebio/bdn9:jo-m:avrdude
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
