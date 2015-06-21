//
// Copyright(c) 1997 Amol Deshpande
// amold@microsoft.com
// Redistribution in source or binary form is permitted as long as you 
// retain this notice in the distribution
//
// The memory allocator herein is part of the tcsh shell distribution. 
// The original tcsh code is under its own copyright. Get the source from
// ftp.deshaw.com/pub to figure it out.
//
// 
// The fork() implementation borrows heavily from the cygnus gnu-win32
// project's implementation. Check out www.cygnus.com for more information.
// 
//
// There is one restriction that I impose on any users of this code. If you
// use it in your own application, your application *must* be freely 
// redistributable in source form also.
// (I suppose borrowing ideas from the cygnus code makes this a requirement,
// since that code is GPL'd. However, I want to explicitly make it clear that 
// this is FREE software).
//
// You are specifically prohibited from enhancing or fixing bugs in this 
// implementation and selling the resultant product. If you make any changes
// that fix bugs in or enhance this code, you *must* send me a copy.
//
// I retain all rights to this software, except for the tcsh code.
//
// Amol Deshpande and the Zsh Development Group specifically disclaim any
// warranties, including, but not limited to, the implied warranties of
// merchantability and fitness for a particular purpose.  The software
// provided hereunder is on an "as is" basis, and Amol Deshpande and the
// Zsh Development Group have no obligation to provide maintenance,
// support, updates, enhancements, or modifications.
//
//
// And finally,
// Microsoft Corporation has nothing to do with this code. 

#include "ntport.h"
#include "zsh.h"

static struct passwd pass_bogus;
static char username[20];
static char homedir[256];
static char *this_shell="zsh";

static char dummy[2]={0,0};

gid_t getuid(void) {
	return 0;
}
gid_t getgid(void) {
	return 0;
}
gid_t geteuid(void) {
	return 0;
}
gid_t getegid(void) {
	return 0;
}
struct passwd * getpwnam(char *name) {

	char *ptr;
	int size =20;

	if (pass_bogus.pw_name == NULL) {
		GetUserName(username,&size);
		ptr = getenv("HOME");
		if (ptr){
			strcpy(homedir,ptr);
		}
		else
			strcpy(homedir,"youdonthavehomeset");
		pass_bogus.pw_dir = &homedir[0];
		pass_bogus.pw_name = &username[0];
		pass_bogus.pw_shell = this_shell;
		

		pass_bogus.pw_passwd= &dummy[0];
		pass_bogus.pw_gecos=&dummy[0];
		pass_bogus.pw_passwd= &dummy[0];
		
	}
	if (stricmp(username,name))
		return NULL;
	return &pass_bogus;
}
struct passwd * getpwuid(uid_t uid) {

	char *ptr;
	int size =20;

	if (pass_bogus.pw_name == NULL) {
		GetUserName(username,&size);
		ptr = getenv("HOME");
		if (ptr){
			strcpy(homedir,ptr);
		}
		else
			strcpy(homedir,"youdonthavehomeset");
		pass_bogus.pw_dir = &homedir[0];
		pass_bogus.pw_name = &username[0];
		pass_bogus.pw_shell = this_shell;
		

		pass_bogus.pw_passwd= &dummy[0];
		pass_bogus.pw_gecos=&dummy[0];
		pass_bogus.pw_passwd= &dummy[0];
		
	}
	return &pass_bogus;
}
struct group * getgrnam(char *name) {

	return NULL;
}
struct group * getgrgid(gid_t gid) {

	return NULL;
}
char * ttyname(int fd) {

	if (isatty(fd)) return "/dev/tty";
	return NULL;
}
int times(struct tms * ignore) {
	return -1;
}
int bin_log(char *nam, char **argv, char *ops, int func){
	return 0;
}
void dowatch(void){
	;
}