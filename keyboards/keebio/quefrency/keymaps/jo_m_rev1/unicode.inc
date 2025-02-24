enum unicode_names {
  ae, AE, oe, OE, ue, UE
};

const uint32_t PROGMEM unicode_map[] = {
  [ae]    =  0x00E4,  // ä
  [AE]    =  0x00C4,  // Ä
  [oe]    =  0x00F6,  // ö
  [OE]    =  0x00D6,  // Ö
  [ue]    =  0x00FC,  // ü
  [UE]    =  0x00DC,  // Ü
};
