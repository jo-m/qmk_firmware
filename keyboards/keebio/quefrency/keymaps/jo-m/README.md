Was set up with

```bash
qmk config user.keyboard=keebio/quefrency/rev1
qmk config user.keymap=jo-m
qmk new-keymap
```

Deploy:

```bash
cd repo_root_folder
qmk compile -kb keebio/quefrency/rev1 -km jo-m && \
make keebio/quefrency/rev1:jo-m:avrdude
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
