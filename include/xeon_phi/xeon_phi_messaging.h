/*
 * Copyright (c) 2014 ETH Zurich.
 * All rights reserved.
 *
 * This file is distributed under the terms in the attached LICENSE file.
 * If you do not find this file, copies can be found by writing to:
 * ETH Zurich D-INFK, Universitaetsstrasse 6, CH-8092 Zurich. Attn: Systems Group.
 */

#ifndef XEON_PHI_MESSAGING_H_
#define XEON_PHI_MESSAGING_H_


struct xeon_phi_msg_open
{
    lpaddr_t base;
    uint64_t size;
    char name[40];
};





#endif // XEON_PHI_MESSAGING_H_
