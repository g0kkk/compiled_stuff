/*
* Copyright (C) 2014 - Brian Caswell <bmc@lungetech.com>
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#ifndef _UTILS_H
#define _UTILS_H

#include <err.h>

#ifndef UID_MAX
#define UID_MAX       ((~(uid_t)0)-1)
#endif

#ifndef MIN
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif

#ifdef DEBUG
#define DEBUG_LINE " (at line %d in %s)", __LINE__, __FILE__
#else
#define DEBUG_LINE
#endif

#define VERIFY(func, args...) do { if(func(args) < 0) err(-1, "unable to call " #func DEBUG_LINE); } while (0);
#define VERIFY_EXP(expression) do { if (!(expression)) err(-1, "unable to verify " #expression DEBUG_LINE); } while (0);
#define VERIFY_ASSN(ret, func, args...) do { if( (ret = func(args)) < 0) err(-1, "unable to call " #func DEBUG_LINE); } while (0);

// Makes debug prints shorter to type :)
#ifdef DEBUG
# define DBG_PRINTF(...) fprintf(stderr, __VA_ARGS__)
#else
# define DBG_PRINTF(...) do { ; } while(0)
#endif

#endif
