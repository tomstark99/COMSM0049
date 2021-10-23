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

static __init int init_uob_fs(void)
{
  struct dentry *uob_dir;

  pr_info("UoB fs: Initializing");
  /* create uob directory in /sys/kernel/security/ */
	uob_dir = securityfs_create_dir("uob", NULL);
  /* create pid file in /sys/kernel/security/uob/ with permission 0666
    and the operations we previously defined */
  securityfs_create_file("pid", 0666, uob_dir, NULL, &uob_pid_ops);

  return 0;
}

__initcall(init_uob_fs);