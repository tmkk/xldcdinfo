#include <stdio.h>
#include <stdlib.h>
#include "XLDCDDABackend.h"

int main(int argc, char *argv[])
{
	xld_cdread_t disc;
	int i;
	int target = 0;
	
	if(argc < 2) return 0;
	int ret = xld_cdda_open(&disc, argv[1]);
	if(ret) {
		fprintf(stderr, "disc open error\n");
		return 0;
	}
	if(argc > 2) target = atoi(argv[2]);
	
	if(target <= 0 || target > disc.numTracks) {
		for(i=0;i<disc.numTracks;i++) {
			if(disc.tracks[i].type == kTrackTypeAudio) xld_cdda_read_isrc(&disc, i+1);
		}
		xld_cdda_print_disc_info(&disc);
	}
	else {
		if(disc.tracks[target-1].type == kTrackTypeAudio) xld_cdda_read_isrc(&disc, target);
		xld_cdda_print_track_info(&disc, target);
		
		// or directly see a pre-emphasis flag
		//fprintf(stdout, "%d\n",disc.tracks[target-1].preEmphasis);
	}
	
	xld_cdda_close(&disc);
	return 0;
}
