/* standard.h: standard definitions and types
 *
 * These are some standard definitions and types for ISAAC.
 *
 * This package and its contents are released by the author into the
 * Public Domain, to the full extent permissible by law. For additional
 * information, please see the included `LICENSE' file.
 *
 * $Id: standard.h 6031 2009-04-06 21:52:00Z FREQUENCY@cpan.org $
 */

#ifndef STANDARD
#define STANDARD 1

/* Use unsigned long as our type */
typedef  unsigned long  ub4;

/* Some miscellaneous bit operation macros */
#define bis(target,mask)  ((target) |=  (mask))
#define bic(target,mask)  ((target) &= ~(mask))
#define bit(target,mask)  ((target) &   (mask))

/* Find the minimum of two values */
#ifndef min
#define min(a,b) (((a)<(b)) ? (a) : (b))
#endif /* min */

/* Find the maximum of two values */
#ifndef max
#define max(a,b) (((a)<(b)) ? (b) : (a))
#endif /* max */

#ifndef align
#define align(a) (((ub4)a+(sizeof(void *)-1))&(~(sizeof(void *)-1)))
#endif /* align */

/* Some boolean truth value constants */
#ifndef TRUE
#define TRUE  1
#endif /* TRUE */
#ifndef FALSE
#define FALSE 0
#endif /* FALSE */

#endif /* STANDARD */
