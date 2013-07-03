/*
 * Asterisk -- An open source telephony toolkit.
 *
 * Copyright (C) 2012 - 2013, Digium, Inc.
 *
 * David M. Lee, II <dlee@digium.com>
 *
 * See http://www.asterisk.org for more information about
 * the Asterisk project. Please do not directly contact
 * any of the maintainers of this project for assistance;
 * the project provides a web site, mailing lists and IRC
 * channels for your use.
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2. See the LICENSE file
 * at the top of the source tree.
 */

/*
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * !!!!!                               DO NOT EDIT                        !!!!!
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * This file is generated by a mustache template. Please see the original
 * template in rest-api-templates/res_stasis_http_resource.c.mustache
 */

/*! \file
 *
 * \brief Recording resources
 *
 * \author David M. Lee, II <dlee@digium.com>
 */

/*** MODULEINFO
	<depend type="module">res_stasis_http</depend>
	<depend type="module">res_stasis</depend>
	<support_level>core</support_level>
 ***/

#include "asterisk.h"

ASTERISK_FILE_VERSION(__FILE__, "$Revision$")

#include "asterisk/module.h"
#include "asterisk/stasis_app.h"
#include "stasis_http/resource_recordings.h"

/*!
 * \brief Parameter parsing callback for /recordings.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_get_recordings_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_get_recordings_args args = {};
	stasis_http_get_recordings(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /recordings/stored.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_get_stored_recordings_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_get_stored_recordings_args args = {};
	stasis_http_get_stored_recordings(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /recordings/stored/{recordingId}.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_get_stored_recording_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_get_stored_recording_args args = {};
	struct ast_variable *i;

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingId") == 0) {
			args.recording_id = (i->value);
		} else
		{}
	}
	stasis_http_get_stored_recording(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /recordings/stored/{recordingId}.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_delete_stored_recording_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_delete_stored_recording_args args = {};
	struct ast_variable *i;

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingId") == 0) {
			args.recording_id = (i->value);
		} else
		{}
	}
	stasis_http_delete_stored_recording(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /recordings/live.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_get_live_recordings_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_get_live_recordings_args args = {};
	stasis_http_get_live_recordings(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /recordings/live/{recordingId}.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_get_live_recording_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_get_live_recording_args args = {};
	struct ast_variable *i;

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingId") == 0) {
			args.recording_id = (i->value);
		} else
		{}
	}
	stasis_http_get_live_recording(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /recordings/live/{recordingId}.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_cancel_recording_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_cancel_recording_args args = {};
	struct ast_variable *i;

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingId") == 0) {
			args.recording_id = (i->value);
		} else
		{}
	}
	stasis_http_cancel_recording(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /recordings/live/{recordingId}/stop.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_stop_recording_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_stop_recording_args args = {};
	struct ast_variable *i;

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingId") == 0) {
			args.recording_id = (i->value);
		} else
		{}
	}
	stasis_http_stop_recording(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /recordings/live/{recordingId}/pause.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_pause_recording_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_pause_recording_args args = {};
	struct ast_variable *i;

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingId") == 0) {
			args.recording_id = (i->value);
		} else
		{}
	}
	stasis_http_pause_recording(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /recordings/live/{recordingId}/unpause.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_unpause_recording_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_unpause_recording_args args = {};
	struct ast_variable *i;

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingId") == 0) {
			args.recording_id = (i->value);
		} else
		{}
	}
	stasis_http_unpause_recording(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /recordings/live/{recordingId}/mute.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_mute_recording_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_mute_recording_args args = {};
	struct ast_variable *i;

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingId") == 0) {
			args.recording_id = (i->value);
		} else
		{}
	}
	stasis_http_mute_recording(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /recordings/live/{recordingId}/unmute.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_unmute_recording_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_unmute_recording_args args = {};
	struct ast_variable *i;

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "recordingId") == 0) {
			args.recording_id = (i->value);
		} else
		{}
	}
	stasis_http_unmute_recording(headers, &args, response);
}

/*! \brief REST handler for /api-docs/recordings.{format} */
static struct stasis_rest_handlers recordings_stored_recordingId = {
	.path_segment = "recordingId",
	.is_wildcard = 1,
	.callbacks = {
		[AST_HTTP_GET] = stasis_http_get_stored_recording_cb,
		[AST_HTTP_DELETE] = stasis_http_delete_stored_recording_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/recordings.{format} */
static struct stasis_rest_handlers recordings_stored = {
	.path_segment = "stored",
	.callbacks = {
		[AST_HTTP_GET] = stasis_http_get_stored_recordings_cb,
	},
	.num_children = 1,
	.children = { &recordings_stored_recordingId, }
};
/*! \brief REST handler for /api-docs/recordings.{format} */
static struct stasis_rest_handlers recordings_live_recordingId_stop = {
	.path_segment = "stop",
	.callbacks = {
		[AST_HTTP_POST] = stasis_http_stop_recording_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/recordings.{format} */
static struct stasis_rest_handlers recordings_live_recordingId_pause = {
	.path_segment = "pause",
	.callbacks = {
		[AST_HTTP_POST] = stasis_http_pause_recording_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/recordings.{format} */
static struct stasis_rest_handlers recordings_live_recordingId_unpause = {
	.path_segment = "unpause",
	.callbacks = {
		[AST_HTTP_POST] = stasis_http_unpause_recording_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/recordings.{format} */
static struct stasis_rest_handlers recordings_live_recordingId_mute = {
	.path_segment = "mute",
	.callbacks = {
		[AST_HTTP_POST] = stasis_http_mute_recording_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/recordings.{format} */
static struct stasis_rest_handlers recordings_live_recordingId_unmute = {
	.path_segment = "unmute",
	.callbacks = {
		[AST_HTTP_POST] = stasis_http_unmute_recording_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/recordings.{format} */
static struct stasis_rest_handlers recordings_live_recordingId = {
	.path_segment = "recordingId",
	.is_wildcard = 1,
	.callbacks = {
		[AST_HTTP_GET] = stasis_http_get_live_recording_cb,
		[AST_HTTP_DELETE] = stasis_http_cancel_recording_cb,
	},
	.num_children = 5,
	.children = { &recordings_live_recordingId_stop,&recordings_live_recordingId_pause,&recordings_live_recordingId_unpause,&recordings_live_recordingId_mute,&recordings_live_recordingId_unmute, }
};
/*! \brief REST handler for /api-docs/recordings.{format} */
static struct stasis_rest_handlers recordings_live = {
	.path_segment = "live",
	.callbacks = {
		[AST_HTTP_GET] = stasis_http_get_live_recordings_cb,
	},
	.num_children = 1,
	.children = { &recordings_live_recordingId, }
};
/*! \brief REST handler for /api-docs/recordings.{format} */
static struct stasis_rest_handlers recordings = {
	.path_segment = "recordings",
	.callbacks = {
		[AST_HTTP_GET] = stasis_http_get_recordings_cb,
	},
	.num_children = 2,
	.children = { &recordings_stored,&recordings_live, }
};

static int load_module(void)
{
	int res = 0;
	stasis_app_ref();
	res |= stasis_http_add_handler(&recordings);
	return res;
}

static int unload_module(void)
{
	stasis_http_remove_handler(&recordings);
	stasis_app_unref();
	return 0;
}

AST_MODULE_INFO(ASTERISK_GPL_KEY, AST_MODFLAG_DEFAULT, "RESTful API module - Recording resources",
	.load = load_module,
	.unload = unload_module,
	.nonoptreq = "res_stasis_http,res_stasis",
	);
