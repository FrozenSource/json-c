#ifndef __math_compat_h
#define __math_compat_h

/**
 * @file
 * @brief Do not use, json-c internal, may be changed or removed at any time.
 */

/* Define isnan, isinf, infinity and nan on Windows/MSVC */

#ifndef HAVE_DECL_ISNAN
#ifdef HAVE_DECL__ISNAN
#include <float.h>
#ifndef isnan
#define isnan(x) _isnan(x)
#endif
#else
/* On platforms like AIX and "IBM i" we need to provide our own isnan */
#define isnan(x) ((x) != (x))
#endif
#endif

#ifndef HAVE_DECL_ISINF
#ifdef HAVE_DECL__FINITE
#include <float.h>
#ifndef isinf
#define isinf(x) (!_finite(x))
#endif
#else
#include <float.h>
/* On platforms like AIX and "IBM i" we need to provide our own isinf */
#define isinf(x) ((x) < -DBL_MAX || (x) > DBL_MAX)
#endif
#endif

#ifndef HAVE_DECL_INFINITY
#include <float.h>
#ifndef INFINITY
#define INFINITY (DBL_MAX + DBL_MAX)
#endif
#define HAVE_DECL_INFINITY
#endif

#ifndef HAVE_DECL_NAN
#ifndef NAN
#define NAN (INFINITY - INFINITY)
#endif
#define HAVE_DECL_NAN
#endif

#endif
