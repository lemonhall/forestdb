/*
 * Copyright 2013 Jung-Sang Ahn <jungsang.ahn@gmail.com>.
 * All Rights Reserved.
 */

#ifndef _JSAHN_DOCIO_H
#define _JSAHN_DOCIO_H

#include "filemgr.h"
#include "common.h"

typedef uint16_t keylen_t;

struct docio_handle {
	struct filemgr *file;
	bid_t curblock;
	uint32_t curpos;
};

struct docio_length {
	keylen_t keylen;
	uint16_t metalen;
	uint32_t bodylen;
};

struct docio_object {
	struct docio_length length;
	void *key;
	void *meta;
	void *body;
};

void docio_init(struct docio_handle *handle, struct filemgr *file);
INLINE bid_t docio_append_doc_raw(struct docio_handle *handle, uint64_t size, void *buf);
bid_t docio_append_doc(struct docio_handle *handle, struct docio_object *doc);
void docio_read_doc_key(struct docio_handle *handle, uint64_t offset, keylen_t *keylen, void *keybuf);
void docio_read_doc(struct docio_handle *handle, uint64_t offset, struct docio_object *doc);

#endif
