Was set up with

```bash
qmk new-keymap -kb keebio/sinc/rev1
```

Deploy:

```bash
cd repo_root_folder
qmk compile -kb keebio/sinc/rev1 -km jo-m && \
    make keebio/sinc/rev1:jo-m:avrdude
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
