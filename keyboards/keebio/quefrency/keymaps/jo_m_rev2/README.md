https://docs.keeb.io/quefrency-rev2-sinc-build-guide

# Was set up with

```bash
qmk new-keymap -kb keebio/quefrency/rev2 -km jo_m_rev2
```

# Deployment

```bash
qmk clean -a
qmk compile -kb keebio/quefrency/rev2 -km jo_m_rev2
qmk flash -kb keebio/quefrency/rev2 -km jo_m_rev2
```
