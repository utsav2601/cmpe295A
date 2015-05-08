#ifndef __ping_pong_IF_H
#define __ping_pong_IF_H 1
/*
 * Copyright (c) 2010, ETH Zurich.
 * All rights reserved.
 * 
 * INTERFACE NAME: ping_pong
 * INTEFACE FILE: ../if/ping_pong.if
 * INTERFACE DESCRIPTION: Ping-Pong async example Interface
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
typedef uint64_t ping_pong_genpaddr_t;
typedef uint64_t ping_pong_genvaddr_t;
typedef uint32_t ping_pong_rsrcid_t;
typedef uint64_t ping_pong_errval_t;
typedef uint64_t ping_pong_cycles_t;
typedef uint32_t ping_pong_iref_t;
typedef uint8_t ping_pong_coreid_t;
typedef uint32_t ping_pong_domainid_t;

/*
 * Forward declaration of binding type
 */
struct ping_pong_binding;

/*
 * Contination (callback) and control function types
 */
typedef  void ping_pong_bind_continuation_fn(void *st, errval_t err, struct ping_pong_binding *_binding);
typedef  bool ping_pong_can_send_fn(struct ping_pong_binding *_binding);
typedef  errval_t ping_pong_register_send_fn(struct ping_pong_binding *_binding, struct waitset *ws, struct event_closure _continuation);
typedef  errval_t ping_pong_change_waitset_fn(struct ping_pong_binding *_binding, struct waitset *ws);
typedef  errval_t ping_pong_control_fn(struct ping_pong_binding *_binding, idc_control_t control);
typedef  void ping_pong_error_handler_fn(struct ping_pong_binding *_binding, errval_t err);

/*
 * Enumeration for message numbers
 */
typedef enum ping_pong_msg_enum {
    ping_pong___dummy__msgnum = 0,
    ping_pong___bind__msgnum = 1,
    ping_pong___bind_reply__msgnum = 2,
    ping_pong_rsrc_join_request__msgnum = 3,
    ping_pong_rsrc_join_reply__msgnum = 4,
    ping_pong_init__msgnum = 5,
    ping_pong_ping__msgnum = 6,
    ping_pong_pong__msgnum = 7,
    ping_pong_slow_op__msgnum = 8,
    ping_pong_slow_reply__msgnum = 9,
    ping_pong_stop__msgnum = 10,
    ping_pong_testrpc_call__msgnum = 11,
    ping_pong_testrpc_response__msgnum = 12,
    ping_pong_testrpc2_call__msgnum = 13,
    ping_pong_testrpc2_response__msgnum = 14,
    ping_pong_outoforder_call__msgnum = 15,
    ping_pong_outoforder_response__msgnum = 16,
    ping_pong_str0__msgnum = 17,
    ping_pong_str1__msgnum = 18,
    ping_pong_str2__msgnum = 19,
    ping_pong_str3_call__msgnum = 20,
    ping_pong_str3_response__msgnum = 21,
    ping_pong_str4_call__msgnum = 22,
    ping_pong_str4_response__msgnum = 23,
    ping_pong_str5_call__msgnum = 24,
    ping_pong_str5_response__msgnum = 25,
    ping_pong_str6_call__msgnum = 26,
    ping_pong_str6_response__msgnum = 27,
    ping_pong_arr0__msgnum = 28,
    ping_pong_arr1__msgnum = 29,
    ping_pong_arr2__msgnum = 30
} ping_pong_msg_enum;

/*
 * Message type signatures (transmit)
 */
typedef  errval_t ping_pong_rsrc_join_request__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t id);
typedef  errval_t ping_pong_rsrc_join_reply__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation);
typedef  errval_t ping_pong_init__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation);
typedef  errval_t ping_pong_ping__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t val);
typedef  errval_t ping_pong_pong__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t val);
typedef  errval_t ping_pong_slow_op__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t val);
typedef  errval_t ping_pong_slow_reply__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t val);
typedef  errval_t ping_pong_stop__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation);
typedef  errval_t ping_pong_testrpc_call__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t testin);
typedef  errval_t ping_pong_testrpc_response__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t testout);
typedef  errval_t ping_pong_testrpc2_call__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t testin);
typedef  errval_t ping_pong_testrpc2_response__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t testout);
typedef  errval_t ping_pong_outoforder_call__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_in, uint64_t testin);
typedef  errval_t ping_pong_outoforder_response__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_out, uint64_t testout);
typedef  errval_t ping_pong_str0__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *s);
typedef  errval_t ping_pong_str1__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *s);
typedef  errval_t ping_pong_str2__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *s);
typedef  errval_t ping_pong_str3_call__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *s);
typedef  errval_t ping_pong_str3_response__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation);
typedef  errval_t ping_pong_str4_call__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation);
typedef  errval_t ping_pong_str4_response__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *s);
typedef  errval_t ping_pong_str5_call__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_in, uint32_t arg1, const char *s);
typedef  errval_t ping_pong_str5_response__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_out);
typedef  errval_t ping_pong_str6_call__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_in);
typedef  errval_t ping_pong_str6_response__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_out, uint32_t arg1, const char *s);
typedef  errval_t ping_pong_arr0__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *a, size_t l);
typedef  errval_t ping_pong_arr1__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *a, size_t l);
typedef  errval_t ping_pong_arr2__tx_method_fn(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *a, size_t l);

/*
 * Message type signatures (receive)
 */
typedef  void ping_pong_rsrc_join_request__rx_method_fn(struct ping_pong_binding *_binding, uint32_t id);
typedef  void ping_pong_rsrc_join_reply__rx_method_fn(struct ping_pong_binding *_binding);
typedef  void ping_pong_init__rx_method_fn(struct ping_pong_binding *_binding);
typedef  void ping_pong_ping__rx_method_fn(struct ping_pong_binding *_binding, uint64_t val);
typedef  void ping_pong_pong__rx_method_fn(struct ping_pong_binding *_binding, uint64_t val);
typedef  void ping_pong_slow_op__rx_method_fn(struct ping_pong_binding *_binding, uint64_t val);
typedef  void ping_pong_slow_reply__rx_method_fn(struct ping_pong_binding *_binding, uint64_t val);
typedef  void ping_pong_stop__rx_method_fn(struct ping_pong_binding *_binding);
typedef  void ping_pong_testrpc_call__rx_method_fn(struct ping_pong_binding *_binding, uint64_t testin);
typedef  void ping_pong_testrpc_response__rx_method_fn(struct ping_pong_binding *_binding, uint64_t testout);
typedef  void ping_pong_testrpc2_call__rx_method_fn(struct ping_pong_binding *_binding, uint64_t testin);
typedef  void ping_pong_testrpc2_response__rx_method_fn(struct ping_pong_binding *_binding, uint64_t testout);
typedef  void ping_pong_outoforder_call__rx_method_fn(struct ping_pong_binding *_binding, uint64_t seq_in, uint64_t testin);
typedef  void ping_pong_outoforder_response__rx_method_fn(struct ping_pong_binding *_binding, uint64_t seq_out, uint64_t testout);
typedef  void ping_pong_str0__rx_method_fn(struct ping_pong_binding *_binding, uint32_t arg1, char *s);
typedef  void ping_pong_str1__rx_method_fn(struct ping_pong_binding *_binding, uint32_t arg1, char *s);
typedef  void ping_pong_str2__rx_method_fn(struct ping_pong_binding *_binding, uint32_t arg1, char *s);
typedef  void ping_pong_str3_call__rx_method_fn(struct ping_pong_binding *_binding, uint32_t arg1, char *s);
typedef  void ping_pong_str3_response__rx_method_fn(struct ping_pong_binding *_binding);
typedef  void ping_pong_str4_call__rx_method_fn(struct ping_pong_binding *_binding);
typedef  void ping_pong_str4_response__rx_method_fn(struct ping_pong_binding *_binding, uint32_t arg1, char *s);
typedef  void ping_pong_str5_call__rx_method_fn(struct ping_pong_binding *_binding, uint64_t seq_in, uint32_t arg1, char *s);
typedef  void ping_pong_str5_response__rx_method_fn(struct ping_pong_binding *_binding, uint64_t seq_out);
typedef  void ping_pong_str6_call__rx_method_fn(struct ping_pong_binding *_binding, uint64_t seq_in);
typedef  void ping_pong_str6_response__rx_method_fn(struct ping_pong_binding *_binding, uint64_t seq_out, uint32_t arg1, char *s);
typedef  void ping_pong_arr0__rx_method_fn(struct ping_pong_binding *_binding, uint32_t arg1, char *a, size_t l);
typedef  void ping_pong_arr1__rx_method_fn(struct ping_pong_binding *_binding, uint32_t arg1, char *a, size_t l);
typedef  void ping_pong_arr2__rx_method_fn(struct ping_pong_binding *_binding, uint32_t arg1, char *a, size_t l);

/*
 * Struct type for holding the args for each msg
 */
struct ping_pong_rsrc_join_request__args {
    uint32_t id;
};
struct ping_pong_ping__args {
    uint64_t val;
};
struct ping_pong_pong__args {
    uint64_t val;
};
struct ping_pong_slow_op__args {
    uint64_t val;
};
struct ping_pong_slow_reply__args {
    uint64_t val;
};
struct ping_pong_testrpc_call__args {
    uint64_t testin;
};
struct ping_pong_testrpc_response__args {
    uint64_t testout;
};
struct ping_pong_testrpc2_call__args {
    uint64_t testin;
};
struct ping_pong_testrpc2_response__args {
    uint64_t testout;
};
struct ping_pong_outoforder_call__args {
    uint64_t seq_in;
    uint64_t testin;
};
struct ping_pong_outoforder_response__args {
    uint64_t seq_out;
    uint64_t testout;
};
struct ping_pong_str0__args {
    uint32_t arg1;
    char *s;
};
struct ping_pong_str1__args {
    uint32_t arg1;
    char *s;
};
struct ping_pong_str2__args {
    uint32_t arg1;
    char *s;
};
struct ping_pong_str3_call__args {
    uint32_t arg1;
    char *s;
};
struct ping_pong_str4_response__args {
    uint32_t arg1;
    char *s;
};
struct ping_pong_str5_call__args {
    uint64_t seq_in;
    uint32_t arg1;
    char *s;
};
struct ping_pong_str5_response__args {
    uint64_t seq_out;
};
struct ping_pong_str6_call__args {
    uint64_t seq_in;
};
struct ping_pong_str6_response__args {
    uint64_t seq_out;
    uint32_t arg1;
    char *s;
};
struct ping_pong_arr0__args {
    uint32_t arg1;
    char *a;
    size_t l;
};
struct ping_pong_arr1__args {
    uint32_t arg1;
    char *a;
    size_t l;
};
struct ping_pong_arr2__args {
    uint32_t arg1;
    char *a;
    size_t l;
};

/*
 * Union type for all message arguments
 */
union ping_pong_arg_union {
    struct ping_pong_rsrc_join_request__args rsrc_join_request;
    struct ping_pong_ping__args ping;
    struct ping_pong_pong__args pong;
    struct ping_pong_slow_op__args slow_op;
    struct ping_pong_slow_reply__args slow_reply;
    struct ping_pong_testrpc_call__args testrpc_call;
    struct ping_pong_testrpc_response__args testrpc_response;
    struct ping_pong_testrpc2_call__args testrpc2_call;
    struct ping_pong_testrpc2_response__args testrpc2_response;
    struct ping_pong_outoforder_call__args outoforder_call;
    struct ping_pong_outoforder_response__args outoforder_response;
    struct ping_pong_str0__args str0;
    struct ping_pong_str1__args str1;
    struct ping_pong_str2__args str2;
    struct ping_pong_str3_call__args str3_call;
    struct ping_pong_str4_response__args str4_response;
    struct ping_pong_str5_call__args str5_call;
    struct ping_pong_str5_response__args str5_response;
    struct ping_pong_str6_call__args str6_call;
    struct ping_pong_str6_response__args str6_response;
    struct ping_pong_arr0__args arr0;
    struct ping_pong_arr1__args arr1;
    struct ping_pong_arr2__args arr2;
};

/*
 * VTable struct definition for the interface (transmit)
 */
struct ping_pong_tx_vtbl {
    ping_pong_rsrc_join_request__tx_method_fn *rsrc_join_request;
    ping_pong_rsrc_join_reply__tx_method_fn *rsrc_join_reply;
    ping_pong_init__tx_method_fn *init;
    ping_pong_ping__tx_method_fn *ping;
    ping_pong_pong__tx_method_fn *pong;
    ping_pong_slow_op__tx_method_fn *slow_op;
    ping_pong_slow_reply__tx_method_fn *slow_reply;
    ping_pong_stop__tx_method_fn *stop;
    ping_pong_testrpc_call__tx_method_fn *testrpc_call;
    ping_pong_testrpc_response__tx_method_fn *testrpc_response;
    ping_pong_testrpc2_call__tx_method_fn *testrpc2_call;
    ping_pong_testrpc2_response__tx_method_fn *testrpc2_response;
    ping_pong_outoforder_call__tx_method_fn *outoforder_call;
    ping_pong_outoforder_response__tx_method_fn *outoforder_response;
    ping_pong_str0__tx_method_fn *str0;
    ping_pong_str1__tx_method_fn *str1;
    ping_pong_str2__tx_method_fn *str2;
    ping_pong_str3_call__tx_method_fn *str3_call;
    ping_pong_str3_response__tx_method_fn *str3_response;
    ping_pong_str4_call__tx_method_fn *str4_call;
    ping_pong_str4_response__tx_method_fn *str4_response;
    ping_pong_str5_call__tx_method_fn *str5_call;
    ping_pong_str5_response__tx_method_fn *str5_response;
    ping_pong_str6_call__tx_method_fn *str6_call;
    ping_pong_str6_response__tx_method_fn *str6_response;
    ping_pong_arr0__tx_method_fn *arr0;
    ping_pong_arr1__tx_method_fn *arr1;
    ping_pong_arr2__tx_method_fn *arr2;
};

/*
 * VTable struct definition for the interface (receive)
 */
struct ping_pong_rx_vtbl {
    ping_pong_rsrc_join_request__rx_method_fn *rsrc_join_request;
    ping_pong_rsrc_join_reply__rx_method_fn *rsrc_join_reply;
    ping_pong_init__rx_method_fn *init;
    ping_pong_ping__rx_method_fn *ping;
    ping_pong_pong__rx_method_fn *pong;
    ping_pong_slow_op__rx_method_fn *slow_op;
    ping_pong_slow_reply__rx_method_fn *slow_reply;
    ping_pong_stop__rx_method_fn *stop;
    ping_pong_testrpc_call__rx_method_fn *testrpc_call;
    ping_pong_testrpc_response__rx_method_fn *testrpc_response;
    ping_pong_testrpc2_call__rx_method_fn *testrpc2_call;
    ping_pong_testrpc2_response__rx_method_fn *testrpc2_response;
    ping_pong_outoforder_call__rx_method_fn *outoforder_call;
    ping_pong_outoforder_response__rx_method_fn *outoforder_response;
    ping_pong_str0__rx_method_fn *str0;
    ping_pong_str1__rx_method_fn *str1;
    ping_pong_str2__rx_method_fn *str2;
    ping_pong_str3_call__rx_method_fn *str3_call;
    ping_pong_str3_response__rx_method_fn *str3_response;
    ping_pong_str4_call__rx_method_fn *str4_call;
    ping_pong_str4_response__rx_method_fn *str4_response;
    ping_pong_str5_call__rx_method_fn *str5_call;
    ping_pong_str5_response__rx_method_fn *str5_response;
    ping_pong_str6_call__rx_method_fn *str6_call;
    ping_pong_str6_response__rx_method_fn *str6_response;
    ping_pong_arr0__rx_method_fn *arr0;
    ping_pong_arr1__rx_method_fn *arr1;
    ping_pong_arr2__rx_method_fn *arr2;
};

/*
 * Incoming connect callback type
 */
typedef  errval_t ping_pong_connect_fn(void *st, struct ping_pong_binding *binding);

/*
 * Export state struct
 */
struct ping_pong_export {
    struct idc_export common;
    ping_pong_connect_fn *connect_cb;
    struct waitset *waitset;
    void *st;
};

/*
 * Export function
 */
extern  errval_t ping_pong_export(void *st, idc_export_callback_fn *export_cb, ping_pong_connect_fn *connect_cb, struct waitset *ws, idc_export_flags_t flags);

/*
 * The message buffer structure (for accept/connect)
 */
struct ping_pong_frameinfo {
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
extern  errval_t ping_pong_accept(struct ping_pong_frameinfo *_frameinfo, void *st, ping_pong_bind_continuation_fn *_continuation, struct waitset *ws, idc_export_flags_t flags);

/*
 * The Binding structure
 */
struct ping_pong_binding {
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
    ping_pong_can_send_fn *can_send;
    
    /* register an event for when a message is likely to be able to be sent */
    ping_pong_register_send_fn *register_send;
    
    /* change the waitset used by a binding */
    ping_pong_change_waitset_fn *change_waitset;
    
    /* perform control operations */
    ping_pong_control_fn *control;
    
    /* error handler for any async errors associated with this binding */
    /* must be filled-in by user */
    ping_pong_error_handler_fn *error_handler;
    
    /* Message send functions (filled in by binding) */
    struct ping_pong_tx_vtbl tx_vtbl;
    
    /* Incoming message handlers (filled in by user) */
    struct ping_pong_rx_vtbl rx_vtbl;
    
    /* Private state belonging to the binding implementation */
    union ping_pong_arg_union tx_union;
    union ping_pong_arg_union rx_union;
    struct waitset_chanstate register_chanstate;
    struct waitset_chanstate tx_cont_chanstate;
    enum ping_pong_msg_enum tx_msgnum;
    enum ping_pong_msg_enum rx_msgnum;
    int tx_msg_fragment;
    int rx_msg_fragment;
    size_t tx_str_pos;
    size_t rx_str_pos;
    size_t tx_str_len;
    size_t rx_str_len;
    struct event_queue_node event_qnode;
    ping_pong_bind_continuation_fn *bind_cont;
};

/*
 * Generic bind function
 */
extern  errval_t ping_pong_bind(iref_t i, ping_pong_bind_continuation_fn *_continuation, void *st, struct waitset *waitset, idc_bind_flags_t flags);

/*
 * Generic connect function over already shared frame
 */
extern  errval_t ping_pong_connect(struct ping_pong_frameinfo *_frameinfo, ping_pong_bind_continuation_fn *_continuation, void *st, struct waitset *ws, idc_bind_flags_t flags);

/*
 * Send wrappers
 */
static inline errval_t ping_pong_rsrc_join_request__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t id) __attribute__ ((always_inline));
static inline errval_t ping_pong_rsrc_join_request__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t id)
{
    return(((_binding->tx_vtbl).rsrc_join_request)(_binding, _continuation, id));
}

static inline errval_t ping_pong_rsrc_join_reply__tx(struct ping_pong_binding *_binding, struct event_closure _continuation) __attribute__ ((always_inline));
static inline errval_t ping_pong_rsrc_join_reply__tx(struct ping_pong_binding *_binding, struct event_closure _continuation)
{
    return(((_binding->tx_vtbl).rsrc_join_reply)(_binding, _continuation));
}

static inline errval_t ping_pong_init__tx(struct ping_pong_binding *_binding, struct event_closure _continuation) __attribute__ ((always_inline));
static inline errval_t ping_pong_init__tx(struct ping_pong_binding *_binding, struct event_closure _continuation)
{
    return(((_binding->tx_vtbl).init)(_binding, _continuation));
}

static inline errval_t ping_pong_ping__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t val) __attribute__ ((always_inline));
static inline errval_t ping_pong_ping__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t val)
{
    return(((_binding->tx_vtbl).ping)(_binding, _continuation, val));
}

static inline errval_t ping_pong_pong__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t val) __attribute__ ((always_inline));
static inline errval_t ping_pong_pong__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t val)
{
    return(((_binding->tx_vtbl).pong)(_binding, _continuation, val));
}

static inline errval_t ping_pong_slow_op__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t val) __attribute__ ((always_inline));
static inline errval_t ping_pong_slow_op__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t val)
{
    return(((_binding->tx_vtbl).slow_op)(_binding, _continuation, val));
}

static inline errval_t ping_pong_slow_reply__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t val) __attribute__ ((always_inline));
static inline errval_t ping_pong_slow_reply__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t val)
{
    return(((_binding->tx_vtbl).slow_reply)(_binding, _continuation, val));
}

static inline errval_t ping_pong_stop__tx(struct ping_pong_binding *_binding, struct event_closure _continuation) __attribute__ ((always_inline));
static inline errval_t ping_pong_stop__tx(struct ping_pong_binding *_binding, struct event_closure _continuation)
{
    return(((_binding->tx_vtbl).stop)(_binding, _continuation));
}

static inline errval_t ping_pong_testrpc_call__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t testin) __attribute__ ((always_inline));
static inline errval_t ping_pong_testrpc_call__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t testin)
{
    return(((_binding->tx_vtbl).testrpc_call)(_binding, _continuation, testin));
}

static inline errval_t ping_pong_testrpc_response__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t testout) __attribute__ ((always_inline));
static inline errval_t ping_pong_testrpc_response__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t testout)
{
    return(((_binding->tx_vtbl).testrpc_response)(_binding, _continuation, testout));
}

static inline errval_t ping_pong_testrpc2_call__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t testin) __attribute__ ((always_inline));
static inline errval_t ping_pong_testrpc2_call__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t testin)
{
    return(((_binding->tx_vtbl).testrpc2_call)(_binding, _continuation, testin));
}

static inline errval_t ping_pong_testrpc2_response__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t testout) __attribute__ ((always_inline));
static inline errval_t ping_pong_testrpc2_response__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t testout)
{
    return(((_binding->tx_vtbl).testrpc2_response)(_binding, _continuation, testout));
}

static inline errval_t ping_pong_outoforder_call__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_in, uint64_t testin) __attribute__ ((always_inline));
static inline errval_t ping_pong_outoforder_call__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_in, uint64_t testin)
{
    return(((_binding->tx_vtbl).outoforder_call)(_binding, _continuation, seq_in, testin));
}

static inline errval_t ping_pong_outoforder_response__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_out, uint64_t testout) __attribute__ ((always_inline));
static inline errval_t ping_pong_outoforder_response__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_out, uint64_t testout)
{
    return(((_binding->tx_vtbl).outoforder_response)(_binding, _continuation, seq_out, testout));
}

static inline errval_t ping_pong_str0__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *s) __attribute__ ((always_inline));
static inline errval_t ping_pong_str0__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *s)
{
    return(((_binding->tx_vtbl).str0)(_binding, _continuation, arg1, s));
}

static inline errval_t ping_pong_str1__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *s) __attribute__ ((always_inline));
static inline errval_t ping_pong_str1__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *s)
{
    return(((_binding->tx_vtbl).str1)(_binding, _continuation, arg1, s));
}

static inline errval_t ping_pong_str2__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *s) __attribute__ ((always_inline));
static inline errval_t ping_pong_str2__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *s)
{
    return(((_binding->tx_vtbl).str2)(_binding, _continuation, arg1, s));
}

static inline errval_t ping_pong_str3_call__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *s) __attribute__ ((always_inline));
static inline errval_t ping_pong_str3_call__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *s)
{
    return(((_binding->tx_vtbl).str3_call)(_binding, _continuation, arg1, s));
}

static inline errval_t ping_pong_str3_response__tx(struct ping_pong_binding *_binding, struct event_closure _continuation) __attribute__ ((always_inline));
static inline errval_t ping_pong_str3_response__tx(struct ping_pong_binding *_binding, struct event_closure _continuation)
{
    return(((_binding->tx_vtbl).str3_response)(_binding, _continuation));
}

static inline errval_t ping_pong_str4_call__tx(struct ping_pong_binding *_binding, struct event_closure _continuation) __attribute__ ((always_inline));
static inline errval_t ping_pong_str4_call__tx(struct ping_pong_binding *_binding, struct event_closure _continuation)
{
    return(((_binding->tx_vtbl).str4_call)(_binding, _continuation));
}

static inline errval_t ping_pong_str4_response__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *s) __attribute__ ((always_inline));
static inline errval_t ping_pong_str4_response__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *s)
{
    return(((_binding->tx_vtbl).str4_response)(_binding, _continuation, arg1, s));
}

static inline errval_t ping_pong_str5_call__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_in, uint32_t arg1, const char *s) __attribute__ ((always_inline));
static inline errval_t ping_pong_str5_call__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_in, uint32_t arg1, const char *s)
{
    return(((_binding->tx_vtbl).str5_call)(_binding, _continuation, seq_in, arg1, s));
}

static inline errval_t ping_pong_str5_response__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_out) __attribute__ ((always_inline));
static inline errval_t ping_pong_str5_response__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_out)
{
    return(((_binding->tx_vtbl).str5_response)(_binding, _continuation, seq_out));
}

static inline errval_t ping_pong_str6_call__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_in) __attribute__ ((always_inline));
static inline errval_t ping_pong_str6_call__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_in)
{
    return(((_binding->tx_vtbl).str6_call)(_binding, _continuation, seq_in));
}

static inline errval_t ping_pong_str6_response__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_out, uint32_t arg1, const char *s) __attribute__ ((always_inline));
static inline errval_t ping_pong_str6_response__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint64_t seq_out, uint32_t arg1, const char *s)
{
    return(((_binding->tx_vtbl).str6_response)(_binding, _continuation, seq_out, arg1, s));
}

static inline errval_t ping_pong_arr0__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *a, size_t l) __attribute__ ((always_inline));
static inline errval_t ping_pong_arr0__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *a, size_t l)
{
    return(((_binding->tx_vtbl).arr0)(_binding, _continuation, arg1, a, l));
}

static inline errval_t ping_pong_arr1__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *a, size_t l) __attribute__ ((always_inline));
static inline errval_t ping_pong_arr1__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *a, size_t l)
{
    return(((_binding->tx_vtbl).arr1)(_binding, _continuation, arg1, a, l));
}

static inline errval_t ping_pong_arr2__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *a, size_t l) __attribute__ ((always_inline));
static inline errval_t ping_pong_arr2__tx(struct ping_pong_binding *_binding, struct event_closure _continuation, uint32_t arg1, const char *a, size_t l)
{
    return(((_binding->tx_vtbl).arr2)(_binding, _continuation, arg1, a, l));
}


/*
 * Backend-specific includes
 */
#ifdef CONFIG_FLOUNDER_BACKEND_LMP
#include <if/ping_pong_lmp_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_LMP
#ifdef CONFIG_FLOUNDER_BACKEND_UMP
#include <if/ping_pong_ump_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_UMP
#ifdef CONFIG_FLOUNDER_BACKEND_UMP_IPI
#include <if/ping_pong_ump_ipi_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_UMP_IPI
#ifdef CONFIG_FLOUNDER_BACKEND_MULTIHOP
#include <if/ping_pong_multihop_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_MULTIHOP
/*
 * And we're done
 */
#endif // __ping_pong_IF_H
