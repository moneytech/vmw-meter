#define DISPLAY_LINES 8

void shutdown_display(void);
void reset_display(unsigned short *display_state);
void update_display(unsigned char *display_state);
int init_display(void);
int set_brightness(int value);
