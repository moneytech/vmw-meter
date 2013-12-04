/* Falling tetromino game */

/* Needs two 8x8 displays and a wii nunchuck */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include <errno.h>

#include <sys/ioctl.h>

#include <linux/i2c-dev.h>

#include "i2c_lib.h"

#define T_O	0
#define T_I	1
#define T_T	2
#define T_S	3
#define T_Z	4
#define T_J	5
#define T_L	6

int pieces[7][4][4]= {

	/* O */
	{{0,0,0,0},
	 {0,1,1,0},
	 {0,1,1,0},
	 {0,0,0,0}},
	{{0,0,0,0},
	 {0,1,1,0},
	 {0,1,1,0},
	 {0,0,0,0}},
	{{0,0,0,0},
	 {0,1,1,0},
	 {0,1,1,0},
	 {0,0,0,0}},
	{{0,0,0,0},
	 {0,1,1,0},
	 {0,1,1,0},
	 {0,0,0,0}},

};

/* http://tetris.wikia.com/wiki/Random_Generator */
/* Generates random bag with 7 pieces */
/* Empties bag before moving on */
static int Random_Generator(void) {

	/* FIXME */
	return rand()%7;
}


int main(int arg, char **argv) {

	struct nunchuck_data n_data;
	unsigned char display_buffer[DISPLAY_LINES];
	unsigned char framebuffer[8];
	int piece_x=4, piece_y=4,piece_rotate=0;
	int piece_type=0;

	char *device="/dev/i2c-1";

	int i2c_fd,i;

	/* Init i2c */

	i2c_fd=init_i2c(device);
	if (i2c_fd < 0) {
		fprintf(stderr,"Error opening i2c dev file %s\n",device);
      		return -1;
	}

	/* Init nunchuck */

	if (init_nunchuck(i2c_fd)) {
		fprintf(stderr,"Error initializing nunchuck\n");
		return -1;
	}

	/* Init display */
	if (init_display(i2c_fd,HT16K33_ADDRESS1,15)) {
		fprintf(stderr,"Error opening display\n");
		return -1;
	}

	/* Clear Framebuffer */
	for(i=0;i<8;i++) framebuffer[i]=0;

	while(1) {

		/* Read Nunchuck */

		read_nunchuck(i2c_fd,&n_data);


		if (n_data.c_pressed) {
			piece_rotate++;
			if (piece_rotate>3) piece_rotate=0;
		}

		if (n_data.z_pressed) {
			piece_rotate--;
			if (piece_rotate<0) piece_rotate=3;
		}


		if (n_data.joy_y>140) {
			/* Fast Drop */
			piece_y--;
			if (piece_y<0) piece_y=0;
		}

		if (n_data.joy_y<100) {
			/* slow drop */
			piece_y++;
			if (piece_y>7) piece_y=7;
		}

		if (n_data.acc_x<400) {
			piece_x++;
			if (piece_x>7) piece_x=7;
		}


		if (n_data.acc_x>624) {
			piece_x--;
			if (piece_x<0) piece_x=0;
		}

		/* Copy framebuffer to screen */
		for(i=0;i<DISPLAY_LINES;i++) {
			display_buffer[i]=framebuffer[i];
		}

		/* Draw Piece */
		display_buffer[piece_y]|=1<<piece_x;

		/* Write Display */
		update_8x8_display_rotated(i2c_fd,HT16K33_ADDRESS1,display_buffer,0);

		/* move down */
		piece_y++;
		/* collision */
		if (piece_y>7) {
			piece_y=0;
		}


		usleep(100000);
	}

	return 0;

}