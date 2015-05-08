#ifndef __xeon_phi_serial_DEV_H
#define __xeon_phi_serial_DEV_H 1
/*
 * DEVICE DEFINITION: Intel Xeon Phi Software Scratch Registers
 * 
 * Copyright (c) 2010, ETH Zurich.
 * All rights reserved.
 * 
 * This file is distributed under the terms in the attached LICENSE
 * file. If you do not find this file, copies can be found by
 * writing to:
 * ETH Zurich D-INFK, Universitaetstr. 6, CH-8092 Zurich.
 * Attn: Systems Group.
 * 
 * THIS FILE IS AUTOMATICALLY GENERATED BY MACKEREL: DO NOT EDIT!
 */
#include <mackerel/mackerel.h>
#include <inttypes.h>
#undef __DN
#define __DN(x) xeon_phi_serial ## _ ## x
/*
 * Constants defn: xeon_phi_serial.ctrl_values (Constants)
 *  - width 8 bits
 */
typedef uint8_t xeon_phi_serial_ctrl_values_t;
#define xeon_phi_serial_reset ((xeon_phi_serial_ctrl_values_t)0x0)
#define xeon_phi_serial_data ((xeon_phi_serial_ctrl_values_t)0x7a)

static inline char *xeon_phi_serial_ctrl_values_describe(xeon_phi_serial_ctrl_values_t _e) __attribute__ ((always_inline));
static inline char *xeon_phi_serial_ctrl_values_describe(xeon_phi_serial_ctrl_values_t _e)
{
    switch (_e) {
    case xeon_phi_serial_reset:
        return("reset: reset");
    case xeon_phi_serial_data:
        return("data: data");
    default:
        return(NULL);
    }
}

static inline int xeon_phi_serial_ctrl_values_prtval(char *_s, size_t _size, xeon_phi_serial_ctrl_values_t _e) __attribute__ ((always_inline));
static inline int xeon_phi_serial_ctrl_values_prtval(char *_s, size_t _size, xeon_phi_serial_ctrl_values_t _e)
{
    char *d = xeon_phi_serial_ctrl_values_describe(_e);
    if (d) {
        return(snprintf(_s, _size, "%s", d));
    } else {
        return(snprintf(_s, _size, "Unknown constant %s value 0x%" PRIx64, "xeon_phi_serial_ctrl_values_t", (uint64_t )(_e)));
    }
}

/*
 * Register type: xeon_phi_serial_data_t
 * Description: Implicit type of  register
 * Fields:
 *   value0	(size 8, offset 0, init 0):	RW	Datavalue to send
 *   value1	(size 8, offset 8, init 0):	RW	Datavalue to send
 *   value2	(size 8, offset 16, init 0):	RW	Datavalue to send
 *   value3	(size 8, offset 24, init 0):	RW	Datavalue to send
 */
typedef uint32_t xeon_phi_serial_data_t;
#define xeon_phi_serial_data_default 0x0
static inline uint8_t xeon_phi_serial_data_value0_extract(xeon_phi_serial_data_t _regval) __attribute__ ((always_inline));
static inline uint8_t xeon_phi_serial_data_value0_extract(xeon_phi_serial_data_t _regval)
{
    return((uint8_t )((_regval & 0xff) >> 0));
}

static inline xeon_phi_serial_data_t xeon_phi_serial_data_value0_insert(xeon_phi_serial_data_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xeon_phi_serial_data_t xeon_phi_serial_data_value0_insert(xeon_phi_serial_data_t _regval, uint8_t _fieldval)
{
    return((_regval & 0xffffff00) | (0xff & (((xeon_phi_serial_data_t )(_fieldval)) << 0)));
}

static inline uint8_t xeon_phi_serial_data_value1_extract(xeon_phi_serial_data_t _regval) __attribute__ ((always_inline));
static inline uint8_t xeon_phi_serial_data_value1_extract(xeon_phi_serial_data_t _regval)
{
    return((uint8_t )((_regval & 0xff00) >> 8));
}

static inline xeon_phi_serial_data_t xeon_phi_serial_data_value1_insert(xeon_phi_serial_data_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xeon_phi_serial_data_t xeon_phi_serial_data_value1_insert(xeon_phi_serial_data_t _regval, uint8_t _fieldval)
{
    return((_regval & 0xffff00ff) | (0xff00 & (((xeon_phi_serial_data_t )(_fieldval)) << 8)));
}

static inline uint8_t xeon_phi_serial_data_value2_extract(xeon_phi_serial_data_t _regval) __attribute__ ((always_inline));
static inline uint8_t xeon_phi_serial_data_value2_extract(xeon_phi_serial_data_t _regval)
{
    return((uint8_t )((_regval & 0xff0000) >> 16));
}

static inline xeon_phi_serial_data_t xeon_phi_serial_data_value2_insert(xeon_phi_serial_data_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xeon_phi_serial_data_t xeon_phi_serial_data_value2_insert(xeon_phi_serial_data_t _regval, uint8_t _fieldval)
{
    return((_regval & 0xff00ffff) | (0xff0000 & (((xeon_phi_serial_data_t )(_fieldval)) << 16)));
}

static inline uint8_t xeon_phi_serial_data_value3_extract(xeon_phi_serial_data_t _regval) __attribute__ ((always_inline));
static inline uint8_t xeon_phi_serial_data_value3_extract(xeon_phi_serial_data_t _regval)
{
    return((uint8_t )((_regval & 0xff000000) >> 24));
}

static inline xeon_phi_serial_data_t xeon_phi_serial_data_value3_insert(xeon_phi_serial_data_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xeon_phi_serial_data_t xeon_phi_serial_data_value3_insert(xeon_phi_serial_data_t _regval, uint8_t _fieldval)
{
    return((_regval & 0xffffff) | (0xff000000 & (((xeon_phi_serial_data_t )(_fieldval)) << 24)));
}

static inline int xeon_phi_serial_data_prtval(char *_s, size_t _size, xeon_phi_serial_data_t _regval) __attribute__ ((always_inline));
static inline int xeon_phi_serial_data_prtval(char *_s, size_t _size, xeon_phi_serial_data_t _regval)
{
    int _r = 0;
    int _avail;
    int _rc;
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, " value0 =\t%" PRIx8 "\t(Datavalue to send)\n", xeon_phi_serial_data_value0_extract(_regval));
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, " value1 =\t%" PRIx8 "\t(Datavalue to send)\n", xeon_phi_serial_data_value1_extract(_regval));
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, " value2 =\t%" PRIx8 "\t(Datavalue to send)\n", xeon_phi_serial_data_value2_extract(_regval));
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, " value3 =\t%" PRIx8 "\t(Datavalue to send)\n", xeon_phi_serial_data_value3_extract(_regval));
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    return(_r);
}

/*
 * Register type: xeon_phi_serial_ctrl_t
 * Description: Implicit type of  register
 * Fields:
 *   value0	(size 8, offset 0, init 0):	RW	Datavalue to send
 *   value1	(size 8, offset 8, init 0):	RW	Datavalue to send
 *   value2	(size 8, offset 16, init 0):	RW	Datavalue to send
 *   value3	(size 8, offset 24, init 0):	RW	Datavalue to send
 */
typedef uint32_t xeon_phi_serial_ctrl_t;
#define xeon_phi_serial_ctrl_default 0x0
static inline uint8_t xeon_phi_serial_ctrl_value0_extract(xeon_phi_serial_ctrl_t _regval) __attribute__ ((always_inline));
static inline uint8_t xeon_phi_serial_ctrl_value0_extract(xeon_phi_serial_ctrl_t _regval)
{
    return((uint8_t )((_regval & 0xff) >> 0));
}

static inline xeon_phi_serial_ctrl_t xeon_phi_serial_ctrl_value0_insert(xeon_phi_serial_ctrl_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xeon_phi_serial_ctrl_t xeon_phi_serial_ctrl_value0_insert(xeon_phi_serial_ctrl_t _regval, uint8_t _fieldval)
{
    return((_regval & 0xffffff00) | (0xff & (((xeon_phi_serial_ctrl_t )(_fieldval)) << 0)));
}

static inline uint8_t xeon_phi_serial_ctrl_value1_extract(xeon_phi_serial_ctrl_t _regval) __attribute__ ((always_inline));
static inline uint8_t xeon_phi_serial_ctrl_value1_extract(xeon_phi_serial_ctrl_t _regval)
{
    return((uint8_t )((_regval & 0xff00) >> 8));
}

static inline xeon_phi_serial_ctrl_t xeon_phi_serial_ctrl_value1_insert(xeon_phi_serial_ctrl_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xeon_phi_serial_ctrl_t xeon_phi_serial_ctrl_value1_insert(xeon_phi_serial_ctrl_t _regval, uint8_t _fieldval)
{
    return((_regval & 0xffff00ff) | (0xff00 & (((xeon_phi_serial_ctrl_t )(_fieldval)) << 8)));
}

static inline uint8_t xeon_phi_serial_ctrl_value2_extract(xeon_phi_serial_ctrl_t _regval) __attribute__ ((always_inline));
static inline uint8_t xeon_phi_serial_ctrl_value2_extract(xeon_phi_serial_ctrl_t _regval)
{
    return((uint8_t )((_regval & 0xff0000) >> 16));
}

static inline xeon_phi_serial_ctrl_t xeon_phi_serial_ctrl_value2_insert(xeon_phi_serial_ctrl_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xeon_phi_serial_ctrl_t xeon_phi_serial_ctrl_value2_insert(xeon_phi_serial_ctrl_t _regval, uint8_t _fieldval)
{
    return((_regval & 0xff00ffff) | (0xff0000 & (((xeon_phi_serial_ctrl_t )(_fieldval)) << 16)));
}

static inline uint8_t xeon_phi_serial_ctrl_value3_extract(xeon_phi_serial_ctrl_t _regval) __attribute__ ((always_inline));
static inline uint8_t xeon_phi_serial_ctrl_value3_extract(xeon_phi_serial_ctrl_t _regval)
{
    return((uint8_t )((_regval & 0xff000000) >> 24));
}

static inline xeon_phi_serial_ctrl_t xeon_phi_serial_ctrl_value3_insert(xeon_phi_serial_ctrl_t _regval, uint8_t _fieldval) __attribute__ ((always_inline));
static inline xeon_phi_serial_ctrl_t xeon_phi_serial_ctrl_value3_insert(xeon_phi_serial_ctrl_t _regval, uint8_t _fieldval)
{
    return((_regval & 0xffffff) | (0xff000000 & (((xeon_phi_serial_ctrl_t )(_fieldval)) << 24)));
}

static inline int xeon_phi_serial_ctrl_prtval(char *_s, size_t _size, xeon_phi_serial_ctrl_t _regval) __attribute__ ((always_inline));
static inline int xeon_phi_serial_ctrl_prtval(char *_s, size_t _size, xeon_phi_serial_ctrl_t _regval)
{
    int _r = 0;
    int _avail;
    int _rc;
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, " value0 =\t%" PRIx8 "\t(Datavalue to send)\n", xeon_phi_serial_ctrl_value0_extract(_regval));
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, " value1 =\t%" PRIx8 "\t(Datavalue to send)\n", xeon_phi_serial_ctrl_value1_extract(_regval));
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, " value2 =\t%" PRIx8 "\t(Datavalue to send)\n", xeon_phi_serial_ctrl_value2_extract(_regval));
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, " value3 =\t%" PRIx8 "\t(Datavalue to send)\n", xeon_phi_serial_ctrl_value3_extract(_regval));
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    return(_r);
}

/*
 * Device representation structure
 */
struct __DN(t) {
    mackerel_addr_t base;
};
typedef struct __DN(t) __DN(t);

/*
 * Initial register values (currently 0)
 */
enum xeon_phi_serial_initials {
    xeon_phi_serial_data_initial = 0x0,
    xeon_phi_serial_ctrl_initial = 0x0
};

/*
 * Device Initialization function
 */
static inline void xeon_phi_serial_initialize(__DN(t) *_dev, mackerel_addr_t base) __attribute__ ((always_inline));
static inline void xeon_phi_serial_initialize(__DN(t) *_dev, mackerel_addr_t base)
{
    _dev->base = base;
}

/*
 * Register data: 
 * Type: xeon_phi_serial.data (Implicit type of  register)
 *   value0	(size 8, offset 0, init 0):	RW	Datavalue to send
 *   value1	(size 8, offset 8, init 0):	RW	Datavalue to send
 *   value2	(size 8, offset 16, init 0):	RW	Datavalue to send
 *   value3	(size 8, offset 24, init 0):	RW	Datavalue to send
 */
static inline xeon_phi_serial_data_t xeon_phi_serial_data_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xeon_phi_serial_data_t xeon_phi_serial_data_rawrd(__DN(t) *_dev)
{
    return(mackerel_read_addr_32(_dev->base, 0xab5c));
}

static inline xeon_phi_serial_data_t xeon_phi_serial_data_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xeon_phi_serial_data_t xeon_phi_serial_data_rd(__DN(t) *_dev)
{
    return(mackerel_read_addr_32(_dev->base, 0xab5c));
}

static inline void xeon_phi_serial_data_rawwr(__DN(t) *_dev, xeon_phi_serial_data_t _regval) __attribute__ ((always_inline));
static inline void xeon_phi_serial_data_rawwr(__DN(t) *_dev, xeon_phi_serial_data_t _regval)
{
    mackerel_write_addr_32(_dev->base, 0xab5c, _regval);
}

static inline void xeon_phi_serial_data_wr(__DN(t) *_dev, xeon_phi_serial_data_t _regval) __attribute__ ((always_inline));
static inline void xeon_phi_serial_data_wr(__DN(t) *_dev, xeon_phi_serial_data_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    mackerel_write_addr_32(_dev->base, 0xab5c, _regval);
}

static inline int xeon_phi_serial_data_pr(char *_s, size_t _size, __DN(t) *_dev) __attribute__ ((always_inline));
static inline int xeon_phi_serial_data_pr(char *_s, size_t _size, __DN(t) *_dev)
{
    int _r = 0;
    int _avail;
    int _rc;
    xeon_phi_serial_data_t _regval = mackerel_read_addr_32(_dev->base, 0xab5c);
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, "Register data (): ");
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, "\n");
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, " value0 =\t%" PRIx8 "\t(Datavalue to send)\n", xeon_phi_serial_data_value0_extract(_regval));
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, " value1 =\t%" PRIx8 "\t(Datavalue to send)\n", xeon_phi_serial_data_value1_extract(_regval));
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, " value2 =\t%" PRIx8 "\t(Datavalue to send)\n", xeon_phi_serial_data_value2_extract(_regval));
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, " value3 =\t%" PRIx8 "\t(Datavalue to send)\n", xeon_phi_serial_data_value3_extract(_regval));
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    return(_r);
}

static inline uint8_t xeon_phi_serial_data_value0_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xeon_phi_serial_data_value0_rdf(__DN(t) *_dev)
{
    xeon_phi_serial_data_t _regval = mackerel_read_addr_32(_dev->base, 0xab5c);
    return(xeon_phi_serial_data_value0_extract(_regval));
}

static inline uint8_t xeon_phi_serial_data_value1_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xeon_phi_serial_data_value1_rdf(__DN(t) *_dev)
{
    xeon_phi_serial_data_t _regval = mackerel_read_addr_32(_dev->base, 0xab5c);
    return(xeon_phi_serial_data_value1_extract(_regval));
}

static inline uint8_t xeon_phi_serial_data_value2_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xeon_phi_serial_data_value2_rdf(__DN(t) *_dev)
{
    xeon_phi_serial_data_t _regval = mackerel_read_addr_32(_dev->base, 0xab5c);
    return(xeon_phi_serial_data_value2_extract(_regval));
}

static inline uint8_t xeon_phi_serial_data_value3_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xeon_phi_serial_data_value3_rdf(__DN(t) *_dev)
{
    xeon_phi_serial_data_t _regval = mackerel_read_addr_32(_dev->base, 0xab5c);
    return(xeon_phi_serial_data_value3_extract(_regval));
}

static inline void xeon_phi_serial_data_value0_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xeon_phi_serial_data_value0_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xeon_phi_serial_data_t _regval = 0xff & (((xeon_phi_serial_data_t )(_fieldval)) << 0);
    _regval = (_regval | (0xffffff00 & mackerel_read_addr_32(_dev->base, 0xab5c)));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mackerel_write_addr_32(_dev->base, 0xab5c, _regval);
    // No shadow register to write to
}

static inline void xeon_phi_serial_data_value1_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xeon_phi_serial_data_value1_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xeon_phi_serial_data_t _regval = 0xff00 & (((xeon_phi_serial_data_t )(_fieldval)) << 8);
    _regval = (_regval | (0xffff00ff & mackerel_read_addr_32(_dev->base, 0xab5c)));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mackerel_write_addr_32(_dev->base, 0xab5c, _regval);
    // No shadow register to write to
}

static inline void xeon_phi_serial_data_value2_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xeon_phi_serial_data_value2_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xeon_phi_serial_data_t _regval = 0xff0000 & (((xeon_phi_serial_data_t )(_fieldval)) << 16);
    _regval = (_regval | (0xff00ffff & mackerel_read_addr_32(_dev->base, 0xab5c)));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mackerel_write_addr_32(_dev->base, 0xab5c, _regval);
    // No shadow register to write to
}

static inline void xeon_phi_serial_data_value3_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xeon_phi_serial_data_value3_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xeon_phi_serial_data_t _regval = 0xff000000 & (((xeon_phi_serial_data_t )(_fieldval)) << 24);
    _regval = (_regval | (0xffffff & mackerel_read_addr_32(_dev->base, 0xab5c)));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mackerel_write_addr_32(_dev->base, 0xab5c, _regval);
    // No shadow register to write to
}

/*
 * Register ctrl: 
 * Type: xeon_phi_serial.ctrl (Implicit type of  register)
 *   value0	(size 8, offset 0, init 0):	RW	Datavalue to send
 *   value1	(size 8, offset 8, init 0):	RW	Datavalue to send
 *   value2	(size 8, offset 16, init 0):	RW	Datavalue to send
 *   value3	(size 8, offset 24, init 0):	RW	Datavalue to send
 */
static inline xeon_phi_serial_ctrl_t xeon_phi_serial_ctrl_rawrd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xeon_phi_serial_ctrl_t xeon_phi_serial_ctrl_rawrd(__DN(t) *_dev)
{
    return(mackerel_read_addr_32(_dev->base, 0xab40));
}

static inline xeon_phi_serial_ctrl_t xeon_phi_serial_ctrl_rd(__DN(t) *_dev) __attribute__ ((always_inline));
static inline xeon_phi_serial_ctrl_t xeon_phi_serial_ctrl_rd(__DN(t) *_dev)
{
    return(mackerel_read_addr_32(_dev->base, 0xab40));
}

static inline void xeon_phi_serial_ctrl_rawwr(__DN(t) *_dev, xeon_phi_serial_ctrl_t _regval) __attribute__ ((always_inline));
static inline void xeon_phi_serial_ctrl_rawwr(__DN(t) *_dev, xeon_phi_serial_ctrl_t _regval)
{
    mackerel_write_addr_32(_dev->base, 0xab40, _regval);
}

static inline void xeon_phi_serial_ctrl_wr(__DN(t) *_dev, xeon_phi_serial_ctrl_t _regval) __attribute__ ((always_inline));
static inline void xeon_phi_serial_ctrl_wr(__DN(t) *_dev, xeon_phi_serial_ctrl_t _regval)
{
    // No MB0 or RSVD fields present
    // No MB1 fields present
    // No pre-read of register required
    mackerel_write_addr_32(_dev->base, 0xab40, _regval);
}

static inline int xeon_phi_serial_ctrl_pr(char *_s, size_t _size, __DN(t) *_dev) __attribute__ ((always_inline));
static inline int xeon_phi_serial_ctrl_pr(char *_s, size_t _size, __DN(t) *_dev)
{
    int _r = 0;
    int _avail;
    int _rc;
    xeon_phi_serial_ctrl_t _regval = mackerel_read_addr_32(_dev->base, 0xab40);
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, "Register ctrl (): ");
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, "\n");
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, " value0 =\t%" PRIx8 "\t(Datavalue to send)\n", xeon_phi_serial_ctrl_value0_extract(_regval));
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, " value1 =\t%" PRIx8 "\t(Datavalue to send)\n", xeon_phi_serial_ctrl_value1_extract(_regval));
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, " value2 =\t%" PRIx8 "\t(Datavalue to send)\n", xeon_phi_serial_ctrl_value2_extract(_regval));
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, " value3 =\t%" PRIx8 "\t(Datavalue to send)\n", xeon_phi_serial_ctrl_value3_extract(_regval));
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    return(_r);
}

static inline uint8_t xeon_phi_serial_ctrl_value0_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xeon_phi_serial_ctrl_value0_rdf(__DN(t) *_dev)
{
    xeon_phi_serial_ctrl_t _regval = mackerel_read_addr_32(_dev->base, 0xab40);
    return(xeon_phi_serial_ctrl_value0_extract(_regval));
}

static inline uint8_t xeon_phi_serial_ctrl_value1_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xeon_phi_serial_ctrl_value1_rdf(__DN(t) *_dev)
{
    xeon_phi_serial_ctrl_t _regval = mackerel_read_addr_32(_dev->base, 0xab40);
    return(xeon_phi_serial_ctrl_value1_extract(_regval));
}

static inline uint8_t xeon_phi_serial_ctrl_value2_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xeon_phi_serial_ctrl_value2_rdf(__DN(t) *_dev)
{
    xeon_phi_serial_ctrl_t _regval = mackerel_read_addr_32(_dev->base, 0xab40);
    return(xeon_phi_serial_ctrl_value2_extract(_regval));
}

static inline uint8_t xeon_phi_serial_ctrl_value3_rdf(__DN(t) *_dev) __attribute__ ((always_inline));
static inline uint8_t xeon_phi_serial_ctrl_value3_rdf(__DN(t) *_dev)
{
    xeon_phi_serial_ctrl_t _regval = mackerel_read_addr_32(_dev->base, 0xab40);
    return(xeon_phi_serial_ctrl_value3_extract(_regval));
}

static inline void xeon_phi_serial_ctrl_value0_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xeon_phi_serial_ctrl_value0_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xeon_phi_serial_ctrl_t _regval = 0xff & (((xeon_phi_serial_ctrl_t )(_fieldval)) << 0);
    _regval = (_regval | (0xffffff00 & mackerel_read_addr_32(_dev->base, 0xab40)));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mackerel_write_addr_32(_dev->base, 0xab40, _regval);
    // No shadow register to write to
}

static inline void xeon_phi_serial_ctrl_value1_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xeon_phi_serial_ctrl_value1_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xeon_phi_serial_ctrl_t _regval = 0xff00 & (((xeon_phi_serial_ctrl_t )(_fieldval)) << 8);
    _regval = (_regval | (0xffff00ff & mackerel_read_addr_32(_dev->base, 0xab40)));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mackerel_write_addr_32(_dev->base, 0xab40, _regval);
    // No shadow register to write to
}

static inline void xeon_phi_serial_ctrl_value2_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xeon_phi_serial_ctrl_value2_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xeon_phi_serial_ctrl_t _regval = 0xff0000 & (((xeon_phi_serial_ctrl_t )(_fieldval)) << 16);
    _regval = (_regval | (0xff00ffff & mackerel_read_addr_32(_dev->base, 0xab40)));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mackerel_write_addr_32(_dev->base, 0xab40, _regval);
    // No shadow register to write to
}

static inline void xeon_phi_serial_ctrl_value3_wrf(__DN(t) *_dev, uint8_t _fieldval) __attribute__ ((always_inline));
static inline void xeon_phi_serial_ctrl_value3_wrf(__DN(t) *_dev, uint8_t _fieldval)
{
    xeon_phi_serial_ctrl_t _regval = 0xff000000 & (((xeon_phi_serial_ctrl_t )(_fieldval)) << 24);
    _regval = (_regval | (0xffffff & mackerel_read_addr_32(_dev->base, 0xab40)));
    // No read of register shadow required
    // No MB0 fields present
    // No MB1 fields present
    mackerel_write_addr_32(_dev->base, 0xab40, _regval);
    // No shadow register to write to
}

static inline int xeon_phi_serial_pr(char *_s, size_t _size, __DN(t) *_dev) __attribute__ ((always_inline));
static inline int xeon_phi_serial_pr(char *_s, size_t _size, __DN(t) *_dev)
{
    int _r = 0;
    int _avail;
    int _rc;
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, "-------------------------\n");
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, "Dump of device xeon_phi_serial (Intel Xeon Phi Software Scratch Registers):\n");
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = xeon_phi_serial_data_pr(_s + _r, _avail, _dev);
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = xeon_phi_serial_ctrl_pr(_s + _r, _avail, _dev);
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, "End of dump of device xeon_phi_serial\n");
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    _avail = ((_r > _size) ? 0 : (_size - _r));
    _rc = snprintf(_s + _r, _avail, "-------------------------\n");
    if ((_rc > 0) && (_rc < _avail)) {
        _r = (_r + _rc);
    }
    return(_r);
}

#undef __DN
#endif // __xeon_phi_serial_DEV_H
