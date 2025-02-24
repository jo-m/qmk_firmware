# Was set up with

```bash
qmk new-keymap -kb keebio/quefrency/rev1 -km jo_m_rev2
```

# Deployment

```bash
qmk clean -a
qmk compile -kb keebio/quefrency/rev1 -km jo_m_rev2
qmk flash -kb keebio/quefrency/rev1 -km jo_m_rev2
```
