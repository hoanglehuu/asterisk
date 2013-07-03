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
 * \brief Channel resources
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
#include "stasis_http/resource_channels.h"

/*!
 * \brief Parameter parsing callback for /channels.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_get_channels_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_get_channels_args args = {};
	stasis_http_get_channels(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /channels.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_originate_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_originate_args args = {};
	struct ast_variable *i;

	for (i = get_params; i; i = i->next) {
		if (strcmp(i->name, "endpoint") == 0) {
			args.endpoint = (i->value);
		} else
		if (strcmp(i->name, "extension") == 0) {
			args.extension = (i->value);
		} else
		if (strcmp(i->name, "context") == 0) {
			args.context = (i->value);
		} else
		if (strcmp(i->name, "priority") == 0) {
			args.priority = atol(i->value);
		} else
		if (strcmp(i->name, "app") == 0) {
			args.app = (i->value);
		} else
		if (strcmp(i->name, "appArgs") == 0) {
			args.app_args = (i->value);
		} else
		if (strcmp(i->name, "callerId") == 0) {
			args.caller_id = (i->value);
		} else
		if (strcmp(i->name, "timeout") == 0) {
			args.timeout = atoi(i->value);
		} else
		{}
	}
	stasis_http_originate(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /channels/{channelId}.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_get_channel_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_get_channel_args args = {};
	struct ast_variable *i;

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "channelId") == 0) {
			args.channel_id = (i->value);
		} else
		{}
	}
	stasis_http_get_channel(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /channels/{channelId}.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_delete_channel_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_delete_channel_args args = {};
	struct ast_variable *i;

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "channelId") == 0) {
			args.channel_id = (i->value);
		} else
		{}
	}
	stasis_http_delete_channel(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /channels/{channelId}/dial.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_dial_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_dial_args args = {};
	struct ast_variable *i;

	for (i = get_params; i; i = i->next) {
		if (strcmp(i->name, "endpoint") == 0) {
			args.endpoint = (i->value);
		} else
		if (strcmp(i->name, "extension") == 0) {
			args.extension = (i->value);
		} else
		if (strcmp(i->name, "context") == 0) {
			args.context = (i->value);
		} else
		if (strcmp(i->name, "timeout") == 0) {
			args.timeout = atoi(i->value);
		} else
		{}
	}
	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "channelId") == 0) {
			args.channel_id = (i->value);
		} else
		{}
	}
	stasis_http_dial(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /channels/{channelId}/continue.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_continue_in_dialplan_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_continue_in_dialplan_args args = {};
	struct ast_variable *i;

	for (i = get_params; i; i = i->next) {
		if (strcmp(i->name, "context") == 0) {
			args.context = (i->value);
		} else
		if (strcmp(i->name, "extension") == 0) {
			args.extension = (i->value);
		} else
		if (strcmp(i->name, "priority") == 0) {
			args.priority = atoi(i->value);
		} else
		{}
	}
	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "channelId") == 0) {
			args.channel_id = (i->value);
		} else
		{}
	}
	stasis_http_continue_in_dialplan(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /channels/{channelId}/answer.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_answer_channel_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_answer_channel_args args = {};
	struct ast_variable *i;

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "channelId") == 0) {
			args.channel_id = (i->value);
		} else
		{}
	}
	stasis_http_answer_channel(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /channels/{channelId}/mute.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_mute_channel_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_mute_channel_args args = {};
	struct ast_variable *i;

	for (i = get_params; i; i = i->next) {
		if (strcmp(i->name, "direction") == 0) {
			args.direction = (i->value);
		} else
		{}
	}
	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "channelId") == 0) {
			args.channel_id = (i->value);
		} else
		{}
	}
	stasis_http_mute_channel(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /channels/{channelId}/unmute.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_unmute_channel_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_unmute_channel_args args = {};
	struct ast_variable *i;

	for (i = get_params; i; i = i->next) {
		if (strcmp(i->name, "direction") == 0) {
			args.direction = (i->value);
		} else
		{}
	}
	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "channelId") == 0) {
			args.channel_id = (i->value);
		} else
		{}
	}
	stasis_http_unmute_channel(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /channels/{channelId}/hold.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_hold_channel_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_hold_channel_args args = {};
	struct ast_variable *i;

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "channelId") == 0) {
			args.channel_id = (i->value);
		} else
		{}
	}
	stasis_http_hold_channel(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /channels/{channelId}/unhold.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_unhold_channel_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_unhold_channel_args args = {};
	struct ast_variable *i;

	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "channelId") == 0) {
			args.channel_id = (i->value);
		} else
		{}
	}
	stasis_http_unhold_channel(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /channels/{channelId}/play.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_play_on_channel_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_play_on_channel_args args = {};
	struct ast_variable *i;

	for (i = get_params; i; i = i->next) {
		if (strcmp(i->name, "media") == 0) {
			args.media = (i->value);
		} else
		if (strcmp(i->name, "lang") == 0) {
			args.lang = (i->value);
		} else
		if (strcmp(i->name, "offsetms") == 0) {
			args.offsetms = atoi(i->value);
		} else
		if (strcmp(i->name, "skipms") == 0) {
			args.skipms = atoi(i->value);
		} else
		{}
	}
	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "channelId") == 0) {
			args.channel_id = (i->value);
		} else
		{}
	}
	stasis_http_play_on_channel(headers, &args, response);
}
/*!
 * \brief Parameter parsing callback for /channels/{channelId}/record.
 * \param get_params GET parameters in the HTTP request.
 * \param path_vars Path variables extracted from the request.
 * \param headers HTTP headers.
 * \param[out] response Response to the HTTP request.
 */
static void stasis_http_record_channel_cb(
    struct ast_variable *get_params, struct ast_variable *path_vars,
    struct ast_variable *headers, struct stasis_http_response *response)
{
	struct ast_record_channel_args args = {};
	struct ast_variable *i;

	for (i = get_params; i; i = i->next) {
		if (strcmp(i->name, "name") == 0) {
			args.name = (i->value);
		} else
		if (strcmp(i->name, "format") == 0) {
			args.format = (i->value);
		} else
		if (strcmp(i->name, "maxDurationSeconds") == 0) {
			args.max_duration_seconds = atoi(i->value);
		} else
		if (strcmp(i->name, "maxSilenceSeconds") == 0) {
			args.max_silence_seconds = atoi(i->value);
		} else
		if (strcmp(i->name, "append") == 0) {
			args.append = atoi(i->value);
		} else
		if (strcmp(i->name, "beep") == 0) {
			args.beep = atoi(i->value);
		} else
		if (strcmp(i->name, "terminateOn") == 0) {
			args.terminate_on = (i->value);
		} else
		{}
	}
	for (i = path_vars; i; i = i->next) {
		if (strcmp(i->name, "channelId") == 0) {
			args.channel_id = (i->value);
		} else
		{}
	}
	stasis_http_record_channel(headers, &args, response);
}

/*! \brief REST handler for /api-docs/channels.{format} */
static struct stasis_rest_handlers channels_channelId_dial = {
	.path_segment = "dial",
	.callbacks = {
		[AST_HTTP_POST] = stasis_http_dial_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/channels.{format} */
static struct stasis_rest_handlers channels_channelId_continue = {
	.path_segment = "continue",
	.callbacks = {
		[AST_HTTP_POST] = stasis_http_continue_in_dialplan_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/channels.{format} */
static struct stasis_rest_handlers channels_channelId_answer = {
	.path_segment = "answer",
	.callbacks = {
		[AST_HTTP_POST] = stasis_http_answer_channel_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/channels.{format} */
static struct stasis_rest_handlers channels_channelId_mute = {
	.path_segment = "mute",
	.callbacks = {
		[AST_HTTP_POST] = stasis_http_mute_channel_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/channels.{format} */
static struct stasis_rest_handlers channels_channelId_unmute = {
	.path_segment = "unmute",
	.callbacks = {
		[AST_HTTP_POST] = stasis_http_unmute_channel_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/channels.{format} */
static struct stasis_rest_handlers channels_channelId_hold = {
	.path_segment = "hold",
	.callbacks = {
		[AST_HTTP_POST] = stasis_http_hold_channel_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/channels.{format} */
static struct stasis_rest_handlers channels_channelId_unhold = {
	.path_segment = "unhold",
	.callbacks = {
		[AST_HTTP_POST] = stasis_http_unhold_channel_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/channels.{format} */
static struct stasis_rest_handlers channels_channelId_play = {
	.path_segment = "play",
	.callbacks = {
		[AST_HTTP_POST] = stasis_http_play_on_channel_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/channels.{format} */
static struct stasis_rest_handlers channels_channelId_record = {
	.path_segment = "record",
	.callbacks = {
		[AST_HTTP_POST] = stasis_http_record_channel_cb,
	},
	.num_children = 0,
	.children = {  }
};
/*! \brief REST handler for /api-docs/channels.{format} */
static struct stasis_rest_handlers channels_channelId = {
	.path_segment = "channelId",
	.is_wildcard = 1,
	.callbacks = {
		[AST_HTTP_GET] = stasis_http_get_channel_cb,
		[AST_HTTP_DELETE] = stasis_http_delete_channel_cb,
	},
	.num_children = 9,
	.children = { &channels_channelId_dial,&channels_channelId_continue,&channels_channelId_answer,&channels_channelId_mute,&channels_channelId_unmute,&channels_channelId_hold,&channels_channelId_unhold,&channels_channelId_play,&channels_channelId_record, }
};
/*! \brief REST handler for /api-docs/channels.{format} */
static struct stasis_rest_handlers channels = {
	.path_segment = "channels",
	.callbacks = {
		[AST_HTTP_GET] = stasis_http_get_channels_cb,
		[AST_HTTP_POST] = stasis_http_originate_cb,
	},
	.num_children = 1,
	.children = { &channels_channelId, }
};

static int load_module(void)
{
	int res = 0;
	stasis_app_ref();
	res |= stasis_http_add_handler(&channels);
	return res;
}

static int unload_module(void)
{
	stasis_http_remove_handler(&channels);
	stasis_app_unref();
	return 0;
}

AST_MODULE_INFO(ASTERISK_GPL_KEY, AST_MODFLAG_DEFAULT, "RESTful API module - Channel resources",
	.load = load_module,
	.unload = unload_module,
	.nonoptreq = "res_stasis_http,res_stasis",
	);
