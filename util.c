/* See LICENSE file for copyright and license details. */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

// Allocates memory of size nmemb * size
void *
ecalloc(size_t nmemb, size_t size)
{
	void *p;

	if (!(p = calloc(nmemb, size)))
		die("calloc:");
	return p;
}

// Prints a formatted message to stderr and exits
void
die(const char *fmt, ...) {
	va_list ap; // list of arguments

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	// when format string ends with a collon
	if (fmt[0] && fmt[strlen(fmt)-1] == ':') {
		fputc(' ', stderr);
		perror(NULL); // print errno message
	} else {
		fputc('\n', stderr);
	}

	exit(1);
}
