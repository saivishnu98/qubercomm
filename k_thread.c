#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/kthread.h>
#include<linux/delay.h>

static struct task_struct *thread_st;

static int thread_fn(void* unused) {

/**while(1) we cannot rmmod*/

allow_signal(SIGKILL);
while(!kthread_should_stop()) {

printk(KERN_INFO"Thread running\n");
ssleep(5);
if(signal_pending(thread_st))
break;
}
printk(KERN_INFO"Thread Stopping\n");
do_exit(0);
return 0;
}

/*Module intialization*/

static int __init thread(void) {

printk(KERN_INFO"Creating thread\n");

thread_st = kthread_run(thread_fn,NULL,"mythread");

if(thread_st) {

printk(KERN_INFO"Thread created sucessfully\n");
}
else {

printk(KERN_ERR"Thread creation failed\n");
}
return 0;
}

/*Module exit*/

static void __exit cleanup(void) {

printk(KERN_INFO"cleaning up");

if(thread_st) {

kthread_stop(thread_st);
printk(KERN_INFO"Thread stopped");
}
}


module_init(thread);
module_exit(cleanup);
