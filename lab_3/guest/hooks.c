// SPDX-License-Identifier: GPL-2.0-only
/* TODO identify needed include */
​
extern int pid;
​
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

/* data structure containing all our hooks */
static struct security_hook_list uob_hooks[] __lsm_ro_after_init = {
  LSM_HOOK_INIT(socket_create, uob_socket_create),
};

static __init int uob_init(void)
{
  pr_info("UoB hooks:  Initializing.\n");
  /* register our hooks */
  security_add_hooks(uob_hooks, ARRAY_SIZE(uob_hooks), "uob");
  return 0;
}

/* define our LSM */
DEFINE_LSM(uob) = {
	.name = "uob",
	.init = uob_init,
};