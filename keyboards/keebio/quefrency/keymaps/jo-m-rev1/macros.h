enum custom_macro_keycodes {
    // git add -p
    GIT_ADD_P = SAFE_RANGE,
    // git commit -m '' <-
    GIT_COM_M,
    // git push
    GIT_PUSH,
    // git pull
    GIT_PULL,
    // tmux zoom
    TMX_ZOOM,
    // tmux create window
    TMX_CRTE,

    // mic push to talk
    KC_MPTT,
};

// KC_F20 is AudioMicMute (https://github.com/linuxmint/gtk/blob/master/gdk/keynames.txt)
#define KC_MMUTE KC_F20

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // mic push to talk
    if (keycode == KC_MPTT) {
        tap_code(KC_F20);
        return true;
    }

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
