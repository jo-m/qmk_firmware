# Was set up with

```bash
qmk new-keymap -kb keebio/quefrency/rev3 -km jo_m_rev3
```

# Deployment

```bash
qmk clean -a
qmk compile -kb keebio/quefrency/rev3 -km jo_m_rev3
qmk flash -kb keebio/quefrency/rev3 -km jo_m_rev3
```
