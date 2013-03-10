/******************************************************************************
Copyright 2009, Freie Universitaet Berlin (FUB). All rights reserved.

These sources were developed at the Freie Universitaet Berlin, Computer Systems
and Telematics group (http://cst.mi.fu-berlin.de).
-------------------------------------------------------------------------------
This file is part of RIOT.

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

RIOT is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see http://www.gnu.org/licenses/ .
--------------------------------------------------------------------------------
For further information and questions please use the web site
	http://scatterweb.mi.fu-berlin.de
and the mailinglist (subscription via web site)
	scatterweb@lists.spline.inf.fu-berlin.de
*******************************************************************************/

#include <stdarg.h>
#include "syslog.h"
#include "tracelog.h"

#undef  VSYSLOG
#define VSYSLOG(level, strModule, strFmt, argp)		vsyslog(level, strModule, strFmt, argp)

void
syslog(
		const uint8_t level,
		const char (*const strModule),
		const char* strFmt, ...
) {
	va_list argp;

	va_start(argp, strFmt);
	VSYSLOG(level, strModule, strFmt, argp);
	va_end(argp);
}
/*-----------------------------------------------------------------------------------*/
#if (SYSLOG_CONF_LEVEL & SL_EMERGENCY) == SL_EMERGENCY
void syslog_emergency(const char (*const mod), const char* strFmt, ...)
{
	va_list argp;

	va_start(argp, strFmt);
	VSYSLOG(SL_EMERGENCY, mod, strFmt, argp);
	va_end(argp);
}
#endif
/*-----------------------------------------------------------------------------------*/
#if (SYSLOG_CONF_LEVEL & SL_CRITICAL) == SL_CRITICAL
void syslog_critical(const char (*const mod), const char* strFmt, ...)
{
	va_list argp;

	va_start(argp, strFmt);
	VSYSLOG(SL_CRITICAL, mod, strFmt, argp);
	va_end(argp);
}
#endif
/*-----------------------------------------------------------------------------------*/
#if (SYSLOG_CONF_LEVEL & SL_WARN) == SL_WARN
void syslog_warn(const char (*const mod), const char* strFmt, ...)
{
	va_list argp;

	va_start(argp, strFmt);
	VSYSLOG(SL_WARN, mod, strFmt, argp);
	va_end(argp);
}
#endif
/*-----------------------------------------------------------------------------------*/
#if (SYSLOG_CONF_LEVEL & SL_NOTICE) == SL_NOTICE
void syslog_notice(const char (*const mod), const char* strFmt, ...)
{
	va_list argp;

	va_start(argp, strFmt);
	VSYSLOG(SL_NOTICE, mod, strFmt, argp);
	va_end(argp);
}
#endif
/*-----------------------------------------------------------------------------------*/
#if (SYSLOG_CONF_LEVEL & SL_INFO) == SL_INFO
void syslog_info(const char (*const mod), const char* strFmt, ...)
{
	va_list argp;

	va_start(argp, strFmt);
	VSYSLOG(SL_INFO, mod, strFmt, argp);
	va_end(argp);
}
#endif
/*-----------------------------------------------------------------------------------*/
#if SYSLOG_ISLEVEL(SL_DEBUG)
void syslog_debug(const char (*const mod), const char* strFmt, ...)
{
	va_list argp;

	va_start(argp, strFmt);
	VSYSLOG(SL_DEBUG, mod, strFmt, argp);
	va_end(argp);
}
#endif

