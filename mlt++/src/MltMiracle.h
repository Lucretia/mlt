/**
 * MltMiracle.h - MLT Wrapper
 * Copyright (C) 2004-2005 Charles Yates
 * Author: Charles Yates <charles.yates@pandora.be>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef _MLTPP_MIRACLE_H_
#define _MLTPP_MIRACLE_H_

#include <miracle/miracle_server.h>
#include <miracle/miracle_log.h>
#include "MltService.h"

namespace Mlt
{
	class Properties;
	class Service;
	class Response;

	class Miracle : public Properties
	{
		private:
			miracle_server server;
			void *_real;
			parser_execute _execute;
			parser_received _received;
			parser_push _push;
		public:
			Miracle( char *name, int port = 5250, char *config = NULL );
			virtual ~Miracle( );
			mlt_properties get_properties( );
			bool start( );
			bool is_running( );
			virtual Response *execute( char *command );
			virtual Response *received( char *command, char *doc );
			virtual Response *push( char *command, Service *service );
			void wait_for_shutdown( );
			static void log_level( int );
	};
}

#endif

