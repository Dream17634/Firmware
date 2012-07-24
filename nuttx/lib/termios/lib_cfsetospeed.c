/****************************************************************************
 * lib/termios/lib_cfsetospeed.c
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <sys/types.h>
#include <termios.h>
#include <assert.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Public Variables
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: cfsetospeed
 *
 * Descripton:
 *   The cfsetospeed() function sets the output baud rate stored in the
 *   structure pointed to by termiosp to speed.
 *
 *   There is no effect on the baud rates set in the hardware until a
 *   subsequent successful call to tcsetattr() on the same termios structure.
 *
 *   NOTE 1: NuttX does not not control input/output baud rates independently
 *   Hense, this function is *identical* to cfsetispeed.
 *   NOTE 2.  In Nuttx, the speed_t is defined to be uint32_t and the baud
 *   encodings of termios.h are the actual baud values themselves.  Therefore,
 *   any baud value can be provided as the speed argument here.  However, if
 *   you do so, your code will *NOT* be portable to other environments where
 *   speed_t is smaller and where the termios.h baud values are encoded! To
 *   avoid portability issues, use the baud definitions in termios.h!
 *
 * Input Parameters:
 *   termiosp - The termiosp argument is a pointer to a termios structure.
 *   speed - The new output speed
 *
 * Returned Value:
 *   Baud is not checked... OK is always returned (this is non-standard
 *   behavior). 
 *
 ****************************************************************************/

int cfsetospeed(struct termios *termiosp, speed_t speed)
{
  FAR speed_t *speedp;

  DEBUGASSERT(termiosp);

  speedp = (FAR speed_t *)&termiosp->c_speed;
 *speedp = speed;

  return OK;
}
