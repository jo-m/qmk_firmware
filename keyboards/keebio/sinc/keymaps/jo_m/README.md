# Was set up with

```bash
qmk new-keymap -kb keebio/sinc/rev1 -km jo_m
```

# Deployment

```bash
qmk clean -a
qmk compile -kb keebio/sinc/rev1 -km jo_m
qmk flash -kb keebio/sinc/rev1 -km jo_m
```
