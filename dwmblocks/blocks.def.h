//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{ "", "~/dots/scripts/statusbar/sb-memory"  , 5 , 0 },
	{ "", "~/dots/scripts/statusbar/sb-nettraf" , 2 , 0 },
	{ "", "~/dots/scripts/statusbar/sb-internet", 60, 0 },
	{ "", "~/dots/scripts/statusbar/sb-volume"  , 60, 22 },
	{ "", "~/dots/scripts/statusbar/sb-battery" , 5 , 0 },
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " ";
static unsigned int delimLen = 2;
