#ifndef __arrakis_RPC_CLIENT_H
#define __arrakis_RPC_CLIENT_H 1
/*
 * Copyright (c) 2010, ETH Zurich.
 * All rights reserved.
 * 
 * INTERFACE NAME: arrakis
 * INTEFACE FILE: ../if/arrakis.if
 * INTERFACE DESCRIPTION: Interface to arrakismon
 * 
 * This file is distributed under the terms in the attached LICENSE
 * file. If you do not find this file, copies can be found by
 * writing to:
 * ETH Zurich D-INFK, Universitaetstr.6, CH-8092 Zurich.
 * Attn: Systems Group.
 * 
 * THIS FILE IS AUTOMATICALLY GENERATED BY FLOUNDER: DO NOT EDIT!
 */

/*
 * RPC client
 */

#include <if/arrakis_defs.h>

/*
 * Forward declaration of binding type
 */
struct arrakis_rpc_client;

/*
 * Function signatures
 */
typedef  errval_t arrakis_spawn_arrakis_domain__rpc_method_fn(struct arrakis_rpc_client *_rpc, const char *path, const char *argvbuf, size_t argvbytes, const char *envbuf, size_t envbytes, arrakis_errval_t *err, arrakis_domainid_t *domain_id);

/*
 * VTable struct definition for the interface
 */
struct arrakis_rpc_vtbl {
    arrakis_spawn_arrakis_domain__rpc_method_fn *spawn_arrakis_domain;
};

/*
 * The Binding structure
 */
struct arrakis_rpc_client {
    struct arrakis_binding *b;
    struct arrakis_rpc_vtbl vtbl;
    bool rpc_in_progress;
    bool reply_present;
    errval_t async_error;
    struct waitset rpc_waitset;
    struct waitset_chanstate dummy_chanstate;
};

/*
 * Function to initialise an RPC client
 */
extern  errval_t arrakis_rpc_client_init(struct arrakis_rpc_client *rpc, struct arrakis_binding *binding);

#endif // __arrakis_RPC_CLIENT_H
