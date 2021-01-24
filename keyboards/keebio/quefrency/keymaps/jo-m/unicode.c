void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX);
};

enum unicode_names {
    // umlauts
    ae, AE, oe, OE, ue, UE,
    // emojis
    THUU, EXCL, FIST, MAHN, LOL,
    SCRM, HMMM, CRY, BOX
};

const uint32_t PROGMEM unicode_map[] = {
    [ae]    =  0x00E4,  // ä
    [AE]    =  0x00C4,  // Ä
    [oe]    =  0x00F6,  // ö
    [OE]    =  0x00D6,  // Ö
    [ue]    =  0x00FC,  // ü
    [UE]    =  0x00DC,  // Ü
};
