#include "8bkc-hal.h"
#include "8bkc-ugui.h"
#include "ugui.h"
#include "powerbtn_menu.h"

static void do_powerbtn_menu() {
    int pwr_input = powerbtn_menu_show(kcugui_get_fb());

    if (pwr_input == POWERBTN_MENU_EXIT) { // This handles the input from the power button menu - without it, menu options do nothing
        kchal_exit_to_chooser();
    } else if (pwr_input == POWERBTN_MENU_POWERDOWN) {
        kchal_power_down();
    }
}

void app_main() {
    kchal_init();
    kcugui_init();
    UG_FontSelect(&FONT_6X8);
    UG_SetForecolor(C_WHITE);
    UG_SetBackcolor(C_BLACK);

    kcugui_cls();
    UG_PutString(0, 0, "Hello World!");
    kcugui_flush();

    while (true) {
        if (kchal_get_keys() & KC_BTN_POWER) {
            do_powerbtn_menu();
        }
    }

    //kchal_exit_to_chooser();
}