Was set up with

```bash
qmk new-keymap -kb keebio/sinc/rev1 -km jo-m
```

Deploy:

```bash
cd repo_root_folder
make keebio/sinc/rev1:jo-m:flash
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
