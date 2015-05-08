/*
 * Copyright (c) 2010, ETH Zurich.
 * All rights reserved.
 * 
 * INTERFACE NAME: mem
 * INTEFACE FILE: ../if/mem.if
 * INTERFACE DESCRIPTION: Memory allocation RPC interface
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
 * Generated Stub for RPC
 */

#include <barrelfish/barrelfish.h>
#include <flounder/flounder_support.h>
#include <if/mem_rpcclient_defs.h>

/*
 * RPC wrapper functions
 */
static  errval_t mem_allocate__rpc(struct mem_rpc_client *_rpc, uint8_t bits, mem_genpaddr_t minbase, mem_genpaddr_t maxlimit, mem_errval_t *ret, struct capref *mem_cap)
{
    errval_t _err = SYS_ERR_OK;
    assert(!(_rpc->rpc_in_progress));
    assert((_rpc->async_error) == SYS_ERR_OK);
    _rpc->rpc_in_progress = true;
    _rpc->reply_present = false;
    
    // call send function
    _err = ((((_rpc->b)->tx_vtbl).allocate_call)(_rpc->b, NOP_CONT, bits, minbase, maxlimit));
    if (err_is_fail(_err)) {
        goto out;
    }
    
    // wait for message to be sent and reply or error to be present
    while (((!(_rpc->reply_present)) || (!(((_rpc->b)->can_send)(_rpc->b)))) && ((_rpc->async_error) == SYS_ERR_OK)) {
        _err = event_dispatch(&(_rpc->rpc_waitset));
        if (err_is_fail(_err)) {
            _err = err_push(_err, LIB_ERR_EVENT_DISPATCH);
            goto out;
        }
    }
    
    if (err_is_fail(_rpc->async_error)) {
        _err = (_rpc->async_error);
        _rpc->async_error = SYS_ERR_OK;
        goto out;
    }
    
    // grab reply variables out of binding
    struct mem_binding *_binding = _rpc->b;
    *ret = (((_binding->rx_union).allocate_response).ret);
    *mem_cap = (((_binding->rx_union).allocate_response).mem_cap);
    
    out:
    _rpc->rpc_in_progress = false;
    return(_err);
}

static  errval_t mem_steal__rpc(struct mem_rpc_client *_rpc, uint8_t bits, mem_genpaddr_t minbase, mem_genpaddr_t maxlimit, mem_errval_t *ret, struct capref *mem_cap)
{
    errval_t _err = SYS_ERR_OK;
    assert(!(_rpc->rpc_in_progress));
    assert((_rpc->async_error) == SYS_ERR_OK);
    _rpc->rpc_in_progress = true;
    _rpc->reply_present = false;
    
    // call send function
    _err = ((((_rpc->b)->tx_vtbl).steal_call)(_rpc->b, NOP_CONT, bits, minbase, maxlimit));
    if (err_is_fail(_err)) {
        goto out;
    }
    
    // wait for message to be sent and reply or error to be present
    while (((!(_rpc->reply_present)) || (!(((_rpc->b)->can_send)(_rpc->b)))) && ((_rpc->async_error) == SYS_ERR_OK)) {
        _err = event_dispatch(&(_rpc->rpc_waitset));
        if (err_is_fail(_err)) {
            _err = err_push(_err, LIB_ERR_EVENT_DISPATCH);
            goto out;
        }
    }
    
    if (err_is_fail(_rpc->async_error)) {
        _err = (_rpc->async_error);
        _rpc->async_error = SYS_ERR_OK;
        goto out;
    }
    
    // grab reply variables out of binding
    struct mem_binding *_binding = _rpc->b;
    *ret = (((_binding->rx_union).steal_response).ret);
    *mem_cap = (((_binding->rx_union).steal_response).mem_cap);
    
    out:
    _rpc->rpc_in_progress = false;
    return(_err);
}

static  errval_t mem_available__rpc(struct mem_rpc_client *_rpc, mem_genpaddr_t *mem_avail, mem_genpaddr_t *mem_total)
{
    errval_t _err = SYS_ERR_OK;
    assert(!(_rpc->rpc_in_progress));
    assert((_rpc->async_error) == SYS_ERR_OK);
    _rpc->rpc_in_progress = true;
    _rpc->reply_present = false;
    
    // call send function
    _err = ((((_rpc->b)->tx_vtbl).available_call)(_rpc->b, NOP_CONT));
    if (err_is_fail(_err)) {
        goto out;
    }
    
    // wait for message to be sent and reply or error to be present
    while (((!(_rpc->reply_present)) || (!(((_rpc->b)->can_send)(_rpc->b)))) && ((_rpc->async_error) == SYS_ERR_OK)) {
        _err = event_dispatch(&(_rpc->rpc_waitset));
        if (err_is_fail(_err)) {
            _err = err_push(_err, LIB_ERR_EVENT_DISPATCH);
            goto out;
        }
    }
    
    if (err_is_fail(_rpc->async_error)) {
        _err = (_rpc->async_error);
        _rpc->async_error = SYS_ERR_OK;
        goto out;
    }
    
    // grab reply variables out of binding
    struct mem_binding *_binding = _rpc->b;
    *mem_avail = (((_binding->rx_union).available_response).mem_avail);
    *mem_total = (((_binding->rx_union).available_response).mem_total);
    
    out:
    _rpc->rpc_in_progress = false;
    return(_err);
}

static  errval_t mem_free_monitor__rpc(struct mem_rpc_client *_rpc, struct capref mem_cap, mem_genpaddr_t base, uint8_t bits, mem_errval_t *err)
{
    errval_t _err = SYS_ERR_OK;
    assert(!(_rpc->rpc_in_progress));
    assert((_rpc->async_error) == SYS_ERR_OK);
    _rpc->rpc_in_progress = true;
    _rpc->reply_present = false;
    
    // call send function
    _err = ((((_rpc->b)->tx_vtbl).free_monitor_call)(_rpc->b, NOP_CONT, mem_cap, base, bits));
    if (err_is_fail(_err)) {
        goto out;
    }
    
    // wait for message to be sent and reply or error to be present
    while (((!(_rpc->reply_present)) || (!(((_rpc->b)->can_send)(_rpc->b)))) && ((_rpc->async_error) == SYS_ERR_OK)) {
        _err = event_dispatch(&(_rpc->rpc_waitset));
        if (err_is_fail(_err)) {
            _err = err_push(_err, LIB_ERR_EVENT_DISPATCH);
            goto out;
        }
    }
    
    if (err_is_fail(_rpc->async_error)) {
        _err = (_rpc->async_error);
        _rpc->async_error = SYS_ERR_OK;
        goto out;
    }
    
    // grab reply variables out of binding
    struct mem_binding *_binding = _rpc->b;
    *err = (((_binding->rx_union).free_monitor_response).err);
    
    out:
    _rpc->rpc_in_progress = false;
    return(_err);
}


/*
 * Receive handlers
 */
static  void mem_allocate__rpc_rx_handler(struct mem_binding *_binding, mem_errval_t ret, struct capref mem_cap)
{
    // get RPC client state pointer
    struct mem_rpc_client *_rpc = _binding->st;
    
    // XXX: stash reply parameters in binding object
    // depending on the interconnect driver, they're probably already there
    ((_binding->rx_union).allocate_response).ret = ret;
    ((_binding->rx_union).allocate_response).mem_cap = mem_cap;
    
    // notify RPC function, and we're done
    _rpc->reply_present = true;
}

static  void mem_steal__rpc_rx_handler(struct mem_binding *_binding, mem_errval_t ret, struct capref mem_cap)
{
    // get RPC client state pointer
    struct mem_rpc_client *_rpc = _binding->st;
    
    // XXX: stash reply parameters in binding object
    // depending on the interconnect driver, they're probably already there
    ((_binding->rx_union).steal_response).ret = ret;
    ((_binding->rx_union).steal_response).mem_cap = mem_cap;
    
    // notify RPC function, and we're done
    _rpc->reply_present = true;
}

static  void mem_available__rpc_rx_handler(struct mem_binding *_binding, mem_genpaddr_t mem_avail, mem_genpaddr_t mem_total)
{
    // get RPC client state pointer
    struct mem_rpc_client *_rpc = _binding->st;
    
    // XXX: stash reply parameters in binding object
    // depending on the interconnect driver, they're probably already there
    ((_binding->rx_union).available_response).mem_avail = mem_avail;
    ((_binding->rx_union).available_response).mem_total = mem_total;
    
    // notify RPC function, and we're done
    _rpc->reply_present = true;
}

static  void mem_free_monitor__rpc_rx_handler(struct mem_binding *_binding, mem_errval_t err)
{
    // get RPC client state pointer
    struct mem_rpc_client *_rpc = _binding->st;
    
    // XXX: stash reply parameters in binding object
    // depending on the interconnect driver, they're probably already there
    ((_binding->rx_union).free_monitor_response).err = err;
    
    // notify RPC function, and we're done
    _rpc->reply_present = true;
}


/*
 * RPC Vtable
 */
static  struct mem_rpc_vtbl mem_rpc_vtbl = {
    .allocate = mem_allocate__rpc,
    .steal = mem_steal__rpc,
    .available = mem_available__rpc,
    .free_monitor = mem_free_monitor__rpc,
};

/*
 * Error handler
 */
static  void mem_rpc_client_error(struct mem_binding *_binding, errval_t _err)
{
    // get RPC client state pointer
    struct mem_rpc_client *_rpc = _binding->st;
    
    if (_rpc->rpc_in_progress) {
        assert(err_is_fail(_err));
        _rpc->async_error = _err;
        // kick waitset with dummy event
        flounder_support_register(&(_rpc->rpc_waitset), &(_rpc->dummy_chanstate), dummy_event_closure, true);
    } else {
        USER_PANIC_ERR(_err, "async error in RPC");
    }
}


/*
 * Init function
 */
 errval_t mem_rpc_client_init(struct mem_rpc_client *rpc, struct mem_binding *binding)
{
    errval_t _err;
    
    // Setup state of RPC client object
    rpc->b = binding;
    rpc->reply_present = false;
    rpc->rpc_in_progress = false;
    rpc->async_error = SYS_ERR_OK;
    waitset_init(&(rpc->rpc_waitset));
    flounder_support_waitset_chanstate_init(&(rpc->dummy_chanstate));
    rpc->vtbl = mem_rpc_vtbl;
    binding->st = rpc;
    
    // Change waitset on binding
    _err = ((binding->change_waitset)(binding, &(rpc->rpc_waitset)));
    if (err_is_fail(_err)) {
        waitset_destroy(&(rpc->rpc_waitset));
        return(err_push(_err, FLOUNDER_ERR_CHANGE_WAITSET));
    }
    
    // Set RX handlers on binding object for RPCs
    (binding->rx_vtbl).allocate_response = mem_allocate__rpc_rx_handler;
    (binding->rx_vtbl).steal_response = mem_steal__rpc_rx_handler;
    (binding->rx_vtbl).available_response = mem_available__rpc_rx_handler;
    (binding->rx_vtbl).free_monitor_response = mem_free_monitor__rpc_rx_handler;
    
    // Set error handler on binding object
    binding->error_handler = mem_rpc_client_error;
    
    return(SYS_ERR_OK);
}

