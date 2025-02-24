
// RGB Commands over serial

#define MAGIC_1 'A'
#define MAGIC_2 'B'
#define MAGIC_3 'C'

typedef struct {
    uint8_t magic_1;
    uint8_t magic_2;

    uint8_t enable;
    uint8_t mode;
    uint8_t hue;
    uint8_t sat;
    uint8_t val;

    uint8_t magic_3;
} serial_msg_t;

void package_received(const serial_msg_t *msg) {
    rgblight_mode_noeeprom(msg->mode);
    rgblight_sethsv_noeeprom(msg->hue, msg->sat, msg->val);

    if (msg->enable == 1) {
        rgblight_enable_noeeprom();
    } else {
        rgblight_disable_noeeprom();
    }
}

// Receive a byte via serial.
void virtser_recv(const uint8_t recv) {
    static serial_msg_t msg;
    static uint8_t n_received = 0;

    if (n_received == offsetof(serial_msg_t, magic_1)) {
        if (recv == MAGIC_1) {
            msg.magic_1 = MAGIC_1;
            n_received++;
            return;
        } else {
            n_received = 0;
            return;
        }
    }

    if (n_received == offsetof(serial_msg_t, magic_2)) {
        if (recv == MAGIC_2) {
            msg.magic_2 = MAGIC_2;
            n_received++;
            return;
        } else {
            n_received = 0;
            return;
        }
    }

    if (n_received == offsetof(serial_msg_t, magic_3)) {
        if (recv == MAGIC_3) {
            msg.magic_2 = MAGIC_3;
            n_received++;
            package_received(&msg);
        }
        n_received = 0;
        return;
    }

    if(n_received > offsetof(serial_msg_t, magic_2)) {
        uint8_t *p = &msg.magic_1;
        p += n_received;
        *p = recv;
        n_received++;
    }
}
