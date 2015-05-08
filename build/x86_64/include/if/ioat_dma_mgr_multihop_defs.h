#ifndef __ioat_dma_mgr_MULTIHOP_H
#define __ioat_dma_mgr_MULTIHOP_H 1
/*
 * Copyright (c) 2010, ETH Zurich.
 * All rights reserved.
 * 
 * INTERFACE NAME: ioat_dma_mgr
 * INTEFACE FILE: ../if/ioat_dma_mgr.if
 * INTERFACE DESCRIPTION: IOAT DMA manager interface
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

struct ioat_dma_mgr_multihop_binding {
    struct ioat_dma_mgr_binding b;
    struct multihop_chan chan;
    void *message;
    struct flounder_cap_state capst;
    bool trigger_chan;
};

extern  void ioat_dma_mgr_multihop_init(struct ioat_dma_mgr_multihop_binding *b, struct waitset *waitset);
extern  void ioat_dma_mgr_multihop_destroy(struct ioat_dma_mgr_multihop_binding *b);
extern  errval_t ioat_dma_mgr_multihop_bind(struct ioat_dma_mgr_multihop_binding *mb, iref_t iref, ioat_dma_mgr_bind_continuation_fn *_continuation, void *st, struct waitset *waitset, idc_bind_flags_t flags);
extern  errval_t ioat_dma_mgr_multihop_connect_handler(void *st, multihop_vci_t vci);
extern  void ioat_dma_mgr_multihop_rx_handler(void *arg, uint8_t *message, size_t message_len);
extern  void ioat_dma_mgr_multihop_caps_rx_handler(void *arg, errval_t success, struct capref cap, uint32_t capid);

#endif // __ioat_dma_mgr_MULTIHOP_H
