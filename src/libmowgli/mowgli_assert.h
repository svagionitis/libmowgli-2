/*
 * libmowgli: A collection of useful routines for programming.
 * mowgli_assert.h: Assertions.
 *
 * Copyright (c) 2007 William Pitcock <nenolod -at- sacredspiral.co.uk>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __MOWGLI_ASSERT_H__
#define __MOWGLI_ASSERT_H__

/*
 * Performs a soft assertion. If the assertion fails, we log it.
 */
#ifdef __GNUC__
#define soft_assert(x)								\
	if (!(x)) { 								\
		mowgli_log("%s(%d) [%s]: critical: Assertion '%s' failed.",	\
			__FILE__, __LINE__, __PRETTY_FUNCTION__, #x);		\
	}
#else
#define soft_assert(x)								\
	if (!(x)) { 								\
		mowgli_log("%s(%d): critical: Assertion '%s' failed.",	\
			__FILE__, __LINE__, #x);				\
	}
#endif

/*
 * Same as soft_assert, but returns if an assertion fails.
 */
#ifdef __GNUC__
#define return_if_fail(x)							\
	if (!(x)) { 								\
		mowgli_log("%s(%d) [%s]: critical: Assertion '%s' failed.",	\
			__FILE__, __LINE__, __PRETTY_FUNCTION__, #x);		\
		return;								\
	}
#else
#define return_if_fail(x)							\
	if (!(x)) { 								\
		mowgli_log("%s(%d): critical: Assertion '%s' failed.",	\
			__FILE__, __LINE__, #x);				\
		return;								\
	}
#endif

/*
 * Same as soft_assert, but returns a given value if an assertion fails.
 */
#ifdef __GNUC__
#define return_val_if_fail(x, y)						\
	if (!(x)) { 								\
		mowgli_log("%s(%d) [%s]: critical: Assertion '%s' failed.",	\
			__FILE__, __LINE__, __PRETTY_FUNCTION__, #x);		\
		return (y);							\
	}
#else
#define return_val_if_fail(x, y)						\
	if (!(x)) { 								\
		mowgli_log("%s(%d): critical: Assertion '%s' failed.",		\
			__FILE__, __LINE__, #x);				\
		return (y);							\
	}
#endif

#endif
