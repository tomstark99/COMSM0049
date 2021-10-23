// SPDX-License-Identifier: GPL-2.0-only
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/bug.h>
#include <linux/socket.h>
#include <linux/lsm_hooks.h>
#include <linux/msg.h>
#include <linux/cred.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/xattr.h>
#include <linux/security.h>

static ssize_t uob_write_pid(struct file *file, const char __user *buf,
				 size_t count, loff_t *ppos) {
    // TODO retrieve PID for buf and populate a list
    pr_info("UoB: PID added");
    return 0;
 }

 static const struct file_operations uob_pid_ops = {
	.write		= uob_write_pid,
  .llseek = generic_file_llseek,
};
