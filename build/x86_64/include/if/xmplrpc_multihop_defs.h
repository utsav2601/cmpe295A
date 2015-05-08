#ifndef __xmplrpc_MULTIHOP_H
#define __xmplrpc_MULTIHOP_H 1
/*
 * Copyright (c) 2010, ETH Zurich.
 * All rights reserved.
 * 
 * INTERFACE NAME: xmplrpc
 * INTEFACE FILE: ../if/xmplrpc.if
 * INTERFACE DESCRIPTION: Example rpc interface
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
 * Multihop interconnect driver
 */

#include <barrelfish/multihop_chan.h>

struct xmplrpc_multihop_binding {
    struct xmplrpc_binding b;
    struct multihop_chan chan;
    void *message;
    struct flounder_cap_state capst;
    bool trigger_chan;
};

extern  void xmplrpc_multihop_init(struct xmplrpc_multihop_binding *b, struct waitset *waitset);
extern  void xmplrpc_multihop_destroy(struct xmplrpc_multihop_binding *b);
extern  errval_t xmplrpc_multihop_bind(struct xmplrpc_multihop_binding *mb, iref_t iref, xmplrpc_bind_continuation_fn *_continuation, void *st, struct waitset *waitset, idc_bind_flags_t flags);
extern  errval_t xmplrpc_multihop_connect_handler(void *st, multihop_vci_t vci);
extern  void xmplrpc_multihop_rx_handler(void *arg, uint8_t *message, size_t message_len);
extern  void xmplrpc_multihop_caps_rx_handler(void *arg, errval_t success, struct capref cap, uint32_t capid);

#endif // __xmplrpc_MULTIHOP_H
