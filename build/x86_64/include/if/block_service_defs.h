#ifndef __block_service_IF_H
#define __block_service_IF_H 1
/*
 * Copyright (c) 2010, ETH Zurich.
 * All rights reserved.
 * 
 * INTERFACE NAME: block_service
 * INTEFACE FILE: ../if/block_service.if
 * INTERFACE DESCRIPTION: block service interface
 * 
 * This file is distributed under the terms in the attached LICENSE
 * file. If you do not find this file, copies can be found by
 * writing to:
 * ETH Zurich D-INFK, Universitaetstr.6, CH-8092 Zurich.
 * Attn: Systems Group.
 * 
 * THIS FILE IS AUTOMATICALLY GENERATED BY FLOUNDER: DO NOT EDIT!
 */

#include <flounder/flounder.h>

/*
 * Concrete type definitions
 */
typedef uint64_t block_service_genpaddr_t;
typedef uint64_t block_service_genvaddr_t;
typedef uint32_t block_service_rsrcid_t;
typedef uint64_t block_service_errval_t;
typedef uint64_t block_service_cycles_t;
typedef uint32_t block_service_iref_t;
typedef uint8_t block_service_coreid_t;
typedef uint32_t block_service_domainid_t;

/*
 * Forward declaration of binding type
 */
struct block_service_binding;

/*
 * Contination (callback) and control function types
 */
typedef  void block_service_bind_continuation_fn(void *st, errval_t err, struct block_service_binding *_binding);
typedef  bool block_service_can_send_fn(struct block_service_binding *_binding);
typedef  errval_t block_service_register_send_fn(struct block_service_binding *_binding, struct waitset *ws, struct event_closure _continuation);
typedef  errval_t block_service_change_waitset_fn(struct block_service_binding *_binding, struct waitset *ws);
typedef  errval_t block_service_control_fn(struct block_service_binding *_binding, idc_control_t control);
typedef  void block_service_error_handler_fn(struct block_service_binding *_binding, errval_t err);

/*
 * Enumeration for message numbers
 */
typedef enum block_service_msg_enum {
    block_service___dummy__msgnum = 0,
    block_service___bind__msgnum = 1,
    block_service___bind_reply__msgnum = 2,
    block_service_read__msgnum = 3,
    block_service_setup__msgnum = 4,
    block_service_status__msgnum = 5
} block_service_msg_enum;

/*
 * Message type signatures (transmit)
 */
typedef  errval_t block_service_read__tx_method_fn(struct block_service_binding *_binding, struct event_closure _continuation, uint32_t start_block, uint32_t count, uint32_t seqn);
typedef  errval_t block_service_setup__tx_method_fn(struct block_service_binding *_binding, struct event_closure _continuation, iref_t tx_iref, iref_t rx_iref);
typedef  errval_t block_service_status__tx_method_fn(struct block_service_binding *_binding, struct event_closure _continuation, block_service_errval_t err, uint32_t seqn, uint32_t req);

/*
 * Message type signatures (receive)
 */
typedef  void block_service_read__rx_method_fn(struct block_service_binding *_binding, uint32_t start_block, uint32_t count, uint32_t seqn);
typedef  void block_service_setup__rx_method_fn(struct block_service_binding *_binding, iref_t tx_iref, iref_t rx_iref);
typedef  void block_service_status__rx_method_fn(struct block_service_binding *_binding, block_service_errval_t err, uint32_t seqn, uint32_t req);

/*
 * Struct type for holding the args for each msg
 */
struct block_service_read__args {
    uint32_t start_block;
    uint32_t count;
    uint32_t seqn;
};
struct block_service_setup__args {
    iref_t tx_iref;
    iref_t rx_iref;
};
struct block_service_status__args {
    block_service_errval_t err;
    uint32_t seqn;
    uint32_t req;
};

/*
 * Union type for all message arguments
 */
union block_service_arg_union {
    struct block_service_read__args read;
    struct block_service_setup__args setup;
    struct block_service_status__args status;
};

/*
 * VTable struct definition for the interface (transmit)
 */
struct block_service_tx_vtbl {
    block_service_read__tx_method_fn *read;
    block_service_setup__tx_method_fn *setup;
    block_service_status__tx_method_fn *status;
};

/*
 * VTable struct definition for the interface (receive)
 */
struct block_service_rx_vtbl {
    block_service_read__rx_method_fn *read;
    block_service_setup__rx_method_fn *setup;
    block_service_status__rx_method_fn *status;
};

/*
 * Incoming connect callback type
 */
typedef  errval_t block_service_connect_fn(void *st, struct block_service_binding *binding);

/*
 * Export state struct
 */
struct block_service_export {
    struct idc_export common;
    block_service_connect_fn *connect_cb;
    struct waitset *waitset;
    void *st;
};

/*
 * Export function
 */
extern  errval_t block_service_export(void *st, idc_export_callback_fn *export_cb, block_service_connect_fn *connect_cb, struct waitset *ws, idc_export_flags_t flags);

/*
 * The message buffer structure (for accept/connect)
 */
struct block_service_frameinfo {
    /* Physical address of send buffer */
    lpaddr_t sendbase;
    
    /* Pointer to incoming message buffer */
    void *inbuf;
    
    /* Size of the incoming buffer in bytes */
    size_t inbufsize;
    
    /* Pointer to outgoing message buffer */
    void *outbuf;
    
    /* Size of the outgoing buffer in bytes */
    size_t outbufsize;
    
};

/*
 * Accept function over already shared frame
 */
extern  errval_t block_service_accept(struct block_service_frameinfo *_frameinfo, void *st, block_service_bind_continuation_fn *_continuation, struct waitset *ws, idc_export_flags_t flags);

/*
 * The Binding structure
 */
struct block_service_binding {
    /* Arbitrary user state pointer */
    void *st;
    
    /* Waitset used for receive handlers and send continuations */
    struct waitset *waitset;
    
    /* Mutex for the use of user code. */
    /* Must be held before any operation where there is a possibility of */
    /* concurrent access to the same binding (eg. multiple threads, or */
    /* asynchronous event handlers that use the same binding object). */
    struct event_mutex mutex;
    
    /* returns true iff a message could currently be accepted by the binding */
    block_service_can_send_fn *can_send;
    
    /* register an event for when a message is likely to be able to be sent */
    block_service_register_send_fn *register_send;
    
    /* change the waitset used by a binding */
    block_service_change_waitset_fn *change_waitset;
    
    /* perform control operations */
    block_service_control_fn *control;
    
    /* error handler for any async errors associated with this binding */
    /* must be filled-in by user */
    block_service_error_handler_fn *error_handler;
    
    /* Message send functions (filled in by binding) */
    struct block_service_tx_vtbl tx_vtbl;
    
    /* Incoming message handlers (filled in by user) */
    struct block_service_rx_vtbl rx_vtbl;
    
    /* Private state belonging to the binding implementation */
    union block_service_arg_union tx_union;
    union block_service_arg_union rx_union;
    struct waitset_chanstate register_chanstate;
    struct waitset_chanstate tx_cont_chanstate;
    enum block_service_msg_enum tx_msgnum;
    enum block_service_msg_enum rx_msgnum;
    int tx_msg_fragment;
    int rx_msg_fragment;
    size_t tx_str_pos;
    size_t rx_str_pos;
    size_t tx_str_len;
    size_t rx_str_len;
    struct event_queue_node event_qnode;
    block_service_bind_continuation_fn *bind_cont;
};

/*
 * Generic bind function
 */
extern  errval_t block_service_bind(iref_t i, block_service_bind_continuation_fn *_continuation, void *st, struct waitset *waitset, idc_bind_flags_t flags);

/*
 * Generic connect function over already shared frame
 */
extern  errval_t block_service_connect(struct block_service_frameinfo *_frameinfo, block_service_bind_continuation_fn *_continuation, void *st, struct waitset *ws, idc_bind_flags_t flags);

/*
 * Send wrappers
 */
static inline errval_t block_service_read__tx(struct block_service_binding *_binding, struct event_closure _continuation, uint32_t start_block, uint32_t count, uint32_t seqn) __attribute__ ((always_inline));
static inline errval_t block_service_read__tx(struct block_service_binding *_binding, struct event_closure _continuation, uint32_t start_block, uint32_t count, uint32_t seqn)
{
    return(((_binding->tx_vtbl).read)(_binding, _continuation, start_block, count, seqn));
}

static inline errval_t block_service_setup__tx(struct block_service_binding *_binding, struct event_closure _continuation, iref_t tx_iref, iref_t rx_iref) __attribute__ ((always_inline));
static inline errval_t block_service_setup__tx(struct block_service_binding *_binding, struct event_closure _continuation, iref_t tx_iref, iref_t rx_iref)
{
    return(((_binding->tx_vtbl).setup)(_binding, _continuation, tx_iref, rx_iref));
}

static inline errval_t block_service_status__tx(struct block_service_binding *_binding, struct event_closure _continuation, block_service_errval_t err, uint32_t seqn, uint32_t req) __attribute__ ((always_inline));
static inline errval_t block_service_status__tx(struct block_service_binding *_binding, struct event_closure _continuation, block_service_errval_t err, uint32_t seqn, uint32_t req)
{
    return(((_binding->tx_vtbl).status)(_binding, _continuation, err, seqn, req));
}


/*
 * Backend-specific includes
 */
#ifdef CONFIG_FLOUNDER_BACKEND_LMP
#include <if/block_service_lmp_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_LMP
#ifdef CONFIG_FLOUNDER_BACKEND_UMP
#include <if/block_service_ump_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_UMP
#ifdef CONFIG_FLOUNDER_BACKEND_UMP_IPI
#include <if/block_service_ump_ipi_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_UMP_IPI
#ifdef CONFIG_FLOUNDER_BACKEND_MULTIHOP
#include <if/block_service_multihop_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_MULTIHOP
/*
 * And we're done
 */
#endif // __block_service_IF_H
