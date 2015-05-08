#ifndef __replay_IF_H
#define __replay_IF_H 1
/*
 * Copyright (c) 2010, ETH Zurich.
 * All rights reserved.
 * 
 * INTERFACE NAME: replay
 * INTEFACE FILE: ../if/replay.if
 * INTERFACE DESCRIPTION: Trace replay
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
typedef uint64_t replay_genpaddr_t;
typedef uint64_t replay_genvaddr_t;
typedef uint32_t replay_rsrcid_t;
typedef uint64_t replay_errval_t;
typedef uint64_t replay_cycles_t;
typedef uint32_t replay_iref_t;
typedef uint8_t replay_coreid_t;
typedef uint32_t replay_domainid_t;

/*
 * Forward declaration of binding type
 */
struct replay_binding;

/*
 * Contination (callback) and control function types
 */
typedef  void replay_bind_continuation_fn(void *st, errval_t err, struct replay_binding *_binding);
typedef  bool replay_can_send_fn(struct replay_binding *_binding);
typedef  errval_t replay_register_send_fn(struct replay_binding *_binding, struct waitset *ws, struct event_closure _continuation);
typedef  errval_t replay_change_waitset_fn(struct replay_binding *_binding, struct waitset *ws);
typedef  errval_t replay_control_fn(struct replay_binding *_binding, idc_control_t control);
typedef  void replay_error_handler_fn(struct replay_binding *_binding, errval_t err);

/*
 * Enumeration for message numbers
 */
typedef enum replay_msg_enum {
    replay___dummy__msgnum = 0,
    replay___bind__msgnum = 1,
    replay___bind_reply__msgnum = 2,
    replay_slave_init__msgnum = 3,
    replay_slave_init_reply__msgnum = 4,
    replay_new_task__msgnum = 5,
    replay_task_completed__msgnum = 6,
    replay_slave_finish__msgnum = 7,
    replay_slave_finish_reply__msgnum = 8,
    replay_slave_print_stats__msgnum = 9,
    replay_slave_print_stats_reply__msgnum = 10
} replay_msg_enum;

/*
 * Message type signatures (transmit)
 */
typedef  errval_t replay_slave_init__tx_method_fn(struct replay_binding *_binding, struct event_closure _continuation, struct capref shared_mem, uint32_t size);
typedef  errval_t replay_slave_init_reply__tx_method_fn(struct replay_binding *_binding, struct event_closure _continuation);
typedef  errval_t replay_new_task__tx_method_fn(struct replay_binding *_binding, struct event_closure _continuation, uint64_t bulk_id, uint32_t size);
typedef  errval_t replay_task_completed__tx_method_fn(struct replay_binding *_binding, struct event_closure _continuation, uint16_t pid, uint64_t bulk_id);
typedef  errval_t replay_slave_finish__tx_method_fn(struct replay_binding *_binding, struct event_closure _continuation);
typedef  errval_t replay_slave_finish_reply__tx_method_fn(struct replay_binding *_binding, struct event_closure _continuation);
typedef  errval_t replay_slave_print_stats__tx_method_fn(struct replay_binding *_binding, struct event_closure _continuation);
typedef  errval_t replay_slave_print_stats_reply__tx_method_fn(struct replay_binding *_binding, struct event_closure _continuation);

/*
 * Message type signatures (receive)
 */
typedef  void replay_slave_init__rx_method_fn(struct replay_binding *_binding, struct capref shared_mem, uint32_t size);
typedef  void replay_slave_init_reply__rx_method_fn(struct replay_binding *_binding);
typedef  void replay_new_task__rx_method_fn(struct replay_binding *_binding, uint64_t bulk_id, uint32_t size);
typedef  void replay_task_completed__rx_method_fn(struct replay_binding *_binding, uint16_t pid, uint64_t bulk_id);
typedef  void replay_slave_finish__rx_method_fn(struct replay_binding *_binding);
typedef  void replay_slave_finish_reply__rx_method_fn(struct replay_binding *_binding);
typedef  void replay_slave_print_stats__rx_method_fn(struct replay_binding *_binding);
typedef  void replay_slave_print_stats_reply__rx_method_fn(struct replay_binding *_binding);

/*
 * Struct type for holding the args for each msg
 */
struct replay_slave_init__args {
    struct capref shared_mem;
    uint32_t size;
};
struct replay_new_task__args {
    uint64_t bulk_id;
    uint32_t size;
};
struct replay_task_completed__args {
    uint16_t pid;
    uint64_t bulk_id;
};

/*
 * Union type for all message arguments
 */
union replay_arg_union {
    struct replay_slave_init__args slave_init;
    struct replay_new_task__args new_task;
    struct replay_task_completed__args task_completed;
};

/*
 * VTable struct definition for the interface (transmit)
 */
struct replay_tx_vtbl {
    replay_slave_init__tx_method_fn *slave_init;
    replay_slave_init_reply__tx_method_fn *slave_init_reply;
    replay_new_task__tx_method_fn *new_task;
    replay_task_completed__tx_method_fn *task_completed;
    replay_slave_finish__tx_method_fn *slave_finish;
    replay_slave_finish_reply__tx_method_fn *slave_finish_reply;
    replay_slave_print_stats__tx_method_fn *slave_print_stats;
    replay_slave_print_stats_reply__tx_method_fn *slave_print_stats_reply;
};

/*
 * VTable struct definition for the interface (receive)
 */
struct replay_rx_vtbl {
    replay_slave_init__rx_method_fn *slave_init;
    replay_slave_init_reply__rx_method_fn *slave_init_reply;
    replay_new_task__rx_method_fn *new_task;
    replay_task_completed__rx_method_fn *task_completed;
    replay_slave_finish__rx_method_fn *slave_finish;
    replay_slave_finish_reply__rx_method_fn *slave_finish_reply;
    replay_slave_print_stats__rx_method_fn *slave_print_stats;
    replay_slave_print_stats_reply__rx_method_fn *slave_print_stats_reply;
};

/*
 * Incoming connect callback type
 */
typedef  errval_t replay_connect_fn(void *st, struct replay_binding *binding);

/*
 * Export state struct
 */
struct replay_export {
    struct idc_export common;
    replay_connect_fn *connect_cb;
    struct waitset *waitset;
    void *st;
};

/*
 * Export function
 */
extern  errval_t replay_export(void *st, idc_export_callback_fn *export_cb, replay_connect_fn *connect_cb, struct waitset *ws, idc_export_flags_t flags);

/*
 * The message buffer structure (for accept/connect)
 */
struct replay_frameinfo {
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
extern  errval_t replay_accept(struct replay_frameinfo *_frameinfo, void *st, replay_bind_continuation_fn *_continuation, struct waitset *ws, idc_export_flags_t flags);

/*
 * The Binding structure
 */
struct replay_binding {
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
    replay_can_send_fn *can_send;
    
    /* register an event for when a message is likely to be able to be sent */
    replay_register_send_fn *register_send;
    
    /* change the waitset used by a binding */
    replay_change_waitset_fn *change_waitset;
    
    /* perform control operations */
    replay_control_fn *control;
    
    /* error handler for any async errors associated with this binding */
    /* must be filled-in by user */
    replay_error_handler_fn *error_handler;
    
    /* Message send functions (filled in by binding) */
    struct replay_tx_vtbl tx_vtbl;
    
    /* Incoming message handlers (filled in by user) */
    struct replay_rx_vtbl rx_vtbl;
    
    /* Private state belonging to the binding implementation */
    union replay_arg_union tx_union;
    union replay_arg_union rx_union;
    struct waitset_chanstate register_chanstate;
    struct waitset_chanstate tx_cont_chanstate;
    enum replay_msg_enum tx_msgnum;
    enum replay_msg_enum rx_msgnum;
    int tx_msg_fragment;
    int rx_msg_fragment;
    size_t tx_str_pos;
    size_t rx_str_pos;
    size_t tx_str_len;
    size_t rx_str_len;
    struct event_queue_node event_qnode;
    replay_bind_continuation_fn *bind_cont;
};

/*
 * Generic bind function
 */
extern  errval_t replay_bind(iref_t i, replay_bind_continuation_fn *_continuation, void *st, struct waitset *waitset, idc_bind_flags_t flags);

/*
 * Generic connect function over already shared frame
 */
extern  errval_t replay_connect(struct replay_frameinfo *_frameinfo, replay_bind_continuation_fn *_continuation, void *st, struct waitset *ws, idc_bind_flags_t flags);

/*
 * Send wrappers
 */
static inline errval_t replay_slave_init__tx(struct replay_binding *_binding, struct event_closure _continuation, struct capref shared_mem, uint32_t size) __attribute__ ((always_inline));
static inline errval_t replay_slave_init__tx(struct replay_binding *_binding, struct event_closure _continuation, struct capref shared_mem, uint32_t size)
{
    return(((_binding->tx_vtbl).slave_init)(_binding, _continuation, shared_mem, size));
}

static inline errval_t replay_slave_init_reply__tx(struct replay_binding *_binding, struct event_closure _continuation) __attribute__ ((always_inline));
static inline errval_t replay_slave_init_reply__tx(struct replay_binding *_binding, struct event_closure _continuation)
{
    return(((_binding->tx_vtbl).slave_init_reply)(_binding, _continuation));
}

static inline errval_t replay_new_task__tx(struct replay_binding *_binding, struct event_closure _continuation, uint64_t bulk_id, uint32_t size) __attribute__ ((always_inline));
static inline errval_t replay_new_task__tx(struct replay_binding *_binding, struct event_closure _continuation, uint64_t bulk_id, uint32_t size)
{
    return(((_binding->tx_vtbl).new_task)(_binding, _continuation, bulk_id, size));
}

static inline errval_t replay_task_completed__tx(struct replay_binding *_binding, struct event_closure _continuation, uint16_t pid, uint64_t bulk_id) __attribute__ ((always_inline));
static inline errval_t replay_task_completed__tx(struct replay_binding *_binding, struct event_closure _continuation, uint16_t pid, uint64_t bulk_id)
{
    return(((_binding->tx_vtbl).task_completed)(_binding, _continuation, pid, bulk_id));
}

static inline errval_t replay_slave_finish__tx(struct replay_binding *_binding, struct event_closure _continuation) __attribute__ ((always_inline));
static inline errval_t replay_slave_finish__tx(struct replay_binding *_binding, struct event_closure _continuation)
{
    return(((_binding->tx_vtbl).slave_finish)(_binding, _continuation));
}

static inline errval_t replay_slave_finish_reply__tx(struct replay_binding *_binding, struct event_closure _continuation) __attribute__ ((always_inline));
static inline errval_t replay_slave_finish_reply__tx(struct replay_binding *_binding, struct event_closure _continuation)
{
    return(((_binding->tx_vtbl).slave_finish_reply)(_binding, _continuation));
}

static inline errval_t replay_slave_print_stats__tx(struct replay_binding *_binding, struct event_closure _continuation) __attribute__ ((always_inline));
static inline errval_t replay_slave_print_stats__tx(struct replay_binding *_binding, struct event_closure _continuation)
{
    return(((_binding->tx_vtbl).slave_print_stats)(_binding, _continuation));
}

static inline errval_t replay_slave_print_stats_reply__tx(struct replay_binding *_binding, struct event_closure _continuation) __attribute__ ((always_inline));
static inline errval_t replay_slave_print_stats_reply__tx(struct replay_binding *_binding, struct event_closure _continuation)
{
    return(((_binding->tx_vtbl).slave_print_stats_reply)(_binding, _continuation));
}


/*
 * Backend-specific includes
 */
#ifdef CONFIG_FLOUNDER_BACKEND_LMP
#include <if/replay_lmp_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_LMP
#ifdef CONFIG_FLOUNDER_BACKEND_UMP
#include <if/replay_ump_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_UMP
#ifdef CONFIG_FLOUNDER_BACKEND_UMP_IPI
#include <if/replay_ump_ipi_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_UMP_IPI
#ifdef CONFIG_FLOUNDER_BACKEND_MULTIHOP
#include <if/replay_multihop_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_MULTIHOP
/*
 * And we're done
 */
#endif // __replay_IF_H
