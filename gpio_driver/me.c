#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>	/* printk() */
#include <linux/slab.h>		/* kmalloc() */
#include <linux/fs.h>		/* everything... */
#include <linux/errno.h>	/* error codes */
#include <linux/types.h>	/* size_t */
#include <linux/proc_fs.h>
#include <linux/ioport.h>	/* needed for request_mem_region */
#include <linux/fcntl.h>	/* O_ACCMODE */
#include <asm/system.h>		/* cli(), *_flags */
#include <asm/io.h>		/* ioremap() etc */
#include <asm/uaccess.h>	/* copy_from/to_user */

MODULE_LICENSE ("Dual BSD/GPL");

int gpio_open (struct inode *inode, struct file *filp);
int gpio_release (struct inode *inode, struct file *filp);
ssize_t gpio_read (struct file *filp, char *buf, size_t count,
		   loff_t * f_pos);
ssize_t gpio_write (struct file *filp, char *buf, size_t count,
		    loff_t * f_pos);
void gpio_exit (void);
int gpio_init (void);

struct file_operations gpio_fops = {
  .read = gpio_read,
  .write = gpio_write,
  .open = gpio_open,
  .release = gpio_release
};

module_init (gpio_init);
module_exit (gpio_exit);

int gpio_major = 60;
void *io_pnt;			// pointer to IO gpio
unsigned long start = xxxxxxx;
unsigned long len = yyyyyy;
ssize_t gpio_current_value = 0;


int
gpio_init (void)
{
  int result;
  result = register_chrdev (gpio_major, "gpio", &gpio_fops);
  if (result < 0)
    {
      printk ("<1>gpio: cannot obtain major number %d\n", gpio_major);
      return result;
    }
  return 0;
}

void
gpio_exit (void)
{
  unregister_chrdev (gpio_major, "gpio");
  printk ("<1>Removing gpio module\n");
}

int
gpio_open (struct inode *inode, struct file *filp)
{
  if (request_mem_region (start, len, "gpio1") == NULL)
    return 1;
  else
    return 0;
}

int
gpio_release (struct inode *inode, struct file *filp)
{
  release_mem_region (start, len);
  return 0;
}

ssize_t
gpio_read (struct file * filp, char *buf, size_t count, loff_t * f_pos)
{

  // return the value last written
  char tmp[2];
  if (current_value == 0)
    tmp = "0";
  else
    tmp = "1";
  copy_to_user (buf, tmp, 1);

  if (*f_pos == 0)
    {
      *f_pos += 1;
      return 1;
    }
  else
    {
      return 0;
    }
}

ssize_t
gpio_write (struct file * filp, char *buf, size_t count, loff_t * f_pos)
{
  char *tmp;
  char tmp_store[2];
  tmp = buf + count - 1;
  copy_from_user (tmp_store, tmp, 1);
  if (tmp_store[0] == '0')
    {


      return 1;
    }
}
