#ifndef __omap_sdma_THC_IF_H
#define __omap_sdma_THC_IF_H 1
/*
 * Copyright (c) 2010, ETH Zurich.
 * All rights reserved.
 * 
 * INTERFACE NAME: omap_sdma
 * INTEFACE FILE: ../if/omap_sdma.if
 * INTERFACE DESCRIPTION: Interface for the OMAP44xx SDMA driver
 * 
 * This file is distributed under the terms in the attached LICENSE
 * file. If you do not find this file, copies can be found by
 * writing to:
 * ETH Zurich D-INFK, Universitaetstr.6, CH-8092 Zurich.
 * Attn: Systems Group.
 * 
 * THIS FILE IS AUTOMATICALLY GENERATED BY FLOUNDER: DO NOT EDIT!
 */
#ifdef BARRELFISH
#include "thc/thcstubs.h"
#include "if/omap_sdma_defs.h"
#else
#include "thcstubs.h"
#include "omap_sdma.h"
#endif // BARRELFISH

/*
 * Typedefs for binding structures
 */

typedef struct omap_sdma_thc_client_binding_t omap_sdma_thc_client_binding_t;
typedef struct omap_sdma_thc_service_binding_t omap_sdma_thc_service_binding_t;

/*
 * Struct type for holding the args for each msg
 */
struct omap_sdma_mem_copy__in_args_t {
    struct capref dst;
    struct capref src;
};
struct omap_sdma_mem_copy__out_args_t {
    omap_sdma_errval_t err;
};
union omap_sdma_mem_copy___union_t {
    struct omap_sdma_mem_copy__in_args_t in;
    struct omap_sdma_mem_copy__out_args_t out;
};
struct omap_sdma_mem_fill__in_args_t {
    struct capref dst;
    uint8_t color;
};
struct omap_sdma_mem_fill__out_args_t {
    omap_sdma_errval_t err;
};
union omap_sdma_mem_fill___union_t {
    struct omap_sdma_mem_fill__in_args_t in;
    struct omap_sdma_mem_fill__out_args_t out;
};
struct omap_sdma_mem_copy_2d__in_args_t {
    omap_sdma_addr_2d_t dst;
    omap_sdma_addr_2d_t src;
    omap_sdma_count_2d_t count;
    bool transparent;
    omap_sdma_uint24_t color;
};
struct omap_sdma_mem_copy_2d__out_args_t {
    omap_sdma_errval_t err;
};
union omap_sdma_mem_copy_2d___union_t {
    struct omap_sdma_mem_copy_2d__in_args_t in;
    struct omap_sdma_mem_copy_2d__out_args_t out;
};
struct omap_sdma_mem_fill_2d__in_args_t {
    omap_sdma_addr_2d_t dst;
    omap_sdma_uint24_t color;
    omap_sdma_count_2d_t count;
};
struct omap_sdma_mem_fill_2d__out_args_t {
    omap_sdma_errval_t err;
};
union omap_sdma_mem_fill_2d___union_t {
    struct omap_sdma_mem_fill_2d__in_args_t in;
    struct omap_sdma_mem_fill_2d__out_args_t out;
};

/*
 * Union type for all message arguments
 */
union omap_sdma_thc_arg_union {
    union omap_sdma_mem_copy___union_t mem_copy;
    union omap_sdma_mem_fill___union_t mem_fill;
    union omap_sdma_mem_copy_2d___union_t mem_copy_2d;
    union omap_sdma_mem_fill_2d___union_t mem_fill_2d;
};

/*
 * Enumerations for message numbers
 */
typedef enum omap_sdma_msg_enum_t {
    omap_sdma_mem_copy,
    omap_sdma_mem_fill,
    omap_sdma_mem_copy_2d,
    omap_sdma_mem_fill_2d
} omap_sdma_msg_enum_t;
typedef enum omap_sdma_call_msg_enum_t {
    omap_sdma__call_mem_copy,
    omap_sdma__call_mem_fill,
    omap_sdma__call_mem_copy_2d,
    omap_sdma__call_mem_fill_2d
} omap_sdma_call_msg_enum_t;
typedef enum omap_sdma_resp_msg_enum_t {
    omap_sdma__resp_mem_copy,
    omap_sdma__resp_mem_fill,
    omap_sdma__resp_mem_copy_2d,
    omap_sdma__resp_mem_fill_2d
} omap_sdma_resp_msg_enum_t;


/*
 * Signatures for individual send/receive operations
 */

typedef  errval_t (*omap_sdma_mem_copy__thc_client_send_t)(omap_sdma_thc_client_binding_t *_thc_binding, struct capref dst, struct capref src);
typedef  errval_t (*omap_sdma_mem_fill__thc_client_send_t)(omap_sdma_thc_client_binding_t *_thc_binding, struct capref dst, uint8_t color);
typedef  errval_t (*omap_sdma_mem_copy_2d__thc_client_send_t)(omap_sdma_thc_client_binding_t *_thc_binding, omap_sdma_addr_2d_t dst, omap_sdma_addr_2d_t src, omap_sdma_count_2d_t count, bool transparent, omap_sdma_uint24_t color);
typedef  errval_t (*omap_sdma_mem_fill_2d__thc_client_send_t)(omap_sdma_thc_client_binding_t *_thc_binding, omap_sdma_addr_2d_t dst, omap_sdma_uint24_t color, omap_sdma_count_2d_t count);
typedef  errval_t (*omap_sdma_mem_copy__thc_client_send_t_x)(omap_sdma_thc_client_binding_t *_thc_binding, struct capref dst, struct capref src);
typedef  errval_t (*omap_sdma_mem_fill__thc_client_send_t_x)(omap_sdma_thc_client_binding_t *_thc_binding, struct capref dst, uint8_t color);
typedef  errval_t (*omap_sdma_mem_copy_2d__thc_client_send_t_x)(omap_sdma_thc_client_binding_t *_thc_binding, omap_sdma_addr_2d_t dst, omap_sdma_addr_2d_t src, omap_sdma_count_2d_t count, bool transparent, omap_sdma_uint24_t color);
typedef  errval_t (*omap_sdma_mem_fill_2d__thc_client_send_t_x)(omap_sdma_thc_client_binding_t *_thc_binding, omap_sdma_addr_2d_t dst, omap_sdma_uint24_t color, omap_sdma_count_2d_t count);
typedef  errval_t (*omap_sdma_mem_copy__thc_service_recv_t)(omap_sdma_thc_service_binding_t *_thc_binding, struct capref *dst, struct capref *src);
typedef  errval_t (*omap_sdma_mem_fill__thc_service_recv_t)(omap_sdma_thc_service_binding_t *_thc_binding, struct capref *dst, uint8_t *color);
typedef  errval_t (*omap_sdma_mem_copy_2d__thc_service_recv_t)(omap_sdma_thc_service_binding_t *_thc_binding, omap_sdma_addr_2d_t *dst, omap_sdma_addr_2d_t *src, omap_sdma_count_2d_t *count, bool *transparent, omap_sdma_uint24_t *color);
typedef  errval_t (*omap_sdma_mem_fill_2d__thc_service_recv_t)(omap_sdma_thc_service_binding_t *_thc_binding, omap_sdma_addr_2d_t *dst, omap_sdma_uint24_t *color, omap_sdma_count_2d_t *count);
typedef  errval_t (*omap_sdma_mem_copy__thc_service_recv_t_x)(omap_sdma_thc_service_binding_t *_thc_binding, struct capref *dst, struct capref *src);
typedef  errval_t (*omap_sdma_mem_fill__thc_service_recv_t_x)(omap_sdma_thc_service_binding_t *_thc_binding, struct capref *dst, uint8_t *color);
typedef  errval_t (*omap_sdma_mem_copy_2d__thc_service_recv_t_x)(omap_sdma_thc_service_binding_t *_thc_binding, omap_sdma_addr_2d_t *dst, omap_sdma_addr_2d_t *src, omap_sdma_count_2d_t *count, bool *transparent, omap_sdma_uint24_t *color);
typedef  errval_t (*omap_sdma_mem_fill_2d__thc_service_recv_t_x)(omap_sdma_thc_service_binding_t *_thc_binding, omap_sdma_addr_2d_t *dst, omap_sdma_uint24_t *color, omap_sdma_count_2d_t *count);
typedef  errval_t (*omap_sdma_mem_copy__thc_service_send_t)(omap_sdma_thc_service_binding_t *_thc_binding, omap_sdma_errval_t err);
typedef  errval_t (*omap_sdma_mem_fill__thc_service_send_t)(omap_sdma_thc_service_binding_t *_thc_binding, omap_sdma_errval_t err);
typedef  errval_t (*omap_sdma_mem_copy_2d__thc_service_send_t)(omap_sdma_thc_service_binding_t *_thc_binding, omap_sdma_errval_t err);
typedef  errval_t (*omap_sdma_mem_fill_2d__thc_service_send_t)(omap_sdma_thc_service_binding_t *_thc_binding, omap_sdma_errval_t err);
typedef  errval_t (*omap_sdma_mem_copy__thc_service_send_t_x)(omap_sdma_thc_service_binding_t *_thc_binding, omap_sdma_errval_t err);
typedef  errval_t (*omap_sdma_mem_fill__thc_service_send_t_x)(omap_sdma_thc_service_binding_t *_thc_binding, omap_sdma_errval_t err);
typedef  errval_t (*omap_sdma_mem_copy_2d__thc_service_send_t_x)(omap_sdma_thc_service_binding_t *_thc_binding, omap_sdma_errval_t err);
typedef  errval_t (*omap_sdma_mem_fill_2d__thc_service_send_t_x)(omap_sdma_thc_service_binding_t *_thc_binding, omap_sdma_errval_t err);
typedef  errval_t (*omap_sdma_mem_copy__thc_client_recv_t)(omap_sdma_thc_client_binding_t *_thc_binding, omap_sdma_errval_t *err);
typedef  errval_t (*omap_sdma_mem_fill__thc_client_recv_t)(omap_sdma_thc_client_binding_t *_thc_binding, omap_sdma_errval_t *err);
typedef  errval_t (*omap_sdma_mem_copy_2d__thc_client_recv_t)(omap_sdma_thc_client_binding_t *_thc_binding, omap_sdma_errval_t *err);
typedef  errval_t (*omap_sdma_mem_fill_2d__thc_client_recv_t)(omap_sdma_thc_client_binding_t *_thc_binding, omap_sdma_errval_t *err);
typedef  errval_t (*omap_sdma_mem_copy__thc_client_recv_t_x)(omap_sdma_thc_client_binding_t *_thc_binding, omap_sdma_errval_t *err);
typedef  errval_t (*omap_sdma_mem_fill__thc_client_recv_t_x)(omap_sdma_thc_client_binding_t *_thc_binding, omap_sdma_errval_t *err);
typedef  errval_t (*omap_sdma_mem_copy_2d__thc_client_recv_t_x)(omap_sdma_thc_client_binding_t *_thc_binding, omap_sdma_errval_t *err);
typedef  errval_t (*omap_sdma_mem_fill_2d__thc_client_recv_t_x)(omap_sdma_thc_client_binding_t *_thc_binding, omap_sdma_errval_t *err);
typedef  errval_t (*omap_sdma_mem_copy__thc_call__t)(omap_sdma_thc_client_binding_t *_thc_binding, struct capref dst, struct capref src, omap_sdma_errval_t *err);
typedef  errval_t (*omap_sdma_mem_fill__thc_call__t)(omap_sdma_thc_client_binding_t *_thc_binding, struct capref dst, uint8_t color, omap_sdma_errval_t *err);
typedef  errval_t (*omap_sdma_mem_copy_2d__thc_call__t)(omap_sdma_thc_client_binding_t *_thc_binding, omap_sdma_addr_2d_t dst, omap_sdma_addr_2d_t src, omap_sdma_count_2d_t count, bool transparent, omap_sdma_uint24_t color, omap_sdma_errval_t *err);
typedef  errval_t (*omap_sdma_mem_fill_2d__thc_call__t)(omap_sdma_thc_client_binding_t *_thc_binding, omap_sdma_addr_2d_t dst, omap_sdma_uint24_t color, omap_sdma_count_2d_t count, omap_sdma_errval_t *err);
typedef  errval_t (*omap_sdma_mem_copy__thc_call__t_x)(omap_sdma_thc_client_binding_t *_thc_binding, struct capref dst, struct capref src, omap_sdma_errval_t *err);
typedef  errval_t (*omap_sdma_mem_fill__thc_call__t_x)(omap_sdma_thc_client_binding_t *_thc_binding, struct capref dst, uint8_t color, omap_sdma_errval_t *err);
typedef  errval_t (*omap_sdma_mem_copy_2d__thc_call__t_x)(omap_sdma_thc_client_binding_t *_thc_binding, omap_sdma_addr_2d_t dst, omap_sdma_addr_2d_t src, omap_sdma_count_2d_t count, bool transparent, omap_sdma_uint24_t color, omap_sdma_errval_t *err);
typedef  errval_t (*omap_sdma_mem_fill_2d__thc_call__t_x)(omap_sdma_thc_client_binding_t *_thc_binding, omap_sdma_addr_2d_t dst, omap_sdma_uint24_t color, omap_sdma_count_2d_t count, omap_sdma_errval_t *err);

/*
 * VTables of send/receive operations
 */

struct omap_sdma_thc_client_send_vtbl {
    omap_sdma_mem_copy__thc_client_send_t mem_copy;
    omap_sdma_mem_fill__thc_client_send_t mem_fill;
    omap_sdma_mem_copy_2d__thc_client_send_t mem_copy_2d;
    omap_sdma_mem_fill_2d__thc_client_send_t mem_fill_2d;
};
struct omap_sdma_thc_client_send_vtbl_x {
    omap_sdma_mem_copy__thc_client_send_t_x mem_copy;
    omap_sdma_mem_fill__thc_client_send_t_x mem_fill;
    omap_sdma_mem_copy_2d__thc_client_send_t_x mem_copy_2d;
    omap_sdma_mem_fill_2d__thc_client_send_t_x mem_fill_2d;
};
struct omap_sdma_thc_service_receive_vtbl {
    omap_sdma_mem_copy__thc_service_recv_t mem_copy;
    omap_sdma_mem_fill__thc_service_recv_t mem_fill;
    omap_sdma_mem_copy_2d__thc_service_recv_t mem_copy_2d;
    omap_sdma_mem_fill_2d__thc_service_recv_t mem_fill_2d;
};
struct omap_sdma_thc_service_receive_vtbl_x {
    omap_sdma_mem_copy__thc_service_recv_t_x mem_copy;
    omap_sdma_mem_fill__thc_service_recv_t_x mem_fill;
    omap_sdma_mem_copy_2d__thc_service_recv_t_x mem_copy_2d;
    omap_sdma_mem_fill_2d__thc_service_recv_t_x mem_fill_2d;
};
struct omap_sdma_service_selector {
    int mem_copy;
    int mem_fill;
    int mem_copy_2d;
    int mem_fill_2d;
};
struct omap_sdma_thc_service_send_vtbl {
    omap_sdma_mem_copy__thc_service_send_t mem_copy;
    omap_sdma_mem_fill__thc_service_send_t mem_fill;
    omap_sdma_mem_copy_2d__thc_service_send_t mem_copy_2d;
    omap_sdma_mem_fill_2d__thc_service_send_t mem_fill_2d;
};
struct omap_sdma_thc_service_send_vtbl_x {
    omap_sdma_mem_copy__thc_service_send_t_x mem_copy;
    omap_sdma_mem_fill__thc_service_send_t_x mem_fill;
    omap_sdma_mem_copy_2d__thc_service_send_t_x mem_copy_2d;
    omap_sdma_mem_fill_2d__thc_service_send_t_x mem_fill_2d;
};
struct omap_sdma_thc_client_receive_vtbl {
    omap_sdma_mem_copy__thc_client_recv_t mem_copy;
    omap_sdma_mem_fill__thc_client_recv_t mem_fill;
    omap_sdma_mem_copy_2d__thc_client_recv_t mem_copy_2d;
    omap_sdma_mem_fill_2d__thc_client_recv_t mem_fill_2d;
};
struct omap_sdma_thc_client_receive_vtbl_x {
    omap_sdma_mem_copy__thc_client_recv_t_x mem_copy;
    omap_sdma_mem_fill__thc_client_recv_t_x mem_fill;
    omap_sdma_mem_copy_2d__thc_client_recv_t_x mem_copy_2d;
    omap_sdma_mem_fill_2d__thc_client_recv_t_x mem_fill_2d;
};
struct omap_sdma_client_selector {
    int mem_copy;
    int mem_fill;
    int mem_copy_2d;
    int mem_fill_2d;
};

/*
 * VTables of RPC operations
 */

struct omap_sdma_thc_rpc_seq {
    omap_sdma_mem_copy__thc_call__t mem_copy;
    omap_sdma_mem_fill__thc_call__t mem_fill;
    omap_sdma_mem_copy_2d__thc_call__t mem_copy_2d;
    omap_sdma_mem_fill_2d__thc_call__t mem_fill_2d;
};
struct omap_sdma_thc_rpc_seq_x {
    omap_sdma_mem_copy__thc_call__t_x mem_copy;
    omap_sdma_mem_fill__thc_call__t_x mem_fill;
    omap_sdma_mem_copy_2d__thc_call__t_x mem_copy_2d;
    omap_sdma_mem_fill_2d__thc_call__t_x mem_fill_2d;
};
struct omap_sdma_thc_rpc_fifo {
    omap_sdma_mem_copy__thc_call__t mem_copy;
    omap_sdma_mem_fill__thc_call__t mem_fill;
    omap_sdma_mem_copy_2d__thc_call__t mem_copy_2d;
    omap_sdma_mem_fill_2d__thc_call__t mem_fill_2d;
};
struct omap_sdma_thc_rpc_fifo_x {
    omap_sdma_mem_copy__thc_call__t_x mem_copy;
    omap_sdma_mem_fill__thc_call__t_x mem_fill;
    omap_sdma_mem_copy_2d__thc_call__t_x mem_copy_2d;
    omap_sdma_mem_fill_2d__thc_call__t_x mem_fill_2d;
};
struct omap_sdma_thc_rpc_ooo {
};
struct omap_sdma_thc_rpc_ooo_x {
};

/*
 * Types for recv_any operations
 */

struct omap_sdma_client_msg {
    enum omap_sdma_msg_enum_t msg;
    union omap_sdma_thc_arg_union args;
};
typedef struct omap_sdma_client_msg omap_sdma_client_msg_t;
typedef  errval_t (*omap_sdma_recv_any__thc_client_t)(omap_sdma_thc_client_binding_t *_thc_binding, struct omap_sdma_client_msg *msg, struct omap_sdma_client_selector ops);
typedef  errval_t (*omap_sdma_recv_any__thc_client_t_x)(omap_sdma_thc_client_binding_t *_thc_binding, struct omap_sdma_client_msg *msg, struct omap_sdma_client_selector ops);
struct omap_sdma_service_msg {
    enum omap_sdma_msg_enum_t msg;
    union omap_sdma_thc_arg_union args;
};
typedef struct omap_sdma_service_msg omap_sdma_service_msg_t;
typedef  errval_t (*omap_sdma_recv_any__thc_service_t)(omap_sdma_thc_service_binding_t *_thc_binding, struct omap_sdma_service_msg *msg, struct omap_sdma_service_selector ops);
typedef  errval_t (*omap_sdma_recv_any__thc_service_t_x)(omap_sdma_thc_service_binding_t *_thc_binding, struct omap_sdma_service_msg *msg, struct omap_sdma_service_selector ops);

/*
 * Binding structures
 */

struct omap_sdma_thc_client_binding_t {
    struct thc_per_binding_state_t thc_per_binding;
    struct omap_sdma_thc_client_send_vtbl send;
    struct omap_sdma_thc_client_send_vtbl_x send_x;
    struct omap_sdma_thc_client_receive_vtbl recv;
    struct omap_sdma_thc_client_receive_vtbl_x recv_x;
    omap_sdma_recv_any__thc_client_t recv_any;
    omap_sdma_recv_any__thc_client_t_x recv_any_x;
    struct omap_sdma_thc_rpc_seq call_seq;
    struct omap_sdma_thc_rpc_fifo call_fifo;
    struct omap_sdma_thc_rpc_ooo call;
    struct omap_sdma_thc_rpc_seq_x call_seq_x;
    struct omap_sdma_thc_rpc_fifo_x call_fifo_x;
    struct omap_sdma_thc_rpc_ooo_x call_x;
    thc_seq_t ooo_rpc_seq;
    struct thc_per_recv_t thc_per_recv[4];
    void *_c2s_st;
    void *_s2c_st;
};
struct omap_sdma_thc_service_binding_t {
    struct thc_per_binding_state_t thc_per_binding;
    struct omap_sdma_thc_service_send_vtbl send;
    struct omap_sdma_thc_service_send_vtbl_x send_x;
    struct omap_sdma_thc_service_receive_vtbl recv;
    struct omap_sdma_thc_service_receive_vtbl_x recv_x;
    omap_sdma_recv_any__thc_service_t recv_any;
    omap_sdma_recv_any__thc_service_t_x recv_any_x;
    struct thc_per_recv_t thc_per_recv[4];
    void *_c2s_st;
    void *_s2c_st;
};

/*
 * Initialize a THC binding over an IDC binding
 * (defined in THC-stubs backend)
 */

extern  errval_t omap_sdma_thc_init_client(omap_sdma_thc_client_binding_t *thc, struct omap_sdma_binding *idc_c2s, struct omap_sdma_binding *idc_s2c);
extern  errval_t omap_sdma_thc_init_service(omap_sdma_thc_service_binding_t *thc, struct omap_sdma_binding *idc_c2s, struct omap_sdma_binding *idc_s2c);

/*
 * THC helper functions for establishing connections
 */
struct omap_sdma_thc_export_info {
    thc_sem_t export_cb_done_sem;
    thc_sem_t connect_cb_done_sem;
    thc_sem_t accept_call_present_sem;
    thc_lock_t next_accept_lock;
    struct omap_sdma_binding **b;
    thc_lock_t info_lock;
    errval_t err;
    const char *service_name;
    iref_t iref;
    iref_t *iref_ptr;
};
struct omap_sdma_thc_connect_info {
    thc_sem_t bind_cb_done_sem;
    errval_t err;
    struct omap_sdma_binding *b;
};
extern  errval_t omap_sdma_thc_export(struct omap_sdma_thc_export_info *info, const char *service_name, struct waitset *ws, idc_export_flags_t flags, iref_t *iref);
extern  errval_t omap_sdma_thc_accept(struct omap_sdma_thc_export_info *info, struct omap_sdma_binding **b);
extern  errval_t omap_sdma_thc_connect(iref_t iref, struct waitset *ws, idc_bind_flags_t flags, struct omap_sdma_binding **b);
extern  errval_t omap_sdma_thc_connect_by_name(const char *service_name, struct waitset *ws, idc_bind_flags_t flags, struct omap_sdma_binding **b);
#endif // __omap_sdma_THC_IF_H
