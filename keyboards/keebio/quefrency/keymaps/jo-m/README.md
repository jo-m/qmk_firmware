Was set up with

```
qmk config user.keyboard=keebio/quefrency/rev1
qmk config user.keymap=jo-m
qmk new-keymap
```

Deploy:

```
qmk compile -kb keebio/quefrency/rev1 -km jo-m && \
make keebio/quefrency/rev1:jo-m:avrdude
```

Upgrade from upstream:

```
git checkout master
git pull upstream master
git push origin master
git checkout jo-m
git merge master
git push origin jo-m
```
