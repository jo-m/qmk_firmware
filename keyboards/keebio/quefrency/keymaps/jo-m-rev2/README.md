Was set up with

```bash
qmk new-keymap -kb keebio/quefrency/rev2 -km jo-m-rev2
```

Deploy:

```bash
cd repo_root_folder
make keebio/quefrency/rev2:jo-m-rev2:flash
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
