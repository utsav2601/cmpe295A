#ifndef __dma_mgr_MULTIHOP_H
#define __dma_mgr_MULTIHOP_H 1
/*
 * Copyright (c) 2010, ETH Zurich.
 * All rights reserved.
 * 
 * INTERFACE NAME: dma_mgr
 * INTEFACE FILE: ../if/dma_mgr.if
 * INTERFACE DESCRIPTION: DMA Manager Interface
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

struct dma_mgr_multihop_binding {
    struct dma_mgr_binding b;
    struct multihop_chan chan;
    void *message;
    struct flounder_cap_state capst;
    bool trigger_chan;
};

extern  void dma_mgr_multihop_init(struct dma_mgr_multihop_binding *b, struct waitset *waitset);
extern  void dma_mgr_multihop_destroy(struct dma_mgr_multihop_binding *b);
extern  errval_t dma_mgr_multihop_bind(struct dma_mgr_multihop_binding *mb, iref_t iref, dma_mgr_bind_continuation_fn *_continuation, void *st, struct waitset *waitset, idc_bind_flags_t flags);
extern  errval_t dma_mgr_multihop_connect_handler(void *st, multihop_vci_t vci);
extern  void dma_mgr_multihop_rx_handler(void *arg, uint8_t *message, size_t message_len);
extern  void dma_mgr_multihop_caps_rx_handler(void *arg, errval_t success, struct capref cap, uint32_t capid);

#endif // __dma_mgr_MULTIHOP_H
