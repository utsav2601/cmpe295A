#ifndef __xeon_phi_manager_IF_H
#define __xeon_phi_manager_IF_H 1
/*
 * Copyright (c) 2010, ETH Zurich.
 * All rights reserved.
 * 
 * INTERFACE NAME: xeon_phi_manager
 * INTEFACE FILE: ../if/xeon_phi_manager.if
 * INTERFACE DESCRIPTION: Xeon Phi Manager Interface
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
typedef uint64_t xeon_phi_manager_genpaddr_t;
typedef uint64_t xeon_phi_manager_genvaddr_t;
typedef uint32_t xeon_phi_manager_rsrcid_t;
typedef uint64_t xeon_phi_manager_errval_t;
typedef uint64_t xeon_phi_manager_cycles_t;
typedef uint32_t xeon_phi_manager_iref_t;
typedef uint8_t xeon_phi_manager_coreid_t;
typedef uint32_t xeon_phi_manager_domainid_t;
struct _xeon_phi_manager_cards__struct {
    uint8_t num;
    iref_t card0;
    iref_t card1;
    iref_t card2;
    iref_t card3;
    iref_t card4;
    iref_t card5;
    iref_t card6;
    iref_t card7;
};
typedef struct _xeon_phi_manager_cards__struct xeon_phi_manager_cards_t;

/*
 * Forward declaration of binding type
 */
struct xeon_phi_manager_binding;

/*
 * Contination (callback) and control function types
 */
typedef  void xeon_phi_manager_bind_continuation_fn(void *st, errval_t err, struct xeon_phi_manager_binding *_binding);
typedef  bool xeon_phi_manager_can_send_fn(struct xeon_phi_manager_binding *_binding);
typedef  errval_t xeon_phi_manager_register_send_fn(struct xeon_phi_manager_binding *_binding, struct waitset *ws, struct event_closure _continuation);
typedef  errval_t xeon_phi_manager_change_waitset_fn(struct xeon_phi_manager_binding *_binding, struct waitset *ws);
typedef  errval_t xeon_phi_manager_control_fn(struct xeon_phi_manager_binding *_binding, idc_control_t control);
typedef  void xeon_phi_manager_error_handler_fn(struct xeon_phi_manager_binding *_binding, errval_t err);

/*
 * Enumeration for message numbers
 */
typedef enum xeon_phi_manager_msg_enum {
    xeon_phi_manager___dummy__msgnum = 0,
    xeon_phi_manager___bind__msgnum = 1,
    xeon_phi_manager___bind_reply__msgnum = 2,
    xeon_phi_manager_register_driver_call__msgnum = 3,
    xeon_phi_manager_register_driver_response__msgnum = 4,
    xeon_phi_manager_terminate_call__msgnum = 5,
    xeon_phi_manager_terminate_response__msgnum = 6,
    xeon_phi_manager_lookup_call__msgnum = 7,
    xeon_phi_manager_lookup_response__msgnum = 8
} xeon_phi_manager_msg_enum;

/*
 * Message type signatures (transmit)
 */
typedef  errval_t xeon_phi_manager_register_driver_call__tx_method_fn(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation, iref_t svc);
typedef  errval_t xeon_phi_manager_register_driver_response__tx_method_fn(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation, uint8_t id, xeon_phi_manager_cards_t irefs, xeon_phi_manager_errval_t msgerr);
typedef  errval_t xeon_phi_manager_terminate_call__tx_method_fn(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation);
typedef  errval_t xeon_phi_manager_terminate_response__tx_method_fn(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation);
typedef  errval_t xeon_phi_manager_lookup_call__tx_method_fn(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation, uint8_t xid);
typedef  errval_t xeon_phi_manager_lookup_response__tx_method_fn(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation, iref_t svc, xeon_phi_manager_errval_t msgerr);

/*
 * Message type signatures (receive)
 */
typedef  void xeon_phi_manager_register_driver_call__rx_method_fn(struct xeon_phi_manager_binding *_binding, iref_t svc);
typedef  void xeon_phi_manager_register_driver_response__rx_method_fn(struct xeon_phi_manager_binding *_binding, uint8_t id, xeon_phi_manager_cards_t irefs, xeon_phi_manager_errval_t msgerr);
typedef  void xeon_phi_manager_terminate_call__rx_method_fn(struct xeon_phi_manager_binding *_binding);
typedef  void xeon_phi_manager_terminate_response__rx_method_fn(struct xeon_phi_manager_binding *_binding);
typedef  void xeon_phi_manager_lookup_call__rx_method_fn(struct xeon_phi_manager_binding *_binding, uint8_t xid);
typedef  void xeon_phi_manager_lookup_response__rx_method_fn(struct xeon_phi_manager_binding *_binding, iref_t svc, xeon_phi_manager_errval_t msgerr);

/*
 * Struct type for holding the args for each msg
 */
struct xeon_phi_manager_register_driver_call__args {
    iref_t svc;
};
struct xeon_phi_manager_register_driver_response__args {
    uint8_t id;
    xeon_phi_manager_cards_t irefs;
    xeon_phi_manager_errval_t msgerr;
};
struct xeon_phi_manager_lookup_call__args {
    uint8_t xid;
};
struct xeon_phi_manager_lookup_response__args {
    iref_t svc;
    xeon_phi_manager_errval_t msgerr;
};

/*
 * Union type for all message arguments
 */
union xeon_phi_manager_arg_union {
    struct xeon_phi_manager_register_driver_call__args register_driver_call;
    struct xeon_phi_manager_register_driver_response__args register_driver_response;
    struct xeon_phi_manager_lookup_call__args lookup_call;
    struct xeon_phi_manager_lookup_response__args lookup_response;
};

/*
 * VTable struct definition for the interface (transmit)
 */
struct xeon_phi_manager_tx_vtbl {
    xeon_phi_manager_register_driver_call__tx_method_fn *register_driver_call;
    xeon_phi_manager_register_driver_response__tx_method_fn *register_driver_response;
    xeon_phi_manager_terminate_call__tx_method_fn *terminate_call;
    xeon_phi_manager_terminate_response__tx_method_fn *terminate_response;
    xeon_phi_manager_lookup_call__tx_method_fn *lookup_call;
    xeon_phi_manager_lookup_response__tx_method_fn *lookup_response;
};

/*
 * VTable struct definition for the interface (receive)
 */
struct xeon_phi_manager_rx_vtbl {
    xeon_phi_manager_register_driver_call__rx_method_fn *register_driver_call;
    xeon_phi_manager_register_driver_response__rx_method_fn *register_driver_response;
    xeon_phi_manager_terminate_call__rx_method_fn *terminate_call;
    xeon_phi_manager_terminate_response__rx_method_fn *terminate_response;
    xeon_phi_manager_lookup_call__rx_method_fn *lookup_call;
    xeon_phi_manager_lookup_response__rx_method_fn *lookup_response;
};

/*
 * Incoming connect callback type
 */
typedef  errval_t xeon_phi_manager_connect_fn(void *st, struct xeon_phi_manager_binding *binding);

/*
 * Export state struct
 */
struct xeon_phi_manager_export {
    struct idc_export common;
    xeon_phi_manager_connect_fn *connect_cb;
    struct waitset *waitset;
    void *st;
};

/*
 * Export function
 */
extern  errval_t xeon_phi_manager_export(void *st, idc_export_callback_fn *export_cb, xeon_phi_manager_connect_fn *connect_cb, struct waitset *ws, idc_export_flags_t flags);

/*
 * The message buffer structure (for accept/connect)
 */
struct xeon_phi_manager_frameinfo {
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
extern  errval_t xeon_phi_manager_accept(struct xeon_phi_manager_frameinfo *_frameinfo, void *st, xeon_phi_manager_bind_continuation_fn *_continuation, struct waitset *ws, idc_export_flags_t flags);

/*
 * The Binding structure
 */
struct xeon_phi_manager_binding {
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
    xeon_phi_manager_can_send_fn *can_send;
    
    /* register an event for when a message is likely to be able to be sent */
    xeon_phi_manager_register_send_fn *register_send;
    
    /* change the waitset used by a binding */
    xeon_phi_manager_change_waitset_fn *change_waitset;
    
    /* perform control operations */
    xeon_phi_manager_control_fn *control;
    
    /* error handler for any async errors associated with this binding */
    /* must be filled-in by user */
    xeon_phi_manager_error_handler_fn *error_handler;
    
    /* Message send functions (filled in by binding) */
    struct xeon_phi_manager_tx_vtbl tx_vtbl;
    
    /* Incoming message handlers (filled in by user) */
    struct xeon_phi_manager_rx_vtbl rx_vtbl;
    
    /* Private state belonging to the binding implementation */
    union xeon_phi_manager_arg_union tx_union;
    union xeon_phi_manager_arg_union rx_union;
    struct waitset_chanstate register_chanstate;
    struct waitset_chanstate tx_cont_chanstate;
    enum xeon_phi_manager_msg_enum tx_msgnum;
    enum xeon_phi_manager_msg_enum rx_msgnum;
    int tx_msg_fragment;
    int rx_msg_fragment;
    size_t tx_str_pos;
    size_t rx_str_pos;
    size_t tx_str_len;
    size_t rx_str_len;
    struct event_queue_node event_qnode;
    xeon_phi_manager_bind_continuation_fn *bind_cont;
};

/*
 * Generic bind function
 */
extern  errval_t xeon_phi_manager_bind(iref_t i, xeon_phi_manager_bind_continuation_fn *_continuation, void *st, struct waitset *waitset, idc_bind_flags_t flags);

/*
 * Generic connect function over already shared frame
 */
extern  errval_t xeon_phi_manager_connect(struct xeon_phi_manager_frameinfo *_frameinfo, xeon_phi_manager_bind_continuation_fn *_continuation, void *st, struct waitset *ws, idc_bind_flags_t flags);

/*
 * Send wrappers
 */
static inline errval_t xeon_phi_manager_register_driver_call__tx(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation, iref_t svc) __attribute__ ((always_inline));
static inline errval_t xeon_phi_manager_register_driver_call__tx(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation, iref_t svc)
{
    return(((_binding->tx_vtbl).register_driver_call)(_binding, _continuation, svc));
}

static inline errval_t xeon_phi_manager_register_driver_response__tx(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation, uint8_t id, xeon_phi_manager_cards_t irefs, xeon_phi_manager_errval_t msgerr) __attribute__ ((always_inline));
static inline errval_t xeon_phi_manager_register_driver_response__tx(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation, uint8_t id, xeon_phi_manager_cards_t irefs, xeon_phi_manager_errval_t msgerr)
{
    return(((_binding->tx_vtbl).register_driver_response)(_binding, _continuation, id, irefs, msgerr));
}

static inline errval_t xeon_phi_manager_terminate_call__tx(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation) __attribute__ ((always_inline));
static inline errval_t xeon_phi_manager_terminate_call__tx(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation)
{
    return(((_binding->tx_vtbl).terminate_call)(_binding, _continuation));
}

static inline errval_t xeon_phi_manager_terminate_response__tx(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation) __attribute__ ((always_inline));
static inline errval_t xeon_phi_manager_terminate_response__tx(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation)
{
    return(((_binding->tx_vtbl).terminate_response)(_binding, _continuation));
}

static inline errval_t xeon_phi_manager_lookup_call__tx(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation, uint8_t xid) __attribute__ ((always_inline));
static inline errval_t xeon_phi_manager_lookup_call__tx(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation, uint8_t xid)
{
    return(((_binding->tx_vtbl).lookup_call)(_binding, _continuation, xid));
}

static inline errval_t xeon_phi_manager_lookup_response__tx(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation, iref_t svc, xeon_phi_manager_errval_t msgerr) __attribute__ ((always_inline));
static inline errval_t xeon_phi_manager_lookup_response__tx(struct xeon_phi_manager_binding *_binding, struct event_closure _continuation, iref_t svc, xeon_phi_manager_errval_t msgerr)
{
    return(((_binding->tx_vtbl).lookup_response)(_binding, _continuation, svc, msgerr));
}


/*
 * Backend-specific includes
 */
#ifdef CONFIG_FLOUNDER_BACKEND_LMP
#include <if/xeon_phi_manager_lmp_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_LMP
#ifdef CONFIG_FLOUNDER_BACKEND_UMP
#include <if/xeon_phi_manager_ump_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_UMP
#ifdef CONFIG_FLOUNDER_BACKEND_UMP_IPI
#include <if/xeon_phi_manager_ump_ipi_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_UMP_IPI
#ifdef CONFIG_FLOUNDER_BACKEND_MULTIHOP
#include <if/xeon_phi_manager_multihop_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_MULTIHOP
/*
 * And we're done
 */
#endif // __xeon_phi_manager_IF_H
