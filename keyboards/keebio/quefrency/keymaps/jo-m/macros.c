enum custom_macro_keycodes {
    GIT_ADD_P = SAFE_RANGE,
    GIT_COM_M,
    GIT_PUSH,
    GIT_PULL,
    TMX_ZOOM,
    TMX_CRTE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }
    switch (keycode) {
    case GIT_ADD_P:
        SEND_STRING("git add -p");
        break;
    case GIT_COM_M:
        SEND_STRING("git commit -m ''");
        tap_code(KC_LEFT);
        break;
    case GIT_PUSH:
        SEND_STRING("git push");
        break;
    case GIT_PULL:
        SEND_STRING("git pull");
        break;
    case TMX_ZOOM:
        SEND_STRING(SS_LCTL("b"));
        SEND_STRING("z");
        break;
    case TMX_CRTE:
        SEND_STRING(SS_LCTL("b"));
        SEND_STRING("c");
        break;
    }
    return true;
};
