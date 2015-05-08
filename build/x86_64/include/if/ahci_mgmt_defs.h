#ifndef __ahci_mgmt_IF_H
#define __ahci_mgmt_IF_H 1
/*
 * Copyright (c) 2010, ETH Zurich.
 * All rights reserved.
 * 
 * INTERFACE NAME: ahci_mgmt
 * INTEFACE FILE: ../if/ahci_mgmt.if
 * INTERFACE DESCRIPTION: AHCI Management Daemon
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
typedef uint64_t ahci_mgmt_genpaddr_t;
typedef uint64_t ahci_mgmt_genvaddr_t;
typedef uint32_t ahci_mgmt_rsrcid_t;
typedef uint64_t ahci_mgmt_errval_t;
typedef uint64_t ahci_mgmt_cycles_t;
typedef uint32_t ahci_mgmt_iref_t;
typedef uint8_t ahci_mgmt_coreid_t;
typedef uint32_t ahci_mgmt_domainid_t;

/*
 * Forward declaration of binding type
 */
struct ahci_mgmt_binding;

/*
 * Contination (callback) and control function types
 */
typedef  void ahci_mgmt_bind_continuation_fn(void *st, errval_t err, struct ahci_mgmt_binding *_binding);
typedef  bool ahci_mgmt_can_send_fn(struct ahci_mgmt_binding *_binding);
typedef  errval_t ahci_mgmt_register_send_fn(struct ahci_mgmt_binding *_binding, struct waitset *ws, struct event_closure _continuation);
typedef  errval_t ahci_mgmt_change_waitset_fn(struct ahci_mgmt_binding *_binding, struct waitset *ws);
typedef  errval_t ahci_mgmt_control_fn(struct ahci_mgmt_binding *_binding, idc_control_t control);
typedef  void ahci_mgmt_error_handler_fn(struct ahci_mgmt_binding *_binding, errval_t err);

/*
 * Enumeration for message numbers
 */
typedef enum ahci_mgmt_msg_enum {
    ahci_mgmt___dummy__msgnum = 0,
    ahci_mgmt___bind__msgnum = 1,
    ahci_mgmt___bind_reply__msgnum = 2,
    ahci_mgmt_list_call__msgnum = 3,
    ahci_mgmt_list_response__msgnum = 4,
    ahci_mgmt_identify_call__msgnum = 5,
    ahci_mgmt_identify_response__msgnum = 6,
    ahci_mgmt_open_call__msgnum = 7,
    ahci_mgmt_open_response__msgnum = 8,
    ahci_mgmt_close_call__msgnum = 9,
    ahci_mgmt_close_response__msgnum = 10,
    ahci_mgmt_command_completed__msgnum = 11
} ahci_mgmt_msg_enum;

/*
 * Message type signatures (transmit)
 */
typedef  errval_t ahci_mgmt_list_call__tx_method_fn(struct ahci_mgmt_binding *_binding, struct event_closure _continuation);
typedef  errval_t ahci_mgmt_list_response__tx_method_fn(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, const uint8_t *port_ids, size_t len);
typedef  errval_t ahci_mgmt_identify_call__tx_method_fn(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, uint8_t port_id);
typedef  errval_t ahci_mgmt_identify_response__tx_method_fn(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, const uint8_t *identify_data, size_t data_len);
typedef  errval_t ahci_mgmt_open_call__tx_method_fn(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, uint8_t port_id);
typedef  errval_t ahci_mgmt_open_response__tx_method_fn(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, ahci_mgmt_errval_t status, struct capref controller_mem, uint64_t offset, uint32_t capabilities);
typedef  errval_t ahci_mgmt_close_call__tx_method_fn(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, uint8_t port_id);
typedef  errval_t ahci_mgmt_close_response__tx_method_fn(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, ahci_mgmt_errval_t status);
typedef  errval_t ahci_mgmt_command_completed__tx_method_fn(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, uint8_t port_id, uint32_t interrupt_status);

/*
 * Message type signatures (receive)
 */
typedef  void ahci_mgmt_list_call__rx_method_fn(struct ahci_mgmt_binding *_binding);
typedef  void ahci_mgmt_list_response__rx_method_fn(struct ahci_mgmt_binding *_binding, uint8_t *port_ids, size_t len);
typedef  void ahci_mgmt_identify_call__rx_method_fn(struct ahci_mgmt_binding *_binding, uint8_t port_id);
typedef  void ahci_mgmt_identify_response__rx_method_fn(struct ahci_mgmt_binding *_binding, uint8_t *identify_data, size_t data_len);
typedef  void ahci_mgmt_open_call__rx_method_fn(struct ahci_mgmt_binding *_binding, uint8_t port_id);
typedef  void ahci_mgmt_open_response__rx_method_fn(struct ahci_mgmt_binding *_binding, ahci_mgmt_errval_t status, struct capref controller_mem, uint64_t offset, uint32_t capabilities);
typedef  void ahci_mgmt_close_call__rx_method_fn(struct ahci_mgmt_binding *_binding, uint8_t port_id);
typedef  void ahci_mgmt_close_response__rx_method_fn(struct ahci_mgmt_binding *_binding, ahci_mgmt_errval_t status);
typedef  void ahci_mgmt_command_completed__rx_method_fn(struct ahci_mgmt_binding *_binding, uint8_t port_id, uint32_t interrupt_status);

/*
 * Struct type for holding the args for each msg
 */
struct ahci_mgmt_list_response__args {
    uint8_t *port_ids;
    size_t len;
};
struct ahci_mgmt_identify_call__args {
    uint8_t port_id;
};
struct ahci_mgmt_identify_response__args {
    uint8_t *identify_data;
    size_t data_len;
};
struct ahci_mgmt_open_call__args {
    uint8_t port_id;
};
struct ahci_mgmt_open_response__args {
    ahci_mgmt_errval_t status;
    struct capref controller_mem;
    uint64_t offset;
    uint32_t capabilities;
};
struct ahci_mgmt_close_call__args {
    uint8_t port_id;
};
struct ahci_mgmt_close_response__args {
    ahci_mgmt_errval_t status;
};
struct ahci_mgmt_command_completed__args {
    uint8_t port_id;
    uint32_t interrupt_status;
};

/*
 * Union type for all message arguments
 */
union ahci_mgmt_arg_union {
    struct ahci_mgmt_list_response__args list_response;
    struct ahci_mgmt_identify_call__args identify_call;
    struct ahci_mgmt_identify_response__args identify_response;
    struct ahci_mgmt_open_call__args open_call;
    struct ahci_mgmt_open_response__args open_response;
    struct ahci_mgmt_close_call__args close_call;
    struct ahci_mgmt_close_response__args close_response;
    struct ahci_mgmt_command_completed__args command_completed;
};

/*
 * VTable struct definition for the interface (transmit)
 */
struct ahci_mgmt_tx_vtbl {
    ahci_mgmt_list_call__tx_method_fn *list_call;
    ahci_mgmt_list_response__tx_method_fn *list_response;
    ahci_mgmt_identify_call__tx_method_fn *identify_call;
    ahci_mgmt_identify_response__tx_method_fn *identify_response;
    ahci_mgmt_open_call__tx_method_fn *open_call;
    ahci_mgmt_open_response__tx_method_fn *open_response;
    ahci_mgmt_close_call__tx_method_fn *close_call;
    ahci_mgmt_close_response__tx_method_fn *close_response;
    ahci_mgmt_command_completed__tx_method_fn *command_completed;
};

/*
 * VTable struct definition for the interface (receive)
 */
struct ahci_mgmt_rx_vtbl {
    ahci_mgmt_list_call__rx_method_fn *list_call;
    ahci_mgmt_list_response__rx_method_fn *list_response;
    ahci_mgmt_identify_call__rx_method_fn *identify_call;
    ahci_mgmt_identify_response__rx_method_fn *identify_response;
    ahci_mgmt_open_call__rx_method_fn *open_call;
    ahci_mgmt_open_response__rx_method_fn *open_response;
    ahci_mgmt_close_call__rx_method_fn *close_call;
    ahci_mgmt_close_response__rx_method_fn *close_response;
    ahci_mgmt_command_completed__rx_method_fn *command_completed;
};

/*
 * Incoming connect callback type
 */
typedef  errval_t ahci_mgmt_connect_fn(void *st, struct ahci_mgmt_binding *binding);

/*
 * Export state struct
 */
struct ahci_mgmt_export {
    struct idc_export common;
    ahci_mgmt_connect_fn *connect_cb;
    struct waitset *waitset;
    void *st;
};

/*
 * Export function
 */
extern  errval_t ahci_mgmt_export(void *st, idc_export_callback_fn *export_cb, ahci_mgmt_connect_fn *connect_cb, struct waitset *ws, idc_export_flags_t flags);

/*
 * The message buffer structure (for accept/connect)
 */
struct ahci_mgmt_frameinfo {
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
extern  errval_t ahci_mgmt_accept(struct ahci_mgmt_frameinfo *_frameinfo, void *st, ahci_mgmt_bind_continuation_fn *_continuation, struct waitset *ws, idc_export_flags_t flags);

/*
 * The Binding structure
 */
struct ahci_mgmt_binding {
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
    ahci_mgmt_can_send_fn *can_send;
    
    /* register an event for when a message is likely to be able to be sent */
    ahci_mgmt_register_send_fn *register_send;
    
    /* change the waitset used by a binding */
    ahci_mgmt_change_waitset_fn *change_waitset;
    
    /* perform control operations */
    ahci_mgmt_control_fn *control;
    
    /* error handler for any async errors associated with this binding */
    /* must be filled-in by user */
    ahci_mgmt_error_handler_fn *error_handler;
    
    /* Message send functions (filled in by binding) */
    struct ahci_mgmt_tx_vtbl tx_vtbl;
    
    /* Incoming message handlers (filled in by user) */
    struct ahci_mgmt_rx_vtbl rx_vtbl;
    
    /* Private state belonging to the binding implementation */
    union ahci_mgmt_arg_union tx_union;
    union ahci_mgmt_arg_union rx_union;
    struct waitset_chanstate register_chanstate;
    struct waitset_chanstate tx_cont_chanstate;
    enum ahci_mgmt_msg_enum tx_msgnum;
    enum ahci_mgmt_msg_enum rx_msgnum;
    int tx_msg_fragment;
    int rx_msg_fragment;
    size_t tx_str_pos;
    size_t rx_str_pos;
    size_t tx_str_len;
    size_t rx_str_len;
    struct event_queue_node event_qnode;
    ahci_mgmt_bind_continuation_fn *bind_cont;
};

/*
 * Generic bind function
 */
extern  errval_t ahci_mgmt_bind(iref_t i, ahci_mgmt_bind_continuation_fn *_continuation, void *st, struct waitset *waitset, idc_bind_flags_t flags);

/*
 * Generic connect function over already shared frame
 */
extern  errval_t ahci_mgmt_connect(struct ahci_mgmt_frameinfo *_frameinfo, ahci_mgmt_bind_continuation_fn *_continuation, void *st, struct waitset *ws, idc_bind_flags_t flags);

/*
 * Send wrappers
 */
static inline errval_t ahci_mgmt_list_call__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation) __attribute__ ((always_inline));
static inline errval_t ahci_mgmt_list_call__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation)
{
    return(((_binding->tx_vtbl).list_call)(_binding, _continuation));
}

static inline errval_t ahci_mgmt_list_response__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, const uint8_t *port_ids, size_t len) __attribute__ ((always_inline));
static inline errval_t ahci_mgmt_list_response__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, const uint8_t *port_ids, size_t len)
{
    return(((_binding->tx_vtbl).list_response)(_binding, _continuation, port_ids, len));
}

static inline errval_t ahci_mgmt_identify_call__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, uint8_t port_id) __attribute__ ((always_inline));
static inline errval_t ahci_mgmt_identify_call__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, uint8_t port_id)
{
    return(((_binding->tx_vtbl).identify_call)(_binding, _continuation, port_id));
}

static inline errval_t ahci_mgmt_identify_response__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, const uint8_t *identify_data, size_t data_len) __attribute__ ((always_inline));
static inline errval_t ahci_mgmt_identify_response__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, const uint8_t *identify_data, size_t data_len)
{
    return(((_binding->tx_vtbl).identify_response)(_binding, _continuation, identify_data, data_len));
}

static inline errval_t ahci_mgmt_open_call__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, uint8_t port_id) __attribute__ ((always_inline));
static inline errval_t ahci_mgmt_open_call__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, uint8_t port_id)
{
    return(((_binding->tx_vtbl).open_call)(_binding, _continuation, port_id));
}

static inline errval_t ahci_mgmt_open_response__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, ahci_mgmt_errval_t status, struct capref controller_mem, uint64_t offset, uint32_t capabilities) __attribute__ ((always_inline));
static inline errval_t ahci_mgmt_open_response__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, ahci_mgmt_errval_t status, struct capref controller_mem, uint64_t offset, uint32_t capabilities)
{
    return(((_binding->tx_vtbl).open_response)(_binding, _continuation, status, controller_mem, offset, capabilities));
}

static inline errval_t ahci_mgmt_close_call__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, uint8_t port_id) __attribute__ ((always_inline));
static inline errval_t ahci_mgmt_close_call__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, uint8_t port_id)
{
    return(((_binding->tx_vtbl).close_call)(_binding, _continuation, port_id));
}

static inline errval_t ahci_mgmt_close_response__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, ahci_mgmt_errval_t status) __attribute__ ((always_inline));
static inline errval_t ahci_mgmt_close_response__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, ahci_mgmt_errval_t status)
{
    return(((_binding->tx_vtbl).close_response)(_binding, _continuation, status));
}

static inline errval_t ahci_mgmt_command_completed__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, uint8_t port_id, uint32_t interrupt_status) __attribute__ ((always_inline));
static inline errval_t ahci_mgmt_command_completed__tx(struct ahci_mgmt_binding *_binding, struct event_closure _continuation, uint8_t port_id, uint32_t interrupt_status)
{
    return(((_binding->tx_vtbl).command_completed)(_binding, _continuation, port_id, interrupt_status));
}


/*
 * Backend-specific includes
 */
#ifdef CONFIG_FLOUNDER_BACKEND_LMP
#include <if/ahci_mgmt_lmp_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_LMP
#ifdef CONFIG_FLOUNDER_BACKEND_UMP
#include <if/ahci_mgmt_ump_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_UMP
#ifdef CONFIG_FLOUNDER_BACKEND_UMP_IPI
#include <if/ahci_mgmt_ump_ipi_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_UMP_IPI
#ifdef CONFIG_FLOUNDER_BACKEND_MULTIHOP
#include <if/ahci_mgmt_multihop_defs.h>
#endif // CONFIG_FLOUNDER_BACKEND_MULTIHOP
/*
 * And we're done
 */
#endif // __ahci_mgmt_IF_H
