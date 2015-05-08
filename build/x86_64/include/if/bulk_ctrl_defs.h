#ifndef __bulk_ctrl_IF_H
#define __bulk_ctrl_IF_H 1
/*
 * Copyright (c) 2010, ETH Zurich.
 * All rights reserved.
 * 
 * INTERFACE NAME: bulk_ctrl
 * INTEFACE FILE: ../if/bulk_ctrl.if
 * INTERFACE DESCRIPTION: bulk control channel interface
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
typedef uint64_t bulk_ctrl_genpaddr_t;
typedef uint64_t bulk_ctrl_genvaddr_t;
typedef uint32_t bulk_ctrl_rsrcid_t;
typedef uint64_t bulk_ctrl_errval_t;
typedef uint64_t bulk_ctrl_cycles_t;
typedef uint32_t bulk_ctrl_iref_t;
typedef uint8_t bulk_ctrl_coreid_t;
typedef uint32_t bulk_ctrl_domainid_t;
typedef uint64_t bulk_ctrl_error_t;
typedef enum bulk_ctrl_direction_t {
    bulk_ctrl_SOURCE,
    bulk_ctrl_SINK
} bulk_ctrl_direction_t;
typedef enum bulk_ctrl_role_t {
    bulk_ctrl_MASTER,
    bulk_ctrl_SLAVE,
    bulk_ctrl_GENERIC
} bulk_ctrl_role_t;
typedef enum bulk_ctrl_trust_t {
    bulk_ctrl_NONE,
    bulk_ctrl_HALF,
    bulk_ctrl_FULL
} bulk_ctrl_trust_t;
struct _bulk_ctrl_poolid__struct {
    uint32_t pool_id_machine;
    uint32_t pool_id_dom;
    uint32_t pool_id_local;
};
typedef struct _bulk_ctrl_poolid__struct bulk_ctrl_poolid_t;
struct _bulk_ctrl_pool__struct {
    uint32_t pool_id_machine;
    uint32_t pool_id_dom;
    uint32_t pool_id_local;
    bulk_ctrl_trust_t trust;
    uint32_t buffer_size;
    uint32_t num_buffers;
    struct capref cap;
};
typedef struct _bulk_ctrl_pool__struct bulk_ctrl_pool_t;

/*
 * Forward declaration of binding type
 */
struct bulk_ctrl_binding;

/*
 * Contination (callback) and control function types
 */
typedef  void bulk_ctrl_bind_continuation_fn(void *st, errval_t err, struct bulk_ctrl_binding *_binding);
typedef  bool bulk_ctrl_can_send_fn(struct bulk_ctrl_binding *_binding);
typedef  errval_t bulk_ctrl_register_send_fn(struct bulk_ctrl_binding *_binding, struct waitset *ws, struct event_closure _continuation);
typedef  errval_t bulk_ctrl_change_waitset_fn(struct bulk_ctrl_binding *_binding, struct waitset *ws);
typedef  errval_t bulk_ctrl_control_fn(struct bulk_ctrl_binding *_binding, idc_control_t control);
typedef  void bulk_ctrl_error_handler_fn(struct bulk_ctrl_binding *_binding, errval_t err);

/*
 * Enumeration for message numbers
 */
typedef enum bulk_ctrl_msg_enum {
    bulk_ctrl___dummy__msgnum = 0,
    bulk_ctrl___bind__msgnum = 1,
    bulk_ctrl___bind_reply__msgnum = 2,
    bulk_ctrl_negotiate_call__msgnum = 3,
    bulk_ctrl_negotiate_response__msgnum = 4,
    bulk_ctrl_assign_pool_call__msgnum = 5,
    bulk_ctrl_assign_pool_response__msgnum = 6,
    bulk_ctrl_move_untrusted_call__msgnum = 7,
    bulk_ctrl_move_trusted_call__msgnum = 8,
    bulk_ctrl_move_response__msgnum = 9,
    bulk_ctrl_copy_untrusted_call__msgnum = 10,
    bulk_ctrl_copy_trusted_call__msgnum = 11,
    bulk_ctrl_copy_response__msgnum = 12,
    bulk_ctrl_pass_untrusted_call__msgnum = 13,
    bulk_ctrl_pass_trusted_call__msgnum = 14,
    bulk_ctrl_pass_response__msgnum = 15,
    bulk_ctrl_release_call__msgnum = 16,
    bulk_ctrl_release_response__msgnum = 17
} bulk_ctrl_msg_enum;

/*
 * Message type signatures (transmit)
 */
typedef  errval_t bulk_ctrl_negotiate_call__tx_method_fn(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_role_t role, bulk_ctrl_trust_t trust);
typedef  errval_t bulk_ctrl_negotiate_response__tx_method_fn(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, bulk_ctrl_direction_t match_direction, bulk_ctrl_role_t match_role, uint64_t meta_size);
typedef  errval_t bulk_ctrl_assign_pool_call__tx_method_fn(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_pool_t pool, uint64_t id);
typedef  errval_t bulk_ctrl_assign_pool_response__tx_method_fn(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, uint64_t id);
typedef  errval_t bulk_ctrl_move_untrusted_call__tx_method_fn(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, struct capref cap, const uint8_t *meta, size_t metasize);
typedef  errval_t bulk_ctrl_move_trusted_call__tx_method_fn(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, const uint8_t *meta, size_t metasize);
typedef  errval_t bulk_ctrl_move_response__tx_method_fn(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, uint32_t tid);
typedef  errval_t bulk_ctrl_copy_untrusted_call__tx_method_fn(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, struct capref cap, const uint8_t *meta, size_t metasize);
typedef  errval_t bulk_ctrl_copy_trusted_call__tx_method_fn(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, const uint8_t *meta, size_t metasize);
typedef  errval_t bulk_ctrl_copy_response__tx_method_fn(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, uint32_t tid);
typedef  errval_t bulk_ctrl_pass_untrusted_call__tx_method_fn(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, struct capref cap, const uint8_t *meta, size_t metasize);
typedef  errval_t bulk_ctrl_pass_trusted_call__tx_method_fn(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, const uint8_t *meta, size_t metasize);
typedef  errval_t bulk_ctrl_pass_response__tx_method_fn(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, uint32_t tid);
typedef  errval_t bulk_ctrl_release_call__tx_method_fn(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid);
typedef  errval_t bulk_ctrl_release_response__tx_method_fn(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, uint32_t tid);

/*
 * Message type signatures (receive)
 */
typedef  void bulk_ctrl_negotiate_call__rx_method_fn(struct bulk_ctrl_binding *_binding, bulk_ctrl_role_t role, bulk_ctrl_trust_t trust);
typedef  void bulk_ctrl_negotiate_response__rx_method_fn(struct bulk_ctrl_binding *_binding, bulk_ctrl_error_t error, bulk_ctrl_direction_t match_direction, bulk_ctrl_role_t match_role, uint64_t meta_size);
typedef  void bulk_ctrl_assign_pool_call__rx_method_fn(struct bulk_ctrl_binding *_binding, bulk_ctrl_pool_t pool, uint64_t id);
typedef  void bulk_ctrl_assign_pool_response__rx_method_fn(struct bulk_ctrl_binding *_binding, bulk_ctrl_error_t error, uint64_t id);
typedef  void bulk_ctrl_move_untrusted_call__rx_method_fn(struct bulk_ctrl_binding *_binding, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, struct capref cap, uint8_t *meta, size_t metasize);
typedef  void bulk_ctrl_move_trusted_call__rx_method_fn(struct bulk_ctrl_binding *_binding, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, uint8_t *meta, size_t metasize);
typedef  void bulk_ctrl_move_response__rx_method_fn(struct bulk_ctrl_binding *_binding, bulk_ctrl_error_t error, uint32_t tid);
typedef  void bulk_ctrl_copy_untrusted_call__rx_method_fn(struct bulk_ctrl_binding *_binding, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, struct capref cap, uint8_t *meta, size_t metasize);
typedef  void bulk_ctrl_copy_trusted_call__rx_method_fn(struct bulk_ctrl_binding *_binding, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, uint8_t *meta, size_t metasize);
typedef  void bulk_ctrl_copy_response__rx_method_fn(struct bulk_ctrl_binding *_binding, bulk_ctrl_error_t error, uint32_t tid);
typedef  void bulk_ctrl_pass_untrusted_call__rx_method_fn(struct bulk_ctrl_binding *_binding, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, struct capref cap, uint8_t *meta, size_t metasize);
typedef  void bulk_ctrl_pass_trusted_call__rx_method_fn(struct bulk_ctrl_binding *_binding, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, uint8_t *meta, size_t metasize);
typedef  void bulk_ctrl_pass_response__rx_method_fn(struct bulk_ctrl_binding *_binding, bulk_ctrl_error_t error, uint32_t tid);
typedef  void bulk_ctrl_release_call__rx_method_fn(struct bulk_ctrl_binding *_binding, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid);
typedef  void bulk_ctrl_release_response__rx_method_fn(struct bulk_ctrl_binding *_binding, bulk_ctrl_error_t error, uint32_t tid);

/*
 * Struct type for holding the args for each msg
 */
struct bulk_ctrl_negotiate_call__args {
    bulk_ctrl_role_t role;
    bulk_ctrl_trust_t trust;
};
struct bulk_ctrl_negotiate_response__args {
    bulk_ctrl_error_t error;
    bulk_ctrl_direction_t match_direction;
    bulk_ctrl_role_t match_role;
    uint64_t meta_size;
};
struct bulk_ctrl_assign_pool_call__args {
    bulk_ctrl_pool_t pool;
    uint64_t id;
};
struct bulk_ctrl_assign_pool_response__args {
    bulk_ctrl_error_t error;
    uint64_t id;
};
struct bulk_ctrl_move_untrusted_call__args {
    bulk_ctrl_poolid_t poolid;
    uint32_t bufferid;
    uint32_t tid;
    struct capref cap;
    uint8_t *meta;
    size_t metasize;
};
struct bulk_ctrl_move_trusted_call__args {
    bulk_ctrl_poolid_t poolid;
    uint32_t bufferid;
    uint32_t tid;
    uint8_t *meta;
    size_t metasize;
};
struct bulk_ctrl_move_response__args {
    bulk_ctrl_error_t error;
    uint32_t tid;
};
struct bulk_ctrl_copy_untrusted_call__args {
    bulk_ctrl_poolid_t poolid;
    uint32_t bufferid;
    uint32_t tid;
    struct capref cap;
    uint8_t *meta;
    size_t metasize;
};
struct bulk_ctrl_copy_trusted_call__args {
    bulk_ctrl_poolid_t poolid;
    uint32_t bufferid;
    uint32_t tid;
    uint8_t *meta;
    size_t metasize;
};
struct bulk_ctrl_copy_response__args {
    bulk_ctrl_error_t error;
    uint32_t tid;
};
struct bulk_ctrl_pass_untrusted_call__args {
    bulk_ctrl_poolid_t poolid;
    uint32_t bufferid;
    uint32_t tid;
    struct capref cap;
    uint8_t *meta;
    size_t metasize;
};
struct bulk_ctrl_pass_trusted_call__args {
    bulk_ctrl_poolid_t poolid;
    uint32_t bufferid;
    uint32_t tid;
    uint8_t *meta;
    size_t metasize;
};
struct bulk_ctrl_pass_response__args {
    bulk_ctrl_error_t error;
    uint32_t tid;
};
struct bulk_ctrl_release_call__args {
    bulk_ctrl_poolid_t poolid;
    uint32_t bufferid;
    uint32_t tid;
};
struct bulk_ctrl_release_response__args {
    bulk_ctrl_error_t error;
    uint32_t tid;
};

/*
 * Union type for all message arguments
 */
union bulk_ctrl_arg_union {
    struct bulk_ctrl_negotiate_call__args negotiate_call;
    struct bulk_ctrl_negotiate_response__args negotiate_response;
    struct bulk_ctrl_assign_pool_call__args assign_pool_call;
    struct bulk_ctrl_assign_pool_response__args assign_pool_response;
    struct bulk_ctrl_move_untrusted_call__args move_untrusted_call;
    struct bulk_ctrl_move_trusted_call__args move_trusted_call;
    struct bulk_ctrl_move_response__args move_response;
    struct bulk_ctrl_copy_untrusted_call__args copy_untrusted_call;
    struct bulk_ctrl_copy_trusted_call__args copy_trusted_call;
    struct bulk_ctrl_copy_response__args copy_response;
    struct bulk_ctrl_pass_untrusted_call__args pass_untrusted_call;
    struct bulk_ctrl_pass_trusted_call__args pass_trusted_call;
    struct bulk_ctrl_pass_response__args pass_response;
    struct bulk_ctrl_release_call__args release_call;
    struct bulk_ctrl_release_response__args release_response;
};

/*
 * VTable struct definition for the interface (transmit)
 */
struct bulk_ctrl_tx_vtbl {
    bulk_ctrl_negotiate_call__tx_method_fn *negotiate_call;
    bulk_ctrl_negotiate_response__tx_method_fn *negotiate_response;
    bulk_ctrl_assign_pool_call__tx_method_fn *assign_pool_call;
    bulk_ctrl_assign_pool_response__tx_method_fn *assign_pool_response;
    bulk_ctrl_move_untrusted_call__tx_method_fn *move_untrusted_call;
    bulk_ctrl_move_trusted_call__tx_method_fn *move_trusted_call;
    bulk_ctrl_move_response__tx_method_fn *move_response;
    bulk_ctrl_copy_untrusted_call__tx_method_fn *copy_untrusted_call;
    bulk_ctrl_copy_trusted_call__tx_method_fn *copy_trusted_call;
    bulk_ctrl_copy_response__tx_method_fn *copy_response;
    bulk_ctrl_pass_untrusted_call__tx_method_fn *pass_untrusted_call;
    bulk_ctrl_pass_trusted_call__tx_method_fn *pass_trusted_call;
    bulk_ctrl_pass_response__tx_method_fn *pass_response;
    bulk_ctrl_release_call__tx_method_fn *release_call;
    bulk_ctrl_release_response__tx_method_fn *release_response;
};

/*
 * VTable struct definition for the interface (receive)
 */
struct bulk_ctrl_rx_vtbl {
    bulk_ctrl_negotiate_call__rx_method_fn *negotiate_call;
    bulk_ctrl_negotiate_response__rx_method_fn *negotiate_response;
    bulk_ctrl_assign_pool_call__rx_method_fn *assign_pool_call;
    bulk_ctrl_assign_pool_response__rx_method_fn *assign_pool_response;
    bulk_ctrl_move_untrusted_call__rx_method_fn *move_untrusted_call;
    bulk_ctrl_move_trusted_call__rx_method_fn *move_trusted_call;
    bulk_ctrl_move_response__rx_method_fn *move_response;
    bulk_ctrl_copy_untrusted_call__rx_method_fn *copy_untrusted_call;
    bulk_ctrl_copy_trusted_call__rx_method_fn *copy_trusted_call;
    bulk_ctrl_copy_response__rx_method_fn *copy_response;
    bulk_ctrl_pass_untrusted_call__rx_method_fn *pass_untrusted_call;
    bulk_ctrl_pass_trusted_call__rx_method_fn *pass_trusted_call;
    bulk_ctrl_pass_response__rx_method_fn *pass_response;
    bulk_ctrl_release_call__rx_method_fn *release_call;
    bulk_ctrl_release_response__rx_method_fn *release_response;
};

/*
 * Incoming connect callback type
 */
typedef  errval_t bulk_ctrl_connect_fn(void *st, struct bulk_ctrl_binding *binding);

/*
 * Export state struct
 */
struct bulk_ctrl_export {
    struct idc_export common;
    bulk_ctrl_connect_fn *connect_cb;
    struct waitset *waitset;
    void *st;
};

/*
 * Export function
 */
extern  errval_t bulk_ctrl_export(void *st, idc_export_callback_fn *export_cb, bulk_ctrl_connect_fn *connect_cb, struct waitset *ws, idc_export_flags_t flags);

/*
 * The message buffer structure (for accept/connect)
 */
struct bulk_ctrl_frameinfo {
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
extern  errval_t bulk_ctrl_accept(struct bulk_ctrl_frameinfo *_frameinfo, void *st, bulk_ctrl_bind_continuation_fn *_continuation, struct waitset *ws, idc_export_flags_t flags);

/*
 * The Binding structure
 */
struct bulk_ctrl_binding {
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
    bulk_ctrl_can_send_fn *can_send;
    
    /* register an event for when a message is likely to be able to be sent */
    bulk_ctrl_register_send_fn *register_send;
    
    /* change the waitset used by a binding */
    bulk_ctrl_change_waitset_fn *change_waitset;
    
    /* perform control operations */
    bulk_ctrl_control_fn *control;
    
    /* error handler for any async errors associated with this binding */
    /* must be filled-in by user */
    bulk_ctrl_error_handler_fn *error_handler;
    
    /* Message send functions (filled in by binding) */
    struct bulk_ctrl_tx_vtbl tx_vtbl;
    
    /* Incoming message handlers (filled in by user) */
    struct bulk_ctrl_rx_vtbl rx_vtbl;
    
    /* Private state belonging to the binding implementation */
    union bulk_ctrl_arg_union tx_union;
    union bulk_ctrl_arg_union rx_union;
    struct waitset_chanstate register_chanstate;
    struct waitset_chanstate tx_cont_chanstate;
    enum bulk_ctrl_msg_enum tx_msgnum;
    enum bulk_ctrl_msg_enum rx_msgnum;
    int tx_msg_fragment;
    int rx_msg_fragment;
    size_t tx_str_pos;
    size_t rx_str_pos;
    size_t tx_str_len;
    size_t rx_str_len;
    struct event_queue_node event_qnode;
    bulk_ctrl_bind_continuation_fn *bind_cont;
};

/*
 * Generic bind function
 */
extern  errval_t bulk_ctrl_bind(iref_t i, bulk_ctrl_bind_continuation_fn *_continuation, void *st, struct waitset *waitset, idc_bind_flags_t flags);

/*
 * Generic connect function over already shared frame
 */
extern  errval_t bulk_ctrl_connect(struct bulk_ctrl_frameinfo *_frameinfo, bulk_ctrl_bind_continuation_fn *_continuation, void *st, struct waitset *ws, idc_bind_flags_t flags);

/*
 * Send wrappers
 */
static inline errval_t bulk_ctrl_negotiate_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_role_t role, bulk_ctrl_trust_t trust) __attribute__ ((always_inline));
static inline errval_t bulk_ctrl_negotiate_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_role_t role, bulk_ctrl_trust_t trust)
{
    return(((_binding->tx_vtbl).negotiate_call)(_binding, _continuation, role, trust));
}

static inline errval_t bulk_ctrl_negotiate_response__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, bulk_ctrl_direction_t match_direction, bulk_ctrl_role_t match_role, uint64_t meta_size) __attribute__ ((always_inline));
static inline errval_t bulk_ctrl_negotiate_response__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, bulk_ctrl_direction_t match_direction, bulk_ctrl_role_t match_role, uint64_t meta_size)
{
    return(((_binding->tx_vtbl).negotiate_response)(_binding, _continuation, error, match_direction, match_role, meta_size));
}

static inline errval_t bulk_ctrl_assign_pool_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_pool_t pool, uint64_t id) __attribute__ ((always_inline));
static inline errval_t bulk_ctrl_assign_pool_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_pool_t pool, uint64_t id)
{
    return(((_binding->tx_vtbl).assign_pool_call)(_binding, _continuation, pool, id));
}

static inline errval_t bulk_ctrl_assign_pool_response__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, uint64_t id) __attribute__ ((always_inline));
static inline errval_t bulk_ctrl_assign_pool_response__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, uint64_t id)
{
    return(((_binding->tx_vtbl).assign_pool_response)(_binding, _continuation, error, id));
}

static inline errval_t bulk_ctrl_move_untrusted_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, struct capref cap, const uint8_t *meta, size_t metasize) __attribute__ ((always_inline));
static inline errval_t bulk_ctrl_move_untrusted_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, struct capref cap, const uint8_t *meta, size_t metasize)
{
    return(((_binding->tx_vtbl).move_untrusted_call)(_binding, _continuation, poolid, bufferid, tid, cap, meta, metasize));
}

static inline errval_t bulk_ctrl_move_trusted_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, const uint8_t *meta, size_t metasize) __attribute__ ((always_inline));
static inline errval_t bulk_ctrl_move_trusted_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, const uint8_t *meta, size_t metasize)
{
    return(((_binding->tx_vtbl).move_trusted_call)(_binding, _continuation, poolid, bufferid, tid, meta, metasize));
}

static inline errval_t bulk_ctrl_move_response__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, uint32_t tid) __attribute__ ((always_inline));
static inline errval_t bulk_ctrl_move_response__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, uint32_t tid)
{
    return(((_binding->tx_vtbl).move_response)(_binding, _continuation, error, tid));
}

static inline errval_t bulk_ctrl_copy_untrusted_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, struct capref cap, const uint8_t *meta, size_t metasize) __attribute__ ((always_inline));
static inline errval_t bulk_ctrl_copy_untrusted_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, struct capref cap, const uint8_t *meta, size_t metasize)
{
    return(((_binding->tx_vtbl).copy_untrusted_call)(_binding, _continuation, poolid, bufferid, tid, cap, meta, metasize));
}

static inline errval_t bulk_ctrl_copy_trusted_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, const uint8_t *meta, size_t metasize) __attribute__ ((always_inline));
static inline errval_t bulk_ctrl_copy_trusted_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, const uint8_t *meta, size_t metasize)
{
    return(((_binding->tx_vtbl).copy_trusted_call)(_binding, _continuation, poolid, bufferid, tid, meta, metasize));
}

static inline errval_t bulk_ctrl_copy_response__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, uint32_t tid) __attribute__ ((always_inline));
static inline errval_t bulk_ctrl_copy_response__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, uint32_t tid)
{
    return(((_binding->tx_vtbl).copy_response)(_binding, _continuation, error, tid));
}

static inline errval_t bulk_ctrl_pass_untrusted_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, struct capref cap, const uint8_t *meta, size_t metasize) __attribute__ ((always_inline));
static inline errval_t bulk_ctrl_pass_untrusted_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, struct capref cap, const uint8_t *meta, size_t metasize)
{
    return(((_binding->tx_vtbl).pass_untrusted_call)(_binding, _continuation, poolid, bufferid, tid, cap, meta, metasize));
}

static inline errval_t bulk_ctrl_pass_trusted_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, const uint8_t *meta, size_t metasize) __attribute__ ((always_inline));
static inline errval_t bulk_ctrl_pass_trusted_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid, const uint8_t *meta, size_t metasize)
{
    return(((_binding->tx_vtbl).pass_trusted_call)(_binding, _continuation, poolid, bufferid, tid, meta, metasize));
}

static inline errval_t bulk_ctrl_pass_response__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, uint32_t tid) __attribute__ ((always_inline));
static inline errval_t bulk_ctrl_pass_response__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, uint32_t tid)
{
    return(((_binding->tx_vtbl).pass_response)(_binding, _continuation, error, tid));
}

static inline errval_t bulk_ctrl_release_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid) __attribute__ ((always_inline));
static inline errval_t bulk_ctrl_release_call__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_poolid_t poolid, uint32_t bufferid, uint32_t tid)
{
    return(((_binding->tx_vtbl).release_call)(_binding, _continuation, poolid, bufferid, tid));
}

static inline errval_t bulk_ctrl_release_response__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, uint32_t tid) __attribute__ ((always_inline));
static inline errval_t bulk_ctrl_release_response__tx(struct bulk_ctrl_binding *_binding, struct event_closure _continuation, bulk_ctrl_error_t error, uint32_t tid)
{
    return(((_binding->tx_vtbl).release_response)(_binding, _continuation, error, tid));
}


/*
 * Backend-specific includes
 */
#ifdef CONFIG_FLOUNDER_BACKEND_LMP
#include <if/bulk_ctrl_lmp_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_LMP
#ifdef CONFIG_FLOUNDER_BACKEND_UMP
#include <if/bulk_ctrl_ump_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_UMP
#ifdef CONFIG_FLOUNDER_BACKEND_UMP_IPI
#include <if/bulk_ctrl_ump_ipi_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_UMP_IPI
#ifdef CONFIG_FLOUNDER_BACKEND_MULTIHOP
#include <if/bulk_ctrl_multihop_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_MULTIHOP
/*
 * And we're done
 */
#endif // __bulk_ctrl_IF_H
