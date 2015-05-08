#ifndef __terminal_IF_H
#define __terminal_IF_H 1
/*
 * Copyright (c) 2010, ETH Zurich.
 * All rights reserved.
 * 
 * INTERFACE NAME: terminal
 * INTEFACE FILE: ../if/terminal.if
 * INTERFACE DESCRIPTION: Unidirectional character stream.
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
typedef uint64_t terminal_genpaddr_t;
typedef uint64_t terminal_genvaddr_t;
typedef uint32_t terminal_rsrcid_t;
typedef uint64_t terminal_errval_t;
typedef uint64_t terminal_cycles_t;
typedef uint32_t terminal_iref_t;
typedef uint8_t terminal_coreid_t;
typedef uint32_t terminal_domainid_t;

/*
 * Forward declaration of binding type
 */
struct terminal_binding;

/*
 * Contination (callback) and control function types
 */
typedef  void terminal_bind_continuation_fn(void *st, errval_t err, struct terminal_binding *_binding);
typedef  bool terminal_can_send_fn(struct terminal_binding *_binding);
typedef  errval_t terminal_register_send_fn(struct terminal_binding *_binding, struct waitset *ws, struct event_closure _continuation);
typedef  errval_t terminal_change_waitset_fn(struct terminal_binding *_binding, struct waitset *ws);
typedef  errval_t terminal_control_fn(struct terminal_binding *_binding, idc_control_t control);
typedef  void terminal_error_handler_fn(struct terminal_binding *_binding, errval_t err);

/*
 * Enumeration for message numbers
 */
typedef enum terminal_msg_enum {
    terminal___dummy__msgnum = 0,
    terminal___bind__msgnum = 1,
    terminal___bind_reply__msgnum = 2,
    terminal_characters__msgnum = 3
} terminal_msg_enum;

/*
 * Message type signatures (transmit)
 */
typedef  errval_t terminal_characters__tx_method_fn(struct terminal_binding *_binding, struct event_closure _continuation, const char *buffer, size_t length);

/*
 * Message type signatures (receive)
 */
typedef  void terminal_characters__rx_method_fn(struct terminal_binding *_binding, char *buffer, size_t length);

/*
 * Struct type for holding the args for each msg
 */
struct terminal_characters__args {
    char *buffer;
    size_t length;
};

/*
 * Union type for all message arguments
 */
union terminal_arg_union {
    struct terminal_characters__args characters;
};

/*
 * VTable struct definition for the interface (transmit)
 */
struct terminal_tx_vtbl {
    terminal_characters__tx_method_fn *characters;
};

/*
 * VTable struct definition for the interface (receive)
 */
struct terminal_rx_vtbl {
    terminal_characters__rx_method_fn *characters;
};

/*
 * Incoming connect callback type
 */
typedef  errval_t terminal_connect_fn(void *st, struct terminal_binding *binding);

/*
 * Export state struct
 */
struct terminal_export {
    struct idc_export common;
    terminal_connect_fn *connect_cb;
    struct waitset *waitset;
    void *st;
};

/*
 * Export function
 */
extern  errval_t terminal_export(void *st, idc_export_callback_fn *export_cb, terminal_connect_fn *connect_cb, struct waitset *ws, idc_export_flags_t flags);

/*
 * The message buffer structure (for accept/connect)
 */
struct terminal_frameinfo {
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
extern  errval_t terminal_accept(struct terminal_frameinfo *_frameinfo, void *st, terminal_bind_continuation_fn *_continuation, struct waitset *ws, idc_export_flags_t flags);

/*
 * The Binding structure
 */
struct terminal_binding {
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
    terminal_can_send_fn *can_send;
    
    /* register an event for when a message is likely to be able to be sent */
    terminal_register_send_fn *register_send;
    
    /* change the waitset used by a binding */
    terminal_change_waitset_fn *change_waitset;
    
    /* perform control operations */
    terminal_control_fn *control;
    
    /* error handler for any async errors associated with this binding */
    /* must be filled-in by user */
    terminal_error_handler_fn *error_handler;
    
    /* Message send functions (filled in by binding) */
    struct terminal_tx_vtbl tx_vtbl;
    
    /* Incoming message handlers (filled in by user) */
    struct terminal_rx_vtbl rx_vtbl;
    
    /* Private state belonging to the binding implementation */
    union terminal_arg_union tx_union;
    union terminal_arg_union rx_union;
    struct waitset_chanstate register_chanstate;
    struct waitset_chanstate tx_cont_chanstate;
    enum terminal_msg_enum tx_msgnum;
    enum terminal_msg_enum rx_msgnum;
    int tx_msg_fragment;
    int rx_msg_fragment;
    size_t tx_str_pos;
    size_t rx_str_pos;
    size_t tx_str_len;
    size_t rx_str_len;
    struct event_queue_node event_qnode;
    terminal_bind_continuation_fn *bind_cont;
};

/*
 * Generic bind function
 */
extern  errval_t terminal_bind(iref_t i, terminal_bind_continuation_fn *_continuation, void *st, struct waitset *waitset, idc_bind_flags_t flags);

/*
 * Generic connect function over already shared frame
 */
extern  errval_t terminal_connect(struct terminal_frameinfo *_frameinfo, terminal_bind_continuation_fn *_continuation, void *st, struct waitset *ws, idc_bind_flags_t flags);

/*
 * Send wrappers
 */
static inline errval_t terminal_characters__tx(struct terminal_binding *_binding, struct event_closure _continuation, const char *buffer, size_t length) __attribute__ ((always_inline));
static inline errval_t terminal_characters__tx(struct terminal_binding *_binding, struct event_closure _continuation, const char *buffer, size_t length)
{
    return(((_binding->tx_vtbl).characters)(_binding, _continuation, buffer, length));
}


/*
 * Backend-specific includes
 */
#ifdef CONFIG_FLOUNDER_BACKEND_LMP
#include <if/terminal_lmp_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_LMP
#ifdef CONFIG_FLOUNDER_BACKEND_UMP
#include <if/terminal_ump_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_UMP
#ifdef CONFIG_FLOUNDER_BACKEND_UMP_IPI
#include <if/terminal_ump_ipi_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_UMP_IPI
#ifdef CONFIG_FLOUNDER_BACKEND_MULTIHOP
#include <if/terminal_multihop_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_MULTIHOP
/*
 * And we're done
 */
#endif // __terminal_IF_H
