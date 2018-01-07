/*
 *
 *   Copyright (C) 2012-2018 by C.H. Huang
 *   plushuang.tw@gmail.com
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *  ---
 *
 *  In addition, as a special exception, the copyright holders give
 *  permission to link the code of portions of this program with the
 *  OpenSSL library under certain conditions as described in each
 *  individual source file, and distribute linked combinations
 *  including the two.
 *  You must obey the GNU Lesser General Public License in all respects
 *  for all of the code used other than OpenSSL.  If you modify
 *  file(s) with this exception, you may extend this exception to your
 *  version of the file(s), but you are not obligated to do so.  If you
 *  do not wish to do so, delete this exception statement from your
 *  version.  If you delete this exception statement from all source
 *  files in the program, then also delete it here.
 *
 */

#ifndef UGET_DATA_H
#define UGET_DATA_H

#include <stdint.h>
#include <UgData.h>
#include <UgetPlugin.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct  UgetCommon      UgetCommon;
typedef struct  UgetProgress    UgetProgress;
typedef struct  UgetProxy       UgetProxy;
typedef struct  UgetHttp        UgetHttp;
typedef struct  UgetFtp         UgetFtp;
typedef struct  UgetLog         UgetLog;
typedef struct  UgetRelation    UgetRelation;
typedef struct  UgetCategory    UgetCategory;

extern const UgDataInfo*  UgetCommonInfo;
extern const UgDataInfo*  UgetProgressInfo;
extern const UgDataInfo*  UgetProxyInfo;
extern const UgDataInfo*  UgetHttpInfo;
extern const UgDataInfo*  UgetFtpInfo;
extern const UgDataInfo*  UgetLogInfo;
extern const UgDataInfo*  UgetRelationInfo;
extern const UgDataInfo*  UgetCategoryInfo;

// ----------------------------------------------------------------------------
// UgetCommon: It derived from UgData and store in UgMap.

struct UgetCommon
{
	UG_DATA_MEMBERS;           // It derived from UgData
//	const UgDataInfo*  info;

//	char*   name;
	char*   uri;
	char*   mirrors;
	char*   file;
	char*   folder;
	char*   user;
	char*   password;

	// timeout
	unsigned int  connect_timeout;    // second
	unsigned int  transmit_timeout;   // second
	// retry
	int           retry_delay;        // second
	int           retry_limit;        // limit of retry_count
	int           retry_count;

	unsigned int  max_connections;    // max connections per server
	int           max_upload_speed;   // bytes per seconds
	int           max_download_speed; // bytes per seconds

	// retrieve timestamp of the remote file if it is available.
	int           timestamp;          // retrieve file timestamp
	// debug
	int           debug_level;

	// keeping flags used by ug_data_assign ()
	// They works like read-only
	struct {
		uint8_t   enable:1;

//		uint8_t   name:1;
		uint8_t   uri:1;
		uint8_t   mirrors:1;
		uint8_t   file:1;
		uint8_t   folder:1;
		uint8_t   user:1;
		uint8_t   password:1;
		uint8_t   timestamp:1;
		uint8_t   connect_timeout:1;
		uint8_t   transmit_timeout:1;
		uint8_t   retry_delay:1;
		uint8_t   retry_limit:1;

		uint8_t   max_connections:1;
		uint8_t   max_upload_speed:1;
		uint8_t   max_download_speed:1;

		uint8_t   discard_timestamp:1;
		uint8_t   debug_level:1;
	} keeping;
};

// ----------------------------------------------------------------------------
// UgetProgress: It derived from UgData and store in UgMap.

struct UgetProgress
{
	UG_DATA_MEMBERS;           // It derived from UgData
//	const UgDataInfo*  info;

	int64_t      elapsed;     // consume time (seconds)
	int64_t      left;        // remain time  (seconds)
	int64_t      complete;    // complete size
	int64_t      total;       // total size
	// torrent - upload
	int64_t      uploaded;
	double       ratio;
	int          upload_speed;
	// other
	int          download_speed;
	int          percent;
};

// ----------------------------------------------------------------------------
// UgetProxy: It derived from UgData and store in UgMap.

typedef enum
{
	UGET_PROXY_NONE,
	UGET_PROXY_DEFAULT,      // Decided by plug-ins
	UGET_PROXY_HTTP,
	UGET_PROXY_SOCKS4,
	UGET_PROXY_SOCKS5,
#ifdef HAVE_LIBPWMD
	UGET_PROXY_PWMD,
#endif

	UGET_PROXY_N_TYPE,
} UgetProxyType;

struct UgetProxy
{
	UG_DATA_MEMBERS;           // It derived from UgData
//	const UgDataInfo*  info;

	char*          host;
	unsigned int   port;
	UgetProxyType  type;

	char*          user;
	char*          password;

	struct {
		uint8_t    enable:1;

		uint8_t    host:1;
		uint8_t    port:1;
		uint8_t    type:1;

		uint8_t    user:1;
		uint8_t    password:1;
	} keeping;

#ifdef HAVE_LIBPWMD
	struct UgetProxyPwmd {
		char*  socket;
		char*  socket_args;
		char*  file;
		char*  element;

		struct {
			uint8_t    socket:1;
			uint8_t    socket_args:1;
			uint8_t    file:1;
			uint8_t    element:1;
		} keeping;
	} pwmd;
#endif	// HAVE_LIBPWMD
};

// ----------------------------------------------------------------------------
// UgetHttp: It derived from UgData and store in UgMap.

struct UgetHttp
{
	UG_DATA_MEMBERS;           // It derived from UgData
//	const UgDataInfo*  info;

	char*  user;
	char*  password;
	char*  referrer;
	char*  user_agent;

	char*  post_data;
	char*  post_file;
	char*  cookie_data;
	char*  cookie_file;

	unsigned int  redirection_limit;    // limit of redirection_count
	unsigned int  redirection_count;    // count of redirection

	struct {
		uint8_t    enable:1;

		uint8_t    user:1;
		uint8_t    password:1;
		uint8_t    referrer:1;
		uint8_t    user_agent:1;

		uint8_t    post_data:1;
		uint8_t    post_file:1;
		uint8_t    cookie_data:1;
		uint8_t    cookie_file:1;
		uint8_t    redirection_limit:1;
	} keeping;
};

// ----------------------------------------------------------------------------
// UgetFtp: It derived from UgData and store in UgMap.

struct UgetFtp
{
	UG_DATA_MEMBERS;           // It derived from UgData
//	const UgDataInfo*  iface;

	char*		 user;
	char*		 password;

	int          active_mode;

	struct {
		uint8_t    enable:1;

		uint8_t    user:1;
		uint8_t    password:1;
		uint8_t    active_mode:1;
	} keeping;
};

// ---------------------------------------------------------------------------
// UgetLog

struct UgetLog
{
	UG_DATA_MEMBERS;           // It derived from UgData
//	const UgDataInfo*  info;

	time_t  added_time;
	time_t  completed_time;

	UgList  messages;          // List for UgetEvent
};

// ----------------------------------------------------------------------------
// UgetRelation: It derived from UgData and store in UgMap.

typedef enum
{
	UGET_PRIORITY_LOW,      // 0
	UGET_PRIORITY_NORMAL,   // default
	UGET_PRIORITY_HIGH
} UgetPriority;

struct UgetRelation
{
	UG_DATA_MEMBERS;           // It derived from UgData
//	const UgDataInfo*  info;

	// used by UgetTask
	struct UgetRelationTask {
		UgetRelation*  prev;
		UgetPlugin*  plugin;
		char*        plugin_name;
		int          priority;   // UgetPriority
		// speed control
		int          speed[2];   // current speed
		int          limit[2];   // current speed limit
	} task;

	// call destroy.func(destroy.data) when destroying.
	struct {
		UgNotifyFunc func;
		void*        data;
	} destroy;

	// used by user application
	struct {
		void*  pointer;
		void*  storage;
		void*  position;
		void*  data[4];
	} user;
};

// ----------------------------------------------------------------------------
// UgetCategory: It derived from UgData and store in UgMap.

struct UgetCategory
{
	UG_DATA_MEMBERS;           // It derived from UgData
//	const UgDataInfo*  info;

	// use these to classify download
	UgArrayStr    hosts;
	UgArrayStr    schemes;
	UgArrayStr    file_exts;

	// limit
	int        active_limit;
	int        finished_limit; // finished: completed and paused
	int        recycled_limit;

	// 4 fake sub-category tree
	UgetNode*  active;
	UgetNode*  queuing;
	UgetNode*  finished;
	UgetNode*  recycled;
};


#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------
// C++11 standard-layout

#ifdef __cplusplus

namespace Uget
{

// These are for directly use only. You can NOT derived it.
struct Common : Ug::DataMethod, UgetCommon {};
struct Progress : Ug::DataMethod, UgetProgress {};
struct Proxy : Ug::DataMethod, UgetProxy {};
struct Http : Ug::DataMethod, UgetHttp {};
struct Ftp : Ug::DataMethod, UgetFtp {};
struct Log : Ug::DataMethod, UgetLog {};
struct Relation : Ug::DataMethod, UgetRelation {};
struct Category : Ug::DataMethod, UgetCategory {};

};  // namespace Uget

#endif  // __cplusplus


#endif  // End of UGET_DATA_H

