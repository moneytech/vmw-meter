#define USE_LINUX_I2C 1

extern int i2c_fd;

#define DISPLAY_I2C	0x1
#define DISPLAY_TEXT	0x2
#define DISPLAY_BOTH	0x3

#define MODE_TITLE	0x0	/* Prints VMW CHIPTUNE */
#define MODE_VISUAL	0x1	/* Waterfall visualization */
#define MODE_NAME	0x2	/* Scrolls filename */
#define MODE_TIME	0x3	/* Shows elapsed time */
#define MODE_VOLUME	0x4	/* Allows setting the volume */
#define MODE_MAX	0x5

#define CMD_STOP		0x1
#define CMD_BACK		0x2
#define CMD_NEXT		0x3
#define CMD_EXIT_PROGRAM	0x4
#define CMD_FF			0x5
#define CMD_RW			0x6
#define CMD_LOOP		0x7

#define CMD_VOL_UP		0x8
#define CMD_VOL_DOWN		0x9

#define CMD_MUTE_A		0xA
#define CMD_MUTE_B		0xB
#define CMD_MUTE_C		0xC
#define CMD_MUTE_N		0xD

#define CMD_HEADPHONE_IN	0xE
#define CMD_HEADPHONE_OUT	0xF

#define CMD_PLAY		0x10
#define CMD_MENU		0x11
#define CMD_CANCEL		0x12


#define NUM_ALPHANUM	12

struct display_stats {
	int a_bar,b_bar,c_bar;
	int a_freq,b_freq,c_freq;
};

/********************* display_bargraph.c */
int bargraph(int type, int left_a, int left_b, int left_c,
			int right_a, int right_b, int right_c);
int close_bargraph(int type);


/********************* dispay_14seg.c */
int setup_14seg_font(void);
int display_14seg_string(int display_type,char *led_string);
int close_14seg(int type);

/********************* display_keypad.c */
int display_keypad_read(int display_type);
int display_keypad_clear(int display_type);
int display_keypad_repeat_until_keypressed(int display_type);

/********************* display_8x16.c */
int display_8x16_raw(int display_type, unsigned char *buffer);
int close_8x16_display(int display_type);
int display_8x16_led_art(int display_type,
                short led_art[10][8],
                int which);
int display_8x16_freq(int display_type, int a, int b, int c);

int display_8x16_time(int display_type, int current_frame, int total_frames);
int display_8x16_title(int display_type);
int display_8x16_scroll_text(int display_type, char *string, int new_string);

void display_8x16_vertical_putpixel(unsigned char *buffer,int x,int y);
int display_8x16_vertical_getpixel(unsigned char *buffer,int x,int y);

/********************* display.c */
int display_init(int type);
int display_update(int type,
			struct display_stats *ds,
			int current_frame, int num_frames,
			char *filename, int new_filename);
int display_shutdown(int type);


