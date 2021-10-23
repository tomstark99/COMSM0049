// SPDX-License-Identifier: GPL-2.0-only
/* TODO identify needed include */
include lsm_hooks.h

static int uob_socket_create(int family, int type,
				 int protocol, int kern)
{
  /* TODO:
    retrieve current process PID
    check if it is on the list or not
    return -EPERM if it is
  */
  return 0;
}